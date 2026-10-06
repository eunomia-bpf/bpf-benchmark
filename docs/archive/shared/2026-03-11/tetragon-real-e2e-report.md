# Tetragon Real E2E Report

## Summary

- Task: `#74`
- Date: `2026-03-11`
- Kernel: `7.0.0-rc2-g2a6783cc77b6` from `vendor/linux-framework/arch/x86/boot/bzImage`
- Mode: `manual_fallback`
- Result: the new `e2e/cases/tetragon/` benchmark ran successfully inside the framework-kernel VM, persisted JSON/Markdown outputs, and collected application throughput + controller CPU + BPF runtime deltas before and after `BPF_PROG_JIT_RECOMPILE`.

## What Was Added

- `e2e/cases/tetragon/case.py`
- `e2e/cases/tetragon/setup.sh`
- `e2e/cases/tetragon/guest_smoke.sh`
- Shared helper extensions:
  - explicit `bpftool` resolution via `BPFTOOL_BIN` / `BPFTOOL`
  - rapid `open` / `connect` workload wrappers
  - root-safe exec-storm fallback using a real `/bin/true` exec loop

## VM Run

Successful persistence command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --cwd /home/yunwei37/workspace/bpf-benchmark \
  --disable-monitor \
  --cpus 2 \
  --mem 4G \
  --rwdir /home/yunwei37/workspace/bpf-benchmark/e2e/results \
  --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp \
  --exec './e2e/cases/tetragon/guest_smoke.sh'
```

Guest command path:

```bash
export PATH="/usr/local/sbin:$PATH"
export BPFTOOL_BIN="/usr/local/sbin/bpftool"
. /home/yunwei37/workspace/.venv/bin/activate
PYTHONPATH=micro python3 e2e/cases/tetragon/case.py --smoke
```

## Result Artifacts

- `e2e/results/tetragon-real-e2e.json`
- `e2e/results/tetragon-real-e2e.md`

## Outcome

Overall smoke summary:

- App throughput mean: `340697.33 -> 354538.24 ops/s` (`+4.06%`)
- Controller CPU mean: `50.56% -> 48.01%` (`-5.04%`)
- BPF avg ns mean: `443.34 -> 409.96 ns` (`-7.53%`)

Per-program aggregate:

| Program ID | Attach target | Sites | Stock avg ns | ReJIT avg ns | Speedup |
| --- | --- | ---: | ---: | ---: | ---: |
| `9` | `syscalls/sys_enter_execve` | `37` | `2649.13` | `2611.66` | `1.014x` |
| `21` | `security_file_open` | `2` | `219.56` | `219.35` | `1.001x` |
| `34` | `security_socket_connect` | `2` | `293.11` | `272.59` | `1.075x` |

Per-workload application / CPU deltas:

| Workload | App ops/s baseline | App ops/s post | App delta | CPU delta | BPF avg ns delta |
| --- | ---: | ---: | ---: | ---: | ---: |
| `connect_storm` | `12949.46` | `30400.09` | `+134.76%` | `-10.17%` | `-6.77%` |
| `file_io` | `1071625.99` | `1107526.14` | `+3.35%` | `n/a` | `-13.45%` |
| `open_storm` | `278037.68` | `280052.47` | `+0.72%` | `-0.12%` | `-0.08%` |
| `stress_exec` | `176.17` | `174.26` | `-1.09%` | `+5.88%` | `-4.75%` |

## Notes

- The guest did not have a usable `tetragon` binary after setup, so the benchmark took the explicitly allowed fallback path: direct loading of `corpus/build/tetragon/bpf_execve_event.bpf.o` and `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`.
- `BPF_PROG_JIT_RECOMPILE` still applied successfully to all three loaded programs in the VM.
- `events_total` / `events_per_sec` are derived from aggregate BPF `run_cnt` deltas, so they are not unique user-space event counts.
- In fallback mode, the reported “agent CPU” is the benchmark controller process, not a real Tetragon daemon.
