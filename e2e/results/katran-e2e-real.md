# Katran Real End-to-End Benchmark

- Generated: 2026-03-19T22:46:37.497424+00:00
- Mode: `katran_dsr_direct_map_emulation`
- Smoke: `False`
- Traffic rounds: `1`
- Requests per round: `5`
- Control plane: `bpftool_direct_map`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `5` / `5`
- ipip rx packets delta: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 407.6, 'median': 407.6, 'min': 407.6, 'max': 407.6}`
- total events: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`

## Recompile

- Applied programs: `1` / `1`
- Applied successfully: `True`

## Post-ReJIT

- HTTP successes: `5` / `5`
- ipip rx packets delta: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 507.03333333333336, 'median': 507.03333333333336, 'min': 507.03333333333336, 'max': 507.03333333333336}`
- total events: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`
