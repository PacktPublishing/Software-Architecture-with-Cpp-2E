# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 18: Cloud Native Design

### [OTLP exporters](https://opentelemetry.io/docs/languages/cpp/exporters/)

You can run the OpenTelemetry collector in a Docker container and telemetry to the console to debug your application locally:

```bash
docker run -p 4317:4317 -p 4318:4318 --rm -v $(pwd)/debug/collector-config.yaml:/etc/otelcol/config.yaml otel/opentelemetry-collector
```

### The app in Docker

Build the Docker image and run one of these tools

#### Aspire Dashboard

A free & open-source OpenTelemetry [dashboard](https://aspiredashboard.com/) for deep insights into your apps on your local development machine.

```bash
docker compose -f ./aspire/compose.yaml up
```

Then open the [customer app](http://localhost:8080/customer/v1?name=anonymous) and [dashboard](http://localhost:18888/) in a browser.
Select a time period as the metrics are updated periodically.
