# Tracee Real E2E Report

- Date: `2026-03-11`
- Runner: `python3 e2e/run.py tracee`
- New framework pieces: `e2e/common/{agent,workload,metrics,recompile,vm}.py`, `e2e/cases/tracee/{setup.sh,config.yaml,case.py}`, `e2e/run.py`

## What Changed

- Added a real attach+trigger Tracee benchmark path instead of the old BPF-only `micro/run_e2e_tracee.py` flow.
- The new runner starts Tracee, discovers live agent-owned BPF programs, measures application throughput + Tracee event rate + drops + agent CPU, then runs `scanner/build/bpf-jit-scanner apply --v5`, reruns the workloads, and writes JSON/Markdown reports.
- Added VM support through `vng`, including guest-script generation and shared output persistence.

## Setup Notes

- `tracee` was not available on the host PATH and `apt` did not provide a usable package.
- The old direct GitHub URL `.../releases/latest/download/tracee-x86_64` now returns `404`.
- Current official release packaging on `2026-03-11` is `tracee-x86_64.v0.24.1.tar.gz`.
- The extracted binary cannot live at `/tmp/tracee` anymore because Tracee `v0.24.1` also tries to create `/tmp/tracee` as a runtime/output directory and exits with `mkdir /tmp/tracee: not a directory`.
- `e2e/cases/tracee/setup.sh` now installs the binary at `/tmp/tracee-bin/tracee`.

## Host Smoke

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 e2e/run.py tracee --smoke --duration 10 \
  --tracee-binary /tmp/tracee-bin/tracee \
  --output-json docs/tmp/tracee-real-e2e-host-smoke.json \
  --output-md docs/tmp/tracee-real-e2e-host-smoke.md
```

Environment:

- Kernel: stock host kernel
- Tracee: `v0.24.1`
- Result: JSON valid, baseline metrics collected, host recompile still fails with `BPF_PROG_JIT_RECOMPILE: Invalid argument`

Baseline smoke metrics:

| Workload | App Throughput | Events/s | Agent CPU | BPF avg ns/run |
| --- | ---: | ---: | ---: | ---: |
| `exec_storm` | `28665.52` bogo-ops/s | `39168.78` | `60.67%` | `46.34` |
| `file_io` | `14296.53` IOPS | `28017.74` | `49.10%` | `36.88` |
| `network` | `4380.91` req/s | `5095.46` | `29.60%` | `39.19` |

Host result paths:

- `docs/tmp/tracee-real-e2e-host-smoke.json`
- `docs/tmp/tracee-real-e2e-host-smoke.md`

## Framework-Kernel VM Smoke

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 e2e/run.py tracee --vm \
  --kernel vendor/linux-framework/arch/x86/boot/bzImage \
  --smoke --duration 10
```

Environment:

- Kernel image: `vendor/linux-framework/arch/x86/boot/bzImage`
- Guest kernel: `7.0.0-rc2-g2a6783cc77b6`
- Tracee: `v0.24.1`
- Programs discovered: `15`
- Sites scanned: `21` CMOV, `0` WIDE, `0` ROTATE, `0` LEA
- Programs recompiled successfully: `8 / 15`

Accepted recompile subset:

- `sys_enter_submit`: `2` CMOV sites
- `sys_exit_submit`: `2` CMOV sites
- `syscall__execve*`: `8` CMOV sites across four programs
- `sys_dup_exit_ta*`: `5` CMOV sites
- `tracepoint__sched__*`: `4` CMOV sites

VM before/after smoke comparison:

| Workload | App Delta | Events/s Delta | BPF avg ns Delta | Agent CPU Delta |
| --- | ---: | ---: | ---: | ---: |
| `exec_storm` | `+21.65%` | `+21.16%` | `-2.63%` | `+2.38%` |
| `file_io` | `+5.06%` | `-10.05%` | `-0.19%` | `-50.00%` |
| `network` | `+1.32%` | `+1.26%` | `+1.86%` | `+1.50%` |

Absolute VM smoke metrics:

| Workload | Stock App | ReJIT App | Stock Events/s | ReJIT Events/s |
| --- | ---: | ---: | ---: | ---: |
| `exec_storm` | `159.16` | `193.63` | `1605.82` | `1945.65` |
| `file_io` | `826273.77` | `868049.87` | `37.91` | `34.10` |
| `network` | `5005.82` | `5072.01` | `5021.23` | `5084.46` |

VM result paths:

- `e2e/results/tracee-e2e-real.json`
- `e2e/results/tracee-e2e-real.md`
- `docs/tmp/tracee-real-e2e-vm-smoke.json`
- `docs/tmp/tracee-real-e2e-vm-smoke.md`

## Current Limitations

- The validated runs were smoke runs at `10s` per workload, not full `60s` publication runs.
- The framework kernel still rejects `7 / 15` selected Tracee programs with `BPF_PROG_JIT_RECOMPILE: Invalid argument`; the runner records partial success instead of aborting.
- Host stock-kernel runs remain baseline-only because recompile returns `EINVAL`.
