# Katran Real End-to-End Benchmark

- Generated: 2026-03-23T11:10:21.567485+00:00
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

- HTTP successes: `217875` / `217875`
- App throughput median req/s: `7463.884361644712`
- Packet PPS median: `44783.30616986827`
- Latency p99 median (ms): `1.0024675399677108`
- System CPU busy median (%): `6.145977445185091`
- bpf avg ns/run: `{'count': 3, 'mean': 236.31578106218566, 'median': 237.20334427664696, 'min': 230.38703051250107, 'max': 241.356968397409}`
- total events: `{'count': 3, 'mean': 435749.6666666667, 'median': 447882.0, 'min': 402467.0, 'max': 456900.0}`


## Post-ReJIT

- HTTP successes: `211104` / `211104`
- App throughput median req/s: `7068.847440605066`
- Packet PPS median: `42412.9846542754`
- Latency p99 median (ms): `1.084149250016253`
- System CPU busy median (%): `5.925770601803315`
- bpf avg ns/run: `{'count': 3, 'mean': 241.28840595086862, 'median': 243.58129123468427, 'min': 234.6897803339586, 'max': 245.594146283963}`
- total events: `{'count': 3, 'mean': 422207.6666666667, 'median': 424175.0, 'min': 407424.0, 'max': 435024.0}`

## Comparison

- Median throughput delta: `-5.2926452487615565`
- Median latency p99 delta: `8.148065327997877`
- Median packet PPS delta: `-5.2928685224846195`
- Median system CPU delta: `-3.5829425888032103`
- Median BPF delta: `2.6888098806055627`
- Median BPF speedup ratio (stock/reJIT): `0.9738159407657777`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
