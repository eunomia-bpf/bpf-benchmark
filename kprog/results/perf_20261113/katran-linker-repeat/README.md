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


2026-11-16T10:39:58Z: completed May-linker comparison and restored current image.

Both cases finished app OK / Make 0 through the unchanged stats-off entry,
with three 180-second samples in each sequential arm:

| Linker | eBPF successful pps series | Native successful pps series | Native/eBPF by ordinal sample | Ratio of phase medians | Installed native B |
|---|---|---|---|---:|---:|
| Current LTO | 2313080 / 2575600 / 2743354 | 2883180 / 2906745 / 2885492 | 1.2465 / 1.1286 / 1.0518 | 1.120318372 | 12990 |
| May reference | 2513764 / 2824571 / 2620302 | 2735755 / 2938609 / 3192751 | 1.0883 / 1.0404 / 1.2185 | 1.121477219 | 10196 |

The May case is x86_kvm_corpus_20261116_095730_161987. Its eBPF and
native medians are 2620302 and 2938609 pps; eBPF code remains 13641 B.
Ordinal ratios pair sample indices across sequential phases, rather than
concurrent or randomized matched trials. Current native throughput stays near
2.89 Mpps while its eBPF series rises; the May native series rises while its
eBPF series varies. The approximately 0.1% difference between the median
ratios is much smaller than either series' spread. These observations do not
isolate an earlier throughput regression to LTO. The median is one summary
of the recorded series, with host-load variation retained as a caveat.

The May linker omits the three previously identified LRU lookups and their
reference-bit writes. This comparison preserves that work difference and is
not evidence of equal-work target completion. Stats are off in both cases,
so per-call and body time remain unmeasured. The current P entry is still
7965 B; installed native code includes generated routines and glue. The
operator's per-call, throughput, native speed and code-size targets stay open.

pair-analysis.json retains both complete analyses, generated with:

```sh
make -r -f kprog/test/katran-accounting.mk comparison-analysis \
  COMPARISON_RUNS='--run current corpus/results/x86_kvm_corpus_20261116_092956_863537 --run may corpus/results/x86_kvm_corpus_20261116_095730_161987' \
  OUTPUT=/workspaces/kprog-raw/perf/20261116-katran-linker-repeat-after-overlap/analysis-pair-series
```

The comparator restored the sole current image 3a1906ab1d4f at 10:23:17 UTC.
The queued default rotate started at 10:23:18 UTC under controller 1451239;
its log is /workspaces/kprog-raw/one-image-runs/rotate-20261116T0924Z-after-repeat-perf.log.
The earlier interrupted comparison and all its raw data remain available.
