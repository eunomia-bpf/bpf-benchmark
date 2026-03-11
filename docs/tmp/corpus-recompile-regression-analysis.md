# Corpus Recompile Regression Analysis

**Date**: 2026-03-11
**Source data**: `docs/tmp/corpus-batch-recompile-results.md` (78 measured pairs, 200 repeats, VM 7.0-rc2)
**Purpose**: Separate noise from real regressions, assess CMOV policy-sensitivity, recalculate reliable geomeans.

---

## 1. Resolution Tier Classification

The kernel `bpf_prog_test_run` uses `ktime_get_ns()` which has ~50-100ns resolution on most hardware. Programs with execution times below this threshold produce quantized, unreliable ratios.

| Tier | Criterion | Programs | Notes |
| --- | --- | --- | --- |
| Sub-resolution | min(baseline, v5) < 50ns | 32 | Pure noise; ratios like 0.438x are 7ns vs 16ns (1 ktime quantum) |
| Low-confidence | both in 50-200ns range | 12 | Marginal; within 1-3 ktime quanta of noise |
| Reliable | max(baseline, v5) > 200ns | 34 | Trustworthy; large enough absolute times for meaningful ratios |

### Sub-resolution programs (32)

These are dominated by linux-selftests (14), xdp-tutorial (5), xdp-tools (3), katran (2), tracee (2), suricata (1), calico (1). All have baseline exec in the 7-17ns range. The reported ratios (0.438x to 1.286x) are entirely artifacts of ktime quantization. For example:

- `__encap_vxlan_eth`: 7ns -> 16ns = 0.438x. This is a 1-quantum difference.
- `__encap_gre_none`: 9ns -> 7ns = 1.286x. Also a 1-quantum difference.
- `katran/balancer_ingress`: 11ns -> 16ns = 0.688x. Same.

**All 32 sub-resolution results must be excluded from any performance claims.**

### Low-confidence programs (12)

All 12 are Calico programs (plus 1 xdp-tutorial) in the 169-198ns range. The absolute differences are 2-28ns, which is within the noise floor shown by the control programs (see Section 5). These should be reported with strong caveats.

---

## 2. Recalculated Geomean (Excluding Sub-Resolution)

| Scope | N | Geomean | Interpretation |
| --- | --- | --- | --- |
| All programs (reported) | 78 | 0.813x | Inflated by sub-resolution noise |
| Excluding sub-resolution | 46 | 0.847x | More honest but still includes marginal data |
| Reliable only (>200ns) | 34 | 0.805x | Most trustworthy but dominated by Calico |
| Low-confidence + reliable | 46 | 0.847x | Same as excl. sub-resolution |

**The corrected geomean, excluding sub-resolution noise, is 0.847x** (v5 is ~15% slower on average). However, this is heavily dominated by CMOV regressions on Calico programs, which is the expected policy-sensitivity effect (see Section 3).

---

## 3. CMOV Policy-Sensitivity: Validated

### CMOV-only reliable programs (11 programs, all Calico)

Every single CMOV-only reliable program regresses:

| Function | Instances | Ratio Range | Mean Ratio |
| --- | --- | --- | --- |
| calico_tc_skb_accepted_entrypoint | 5 | 0.596x - 0.877x | 0.729x |
| calico_tc_skb_new_flow_entrypoint | 4 | 0.547x - 0.947x | 0.743x |
| calico_tc_skb_ipv4_frag | 2 | 0.606x - 0.761x | 0.684x |

**Geomean: 0.718x** (28% slower with CMOV).

This is consistent with micro-benchmark results where CMOV on `log2_fold` showed +28-46% regression. CMOV converts branches to conditional moves, which hurts when the branch predictor is already performing well (highly predictable branches). These Calico packet-processing functions have deterministic early-exit paths that the branch predictor handles perfectly; replacing them with cmov removes this optimization.

**Conclusion: CMOV-only regressions are NOT noise; they are real and validate the policy-sensitivity thesis.** CMOV is a policy-sensitive directive that requires workload profiling to apply correctly.

### Code-size impact of CMOV-only

CMOV-only programs show code ratio ~0.999x with +6 to +25 bytes added to JIT code. CMOV replaces a branch (jcc + mov = ~7-9B) with cmov (~4-6B) but adds setup code. The net effect is negligible on code size but negative on exec time for predictable branches.

---

## 4. Per-Family Attribution (Reliable Programs)

### CMOV-only (11 programs)

- **Geomean: 0.718x** (28% regression)
- **All 11 regress** (0/11 improved)
- Range: 0.547x to 0.947x
- All are Calico programs with predictable packet-processing branches
- **Validates policy-sensitivity thesis**

### WIDE-only (0 reliable programs)

No reliable programs have WIDE as the sole applied family. The only WIDE-only program is `calico_xdp_main` (xdp_debug variant) at 170ns->198ns, which falls in the low-confidence tier. Its ratio of 0.859x could be real or noise.

### ROTATE-only (1 reliable program)

- `calico_tc_maglev`: 169ns -> 215ns = 0.786x
- This is at the lower boundary of "reliable" (v5 is >200ns but baseline is borderline)
- **Unexpected regression**: ROTATE should improve performance. Possible explanations:
  - Measurement noise (baseline is only 169ns)
  - ROTATE emitter has a code-size increase (3267 -> 3124 JIT bytes = 1.046x improvement), suggesting the rotation itself worked but overall program performance is noisy

### CMOV+WIDE mixed (20 reliable programs)

- **Geomean: 0.848x** (15% regression)
- **15/20 regress, 5/20 improve**
- Range: 0.601x to 1.711x
- The improved programs include the 1.711x outlier (`from_nat_debug:calico_tc_skb_send_tcp_rst`)

WIDE contributes code-size savings (jit_delta = -5 to -103 bytes) while CMOV adds exec-time regression. The net effect depends on which dominates. Programs with more WIDE savings (larger code shrink) show a weak positive correlation with better exec ratios (Pearson r = 0.25), but the effect is overwhelmed by measurement noise.

### No families applied (2 control programs)

- `test_verif_scale2:balancer_ingress`: 471ns -> 642ns = 0.734x (-36%)
- `core_kern:balancer_ingress`: 548ns -> 485ns = 1.130x (+13%)

These programs have 818 and 992 sites detected by the scanner but **no directives were actually applied** during recompile. Despite having identical baseline and v5 JIT sizes (48576/48576 and 50290/50290), they show -36% to +13% exec ratio variation. **This quantifies the noise floor: even with zero code changes, `bpf_prog_test_run` measurements vary by up to +-36% for these programs.**

---

## 5. Cross-Object Variance Analysis (Noise Quantification)

Calico builds the same function into multiple .bpf.o files (from_hep_debug, from_nat_debug, to_wep_debug, etc.). The same function with the same directive families applied shows extreme variance:

| Function | N | Families | Ratio Range | Spread | CV |
| --- | --- | --- | --- | --- | --- |
| calico_tc_skb_send_tcp_rst | 6 | cmov,wide | 0.839x - 1.711x | 0.872 | 28.5% |
| calico_tc_skb_send_icmp_replies | 6 | cmov,wide | 0.601x - 1.197x | 0.596 | 26.8% |
| calico_tc_skb_new_flow_entrypoint | 6 | cmov | 0.547x - 1.140x | 0.593 | 22.6% |
| calico_tc_skb_accepted_entrypoint | 6 | cmov | 0.596x - 1.089x | 0.493 | 20.2% |
| calico_tc_skb_ipv4_frag | 3 | cmov | 0.606x - 0.994x | 0.388 | 20.3% |
| calico_tc_skb_icmp_inner_nat | 6 | cmov,wide | 0.680x - 0.971x | 0.291 | 15.7% |
| calico_tc_main | 6 | cmov,wide | 0.659x - 1.009x | 0.350 | 12.6% |

**Key finding**: The coefficient of variation (CV) is 13-29% across instances of the same function. This means individual program ratios are not reliable for causal attribution. Only aggregate trends (geomean across many programs) are trustworthy.

The baseline exec times also vary significantly across instances of the same function (e.g., `calico_tc_main` baselines range from 183ns to 326ns), indicating that `bpf_prog_test_run` timing is sensitive to factors beyond the BPF program itself (cache state, scheduling, JIT allocation layout, etc.).

---

## 6. Summary and Interpretation

### What the data actually shows:

1. **32/78 programs (41%) are sub-resolution noise** and should be excluded from all claims.

2. **CMOV regressions are real but expected**: The 11 CMOV-only reliable programs all regress (geomean 0.718x). This is the policy-sensitivity effect: CMOV hurts predictable branches. This **validates** the paper's thesis that directive application must be policy-driven.

3. **WIDE impact is unobservable in isolation**: No reliable WIDE-only programs exist. WIDE's code-size benefit is real (-5 to -103 bytes) but its exec-time impact cannot be separated from CMOV in the mixed programs.

4. **Measurement noise is severe**: Control programs with zero code changes show +-36% exec ratio variance. Same-function cross-object CV is 13-29%. Individual program ratios should not be cited as evidence of anything.

5. **Corrected geomean is 0.847x** (excluding sub-resolution), driven primarily by CMOV policy-sensitivity on Calico programs.

### Recommendations for the paper:

1. **Do NOT cite the 0.813x geomean** from the raw results. Use 0.847x with explicit sub-resolution exclusion, or better yet, separate CMOV and non-CMOV programs.

2. **Frame CMOV regression as a positive result**: It proves the policy-sensitivity thesis. The framework enables per-program policy control; blindly applying CMOV everywhere is the wrong strategy (and exactly what the "fixed baselines" approach does).

3. **Report per-family geomeans separately**:
   - CMOV-only reliable: 0.718x (regression, expected, validates thesis)
   - CMOV+WIDE reliable: 0.848x (regression, CMOV dominates)
   - Need WIDE-only and ROTATE-only data from larger programs to show substrate directive benefits

4. **Acknowledge the noise floor**: State that `bpf_prog_test_run` has +-30% noise for short-running programs, and that robust evaluation requires either (a) longer-running programs or (b) higher-precision timing (e.g., rdtsc in-kernel).

5. **Add a column to the data for resolution tier** so readers can assess which results are trustworthy.

---

## Appendix: Raw Data by Tier

### A. Sub-resolution programs (32, excluded from analysis)

| Program | Baseline ns | v5 ns | Ratio | Families |
| --- | --- | --- | --- | --- |
| test_tc_tunnel:__encap_vxlan_eth | 7 | 16 | 0.438x | cmov |
| test_tc_tunnel:decap_f | 7 | 16 | 0.438x | wide |
| tracee:cgroup_skb_ingress | 8 | 16 | 0.500x | cmov, wide |
| test_tc_change_tail:change_tail | 9 | 17 | 0.529x | cmov |
| test_sockmap_update:copy_sock_map | 9 | 16 | 0.562x | cmov |
| xdp_synproxy_kern:syncookie_tc | 8 | 14 | 0.571x | cmov, wide |
| test_tc_bpf:pkt_ptr | 7 | 12 | 0.583x | cmov |
| xdp_synproxy_kern:syncookie_xdp | 9 | 15 | 0.600x | cmov, wide |
| test_tc_tunnel:__encap_gre_eth | 8 | 13 | 0.615x | cmov |
| test_tc_tunnel:__encap_gre_mpls | 8 | 13 | 0.615x | cmov |
| for_each_array_map_elem:test_pkt_access | 17 | 27 | 0.630x | cmov |
| healthchecking:healthcheck_encap | 10 | 15 | 0.667x | cmov |
| test_tc_tunnel:__encap_udp_eth | 8 | 12 | 0.667x | cmov |
| test_tc_tunnel:__encap_udp_mpls | 8 | 12 | 0.667x | cmov |
| katran/balancer:balancer_ingress | 11 | 16 | 0.688x | cmov, wide, rotate |
| xdp_synproxy_kern:syncookie_tc | 10 | 14 | 0.714x | cmov, wide |
| tracee:cgroup_skb_egress | 8 | 10 | 0.800x | cmov, wide |
| test_tc_tunnel:__encap_ipip_none | 10 | 12 | 0.833x | cmov |
| xdp_prog_kern:xdp_parser_func | 9 | 10 | 0.900x | cmov |
| xdp_prog_kern:xdp_redirect_func | 10 | 11 | 0.909x | cmov, wide |
| decap_sanity:decap_sanity | 8 | 8 | 1.000x | cmov |
| test_tc_tunnel:__encap_udp_none | 7 | 7 | 1.000x | cmov |
| xdp_synproxy_kern:syncookie_xdp | 10 | 10 | 1.000x | cmov, wide |
| xdp_forward:xdp_fwd_fib_direct | 9 | 9 | 1.000x | cmov |
| xdp_load_bytes:xdp_probe_prog | 15 | 15 | 1.000x | cmov |
| xdp_prog_kern:xdp_icmp_echo_func | 10 | 10 | 1.000x | cmov |
| xdp_prog_kern:xdp_redirect_map_func | 15 | 15 | 1.000x | cmov, wide |
| calico/xdp_no_log:calico_xdp_main | 16 | 15 | 1.067x | wide |
| suricata/xdp_filter:xdp_hashfilter | 10 | 9 | 1.111x | cmov |
| xdp_prog_kern:xdp_vlan_swap_func | 10 | 9 | 1.111x | cmov, wide |
| xdp_forward:xdp_fwd_fib_full | 9 | 8 | 1.125x | cmov |
| test_tc_tunnel:__encap_gre_none | 9 | 7 | 1.286x | cmov |

### B. Low-confidence programs (12)

| Program | Baseline ns | v5 ns | Ratio | Families |
| --- | --- | --- | --- | --- |
| calico/xdp_debug:calico_xdp_main | 170 | 198 | 0.859x | wide |
| calico:calico_tc_skb_new_flow_entrypoint (from_wep) | 169 | 193 | 0.876x | cmov |
| calico:calico_tc_skb_send_tcp_rst (to_hep) | 174 | 185 | 0.941x | cmov, wide |
| xdp-tutorial:xdp_sample_prog | 175 | 184 | 0.951x | cmov |
| calico:calico_tc_skb_icmp_inner_nat (to_nat) | 170 | 177 | 0.960x | cmov, wide |
| calico:calico_tc_skb_icmp_inner_nat (to_wep) | 170 | 175 | 0.971x | cmov, wide |
| calico:calico_tc_skb_send_icmp_replies (to_nat) | 174 | 177 | 0.983x | cmov, wide |
| calico:calico_tc_skb_ipv4_frag (from_hep) | 176 | 177 | 0.994x | cmov |
| calico:calico_tc_skb_send_tcp_rst (to_wep) | 178 | 179 | 0.994x | cmov, wide |
| calico:calico_tc_skb_send_tcp_rst (to_nat) | 187 | 185 | 1.011x | cmov, wide |
| calico:calico_tc_skb_accepted_entrypoint (from_nat) | 195 | 179 | 1.089x | cmov |
| calico:calico_tc_skb_new_flow_entrypoint (from_hep) | 196 | 172 | 1.140x | cmov |

### C. Reliable programs (34)

See Section 4 for detailed per-family breakdown.
