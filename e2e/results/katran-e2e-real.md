# Katran Real End-to-End Benchmark

- Generated: 2026-03-29T01:57:09.191539+00:00
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Smoke: `False`
- Paired cycles: `3`
- Timed duration per phase: `10s`
- Traffic driver: `python_parallel`
- Workload model: `http_short_flow_connection_churn`
- Client concurrency: `4`
- wrk threads: `None`
- wrk connections: `None`
- Warmup duration per phase: `2.0`
- Control plane: `bpftool_direct_map`
- Interface: `katran0`
- Attach mode: `xdpgeneric`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `188527` / `188527`
- App throughput median req/s: `5938.861475256748`
- Packet PPS median: `35633.068863974404`
- Latency p99 median (ms): `1.3401638500567978`
- System CPU busy median (%): `8.715572173363528`
- bpf avg ns/run: `{'count': 3, 'mean': 273.0775266517509, 'median': 270.8209699867556, 'min': 260.51473441086927, 'max': 287.89687555762777}`
- total events: `{'count': 3, 'mean': 377054.3333333333, 'median': 356376.0, 'min': 347454.0, 'max': 427333.0}`


## Post-ReJIT

- HTTP successes: `187845` / `187845`
- App throughput median req/s: `5965.895534441554`
- Packet PPS median: `35795.373206649325`
- Latency p99 median (ms): `1.3418078999302452`
- System CPU busy median (%): `8.730493462673984`
- bpf avg ns/run: `{'count': 3, 'mean': 272.1672467970216, 'median': 271.7452127005409, 'min': 268.23542704233694, 'max': 276.5211006481871}`
- total events: `{'count': 3, 'mean': 375691.0, 'median': 358009.0, 'min': 354373.0, 'max': 414691.0}`

## Comparison

- Median throughput delta: `0.45520609122538047`
- Median latency p99 delta: `0.12267528879977428`
- Median packet PPS delta: `0.45548797184576256`
- Median system CPU delta: `0.17120263608232308`
- Median BPF delta: `0.34127442709864897`
- Median BPF speedup ratio (stock/reJIT): `0.9965988629400298`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

