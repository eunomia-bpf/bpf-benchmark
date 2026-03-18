# Micro Policy Improvement Results

Date: 2026-03-18

## Summary

I updated the micro benchmark policy set as requested:

- Kept the 6 regressor removals in place:
  - `memcmp_prefix_64`: `sites: []`
  - `branch_flip_dense`: `sites: []`
  - `addr_calc_stride`: `sites: []`
  - `multi_acc_8`: keep only `wide`
  - `bpf_call_chain`: keep only `wide`
  - `large_mixed_500`: removed `branch-flip`
- Added scanner-driven rotate coverage:
  - `rotate64_hash`: new rotate-only policy, 116 sites
  - `large_mixed_1000`: new rotate-only policy, 7 sites
  - `large_mixed_500`: switched to rotate-only, 7 sites
- Tested but then cleared two unstable new rotate policies:
  - `branch_fanout_32`: scanned 8 rotate sites, final policy `sites: []`
  - `packet_rss_hash`: scanned 11 rotate sites, final policy `sites: []`
- Updated `config/micro_pure_jit.yaml` to reference the new policy files.

Final policy set in the repo now has 15 applied micro benchmarks.

## Final Policy State

| Benchmark | Final state |
|---|---|
| `memcmp_prefix_64` | cleared |
| `branch_flip_dense` | cleared |
| `addr_calc_stride` | cleared |
| `multi_acc_8` | `wide` only |
| `bpf_call_chain` | `wide` only |
| `large_mixed_500` | rotate-only, 7 sites |
| `large_mixed_1000` | rotate-only, 7 sites |
| `rotate64_hash` | rotate-only, 116 sites |
| `branch_fanout_32` | scanned, then cleared |
| `packet_rss_hash` | scanned, then cleared |

## Validation Runs

All validation used Makefile as requested:

- Affected subset:
  - `make vm-micro BENCH='rotate_dense cmov_dense rotate64_hash memcmp_prefix_64 branch_flip_dense addr_calc_stride multi_acc_8 large_mixed_500 bpf_call_chain branch_fanout_32 large_mixed_1000 packet_rss_hash' ITERATIONS=3 WARMUPS=2 REPEAT=500`
- Full suite:
  - `make vm-micro ITERATIONS=3 WARMUPS=2 REPEAT=500`

Important environment note:

- The guest VM clock still reported 2026-03-14, so each Makefile run wrote `micro/results/vm_micro_authoritative_20260314.json`.
- I saved distinct copies after each run:
  - `micro/results/vm_micro_policy_iter_r1_subset_20260318.json`
  - `micro/results/vm_micro_policy_iter_r2_subset_20260318.json`
  - `micro/results/vm_micro_policy_iter_r3_subset_20260318.json`
  - `micro/results/vm_micro_policy_improved_full_20260318.json`
  - `micro/results/vm_micro_policy_improved_full_r2_20260318.json`
- The pre-change authoritative baseline was recovered from git `HEAD` for comparison.

## Main Findings

### 1. `rotate64_hash` is the clearest positive addition

`rotate64_hash` improved in every rerun I did:

| Run | KR/K |
|---|---|
| old baseline | 1.011 |
| subset r1 | 0.688 |
| subset r2 | 0.753 |
| subset r3 | 0.821 |
| full r1 | 0.587 |
| full r2 | 0.759 |

This is the strongest evidence from the whole iteration. The new 116-site rotate-only policy should stay.

### 2. `large_mixed_500` looks worth keeping

`large_mixed_500` moved from a `branch-flip` regressor to roughly neutral/slightly positive rotate-only behavior:

| Run | KR/K |
|---|---|
| old baseline | 1.025 |
| subset r1 | 0.873 |
| subset r2 | 0.869 |
| subset r3 | 0.980 |
| full r1 | 1.004 |
| full r2 | 0.960 |

The signal is not huge, but it is much better than the old `branch-flip=3` policy.

### 3. `large_mixed_1000` is mildly promising but not yet stable

| Run | KR/K |
|---|---|
| old baseline | 0.968 |
| subset r1 | 0.866 |
| subset r2 | 0.953 |
| subset r3 | 0.865 |
| full r1 | 0.955 |
| full r2 | 1.049 |

Most reruns were positive, but one full rerun regressed slightly. I left it enabled because the evidence is better than for the two unstable packet/fanout additions.

### 4. `branch_fanout_32` and `packet_rss_hash` were too unstable, so I cleared them

Before clearing:

| Benchmark | old | subset r1 | subset r2 |
|---|---:|---:|---:|
| `branch_fanout_32` | 0.996 | 0.937 | 1.097 |
| `packet_rss_hash` | 1.111 | 0.556 | 1.091 |

These were not stable enough to keep. After clearing them, both remained noisy as non-applied benchmarks, which reinforces that the underlying VM variance is large.

### 5. The full-suite geomean is not stable enough to claim a better headline number

Baseline from the original authoritative file in git:

- Overall: KR/K `0.948874` = `1.0539x`
- Applied-only (old 16 applied benchmarks): KR/K `0.930777` = `1.0744x`

Current final policy set, full rerun #1:

- Overall: KR/K `0.979558` = `1.0209x`
- Applied-only (current 15 applied benchmarks): KR/K `0.960984` = `1.0406x`

Current final policy set, full rerun #2:

- Overall: KR/K `1.078853` = `0.9269x`
- Applied-only (current 15 applied benchmarks): KR/K `1.058271` = `0.9449x`

Interpretation:

- I cannot honestly claim that the final policy set improved the full-suite headline geomean under the current VM setup.
- The variance between full reruns is too large.
- The targeted policy conclusions are stronger than the full-suite geomean conclusions.

## What I Recommend Keeping

Keep:

- `rotate64_hash` rotate-only policy
- `large_mixed_500` rotate-only policy
- `large_mixed_1000` rotate-only policy, but mark as tentative
- all 6 requested regressor removals / trims

Keep cleared:

- `branch_fanout_32`
- `packet_rss_hash`

## Recommended Next Step

If we want a new authoritative number, rerun the final policy set with a more stable setup before replacing the headline result:

- more iterations and warmups
- pinned CPU / performance governor
- ideally a fixed VM environment with lower timing variance

With the current data, the safest claim is:

- policy cleanup succeeded structurally
- `rotate64_hash` is a clear win
- `large_mixed_500` improved versus the old `branch-flip` policy
- full-suite geomean remains dominated by VM noise, so the old March 14, 2026 headline should not be replaced yet
