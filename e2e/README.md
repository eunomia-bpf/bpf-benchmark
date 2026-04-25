# End-to-End

`e2e/` is the deployment-layer benchmark harness. `make vm-e2e` and the AWS
benchmark aliases are the canonical entrypoints; `python3 e2e/driver.py <case>`
is a developer/debug entrypoint only.

Active checked-in cases are `tracee`, `tetragon`, `bpftrace`, `bcc`, and `katran`.

## Layout

- `driver.py`: unified dispatcher for `tracee`, `tetragon`, `bpftrace`, `bcc`, and `katran`
- `cases/`: per-system case logic and assets
- `../runner/libs/`: shared helpers for agent lifecycle, workload generation, BPF stats sampling, VM runs, and REJIT
- `results/`: timestamped run-artifact directories

## Shared Prerequisites

- Most cases require root or passwordless `sudo -n`.
- Repo-managed runtime artifacts are prepared by Make under
  `.cache/repo-artifacts/<arch>` before the suite enters the VM or AWS host.
- Canonical runs should go through the root `Makefile` aliases (`make vm-e2e`,
  `make aws-x86-benchmark`, `make aws-arm64-benchmark`). Direct
  `python3 e2e/driver.py ...` execution assumes the required runtime, daemon,
  and repo-artifact outputs already exist at their canonical paths.

Results live under `e2e/results/<run_type>_<timestamp>/`. `metadata.json` is the canonical run summary; `details/` contains `progress.json`, `result.json`, `result.md`, and any retained per-case payloads.

## Case Notes

### Tracee

- Setup is Python-only and validates the bundled `tracee` binary plus required workload tools such as `stress-ng`, `fio`, `wrk`, and `hackbench`
- Uses the fixed in-code Tracee benchmark plan plus `.cache/repo-artifacts/<arch>/tracee/tracee.bpf.o`
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

- Uses the repo-managed, fully static `.cache/repo-artifacts/<arch>/bpftrace/bin/bpftrace` artifact plus `bpftool` and workload tools in `PATH`
- Scripts live under `e2e/cases/bpftrace/scripts/`
- The case expects the canonical runner and daemon artifacts to already exist at their prepared paths
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py bpftrace --smoke`
