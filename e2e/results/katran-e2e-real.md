# Katran Real End-to-End Benchmark

- Generated: 2026-03-28T21:05:59.404348+00:00
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

- HTTP successes: `182361` / `182361`
- App throughput median req/s: `6060.40174759337`
- Packet PPS median: `36362.41048556022`
- Latency p99 median (ms): `1.3296381899976972`
- System CPU busy median (%): `8.561788274989457`
- bpf avg ns/run: `{'count': 3, 'mean': 281.7207333153906, 'median': 281.8415249460385, 'min': 274.7517263957518, 'max': 288.56894860438155}`
- total events: `{'count': 3, 'mean': 364723.0, 'median': 363685.0, 'min': 360433.0, 'max': 370051.0}`


## Post-ReJIT

- HTTP successes: `198484` / `198484`
- App throughput median req/s: `6661.930711488669`
- Packet PPS median: `39971.58426893201`
- Latency p99 median (ms): `1.1043196498553725`
- System CPU busy median (%): `8.828675963730849`
- bpf avg ns/run: `{'count': 3, 'mean': 260.71028918517914, 'median': 261.4591213689495, 'min': 251.6819841795801, 'max': 268.9897620070077}`
- total events: `{'count': 3, 'mean': 396968.6666666667, 'median': 399781.0, 'min': 365599.0, 'max': 425526.0}`

## Comparison

- Median throughput delta: `9.925562511333027`
- Median latency p99 delta: `-16.945853528975054`
- Median packet PPS delta: `9.925562511333021`
- Median system CPU delta: `3.117195615792312`
- Median BPF delta: `-7.231866766613393`
- Median BPF speedup ratio (stock/reJIT): `1.077956368362177`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

