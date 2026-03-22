# Katran Real End-to-End Benchmark

- Generated: 2026-03-20T16:55:36.810923+00:00
- Mode: `katran_dsr_direct_map_emulation_same_image_paired`
- Smoke: `True`
- Paired cycles: `1`
- Timed duration per phase: `3s`
- Request batch size: `25`
- Warmup requests per phase: `100`
- Minimum requests per phase: `100`
- Control plane: `bpftool_direct_map`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `250` / `250`
- ipip rx packets delta: `{'count': 1, 'mean': 1500.0, 'median': 1500.0, 'min': 1500.0, 'max': 1500.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 255.81933333333333, 'median': 255.81933333333333, 'min': 255.81933333333333, 'max': 255.81933333333333}`
- total events: `{'count': 1, 'mean': 1500.0, 'median': 1500.0, 'min': 1500.0, 'max': 1500.0}`

## Recompile

- Applied cycles: `1` / `1`
- Applied successfully on all cycles: `True`

## Post-ReJIT

- HTTP successes: `250` / `250`
- ipip rx packets delta: `{'count': 1, 'mean': 1500.0, 'median': 1500.0, 'min': 1500.0, 'max': 1500.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 245.556, 'median': 245.556, 'min': 245.556, 'max': 245.556}`
- total events: `{'count': 1, 'mean': 1500.0, 'median': 1500.0, 'min': 1500.0, 'max': 1500.0}`

## Comparison

- Median BPF delta: `-4.0119459305916365`
- Median BPF speedup ratio (stock/reJIT): `1.0417963044410778`

## Limitations

- Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load.
