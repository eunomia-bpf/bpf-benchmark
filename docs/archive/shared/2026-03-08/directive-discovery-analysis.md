# Directive Discovery Analysis

## Scope and Method

- Analyzed all 60 benchmark sources under `micro/programs/*.bpf.c`:
  - 50 entries from `config/micro_pure_jit.yaml`
  - 10 entries from `config/micro_runtime.yaml`
- Reviewed the current analysis in `docs/tmp/additional_jit_optimizations.md`.
- Reviewed the current directive taxonomy in `docs/kernel-jit-optimization-plan.md`.
- Used the corpus summaries in `corpus/results/bytecode_features.json`, `corpus/results/real_world_code_size.md`, and `corpus/results/real_world_exec_time.md`.
- Inspected representative real-world objects:
  - `corpus/bcf/bpf-examples/clang-20_-O1_nat64_kern.o`
  - `corpus/bcf/cilium/clang-20_-O1_bpf_overlay.o`
  - `corpus/bcf/bcc/clang-20_-O1_ksnoop.bpf.o`

Important caveat: the corpus is dominated numerically by Calico and Cilium objects. I treat those numbers as evidence that a pattern exists at production scale, not as a market-share estimate.

## Executive Summary

The strongest new opportunities are still bounded backend combines, not a late compiler pass inside the kernel JIT.

The most convincing additions beyond `wide_load`, `cmov_select`, and `branch_reorder` are:

1. `bitfield_extract`
2. `rotate_fusion`
3. `lea_fusion`
4. `bounds_window` / redundant bounds-check elimination
5. `packet_ctx_wide_load` as the next substrate extension after current `wide_load`

The strongest future ideas with clear real-world relevance but poor v1 fit are:

1. `map_lookup_cache`
2. `subprog_inline`

The directions I would explicitly de-scope from v1 are:

1. generic cross-insn constant propagation
2. generic post-verifier DCE
3. tail-call optimization

Those either need a mini compiler/dataflow engine, or they cross the current framework boundary of exact straight-line / single-diamond validators.

## Corpus Signals That Matter

- `corpus/results/bytecode_features.json` contains 1,588 analyzed objects and 4,001 executable sections.
- Object-level prevalence is extremely high for the families that matter to production eBPF:
  - `map_lookup_elem`: 1,585 / 1,588 objects (99.81%)
  - `map_update_elem`: 1,581 / 1,588 objects (99.56%)
  - `tail_call`: 1,510 / 1,588 objects (95.09%)
  - objects with `branch_count >= 500`: 1,518 / 1,588 (95.59%)
  - objects with `mem_load_count + mem_store_count >= 1000`: 1,524 / 1,588 (95.97%)
  - objects with subprograms: 1,544 / 1,588 (97.23%)
- Real-world paired results already show a large backend gap:
  - code size geomean (`llvmbpf/kernel`): `0.618x`
  - exec-time geomean (`llvmbpf/kernel`): `0.694x`
- The largest exec-time wins are concentrated in Cilium `tc` programs such as `cil_to_container`, `handle_policy`, and `cil_from_overlay`, which is exactly where packet parsing, fixed-offset field extraction, and map-heavy policy logic live.

Two cautions matter:

1. Raw helper counts are skewed by debug-heavy artifacts such as tracing programs with `trace_printk`.
2. High object-level subprogram prevalence does not mean every hot executable section is a great inline target; the project medians show much stronger subprogram density in `bcc` and `bpf-examples` than in Calico/Cilium hot sections.

## Candidate Directive Table

| Candidate directive | Triggering BPF pattern | Evidence | Native improvement | Estimated impact | Current-framework fit | Recommendation |
| --- | --- | --- | --- | --- | --- | --- |
| `packet_ctx_wide_load` | Contiguous byte/halfword packet or ctx field extraction from one base with exact fixed offsets | Micro: `packet_parse`, `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `struct_field_cluster`; Corpus: Cilium `tc`/cgroup parsers, `nat64_kern` | Replace byte ladders and repeated narrow loads with native loads plus byte-swap/extract; reduce address recomputation | High | Needs extension of `wide_load` beyond current `STACK` / `MAP_VALUE` memory classes | Highest-value post-v1 substrate extension |
| `bounds_window` | One dominating length/range check makes later narrower checks redundant | Micro: `bounds_ladder`, `bounds_check_heavy`, `packet_redundant_bounds`, `packet_parse_vlans_tcpopts`; real packet parsers show the same guard ladders | Remove repeated compare/add/branch pairs and shorten parse fast paths | High | Feasible only if each removed check can be validated from an entry range fact; one-check-at-a-time fits single-diamond, full-window elimination needs more | Stretch v1 if retained facts are ready |
| `bitfield_extract` | `(src >> c) & mask`, endian load plus mask/shift, packed header field extraction | Micro: `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `checksum`, `struct_field_cluster`; Corpus: packet and socket parsers | Lower to shorter shift/mask/extract sequences; reduce temporary traffic | Medium-high | Straight-line | Add to v1 candidate set |
| `rotate_fusion` | Rotate idioms from hash/checksum code | Micro: `packet_rss_hash`, `checksum`, `bitcount`, `smallmul_strength_reduce`; real packet/policy hashes use the same structure | Lower to `rol`/`ror` or BMI2 `rorx`; reduce dependency depth | Medium | Straight-line | Add to v1 candidate set |
| `lea_fusion` | Small constant multiply plus add; scale/index/address arithmetic | Micro: `smallmul_strength_reduce`, `local_call_fanout`, `packet_rss_hash`, `branch_dense`; common in parser indexing and record walking | Use `lea` instead of separate multiply/add chains | Medium | Straight-line | Add to v1 candidate set |
| `wide_store` | Adjacent byte/word stores building one wider value, or zero-init store runs | Micro: packet-backed `micro_write_u64_le` epilogues; Corpus: long stack zeroing runs in `ksnoop` and `bpf_overlay` | Fewer store instructions and smaller code | Medium for code size, low-medium for exec | Straight-line | Already on roadmap; corpus evidence reinforces it |
| `map_lookup_cache` | Repeated `bpf_map_lookup_elem(map, same_key)` in a short window with no invalidation | Micro: `map_lookup_repeat`, `map_lookup_churn`; Corpus: map lookup is nearly universal in policy programs | Reuse looked-up pointer/result instead of repeating the helper call | Potentially high | Needs helper-effect, alias, and invalidation modeling | Future research, not v1 |
| `subprog_inline` | Hot BPF-to-BPF call chains or fanout through local subprograms | Micro: `bpf_call_chain`, `local_call_fanout`; Corpus: many objects are multi-function, especially `bcc` and `bpf-examples` | Remove call/return overhead and expose more local combines | Medium-high on suitable sites | Needs interprocedural validator, budget model, and code-size policy | Future, but worth keeping on roadmap |
| `const_fold_region` | Constant-heavy ALU32/ALU64 cascades with truncation/re-extension | Micro: `const_fold_chain`, `imm64_storm`, `code_clone_*`, `large_mixed_*`, `mega_basic_block_2048`; little direct corpus evidence on hot paths | Fold immediate cascades and kill transient temporaries | High in synthetic code, low in production evidence | Really a small compiler/dataflow pass, not a narrow validator | Do not add to v1 |
| `post_verifier_dce` / `helper_result_dce` | Dead ALU/MOV sequences after verifier-friendly rewrites or after pure helper results cancel out | Micro: `helper_call_*`, `get_time_heavy`; little convincing corpus evidence | Remove a few dead moves/xors after helpers or guards | Low | Would need dataflow to matter; straight-line-only version is tiny ROI | Do not add to v1 |
| `tail_call_specialize` | Repeated fixed-index tail calls or predictable program-array dispatch | Corpus: `tail_call` appears in 95.09% of objects | Avoid repeated program-array lookup/dispatch overhead | Theoretical high value | Cross-program semantics and verifier interaction are outside current model | Explicitly out of scope for current framework |

Heavy struct field access deserves one explicit note: the new `struct_field_cluster` benchmark is useful, but it does not justify a standalone `field_group_load` directive. The better conclusion is that the pattern strengthens the case for `packet_ctx_wide_load` plus `bitfield_extract` and `lea_fusion`.

## Real-World Workload View

| Workload family | Real pattern that matters | Directives that help | Conclusion |
| --- | --- | --- | --- |
| XDP packet processing | Ethernet/IP/TCP field extraction, bounds ladders, checksum and RSS-style mixing | `packet_ctx_wide_load`, `bounds_window`, `bitfield_extract`, `rotate_fusion`, `lea_fusion` | This is the clearest production target after current `wide_load` |
| TC classifier/action | Packet parsing plus policy map lookups, stateful rewrites, tail calls, dense early exits | `packet_ctx_wide_load`, `bounds_window`, existing `branch_reorder`, future `map_lookup_cache`, future `subprog_inline` | Real branches are often too side-effectful for narrow `cmov_select`; load/bounds work is higher leverage |
| Socket filter / cgroup socket | Fixed-offset ctx fields, address/port extraction, packed bit tests | `packet_ctx_wide_load`, `bitfield_extract`, `lea_fusion` | Production-relevant, especially for Cilium socket/cgroup hooks |
| Tracing / kprobes | Stack zero/init runs, probe-read helpers, repeated map state management | `wide_store`, future `subprog_inline`, maybe `map_lookup_cache` in narrow cases | Helper-result DCE is not the answer; helper cost dominates |
| cgroup / LSM policy | Fixed-offset ctx access plus map-based policy checks | `packet_ctx_wide_load` generalized to ctx, future `map_lookup_cache`, `lea_fusion` | Moderate value, mostly as an extension of the packet/ctx load story |

Tail calls are important in production, but they do not look like a good directive target in the current system. They change control flow across program boundaries, and an exact fail-closed validator for that is a different project.

## Representative Real-World Patterns

- `corpus/bcf/cilium/clang-20_-O1_bpf_overlay.o`, section `2/5`
  - Contains repeated fixed-offset ctx loads such as `*(u32 *)(r6 + off)`, long stack zero/init runs, and helper-driven packet copy/build sequences.
  - This is strong evidence for `packet_ctx_wide_load` and `wide_store`.
  - It is also evidence against over-indexing on `cmov_select`: many branches are wrapped around helpers and stateful packet edits, so they are not clean select diamonds.
- `corpus/bcf/bcc/clang-20_-O1_ksnoop.bpf.o`, section `.text`
  - Contains long stack zeroing sequences, repeated map lookups, and probe-read style control flow.
  - The profitable backend opportunities are local store fusion and possibly future map/call structure work, not generic helper-result DCE.
- `corpus/bcf/bpf-examples/clang-20_-O1_nat64_kern.o`
  - The `tc` entry points are thin wrappers into a larger multi-function packet-translation body.
  - That shape reinforces two points: real packet processing wants packet/ctx load fusion and bitfield work, and subprogram structure is common enough that `subprog_inline` remains relevant as a future direction.

## Feasibility Within the Current Framework

### Feasible With Current Straight-Line Validators

- `bitfield_extract`
- `rotate_fusion`
- `lea_fusion`
- `wide_store`

These are the cleanest fits. They are local, side-effect free, and do not need CFG recovery beyond a straight-line slice.

### Feasible Only With Current Single-Diamond Validators Plus Retained Facts

- `bounds_window`, but only at per-check granularity

The practical way to fit `bounds_window` into the current framework is not to delete an entire parser ladder at once. It is to validate one redundant guard at a time using an entry fact such as:

- same base
- same original range source
- dominating readable window that already covers `base + off .. base + off + width`

Without that retained-fact story, redundant bounds-check elimination becomes a multi-diamond region problem.

### Requires Framework Extension

- `packet_ctx_wide_load`
- `map_lookup_cache`
- `subprog_inline`
- `tail_call_specialize`

Why:

- `packet_ctx_wide_load` needs memory-class expansion and a clearer packet/ctx safety contract.
- `map_lookup_cache` needs helper-effect and invalidation reasoning.
- `subprog_inline` needs interprocedural region recovery and budget control.
- `tail_call_specialize` crosses program boundaries entirely.

### Poor Fit Even If Extensions Exist

- `const_fold_region`
- `post_verifier_dce`

These are the directions most likely to turn the JIT into a second compiler backend. The micro suite can manufacture wins for them, but the real workload evidence does not justify that complexity.

## Recommendations for v1 Scope

1. Add `bitfield_extract`, `rotate_fusion`, and `lea_fusion` to the serious v1 candidate set.
2. Prototype `bounds_window` only if retained entry range facts can be exported cleanly; otherwise keep it as the first post-v1 control-flow extension.
3. Treat `packet_ctx_wide_load` as the most important next substrate extension after current `wide_load`.
4. Keep `map_lookup_cache` and `subprog_inline` on the roadmap, but label them explicitly as framework-extension work.
5. De-scope generic constant propagation, generic DCE, and tail-call optimization from v1.

If I had to rank the additions by "real workload relevance divided by implementation risk", the order would be:

1. `bitfield_extract`
2. `rotate_fusion`
3. `lea_fusion`
4. `bounds_window`
5. `packet_ctx_wide_load`
6. `wide_store`
7. `subprog_inline`
8. `map_lookup_cache`
9. `const_fold_region`
10. `post_verifier_dce`
11. `tail_call_specialize`

## New Benchmarks Added in This Task

| Benchmark | Isolated pattern | Smoke result | What it says |
| --- | --- | --- | --- |
| `packet_redundant_bounds` | One dominating packet window plus many redundant sub-checks | `llvmbpf 71 ns`, `kernel 115 ns`, code size `273 B / 717 B` | Good dedicated target for `bounds_window` |
| `const_fold_chain` | ALU32/ALU64 constant cascade with repeated truncation | `llvmbpf 211 ns`, `kernel 891 ns`, code size `408 B / 602 B` | Synthetic upside exists, but still looks more like compiler work than directive work |
| `map_lookup_repeat` | Repeated identical array-map lookup in one hot loop | `llvmbpf 1.744 us`, `kernel 678 ns`, code size `591 B / 872 B` | Clean benchmark for future `map_lookup_cache`; neither runtime does this today |
| `struct_field_cluster` | Dense fixed-offset struct field extraction | `llvmbpf 98 ns`, `kernel 76 ns`, code size `339 B / 439 B` | Supports `packet_ctx_wide_load` + `bitfield_extract`, not a standalone directive |
| `smallmul_strength_reduce` | Multiply-by-small-constant hot loop | `llvmbpf 393 ns`, `kernel 349 ns`, code size `413 B / 586 B` | Clean `lea_fusion` / strength-reduction target |

Smoke command used:

```bash
python3 micro/run_micro.py \
  --suite config/micro_pure_jit.yaml \
  --bench packet_redundant_bounds \
  --bench const_fold_chain \
  --bench map_lookup_repeat \
  --bench struct_field_cluster \
  --bench smallmul_strength_reduce \
  --runtime llvmbpf \
  --runtime kernel \
  --iterations 1 \
  --warmups 1 \
  --repeat 50 \
  --output tmp/directive_discovery_smoke.json
```

## Appendix A: Per-Benchmark Analysis

### A.1 Baselines, Loads, Bounds, and Packet Parsing

| Benchmark | Main pattern | Beyond-current opportunity |
| --- | --- | --- |
| `simple` | Return-only baseline | None; keep as control |
| `simple_packet` | Packet-backed return baseline | None; keep as control |
| `memory_pair_sum` | Two aligned loads and one reduction | No strong new directive |
| `load_word32` | Direct aligned 32-bit loads | Control case; no new directive |
| `load_byte` | Same data read byte-by-byte | Mostly existing `wide_load`; not a new directive |
| `load_byte_recompose` | Canonical byte ladder rebuilding wider values | Existing `wide_load`; main new lesson is to extend that story to packet/ctx memory later |
| `load_native_u64` | Native aligned 64-bit loads | Control for `wide_load`; no new directive |
| `stride_load_4` | Streaming strided loads | No compelling bounded directive |
| `stride_load_16` | Wider-stride streaming loads | No compelling bounded directive |
| `mixed_alu_mem` | Mixed memory and arithmetic | Minor `lea_fusion` at best; not strong enough for a dedicated directive |
| `checksum` | Endian-sensitive checksum-style arithmetic | Supports `bitfield_extract` and `rotate_fusion` |
| `packet_parse` | Packet header extraction with explicit guards | Strong evidence for `packet_ctx_wide_load`, `bounds_window`, and `bitfield_extract` |
| `bounds_ladder` | Dense staged-input bounds ladder | Strong evidence for `bounds_window` |
| `bounds_check_heavy` | Repeated dependent bounds checks | Strong evidence for `bounds_window` |
| `memcmp_prefix_64` | Many fixed-size prefix comparisons | Mostly reinforces existing `wide_load`; no persuasive new directive |
| `packet_parse_vlans_tcpopts` | Realistic Ethernet/VLAN/IPv4/TCP parse with option walk | Best synthetic evidence for `packet_ctx_wide_load`, `bounds_window`, and `bitfield_extract` together |
| `packet_rss_hash` | Parse 5-tuple then run Jenkins-style hash | Strong evidence for `packet_ctx_wide_load`, `bitfield_extract`, `rotate_fusion`, and `lea_fusion` |
| `packet_redundant_bounds` | Dominating packet window with redundant sub-checks | Purpose-built `bounds_window` benchmark |
| `struct_field_cluster` | Dense fixed-offset record loads | Supports `packet_ctx_wide_load` plus `bitfield_extract`; not a standalone directive |

### A.2 Branching and Control-Flow Benchmarks

| Benchmark | Main pattern | Beyond-current opportunity |
| --- | --- | --- |
| `binary_search` | Search tree over sorted data | Still mainly an existing `cmov_select` / branch-layout case |
| `branch_layout` | Hot/cold branch skew | Existing `branch_reorder` benchmark; no stronger new directive |
| `switch_dispatch` | Dense switch/select | Existing `cmov_select` benchmark; little new beyond that |
| `branch_dense` | Many conditional branches | Small `lea_fusion` in index math only; not a new control-flow directive |
| `branch_fanout_32` | Large fanout dispatch with work in each arm | Existing branch-layout/select work dominates; `bitfield_extract` only secondary |
| `deep_guard_tree_8` | Nested guard diamonds | Interesting for future guard-fact retention, but too branchy for current narrow validators |

### A.3 Loops, ALU Chains, and Code-Size Stressors

| Benchmark | Main pattern | Beyond-current opportunity |
| --- | --- | --- |
| `bitcount` | `x &= x - 1` loop plus rotates | Supports `rotate_fusion`; narrow `blsr`-style idiom exists but is too small to drive the roadmap |
| `log2_fold` | Shift/test recurrence | No strong new directive |
| `dep_chain_short` | Short serialized ALU chain | Looks more like scheduling/regalloc than directive work; not recommended |
| `dep_chain_long` | Long serialized ALU chain | Same as above |
| `spill_pressure` | Register-pressure stress | No bounded directive with good ROI |
| `multi_acc_4` | Cross-lane accumulator mixing | No strong new directive |
| `multi_acc_8` | Wider cross-lane mixing | No strong new directive |
| `fibonacci_iter` | Loop-carried recurrence | Loop optimization is outside the recommended scope |
| `fibonacci_iter_packet` | Packet-backed loop recurrence | Same conclusion as `fibonacci_iter` |
| `fixed_loop_small` | Fixed-trip recurrence loop | Minor `lea_fusion` / const-fold effects only |
| `fixed_loop_large` | Longer fixed-trip recurrence loop | Minor `lea_fusion` / const-fold effects only |
| `nested_loop_2` | Two-level bounded nested loop | Not a good directive target |
| `nested_loop_3` | Three-level bounded nested loop | Not a good directive target |
| `code_clone_2` | Repeated scalar block | Mostly synthetic support for `const_fold_region` |
| `code_clone_8` | Larger repeated scalar block | Same as above |
| `large_mixed_500` | Large mixed straight-line body | Only broad peepholes such as `lea_fusion`; no evidence for a new dedicated directive |
| `large_mixed_1000` | Very large mixed straight-line body | Same as above |
| `imm64_storm` | Many distinct 64-bit immediates | Synthetic support for `const_fold_region`, not for v1 |
| `alu32_64_pingpong` | Repeated width truncation/re-extension | Synthetic support for width-aware constant folding, not for v1 |
| `mega_basic_block_2048` | Giant straight-line block | Useful stressor for local peepholes, but not evidence for a standalone directive |
| `smallmul_strength_reduce` | Multiply-by-small-constant hot loop | Purpose-built `lea_fusion` benchmark |

### A.4 Calls, Helpers, Maps, and Atomics

| Benchmark | Main pattern | Beyond-current opportunity |
| --- | --- | --- |
| `bpf_call_chain` | Hot chain of local BPF calls | Strongest synthetic evidence for future `subprog_inline` |
| `local_call_fanout` | Local call fanout with multiple pressure profiles | Strong evidence for future `subprog_inline`; `lea_fusion` only secondary |
| `map_lookup_churn` | Same `input_map` lookup every round, then indexed load | Good evidence for narrow `map_lookup_cache` if helper effects can be modeled |
| `map_lookup_repeat` | Repeated same-key lookups in one hot loop | Purpose-built `map_lookup_cache` benchmark |
| `map_roundtrip` | Update then lookup same key repeatedly | Simple caching is invalidated by the update; only a richer helper/value-forwarding design could help |
| `hash_map_lookup` | Many varying hash-map lookups | Proves map-helper cost matters, but not a simple cacheable window |
| `percpu_map_update` | Repeated percpu map updates | No good bounded directive under current design |
| `helper_call_1` | One pure helper call | Tiny `helper_result_dce` opportunity, but not roadmap-worthy |
| `helper_call_10` | Ten pure helper calls | Same conclusion; helper cost dominates |
| `helper_call_100` | One hundred pure helper calls | Same conclusion; helper cost dominates even more strongly |
| `probe_read_heavy` | Repeated probe-read helper traffic | Would need helper-specific batching, not a current directive |
| `get_time_heavy` | Repeated `ktime_get_ns` calls | `helper_result_dce` is too weak to matter |
| `atomic_counter_xadd` | Atomic map-counter updates | Atomics dominate; no credible current directive |
