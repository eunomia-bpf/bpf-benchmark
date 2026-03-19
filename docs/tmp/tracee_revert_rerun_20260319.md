# Tracee revert kernel rerun (2026-03-19)

## Goal

Use the reverted kernel without the trampoline guard to rerun Tracee E2E and check whether performance returns to the old authoritative result.

Comparison baseline used in this report:

- Old authoritative numbers requested in the task: [`e2e/results/archive/tracee-e2e-real.md`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/archive/tracee-e2e-real.md)
  - `exec_storm` `+6.28%`
  - `file_io` `+7.00%`
- Guarded rerun reference: [`e2e/results/dev/tracee_20260318.md`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tracee_20260318.md)

## Environment checks

- venv activated: `/home/yunwei37/workspace/.venv/bin/activate`
- No other `qemu` or `vng` process before the run
- Kernel repo head before the run:
  - `8c70a729d Revert "bpf: reject recompile for trampoline-attached programs"`
  - `ce3f7a7b0 bpf: reject recompile for trampoline-attached programs`
  - `7de19ef03 bpf_jit_comp: add COND_SELECT site_len=2 guarded-update emitter`
- Rebuilt image present: [`vendor/linux-framework/arch/x86/boot/bzImage`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage)
  - size `18224128`
  - mtime `2026-03-19 07:47`
- `make vm-e2e` does not support `CASES=tracee`; it runs all E2E cases sequentially, so the run used direct `vng`
- No `qemu` or `vng` process remained after the run

Run command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --memory 4G \
  --cpus 2 \
  --rwdir /home/yunwei37/workspace/bpf-benchmark \
  -- bash -lc 'export PATH=/home/yunwei37/workspace/bpf-benchmark/micro/build/vendor/bpftool:$PATH && source /home/yunwei37/workspace/.venv/bin/activate && cd /home/yunwei37/workspace/bpf-benchmark && python3 e2e/run.py tracee --output-json e2e/results/dev/tracee_revert_20260319.json --output-md e2e/results/dev/tracee_revert_20260319.md'
```

Outputs:

- [`e2e/results/dev/tracee_revert_20260319.json`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tracee_revert_20260319.json)
- [`e2e/results/dev/tracee_revert_20260319.md`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tracee_revert_20260319.md)

## Result

- Run finished successfully
- Recompile summary: `13 / 15` programs applied, `applied=true`, no errors
- Workload comparison remained comparable
- `lost_event_count_delta = 0` for all three workloads

| Workload | Old authority | Guarded rerun 2026-03-18 | Revert rerun 2026-03-19 | vs old authority | vs guarded rerun |
| --- | ---: | ---: | ---: | ---: | ---: |
| `exec_storm` | `+6.28%` | `+5.97%` | `+4.40%` | `-1.88 pp` | `-1.58 pp` |
| `file_io` | `+7.00%` | `+1.68%` | `+4.69%` | `-2.31 pp` | `+3.01 pp` |
| `network` | `+1.44%` | `+2.20%` | `+2.18%` | `+0.75 pp` | `-0.01 pp` |

New rerun details:

- `exec_storm`: app `239.52 -> 250.05` bogo-ops/s, `app_delta=+4.40%`, `events_delta=+4.30%`, `bpf_ns_delta=-0.77%`
- `file_io`: app `1136334 -> 1189604` IOPS, `app_delta=+4.69%`, `events_delta=-0.29%`, `bpf_ns_delta=+0.08%`
- `network`: app `7317.44 -> 7477.26` req/s, `app_delta=+2.18%`, `events_delta=+2.18%`, `bpf_ns_delta=-0.53%`

## Conclusion

Performance recovery is mixed, not full.

- Relative to the guarded 2026-03-18 rerun, `file_io` recovered clearly: `+1.68% -> +4.69%` (`+3.01 pp`)
- `exec_storm` did not recover: `+5.97% -> +4.40%` (`-1.58 pp`)
- Relative to the old authoritative target requested in the task, both key workloads are still below the old level:
  - `exec_storm`: `+4.40%` vs `+6.28%`
  - `file_io`: `+4.69%` vs `+7.00%`

Verdict: removing the trampoline guard did not restore Tracee E2E back to the old authoritative `exec_storm +6.28% / file_io +7.00%` result. It improved `file_io` versus the guarded rerun, but not enough to count as full recovery.
