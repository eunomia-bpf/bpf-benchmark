# BpfReJIT v6 Interface Design

Date: 2026-03-11

## 0. Framing

BpfReJIT v6 should strengthen the same core boundary, not change it:

- kernel owns safety, validation, and native emission
- userspace owns pattern discovery, cost model, and policy
- kernel never executes userspace-supplied machine code

The right v6 question is therefore not "how do we inject more code from userspace?", but:

> how do we let userspace make richer optimization decisions while keeping legality and emission kernel-owned?

The main answer is a stronger fact channel plus a richer site model.

---

## 1. What Verifier Log Already Exposes

### 1.1 Acquisition path

Today userspace can already ask the verifier to emit a textual trace through `BPF_PROG_LOAD.log_level/log_size/log_buf/log_true_size`; the shared logging machinery is in `vendor/linux-framework/kernel/bpf/log.c`, and the log-level bits are defined in `vendor/linux-framework/include/linux/bpf_verifier.h:623-629`.

Operationally, if userspace wants to mine facts from the log, it should use:

- `BPF_LOG_LEVEL2` when possible, because plain `LEVEL1` misses SCC/liveness and many full-state dumps
- `BPF_LOG_FIXED`, so the buffer behaves like the verifier log path rather than a rotating ring
- `log_true_size`, so truncation is detectable

Relevant code:

- `vendor/linux-framework/include/linux/bpf_verifier.h:623-629`
- `vendor/linux-framework/include/uapi/linux/bpf.h:1794-1821`
- `vendor/linux-framework/kernel/bpf/log.c:13-38`
- `vendor/linux-framework/kernel/bpf/log.c:226-257`
- `vendor/linux-framework/kernel/bpf/verifier.c:26116-26122`

### 1.2 Fact classes visible in the log today

| Fact class | Log format today | Code references | Immediate value to userspace | Main caveat |
| --- | --- | --- | --- | --- |
| Register type and modifiers | `R6=pkt(...)`, `R1=trusted_ptr_foo(...)`, `R2=scalar(...)` | `vendor/linux-framework/kernel/bpf/log.c:440-492`, `vendor/linux-framework/kernel/bpf/log.c:673-747` | Pointer class, nullability, trusted/untrusted, mem/packet/BTF distinctions | Textual, not a stable ABI |
| Scalar bounds and tnum | `smin/smax/umin/umax/smin32/...`, `var_off=(value; mask)` | `vendor/linux-framework/kernel/bpf/log.c:591-645`, `vendor/linux-framework/kernel/bpf/log.c:724-742` | Enough to recover min/max windows and bit-level uncertainty | Omitted defaults and coalesced equal 32/64-bit bounds mean parser must normalize |
| Pointer provenance | `id=`, `ref_obj_id=`, `off=`, `imm=`, `r=`, `sz=`, BTF type names, map key/value sizes | `vendor/linux-framework/include/linux/bpf_verifier.h:37-210`, `vendor/linux-framework/kernel/bpf/log.c:697-742` | Correlates same-provenance pointers across a region; distinguishes map/pkt/mem/BTF access windows | Some pointer types are underprinted (`PTR_TO_STACK`, `PTR_TO_ARENA`) |
| Stack slot state | `fp-8=...`, spill state, `dynptr_*`, `iter_*` | `vendor/linux-framework/include/linux/bpf_verifier.h:213-240`, `vendor/linux-framework/kernel/bpf/log.c:538-547`, `vendor/linux-framework/kernel/bpf/log.c:770-825` | Spilled reg facts, zero/misc/invalid bytes, dynptr/iter presence, stack occupancy | `STACK_IRQ_FLAG` only prints as `f`; no class/ref details |
| Ref-set summary | `refs=...` | `vendor/linux-framework/kernel/bpf/log.c:826-833` | Tells userspace whether ref-tracked objects are live | No ref type or allocation-site detail |
| Branch / path trace | `from A to B:`, `safe`, caller/callee transitions, `cur state:` / `old state:` | `vendor/linux-framework/kernel/bpf/verifier.c:10936-10940`, `vendor/linux-framework/kernel/bpf/verifier.c:11275-11279`, `vendor/linux-framework/kernel/bpf/verifier.c:20567-20572`, `vendor/linux-framework/kernel/bpf/verifier.c:21237-21273` | Userspace can reconstruct visited states and some branch outcomes | No explicit stable edge IDs or dominance tree |
| SCC and loop context | `SCC enter`, `SCC exit`, `SCC backedge` | `vendor/linux-framework/kernel/bpf/verifier.c:1907-1920`, `vendor/linux-framework/kernel/bpf/verifier.c:1941`, `vendor/linux-framework/kernel/bpf/verifier.c:1983`, `vendor/linux-framework/kernel/bpf/verifier.c:2013` | Lets userspace know when a site is in a loop/SCC | `LEVEL2` only |
| Live register pressure | `Live regs before insn:` bitmap | `vendor/linux-framework/include/linux/bpf_verifier.h:595-597`, `vendor/linux-framework/kernel/bpf/verifier.c:25701-25717` | Useful for code-size / register-pressure heuristics | Registers only; no stack live-in/live-out |
| CFG rejection / dead markers | `unreachable insn N`, `back-edge from insn A to B`, `infinite loop detected` | `vendor/linux-framework/kernel/bpf/verifier.c:18249`, `vendor/linux-framework/kernel/bpf/verifier.c:18978-18989`, `vendor/linux-framework/kernel/bpf/verifier.c:20567-20572` | Userspace can detect rejected dead/unreachable shapes | Runtime-dead code is not exported as a structured fact |
| Source correlation | source line text + `@ file:line` | `vendor/linux-framework/kernel/bpf/log.c:381-433` | Handy for tooling and policy debugging | Line-only, no columns; duplicates suppressed |

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
  - SCC membership and live-reg-before sets at `LEVEL2`

### 1.4 What the log is not

The current verifier log is useful, but it is not a production fact ABI.

Important limits:

- It is free-form text, not a stable machine-readable UAPI.
- It is path-sensitive and often delta-only:
  - ordinary per-insn logs print only scratched regs/slots
  - full-state dumps happen only at selected transition sites
- One BPF instruction can appear with multiple verifier states.
- It does not export a stable per-edge or per-state identifier.
- Some real verifier facts are not printed at all:
  - `STACK_IRQ_FLAG` class details
  - ref type / allocation insn
  - stack liveness
  - "after" liveness
  - a retained `seen` bitmap for runtime-dead code

Relevant code:

- `vendor/linux-framework/kernel/bpf/log.c:749-852`
- `vendor/linux-framework/kernel/bpf/log.c:854-865`
- `vendor/linux-framework/kernel/bpf/verifier.c:21268-21283`
- `vendor/linux-framework/kernel/bpf/verifier.c:22257-22310`

### 1.5 Optimization assessment

These logs are already enough for:

- better userspace site discovery for existing v5 families
- fact-gated local peepholes over contiguous regions
- cost-model heuristics that avoid expansion in loops or under high live-reg pressure
- prototyping `bounds_window`-style candidates offline

They are not enough, by themselves, for a production legality boundary for:

- fact-backed check removal
- general `branch_reorder`
- `subprog_inline`
- general `dead_store_elim`

The reason is structural: the log gives a rich trace, but not a stable kernel-owned summary that `BPF_PROG_JIT_RECOMPILE` can re-bind against.

---

## 2. Fact Channel Options

### 2.1 Option 1: userspace parses verifier log

Mechanism:

- userspace requests `BPF_PROG_LOAD` verifier log
- parses textual register/stack/CFG facts
- constructs a richer rule or policy from those facts

Pros:

- zero new verifier semantics
- richest information immediately available
- path-sensitive trace can be richer than any first summary export

Cons:

- text ABI is brittle
- truncation / log-level dependence is awkward
- the kernel cannot treat parsed log text as a stable legality proof
- poor fit for long-term fail-closed re-JIT

Best use:

- immediate research
- userspace-only prototype
- discovery and ranking, not final safety binding

### 2.2 Option 2: export a verifier summary through `BPF_OBJ_GET_INFO_BY_FD`

Mechanism:

- extend `struct bpf_prog_info` with an optional verifier-fact array
- expose a kernel-owned summary keyed to the loaded program

Recommended semantic choice:

- export only path-invariant facts
- if the verifier saw conflicting states for the same `(insn, reg/slot)`, omit the fact rather than export an unsound union

Pros:

- stable machine-readable ABI
- kernel-owned facts, so re-JIT can trust them
- natural fit for tooling: query once, build policy, recompile
- good precedent in existing Linux APIs

Cons:

- needs some retained summary state
- loses some path-sensitive richness relative to raw logs

Best use:

- production v6 fact channel

### 2.3 Option 3: add `fact_ref` to `BPF_PROG_JIT_RECOMPILE`

Mechanism:

- the recompile syscall carries a cookie/reference to a specific verifier-summary snapshot
- the policy blob carries per-rule `fact_id` references

Pros:

- fail-closed against stale policies
- keeps `BPF_PROG_JIT_RECOMPILE` self-contained
- cleanly separates "query facts" from "recompile against those facts"

Cons:

- not useful by itself
- must sit on top of option 2, or at least some kernel-owned fact table

Best use:

- binder on top of option 2, not a standalone fact channel

### 2.4 Recommendation

Recommended staged answer:

1. Use option 1 immediately for research and policy prototyping.
2. Implement option 2 as the real v6 fact channel.
3. Add option 3 so the recompile path can reject stale fact-backed policies.

This keeps verifier changes minimal:

- first prove which fact kinds are actually useful
- then export only those facts, in a stable summary
- avoid turning the verifier log itself into the long-term ABI

---

## 3. v6 UAPI Proposal

### 3.1 Friction fixes first

Before adding new semantics, v6 should remove current v5 friction:

- delete the hard-coded shape whitelist in `vendor/linux-framework/kernel/bpf/jit_directives.c:214-233`
- add `log_level/log_size/log_buf/log_true_size` to `BPF_PROG_JIT_RECOMPILE`
- make overlap semantics explicit at policy-parse time

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

Current motivation:

- rules today are keyed only by `site_start/site_len`
- lookup happens only from the per-insn JIT loop
- prologue emission lives outside that loop

Relevant code:

- `vendor/linux-framework/include/uapi/linux/bpf.h:1640-1650`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:55-78`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:169-233`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2075-2108`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:510-565`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3401-3456`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4398-4424`

### 3.3 Fact-backed pattern rule

```c
enum bpf_jit_rule_kind {
	BPF_JIT_RK_PATTERN  = 6,
	BPF_JIT_RK_TEMPLATE = 7,
};

struct bpf_jit_fact_ref {
	__u32 fact_id;        /* from bpf_prog_info verifier-fact table */
	__u16 expected_kind;  /* enum bpf_prog_verifier_fact_kind */
	__u16 flags;
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
	__u16 fact_count;
	__u16 rule_len;
	__u16 reserved;
	/* followed by:
	 *   struct bpf_jit_pattern_insn pattern[pattern_count];
	 *   struct bpf_jit_pattern_constraint constraint[constraint_count];
	 *   struct bpf_jit_binding binding[binding_count];
	 *   struct bpf_jit_fact_ref fact[fact_count];
	 */
};
```

Semantics:

- `fact_count == 0` means current v5-style syntactic rule
- `fact_count > 0` means the kernel must also validate referenced verifier facts before activating the rule
- facts are conjunctive
- missing or stale facts fail closed

### 3.4 Exported verifier summary

Recommended `bpf_prog_info` tail extension:

```c
enum bpf_prog_verifier_fact_kind {
	BPF_PROG_FACT_REG_TYPE   = 1,
	BPF_PROG_FACT_REG_BOUNDS = 2,
	BPF_PROG_FACT_STACK_SLOT = 3,
	BPF_PROG_FACT_BRANCH     = 4,
	BPF_PROG_FACT_INSN_AUX   = 5,
};

enum bpf_prog_verifier_fact_flags {
	BPF_PROG_FACT_PATH_INVARIANT = (1U << 0),
	BPF_PROG_FACT_ALWAYS_TRUE    = (1U << 1),
	BPF_PROG_FACT_ALWAYS_FALSE   = (1U << 2),
};

struct bpf_prog_verifier_fact {
	__u32 fact_id;
	__u32 insn_idx;
	__u16 kind;
	__u8  subject; /* regno for REG_*, stack slot for STACK_SLOT, 0xff otherwise */
	__u8  flags;
	union {
		struct {
			__u32 reg_type;
			__u32 id;
			__u32 ref_obj_id;
			__s32 off;
			__u64 aux; /* btf_id, pkt range, or mem_size depending on reg_type */
		} reg_type;
		struct {
			__s64 smin_value;
			__s64 smax_value;
			__u64 umin_value;
			__u64 umax_value;
			__s32 s32_min_value;
			__s32 s32_max_value;
			__u32 u32_min_value;
			__u32 u32_max_value;
			__u64 tnum_value;
			__u64 tnum_mask;
		} reg_bounds;
		struct {
			__u32 slot_kind_mask;
			__u32 spilled_reg_type;
			__u32 spilled_ref_obj_id;
			__u32 reserved;
		} stack_slot;
		struct {
			__u32 branch_target;
			__u32 fallthrough_target;
			__u32 reserved0;
			__u32 reserved1;
		} branch;
		struct {
			__u32 live_regs_before;
			__u32 scc_id;
			__u32 prune_point;
			__u32 seen;
		} insn_aux;
	};
};

/* tail extension to struct bpf_prog_info */
__u64 verifier_fact_cookie;
__u32 nr_verifier_facts;
__u32 verifier_fact_rec_size;
__aligned_u64 verifier_facts;
```

Why this shape:

- mirrors existing `func_info` / `line_info` query style
- keeps facts attached to the loaded program
- supports a compact path-invariant summary without inventing a new fd type
- `BPF_PROG_FACT_BRANCH` should be emitted only when the verifier proved a direction or target relation invariant across all reachable states for that instruction

### 3.5 `BPF_PROG_JIT_RECOMPILE` attr extension

```c
struct { /* BPF_PROG_JIT_RECOMPILE */
	__u32        prog_fd;
	__s32        policy_fd;
	__u32        flags;
	__u32        log_level;
	__u32        log_size;
	__aligned_u64 log_buf;
	__u32        log_true_size;
	__u32        reserved0;
	__u64        fact_ref; /* must match bpf_prog_info.verifier_fact_cookie */
} jit_recompile;
```

Semantics:

- `log_*` mirrors `BPF_PROG_LOAD` / `BPF_BTF_LOAD`
- `fact_ref == 0` means no fact binding
- `fact_ref != 0` means:
  - the policy may carry `fact_ref[]`
  - the kernel rejects the recompile if the cookie does not match the current program summary

### 3.6 Explicit overlap semantics

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

This is stricter and cleaner than current behavior, where rules are sorted by `(site_start, -priority)` but interval overlap is not a first-class kernel semantic.

### 3.7 Remove the shape whitelist

Recommended change:

- delete `bpf_jit_pattern_rule_shape_valid()`
- delete its call sites in parse-time and validate-time paths

The real checks should be:

- exact pattern match
- constraint validation
- canonical-param validation
- fact validation, when present
- emitter/template-specific legality

If those pass, a fixed site-length whitelist is just friction.

---

## 4. `FUNC_ENTRY` / `FUNC_EXIT`

Current problem:

- the x86 prologue/epilogue is emitted outside the per-insn dispatch path
- current UAPI cannot name those sites at all

Relevant code:

- prologue: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:510-565`
- per-insn dispatch: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3401-3456`
- shared exit / epilogue: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4398-4424`

Recommended semantics:

- `BPF_JIT_SITE_FUNC_ENTRY`:
  - site is `(subprog_idx, entry)`
  - rule is consulted before `emit_prologue()`
- `BPF_JIT_SITE_FUNC_EXIT`:
  - site is `(subprog_idx, exit)`
  - rule is consulted when emitting shared cleanup / return sequence

Why only these two first:

- they solve the concrete prologue/epilogue gap
- they do not require a general label-preserving CFG interface
- they let userspace express `prologue_trim` / `epilogue_trim` without touching verifier semantics

---

## 5. Restricted Template Plan

### 5.1 Safety boundary

The template tier is useful only if it stays narrow.

Safe and useful userspace control:

- choose a kernel-defined `template_id`
- supply a small arg list of regs/immediates/enums
- bind the template to verifier facts through `fact_ref[]`
- choose among kernel-owned local layout variants

Out of scope:

- raw native bytes
- arbitrary branches or labels
- arbitrary stack pointer arithmetic
- arbitrary helper/kfunc call injection
- arbitrary composition of native opcodes

### 5.2 UAPI shape

```c
enum bpf_jit_template_arg_kind {
	BPF_JIT_TARG_REG  = 0,
	BPF_JIT_TARG_IMM  = 1,
	BPF_JIT_TARG_ENUM = 2,
};

struct bpf_jit_template_arg {
	__u8  kind;
	__u8  index;
	__u16 reserved;
	__s32 value;
};

struct bpf_jit_template_rule_v1 {
	struct bpf_jit_site_desc site;
	__u32 cpu_features_required;
	__u16 rule_kind;       /* BPF_JIT_RK_TEMPLATE */
	__u16 template_id;
	__u16 priority;
	__u16 conflict_group;
	__u16 arg_count;
	__u16 fact_count;
	__u16 rule_len;
	__u16 reserved;
	/* followed by:
	 *   struct bpf_jit_template_arg arg[arg_count];
	 *   struct bpf_jit_fact_ref fact[fact_count];
	 */
};
```

### 5.3 First useful templates

Reasonable first templates:

- `WIDE_LOAD_PLAN`
  - userspace chooses chunking / order from a kernel-defined menu
- `LOCAL_BRANCH_LAYOUT`
  - only for tiny single-entry/single-exit local regions
- `FUNC_ENTRY_PLAN`
  - prologue/entry variant menu
- `FUNC_EXIT_PLAN`
  - epilogue/cleanup variant menu

This gives userspace more control than current fixed canonical emitters, without crossing into native-code injection.

---

## 6. CAN / CANNOT

| Directive family | With current verifier log only | With full v6 (`fact` summary + `fact_ref` + `site_kind` + templates where needed) | Status |
| --- | --- | --- | --- |
| More `cmov_select` / `rotate` / `wide_mem` / `addr_calc` patterns inside existing canonical forms | Yes | Yes | `CAN` |
| More `bitfield_extract` patterns | Yes | Yes | `CAN` |
| `packet_ctx_wide_load` that depends on pointer type / access window facts | Prototype only | Yes | `CAN` |
| Local `bounds_window` where an earlier dominating check proves a later load window | Prototype only; not a sound kernel contract | Yes, if rules reference kernel-owned verifier facts | `CAN` |
| `prologue_trim` / `epilogue_trim` | No | Yes, via `FUNC_ENTRY` / `FUNC_EXIT` | `CAN` |
| Tiny local branch-layout choice inside one validated region | No | Partially, via restricted template plans | `PARTIAL` |
| General `branch_reorder` over arbitrary CFG regions | No | No | `CANNOT` |
| `subprog_inline` | No | No | `CANNOT` |
| General `dead_store_elim` | No | No | `CANNOT` |
| Raw native code injection | Never | Never | `CANNOT` |

Key point:

- v6 should unlock fact-backed local and entry/exit decisions
- it should not pretend to be a general CFG rewrite or external code-install interface

---

## 7. Comparison With Existing Work

| System | Boundary shape | Similarity to BpfReJIT | Important difference | Lesson for v6 |
| --- | --- | --- | --- | --- |
| JVMCI / Graal | VM exposes metadata/profile information to an external compiler; VM installs compiled code | Strong example of a structured optimization interface with a runtime install barrier | External compiler owns machine-code generation; BpfReJIT should not cross that line | Use a structured fact/control interface, but keep emission kernel-owned |
| .NET Dynamic PGO / ReadyToRun | Runtime and ahead-of-time artifacts guide which runtime-owned code path is used | Good precedent for fact/profile-guided policy choices | Policy and emission remain runtime-internal; not an external policy plane | Facts should guide choices, but the runtime/kernel still owns legality and emission |
| GCC / LLVM plugin interfaces | Compiler exposes pass-manager/plugin hooks and reusable analyses | Good precedent for explicit extension points instead of hard-coded heuristics | In-process compiler plugins can arbitrarily transform IR/code; no kernel safety boundary | Expose structured hooks and facts, not ad hoc knobs |
| `perf_event_open` | Kernel exports structured measurement data to userspace via a normal Linux interface | Strong precedent for "kernel data -> userspace analysis/policy" | `perf_event_open` exports data, not rewrite legality | A verifier-summary export is natural Linux API design |
| eBPF verifier log | Kernel already exports analysis results to userspace | Immediate precedent for a fact channel with zero semantic redesign | Textual, path-trace-oriented, unstable as long-term ABI | Great bootstrap path, weak production ABI |

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

| Improvement | Estimated kernel LOC | Notes |
| --- | --- | --- |
| Remove shape whitelist | 20-40 | Delete helper + two call sites |
| `jit_recompile` log channel | 140-230 | Reuse existing verifier-log infra |
| Explicit overlap semantics | 80-140 | Parse-time arbitration and logging |
| `FUNC_ENTRY` / `FUNC_EXIT` site kinds | 180-325 | Common + x86 dispatch hooks |
| Export verifier summary in `bpf_prog_info` | 330-520 | Summary capture + syscall plumbing |
| `fact_ref` binding in recompile path | 80-140 | Cookie check + rule-side fact validation plumbing |
| Restricted template plan tier | 430-660 | Common framework + first useful x86 templates |

---

## 9. Recommended Implementation Order

### Phase 0: userspace-only prototype

1. Parse existing verifier logs in userspace.
2. Use that to validate which fact kinds materially improve policy quality.

This de-risks the summary design before new kernel state is added.

### Phase 1: remove current v5 friction

1. Remove shape whitelist.
2. Add `jit_recompile` log channel.
3. Make overlap semantics explicit.

This immediately improves policy iteration even before any new fact ABI lands.

### Phase 2: make entry/exit sites first-class

4. Add `FUNC_ENTRY` / `FUNC_EXIT`.

This unlocks prologue/epilogue work without touching verifier semantics.

### Phase 3: production fact channel

5. Export path-invariant verifier facts through `BPF_OBJ_GET_INFO_BY_FD`.
6. Add `fact_ref` binding to `BPF_PROG_JIT_RECOMPILE`.
7. Extend pattern rules with `fact_count + fact_ref[]`.

This is the actual v6 boundary expansion.

### Phase 4: optional richer emission control

8. Add a restricted template tier for a very small initial template set.

Only do this after phases 1-3 are stable; otherwise too many moving pieces land at once.

---

## 10. Bottom Line

The current verifier log already contains enough information to prove that v6 should be fact-aware:

- bounds
- pointer class/provenance
- stack slot state
- loop context
- live-reg pressure

But the log is still the wrong long-term ABI. The right v6 direction is:

- use log parsing now to validate the policy opportunity
- export a small kernel-owned verifier summary next
- bind recompile requests to that summary with `fact_ref`
- add `FUNC_ENTRY` / `FUNC_EXIT`
- keep emitters and templates kernel-owned

That preserves the core BpfReJIT novelty:

> kernel-validated, userspace-driven optimization

while meaningfully expanding what userspace can decide.
