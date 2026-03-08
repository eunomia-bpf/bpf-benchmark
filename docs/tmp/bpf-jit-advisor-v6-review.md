# Review of BPF JIT Advisor v6

## Overall Verdict

v6 improves the paper framing, but it overstates what the current mechanism can support.

The v5r2 substrate is still a credible design for **local closed-region rewrites** such as:

- `wide_load`;
- the **narrow** `cmov_select` that v5r2 and the v5r2 review freeze to a one-diamond, pure-destination-assignment template.

It is **not yet** a convincing mechanism for the next novelty-carrying families that v6 wants to rely on:

- `branch_reorder` / `hot_fallthrough`;
- `subprog_inline`;
- a deployment-time control loop spanning pinned programs, mixed loaders, and fleet rollout.

The main problems are not theoretical. They fall directly out of:

- the current x86 JIT structure (`vendor/linux/arch/x86/net/bpf_jit_comp.c`);
- the verifier rewrite pipeline (`vendor/linux/kernel/bpf/verifier.c`);
- the separate subprogram JIT pipeline (`jit_subprogs()`); and
- the one-image, one-digest, one-load-time binding model described in v5r2/v6.

## Major Findings

1. v6's new policy-sensitive families are not supported by the v5r2 mechanism as currently specified.
   - v5r2 explicitly says "No block reordering is introduced in v1" and that this is why `cmov_select` is feasible while `branch_hint` stays future work (`docs/tmp/bpf-jit-advisor-v5r2.md:520`).
   - The hub doc then upgrades `branch_reorder` to "should be added in v1" (`docs/kernel-jit-optimization-plan.md:174`, `docs/kernel-jit-optimization-plan.md:402`) without supplying the missing mechanism.

2. The v6 `cmov_select` example exceeds the v5r2 contract.
   - v5r2 allows only arm values that are `reg` or `imm`, with each arm performing exactly one assignment to the same destination and no other state changes (`docs/tmp/bpf-jit-advisor-v5r2.md:592-610`).
   - v6's `binary_search` example uses `reg+reg` arithmetic and `reg xor (reg+imm)` inside the select lowering (`docs/tmp/bpf-jit-advisor-v6.md:360-412`).
   - The v5r2 review explicitly said to keep `cmov_select` frozen to the narrow pure-assignment template (`docs/tmp/bpf-jit-advisor-v5r2-review-r2.md:104-105`).

3. The current kernel/JIT interfaces still assume one canonical native PC per BPF instruction.
   - `bpf_prog_update_insn_ptrs()` stores one `jitted_off` per original instruction (`vendor/linux/kernel/bpf/bpf_insn_array.c:268-303`).
   - `bpf_prog_fill_jited_linfo()` similarly maps each BPF instruction offset to one native offset (`vendor/linux/kernel/bpf/core.c:228-255`).
   - Any directive that duplicates BPF instructions, such as v6's sketched `hot_fallthrough { max_dup_insns = 4 }`, needs a canonical-PC rule that the design never defines.

4. The fleet/A-B story assumes a much more controlled deployment environment than the docs admit.
   - v6 says the advisor runs on the exact post-CO-RE, post-subprogram-finalization image passed to `BPF_PROG_LOAD` (`docs/tmp/bpf-jit-advisor-v6.md:237`).
   - That makes the directive blob inherently loader-specific and build-specific.
   - A "fleet policy DB" is not enough by itself; you also need a directive-aware loader path everywhere that exact image can be created.

## 1. Mechanism Gaps

### 1.1 What the current framework can actually support

The current substrate is best described as:

- one finalized pre-verifier BPF image;
- one directive blob bound to that exact image digest;
- one directive naming one original contiguous range;
- remap to one contiguous post-verifier interval;
- validate one exact local shape;
- emit one fused native sequence at the directive start;
- fall back per site if validation fails.

That model is a good fit for:

- straight-line local fusion (`wide_load`);
- one closed diamond that is still emitted as one local region (`cmov_select`).

It is **not** a general CFG-transform substrate.

### 1.2 Cross-basic-block optimizations

`branch_reorder` is the biggest gap.

v6 sketches a future `hot_fallthrough` directive as a bounded one-diamond layout choice (`docs/tmp/bpf-jit-advisor-v6.md:432-445`). The hub doc refers to `branch_reorder` more broadly and promotes it to a v1 target (`docs/kernel-jit-optimization-plan.md:174`, `docs/kernel-jit-optimization-plan.md:402`). Those are not the same thing.

What the current framework can plausibly support:

- a **very narrow** one-diamond region emitter that consumes the whole diamond at the entry and emits both arms in a chosen order;
- no external edges into either arm;
- no duplication, or duplication only with a newly defined canonical-PC rule.

What it cannot support cleanly today:

- general block reordering across an open CFG;
- trace formation;
- layout transforms that need to retarget external branches;
- code duplication without redefining `addrs[]` / line-info semantics.

The reason is structural. The x86 JIT is still a linear multi-pass emitter that iterates BPF instructions in index order inside `do_jit()` and resolves control-flow using `addrs[]` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1652-2785`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:3716-3917`). That is compatible with local region replacement. It is not naturally compatible with "move block B before block A" as a first-class operation.

### 1.3 Multi-instruction rewrites that change instruction count

The problem is **not** "changing native instruction count" in general.

The substrate already assumes native instruction-count changes:

- `wide_load` replaces a byte ladder with one load;
- `cmov_select` replaces a branch diamond with a different native sequence.

The unsupported case is narrower and more important:

- rewrites that need **multiple emitted native regions** for one directive;
- rewrites that **duplicate** original BPF instructions;
- rewrites that need **multiple canonical native PCs** for one BPF instruction;
- rewrites that need discontiguous remap results.

The v5r2 remap rule explicitly requires one contiguous post-verifier interval (`docs/tmp/bpf-jit-advisor-v5r2.md:469-479`). That blocks a large class of more ambitious directives by construction.

### 1.4 Runtime-feedback-driven directives

v6's paper framing leans heavily on workload adaptation, fleet feedback, and telemetry (`docs/tmp/bpf-jit-advisor-v6.md:182-197`, `docs/tmp/bpf-jit-advisor-v6.md:208-232`). The mechanism is still mostly **load-time static**:

- decisions are made before `BPF_PROG_LOAD`;
- the kernel only logs accept/reject outcomes;
- there is no in-kernel per-site runtime feedback path;
- changing policy means reloading or replacing the program.

That is enough for offline profiling and canary rollout. It is **not** yet a runtime control plane in the stronger sense implied by the v6 framing.

This matters most for:

- `branch_reorder`, where actual edge bias matters;
- `subprog_inline`, where hotness and code-size budget are program-global;
- any future policy that wants to react to production traffic drift without reloading.

### 1.5 Directive interaction and composability

The current blob rules require directives to be sorted and non-overlapping in original coordinates (`docs/tmp/bpf-jit-advisor-v5r2.md:356-361`). That is a reasonable v1 simplification, but it means the system does **not** currently support composability in the way v6 implies.

Real interaction problems that remain unspecified:

- `branch_reorder` around a region that also contains a `cmov_select` candidate;
- `subprog_inline` changing code size and therefore the profitability of downstream `branch_reorder`;
- `wide_load` and `cmov_select` both depending on the same verifier rewrite/remap decisions;
- any directive whose validity depends on another directive firing first.

Right now the design has only "independent, non-overlapping sites." It does not have:

- ordering rules;
- dependency rules;
- conflict resolution;
- a program-level legality/profitability planner.

### 1.6 `subprog_inline` is outside the current mechanism

`subprog_inline` is not "just another directive kind." It collides with the actual verifier/JIT architecture.

The kernel today:

- discovers subprograms in the verifier;
- splits a multi-function program into separate `bpf_prog`s in `jit_subprogs()`;
- JITs each subprog separately;
- patches `BPF_PSEUDO_CALL` / `BPF_PSEUDO_FUNC` call sites with compiled addresses;
- then runs a final JIT pass with those addresses (`vendor/linux/kernel/bpf/verifier.c:22778-23029`).

That means a late post-verifier emitter hook cannot realistically "inline a subprog" using only `orig_idx` remap. It would also need to reason about:

- call-frame semantics and stack-depth accounting;
- tail-call reachability propagation;
- exception callbacks and exception boundaries;
- per-subprog prologue/epilogue generation;
- linfo and symbol boundaries;
- verifier facts across caller/callee boundaries.

This is a **different class of mechanism** from `wide_load` and narrow `cmov_select`.

## 2. Validator Soundness

### 2.1 `wide_load`

| Item | Review |
| --- | --- |
| Exact preconditions | The site must be a contiguous straight-line interval with no interior targets; all memory ops must be byte loads from one base register and one exact contiguous byte ladder; the load pattern must reconstruct either 4 or 8 bytes in the exact byte order expected by a native little-endian load; `mem_class` must be `STACK` or `MAP_VALUE`; access must be nonfaulting; effective offset must be constant; `min_readable >= width`; `align_log2 >= min_align_log2`; the final architectural result must be the requested `liveout_reg`; and every intermediate definition created by the byte ladder must be dead at the region boundary unless the validator reproduces it. |
| If a precondition is missed | Missing the memory-class / readability / nonfaulting precondition can turn a legal byte ladder into an illegal wider access. Missing the exact byte-order or exact-offset-ladder check can produce the wrong value. Missing the intermediate-register-liveness check can silently drop architectural state that later BPF instructions still use. Missing the width-4 zero-extension check changes upper 32-bit semantics. |
| Edge cases not handled by the current writeup | The v5r2 text does not explicitly require that each byte in the ladder is used exactly once in the correct order. It also does not state that all temporaries other than the final liveout must be dead after the site. Those are real soundness conditions, not optimizations. The writeup also does not say how mixed ALU32/ALU64 byte ladders, duplicated bytes, or partially overlapping ladders are rejected. |

The big gap here is not feasibility. `wide_load` is feasible. The gap is that the validator description is still slightly underspecified for a correctness-critical local rewrite.

### 2.2 `cmov_select`

| Item | Review |
| --- | --- |
| Exact preconditions | The site must be exactly one entry conditional branch plus two arms plus one join; no interior targets; no calls, helpers, tail calls, exits, stack writes, atomics, or other side effects; each arm performs exactly one assignment to the same `dst_reg`; both values must match the directive payload; the compare/condition-code mapping must be exact; width must be 32 or 64; and for width 32 the validator must prove the expected zero-extension behavior. |
| If a precondition is missed | If the region is not a single closed diamond, the transformed control flow can be wrong. If an arm performs any extra visible state change, converting it to `cmov` drops that effect. If the condition-code mapping is wrong or inverted, the selected value is wrong. If width-32 zero-extension is mishandled, region-boundary semantics change. If x86 materialization clobbers flags before `cmov`, the branch condition is lost. |
| Edge cases not handled by the current writeup | The x86 side does not specify how immediate-valued arms are materialized. `cmovcc` cannot take an immediate source. v5r2 says the future arm64 emitter may materialize immediates into registers, but the x86 emitter description does not say whether x86 v1 rejects immediate arms or reserves a temp register (`docs/tmp/bpf-jit-advisor-v5r2.md:549-556`, `docs/tmp/bpf-jit-advisor-v5r2.md:612-620`). The writeup also does not spell out the flag-discipline requirement: any value materialization done between `cmp/test` and `cmov` must preserve flags, or the compare must be re-issued. |

There is also a design inconsistency here:

- v5r2 `cmov_select` is a **pure assignment** selector;
- v6's `binary_search` example is a **small expression selector**.

Those are different directives. The current validator only covers the first.

### 2.3 `branch_reorder` / `hot_fallthrough`

This validator is not sound today because it is not actually specified.

At minimum, a sound bounded one-diamond layout directive would need all of the following preconditions:

- the remapped region is exactly one entry and one join;
- no external jumps target either interior arm;
- the join is unique and post-dominates both arms;
- no helper calls, tail calls, bpf2bpf calls, exits, extable-producing memory accesses, exception boundaries, or poke-descriptor sites occur inside moved/duplicated code;
- if inversion is allowed, the condition-code inversion is exact;
- if duplication is allowed, only instructions with no observable side effects, no fault behavior, and no special metadata obligations may be duplicated;
- the design must define which native copy owns the canonical BPF PC for `addrs[]`, `jited_linfo`, and insn-array users.

If any of those are missed, the failure modes are concrete:

- external control-flow can jump into the wrong place;
- duplicated side effects can execute twice;
- exception-table or tail-call fixup metadata can point at the wrong native code;
- line-info and insn-array mappings become ambiguous or wrong.

The edge cases the current design does not handle are precisely the ones that make layout transforms hard:

- nested diamonds;
- loops / backedges;
- blocks with side effects;
- code duplication;
- interaction with tail-call poke descriptors;
- interaction with subprogram boundaries.

## 3. Implementation Feasibility Against the Actual Kernel

### 3.1 The actual JIT model is still linear

The x86 JIT does not have a CFG builder or a block placer. It does:

- a linear `for` loop over BPF instructions in `do_jit()` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1717-2785`);
- multi-pass size convergence using `addrs[]` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3716-3917`);
- branch displacement calculation from BPF-PC-relative targets (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2605`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:2656`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:2661`).

That model is well aligned with:

- local replacement at one site entry;
- skipping covered instructions;
- assigning a single canonical native entry point to each covered original instruction.

It is poorly aligned with:

- arbitrary block reordering;
- duplication;
- interprocedural transforms.

### 3.2 Can `branch_reorder` work without fundamental JIT changes?

**General block reordering:** no.

For the reasons above, there is no existing notion of:

- BPF basic blocks as first-class objects;
- external edge retargeting for moved blocks;
- canonical-PC selection for duplicated code;
- block-order search or layout convergence.

**A narrow `hot_fallthrough` one-diamond region emitter:** maybe, but only with a much narrower contract than the docs currently imply.

That narrower contract would still require non-trivial new machinery:

- region-level emission at the diamond entry instead of per-insn emission only;
- explicit rules for `addrs[]` values inside a reordered region;
- a canonical-PC rule if any duplication is allowed;
- careful convergence handling for internal label distances.

That is not impossible. But it is also not "same substrate, another 50-100 LOC directive."

### 3.3 Verifier rewrites are a real implementation burden

v5r2 correctly identifies `orig_idx` preservation as required new verifier work. The current kernel does **not** preserve it through patch expansion:

- `orig_idx` is initialized once (`vendor/linux/kernel/bpf/verifier.c:25939-25940`);
- `adjust_insn_aux_data()` currently propagates `seen` and `zext_dst`, but not `orig_idx` (`vendor/linux/kernel/bpf/verifier.c:21922-22039`).

So even for `wide_load` / narrow `cmov_select`, the design still needs meaningful verifier surgery. That is fine for v1. It becomes much harder once the target directive family is `branch_reorder` or `subprog_inline`.

### 3.4 Constant blinding is still a hard cutoff

The actual JIT pipeline blinds constants **before** JIT by cloning and rewriting the program:

- `bpf_jit_blind_constants()` clones and patches instructions (`vendor/linux/kernel/bpf/core.c:1489-1554`);
- x86 JIT runs that before normal compilation (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3738-3748`).

v5r2 therefore drops the entire directive set if blinding is requested (`docs/tmp/bpf-jit-advisor-v5r2.md:491-500`).

That is a real deployment limitation:

- the mechanism is unavailable on the blinded path;
- any environment that insists on blinding gets no advisor at all;
- v6's deployment story should treat this as a meaningful scope cut, not a footnote.

### 3.5 Tail calls are not just another excluded opcode

The verifier rewrites helper-form tail calls into `BPF_JMP | BPF_TAIL_CALL`, may inject speculation-guard instructions, and may create poke descriptors before JIT (`vendor/linux/kernel/bpf/verifier.c:23725-23797`).

The x86 JIT then emits dedicated tail-call machinery and does direct fixups after image finalization (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2443-2477`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:3878-3885`).

Implications:

- directives cannot safely span or reorder tail-call sites without becoming tail-call-aware;
- any layout directive must explicitly blacklist poke-descriptor sites;
- `subprog_inline` also interacts with the verifier's tail-call reachability propagation (`vendor/linux/kernel/bpf/verifier.c:6840-6865`, `vendor/linux/kernel/bpf/verifier.c:22911`).

### 3.6 BPF-to-BPF calls are the clearest evidence against `subprog_inline`

The real pipeline for multi-function programs is:

1. split into per-subprog `bpf_prog`s;
2. JIT each subprog;
3. patch pseudo calls/functions to compiled addresses;
4. run a final JIT pass (`vendor/linux/kernel/bpf/verifier.c:22778-23029`).

That means `subprog_inline` cannot be treated as a late local lowering choice over an already-verified whole program. It wants to change the very call boundary that the verifier/JIT pipeline currently reifies as separate compiled objects.

This is why `subprog_inline` is qualitatively different from every v5r2 directive.

## 4. Deployment Story Gaps

### 4.1 Pinned programs make rollout reload-based, not policy-DB-based

v6 talks about fleet management and A/B testing as if a new policy can simply be rolled out to 5% of machines (`docs/tmp/bpf-jit-advisor-v6.md:195-197`). For pinned BPF programs, that is not how it works.

Once the program is already loaded and pinned:

- the native code is already fixed;
- the directive decision is already baked into that loaded instance;
- changing policy requires loading a **new** program instance and switching attachments or links.

That is still operationally acceptable, but it is not "update policy DB and observe effects." It is versioned program replacement.

### 4.2 Map sharing is central to safe rollout, but unspecified

In real deployments, safe rollout often depends on:

- pinning maps separately;
- loading a new program version that reuses those pinned maps;
- switching links/attachments atomically;
- rolling back without losing state.

v6 mentions fleet ownership and service-level control, but it does not explain how the advisor story works with:

- shared pinned maps;
- ABI compatibility between old and new program versions;
- multi-program map sharing during canary rollout.

Without that, the deployment story is incomplete.

### 4.3 Mixed loaders are a real operational problem

The directive blob is bound to the exact finalized pre-verifier image after CO-RE relocation and subprogram finalization (`docs/tmp/bpf-jit-advisor-v6.md:237`).

That means:

- different loaders can produce different finalized images for the "same" source program;
- a fleet service cannot precompute one portable blob and hand it to every loader;
- the loader that generates the final image must either generate the directives itself or call into a directive-aware sidecar that sees that exact image.

The v6 text assumes a Cilium/Katran-like privileged loader path. That is a valid deployment model, but it is **not** a generic one. The paper should say so.

### 4.4 Digest binding is safe, but too rigid to be the whole deployment key

The exact-image digest is the right safety anchor.

It is also operationally rigid:

- any CO-RE difference changes the digest;
- any loader-side subprogram-finalization difference changes the digest;
- semantically equivalent rebuilds still miss the cache;
- cross-version policy reuse becomes a regeneration problem, not a lookup problem.

This does not make digest binding wrong. It means the deployment story needs an additional layer:

- how policies are cached above the digest;
- how site identities remain stable across rebuilds;
- who regenerates blobs when the digest changes.

Right now the docs only specify the lowest-level safety binding, not the operational keying story above it.

## 5. What's Missing From the Design

### 5.1 The third directive family is still not actually specified

The docs currently alternate among:

- `branch_reorder` (`docs/kernel-jit-optimization-plan.md:174`, `docs/kernel-jit-optimization-plan.md:402`);
- `hot_fallthrough` (`docs/tmp/bpf-jit-advisor-v6.md:432-445`);
- earlier `branch_hint` terminology (`docs/tmp/bpf-jit-advisor-v5r2.md:520`).

Those are materially different scopes. The design needs to pick one narrow contract and specify it fully.

### 5.2 Canonical-PC mapping for reordered or duplicated code

This is the single most important missing low-level detail for any CFG/layout directive.

The design needs to define:

- what `addrs[]` means for moved blocks;
- what happens if one original BPF instruction has two native copies;
- what `bpf_prog_update_insn_ptrs()` should record;
- what `bpf_prog_fill_jited_linfo()` should record.

Until this is defined, `branch_reorder` with duplication is not reviewable as a kernel mechanism.

### 5.3 `cmov_select` x86 temp-register and flag discipline

The current text still does not say:

- whether x86 v1 accepts immediate arms;
- which temp register is used if it does;
- how flag preservation is guaranteed between compare and `cmov`;
- whether the v6 expression-style example requires a richer directive than v5r2's payload.

This is not a paper-polish issue. It is part of the exact legality contract.

### 5.4 Directive interaction rules

Still unspecified:

- overlap policy beyond "forbidden";
- dependency ordering;
- whether one directive may invalidate another's retained facts;
- whether userspace must pre-resolve all conflicts;
- what the kernel logs when a directive is rejected because an earlier one fired.

### 5.5 Telemetry / logging interface

v6 correctly elevates logging into the systems story, but the mechanism is still underspecified:

- where the logs go;
- how they are rate-limited;
- how operators retrieve them;
- how site IDs stay meaningful across program rebuilds;
- how acceptance/rejection data is correlated with a pinned program instance.

### 5.6 Real rollout mechanics

Missing deployment details include:

- how to version pinned programs under rollout;
- how to atomically flip links/attachments;
- how to share maps safely across old/new versions;
- how rollback works when the new digest implies a different directive blob;
- what the failure mode is if the loader path is not directive-aware.

## Bottom Line

The honest claim supported by the current mechanism is still:

> a fail-closed substrate for local, closed-region backend lowerings on one exact finalized BPF image.

That is enough for:

- `wide_load`;
- narrow `cmov_select`;
- perhaps, with materially more JIT work, a **very narrow** one-diamond `hot_fallthrough` directive.

It is **not yet** enough for the broader v6 story around:

- general `branch_reorder`;
- `subprog_inline`;
- loader-agnostic fleet policy deployment.

If v6 wants to keep the stronger paper framing, it needs one of two corrections:

1. Narrow the mechanism claim:
   state explicitly that v1 supports only local single-region lowerings, and treat `branch_reorder` / `subprog_inline` as future work requiring new kernel machinery.

2. Or specify the new machinery:
   especially canonical-PC mapping, region-level CFG emission, duplication rules, and a real rollout model for pinned programs and mixed loaders.

Without that correction, v6 is strong as a **paper framing** but still too optimistic as a **mechanism design**.
