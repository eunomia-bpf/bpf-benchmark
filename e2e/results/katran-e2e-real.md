# Katran Real End-to-End Benchmark

- Generated: 2026-03-28T18:56:47.175964+00:00
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

- HTTP successes: `192814` / `192814`
- App throughput median req/s: `6618.208513249415`
- Packet PPS median: `39709.15110202752`
- Latency p99 median (ms): `1.1511511599564983`
- System CPU busy median (%): `8.602321513754173`
- bpf avg ns/run: `{'count': 3, 'mean': 267.2551276804272, 'median': 268.45826850159375, 'min': 263.9203158116533, 'max': 269.3867987280346}`
- total events: `{'count': 3, 'mean': 385628.6666666667, 'median': 397182.0, 'min': 356299.0, 'max': 403405.0}`


## Post-ReJIT

- HTTP successes: `185874` / `185874`
- App throughput median req/s: `6168.767319393912`
- Packet PPS median: `37012.60391636347`
- Latency p99 median (ms): `1.2213207599688762`
- System CPU busy median (%): `8.539349533498497`
- bpf avg ns/run: `{'count': 3, 'mean': 267.1109832812159, 'median': 265.4381540050345, 'min': 262.5014168667929, 'max': 273.39337897182025}`
- total events: `{'count': 3, 'mean': 371749.0, 'median': 370183.0, 'min': 357739.0, 'max': 387325.0}`

## Comparison

- Median throughput delta: `-6.790979657950305`
- Median latency p99 delta: `6.095602597927245`
- Median packet PPS delta: `-6.790744981517288`
- Median system CPU delta: `-0.7320347205692256`
- Median BPF delta: `-1.1249847186365636`
- Median BPF speedup ratio (stock/reJIT): `1.011377846217624`

## Limitations

- Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead.
- Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.

