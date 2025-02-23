# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 20: Cloud Native Design

**Important**: The shortest path on Linux is to install MicroK8s, enable the dns, ingress and helm addons,
check the status, build the customer image, deploy Aspire dashboard and the customer application,
resolve domain names relatively the loopback IP address `127.0.0.1`. But MicroK8s is a production-grade
conformant K8s tool and YOUR configuration may differ. Therefore, this manual describes different K8S tools and
ways to configure the development environment.

### MicroK8s

The examples were tested with [MicroK8S](https://microk8s.io/docs/command-reference)
([getting started](https://microk8s.io/docs/getting-started)) on Linux. Using this tool on macOS and Windows is similar.

Join the group `microk8s` not to apply `sudo microk8s` every time:

```bash
sudo usermod -a -G microk8s $USER
```

MicroK8s [addons](https://microk8s.io/docs/addons) ([how to manage addons](https://microk8s.io/docs/how-to-manage-addons)):

Mandatory addons (for the examples):

- [dns](https://microk8s.io/docs/addon-dns) - deploys CoreDNS
- [helm](https://helm.sh/docs/) - installs the Helm package manager
- [ingress](https://microk8s.io/docs/addon-ingress) - a simple ingress controller for external access

```bash
microk8s enable dns
microk8s enable ingress
microk8s enable helm
```

Optional addons:

- [dashboard](https://microk8s.io/docs/addon-dashboard) - the standard Kubernetes dashboard
- [host-access](https://microk8s.io/docs/addon-host-access) - provides a fixed IP for access to the host’s services
- [registry](https://microk8s.io/docs/registry-built-in) - deploy a private image registry and expose it on localhost:32000
- [metallb](https://microk8s.io/docs/addon-metallb) - deploys the [MetalLB LoadBalancer](https://metallb.io/)
- [community](https://microk8s.io/docs/howto-addons#promote-your-work-in-the-microk8s-community-repo) - community maintained addons

```bash
microk8s enable dashboard
microk8s enable registry
microk8s enable community
```

Check the status:

```bash
microk8s status --wait-ready
```

You can get an IP address of your Kubernetes node with this command and provide that address to MetalLB to assign
the [external IP](https://kubernetes.io/docs/concepts/services-networking/service/#external-ips):

```bash
microk8s kubectl get nodes -o wide
```

```bash
microk8s enable metallb
```

The alternative is to provide the address as the [IP address pool](https://microk8s.io/docs/addon-metallb) parameter:

```bash
microk8s enable metallb ODE_IP-NODE_IP
```

Or enable the addon [host-access](https://microk8s.io/docs/addon-host-access)
(NODE_IP is the Fixed IP `10.0.1.1` address by default) instead of retrieving NODE_IP:

```bash
microk8s enable host-access
```

This command is to open the Kubernetes dashboard:

```bash
microk8s dashboard-proxy
```

#### [Aspire Dashboard](https://aspiredashboard.com/)

Aspire Dashboard was chosen just as a simple 3-in-1 solution for local development: metrics, logs and traces.
Deploy the dashboard on Kubernetes with [helm](https://helm.sh/docs/helm/)

Helm charts:

- [aspire-dashboard](https://artifacthub.io/packages/helm/aspire-dashboard/aspire-dashboard)

The alternatives ([vendors](https://opentelemetry.io/ecosystem/vendors/) and [integrations](https://opentelemetry.io/ecosystem/integrations/)):

- [Loki, Grafana, Tempo and Mimir](https://artifacthub.io/packages/helm/grafana/lgtm-distributed) ([for development, demo, and testing environments](https://github.com/grafana/docker-otel-lgtm))
- [OpenTelemetry with Kubernetes](https://opentelemetry.io/docs/platforms/kubernetes/getting-started/)
- [SigNoz](https://signoz.io/docs/install/kubernetes/others/) ([configuration](https://github.com/SigNoz/charts/tree/main/charts/signoz#configuration))
- [Uptrace](https://artifacthub.io/packages/helm/uptrace/uptrace) ([Helm charts](https://github.com/uptrace/helm-charts))
- [Lightstep](https://docs.lightstep.com/docs/quick-start-operator) (OpenTelemetry Collector and Kubernetes Operator)

```bash
microk8s helm repo add aspire-dashboard https://kube-the-home.github.io/aspire-dashboard-helm/
microk8s helm install -f values.yaml aspire-dashboard aspire-dashboard/aspire-dashboard
```

MicroK8S runs on [Multipass](https://canonical.com/multipass) on macOS, Windows and as a deployment option on Linux.

Transfer the file `values.yaml` to the virtual machine (VM) if MicroK8S runs on Multipass and Helm complains the file is not found.<br>
`Error: INSTALLATION FAILED: open values.yaml: no such file or directory`

```bash
multipass transfer values.yaml microk8s-vm:
```

To open the [shell](https://canonical.com/multipass/docs/shell-command) on the VM in Multipass:

```bash
multipass shell microk8s-vm
```

To uninstall the dashboard:

```bash
microk8s helm uninstall aspire-dashboard
```

MicroK8S provides built-in [kubectl](https://kubernetes.io/docs/reference/kubectl/quick-reference/) and [helm](https://helm.sh/docs/intro/cheatsheet/) commands.
The name `aspire-dashboard` is important because this name is used in `kubernetes/manifest.yaml` as a server name of the OpenTelemetry collector.

All the namespaces:

```bash
microk8s kubectl get all -A
```

#### The customer application

Build [the Docker image](../README.md#docker)

There are two options to load the image to Kubernetes in MicroK8s:

- [built-in registry](https://microk8s.io/docs/registry-built-in) (the image name will differ from the local name)
- [image side-loading](https://microk8s.io/docs/sideload)

```bash
mkdir -p build && cd build
docker save customer > customer.tar
microk8s ctr image import customer.tar
```

Transfer the file `customer.tar` to the virtual machine (VM) if MicroK8S runs on Multipass and MicroK8S complains the file is not found.<br>
`ctr: open customer.tar: no such file or directory`

```bash
multipass transfer customer.tar microk8s-vm:
```

Deploy the app on Kubernetes with [kubectl](https://microk8s.io/docs/working-with-kubectl)

```bash
microk8s kubectl apply -f manifest.yaml
```

Select namespaces:

```bash
microk8s kubectl get all -n default
microk8s kubectl get all -n ingress
```

To delete the app:

```bash
microk8s kubectl delete -f manifest.yaml
```

#### Accessing the customer app and Aspire Dashboard

Get the IP address (NODE_IP) of your Kubernetes node by using the command above. Or use this command:

```bash
ip route | grep default
```

Alternatively, use this recipe if the `jq` command is installed:

```bash
microk8s kubectl get node -o json | jq '.items[].status.addresses[] | select(.type=="InternalIP") | .address'
```

The host names are specified in `kubernetes/manifest.yaml` and `kubernetes/values.yaml`.
MicroK8S redirects all the requests to `127.0.0.1` to its Kubernetes node if host names in the Ingress configuration are not set.
Replace NODE_IP and run this command in the console:

```bash
curl --header "Host: customer.local" http://NODE_IP/customer/v1?name=anonymous
```

The address NODE_IP is static if the addon `host-access` is enabled:

```bash
curl --header "Host: customer.local" http://10.0.1.1/customer/v1?name=anonymous
```

You need to resolve DNS domain names to open the app and dashboard in a browser.
The simplest solution is to change `/etc/hosts` because Kubernetes Ingress works as a router
when the HTTP header `Host` is provided. A browser sets that header automatically:

```
NODE_IP customer.local
NODE_IP opentelemetry.local  # opentelemetry-collector
NODE_IP dashboard.local      # aspire-dashboard
```

In Windows, the default path to the file looks like this: `%SystemRoot%\system32\drivers\etc\hosts`

NODE_IP changes when DHCP (Dynamic Host Configuration Protocol) assigns a new IP address,
and you must change these fully qualified domain names (FQDN) in `/etc/hosts` in this case,
but the address NODE_IP can be static if the addon `host-access` is enabled:

```
10.0.1.1 customer.local
10.0.1.1 opentelemetry.local
10.0.1.1 dashboard.local
```

Network redirection is configuration sensitive. Using `127.0.0.1` also works locally:

```
127.0.0.1 customer.local
127.0.0.1 opentelemetry.local
127.0.0.1 dashboard.local
```

Open `customer.local/customer/v1?name=anonymous` and `dashboard.local` in a browser.

[Tutorials](https://microk8s.io/tutorials) and [guides](https://microk8s.io/docs/how-to) for MicroK8S.

#### [Troubleshooting](https://microk8s.io/docs/troubleshooting)

Refresh CA certificates if `microk8s dashboard-proxy` fails to verify the certificate:<br>
`error: error upgrading connection: error dialing backend: tls: failed to verify certificate: x509: certificate is valid for`<br>
`Unable to connect to the server: x509: certificate is valid for`
`Unable to connect to the server: x509: certificate has expired or is not yet valid`<br>
The addresses are set here `/var/snap/microk8s/current/certs/csr.conf.template`

```bash
sudo microk8s refresh-certs --cert ca.crt
```

Clear browser data if Aspire Dashboard partially does not work after redeployment:<br>
`The key {#} was not found in the key ring.` (check [Kubernetes logs](https://kubernetes.io/docs/reference/kubectl/generated/kubectl_logs/))

### MiniKube

This [tool](https://minikube.sigs.k8s.io/docs/) has similar to MicroK8S features:

- [details on addons](https://minikube.sigs.k8s.io/docs/handbook/addons/)
- [ingress DNS](https://minikube.sigs.k8s.io/docs/handbook/addons/ingress-dns/)
- [interact with registries](https://minikube.sigs.k8s.io/docs/handbook/registry/)
- [pushing images](https://minikube.sigs.k8s.io/docs/handbook/pushing/)
- [static IP address](https://minikube.sigs.k8s.io/docs/tutorials/static_ip/)
- [retrieve IP address](https://minikube.sigs.k8s.io/docs/commands/ip/)
- [drivers](https://minikube.sigs.k8s.io/docs/drivers/) (Docker, Podman, KVM, VirtualBox, VMware, Parallels, Hyperkit, Hyper-V, SSH, None (bare-metal), etc.)

#### Running the Kubernetes cluster

[Start](https://minikube.sigs.k8s.io/docs/commands/start/) your cluster:

```bash
minikube start
```

To choose [the driver](https://minikube.sigs.k8s.io/docs/drivers/) (for example, KVM2 on Linux):

```bash
minikube start --driver=kvm2
```

minikube supports [static IPs](https://minikube.sigs.k8s.io/docs/tutorials/static_ip/):

```bash
minikube start --driver docker --static-ip 192.168.200.200
```

[Interact](https://minikube.sigs.k8s.io/docs/commands/) with your cluster:

```bash
kubectl get po -A
```

Alternatively:

```bash
minikube kubectl -- get po -A
```

Open the Kubernetes Dashboard:

```bash
minikube dashboard
```

#### Building the customer image in minikube

Run this command before building Docker images to push the images to the minikube Docker registry directly:

```bash
eval $(minikube -p minikube docker-env)
```

This command sets the environment variables to use minikube [Docker context](https://docs.docker.com/engine/manage-resources/contexts/):

```
export DOCKER_TLS_VERIFY="1"
export DOCKER_HOST="tcp://127.0.0.1:36195"
export DOCKER_CERT_PATH="/home/user/.minikube/certs"
export MINIKUBE_ACTIVE_DOCKERD="minikube"
```

#### Deploying Aspire Dashboard and the customer application

Enable the [Ingress DNS](https://minikube.sigs.k8s.io/docs/handbook/addons/ingress-dns/) addons:

```bash
minikube addons enable ingress
minikube addons enable ingress-dns
```

To list the addons:

```bash
minikube addons list
```

To deploy the dashboard:

```bash
helm repo add aspire-dashboard https://kube-the-home.github.io/aspire-dashboard-helm/
helm install -f values.yaml aspire-dashboard aspire-dashboard/aspire-dashboard
```

To build the image which looks like this:

```bash
cd ../cmake-build-release
eval $(minikube -p minikube docker-env)
cmake --build . --target docker
```

To deploy the application:

```bash
kubectl apply -f manifest.yaml
```

List all Kubernetes (K8S) resources:

```bash
kubectl get all -A
kubectl get ingress -A
```

#### [Accessing apps](https://minikube.sigs.k8s.io/docs/handbook/accessing/)

minikube supports NodePort and LoadBalancer access

##### NodePort access

```bash
kubectl get svc -A
```

```bash
minikube service customer --url
```

```bash
minikube service aspire-dashboard-ui-clusterip --url
```

##### LoadBalancer access

Adding FQDN entities to `/etc/hosts` also works with `minikube ip`:

```bash
minikube tunnel
```

You will see something like when the tunnel works (tested with KVM2):

```
Status:
    machine: minikube
    pid: 3510325
    route: 10.96.0.0/12 -> 192.168.39.166
    minikube: Running
    services: []
    errors:
        minikube: no errors
        router: no errors
        loadbalancer emulator: no errors
```

Open `customer.local/customer/v1?name=anonymous` and `dashboard.local` in a browser.

Functionality of minikube depends on the driver and operating system therefore please check the instructions
in its [tutorials](https://minikube.sigs.k8s.io/docs/tutorials/) and [handbook](https://minikube.sigs.k8s.io/docs/handbook/).

### Docker Desktop and Rancher Desktop

Turn on [Kubernetes](https://docs.docker.com/desktop/features/kubernetes/)

To deploy [Ingress-Nginx Controller](https://kubernetes.github.io/ingress-nginx/deploy/#quick-start)

```bash
helm upgrade --install ingress-nginx ingress-nginx \
  --repo https://kubernetes.github.io/ingress-nginx \
  --namespace ingress-nginx --create-namespace
```

To deploy the dashboard:

```bash
helm repo add aspire-dashboard https://kube-the-home.github.io/aspire-dashboard-helm/
helm install -f values.yaml aspire-dashboard aspire-dashboard/aspire-dashboard
```

To build the image which looks like this:

```bash
cd ../cmake-build-release
cmake --build . --target docker
```

To deploy the application:

```bash
kubectl apply -f manifest.yaml
```

Using FQDN entities in `/etc/hosts` also works:

```
127.0.0.1 customer.local
127.0.0.1 opentelemetry.local
127.0.0.1 dashboard.local
```

Open `customer.local/customer/v1?name=anonymous` and `dashboard.local` in a browser.

Rancher Desktop supports [Kubernetes](https://docs.rancherdesktop.io/ui/preferences/kubernetes/) in a similar way:

- [NGINX Ingress Controller](https://docs.rancherdesktop.io/how-to-guides/setup-NGINX-Ingress-Controller/)
- [Traefik Ingress Controller](https://docs.rancherdesktop.io/how-to-guides/traefik-ingress-example/)

There are many [Ingress Controllers](https://kubernetes.io/docs/concepts/services-networking/ingress-controllers/).
You may deploy any number of ingress controllers within a cluster.
