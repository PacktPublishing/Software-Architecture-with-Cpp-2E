# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## [Running Artifactory CE](https://docs.conan.io/2/tutorial/conan_repositories/setting_up_conan_remotes/artifactory/artifactory_ce_cpp.html)

Run Artifactory CE using Docker Compose and wait because the server takes a while to start:

```bash
docker compose up -d
```

Open the URL http://localhost:8081 in a browser. The default user and password are `admin:password`.
Navigate to `Administration -> Repositories -> Repositories`, then click on the `Create a Repository` button, select `Local` and the Package Type `Conan`.
For example, type `conan-local` in the `Repository key` and click on `Create Local Repository`.

Connect the Conan remote repository:

```bash
conan remote add artifactory http://localhost:8081/artifactory/api/conan/conan-local
```

Configure the credentials for the remote. By default, they are `admin:password`:

```bash
conan remote login artifactory admin -p password
```

Upload the customer package (from the directory containing `conanfile.py`):

```bash
conan upload customer -r=artifactory
conan search "*" -r=artifactory
```
