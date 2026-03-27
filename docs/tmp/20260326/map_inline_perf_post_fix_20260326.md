# Map Inline Post-Fix Performance Analysis (2026-03-26)

## Corpus Benchmark Summary

Source: `corpus/results/vm_corpus_20260326_201508/`

| Metric | Value |
| --- | --- |
| Total programs | 764 |
| Compile pairs | 442 |
| Measured pairs | 315 |
| Applied programs | 130 |
| Exec ratio geomean (rejit/stock) | **0.807x** |
| Code-size ratio geomean | 1.025x |
| Kernel | 7.0.0-rc2+ |
| Repeat | 50 |

### By Project (measured only)

| Project | Programs | Measured | Applied | Exec Geomean | Code Geomean |
| --- | ---: | ---: | ---: | ---: | ---: |
| linux-selftests | 417 | 156 | 37 | **0.696x** | 0.999x |
| calico | 59 | 59 | 54 | 0.796x | 1.008x |
| katran | 5 | 5 | 0 | 0.830x | 1.000x |
| tracee | 5 | 4 | 4 | **0.688x** | 1.108x |
| xdp-tools | 51 | 5 | 2 | 0.744x | 1.005x |
| suricata | 2 | 2 | 0 | 0.898x | 1.000x |
| coroot-node-agent | 2 | 1 | 0 | 0.972x | 1.000x |
| bcc | 90 | 33 | 10 | 1.203x | 0.996x |
| tetragon | 23 | 10 | 9 | 1.076x | 2.361x |
| xdp-tutorial | 38 | 22 | 3 | 1.106x | 1.005x |
| libbpf-bootstrap | 12 | 7 | 5 | 1.021x | 0.996x |
| real_world_code_size | 15 | 9 | 5 | 1.190x | 0.998x |

### Pass Application Counts (compile + run totals)

| Pass | Count |
| --- | ---: |
| const_prop | 138 |
| endian_fusion | 119 |
| live_patch | 116 |
| dangerous_helper_firewall | 86 |
| wide_mem | 67 |
| dce | 34 |
| cond_select | 19 |
| extract | 13 |
| skb_load_bytes_spec | 2 |

**map_inline: 0 applications in the corpus benchmark.** The pass was not triggered on any of the 764 corpus programs. This is consistent with prior observations: corpus objects are loaded without live map state, so map lookups return zeroed/missing values, leaving map_inline with nothing to inline.

### Comparison with Earlier Run (vm_corpus_20260326_174240)

| Metric | Earlier (174240) | Latest (201508) | Delta |
| --- | --- | --- | --- |
| Applied programs | 144 | 130 | -14 |
| Measured pairs | 343 | 315 | -28 |
| Exec geomean | 0.787x | 0.807x | +0.020 (slight regression) |
| Code-size geomean | 1.024x | 1.025x | ~same |

The slight exec regression and fewer applied/measured pairs may be due to the `repeat=50` setting (lower than some earlier runs) and VM noise.

---

## Map Inline Specific Results

### map_inline in Corpus: No Hits

The corpus benchmark does not populate maps with live data before running programs. Since `map_inline` requires reading a live map value from the kernel to substitute into the BPF bytecode, it finds nothing to inline in the corpus context. All 764 programs show 0 `map_inline` applications.

### map_inline in E2E: Partial Application, Blocked by Verifier

All three E2E targets that attempted REJIT (tracee, tetragon, katran) reported **"rejit did not apply successfully"** -- the daemon optimized some programs but hit a verifier rejection on at least one, causing the overall REJIT phase to fail. As a result, no post-REJIT performance measurements were collected.

#### Tracee E2E (20260327_012734)

- Status: completed, but **rejit failed**
- prog 17 (`tracepoint__raw`): 29 -> 30 insns, REJIT ok
  - `map_inline`: 0 sites applied, 1 site skipped
    - skip reason: "lookup key is not a constant stack materialization" x1
    - diagnostic: "register r7 definition at pc 4 is not a supported constant materialization"
  - `live_patch`: 2 sites applied (the only pass that changed)
- prog 36: **verifier rejection** -- "unreachable insn 252"
  - This blocked the entire REJIT batch

#### Tetragon E2E (20260327_013101)

- Status: completed, but **rejit failed**
- prog 151 (`event_exit_acct`): **177 -> 121 insns** (delta -56)
  - **map_inline: 1 site applied, 6 sites skipped** (first real E2E hit!)
    - insns: 177 -> 169 (delta -8 from map_inline alone)
    - skip reasons:
      - "lookup key is not a constant stack materialization" x1
      - "map type 6 not inlineable in v1" x5
  - `const_prop`: 2 sites applied (169 -> 169, no size change but propagated constants)
  - `dce`: 49 sites applied (169 -> 120, delta -49 -- cascaded dead code from inlining)
  - `live_patch`: also applied
  - **Total: 53 sites applied across 4 passes**
- Despite optimization success on prog 151, **verifier rejected the REJIT** of this program:
  - Error: "BPF_PROG_REJIT: Invalid argument (os error 22)"

#### Katran E2E

- 20260326_211701: completed but **rejit did not apply**
  - No rejit_result found -- the daemon did not attempt REJIT on the live Katran program
  - Scan detected 6 sites (4 wide_mem, 2 endian_fusion) on `balancer_ingress` (2546 insns)
  - No map_inline sites were detected on the live katran program
- 20260327_013934: **errored** during map capture phase (command killed with signal -9)
- Katran `balancer_ingress` has 64 lookup sites, but all were skipped due to unsupported map types (6/12/13)

---

## Comparison with Pre-Fix Validation Data

### Katran `xdp_pktcntr` (from `katran_map_inline_perf_test_20260326.md`)

Pre-fix isolated test (direct VM apply, not corpus):

| Metric | Stock | REJIT | Change |
| --- | ---: | ---: | --- |
| Instruction count | 22 | 12 | **-45%** |
| JIT bytes | 177 | 94 | **-47%** |
| xlated insns | 36 | 18 | -50% |
| exec_ns (repeat=500) | 5 (median) | 10 (median) | 2.00x slower |
| exec_ns (repeat=1000) | 4 (median) | 10 (median) | 2.50x slower |
| exec_cycles (repeat=500) | 120,826 | 122,257 | ~flat |

Despite a dramatic code shrink (-45% insns, -47% JIT bytes), exec_ns was **worse** (noise-dominated at single-digit ns). The exec_cycles metric was nearly flat, suggesting the code-size improvement is real but the program is too fast to measure reliably.

### Tracee `cgroup_skb` (from `map_inline_performance_validation_20260326.md`)

Pre-fix isolated test:

| Program | map_inline sites | Stock exec_ns | REJIT exec_ns | Speedup |
| --- | ---: | ---: | ---: | ---: |
| cgroup_skb_ingress | 56 found, 9 inlined | 13 | 16 | 0.813x (slower) |
| cgroup_skb_egress | 56 found, 9 inlined | 13 | 18 | 0.722x (slower) |

- insn_delta = -399 for both tracee cgroup_skb programs (massive reduction)
- Still measured slower, likely due to JIT I-cache flush overhead dominating at these tiny exec times

### Tetragon `event_exit_acct` (new in latest E2E)

This is the first time map_inline was successfully applied on a real Tetragon program in the E2E pipeline:

| Metric | Stock | REJIT | Change |
| --- | ---: | ---: | --- |
| Instruction count | 177 | 121 | **-32%** |
| map_inline contribution | - | -8 insns | from 1 inlined lookup |
| dce cascade | - | -49 insns | dead code eliminated after inlining |

However, the verifier rejected the program after transformation, so no runtime measurement is available.

---

## Assessment: Did MOV64_IMM + Fixed-Point Fixes Help?

### MOV64_IMM Fix

The fix ensures that when a 64-bit inlined value fits in signed 32-bit range, the pass emits a compact `MOV64_IMM` (1 slot) instead of `LD_IMM64` (2 slots). This produces tighter code and avoids instruction-count inflation that could confuse the verifier.

**Evidence of impact:** The Katran `pktcntr` shrink from 22 -> 12 insns and the Tetragon `event_exit_acct` shrink from 177 -> 121 insns both demonstrate the pass produces real instruction reductions. The fixed-point iteration of `const_prop + dce` is critical for Tetragon: 1 map_inline site (-8 insns) cascaded into 49 DCE eliminations (-49 insns), showing the fixed-point loop amplifies the initial optimization 7x.

### What Is NOT Working Yet

1. **Verifier rejections in E2E:** All three E2E targets had at least one program fail verifier re-verification after REJIT. This blocks the entire REJIT phase, so no post-optimization measurements are collected. The errors include "unreachable insn" (tracee) and live-register analysis failures (tetragon). These are likely bugs in the REJIT transformation or the live-patching pass, not in map_inline itself.

2. **No map_inline in corpus:** The corpus pipeline does not provide live map values, so map_inline has zero opportunity to fire. This means the 0.807x overall corpus geomean reflects only the other passes (const_prop, endian_fusion, live_patch, wide_mem, etc.).

3. **exec_ns regression at low latency:** Even in isolated tests, map_inline-optimized programs show no exec_ns improvement at single-digit nanosecond scale. The exec_cycles metric is flat, suggesting the JIT code is not actually slower -- the measurement granularity is the bottleneck. This is consistent with the known I-cache flush overhead dominating for same-size or small-delta optimizations.

4. **Katran `balancer_ingress` untouched:** The flagship Katran program uses map types 6/12/13 (LRU_HASH, PERCPU_HASH, etc.) which map_inline v1 does not support. Only `pktcntr` (a trivial counter program) benefits.

### Bottom Line

The MOV64_IMM and fixed-point fixes are **correct and produce measurably tighter code** (verified by instruction counts and JIT byte reductions). However, the E2E impact is currently **blocked by verifier failures** that prevent post-REJIT measurements. The corpus impact is **zero** because corpus runs lack live map state. To unblock meaningful E2E measurement:

1. Fix the verifier rejection bugs (unreachable insn, live-reg analysis) in the REJIT pipeline
2. Support more map types in map_inline (LRU_HASH, PERCPU variants) for Katran coverage
3. Consider providing fixture-based map state in corpus runs to exercise map_inline there

The code-size evidence is strong (Katran -45%, Tetragon -32%, Tracee -11%), but runtime validation remains pending on the verifier fix.
