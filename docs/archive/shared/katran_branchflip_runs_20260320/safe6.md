# Katran Real End-to-End Benchmark

- Generated: 2026-03-21T02:23:42.088330+00:00
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Smoke: `False`
- Paired cycles: `3`
- Timed duration per phase: `5s`
- Traffic driver: `python_parallel`
- Workload model: `http_short_flow_connection_churn`
- Client concurrency: `1`
- wrk threads: `None`
- wrk connections: `None`
- Warmup duration per phase: `2.0`
- Control plane: `bpftool_direct_map`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `740` / `740`
- App throughput median req/s: `49.919628479626624`
- Packet PPS median: `299.51777087775974`
- Latency p99 median (ms): `27.34067207000006`
- System CPU busy median (%): `2.1105527638190957`
- bpf avg ns/run: `{'count': 3, 'mean': 305.5291443095757, 'median': 295.374649859944, 'min': 293.9021164021164, 'max': 327.3106666666667}`
- total events: `{'count': 3, 'mean': 1480.0, 'median': 1500.0, 'min': 1428.0, 'max': 1512.0}`

## Recompile

- Applied cycles: `3` / `3`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `715` / `715`
- App throughput median req/s: `50.10132534954169`
- Packet PPS median: `300.6079520972501`
- Latency p99 median (ms): `29.583959500000034`
- System CPU busy median (%): `2.104208416833664`
- bpf avg ns/run: `{'count': 3, 'mean': 305.6478100921257, 'median': 315.3478260869565, 'min': 266.62216461438754, 'max': 334.9734395750332}`
- total events: `{'count': 3, 'mean': 1430.3333333333333, 'median': 1506.0, 'min': 1242.0, 'max': 1543.0}`

## Comparison

- Median throughput delta: `0.3639788104377013`
- Median latency p99 delta: `8.20494618514317`
- Median packet PPS delta: `0.36397881043769653`
- Median system CPU delta: `-0.3006012024049851`
- Median BPF delta: `6.761980500521313`
- Median BPF speedup ratio (stock/reJIT): `0.9366630286472787`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
