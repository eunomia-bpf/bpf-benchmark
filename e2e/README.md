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
- Repo-managed runtime artifacts come from `RUN_REPO_ARTIFACT_ROOT`, which resolves to
  `.cache/repo-artifacts/<arch>` on canonical runs.
- Canonical runs should go through the root `Makefile` aliases (`make vm-e2e`,
  `make aws-x86-benchmark`, `make aws-arm64-benchmark`). Direct
  `python3 e2e/driver.py ...` execution assumes the required runtime, daemon,
  and repo-artifact outputs already exist at their canonical paths.

Results live under `e2e/results/<run_type>_<timestamp>/`. `metadata.json` is the canonical run summary; `details/` contains `result.json`, `result.md`, optional `report.md`, and any retained per-case payloads.

## Case Notes

### Tracee

- Setup is Python-only and validates the bundled `tracee` binary plus required workload tools such as `stress-ng`, `fio`, `wrk`, and `hackbench`
- Uses `e2e/cases/tracee/config.yaml` plus `.cache/repo-artifacts/<arch>/tracee/tracee.bpf.o`
- Supports `--vm` and `--kernel`
- Smoke example: `python3 e2e/driver.py tracee --smoke`

### Tetragon

- Setup is Python-only and validates the bundled Tetragon binary, bundled `.bpf.o` assets, and required workload tools
- Uses `.cache/repo-artifacts/<arch>/tetragon/bpf_execve_event.bpf.o` and `.cache/repo-artifacts/<arch>/tetragon/bpf_generic_kprobe.bpf.o`
- Requires `bpftool` for attach/discovery paths
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py tetragon --smoke`

### BCC

- Setup is Python-only and validates bundled repo-managed BCC libbpf-tools plus required workload tools
- Uses `.cache/repo-artifacts/<arch>/bcc/libbpf-tools/.output`
- Smoke example: `python3 e2e/driver.py bcc --smoke`

### bpftrace

- No separate setup script; the case requires `bpftrace >= 0.16`, `bpftool`, and workload tools already in `PATH`
- Scripts live under `e2e/cases/bpftrace/scripts/`
- The case expects the canonical runner and daemon artifacts to already exist at their prepared paths
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py bpftrace --smoke`

### scx

- `make vm-e2e` now prepares `.cache/repo-artifacts/<arch>/scx/bin/scx_rusty` before entering the VM
- Uses `.cache/repo-artifacts/<arch>/scx/scx_rusty_main.bpf.o`
- Requires `hackbench`, `stress-ng`, and `sysbench` in `PATH`
- Supports `--vm` and requires `--kernel` when enabled
- Smoke example: `python3 e2e/driver.py scx --smoke`
