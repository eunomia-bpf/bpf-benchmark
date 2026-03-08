# BPF JIT Advisor v5r2

## 1. Thesis

v5r2 narrows the design to the version we can realistically build and defend:

- privileged userspace supplies **bounded, arch-neutral JIT directives** for one exact pre-verifier BPF image;
- the kernel owns **legality only**: digest binding, verifier-remap, retained-fact checks, shared template validation, CPU gating, logging, and fail-closed fallback;
- userspace owns **profitability only**: candidate discovery, CPU/workload policy, and directive generation;
- the directive substrate is **arch-neutral**, while per-architecture code is limited to native emitters;
- the prototype implementation is **x86-64 only** and implements **two directives only**: `wide_load` and `cmov_select`.

This is not a generic optimization language. It is a reusable transport/remap/validation substrate for a small family of backend decisions, some of which still belong as kernel peepholes and some of which genuinely need userspace policy.

## 2. What Changed From v5

v5r2 makes five explicit corrections.

1. The prototype is cut to `wide_load` and `cmov_select`. `diamond_layout` and `rotate_fusion` move to future work.
2. The microarchitecture story is centered on a real policy split: the same BPF program may receive different directives on different CPUs or workload profiles.
3. The paper no longer hand-waves past kernel-only peepholes. We will implement direct-kernel baselines and require the advisor to beat them where policy matters.
4. Verifier interaction is specified as concrete kernel work, not “plumbing”: `orig_idx` propagation, retained memory facts, and explicit constant-blinding behavior.
5. The security model is narrowed: `CAP_BPF + CAP_PERFMON` (or equivalent token authority), explicit side-channel posture, and hard scope limits against arbitrary JIT steering.

## 3. Claims And Non-Claims

### 3.1 Claim

The paper’s claim is:

> backend profitability policy should live in userspace, while the kernel JIT should own only legality and fail-closed adoption.

This split is useful because profitability depends on hardware and workload, while legality is stable and kernel-local.

### 3.2 Non-claims

v5r2 explicitly does **not** claim:

- a target-independent IR contract;
- a generic optimization DSL;
- open-ended extensibility;
- stable portable directive artifacts;
- compatibility with every existing JIT hardening path in v1.

Every new directive kind still needs a small kind-specific validator, one emitter per supported architecture, selftests, and sometimes new retained facts. The reusable part is the envelope around those consumers: blob format, transport, remap, CPU gating, shared precondition checks, fail-closed behavior, and logging.

## 4. Why This Is Not “Just Add Peepholes”

The review is correct that `wide_load` alone does not justify a new UAPI. A direct x86 peephole is a strong alternative there.

The design is justified only if it cleanly separates two jobs:

- **Kernel legality**: is this transformation safe on the post-verifier program?
- **Userspace profitability**: is this transformation faster on this CPU for this workload?

That separation matters most for `cmov_select`.

- On modern wide OoO cores, `cmov` often wins when the branch is hard to predict because it removes mispredicts.
- On Atom-class cores and some older AMD cores, `cmov` can lose because it creates a longer data-dependency chain and the branch predictor penalty is lower than the dependency cost for predictable branches.
- Even on one CPU, the right choice changes with workload: the same compare/select site may want `cmov` for random keys and a branch for sorted keys.

The kernel JIT should not accumulate heuristics such as:

- “use `cmov` on Arrow Lake if branch-miss rate exceeds X”;
- “disable `cmov` on Atom-like cores except for this opcode subset”;
- “only use 8-byte wide loads on this CPU if alignment is at least Y.”

Those are profitability policies. They change with new CPUs, new measurements, and new workloads. Userspace can update them without kernel patches; the kernel cannot do that cleanly.

### 4.1 Directive-By-Directive Answer

The honest answer is not “every directive belongs in userspace.” Some are better as kernel peepholes. The framework is valuable because it provides one shared substrate for the subset that really needs userspace profitability policy while still letting us measure kernel-only alternatives directly.

| Directive | Scope | µarch dependency | Better as | Why |
| --- | --- | --- | --- | --- |
| `wide_load` | prototype scope | weak | mostly a kernel peephole | legality is local, workload sensitivity is low, and a fixed x86 rule may be good enough. It stays in v1 because it exercises the full transport/remap/retained-fact path and provides the mandatory baseline-recovery case. |
| `cmov_select` | prototype scope | strong | userspace directive | the same legal diamond can prefer `cmov` or a branch depending on CPU family and workload predictability. This is the clearest case where fixed in-kernel heuristics are the wrong abstraction boundary. |
| `wide_store` | future work | weak | mostly a kernel peephole | like `wide_load`, the transform is highly local and mostly legality-driven. It is worth tracking as a directive candidate because it can reuse the same substrate, not because it independently justifies a new UAPI. |
| `rotate_fusion` | future work | medium | mixed, leaning kernel peephole | it is a local rewrite with some feature dependence (`BMI`/`BMI2`, flag behavior), but that likely fits a small in-kernel table unless characterization shows real cross-CPU policy divergence. |
| `lea_fusion` | future work | weak | kernel peephole | this is classic backend combine logic with little workload policy content. If implemented, it should probably start life as a normal JIT peephole. |
| `branch_hint` | future work | strong | userspace directive | block layout and fall-through decisions depend on hotness, predictability, and front-end behavior. The kernel should not own benchmark-specific layout policy tables. |

The framework’s value is therefore twofold:

- it gives us one shared legality/fail-closed path for all local backend directives; and
- it keeps the door open for the small subset, led by `cmov_select` and potentially `branch_hint`, that truly needs userspace policy.

### 4.2 Mandatory Baseline

v5r2 therefore requires a direct-kernel comparison in the evaluation:

- `kernel-wide-load`: an x86 JIT peephole that always uses wide loads when legal;
- `kernel-fixed-cmov`: an x86 JIT peephole with a fixed kernel policy, either “always `cmov` when legal” or one built-in CPU table.

If the advisor does not beat these baselines on at least one meaningful workload, then the right outcome is kernel peepholes, not a new interface.

## 5. Microarchitecture-Dependent Policy Model

The policy is no longer “hints with a CPU label.” The userspace advisor computes:

```text
decision = policy(kind, cpu_profile, workload_profile, site_features)
```

Where:

- `cpu_profile` is vendor/family/model/features plus an advisor policy DB version;
- `workload_profile` is optional branch predictability / hotness information from a training run or benchmark manifest;
- `site_features` are extracted from the finalized BPF program.

The kernel does **not** evaluate this function. It only validates legality for any directive that userspace decided to request.

### 5.1 Why `cmov_select` Must Be Per-CPU And Per-Workload

For a select-shaped diamond:

```c
if (cond)
	r0 = a;
else
	r0 = b;
```

the advisor may make different choices for the same BPF site.

| Same BPF site | CPU / workload profile | Directive choice | Reason |
| --- | --- | --- | --- |
| `binary_search` select | Arrow Lake, random keys | emit `cmov_select` | branch is hard to predict; avoiding mispredicts wins |
| `binary_search` select | Arrow Lake, sorted keys | no directive | branch is predictable; `cmov` only lengthens the dependency chain |
| `binary_search` select | Atom-like profile, random keys | no directive | shallow OoO and higher dependency cost make `cmov` unattractive |

This is the paper’s strongest microarchitecture evidence. The same verified BPF program should produce different directive blobs across these cases.

### 5.2 Why `wide_load` Is Still Policy-Carrying

`wide_load` is less workload-sensitive than `cmov_select`, and on many modern x86 cores it will usually be selected when legal. That is fine; the document should be honest that `cmov_select` carries most of the microarchitecture story.

But `wide_load` is still not completely policy-free:

- CPUs differ in how tolerant they are of unaligned 8-byte loads;
- the cost of line splits and replay behavior differs across cores;
- userspace may choose stricter alignment thresholds on smaller or older cores.

Example:

| Same BPF site | CPU profile | Directive choice |
| --- | --- | --- |
| 8-byte byte-recompose from stack/map value | Arrow Lake | emit `wide_load(width=8, min_align_log2=0)` |
| same site | Atom-like profile | emit only if `min_align_log2 >= 3`, otherwise no directive |

The kernel does not decide whether `min_align_log2=0` is profitable. Userspace does.

### 5.3 Policy Inputs

The initial policy DB uses two inputs.

1. Static CPU profile
   - vendor / family / model;
   - ISA features;
   - offline calibration data.
2. Optional workload profile
   - branch predictability bucket for select diamonds;
   - benchmark or training-run class, such as `predictable`, `mixed`, or `unpredictable`.

v1 does not require a new kernel feedback API. The workload profile can come from:

- a deterministic benchmark manifest for controlled experiments;
- a training run using existing perf tooling when available.

## 6. Scope

### 6.1 In Scope For The Prototype

- x86-64 only;
- `BPF_PROG_LOAD` transport with a sealed `memfd`;
- automated userspace directive generation;
- `wide_load`;
- `cmov_select`;
- verifier remap through preserved `orig_idx`;
- retained memory facts for `wide_load`;
- per-directive logging and rejection statistics.

### 6.2 Explicitly Out Of Scope

- `wide_store`;
- `diamond_layout`;
- `branch_hint`;
- `rotate_fusion`;
- `lea_fusion`;
- arbitrary native code injection;
- target-independent replacement IR;
- packet / ctx / `PROBE_MEM` wide loads;
- offloaded BPF;
- per-core heterogeneous-policy selection inside the kernel;
- directive support on the constant-blinding path.

## 7. End-To-End Flow

```text
finalized pre-verifier BPF image
  -> userspace advisor
       - discover candidates automatically
       - compute site features
       - consult CPU/workload policy DB
       - emit directive blob
       - seal blob into memfd
  -> BPF_PROG_LOAD(jit_directives_fd=fd)
  -> kernel parses blob, checks digest and CPU contract
  -> verifier runs normally
       - preserves orig_idx through rewrites
       - records retained mem facts for covered sites
  -> post-verifier remap
  -> shared validator checks exact templates and produces a lowering plan
  -> x86 emitter adopts or rejects each directive
  -> rejected directives fall back to stock emission
```

Manual YAML remains useful for debugging and selftests, but the paper evaluation will use the automated generator, not hand-written directives.

## 8. Kernel Interface

### 8.1 `BPF_PROG_LOAD` Extension

The interface remains an optional blob FD:

```c
struct {
	...
	__s32  jit_directives_fd;
	__u32  jit_directives_flags;
};
```

Recommended flags:

- `BPF_F_JIT_DIRECTIVES_STRICT_CPU`
- `BPF_F_JIT_DIRECTIVES_LOG`

The blob FD must be a sealed `memfd` with:

- `F_SEAL_WRITE`
- `F_SEAL_SHRINK`
- `F_SEAL_GROW`

### 8.2 Capability Requirement

Directive use requires:

- `CAP_BPF`; and
- `CAP_PERFMON`;
- or an equivalent delegated BPF token policy.

Why both:

- `CAP_BPF` already gates privileged BPF load behavior;
- `CAP_PERFMON` reflects that the feature is driven by performance profiling and intentionally changes timing, speculation, and cache behavior.

Unprivileged BPF never gets this interface.

### 8.3 CPU Binding

The blob carries a CPU contract. The kernel checks:

- architecture;
- required / forbidden features;
- optional exact vendor / family / model match in strict mode.

On mismatch:

- strict mode rejects the load;
- non-strict mode loads the program but drops the blob.

### 8.4 Heterogeneous Systems

v1 assumes one homogeneous execution domain.

- If online CPUs do not satisfy one common CPU contract, strict blobs are rejected.
- On hybrid x86 systems, the evaluation must run on a homogeneous host or a homogeneous VM/cpuset configuration.
- Per-core or per-cpuset directive selection is future work.

## 9. Blob Format

The blob stays compact and binary. The header and common record layout are arch-neutral; only the final emitter is architecture-specific. v1 still defines only two directive kinds.

### 9.1 Blob Header

```c
#define BPF_JIT_ADV_MAGIC 0x424a4156 /* "BJAV" */

enum bpf_jit_arch {
	BPF_JIT_ARCH_X86_64 = 1,
	BPF_JIT_ARCH_ARM64  = 2, /* future emitter */
};

struct bpf_jit_cpu_contract {
	__u32 arch;
	__u32 vendor;
	__u32 family;
	__u32 model;
	__u32 stepping_mask;
	__u64 required_features[2];
	__u64 forbidden_features[2];
	__u64 policy_id;      /* opaque userspace policy DB id */
	__u32 policy_version;
	__u32 workload_class; /* opaque userspace label for logging */
};

struct bpf_jit_adv_blob_hdr {
	__u32 magic;
	__u16 version;
	__u16 hdr_len;
	__u32 total_len;
	__u32 nr_directives;
	__u32 flags;
	__u32 orig_insn_cnt;
	__u8  prog_digest[32];
	struct bpf_jit_cpu_contract cpu;
	__u32 dir_off;
	__u32 reserved;
};
```

### 9.2 Common Directive Header

```c
enum bpf_jit_dir_kind {
	BPF_JIT_DIR_WIDE_LOAD   = 1,
	BPF_JIT_DIR_CMOV_SELECT = 2,
	/* future: WIDE_STORE, ROTATE_FUSION, LEA_FUSION, BRANCH_HINT */
};

enum bpf_jit_precond_bits {
	BPF_JIT_PC_STRAIGHT_LINE      = 1U << 0,
	BPF_JIT_PC_ONE_DIAMOND        = 1U << 1,
	BPF_JIT_PC_NO_INTERIOR_TARGET = 1U << 2,
	BPF_JIT_PC_NO_CALLS           = 1U << 3,
	BPF_JIT_PC_NO_STORES          = 1U << 4,
	BPF_JIT_PC_CONST_OFFSET_MEM   = 1U << 5,
	BPF_JIT_PC_SAME_BASE_MEM      = 1U << 6,
};

struct bpf_jit_dir_rec {
	__u16 kind;
	__u16 len;
	__u16 subprog_id;
	__u16 flags;
	__u32 orig_start_off;
	__u32 orig_end_off; /* exclusive */
	__u32 precond_mask;
	__u32 site_id;      /* opaque userspace site id for logging */
	__u64 required_features[2];
	__u64 forbidden_features[2];
};
```

Rules:

- coordinates are in the finalized pre-verifier image;
- directives are sorted and non-overlapping in original coordinates;
- ranges stay within one subprogram;
- max blob size in v1: 64 KiB.

### 9.3 `wide_load`

```c
enum bpf_jit_mem_class {
	BPF_JIT_MEM_STACK     = 1,
	BPF_JIT_MEM_MAP_VALUE = 2,
};

struct bpf_jit_dir_wide_load {
	__u8 width;          /* 4 or 8 */
	__u8 mem_class;
	__u8 dst_reg;
	__u8 base_reg;
	__s16 base_off;
	__u8 min_align_log2;
	__u8 liveout_reg;
};
```

### 9.4 `cmov_select`

```c
enum bpf_jit_val_kind {
	BPF_JIT_VAL_REG = 1,
	BPF_JIT_VAL_IMM = 2,
};

struct bpf_jit_value_ref {
	__u8 kind;
	__u8 reg;
	__u16 reserved;
	__s32 imm;
};

struct bpf_jit_dir_cmov_select {
	__u8 cc;
	__u8 width;    /* 32 or 64 */
	__u8 dst_reg;
	__u8 lhs_reg;
	struct bpf_jit_value_ref rhs;
	struct bpf_jit_value_ref true_val;
	struct bpf_jit_value_ref false_val;
};
```

## 10. Verifier Interaction And Remap

This is required new verifier machinery, not a minor implementation detail.

### 10.1 Source Coordinate System

Userspace names ranges in the exact instruction stream passed to `BPF_PROG_LOAD`, after:

- CO-RE relocation;
- libbpf subprogram finalization;
- any userspace preprocessing before the syscall.

### 10.2 Required `orig_idx` Propagation

Today `orig_idx` is initialized once, but inserted aux slots are zeroed during rewrite expansion. In the current tree, `adjust_insn_aux_data()` keeps `seen` and `zext_dst` but not origin ownership. v5r2 changes that contract.

Required rule:

> whenever one original instruction is expanded into `N` post-rewrite instructions, every inserted instruction inherits the replaced instruction’s `orig_idx`.

Concretely, the verifier work is:

1. Keep initial `env->insn_aux_data[i].orig_idx = i`.
2. In `adjust_insn_aux_data()`:
   - save `old_orig = data[off].orig_idx`;
   - after expansion, assign `data[i].orig_idx = old_orig` for all `i` in the patched range.
3. Audit rewrite paths that go through `bpf_patch_insn_data()`, especially:
   - `convert_ctx_accesses()`;
   - `do_misc_fixups()`;
   - prologue / helper rewrite sites that expand instructions.
4. For rewrites that delete an original instruction, allow remap to become empty and reject the directive later.

This is enough for v1 because `bpf_patch_insn_data()` is already the common expansion path.

### 10.3 Retained Facts

v1 retains only the facts needed for `wide_load`. `cmov_select` is intentionally narrowed so that it consumes no new verifier state beyond existing CFG information and `zext_dst`.

New retained fact:

```c
struct bpf_jit_mem_fact {
	__u8 valid;
	__u8 mem_class;   /* stack or map value */
	__u8 align_log2;  /* lower bound on effective alignment */
	__u8 flags;       /* NONFAULTING, CONST_OFFSET, READONLY */
	__s16 const_off;
	__u16 min_readable;
};
```

Recording rule:

- the verifier records `bpf_jit_mem_fact` only for instructions whose `orig_idx` is covered by at least one directive range;
- hook in `check_mem_access()` after final legality is known;
- preserve the fact through rewrite expansion using the same origin rule above.

No full verifier-state snapshot is retained.

The same fact shape is intentionally enough for future `wide_store` validation as well. v1 still consumes it only for `wide_load`.

### 10.4 Post-Verifier Remap

After verification:

1. Find all post-verifier instructions whose preserved `orig_idx` lies in the directive’s original range.
2. Require the result to form one contiguous post-verifier interval.
3. Reject empty intervals.
4. Reject intervals that cross subprogram boundaries.
5. Reject overlaps after remap.

The kernel never trusts userspace-supplied post-verifier coordinates.

### 10.5 ALU32 / Zero-Extension Semantics

The review is right that this must be explicit.

- `wide_load(width=4)` uses x86 `movl`, which zero-extends exactly as stock lowering does.
- `cmov_select(width=32)` is accepted only when both arm assignments are 32-bit moves to the same destination and the validator sees the expected `zext_dst` behavior on those arm definitions.
- `cmov_select(width=64)` has no extra zero-extension constraint.

This keeps region-boundary semantics identical without a general equivalence proof.

### 10.6 Constant Blinding

The current constant-blinding path clones and rewrites the program after verification. v1 does **not** try to remap directives through that extra rewrite.

Rule:

- if `prog->blinding_requested` is true, the kernel drops the directive set and compiles the stock blinded program;
- the rejection reason is logged as `BPF_JIT_REJECT_CONST_BLINDING`.

This is a deliberate prototype limitation. Supporting directives on the blinded path is future work.

## 11. Shared Validation And Arch-Specific Emission

The current x86 JIT is a linear emitter built around `do_jit()` and `addrs[]`. v5r2 keeps that model for the prototype, but the directive consumer is split cleanly so that blob handling, remap, validation, fail-closed behavior, and logging are shared across architectures.

### 11.1 Arch-Neutral / Arch-Specific Split

| Layer | Responsibilities |
| --- | --- |
| Arch-neutral core | blob format, `BPF_PROG_LOAD` transport, digest binding, `orig_idx` remap, retained verifier facts, CPU gating, shared precondition checks, kind-specific validator logic, fail-closed fallback, and rejection logging |
| Arch-specific layer | emitter functions only: translate one already-validated directive plan into native instructions for that JIT |

For accepted directives:

- the shared validator produces one small arch-neutral lowering plan at the directive start;
- the selected architecture emitter produces one fused native sequence from that plan;
- covered BPF instructions share one native entry address in `addrs[]`;
- this is legal because v1 requires `BPF_JIT_PC_NO_INTERIOR_TARGET`.

No block reordering is introduced in v1. This is why `cmov_select` is feasible today and `branch_hint` remains future work.

### 11.2 Parameterized Directive Template

Instead of a fully ad-hoc validator per directive, the kernel should use one shared template descriptor plus a small kind-specific `validate()` and one emitter per supported architecture.

```c
struct bpf_jit_dir_template {
	enum bpf_jit_dir_kind kind;
	bool requires_aligned_access;
	bool requires_no_side_effects;
	bool requires_single_entry_exit;
	u8 min_insn_count;
	u8 max_insn_count;
	bool (*validate)(const struct bpf_prog *prog,
			 const struct bpf_jit_dir_rec *rec,
			 const struct bpf_jit_site *site,
			 struct bpf_jit_plan *plan);
};
```

Common helper logic enforces the shared preconditions before the kind-specific validator runs. The validator itself is still exact, but it only checks the remaining directive-specific shape and fills an arch-neutral `bpf_jit_plan`. Each architecture then registers only the matching `emit(plan)` hook for the kinds it supports. The intended incremental cost of a new directive is therefore small and localized:

- ~50-100 LOC of shared kind-specific validation on the common path;
- one similarly small emitter function per implemented architecture;
- no new blob, remap, CPU-gating, fail-closed, or logging machinery.

### 11.3 Same Directive, Different Native Instructions

The same directive payload and validator result should map to different native instructions without changing the legality contract.

| Directive | Shared validator proves | x86 emitter | arm64 emitter |
| --- | --- | --- | --- |
| `wide_load` | byte ladder from one base + constant offsets, nonfaulting, aligned enough, one liveout | `movl` / `movq` | `ldr wN` / `ldr xN` |
| `cmov_select` | one-entry/one-exit diamond, pure destination assignment, compare opcode/width match | `cmp` + `cmovcc` | `cmp` + `csel` |

For `cmov_select`, the shared validator decides only that the BPF region is a legal select. The x86 emitter lowers that plan to `cmovcc`; a future arm64 emitter lowers the same plan to `csel` after materializing immediates into registers when needed. Profitability policy still lives in userspace in both cases.

### 11.4 `wide_load` Validator

Accepted shape:

- straight-line byte-load recomposition only;
- one base register;
- constant offsets `base_off + i`;
- only byte loads, shifts by immediates, and ORs that build a 4-byte or 8-byte value;
- one final liveout register.

Kernel checks:

1. region is straight-line with no interior targets;
2. no calls, stores, atomics, helpers, tail calls, or exits;
3. all loads share the same base and constant-offset ladder;
4. retained `bpf_jit_mem_fact` says:
   - `mem_class` is `STACK` or `MAP_VALUE`;
   - access is nonfaulting;
   - offset is constant;
   - `min_readable >= width`;
   - `align_log2 >= min_align_log2`;
5. final liveout matches `liveout_reg`.

Emitter:

- x86 prototype: replace the byte ladder with one `movl` or `movq` from the same base object and constant offset;
- future arm64 emitter: replace it with one `ldr wN` or `ldr xN` from the same base object and constant offset;
- preserve destination register semantics exactly.

Rejected in v1:

- packet, ctx, arena, and `PROBE_MEM` accesses;
- any case that would need new extable behavior.

### 11.5 `cmov_select` Validator

Accepted shape:

- one-entry, one-exit diamond;
- entry instruction is one conditional jump;
- each arm assigns exactly one value to the same destination register;
- arm values are register or immediate;
- no side effects besides that destination assignment.

Kernel checks:

1. remapped region is exactly one select diamond with one join;
2. no calls, helpers, tail calls, exits, stack writes, atomics, or interior targets;
3. the compare opcode matches `cc`;
4. both arms assign the same `dst_reg`;
5. the assigned values match `true_val` and `false_val`;
6. no other register or memory state changes occur in either arm;
7. `CMOV` is present;
8. `width` is `32` or `64`, and the zero-extension rule above holds for `width=32`.

Because the arms are restricted to pure destination assignment, “all other liveouts are equal” follows trivially. v1 does not need a retained liveout mask for this directive.

Emitter:

- x86 prototype: emit `cmp`, materialize the false value in `dst`, then emit `cmovcc` of the true value into `dst`;
- future arm64 emitter: emit `cmp`, materialize both arm values in registers if needed, then emit `csel` into `dst`.

## 12. Automated Userspace Advisor

The paper evaluation must use deterministic automated generation. Manual directives are only for debugging.

### 12.1 Candidate Discovery

The advisor runs on the finalized pre-verifier image and finds:

- `wide_load` candidates via byte-load/shift/OR pattern matching;
- `cmov_select` candidates via CFG pattern matching for one-diamond selects.

The same discovery framework can later grow `wide_store`, `rotate_fusion`, `lea_fusion`, and `branch_hint` without changing the blob transport or remap path. v1 still emits only the first two kinds.

### 12.2 Site Features

For each candidate, userspace records:

- kind;
- width;
- compare opcode;
- value shape (`reg` / `imm`);
- memory class and constant-offset shape for `wide_load`;
- alignment bucket for `wide_load`;
- optional workload predictability bucket for `cmov_select`.

### 12.3 Policy Engine

Initial policy form:

```text
if kind == CMOV_SELECT:
    if cpu_profile in atom_like:
        reject
    if workload_predictability == predictable:
        reject
    accept

if kind == WIDE_LOAD:
    if not legal_candidate_shape:
        reject
    if align_log2 < cpu_policy.min_align_for(width, mem_class):
        reject
    accept
```

This policy is intentionally simple and lives entirely in userspace.

### 12.4 Output

The advisor packs accepted directives into the binary blob, seals a `memfd`, and passes the FD into `BPF_PROG_LOAD`.

## 13. Security Model

### 13.1 Threat Model

This feature adds a real JIT control surface. Even without native code injection, it changes:

- timing;
- branch predictor behavior;
- cache footprint;
- speculation behavior.

The design therefore treats directive use as privileged performance steering, not as a harmless hint.

### 13.2 Fail-Closed Rules

On any failure, the kernel falls back to stock JIT emission. Directives must never:

- change verifier acceptance;
- introduce new memory classes or wider memory footprints than the verifier proved;
- span helpers, tail calls, exits, subprogram-call boundaries, exception boundaries, or speculation-sensitive fixup sites;
- inject native code.

### 13.3 Scope Limits Against API Creep

v1 keeps the interface narrow by rule:

- only two directive kinds exist;
- payloads are declarative, not procedural;
- each kind maps to one shared kernel validator shape and one emitter per supported architecture;
- new kinds require separate proof obligations, selftests, and review.

There is no free-form replacement encoding, no arbitrary block scheduler, and no “native patch” mode.

### 13.4 Side-Channel Posture

The interface is not a side-channel mitigation. It is allowed to change observable timing for privileged users.

That is acceptable because:

- privileged BPF JIT already changes timing across kernels and architectures;
- this interface is gated by `CAP_BPF + CAP_PERFMON`;
- v1 exposes no runtime feedback channel in the kernel and no unprivileged access.

## 14. Evaluation Plan

The evaluation must answer exactly the review’s objections.

### 14.1 Baselines

Required baselines:

1. stock kernel JIT;
2. `kernel-wide-load` peephole only;
3. `kernel-fixed-cmov` peephole with a fixed kernel policy;
4. `advisor-static`: automated generator with CPU DB only;
5. `advisor-profiled`: automated generator with CPU DB plus workload profile;
6. llvmbpf as an upper-bound reference where useful.

### 14.2 Key Questions

1. Does `kernel-wide-load` recover most of the byte-recompose loss?
2. Does the advisor still add value beyond `kernel-wide-load` through `cmov_select` policy?
3. Does the same BPF program receive different directives on different CPUs or workload profiles?
4. Are those differences measurable in runtime and PMU counters?
5. What fraction of auto-generated directives survive verifier remap and JIT validation?

### 14.3 Required Microarchitecture Evidence

The paper must show at least one table of directive selection differences for the same BPF program, for example:

- Arrow Lake or another modern OoO x86 host;
- one Atom-class or “Atom-like” policy configuration;
- one predictable and one unpredictable workload profile on the same program.

For `cmov_select`, the result should look like:

- modern OoO + unpredictable input: many accepted `cmov_select` sites;
- modern OoO + predictable input: fewer or zero `cmov_select` sites;
- Atom-like: zero or very few `cmov_select` sites.

For `wide_load`, the expected difference is smaller and mainly visible through alignment policy.

### 14.4 Required Automation Evidence

The evaluation must not rely on manual annotation.

It must report:

- number of candidates discovered automatically;
- number of directives emitted automatically;
- remap rejection rate;
- JIT validation rejection rate;
- end-to-end speedup and native code size change.

### 14.5 Measurements

Primary metrics:

- runtime / throughput;
- native code size;
- accepted directives per kind;
- branch misses and branch-miss rate;
- instruction count / uops where available;
- L1D or cache-miss counters for `wide_load` sensitivity.

Workloads:

- the pure-JIT suite;
- byte-recompose-heavy microbenchmarks;
- select-heavy benchmarks such as `switch_dispatch` and `binary_search`.

### 14.6 Arm64 Analysis Track

Even though the first implementation is x86-only, the evaluation plan should include an arm64 analysis track to show that the directive model is not accidentally x86-specific.

Arm64 analysis looks like:

- run the same userspace candidate discovery on the finalized pre-verifier BPF image;
- dump the stock arm64 JIT output for those programs;
- count how many sites the shared validator would accept for `wide_load`, `cmov_select`, and future `wide_store` / `branch_hint`;
- compare current arm64 lowering against the native idioms that the same directive would request:
  - `wide_load` -> `ldr wN` / `ldr xN`
  - `wide_store` -> `str wN` / `str xN`
  - `cmov_select` -> `csel`
  - `branch_hint` -> alternate fall-through / block layout
- report candidate counts, hypothetical accepted directives, code-size deltas from JIT dumps, and instruction-count deltas where the dump analysis is clear enough to estimate them.

`rotate_fusion` and `lea_fusion` stay lower priority on arm64 because their native idioms differ and need separate characterization first. The arm64 track is therefore analysis-only in v1, but it should still demonstrate that the blob format, remap path, validator logic, and userspace policy interface carry across architectures.

## 15. Implementation Plan

### 15.1 Kernel Work

Core files for the prototype:

- `include/uapi/linux/bpf.h`: add `jit_directives_fd` and flags;
- `kernel/bpf/syscall.c`: parse blob, check digest, check CPU contract, enforce capability gate;
- `kernel/bpf/`: shared directive template, common precondition checks, remap finalization, and rejection logging;
- `include/linux/bpf_verifier.h`: add compact retained `bpf_jit_mem_fact` storage;
- `kernel/bpf/verifier.c`: preserve `orig_idx`, record retained facts, compute remap, finalize directives;
- `arch/x86/net/bpf_jit_comp.c`: x86 emitter hooks for `wide_load` and `cmov_select`;
- future `arch/arm64/net/bpf_jit_comp.c`: arm64 emitter hooks for the same directive kinds;
- selftests under `tools/testing/selftests/bpf/`.

### 15.2 Milestones

1. Transport and parser only.
2. `orig_idx` propagation plus remap finalization.
3. Shared directive template plus common precondition checks.
4. Retained memory facts in `check_mem_access()`.
5. `wide_load`.
6. `cmov_select`.
7. Automated generator and x86 evaluation baselines.
8. arm64 JIT dump analysis and future-emitter design validation.

## 16. Related-Work Positioning

The positioning remains:

- K2 / Merlin / EPSO optimize verifier-visible bytecode before JIT;
- KFuse changes relationships among already-validated programs inside the kernel;
- v5r2 steers backend lowering of one verified program after verification.

This work is therefore orthogonal to bytecode optimizers and to KFuse.

## 17. Bottom Line

v5r2 is deliberately narrower than v5.

- The prototype is only `wide_load` plus `cmov_select`.
- The novelty claim is only the legality/profitability split, not a generic compiler abstraction.
- The microarchitecture story is carried primarily by `cmov_select`, with `wide_load` as a secondary case.
- The paper lives or dies on beating direct-kernel peephole baselines with automated, CPU-aware directive generation.

That is the version worth building.
