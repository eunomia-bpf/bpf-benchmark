# BpfReJIT v6 Interface Improvement Proposals

## Executive summary

The current v5 path is strong for one class of optimization:

- a contiguous xlated-BPF window
- matched by exact opcode/operand shape plus a few simple numeric constraints
- reduced to a small scalar semantic tuple
- lowered by a kernel-owned emitter

That is enough for `rotate`, `wide_mem`, `addr_calc`, `cond_select`, and the current `bitfield_extract` path. It is not enough for the full v6 wish list. The hard blockers are not just "missing descriptors"; they are structural:

- sites must be contiguous and `pattern_count == site_len`
- rules must stay within one subprog
- the kernel only checks local arithmetic constraints, not verifier facts
- the rewrite engine only dispatches at an exact `site_start` and collapses the whole region into one native block
- userspace can pick only `canonical_form + native_choice`, not an arbitrary emission plan

My recommendation is:

1. Keep the current canonical-form model as the default for local peepholes.
2. Do not accept raw userspace native code templates.
3. Add a second v6 tier for fact-backed region rewrites and restricted template plans.

## 1. What v5 actually provides

At the UAPI level, a v5 rule is a `BPF_JIT_RK_PATTERN` record carrying:

- `site_start`, `site_len`
- `pattern_insn[]`
- `constraint[]`
- `binding[]`
- `canonical_form`, `native_choice`

See `vendor/linux-framework/include/uapi/linux/bpf.h:1480-1499`, `vendor/linux-framework/include/uapi/linux/bpf.h:1552-1572`, and `vendor/linux-framework/include/uapi/linux/bpf.h:1659-1672`.

The kernel parses that blob, insists that the rule is a pattern rule, requires `pattern_count == site_len`, and then checks a per-form shape whitelist before it will even try to match it. See `vendor/linux-framework/kernel/bpf/jit_directives.c:2238-2265` and `vendor/linux-framework/kernel/bpf/jit_directives.c:548-568`.

The actual matcher is exact and linear:

- every instruction in the window must match one `pattern_insn`
- opcode match is exact
- operand expectations are exact when the corresponding flag is set
- variables are only bound from `dst_reg`, `src_reg`, `imm`, `off`

See `vendor/linux-framework/kernel/bpf/jit_directives.c:1601-1643`.

If the match succeeds, the kernel evaluates a very small arithmetic predicate language (`EQUAL`, `SUM_CONST`, `IMM_RANGE`, `NOT_ZERO`, `MASK_BITS`, `DIFF_CONST`, `NOT_EQUAL`) and then extracts canonical parameters into a fixed-size tuple. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1646-1719`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1814-1867`, and `vendor/linux-framework/kernel/bpf/jit_directives.c:1869-1953`.

Finally, x86 dispatch just switches on the canonical form and jumps into one of a handful of emitter entry points:

- `emit_canonical_select`
- `emit_canonical_wide_load`
- `emit_canonical_rotate`
- `emit_canonical_lea_fusion`
- `emit_canonical_bitfield_extract`

See `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3251-3374`.

So the real abstraction is not "userspace describes any rewrite." The real abstraction is:

> userspace proves that a local BPF region belongs to one of a few kernel semantic families, and the kernel emits one of its own prewritten native variants.

That is a good abstraction for local lowerings. It is not a general optimization interface.

## 2. Hard limits of the current v5 path

### 2.1 Contiguous, fixed-length windows only

The parser requires `pattern_count == site_len`, and the matcher walks `rule->site_start + i` for every pattern slot. There is no notion of gaps, optional instructions, or multiple disjoint spans. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1607-1616` and `vendor/linux-framework/kernel/bpf/jit_directives.c:2259-2262`.

Implication:

- non-contiguous patterns: impossible
- "match insns 10-12 and 20-21": impossible
- "match a guard here and a redundant guard 40 insns later": impossible

### 2.2 Only local CFG shapes, not general regions

The current mechanism can span a tiny control-flow shape only when the shape is already linearized into one contiguous window. `cond_select` descriptors do exactly that: they encode jump instructions directly in the pattern. See `scanner/src/pattern_v5.cpp:411-470`, `scanner/src/pattern_v5.cpp:493-572`, and `scanner/src/pattern_v5.cpp:655-687`.

The kernel safety check for such a site is only "no outside edge may target an interior instruction." See `vendor/linux-framework/kernel/bpf/jit_directives.c:603-667` and `vendor/linux-framework/kernel/bpf/jit_directives.c:1978-1980`.

This means:

- matching across basic blocks: limited yes, but only for a contiguous single-entry region
- matching arbitrary CFG regions: no
- matching discontiguous blocks: no
- loop-aware matching: effectively no

The reason loops are effectively out is the dispatch model. The rewrite path collapses a whole BPF region into one emitted native block and fills `addrs[]` as if only the region start and region end remain externally visible. See `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3506-3517`. That is fine for a small acyclic local diamond; it is not a general label-preserving layout engine.

### 2.3 Rules must stay within one subprog

`bpf_jit_rule_within_single_subprog()` rejects any site that crosses subprog boundaries. See `vendor/linux-framework/kernel/bpf/jit_directives.c:2040-2076`.

Implication:

- no cross-subprog matching
- no caller-callee transforms
- no inlining family in the current model

### 2.4 Side-effecting regions are filtered out early

The generic safety layer rejects helper calls and all stores before any family-specific validation runs. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1517-1538`.

Implication:

- no store-elimination family today
- no call/inlining family today
- no region that needs to reason about memory side effects today

### 2.5 Shape is hard-coded per canonical form

Even after the UAPI moved pattern recognition into userspace, the kernel still bakes in per-form length whitelists:

- `COND_SELECT`: 3 or 4
- `WIDE_MEM`: 4, 7, 10, 13, 16, 19, 22
- `ROTATE`: 4, 5, 6
- `ADDR_CALC`: 3
- `BITFIELD_EXTRACT`: 2 or 3

See `vendor/linux-framework/kernel/bpf/jit_directives.c:548-568`.

This is the biggest practical v5 gap inside the "local peephole" category: new patterns inside an existing family are still kernel-gated.

### 2.6 Userspace does not control emission, only emitter selection

For each family, the emitter consumes a tiny fixed tuple:

- rotate: 4 params
- wide_mem: 4 params
- addr_calc: 4 params
- cond_select: 7 params
- bitfield_extract: 6 params

See `vendor/linux-framework/include/uapi/linux/bpf.h:1603-1649`.

The current max is 12 canonical params and 12 bindings. See `vendor/linux-framework/include/uapi/linux/bpf.h:1555-1556`.

In practice this means userspace cannot say "emit this specific 5-op sequence." It can only say "this site is a rotate by N" or "this site is a bitfield extract with these scalar parameters," and the kernel picks its own sequence. The x86 side makes that explicit. See `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2729-3192`.

### 2.7 The current built-in scanner path is narrower than the UAPI

The UAPI could accept arbitrary v5 rules, but the current scanner CLI does not expose that generality. `--v5` just runs the built-in descriptor registry, builds a blob, and applies it; `--policy` is explicitly unsupported in v5 mode. See `scanner/src/cli.cpp:472-474`, `scanner/src/cli.cpp:590-603`, and `scanner/src/cli.cpp:633-649`.

The built-in v5 scanner is also greedy:

- descriptors are concatenated in family order
- first match wins
- the scanner advances by the matched pattern length
- every emitted v5 rule gets `priority = 0`

See `scanner/src/pattern_v5.cpp:118-130`, `scanner/src/pattern_v5.cpp:712-739`, and `scanner/src/pattern_v5.cpp:1261-1295`.

That is a tooling limitation, not a UAPI limitation, but it matters for real policy quality.

## 3. Are the current constraints and parameter budget sufficient?

### 3.1 Constraint set

For local scalar peepholes, the current constraint language is surprisingly usable:

- `SUM_CONST` covers rotate complements
- `DIFF_CONST` covers consecutive offsets and relative branch distances
- `IMM_RANGE` covers scales and shift ranges
- `NOT_EQUAL` covers temp/dst separation

That is why the current rotate/wide/cmov families fit. See the userspace descriptors in `scanner/src/pattern_v5.cpp:777-883`, `scanner/src/pattern_v5.cpp:928-1056`, and `scanner/src/pattern_v5.cpp:517-570`.

But it is not sufficient for the next tier of directives. Missing predicate classes include:

- ordered comparisons between variables (`a < b`, `a <= b + c`)
- typed constraints (`var must be reg/imm/off`)
- mask structure predicates ("contiguous low-bit mask", "single run of ones", "power of two")
- CFG predicates ("same merge target", "single exit", "fallthrough edge")
- verifier-fact predicates ("guard A dominates load B", "stack slot dead after insn X")

`MASK_BITS` is especially weak: it only checks `(var & const) != 0`. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1691-1694`. That is nowhere near enough for bounds or structured bitfield reasoning.

### 3.2 Are 12 canonical params enough?

For the current families: yes. The largest current form is `COND_SELECT` at 7 parameters. See `vendor/linux-framework/include/uapi/linux/bpf.h:1641-1649`.

For future work:

- local scalar peepholes: probably still yes
- richer region/layout directives: not really the right question

For `branch_reorder`, `bounds_window`, or `subprog_inline`, the bottleneck is not "12 vs 16 params." The bottleneck is that the interface has no way to carry structured region information, fact references, or block contents. Raising the limit to 16 would be a good cleanup, but it would not make structural transforms suddenly fit.

## 4. Candidate directives: can the current interface express them?

I use "CAN" to mean "fits the current v5 abstraction with at most a new descriptor and, if needed, a new canonical emitter within the same overall model." I use "CANNOT" to mean "the current abstraction boundary is wrong for the directive family."

| Directive | Status | Why |
|---|---|---|
| `bitfield_extract` | CAN | Already fits the model. The current codebase has the UAPI form, userspace descriptors, validator, and emitter for `(src >> shift) & mask` or `mask; shift`. See `vendor/linux-framework/include/uapi/linux/bpf.h:1627-1639`, `scanner/src/pattern_v5.cpp:1112-1222`, `vendor/linux-framework/kernel/bpf/jit_directives.c:1339-1453`, and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2904-3192`. |
| `branch_reorder` | CANNOT as a general family | A real branch-reorder transform needs region structure and layout control over multiple blocks. The current model only passes scalar params into a kernel emitter and collapses a contiguous window into one native block. It can encode a tiny diamond, but not arbitrary hot/cold block permutation. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1601-1643`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3506-3517`, and `docs/kernel-jit-optimization-plan.md:107`. |
| `bounds_window` | CANNOT in the intended form | The important case needs retained verifier facts: an earlier dominating check proves a later access is safe. The current interface has no fact channel, no dominance notion, and no non-local region matcher. A toy local duplicate-guard peephole might fit; the general directive does not. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1646-1719` and `vendor/linux-framework/kernel/bpf/jit_directives.c:1955-1984`. |
| `packet_ctx_wide_load` | CAN for the local gather form | If this means "detect a byte-load ladder from one base reg with consecutive offsets and lower it into a wider native load/recompose sequence," the current `WIDE_MEM` abstraction already fits it. The x86 emitter already supports widths 2..8, including odd widths, and only needs `dst`, `base`, `off`, `width`, and endianness. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1888-1901` and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2320-2357`. If the directive also wants to consume separated bounds checks or indexed/non-consecutive accesses, then it becomes a different, structural directive. |
| `subprog_inline` | CANNOT | Calls are rejected by the generic side-effect filter, and rules cannot cross subprog boundaries. Inlining also needs caller/callee frame and control-flow rewriting, not just local instruction selection. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1517-1538`, `vendor/linux-framework/kernel/bpf/jit_directives.c:2040-2076`, and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4270-4289`. |
| `prologue_trim` | CANNOT | The rewrite engine only runs inside the BPF instruction loop. The x86 prologue is emitted before any per-insn dispatch happens, and there is no "function-entry pseudo-site" in the UAPI. See `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:514-565`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3405-3410`, and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3463-3479`. |
| `dead_store_elim` | CANNOT | Stores are rejected before family validation, and real DSE needs memory liveness, not just local pattern shape. See `vendor/linux-framework/kernel/bpf/jit_directives.c:1534-1535`. |

Short version:

- good fit: `bitfield_extract`, local `packet_ctx_wide_load`
- wrong abstraction: `branch_reorder`, `bounds_window`, `subprog_inline`, `prologue_trim`, `dead_store_elim`

## 5. Where the boundary should be

The design doc is directionally right: the kernel should own safety and code generation, and userspace should own pattern discovery and policy. See `docs/kernel-jit-optimization-plan.md:17-20` and `docs/kernel-jit-optimization-plan.md:79-83`.

I would keep that boundary, but sharpen it:

### 5.1 Kernel should do

- digest binding, arch binding, CPU gating
- local rule validation against actual xlated BPF
- validation against retained verifier facts when needed
- native code emission from a kernel-owned template vocabulary
- fail-closed fallback

### 5.2 Userspace should do

- candidate discovery
- cost/benefit decisions
- overlap resolution policy
- hotness/profile integration
- template choice within a safe kernel-defined menu

### 5.3 What the kernel should not do

- rediscover optimization candidates heuristically
- own workload policy
- execute userspace-supplied raw native code

### 5.4 Raw native templates are the wrong next step

A "userspace provides raw x86 bytes and the kernel validates them" design sounds flexible, but it is the wrong tradeoff.

The kernel would need to validate at least:

- instruction whitelist / decode correctness
- branch targets and region confinement
- stack pointer and frame invariants
- callee-saved register discipline
- exception/extable interaction
- ENDBR/CFI/tail-call layout constraints
- helper/kfunc/call restrictions
- memory access safety

That is already close to building a second native verifier. On x86, with variable-length encoding, that is the opposite of the project's current minimal and fail-closed philosophy.

### 5.5 Better answer: a restricted template-plan tier

The right direction is not raw machine code. The right direction is:

- kernel-defined micro-templates or macro-ops
- userspace-selected plan instances
- kernel validation of operands, control flow, and allowed template composition

Conceptually:

- v5 canonical forms stay for simple scalar lowerings
- v6 adds a structured "plan" tier for richer local/native layout control

That would have been a cleaner answer to the "odd-width wide load needed kernel emitter work" problem: userspace could choose a chunking plan, while the kernel would still own the actual safe instruction encodings.

## 6. Concrete v6 interface improvements

### 6.1 Remove the hard-coded per-form shape whitelist

What it enables:

- new local patterns inside an existing semantic family without touching the parser
- better `cmov_select` coverage
- more rotate/wide variants without a kernel-side "site_len list" edit

UAPI change:

- none required if the kernel simply drops `bpf_jit_pattern_rule_shape_valid()`
- optional: add per-form capability flags later if desired

Kernel work:

- roughly 40-80 LOC

Risk:

- low

Why:

Today this is pure friction. If canonical params validate and the emitter can handle the form, the static length whitelist is redundant.

### 6.2 Add `log_level` / `log_buf` / reject-reason reporting to `BPF_PROG_JIT_RECOMPILE`

What it enables:

- userspace can see why a rule was rejected
- practical policy iteration on live programs
- easier diagnosis of overlap, subprog, CFG, or CPU-gating failures

UAPI change:

- extend `attr.jit_recompile` with `log_level`, `log_size`, `log_buf`
- optionally add per-rule reject reason codes

Kernel work:

- roughly 120-220 LOC

Risk:

- low

Why:

Current `jit_recompile.flags` must be zero and there is no log channel. See `vendor/linux-framework/include/uapi/linux/bpf.h:2169-2173` and `vendor/linux-framework/kernel/bpf/jit_directives.c:2604-2612`.

### 6.3 Make overlap semantics explicit

What it enables:

- deterministic arbitration between large structural rules and smaller peepholes
- safer composition of userspace policy engines

UAPI change:

- add either `conflict_group` + `priority`, or an explicit `overlap_policy`
- minimally, reject all unresolved overlaps in-kernel instead of today’s implicit behavior

Kernel work:

- roughly 80-180 LOC

Risk:

- low to medium

Why:

Today the kernel sorts by `(site_start, -priority)` but only returns a rule if lookup hits the exact `site_start`; overlapping intervals with different starts are not a first-class concept. See `vendor/linux-framework/kernel/bpf/jit_directives.c:487-502` and `vendor/linux-framework/kernel/bpf/jit_directives.c:2485-2522`.

### 6.4 Replace fixed arithmetic constraints with a small typed expression language

What it enables:

- richer local peepholes without adding one-off kernel validators
- predicates like `a < b + c`, "mask is contiguous low bits", "shift matches field width"
- better `packet_ctx_wide_load` and future bitfield families

UAPI change:

- either add more constraint opcodes, or better:
- add an expression section with bounded nodes and typed comparators

Kernel work:

- roughly 200-400 LOC

Risk:

- medium

Why:

This is the highest-value upgrade inside the current local-window model. It directly extends the part of v5 that is already working well.

### 6.5 Add fact-backed predicates from the verifier / BTF side tables

What it enables:

- `bounds_window`
- guarded packet/ctx load fusion
- limited store elimination
- any future transform whose legality depends on dominance, liveness, or access-window facts

UAPI change:

- new fact-query API, or new `fact_ref[]` section in the policy blob
- rule predicates can then refer to fact kinds such as `PTR_WINDOW`, `DOMINATES`, `STACK_SLOT_DEAD`, `LIVEOUT_MASK`

Kernel work:

- roughly 350-700 LOC, mostly verifier plumbing and validation

Risk:

- high

Why:

This is the real boundary-crossing upgrade. Without a fact channel, the interface stays limited to syntactic peepholes.

### 6.6 Add new site kinds beyond "BPF insn span"

What it enables:

- `prologue_trim`
- epilogue policies
- call-site or subprog-entry transforms

UAPI change:

- add `site_kind`
- examples: `INSN_REGION`, `FUNC_ENTRY`, `FUNC_EXIT`, `CALL_SITE`

Kernel work:

- roughly 200-400 LOC

Risk:

- medium to high

Why:

The current site model cannot even name the prologue. That makes "prologue as a directive family" impossible by construction.

### 6.7 Add a restricted template-plan emission tier

What it enables:

- more userspace control over native layout without raw machine code
- future `branch_reorder`-like local region layouts
- more flexible lowering choices inside existing families

UAPI change:

- add either:
  - `template_id + plan_args[]`, or
  - a bounded `template_op[]` array from a kernel-owned opcode set

Kernel work:

- roughly 400-900 LOC for the first useful x86 version

Risk:

- medium to high

Why:

This is the best compromise between "current emitters are too rigid" and "raw native templates are too dangerous."

### 6.8 Raise the scalar tuple budget modestly, but do not over-index on it

What it enables:

- cleaner future forms without immediately hitting arbitrary ceilings

UAPI change:

- raise `BPF_JIT_MAX_BINDINGS` and `BPF_JIT_MAX_CANONICAL_PARAMS` from 12 to 16
- widen `present_mask` if needed later

Kernel work:

- roughly 30-80 LOC

Risk:

- low

Why:

This is a cleanup, not a strategic answer. It is worth doing, but it does not solve the structural gaps.

## 7. Comparison with related systems

### 7.1 JVM / .NET JIT hints

HotSpot, Graal/JVMCI, and .NET PGO all let external information influence optimization policy, but they do not normally accept arbitrary externally authored machine code as the fast path. Profiles, compiler directives, and metadata shape what the JIT chooses; the runtime still owns legality and emission.

BpfReJIT should follow that model:

- userspace provides policy and region knowledge
- kernel retains emission ownership

What is unusual about BpfReJIT is that the policy boundary is post-verifier and backend-facing, not IR-facing.

### 7.2 Profile-guided optimization interfaces

Classic PGO exports things like:

- edge counts
- block hotness
- type profiles
- inline profitability hints

Those interfaces guide decisions; they do not replace the compiler backend.

For BpfReJIT, the analogue would be:

- userspace chooses the site and the template
- optional hotness/fact metadata helps justify the choice
- kernel still validates and emits

This is another argument against raw native templates.

### 7.3 eBPF extension mechanisms

`struct_ops`, trampolines, helpers, and kfuncs all follow the same basic philosophy:

- userspace or BPF code gets control over policy/mechanism selection
- the kernel still defines the safe execution model

BpfReJIT should look more like those mechanisms than like a native-code injection API. The right mental model is "structured, kernel-validated lowering selection," not "upload assembly."

## 8. Recommended v6 direction

For v6, I would split the work into three bands.

### 8.1 Immediate, low-risk upgrades

- remove the shape whitelist
- add `jit_recompile` logging
- define overlap semantics
- raise the scalar tuple ceiling to 16

These directly improve the current v5 experience without changing the thesis.

### 8.2 Medium-term upgrade to keep the current local model viable

- replace fixed constraints with typed expressions
- add a few more emitter families that still fit the scalar model

This is enough for:

- better `cmov_select` coverage
- more `packet_ctx_wide_load`
- more bitfield-style lowerings

### 8.3 Real v6 expansion for structural directives

- add verifier fact references
- add site kinds beyond insn spans
- add restricted template plans

That is the line where the interface becomes powerful enough for:

- `bounds_window`
- some `branch_reorder` forms
- `prologue_trim`

Even then, I would still keep `subprog_inline` and general `dead_store_elim` out of scope until there is much stronger region/fact infrastructure. Those are not just "one more canonical form."

## Bottom line

The current v5 path is powerful enough for local semantic peepholes and is already a good fit for `bitfield_extract` and local `packet_ctx_wide_load`.

It is not powerful enough for the structural half of the v6 wishlist. The limiting factor is not descriptor count; it is the current abstraction boundary:

- local contiguous window
- local arithmetic predicates
- small scalar tuple
- kernel-chosen emitter

So the right v6 move is not "let userspace send raw x86." The right v6 move is:

- keep kernel-owned safe emitters
- add verifier-backed facts
- add site kinds / region structure
- add a restricted template-plan tier for richer emission choices

That preserves the paper's safety/optimization split while making the interface meaningfully more expressive.
