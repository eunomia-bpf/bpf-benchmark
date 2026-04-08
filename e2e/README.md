# End-to-End

`e2e/` is the deployment-layer benchmark harness. `make vm-e2e` and the AWS
benchmark aliases are the canonical entrypoints; `python3 e2e/driver.py <case>`
is a developer/debug entrypoint only.

Active checked-in cases are `tracee`, `tetragon`, `bpftrace`, `bcc`, `scx`, and `katran`.

## Layout

- `driver.py`: unified dispatcher for `tracee`, `tetragon`, `bpftrace`, `scx`, `bcc`, and `katran`
- `cases/`: per-system case logic, configs, and assets
- `../runner/libs/`: shared helpers for agent lifecycle, workload generation, metrics, VM runs, and REJIT
- `results/`: timestamped run-artifact directories

## Shared Prerequisites

- Most cases require root or passwordless `sudo -n`.
- `tracee`, `tetragon`, and `scx` consume objects from `corpus/build/`.
- Canonical runs should go through the root `Makefile` aliases (`make vm-e2e`,
  `make aws-x86-benchmark`, `make aws-arm64-benchmark`). Direct
  `python3 e2e/driver.py ...` execution assumes the required runtime, daemon,
  and `corpus/build` artifacts already exist at their canonical paths.

Results live under `e2e/results/<run_type>_<timestamp>/`. `metadata.json` is the canonical run summary; `details/` contains `result.json`, `result.md`, optional `report.md`, and any retained per-case payloads.

## Case Notes

### Tracee

- Setup is Python-only and validates the bundled `tracee` binary plus required workload tools such as `stress-ng`, `fio`, `wrk`, and `hackbench`
- Uses `e2e/cases/tracee/config.yaml` plus `corpus/build/tracee/tracee.bpf.o`
- Supports `--vm` and `--kernel`
- Smoke example: `python3 e2e/driver.py tracee --smoke`

### Tetragon

- Setup is Python-only and validates the bundled Tetragon binary, bundled `.bpf.o` assets, and required workload tools
- Uses `corpus/build/tetragon/bpf_execve_event.bpf.o` and `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
- Requires `bpftool` for attach/discovery paths
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py tetragon --smoke`

### BCC

- Setup is Python-only and validates bundled repo-managed BCC libbpf-tools plus required workload tools
- Uses `corpus/build/bcc/libbpf-tools/.output`
- Smoke example: `python3 e2e/driver.py bcc --smoke`

### bpftrace

- No separate setup script; the case requires `bpftrace >= 0.16`, `bpftool`, and workload tools already in `PATH`
- Scripts live under `e2e/cases/bpftrace/scripts/`
- The case auto-builds `micro_exec` and the daemon CLI if they are missing
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py bpftrace --smoke`

### scx

- `make vm-e2e` now prepares `runner/repos/scx` and `runner/repos/scx/target/release/scx_rusty` through the runner control plane before entering the VM
- Uses `corpus/build/scx/scx_rusty_main.bpf.o`
- Requires `hackbench`, `stress-ng`, and `sysbench` in `PATH`
- Supports `--vm` and requires `--kernel` when enabled
- Smoke example: `python3 e2e/driver.py scx --smoke`
