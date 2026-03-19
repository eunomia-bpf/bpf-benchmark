# Katran Real End-to-End Benchmark

- Generated: 2026-03-19T02:45:14.891387+00:00
- Mode: `katran_dsr_live_topology`
- Smoke: `False`
- Traffic rounds: `1`
- Requests per round: `5`
- Interface: `eth0`
- Attach mode: `xdp`

## Kernel

- CONFIG_NET_IPIP: `True`
- CONFIG_DUMMY: `True`
- CONFIG_VETH: `True`

## Baseline

- HTTP successes: `5` / `5`
- ipip rx packets delta: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 603.7, 'median': 603.7, 'min': 603.7, 'max': 603.7}`
- total events: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`

## Recompile

- Applied programs: `1` / `1`
- Applied successfully: `True`

## Post-ReJIT

- HTTP successes: `5` / `5`
- ipip rx packets delta: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`
- bpf avg ns/run: `{'count': 1, 'mean': 351.8, 'median': 351.8, 'min': 351.8, 'max': 351.8}`
- total events: `{'count': 1, 'mean': 30.0, 'median': 30.0, 'min': 30.0, 'max': 30.0}`

## Limitations

- Katran userspace server binary is not present; this case provisions the dataplane directly through pinned maps.
