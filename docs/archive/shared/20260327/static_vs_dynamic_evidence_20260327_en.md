# Static vs Dynamic Evidence (2026-03-27)

## Scope and Ratio Convention

- This report uses `exec_ratio = rejit / baseline` throughout.
- `exec_ratio > 1.0` means regression.
- `exec_ratio < 1.0` means speedup.
- Many older notes in this repository use the inverse ratio `baseline / rejit`; all numbers below have been converted to the paper-friendly direction.
- Family names are normalized to current daemon/paper terminology:
  - `cmov -> cond_select`
  - `wide -> wide_mem`
  - `endian -> endian_fusion`
  - `branch-flip -> branch_flip`

## Primary Data Sources

- Full-apply authoritative corpus:
  `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
- Selective authoritative corpus:
  `corpus/results/corpus_authoritative_20260320.json`
- Latest raw micro run:
  `micro/results/vm_micro_20260326_201241/details/result.json`
- Clean per-form isolation rerun:
  `docs/tmp/2026-03-12/per-form-rerun-correct-policy.md`
- Policy regeneration note:
  `docs/tmp/20260320/corpus_policy_regen_20260320.md`
- Map-inline targeted corpus artifacts:
  `corpus/results/corpus_vm_batch_20260327_141413/details/result.json`
  `runner/corpus/results/vm_corpus_20260327_170425/details/result.json`
  `corpus/results/vm_corpus_20260327_172402/details/result.json`
- E2E notes and raw artifacts:
  `docs/tmp/20260327/vm_e2e_perf_passes_results_20260327.md`
  `e2e/results/*_20260327_*/details/result.json`
- Static verify:
  `docs/tmp/20260324/static_verify.full_micro.rerun.json`

## Executive Summary

The strongest direct evidence against fixed heuristics comes from the full-apply authoritative corpus artifact. In the `2026-03-11` blind/full-apply run, `63` out of `92` programs that actually changed regressed, a regression rate of `68.5%`. The applied-only geomean is `1.121x`, i.e. a `12.1%` slowdown. Even over all `163` measured pairs, the overall geomean is still `1.152x`.

Selective policy already removes much of this damage. After aligning the `2026-03-11` full-apply artifact and the `2026-03-20` selective authoritative artifact on canonical program identity, the geomean over the `86` common positive-site programs improves from `1.123x` to `1.018x`. There are `60` programs that were rewritten under full-apply but skipped under the selective artifact; their geomean improves from `1.105x` to `1.003x`, essentially back to neutral.

This is still a conservative result. The `2026-03-20` selective artifact is policy-file selective, not a true runtime-aware daemon oracle. So it already shows that "do not always apply" helps, but it is still weaker than the dynamic-policy story the paper wants to argue.

The oracle-style simulation inside the full-apply artifact is even more striking. If we keep only the `29` applied programs with `exec_ratio <= 1.0`, the geomean moves from `1.121x` to `0.849x`. Fixed peepholes are not just "a bit noisy"; they are paying a large profitability penalty on real workloads.

## 1. Micro Evidence: CMOV Is Not the Only Sensitive Family

The cleanest family-level micro evidence comes from the per-form isolation rerun in `docs/tmp/2026-03-12/per-form-rerun-correct-policy.md`:

| Benchmark | Family | Stock -> ReJIT | Exec Ratio | Interpretation |
| --- | --- | ---: | ---: | --- |
| `cond_select_dense` | `cond_select` | `124.0 -> 101.0 ns` | `0.815x` | clear speedup |
| `rotate_dense` | `rotate` | `266.0 -> 172.5 ns` | `0.648x` | clear speedup |
| `extract_dense` | `extract` | `164.0 -> 170.0 ns` | `1.037x` | small regression |
| `endian_swap_dense` | `endian_fusion` | `211.0 -> 199.5 ns` | `0.945x` | small speedup |
| `branch_flip_dense` | `branch_flip` | `239.0 -> 239.5 ns` | `1.002x` | neutral |

The key point is not that `cond_select` wins here. The key point is that it wins only in a pure isolated select-diamond benchmark. That does not contradict the corpus result where `cond_select` is net negative; it supports the paper's argument that the same legal lowering flips sign across workload classes.

The latest raw micro snapshot (`2026-03-26`) is less useful for clean family attribution, but it is still useful as evidence that active kinsn rewrites are not always profitable:

| Benchmark | Applied Pass | Stock -> ReJIT | Exec Ratio | Note |
| --- | --- | ---: | ---: | --- |
| `binary_search` | `wide_mem` | `981 -> 1066 ns` | `1.087x` | branch-heavy case regresses |
| `switch_dispatch` | `wide_mem` | `650 -> 638 ns` | `0.982x` | similar control-flow case is near neutral |
| `log2_fold` | `wide_mem` | `290 -> 278 ns` | `0.959x` | small speedup |
| `rotate_dense` | `rotate` | `224 -> 178 ns` | `0.795x` | strong speedup |
| `extract_dense` | `extract` | `281 -> 148 ns` | `0.527x` | strong speedup |
| `endian_swap_dense` | `endian_fusion` | `114 -> 294 ns` | `2.579x` | strong regression |
| `cond_select_dense` | none | `78 -> 78 ns` | `1.000x` | no rewrite applied in this raw run |
| `cmov_select` | `wide_mem` | `484 -> 1144 ns` | `2.364x` | no longer a clean cmov benchmark |

`cmov_select` is important because it shows benchmark drift. `docs/tmp/20260318/micro_further_optimization_20260318.md` already notes that this benchmark currently has no `cmov` sites in its manifest and instead exposes `rotate=4, wide=6`. So the latest raw regression there should not be used as a direct `cond_select` result. What it does show is that once benchmark intent, site census, and active policy drift apart, fixed-heuristic family attribution becomes unreliable.

If we only count benchmarks in the latest raw micro run where a given family actually fired, the regression shares are:

| Family | Applied Benchmarks | Regressed | Regression Share |
| --- | ---: | ---: | ---: |
| `wide_mem` | `49` | `17` | `34.7%` |
| `rotate` | `13` | `2` | `15.4%` |
| `extract` | `4` | `1` | `25.0%` |
| `endian_fusion` | `1` | `1` | `100%` |
| `cond_select` | `0` | `0` | n/a |
| `branch_flip` | `0` | `0` | n/a |

So the broader statement is defensible: not just `cond_select`, but multiple kinsn-related families can regress. Micro is strongest as workload-sensitivity evidence; corpus is where regression-rate evidence becomes compelling.

## 2. Corpus: Most Full-Apply Rewrites Regress

### 2.1 Overall

From `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`:

- measured programs: `163`
- applied programs: `92`
- regressed among applied: `63 / 92 = 68.5%`
- applied-only geomean: `1.121x`
- all-measured geomean: `1.152x`

This alone is enough to support the claim that a fixed "always apply" kernel peephole policy regresses real workloads.

### 2.2 Per-Pass Regression Rates

The table below uses the practical question the user asked for: when a family actually applied on a program, how often did that program regress? This is not perfect single-family causality, because some programs apply multiple families together, but it is the right operational view for the fixed-vs-dynamic argument.

| Pass | Full-Apply Applied | Full-Apply Regressed | Regression Share | Full-Apply Geomean | Selective Applied | Selective Regressed | Regression Share | Selective Geomean |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `cond_select` | `79` | `53` | `67.1%` | `1.091x` | `0` | `0` | n/a | n/a |
| `extract` | `37` | `29` | `78.4%` | `1.200x` | `0` | `0` | n/a | n/a |
| `wide_mem` | `39` | `28` | `71.8%` | `1.129x` | `15` | `11` | `73.3%` | `1.139x` |
| `rotate` | `2` | `1` | `50.0%` | `1.035x` | `0` | `0` | n/a | n/a |
| `endian_fusion` | n/a | n/a | n/a | n/a | `23` | `15` | `65.2%` | `1.018x` |
| `branch_flip` | n/a | n/a | n/a | n/a | `0` | `0` | n/a | n/a |

Stronger subset evidence:

- pure `cond_select` rows in full-apply: `34` applied, `21` regressed, geomean `1.052x`
- pure `extract` rows in full-apply: `10` applied, `10` regressed, geomean `1.465x`
- pure `wide_mem` rows in full-apply: `2` applied, `0` regressed, geomean `0.924x`
- pure `endian_fusion` rows in selective: `11` applied, `5` regressed, geomean `0.953x`
- `endian_fusion + wide_mem` rows in selective: `12` applied, `10` regressed, geomean `1.081x`

Two conclusions follow:

- `cond_select` is clearly policy-sensitive, but it is not the only problem family.
- `extract` and `wide_mem` are also not safe blanket defaults. In particular, `extract` is close to systematically unprofitable in the full-apply corpus artifact.

`rotate` should be treated more carefully: the applied corpus sample is still small, so it is better used as supporting "not guaranteed win" evidence than as a main regression-rate argument.

### 2.3 Combination-Level Results

The most common applied family combinations in full-apply are:

| Family Combination | Programs | Regressed | Geomean |
| --- | ---: | ---: | ---: |
| `cond_select` | `34` | `21` | `1.052x` |
| `cond_select + extract + wide_mem` | `18` | `14` | `1.147x` |
| `cond_select + wide_mem` | `18` | `13` | `1.134x` |
| `extract` | `10` | `10` | `1.465x` |

This aligns with the paper outline's "combination interference" story: code-size effects may compose, but execution-time effects do not. In realistic programs, combinations often get worse.

## 3. "Always Apply" vs "Selective"

### 3.1 Oracle Selective Inside the Full-Apply Artifact

If we treat the `2026-03-11` full-apply artifact as the closest available proxy for "always apply all passes", then:

- always apply: `92` applied rows, geomean `1.121x`
- oracle selective: keep only the `29` applied rows with `exec_ratio <= 1.0`, geomean `0.849x`

So the regression cost of a fixed heuristic is not a corner case; it dominates the applied subset.

### 3.2 Same-Program Alignment: Full-Apply vs Selective

Aligning the `2026-03-11` full-apply artifact and the `2026-03-20` selective artifact by canonical program identity:

- common positive-site programs: `86`
- full-apply geomean on common set: `1.123x`
- selective geomean on common set: `1.018x`
- full-apply regressions on common set: `59`
- selective regressions on common set: `49`

The more important subset is the skip set:

- `60` programs were rewritten under full-apply but skipped under selective
- those `60` programs have geomean `1.105x` under full-apply
- the same canonical programs have geomean `1.003x` under the selective artifact

So even before introducing full runtime awareness, simply not blanket-applying families already removes most of the damage.

### 3.3 Representative Same-Program Examples

These examples are especially useful for the paper because they show sign flips or major shrinkage in loss on the same real program:

| Program | Full-Apply | Selective | Interpretation |
| --- | ---: | ---: | --- |
| `tracee:tracee.bpf.o:cgroup_skb_ingress` | `1.625x` | `1.000x` | skipping `cond_select/extract` removes the loss |
| `tracee:tracee.bpf.o:cgroup_skb_egress` | `1.444x` | `1.083x` | same direction, much smaller loss |
| `katran:healthchecking.bpf.o:healthcheck_encap` | `1.889x` | `1.000x` | pure `cond_select` loss disappears |
| `calico:to_hep_debug.bpf.o:calico_tc_main` | `1.815x` | `0.973x` | large regression flips to small win |
| `calico:from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | `1.784x` | `0.972x` | large regression flips near neutral/small win |
| `xdp-tutorial:xdp_prog_kern.bpf.o:xdp_redirect_func` | `0.909x` | `2.750x` | selective can still choose badly, which strengthens the need for runtime-aware policy |

These are cross-artifact comparisons, so they should not be framed as a strict controlled A/B experiment. They are still strong qualitative support because they directly show that the same real program can change sign depending on whether families are blanket-applied or skipped.

## 4. Dense-Site / I-Cache Directional Evidence

Using total candidate sites as a rough proxy for dense rewrite pressure, the full-apply artifact shows:

- `9 / 10` of the top-10 most site-heavy applied rows regress
- the geomean for those top-10 dense rows is `1.233x`
- this is materially worse than the full-apply applied overall geomean of `1.121x`

Representative rows:

| Program | Sites | Exec Ratio | Applied Families |
| --- | ---: | ---: | --- |
| `tracee:tracee.bpf.o:cgroup_skb_ingress` | `121` | `1.625x` | `cond_select, extract, wide_mem` |
| `tracee:tracee.bpf.o:cgroup_skb_egress` | `121` | `1.444x` | `cond_select, extract, wide_mem` |
| `katran:balancer.bpf.o:balancer_ingress` | `34` | `1.182x` | `cond_select, extract, rotate, wide_mem` |
| `calico:from_hep_debug.bpf.o:calico_tc_main` | `33` | `1.075x` | `cond_select, extract, wide_mem` |
| `calico:from_wep_debug.bpf.o:calico_tc_main` | `29` | `1.343x` | `cond_select, wide_mem` |
| `calico:to_hep_debug.bpf.o:calico_tc_main` | `26` | `1.815x` | `cond_select, extract, wide_mem` |

This does not by itself prove that I-cache or code layout is the only mechanism, but it is consistent with the paper's argument: once rewrites become dense and multiple families interact, locality/layout/interference costs become more likely.

The latest raw micro run shows the same direction on a synthetic dense case: `mega_basic_block_2048` applies `262` `wide_mem+rotate` sites and regresses from `754` to `900 ns`, i.e. `1.194x`.

## 5. Map Inline: Real Structural Value, Still Not a Blanket Runtime Win

`map_inline` is not one of the original kinsn lowerings, but it deserves separate treatment because it shows a different form of value: not just the direct rewrite, but the optimization cascade it unlocks.

### 5.1 Compile-Only Structural Value

From `corpus/results/corpus_vm_batch_20260327_141413/details/result.json`:

- program: `katran:balancer.bpf.o:balancer_ingress`
- `map_inline`: `sites_found=64`, `sites_applied=7`, `sites_skipped=57`
- same compile also applies `wide_mem=4` and `endian_fusion=2`
- native code: `13645 -> 13584`, shrink of `61 B`
- xlated size: `23872 -> 23776`, shrink of `96 B`
- no comparable runtime sample in this artifact

### 5.2 The Cascade Is Real, But Runtime Can Still Regress

From `runner/corpus/results/vm_corpus_20260327_170425/details/result.json`:

- `map_inline`: `sites_found=107`, `sites_applied=43`, `sites_skipped=64`
- then `const_prop` fires for `47` sites across two rounds
- then `dce` fires for `90` sites across two rounds
- native code: `13645 -> 12864`, shrink of `781 B`
- xlated size: `23872 -> 22672`, shrink of `1200 B`
- runtime: `1749 -> 2288 ns`, i.e. `1.308x` regression

So `map_inline` absolutely does have unique structural value: it can unlock `map_inline -> const_prop -> dce`. But that does not imply blanket throughput wins.

### 5.3 Even Map-Inline-Only Can Regress Hard

From `corpus/results/vm_corpus_20260327_172402/details/result.json`:

- `map_inline`: `sites_found=66`, `sites_applied=2`, `sites_skipped=64`
- native code: `13656 -> 13634`, shrink of only `22 B`
- runtime: `1474 -> 3096 ns`
- `exec_ratio = 2.100x`

So even `map_inline` by itself is not an always-win pass.

### 5.4 About the Reported `2.0x` Katran Speedup

`docs/tmp/20260327/katran_map_inline_perf_results_20260327.md` cites
`runner/corpus/results/vm_corpus_20260327_152626/metadata.json`,
which does record `exec_ratio_geomean = 2.0` in the old direction and a `map_inline` hit.

However, that artifact does not preserve a `details/result.json`, so it cannot be re-checked the same way as the detailed artifacts above. It is useful as supporting background showing that positive cases exist, but it should not be the primary evidence in this report.

### 5.5 Map Inline Takeaway

- `map_inline` has genuine unique value because it unlocks follow-on simplification and code-size shrink.
- Its runtime profitability is still unstable.
- Therefore `map_inline` also supports "dynamic > static"; it does not support "just turn on another always-on pass".

## 6. E2E and Static Verify: The Problem Is Profitability, Not Safety

`docs/tmp/20260324/static_verify.full_micro.rerun.json` is clear:

- `62 / 62` programs are verifier-accepted
- `53` programs truly apply rewrites
- applied-only average `insn delta = -42.3`
- applied-only average `code delta = -188.3 B`

So the current bottleneck is not safety. The bottleneck is whether the pass should fire on this workload.

The latest `2026-03-27` E2E artifacts do not support a clean corpus-style per-pass regression table because:

- Tracee and Tetragon have verifier rejection or incomparable post-rejit measurements
- SCX lacks post-rejit measurement
- the latest Katran artifact fails earlier during map capture

Still, E2E provides two useful directional pieces of evidence:

- `docs/tmp/20260327/vm_e2e_perf_passes_results_20260327.md` shows that real live workloads do expose many `cmov/branch-flip/endian/wide` opportunities. The issue is not that these patterns exist only in corpus and not in real systems.
- The two same-day Katran live artifacts
  `e2e/results/katran_e2e_live_20260327_065733_20260327_135738/details/result.json`
  and
  `e2e/results/katran_live_20260327_070135_20260327_140143/details/result.json`
  enumerate exactly the same static site mix, `wide_mem=4 endian_fusion=2 total=6`, but one reports `bpf_speedup_ratio = 1.016x` while the other reports `0.988x`.

That second point is especially valuable for the paper. If the static site summary is identical while runtime profitability crosses the `1.0x` boundary, then a static heuristic does not carry enough information by itself.

## 7. Strongest Evidence for "Dynamic > Static"

The four strongest pieces of evidence are:

1. The full-apply authoritative corpus gives a direct regression rate.
   `63 / 92 = 68.5%` regressions among programs that actually changed, with applied-only geomean `1.121x`.

2. Same-program selective alignment already shows that simply not blanket-applying families helps.
   On the `86` common positive-site programs, full-apply is `1.123x` while selective is `1.018x`.
   On the `60` programs skipped by selective, the geomean moves from `1.105x` to `1.003x`.

3. CMOV is not the only family that fails under fixed policy.
   In full-apply:
   `cond_select` regression share is `67.1%`,
   `extract` is `78.4%`,
   `wide_mem` is `71.8%`.
   In selective:
   `endian_fusion` still regresses in `65.2%` of applied rows.

4. Dense-site programs and live E2E both show runtime-context sensitivity.
   The top-10 site-heavy full-apply rows regress `9/10` times with geomean `1.233x`.
   Katran live E2E shows both `1.016x` speedup and `0.988x` slowdown under the same static site mix.

## 8. Conclusion

The current data is already strong enough to support the paper's core claim: fixed kernel peepholes or fixed heuristics cause systematic regressions on real workloads, and the decision to apply a family must be policy-controlled rather than hardcoded.

If the paper focuses only on `cond_select`, the argument still works, but it is narrower than the data now supports. The stronger framing is:

- `cond_select` is the clearest policy-sensitive family: isolated dense micro can win, yet corpus full-apply loses often.
- But the problem is broader than `cond_select`; `extract`, `wide_mem`, and `endian_fusion` also show meaningful regression rates.
- So the paper is not merely arguing against one bad heuristic. It is arguing that fixed peephole policy as a class is unreliable on realistic workloads.
- Selective policy already reduces the damage substantially. A runtime-aware daemon policy should only have more information and more opportunities to avoid these losers.

If the paper needs the most persuasive headline numbers, I would prioritize:

- full-apply applied regressions: `63 / 92 = 68.5%`
- full-apply applied-only geomean: `1.121x`
- common positive-site full-vs-selective: `1.123x -> 1.018x`
- skip-set full-vs-selective: `1.105x -> 1.003x`
- pure `extract`: `10 / 10` regressions, geomean `1.465x`
- pure `cond_select`: `21 / 34` regressions, geomean `1.052x`
