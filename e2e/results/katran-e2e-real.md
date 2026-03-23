# Katran Real End-to-End Benchmark

- Generated: 2026-03-23T08:48:51.174485+00:00
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

- HTTP successes: `1570` / `1594`
- App throughput median req/s: `44.283543614289016`
- Packet PPS median: `268.395317571014`
- Latency p99 median (ms): `18.308313599959547`
- System CPU busy median (%): `0.2794228042372171`
- bpf avg ns/run: `{'count': 3, 'mean': 472.6128274626988, 'median': 476.4335620711167, 'min': 459.96796925048045, 'max': 481.4369510664994}`
- total events: `{'count': 3, 'mean': 3172.0, 'median': 3188.0, 'min': 3122.0, 'max': 3206.0}`


## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
- Post-REJIT measurement failed (cycle 0): Katran warmup failed after 3 attempts: Katran parallel warmup below threshold (0/4=0.0% < 90%): [{'worker': 2, 'error': 'timed out', 'snippet': ''}, {'worker': 1, 'error': 'timed out', 'snippet': ''}, {'worker': 3, 'error': 'timed out', 'snippet': ''}, {'worker': 0, 'error': 'timed out', 'snippet': ''}]
- Post-REJIT measurement failed (cycle 1): Katran warmup failed after 3 attempts: Katran parallel warmup below threshold (0/4=0.0% < 90%): [{'worker': 0, 'error': 'timed out', 'snippet': ''}, {'worker': 2, 'error': 'timed out', 'snippet': ''}, {'worker': 1, 'error': 'timed out', 'snippet': ''}, {'worker': 3, 'error': 'timed out', 'snippet': ''}]
- Post-REJIT measurement failed (cycle 2): Katran warmup failed after 3 attempts: Katran parallel warmup below threshold (0/4=0.0% < 90%): [{'worker': 3, 'error': 'timed out', 'snippet': ''}, {'worker': 1, 'error': 'timed out', 'snippet': ''}, {'worker': 2, 'error': 'timed out', 'snippet': ''}, {'worker': 0, 'error': 'timed out', 'snippet': ''}]
