# Katran Real End-to-End Benchmark

- Generated: 2026-03-21T02:38:32.774301+00:00
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Smoke: `False`
- Paired cycles: `5`
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

- HTTP successes: `1315` / `1315`
- App throughput median req/s: `53.42748443723014`
- Packet PPS median: `320.56490662338086`
- Latency p99 median (ms): `26.60677039999937`
- System CPU busy median (%): `2.4242424242424288`
- bpf avg ns/run: `{'count': 5, 'mean': 373.8682965843272, 'median': 382.8517857142857, 'min': 333.9850746268657, 'max': 411.2178932178932}`
- total events: `{'count': 5, 'mean': 1578.0, 'median': 1608.0, 'min': 1386.0, 'max': 1680.0}`

## Recompile

- Applied cycles: `5` / `5`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `1310` / `1310`
- App throughput median req/s: `51.70497801845506`
- Packet PPS median: `310.2298681107303`
- Latency p99 median (ms): `26.753786080001014`
- System CPU busy median (%): `2.5201612903225756`
- bpf avg ns/run: `{'count': 5, 'mean': 369.25984839019543, 'median': 350.21043165467626, 'min': 293.04247104247105, 'max': 459.33991363355955}`
- total events: `{'count': 5, 'mean': 1572.2, 'median': 1554.0, 'min': 1506.0, 'max': 1668.0}`

## Comparison

- Median throughput delta: `-3.2240080866970042`
- Median latency p99 delta: `0.5525498878347426`
- Median packet PPS delta: `-3.2240080866970215`
- Median system CPU delta: `3.9566532258060514`
- Median BPF delta: `-8.52584610483416`
- Median BPF speedup ratio (stock/reJIT): `1.0932049736650773`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
