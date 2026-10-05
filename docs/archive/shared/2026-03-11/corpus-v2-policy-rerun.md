# Corpus v2 Policy Rerun

Date: 2026-03-12

## Final Run

- Final artifact: `corpus/results/corpus_v5_v2_policy_20260312.json`
- Command:

```bash
python3 corpus/_driver_impl_run_corpus_v5_vm_batch.py \
  --skip-build \
  --use-policy \
  --inventory-json docs/tmp/corpus-runnability-results.json \
  --output-json corpus/results/corpus_v5_v2_policy_20260312.json \
  --output-md docs/tmp/corpus-v2-policy-rerun.md \
  --repeat 200 \
  --timeout 240
```

- Final VM config came from the driver after updating `build_vng_command()` to use `--memory 4G --cpus 2`.
- The final accepted run was done after rebuilding both `scanner/build/bpf-jit-scanner` and `micro/build/runner/micro_exec` so runtime policy parsing accepted `default: stock`. Earlier intermediate runs that rejected `stock` were discarded.

## Policy Lookup Audit

- `corpus/_driver_impl_run_corpus_v5_vm_batch.py` resolves `--use-policy` via `resolve_policy_path(object_path, program_name=...)`.
- `corpus/policy_utils.py` is now v2-only and only returns per-program paths of the form `corpus/policies/<relpath>/<object-stem>/<program>.policy.yaml`.
- There is no remaining v1 per-object fallback in `resolve_policy_path()`.
- Concrete path check:
  - v1 tuned artifact used `/home/yunwei37/workspace/bpf-benchmark/corpus/policies/calico/from_hep_debug.bpf.o.policy.yaml`
  - this rerun used `/home/yunwei37/workspace/bpf-benchmark/corpus/policies/calico/from_hep_debug/calico_tc_maglev.policy.yaml`

Policy coverage in the final run:

| Scope | `policy-file` | `auto-scan-v5` |
| --- | ---: | ---: |
| All 166 targets | 109 | 57 |
| 155 measured pairs | 101 | 54 |

- `57/166` targets still fell back to auto-scan because no per-program YAML was found.
- `14` of those fallback rows still had positive sites; they are mostly branch-flip-only programs (`11/14`), concentrated in `xdp-tutorial` (6), `calico` (3), `linux-selftests` (3), and `katran` (2).
- Notable positive-site fallbacks include `for_each_array_map_elem:test_pkt_access` and `test_tc_tunnel:decap_f`.

## Topline

| Run | Measured Pairs | Applied Programs | Exec Geomean (stock/v5) | Wins | Losses |
| --- | ---: | ---: | ---: | ---: | ---: |
| Blind all-apply | 163 | 92 | 0.868x | 40 | 107 |
| v1 tuned per-object | 142 | 94 | 0.898x | 42 | 84 |
| v2 per-program | 155 | 58 | 0.848x | 47 | 92 |

- The final v2 rerun missed the `>1.0x` target.
- Relative to blind all-apply, v2 regressed from `0.868x` to `0.848x` (`-2.3%`).
- Relative to v1 tuned, v2 regressed from `0.898x` to `0.848x` (`-5.6%`).
- v2 recovered more measurements than v1 (`155` vs `142`), but that extra coverage did not improve the topline.

## Shared Measured Subset

The fairest comparison is the `142` programs measured by all three runs.

| Shared Subset | Blind All-Apply | v1 Tuned | v2 Per-Program |
| --- | ---: | ---: | ---: |
| 142 shared measured programs | 0.891x | 0.898x | 0.847x |

- The regression persists on the exact shared overlap, so the worse v2 result is not explained only by recovering additional rows.

## Per-Source

| Project | Blind | v1 | v2 | v2 Measured | v2 Wins / Losses |
| --- | ---: | ---: | ---: | ---: | ---: |
| calico | 0.935x | 0.914x | 0.860x | 59 | 16 / 42 |
| linux-selftests | 0.802x | 0.900x | 0.776x | 62 | 13 / 40 |
| xdp-tutorial | 0.983x | 0.881x | 1.060x | 20 | 13 / 4 |
| xdp-tools | 1.003x | 1.040x | 1.019x | 4 | 3 / 1 |
| katran | 0.776x | 0.777x | 0.835x | 5 | 2 / 2 |
| tracee | 0.653x | n/a | 0.784x | 2 | 0 / 1 |
| real_world_code_size | 0.622x | n/a | 0.778x | 1 | 0 / 1 |
| suricata | 1.111x | n/a | 1.000x | 1 | 0 / 0 |
| libbpf-bootstrap | 0.583x | 0.583x | 0.583x | 1 | 0 / 1 |

Main takeaways:

- `xdp-tutorial` is the only large source that clearly improved, crossing break-even to `1.060x`.
- `calico` and `linux-selftests` dominate the loss. They also dominate the measured corpus.
- `xdp-tools` stayed slightly above `1.0x`, but the absolute sample count is tiny.
- On the strict v1/v2 shared subset, `xdp-tutorial` improved (`0.881x -> 1.060x`), while `calico` (`0.914x -> 0.860x`) and `linux-selftests` (`0.900x -> 0.769x`) both got worse.

## Top Improvements

| Program | Project | Ratio | Applied Families |
| --- | --- | ---: | --- |
| `test_tc_bpf.bpf.o:pkt_ptr` | linux-selftests | 2.917x | cmov |
| `to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | calico | 1.871x | cmov, extract, endian, branch-flip |
| `to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst` | calico | 1.734x | cmov, wide, extract, endian, branch-flip |
| `basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple` | xdp-tutorial | 1.636x | none |
| `basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func` | xdp-tutorial | 1.556x | branch-flip |

## Top Regressions

| Program | Project | Ratio | Applied Families |
| --- | --- | ---: | --- |
| `xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint` | calico | 0.312x | branch-flip |
| `test_tc_tunnel.bpf.o:__encap_udp_eth` | linux-selftests | 0.438x | endian |
| `test_xdp_do_redirect.bpf.o:xdp_count_pkts` | linux-selftests | 0.438x | none |
| `test_tc_tunnel.bpf.o:__encap_vxlan_eth` | linux-selftests | 0.467x | endian |
| `healthchecking.bpf.o:healthcheck_encap` | katran | 0.500x | cmov, endian, branch-flip |

## Biggest Deltas vs v1 Tuned

Largest improvements vs v1 tuned:

| Program | v1 | v2 | Delta |
| --- | ---: | ---: | ---: |
| `test_tc_bpf.bpf.o:pkt_ptr` | 0.636x | 2.917x | +2.280x |
| `basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple` | 0.667x | 1.636x | +0.970x |
| `to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 0.812x | 1.734x | +0.921x |
| `to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 0.967x | 1.871x | +0.904x |
| `basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func` | 0.588x | 1.214x | +0.626x |

Largest regressions vs v1 tuned:

| Program | v1 | v2 | Delta |
| --- | ---: | ---: | ---: |
| `res_spin_lock.bpf.o:res_spin_lock_test` | 12.282x | 1.015x | -11.267x |
| `xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint` | 1.333x | 0.312x | -1.021x |
| `test_tc_tunnel.bpf.o:__encap_ip6gre_mpls` | 1.429x | 0.500x | -0.929x |
| `test_tc_bpf.bpf.o:cls` | 1.364x | 0.583x | -0.780x |
| `test_tc_tunnel.bpf.o:__encap_udp_eth` | 1.143x | 0.438x | -0.705x |

## Failures And Caveats

Remaining non-measurement failures in the final run:

- `14` packet-context failures: `io-mode packet requires an XDP or skb packet context`
- `4` load permission failures
- `2` `Argument list too long` load failures
- `1` branch-flip stale-site failure: `no branch_flip sites found in xlated program (234 insns)`
- `2` `BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7)` non-fatal recompile failures

Other caveats:

- The final artifact is from the post-rebuild run only. Earlier intermediate reruns with stale `scanner`/`micro_exec` binaries were overwritten and should be ignored.
- The host had other concurrent VM/QEMU workloads during measurement. That can add noise, but the shared-subset comparison (`0.898x -> 0.847x`) is large enough that host noise alone is unlikely to reverse the conclusion.

## Conclusion

- `--use-policy` lookup is correctly using v2 per-program policy files.
- The final v2 per-program corpus rerun did **not** improve the corpus. It landed at `0.848x`, below both blind all-apply (`0.868x`) and v1 tuned (`0.898x`).
- The negative result is concentrated in `calico` and `linux-selftests`, while `xdp-tutorial` improved materially.
- The next debugging target is policy content, not path resolution: only `58` programs actually applied recompile, and `14` positive-site programs still fell back to auto-scan.
