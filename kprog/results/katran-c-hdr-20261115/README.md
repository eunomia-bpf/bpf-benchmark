# Katran on the compile-flag/header route, 2026-11-15

Fixed-frequency follow-up completed19:44:34Z on imagefc5336c2 with all LTO,
including clock linkage. One A/A plus one A/B yields **1.031460x per call** and
**1.031075x mean throughput** after A/A normalization. Native application body
is7965B; installed native code12418B versus JIT13641B. Pure-body runtime needs
matched profiling; these counters include helper work. Full counters, sample
rates, actual link plan/blob metadata and replay are in [fixed-frequency/](fixed-frequency/README.md).
The earlier measurements below retain their original unfixed-frequency scope.

Katran's native objects come from untouched upstream source through compile flags and
one `-include` header. This records what the build produced, what both arms emitted,
and the first timing under the coordinator's 14:03 protocol (one A/A, one A/B).

Batch: `corpus/results/x86_kvm_corpus_20261115_152839_074362` (A/A, both arms eBPF)
and `corpus/results/x86_kvm_corpus_20261115_155520_165744` (A/B, second arm native).
Both `status: ok`, no app error. CPUs 0-7, 3x180 s, `SKIP_REJIT_MODE=norejit`,
`BPFREJIT_CORPUS_BPF_STATS=1`. Raw logs `/workspaces/kprog-raw/C/katran-c-hdr-20261115/timing/`.

## 1. Code size: native body against the JIT's

Program body is the object's own `xdp` section; JIT is `jited_prog_len` of the same
program from the same guest.

| program | native | JIT | native/JIT |
|---|---:|---:|---:|
| `balancer_ingress` | 7 965 | 13 641 | **0.584** |
| `healthchecking` | 1 104 | — | — |
| `healthchecking_ipip` | 384 | — | — |
| `xdp_root` | 72 | — | — |

`balancer_ingress` is the program that carries the traffic; the other three are
attached but their JIT sizes were not captured in this run's stats window.

## 2. Both arms' output

Native load in the A/B run's second start, from
`details/shim-logs/katran.post_rejit.log`:

```
jit-info original fd=19 id=15 type=6 name=balancer_ingres tag=90e1a12c30a4bce5 jited_len=13641 xlated_len=23840
jit-info native   fd=48 id=16 type=6 name=balancer_ingres tag=59f4a931744dcdc6 jited_len=12418 xlated_len=16
replaced prog=balancer_ingres original_fd=19 native_fd=48
```

The baseline log carries no `native` line — the first start is pure eBPF, as the
protocol requires. Both arms ran the same app to completion, 3 samples each, no
dropped-connection or app error in either.

## 3. Per-call time and throughput

Per invocation is primary (kprog/docs/todo.md §0). A/A is the drift floor measured on
the same machine within the same two hours; the native effect is the A/B ratio divided
by the A/A ratio.

| run | arms | per call (ns/inv) | ratio first/second | pps mean | pps median |
|---|---|---:|---:|---:|---:|
| A/A | eBPF → eBPF | 171.81 → 176.41 | 0.974 | 2 596 290 → 2 432 523 (0.937) | 1.012 |
| A/B | eBPF → native | 199.61 → 193.34 | 1.032 | 2 283 933 → 2 347 008 (1.028) | 1.055 |

**Native effect on per-call time: $1.032/0.974 = 1.060$**, i.e. 6.0% faster per
invocation with the A/A drift divided out, on one A/A and one A/B run.

CPU 0-7 busy during each run, from `/proc/stat` around the run: 82.3% (A/A) and
83.4% (A/B) — comparable contention, so the two are on similar footing. The host is
shared (load average 32 at the time), so the A/A drift of 2.7% is real and the
division is what removes it.

Absolute per-call numbers differ between the two runs (171.8 vs 199.6 ns for the same
eBPF program) because they are separate guest boots on a shared host; only the
within-run ratio is used.

## 4. What produced the objects

`flock …/locks/build-c make -C vendor/bpf -j8 native-katran` → 4/4 `proof.ok`, with
`NATIVE_CFLAGS` as `vendor/bpf/Makefile:44-51` has it (`-O3 -g -fPIC -march=native
-mno-red-zone -mgeneral-regs-only`, all optimization flags on) and
`-include katran-compat.h` on the Katran rule only. No file under
`vendor/bpf/katran/` differs from `vendor/repos/katran/`.

Staged objects: `corpus/results/katran-c-hdr-20261115/objects/`.
