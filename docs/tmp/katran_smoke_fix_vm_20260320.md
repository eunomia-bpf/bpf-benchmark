# Katran Real End-to-End Benchmark

- Generated: 2026-03-21T04:22:55.154851+00:00
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Smoke: `True`
- Paired cycles: `1`
- Timed duration per phase: `3s`
- Traffic driver: `python_parallel`
- Workload model: `http_short_flow_connection_churn`
- Client concurrency: `1`
- wrk threads: `None`
- wrk connections: `None`
- Warmup duration per phase: `0.5`
- Control plane: `bpftool_direct_map`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `151` / `151`
- App throughput median req/s: `50.32872216547979`
- Packet PPS median: `302.6389385844745`
- Latency p99 median (ms): `22.644653499999556`
- System CPU busy median (%): `2.1848739495798353`
- bpf avg ns/run: `{'count': 1, 'mean': 272.19493392070484, 'median': 272.19493392070484, 'min': 272.19493392070484, 'max': 272.19493392070484}`
- total events: `{'count': 1, 'mean': 908.0, 'median': 908.0, 'min': 908.0, 'max': 908.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `124` / `124`
- App throughput median req/s: `41.09352679773374`
- Packet PPS median: `246.89256019606157`
- Latency p99 median (ms): `28.55366173000096`
- System CPU busy median (%): `2.010050251256279`
- bpf avg ns/run: `{'count': 1, 'mean': 264.9718120805369, 'median': 264.9718120805369, 'min': 264.9718120805369, 'max': 264.9718120805369}`
- total events: `{'count': 1, 'mean': 745.0, 'median': 745.0, 'min': 745.0, 'max': 745.0}`

## Comparison

- Median throughput delta: `-18.34975133559108`
- Median latency p99 delta: `26.094496124665895`
- Median packet PPS delta: `-18.420094469387866`
- Median system CPU delta: `-8.001546192501218`
- Median BPF delta: `-2.6536577063084392`
- Median BPF speedup ratio (stock/reJIT): `1.0272599631766586`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
