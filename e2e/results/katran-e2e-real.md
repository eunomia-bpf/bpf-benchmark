# Katran Real End-to-End Benchmark

- Generated: 2026-03-28T22:33:06.158842+00:00
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

- HTTP successes: `184658` / `184658`
- App throughput median req/s: `6027.082252712454`
- Packet PPS median: `36162.49351627472`
- Latency p99 median (ms): `1.140332490002578`
- System CPU busy median (%): `8.833660113401521`
- bpf avg ns/run: `{'count': 3, 'mean': 297.38792047145193, 'median': 277.99026845163206, 'min': 272.1745270402796, 'max': 341.9989659224442}`
- total events: `{'count': 3, 'mean': 369317.0, 'median': 361675.0, 'min': 353695.0, 'max': 392581.0}`


## Post-ReJIT

- HTTP successes: `186458` / `186458`
- App throughput median req/s: `6193.609678226731`
- Packet PPS median: `37161.55808050486`
- Latency p99 median (ms): `1.2037789499996165`
- System CPU busy median (%): `8.921599662340407`
- bpf avg ns/run: `{'count': 3, 'mean': 289.69884078697515, 'median': 277.2278923095965, 'min': 269.2008635059725, 'max': 322.6677665453565}`
- total events: `{'count': 3, 'mean': 372916.3333333333, 'median': 371658.0, 'min': 370950.0, 'max': 376141.0}`

## Comparison

- Median throughput delta: `2.7629857787212533`
- Median latency p99 delta: `5.5638562045088396`
- Median packet PPS delta: `2.762709279935344`
- Median system CPU delta: `0.995505235768275`
- Median BPF delta: `-0.27424562243919864`
- Median BPF speedup ratio (stock/reJIT): `1.0027499979734513`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

