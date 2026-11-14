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
