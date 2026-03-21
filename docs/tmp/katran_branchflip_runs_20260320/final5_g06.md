# Katran Real End-to-End Benchmark

- Generated: 2026-03-21T02:40:18.533714+00:00
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

- HTTP successes: `1357` / `1357`
- App throughput median req/s: `53.993416129226695`
- Packet PPS median: `323.9604967753602`
- Latency p99 median (ms): `23.519016860000548`
- System CPU busy median (%): `2.426693629929222`
- bpf avg ns/run: `{'count': 5, 'mean': 361.09610600903545, 'median': 342.9135101010101, 'min': 335.7366568914956, 'max': 411.8969135802469}`
- total events: `{'count': 5, 'mean': 1629.0, 'median': 1620.0, 'min': 1579.0, 'max': 1705.0}`

## Recompile

- Applied cycles: `5` / `5`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `1273` / `1273`
- App throughput median req/s: `52.24450714975981`
- Packet PPS median: `313.4670428985589`
- Latency p99 median (ms): `26.56386161999918`
- System CPU busy median (%): `2.4169184290030232`
- bpf avg ns/run: `{'count': 5, 'mean': 372.93509806991176, 'median': 375.6522262334537, 'min': 322.4440203562341, 'max': 396.5214460784314}`
- total events: `{'count': 5, 'mean': 1527.8, 'median': 1572.0, 'min': 1284.0, 'max': 1662.0}`

## Comparison

- Median throughput delta: `-3.2391152567214516`
- Median latency p99 delta: `12.946309695355868`
- Median packet PPS delta: `-3.239115256721456`
- Median system CPU delta: `-0.40281973816710287`
- Median BPF delta: `9.547222599307892`
- Median BPF speedup ratio (stock/reJIT): `0.9128483372487783`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
