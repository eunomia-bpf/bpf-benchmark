# BPF JIT Advisor v7: Hybrid Verifier Rewriting and JIT Lowering

Status: definitive v7 design.

This document supersedes the earlier v4, v5, v5r2, and v6 design notes for the BPF JIT Advisor project.
It is the design to implement.

The core decision is:

> Structural program transforms belong in the verifier after legality has been proven.
> Target-specific encoding choices belong in the JIT backend.
> Userspace selects profitability policy for both through one load-time, digest-bound, fail-closed directive interface.

This is a Hybrid design:

- verifier-level structural rewrite for cross-architecture program-shape changes;
- JIT-level target-specific lowering for architecture-dependent encoding choices;
- a narrow shared transport and telemetry substrate bound to one exact pre-verifier BPF image.

Unless stated otherwise, kernel behavior and source-path references refer to the local `vendor/linux/` tree in this repository, especially:

- `vendor/linux/kernel/bpf/syscall.c`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/kernel/bpf/core.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux/arch/arm64/net/bpf_jit_comp.c`

Primary synthesis inputs:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/interface-design-detail.md`
- `docs/tmp/interface-design-review.md`
- `docs/tmp/cross-document-review.md`
- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/tmp/jit-pass-implementation-detail.md`

Design conventions used below:

- "original coordinates" means the exact finalized pre-verifier instruction stream passed in `attr.insns`.
- "post-verifier coordinates" means the instruction stream after verifier late rewrites.
- "subprog-local coordinates" means the instruction stream seen by one `struct bpf_prog` after `jit_subprogs()`.
- "directive" always means a bounded kernel-validated request. It never means arbitrary native code.
- "fail-closed" means malformed or stale inputs fail explicitly, while legality/profitability mismatches reduce to existing stock verifier/JIT behavior.

Non-goals for v7:

- replacing the kernel JIT with LLVM;
- allowing arbitrary code snippets or free-form backend hooks;
- building a second full compiler in the kernel;
- supporting every speculative future directive family in v1;
- solving cross-program transforms such as tail-call specialization in this revision.

## 1. Thesis & Contribution

Sources for this section:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`

### 1.1 Thesis

The v7 thesis is:

> eBPF backend optimization should be split into a stable kernel legality plane and an updateable userspace profitability plane.
> The kernel remains the sole authority on safety, exact image binding, remap, validation, and final code generation.
> Privileged userspace remains the sole authority on whether a legal alternative is actually profitable for a given CPU class, workload class, program shape, and rollout policy.

That split is narrower and more defensible than "userspace controls the compiler backend."
Userspace does not inject native code.
Userspace does not bypass the verifier.
Userspace does not choose arbitrary schedules or register allocations.
Userspace chooses among a bounded set of kernel-defined, kernel-validated transformations.

### 1.2 What The Contribution Is

The contribution is not any single peephole.

The contribution is the combination of:

1. A mechanism/policy split for eBPF backend optimization.
2. A fail-closed kernel substrate that binds directives to one exact BPF image.
3. A Hybrid architecture that assigns structural rewrites to the verifier and target-specific lowering to the JIT.
4. Evidence that profitability varies across CPU class, workload class, and program context strongly enough that fixed in-kernel heuristics are not always the right owner.

`wide_load` matters because it validates the substrate and recovers a large measured gap.
`cmov_select` matters because it is the first policy-sensitive case.
`branch_reorder` matters because it is the first strong non-local structural case that the current JIT cannot honestly express.

The paper claim must remain:

> We do not claim that every backend optimization belongs in userspace.
> We claim that a meaningful subset of backend decisions has stable legality but deployment-specific profitability, and that this subset needs a kernel/userspace split.

### 1.3 What The Contribution Is Not

The contribution is not:

- "we added `wide_load` to the kernel";
- "we added `cmov` support to x86";
- "we created a generic optimizer IR";
- "we proved that userspace should own every backend heuristic";
- "we eliminated the need for LLVM or for kernel-local cleanup passes."

This distinction is not rhetorical.
It determines the falsification condition and the experimental bar.

### 1.4 Mechanism/Policy Separation

v7 fixes the contribution boundary explicitly.

Kernel-owned responsibilities:

- exact image binding via SHA-256 over the pre-verifier instruction stream;
- verifier execution and retained legality facts;
- original-to-post-verifier coordinate remap;
- subprogram-aware plan slicing for `jit_subprogs()`;
- exact stage-specific validators;
- architecture-specific code emission;
- fail-closed fallback and structured telemetry.

Userspace-owned responsibilities:

- candidate discovery over the exact finalized pre-verifier image;
- CPU/workload policy selection;
- code-size and deployment-budget policy;
- rollout, rollback, and canarying;
- interpretation of structured telemetry.

This is the core system split.

### 1.5 Why This Is Not "Just Add Kernel Peepholes"

This is the most obvious attack, so v7 answers it directly.

The honest answer is asymmetric:

- `wide_load` by itself does look like a kernel peephole.
- `wide_store`, `rotate_fusion`, and `lea_fusion` also look like ordinary backend cleanups when considered in isolation.
- v7 does not deny that.

The framework is still justified only if all three of the following are true:

1. At least one supported directive family is genuinely policy-sensitive.
   - `cmov_select` is the minimal case because the better lowering depends on branch predictability, dependency depth, and CPU family.
2. At least one supported directive family is structurally beyond the current JIT-level peephole layer.
   - `branch_reorder` is the key case because it requires CFG-aware permutation at the BPF level.
3. Fixed kernel baselines do not recover the same gains across the tested workload and hardware matrix.
   - this is the mandatory falsification condition.

If condition 3 fails, the correct conclusion is "use kernel patches or kernel-only policy."
v7 makes that explicit.

### 1.6 Why This Is Not "Just Use llvmbpf"

This is the second major attack, and the correct answer is not "LLVM is bad."

LLVM or llvmbpf is a simpler answer if a deployment can replace the kernel JIT backend outright.
v7 matters only because a large class of real BPF deployments cannot or will not do that.

The reasons to preserve the kernel JIT model are:

- the kernel verifier and JIT already define the trusted execution path for BPF deployment;
- existing production loaders, attach points, map ownership, and verifier semantics are built around `BPF_PROG_LOAD`;
- deployment operators want incremental adoption without replacing the kernel execution model;
- some legality facts exist only after the kernel verifier has classified pointers, pruned dead paths, finalized subprogram structure, and applied kernel-specific late rewrites.

So the v7 claim is complementary to llvmbpf:

- LLVM remains an upper-bound backend and an important baseline;
- v7 preserves the kernel JIT ownership model while importing deployment-specific profitability policy.

### 1.7 Evidence That Policy Can Vary

The design is not motivated by vague intuition.
The evidence base already contains concrete policy-sensitive signals:

| Signal | Evidence | Why it matters |
| --- | --- | --- |
| `cmov` is not uniformly profitable | `no-cmov` ablation changes sign across benchmarks | one legal lowering does not dominate everywhere |
| branch layout changes with input distribution | `branch_layout` predictable vs random differs materially | workload matters, not just ISA |
| real programs are structurally diverse | 36 unique real-program corpus, 14 exec-time cases, high subprog prevalence | fixed one-size-fits-all local heuristics are suspect |
| the strongest future transforms are non-local | `branch_reorder`, `bounds_window`, `packet_ctx_wide_load`, future `subprog_inline` | the current linear JIT is not the right layer for all of them |

This is why v7 moves away from a pure Path A story.

### 1.8 OSDI/SOSP Claim

The claim v7 is willing to defend is:

> BPF JIT Advisor provides a safe load-time interface for userspace-guided backend optimization in which verifier-owned structural rewrites and JIT-owned target-specific lowering are separated, image-bound, and fail closed.

The claim v7 will not defend is:

> every backend gap should be fixed by userspace guidance.

That narrower claim is stronger.

## 2. Hybrid Architecture

Sources for this section:

- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/tmp/jit-pass-implementation-detail.md`
- `docs/tmp/interface-design-review.md`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/kernel/bpf/core.c`
- `vendor/linux/kernel/bpf/syscall.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`

### 2.1 Design Summary

The v7 architecture has two explicit layers:

1. Verifier structural rewrite layer.
   - consumes directives that change BPF program shape;
   - operates on BPF instructions after legality facts are known;
   - is cross-architecture by construction because it rewrites BPF, not native code.
2. JIT target-specific lowering layer.
   - consumes directives that choose one native lowering among multiple legal lowerings;
   - operates inside the existing backend convergence loop;
   - is architecture-specific by definition.

The same load-time blob can contain both classes.
The kernel handles them at different stages.

### 2.2 Why Hybrid

#### Pure Path A Is Too Narrow

Pure Path A means:

- parse directives once;
- remap them after verification;
- consume them only inside `do_jit()`.

That works for:

- local multi-insn fusion;
- one-entry, one-exit diamonds that collapse to one native region.

It does not work naturally for:

- CFG permutation;
- block duplication;
- interprocedural transforms;
- anything that wants multiple native regions or multiple canonical PCs for one original interval.

The x86 backend in `vendor/linux/arch/x86/net/bpf_jit_comp.c` is a linear emitter over original BPF order.
It relies on `addrs[]` convergence and adjacent-index size reasoning.
That is the wrong abstraction for real layout transforms.

#### Pure Path B Is Also Incomplete

Pure Path B means:

- do all interesting optimization by rewriting BPF in the verifier;
- hand the resulting BPF to the stock JIT.

That is attractive for:

- `branch_reorder`;
- `bounds_window`;
- `packet_ctx_wide_load`;
- future `subprog_inline`.

But it cannot fully replace the JIT layer because some profitable choices are fundamentally target-specific:

- x86 `cmovcc` vs arm64 `csel` vs keeping a branch;
- x86 `lea` fusion;
- x86 rotate/BMI2 idioms;
- short encoding choices and backend-specific materialization details.

Pure Path B would either lose those choices or force target-specific semantics back into verifier rewriting.

#### Hybrid Keeps Each Layer At The Right Abstraction

Hybrid therefore makes the split explicit:

- verifier rewrites BPF structure;
- JIT chooses native lowering.

This is the smallest architecture that can honestly support both:

- the strong novelty-carrying structural cases;
- the target-specific policy-sensitive lowering cases.

### 2.3 The Two Layers

#### Layer 1: Verifier Structural Rewrite

Layer-1 directives:

- consume original-coordinate site requests after the verifier has proven legality;
- match on post-analysis BPF regions while pointer class, CFG shape, stack/call structure, and readable-window facts are still available;
- rewrite the BPF instruction stream itself;
- hand the rewritten program to later kernel lowering passes.

Layer-1 is the right place for:

- `bounds_window`;
- `packet_ctx_wide_load`;
- `branch_reorder`;
- the verifier-recognition half of `cmov_select`;
- future `subprog_inline`.

#### Layer 2: JIT Target-Specific Lowering

Layer-2 directives:

- operate only after verifier rewrites have completed;
- see the final post-verifier BPF stream, possibly already normalized by layer 1;
- choose a target-specific native lowering;
- must be deterministic across dry passes and the final image pass.

Layer-2 is the right place for:

- `wide_load`;
- `wide_store`;
- `rotate_fusion`;
- `lea_fusion`;
- the JIT-lowering half of `cmov_select`.

### 2.4 Exact Kernel Placement

The precise placement matters because v7 is intentionally designed around the real kernel pipeline, not a simplified two-pass story.

The relevant verifier and runtime path today is:

1. `bpf_prog_load()` in `vendor/linux/kernel/bpf/syscall.c`
2. `bpf_check()` in `vendor/linux/kernel/bpf/verifier.c`
3. inside `bpf_check()`:
   - subprogram discovery and CFG checks;
   - `do_check_main()` and `do_check_subprogs()`;
   - `remove_fastcall_spills_fills()`;
   - `check_max_stack_depth()`;
   - `optimize_bpf_loop()`;
   - dead-code cleanup (`opt_hard_wire_dead_code_branches()`, `opt_remove_dead_code()`, `opt_remove_nops()` for privileged loads; `sanitize_dead_code()` otherwise);
   - `convert_ctx_accesses()`;
   - `do_misc_fixups()`;
   - `opt_subreg_zext_lo32_rnd_hi32()`;
   - `fixup_call_args()`, which calls `jit_subprogs()` if JIT is requested.
4. `bpf_prog_select_runtime()` in `vendor/linux/kernel/bpf/core.c`
5. `bpf_int_jit_compile()` in `vendor/linux/arch/x86/net/bpf_jit_comp.c`
6. constant blinding inside `bpf_int_jit_compile()` through `bpf_jit_blind_constants()`
7. repeated dry `do_jit()` passes until convergence
8. final image-emission `do_jit()` pass

v7 inserts its two stages into that real flow as follows.

#### Stage 1: Verifier Rewrite Insertion Point

Stage-1 directives execute:

- after `do_check_main()` and `do_check_subprogs()`;
- after dead-code cleanup;
- before `convert_ctx_accesses()`;
- before `do_misc_fixups()`.

That placement is mandatory for the following reasons:

- the verifier already knows pointer class, readable ranges, CFG, SCC structure, and subprogram boundaries at that point;
- dead paths are already removed, simplifying region matching;
- later kernel rewrite passes should see the rewritten BPF, not the original shape;
- `convert_ctx_accesses()` and `do_misc_fixups()` are themselves late-lowering passes and should continue to own their existing semantics on the rewritten program.

This corresponds directly to the existing comment in `vendor/linux/kernel/bpf/verifier.c`:

`/* instruction rewrites happen after this point */`

and to the existing order around `optimize_bpf_loop()`.

#### Stage 2: JIT Lowering Insertion Point

Stage-2 directives execute inside `do_jit()`, but only after a stable plan has been prepared.

That means:

- original coordinates are remapped after verifier rewriting is complete;
- legality validation happens before any backend pass consumes the plan;
- the backend sees only a stable per-subprog plan table;
- every dry pass and the final image pass consume exactly the same plan.

No stage-2 matcher may opportunistically rediscover windows inside `do_jit()`.
That would break convergence and turn pass-count variation into a correctness bug.

### 2.5 Existing Verifier Rewrite Precedent

v7 does not invent verifier rewriting from scratch.

The existing verifier already performs substantial late rewrites:

- `bpf_patch_insn_data()` is used from 31 call sites in `vendor/linux/kernel/bpf/verifier.c`;
- `optimize_bpf_loop()` and `inline_bpf_loop()` already perform a non-local structural transform;
- `convert_ctx_accesses()` rewrites context loads/stores into ordinary BPF memory operations and probe forms;
- `do_misc_fixups()` rewrites helpers, tail calls, and speculation-hardening sequences;
- dead-code cleanup already deletes and rewrites instructions after legality proof.

So the v7 claim is not "the verifier can rewrite BPF."
That is already true.
The v7 claim is:

> userspace-guided structural transforms should join that existing late-rewrite phase, under explicit bounded validators.

### 2.6 Why `branch_reorder` Moves To The Verifier

`branch_reorder` is the strongest proof that Hybrid is necessary.

The current x86 backend:

- emits in original BPF order;
- resolves branches through `addrs[]`;
- assumes a monotonic original-order boundary table;
- has no CFG builder or block placer.

That makes true block reordering unnatural inside `do_jit()`.

The verifier, by contrast, already has:

- CFG validity;
- SCC information;
- subprogram boundaries;
- proof state at branch points;
- late rewrite machinery.

Therefore v7 freezes `branch_reorder` as a verifier-stage transform:

- v1 supports only one-entry, one-join diamond permutation;
- v1 does not duplicate instructions;
- v1 does not allow open-region layout transforms;
- v1 does not redefine canonical-PC semantics.

That design is much smaller and much safer than a JIT-local block placer.

### 2.7 Why `cmov_select` Is Hybrid

`cmov_select` sits exactly on the abstraction boundary.

The verifier is the right place to recognize:

- the entry compare;
- the two assignment arms;
- the unique join;
- the lack of side effects.

The JIT is the right place to choose:

- x86 `cmovcc`;
- arm64 `csel`;
- or a retained branch sequence when the policy or backend says not to use a select.

So v7 defines `cmov_select` as:

- verifier-stage recognition plus normalization to an internal select abstraction;
- JIT-stage lowering choice per target.

This is the first truly Hybrid directive.

### 2.8 Constant Blinding Under Hybrid

v6 and the interface draft treated constant blinding as a whole-blob cutoff because a pure JIT-level scheme could not safely carry directive provenance through the blinding clone.

Hybrid changes that substantially.

The new rule is:

1. Verifier-stage directives run before blinding.
2. Constant blinding then runs on the already rewritten BPF program.
3. JIT-stage directives are handled per directive family:
   - pure local fusion directives that depend on raw post-verifier instruction shape are disabled when blinding rewrites that shape;
   - Hybrid directives whose stage-2 plans are keyed by BPF instruction indices need an explicit rebase through the `bpf_jit_blind_constants()` rewrites before they can lower after blinding.

Implications:

- `bounds_window`, `packet_ctx_wide_load`, and `branch_reorder` are no longer blocked by blinding, because their work is already reflected in rewritten BPF before the clone is created.
- `wide_load`, `wide_store`, `rotate_fusion`, and `lea_fusion` are still disabled on the blinded path in v1, because blinding rewrites the immediate-bearing or local-shape assumptions those JIT matchers rely on.
- `cmov_select` is also disabled on the blinded path in v1, because copied side state alone would not rebase the normalized select plan onto the rewritten blinded instruction stream.

So Hybrid does not magically eliminate blinding complexity.
It does remove the v6 failure mode where the entire advisory blob had to be dropped.

### 2.9 Multi-Subprog Handling

The existing kernel pipeline for multi-function programs is a decisive design constraint.

`jit_subprogs()` in `vendor/linux/kernel/bpf/verifier.c`:

- slices one verified program into per-subprog `struct bpf_prog` objects;
- JITs each subprogram once;
- patches pseudo-call targets to final addresses;
- JITs each subprogram again.

v7 therefore makes subprogram handling explicit:

1. All directive records use original whole-program coordinates plus an original `subprog_id`.
2. Verifier-stage directives run on the whole program before `jit_subprogs()`.
3. JIT-stage directives are first validated in whole-program post-verifier coordinates.
4. Immediately before subprog JIT begins, the validated JIT-stage plan is sliced by subprogram boundary and rebased to subprog-local coordinates.
5. Each `func[i]->aux` receives only the plans that lie entirely inside that subprogram.
6. The same sliced plan is reused for both JIT passes of that subprogram.

No JIT-stage directive may cross a subprogram boundary in v1.

### 2.10 Hybrid Invariants

The following invariants are mandatory:

1. The kernel never trusts userspace-supplied post-verifier coordinates.
2. All verifier rewrites happen on the exact program that was digest-bound before load.
3. All JIT-stage plans are stable before the first backend dry pass.
4. No JIT-stage directive may cause pass-dependent acceptance.
5. No v1 directive may duplicate BPF instructions.
6. No v1 directive may cross a subprogram boundary.
7. The fallback for a rejected stage is always stock behavior for that stage.
8. Structural rewrites never bypass later stock verifier fixups.

Those invariants are what make the design reviewable.

## 3. Interface Design

Sources for this section:

- `docs/tmp/interface-design-detail.md`
- `docs/tmp/interface-design-review.md`
- `docs/tmp/cross-document-review.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/tmp/jit-pass-implementation-detail.md`
- `vendor/linux/kernel/bpf/syscall.c`
- `vendor/linux/kernel/bpf/core.c`
- `vendor/linux/kernel/bpf/verifier.c`

### 3.1 Design Goals

The v7 interface keeps the parts of the interface draft that survived review:

- one load-time transport carried through `BPF_PROG_LOAD`;
- exact-image digest binding;
- bounded binary format with explicit versioning;
- one advisory blob per load;
- structured telemetry and fail-closed behavior.

The interface changes the parts that did not survive review:

- it models the real kernel pipeline, including `jit_subprogs()` and the JIT convergence loop;
- it adds an explicit stage dimension;
- it makes multi-subprog slicing first-class;
- it states the `addrs[]` collapse rule;
- it tightens signedness, compatibility, and reason-code semantics.

### 3.2 Syscall Extension

The UAPI keeps the historical `jit_directives_*` naming even though some directives are consumed in the verifier.
That naming is acceptable because the interface still belongs to the backend optimization path of `BPF_PROG_LOAD`.

```c
/* prog_flags bit: jit_directives_fd/jit_directives_flags are valid */
#define BPF_F_JIT_DIRECTIVES_FD (1U << 20)

enum bpf_jit_directives_load_flags {
	BPF_F_JIT_DIRECTIVES_STRICT_CPU = (1U << 0),
	BPF_F_JIT_DIRECTIVES_LOG        = (1U << 1),
};

union bpf_attr {
	struct { /* BPF_PROG_LOAD */
		/* existing fields omitted */
		__aligned_u64 signature;
		__u32         signature_size;
		__s32         keyring_id;

		/*
		 * Sealed memfd containing one Hybrid directive blob.
		 * Valid only when prog_flags has BPF_F_JIT_DIRECTIVES_FD.
		 */
		__s32         jit_directives_fd;
		__u32         jit_directives_flags;
	};
};
```

The gate bit remains mandatory.
Old callers with zeroed tail bytes must not accidentally look like `fd=0`.

### 3.3 Transport Choice

v7 keeps a sealed `memfd` transport.

The review correctly noted that pointer-plus-length copied at syscall entry would also work.
The reason v7 still chooses `memfd` is not parser convenience.
It is deployment composition.

The loader, advisor sidecar, and policy manager may be distinct components.
Sealed `memfd` gives them:

- a kernel-verifiable immutable object;
- explicit sealing semantics instead of implicit copy-at-entry assumptions;
- a simple ownership model across cooperating privileged processes;
- no pathname dependency and no post-load lifetime.

The kernel still copies the blob into kernel memory exactly once and then detaches from the FD.
The `memfd` is transport, not storage.

Required seals:

- `F_SEAL_WRITE`
- `F_SEAL_GROW`
- `F_SEAL_SHRINK`

`F_SEAL_SEAL` is accepted but not required.

### 3.4 Authorization

For the v7 research prototype, the privilege rule remains:

- `CAP_BPF`
- plus `CAP_PERFMON`
- or a token-delegated equivalent with the same effective boundary.

This is still a prototype-facing rule, not a claim that the final upstream privilege model has been completely settled.
v7 keeps it because:

- the interface changes performance and speculation shape;
- it is not a harmless hint channel;
- it belongs on the same privilege side of the line as other privileged BPF execution control.

### 3.5 Error Model

v7 keeps the interface-draft split between:

- fatal protocol/load errors;
- non-fatal fail-closed stage rejection.

It changes the errno assignment to remove ambiguity.

Fatal errors:

| Condition | errno |
| --- | --- |
| gate bit set but invalid FD | `EBADF` or `EINVAL` |
| FD not a correctly sealed `memfd` | `EINVAL` |
| malformed blob, bad offsets, reserved bytes non-zero | `EINVAL` |
| unsupported blob ABI major or unsupported directive kind/version | `EOPNOTSUPP` |
| digest mismatch or `orig_insn_cnt` mismatch | `EINVAL` |
| authorization failure | `EPERM` |
| strict CPU mismatch | `EOPNOTSUPP` |
| blob or record too large | `EFBIG` |

Compatibility-only retry conditions:

- `E2BIG` remains reserved for old-kernel `bpf_attr` size negotiation behavior.
- loaders should not treat `EFBIG` as a capability-probe retry.

Non-fatal outcomes:

- stage-specific reject or drop;
- per-site fallback to stock behavior;
- structured telemetry reporting that the advisory path ran but was not adopted.

### 3.6 Blob Layout

The top-level layout remains compact and little-endian:

```text
+------------------------------+
| blob header                  |
+------------------------------+
| CPU contract                 |
+------------------------------+
| directive record 0           |
+------------------------------+
| 0-7 bytes zero padding       |
+------------------------------+
| directive record 1           |
+------------------------------+
| ...                          |
+------------------------------+
```

Global invariants:

- entire blob is little-endian;
- `total_len <= 64 * 1024`;
- all offsets are within `total_len`;
- all sections are 8-byte aligned;
- all reserved bytes are zero;
- records are sorted by `(subprog_id, stage, orig_start_off, orig_end_off)`;
- original ranges are non-overlapping inside one `(subprog_id, stage)` space;
- each record names exactly one subprogram and one original contiguous range.

The last invariant is deliberate.
v7 still does not encode discontiguous or cross-subprog records in v1.

### 3.7 Blob Header

The header is inherited from the interface draft with only editorial tightening.

```c
#define BPF_JIT_DIR_BLOB_MAGIC     0x424a4156U /* "BJAV" */
#define BPF_JIT_DIR_BLOB_ABI_MAJOR 1
#define BPF_JIT_DIR_BLOB_ABI_MINOR 1
#define BPF_JIT_DIR_BLOB_MAX_LEN   (64 * 1024)
#define BPF_JIT_DIR_MAX_RECORDS    1024
#define BPF_JIT_DIR_MAX_REC_LEN    256

enum bpf_jit_blob_endian {
	BPF_JIT_BLOB_LE = 1,
};

struct bpf_jit_dir_blob_hdr_v1 {
	__le32 magic;
	__le16 abi_major;
	__le16 abi_minor;
	__le16 hdr_len;
	__le16 endian;
	__le32 total_len;
	__le32 flags;
	__le32 nr_directives;
	__le32 orig_insn_cnt;
	__u8   prog_digest[32];
	__le32 cpu_off;
	__le32 cpu_len;
	__le32 dir_off;
	__le32 dir_len;
	__le32 reserved[3];
}; /* 88 bytes */
```

The minor version increments from the earlier draft because the record semantics are revised.
The draft was never shipped, so v7 treats this as a documentation cleanup rather than a compatibility burden.

### 3.8 CPU Contract

The CPU contract survives almost unchanged because it is orthogonal to Path A versus Hybrid.

```c
enum bpf_jit_arch {
	BPF_JIT_ARCH_X86_64 = 1,
	BPF_JIT_ARCH_ARM64  = 2,
};

enum bpf_jit_cpu_vendor {
	BPF_JIT_CPU_VENDOR_UNKNOWN = 0,
	BPF_JIT_CPU_VENDOR_INTEL   = 1,
	BPF_JIT_CPU_VENDOR_AMD     = 2,
	BPF_JIT_CPU_VENDOR_ARM     = 3,
};

enum bpf_jit_cpu_contract_flags {
	BPF_JIT_CPU_F_MATCH_MODEL_SET     = (1U << 0),
	BPF_JIT_CPU_F_MATCH_STEPPING      = (1U << 1),
	BPF_JIT_CPU_F_REQUIRE_HOMOGENEOUS = (1U << 2),
};

struct bpf_jit_cpu_contract_v1 {
	__le32 arch;
	__le32 vendor;
	__le32 family;
	__le32 model;
	__le32 stepping_mask;
	__le32 flags;
	__le64 required_features[2];
	__le64 forbidden_features[2];
	__le64 policy_id;
	__le32 policy_version;
	__le32 workload_class;
}; /* 72 bytes */
```

Semantics:

- `arch`, `required_features`, and `forbidden_features` are correctness-relevant;
- `policy_id`, `policy_version`, and `workload_class` are telemetry tags;
- heterogeneous systems still require a lowest-common-denominator contract or explicit outside-the-kernel placement control.

### 3.9 Stage Dimension

The earlier interface draft had no explicit stage field.
v7 adds one.

```c
enum bpf_jit_stage {
	BPF_JIT_STAGE_VERIFIER_REWRITE = 1,
	BPF_JIT_STAGE_JIT_LOWERING     = 2,
};
```

The stage dimension exists because Hybrid uses two consumers with different legality vocabularies:

- verifier rewrite cares about CFG shape, pointer class, readable windows, and structural invariants;
- JIT lowering cares about a stable post-verifier instruction interval, backend legality, and pass-stable native emission.

### 3.10 Record Header

The record header keeps the same overall size as the interface draft while making stage explicit.

```c
struct bpf_jit_dir_rec_hdr_v1 {
	__le16 kind;
	__u8   kind_version;
	__u8   hdr_len;
	__le16 rec_len;
	__u8   stage;          /* enum bpf_jit_stage */
	__u8   rec_flags;      /* zero in v1 */
	__le32 site_id;
	__le16 subprog_id;
	__u8   reserved0[2];
	__le32 orig_start_off;
	__le32 orig_end_off;   /* exclusive */
	__le32 precond_mask;
	__le32 reserved1;
	__le64 required_features[2];
	__le64 forbidden_features[2];
}; /* 64 bytes */
```

The record still does not claim to encode the full validator contract.
It encodes only:

- the requested site identity;
- the requested stage;
- the userspace-side parameters;
- the CPU filters.

Kernel-side validation still depends on:

- `orig_idx` remap;
- retained verifier facts;
- CFG and liveness checks;
- subprog slicing;
- backend-specific constraints such as `addrs[]`.

### 3.11 Shared Precondition Bits

v7 keeps the shared precondition mask, but explicitly stops pretending it is sufficient by itself.

```c
enum bpf_jit_precond_bits {
	BPF_JIT_PC_STRAIGHT_LINE        = (1U << 0),
	BPF_JIT_PC_ONE_DIAMOND          = (1U << 1),
	BPF_JIT_PC_NO_INTERIOR_TARGET   = (1U << 2),
	BPF_JIT_PC_NO_CALLS             = (1U << 3),
	BPF_JIT_PC_NO_STORES            = (1U << 4),
	BPF_JIT_PC_CONST_OFFSET_MEM     = (1U << 5),
	BPF_JIT_PC_SAME_BASE_MEM        = (1U << 6),
	BPF_JIT_PC_NO_PROBE_OR_EXTABLE  = (1U << 7),
	BPF_JIT_PC_NO_TAILCALL_OR_POKE  = (1U << 8),
};
```

Interpretation:

- these are shared structural expectations, not proof objects;
- verifier-stage directives use them only as cheap shape hints;
- JIT-stage directives use them only as summary filters before exact validation.

### 3.12 Directive Kinds

The v7 frozen directive namespace is:

```c
enum bpf_jit_dir_kind {
	BPF_JIT_DIR_WIDE_LOAD           = 1,
	BPF_JIT_DIR_CMOV_SELECT         = 2,
	BPF_JIT_DIR_WIDE_STORE          = 3,
	BPF_JIT_DIR_ROTATE_FUSION       = 4,
	BPF_JIT_DIR_LEA_FUSION          = 5,
	BPF_JIT_DIR_BOUNDS_WINDOW       = 6,
	BPF_JIT_DIR_PACKET_CTX_WIDE_LOAD = 7,
	BPF_JIT_DIR_BRANCH_REORDER      = 8,
};
```

Kinds intentionally not frozen in v1 are listed in Section 4.4.

### 3.13 Signedness Fixes

The interface review identified two real wire-format mismatches in the earlier draft.
v7 fixes them:

- offsets are signed when negative values are meaningful;
- immediates are signed when negative values are meaningful.

That means:

- `base_off` fields use `__s16` / `__le16` interpreted as signed;
- immediate-carrying payload fields use `__s32` or `__s64` as appropriate.

No v7 payload relies on "unsigned on the wire, signed by convention."

### 3.14 Digest Binding

Digest binding remains unchanged in principle.

The kernel hashes:

```text
SHA-256(attr.insn_cnt * sizeof(struct bpf_insn) bytes)
```

More precisely:

1. copy `attr.insns` into kernel memory;
2. copy the sealed blob into kernel memory;
3. parse the blob;
4. check `orig_insn_cnt`;
5. hash the copied instruction array;
6. compare `prog_digest`;
7. only then run verifier rewriting.

This preserves the key v5r2/v6 property:

- directives are bound to the exact pre-verifier image userspace analyzed.

It also means:

- maps are included only through their pseudo-insn bytes;
- BTF and CO-RE are included only through their materialized instruction bytes;
- there is no meaningful TOCTOU window once the kernel has taken both copies.

### 3.15 Real Pipeline Model

v7 replaces the earlier "verify, remap, emit/fallback" simplification with the actual stage model.

```text
userspace finalized BPF image
  -> sealed memfd blob
  -> BPF_PROG_LOAD
  -> kernel copies insns
  -> kernel copies and parses blob
  -> digest and CPU precheck
  -> verifier do_check_*()
  -> dead-code cleanup
  -> apply VERIFIER_REWRITE directives
  -> convert_ctx_accesses()
  -> do_misc_fixups()
  -> opt_subreg_zext_lo32_rnd_hi32()
  -> prepare JIT_LOWERING plans on final post-verifier program
  -> fixup_call_args()
     -> jit_subprogs() if needed
        -> slice plan per subprog
        -> first JIT pass per subprog
        -> patch pseudo calls
        -> second JIT pass per subprog
  -> bpf_prog_select_runtime()
  -> constant blinding if requested
  -> do_jit() convergence loop
  -> final image pass
```

This model is mandatory because:

- `jit_subprogs()` is not optional detail;
- x86 is a convergence loop, not a one-shot emitter;
- stage-2 directives must survive two JIT passes for subprograms and multiple dry passes for each JIT.

### 3.16 Multi-Subprog Plan Slicing

The precise v7 rule is:

1. Records are submitted in original whole-program coordinates and original `subprog_id`.
2. After verifier rewriting, the kernel remaps each record to a whole-program post-verifier interval.
3. JIT-stage records whose remapped interval is empty, non-contiguous, or crosses a post-verifier subprogram boundary are rejected.
4. For each surviving JIT-stage record, the kernel rebases its `[post_start_off, post_end_off)` into subprog-local coordinates before the first `bpf_int_jit_compile()` of that subprog.
5. Telemetry records both:
   - whole-program post-verifier coordinates;
   - subprog-local execution if needed for debugging.

This is the missing mechanism piece from the interface draft.

### 3.17 `addrs[]` Collapse Rule

For any JIT-stage fused directive that replaces a contiguous BPF interval `[start, end)` with one native region:

- `addrs[start]` is the native start of the fused region;
- for each covered instruction `k` with `start < k < end`, set `addrs[k] = addrs[start]`;
- `addrs[end]` is the native boundary of the first uncovered instruction;
- any outside edge targeting an interior instruction `k` with `start < k < end` is a hard rejection.

This rule is what gives `BPF_JIT_PC_NO_INTERIOR_TARGET` its concrete meaning.

It also explains why v1 excludes duplication and true layout-changing JIT directives:

- tooling can tolerate many BPF PCs mapping to one native PC;
- control flow cannot tolerate a branch landing on a collapsed interior boundary.

### 3.18 Result Telemetry

The earlier interface draft had only `accepted`, `dropped`, and `rejected`.
Hybrid needs stage-aware results.

```c
enum bpf_jit_dir_status {
	BPF_JIT_DIR_STATUS_APPLIED  = 0,
	BPF_JIT_DIR_STATUS_DROPPED  = 1,
	BPF_JIT_DIR_STATUS_REJECTED = 2,
};

enum bpf_jit_dir_reason {
	BPF_JIT_DIR_REASON_OK = 0,
	BPF_JIT_DIR_REASON_DROP_CPU_MISMATCH,
	BPF_JIT_DIR_REASON_DROP_JIT_DISABLED,
	BPF_JIT_DIR_REASON_DROP_CONST_BLINDING,
	BPF_JIT_DIR_REASON_REMAP_EMPTY,
	BPF_JIT_DIR_REASON_REMAP_NONCONTIG,
	BPF_JIT_DIR_REASON_REMAP_CROSS_SUBPROG,
	BPF_JIT_DIR_REASON_FACT_MISSING,
	BPF_JIT_DIR_REASON_PRECOND_MISMATCH,
	BPF_JIT_DIR_REASON_TEMPLATE_MISMATCH,
	BPF_JIT_DIR_REASON_TEMP_LIVEOUT,
	BPF_JIT_DIR_REASON_PROBE_MEM_OR_EXTABLE,
	BPF_JIT_DIR_REASON_TAIL_CALL_OR_POKE_SITE,
	BPF_JIT_DIR_REASON_SPEC_HARDENING_REGION,
	BPF_JIT_DIR_REASON_CPU_FEATURE_MISMATCH,
	BPF_JIT_DIR_REASON_ARCH_UNSUPPORTED,
	BPF_JIT_DIR_REASON_EMIT_FAILED,
};

struct bpf_jit_dir_result_v1 {
	__u32 site_id;
	__u16 kind;
	__u8  stage;     /* enum bpf_jit_stage */
	__u8  status;    /* enum bpf_jit_dir_status */
	__u32 reason;    /* enum bpf_jit_dir_reason */
	__u32 subprog_id;
	__u32 orig_start_off;
	__u32 orig_end_off;
	__u32 post_start_off;
	__u32 post_end_off;
}; /* 32 bytes */
```

Interpretation:

- verifier-stage success produces `stage=VERIFIER_REWRITE, status=APPLIED`;
- verifier-stage rejection produces `stage=VERIFIER_REWRITE, status=REJECTED`;
- JIT-stage success produces `stage=JIT_LOWERING, status=APPLIED`;
- JIT-stage reject or blinding drop produces `stage=JIT_LOWERING, status=REJECTED` or `DROPPED` with a reason.

This is how v7 exposes:

- rewritten-in-verifier;
- accepted-in-JIT;
- rejected-in-verifier;
- rejected-in-JIT.

### 3.19 Logging Interface

Two channels remain:

1. Text appended to the existing verifier log when `BPF_F_JIT_DIRECTIVES_LOG` is set.
2. Structured result records through `bpf_prog_info`.

Representative log lines:

```text
jitdir: site=42 kind=CMOV_SELECT stage=VERIFIER_REWRITE subprog=1 orig=[153,158) post=[161,166) status=applied
jitdir: site=42 kind=CMOV_SELECT stage=JIT_LOWERING subprog=1 post=[161,166) status=applied reason=OK
jitdir: site=17 kind=WIDE_LOAD stage=JIT_LOWERING subprog=0 orig=[30,52) status=rejected reason=TEMP_LIVEOUT
jitdir: site=91 kind=BRANCH_REORDER stage=VERIFIER_REWRITE subprog=0 orig=[220,231) status=rejected reason=PRECOND_MISMATCH
```

The structured `bpf_prog_info` extension remains the production interface.
The text path is for human debugging.

### 3.20 Compatibility And Probing

v7 keeps the retry-without-directives fallback, but narrows its use:

```text
first attempt: load with directives
if errno in { E2BIG, EOPNOTSUPP } and the loader has not cached support state:
    mark kernel as lacking this UAPI or this ABI/kind set
    retry once without directives
else:
    surface the real error
```

Important changes from the draft:

- `EFBIG` now means "your blob is too large"; do not silently retry.
- loaders should cache the support result per kernel build or boot session instead of probing on every load.
- exact-image digest binding means the entity that finalizes the pre-verifier image must also create the blob or invoke a sidecar that sees that exact image.

That last point is essential.
The interface is not loader-agnostic.
It is loader-aware by design.

## 4. v1 Directive Set (Frozen Scope)

Sources for this section:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`
- `docs/tmp/cross-document-review.md`
- `docs/tmp/jit-pass-implementation-detail.md`

v7 freezes the v1 scope here.
Anything not named in this section is not part of v1, even if it appears elsewhere in earlier drafts.

The split is deliberate:

- JIT-level directives validate the local-fusion substrate and give immediate x86-first breadth.
- verifier-level directives justify the structural-rewrite half of Hybrid.
- Hybrid directives show where verifier recognition and backend lowering genuinely need both layers.

### 4.1 JIT-Level v1 Directives

These directives are consumed in `do_jit()` after a stable plan has already been built.
They must fit the current convergence-loop backend model.

#### `wide_load`

- Meaning: fuse an adjacent byte-load recomposition ladder into one native-width load.
- Scope: stack and map-value ladders only in v1.
- Role in the paper: substrate exercise and baseline-gap recovery, not the novelty anchor.
- Why JIT-level in v1: the x86 implementation is mature, the `addrs[]` behavior is clear, and it validates the pass-stable local fusion path.

#### `wide_store`

- Meaning: fuse adjacent byte stores into one wider native store.
- Scope: stack and map-value stores only in v1.
- Role: low-risk breadth directive that shows the substrate is not special-cased to loads.
- Why JIT-level in v1: the contract matches `wide_load`, and the main value is local code-size recovery.

#### `rotate_fusion`

- Meaning: fuse a shift/shift/or rotate idiom into `rorx`, `rol`, or `ror`.
- Scope: immediate rotate amounts only in v1.
- Role: target-specific idiom with clear x86 payoff and explicit feature gating.
- Why JIT-level in v1: BPF has no rotate instruction, so the value is in native encoding choice.

#### `lea_fusion`

- Meaning: fuse a `mov` plus add/shift/address arithmetic chain into x86 `lea`.
- Scope: encodings representable as one x86 `lea` in v1.
- Role: classic backend combine that broadens the local-fusion substrate.
- Why JIT-level in v1: `lea` is a target-specific encoding choice, not a BPF-level semantic transform.

JIT-level v1 summary:

| Directive | Stage | v1 Scope | Cross-arch status |
| --- | --- | --- | --- |
| `wide_load` | `JIT_LOWERING` | stack/map-value byte ladders | x86 implemented first |
| `wide_store` | `JIT_LOWERING` | stack/map-value byte stores | x86 implemented first |
| `rotate_fusion` | `JIT_LOWERING` | immediate rotate idioms | x86 only in v1 |
| `lea_fusion` | `JIT_LOWERING` | encodable address arithmetic chains | x86 only in v1 |

### 4.2 Verifier-Level v1 Directives

These directives are consumed after `do_check_*()` and dead-code cleanup, before `convert_ctx_accesses()` and `do_misc_fixups()`.

#### `bounds_window`

- Meaning: remove one redundant packet or context bounds guard when the immediately guarded access already has a verifier-retained readable-window fact at that access site and no proof-relevant state changes intervene.
- Scope: one guard plus one immediately following protected access in v1; not arbitrary ladder elimination.
- Role: the first retained-fact structural rewrite.
- Why verifier-level: correctness depends on verifier-owned pointer class and window facts, not on native encoding.

#### `packet_ctx_wide_load`

- Meaning: rewrite byte ladders that extract packet or context fields into wider BPF loads, optionally followed by endian conversion or extraction already implied by the source ladder.
- Scope: packet and ctx pointers with verifier-proven readable windows only.
- Role: the strongest production-relevant post-`wide_load` substrate extension.
- Why verifier-level: the verifier already owns pointer class, readable-window, and access legality; the stock JIT should simply see a better BPF load.

Verifier-level v1 summary:

| Directive | Stage | v1 Scope | Cross-arch status |
| --- | --- | --- | --- |
| `bounds_window` | `VERIFIER_REWRITE` | single redundant guard elimination | cross-arch by construction |
| `packet_ctx_wide_load` | `VERIFIER_REWRITE` | packet/ctx byte ladders to wide BPF loads | cross-arch by construction |

### 4.3 Hybrid Directives

These directives prove why Hybrid exists instead of pure Path A or pure Path B.

#### `cmov_select`

- Meaning: recognize a pure-assignment one-diamond select region, normalize it to an internal select abstraction, then lower it to `cmovcc`, `csel`, or a retained branch according to target and policy.
- Scope: pure destination assignment only in v1.
- Explicit freeze: the richer v6 expression-arm example is not part of v1.
- Why Hybrid: CFG recognition and semantic normalization belong in the verifier; the actual lowering is target-specific.

#### `branch_reorder`

- Meaning: permute one closed diamond so the requested hot arm becomes fall-through in the BPF stream seen by later passes.
- Scope: no duplication, one entry, one join, one subprogram, no side-effectful arms that prevent safe permutation.
- Why included under Hybrid even though it is verifier-only in v1: it is the strongest proof that a pure JIT-level design is too weak for the paper's structural claim.

Hybrid summary:

| Directive | Stage(s) | v1 Scope | Why it matters |
| --- | --- | --- | --- |
| `cmov_select` | verifier recognition + JIT lowering | narrow pure-assignment select only | first true policy-sensitive Hybrid case |
| `branch_reorder` | verifier rewrite | one-diamond permutation, no duplication | strongest Path-B-style justification |

### 4.4 Explicit v1 Exclusions

The following ideas are explicitly out of scope for v1.
They are not "maybe if there is time."
They are cut because they require a different mechanism class or a larger soundness envelope.

| Excluded directive | Why excluded from v1 |
| --- | --- |
| `subprog_inline` | crosses subprogram boundaries, collides with `jit_subprogs()`, needs stack/call remapping and re-verification |
| `map_lookup_cache` | needs helper-effect, alias, and invalidation reasoning not present in the current validator model |
| `const_fold_region` | turns the kernel into a mini compiler/dataflow engine rather than a bounded directive consumer |
| `post_verifier_dce` | better treated as kernel-owned cleanup after structural rewrites, not a userspace-controlled directive |
| `helper_result_dce` | requires helper purity modeling and effect reasoning beyond current retained facts |
| `tail_call_specialize` | crosses program boundaries and interacts with poke descriptors and direct-tail-call patch geometry |
| general `bitfield_extract` | promising, but not frozen in v1 because the strongest production cases overlap with `packet_ctx_wide_load`; adding it now would dilute scope discipline |
| general duplicated-code layout directives | canonical-PC and tooling semantics are not frozen in v1 |

### 4.5 Directive Interaction Rules

v7 keeps interaction deliberately simple in v1.

The rules are:

1. Records may not overlap inside the same `(subprog_id, stage)` coordinate space.
2. Verifier-stage directives run before JIT-stage directives are prepared.
3. A successful verifier-stage rewrite may invalidate a later JIT-stage record by changing the final post-verifier interval.
4. That invalidation is reported as a normal stage-specific reject, not as a fatal load error.
5. v1 does not support explicit dependency chains between directives.
6. Userspace is expected to pre-resolve profitability interactions.
7. The kernel resolves legality only.

This is intentionally conservative.
The first release should not attempt a global kernel-side profitability planner.

### 4.6 Stage Ownership Table

The complete v1 ownership table is:

| Directive | Recognized by | Rewritten by | Lowered by |
| --- | --- | --- | --- |
| `wide_load` | arch-neutral validator on final post-verifier BPF | none | JIT |
| `wide_store` | arch-neutral validator on final post-verifier BPF | none | JIT |
| `rotate_fusion` | arch-neutral validator on final post-verifier BPF | none | JIT |
| `lea_fusion` | arch-neutral validator on final post-verifier BPF | none | JIT |
| `bounds_window` | verifier | verifier | stock JIT on rewritten BPF |
| `packet_ctx_wide_load` | verifier | verifier | stock JIT on rewritten BPF |
| `cmov_select` | verifier | verifier normalization to internal select plan | JIT |
| `branch_reorder` | verifier | verifier | stock JIT on rewritten BPF |

## 5. Per-Directive Specification

Sources for this section:

- `docs/tmp/interface-design-detail.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/jit-pass-implementation-detail.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`

This section is normative.
If later implementation disagrees with this section, the implementation should change unless a design bug is found here first.

### 5.1 Shared Types

```c
enum bpf_jit_mem_class {
	BPF_JIT_MEM_STACK      = 1,
	BPF_JIT_MEM_MAP_VALUE  = 2,
	BPF_JIT_MEM_PACKET     = 3,
	BPF_JIT_MEM_CTX        = 4,
};

enum bpf_jit_byte_order {
	BPF_JIT_BYTE_ORDER_LE = 1,
	BPF_JIT_BYTE_ORDER_BE = 2,
};

enum bpf_jit_val_kind {
	BPF_JIT_VAL_REG   = 1,
	BPF_JIT_VAL_IMM32 = 2,
	BPF_JIT_VAL_IMM64 = 3,
};

struct bpf_jit_value_ref_v1 {
	__u8  kind;
	__u8  reg;
	__u8  width;       /* 32 or 64 for immediates */
	__u8  reserved0;
	__s64 imm;
}; /* 16 bytes */
```

Internal kernel-only retained-fact side state used by some directives:

```c
struct bpf_jit_mem_fact {
	__u8  valid;
	__u8  mem_class;
	__u8  align_log2;
	__u8  flags;
	__s16 const_off;
	__u16 min_readable;
};
```

Internal kernel-only normalized select plan used by `cmov_select`:

```c
struct bpf_jit_select_plan {
	__u8  width;         /* 32 or 64 */
	__u8  cc;
	__u8  dst_reg;
	__u8  lhs_reg;
	struct bpf_jit_value_ref_v1 rhs;
	struct bpf_jit_value_ref_v1 true_val;
	struct bpf_jit_value_ref_v1 false_val;
};
```

### 5.2 Shared v1 Validation Contract

Every v1 directive, regardless of kind, is subject to the following common rules:

1. The record must bind to exactly one original whole-program subprogram and one contiguous original interval.
2. The remapped post-verifier interval must be non-empty and contiguous.
3. The interval must stay inside one post-verifier subprogram.
4. The interval must not cross an exception boundary.
5. The interval must not cross a tail-call poke site.
6. Any stage-specific CPU requirement mismatch produces `DROPPED` or `REJECTED`, never silent best-effort transformation.
7. If a validator cannot prove the exact requested shape, the site is rejected and the stock stage behavior remains.

The blob never overrides kernel legality.
It only requests extra legality checks.

### 5.3 `wide_load`

Kind:

```c
struct bpf_jit_dir_wide_load_v1 {
	__u8  width;            /* 4 or 8 */
	__u8  mem_class;        /* STACK or MAP_VALUE */
	__u8  dst_reg;
	__u8  base_reg;
	__s16 base_off;
	__u8  min_align_log2;
	__u8  liveout_reg;
}; /* 8 bytes */
```

Stage:

- `BPF_JIT_STAGE_JIT_LOWERING`

Purpose:

- collapse a byte-load recomposition ladder into one native `movl` or `movq`.

#### Preconditions

Shared preconditions that must be set:

- `BPF_JIT_PC_STRAIGHT_LINE`
- `BPF_JIT_PC_NO_INTERIOR_TARGET`
- `BPF_JIT_PC_NO_CALLS`
- `BPF_JIT_PC_CONST_OFFSET_MEM`
- `BPF_JIT_PC_SAME_BASE_MEM`
- `BPF_JIT_PC_NO_PROBE_OR_EXTABLE`

Kind-specific preconditions:

1. The remapped interval consists only of byte loads, shifts, and ORs that reconstruct one little-endian 4-byte or 8-byte value.
2. All byte loads read from the same base register with one contiguous byte ladder.
3. Each loaded byte is used exactly once in the reconstruction.
4. The final architectural result is written to `liveout_reg == dst_reg`.
5. Every temporary register defined inside the ladder other than `dst_reg` is dead at the interval boundary.
6. The access class is direct nonfaulting stack or map-value access.
7. `min_readable >= width`.
8. The retained alignment lower bound satisfies `align_log2 >= min_align_log2`.
9. The widened load is legal on the current kernel for the effective pointer class and offset.

#### Validator Logic

Validator steps:

1. Remap the original interval to post-verifier coordinates.
2. Confirm contiguity and single-subprog membership.
3. Match the exact byte-ladder template on the final post-verifier program.
4. Look up retained `bpf_jit_mem_fact` for each load and confirm:
   - same memory class;
   - same base register;
   - constant offset ladder;
   - sufficient readable window;
   - sufficient alignment.
5. Recheck widened-access legality with the same access-class rules the verifier would apply to a direct 4-byte or 8-byte load.
6. Recompute post-rewrite liveness for directive-bearing programs and reject if any temporary register is live-out.

#### Before And After

Accepted source shape:

```c
/* before */
BPF_LDX_MEM(BPF_B,  dst, base, off + 0);
BPF_LDX_MEM(BPF_B,  tmp, base, off + 1);
BPF_ALU64_IMM(BPF_LSH, tmp, 8);
BPF_ALU64_REG(BPF_OR,  dst, tmp);
...
BPF_LDX_MEM(BPF_B,  tmp, base, off + 7);
BPF_ALU64_IMM(BPF_LSH, tmp, 56);
BPF_ALU64_REG(BPF_OR,  dst, tmp);

/* native after */
movq off(base), dst
```

4-byte case:

```c
/* before */
BPF_LDX_MEM(BPF_B,  dst, base, off + 0);
BPF_LDX_MEM(BPF_B,  tmp, base, off + 1);
BPF_ALU64_IMM(BPF_LSH, tmp, 8);
BPF_ALU64_REG(BPF_OR,  dst, tmp);
BPF_LDX_MEM(BPF_B,  tmp, base, off + 2);
BPF_ALU64_IMM(BPF_LSH, tmp, 16);
BPF_ALU64_REG(BPF_OR,  dst, tmp);
BPF_LDX_MEM(BPF_B,  tmp, base, off + 3);
BPF_ALU64_IMM(BPF_LSH, tmp, 24);
BPF_ALU64_REG(BPF_OR,  dst, tmp);

/* native after */
movl off(base), dst32
```

Representative x86 emission:

- width 4: reuse `emit_ldx(..., BPF_W, ...)`
- width 8: reuse `emit_ldx(..., BPF_DW, ...)`

#### `addrs[]` Impact

If the site covers `[start, end)`:

- `addrs[start]` is the fused region entry;
- each interior `addrs[k]` for `start < k < end` is set to `addrs[start]`;
- `addrs[end]` is set to the fused region end.

Any outside branch to an interior PC rejects the site.

#### Constant Blinding Interaction

v1 rule:

- reject `wide_load` on the blinded path.

Reason:

- the local instruction shape is not stable after `bpf_jit_blind_constants()`;
- the plan would otherwise need a second stable side representation tied to the blinded clone.

This is a deliberate v1 cut, not an oversight.

#### Error And Fallback Behavior

Reject reasons include:

- `REMAP_EMPTY`
- `REMAP_NONCONTIG`
- `FACT_MISSING`
- `TEMP_LIVEOUT`
- `PROBE_MEM_OR_EXTABLE`
- `PRECOND_MISMATCH`

Fallback:

- stock byte ladder lowering in the current backend.

### 5.4 `cmov_select`

Kind:

```c
struct bpf_jit_dir_cmov_select_v1 {
	__u8  cc;
	__u8  width;            /* 32 or 64 */
	__u8  dst_reg;
	__u8  lhs_reg;
	struct bpf_jit_value_ref_v1 rhs;
	struct bpf_jit_value_ref_v1 true_val;
	struct bpf_jit_value_ref_v1 false_val;
	__u8  reserved0[4];     /* explicit tail pad; natural aligned size is 56 */
}; /* 56 bytes */
```

Stages:

- `BPF_JIT_STAGE_VERIFIER_REWRITE`
- `BPF_JIT_STAGE_JIT_LOWERING`

Purpose:

- recognize a one-diamond pure-assignment select and lower it branchlessly when profitable.

#### Explicit v1 Freeze

Only the narrow pure-assignment contract is in scope.

Allowed arm shapes:

- `dst = reg`
- `dst = imm`

Disallowed in v1:

- `dst = reg + reg`
- `dst = reg ^ (reg + imm)`
- any multi-insn arm expression
- any side-effectful arm

The richer v6 example is deferred.

#### Verifier-Stage Preconditions

Shared preconditions:

- `BPF_JIT_PC_ONE_DIAMOND`
- `BPF_JIT_PC_NO_INTERIOR_TARGET`
- `BPF_JIT_PC_NO_CALLS`
- `BPF_JIT_PC_NO_STORES`
- `BPF_JIT_PC_NO_TAILCALL_OR_POKE`

Kind-specific preconditions:

1. The interval is exactly one conditional entry branch, two assignment arms, one join.
2. Each arm performs exactly one assignment to the same destination register.
3. Neither arm contains helper calls, stores, atomics, exits, tail calls, probe/extable memory ops, or hidden side effects.
4. Compare width and signedness are exactly determined.
5. Any later live-out difference between the two arms is only `dst_reg`.

#### Verifier-Stage Normalization

The verifier does not introduce a new public BPF opcode.
Instead, it stores a normalized internal select plan in side state:

```c
struct bpf_jit_select_plan {
	__u8  width;
	__u8  cc;
	__u8  dst_reg;
	__u8  lhs_reg;
	struct bpf_jit_value_ref_v1 rhs;
	struct bpf_jit_value_ref_v1 true_val;
	struct bpf_jit_value_ref_v1 false_val;
};
```

This is the internal `BPF_SELECT` abstraction in v7:

- kernel-internal;
- verifier-produced;
- JIT-consumed;
- not exposed as a user ISA change.

The verifier records:

- the closed diamond interval;
- the normalized compare;
- the normalized arm values.

It then marks the site as eligible for stage-2 lowering.

#### JIT-Stage Lowering

JIT-stage lowering chooses among:

- x86 `cmp/test` + `mov` + `cmovcc`
- arm64 `cmp` + `csel`
- stock branch sequence if policy says not to use a select or if the backend rejects the lowering

Representative x86 lowering:

```asm
cmp   lhs, rhs
mov   false_val, dst
cmovCC true_val, dst
```

Representative x86 condition mapping:

| BPF cc | x86 `cmov` |
| --- | --- |
| `BPF_JEQ` | `CMOVE` |
| `BPF_JNE` | `CMOVNE` |
| `BPF_JGT` | `CMOVA` |
| `BPF_JGE` | `CMOVAE` |
| `BPF_JLT` | `CMOVB` |
| `BPF_JLE` | `CMOVBE` |
| `BPF_JSGT` | `CMOVG` |
| `BPF_JSGE` | `CMOVGE` |
| `BPF_JSLT` | `CMOVL` |
| `BPF_JSLE` | `CMOVLE` |

`BPF_JSET` is excluded from v1 `cmov_select`.

#### Width Rules

- `BPF_JMP*` sites imply width 64.
- `BPF_JMP32*` sites imply width 32.
- width 32 uses 32-bit compare and 32-bit `cmov`, relying on natural zero-extension of the destination register.

#### Immediate-Arm And Scratch Rules

v1 x86 policy:

- immediate arms are allowed;
- immediate values are materialized into `dst` or `AUX_REG` (`r11`) before `cmov`;
- memory-source `cmov` is disallowed;
- if `dst == true_reg` and false-arm materialization would clobber the true source, copy true-arm value to `AUX_REG` first.

Flags discipline:

- compare or test must happen before any materialization that might overwrite flags;
- materialization instructions between compare and `cmov` must preserve flags or the compare must be reissued.

The implementation should prefer flag-preserving moves so the compare is emitted once.

#### `addrs[]` Impact

The same collapse rule as `wide_load` applies:

- one native entry for the whole diamond interval;
- interior boundaries collapse;
- any outside edge into the interior rejects the site.

An internal edge from the entry compare to one arm is not a rejection because the entire region is replaced.

#### Constant Blinding Interaction

`cmov_select` is the only v1 Hybrid directive whose stage-1 normalization still runs before blinding, but v1 fails closed at stage 2 on blinded programs.

Reason:

- stage-1 normalization stores a stable select plan in auxiliary state;
- `bpf_jit_blind_constants()` clones the program and rewrites the BPF instruction stream before the x86 JIT's `do_jit()` path sees it;
- those rewrites can change instruction indices, so copying side state alone would not keep the normalized plan anchored to the right blinded instructions;
- v1 does not implement the required plan-rebase-through-blinding pass.

So v1 behavior is:

- if `prog->blinded` after `bpf_jit_blind_constants()`, drop `cmov_select` at `JIT_LOWERING`;
- on unblinded programs, use the normalized select plan normally.

This is a deliberate v1 fail-closed rule until an explicit blinding-rebase mechanism exists.

#### Error And Fallback Behavior

Verifier-stage reject reasons:

- `PRECOND_MISMATCH`
- `FACT_MISSING`
- `TAIL_CALL_OR_POKE_SITE`
- `SPEC_HARDENING_REGION`

JIT-stage reject reasons:

- `ARCH_UNSUPPORTED`
- `CPU_FEATURE_MISMATCH`
- `EMIT_FAILED`

Fallback:

- keep the stock branch sequence for that site.

### 5.5 `wide_store`

Kind:

```c
struct bpf_jit_dir_wide_store_v1 {
	__u8  width;            /* 4 or 8 */
	__u8  mem_class;        /* STACK or MAP_VALUE */
	__u8  src_kind;         /* REG, IMM32, IMM64 */
	__u8  src_reg;          /* valid if src_kind == REG */
	__u8  base_reg;
	__u8  min_align_log2;
	__s16 base_off;
	__s64 imm;
}; /* 16 bytes */
```

Stage:

- `BPF_JIT_STAGE_JIT_LOWERING`

Preconditions:

- straight-line interval with no interior targets;
- adjacent byte stores to one base and one contiguous offset ladder;
- stack or map-value class only;
- no probe/extable forms;
- all stored bytes derive from one register or one constant value.

Emission:

- one `movl` or `movq` store, or immediate materialization plus one store.

`addrs[]`:

- same collapse rule as `wide_load`.

Constant blinding:

- disabled on blinded programs in v1.

Fallback:

- stock byte stores.

### 5.6 `rotate_fusion`

Kind:

```c
struct bpf_jit_dir_rotate_fusion_v1 {
	__u8  width;            /* 32 or 64 */
	__u8  dst_reg;
	__u8  dir;              /* left or right */
	__u8  prefer_bmi2;      /* boolean */
	__u8  amount;           /* immediate rotate amount */
	__u8  reserved0[3];
}; /* 8 bytes */
```

Stage:

- `BPF_JIT_STAGE_JIT_LOWERING`

Preconditions:

- straight-line shift/shift/or rotate idiom;
- immediate rotate amount only;
- no live-out dependence on intermediate temporaries.

Emission:

- use `rorx` when `prefer_bmi2` is true and BMI2 is available;
- otherwise use `rol` or `ror`.

`addrs[]`:

- same collapse rule as `wide_load`.

Constant blinding:

- disabled on blinded programs in v1 because immediate-bearing shapes are rewritten.

Fallback:

- stock shift/or sequence.

### 5.7 `lea_fusion`

Kind:

```c
struct bpf_jit_dir_lea_fusion_v1 {
	__u8  width;            /* 32 or 64 */
	__u8  dst_reg;
	__u8  base_reg;
	__u8  index_reg;
	__u8  scale_log2;       /* 0..3 */
	__u8  reserved0[3];
	__s32 disp;
}; /* 12 bytes */
```

Stage:

- `BPF_JIT_STAGE_JIT_LOWERING`

Preconditions:

- straight-line arithmetic chain encodable as one x86 `lea`;
- no side effects;
- no temporary live-out dependence.

Emission:

- one `lea disp(base, index, scale), dst`.

`addrs[]`:

- same collapse rule as `wide_load`.

Constant blinding:

- disabled on blinded programs in v1.

Fallback:

- stock arithmetic chain lowering.

### 5.8 `bounds_window`

Kind:

```c
struct bpf_jit_dir_bounds_window_v1 {
	__u8  ptr_reg;
	__u8  limit_reg;
	__u8  access_width;
	__u8  cmp_cc;
	__s16 access_off;
	__u8  fast_path_is_fallthrough;
	__u8  reserved0;
}; /* 8 bytes */
```

Stage:

- `BPF_JIT_STAGE_VERIFIER_REWRITE`

Purpose:

- eliminate one bounds guard whose truth value is already implied by a verifier-retained readable-window fact on the immediately guarded access.

Important non-goal:

- this is not generic semantic-changing bounds-check elimination.

#### Preconditions

1. The candidate is one guard at a time.
2. The verifier has a retained readable-window fact for the immediately guarded access as recorded at that access site by `check_mem_access()`.
3. No instruction between the guard compare and the guarded access changes the pointer class, `ptr_reg`, `limit_reg`, or access-width/access-offset basis used by the proof.
4. The guard's only purpose is to protect that immediately following access.
5. Removing the guard does not eliminate any side effect except the guard itself.
6. The guard is semantically dead because the guarded access is already verifier-proven safe on all reachable states that reach that access.

#### Rewrite

Before:

```c
BPF_JMP_IMM(cmp_cc, limit_reg, K, +skip_fail);
/* fail path */
...
/* fast path access */
```

After:

- rewrite the guard to the fall-through path already implied by the retained window fact;
- physically remove the dead arm if it becomes unreachable under existing dead-code cleanup.

The exact BPF rewrite may be:

- unconditional `ja` to the surviving arm;
- or direct deletion if the arm is already unreachable after normalization.

#### Patch Semantics

This is a verifier rewrite, so there is no `addrs[]` rule.
The rewrite is applied through `bpf_patch_insn_data()` or a small verifier helper over the BPF stream.

#### Constant Blinding Interaction

Unaffected in principle.

The rewrite runs before blinding, so the blinded program simply sees the already simplified BPF stream.

#### Error And Fallback

Reject if:

- the window fact is missing;
- the guard is not semantically dead;
- the guard is not isolated to one closed region;
- later stock verifier rewrites would need a different pointer class.

Fallback:

- keep the original guard.

### 5.9 `packet_ctx_wide_load`

Kind:

```c
struct bpf_jit_dir_packet_ctx_wide_load_v1 {
	__u8  width;            /* 2, 4, or 8 */
	__u8  mem_class;        /* PACKET or CTX */
	__u8  dst_reg;
	__u8  base_reg;
	__s16 base_off;
	__u8  byte_order;       /* LE or BE */
	__u8  liveout_reg;
}; /* 8 bytes */
```

Stage:

- `BPF_JIT_STAGE_VERIFIER_REWRITE`

Purpose:

- rewrite packet or ctx byte ladders into wider BPF loads so all JITs benefit automatically.

#### Preconditions

1. One contiguous byte ladder from one packet or ctx base.
2. Verifier-retained readable window proves the wider access is legal.
3. The rewritten load stays within the direct access class the later kernel lowering expects.
4. Any later endian correction implied by the original ladder is preserved exactly.
5. Temporary registers other than the final liveout are dead after the region.

#### Rewrite

Before:

```c
BPF_LDX_MEM(BPF_B, dst, base, off + 0);
BPF_LDX_MEM(BPF_B, tmp, base, off + 1);
...
```

After:

```c
BPF_LDX_MEM(BPF_W or BPF_DW, dst, base, off);
/* optional endian conversion or extraction if required */
```

If the original ladder reconstructed big-endian field order, the verifier rewrite inserts the equivalent BPF endian conversion instead of relying on the JIT to infer it later.

#### Patch Semantics

This is a verifier-side BPF rewrite.

The rewrite must happen:

- before `convert_ctx_accesses()`;
- before `do_misc_fixups()`;
- after the verifier has already established readable-window legality.

That ordering lets later kernel rewrite passes operate on the improved BPF form naturally.

#### Constant Blinding Interaction

Unaffected in principle.

The rewritten BPF is what later blinding and JIT phases will see.

#### Error And Fallback

Reject if:

- the wider load would later become `PROBE_MEM*`;
- the access class depends on speculation-hardening behavior not preserved by the rewrite;
- the readable window or byte-order proof is incomplete.

Fallback:

- keep the original byte ladder.

### 5.10 `branch_reorder`

Kind:

```c
struct bpf_jit_dir_branch_reorder_v1 {
	__u8  hot_arm;          /* 0=false arm, 1=true arm */
	__u8  invert_ok;        /* boolean */
	__u8  true_arm_len;
	__u8  false_arm_len;
	__u8  reserved0[4];
}; /* 8 bytes */
```

Stage:

- `BPF_JIT_STAGE_VERIFIER_REWRITE`

Purpose:

- permute one closed diamond so the desired hot arm becomes fall-through in the rewritten BPF stream.

#### v1 Scope Freeze

Allowed:

- one entry;
- one compare;
- two straight-line arms;
- one join;
- no duplication;
- no cross-subprog motion.

Disallowed:

- nested diamonds;
- loops or backedges;
- instruction duplication;
- open-region layout transforms.

#### Preconditions

1. The interval is one closed diamond.
2. The join post-dominates both arms.
3. No outside edge enters either interior arm.
4. Neither arm contains helper calls, tail calls, exits, probe/extable accesses, or other motion-preventing effects.
5. The entire region lies in one subprogram.
6. The requested hot arm can be made fall-through by permutation and optional condition inversion only.

#### Rewrite

Before:

```c
0: if cond goto true
1: false arm
2: goto join
3: true arm
4: join
```

After when the true arm should be fall-through:

```c
0: if !cond goto false
1: true arm
2: goto join
3: false arm
4: join
```

Because v1 forbids duplication, canonical-PC semantics remain simple:

- each original instruction still has exactly one rewritten BPF instance;
- later line info and JIT mapping remain one-to-one with the rewritten stream.

#### Patch Semantics

This rewrite needs more than a simple splice.

Required helper behavior:

1. materialize an old-index to new-index map for the closed region;
2. permute the instruction array, aux side state, and per-insn line info together through that map;
3. rewrite poke descriptors and any other insn-indexed descriptors through that same map;
4. preserve subprogram boundaries explicitly: in v1 the helper rejects any region that crosses a subprog start, and otherwise must leave subprog-start metadata consistent with the permuted interval;
5. recompute internal branch offsets;
6. reject if any branch range becomes invalid or any required metadata cannot be updated consistently.

v1 does not attempt a general verifier block scheduler.
It implements only this closed-diamond helper.

#### Constant Blinding Interaction

Unaffected in principle.

As with other verifier-stage rewrites, blinding happens later on the already permuted program.

#### Error And Fallback

Reject if:

- the region is not a closed diamond;
- the arm contains side effects that make motion illegal;
- an outside edge enters the interior;
- permutation would cross a subprogram boundary.

Fallback:

- keep the original BPF order.

### 5.11 Summary Table

| Directive | Stage | Transformation kind | `addrs[]` effect | Blinding in v1 | Fallback |
| --- | --- | --- | --- | --- | --- |
| `wide_load` | JIT | fuse byte-load ladder to one native load | collapse interval | disabled | stock ladder |
| `cmov_select` | Hybrid | normalize select then lower to branchless select or branch | collapse interval at JIT stage | disabled (fail-closed) | stock branch |
| `wide_store` | JIT | fuse byte-store ladder to one native store | collapse interval | disabled | stock stores |
| `rotate_fusion` | JIT | fuse shift/or to rotate | collapse interval | disabled | stock idiom |
| `lea_fusion` | JIT | fuse arithmetic chain to `lea` | collapse interval | disabled | stock arithmetic |
| `bounds_window` | Verifier | remove one semantically dead guard | no `addrs[]` rule | unaffected | keep guard |
| `packet_ctx_wide_load` | Verifier | rewrite packet/ctx ladder to wide BPF load | no `addrs[]` rule | unaffected | keep ladder |
| `branch_reorder` | Verifier | closed-diamond permutation, no duplication | no JIT-specific collapse | unaffected | keep order |

## 6. Kernel Implementation Plan

Sources for this section:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/jit-pass-implementation-detail.md`
- `docs/tmp/bpf-jit-comp-analysis.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/interface-design-review.md`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/kernel/bpf/core.c`
- `vendor/linux/kernel/bpf/syscall.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`

### 6.1 File Touch Points

Primary kernel files:

- `vendor/linux/kernel/bpf/syscall.c`
  - transport parsing and early bind
- `vendor/linux/kernel/bpf/verifier.c`
  - stage-1 verifier rewrite pass
  - remap logic
  - retained-fact recording
  - `orig_idx` propagation
  - `jit_subprogs()` slicing
- `vendor/linux/kernel/bpf/core.c`
  - constant blinding side-state copy support
  - runtime selection integration
- `vendor/linux/include/linux/bpf_verifier.h`
  - auxiliary-state declarations
- `vendor/linux/include/uapi/linux/bpf.h`
  - UAPI structs and enums
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`
  - stage-2 JIT lowering fast path
- `vendor/linux/arch/arm64/net/bpf_jit_comp.c`
  - `cmov_select`/`csel` lowering path in the arm64 implementation track

### 6.2 Step 0: `orig_idx` Propagation Fix

This is the first implementation task because every remap story depends on it.

Current state:

- `env->insn_aux_data[i].orig_idx = i` is initialized in `bpf_check()`;
- `adjust_insn_aux_data()` does not propagate `orig_idx` through expansion.

Required change:

1. Preserve `orig_idx` for the replaced instruction.
2. Copy that `orig_idx` into inserted prefix slots created by `bpf_patch_insn_data()`.
3. Audit removal paths to ensure empty or non-contiguous remap results are rejected later instead of silently repaired.

Expected code delta:

- roughly 20-40 LOC plus selftests.

### 6.3 Step 1: Transport Layer

Implement:

- `jit_directives_fd` and `jit_directives_flags` parsing in `bpf_prog_load()`;
- `memfd` seal validation;
- blob copy, bounds checks, and version parsing;
- digest binding;
- CPU precheck;
- initial `prog->aux->jit_dir_state` allocation.

Properties:

- malformed or stale input fails load;
- structurally valid but later-unadopted directives remain non-fatal.

Expected code delta:

- roughly 250-400 LOC arch-neutral kernel code;
- 100-150 LOC UAPI definitions;
- selftests for malformed blobs and fallback.

### 6.4 Step 2: Remap Layer

Implement:

- original whole-program interval to post-verifier interval remap using propagated `orig_idx`;
- empty/non-contiguous/cross-subprog rejection;
- stage-specific site tables;
- result recording of `orig_start/end` and `post_start/end`.

Additional requirement:

- rebuild lightweight post-rewrite metadata for directive-bearing programs:
  - final jump-target map;
  - final liveness for directives that need temp dead-out checks.

Expected code delta:

- roughly 200-350 LOC plus metadata rebuild helpers.

### 6.5 Step 3: Stage-1 Verifier Rewrite Insertion

Add a new helper conceptually shaped as:

```c
static int apply_user_verifier_directives(struct bpf_verifier_env *env);
```

Placement:

- after `do_check_*()` and dead-code cleanup;
- before `convert_ctx_accesses()` and `do_misc_fixups()`.

Initial responsibilities:

- apply `bounds_window`;
- apply `packet_ctx_wide_load`;
- perform `cmov_select` recognition and normalize to internal select plans;
- apply `branch_reorder` closed-diamond permutation.

Expected code delta:

- core pass skeleton: 120-180 LOC;
- `bounds_window`: 150-250 LOC;
- `packet_ctx_wide_load`: 150-250 LOC;
- `branch_reorder`: 250-400 LOC because it needs a closed-diamond permutation helper;
- `cmov_select` recognition: 150-220 LOC.

### 6.6 Step 4: Retained-Fact Recording

Required for:

- `wide_load`
- `bounds_window`
- `packet_ctx_wide_load`

Implementation points:

- hook in `check_mem_access()` for relevant accepted access sites and retain the readable-window fact on the access instruction itself;
- for `bounds_window`, require a same-access proof: the guard must protect the immediately following access and no proof-relevant state may change between the guard and that access;
- use a sidecar fact array allocated only for directive-bearing programs;
- preserve that sidecar through the same insert/remove paths as `insn_aux_data`.

Expected code delta:

- roughly 150-250 LOC plus cleanup and tests.

### 6.7 Step 5: Stage-2 JIT Plan Preparation

Add a helper conceptually shaped as:

```c
static int prepare_jit_lowering_directives(struct bpf_verifier_env *env);
```

Placement:

- after `do_misc_fixups()` and `opt_subreg_zext_lo32_rnd_hi32()`;
- before `fixup_call_args()` invokes `jit_subprogs()`.

Responsibilities:

- remap and validate JIT-stage records on the final post-verifier program;
- build a stable whole-program plan;
- for `cmov_select`, attach stage-2 lowering policy to the normalized select plan.

Expected code delta:

- roughly 180-300 LOC.

### 6.8 Step 6: `jit_subprogs()` Slicing

This is the largest missing mechanism detail from the earlier interface draft.

Required behavior in `jit_subprogs()`:

1. Copy only the relevant JIT-stage plans into each subprog `func[i]->aux`.
2. Rebase coordinates from whole-program post-verifier indices to subprog-local indices.
3. Preserve stage-2 result bookkeeping across the first and second subprog JIT passes.
4. Aggregate results back into the main program's `bpf_prog_info` view.

Expected code delta:

- roughly 150-250 LOC.

### 6.9 Step 7: Stage-2 `do_jit()` Fast Path

In `vendor/linux/arch/x86/net/bpf_jit_comp.c`, add:

- a plan lookup by current BPF start PC;
- directive-specific emit helpers;
- explicit covered-range `addrs[]` handling;
- pass-stable rejection behavior.

Rules:

- accept or reject the site before the first dry pass;
- never rediscover or rematch inside later passes;
- treat late length mismatch as a backend bug, not as a graceful per-site fallback.

Implementation order:

1. `wide_load`
2. `cmov_select`
3. `wide_store`
4. `rotate_fusion`
5. `lea_fusion`

Expected code delta:

- `wide_load`: 120-180 LOC
- `cmov_select`: 180-280 LOC
- `wide_store`: 100-160 LOC
- `rotate_fusion`: 80-140 LOC
- `lea_fusion`: 80-140 LOC

### 6.10 Step 8: Constant Blinding Copy Rules

Required v1 rule:

- verifier-stage rewrites remain enabled because blinding sees the already rewritten BPF program;
- JIT-stage directives whose plan coordinates depend on post-verifier BPF instruction indices stay disabled on blinded programs unless they implement an explicit rebase through the blinding rewrites;
- in v1 this means all pure local fusions and `cmov_select` fail closed on the blinded path;
- only bookkeeping that is independent of instruction indices may be copied into the blinded clone unchanged.

Pure local JIT-stage fusion directives remain disabled on the blinded path.

Expected code delta:

- roughly 40-80 LOC in `vendor/linux/kernel/bpf/core.c` plus JIT entry gating.

### 6.11 Estimated LOC By Directive And Layer

| Work item | Layer | Estimated LOC | Notes |
| --- | --- | ---: | --- |
| `orig_idx` propagation fix | verifier infra | 20-40 | prerequisite for everything |
| transport/parser/logging skeleton | shared | 350-550 | includes UAPI and selftests |
| remap + metadata rebuild | shared | 200-350 | whole-program and subprog-aware |
| retained memory facts | verifier infra | 150-250 | sidecar, not permanent aux bloat |
| `bounds_window` | verifier | 150-250 | one guard at a time |
| `packet_ctx_wide_load` | verifier | 150-250 | byte ladder to wide BPF load |
| `branch_reorder` | verifier | 250-400 | closed-diamond permutation helper |
| `cmov_select` recognition | verifier | 150-220 | normalization to select plan |
| `wide_load` JIT fast path | x86 JIT | 120-180 | plus tests |
| `cmov_select` JIT lowering | x86 JIT | 180-280 | includes immediate-arm handling |
| `wide_store` JIT fast path | x86 JIT | 100-160 | optional immediate materialization |
| `rotate_fusion` | x86 JIT | 80-140 | feature gated |
| `lea_fusion` | x86 JIT | 80-140 | x86-specific |
| `jit_subprogs()` slicing | verifier/JIT bridge | 150-250 | critical multi-subprog work |
| blinding clone side-state copy | shared runtime | 80-140 | only Hybrid-relevant state |

### 6.12 Implementation Order

The implementation order is fixed:

1. `orig_idx` propagation.
2. blob transport, parser, and logging.
3. remap and post-rewrite metadata rebuild.
4. `wide_load`.
5. narrow `cmov_select`.
6. one low-risk breadth directive:
   - `wide_store` first choice;
   - `rotate_fusion` or `lea_fusion` second choice.
7. first verifier-stage structural directive:
   - `bounds_window` first if retained window facts are ready;
   - otherwise `packet_ctx_wide_load`.
8. `branch_reorder`.

This order matches the repo-wide critical-path conclusions from the reviews.

### 6.13 Selftests

Kernel selftests must cover:

- malformed blob and version rejection;
- digest mismatch;
- CPU mismatch with strict and non-strict behavior;
- `orig_idx` remap through insertion and deletion;
- `wide_load` accept/reject cases, especially temp live-out and big-endian ladders;
- `cmov_select` accept/reject cases, especially immediate arms and outside interior targets;
- `bounds_window` only when the guarded access has a retained access-site window proof and no proof-relevant state changes intervene;
- `packet_ctx_wide_load` packet and ctx variants;
- `branch_reorder` one-diamond no-duplication cases;
- constant blinding behavior by directive family.

### 6.14 Open But Deliberately Deferred Work

Not required for v1 bring-up:

- verifier-side re-verification path for `subprog_inline`;
- duplication-aware canonical-PC semantics;
- general capability-query UAPI beyond cached load-time probing;
- arm64 implementations for the x86-only local-fusion directives.

## 7. Userspace Advisor

Sources for this section:

- `docs/tmp/interface-design-detail.md`
- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/interface-design-review.md`

### 7.1 Role

The userspace advisor has exactly three responsibilities:

1. discover legal candidate sites on the exact finalized pre-verifier instruction stream;
2. choose which legal candidates are worth requesting on this CPU, workload, and rollout policy;
3. serialize the chosen plan into one digest-bound blob.

The advisor does not:

- prove legality;
- remap post-verifier coordinates;
- emit native code;
- attach or mutate directives after load.

### 7.2 Exact Analysis Point

The advisor must run on the exact instruction stream that will be passed to `BPF_PROG_LOAD`.

That means:

- after CO-RE relocation;
- after loader-side subprogram finalization;
- after any libbpf rewriting;
- after pseudo-instruction materialization visible in `attr.insns`.

It must not run on:

- C source;
- LLVM IR;
- pre-relocation ELF sections;
- any loader-independent abstraction that is not the real pre-verifier byte stream.

This requirement is a consequence of exact digest binding.
It is not optional.

### 7.3 Advisor API

The v7 userspace surface is:

```c
struct bpf_jitadv_program {
	const struct bpf_insn *insns;
	__u32 insn_cnt;
	__u32 prog_type;
	__u32 expected_attach_type;
	const char *logical_name;
};

struct bpf_jitadv_policy_view {
	struct bpf_jit_cpu_contract_v1 cpu;
	__u32 max_directives;
	__u32 code_size_budget_class;
	__u32 workload_profile_class;
};

struct bpf_jitadv_candidate;
struct bpf_jitadv_plan;
struct bpf_jitadv_blob;

int bpf_jitadv_discover(const struct bpf_jitadv_program *prog,
			struct bpf_jitadv_candidate **cands,
			size_t *nr_cands);

int bpf_jitadv_select(const struct bpf_jitadv_candidate *cands,
		      size_t nr_cands,
		      const struct bpf_jitadv_policy_view *policy,
		      struct bpf_jitadv_plan **out);

int bpf_jitadv_pack(const struct bpf_jitadv_program *prog,
		    const struct bpf_jitadv_plan *plan,
		    struct bpf_jitadv_blob **out);

int bpf_jitadv_memfd(const struct bpf_jitadv_blob *blob, int *fd_out);
void bpf_jitadv_blob_free(struct bpf_jitadv_blob *blob);
```

The separation between `discover`, `select`, and `pack` is deliberate:

- discovery is deterministic and image-local;
- selection is policy-dependent and changeable without parser changes;
- packing is ABI-sensitive and must be implemented once, not by every loader.

### 7.4 `bpf_jitadv_discover()`

`bpf_jitadv_discover()` is a static analysis pass over finalized BPF bytecode.

It should produce candidates tagged by:

- kind;
- original `subprog_id`;
- original `[start, end)` interval;
- stage;
- site-local structural summary;
- policy-relevant features.

#### Discovery Rules By Kind

`wide_load`

- scan straight-line intervals for byte ladders over one base register;
- record width, base offset ladder, candidate destination register, and whether the ladder is little-endian.

`wide_store`

- scan straight-line intervals for adjacent byte stores to one base register;
- record width, value source kind, and candidate store range.

`rotate_fusion`

- match shift/shift/or idioms that reconstruct a rotate by one immediate amount;
- record width, direction, and amount.

`lea_fusion`

- match arithmetic chains encodable as `base + index * scale + disp`;
- record width, candidate destination register, base/index registers, scale, and displacement.

`bounds_window`

- build a CFG over finalized BPF;
- scan for single redundant guards whose immediately following protected access already carries a retained access-site window fact and whose guard-to-access slice preserves the proof inputs;
- emit only one-guard candidates, not arbitrary guard ladders.

`packet_ctx_wide_load`

- scan packet/ctx byte ladders separately from `wide_load`;
- record field width, byte order, base class, and offset ladder;
- reject discovery-time shapes that already obviously require helper or probe semantics.

`cmov_select`

- build a CFG;
- find one-entry, one-join diamonds;
- require each arm to contain exactly one assignment to the same destination register;
- classify arm values as `REG`, `IMM32`, or `IMM64`.

`branch_reorder`

- build a CFG;
- find one closed diamond whose hot arm can become fall-through by permutation and optional condition inversion;
- reject if any outside edge enters the interior.

#### Discovery Output Shape

Candidate output should include both:

- kernel-relevant shape facts to pack into the record;
- policy features not sent to the kernel.

Example policy-only features:

- estimated branch predictability bucket;
- surrounding code-size budget bucket;
- hardware class fit score;
- candidate interaction score.

These policy-only features are how userspace remains the profitability owner without bloating the UAPI.

### 7.5 `bpf_jitadv_select()`

`bpf_jitadv_select()` is where policy lives.

Inputs:

- candidate set from `discover`;
- CPU contract for the current node or cpuset;
- workload class or offline profile class;
- fleet policy version;
- program-level code-size and complexity budget.

Outputs:

- a subset of candidates;
- packed record payload values;
- advisory ordering only if the userspace implementation needs it internally.

#### Selection Policy Inputs

Policy inputs fall into four buckets:

| Bucket | Examples | Owned by |
| --- | --- | --- |
| hardware | CPU family, model, BMI2, arm64 feature bits | deployment environment |
| workload | predictable branch, mixed branch, packet mix class | profiling or operator |
| program | code-size budget, hot path density, candidate count | advisor |
| fleet | canary enablement, policy version, rollback target | operator |

#### Policy Examples

`wide_load`

- likely enabled by default on x86 for aligned stack/map-value ladders;
- may be restricted on smaller cores or on misalignment-sensitive deployments.

`cmov_select`

- enabled only for workload classes where branch predictability is poor enough and CPU class favors branchless select;
- otherwise left as a branch.

`branch_reorder`

- enabled only when the hot arm is known or strongly inferred and the code-size budget permits the requested layout.

`rotate_fusion`

- gated on BMI2 or the equivalent backend feature policy if `rorx` is requested.

This is the precise point where userspace policy differs from kernel legality.

### 7.6 `bpf_jitadv_pack()`

`bpf_jitadv_pack()` is the only component that understands the wire ABI.

It owns:

- SHA-256 digest computation;
- exact little-endian packing;
- stage-tagged record layout;
- record ordering;
- reserved-zero discipline;
- `memfd` sealing.

The packer library exists to prevent every loader from reimplementing:

- record alignment;
- signedness rules;
- digest binding;
- result interpretation.

### 7.7 Integration With Existing Loaders

#### `libbpf`

`libbpf` integration should add:

- `jit_directives_fd` and `jit_directives_flags` to program-load options;
- an optional callback invoked after final CO-RE relocation and before each `BPF_PROG_LOAD`;
- a one-time support-state cache to avoid repeated probe retries.

Recommended callback shape:

```c
int (*prepare_jit_directives)(const struct bpf_insn *insns,
			      __u32 insn_cnt,
			      const struct bpf_program *prog,
			      int *fd_out,
			      __u32 *flags_out);
```

#### Cilium/Katran-Class Agents

The agent already owns:

- final program generation;
- rollout and rollback;
- map pinning;
- link replacement.

So the integration model is:

1. finalize the exact load image;
2. call `discover` and `select`;
3. pack the blob;
4. load once with directives;
5. if the kernel rejects the UAPI or ABI, retry without directives;
6. use structured telemetry to decide whether the policy remains enabled.

#### `bpftool`

`bpftool` should grow two debug-oriented commands:

- candidate dump:

```text
bpftool prog advise OBJ
```

- explicit load with directives:

```text
bpftool prog load OBJ PATH --jit-directives directives.json
```

These are not the steady-state production API.
They are for debugging, demos, and selftest bring-up.

### 7.8 Pinned Programs, Shared Maps, And Rollout

The advisor does not change the basic operational truth:

- a directive choice is fixed into the loaded program instance;
- changing policy means loading a new program instance and switching attachments.

So the real rollout model is:

1. keep maps pinned and ABI-compatible across versions;
2. generate a new exact pre-verifier image and a new digest-bound blob;
3. load the new program instance;
4. atomically switch links or attachments where the attach type supports it;
5. roll back by restoring the old link target.

This is versioned program replacement.
It is not "update a JSON DB and the kernel adapts in place."

v7 makes that explicit.

### 7.9 Mixed Loader Reality

The exact-image requirement means:

- the component that finalizes the image must also own advisory generation or delegate it synchronously to a sidecar that sees that exact image;
- two loaders that produce semantically equivalent but bytewise different pre-verifier programs will not share blobs.

This is a constraint, not a bug.
It is the price of exact digest safety.

Operationally:

- loader fleets need one directive-aware finalization path per loader family;
- policy DB distribution alone is not sufficient.

### 7.10 Telemetry Feedback Loop

Structured results are a first-class part of the advisor workflow.

Feedback loop:

1. load with directives;
2. fetch `bpf_prog_info` structured results;
3. join results with `(logical_program_id, prog_digest, site_id, policy_id, policy_version)`;
4. compare acceptance and rejection rates across canaries;
5. correlate with application throughput, latency, branch-miss, or CPU counters;
6. keep, refine, or roll back the policy.

Without this loop, "userspace policy" is just a static offline heuristic.

### 7.11 Minimal Policy Artifact

The earlier interface draft used JSON examples.
v7 keeps JSON only as a minimal experiment artifact.

Production expectations:

- a versioned signed artifact;
- per-kernel or per-fleet support caching;
- clear provenance and rollback metadata.

The kernel ABI does not depend on that representation.
But the system story does.

## 8. Evaluation Plan

Sources for this section:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`

### 8.1 Evaluation Principles

The evaluation must answer reviewer attacks, not just show speedups.

v7 evaluation has four layers:

1. mechanism isolation;
2. policy differentiation;
3. external validity on real programs;
4. deployment realism.

If any layer is missing, the paper becomes vulnerable to a simpler alternative explanation.

### 8.2 Research Questions

RQ1:

- Can the Hybrid mechanism safely adopt both verifier-stage structural rewrites and JIT-stage target-specific lowerings?

RQ2:

- Does userspace policy differ across CPU, workload, and program context in a way that fixed kernel policies do not capture?

RQ3:

- Are the accepted-site counts on real programs high enough to matter outside synthetic microbenchmarks?

RQ4:

- Does the system remain operationally viable under real loader, pinned-map, and rollback constraints?

RQ5:

- What load-time overhead and reject/drop behavior does the system impose?

### 8.3 Baseline Matrix

The mandatory baseline set is:

| Baseline | Purpose |
| --- | --- |
| stock kernel JIT | control |
| `kernel-wide-load` | tests whether local substrate recovery can simply be upstreamed |
| `kernel-fixed-cmov` | tests whether fixed in-kernel branchless lowering is enough |
| `kernel-fixed-layout` | tests whether fixed kernel layout policy can match userspace-guided `branch_reorder` |
| `advisor-static` | uses CPU contract only |
| `advisor-profiled` | uses CPU plus workload class |
| llvmbpf / LLVM JIT | upper-bound backend comparison |

This matrix is not optional.
The fixed-kernel baselines are the falsification experiment.

### 8.4 Microbenchmarks

The base mechanism-isolation suite remains:

- the authoritative 31 pure-JIT microbenchmarks;
- the existing 9 runtime-sensitive microbenchmarks.

v7 uses them to isolate:

- `wide_load`;
- `cmov_select`;
- `branch_reorder`;
- `wide_store`;
- `rotate_fusion`;
- `lea_fusion`.

Supplemental dedicated microbenchmarks from the directive-discovery work remain useful for scope-specific probes:

- `packet_redundant_bounds`
- `struct_field_cluster`
- `smallmul_strength_reduce`
- `map_lookup_repeat`
- `const_fold_chain`

Important interpretive rule:

- the supplemental suite is for mechanism understanding and candidate screening;
- it is not sufficient evidence for the paper's core systems claim.

### 8.5 Directive Ablation

Every v1 directive must support:

- enabled;
- disabled;
- isolated enablement where possible.

Required ablations:

| Ablation | Purpose |
| --- | --- |
| `wide_load` only | substrate recovery |
| `cmov_select` only | policy-sensitive lowering |
| `branch_reorder` only | structural verifier rewrite |
| `wide_store` only | low-risk breadth |
| `rotate_fusion` only | x86 feature-gated breadth |
| `lea_fusion` only | x86 address-combine breadth |
| all verifier-stage only | measure effect of Path-B-style half alone |
| all JIT-stage only | measure effect of Path-A-style half alone |
| full Hybrid | measure combined value |

This is how v7 will answer whether Hybrid is actually better than either half alone.

### 8.6 Fixed Kernel Baselines Are Critical

This is the most important experimental requirement in the entire design.

For each directive family:

- implement the obvious fixed kernel heuristic;
- compare it against the userspace-guided policy;
- do so across multiple hardware and workload classes.

Examples:

`kernel-wide-load`

- always fuse any legal stack/map-value byte ladder.

`kernel-fixed-cmov`

- always convert any legal narrow select diamond to `cmov` on x86 or `csel` on arm64.

`kernel-fixed-layout`

- apply a fixed branch-layout policy for the same one-diamond shapes targeted by `branch_reorder`.

The paper's core claim fails if these baselines recover the same gains everywhere.

### 8.7 Real-Program Evaluation

The existing real-program corpus must be used much more aggressively than in earlier drafts.

Required real-program reporting:

- 36 unique real programs for candidate census and acceptance rates;
- per-directive candidate counts;
- per-directive acceptance and rejection reasons;
- code-size deltas on the 36-program corpus;
- execution-time results on the available 14 unique real-program execution cases.

Additional required slices:

- single-function versus multi-function programs;
- packet-heavy versus map-heavy versus tracing-heavy programs;
- per-subprog candidate density.

This is how v7 escapes the "microbenchmark-only" critique.

### 8.8 End-To-End Deployment

At least one real deployment class is required.

Accepted targets:

- Cilium datapath;
- Katran-class XDP load balancer;
- another production-like BPF deployment with:
  - a privileged control process;
  - pinned or shared maps;
  - versioned link replacement;
  - real or replayed traffic.

Minimum end-to-end measurements:

- throughput or latency;
- load-time overhead;
- acceptance/rejection telemetry;
- rollback time and semantics;
- map-sharing correctness across versions.

Without this, the system remains a compiler-mechanism paper rather than a systems paper.

### 8.9 Multi-Hardware Plan

The evaluation matrix must include:

1. one modern wide OoO x86 system;
2. one smaller-core or efficiency-oriented x86 system;
3. one arm64 system.

Reasons:

- `cmov_select` is the strongest hardware-sensitive case;
- verifier-stage directives should generalize across both x86 and arm64;
- the repo already has CI infrastructure for x86 and arm64, so the architecture split should not remain purely aspirational.

The x86-only local-fusion directives may remain x86-only in the first implementation.
The evaluation should still show that the verifier-stage half and the Hybrid split are not x86-specific ideas.

### 8.10 Overhead Measurement

Load-time overhead is mandatory.

Required metrics:

- blob size distribution;
- parse time;
- digest time;
- remap time;
- verifier-stage rewrite time;
- JIT-stage validation time;
- structured logging overhead;
- extra kernel memory retained per program;
- rejection and drop rates by kind and reason.

Runtime overhead measurement:

- there should be none outside the effect of the chosen code shape;
- the paper still must report if any residual runtime bookkeeping remains.

### 8.11 Deployment-Policy Evaluation

To support the fleet-management argument, the evaluation must show:

1. two policy versions for the same logical program;
2. a canary rollout to a subset of machines or processes;
3. structured acceptance telemetry for both versions;
4. application-level or PMU-level performance comparison;
5. rollback without service interruption.

Otherwise "fleet A/B testing" is still just framing.

### 8.12 Falsification Condition

The falsification condition is mandatory and must appear in the paper:

> If the fixed kernel baselines match the userspace-guided Hybrid system across the tested CPU, workload, and program matrix, then the correct conclusion is to use kernel-local heuristics or kernel patches, not to deploy the userspace-guided interface.

That sentence is not for rhetoric.
It defines the meaning of a negative result.

### 8.13 Success Criteria For v7

The system is a publishable Hybrid design only if all of the following hold:

1. at least one verifier-stage structural directive shows real value;
2. at least one JIT-stage or Hybrid directive shows genuine policy sensitivity;
3. fixed kernel baselines lose in at least some meaningful cases;
4. real programs show non-trivial candidate density and acceptance;
5. one end-to-end deployment shows the operational story is real.

If any of these fail, the framing must be narrowed.

## 9. OSDI Reviewer FAQ

Sources for this section:

- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`

### 9.1 "Why Not Just Add These Peepholes To The Kernel?"

That is the correct question for `wide_load`, `wide_store`, `rotate_fusion`, and `lea_fusion` when viewed in isolation.
v7 does not pretend otherwise.

The framework still matters for three reasons:

1. `cmov_select` is policy-sensitive.
   - the same legal select site can want `cmov`, `csel`, or a retained branch depending on CPU and workload.
2. `branch_reorder` is structural.
   - it belongs in the verifier because the current JIT does not have a block scheduler.
3. the paper's claim is falsifiable.
   - if the fixed kernel baselines recover the same gains, the framework loses.

So the honest answer is:

- yes, some directives should probably become ordinary kernel heuristics eventually;
- the system contribution exists only if Hybrid covers policy-sensitive and structural cases that fixed kernel policy does not fully subsume.

### 9.2 "Why Not Just Use llvmbpf Or LLVM?"

Because the problem being solved is not "LLVM is missing."
The problem is that many deployments retain the kernel verifier/JIT model for correctness, compatibility, and ownership reasons.

llvmbpf remains:

- an upper bound;
- an important competitor;
- a required baseline.

v7 remains justified only if:

- the deployment wants to keep the kernel JIT model;
- the Hybrid interface preserves that model;
- the resulting policy advantages matter operationally.

If a deployment can replace the kernel JIT with LLVM and is satisfied, that is a simpler answer.
The paper should say so.

### 9.3 "Why Not Extend BPF Bytecode With `BPF_SELECT` Or `BPF_WIDE_LOAD`?"

That alternative is stronger when the useful transform set is tiny and permanent.

v7's answer is:

- new bytecodes permanently change the BPF ISA, compiler pipeline, verifier semantics, and portability envelope;
- directives are optional and deployment-scoped;
- directives allow policy changes without requiring every compiler and every kernel producer to adopt new semantic bytecodes.

This answer is strongest for:

- `cmov_select`, where the best lowering really is deployment-sensitive;
- `branch_reorder`, where the transform is structural but still not something we want exposed as user ISA.

It is weaker for:

- `wide_load`, which really may be a better kernel or ISA-local optimization in the long run.

### 9.4 "Why Not Use Compiler Hints Or BTF Annotations?"

Because they live too early.

They do not see:

- the final pre-verifier image actually passed to the kernel;
- verifier-retained pointer and range facts;
- the final subprogram structure after verifier processing;
- deployment-time workload class;
- canary and rollback policy.

Hints may still be useful in the future as one input to userspace policy.
They are not a replacement for the v7 mechanism.

### 9.5 "Why Not Use PGO Or AutoFDO?"

This is a real conceptual competitor, especially for layout and select profitability.

The answer is not that PGO is irrelevant.
The answer is:

- PGO solves profitability selection in ordinary compiler pipelines;
- the kernel JIT does not currently have a safe, bounded, deployment-owned path to consume that information;
- BPF deployment owners want that path without replacing the kernel execution model.

So v7 is best understood as:

- a bounded mechanism to import deployment-specific backend policy into the kernel JIT path.

If kernel-fixed profile-guided heuristics are enough, the v7 mechanism loses.

### 9.6 "Isn't This Just PGO For BPF?"

No, but it is adjacent.

Key differences:

- the kernel still owns verification and final emission;
- directives are digest-bound to one exact BPF image;
- legality remains kernel-local and fail-closed;
- the policy owner is the deployment operator, not an in-process runtime or compiler service;
- the interface can consume non-profile deployment information such as fleet rollout class and hardware class.

So the closest analogy is not generic PGO.
It is "deployment-owned bounded backend policy for a kernel JIT."

### 9.7 "Does Constant Blinding Kill The Design?"

It kills pure Path A much more than Hybrid.

Under v7:

- verifier-stage directives still work because they rewrite BPF before blinding;
- local JIT-stage fusions are still disabled on blinded programs in v1;
- `cmov_select` is also disabled on blinded programs in v1, because blinding rewrites the cloned BPF stream before `do_jit()` and v1 does not yet rebase select plans through that rewrite.

So the v7 answer is:

- blinding remains a real implementation and deployment constraint;
- it no longer forces whole-blob abandonment.

That is a material design improvement over v6.

### 9.8 "Is The Evidence Just Microbenchmarks?"

It cannot be.

v7 explicitly requires:

- the 36 unique real-program corpus;
- the 14 unique real-program execution cases;
- one end-to-end deployment;
- fixed kernel baselines;
- load-time overhead measurement.

If those experiments are not run, the paper should not claim systems-level external validity.

### 9.9 "Why Userspace At All?"

The strongest reasons remain:

- updateability without kernel upgrades;
- workload-specific profitability selection;
- program-level policy budgeting;
- canary and rollback control;
- ownership by the service/operator rather than the upstream kernel.

These reasons are independent of whether a given directive family eventually also deserves a kernel heuristic.

### 9.10 "Is The Verifier Now Too Big A TCB?"

The TCB does grow.
v7 does not deny that.

The mitigation is scope discipline:

- verifier-stage v1 rewrites are narrow and exact;
- no v1 duplication;
- no v1 cross-subprog transform;
- no arbitrary internal opcode exposed to the interpreter;
- strong fail-closed semantics;
- structural rewrites placed before later stock fixups, not after them.

The design would become much less defensible if v1 tried to include `subprog_inline` or generic dataflow transforms.

## 10. Design Decisions Log

Sources for this section:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/bpf-jit-advisor-v6.md`
- `docs/tmp/verifier-rewrite-approach.md`
- `docs/tmp/interface-design-detail.md`
- `docs/tmp/interface-design-review.md`
- `docs/tmp/cross-document-review.md`
- `docs/tmp/osdi-readiness-review.md`
- `docs/tmp/bpf-jit-advisor-v6-review.md`

This table records the major design decisions from v4 through v7.

| Iteration | Decision | Final choice in v7 | Rationale |
| --- | --- | --- | --- |
| v4 | target-independent replacement IR | rejected | too heavy, wrong abstraction, weak safety story |
| v5 | microarchitecture-specific directive framing | retained but broadened | useful for profitability, insufficient alone for structural transforms |
| v5r2 | narrow local-region validator model | retained for JIT-stage directives only | still the right substrate for local fusion |
| v5r2 | `wide_load` as headline contribution | demoted to substrate case | important recovery, weak novelty anchor by itself |
| v5r2 | narrow `cmov_select` | retained and frozen | first real policy-sensitive case, but must stay narrow |
| v5r2 | `cmov_select` expression-valued arms | rejected for v1 | contract drift made soundness vague |
| v5r2 | digest binding to exact pre-verifier image | retained | correct safety anchor |
| v5r2 | `orig_idx` remap bridge | retained and strengthened | required for any post-verifier mapping |
| v5r2 | whole-blob drop on constant blinding | revised | too limiting under Hybrid |
| v6 | mechanism/policy separation as main paper claim | retained | still the core systems idea |
| v6 | five why-userspace reasons | retained with tighter evidence bar | still the right framing, but needs stronger evaluation |
| v6 | third novelty-carrying family required | retained | two local directives are not enough for OSDI/SOSP |
| v6 | `branch_reorder` as a JIT-stage v1 target | rejected | current JIT is linear and not a natural block scheduler |
| v6 | `hot_fallthrough` sketch with duplication | rejected for v1 | canonical-PC semantics not frozen |
| v6 | `subprog_inline` near-term | rejected for v1 | requires a different mechanism class and re-verification |
| interface draft | load-time-only transport | retained | correct scope discipline |
| interface draft | sealed `memfd` transport | retained | explicit immutable object across cooperating loader components |
| interface draft | `BPF_PROG_LOAD` extension via `jit_directives_fd` | retained | minimal integration point |
| interface draft | no explicit stage field | rejected | Hybrid requires stage-aware ownership and telemetry |
| interface draft | records sorted by `(subprog_id, orig_start_off, orig_end_off)` | revised to include stage | stage-aware processing and non-overlap |
| interface draft | `wide_load.base_off` unsigned | rejected | negative stack offsets must be explicit |
| interface draft | `value_ref.imm` unsigned | rejected | signed immediates must be explicit |
| interface draft | simplified "verify, remap, emit" pipeline | rejected | real kernel path includes `jit_subprogs()`, blinding, convergence loop |
| interface draft | whole-blob non-fatal drop for any blinding | revised | verifier-stage directives must survive blinding |
| cross-doc review | minimal JIT-level v1 should add `wide_store`, `rotate_fusion`, `lea_fusion` | retained | low-risk breadth on the local-fusion substrate |
| cross-doc review | packet/ctx load widening belongs to verifier stage | retained | strongest production case requires verifier facts |
| cross-doc review | `bounds_window` only one guard at a time | retained | safe, bounded, and reviewable |
| OSDI review | fixed kernel baselines are mandatory | retained | they are the falsification experiment |
| OSDI review | one end-to-end deployment is mandatory | retained | otherwise the system story is incomplete |
| OSDI review | unresolved Path A vs Path B is a blocker | resolved in v7 | Hybrid is now the explicit answer |
| verifier-rewrite analysis | `branch_reorder` is the strongest Path-B case | retained | structurally beyond the JIT peephole layer |
| verifier-rewrite analysis | `cmov_select` is best split across verifier and JIT | retained | canonical Hybrid example |
| verifier-rewrite analysis | verifier rewrite stage should run before `convert_ctx_accesses()` and `do_misc_fixups()` | retained | later stock fixups should operate on rewritten BPF |
| JIT implementation analysis | `do_jit()` fast path is right for local fusion | retained | pass-stable, minimal change, clear `addrs[]` model |
| JIT implementation analysis | pass-local dynamic rediscovery inside `do_jit()` | rejected | breaks convergence and makes acceptance pass-dependent |
| JIT implementation analysis | `addrs[]` collapse rule for fused regions | retained and made explicit | correctness hinge for JIT-stage directives |
| JIT implementation analysis | local-fusion directives on blinded programs | rejected in v1 | shape instability after blinding |
| v7 | verifier-stage directives survive blinding | adopted | Hybrid advantage over Path A |
| v7 | `cmov_select` is fail-closed on blinded programs until plan rebasing exists | adopted for v1 | blinding rewrites the cloned BPF stream before `do_jit()`, so copied side state alone is not enough |
| v7 | verifier-stage `branch_reorder` forbids duplication | adopted | avoids undefined canonical-PC semantics in v1 |
| v7 | capability probing remains cached load-time retry rather than a separate new UAPI | adopted for v1 | enough for the prototype, keeps scope bounded |
| v7 | arm64 support requirement | partial | verifier-stage directives and `cmov_select` are architecturally shared; x86-only local fusions remain acceptable in first implementation |

### 10.1 Final v7 Position

The final v7 position is concise:

- keep exact-image, fail-closed, load-time transport;
- move structural transforms into the verifier;
- keep target-specific lowering in the JIT;
- freeze `cmov_select` to the narrow contract;
- treat `wide_load` as a substrate case, not the novelty anchor;
- use `branch_reorder` as the first strong structural proof case;
- evaluate against fixed kernel baselines and real deployments or do not make the stronger paper claim.

That is the design to implement.
