# Katran Real End-to-End Benchmark

- Generated: 2026-03-28T14:41:01.843284+00:00
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

- HTTP successes: `189998` / `189998`
- App throughput median req/s: `6009.145419599696`
- Packet PPS median: `36054.872517598174`
- Latency p99 median (ms): `1.2888784201186354`
- System CPU busy median (%): `8.908733322702389`
- bpf avg ns/run: `{'count': 3, 'mean': 278.5620570089374, 'median': 283.02893225476356, 'min': 259.6011480232813, 'max': 293.05609074876736}`
- total events: `{'count': 3, 'mean': 379997.0, 'median': 360601.0, 'min': 355531.0, 'max': 423859.0}`


## Post-ReJIT

- HTTP successes: `189857` / `189857`
- App throughput median req/s: `6116.022808205479`
- Packet PPS median: `36696.13684923288`
- Latency p99 median (ms): `1.2604000399278448`
- System CPU busy median (%): `8.70758351364188`
- bpf avg ns/run: `{'count': 3, 'mean': 269.7263551559949, 'median': 270.15239159162434, 'min': 265.7994901547117, 'max': 273.2271837216486}`
- total events: `{'count': 3, 'mean': 379714.3333333333, 'median': 367015.0, 'min': 362592.0, 'max': 409536.0}`

## Comparison

- Median throughput delta: `1.7785788351399743`
- Median latency p99 delta: `-2.2095474442166023`
- Median packet PPS delta: `1.7785788351399792`
- Median system CPU delta: `-2.2578946049256228`
- Median BPF delta: `-4.549549249455752`
- Median BPF speedup ratio (stock/reJIT): `1.0476639891554396`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

