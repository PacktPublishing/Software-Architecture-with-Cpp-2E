# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 11: Observability

### Docker

This commands builds the app Docker image:

```bash
docker compose -f compose-app.yml build --no-cache
```

Run the stack:

```bash
docker compose -f compose-lgtm.yml -f compose-app.yml up
```

Then open the [customer app](http://localhost:8080/customer/v1?name=anonymous) and [Grafana dashboard](http://localhost:3000/) in a browser.
Grafana credentials are `admin` and `admin`.

The other HTTP endpoints:

- [application metrics](http://localhost:8080/metrics): http_requests_total and http_request_duration_seconds_bucket
- [Grafana explore](http://localhost:3000/explore)
- [Grafana drilldown](http://localhost:3000/drilldown)
- [Grafana drilldown: logs](http://localhost:3000/a/grafana-lokiexplore-app/explore)
- [Grafana drilldown: metrics](http://localhost:3000/a/grafana-metricsdrilldown-app/drilldown)
