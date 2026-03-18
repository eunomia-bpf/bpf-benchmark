# Micro Policy Improvement Results

Date: 2026-03-18

## Final Outcome

This round focused on removing the remaining harmful sites from the 2026-03-18 R1 micro policy set, then rerunning the suite with a higher-quality VM configuration.

Final authoritative full-suite run:

- Command: `make vm-micro ITERATIONS=10 WARMUPS=5 REPEAT=1000`
- Result file saved as: `micro/results/vm_micro_authoritative_20260318.json`
- VM-written file remained dated `20260314`, so I copied it manually as requested.

Headline numbers from `micro/results/vm_micro_authoritative_20260318.json`:

- Overall geomean KR/K: `0.981669` = `1.0187x`
- Applied-only geomean KR/K: `0.905682` = `1.1041x`
- Non-applied geomean KR/K: `0.995192`
- Applied benchmarks: `9 / 62`

Interpretation:

- Overall headline speedup is roughly flat versus R1 (`1.021x` -> `1.019x`), slightly lower.
- Applied-only quality is much better (`1.041x` -> `1.104x`), because the loss-heavy applied set was cleaned up aggressively.
- The biggest measurement improvement is noise: non-applied geomean is now `0.995`, much closer to the ideal `1.0`.

## Policy Changes

Scanner-confirmed changes applied to the target regressors:

- `log2_fold`: cleared to `sites: []`
- `switch_dispatch`: cleared to `sites: []`
- `branch_dense`: cleared to `sites: []`
- `multi_acc_8`: cleared to `sites: []`
- `multi_acc_4`: cleared to `sites: []`
- `binary_search`: cleared to `sites: []`
- `cmov_select`: replaced the old CMOV policy with `rotate`-only (`4` sites)

`bounds_ladder` was kept unchanged, per request.

Scanner outcome for rotate substitution:

- Only `cmov_select` had usable replacement `rotate` sites among the 7 target benchmarks.
- The other 6 targets had no `rotate` fallback and were fully cleared.

## Authoritative Full Run

Applied benchmarks in the 10x authoritative rerun:

| Benchmark | Policy | KR/K | Notes |
|---|---|---:|---|
| `rotate_dense` | `256 rotate` | `0.7189` | biggest winner |
| `rotate64_hash` | `116 rotate` | `0.7935` | strong win, keep |
| `cmov_dense` | `26 rotate` | `0.8251` | strong win, keep |
| `large_mixed_500` | `7 rotate` | `0.9410` | mild win |
| `bounds_ladder` | `2 cmov + 2 wide` | `0.9615` | still positive |
| `bpf_call_chain` | `2 wide` | `0.9763` | small positive |
| `large_mixed_1000` | `7 rotate` | `0.9781` | small positive |
| `cmov_select` | `4 rotate` | `0.9950` | effectively neutral; much better than old CMOV path |
| `mixed_alu_mem` | `2 extract + 1 wide` | `1.0133` | only remaining applied regressor |

Results for the 7 specifically targeted regressors:

| Benchmark | Final state | KR/K |
|---|---|---:|
| `log2_fold` | cleared | `1.0083` |
| `switch_dispatch` | cleared | `0.9861` |
| `branch_dense` | cleared | `0.9720` |
| `multi_acc_8` | cleared | `0.9511` |
| `multi_acc_4` | cleared | `1.0631` |
| `binary_search` | cleared | `0.9745` |
| `cmov_select` | rotate-only | `0.9950` |

Important note on the cleared rows:

- `multi_acc_4` still shows `1.063x` despite `sites=0`, which is exactly why the non-applied noise check matters.
- With non-applied geomean at `0.995`, the suite-level noise is now much cleaner, but individual short benchmarks can still drift a few percent.

Largest non-applied deviations in the authoritative run:

- `packet_parse_vlans_tcpopts`: `1.165x` (`20.5ns` vs `20.5ns`, effectively timer noise)
- `memory_pair_sum`: `0.838x` (`11.5ns` vs `5.5ns`, sub-resolution noise)
- `simple_packet`: `1.125x` (`7ns` vs `10ns`, sub-resolution noise)

These outliers are still present, but they are no longer strong enough to distort the suite-level non-applied geomean.

## Follow-up Iteration

Because the authoritative 10x run still had one applied regressor (`mixed_alu_mem`), I tried one additional policy iteration as requested:

- Changed `mixed_alu_mem` from `wide+extract` to `wide`-only
- Reran full suite with `make vm-micro ITERATIONS=3 WARMUPS=3 REPEAT=1000`
- Saved result as `micro/results/vm_micro_followup_mixed_alu_mem_wide_only_20260318.json`

Follow-up result:

- `mixed_alu_mem`: `1.0133` -> `1.0057`
- But non-applied geomean worsened from `0.9952` -> `1.0112`
- Other applied rows became clearly noisier (`rotate64_hash` `1.130x`, `cmov_dense` `0.446x`)

Conclusion:

- The wide-only trim may help `mixed_alu_mem` slightly.
- The 3-iteration follow-up was too noisy to justify changing the final repo policy set.
- I kept the final authoritative policy state aligned with the 10x rerun.

## Files Produced

- Authoritative full run: `micro/results/vm_micro_authoritative_20260318.json`
- Subset validation run: `micro/results/vm_micro_policy_subset_r2_20260318.json`
- Follow-up mixed_alu_mem test: `micro/results/vm_micro_followup_mixed_alu_mem_wide_only_20260318.json`

## Final Recommendation

Keep the current final policy set from the 10x authoritative rerun:

- 6 harmful regressor benchmarks fully cleared
- `cmov_select` switched to rotate-only
- `bounds_ladder` unchanged
- `mixed_alu_mem` kept unchanged for now

The main result to quote is:

- authoritative full-suite: `1.0187x` overall
- authoritative applied-only: `1.1041x`
- non-applied noise floor: `0.995x`

That is the cleanest data point produced in this round.
