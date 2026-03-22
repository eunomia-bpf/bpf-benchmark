# Katran Real End-to-End Benchmark

- Generated: 2026-03-20T23:14:59.143485+00:00
- Mode: `katran_dsr_direct_map_connection_churn_same_image_paired`
- Smoke: `True`
- Paired cycles: `1`
- Timed duration per phase: `3s`
- Traffic driver: `python_parallel`
- Workload model: `http_short_flow_connection_churn`
- Client concurrency: `1`
- wrk threads: `None`
- wrk connections: `None`
- Warmup duration per phase: `1.0`
- Control plane: `bpftool_direct_map`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `151` / `151`
- App throughput median req/s: `50.2918247410881`
- Packet PPS median: `301.7509484465286`
- Latency p99 median (ms): `23.996035499999735`
- System CPU busy median (%): `1.8487394957983239`
- bpf avg ns/run: `{'count': 1, 'mean': 291.0077262693157, 'median': 291.0077262693157, 'min': 291.0077262693157, 'max': 291.0077262693157}`
- total events: `{'count': 1, 'mean': 906.0, 'median': 906.0, 'min': 906.0, 'max': 906.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `156` / `156`
- App throughput median req/s: `51.94150368631451`
- Packet PPS median: `311.64902211788706`
- Latency p99 median (ms): `29.314976500001848`
- System CPU busy median (%): `2.1848739495798353`
- bpf avg ns/run: `{'count': 1, 'mean': 321.1741452991453, 'median': 321.1741452991453, 'min': 321.1741452991453, 'max': 321.1741452991453}`
- total events: `{'count': 1, 'mean': 936.0, 'median': 936.0, 'min': 936.0, 'max': 936.0}`

## Comparison

- Median throughput delta: `3.2802129445874635`
- Median latency p99 delta: `22.16591569887522`
- Median packet PPS delta: `3.2802129445874635`
- Median system CPU delta: `18.18181818181807`
- Median BPF delta: `10.366191790355368`
- Median BPF speedup ratio (stock/reJIT): `0.9060745720931793`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
