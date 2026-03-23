# Katran Real End-to-End Benchmark

- Generated: 2026-03-23T12:10:15.788556+00:00
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

- HTTP successes: `215524` / `215524`
- App throughput median req/s: `7106.860173256799`
- Packet PPS median: `42641.06105416996`
- Latency p99 median (ms): `1.111362500013229`
- System CPU busy median (%): `5.9875485730998985`
- bpf avg ns/run: `{'count': 3, 'mean': 228.71205786191453, 'median': 230.31654993399349, 'min': 218.81066429305153, 'max': 237.00895935869855}`
- total events: `{'count': 3, 'mean': 431047.0, 'median': 426473.0, 'min': 407172.0, 'max': 459496.0}`


## Post-ReJIT

- HTTP successes: `225400` / `225400`
- App throughput median req/s: `7530.736902634569`
- Packet PPS median: `45184.42141580741`
- Latency p99 median (ms): `1.0126362400040987`
- System CPU busy median (%): `5.918846411804157`
- bpf avg ns/run: `{'count': 3, 'mean': 224.4627999203312, 'median': 223.12524340591256, 'min': 218.33064694049705, 'max': 231.93250941458405}`
- total events: `{'count': 3, 'mean': 450800.0, 'median': 451920.0, 'min': 438150.0, 'max': 462330.0}`

## Comparison

- Median throughput delta: `5.964331913730671`
- Median latency p99 delta: `-8.88335354197709`
- Median packet PPS delta: `5.96458038041418`
- Median system CPU delta: `-1.1474171851297814`
- Median BPF delta: `-3.1223576986290773`
- Median BPF speedup ratio (stock/reJIT): `1.0322299100644494`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
