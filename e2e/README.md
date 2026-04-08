# End-to-End

`e2e/` is the deployment-layer benchmark harness. `make vm-e2e` is the canonical benchmark entrypoint, and `python3 e2e/driver.py <case>` is the direct driver entrypoint.

Active checked-in cases are `tracee`, `tetragon`, `bpftrace`, `bcc`, `scx`, and `katran`.

## Layout

- `driver.py`: unified dispatcher for `tracee`, `tetragon`, `bpftrace`, `scx`, `bcc`, and `katran`
- `cases/`: per-system case logic, setup scripts, configs, and assets
- `../runner/libs/`: shared helpers for agent lifecycle, workload generation, metrics, VM runs, and REJIT
- `results/`: timestamped run-artifact directories

## Shared Prerequisites

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make -C runner micro_exec
make -C runner DAEMON_TARGET_DIR="$PWD/daemon/target" daemon-binary
make -C runner REPOS="tracee tetragon scx" corpus-build-native
```

- Most cases require root or passwordless `sudo -n`.
- `tracee`, `tetragon`, and `scx` consume objects from `corpus/build/`.
- `e2e` expects the daemon CLI at `daemon/target/release/bpfrejit-daemon`; `make -C runner DAEMON_TARGET_DIR="$PWD/daemon/target" daemon-binary` builds it.

Results live under `e2e/results/<run_type>_<timestamp>/`. `metadata.json` is the canonical run summary; `details/` contains `result.json`, `result.md`, optional `report.md`, and any retained per-case payloads.

## Case Notes

### Tracee

- Setup helper: `e2e/cases/tracee/setup.sh`
- Auto-installs or downloads `tracee`, and tries to provision workload tools such as `stress-ng`, `fio`, `wrk`, and `hackbench`
- Uses `e2e/cases/tracee/config.yaml` plus `corpus/build/tracee/tracee.bpf.o`
- Supports `--vm` and `--kernel`
- Smoke example: `python3 e2e/driver.py tracee --smoke`

### Tetragon

- Setup helper: `e2e/cases/tetragon/setup.sh`
- Tries to provision `stress-ng`, `fio`, `curl`, `tar`, then downloads a Tetragon release bundle when needed
- Uses `corpus/build/tetragon/bpf_execve_event.bpf.o` and `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
- Requires `bpftool` for attach/discovery paths
- `--vm` is not supported in `e2e/driver.py`
- Smoke example: `python3 e2e/driver.py tetragon --smoke`

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
