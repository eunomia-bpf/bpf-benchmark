# End-to-End

`e2e/` is the deployment-layer benchmark harness. The unified entrypoint is `python3 e2e/run.py <case>`.

Active checked-in cases are `tracee`, `tetragon`, `bpftrace`, `scx`, and `katran`. The former low-value XDP dataplane case was retired on 2026-03-18; `katran` is the current XDP replacement.

## Layout

- `run.py`: unified dispatcher for `tracee`, `tetragon`, `bpftrace`, `scx`, and `katran`
- `cases/`: per-system case logic, setup scripts, configs, and assets
- `../runner/libs/`: shared helpers for agent lifecycle, workload generation, metrics, VM runs, and recompile
- `results/`: JSON/Markdown outputs

## Shared Prerequisites

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make micro
make daemon
python3 corpus/build_expanded_corpus.py --repo tracee --repo tetragon --repo scx --repo katran
```

- Most cases require root or passwordless `sudo -n`.
- `tracee`, `tetragon`, `scx`, and `katran` consume objects from `corpus/build/`.
- `e2e` expects the daemon CLI at `daemon/target/release/bpfrejit-daemon`; `make daemon` builds it.

## Case Notes

### Tracee

- Setup helper: `e2e/cases/tracee/setup.sh`
- Auto-installs or downloads `tracee`, and tries to provision workload tools such as `stress-ng`, `fio`, `wrk`, and `hackbench`
- Uses `e2e/cases/tracee/config.yaml` plus `corpus/build/tracee/tracee.bpf.o`
- Supports `--vm` and `--kernel`
- Smoke example: `python3 e2e/run.py tracee --smoke`

### Tetragon

- Setup helper: `e2e/cases/tetragon/setup.sh`
- Tries to provision `stress-ng`, `fio`, `curl`, `tar`, then downloads a Tetragon release bundle when needed
- Uses `corpus/build/tetragon/bpf_execve_event.bpf.o` and `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
- Requires `bpftool` for attach/discovery paths
- `--vm` is not supported in `e2e/run.py`
- Smoke example: `python3 e2e/run.py tetragon --smoke`

### bpftrace

- No separate setup script; the case requires `bpftrace >= 0.16`, `bpftool`, and workload tools already in `PATH`
- Scripts live under `e2e/cases/bpftrace/scripts/`
- The case auto-builds `micro_exec` and the daemon CLI if they are missing
- `--vm` is not supported in `e2e/run.py`
- Smoke example: `python3 e2e/run.py bpftrace --smoke`

### scx

- No setup script; the case auto-builds `daemon/target/release/bpfrejit-daemon` and `corpus/repos/scx/target/release/scx_rusty` if needed
- Uses `corpus/build/scx/scx_rusty_main.bpf.o`
- Requires at least one workload generator in `PATH`: `hackbench`, `stress-ng`, or `sysbench`
- Supports `--vm` and requires `--kernel` when enabled
- Smoke example: `python3 e2e/run.py scx --smoke`

### Katran

- Setup helper: `e2e/cases/katran/setup.sh`
- Uses `corpus/build/katran/balancer.bpf.o` plus the live DSR topology helper assets in the case directory
- Supports `--vm` and requires `--kernel` when enabled
- Smoke example: `python3 e2e/run.py katran --smoke`
