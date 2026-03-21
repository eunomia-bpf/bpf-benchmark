# Katran Real End-to-End Benchmark

- Generated: 2026-03-20T23:22:14.292265+00:00
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

- HTTP successes: `176` / `176`
- App throughput median req/s: `58.430613706811734`
- Packet PPS median: `350.5836822408704`
- Latency p99 median (ms): `20.950128999999595`
- System CPU busy median (%): `2.352941176470591`
- bpf avg ns/run: `{'count': 1, 'mean': 298.2073863636364, 'median': 298.2073863636364, 'min': 298.2073863636364, 'max': 298.2073863636364}`
- total events: `{'count': 1, 'mean': 1056.0, 'median': 1056.0, 'min': 1056.0, 'max': 1056.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `176` / `176`
- App throughput median req/s: `58.444017849234754`
- Packet PPS median: `350.6641070954085`
- Latency p99 median (ms): `22.693699000000844`
- System CPU busy median (%): `2.842809364548493`
- bpf avg ns/run: `{'count': 1, 'mean': 299.90909090909093, 'median': 299.90909090909093, 'min': 299.90909090909093, 'max': 299.90909090909093}`
- total events: `{'count': 1, 'mean': 1056.0, 'median': 1056.0, 'min': 1056.0, 'max': 1056.0}`

## Comparison

- Median throughput delta: `0.02294027321068139`
- Median latency p99 delta: `8.322478587130812`
- Median packet PPS delta: `0.022940273210669226`
- Median system CPU delta: `20.819397993310815`
- Median BPF delta: `0.570644666520597`
- Median BPF speedup ratio (stock/reJIT): `0.9943259321006365`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
