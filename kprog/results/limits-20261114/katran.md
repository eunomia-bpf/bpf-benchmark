# Katran performance limits, 2026-11-14

Both arms of one run, same guest, same workload, `kprog/perf/profile/phase-profile.py
run --app katran --seconds 60 --cpus 0-7`. Capture `/workspaces/kprog-raw/C/limits/katran`;
corpus run `x86_kvm_corpus_20261114_183513_065331` (`status: ok`); attribution
`bpf-attribution.py` → `attribution.json` / `attribution.txt`.

## What the capture is

`perf record -a -g -e cpu-clock` at 999 Hz for the whole 60 s of each phase, with the
guest's own `kallsyms` saved per phase and the JIT'd program ranges from
`jit-lines.json`. BPF time is **samples whose callchain contains a frame inside a JIT'd
program**. A sample's bucket is the helper the innermost program frame called (the frame
just above it); a sample rooted inside the program is `program_text`. `bpf_prog_*` did
not reach `kallsyms` in this guest, so program identity comes from the JIT address ranges,
not from symbol names.

## Program body against helpers

Shares of the BPF denominator (samples under a BPF program), not of guest CPU time:

| bucket | eBPF | native |
|---|---:|---:|
| program text | 36.2% | 45.2% |
| `bpf_ktime_get_ns` | 34.1% | 39.6% |
| map lookup (LRU/htab) | 25.4% | 13.4% |
| map update | 1.1% | 1.2% |
| other helpers (`bpf_xdp_adjust_head`, …) | 3.2% | 0.6% |
| **BPF samples** | **42 159** | **34 434** |

BPF is 8.86% of guest CPU time in the eBPF arm and 7.90% in the native arm. Everything
else — 91% — is the pktgen driver and the kernel network path, which neither arm changes.

The whole program is one object, `balancer_ingress` (sole entry of both arms' BPF
denominator at 100%).

## Conditional code-generation limit

For a program-text fraction `f` and a program-only speedup `s`, total speedup is
`1 / (1-f+f/s)`; the absolute program-only ceiling is `1/(1-f)`.

Katran is the app where code generation pays the most: `f = 0.362` on the eBPF arm. Under
that denominator assumption:

| program speedup | whole-BPF speedup | whole-app effect |
|---|---:|---:|
| 1.10x | 1.034x | 1.003x |
| 1.30x | 1.091x | 1.008x |
| eliminate program text | 1.567x | 1.033x |

The third row is the point: with 8.86% of guest CPU in BPF at all, **no amount of code
generation can move Katran's throughput by more than about 3%**. Katran is therefore a poor
target for codegen work and a good target for helper work or for confirming a change does
no harm.

Measured `balancer_ingress` ns/invocation in this capture: 121.2 → 105.0 (**1.155x**),
217.1M against 208.4M runs. That is consistent with the native body being absent from
`ktime`/map paths and slightly better in its own text, and it is a single 60 s sample, not
a timing run.

## Note on the profile's own workload

The profile uses one sample of the app's normal workload for each phase, so its throughput
numbers are not timing results. Use it for shares only.
Raw capture: `/workspaces/kprog-raw/C/limits/katran` (`baseline.data`, `post_rejit.data`, per-phase `kallsyms` and `jit-lines.json`, `attribution.txt`). Regenerate the numbers with
`python3 kprog/results/limits-20261114/bpf-attribution.py /workspaces/kprog-raw/C/limits/katran`.
