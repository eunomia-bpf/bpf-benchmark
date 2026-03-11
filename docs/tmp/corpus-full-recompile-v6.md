# Corpus Full Recompile v6

- Generated: 2026-03-11T20:59:25.353666+00:00
- Kernel image: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`
- Built kernel source: current `vendor/linux-framework` submodule `e52504a75c05` (this rerun did not use the older `5d99e3842` state mentioned in earlier notes)
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- VM batch JSON: `corpus/results/corpus_v5_vm_batch_full.json`
- VM batch markdown: `docs/tmp/corpus-batch-recompile-results-full.md`

## Scope

- `corpus/directive_census.py` was replaced with a scanner-backed v5 raw census over `corpus/build`.
- `run_corpus_v5_vm_batch.py` target selection was widened from the old 79 site-positive packet targets to all 166 baseline-runnable `packet_test_run` targets, so new scanner-positive programs are no longer filtered out by stale inventory scan data.
- The full VM batch below is therefore the current authoritative live recompile result for the runnable packet-test-run subset, while the raw corpus census remains the authoritative corpus-wide coverage view.

## Fix Validation

- Scanner CLI compatibility: verified `bpf-jit-scanner scan <obj> --v5` positional input support and the `corpus/directive_census.py` census path. Current raw corpus census remains `143 / 560` objects with sites and `14593` total 5-family sites.
- `simple.bpf.o` kernel runner regression: `micro_exec run-kernel micro/programs/simple.bpf.o --repeat 5 --warmup 0` now parses correctly and succeeds in a privileged run. The runner falls back from `map` to `staged` when an object exposes `input_map` but not `result_map`, which fixes the previous `map not found` failure mode.
- Build/test gates used before rerun: `cmake --build scanner/build`, `ctest --test-dir scanner/build`, `make -C micro micro_exec`, host smoke for `directive_census.py`, then the authoritative full `strict-vm` rerun.

## Coverage Delta

| View | Population | Objects/Programs With Sites | Total Objects/Programs | Note |
| --- | --- | --- | --- | --- |
| Old live runnability (March 11) | corpus-wide raw/live hybrid | 69 | n/a | old discovered objects with sites from docs/tmp/corpus-new-directive-census.md |
| New scanner-backed raw census | corpus/build raw ELF scan | 143 | 560 | current corpus/directive_census.py output |
| Old paired recompile scope | baseline-runnable packet targets in old inventory | 79 | 166 | 79 site-positive programs in old packet_test_run subset |
| New full VM batch scope | baseline-runnable packet targets rescanned in VM batch | 95 | 166 | current corpus_v5_vm_batch_full.json |

- Raw corpus coverage moved from `69` old discovered objects with sites to `143` / `560` objects with sites under the new scanner-backed census.
- Within the runnable packet-test-run subset, site-positive programs moved from `79` / `166` to `95` / `166`.
- That adds `16` newly positive programs across `6` objects that were old-zero in the March 11 inventory but now receive live v5 scanning and recompile consideration.

## Family Counts

| Family | Raw Corpus Sites | Raw Corpus Objects | Live VM Batch Sites | Live VM Applied Programs |
| --- | --- | --- | --- | --- |
| CMOV | 9383 | 130 | 446 | 79 |
| WIDE_MEM | 2832 | 32 | 342 | 39 |
| ROTATE | 1820 | 3 | 1840 | 2 |
| BITFIELD_EXTRACT | 544 | 41 | 86 | 37 |
| LEA | 14 | 7 | 0 | 0 |

## VM Batch Summary

| Metric | Value |
| --- | --- |
| Targets attempted | 166 |
| Compile pairs | 163 |
| Measured pairs | 163 |
| Applied programs | 92 |
| Exec ratio geomean (baseline/v5, all measured) | 0.868x |
| Exec ratio geomean (baseline/v5, applied only) | 0.892x |
| Code-size ratio geomean (baseline/v5) | 0.999x |
| Median code-size delta | +0.0% |
| Wins / regressions | 40 / 107 |

### By Source

| Source | Programs | Applied | Sites | Exec Ratio | Code Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 30 | 1900 | 0.802x | 0.996x | 49 |
| calico | 59 | 47 | 516 | 0.935x | 1.001x | 39 |
| xdp-tutorial | 20 | 7 | 14 | 0.983x | 0.999x | 9 |
| katran | 5 | 2 | 35 | 0.776x | 1.004x | 4 |
| xdp-tools | 4 | 3 | 3 | 1.003x | 0.977x | 1 |
| real_world_code_size | 2 | 0 | 0 | 0.622x | 1.000x | 2 |
| suricata | 2 | 1 | 4 | 1.111x | 0.996x | 0 |
| tracee | 2 | 2 | 242 | 0.653x | 1.089x | 2 |
| libbpf-bootstrap | 1 | 0 | 0 | 0.583x | 1.000x | 1 |

### By Family

| Family | Programs | Applied | Sites | Applied Sites | Exec Ratio | Code Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 0.950x | 1.017x |
| cmov | 80 | 79 | 446 | 445 | 0.916x | 0.997x |
| wide | 39 | 39 | 342 | 342 | 0.885x | 1.008x |
| extract | 37 | 37 | 86 | 86 | 0.833x | 1.006x |
| lea | 0 | 0 | 0 | 0 | n/a | n/a |

## Newly Positive Objects

| Object | New Positive Programs | New Sites | Families | Applied Programs | Exec Ratio Geomean |
| --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_wep_debug.bpf.o | 1 | 1 | cmov | 1 | 0.973x |
| corpus/build/calico/to_hep_debug.bpf.o | 1 | 1 | cmov | 1 | 1.074x |
| corpus/build/calico/to_nat_debug.bpf.o | 1 | 1 | cmov | 1 | 0.973x |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o | 2 | 3 | cmov | 2 | 4.092x |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o | 10 | 11 | cmov, extract | 10 | 0.662x |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o | 1 | 1 | extract | 1 | 0.900x |

- All `16` newly positive programs were actually applied in the live VM batch.
- Newly positive programs have an overall exec ratio geomean of `0.917x`.

## Failures

| Program | Reason |
| --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | baseline_compile: bpf_object__load failed: Permission denied (exit=1) ; v5_compile: bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | baseline_compile: bpf_object__load failed: Permission denied (exit=1) ; v5_compile: bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | baseline_compile: bpf_object__load failed: Argument list too long (exit=1) ; v5_compile: bpf_object__load failed: Argument list too long (exit=1) |

## Complete Results

| Source | Program | Old Sites | New Sites | Eligible | Applied Families | Applied | Baseline ns | v5 ns | Exec Ratio | Baseline JIT | v5 JIT | Code Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | 10 | 10 | rotate | rotate | yes | 192 | 174 | 1.103x | 3260 | 3117 | 1.046x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | 23 | 33 | cmov, wide, extract | cmov, wide, extract | yes | 334 | 359 | 0.930x | 46152 | 46072 | 1.002x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 6 | 10 | cmov | cmov | yes | 175 | 228 | 0.768x | 20957 | 20993 | 0.998x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 187 | 301 | 0.621x | 2408 | 2408 | 1.000x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 7 | 8 | cmov, wide | cmov, wide | yes | 183 | 248 | 0.738x | 18440 | 18434 | 1.000x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | 1 | 1 | cmov | cmov | yes | 198 | 174 | 1.138x | 896 | 902 | 0.993x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 8 | 20 | cmov, extract | cmov, extract | yes | 195 | 214 | 0.911x | 23489 | 23502 | 0.999x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | 4 | 6 | cmov, wide | cmov, wide | yes | 173 | 172 | 1.006x | 11888 | 11877 | 1.001x |  |
| calico | corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | 3 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 196 | 225 | 0.871x | 10978 | 10960 | 1.002x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | 16 | 25 | cmov, wide, extract | cmov, wide, extract | yes | 325 | 331 | 0.982x | 33180 | 33131 | 1.001x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 7 | 10 | cmov | cmov | yes | 178 | 182 | 0.978x | 18932 | 18968 | 0.998x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 180 | 207 | 0.870x | 2408 | 2408 | 1.000x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 7 | 9 | cmov, wide | cmov, wide | yes | 187 | 296 | 0.632x | 16630 | 16629 | 1.000x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | 1 | 1 | cmov | cmov | yes | 184 | 175 | 1.051x | 896 | 902 | 0.993x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 7 | 22 | cmov, extract | cmov, extract | yes | 205 | 192 | 1.068x | 21185 | 21206 | 0.999x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | 4 | 6 | cmov, wide | cmov, wide | yes | 213 | 177 | 1.203x | 12004 | 11993 | 1.001x |  |
| calico | corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | 3 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 177 | 191 | 0.927x | 11097 | 11079 | 1.002x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | 16 | 29 | cmov, wide | cmov, wide | yes | 172 | 231 | 0.745x | 36667 | 36626 | 1.001x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 5 | 8 | cmov | cmov | yes | 178 | 177 | 1.006x | 22172 | 22198 | 0.999x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 169 | 184 | 0.918x | 1729 | 1729 | 1.000x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 6 | 9 | cmov, wide | cmov, wide | yes | 171 | 305 | 0.561x | 18044 | 18026 | 1.001x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | 0 | 1 | cmov | cmov | yes | 182 | 187 | 0.973x | 900 | 902 | 0.998x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 3 | 7 | cmov, extract | cmov, extract | yes | 168 | 176 | 0.955x | 18632 | 18646 | 0.999x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | 4 | 5 | cmov, wide | cmov, wide | yes | 212 | 224 | 0.946x | 11762 | 11744 | 1.002x |  |
| calico | corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | 3 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 175 | 201 | 0.871x | 10999 | 10978 | 1.002x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | 10 | 23 | cmov, wide, extract | cmov, wide, extract | yes | 173 | 180 | 0.961x | 22218 | 22219 | 1.000x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | 18 | 26 | cmov, wide, extract | cmov, wide, extract | yes | 178 | 323 | 0.551x | 42747 | 42671 | 1.002x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 7 | 10 | cmov | cmov | yes | 192 | 195 | 0.985x | 21862 | 21900 | 0.998x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 174 | 178 | 0.978x | 2401 | 2401 | 1.000x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 8 | 10 | cmov, wide | cmov, wide | yes | 177 | 182 | 0.973x | 18781 | 18781 | 1.000x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | 0 | 1 | cmov | cmov | yes | 189 | 176 | 1.074x | 902 | 904 | 0.998x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 8 | 20 | cmov, extract | cmov, extract | yes | 174 | 208 | 0.837x | 22542 | 22557 | 0.999x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | 5 | 6 | cmov, wide | cmov, wide | yes | 170 | 179 | 0.950x | 11454 | 11443 | 1.001x |  |
| calico | corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | 4 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 175 | 180 | 0.972x | 10479 | 10460 | 1.002x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | 10 | 23 | cmov, wide, extract | cmov, wide, extract | yes | 192 | 176 | 1.091x | 22100 | 22101 | 1.000x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | 18 | 26 | cmov, wide, extract | cmov, wide, extract | yes | 173 | 187 | 0.925x | 42660 | 42588 | 1.002x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 7 | 10 | cmov | cmov | yes | 174 | 177 | 0.983x | 21739 | 21777 | 0.998x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 176 | 222 | 0.793x | 2401 | 2401 | 1.000x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 8 | 10 | cmov, wide | cmov, wide | yes | 173 | 182 | 0.951x | 18648 | 18648 | 1.000x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | 0 | 1 | cmov | cmov | yes | 177 | 182 | 0.973x | 902 | 904 | 0.998x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 8 | 19 | cmov, extract | cmov, extract | yes | 195 | 180 | 1.083x | 21882 | 21891 | 1.000x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | 5 | 6 | cmov, wide | cmov, wide | yes | 210 | 220 | 0.955x | 11454 | 11443 | 1.001x |  |
| calico | corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | 4 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 174 | 173 | 1.006x | 10479 | 10460 | 1.002x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | 19 | 27 | cmov, wide | cmov, wide | yes | 196 | 192 | 1.021x | 30314 | 30240 | 1.002x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | 4 | 8 | cmov | cmov | yes | 221 | 235 | 0.940x | 13936 | 13966 | 0.998x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | 0 | 0 | none | none | no | 177 | 177 | 1.000x | 1732 | 1732 | 1.000x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | 8 | 8 | cmov, wide | cmov, wide | yes | 173 | 175 | 0.989x | 12395 | 12387 | 1.001x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | 1 | 1 | cmov | cmov | yes | 173 | 175 | 0.989x | 898 | 904 | 0.993x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | 3 | 8 | cmov, extract | cmov, extract | yes | 212 | 177 | 1.198x | 15641 | 15663 | 0.999x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | 5 | 5 | cmov, wide | cmov, wide | yes | 177 | 178 | 0.994x | 8023 | 8010 | 1.002x |  |
| calico | corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | 4 | 7 | cmov, wide, extract | cmov, wide, extract | yes | 174 | 174 | 1.000x | 7250 | 7234 | 1.002x |  |
| calico | corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | 0 | 0 | none | none | no | 169 | 173 | 0.977x | 831 | 831 | 1.000x |  |
| calico | corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | 0 | 0 | none | none | no | 353 | 339 | 1.041x | 1035 | 1035 | 1.000x |  |
| calico | corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | 4 | 4 | wide | wide | yes | 192 | 175 | 1.097x | 4427 | 4379 | 1.011x |  |
| calico | corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | 0 | 0 | none | none | no | 200 | 181 | 1.105x | 125 | 125 | 1.000x |  |
| calico | corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | 0 | 0 | none | none | no | 15 | 22 | 0.682x | 271 | 271 | 1.000x |  |
| calico | corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | 0 | 0 | none | none | no | 15 | 16 | 0.938x | 274 | 274 | 1.000x |  |
| calico | corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | 2 | 2 | wide | wide | yes | 16 | 15 | 1.067x | 1816 | 1788 | 1.016x |  |
| calico | corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | 0 | 0 | none | none | no | 8 | 8 | 1.000x | 31 | 31 | 1.000x |  |
| katran | corpus/build/katran/balancer.bpf.o:balancer_ingress | 29 | 34 | cmov, wide, rotate, extract | cmov, wide, rotate, extract | yes | 11 | 13 | 0.846x | 13412 | 13113 | 1.023x |  |
| katran | corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | 1 | 1 | cmov | cmov | yes | 9 | 17 | 0.529x | 1615 | 1618 | 0.998x |  |
| katran | corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | 0 | 0 | none | none | no | 7 | 11 | 0.636x | 544 | 544 | 1.000x |  |
| katran | corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | 0 | 0 | none | none | no | 8 | 9 | 0.889x | 174 | 174 | 1.000x |  |
| katran | corpus/build/katran/xdp_root.bpf.o:xdp_root | 0 | 0 | none | none | no | 10 | 9 | 1.111x | 188 | 188 | 1.000x |  |
| libbpf-bootstrap | corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | 0 | 0 | none | none | no | 7 | 12 | 0.583x | 111 | 111 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | 0 | 0 | none | none | no | 7 | 12 | 0.583x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | 1 | 1 | cmov | cmov | yes | 9 | 12 | 0.750x | 53 | 59 | 0.898x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | 0 | 0 | none | none | no | 7 | 12 | 0.583x | 253 | 253 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | 0 | 0 | none | none | no | 8 | 12 | 0.667x | 47 | 47 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | 818 | 818 | rotate | none | no | 486 | 548 | 0.887x | 50198 | 50198 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | 2 | 2 | cmov | cmov | yes | 8 | 13 | 0.615x | 403 | 415 | 0.971x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | 1 | 1 | cmov | cmov | yes | 19 | 25 | 0.760x | 254 | 260 | 0.977x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | 0 | 0 | none | none | no | 23 | 36 | 0.639x | 426 | 426 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | 0 | 0 | none | none | no | 264 | 220 | 1.200x | 122 | 122 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | 0 | 0 | none | none | no | 44 | 39 | 1.128x | 151 | 151 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | 0 | 0 | none | none | no | 10 | 18 | 0.556x | 75 | 75 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | 0 | 0 | none | none | no | 10 | 16 | 0.625x | 72 | 72 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | 0 | 0 | none | none | no | 7 | 12 | 0.583x | 42 | 42 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | 0 | 0 | none | none | no | 8 | 8 | 1.000x | 31 | 31 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | 0 | 1 | cmov | cmov | yes | 4487 | 268 | 16.743x | 266 | 272 | 0.978x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | 0 | 0 | none | none | no | 18 | 17 | 1.059x | 114 | 114 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | 0 | 0 | none | none | no | 17 | 17 | 1.000x | 148 | 148 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | 0 | 2 | cmov | cmov | yes | 1000815121 | 1000685007 | 1.000x | 1676 | 1678 | 0.999x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | 0 | 0 | none | none | no | 9 | 12 | 0.750x | 129 | 129 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | 0 | 0 | none | none | no | 11 | 11 | 1.000x | 35 | 35 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | 0 | 0 | none | none | no | 13 | 17 | 0.765x | 107 | 107 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | 0 | 0 | none | none | no | 7 | 7 | 1.000x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | 0 | 0 | none | none | no | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | 0 | 0 | none | none | no | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | 0 | 0 | none | none | no | 8 | 12 | 0.667x | 1244 | 1244 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | 0 | 0 | none | none | no | 8 | 13 | 0.615x | 86 | 86 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | 0 | 0 | none | none | no | 21 | 32 | 0.656x | 115 | 115 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | 1 | 1 | cmov | cmov | yes | 10 | 16 | 0.625x | 171 | 176 | 0.972x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | 1 | 1 | cmov | cmov | yes | 11 | 17 | 0.647x | 392 | 398 | 0.985x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | 1 | 1 | cmov | cmov | yes | 7 | 12 | 0.583x | 557 | 563 | 0.989x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | 1 | 1 | cmov | cmov | yes | 8 | 7 | 1.143x | 526 | 532 | 0.989x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | 1 | 1 | cmov | cmov | yes | 7 | 7 | 1.000x | 513 | 519 | 0.988x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | 0 | 1 | extract | extract | yes | 8 | 16 | 0.500x | 479 | 479 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | 0 | 1 | extract | extract | yes | 7 | 12 | 0.583x | 448 | 448 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | 0 | 1 | extract | extract | yes | 8 | 13 | 0.615x | 435 | 435 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | 0 | 1 | extract | extract | yes | 7 | 12 | 0.583x | 407 | 407 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | 0 | 1 | extract | extract | yes | 8 | 9 | 0.889x | 589 | 589 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | 0 | 1 | extract | extract | yes | 7 | 9 | 0.778x | 558 | 558 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | 0 | 1 | extract | extract | yes | 7 | 12 | 0.583x | 545 | 545 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | 0 | 1 | extract | extract | yes | 10 | 12 | 0.833x | 605 | 605 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | 0 | 1 | extract | extract | yes | 9 | 13 | 0.692x | 491 | 491 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | 1 | 1 | cmov | cmov | yes | 8 | 13 | 0.615x | 505 | 511 | 0.988x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | 0 | 2 | cmov, extract | cmov, extract | yes | 8 | 12 | 0.667x | 697 | 703 | 0.991x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | 1 | 1 | cmov | cmov | yes | 10 | 8 | 1.250x | 689 | 695 | 0.991x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | 1 | 1 | cmov | cmov | yes | 9 | 8 | 1.125x | 656 | 662 | 0.991x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | 1 | 1 | cmov | cmov | yes | 8 | 16 | 0.500x | 643 | 649 | 0.991x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | 1 | 1 | cmov | cmov | yes | 7 | 9 | 0.778x | 705 | 711 | 0.992x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | 1 | 2 | cmov, wide | cmov, wide | yes | 7 | 13 | 0.538x | 696 | 686 | 1.015x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | 992 | 992 | rotate | none | no | 476 | 483 | 0.986x | 48574 | 48574 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | 0 | 0 | none | none | no | 9 | 7 | 1.286x | 152 | 152 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | 0 | 0 | none | none | no | 8 | 10 | 0.800x | 107 | 107 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | 0 | 0 | none | none | no | 9 | 10 | 0.900x | 251 | 251 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | 0 | 0 | none | none | no | 11 | 11 | 1.000x | 38 | 38 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | 0 | 0 | none | none | no | 10 | 10 | 1.000x | 38 | 38 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | 0 | 0 | none | none | no | 10 | 11 | 0.909x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | 0 | 0 | none | none | no | 8 | 11 | 0.727x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | 0 | 0 | none | none | no | 8 | 11 | 0.727x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | 0 | 0 | none | none | no | 7 | 11 | 0.636x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | 0 | 0 | none | none | no | 7 | 16 | 0.438x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | 0 | 0 | none | none | no | 7 | 16 | 0.438x | 28 | 28 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | 0 | 0 | none | none | no | 28 | 26 | 1.077x | 79 | 79 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | 0 | 0 | none | none | no | 26 | 25 | 1.040x | 79 | 79 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | 0 | 0 | none | none | no | 12 | 13 | 0.923x | 58 | 58 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | 0 | 0 | none | none | no | 12 | 18 | 0.667x | 58 | 58 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | 0 | 0 | none | none | no | 8 | 12 | 0.667x | 35 | 35 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | 0 | 0 | none | none | no | 10 | 16 | 0.625x | 54 | 54 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | 0 | 0 | none | none | no | 10 | 10 | 1.000x | 53 | 53 | 1.000x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | 5 | 15 | cmov, wide, extract | cmov, wide, extract | yes | 8 | 8 | 1.000x | 5424 | 5391 | 1.006x |  |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | 5 | 15 | cmov, wide, extract | cmov, wide, extract | yes | 9 | 10 | 0.900x | 5454 | 5414 | 1.007x |  |
| linux-selftests | corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | 5 | 15 | cmov, wide, extract | cmov, wide, extract | yes | 8 | 11 | 0.727x | 5424 | 5391 | 1.006x |  |
| linux-selftests | corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | 5 | 15 | cmov, wide, extract | cmov, wide, extract | yes | 9 | 10 | 0.900x | 5454 | 5414 | 1.007x |  |
| real_world_code_size | corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | 0 | 0 | none | none | no | 14 | 23 | 0.609x | 374 | 374 | 1.000x |  |
| real_world_code_size | corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | 0 | 0 | none | none | no | 7 | 11 | 0.636x | 111 | 111 | 1.000x |  |
| suricata | corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | 1 | 3 | cmov, extract | cmov, extract | yes | 10 | 9 | 1.111x | 1628 | 1634 | 0.996x |  |
| suricata | corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | 1 | 1 | cmov | none | no | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| tracee | corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | 110 | 121 | cmov, wide, extract | cmov, wide, extract | yes | 9 | 13 | 0.692x | 19383 | 17803 | 1.089x |  |
| tracee | corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | 110 | 121 | cmov, wide, extract | cmov, wide, extract | yes | 8 | 13 | 0.615x | 19383 | 17803 | 1.089x |  |
| xdp-tools | corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | 1 | 1 | cmov | cmov | yes | 10 | 9 | 1.111x | 697 | 703 | 0.991x |  |
| xdp-tools | corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | 1 | 1 | cmov | cmov | yes | 10 | 10 | 1.000x | 694 | 700 | 0.991x |  |
| xdp-tools | corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | 1 | 1 | cmov | cmov | yes | 15 | 15 | 1.000x | 78 | 84 | 0.929x |  |
| xdp-tools | corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | 0 | 0 | none | none | no | 10 | 11 | 0.909x | 91 | 91 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | 0 | 0 | none | none | no | 11 | 16 | 0.688x | 215 | 215 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | 0 | 0 | none | none | no | 11 | 10 | 1.100x | 31 | 31 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | 0 | 0 | none | none | no | 11 | 7 | 1.571x | 31 | 31 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | 0 | 0 | none | none | no | 8 | 10 | 0.800x | 31 | 31 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | 0 | 0 | none | none | no | 14 | 11 | 1.273x | 108 | 108 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | 0 | 0 | none | none | no | 10 | 15 | 0.667x | 145 | 145 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | 0 | 0 | none | none | no | 10 | 10 | 1.000x | 146 | 146 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | 0 | 0 | none | none | no | 10 | 9 | 1.111x | 146 | 146 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | 0 | 1 | extract | extract | yes | 9 | 10 | 0.900x | 549 | 549 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | 1 | 1 | cmov | cmov | yes | 10 | 12 | 0.833x | 511 | 514 | 0.994x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | 0 | 0 | none | none | no | 11 | 8 | 1.375x | 31 | 31 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | 2 | 3 | cmov, wide | cmov, wide | yes | 10 | 10 | 1.000x | 122 | 121 | 1.008x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | 2 | 2 | cmov | cmov | yes | 8 | 9 | 0.889x | 526 | 541 | 0.972x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | 0 | 0 | none | none | no | 10 | 8 | 1.250x | 31 | 31 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | 2 | 3 | cmov, wide | cmov, wide | yes | 11 | 10 | 1.100x | 244 | 243 | 1.004x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | 2 | 3 | cmov, wide | cmov, wide | yes | 15 | 16 | 0.938x | 378 | 378 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | 0 | 0 | none | none | no | 10 | 17 | 0.588x | 471 | 471 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | 0 | 0 | none | none | no | 9 | 8 | 1.125x | 28 | 28 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | 0 | 0 | none | none | no | 231 | 214 | 1.079x | 231 | 231 | 1.000x |  |
| xdp-tutorial | corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | 1 | 1 | cmov | cmov | yes | 193 | 206 | 0.937x | 170 | 169 | 1.006x |  |
