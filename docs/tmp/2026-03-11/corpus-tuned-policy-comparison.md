# Corpus Tuned Policy Comparison

- Baseline blind all-apply artifact: `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
- Tuned per-program policy artifact: `corpus/results/corpus_v5_tuned_policy.json`
- Baseline summary doc: `docs/tmp/corpus-full-recompile-v6.md`
- Tuned batch summary doc: `docs/tmp/corpus-tuned-policy-results.md`

## Topline

| Run | Measured Pairs | Applied Programs | Exec Geomean (baseline/v5) | Wins | Regressions |
| --- | --- | --- | --- | --- | --- |
| Blind all-apply | 163 | 92 | 0.868x | 40 | 107 |
| Tuned policy (`--use-policy`) | 142 | 94 | 0.898x | 42 | 84 |

- Tuned policy improves the raw corpus geomean from `0.868x` to `0.898x` (`+3.5%` relative), but it is still below break-even (`1.0x`).

## Comparable Measured Subset

The tuned run lost 21 measurements, so the fairest comparison is the 142 programs measured in both runs.

| Subset | Measured Pairs | Blind All-Apply | Tuned Policy |
| --- | --- | --- | --- |
| Shared measured programs | 142 | 0.891x | 0.898x |
| Wins / regressions | 142 | 38 / 90 | 42 / 84 |

- On the shared measured subset, tuned policy still improves the geomean (`0.891x -> 0.898x`) and converts four regressions into wins/non-losses.

## `cmov: skip` Subset

The policy corpus contains 18 `cmov: skip` files. In this run, 15 of those objects contributed 78 programs that were measured in both runs.

| Subset | Programs | Blind All-Apply | Tuned Policy |
| --- | --- | --- | --- |
| `cmov: skip` comparable programs | 78 | 0.841x | 0.866x |
| Wins / regressions | 78 | 17 / 59 | 19 / 53 |

- CMOV application dropped from `79` applied programs / `445` applied CMOV sites in the blind run to `12` programs / `49` sites in the tuned run.
- The `cmov: skip` subset improves materially, but it still does not reach `1.0x`.

## Notable `cmov: skip` Improvements

- `test_tc_tunnel.bpf.o:__encap_ip6gre_mpls` improved from `0.583x` to `1.429x`.
- `test_tc_bpf.bpf.o:cls` improved from `0.583x` to `1.364x`.
- `test_tc_tunnel.bpf.o:decap_f` improved from `0.538x` to `1.286x`.
- `test_tc_change_tail.bpf.o:change_tail` improved from `0.647x` to `1.091x`.
- `from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat` improved from `0.632x` to `1.057x`.

## Remaining Issues

21 programs measured in the blind run were missing from the tuned run:

- 13 due to `micro_exec` reporting `No such file or directory` inside the guest.
- 6 due to `io-mode packet requires an XDP or skb packet context`.
- 1 due to `recompile-branch-flip: no branch_flip sites found in xlated program (234 insns)`.
- 1 due to `micro_exec` permission denied inside the guest.

- Because of these harness failures, the `0.898x` topline should be read together with the 142-program comparable-subset result above.

## Conclusion

- Per-program policy moves the corpus result in the right direction (`0.868x -> 0.898x`) and helps the targeted `cmov: skip` subset (`0.841x -> 0.866x` on comparable programs).
- It does not recover the corpus to `>1.0x`, so the current policy set improves but does not solve the corpus-wide regression problem.
