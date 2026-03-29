# Katran Real End-to-End Benchmark

- Generated: 2026-03-29T08:51:43.804853+00:00
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

- HTTP successes: `192900` / `192900`
- App throughput median req/s: `6543.8199811601`
- Packet PPS median: `39262.9198869606`
- Latency p99 median (ms): `1.2202911096755993`
- System CPU busy median (%): `8.493963143401817`
- bpf avg ns/run: `{'count': 3, 'mean': 263.581408715896, 'median': 263.18220780312157, 'min': 260.22545426304544, 'max': 267.336564081521}`
- total events: `{'count': 3, 'mean': 385800.6666666667, 'median': 392689.0, 'min': 365550.0, 'max': 399163.0}`


## Post-ReJIT

- HTTP successes: `193926` / `193926`
- App throughput median req/s: `6660.151939842499`
- Packet PPS median: `39960.911639055`
- Latency p99 median (ms): `1.2011144900907311`
- System CPU busy median (%): `8.497627833421195`
- bpf avg ns/run: `{'count': 3, 'mean': 261.04580522776996, 'median': 257.46881390720705, 'min': 252.94993407110312, 'max': 272.7186677049997}`
- total events: `{'count': 3, 'mean': 387853.0, 'median': 399673.0, 'min': 363403.0, 'max': 400483.0}`

## Comparison

- Median throughput delta: `1.777737758943906`
- Median latency p99 delta: `-1.5714790866554824`
- Median packet PPS delta: `1.7777377589439198`
- Median system CPU delta: `0.043144642347831066`
- Median BPF delta: `-2.170889112758159`
- Median BPF speedup ratio (stock/reJIT): `1.0221906249895323`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

