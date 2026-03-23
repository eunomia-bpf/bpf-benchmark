# Katran Real End-to-End Benchmark

- Generated: 2026-03-23T13:36:34.399606+00:00
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

- HTTP successes: `220861` / `220861`
- App throughput median req/s: `7089.755519785225`
- Packet PPS median: `42538.53311871135`
- Latency p99 median (ms): `1.1393599599546176`
- System CPU busy median (%): `5.989255435238816`
- bpf avg ns/run: `{'count': 3, 'mean': 217.46281043002705, 'median': 218.74632499847218, 'min': 212.47571984795735, 'max': 221.1663864436516}`
- total events: `{'count': 3, 'mean': 441721.6666666667, 'median': 425442.0, 'min': 424067.0, 'max': 475656.0}`


## Post-ReJIT

- HTTP successes: `219415` / `219415`
- App throughput median req/s: `6951.460721864845`
- Packet PPS median: `41708.76433118907`
- Latency p99 median (ms): `1.159665940022024`
- System CPU busy median (%): `5.995042641683823`
- bpf avg ns/run: `{'count': 3, 'mean': 225.9468462305276, 'median': 234.21763394462423, 'min': 205.37607943144155, 'max': 238.24682531551704}`
- total events: `{'count': 3, 'mean': 438830.0, 'median': 417150.0, 'min': 409962.0, 'max': 489378.0}`

## Comparison

- Median throughput delta: `-1.9506285870428641`
- Median latency p99 delta: `1.7822269327610194`
- Median packet PPS delta: `-1.9506285870428557`
- Median system CPU delta: `0.09662647565434418`
- Median BPF delta: `7.072717197082104`
- Median BPF speedup ratio (stock/reJIT): `0.9339447304389988`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
