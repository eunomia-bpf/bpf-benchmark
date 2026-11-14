# Tracee performance limits, 2026-11-14

Both arms of one run, same guest, same workload, `kprog/perf/profile/phase-profile.py
run --app tracee/monitor --seconds 60 --cpus 0-7`. Capture
`/workspaces/kprog-raw/C/limits/tracee`; corpus run
`x86_kvm_corpus_20261114_185936_709485` (`status: ok`); attribution
`bpf-attribution.py` → `attribution.json` / `attribution.txt`.

Method as in `katran.md`: BPF time is samples whose callchain contains a frame inside a
JIT'd program; a sample's bucket is the helper that the innermost program frame called.

## Program body against helpers

Shares of the BPF denominator:

| bucket | eBPF | native |
|---|---:|---:|
| `bpf_probe_read_kernel` / `_compat` / `_kernel_str` | 46.3% | 30.4% |
| map lookup (htab + compare) | 14.8% | 14.1% |
| **program text** | **12.0%** | **31.8%** |
| `bpf_perf_event_output` | 10.8% | 9.4% |
| `bpf_ktime_get_ns` / `ktime_get_boot_fast_ns` | 9.2% | 9.5% |
| map update | 0.8% | 0.8% |
| other (`bpf_get_current_comm`, `_uid_gid`, `_cgroup_id`, …) | 6.1% | 3.8% |
| **BPF samples** | **237 890** | **222 443** |

Two things stand out, and both matter for the 1.20x target:

1. **Tracee is a BPF-heavy app**: 51.1% of guest CPU time is under a BPF program in the
   eBPF arm. This is the app where whole-app gains from BPF code are largest.
2. **The native arm's program-text share is 2.6x the eBPF arm's** (31.8% against 12.0%)
   while its `probe_read` share falls from 46.3% to 30.4%. The reading: the native body
   inlines or re-implements work that the JIT'd eBPF body calls out to, so its own text
   absorbs the time instead of the helper. Total BPF time still fell (51.1% → 40.3% of
   guest), but the body is now the single largest bucket, which is exactly the shape where
   codegen work pays.

Breakdown of the top helpers, eBPF arm: `bpf_probe_read_kernel` 38.7%,
`bpf_perf_event_output_raw_tp` 10.0%, `ktime_get_boot_fast_ns` 9.1%,
`lookup_nulls_elem_raw` 8.5%, `__htab_map_lookup_elem` 6.3%, `bpf_probe_read_compat`
5.6%, `bpf_get_current_comm` 3.4%.

Per program (share of BPF, inclusive):

| program | eBPF | native |
|---|---:|---:|
| `sys_exit_submit` | 27.3% | 25.4% |
| `trace_sys_enter` | 23.9% | 25.4% |
| `trace_sys_exit` | 23.8% | 25.5% |
| `sys_enter_submit` | 7.1% | 6.7% |
| `sys_enter_init` | 4.8% | 3.2% |
| `trace_ret_vfs_r` | 3.6% | 3.8% |

## Conditional code-generation limit

`f = 0.318` on the native arm — the largest body fraction of the three apps in this set.

| program speedup | whole-BPF speedup | whole-app effect (native, BPF = 40.3%) |
|---|---:|---:|
| 1.10x | 1.030x | 1.012x |
| 1.30x | 1.079x | 1.030x |
| eliminate program text | 1.466x | 1.147x |

Even eliminating the native program body entirely gives about 1.15x end to end on this
capture, short of the 1.20x target. **Tracee cannot be brought to 1.20x through the
program body alone**; a gain that size needs the program body *and* one of the
`probe_read`/output helpers to shrink.

On the eBPF arm's own numbers, `f = 0.120` and BPF is 51.1% of guest; eliminating program
text there gives `1/(1-0.120) = 1.136x` of whole-BPF, `1.065x` end to end. The native
arm's larger body share is the reason it has more room than the eBPF arm would.

## On the profile's workload

One 60 s sample per phase; `stress-ng` bogo ops from this capture are not timing results.
Timing runs for Tracee are in `../tracee-samesource-20261113/README.md` and, for the
image-objects comparison, run `x86_kvm_corpus_20261114_085217_843248` (1.0241x).
Raw capture: `/workspaces/kprog-raw/C/limits/tracee` (`baseline.data`, `post_rejit.data`, per-phase `kallsyms` and `jit-lines.json`, `attribution.txt`). Regenerate the numbers with
`python3 kprog/results/limits-20261114/bpf-attribution.py /workspaces/kprog-raw/C/limits/tracee`.

## The native body's extra time is mostly failed `probe_read`, not inlined work

Added after re-profiling the same capture. The "the native body absorbs helper work"
reading above is wrong in its cause. Walking each sample's callchain and attributing the
frame immediately above the innermost program frame:

| | eBPF arm | native arm |
|---|---:|---:|
| samples whose leaf is on the `bpf_probe_read_kernel` path | 96 238 | 62 884 |
| of those, leaf is `memset` (the helper's EFAULT zero-fill) | **54 (0.06%)** | **14 062 (22.36%)** |
| `memset` anywhere under a program frame, as share of all BPF samples | 1.02% | **6.65%** |

A `memset` leaf under `bpf_probe_read_kernel` is the kernel's failure path
(`bpf_probe_read_kernel_common` in `include/linux/bpf.h`: `copy_from_kernel_nofault`
returns `-EFAULT`, then `memset(dst, 0, size)`). So on the native arm **roughly one read
in four fails where the eBPF arm's reads essentially never do**, and the zero-fill plus
the faulting copy are charged to the program.

Rate by program (native arm, `run_cnt_delta` matched): `trace_sys_enter` 8.0%,
`trace_sys_exit` 8.0%, `sys_exit_submit` 7.5%, `trace_ret_vfs_r` 6.4%,
`trace_security_*` 6.2%, `trace_ret_arch_*` 7.7%. It is uniform across programs, not a
single bad site.

**What this is and is not.** It is a real, measured cost, and removing it is worth about
`1/(1 - 0.0665*0.304*0.4025)` ≈ **1.03x** end to end if the failed reads also stop
faulting — small, not the 1.20x. But it means the 31.8% "program text" bucket is not
purely codegen: part of it is a native-arm defect, so codegen work measured against this
profile has a smaller ceiling than the table above implies.

**Not yet identified:** which read faults. The two arms' `trace_sys_exit` machine code is
identical instruction for instruction (2 129 instructions, differing only in relocated map
pointers and helper target addresses), so the difference is in the data or in the
argument registers at the call, not in the emitted code. The failing call sites resolve to
`common/filtering.h:144-146` (`bpf_map_lookup_elem(filter_map, key)` and the
`equality->` reads) on the native arm's line table. Confirming it needs a guest-side
comparison of the `bpf_probe_read_kernel` argument triple at one site between arms; do not
treat "the native arm's `probe_read` fails 22% more" as a syntax for a known cause.

## Timing, recomputed

`x86_kvm_corpus_20261114_085217_843248`, the image-objects comparison, recomputed from
the raw `stress-ng` payloads as the sum of real-time `bogo ops/s` over stressors (the
`kprog/docs/evaluation.md` metric, not the geometric mean):

| arm | sample 1 | sample 2 | sample 3 | mean |
|---|---:|---:|---:|---:|
| baseline | 497 989 | 494 105 | 521 938 | 504 677 |
| native | 527 333 | 497 467 | 506 032 | 510 277 |

per-sample 1.0589 / 1.0068 / 0.9695, **1.0111x** on the mean. The `1.0241x` quoted
above is the geometric mean of the same samples and is not the documented metric; 1.0111x
is. Either way Tracee is at parity, not at 1.20x, and the consistency with the frozen
0.948x reference (which was measured on a different machine state) is that this app does
not currently move.
