# BpfReJIT v6 Interface Design

Date: 2026-03-11

## 0. Framing

BpfReJIT v6 should strengthen the same core boundary, not change it:

- kernel owns safety, validation, and native emission
- userspace owns pattern discovery, cost model, and policy
- kernel never executes userspace-supplied machine code

The main v6 correction is architectural:

- userspace fact discovery and kernel safety validation are different problems
- verifier log already solves the discovery side for the current v6 scope
- most near-term gaps are missing canonical forms or missing site kinds, not missing verifier semantics

So the right v6 question is not "how do we export more verifier internals first?" It is:

> how do we remove current v5 friction, add the missing site kinds, and add more kernel-owned canonical emitters while letting userspace drive policy with facts it can already read today?

The main answer is:

- use verifier log parsing in userspace now
- keep kernel legality checks pattern-based now
- reserve kernel verifier-fact export as optional future work, not a prerequisite

---

## 1. What Verifier Log Already Exposes

### 1.1 Acquisition path

Today userspace can already ask the verifier to emit a textual trace through `BPF_PROG_LOAD.log_level/log_size/log_buf/log_true_size`; the shared logging machinery is in `vendor/linux-framework/kernel/bpf/log.c`, and the log-level bits are defined in `vendor/linux-framework/include/linux/bpf_verifier.h`.

Operationally, if userspace wants to mine facts from the log, it should use:

- `BPF_LOG_LEVEL2` when possible, because plain `LEVEL1` misses SCC/liveness and many full-state dumps
- `BPF_LOG_FIXED`, so the buffer behaves like the verifier log path rather than a rotating ring
- `log_true_size`, so truncation is detectable

Relevant code:

- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/log.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`

### 1.2 Fact classes visible in the log today

| Fact class | Log format today | Immediate value to userspace | Main caveat |
| --- | --- | --- | --- |
| Register type and modifiers | `R6=pkt(...)`, `R1=trusted_ptr_foo(...)`, `R2=scalar(...)` | Pointer class, nullability, trusted/untrusted, mem/packet/BTF distinctions | Textual, not a stable ABI |
| Scalar bounds and tnum | `smin/smax/umin/umax/smin32/...`, `var_off=(value; mask)` | Enough to recover min/max windows and bit-level uncertainty | Omitted defaults and coalesced equal 32/64-bit bounds mean parser must normalize |
| Pointer provenance | `id=`, `ref_obj_id=`, `off=`, `imm=`, `r=`, `sz=`, BTF type names, map key/value sizes | Correlates same-provenance pointers across a region; distinguishes map/pkt/mem/BTF access windows | Some pointer types are underprinted |
| Stack slot state | `fp-8=...`, spill state, `dynptr_*`, `iter_*` | Spilled reg facts, zero/misc/invalid bytes, dynptr/iter presence, stack occupancy | Some stack details are still underprinted |
| Ref-set summary | `refs=...` | Tells userspace whether ref-tracked objects are live | No ref type or allocation-site detail |
| Branch / path trace | `from A to B:`, `safe`, caller/callee transitions, `cur state:` / `old state:` | Userspace can reconstruct visited states and some branch outcomes | No explicit stable edge IDs or dominance tree |
| SCC and loop context | `SCC enter`, `SCC exit`, `SCC backedge` | Lets userspace know when a site is in a loop/SCC | `LEVEL2` only |
| Live register pressure | `Live regs before insn:` bitmap | Useful for code-size and register-pressure heuristics | Registers only; no stack live-in/live-out |
| CFG rejection / dead markers | `unreachable insn N`, `back-edge from insn A to B`, `infinite loop detected` | Userspace can detect rejected dead/unreachable shapes | Runtime-dead code is not exported as a structured fact |
| Source correlation | source line text + `@ file:line` | Handy for tooling and policy debugging | Line-only; duplicates suppressed |

### 1.3 Concrete information userspace can recover

Userspace can already extract the fact categories called out in the v6 requirements:

- register bounds:
  - `min/max`, `umin/umax`, `s32_min/s32_max`, `u32_min/u32_max`, `var_off`
- pointer type and provenance:
  - `reg_type`, nullability, trust modifiers, `id`, `ref_obj_id`, `off`, packet `range`, mem `size`, BTF type name, map sizes
- stack slot state:
  - spilled register state, `STACK_MISC`, `STACK_ZERO`, `STACK_INVALID`, dynptr, iter
- branch taken / not-taken information:
  - partially yes, by replaying the path trace and noting when the verifier follows only one successor
- dead code markers:
  - partially yes, through `unreachable insn` rejection and `safe` pruning markers
- loop / pressure context:
  - SCC membership and `live_regs_before` sets at `LEVEL2`

### 1.4 What the log is not

The current verifier log is useful, but it is not a kernel safety ABI.

Important limits:

- It is free-form text, not a stable machine-readable UAPI.
- It is path-sensitive and often delta-only:
  - ordinary per-insn logs print only scratched regs/slots
  - full-state dumps happen only at selected transition sites
- One BPF instruction can appear with multiple verifier states.
- It does not export a stable per-edge or per-state identifier.
- Some real verifier facts are not printed at all:
  - richer stack metadata
  - ref type / allocation insn
  - stack liveness
  - a stable runtime-dead bitmap

That matters for ergonomics, but it does not force verifier changes for the current v6 baseline, because the kernel does not need to trust parsed log text as the legality proof.

### 1.5 Zero-kernel-change production path

This is the key correction.

For the current v6 scope, a complete zero-verifier-change workflow already exists:

1. Userspace loads the program with verifier logging enabled.
2. Userspace parses the log to recover bounds, types, stack state, branch context, SCC context, and liveness.
3. Userspace uses those facts only for discovery and policy:
   - decide whether a site is interesting
   - rank legal alternatives
   - decide hot-path placement, code-size budget, or liveness-sensitive choices
4. Userspace sends ordinary re-JIT rules that name a site, a pattern, constraints, and a kernel-owned canonical form.
5. The kernel ignores the parsed text and independently re-validates safety against the real xlated program before emitting native code.

So:

- discovery uses verifier log
- safety uses pattern match plus kernel-owned emitter validation
- no verifier export is required to make v6 useful

### 1.6 Optimization assessment

The current verifier log is already enough for:

- better userspace site discovery for existing v5 families
- policy-sensitive `BRANCH_FLIP` ranking based on workload hotness
- `DIV_LIVENESS` ranking using `live_regs_before`
- loop-aware and pressure-aware heuristics that avoid code expansion in SCCs or high-pressure regions
- offline experiments for bounds-oriented ideas

It is not, by itself, a kernel safety proof for transformations whose correctness depends on semantic reasoning rather than local shape preservation.

That boundary is the important one:

- if userspace needs more information to choose among already-safe alternatives, parse verifier log
- if kernel needs to prove the transform preserves safety, use pattern match plus constraints when that is enough
- only transforms like `BOUNDS_ELIDE` or general `DEAD_STORE_ELIM` need extra kernel-side reasoning

---

## 2. Fact Channel Options

### 2.1 Option 1: userspace parses verifier log

Mechanism:

- userspace requests `BPF_PROG_LOAD` verifier log
- parses textual register/stack/CFG/liveness facts
- constructs richer policy from those facts

Pros:

- zero verifier changes
- zero new kernel state
- richest information immediately available
- already enough for the current v6 discovery problem
- production-safe because the kernel still does not trust the parsed text as the legality proof

Cons:

- text ABI is brittle
- truncation and log-level dependence are awkward
- userspace parsers must be version-aware
- poor fit if the long-term goal is a stable machine-readable fact ABI

Best use:

- recommended production solution for v6 discovery and policy construction
- immediate deployment path
- acceptable long-term path as long as fact parsing remains on the discovery side, not the kernel safety side

### 2.2 Option 2: export a verifier summary through `BPF_OBJ_GET_INFO_BY_FD`

Mechanism:

- extend `struct bpf_prog_info` with an optional verifier-fact array
- expose a kernel-owned summary keyed to the loaded program

Pros:

- stable machine-readable ABI
- cleaner tooling
- easier versioning than free-form text

Cons:

- needs verifier-summary capture and syscall plumbing
- duplicates information userspace can already recover today
- still does not remove the need for kernel-side legality checks in the re-JIT path

Best use:

- optional future optimization for tooling and ergonomics
- not required for baseline v6

### 2.3 Option 3: add `fact_ref` to `BPF_PROG_JIT_RECOMPILE`

Mechanism:

- the recompile syscall carries a cookie/reference to a specific verifier-summary snapshot
- policies can bind to that snapshot

Pros:

- fail-closed against stale fact-backed policies
- clean binder if option 2 ever exists

Cons:

- not useful by itself
- only makes sense on top of option 2 or another kernel-owned fact table

Best use:

- optional future binder on top of option 2
- not part of the required v6 baseline

### 2.4 Recommendation

Recommended staged answer:

1. Use option 1 now, including in production, for discovery and policy ranking.
2. Keep the baseline re-JIT legality boundary syntactic:
   - site naming
   - pattern match
   - constraints
   - overlap policy
   - kernel-owned emitter validation
3. Treat option 2 and option 3 as future optimizations only.
4. Do not block `BRANCH_FLIP`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, `DIV_LIVENESS`, or `PROLOGUE_TRIM` on verifier changes.

---

## 3. v6 UAPI Proposal

### 3.1 Friction fixes first

Before adding any new semantics, v6 should remove current v5 friction:

- delete the hard-coded shape whitelist in `vendor/linux-framework/kernel/bpf/jit_directives.c`
- keep the existing `BPF_PROG_JIT_RECOMPILE` log channel and add `log_true_size`
- make overlap semantics explicit at policy-parse time

This tree already contains most of the `jit_recompile` log plumbing in `vendor/linux-framework/kernel/bpf/jit_directives.c`; the remaining gap is mainly parity with `BPF_PROG_LOAD` style truncation reporting.

### 3.2 Proposed policy v3 header and site model

```c
#define BPF_JIT_POLICY_VERSION_3 3

enum bpf_jit_site_kind {
	BPF_JIT_SITE_INSN_REGION = 0,
	BPF_JIT_SITE_FUNC_ENTRY  = 1,
	BPF_JIT_SITE_FUNC_EXIT   = 2,
};

enum bpf_jit_overlap_policy {
	BPF_JIT_OVERLAP_REJECT   = 0,
	BPF_JIT_OVERLAP_PRIORITY = 1,
};

struct bpf_jit_policy_hdr_v3 {
	__u32 magic;
	__u16 version;
	__u16 hdr_len;
	__u32 total_len;
	__u32 rule_cnt;
	__u32 insn_cnt;
	__u8  prog_tag[8];
	__u16 arch_id;
	__u16 flags;
	__u16 overlap_policy;
	__u16 reserved0;
};

struct bpf_jit_site_desc {
	__u32 site_start;   /* absolute xlated insn idx for INSN_REGION */
	__u16 site_len;     /* >0 only for INSN_REGION */
	__u8  site_kind;    /* enum bpf_jit_site_kind */
	__u8  subprog_idx;  /* used by FUNC_ENTRY / FUNC_EXIT */
};
```

Design notes:

- `INSN_REGION` preserves current semantics.
- `FUNC_ENTRY` and `FUNC_EXIT` solve the current inability to name prologue/epilogue sites at all.
- `subprog_idx` makes entry/exit sites explicit without needing pseudo-insn indices.

### 3.3 Primary v6 pattern rule

The primary v6 rule should still be a pattern rule. That is the right abstraction for the next wave of canonical forms.

```c
enum bpf_jit_rule_kind {
	BPF_JIT_RK_PATTERN = 6,
};

struct bpf_jit_rewrite_rule_v3 {
	struct bpf_jit_site_desc site;
	__u32 cpu_features_required;
	__u16 rule_kind;         /* BPF_JIT_RK_PATTERN */
	__u16 canonical_form;
	__u16 native_choice;
	__u16 priority;
	__u16 conflict_group;    /* 0 = no deliberate overlap */
	__u16 pattern_count;
	__u16 constraint_count;
	__u16 binding_count;
	__u16 rule_len;
	__u16 reserved;
	/* followed by:
	 *   struct bpf_jit_pattern_insn pattern[pattern_count];
	 *   struct bpf_jit_pattern_constraint constraint[constraint_count];
	 *   struct bpf_jit_binding binding[binding_count];
	 */
};
```

Semantics:

- the baseline rule remains purely syntactic
- userspace may use verifier-log facts to decide when to emit the rule
- kernel safety still depends only on the matched BPF region and the emitter's own legality checks

### 3.4 Optional future fact-backed extension

If a later phase proves that a kernel-owned fact ABI is worth the cost, the cleanest extension is still a tail-appended fact reference array:

```c
struct bpf_jit_fact_ref {
	__u32 fact_id;
	__u16 expected_kind;
	__u16 flags;
};
```

That should stay future-only until phase-0 log parsing proves that the extra kernel complexity is justified.

### 3.5 Optional future exported verifier summary

If a structured fact ABI is later added, `BPF_OBJ_GET_INFO_BY_FD` remains the most natural place for it, keyed to the loaded program in the same style as `func_info` or `line_info`.

A future summary should be treated as:

- an optional tooling and binding optimization
- not a prerequisite for the baseline v6 interface
- not a replacement for kernel-side pattern validation

### 3.6 `BPF_PROG_JIT_RECOMPILE` attr extension

Baseline v6 only needs the log channel to reach parity with `BPF_PROG_LOAD`:

```c
struct { /* BPF_PROG_JIT_RECOMPILE */
	__u32         prog_fd;
	__s32         policy_fd;
	__u32         flags;
	__u32         log_level;
	__u32         log_size;
	__aligned_u64 log_buf;
	__u32         log_true_size;
	__u32         reserved0;
	/* optional future:
	 * __u64      fact_ref;
	 */
} jit_recompile;
```

Semantics:

- `log_*` mirrors `BPF_PROG_LOAD`
- `log_true_size` lets userspace detect truncation cleanly
- `fact_ref` is future-only, if a kernel-owned fact channel is ever added

### 3.7 Explicit overlap semantics

Recommended rules:

- overlap handling happens during policy parse/activation, not at lookup time
- after arbitration, the active set must be non-overlapping
- lookup can then stay simple and O(log n)

Policy:

- `BPF_JIT_OVERLAP_REJECT`:
  - any active interval overlap is `-EINVAL`
- `BPF_JIT_OVERLAP_PRIORITY`:
  - overlap is allowed only when all overlapping rules share the same non-zero `conflict_group`
  - higher `priority` wins
  - tie is `-EINVAL`
  - losers are marked inactive with a `shadowed` reject reason in the recompile log

### 3.8 Remove the shape whitelist

Recommended change:

- delete `bpf_jit_pattern_rule_shape_valid()`
- delete its call sites in parse-time and validate-time paths

The real checks should be:

- exact pattern match
- constraint validation
- site-kind validation
- canonical-param validation
- emitter-specific legality

If those pass, a fixed site-length whitelist is just friction.

---

## 4. `FUNC_ENTRY` / `FUNC_EXIT`

Current problem:

- the x86 prologue/epilogue is emitted outside the per-insn dispatch path
- current UAPI cannot name those sites at all

Relevant code:

- prologue: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- per-insn dispatch: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- shared exit / epilogue: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Recommended semantics:

- `BPF_JIT_SITE_FUNC_ENTRY`:
  - site is `(subprog_idx, entry)`
  - rule is consulted before `emit_prologue()`
- `BPF_JIT_SITE_FUNC_EXIT`:
  - site is `(subprog_idx, exit)`
  - rule is consulted when emitting shared cleanup / return sequence

Why this belongs in v6:

- it solves the concrete `PROLOGUE_TRIM` / `EPILOGUE_TRIM` gap
- it is an engineering limitation in the current interface, not a verifier limitation
- it does not require a general label-preserving CFG interface

---

## 5. New Canonical Forms Implementable via Pure Pattern Match

### 5.1 Where the canonical-form bottleneck really is

Canonical form means:

- many BPF spellings
- one semantics
- one kernel-owned native emitter family

v5 already moved the many-to-one reduction to userspace:

- userspace matches the local BPF shape
- userspace binds a small semantic tuple
- kernel validates the region and dispatches to a kernel-owned emitter

The real bottleneck is now on the emit side:

- every new canonical form still needs a new kernel validator/emitter pair
- but many useful forms do not need verifier facts and do not need a new safety model

So the right question is not "what needs a new fact ABI?" It is:

> which additional canonical forms can be proven correct by local pattern preservation alone?

For the next tier, the answer includes `BRANCH_FLIP`, `ZERO_EXT_ELIDE`, and `ENDIAN_FUSION`, with `DIV_LIVENESS` as the first information-sensitive but still local extension.

### 5.2 `BRANCH_FLIP`

Shape:

- local if/else diamond:
  - `{ jcc target, body_A, ja join, body_B, join: }`

Mechanism:

- match a contiguous single-entry/single-exit local diamond, in the same validation style as the current local `COND_SELECT` path in `vendor/linux-framework/kernel/bpf/jit_directives.c`
- emit the inverted condition
- swap the fallthrough and taken bodies

Why this is safe by pure pattern match:

- both bodies are preserved
- only branch polarity and linearized order change
- the region still has the same entry and same join
- the same outside-edge exclusion used for local diamonds is enough

Why this is policy-sensitive:

- which body should come first depends on workload hotness and branch predictability
- that decision belongs in userspace

Why this does not need verifier facts or template plans:

- the kernel only needs to prove it matched the local diamond correctly
- userspace only needs workload policy to choose body order

Estimated x86 emitter work:

- roughly 80-120 LOC for the emitter itself

### 5.3 `ZERO_EXT_ELIDE`

Shape:

- local pair such as `{ alu32 dst; zext dst }`
- in practice, the trailing zero-extension often comes from verifier patching in `opt_subreg_zext_lo32_rnd_hi32()` in `vendor/linux-framework/kernel/bpf/verifier.c`

Mechanism:

- match a 32-bit defining op on `dst`
- match the immediately following zero-extension of the same `dst`
- emit only the 32-bit op on x86

Why this is safe by pure pattern match:

- x86 32-bit ALU writes already zero-extend the upper 32 bits
- if the first instruction is a 32-bit def on the same destination, the explicit zero-extension is redundant
- no non-local reasoning is required

Why this is a canonical form problem, not a verifier problem:

- the verifier already knows about zero-extension
- the current gap is only that the kernel lacks a dedicated emitter family for the redundant pair

Estimated x86 emitter work:

- roughly 40-60 LOC

### 5.4 `ENDIAN_FUSION`

Shape:

- local load plus endian-convert sequence:
  - `{ ldxh/ldxw/ldxdw; bswap/endian-convert }`

Mechanism:

- match a contiguous load followed by byte-swap
- on x86, emit `movbe` when the width is 16/32/64 and CPU feature gating allows it

Why this is safe by pure pattern match:

- the transform preserves both the memory access and the byte order conversion
- the load and swap stay adjacent and local
- the kernel still owns the exact native sequence

Important caveat:

- `movbe` is only meaningful for widths that x86 actually supports; 8-bit loads are not part of this useful subset

Why this is an emitter gap, not a verifier gap:

- current x86 code already lowers this semantics as `emit_ldx()` plus `emit_bswap_width()` in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `movbe` is just another kernel-owned emission choice for the same local semantics

Estimated x86 emitter work:

- roughly 60-80 LOC

### 5.5 `DIV_LIVENESS`

Shape:

- local div/mod site where the architectural scratch/result constraints make `rdx` save/restore conditional

Mechanism:

- userspace discovers candidate sites using verifier-log liveness
- kernel validates the same condition from existing liveness data and chooses the cheaper emitter variant when `rdx` is absent from the fallthrough successor's `live_regs_before`

Why this is not a verifier-change requirement:

- userspace can already recover `live_regs_before` from verifier log
- the verifier already computes `insn_aux_data[].live_regs_before`
- the current x86 div/mod path in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` already makes the save/restore of `rdx` explicit

Limit class:

- this is an information limitation for userspace ranking, not a new kernel safety model

Estimated x86 emitter work:

- roughly 80-100 LOC

---

## 6. CAN / CANNOT

The key distinction is:

- engineering limitation:
  - missing canonical form, missing site kind, or missing emitter plumbing
- information limitation:
  - userspace needs more facts to rank sites, but verifier log already provides enough
- safety limitation:
  - local pattern preservation is not enough to prove the transform correct
- structural limitation:
  - current architecture has no model for the required region shape

| Directive family | What userspace needs for discovery | What kernel must prove | Real limit class | Status |
| --- | --- | --- | --- | --- |
| More patterns inside existing canonical forms | Pattern matching only | Existing validation/emitter path | None | `CAN` |
| `BRANCH_FLIP` for a local single-entry/single-exit diamond | Workload hotness / branch policy | Local diamond match, same join, no interior outside edge | Engineering limitation only | `CAN` |
| `ZERO_EXT_ELIDE` | Pattern matching only | Same-dst def32 followed by redundant zext | Engineering limitation only | `CAN` |
| `ENDIAN_FUSION` | Pattern matching only plus CPU feature policy | Adjacent load plus endian-convert of supported width | Engineering limitation only | `CAN` |
| `DIV_LIVENESS` | Liveness info from verifier log | Existing `insn_aux_data` liveness check plus local emitter legality | Information limitation only | `CAN` |
| `PROLOGUE_TRIM` / `EPILOGUE_TRIM` | Policy only | Site-kind match at function entry/exit | Engineering limitation only | `CAN` |
| `BOUNDS_ELIDE` | Bounds and dominance facts | That removing a check still preserves all verifier-proved safety conditions | Safety limitation | `CANNOT` |
| General `DEAD_STORE_ELIM` | Memory-side-effect facts | Alias, overwrite, and liveness reasoning beyond local shape | Safety limitation | `CANNOT` |
| General `branch_reorder` over arbitrary CFG regions | CFG hotness and layout policy | Label-preserving multi-block layout rewrite | Structural limitation | `CANNOT` |
| `SUBPROG_INLINE` | Call hotness and size budget | Cross-subprog frame/control-flow rewrite | Structural limitation | `CANNOT` |
| Non-contiguous pattern families | Region-level analysis | Matching and re-emitting disjoint spans | Structural limitation | `CANNOT` |

The previous v6 draft was too pessimistic about several rows:

- `BRANCH_FLIP` is not a safety blocker; it is a missing canonical form
- `ZERO_EXT_ELIDE` and `ENDIAN_FUSION` are the same category
- `DIV_LIVENESS` is not blocked on verifier export; it is blocked only on surfacing existing liveness to userspace policy, which the verifier log already does

---

## 7. Comparison With Existing Work

| System | Boundary shape | Similarity to BpfReJIT | Important difference | Lesson for v6 |
| --- | --- | --- | --- | --- |
| JVMCI / Graal | VM exposes metadata/profile information to an external compiler; VM installs compiled code | Strong example of a structured optimization interface with a runtime install barrier | External compiler owns machine-code generation; BpfReJIT should not cross that line | Use a structured fact/control interface, but keep emission kernel-owned |
| .NET Dynamic PGO / ReadyToRun | Runtime and ahead-of-time artifacts guide which runtime-owned code path is used | Good precedent for fact/profile-guided policy choices | Policy and emission remain runtime-internal; not an external policy plane | Facts should guide choices, but the runtime/kernel still owns legality and emission |
| GCC / LLVM plugin interfaces | Compiler exposes pass-manager/plugin hooks and reusable analyses | Good precedent for explicit extension points instead of hard-coded heuristics | In-process compiler plugins can arbitrarily transform IR/code; no kernel safety boundary | Expose structured hooks and facts, not ad hoc knobs |
| `perf_event_open` | Kernel exports structured measurement data to userspace via a normal Linux interface | Strong precedent for "kernel data -> userspace analysis/policy" | `perf_event_open` exports data, not rewrite legality | A future verifier-summary export would be natural Linux API design |
| eBPF verifier log | Kernel already exports analysis results to userspace | Immediate precedent for a zero-kernel-change fact channel | Textual and unstable as a formal ABI | Strong production path for discovery, but not the kernel legality contract |

External references:

- JVMCI / JEP 243: https://openjdk.org/jeps/243
- .NET runtime compilation config: https://learn.microsoft.com/en-us/dotnet/core/runtime-config/compilation
- .NET ReadyToRun: https://learn.microsoft.com/en-us/dotnet/core/deploying/ready-to-run
- GCC plugins: https://gcc.gnu.org/onlinedocs/gccint/Plugins.html
- LLVM new-pass-manager plugins: https://llvm.org/docs/WritingAnLLVMNewPMPass.html
- `perf_event_open(2)`: https://man7.org/linux/man-pages/man2/perf_event_open.2.html

---

## 8. Kernel LOC Estimates

These are rough incremental estimates for this tree, excluding tests/docs and any vendored UAPI sync work.

Primary-path estimates:

| Improvement | Estimated kernel LOC | Notes |
| --- | --- | --- |
| Remove shape whitelist | 20-40 | Delete helper plus parse/validate call sites |
| Finish `jit_recompile` log parity (`log_true_size`) | 20-50 | The basic log channel already exists in this tree |
| Explicit overlap semantics | 80-140 | Parse-time arbitration and logging |
| `FUNC_ENTRY` / `FUNC_EXIT` site kinds | 180-325 | Common plus x86 dispatch hooks |
| `BRANCH_FLIP` canonical form | 120-180 | Roughly 80-120 LOC x86 emitter plus common validation/dispatch |
| `ZERO_EXT_ELIDE` canonical form | 60-90 | Roughly 40-60 LOC x86 emitter plus small common plumbing |
| `ENDIAN_FUSION` canonical form | 80-120 | Roughly 60-80 LOC x86 emitter plus CPU-gating plumbing |
| `DIV_LIVENESS` canonical form | 100-150 | Reuses existing liveness data |

Not counted in the baseline path:

- verifier-summary export
- `fact_ref` binding

Those are optional future optimizations, not required v6 cost.

---

## 9. Recommended Implementation Order

### Phase 0: parse verifier log in userspace

1. Parse existing verifier logs in userspace.
2. Use that to drive discovery, ranking, and workload-sensitive policy.
3. Treat this as the baseline fact path.

This is the zero-kernel-change plan.

### Phase 1: remove current v5 friction

1. Remove shape whitelist.
2. Finish `jit_recompile` log parity and truncation reporting.
3. Make overlap semantics explicit.

Status:

- this phase is already in implementation in the current tree

### Phase 2: add new canonical forms that need only pattern matching

1. `BRANCH_FLIP`
2. `ZERO_EXT_ELIDE`
3. `ENDIAN_FUSION`

`DIV_LIVENESS` should follow immediately after or alongside this phase:

- it needs better userspace ranking input
- but that input already exists in verifier log
- it does not require verifier export

### Phase 3: make entry/exit sites first-class

1. Add `FUNC_ENTRY`.
2. Add `FUNC_EXIT`.
3. Use them for `PROLOGUE_TRIM` / `EPILOGUE_TRIM`.

### Phase 4: optional verifier-fact export

Only do this if phase 0 proves that a kernel-owned fact ABI is worth the complexity cost.

If it lands, treat it as:

- a tooling optimization
- an optional stale-policy binder
- not the dependency that unlocks the main v6 optimizations

---

## 10. Bottom Line

The corrected v6 picture is:

- verifier log already exposes the information userspace needs for discovery
- baseline v6 therefore needs zero verifier changes
- kernel safety still comes from pattern match, constraints, site kinds, and kernel-owned emitters
- several things previously labeled "cannot" are actually engineering gaps:
  - `BRANCH_FLIP`
  - `ZERO_EXT_ELIDE`
  - `ENDIAN_FUSION`
  - `PROLOGUE_TRIM`
- `DIV_LIVENESS` is an information problem for userspace ranking, but verifier log already covers it
- the real safety blockers are transforms like `BOUNDS_ELIDE` and general `DEAD_STORE_ELIM`
- the real structural blockers are transforms like `SUBPROG_INLINE`, non-contiguous rewrites, and arbitrary CFG relayout

So the main v6 bottleneck is not "missing verifier facts." It is that the emit side is still locked to too few kernel-owned canonical forms.

That preserves the core BpfReJIT novelty:

> userspace decides policy, kernel proves safety, kernel emits native code

without inventing verifier changes that the current design does not actually need.
