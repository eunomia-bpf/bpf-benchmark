# BPF-JIT Advisor

## Thesis

`BPF-JIT Advisor` v4 changes the core abstraction.

The goal is now explicit:

- minimal kernel changes;
- maximum expressiveness;
- one kernel-side mechanism that can support many optimizations, not one hard-coded peephole.

The recommended design is a general verifier-assisted **optimization region** framework:

1. userspace identifies optimization regions in the finalized pre-verifier BPF program;
2. userspace describes each region with:
   - an original instruction range,
   - a small target-independent replacement IR,
   - declarative safety preconditions;
3. the verifier rewrites the program as usual, builds an `orig_insn_off -> post_insn_off` remap, and retains only the verifier facts the JIT cannot reconstruct later;
4. the JIT validates each region against the post-verifier program plus retained facts;
5. on success, the arch JIT lowers the replacement IR to native code;
6. on failure, the JIT falls back to ordinary instruction-by-instruction emission.

This is the right compromise between:

- v3's overly narrow per-pattern design; and
- a much riskier "inject arbitrary native code" design.

The key architectural change is this:

- the kernel should **not** grow one consumer per optimization type;
- it should grow **one region validator/lifter**, **one retained-fact summary**, and **one per-arch lowering path for a small region IR**.

That is what gives minimal kernel mechanism with maximal future expressiveness.

## Design Tension And v4 Resolution

R3 was correct about one thing: the previous draft became credible only after narrowing hard. In particular, `wide-load-ok` became believable only after reducing the legality basis to aligned constant-offset stack and map-value loads.

The PI's new requirement pulls in the opposite direction:

> Minimal kernel changes, but maximum expressiveness; the kernel-side mechanism should support many optimization types, not just one.

Those are not actually contradictory if the design separates:

- the **kernel mechanism**, which should be general and shared;
- the **initial optimization inventory**, which can still be staged and conservative.

So v4 makes a different cut:

- the kernel mechanism is now general;
- the retained verifier facts stay minimal;
- the initial prototype still starts narrow on what facts are exported from the verifier;
- the architecture no longer bakes `wide-load`, `select`, `rotate`, or any other optimization family into the ABI.

That is the right way to satisfy both constraints:

- R3's realism requirement on verifier-retained facts; and
- the PI's requirement that the mechanism remain reusable for many optimizations.

## Paper Story

The paper story should now be:

1. Characterization shows that residual eBPF performance gaps often come from backend lowering, not only bytecode shape.
2. Bytecode rewriters alone cannot force backend decisions such as memory widening, if-conversion, rotate recognition, bitfield extraction, or other local machine-level improvements.
3. The correct kernel architecture is a verifier-assisted **general region replacement** mechanism:
   - the verifier remains the legality authority;
   - the JIT consumes verifier-retained facts plus the post-verifier program;
   - userspace is optional and only supplies candidate regions plus semantics descriptions.
4. The research question is not "should Linux accept a permanent hint UAPI?" but:
   - can a small kernel mechanism expose enough structure that userspace can keep discovering new backend opportunities without repeated verifier redesign?

That is a stronger systems story than either:

- direct one-off peepholes only; or
- a generic user hint ABI with vague kernel validation.

## Main Design Options

There are now three relevant designs.

| Design | Kernel mechanism | Estimated kernel LOC for research prototype | Expressiveness | Safety model | Trust model | Paper-prototype feasibility |
| --- | --- | ---: | --- | --- | --- | --- |
| v3 narrow hint | per-pattern matchers plus narrow retained facts | ~600-900 shared, then ~100-200 per optimization per arch | Low | kernel local matching | userspace only nominates anchors | High |
| **General optimization region + replacement IR** | one shared region validator/lifter, one retained-fact summary, one per-arch IR lowerer | ~900-1400 shared, then ~250-500 per arch | High within the IR vocabulary | kernel re-lifts and validates against verifier facts | low trust in userspace | **Medium-high** |
| Optimized native code injection + certificate | parser, proof checker or translation validator, code patcher | ~1800-3500+ shared, plus arch-specific proof/patching work | Very high | only as strong as the proof checker | medium/high unless proof is extremely strong | Low |

These are order-of-magnitude estimates for an x86-first research prototype, not upstream engineering estimates.

### Why v3 Narrow Hint Is No Longer The Right Center

v3's narrow design fixed credibility by collapsing scope:

- only `wide-load-ok`;
- only `select-region`;
- only narrow retained facts;
- userspace reduced to optional anchor discovery.

That was appropriate as a repair step, but it now undershoots the PI's requirement. It still implies that every new optimization family needs:

- a new kernel matcher;
- often a new kernel hint kind;
- usually new paper text defending each new consumer separately.

That is exactly the scaling problem v4 should remove.

### General Optimization Region + Replacement IR

This is the recommended v4 architecture.

Userspace supplies a **region description**, not a claim that the kernel should trust blindly:

- original instruction range;
- replacement IR saying what the region computes;
- preconditions describing what must hold for replacement to be valid.

The kernel then:

1. remaps the region to the post-verifier program;
2. locally re-lifts the post-verifier region into the same IR;
3. checks structural constraints and safety preconditions;
4. lowers the IR to native code if validation succeeds.

The important property is that many future optimizations can reuse the same mechanism:

- `wide-load`
- `select`
- `rotate`
- `bswap`
- bitfield extract
- mask/shift fusion
- other local scalar or memory-folding patterns

If a new optimization is expressible in the existing IR vocabulary and region topology rules, it can be added in userspace without new verifier plumbing and without a new kernel-side hint format.

That is the closest realistic design to "userspace-extensible" without moving trust out of the kernel.

### Optimized Native Code Injection

This is the more aggressive alternative:

1. userspace compiles BPF regions to optimized native code directly;
2. userspace supplies native bytes, replaced BPF range, and a certificate;
3. kernel validates the certificate and patches the JIT stream.

Its appeal is obvious:

- maximum expressiveness;
- per-arch optimization logic moves to userspace;
- adding new optimizations can become purely userspace-side.

But it is also a different research project.

The hard part is not code patching. The hard part is certificate checking:

- semantic equivalence between BPF region and native bytes;
- register convention preservation;
- stack discipline;
- absence of hidden side effects;
- valid control-flow shape;
- memory access constraints;
- speculation and fault behavior;
- interaction with extables, helper calls, tail calls, and epilogues;
- deterministic code size across JIT passes.

Unless the kernel contains a serious translation validator or proof checker, the trust model becomes unacceptable. If it does contain one, the kernel mechanism is no longer small.

That makes native injection attractive as future work, but too risky for the main v4 design.

## Recommendation

The recommended design is:

- **general optimization regions**
- **described by a small replacement IR**
- **validated by the kernel against the post-verifier program and retained verifier facts**

Not:

- one kernel consumer per optimization kind; and not
- user-provided native bytes in v1.

This gives the best balance:

- minimal verifier changes;
- one reusable kernel mechanism;
- real support for many optimization families;
- credible fail-closed behavior;
- a prototype that is still buildable.

## Coordinate Systems

v4 still needs the same two coordinate systems as v3:

- `orig_insn_off`: instruction index in the program image submitted to `BPF_PROG_LOAD`, after CO-RE/libbpf relocation and subprogram finalization, but before verifier rewrites.
- `post_insn_off`: instruction index in the final verifier-rewritten `prog->insnsi` consumed by the JIT.

Userspace only speaks in `orig_insn_off`.

The JIT only speaks in `post_insn_off`.

### Why This Still Matters

Userspace cannot name stable post-verifier coordinates:

- the verifier inserts instructions;
- the verifier removes instructions;
- `convert_ctx_accesses()` rewrites accesses later;
- aux entries are shifted during patch/remove paths;
- `env->insn_aux_data` is freed before the JIT runs.

So v4 keeps the same core rule from v3:

- userspace never supplies post-verifier indices;
- the verifier constructs the remap in-kernel.

### Remap Semantics

The practical rule should remain the same as `BPF_MAP_TYPE_INSN_ARRAY` semantics:

- every original instruction gets one remap entry;
- `orig_to_post[orig]` is the first rewritten instruction corresponding to that original instruction;
- deleted originals map to `U32_MAX`.

That semantics is already the right one for JIT consumers because it anchors to the first surviving rewritten slot.

### Region Remap For Ranges

Unlike v3's anchor-only design, v4 region records carry a range:

- `orig_start_off`
- `orig_end_off` (exclusive)

To remap a userspace region into a post-verifier envelope:

1. find the first surviving `orig_to_post[o] != U32_MAX` for `o in [orig_start_off, orig_end_off)`;
2. that becomes `post_start`;
3. find the first surviving mapping for `o >= orig_end_off`;
4. that becomes `post_end`, or `post_insn_cnt` if none exists.

So the JIT receives a conservative post-verifier envelope `[post_start, post_end)`.

That envelope may contain:

- inserted verifier instructions;
- rewritten ctx sequences;
- other verifier-generated instructions.

The region validator must therefore recover the actual candidate region from the post-verifier envelope, not assume that the original range survived literally.

If no original instruction in the interval survives, the region is dropped.

### Why `orig_idx` Alone Is Still Not Enough

The same realism point from v3 remains true:

- `orig_idx` is verifier scratch;
- inserted instructions get zeroed aux slots;
- replacement moves aux state in ways that do not give the JIT the right contract;
- the whole aux array is freed before return from `bpf_check()`.

So the design must still say:

- explicit `orig_to_post` in `bpf_prog_aux`;
- not "reuse `orig_idx` later in the JIT."

### Update Points

The remap and any temporary JIT scratch metadata must follow the same verifier rewrite sites that already adjust instruction-sensitive state:

- insertion/replacement path: `adjust_insn_aux_data()` and `bpf_patch_insn_data()` in `vendor/linux/kernel/bpf/verifier.c`;
- removal path: `verifier_remove_insns()` in `vendor/linux/kernel/bpf/verifier.c`.

That is where drift is actually solved.

## What Exists Today In The Kernel

The verifier today keeps the information v4 needs, but only transiently.

Relevant current state:

- full path-sensitive register state in `struct bpf_reg_state` in `vendor/linux/include/linux/bpf_verifier.h`;
- stack byte initialization state in `struct bpf_stack_state` in the same header;
- per-insn scratch in `struct bpf_insn_aux_data`;
- coarse surviving program metadata in `struct bpf_prog_aux` in `vendor/linux/include/linux/bpf.h`.

What does **not** survive into JIT time today:

- full register-state snapshots;
- per-insn fixed offsets;
- per-insn readable-byte facts;
- per-insn aligned-width facts;
- path-sensitive stack initialization summaries;
- any reusable remap from original to post-verifier numbering.

So v4 still needs a new retained summary in `bpf_prog_aux`.

The difference from v3 is not "more retained data." It is:

- the retained data stay minimal;
- the region interface becomes general.

## Retained Kernel State

### Design Principle

The verifier should retain only facts that the JIT cannot reconstruct by re-reading the post-verifier BPF program.

That means:

- keep control/data-flow structure in the JIT matcher and region lifter;
- retain only verifier-only legality facts, mostly around memory access.

This keeps the kernel mechanism small even while the region abstraction becomes general.

### Proposed Persistent Summary

```c
enum bpf_jit_mem_class {
    BPF_JIT_MEM_NONE      = 0,
    BPF_JIT_MEM_STACK     = 1,
    BPF_JIT_MEM_MAP_VALUE = 2,
    BPF_JIT_MEM_PACKET    = 3, /* reserved for future work */
    BPF_JIT_MEM_CTX       = 4, /* reserved for future work */
};

struct bpf_jit_insn_meta {
    __u32 ptr_type;
    __s32 fixed_off;
    __u8  mem_class;
    __u8  access_size;
    __u8  max_readable_bytes;
    __u8  max_aligned_width;
};

struct bpf_jit_summary {
    __u32 orig_insn_cnt;
    __u32 post_insn_cnt;
    __u32 *orig_to_post;                 /* orig_insn_cnt entries */
    struct bpf_jit_insn_meta *insn_meta; /* post_insn_cnt entries */
};

struct bpf_prog_aux {
    ...
    struct bpf_jit_summary *jit_summary;
};
```

Important details:

- `fixed_off` should be `s32`, not `s16`;
- `insn_meta[i]` is meaningful only for instructions where verifier-only memory facts matter;
- `PACKET` and `CTX` are placeholders for future work, not v1 claims.

This summary is small enough to be credible and general enough to support many region families.

### What The Summary Is And Is Not

It is:

- a remap;
- a minimal memory-legality summary.

It is not:

- a full per-insn verifier-state snapshot;
- a persistent region database;
- a generic proof object;
- a full symbolic summary of arbitrary BPF.

That boundary is important for keeping kernel changes minimal.

## Verifier-Side Scratch State

The verifier should accumulate temporary JIT memory facts while normal verification runs, then copy them into `prog->aux->jit_summary` after all rewrites finish.

### Proposed Scratch Record

```c
struct bpf_jit_mem_aux {
    __u32 ptr_type;
    __s32 fixed_off;
    __u8  mem_class;
    __u8  access_size;
    __u8  max_readable_bytes;
    __u8  max_aligned_width;
};
```

This scratch record lives alongside `env->insn_aux_data`.

### Update Point

The right update point remains immediately after a load has passed normal verifier checks in `check_load_mem()`.

At that point, the verifier still has:

- `bpf_reg_state`;
- stack slot state;
- map metadata;
- alignment and range information.

So `record_jit_mem_aux(env, insn)` can snapshot only the facts the JIT will later need.

### v1 Memory Fact Scope

To keep the verifier export credible, v1 still records memory facts only for:

- `BPF_LDX | BPF_MEM` loads;
- constant-offset accesses;
- `PTR_TO_STACK`;
- `PTR_TO_MAP_VALUE`.

This keeps the retained facts narrow while leaving the **region mechanism** general.

That distinction is the core v4 discipline:

- the mechanism supports many optimization families;
- the exported verifier facts remain minimal in v1.

### How Memory Facts Are Computed

For `PTR_TO_MAP_VALUE`:

- `fixed_off` comes from the effective constant offset at the load site;
- `max_readable_bytes` comes from the remaining `map->value_size` bound;
- `max_aligned_width` reuses the verifier's current alignment basis.

For `PTR_TO_STACK`:

- `fixed_off` comes from the effective constant stack byte offset;
- `max_readable_bytes` comes from contiguous initialized bytes in `slot_type[]`;
- `max_aligned_width` again reuses the verifier's alignment basis.

This is enough to validate memory-widening and load-fusion regions without pretending that packet and ctx are already solved.

## Path-Merge Semantics

R3's remaining verifier-side gap should now be stated explicitly.

If the same load instruction is revisited under multiple verifier states, JIT metadata must merge conservatively.

The rule should be **intersection**, not union.

### Conservative Join Rule

On first visit:

- record the candidate facts normally.

On later visits:

- if memory class differs, clear the record;
- if pointer kind differs, clear the record;
- if constant-offset status is lost, clear the record;
- if `fixed_off` differs, clear the record;
- if access size differs, clear the record;
- if a numeric fact is monotone-safe, keep the minimum:
  - `max_readable_bytes = min(old, new)`
  - `max_aligned_width = min(old, new)`

If any path weakens the proof basis, the result is simply:

- no optimization for that instruction.

That is the right fail-closed rule.

It is also consistent with the spirit of current verifier behavior such as `save_aux_ptr_type()`:

- verifier conflicts can still be fatal for safety;
- JIT optimization facts should merely degrade to "not usable."

## Scratch Tracking During Verifier Rewrites

R3's other remaining implementation gap also needs to be explicit.

Any new verifier-side scratch array must follow the same lifecycle as `env->insn_aux_data`.

### Required Update Sites

Allocate and initialize it alongside `env->insn_aux_data` in `bpf_check()`.

Track insert/replace in:

- `bpf_patch_insn_data()`
- `adjust_insn_aux_data()`

Track removals in:

- `verifier_remove_insns()`

If the scratch entries ever own dynamic memory, clear removed entries the same way `clear_insn_aux_data()` clears aux-owned state before removal.

### Required Semantics

On insertion or replacement:

- grow the scratch array as needed;
- shift the tail with the same `memmove` pattern used for aux data;
- zero the newly inserted range;
- treat the replaced slot as needing recomputation unless a field is intentionally propagated.

On removal:

- clear removed entries if needed;
- shift the tail left exactly as aux data is shifted.

If this is not done, the final copied summary can drift even when `orig_to_post` itself is correct.

That point should now be non-negotiable in the design text.

## Finalization Point

The verifier should finalize `prog->aux->jit_summary` after all rewrite passes complete and before verifier teardown frees scratch state.

The natural place remains:

- after the existing rewrite/fixup phase;
- after `adjust_btf_func(env)`;
- before cleanup frees `env->insn_aux_data`.

Finalization does four things:

1. allocate `prog->aux->jit_summary`;
2. copy the completed `orig_to_post` remap;
3. copy the surviving per-insn memory facts into post-verifier indexing;
4. free temporary verifier-side scratch only after the persistent summary exists.

## General Optimization Region Abstraction

The kernel should consume one general region descriptor, not one descriptor per optimization family.

### Region Record

```c
struct bja_region_rec {
    __u32 subprog_id;
    __u32 orig_start_off;
    __u32 orig_end_off;   /* exclusive */
    __u16 arch_mask;
    __u16 flags;
    __u16 nr_inputs;
    __u16 nr_outputs;
    __u16 ir_len;
    __u16 nr_preconds;
    __u32 ir_off;
    __u32 precond_off;
};
```

The record is deliberately generic:

- it names a range;
- it carries semantics;
- it carries declarative preconditions.

It does **not** hard-code `kind == WIDE_LOAD`, `kind == SELECT`, `kind == ROTATE`, and so on as the correctness interface.

If the paper wants family-level reporting, that can be a statistics field, not the kernel correctness contract.

### Region Flags

Useful generic flags are:

- pure / side-effect free;
- single-entry;
- single-exit;
- region contains explicit loads only;
- no interior branch targets expected.

The kernel should still check these properties itself. The flags are descriptive, not trusted.

## Replacement IR

The replacement semantics should be expressed in a small target-independent IR, not as:

- opaque optimization kinds; and not
- user-provided native bytes.

### Why IR Is The Right Middle Ground

If userspace sends only `kind = WIDE_LOAD`, the kernel still needs:

- a pattern-specific matcher;
- a pattern-specific native emitter.

That scales poorly.

If userspace sends raw native bytes, the kernel needs:

- a proof checker or translation validator for arbitrary machine code.

That is too ambitious for v1.

A small replacement IR is the middle ground:

- expressive enough to describe many local backend optimizations;
- constrained enough that the kernel can re-lift and validate it.

### IR Shape

The IR should be:

- small;
- acyclic in v1;
- target-independent;
- canonicalizable;
- restricted to pure local regions.

A sufficient initial vocabulary is:

- input register
- constant
- load from verified memory
- add/sub
- and/or/xor
- shl/lshr/ashr
- zext/sext
- bswap
- rotl/rotr
- compare
- select

That is already enough to describe:

- byte-load recomposition;
- endianness fixes;
- rotate recognition;
- bitfield extraction;
- if-conversion into conditional select.

### Kernel Validation Strategy

The kernel should not try to prove arbitrary equivalence between:

- an opaque userspace IR blob; and
- the BPF region.

Instead, the validator should:

1. parse the post-verifier region;
2. re-lift the region into the same canonical IR;
3. compare the lifted IR against the candidate IR;
4. separately check preconditions against retained facts and current CFG constraints.

That is the critical v4 move.

It makes the validation problem realistic because the kernel only needs a small local region lifter for a restricted BPF subset, not a general proof engine.

### Honest Limit

New optimizations can be added in userspace without kernel changes **only if** they are expressible in:

- the existing region topology rules; and
- the existing IR vocabulary.

If a future optimization needs:

- a new IR operator; or
- new verifier-retained facts,

then the kernel still changes.

That is the honest limit of "userspace-extensible."

## Safety Preconditions

Userspace also supplies declarative preconditions for each region.

These are not trusted claims. They are a compact description of what the kernel should validate.

Useful precondition kinds include:

- no interior branch targets;
- single live-out;
- same base register for all loads;
- constant-offset memory accesses;
- memory class is one of `{STACK, MAP_VALUE}`;
- minimum readable bytes at least `N`;
- minimum aligned width at least `N`;
- no calls, exits, tail calls, atomics, or stores.

The kernel still enforces a fixed minimum safety floor even if the region record underspecifies one of these.

## What Many Optimizations Look Like Under The Same Abstraction

The reason to use a region IR is that distinct optimization families become instances of the same mechanism.

| Family | Region topology | Example replacement IR | Extra verifier facts needed | v4 status |
| --- | --- | --- | --- | --- |
| Wide load / load fusion | straight-line | `dst = bswap(load64(base + off))` or `dst = load32(base + off)` | yes: memory class, readable bytes, alignment | must-have |
| Select / if-conversion | one compare diamond | `dst = select(cmp(a, b), t, f)` | no extra memory facts | must-have |
| Rotate recognition | straight-line | `dst = rotl32(src, c)` | no extra verifier facts | should-have |
| Bitfield extract | straight-line | `dst = and(lshr(src, c), mask)` | no extra verifier facts | should-have |
| Mask/shift fusion | straight-line | `dst = or(shl(x, a), y)` | no extra verifier facts | future |

This is the main answer to the PI's requirement.

The system does not need ten implemented optimizations to make the point. It needs:

- one general mechanism; and
- several clearly different families that reuse it.

## Userspace Candidate Discovery

Userspace is still optional.

Its role is now:

- candidate discovery;
- region IR synthesis;
- precondition description.

It is **not**:

- the legality authority;
- a source of trusted post-verifier coordinates;
- a source of trusted machine code.

### Extraction Point

The extraction point remains after CO-RE and libbpf relocation, because `orig_insn_off` must refer to the exact instruction image submitted to `BPF_PROG_LOAD`.

```text
raw .bpf.o
  -> libbpf parse/open
  -> CO-RE / call / data relocation
  -> finalized submitted instruction image
  -> optional region discovery + IR synthesis
  -> BPF_PROG_LOAD
```

That continues to fix the original pre-relocation drift problem from earlier revisions.

### Prototype Transport

For the artifact, a sealed `memfd` via `hint_fd` is still acceptable as a research transport.

It should now carry region records, not narrow per-pattern anchors.

```c
struct bja_region_blob_hdr {
    __u32 magic;
    __u16 version;
    __u16 hdr_len;
    __u32 total_len;
    __u32 nr_regions;
    __u32 orig_insn_cnt;
    __u8  image_digest[16];
    __u32 rec_off;
};

struct bja_region_rec {
    __u32 subprog_id;
    __u32 orig_start_off;
    __u32 orig_end_off;
    __u16 arch_mask;
    __u16 flags;
    __u16 nr_inputs;
    __u16 nr_outputs;
    __u16 ir_len;
    __u16 nr_preconds;
    __u32 ir_off;
    __u32 precond_off;
};
```

At load time:

1. the kernel validates the blob against the submitted pre-verifier image digest;
2. stores the parsed original ranges temporarily;
3. after verification, remaps ranges through `orig_to_post`;
4. drops regions whose ranges delete away completely;
5. lets the JIT validate the post-verifier envelope and semantics locally.

### Why This Is Better Than v3's Anchor-Only Blob

The blob is still small, but it now carries enough information for generality:

- range;
- semantics;
- preconditions.

It does not require a new record type every time the paper adds another optimization family.

## Kernel Integration

### Generic Flow

The full v4 flow is:

```text
submitted pre-verifier program
  -> verifier ordinary checks
  -> record temporary per-insn memory facts when relevant
  -> verifier rewrites
     - dead-code removal / sanitization
     - ctx conversion
     - other patch/remove passes
  -> finalize orig_to_post + persistent jit_summary
  -> remap optional userspace regions to post-verifier envelopes
  -> JIT
     - kernel-only full scan baseline, or
     - userspace-region-guided validation
     - re-lift post-verifier region into canonical IR
     - validate semantics + preconditions
     - lower IR to native code
     - otherwise fall back to ordinary instruction emission
```

### Shared Kernel Helpers

The shared kernel side should be centered on generic helpers like:

```c
bool bpf_jit_lift_region(const struct bpf_prog *prog,
                         const struct bpf_jit_summary *sum,
                         u32 post_start,
                         u32 post_end,
                         struct bja_lifted_region *out);

bool bpf_jit_validate_region(const struct bpf_prog *prog,
                             const struct bpf_jit_summary *sum,
                             const struct bja_region_rec *cand,
                             struct bja_verified_region *out);

int bpf_jit_emit_region(struct bpf_binary_header *hdr,
                        struct bja_verified_region *vr,
                        void *arch_ctx);
```

The point is:

- one shared lifter;
- one shared validator;
- one arch lowering entry point.

Not:

- one front door per optimization kind.

### Kernel-Only Baseline

The main kernel baseline should still exist:

- verifier-retained summary;
- no userspace regions;
- the kernel locally scans the post-verifier program for regions it knows how to lift.

Userspace regions are then an ablation:

- same kernel validator and lowering path;
- less search work;
- potentially richer offline discovery.

That remains the clean evaluation story.

## Concrete JIT Constraints

R3's practical caveat remains correct: a region consumer is not "just emit one instruction and skip N."

The document should now state the concrete JIT bookkeeping constraints explicitly.

### Per-Instruction Offset Tables Still Matter

Both major JITs keep per-BPF-instruction native offsets:

- x86 uses `addrs[prog->len + 1]`;
- arm64 uses `ctx.offset[prog->len + 1]`.

Those offsets drive:

- branch displacement calculation;
- line-info mapping;
- `BPF_MAP_TYPE_INSN_ARRAY` IP updates.

So a region replacement must still write coherent offset entries for every consumed BPF slot.

In practice, the region emitter can map all interior consumed slots to the region entry address so long as:

- no jump targets land inside the region; and
- the slot after the region points to the address after the emitted native sequence.

### Interior Branch Targets Must Be Rejected

If any jump lands inside a consumed region, collapsing those BPF instructions into a different native sequence will misdirect control flow.

So v1 must reject any region with:

- an interior branch target;
- multiple external entries.

This should be a hard validator rule, not an implementation footnote.

### Faulting Loads Need Extable Discipline

Both x86 and arm64 populate extable entries for faulting probe-style memory operations.

So a region that swallows faulting memory instructions must either:

- recreate matching extable bookkeeping; or
- be rejected.

For v1, rejection is the right rule.

### Calls, Tail Calls, And Exits Are Out Of Scope

Helper calls, tail calls, subprogram calls, and exits carry additional JIT bookkeeping:

- relocatable call handling;
- tail-call patch sites;
- shared epilogue control flow.

So v1 regions should reject any region containing:

- `CALL`
- `TAIL_CALL`
- `EXIT`

Again, that should be explicit in the design.

### Emission Size Must Be Deterministic

x86 iterates until offsets converge, and arm64 does a dry run then a write pass.

So the region emitter must produce deterministic size across passes for the same validated region.

If an optimization has pass-dependent size, it is out of scope for v1.

## Comparison With Optimized Native Code Injection

The native-injection alternative deserves an explicit, sober comparison.

### Kernel LOC

Region replacement needs:

- remap and retained summary;
- region lifter/validator;
- small arch lowerer for the region IR.

Native injection needs:

- remap and retained summary;
- code blob transport;
- machine-code certificate checker or translation validator;
- patching logic that still respects offset tables, CFG, and extable constraints.

So native injection is not lower-LOC in practice unless the kernel simply trusts userspace, which it should not.

### Expressiveness

Native injection wins on raw expressiveness:

- any optimization the userspace compiler can emit becomes possible.

Region replacement is less expressive, but still large enough for many local backend optimizations:

- memory widening;
- scalar fusion;
- rotate and bswap;
- if-conversion;
- bitfield operations.

For this paper, that is enough.

### Safety Model

Region replacement:

- kernel lifts BPF region;
- kernel checks equivalence to candidate IR;
- kernel checks preconditions against retained facts;
- kernel emits code itself.

Native injection:

- kernel must verify arbitrary native code semantics or trust userspace.

That is the decisive difference.

### Trust Model

Region replacement keeps trust low:

- userspace nominates;
- kernel validates;
- kernel emits.

Native injection shifts trust upward unless the proof checker is extremely strong.

### Comparison With v3 Narrow Hint

Compared to v3:

- region replacement is somewhat more kernel work up front;
- but it removes the need to redesign the mechanism for every optimization family.

That is exactly the trade-off the PI asked for.

### Feasibility For A Paper Prototype

Region replacement is feasible for an x86-first prototype.

Native injection is feasible only if the paper becomes primarily about:

- proof-carrying code; or
- translation validation of machine code.

That is too large a pivot for this project.

## Prototype Scope

v4 should separate:

- what the mechanism can support in principle; from
- what the first prototype actually builds.

### v1 In Scope

| Area | v1 decision |
| --- | --- |
| Main mechanism | general optimization region framework |
| Semantics format | small replacement IR |
| Coordinate system | original-range transport, post-verifier remap in-kernel |
| Retained verifier facts | remap + memory facts for constant-offset stack/map-value loads |
| Region topologies | straight-line slice; one compare diamond |
| Architectures | x86-64 first |
| Userspace | optional region discovery and IR synthesis |
| Transport | sealed `memfd` via `hint_fd` as research artifact |
| Initial families | wide-load, select; rotate/bitfield as stretch |
| Paper framing | research prototype, not permanent UAPI |

### Explicitly Out Of Scope For v1

- arbitrary native code injection;
- packet and ctx memory-widening proof;
- stores, atomics, helper calls, tail calls, exits inside optimized regions;
- arbitrary CFG regions beyond straight-line slices and one-diamond regions;
- riscv support;
- upstream-ready UAPI claims.

This keeps the design honest while still making the mechanism general.

## What The Initial Prototype Should Demonstrate

To satisfy the PI's "many optimization types" requirement, the prototype should demonstrate at least two clearly different families that reuse the same mechanism.

The strongest minimum set is:

1. `wide-load` or load-fusion
2. `select` / if-conversion

If schedule allows, the best third family is:

3. `rotate` or bitfield extract

That combination matters because it spans:

- memory legality;
- control-flow compaction;
- pure scalar algebra.

If all three use the same:

- region transport;
- remap;
- region lifter;
- validator;
- arch lowerer,

then the paper has already demonstrated the intended generality.

## Mode 1

Mode 1 remains secondary:

- no-kernel-change deployment fallback;
- comparison point against bytecode-only optimizers;
- negative control showing that bytecode rewriting alone does not erase the backend gap.

The paper center should stay on the kernel mechanism in Mode 2.

## Evaluation Plan

### Main Questions

The revised evaluation should answer:

1. How much backend gap remains after the best bytecode-only optimization?
2. How much of that gap can the general region framework close?
3. Does optional userspace region discovery help beyond kernel-only scanning?
4. How many optimization opportunities fit the existing IR vocabulary without additional kernel changes?
5. How often do candidates fail closed because remap, lifter, or retained-fact validation rejects them?

### Required Baselines

1. Stock kernel JIT
2. Direct kernel peepholes for the same exemplar families
3. Verifier-assisted region JIT without userspace regions
4. Verifier-assisted region JIT with userspace regions
5. Mode 1 only
6. Best bytecode optimizer on the shared subset
7. Best bytecode optimizer + verifier-assisted region JIT
8. llvmbpf oracle

The most important comparison is now:

```text
stock JIT
vs
direct peepholes
vs
verifier-assisted region JIT
vs
verifier-assisted region JIT + userspace regions
```

### Reporting Requirements

The paper should report at least:

- region acceptance counts by family;
- for load-fusion, counts split by memory class:
  - stack
  - map value
- how many candidate regions required no kernel changes because they fit the existing IR vocabulary;
- JIT-time overhead with and without userspace candidates.

### Robustness Tests

Required fail-closed tests:

- stale pre-relocation blob;
- digest mismatch on the submitted pre-verifier image;
- malformed region records;
- range remapping that deletes away completely;
- lifted post-verifier IR mismatch with userspace IR;
- unsatisfied preconditions;
- interior branch target rejection;
- rejected calls, exits, tail calls, or faulting loads inside candidate regions;
- unsupported IR operators.

Success criterion:

- every bad candidate degrades to ordinary JIT lowering;
- no bad candidate changes program semantics;
- no bad candidate can make a previously valid program unloadable.

## Non-Claims

The document should now explicitly avoid these claims:

- "one hint kind is enough for the whole system"
- "safe because advisory only"
- "the retained facts already exist in `bpf_prog_aux`"
- "post-libbpf extraction alone solves verifier drift"
- "packet and ctx memory summaries are solved in v1"
- "native code injection is part of the recommended prototype"
- "`hint_fd` is the intended upstream ABI"

## Bottom Line

The credible v4 design is:

- **Keep the verifier as the legality authority.**
- **Export only a small retained summary: remap plus minimal memory facts.**
- **Replace per-optimization kernel consumers with one general optimization-region mechanism.**
- **Describe replacement semantics with a small target-independent IR, not with narrow hint kinds and not with raw native bytes.**
- **Let userspace discover regions and synthesize IR, but let the kernel re-lift and validate everything against the post-verifier program.**
- **Use `wide-load`, `select`, and optionally `rotate/bitfield` as exemplars of the mechanism, not as the definition of the mechanism.**
- **Treat native code injection as future work, not the mainline design.**

That satisfies the PI's requirement directly:

- minimal kernel changes, because the verifier export and validator are shared;
- maximum expressiveness, because many new optimization regions can be added in userspace as long as they fit the existing region IR and topology rules.
