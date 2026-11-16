2026-11-16T09:57:30Z

Repeat requested after the coordinator recorded another8-vCPU guest overlapping
the first comparison from09:13 to09:20. Original errors and logs remain in
20261116-katran-linker-after-rerun; this repeat has its own raw directory and
uses the unchanged one-image entry, stats0/default3x180/CPUs0-7.

Current LTO case x86_kvm_corpus_20261116_092956_863537 is app OK, Make0:

| Arm | Successful pktgen pps samples | Median pps | Installed code B |
|---|---|---:|---:|
| eBPF | 2313080 / 2575600 / 2743354 | 2575600 | 13641 |
| native | 2883180 / 2906745 / 2885492 | 2885492 | 12990 |

Median throughput native/eBPF =1.120318372x. This current case exceeds the stated
1.113x May floor, but the May-linker comparison is still running. The original
May Katran work difference (three omitted LRU lookups/reference-bit writes)
remains a caveat; it cannot be promoted into an equal-work target result.

Stats are off: per-call and body timing are not measured. P's known7965-byte
entry is distinct from installed code, which includes LTO routines and glue.
Neither the30% throughput target nor native50% speed/code-half targets are
claimed complete. Pktgen sent/error counters stay in raw and analysis; this
metric counts successful sends, not attempts. Counters are not an error gate.

Raw: /workspaces/kprog-raw/perf/20261116-katran-linker-repeat-after-overlap.
Analysis: make -r -f kprog/test/katran-accounting.mk comparison-analysis
COMPARISON_RUNS='--run current corpus/results/x86_kvm_corpus_20261116_092956_863537'.
The May case and complete pair result will be appended when available.
