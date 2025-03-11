# Software Architecture with C++, Second Edition

Software Architecture with C++, Second Edition, Published by Packt

## Chapter 4: Architectural and System Design Patterns

### Technical requirements

You'll need Docker to run the examples from this chapter.

For the tracing and reverse proxy, and the canary releases example you'll
also need Docker Compose.

### Running the examples

To run the examples:

```bash
./build.sh
./run.sh
```

To stop the examples:

```bash
./stop.sh
```

### Envoy

Make requests to the Envoy proxy by calling http://localhost:12345. The admin interface in on http://localhost:9901.

### OpenTelemetry extensions: [zPages](https://github.com/open-telemetry/opentelemetry-collector/blob/main/extension/zpagesextension/README.md)

#### Exposed zPages routes

The collector exposes the following zPage routes:

- lists the feature gates: http://localhost:55679/debug/featurez
- exposes the information about Go runtime: http://localhost:55679/debug/expvarz
- shows the extensions: http://localhost:55679/debug/extensionz
- brings insight on the running pipelines: http://localhost:55679/debug/pipelinez
- gives an overview of the collector services: http://localhost:55679/debug/servicez
- to examine and bucketize spans: http://localhost:55679/debug/tracez
