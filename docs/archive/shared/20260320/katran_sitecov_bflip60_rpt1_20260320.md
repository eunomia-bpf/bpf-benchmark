# Katran Real End-to-End Benchmark

- Generated: 2026-03-20T23:22:14.309061+00:00
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

- HTTP successes: `181` / `181`
- App throughput median req/s: `59.999627425517964`
- Packet PPS median: `359.9977645531078`
- Latency p99 median (ms): `19.3176568000009`
- System CPU busy median (%): `2.5210084033613467`
- bpf avg ns/run: `{'count': 1, 'mean': 256.7744014732965, 'median': 256.7744014732965, 'min': 256.7744014732965, 'max': 256.7744014732965}`
- total events: `{'count': 1, 'mean': 1086.0, 'median': 1086.0, 'min': 1086.0, 'max': 1086.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `178` / `178`
- App throughput median req/s: `59.27539917837066`
- Packet PPS median: `355.652395070224`
- Latency p99 median (ms): `21.669523779999015`
- System CPU busy median (%): `2.1922428330522714`
- bpf avg ns/run: `{'count': 1, 'mean': 347.3445692883895, 'median': 347.3445692883895, 'min': 347.3445692883895, 'max': 347.3445692883895}`
- total events: `{'count': 1, 'mean': 1068.0, 'median': 1068.0, 'min': 1068.0, 'max': 1068.0}`

## Comparison

- Median throughput delta: `-1.2070545738743805`
- Median latency p99 delta: `12.174701126267056`
- Median packet PPS delta: `-1.2070545738743843`
- Median system CPU delta: `-13.041034288926642`
- Median BPF delta: `35.27227297403005`
- Median BPF speedup ratio (stock/reJIT): `0.7392497945177449`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
