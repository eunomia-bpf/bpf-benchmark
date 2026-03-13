# Corpus Top Regressor Root Cause

Date: 2026-03-13

## Scope And Method

- Main artifact: `corpus/results/corpus_v5_v2_fixed_20260312.json`
- Supporting docs: `docs/tmp/corpus-v2-fixed-rerun.md`, `docs/tmp/policy-improvement-analysis.md`, `docs/tmp/bflip-endian-skip-sweep.md`
- Comparison artifacts:
  - blind: `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
  - tuned: `corpus/results/corpus_v5_tuned_policy.json`
  - branch-flip/endian sweep: `corpus/results/corpus_v5_bflip_skip_sweep_20260312.json`

Sorting rule:

- I sorted measured rows by the artifact field `speedup_ratio = stock_exec_ns / recompile_exec_ns`, ascending.
- Lower `speedup_ratio` means a worse regression.
- For readability I also list `recompile/stock = recompile_exec_ns / stock_exec_ns`.

Important policy caveat:

- The 2026-03-12 fixed-v2 rerun used the old `version: 2` policy format.
- The current worktree has since migrated to `version: 3` explicit-site policies (`da10f84`), so current `corpus/policies/` files do not exactly match the policies that produced the fixed-v2 artifact.
- For fixed-v2 root cause work, the authoritative source is:
  - historical policy snapshot from `git show 9c7d9e1:<policy-path>`
  - runtime-applied site counts embedded in `v5_run.sample.recompile`
- I still inspected current `corpus/policies/` files to confirm post-migration drift.

## Top-10 Regressors

| Rank | Program | stock/recompile | recompile/stock | Stock exec_ns | Fixed-v2 policy snapshot | Runtime-applied sites | Verdict |
| --- | --- | ---: | ---: | ---: | --- | --- | --- |
| 1 | `xdp-tutorial/basic04-pinning-maps:xdp_drop_func` | `0.267x` | `3.750x` | `8` | no policy file (`policy_mode=stock`) | none | sub-ktime noise, no-op |
| 2 | `calico/from_hep_debug:calico_tc_skb_icmp_inner_nat` | `0.303x` | `3.296x` | `189` | historical v2: `default: apply`, `cmov: skip` | `wide=2, endian=28, branch-flip=2` | true regression |
| 3 | `linux-selftests/verifier_const:tcx2` | `0.321x` | `3.120x` | `25` | no policy file (`policy_mode=stock`) | none | sub-ktime noise, no-op |
| 4 | `linux-selftests/test_tc_tunnel:__encap_ip6vxlan_eth` | `0.438x` | `2.286x` | `7` | historical v2: `default: apply` | `extract=1` | sub-ktime noise |
| 5 | `linux-selftests/test_tc_tunnel:__encap_udp_eth` | `0.438x` | `2.286x` | `7` | historical v2: `default: apply`, `cmov: skip` | `endian=1` | sub-ktime noise |
| 6 | `linux-selftests/test_tc_tunnel:__encap_udp_none` | `0.500x` | `2.000x` | `8` | historical v2: `default: apply`, `cmov: skip` | `endian=1` | sub-ktime noise |
| 7 | `calico/xdp_debug:calico_xdp_main` | `0.501x` | `1.994x` | `168` | historical v2: `default: apply` | `wide=4, endian=6, branch-flip=2` | true regression |
| 8 | `calico/to_hep_debug:calico_tc_main` | `0.531x` | `1.883x` | `180` | historical v2: `default: apply`, `cmov: skip` | `wide=10, extract=1, endian=47, branch-flip=4` | true regression |
| 9 | `linux-selftests/test_sockmap_update:copy_sock_map` | `0.533x` | `1.875x` | `8` | historical v2: `default: apply`, `cmov: skip` | none (`cmov` skipped) | sub-ktime noise, no-op |
| 10 | `xdp-tutorial/packet-solutions:_fix_port_egress` | `0.533x` | `1.875x` | `8` | historical v2: `default: apply` | `extract=1, endian=5` | sub-ktime noise |

## Per-Regressor Notes

1. `xdp_drop_func`
   - Fixed-v2 row stayed on stock because there is no matching policy file in `corpus/policies/`.
   - Eligible set was only `branch-flip=1`, but runtime applied no recompile sites.
   - `exec_ns=8`, so this is not actionable policy evidence.

2. `calico_tc_skb_icmp_inner_nat`
   - Historical fixed-v2 policy file: `corpus/policies/calico/from_hep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml` at `9c7d9e1`.
   - Historical semantics were `default: apply` with `cmov: skip`.
   - Current HEAD v3 file is different: explicit allowlist with `wide=2, endian=26` and no branch-flip entries.
   - Fixed-v2 runtime actually applied `wide=2, endian=28, branch-flip=2`, so the March 12 run predates the current v3 file contents.

3. `tcx2`
   - No policy file, no eligible sites, no recompile sites.
   - `exec_ns=25`, so this is pure measurement noise.

4. `__encap_ip6vxlan_eth`
   - Historical fixed-v2 policy was `default: apply`; current v3 file contains exactly one `extract` site.
   - Fixed-v2 runtime applied `extract=1`.
   - `exec_ns=7`, so the regression is below measurement resolution.

5. `__encap_udp_eth`
   - Historical fixed-v2 policy was `default: apply` plus `cmov: skip`; current v3 file contains one `endian` site.
   - Fixed-v2 runtime applied `endian=1` and skipped `cmov`.
   - `exec_ns=7`, so this is not trustworthy.

6. `__encap_udp_none`
   - Same pattern as `__encap_udp_eth`: historical `cmov: skip`, current v3 `endian=1`, fixed-v2 runtime `endian=1`.
   - `exec_ns=8`, so this is not trustworthy.

7. `calico_xdp_main`
   - Historical fixed-v2 policy file: `corpus/policies/calico/xdp_debug/calico_xdp_main.policy.yaml` at `9c7d9e1`.
   - Historical semantics were `default: apply`.
   - Current HEAD v3 file now only lists `wide=4, endian=6`; current file no longer includes branch-flip.
   - Fixed-v2 runtime applied `wide=4, endian=6, branch-flip=2`, again showing policy drift after the March 12 rerun.

8. `calico_tc_main`
   - Historical fixed-v2 policy file: `corpus/policies/calico/to_hep_debug/calico_tc_main.policy.yaml` at `9c7d9e1`.
   - Historical semantics were `default: apply` plus `cmov: skip`.
   - Current HEAD v3 file lists `wide=10, extract=1, endian=45`; current file no longer includes branch-flip.
   - Fixed-v2 runtime applied `wide=10, extract=1, endian=47, branch-flip=4`, so March 12 again used the older v2 default-apply behavior.

9. `copy_sock_map`
   - Historical fixed-v2 policy was `default: apply` plus `cmov: skip`.
   - Current v3 file is empty (`sites: []`).
   - Fixed-v2 runtime applied no sites because the only eligible family was `cmov`, and it was skipped.
   - `exec_ns=8`, so this is a no-op noise row.

10. `_fix_port_egress`
   - Historical fixed-v2 policy was `default: apply`.
   - Current v3 file contains `extract=1, endian=5`, matching the runtime-applied family mix.
   - `exec_ns=8`, so this is still sub-ktime noise.

## Sub-Ktime Rows Are Not Real Regressors

Seven of the top ten are below `100ns` stock runtime:

- `xdp_drop_func` (`8ns`)
- `tcx2` (`25ns`)
- `__encap_ip6vxlan_eth` (`7ns`)
- `__encap_udp_eth` (`7ns`)
- `__encap_udp_none` (`8ns`)
- `copy_sock_map` (`8ns`)
- `_fix_port_egress` (`8ns`)

These rows are unstable across adjacent artifacts:

- `__encap_udp_eth`: blind `1.250x`, tuned `1.143x`, fixed `0.438x`
- `_fix_port_egress`: blind `0.900x`, tuned `1.000x`, fixed `0.533x`
- `tcx2`: blind `1.077x`, tuned `0.963x`, fixed `0.321x`

Conclusion:

- These seven rows should be treated as measurement noise or no-op rows, not as evidence of real harmful lowerings.

## True Regressions: Root Cause Hypotheses

Only three top-10 rows are both `ratio < 0.95x` and `stock exec_ns >= 100`:

- `calico/from_hep_debug:calico_tc_skb_icmp_inner_nat`
- `calico/xdp_debug:calico_xdp_main`
- `calico/to_hep_debug:calico_tc_main`

### 1. `calico/from_hep_debug:calico_tc_skb_icmp_inner_nat`

Evidence:

- blind run: `cmov + wide`, `0.738x`
- tuned run: `wide + endian + branch-flip`, `0.628x`
- fixed-v2 run: `wide + endian + branch-flip`, `0.303x`
- branch-flip/endian sweep on the same program:
  - round1 (`wide + endian + branch-flip`): `0.972x`
  - round2 (`wide + endian`, branch-flip skipped): `1.079x`
  - round3 (`wide` only, branch-flip + endian skipped): `1.023x`
- round1 and round2 have the same `size_ratio = 1.0039745`, so the improvement from skipping branch-flip is not explained by code-size/alignment changes.

Most likely culprit:

- Primary: `branch-flip`
- Secondary: possible run-to-run amplification/noise

Hypothesis:

- `c) optimization is actually slower on this CPU/workload`
- `d) measurement noise` amplifies the fixed-v2 outlier magnitude

Not supported by current data:

- `a) emitter bug`: not the leading explanation, because the same program recovers to `>1.0x` in the sweep without any correctness signal changing.
- `b) code layout shift`: weak, because removing branch-flip improved performance with unchanged size ratio.

Verifiable fix:

- Add a per-program policy that skips `branch-flip` for this program first.
- Rerun with `repeat >= 1000`.
- Run `perf stat` on stock vs fixed-v2 vs branch-flip-skip:
  - `cycles`
  - `instructions`
  - `branches`
  - `branch-misses`
- If the regression remains deterministic after that, dump the JIT image before/after to rule out a hidden emitter issue.

### 2. `calico/xdp_debug:calico_xdp_main`

Evidence:

- blind run: `wide` only, `1.097x`
- tuned run: `wide + endian + branch-flip`, `0.783x`
- fixed-v2 run: `wide + endian + branch-flip`, `0.501x`
- branch-flip/endian sweep on the same program:
  - round1 (`wide + endian + branch-flip`): `0.609x`
  - round2 (`wide + endian`, branch-flip skipped): `1.133x`
  - round3 (`wide` only, branch-flip + endian skipped): `1.193x`
- round1 and round2 have identical `size_ratio = 1.0142039`, so skipping branch-flip changed performance without changing image size.

Most likely culprit:

- Primary: `branch-flip`
- Secondary: `endian`

Hypothesis:

- `c) optimization is actually slower on this CPU/workload`

Not supported by current data:

- `a) emitter bug`: weak, because wide-only is already positive in blind and in round3.
- `b) code layout shift`: weak, because round1 -> round2 flips from loss to win at the same size ratio.
- `d) measurement noise`: possible, but not needed to explain the direction of the effect.

Verifiable fix:

- Skip `branch-flip` for this program immediately.
- If the goal is maximum gain, also test `endian: skip`.
- Validate with `perf stat` (`cycles`, `instructions`, `branches`, `branch-misses`).
- Confirm that image-size change is negligible; if perf improves while size stays flat, that is strong evidence of a true CPU/workload-sensitive branch-flip regression.

### 3. `calico/to_hep_debug:calico_tc_main`

Evidence:

- blind run: `cmov + wide + extract`, `0.551x`
- tuned run: `wide + extract + endian + branch-flip`, `0.848x`
- fixed-v2 run: `wide + extract + endian + branch-flip`, `0.531x`
- branch-flip/endian sweep on the same program:
  - round1 (`wide + extract + endian + branch-flip`): `1.190x`
  - round2 (`wide + extract + endian`, branch-flip skipped): `1.027x`
  - round3 (`wide + extract`, branch-flip + endian skipped): `0.856x`
- The sweep does not identify one stable harmful family:
  - skipping branch-flip is not clearly better than keeping it
  - skipping endian in addition is worse than round2
  - even `wide + extract` alone still regresses (`0.856x`)
- Size ratio stays essentially flat (`1.00463` -> `1.00322`) while exec time swings a lot.

Most likely culprit:

- No single family is proven by current data.
- The stable residual candidate is `wide + extract`.
- The fixed-v2 `0.531x` point is also inconsistent enough that measurement instability is part of the story.

Hypothesis:

- Primary: `d) measurement noise`
- Secondary: `c) one or both of wide/extract are actually slower on this CPU`

Not supported by current data:

- `a) emitter bug`: no direct evidence yet
- `b) code layout shift`: not the leading explanation, because the size barely changes while runtime swings widely

Verifiable fix:

- Run a targeted per-program family sweep for this program only:
  - `wide` only
  - `extract` only
  - `wide + extract`
  - `cmov + wide + extract`
- Increase `repeat` to at least `1000`.
- Collect `perf stat` (`cycles`, `instructions`, `branches`, `branch-misses`).
- If one of the `wide`/`extract` variants is still deterministically bad, dump stock vs recompile JIT images to rule out an emitter bug.

## Actionable Next Steps

1. Filter or separately remeasure all `stock exec_ns < 100ns` rows.
   - They dominate the top-10 list numerically but are not trustworthy performance evidence.

2. For `calico/from_hep_debug:calico_tc_skb_icmp_inner_nat`, skip `branch-flip` first.
   - This is the cleanest non-CMOV regression with same-size ablation evidence.

3. For `calico/xdp_debug:calico_xdp_main`, skip `branch-flip` first and test `endian: skip` second.
   - The existing sweep already shows a likely win.

4. For `calico/to_hep_debug:calico_tc_main`, do a dedicated `wide`/`extract` family sweep before changing the global policy.
   - Current data do not isolate a single harmful family.

5. For all three high-confidence programs, collect `perf stat`.
   - If `cycles` and `branch-misses` move in the expected direction while image size stays flat, the issue is CPU/workload sensitivity.
   - If perf counters do not explain it, dump JIT images and inspect instruction sequences for a possible emitter problem.

## Bottom Line

- The top-10 list is mostly contaminated by sub-ktime noise: only `3/10` rows are true regressions by the `>=100ns` rule.
- Among those three:
  - `calico_tc_skb_icmp_inner_nat`: `branch-flip` is the leading culprit.
  - `calico_xdp_main`: `branch-flip` is the leading culprit, `endian` is secondary.
  - `calico_tc_main`: current data are inconclusive; treat it as `noise + possible wide/extract regression` until a targeted sweep proves otherwise.
