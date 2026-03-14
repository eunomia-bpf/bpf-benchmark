# Corpus v2 Fixed Full Rerun

Date: 2026-03-12

## Final Run

- Final artifact: `corpus/results/corpus_v5_v2_fixed_20260312.json`
- Driver markdown: `docs/tmp/corpus-v2-fixed-rerun-driver.md`
- Command:

```bash
python3 corpus/_driver_impl_run_corpus_v5_vm_batch.py \
  --skip-build \
  --use-policy \
  --repeat 200 \
  --output-json corpus/results/corpus_v5_v2_fixed_20260312.json \
  --output-md docs/tmp/corpus-v2-fixed-rerun-driver.md
```

- VM mode stayed on `vm`; no host fallback occurred.
- Final strict-VM summary: measured `156`, applied `91`, code-size geomean `1.004x`, exec geomean `0.875x`.

## Policy Audit

- Policy corpus shape check: `580` policy files, all `default: apply`; `196` files carry only `families: { cmov: skip }`; no file has non-empty `sites`.
- Full-run policy coverage: `109` targets used `policy-file`, `57` targets stayed `stock` on miss-policy.
- Measured subset coverage: `101` measured `policy-file` rows, `55` measured `stock` rows.
- No old-v2-style stale-site symptoms survived into the final summary: there are no `policy site ... was not found` or `policy selected 0 of N` entries in `recompile_failure_reasons`; the only recorded recompile failure is `errno=7` (`Argument list too long`) on `4` rows.

Representative VM validation before the full rerun:

| Case | Target | Observed |
| --- | --- | --- |
| policy-hit | calico/from_hep_debug:calico_tc_maglev | `policy_mode=policy-file`, requested all families, applied `rotate, endian, branch-flip` via `corpus/policies/calico/from_hep_debug/calico_tc_maglev.policy.yaml` |
| policy-miss | test_tc_tunnel:decap_f | eligible `cmov, wide, endian` but `policy_mode=stock`, `requested=false`, `applied=false` |

## Topline

| Run | Measured Pairs | Applied Programs | Exec Geomean (stock/v5) | Wins / Losses |
| --- | --- | --- | --- | --- |
| blind all-apply | 163 | 92 | 0.868x | 40 / 107 |
| v1 tuned | 142 | 94 | 0.898x | 42 / 84 |
| old v2 | 155 | 58 | 0.848x | 47 / 92 |
| fixed v2 | 156 | 91 | 0.875x | 45 / 101 |
| smoke (13-target subset) | 13 | 11 | 1.055x | 4 / 9 |

- Fixed v2 improved over old v2 by `+3.2%` (`0.848x -> 0.875x`).
- Fixed v2 is `+0.8%` above blind all-apply (`0.868x -> 0.875x`).
- Fixed v2 is still `-2.6%` below v1 tuned (`0.898x -> 0.875x`).
- On the strict shared `142`-program overlap measured by blind/v1/old-v2/fixed-v2, geomean is blind `0.891x`, v1 `0.898x`, old v2 `0.847x`, fixed v2 `0.880x`.
- On the `13`-target smoke overlap, standalone smoke was `1.055x` and the same `13` programs inside the full rerun came out at `1.048x`.

## Per-Source

| Project | Blind | v1 | Old v2 | Fixed v2 | Delta vs Old v2 | Delta vs Blind | Fixed Measured | Fixed Wins / Losses |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 0.935x | 0.914x | 0.860x | 0.862x | +0.2% | -7.8% | 59 | 14 / 44 |
| katran | 0.776x | 0.777x | 0.835x | 0.803x | -3.8% | +3.5% | 5 | 2 / 3 |
| libbpf-bootstrap | 0.583x | 0.583x | 0.583x | 0.727x | +24.7% | +24.7% | 1 | 0 / 1 |
| linux-selftests | 0.802x | 0.900x | 0.776x | 0.859x | +10.7% | +7.2% | 63 | 16 / 41 |
| real_world_code_size | 0.622x | n/a | 0.778x | 0.583x | -25.0% | -6.3% | 1 | 0 / 1 |
| suricata | 1.111x | n/a | 1.000x | 1.000x | +0.0% | -10.0% | 1 | 0 / 0 |
| tracee | 0.653x | n/a | 0.784x | 0.615x | -21.6% | -5.7% | 2 | 0 / 2 |
| xdp-tools | 1.003x | 1.040x | 1.019x | 1.045x | +2.5% | +4.2% | 4 | 2 / 1 |
| xdp-tutorial | 0.983x | 0.881x | 1.060x | 1.012x | -4.6% | +2.9% | 20 | 11 / 8 |

Main source-level takeaways:

- `linux-selftests` recovered the most headline signal: `0.776x -> 0.859x`, measured `63`, wins/losses `16 / 41`.
- `calico` barely moved overall: `0.860x -> 0.862x`; it remains below both blind `0.935x` and v1 `0.914x`.
- `xdp-tutorial` stayed above break-even, but fixed v2 gave back part of old-v2's peak: `1.060x -> 1.012x`.
- `tracee` regressed versus old v2 (`0.784x -> 0.615x`), though the sample size is only `2`.

## Key Samples

| Program | Blind | Old v2 | Fixed v2 | Fixed Applied Families |
| --- | --- | --- | --- | --- |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | 0.529x | 0.500x | 0.562x | endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | 16.743x | 1.015x | 24.377x | cmov, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | 1.250x | 0.438x | 0.438x | endian |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | 1.203x | 0.575x | 0.989x | wide, endian, branch-flip |

- `res_spin_lock_test` is the clearest proof that stale-site no-op behavior is gone: fixed v2 re-applies `cmov + branch-flip` and jumps from `1.015x` back to `24.377x`.
- `from_nat_debug:calico_tc_skb_send_icmp_replies` largely recovered (`0.575x -> 0.989x`) but still did not quite reach blind (`1.203x`).
- `healthcheck_encap` improved only marginally in the authoritative full run (`0.500x -> 0.562x`), weaker than the earlier smoke point estimate (`0.850x`).
- `__encap_udp_eth` remained flat at `0.438x`; this matches the diagnosis that the coarse object-level `cmov: skip` heuristic is still the main residual issue for `test_tc_tunnel`.

## Biggest Deltas Vs Old v2

Largest improvements on the shared old-v2/fixed-v2 measured subset:

| Program | Old v2 | Fixed v2 | Delta |
| --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | 1.015x | 24.377x | 23.362x |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | 1.556x | 4.300x | 2.744x |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | 0.643x | 2.000x | 1.357x |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | 0.583x | 1.429x | 0.845x |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | 0.438x | 1.167x | 0.729x |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | 0.583x | 1.286x | 0.702x |

Largest regressions on the shared old-v2/fixed-v2 measured subset:

| Program | Old v2 | Fixed v2 | Delta |
| --- | --- | --- | --- |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | 2.917x | 0.667x | -2.250x |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | 1.214x | 0.267x | -0.948x |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | 1.734x | 0.795x | -0.938x |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 1.871x | 1.084x | -0.787x |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | 1.368x | 0.728x | -0.640x |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | 1.250x | 0.636x | -0.614x |

## Failures And Caveats

- Non-measurement failures are concentrated in baseline/runtime environment issues rather than policy parsing: `{'io-mode packet requires an XDP or skb packet context (exit=1)': 14, 'bpf_object__load failed: Permission denied (exit=1)': 4, 'bpf_object__load failed: Argument list too long (exit=1)': 2}`.
- Recompile failures are limited to `{'BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7)': 4}`.
- The fixed rerun restored application count from `58` to `91`, but it still trails v1 tuned's `94` applied programs.
- Smoke remained directionally predictive on its own subset (`1.055x -> 1.048x` on the same 13-program overlap), but that improvement did not generalize strongly enough across the whole corpus to match v1 tuned.

## Conclusion

- `--use-policy` is now using the repaired per-program v2 policies correctly, and miss-policy rows stay on stock rather than silently falling back to blind all-apply.
- The fixed full rerun materially repaired the old-v2 regression: overall geomean `0.848x -> 0.875x`, with applied programs `58 -> 91`.
- The final fixed-v2 result is now slightly above blind all-apply (`0.868x`) but still below v1 tuned (`0.898x`).
- The remaining optimization target is no longer stale-site policy drift; it is policy content, especially the coarse CMOV denylist on `test_tc_tunnel`-like objects and residual calico regressors.
