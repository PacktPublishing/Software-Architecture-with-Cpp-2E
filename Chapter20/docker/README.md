# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 20: Cloud Native Design

### [OTLP exporters](https://opentelemetry.io/docs/languages/cpp/exporters/)

You can run the OpenTelemetry collector in a Docker container and telemetry to the console to debug your application locally:

```bash
docker run -p 4317:4317 -p 4318:4318 --rm -v $(pwd)/collector-config.yaml:/etc/otelcol/config.yaml otel/opentelemetry-collector
```

### The app in Docker

Build the Docker image run this command:

```bash
docker compose up
```

Then open the [customer app](http://localhost:8080/customer/v1?name=anonymous) and [dashboard](http://localhost:18888/) in a browser.
Select a time period as the metrics are updated periodically.
