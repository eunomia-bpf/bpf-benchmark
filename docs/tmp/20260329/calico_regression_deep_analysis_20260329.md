# Calico Regression Deep Analysis

- Date: 2026-03-29
- Scope: analyze the `calico` `0.9143358186895306x` regression reported by `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`

## 0. Source Boundary

There are two evidence tiers in the current tree.

1. Exact authoritative metadata for the target run:
   - `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`
2. Nearest accessible same-day raw program-level batch result:
   - `docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-rlg7cu6g.json`
   - matched by `runner/corpus/results/vm_corpus_20260329_124613/metadata.json`

Important caveat:

- The exact `091745` raw program-level JSON is not present in the repository.
- So exact repo-level and object-level claims below come from `091745/metadata.json`.
- Program-level ratio distribution, top-5 regressors, pass mix, per-program code-size deltas, and `exec_ns` scale are inferred from the nearest accessible same-day raw rerun (`124613`), and are labeled as such.

This is still useful because the nearby raw rerun has:

- the same `54` calico transformed comparable pairs
- the same calico repo code-size geomean: `1.004956181433201`
- identical calico object-level code-size ratios for all `8` calico objects

## 1. Exact `091745` Calico By-Repo Data

From `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`:

| Metric | Value |
| --- | ---: |
| programs | `59` |
| compile_pairs | `59` |
| measured_pairs | `59` |
| comparable_pairs | `59` |
| applied_programs | `54` |
| applied_comparable_pairs | `54` |
| applied-only exec geomean | `0.9143358186895306x` |
| all-comparable exec geomean | `0.9170368996257875x` |
| code-size geomean | `1.004956181433201x` |

Immediate read:

- This is not a conditioning artifact from dropping non-applied rows: even `all-comparable` is negative (`0.9170x`).
- The size signal is tiny: REJIT code is only about `0.4956%` smaller on geomean.

## 2. Exact `091745` Object-Level Concentration

Negative mass in the exact `091745` calico transformed subset is concentrated in a few objects:

| Object | Applied comparable pairs | Exec geomean | Share of calico negative-log mass | Code-size geomean |
| --- | ---: | ---: | ---: | ---: |
| `calico:from_wep_debug.bpf.o` | `8` | `0.4207583871408103x` | `59.3%` | `1.0039241558619971x` |
| `calico:to_hep_debug.bpf.o` | `9` | `0.7077664722060774x` | `26.6%` | `1.0050768269038362x` |
| `calico:to_nat_debug.bpf.o` | `9` | `0.9025931109010734x` | `7.9%` | `1.0051067792975121x` |
| `calico:xdp_no_log.bpf.o` | `1` | `0.6666666666666666x` | `3.5%` | `1.0051365609966836x` |
| `calico:xdp_debug.bpf.o` | `2` | `0.8523691491707525x` | `2.7%` | `1.00243703810483x` |
| `calico:from_hep_debug.bpf.o` | `9` | `1.1385324754550323x` | `0%` | `1.0035552579567255x` |
| `calico:to_wep_debug.bpf.o` | `8` | `1.3963412517329368x` | `0%` | `1.009436307862328x` |
| `calico:from_nat_debug.bpf.o` | `8` | `1.4566341115889911x` | `0%` | `1.0039620414335886x` |

Takeaway:

- `from_wep_debug.bpf.o` + `to_hep_debug.bpf.o` explain about `85.9%` of the exact `091745` calico negative mass.
- Even those negative objects still have only `0.24%` to `0.51%` size shrink, not code growth.

## 3. Program-Level Shape From Nearest Accessible Raw Rerun

Nearest accessible raw:

- `docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-rlg7cu6g.json`
- matched by `runner/corpus/results/vm_corpus_20260329_124613/metadata.json`

That rerun has the same calico transformed-pair count (`54`) and identical calico code-size ratios, but a nearby applied-only geomean of `0.8874293308973961x`.

### 3.1 Ratio distribution over `54` applied comparable programs

| Bucket | Count |
| --- | ---: |
| `ratio < 0.8` | `25` |
| `0.8 <= ratio < 0.9` | `5` |
| `0.9 <= ratio < 0.95` | `1` |
| `0.95 <= ratio < 1.0` | `0` |
| `1.0 <= ratio < 1.05` | `3` |
| `1.05 <= ratio < 1.1` | `0` |
| `ratio >= 1.1` | `20` |

Headline counts:

- `23` programs with `ratio > 1.0`
- `31` programs with `ratio < 1.0`
- median `0.8188434048083171x`
- min `0.09619289340101522x`
- max `11.014388489208633x`

Interpretation:

- The transformed subset is not uniformly negative; it is heavy-tailed on both sides.
- There are many large wins and many large losses, which already looks more like instability/layout sensitivity than a single deterministic regressor.

### 3.2 Worst top-5 regressors in the accessible raw rerun

These are not the exact `091745` top-5, because exact `091745` raw is missing. They are the nearest same-day raw top-5 with the same `54` transformed comparable calico rows.

| Rank | Program | Ratio | Baseline `exec_ns` | REJIT `exec_ns` | Sub-100ns? | Applied passes | Native bytes `baseline -> rejit` |
| --- | --- | ---: | ---: | ---: | --- | --- | --- |
| 1 | `calico:to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag` | `0.0962x` | `379` | `3940` | no | `const_prop,dce` | `903 -> 900` |
| 2 | `calico:from_wep_debug.bpf.o:calico_tc_skb_drop` | `0.1298x` | `634` | `4886` | no | `const_prop,dce,endian_fusion` | `1735 -> 1732` |
| 3 | `calico:from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies` | `0.2308x` | `249` | `1079` | no | `const_prop,dce,wide_mem,endian_fusion` | `11902 -> 11861` |
| 4 | `calico:from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag` | `0.2755x` | `238` | `864` | no | `const_prop,dce` | `905 -> 902` |
| 5 | `calico:to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | `0.3417x` | `245` | `717` | no | `const_prop,dce,bulk_memory,endian_fusion` | `15708 -> 15660` |

Notes:

- None of the top-5 are sub-100ns.
- But `3/5` are still only `238-249ns` baseline, and `5/5` are below `700ns` baseline, so they are still in a noise-sensitive regime for one averaged `repeat=50` sample.
- For all top-5, `result` and `retval` match exactly between baseline and REJIT.

### 3.3 Which passes hit?

Accessible nearby raw pass-hit counts over the `54` transformed calico rows:

| Pass | Hits |
| --- | ---: |
| `const_prop` | `51` |
| `dce` | `51` |
| `endian_fusion` | `48` |
| `wide_mem` | `28` |
| `cond_select` | `14` |
| `extract` | `7` |
| `bulk_memory` | `6` |
| `map_inline` | `1` |

Most common pass bundles:

| Bundle | Count |
| --- | ---: |
| `const_prop,dce,wide_mem,endian_fusion` | `16` |
| `const_prop,dce,endian_fusion` | `8` |
| `const_prop,dce` | `6` |
| `const_prop,dce,cond_select,endian_fusion` | `5` |
| `const_prop,dce,wide_mem,extract,endian_fusion` | `5` |

Conclusion:

- This does not look like a `map_inline` regression.
- Calico is dominated by the `const_prop + dce` core, usually with `endian_fusion`, and sometimes `wide_mem`.

## 4. Code-Size Direction

Exact `091745` repo-level result:

- calico code-size geomean = `1.004956181433201x`

Nearby raw rerun, per transformed program:

- `53/54` rows got smaller native code
- `1/54` was unchanged
- `0/54` got larger native code

Speed/size cross-tab in the nearby raw rerun:

| Pattern | Count |
| --- | ---: |
| smaller and slower | `30` |
| smaller and faster | `23` |
| larger and slower | `0` |
| larger and faster | `0` |
| unchanged and slower | `1` |

Takeaway:

- This is not code bloat.
- The dominant pattern is "code got slightly smaller, timing moved in either direction."

## 5. Layout Perturbation or Real Bug?

The evidence points much more strongly to layout perturbation / measurement instability than to a real semantic bug.

Evidence:

1. Exact `091745` calico code-size shrink is only about `0.5%` geomean.
2. Nearby raw rerun shows `53/54` transformed rows smaller, none larger.
3. Nearby raw rerun has `0` semantic mismatches in `result` or `retval`.
4. Same-day nearby raw rerun also contains huge wins with the same tiny size deltas:
   - `11.014x`: `calico:from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies`
   - `9.463x`: `calico:to_wep_debug.bpf.o:calico_tc_skb_drop`
   - `4.309x`: `calico:to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies`
5. Between `2026-03-29 09:17:45` and `2026-03-29 12:46:13`, `6/8` calico object directions flip sign while all `8/8` object code-size ratios stay exactly identical.

That last point is decisive:

- `from_hep`: `1.1385x -> 0.8999x`
- `from_nat`: `1.4566x -> 0.9931x`
- `to_nat`: `0.9026x -> 1.0356x`
- `to_wep`: `1.3963x -> 0.6932x`
- `xdp_debug`: `0.8524x -> 1.4392x`
- `xdp_no_log`: `0.6667x -> 1.2800x`

If the transformed code is byte-for-byte the same size and most object directions still flip, this is not behaving like a stable deterministic optimization bug.

## 6. Consistency With Previous Calico Regression Analysis (`#577`)

The previous conclusion remains qualitatively consistent.

Recorded earlier evidence from `docs/kernel-jit-optimization-plan.md` for `#577`:

- `51` applied rows
- `25` slower, `26` faster
- median `1.005x`
- same config reruns flipped repo geomean from about `0.84x` to `0.80x` to `1.13x`
- conclusion: `repeat=50` was not enough for those `138-150ns` calico programs

Current evidence:

- `2026-03-29 09:17:45`: exact metadata says `0.9143x` on `54` applied pairs
- `2026-03-29 12:46:13`: nearby raw-matched rerun says `0.8874x` on the same `54` applied pairs
- but the object ranking is still unstable: `6/8` object signs flip with identical code-size ratios

So the comparison to `#577` is:

- Yes, still consistent with the old "mostly noise / layout sensitivity, not a hard bug" diagnosis.
- Slight difference: the repo-level sign on `2026-03-29` stayed negative across the two same-day reruns (`0.914x` and `0.887x`) instead of immediately flipping positive.
- But pair-level and object-level behavior is still far too unstable to claim a specific calico bug from this data alone.

Historical calico repo-level geomeans visible in current metadata tree:

| Run | Applied comparable pairs | Exec geomean |
| --- | ---: | ---: |
| `vm_corpus_20260328_145400` | older schema | `0.842955392387365x` |
| `vm_corpus_20260328_154829` | older schema | `0.7991324437374243x` |
| `vm_corpus_20260328_194356` | older schema | `1.1254703722655317x` |
| `vm_corpus_20260328_234253` | `53` | `0.8790061884498553x` |
| `vm_corpus_20260328_235046` | `53` | `0.7988823671595348x` |
| `vm_corpus_20260329_091745` | `54` | `0.9143358186895306x` |
| `vm_corpus_20260329_124613` | `54` | `0.8874293308973961x` |

This is still a volatility story, not a clean monotonic regression story.

## 7. Is `repeat=50` Enough for Calico?

For the nearby same-day raw rerun over the `54` transformed calico rows:

Baseline `exec_ns` distribution:

| Statistic | Value |
| --- | ---: |
| min | `32ns` |
| p25 | `250.25ns` |
| median | `408.5ns` |
| p75 | `598.5ns` |
| max | `4593ns` |

Counts by baseline `exec_ns`:

| Threshold | Count |
| --- | ---: |
| `< 100ns` | `1` |
| `< 150ns` | `1` |
| `< 200ns` | `3` |
| `< 300ns` | `16` |
| `< 500ns` | `40` |
| `< 1000ns` | `51` |

Interpretation:

- This March 29 calico slice is not dominated by the `138-150ns` regime called out in `#577`.
- But it is still mostly a sub-`1us` workload, and the artifact stores only one average over `repeat=50`, with no variance, no CI, and no per-repeat distribution.
- That is enough for medium-confidence repo-level direction across `54` rows.
- It is not enough for confident pair-level or object-level claims.

My judgment:

- `repeat=50` is not sufficient to conclude that any specific calico program is a real regressor.
- `repeat=50` is barely sufficient to say "calico as a repo trends negative in this artifact" because both exact `091745` metrics are negative and the same-day nearby rerun stays negative too.
- If calico object/program attribution matters, rerun with either multiple independent reruns or much larger repeat counts such as `repeat=500`.

## 8. Direct Answers To The 7 Requested Questions

1. Ratio distribution:
   - Exact `091745` raw distribution is unavailable.
   - Nearest same-day raw rerun with the same `54` transformed pairs shows `23 > 1.0`, `31 < 1.0`, median `0.8188x`, heavy tails on both sides.
2. Top-5 regressors:
   - Nearby raw top-5 are `to_wep/ipv4_frag`, `from_wep/drop`, `from_hep/send_icmp_replies`, `from_wep/ipv4_frag`, `to_wep/new_flow_entrypoint`.
   - Their baseline `exec_ns` are `379`, `634`, `249`, `238`, `245`; none are sub-`100ns`.
3. Which passes hit:
   - Dominant bundle is `const_prop + dce`, usually with `endian_fusion`, sometimes `wide_mem`.
   - `map_inline` is only `1/54`, so calico is not a `map_inline` story.
4. Code-size change:
   - Exact `091745` repo code-size geomean is `1.004956x`.
   - Nearby raw shows `53/54` rows smaller, `1/54` unchanged, `0/54` larger.
5. Layout perturbation or real bug:
   - Much more consistent with layout perturbation / measurement instability.
   - Tiny size shifts, zero semantic mismatches, and same-day object sign flips with identical code-size ratios argue strongly against a stable real bug.
6. Consistency with `#577`:
   - Yes, qualitatively consistent with the earlier "noise" diagnosis.
   - The only nuance is that the repo-level sign stayed negative across two March 29 reruns, so the aggregate negative direction is a bit more believable than in the earlier `0.84 -> 0.80 -> 1.13` flip sequence.
7. Is `repeat=50` enough:
   - Not for pair-level or object-level calico claims.
   - Maybe barely enough for repo-level direction on this exact artifact, because the transformed set is `54` rows and both `applied-only` and `all-comparable` are negative.

## 9. Bottom Line

The strongest defensible statement is:

- `calico` is a medium-confidence negative repo-level signal in `vm_corpus_20260329_091745` (`0.9143x`, `54` transformed comparable pairs).
- But the mechanism is not `map_inline`, not code bloat, and not obviously a real semantic bug.
- The observed behavior is much more consistent with small code-layout perturbations plus insufficiently replicated timing on mostly sub-`1us` programs.

What is missing:

- the exact `091745` raw program-level JSON
- repeated independent reruns with preserved variance

Without those, do not over-interpret individual calico programs or individual calico objects.
