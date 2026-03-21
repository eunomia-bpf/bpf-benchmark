# Katran Real End-to-End Benchmark

- Generated: 2026-03-20T23:23:34.241033+00:00
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

- HTTP successes: `157` / `157`
- App throughput median req/s: `52.146779204137104`
- Packet PPS median: `312.8806752248226`
- Latency p99 median (ms): `23.16402695999919`
- System CPU busy median (%): `2.5083612040133763`
- bpf avg ns/run: `{'count': 1, 'mean': 291.23991507431, 'median': 291.23991507431, 'min': 291.23991507431, 'max': 291.23991507431}`
- total events: `{'count': 1, 'mean': 942.0, 'median': 942.0, 'min': 942.0, 'max': 942.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `159` / `159`
- App throughput median req/s: `52.749058206537505`
- Packet PPS median: `316.4943492392251`
- Latency p99 median (ms): `22.157617980000662`
- System CPU busy median (%): `2.345058626465657`
- bpf avg ns/run: `{'count': 1, 'mean': 279.6194968553459, 'median': 279.6194968553459, 'min': 279.6194968553459, 'max': 279.6194968553459}`
- total events: `{'count': 1, 'mean': 954.0, 'median': 954.0, 'min': 954.0, 'max': 954.0}`

## Comparison

- Median throughput delta: `1.154968747048943`
- Median latency p99 delta: `-4.344706478439378`
- Median packet PPS delta: `1.1549687470489658`
- Median system CPU delta: `-6.510329424902412`
- Median BPF delta: `-3.98998132381652`
- Median BPF speedup ratio (stock/reJIT): `1.0415579684165428`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
