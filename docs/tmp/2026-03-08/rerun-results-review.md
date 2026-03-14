# Rerun Results Review

## Findings

1. High: `docs/tmp/vm-rerun-analysis.md:43` overstates what the VM comparison shows. The raw numbers are real: `cmov_select` kernel median is `815 ns` on the host and `760 ns` in the VM, so the reported `0.933x` ratio is correct. The inference is not. That delta does not isolate kernel `7.0-rc2`; it also includes bare-metal vs VM, `10/2/500` vs `5/1/200`, unknown VM governor/turbo, and no pinning. The strongest defensible wording is “the VM run measured `0.933x` of the host kernel median on `cmov_select`,” not “kernel `7.0-rc2` was about `6.7%` faster.”

2. High: `docs/tmp/vm-rerun-analysis.md:96` says the guest had “turbo enabled,” but both VM result files record `turbo_state: "unknown"`. `docs/tmp/combined-results-analysis.md:85` gets this right. The VM doc is internally inconsistent with the combined doc and should be corrected.

3. Medium: `docs/tmp/combined-results-analysis.md:51-55` and `docs/tmp/vm-rerun-analysis.md:62-66` present `map_lookup_repeat` as a meaningful VM runtime improvement. The raw values are host kernel `642 ns`, VM kernel `639 ns`, ratio `0.995x`. That is a `3 ns` delta under an uncontrolled host-vs-VM comparison. It is noise, not a “credible improvement” or a “main win.”

4. Medium: `docs/tmp/benchmark-rerun-analysis.md:75` says `simple`, `simple_packet`, and `memory_pair_sum` “dominate” the pure-overlap geomean shift. Excluding them changes the overlap comparison from `0.923x vs 0.811x` (`+13.9%`) to `0.841x vs 0.784x` (`+7.3%`). Those timer-floor cases explain part of the drift, but there is still a substantial non-floor shift left. “Dominate” is too strong.

5. Medium: `docs/tmp/combined-results-analysis.md:69` assigns causes (“register-pressure / callee-saved-adjacent shapes”) that the data here does not establish. The document shows benchmark-level timing deltas, not codegen diffs or a causal analysis tying those deltas to a specific backend change.

6. Medium: `docs/tmp/combined-results-analysis.md:163` is too aggressive about paper readiness. The host `cmov_select` result is strong provisional evidence because the effect size is large (`147.5 ns` vs `815 ns`, `0.181x`) and the code-size gap is large (`970 B` vs `3537 B`). The VM comparison does not materially strengthen that claim because it is not a matched-environment confirmation.

## 1. Data Accuracy

Arithmetic spot-checks are mostly clean. I did not find a numeric mismatch in the values below.

| Ref | Claim | Recomputed from raw JSON | Verdict |
| --- | --- | --- | --- |
| `docs/tmp/combined-results-analysis.md:11` | Pure-JIT full rerun geomean `0.797x` | `exp(mean(log(L/K))) = 0.797305...` over all `50` benchmarks in `micro/results/pure_jit_with_cmov.json` | Correct |
| `docs/tmp/combined-results-analysis.md:12` | Runtime full rerun geomean `0.875x` | `0.874602...` over all `11` benchmarks in `micro/results/runtime_with_map_lookup_repeat.json` | Correct |
| `docs/tmp/combined-results-analysis.md:20` | Pure overlap geomeans `0.923x` vs `0.811x` | `0.923008...` on current `31`-benchmark overlap; `0.810589...` on `micro/results/pure_jit_authoritative.json` | Correct |
| `docs/tmp/combined-results-analysis.md:21` | Runtime overlap geomeans `0.806x` vs `0.826x` | `0.805899...` on current `9`-benchmark overlap; `0.826152...` on `micro/results/runtime_authoritative.json` | Correct |
| `docs/tmp/combined-results-analysis.md:87` and `docs/tmp/benchmark-rerun-analysis.md:60` | Pure-overlap sensitivity `0.841x` vs `0.784x` after excluding `simple`, `simple_packet`, `memory_pair_sum` | `0.841434...` vs `0.784454...` | Correct |
| `docs/tmp/combined-results-analysis.md:88` and `docs/tmp/benchmark-rerun-analysis.md:62` | Runtime-overlap sensitivity `0.775x` vs `0.759x` after excluding `helper_call_1` | `0.775011...` vs `0.758781...` | Correct |
| `docs/tmp/benchmark-rerun-analysis.md:29-32` and `docs/tmp/combined-results-analysis.md:27` | Host `cmov_select`: `147.5 ns` vs `815 ns`, `0.181x` | `147.5 / 815.0 = 0.180982...`; speedup `815 / 147.5 = 5.525...` | Correct |
| `docs/tmp/combined-results-analysis.md:28-30` and `docs/tmp/vm-rerun-analysis.md:39-43` | VM `cmov_select`: host kernel `815 ns`, VM kernel `760 ns`, `0.933x`; VM L/K `165 ns / 760 ns = 0.217x`; code sizes `970 B`, `3537 B`, `3548 B` | Recomputed exactly from `micro/results/pure_jit_with_cmov.json` and `micro/results/vm_pure_jit_with_cmov.json` | Correct |
| `docs/tmp/benchmark-rerun-analysis.md:36-48` and `docs/tmp/combined-results-analysis.md:75-78` | `map_lookup_repeat` old smoke `1744 / 678 = 2.572x`; new runtime `1638 / 642 = 2.551x`; changes `-6.1%`, `-5.3%`, `-0.8%` | `1744/678 = 2.572271...`; `1638/642 = 2.551402...`; relative changes match rounding | Correct |
| `docs/tmp/combined-results-analysis.md:37-39` and `docs/tmp/vm-rerun-analysis.md:24-29` | VM/host kernel geomeans `0.993x`, `1.049x`, `1.003x` | `0.993375...` over `50` pure-JIT benchmarks, `1.049487...` over `11` runtime benchmarks, `1.003267...` combined | Correct |
| `docs/tmp/combined-results-analysis.md:86` | Host floor-sensitive counts: `14/50` pure-JIT, `1/11` runtime | Recomputed by checking benchmarks with at least one median `< 100 ns` | Correct |

Numeric conclusion: the arithmetic is in decent shape. The problems are interpretation and methodology, not basic math.

## 2. Methodology

- The geomean calculations are correct. All three docs are effectively using the geometric mean of per-benchmark median ratios, not a ratio of suite-wide medians. That is the right way to summarize multiplicative benchmark ratios.
- The overlap sets are correct. Pure-JIT overlap with `pure_jit_authoritative.json` is `31` benchmarks; runtime overlap with `runtime_authoritative.json` is `9`. The “new” inventory is also correct: `19` new pure-JIT cases and `2` new runtime cases.
- The inclusion/exclusion logic for the quoted sensitivity checks is correct. The pure overlap excludes exactly `simple`, `simple_packet`, and `memory_pair_sum`; the runtime overlap excludes exactly `helper_call_1`.
- The host rerun comparison is fair only when it stays within the same run. `llvmbpf` vs kernel inside `pure_jit_with_cmov.json` or `runtime_with_map_lookup_repeat.json` is the cleanest evidence in these docs.
- The cross-run overlap comparison is fair only as a provisional trend comparison. `docs/tmp/benchmark-rerun-analysis.md:54-67` and `docs/tmp/combined-results-analysis.md:16-23` do acknowledge that the March 9 rerun is not methodologically matched to the March 7 authoritative run. That caveat is necessary.
- The host-vs-VM comparison is not fair if the prose is trying to isolate kernel version. It conflates kernel version, virtualization, different sampling (`10/2/500` vs `5/1/200`), unknown VM governor/turbo state, and no pinning. The arithmetic is fine; the causal interpretation is not.
- One useful method detail is missing from all three docs: the JSON shows alternating per-iteration runtime order (`llvmbpf,kernel`, then `kernel,llvmbpf`, repeated). That materially supports the claim that within-run L/K comparisons are more trustworthy than cross-run comparisons, and it should be documented.

## 3. Interpretation Issues

- `docs/tmp/vm-rerun-analysis.md:43` is the clearest overclaim. The document turns a host-vs-VM measurement into a kernel-version result. That is not what the data shows.
- `docs/tmp/combined-results-analysis.md:41` is acceptable as a descriptive summary if read literally, but any stronger reading should be avoided. “VM kernel `7.0-rc2` is basically flat against host kernel `6.15.11`” is already flirting with causal language.
- `docs/tmp/combined-results-analysis.md:51-55` and `docs/tmp/vm-rerun-analysis.md:62-66` oversell `map_lookup_repeat`. A `642 ns` to `639 ns` kernel shift is effectively unchanged here.
- `docs/tmp/benchmark-rerun-analysis.md:71-75` over-assigns the pure-overlap drift to the three shortest baselines. The reduced shift (`+7.3%` instead of `+13.9%`) still leaves a large unexplained move toward kernel on the overlap subset.
- `docs/tmp/combined-results-analysis.md:69` is speculation presented too confidently. If the claim is “these wins may reflect register-pressure-sensitive shapes,” say that. Do not present a backend diagnosis that the current evidence does not prove.
- `docs/tmp/combined-results-analysis.md:163` should not say the rerun numbers are paper-citable “today” without a stricter rerun. They are useful provisional evidence. They are not yet clean replacement data.

## 4. Environment Caveats

- The host caveats are mostly acknowledged correctly in `docs/tmp/benchmark-rerun-analysis.md:18-22` and `docs/tmp/combined-results-analysis.md:84`: `powersave`, turbo allowed, no CPU affinity, and lighter sampling. That part is fine.
- The VM caveats are acknowledged, but `docs/tmp/vm-rerun-analysis.md:96` gets turbo wrong. The VM metadata says `unknown`, not enabled.
- The docs correctly note timer-floor sensitivity, but they still give too much rhetorical weight to some very short benchmarks. On the host pure-JIT rerun, `14/50` benchmarks have at least one median below `100 ns`. That is too much floor exposure for these numbers to carry paper-level authority without stronger sensitivity analysis.
- The `100 ns` cutoff is only a heuristic. Benchmarks barely above it are still fragile. Examples: `dep_chain_short` host kernel `107 ns`, `fixed_loop_small` host kernel `101.5 ns`, `local_call_fanout` host kernel `96.5 ns`. These are not good anchors for cross-run or host-vs-VM claims.
- The lack of CPU pinning is acknowledged, but the consequence is understated. With no isolated core, `powersave`, and turbo allowed or unknown, the documents should treat any small percentage delta as suspect by default.

## 5. Missing Analysis

- There is no uncertainty analysis. The JSON contains enough sample data to report IQRs, MADs, or bootstrap confidence intervals, but the docs only report medians and geomeans. That is not enough for publication-facing claims.
- There is no full-suite sensitivity pass that excludes all benchmarks with either side below `100 ns`. The docs only show overlap sensitivity. A paper-facing appendix should include “all current pure-JIT benchmarks above floor” and “all current runtime benchmarks above floor.”
- There is no explicit inventory-diff table. The combined doc mentions `19` new pure-JIT and `2` new runtime cases, but it should list them plainly so readers can see exactly what changed relative to the March 7 baseline.
- There is no attempt to separate VM effects from kernel effects. To make a kernel-version claim, you need either host bare-metal `7.0-rc2`, VM `6.15.11`, or both. Right now the VM section is environment-comparison data wearing kernel-version language.
- The docs do not surface run-order handling, even though the JSON does. That omission makes the methodology read weaker than it actually is.

## 6. Recommendations Before Paper Citation

- Fix `docs/tmp/vm-rerun-analysis.md:43` and `docs/tmp/vm-rerun-analysis.md:96`. Remove kernel-causal wording and correct the turbo-state claim.
- Downgrade `map_lookup_repeat` in the VM sections from “improvement” / “main win” to “effectively unchanged (`642 ns` vs `639 ns`, `0.995x`).”
- Tone down `docs/tmp/benchmark-rerun-analysis.md:75`. The three timer-floor baselines matter, but they do not explain the entire overlap drift.
- Rewrite `docs/tmp/combined-results-analysis.md:69` as hypothesis, not conclusion, unless you add actual codegen evidence.
- Do not cite the March 9 rerun geomeans as authoritative paper numbers yet. At minimum, rerun under matched strict settings: pinned isolated CPU, `performance` governor, turbo disabled, matched `30/5/1000`-class sampling, and at least one independent repeat run.
- Add uncertainty reporting for the paper-facing version. For `cmov_select`, `helper_call_10`, `map_lookup_repeat`, and the suite geomeans, report variability, not just point estimates.
- If `cmov_select` must be mentioned before the strict rerun, label it explicitly as provisional rerun evidence. The large within-run host effect is credible; the VM comparison should not be used as the reason it is credible.

## Bottom Line

The documents are numerically competent. The main fixes are not arithmetic. They are about being stricter with causal language, being honest about noise, and not presenting an uncontrolled host-vs-VM comparison as a kernel-version result. Until the rerun is repeated under matched strict conditions with uncertainty reporting, these numbers are useful internal evidence, not paper-grade authoritative replacements.
