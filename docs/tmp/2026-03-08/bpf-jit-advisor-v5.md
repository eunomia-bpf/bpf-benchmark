# BPF JIT Advisor v5

## 1. Thesis

v5 replaces the rejected v4 "target-independent region IR" with a much narrower kernel contract:

- privileged userspace supplies arch-specific JIT directives for a specific BPF program image;
- each directive names a source range, a target-specific backend decision, explicit preconditions, and a CPU contract;
- the kernel never trusts userspace semantics, never lifts to a generic IR, and never compares canonical forms;
- the kernel only remaps ranges through verifier rewrites, checks bounded preconditions, and either adopts or rejects each directive.

This keeps the design paper-worthy without turning the kernel into a mini compiler.

The contribution is not "add three x86 peepholes." The contribution is a shared userspace-guided, microarchitecture-aware advisory substrate for backend decisions that bytecode optimizers cannot express.

## 2. Problem Statement And Hard Constraints

The characterization result is clear:

- llvmbpf is about 2x smaller in native code and about 15% faster on the pure-JIT suite.
- Byte-load recomposition accounts for 50.7% of kernel instruction surplus and has a 2.24x isolated time penalty.
- Missing `cmov` accounts for 19.9% of branch surplus.
- Fixed callee-saved saves accounted for 18.5%, but that gap is already fixed in kernel v7.0-rc2.

The design therefore has to satisfy these constraints:

- no one-off kernel-only peephole patches as the paper's main mechanism;
- no lift -> compare -> emit path inside the kernel;
- no target-independent IR;
- userspace in the loop from day one;
- decisions tied to the target CPU, not just to BPF syntax;
- minimal kernel changes;
- manual directive authoring first, llvmbpf automation later.

## 3. Design Overview

### 3.1 Core idea

The advisor contract is:

1. Userspace decides *which backend transformation to request* for a given BPF region on a given CPU.
2. The kernel decides *whether the transformation is legal* on the post-verifier program.
3. If the check fails, the kernel emits the ordinary JIT sequence.

The key shift from v4 is the abstraction boundary:

- v4 tried to exchange replacement semantics.
- v5 exchanges backend decisions.

That difference matters. `x86.cmov_select` is not a generic semantic description. It is a request to use an x86 backend mechanism if a bounded select-shaped region still exists and a small set of facts still hold.

### 3.2 High-level data flow

```text
raw .bpf.o
  -> libbpf CO-RE relocation
  -> finalized pre-verifier instruction image
  -> userspace advisor
       - detect CPU profile
       - manually or automatically choose directives
       - pack directive blob
       - seal blob into memfd
  -> BPF_PROG_LOAD(attr.jit_directives_fd = fd)
  -> kernel parses blob and checks digest against submitted insns
  -> verifier runs normally
       - preserves orig->post remap information
       - retains only directive-relevant facts
  -> post-verifier remap
  -> x86 JIT
       - for each remapped directive:
           validate bounded pattern + retained facts + CPU gates
           accept or reject
       - rejected directives fall back to stock emission
```

### 3.3 Why this is not "just peepholes"

The per-kind validators are intentionally narrow, but the system contribution is broader:

- shared transport and ABI from userspace to kernel;
- a stable range-remap contract through verifier rewrites;
- a common fail-closed validation model;
- explicit CPU binding;
- a path for manual nomination first and llvmbpf-guided nomination later.

The kernel still needs per-kind consumers, but it no longer owns site discovery or profitability policy. That is the major architectural move.

## 4. Kernel Interface

### 4.1 Chosen interface: extend `BPF_PROG_LOAD`

The recommended ABI is an optional directive blob FD on `BPF_PROG_LOAD`:

```c
struct {
	...
	__s32  jit_directives_fd;
	__u32  jit_directives_flags;
};
```

Recommended `jit_directives_flags` bits:

- `BPF_F_JIT_DIRECTIVES_STRICT_CPU`: reject the entire blob if the host CPU does not match the blob CPU contract.
- `BPF_F_JIT_DIRECTIVES_LOG`: append acceptance and rejection reasons to the verifier log when logging is enabled.

The blob FD should be a sealed `memfd`. The kernel requires:

- `F_SEAL_WRITE`
- `F_SEAL_SHRINK`
- `F_SEAL_GROW`

This keeps the object immutable and makes the blob lifetime independent from userspace pointers.

### 4.2 Why `BPF_PROG_LOAD` is the right place

Directives must bind to the exact instruction image submitted to the verifier. A separate attach step is the wrong abstraction because:

- it loses atomicity with the pre-verifier image the directives were built against;
- the program may already be JITed;
- it would require re-JIT or delayed materialization;
- it complicates failure semantics.

Attaching directives at load time keeps the trust boundary simple: one blob, one submitted image, one verifier run, one JIT decision.

### 4.3 Why not the other options

| Option | Why not chosen |
| --- | --- |
| ELF metadata / ELF notes | wrong layer; directives are host- and CPU-specific, while ELF is a portable artifact; the kernel does not parse ELF at `BPF_PROG_LOAD` time anyway |
| New `bpf()` command after load | breaks atomic binding to the submitted instruction image and implies re-JIT machinery |
| BTF-based transport | BTF is target-independent type metadata; it is the wrong semantic layer for arch-specific backend directives |
| sysfs / procfs | global mutable state, bad per-program atomicity, weak security model, awkward lifecycle |

The only reasonable kernel ABI is "optional per-load opaque blob, consumed before or during verification."

### 4.4 Userspace authoring interface

The kernel ABI should stay binary and compact. Manual phase authoring should use a userspace text format and a packer:

```text
manual YAML/JSON
  -> jitadv pack
  -> sealed memfd
  -> BPF_PROG_LOAD
```

This keeps the kernel ABI stable while making manual authoring practical.

## 5. Directive Blob Format

### 5.1 Blob header

```c
#define BPF_JIT_ADV_MAGIC 0x424a4156 /* "BJAV" */

enum bpf_jit_arch {
	BPF_JIT_ARCH_X86_64 = 1,
};

struct bpf_jit_cpu_contract {
	__u32 arch;
	__u32 vendor;
	__u32 family;
	__u32 model;
	__u32 stepping_mask;
	__u64 required_features[2];
	__u64 forbidden_features[2];
	__u64 profile_hash;
	__u32 profile_version;
	__u32 flags;
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

Blob-level rules:

- `arch` is mandatory and arch-specific.
- `prog_digest` is computed over the finalized pre-verifier instruction image after libbpf relocation and subprogram finalization.
- `orig_insn_cnt` must match the submitted program length.
- `profile_hash` identifies the userspace tuning profile used to generate the blob. The kernel treats it as opaque metadata for logging and observability.

### 5.2 Common directive header

```c
enum bpf_jit_dir_kind {
	BPF_JIT_X86_WIDE_LOAD      = 1,
	BPF_JIT_X86_CMOV_SELECT    = 2,
	BPF_JIT_X86_DIAMOND_LAYOUT = 3,
	BPF_JIT_X86_ROTATE_FUSION  = 4,
};

enum bpf_jit_precond_bits {
	BPF_JIT_PC_STRAIGHT_LINE      = 1U << 0,
	BPF_JIT_PC_ONE_DIAMOND        = 1U << 1,
	BPF_JIT_PC_NO_INTERIOR_TARGET = 1U << 2,
	BPF_JIT_PC_NO_CALLS           = 1U << 3,
	BPF_JIT_PC_NO_STORES          = 1U << 4,
	BPF_JIT_PC_NO_ATOMICS         = 1U << 5,
	BPF_JIT_PC_CONST_OFFSET_MEM   = 1U << 6,
	BPF_JIT_PC_SAME_BASE_MEM      = 1U << 7,
	BPF_JIT_PC_SINGLE_LIVEOUT     = 1U << 8,
	BPF_JIT_PC_NONFAULTING_MEM    = 1U << 9,
	BPF_JIT_PC_FLAGS_DEAD         = 1U << 10,
};

struct bpf_jit_dir_rec {
	__u16 kind;
	__u16 len;
	__u16 subprog_id;
	__u16 flags;
	__u32 orig_start_off;
	__u32 orig_end_off; /* exclusive */
	__u32 precond_mask;
	__u32 reserved;
	__u64 required_features[2];
	__u64 forbidden_features[2];
	/* followed by kind-specific payload */
};
```

`required_features` and `forbidden_features` are interpreted in an arch-specific namespace. For x86-64 this should map to CPUID-derived capability bits plus a small execution-contract bitset such as `UNALIGNED_8B_OK`.

Rules:

- `orig_start_off` and `orig_end_off` are in finalized pre-verifier coordinates.
- directives are sorted by `(subprog_id, orig_start_off)`;
- overlapping ranges are rejected at parse time;
- regional directives must stay within a single subprogram;
- max blob size in v1: 64 KiB;
- max directives in v1: 1024.

### 5.3 Kind-specific payloads

#### `BPF_JIT_X86_WIDE_LOAD`

```c
enum bpf_jit_mem_class {
	BPF_JIT_MEM_STACK     = 1,
	BPF_JIT_MEM_MAP_VALUE = 2,
};

struct bpf_jit_x86_wide_load {
	__u8 width;          /* 4 or 8 */
	__u8 endian;         /* little-endian only in v1 */
	__u8 mem_class;      /* expected verifier class */
	__u8 min_align_log2; /* 0 means alignment >= 1 */
	__u8 dst_reg;
	__u8 base_reg;
	__s16 base_off;
	__u8 liveout_reg;
	__u8 reserved[7];
};
```

#### `BPF_JIT_X86_CMOV_SELECT`

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

struct bpf_jit_x86_cmov_select {
	__u8 cc;      /* expected BPF relational op */
	__u8 dst_reg;
	__u8 lhs_reg;
	__u8 reserved;
	struct bpf_jit_value_ref rhs;
	struct bpf_jit_value_ref true_val;
	struct bpf_jit_value_ref false_val;
};
```

#### `BPF_JIT_X86_DIAMOND_LAYOUT`

```c
struct bpf_jit_x86_diamond_layout {
	__u8 hot_arm;   /* 0 = fallthrough arm in BPF order, 1 = jump arm */
	__u8 invert_cc; /* userspace-expected inversion */
	__u16 reserved;
	__u32 max_hot_len;  /* bound for validator */
	__u32 max_cold_len; /* bound for validator */
};
```

#### `BPF_JIT_X86_ROTATE_FUSION`

```c
struct bpf_jit_x86_rotate_fusion {
	__u8 width;      /* 32 or 64 */
	__u8 direction;  /* left or right */
	__u8 dst_reg;
	__u8 src_reg;
	__u8 amount_kind; /* reg or imm */
	__u8 amount_reg;
	__u16 reserved;
	__u32 amount_imm;
	__u8 use_bmi2;   /* request a BMI2 flag-independent rotate form */
	__u8 reserved2[7];
};
```

### 5.4 Example human-readable directive

```yaml
- kind: x86_wide_load
  subprog_id: 0
  range: [84, 85]
  cpu:
    exact_cpu: intel/06c6
    require_features: [fast_unaligned_8b]
    profile: arrowlake-s-v1
  preconditions:
    - straight_line
    - no_calls
    - no_stores
    - same_base_mem
    - const_offset_mem
    - nonfaulting_mem
    - single_liveout
  payload:
    width: 8
    mem_class: map_value
    min_align_log2: 0
    dst_reg: r0
    base_reg: r6
    base_off: 0
```

The userspace packer turns this into the binary blob. The kernel only consumes the binary form.

## 6. Range Naming And Remap Model

### 6.1 Source coordinate system

Userspace names ranges in the exact instruction image passed to `BPF_PROG_LOAD`, after:

- CO-RE relocation;
- libbpf subprogram finalization;
- any userspace preprocessing that will happen before the syscall.

Userspace never names post-verifier instruction indices.

### 6.2 Why remap is still necessary in v5

Even without v4's IR, v5 still needs in-kernel remap because verifier rewrites can:

- insert instructions;
- remove instructions;
- expand one original access into multiple instructions;
- shift subprogram boundaries.

This is especially important for byte-recompose candidates: the byte ladder already exists in the submitted BPF image, but verifier rewrites can still insert, delete, or shift neighboring instructions, so the kernel must remap the userspace-named range to the final verified envelope before validating it.

### 6.3 Remap rule

After verification completes, the kernel computes the post-verifier envelope for each directive:

1. Find all post-verifier instructions whose preserved `orig_idx` lies in `[orig_start_off, orig_end_off)`.
2. Require those instructions to form one contiguous post-verifier interval.
3. Reject if the interval is empty.
4. Reject if the interval crosses a subprogram boundary.
5. Reject if remapped post-verifier intervals overlap.

The kernel never trusts userspace-provided post-verifier coordinates.

### 6.4 Required verifier bookkeeping

Current `orig_idx` support is not sufficient as-is because inserted instructions do not reliably preserve original ownership across all rewrite paths. v5 therefore reuses only the remap idea from v4 and adds one concrete rule:

- whenever verifier rewriting expands one instruction into `N` instructions, all inserted instructions inherit the original instruction's `orig_idx`.

This requires touching the existing patching path around:

- `bpf_patch_insn_data()`
- `adjust_insn_aux_data()`
- rewrite passes such as `convert_ctx_accesses()` and `do_misc_fixups()`

No IR machinery is needed; only stable origin tracking is required.

## 7. Kernel Processing Pipeline

### 7.1 Load-time parsing

On `BPF_PROG_LOAD`:

1. If `jit_directives_fd < 0`, the load path is unchanged.
2. Otherwise the kernel:
   - requires the same privileged load authorization as unrestricted `BPF_PROG_LOAD` (`CAP_BPF` or equivalent token policy);
   - reads the sealed memfd;
   - validates header, version, size, ordering, and non-overlap;
   - computes the digest of the submitted pre-verifier instruction image;
   - checks `prog_digest`, `orig_insn_cnt`, and CPU contract;
   - stores the parsed directives in `prog->aux`.

CPU mismatch handling:

- if `BPF_F_JIT_DIRECTIVES_STRICT_CPU` is set, reject the load;
- otherwise accept the program but drop the entire blob before verification.

### 7.2 Verifier-side retained facts

The verifier remains unchanged for ordinary legality. v5 adds only minimal retained facts needed by some directives.

For v1, only wide-load needs retained facts. The verifier records a compact memory fact for tracked candidate accesses:

```c
struct bpf_jit_mem_fact {
	__u8 valid;
	__u8 mem_class;
	__u8 align_log2;
	__u8 flags;      /* nonfaulting, const_offset, readonly, etc. */
	__s16 const_off;
	__u16 min_readable;
};
```

The fact is recorded only when:

- the instruction's `orig_idx` is covered by at least one directive range; and
- the access is of a class the directive validator may later use.

Useful hook points are:

- `check_mem_access()` for finalized memory legality;
- rewrite paths after `convert_ctx_accesses()` and `do_misc_fixups()` to preserve origin tracking.

No full verifier-state snapshot is retained.

### 7.3 Post-verifier directive finalization

After rewrites finish:

- remap directives from original to post-verifier intervals;
- attach any retained per-insn facts to the remapped interval;
- sort by `post_start`;
- reject overlaps and impossible envelopes;
- store a compact `prog->aux->jit_advice_ready` structure for the JIT.

### 7.4 JIT-time consumption

The x86 JIT consumes directives during `do_jit()`:

```text
for each BPF insn index i:
  if no directive starts at i:
    emit stock lowering for insn i
  else:
    validate directive against post-verifier insns [i, end)
    if validation fails:
      emit stock lowering for insn i
    else:
      emit fused native sequence
      mark covered insns as consumed
      continue at post_end
```

Important rule:

- regional directives require `BPF_JIT_PC_NO_INTERIOR_TARGET`;
- therefore the JIT may legally collapse all covered BPF insns onto one native entry address in `addrs[]`.

That keeps branch-offset handling and line mapping manageable without out-of-kernel semantic comparison.

## 8. Safety Model

### 8.1 Global fail-closed rules

Every directive is advisory. The kernel never changes program acceptance based on directive success.

Bad blobs must not:

- change program semantics;
- make a previously valid program unloadable;
- expand the memory footprint beyond the verifier-proven byte interval;
- force the JIT down an unverified path.

On any blob or directive failure, the kernel falls back to ordinary JIT emission.

### 8.2 What the kernel validates

The kernel validates only three categories of properties:

1. Blob integrity:
   - format, size, ordering, overlap, digest, privilege, CPU contract.
2. Range integrity:
   - remapped envelope exists, is contiguous, and has no illegal interior targets.
3. Kind-specific preconditions:
   - a bounded syntactic match on the post-verifier BPF interval;
   - retained verifier facts where the JIT itself cannot reconstruct legality.

The kernel does *not* validate:

- semantic equivalence to a userspace IR;
- arbitrary native code;
- profitability.

### 8.3 Directive-specific preconditions

#### `BPF_JIT_X86_WIDE_LOAD`

Exact semantics:

- replace a validated byte-load/shift/or recomposition region with one x86 `movl` or `movq` load from the same base object and constant offset.

Kernel checks:

1. Remapped region is straight-line.
2. No calls, stores, atomics, tail calls, or exits.
3. Final liveout is exactly the declared `liveout_reg`.
4. Region matches one accepted byte-recompose shape:
   - contiguous byte loads from one base register;
   - constant offsets `base_off + i`;
   - only `mov`, `lsh imm`, and `or` combine the loaded bytes;
   - no arithmetic on the loaded bytes besides the recomposition tree.
5. All load sites share one retained memory class.
6. Memory class is one of `{STACK, MAP_VALUE}` in v1.
7. Retained fact says:
   - nonfaulting access;
   - constant offset;
   - readable width at least `width`;
   - alignment at least `2^min_align_log2`.
8. The region has no interior branch targets.

Rejected in v1:

- packet accesses;
- ctx accesses;
- `PROBE_MEM` accesses;
- arena accesses;
- any region that would require new extable behavior.

#### `BPF_JIT_X86_CMOV_SELECT`

Exact semantics:

- replace a one-diamond region that computes `dst = cond ? true_val : false_val` with `cmp + mov + cmovcc`.

Kernel checks:

1. Region remaps to one entry conditional jump, two side-effect-free arms, one join.
2. No calls, stores, atomics, tail calls, exits, or helper invocations inside the region.
3. No interior branch targets from outside the region.
4. Both arms only assign the same destination register.
5. The assigned values match the declared `true_val` and `false_val`.
6. The compare shape and relation operator match the declared `cc`.
7. All other liveouts are equal across both arms.
8. Required CPU feature `CMOV` is present.

The validator does not prove arbitrary branch equivalence. It accepts only the fixed "select diamond" template.

#### `BPF_JIT_X86_DIAMOND_LAYOUT`

Exact semantics:

- keep control-flow semantics identical, but emit a one-diamond region in a different native block order so that the chosen hot arm becomes fallthrough.

Kernel checks:

1. Region is exactly one-entry, one-exit diamond.
2. No interior branch targets from outside the region.
3. Both arms stay within `max_hot_len` and `max_cold_len`.
4. No calls, tail calls, exits, or helper invocations in either arm.
5. The join block is unique and outside-arm control flow is unchanged.
6. Cross-region branch targets refer only to the region entry or the join.

This directive changes only native layout, not dataflow.

#### `BPF_JIT_X86_ROTATE_FUSION`

Exact semantics:

- replace a recognized rotate idiom `(x << k) | (x >> (W-k))` or the right-rotate equivalent with x86 `rol`, `ror`, or `rorx`.

Kernel checks:

1. Region is straight-line.
2. The idiom matches the declared width, direction, and amount source.
3. The two shifts use the same source register and complementary amounts.
4. The final OR produces the declared destination register.
5. No interior target exists.
6. If `use_bmi2` is requested, BMI2 is present.
7. If a flags-free variant is requested, no intervening flags dependency is required.

### 8.4 Rejection behavior

Directive rejection reasons should be explicit and countable:

- blob parse failure
- digest mismatch
- CPU mismatch
- remap failure
- overlap after remap
- unsupported kind
- pattern mismatch
- retained-fact mismatch
- prohibited memory class
- prohibited control-flow shape

These reasons are needed both for debugging and for the paper's acceptance-rate analysis.

## 9. Initial Directive Set

### 9.1 v1 directive families

The initial directive set should be:

1. `BPF_JIT_X86_WIDE_LOAD`
2. `BPF_JIT_X86_CMOV_SELECT`
3. `BPF_JIT_X86_DIAMOND_LAYOUT`
4. `BPF_JIT_X86_ROTATE_FUSION`

Why these four:

- `wide_load` attacks the single largest measured gap;
- `cmov_select` attacks the measured branchless-lowering gap;
- `diamond_layout` covers branch layout decisions that remain even when `cmov` is not profitable;
- `rotate_fusion` demonstrates that the same substrate handles a pure scalar backend decision as well.

This gives one memory family, two control-flow families, and one scalar family.

### 9.2 Why callee-saved is not in the v1 directive set

The characterization identified callee-saved policy as an important gap, but x86 already fixed it in v7.0-rc2 via `detect_reg_usage()`.

That makes it poor as the center of the new system. The paper should mention it as validated prior analysis, not as the main remaining directive family.

### 9.3 Prototype implementation priority

Implementation order should be:

1. `wide_load`
2. `cmov_select`
3. `diamond_layout` as stretch
4. `rotate_fusion` as stretch

This matches the evidence and minimizes kernel-risk first.

## 10. Microarchitecture Adaptation

### 10.1 CPU binding model

Directives are generated for one concrete target CPU profile. The userspace advisor computes:

- ISA feature bits from CPUID;
- vendor / family / model identity;
- an advisor profile hash representing the measured profitability model for that CPU.

The kernel checks only:

- exact architecture;
- required and forbidden hardware features;
- optionally exact vendor / family / model when strict CPU matching is enabled.

The kernel does not embed a performance model.

### 10.2 Advisor policy inputs

Userspace uses two inputs:

1. Static CPU profile
   - family/model
   - ISA features
   - offline benchmarked policy database
2. Optional workload profile
   - branch hotness or branch miss behavior
   - known input distributions
   - training-run PMU data

This split matters:

- `wide_load` is mostly a static CPU + legality decision;
- `cmov` and `diamond_layout` depend on both CPU and workload;
- `rotate_fusion` depends mostly on CPU feature availability and scheduler/front-end tradeoffs.

### 10.3 Example policy matrix

| Directive | Hard CPU gate | Userspace profitability rule |
| --- | --- | --- |
| `wide_load` | none beyond x86-64 and any requested unaligned-load contract | enable when legal for stack/map-value; prefer 8-byte widening on CPUs where unaligned qword load is not penalized materially |
| `cmov_select` | `CMOV` | enable only on CPU profiles where `cmov` beats predicted-branch lowering for this shape; disable on profiles where predictable branches win |
| `diamond_layout` | none | enable when the profile or training data says hot-fallthrough reduces branch cost on this CPU |
| `rotate_fusion` | baseline rotate or BMI2 for `rorx` | choose `rorx` only on profiles where the BMI2 form wins for the observed dependency pattern |

### 10.4 Manual-first workflow

Phase 1 manual authoring is intentionally simple:

1. The operator chooses a CPU profile, for example `intel-arrowlake-s-v1`.
2. The operator manually writes directives and ranges.
3. The packer resolves the final submitted instruction image, computes the digest, and emits the blob.

No llvmbpf automation is required in v1.

### 10.5 llvmbpf automation later

Phase 2 uses llvmbpf only as a nomination oracle, not as a trusted semantics source.

Recommended automation flow:

1. Compile the finalized BPF program with llvmbpf using the same CPUID feature mask as the target host.
2. Compare *known local templates* between the BPF program and llvmbpf's native lowering:
   - if llvmbpf uses one wide load where the post-verifier BPF expands to a byte ladder, emit `wide_load`;
   - if llvmbpf uses `cmovcc` on a select-shaped diamond, emit `cmov_select`;
   - if llvmbpf chooses hot-fallthrough layout for a one-diamond region, emit `diamond_layout`;
   - if llvmbpf emits rotate or `rorx`, emit `rotate_fusion`.
3. Emit the same directive blob format used by the manual path.

The kernel still performs the same bounded validation and still does not compare against llvmbpf IR or machine code.

### 10.6 Heterogeneous CPU systems

v1 should be explicit here:

- if online CPUs do not share one common vendor/family/model contract, reject strict blobs;
- non-strict blobs may be accepted only if required feature masks are satisfied system-wide.

Per-core or per-cpuset advisor blobs are future work.

## 11. Comparison With K2, Merlin, And EPSO

K2, Merlin, and EPSO operate before the kernel JIT and therefore cannot directly force backend decisions such as:

- native wide loads instead of post-verifier byte ladders;
- `cmov` instead of conditional branches;
- native block layout tuned for the branch predictor;
- target-specific rotate or BMI2 lowering.

Why not:

1. They optimize verifier-visible program representations, not the final machine backend.
2. They cannot ask the kernel x86 JIT to use `cmov`; BPF has no `cmov` instruction.
3. They cannot express "emit the hot arm as fallthrough on Arrow Lake but not on some other CPU" because that is a backend block-layout decision, not a bytecode rewrite.
4. Even when they change bytecode, the kernel can still make the same conservative lowering choice afterward.

So the systems are orthogonal:

- bytecode optimizers change the verifier-visible program;
- the advisor changes arch-specific lowering decisions after verification.

They stack rather than replace each other.

## 12. Implementation Plan

### 12.1 Kernel files

Core kernel changes for the prototype:

| File | Change |
| --- | --- |
| `vendor/linux/include/uapi/linux/bpf.h` | add `jit_directives_fd` and flags to `BPF_PROG_LOAD` |
| `vendor/linux/include/linux/bpf.h` | add `prog->aux` storage for parsed blob, remapped directives, and stats |
| `vendor/linux/include/linux/bpf_verifier.h` | add compact retained `jit_mem_fact` state to `bpf_insn_aux_data` or equivalent |
| `vendor/linux/kernel/bpf/syscall.c` | parse the blob FD, validate digest/CPU contract, attach parsed directives to `prog->aux` |
| `vendor/linux/kernel/bpf/verifier.c` | preserve `orig_idx` through rewrites, retain directive-relevant facts, compute orig->post remap, finalize remapped directives |
| `vendor/linux/kernel/bpf/jit_advisor.c` | new shared blob parser, range remap helpers, common validation helpers |
| `vendor/linux/include/linux/bpf_jit_advisor.h` | new internal shared structs and helper declarations |
| `vendor/linux/arch/x86/net/bpf_jit_comp.c` | x86 directive validators and emitters, plus JIT dispatch logic |

Optional userspace convenience changes:

| File | Change |
| --- | --- |
| `vendor/libbpf/src/bpf.h` | add `jit_directives_fd` to `struct bpf_prog_load_opts` |
| `vendor/libbpf/src/bpf.c` | plumb new load option into `BPF_PROG_LOAD` |

Test and prototype tooling:

| File | Change |
| --- | --- |
| `vendor/linux/tools/testing/selftests/bpf/prog_tests/jit_advisor.c` | new selftest driver |
| `vendor/linux/tools/testing/selftests/bpf/progs/jit_advisor_*.c` | focused BPF test programs |
| repo `scripts/` or `tools/` | manual blob packer and llvmbpf-guided generator |

### 12.2 Recommended milestone order

#### Milestone 0: transport only

- add blob FD plumbing;
- parse and validate header;
- no x86 consumers yet;
- verify failure paths and logging.

#### Milestone 1: remap and retained facts

- preserve `orig_idx` through verifier rewrites;
- remap original ranges to post-verifier intervals;
- retain only the memory facts needed for wide-load.

#### Milestone 2: `wide_load`

- implement x86 validator and emitter for stack/map-value byte ladders;
- evaluate on the byte-recompose-heavy microbenchmarks.

#### Milestone 3: `cmov_select`

- add one-diamond select validation and x86 `cmovcc` emission;
- evaluate on `switch_dispatch`, `binary_search`, and select-like kernels.

#### Milestone 4: stretch families

- `diamond_layout`
- `rotate_fusion`

#### Milestone 5: automation

- llvmbpf-guided userspace nomination;
- same kernel ABI, same validators.

### 12.3 Prototype scope

v1 in scope:

- x86-64 only;
- privileged loads only;
- blob on `BPF_PROG_LOAD`;
- manual directive authoring;
- `wide_load` and `cmov_select` implemented;
- `diamond_layout` and `rotate_fusion` defined, optional if time allows.

Explicitly out of scope in v1:

- arbitrary native code injection;
- target-independent replacement IR;
- packet and ctx wide-load validation;
- `PROBE_MEM` and extable-rewriting load fusion;
- offloaded BPF;
- constant-blinding-aware directive remap;
- per-core heterogeneous CPU tuning;
- upstream ABI stability claims.

### 12.4 Constant blinding and other interactions

The x86 prototype should be honest about interactions with existing JIT features:

- if constant blinding rewrites the program before final x86 emission, v1 should simply disable directives for that compilation path;
- tail calls, helpers, exits, and exception-boundary functions are excluded from directive regions;
- no directive may span a subprogram call boundary.

That is acceptable for a research prototype and avoids hidden semantic risk.

### 12.5 Required selftests

At minimum the prototype should ship these selftests:

- blob parse rejection for malformed header, bad length, and overlapping ranges;
- digest mismatch rejection;
- strict CPU mismatch rejection;
- non-strict CPU mismatch fallback to ordinary JIT;
- remap failure when verifier rewrites delete or split the nominated range;
- wide-load acceptance on a stack or map-value byte ladder;
- wide-load rejection on packet, ctx, or `PROBE_MEM` ladders;
- `cmov_select` acceptance on a select-shaped diamond;
- `cmov_select` rejection when either arm has a store or helper call;
- mixed-directive load where one directive is accepted and a later one is rejected, proving fail-closed per-directive behavior.

## 13. Why v5 is implementable and v4 was not

v4 failed because its trusted kernel path required:

- a typed canonical IR;
- a re-lifter;
- a comparator;
- a lowerer;
- precise equivalence semantics.

v5 removes the blocker:

- no generic semantics exchange;
- no equivalence checker;
- only bounded, kind-specific validators over post-verifier BPF and minimal retained facts.

What remains is still real engineering, but it is engineering in the right layer:

- remap;
- blob plumbing;
- a few retained facts;
- a few arch-specific consumers.

That is a credible OSDI/SOSP systems prototype.

## 14. Bottom Line

The right v5 design is:

- userspace-guided from the start;
- arch-specific rather than target-independent;
- microarchitecture-bound through a concrete CPU contract;
- fail-closed;
- built around typed backend directives, not IR replacement;
- implemented with minimal verifier retention and bounded JIT validators.

This directly matches the measured gaps:

- `wide_load` for the 50.7% byte-recompose surplus;
- `cmov_select` and `diamond_layout` for the 19.9% branch surplus;
- `rotate_fusion` as a third family proving the substrate is not memory-only.

It also cleanly explains why K2, Merlin, and EPSO cannot solve the remaining problem: they operate before the backend decisions that matter here.
