# Cross-Document Review

This review cross-checks:

- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/interface-design-detail.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`
- `docs/tmp/jit-pass-implementation-detail.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/additional_jit_optimizations.md`

Scope note:

- "Current interface" means `bpf_jit_dir_rec_hdr_v1` plus the v1 ABI in `interface-design-detail.md`.
- "Current JIT" means the current x86 `do_jit()` + `addrs[]` multi-pass emitter analyzed in `jit-pass-implementation-detail.md` and `bpf-jit-comp-analysis.md`.
- Where the docs do not freeze an x86 emitter or payload shape, I label the design as **Inferred** rather than pretending it is already specified.
- The requested `orig_range` check is folded into the `Issues` column in Section 1 because the requested table format has no dedicated `orig_range` column.

## 1. Directive Candidate vs Interface Format Compatibility

Bottom line: the transport is generic, but the *current* v1 record schema, precondition bits, remap rule, and validator story are still tuned for one contiguous range that becomes one local fused native region. That is a clean fit for `wide_load` and narrow `cmov_select`. It is only a partial fit, or no fit, for several discovery candidates (`interface-design-detail.md:267-268`, `interface-design-detail.md:371-483`, `bpf-jit-advisor-v6-review.md:50-63`, `bpf-jit-advisor-v6-review.md:99-104`).

| Directive | Blob expressible? | Precond fit? | Validator fit? | Payload design needed? | Issues |
| --- | --- | --- | --- | --- | --- |
| `packet_ctx_wide_load` | **Partial**. Generic record header can carry it, but current `wide_load` payload only supports `STACK` / `MAP_VALUE`. | **Partial**. `STRAIGHT_LINE`, `NO_INTERIOR_TARGET`, `CONST_OFFSET_MEM`, `SAME_BASE_MEM` help, but there is no shared bit for packet/ctx safety class, speculation-hardening exclusion, or "direct nonfaulting packet/ctx access". | **Partial**. The byte-ladder validator is reusable in principle, but current v1 safety rules explicitly exclude packet/ctx speculation-sensitive regions and `PROBE_MEM` / extable sites. | **Yes**. Best shape is either `WIDE_LOAD v2` with expanded `mem_class`, or a new `PACKET_CTX_WIDE_LOAD` payload carrying `{ width, mem_class, dst_reg, base_reg, base_off, min_align_log2, liveout_reg }`. | `orig_range` is enough only for one ladder. Main gap is not the header; it is the missing packet/ctx safety contract. The highest-value evidence is precisely in packet/ctx code, which current v1 excludes (`directive-discovery-analysis.md:67`, `directive-discovery-analysis.md:138`, `interface-design-detail.md:777-782`). |
| `bounds_window` | **Partial**. One redundant guard can be named as one contiguous record; full ladder/window elimination cannot. | **Weak partial**. Existing bits do not express "dominated by prior readable window", "single redundant guard to external fail path", or "entry range fact proves branch dead". `ONE_DIAMOND` is too narrow for many real parser guards, which branch to exit, not to a closed join. | **Partial at best**. A dedicated one-guard eliminator is plausible if the verifier retains exact entry range facts. A full window eliminator does not fit the current template. | **Yes**. New kind such as `REDUNDANT_GUARD_ELIDE` / `BOUNDS_WINDOW` with fields like `{ base_reg, limit_reg, checked_off, checked_width, cmp_cc, flags }`. | `orig_range` is sufficient for one guard site, not for deleting an entire parser ladder. The discovery doc says "single-diamond + retained facts", but many real packet bounds checks are not single closed diamonds; they are branch-to-exit guards. This is a real model mismatch (`directive-discovery-analysis.md:68`, `directive-discovery-analysis.md:117-127`, `interface-design-detail.md:376-383`). |
| `bitfield_extract` | **Yes** for a local straight-line region. | **Mostly yes** if scoped to local shift/mask/extract slices. May reuse `CONST_OFFSET_MEM` / `SAME_BASE_MEM` for memory-backed variants. | **Yes** for a straight-line exact matcher. | **Yes**. **Inferred** new payload such as `{ src_kind, dst_reg, src_reg, width, lsb, extract_width, endian, base_off }`. | `orig_range` is fine for a local slice. The main ambiguity is whether this is a pure register extract directive or a packet-field-load-plus-extract directive. Those are different legality stories. Packet-heavy evidence pulls it toward the latter, which current v1 excludes (`directive-discovery-analysis.md:69`, `directive-discovery-analysis.md:152`, `interface-design-detail.md:777-782`). |
| `rotate_fusion` | **Yes**. | **Yes**. Straight-line local region is enough. | **Yes**. Exact local pattern matcher is a natural fit. | **Yes**. **Inferred** payload such as `{ width, dst_reg, src_reg, dir, amount_kind, amount, prefer_bmi2 }`. | `orig_range` is sufficient. This is one of the cleanest current-framework fits because it is local and side-effect free (`directive-discovery-analysis.md:70`, `directive-discovery-analysis.md:108-115`). |
| `lea_fusion` | **Yes**. | **Yes**. Straight-line local region is enough. | **Yes**. Exact local matcher is a natural fit. | **Yes**. **Inferred** payload such as `{ width, dst_reg, base_reg, index_reg, scale_log2, disp32, form_flags }`. | `orig_range` is sufficient. Clean fit, but profitability depends on limiting the scope to scales/immediates that x86 `lea` can encode directly (`directive-discovery-analysis.md:71`, `directive-discovery-analysis.md:108-115`). |
| `wide_store` | **Yes**. | **Yes** for straight-line store ladders. Current shared bits are enough, although the kind-specific validator still has to prove store ordering and source-value consistency. | **Yes** for an exact straight-line store-ladder matcher. | **Yes**. New payload such as `{ width, mem_class, src_kind, src_reg, base_reg, base_off, min_align_log2, flags }`. | `orig_range` is sufficient for one store run. The main scoping decision is whether v1 accepts only direct stack/map-value stores or also packet/probe/arena cases. Current safety posture strongly suggests stack/map-value only (`directive-discovery-analysis.md:72`, `additional_jit_optimizations.md:377-411`, `interface-design-detail.md:777-780`). |
| `map_lookup_cache` | **Partial** in the trivial sense that a record can name a range, but **not expressible in the current *meaningful* model**. | **No**. Existing bits say nothing about helper purity, aliasing, invalidation, map/key identity, or "no intervening invalidator". | **No**. Current validators are exact local-shape checks; this wants helper-effect and alias reasoning. | **Yes**, but this is already drifting into mini-compiler territory: helper id, map identity, key source, reuse register, invalidation mask/window. | `orig_range` is often not enough because the optimization is defined by a window of helper call + uses + absence of invalidators. Current v1 also excludes helper/tail-call boundaries from directive regions (`directive-discovery-analysis.md:73`, `directive-discovery-analysis.md:132-140`, `interface-design-detail.md:779`). |
| `subprog_inline` | **No** in the current semantic model. One record names one contiguous range in one subprogram; inlining wants callsite + callee body, often across subprogram boundaries. | **No**. Current bits do not cover call-frame semantics, interprocedural facts, code budget, or tail-call reachability. | **No**. | **Yes**, but the needed payload is already beyond the current mechanism: callsite id, callee subprog id, code-size budget, stack delta, livein/liveout contract, maybe tail-call metadata. | `orig_range` is not sufficient. The current pipeline splits subprograms before JIT and patches pseudo calls afterward. This is qualitatively outside the existing design (`directive-discovery-analysis.md:74`, `directive-discovery-analysis.md:133-141`, `bpf-jit-advisor-v6-review.md:141-162`). |
| `const_fold_region` | **Partial**. One range can be named, but the current ABI has no way to describe the result without re-encoding semantics. | **Partial**. Straight-line helps, but current shared bits do not express value-state/width-truncation invariants. | **No**. A sound validator would need dataflow / symbolic evaluation, not a local shape check. | **Yes**. This would need something like `{ liveout regs and their final values/expressions }`, which is exactly why the discovery doc says it looks like a small compiler pass, not a narrow directive. | `orig_range` is locally sufficient, but the validator model is not. This is a poor fit even before JIT feasibility is considered (`directive-discovery-analysis.md:75`, `directive-discovery-analysis.md:143-148`). |
| `post_verifier_dce` / `helper_result_dce` | **Partial** for plain dead straight-line ALU/MOV regions; **no** for helper-result elimination. | **Weak partial** for plain DCE, **no** for helper-result DCE. Current bits do not express liveness or helper purity. | **No** in the current exact-template model. | **Yes**. Realistically this would split into two different kinds: a dead straight-line fragment eliminator and a helper-result-specific directive. | `orig_range` is enough for a dead straight-line fragment, but not the hard part. The hard part is proving deadness after verifier rewrites or proving a helper result can be elided at all (`directive-discovery-analysis.md:76`, `directive-discovery-analysis.md:146-148`). |
| `tail_call_specialize` | **No** in the current model. | **No**. Current bits do not cover cross-program semantics, poke descriptors, patch slots, or tail-call target identity. | **No**. | **Yes**, but the required payload would be large and cross-program: map/key identity, target program identity, maybe direct-slot metadata. | `orig_range` is not sufficient because the optimization fundamentally crosses program boundaries. The discovery doc already marks it outside the current framework (`directive-discovery-analysis.md:77`, `directive-discovery-analysis.md:141`). |

## 2. JIT Feasibility Cross-Check

Bottom line: in the *current* x86 backend, the cleanly supported family is "one contiguous post-verifier interval, one native region emitted at the interval entry, covered instructions skipped, `addrs[]` filled for the covered range" (`bpf-jit-advisor-v6-review.md:50-63`, `jit-pass-implementation-detail.md:196-277`). That is a natural fit for `wide_load` and narrow `cmov_select`. It is a good fit for local straight-line fusion directives. It is a bad fit for layout transforms, helper/call semantics, and cross-program work.

The `Const blinding?` column below is about the *current* x86 path. In current v1, blinding is a hard whole-blob drop (`interface-design-detail.md:182-184`, `bpf-jit-comp-analysis.md:1294-1328`).

| Directive | JIT emittable? | `addrs[]` impact | Const blinding? | PROBE_MEM? | x86 encoding |
| --- | --- | --- | --- | --- | --- |
| `packet_ctx_wide_load` | **Not as current Path A v1**. A future extension could emit it like `wide_load`, but current docs exclude the exact packet/ctx/spec-hardening cases that motivate it. | Same pattern as `wide_load` if ever supported: interior covered PCs collapse to the fused entry, `addrs[end]` points to the first uncovered instruction. | **Hard conflict today**: whole blob drops when blinding is active; packet-field variants also rely on immediate shifts/masks/endian ops that blinding perturbs. | Must reject any remapped site that becomes `BPF_PROBE_MEM*`, extable-producing, or speculation-hardened. | **Inferred**: same `emit_ldx(BPF_W/BPF_DW)` `movl` / `movq` core as `wide_load`, possibly plus `bswap` / `movbe` / `shr` / `and` for endian-sensitive fields. |
| `bounds_window` | **Partial**. A one-guard eliminator is plausible by emitting nothing for the redundant guard window. A full parser-window eliminator is not a clean `do_jit()` patch. | If a guard is fully removed, all covered PCs share the same native boundary and `addrs[end]` may equal `addrs[start]`. This is more like zero-length region elimination than fusion. | **Hard conflict today**: whole blob drops under blinding; guard shapes that depend on immediates also drift. | This is the biggest blocker. The high-value sites are packet/ctx bounds checks and speculation-sensitive parse guards, which current v1 explicitly excludes. | Stock pattern is usually `lea/add` to form `ptr+off`, then `cmp` / `ja` or `jbe` against `data_end`. Optimized form is to emit no `cmp` / `jcc`, or only keep address arithmetic if still needed. |
| `bitfield_extract` | **Yes**, if scoped to a local straight-line slice. No concrete emitter is frozen yet. | Same fused-range rule as `wide_load`: collapse local shift/mask chain into one entry sequence. | **Hard conflict today**: whole blob drops; most profitable cases use immediate shifts/masks. | Safe only if the source is already nonfaulting stack/map-value data or a register value. Packet/ctx-backed forms hit the same exclusion as `packet_ctx_wide_load`. | **Inferred**: `movzx`, `mov`, `movbe`, `shr`, `and`, maybe BMI1 `bextr` if the scope expands that far. |
| `rotate_fusion` | **Yes**. This is a clean local peephole in the current JIT model. | Covered shift/or sequence collapses to one native rotate sequence; interior PCs share one native start. | **Hard conflict today**: whole blob drops; rotate-by-immediate patterns are exactly the sort of `*_K` shape blinding rewrites. | Not relevant. | `rorx` when BMI2 is available and desirable; otherwise `rol` / `ror`. (`additional_jit_optimizations.md:299-330`) |
| `lea_fusion` | **Yes**. Clean local peephole. | Collapse `mov` / `add` / `shift` / small-scale arithmetic chain to one `lea` region. | **Hard conflict today**: whole blob drops; small-constant patterns also drift under blinding. | Not relevant. | `lea disp(base,index,scale), dst`. (`additional_jit_optimizations.md:352-373`) |
| `wide_store` | **Yes**. This is the store-side analogue of `wide_load`. | Same covered-range collapse as `wide_load`: many byte-store PCs map to one native store entry. | **Hard conflict today**: whole blob drops; immediate stores are also rewritten during blinding (`store-immediate` becomes load-to-`ax` + `STX`). | Must reject probe/arena/extable-producing stores. Direct stack/map-value stores are the obvious safe subset. | `movl` / `movq [base+off], reg`; for zero-init, possibly `xor reg, reg` + `movq [mem], reg` or `mov qword ptr [mem], 0` where legal. (`additional_jit_optimizations.md:377-411`) |
| `map_lookup_cache` | **No** in the current local emitter model. It wants to eliminate or reuse helper calls across a window. | Not a local covered-range story. It wants call-site + downstream uses, often across multiple native regions. | Not the main issue. The whole blob still drops today, but helper semantics are the real blocker. | Not directly. | Would have to suppress repeated `call __bpf_call_base + imm32` helper sequences and reuse the returned pointer/value, likely via `mov`/register reuse. The docs do not present a viable current-path emitter. |
| `subprog_inline` | **No**. The current pipeline splits subprograms before JIT and JITs each subprogram separately. | Breaks per-subprog `addrs[]`, line info, symbol boundaries, and callsite patch flow. | Not the main issue. | If the callee contains probe/exception/tail-call sites, all of that metadata would also have to move. | Would replace `call rel32` / patched pseudo-call sites with inlined body code and remove matching prologue/epilogue edges. That is not a local `do_jit()` fast-path. |
| `const_fold_region` | **Not realistically** in the current linear emitter. | Would delete/collapse many local PCs; mechanically possible, but it needs dataflow rather than a local x86 emitter hook. | **Worst conflict**: this candidate is dominated by immediate-heavy code, exactly what blinding rewrites. | Not directly. | Could reduce to shorter `mov imm`, `add imm`, `lea`, or no code at all, but no concrete x86 lowering is frozen because the hard part is proof, not emission. |
| `post_verifier_dce` / `helper_result_dce` | **Plain dead ALU/MOV elimination: maybe, but low value. Helper-result DCE: no.** | Plain DCE would create zero-length or shorter regions; helper-result DCE wants to remove or bypass helper call sequences, which is not a local safe emitter tweak. | **Hard conflict today** for immediate-heavy dead code; helper case is dominated by semantics, not blinding. | Helper-result DCE crosses helper boundaries, which current v1 explicitly excludes. | Plain DCE emits nothing for removed code. Helper-result DCE would have to remove `call`-driven sequences, which the discovery doc itself argues is not the right direction. |
| `tail_call_specialize` | **No**. Tail calls already have dedicated verifier rewriting, direct-tail-call patch slots, and post-finalization fixups. | Interacts with fixed patch geometry and poke descriptors rather than a simple covered-range map. | Not the main issue. | Not directly, but the same "special metadata site" problem exists. | Would have to alter the `emit_bpf_tail_call_direct()` / `emit_bpf_tail_call_indirect()` machinery and 5-byte patchable jump slots, not just choose a different local instruction encoding (`bpf-jit-comp-analysis.md:532-560`, `bpf-jit-comp-analysis.md:1418-1424`). |

## 3. Evidence Quality Assessment

One cross-document caution matters up front: the micro suite is useful for mechanism isolation, but `bpf-jit-advisor-v6.md` explicitly says the current microbenchmark suite covers only about `0.8%` of the observed 5D real-program feature box (`bpf-jit-advisor-v6.md:638-643`). So the right reading is:

- microbenchmarks: good for "can this mechanism matter at all?"
- corpus/workload evidence: required for "is this worth interface budget?"

| Directive | Micro-benchmark evidence | Corpus / workload evidence | Is the benchmark isolating the right pattern? | Would the gain likely survive real cache/TLB/branch effects? |
| --- | --- | --- | --- | --- |
| `packet_ctx_wide_load` | **Strong**. `packet_parse`, `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `struct_field_cluster` all show the pattern. | **Strong**. Cilium `tc` / cgroup parsers, `nat64_kern`, `bpf_overlay` all show repeated fixed-offset packet/ctx extraction. | **Medium**. `struct_field_cluster` is useful but explicitly not a standalone directive benchmark; most packet benchmarks mix load fusion with bounds and bitfield work. | **High if the safety contract exists**. Packet fast paths are hot enough that shorter load sequences should survive front-end noise. The blocker is legality, not likely external validity. |
| `bounds_window` | **Strong**. `bounds_ladder`, `bounds_check_heavy`, and dedicated `packet_redundant_bounds` are on point; the smoke result is large (`71 ns` vs `115 ns`, `273 B` vs `717 B`). | **Moderate to strong**. Real packet parsers do have the same guard ladders, especially in XDP/TC. | **Strong** for `packet_redundant_bounds`; **medium** elsewhere because packet parsers also mix field extraction. | **Medium-high**. Removing truly redundant guards should survive, but exact gains depend on branch predictor behavior and speculation-hardening details. |
| `bitfield_extract` | **Moderate to strong**. `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `checksum`, `struct_field_cluster`. | **Moderate**. Packet/socket parsers make this believable, but the corpus evidence is qualitative, not quantified. | **Medium**. The current benchmarks often mix load widening, endian handling, and arithmetic. | **Medium**. The gain is real, but often piggybacks on `packet_ctx_wide_load`; the pure extract-only upside is smaller. |
| `rotate_fusion` | **Moderate**. `packet_rss_hash`, `checksum`, `bitcount`, `smallmul_strength_reduce`; `additional_jit_optimizations.md` estimates impact in about `10/31` pure-JIT benchmarks. | **Weak to moderate**. The workload claim is "real packet/policy hashes use the same structure", but the corpus evidence is qualitative. | **Medium**. `bitcount` isolates the bit-twiddle side well; packet/hash benchmarks mix multiple missing idioms. | **Medium**. On rotate-heavy loops the win should survive; on mixed code it will often be noise. |
| `lea_fusion` | **Moderate**. `smallmul_strength_reduce` is a good dedicated signal; `packet_rss_hash`, `local_call_fanout`, `branch_dense` add breadth. | **Moderate**. Parser indexing and record walking are plausible production patterns. | **Strong** for `smallmul_strength_reduce`; **medium** elsewhere. | **Low-medium**. Likely to survive, but as small per-site improvements rather than dramatic wins. |
| `wide_store` | **Strong for code size, modest for runtime**. `additional_jit_optimizations.md` argues the pattern shows up in roughly `31/31` pure-JIT cases. | **Moderate**. `ksnoop` and `bpf_overlay` contain the same stack-zero/init style runs. | **Strong**. The store-side pattern is well isolated. | **High for code size, low-medium for runtime**. This should survive, but mostly as code-size recovery and fixed-overhead reduction. |
| `map_lookup_cache` | **Medium**. `map_lookup_repeat` and `map_lookup_churn` isolate the idea, but the smoke run does *not* show a current LLVM-style backend win. | **Weak for the actual optimization, strong only for prevalence**. Map lookups are everywhere, but same-key short-window reuse is not quantified. | **Strong** in the synthetic sense. | **Uncertain**. Real programs have invalidations, differing keys, helper interactions, and memory traffic that the microbenchmarks abstract away. |
| `subprog_inline` | **Medium**. `bpf_call_chain` and `local_call_fanout` isolate call overhead. | **Strong on prevalence, weak on hotness**. Multi-function objects are common, but that does not prove profitable inline targets. | **Medium**. The microbenchmarks isolate call overhead well, but not I-cache/code-size tradeoffs on real programs. | **Medium**. It can survive on hot call chains, but the tradeoff is highly program-specific. |
| `const_fold_region` | **Strong synthetic**. `const_fold_chain` and related benchmarks show very large artificial gaps. | **Weak**. The discovery doc says direct production evidence is little/weak. | **Strong synthetic isolation**, but it isolates a compiler problem more than a directive problem. | **Low**. The synthetic wins are unlikely to transfer cleanly once real cache, code mix, and already-folded constants enter the picture. |
| `post_verifier_dce` / `helper_result_dce` | **Weak**. The cited helper benchmarks mostly prove helper cost dominates. | **Weak**. The tracing/corpus discussion explicitly argues this is not the leverage point. | **Fair**, but mostly as negative evidence. | **Low**. Even if it works, the effect is likely swamped by helper latency and other real effects. |
| `tail_call_specialize` | **Very weak**. There is no dedicated microbenchmark in the discovery doc. | **Medium only as prevalence evidence**. Tail calls are common in objects and workloads, but fixed-index/predictable-target cases are not quantified. | **Poor**. Current evidence does not isolate the intended specialization opportunity. | **Unknown**. The upside could be real, but the current evidence does not support a v1 commitment. |

Two evidence nuances are easy to miss:

1. `struct_field_cluster` and `smallmul_strength_reduce` are used as supporting evidence for `packet_ctx_wide_load` / `bitfield_extract` / `lea_fusion`, but in the smoke data the kernel is already faster there. Those benchmarks support *pattern presence* and code-shape arguments, not a clean "advisor recovers an existing LLVM win" story (`directive-discovery-analysis.md:179-180`).
2. `map_lookup_repeat` is a purpose-built future benchmark, but it does not currently support a backend-gap narrative because the kernel already beats llvmbpf there (`directive-discovery-analysis.md:178`).

## 4. Contradictions and Gaps

### 4.1 High-level design vs actual JIT feasibility

1. The core structural contradiction from the earlier docs is real: the current `do_jit()` + `addrs[]` model naturally supports local region fusion, not general CFG/layout or interprocedural transforms (`bpf-jit-advisor-v6-review.md:50-65`, `jit-pass-implementation-detail.md:196-277`, `bpf-jit-comp-analysis.md:1473-1474`).
2. `kernel-jit-optimization-plan.md` still contains two incompatible messages:
   - Section 4.1 says `branch_reorder` "**应加入 v1**" (`kernel-jit-optimization-plan.md:195-196`).
   - Later, the design-decision section says pure Path A is insufficient and recommends **Hybrid**, with `branch_reorder` moved to verifier rewrite (`kernel-jit-optimization-plan.md:424-444`).
   These cannot both be read as the current v1 implementation plan.
3. The interface doc is generic at the transport layer, but the *meaningful* current v1 semantics are not generic yet. Unknown kinds are rejected, current shared preconditions are JIT-shape oriented, and only `WIDE_LOAD` / `CMOV_SELECT` have frozen payloads (`interface-design-detail.md:371-506`).

### 4.2 Interface vs candidate inventory

1. `directive-discovery-analysis.md` and the hub both elevate `bitfield_extract`, `rotate_fusion`, `lea_fusion`, `wide_store`, and `bounds_window` into serious v1 discussion (`directive-discovery-analysis.md:150-170`, `kernel-jit-optimization-plan.md:150-160`, `kernel-jit-optimization-plan.md:203-209`).
2. `interface-design-detail.md` still exposes exactly two kinds and two payloads. So all of those "v1 candidates" are conceptually present in the paper/hub story but absent from the actual ABI (`interface-design-detail.md:371-483`).
3. `packet_ctx_wide_load` is the clearest example of a paper/API mismatch:
   - discovery doc: "highest-value post-v1 substrate extension" from real packet/ctx workloads (`directive-discovery-analysis.md:67`, `directive-discovery-analysis.md:154-155`);
   - interface doc: no packet/ctx mem class, and explicit exclusion of packet/ctx regions relying on speculation hardening (`interface-design-detail.md:443-456`, `interface-design-detail.md:777-782`).
4. `bounds_window` is presented as "single-diamond + retained facts" in discovery/hub (`directive-discovery-analysis.md:119-127`, `kernel-jit-optimization-plan.md:157-158`, `kernel-jit-optimization-plan.md:208`), but the current precondition vocabulary has no way to express "dead guard due to dominating readable window", and many real guards are not closed diamonds.

### 4.3 v6 examples vs frozen contracts

1. The v6 `cmov_select` example is broader than the frozen contract.
   - v6 example: expression-style select, with `acc + index` and `acc ^ (target + 32)` inside the selected values (`bpf-jit-advisor-v6.md:346-412`).
   - current payload: pure assignment of `true_val` / `false_val` as reg-or-imm references (`interface-design-detail.md:474-483`).
   - v6 review: explicitly says those are different directives and the current validator only covers the pure-assignment one (`bpf-jit-advisor-v6-review.md:184-189`).
2. `hot_fallthrough` in v6 and `branch_reorder` in the hub are not the same thing.
   - v6 sketches a *bounded one-diamond layout choice* (`bpf-jit-advisor-v6.md:420-446`).
   - the hub often uses the broader term `branch_reorder` (`kernel-jit-optimization-plan.md:196`, `kernel-jit-optimization-plan.md:440-447`).
   The JIT feasibility docs only leave room for the narrow one-diamond version, not the general one.

### 4.4 Numbers and evidence usage that need tighter wording

1. `struct_field_cluster` (`98 ns` llvmbpf vs `76 ns` kernel) and `smallmul_strength_reduce` (`393 ns` vs `349 ns`) are supporting evidence for patterns, not for current LLVM-over-kernel deficits (`directive-discovery-analysis.md:179-180`).
2. `map_lookup_repeat` is the strongest synthetic benchmark for "repeated same-key lookup", but it points the wrong way for a backend-gap story (`1.744 us` llvmbpf vs `678 ns` kernel) (`directive-discovery-analysis.md:178`).
3. The discovery doc is careful about these caveats; the hub doc should preserve that caution instead of letting the candidate table read like all of these are current-path wins.

### 4.5 Missing implementation-critical details

1. `orig_idx` propagation is still incomplete in the current tree, so any cross-doc sentence that assumes remap already works is aspirational, not current state (`bpf-jit-advisor-v6-review.md:265-272`, `jit-pass-implementation-detail.md:1122-1179`, `bpf-jit-comp-analysis.md:951-962`).
2. Constant blinding is still a hard cutoff on the current JIT-lowering path. This is not a footnote; it removes the whole advisor on the blinded path (`interface-design-detail.md:182-184`, `bpf-jit-advisor-v6-review.md:274-287`, `bpf-jit-comp-analysis.md:1294-1328`).
3. Canonical-PC semantics for moved or duplicated code are still undefined, which is why general `branch_reorder` is not just "one more directive kind" (`bpf-jit-advisor-v6-review.md:195-204`, `bpf-jit-advisor-v6-review.md:388-399`).

## 5. The Elephant in the Room: Path B

Here "Path B" means the verifier-level rewrite path from the hub doc, not the deployment Scenario B in the interface doc. The hub's later decision section is explicit:

- Path A: directive guides JIT emission; clear for `wide_load` / `cmov_select`, but limited to local peepholes.
- Path B: directive guides verifier-side BPF rewrite; supports non-local transforms and is cross-arch.
- Recommended direction: **Hybrid** (`kernel-jit-optimization-plan.md:424-444`).

### 5.1 Which candidates become easier under Path B?

1. `bounds_window`
   - **Much easier.**
   - Reason: the verifier already owns the exact range facts, CFG, and packet safety story. Eliminating a redundant guard is much more natural as a verifier-side BPF rewrite than as a JIT-side "emit nothing" trick.
   - It also avoids the current packet/ctx/speculation exclusion problem on the JIT side.
2. `packet_ctx_wide_load`
   - **Much easier.**
   - Reason: the verifier already knows pointer class, fixed offset, readable window, and where speculation hardening was inserted. Rewriting byte ladders to wider BPF loads is a verifier problem first and an x86 encoding problem second.
   - Cross-arch story also improves immediately because the stock JITs consume ordinary wider BPF loads.
3. `wide_store`
   - **Easier.**
   - Reason: BPF already has wider store opcodes. Rewriting adjacent byte stores into one wider store at the BPF level avoids `addrs[]` and canonical-PC headaches.
4. `const_fold_region`
   - **Easier**, though still probably not worth doing.
   - Reason: if you insist on it, this is much more naturally done as a verifier rewrite/dataflow pass than as a JIT directive.
5. `post_verifier_dce`
   - **Easier** for the same reason: dead-code elimination is naturally verifier-side.
   - `helper_result_dce` does **not** become easy; helper purity and semantic modeling are still hard.
6. `branch_reorder` / `hot_fallthrough`
   - **Much easier**.
   - Reason: verifier-level CFG permutation is exactly the sort of structural transformation the JIT docs say current `do_jit()` cannot do cleanly.
7. `subprog_inline`
   - **Moves from "wrong layer" to "hard but coherent".**
   - The verifier already owns subprogram splitting, call rewriting, stack-depth accounting, and tail-call reachability. It is still a big project, but it stops fighting the pipeline.
8. `map_lookup_cache`
   - **Somewhat easier**, but still hard.
   - The hard part is helper-effect / invalidation modeling, which belongs closer to verifier semantics than to the x86 emitter.
9. `tail_call_specialize`
   - **Somewhat easier**, but still hard / likely out of near-term scope.
   - The verifier already rewrites tail calls and creates direct-tail-call poke descriptors. That makes Path B more coherent than Path A, but the semantics are still cross-program and operationally tricky.

### 5.2 Which candidates become harder or impossible under pure Path B?

1. `rotate_fusion`
   - **Harder under pure Path B.**
   - BPF has no rotate opcode. The x86-specific win is exactly the backend choice of `rorx` / `rol` / `ror`.
2. `lea_fusion`
   - **Harder under pure Path B.**
   - BPF has no `lea`-equivalent opcode. This is an x86 lowering choice over existing BPF arithmetic.
3. `bitfield_extract`
   - **Splits into two different cases.**
   - Packet-field extraction that is really "load wider, then simplify shifts/masks" becomes easier if Path B first rewrites the load side.
   - Pure backend extract choices (`movbe`, maybe `bextr`) become harder under pure Path B because BPF has no direct way to ask for them.
4. `cmov_select`
   - Not in the discovery table, but important for the design: pure Path B weakens the nicest current userspace-policy story, because the target-specific lowering choice (`cmovcc` vs branch on x86, `csel` vs branch on arm64) is exactly where JIT lowering still adds value.

### 5.3 Does the current interface design work equally well for Path B?

**Transport: mostly yes. Mechanism semantics: not quite.**

What still works well:

- digest-bound blob on the exact load image;
- one sealed memfd per `BPF_PROG_LOAD`;
- CPU contract, `policy_id`, `policy_version`, `workload_class`;
- per-site telemetry / structured results;
- fail-closed fallback to stock semantics.

What does **not** map cleanly without changes:

1. The current shared precondition bits are JIT-shape biased.
   - `STRAIGHT_LINE`, `ONE_DIAMOND`, `NO_INTERIOR_TARGET`, `CONST_OFFSET_MEM`, `SAME_BASE_MEM` were chosen for JIT-side validators.
   - Path B wants more verifier-semantic facts: dominance, post-dominance, liveness, stack-depth deltas, tail-call reachability, helper-purity classes, etc.
2. The current control flow is documented as:
   - remap original coordinates;
   - run kind-specific validators;
   - emit/fallback in JIT (`interface-design-detail.md:636-645`, `interface-design-detail.md:1280-1290`).
   Path B needs:
   - remap / match;
   - rewrite BPF;
   - then let the ordinary verifier/JIT pipeline continue.
3. The current result taxonomy should grow a **stage** dimension.
   - Today the model is basically "accepted/rejected/dropped at JIT-lowering time".
   - Hybrid wants at least "rewritten in verifier", "accepted in JIT", "rejected in verifier", "rejected in JIT".
4. `orig_range` still works, but the interface should stop implying that every accepted directive becomes one fused native region.
   - That is true for current Path A local fusion.
   - It is false for Path B rewrite directives.

### 5.4 Does the directive ranking change under Path B?

Yes, materially.

**Rises under Path B / Hybrid**

- `bounds_window`
- `packet_ctx_wide_load`
- `wide_store`
- `branch_reorder`
- `post_verifier_dce` (though still low value)
- `const_fold_region` (mechanically easier, still likely low priority)
- `subprog_inline` (from impossible-in-layer to hard-but-plausible)

**Falls under pure Path B**

- `rotate_fusion`
- `lea_fusion`
- backend-centric `bitfield_extract`

**Best Hybrid split**

- verifier rewrite: `bounds_window`, `packet_ctx_wide_load`, likely `wide_store`, maybe future `branch_reorder`
- JIT lowering: `cmov_select`, `rotate_fusion`, `lea_fusion`, backend-centric `bitfield_extract`

One more important Path B point: for rewrite-only directives, the current constant-blinding blocker becomes much smaller. If the verifier rewrites the BPF program first, blinding simply runs on the already-rewritten BPF program. That is a real advantage over the current Path A-only design.

## 6. Actionable Recommendations

### 6.1 Which directives should definitely be in the v1 prototype?

There are really two coherent answers, and the docs are currently mixing them.

**If v1 means "smallest working prototype on the current JIT-level substrate":**

- definitely include existing `wide_load`
- definitely include **narrow** `cmov_select` only
- add `wide_store`
- add `rotate_fusion`
- add `lea_fusion`
- add `bitfield_extract` **only** if it is scoped to straight-line register/stack/map-value extracts, not to packet/ctx field extraction

This is the clean JIT-level set because all of them are local region fusion or local straight-line peepholes.

**If v1 means "the strategically correct direction already recorded in the hub doc":**

- keep `wide_load`
- keep narrow `cmov_select`
- move `bounds_window` to verifier rewrite
- move `packet_ctx_wide_load` to verifier rewrite
- keep `rotate_fusion` / `lea_fusion` on the JIT-lowering side
- put `wide_store` on whichever side is implemented first, but verifier rewrite is cleaner

That is the more coherent **Hybrid** set.

### 6.2 Which directives should be cut from near-term scope?

Cut from Path A v1:

- `packet_ctx_wide_load`
- `bounds_window`
- `map_lookup_cache`
- `subprog_inline`
- `const_fold_region`
- `post_verifier_dce` / `helper_result_dce`
- `tail_call_specialize`
- general `branch_reorder`

Reason:

- the first two are strong *ideas* but want verifier-level semantics and/or packet safety contracts;
- the next five are genuine framework-extension or semantic-model projects;
- `branch_reorder` is exactly the thing the current JIT docs say does not fit local `do_jit()` patching.

### 6.3 What interface design changes are needed for the recommended v1 set?

For the **minimal JIT-level v1** set:

1. Add new kind enum values and payloads for:
   - `WIDE_STORE`
   - `ROTATE_FUSION`
   - `LEA_FUSION`
   - maybe `BITFIELD_EXTRACT`
2. Freeze `cmov_select` to the current narrow contract in the ABI text:
   - pure destination assignment only;
   - explicit 32 vs 64-bit compare/`cmov` rules;
   - explicit x86 immediate-arm handling via `r11`, or explicitly reject immediate arms in x86 v1.
3. Add explicit reject reasons for the cases the current docs know are special:
   - `CONST_BLINDING`
   - `PROBE_MEM_OR_EXTABLE`
   - `TAIL_CALL_OR_POKE_SITE`
   - `SPEC_HARDENING_REGION`
   - `TEMP_LIVEOUT`
4. Keep the current one-range/non-overlap rule for this JIT-level v1. It is a good constraint for local fusion directives.

For the **Hybrid** direction that the hub now recommends:

1. Add a notion of **application stage** now, before the ABI ossifies.
   - Something like `BPF_JIT_STAGE_VERIFIER_REWRITE` vs `BPF_JIT_STAGE_JIT_LOWERING`.
2. Stop letting `precond_mask` pretend to be sufficient for both stages.
   - JIT-lowering and verifier-rewrite directives need different fact vocabularies.
3. Extend result telemetry so a site can report:
   - rewritten in verifier;
   - accepted in JIT;
   - rejected in verifier;
   - rejected in JIT.

### 6.4 What is the critical path to a working prototype?

1. **Settle the path explicitly.**
   - The docs currently mix "Path A local fusion v1" and "Hybrid recommended".
   - The implementation plan and interface need one chosen story.
2. **Fix `orig_idx` propagation.**
   - Without this, even the current `wide_load` / `cmov_select` remap story is incomplete.
3. **Land transport + parser + fail-closed policy + logging/results.**
   - This part is already well designed in `interface-design-detail.md`.
4. **Build the shared remap / validation preparation stage.**
   - For Path A: post-rewrite remap, CFG target map, and post-rewrite liveness for directive-bearing programs.
   - For Hybrid: stage-aware matcher / rewrite preparation.
5. **Implement `wide_load`.**
   - This is the cleanest first directive and the most defensible correctness story.
6. **Implement narrow `cmov_select`.**
   - Freeze the pure-assignment contract first; do not carry the v6 expression-selector example into code.
7. **Add one more low-risk breadth directive.**
   - `wide_store` is the safest extra breadth.
   - `lea_fusion` is the next clean candidate.
   - `rotate_fusion` is also good if BMI2 feature gating is already in place.
8. **Only then decide whether the first structural extension is `bounds_window` or `packet_ctx_wide_load`.**
   - If the project stays Path A, defer them.
   - If the project follows the hub's current Hybrid recommendation, make one of them the first verifier-rewrite directive.

## Bottom Line

The eight documents are aligned on one important fact: the current x86 JIT substrate cleanly supports local region fusion and not much more. They are **not** yet aligned on the implementation plan that follows from that fact.

The discovery doc is right that the strongest real-workload opportunities after current `wide_load` are packet/ctx load widening and redundant bounds elimination. The JIT docs are right that those are not clean current-Path-A `do_jit()` directives. The hub doc's later Hybrid decision is therefore the most coherent synthesis.

If the project wants a small, working prototype fast, keep v1 to local JIT-level directives: `wide_load`, narrow `cmov_select`, `wide_store`, `rotate_fusion`, `lea_fusion`, and maybe a tightly scoped `bitfield_extract`.

If the project wants the strongest long-term design, keep that local prototype, but move `bounds_window`, `packet_ctx_wide_load`, and future `branch_reorder` into the verifier-rewrite side of a Hybrid v7.
