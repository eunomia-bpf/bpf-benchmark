# Kernel Architecture Review (2026-03-19)

## Scope

Reviewed files:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/kernel_loc_breakdown_20260319.md`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/log.c`
- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`

Important naming note:

- The current kernel branch does not contain functions named `bpf_jit_validate_rotate_ror_bitmask`, `bpf_jit_validate_rotate_ror_mod`, `bpf_jit_validate_rotate_rol_bitmask`, or `bpf_jit_validate_rotate_rol_mod`.
- The actual 461-LOC rotate family in this branch is:
  - `bpf_jit_parse_rotate_4insn()` at `kernel/bpf/jit_directives.c:1147`
  - `bpf_jit_parse_rotate_5insn()` at `kernel/bpf/jit_directives.c:1269`
  - `bpf_jit_rotate_mask_matches()` at `kernel/bpf/jit_directives.c:1368`
  - `bpf_jit_parse_rotate_5insn_masked()` at `kernel/bpf/jit_directives.c:1383`
  - `bpf_jit_parse_rotate_6insn()` at `kernel/bpf/jit_directives.c:1501`
  - `bpf_jit_validate_rotate_rule()` at `kernel/bpf/jit_directives.c:1613`
- This review maps those actual functions. Semantically, they cover four source-shape buckets:
  - single-copy modulo-width rotate
  - two-copy modulo-width rotate
  - single-copy masked 32-bit rotate
  - two-copy masked 32-bit rotate

## Part 1: ROTATE validator family

### 1.1 High-level shape of the current implementation

All four rotate parsers normalize accepted source idioms into the same canonical parameter set:

- `BPF_JIT_ROT_PARAM_DST_REG`
- `BPF_JIT_ROT_PARAM_SRC_REG`
- `BPF_JIT_ROT_PARAM_AMOUNT`
- `BPF_JIT_ROT_PARAM_WIDTH`

The x86 emitter then lowers that canonical form to `ror` or `rorx` in `emit_canonical_rotate()` at `arch/x86/net/bpf_jit_comp.c:2253-2330`.

Important semantic detail:

- The source patterns accepted by the kernel are all rotate-left style idioms: they use `lsh dst, N` and `rsh tmp, W-N`.
- The emitter then computes `ror_imm = width - amount` and emits a right rotate by the complement.
- So the current kernel IR is effectively "rotate-left by `amount`", even though the native lowering uses `ror`/`rorx`.
- There is no distinct source-side "ROR parser" in the current branch.

### 1.2 Mapping from requested semantic buckets to actual kernel parsers

| Requested semantic bucket | Actual parser(s) in this branch | Notes |
| --- | --- | --- |
| `rol_mod` | `bpf_jit_parse_rotate_4insn()`, `bpf_jit_parse_rotate_5insn()` | Unmasked complement relation proves rotate width |
| `rol_bitmask` | `bpf_jit_parse_rotate_5insn_masked()`, `bpf_jit_parse_rotate_6insn()` | Mask proves 32-bit rotate shape |
| `ror_mod` | none distinct | Lowered as `ror`, but source matcher is still rol-style |
| `ror_bitmask` | none distinct | Same as above |

### 1.3 Parser-by-parser mapping

#### A. `bpf_jit_parse_rotate_4insn()`

Location: `kernel/bpf/jit_directives.c:1147-1253`

Exact instruction pattern accepted:

- `site_len == 4`
- Instruction 0:
  - opcode must be `BPF_MOV | BPF_X`
  - class must be `BPF_ALU64` or `BPF_ALU`
  - `off == 0`, `imm == 0`
  - `dst_reg != src_reg`
- Instructions 1 and 2:
  - one must be `BPF_LSH | BPF_K`
  - one must be `BPF_RSH | BPF_K`
  - order may be either:
    - classic: `lsh` then `rsh`
    - commuted: `rsh` then `lsh`
  - both must use the same class as the MOV:
    - `BPF_ALU64` for width 64
    - `BPF_ALU` for width 32
  - `lsh.dst_reg` must be the original source register
  - `rsh.dst_reg` must be the temp register
  - `lsh.imm = N`, `rsh.imm = width - N`
- Instruction 3:
  - opcode must be `BPF_OR | BPF_X`
  - class must match the width
  - `off == 0`, `imm == 0`
  - `or.dst_reg` must be the original source register
  - `or.src_reg` must be the temp register

Canonical params extracted:

- `DST_REG = mov.src_reg`
- `SRC_REG = mov.src_reg`
- `AMOUNT = lsh.imm`
- `WIDTH = 32` or `64`, inferred from MOV class

Validation checks performed:

- bounds: `idx + 4 <= insn_cnt`
- width must be exactly 32 or 64 via MOV class
- temp register must differ from original value register
- only immediate shifts are allowed
- shift order may commute, but register roles may not
- rotation amount must satisfy `0 < N < width`
- complement amount must match exactly `width - N`
- final OR must combine original register plus temp register

Semantic summary:

- This is the in-place single-copy rotate idiom.
- It supports both 32-bit and 64-bit source shapes.
- It is the only parser that infers width from opcode class instead of fixing it up front.

#### B. `bpf_jit_parse_rotate_5insn()`

Location: `kernel/bpf/jit_directives.c:1269-1354`

Exact instruction pattern accepted:

- `site_len == 5`
- Instruction 0:
  - `BPF_ALU64 | BPF_MOV | BPF_X`
  - `off == 0`, `imm == 0`
- Instruction 1:
  - `BPF_ALU64 | BPF_RSH | BPF_K`
  - `off == 0`
  - destination must be the temp from instruction 0
  - immediate is `64 - N`
- Instruction 2:
  - `BPF_ALU64 | BPF_MOV | BPF_X`
  - `off == 0`, `imm == 0`
  - source must match instruction 0's source
  - temp register must differ from both the source and final destination
- Instruction 3:
  - `BPF_ALU64 | BPF_LSH | BPF_K`
  - `off == 0`
  - destination must be instruction 2's destination
  - immediate is `N`
- Instruction 4:
  - `BPF_ALU64 | BPF_OR | BPF_X`
  - `off == 0`, `imm == 0`
  - destination must be instruction 2's destination
  - source must be instruction 0's temp register

Canonical params extracted:

- `DST_REG = mov2.dst_reg`
- `SRC_REG = mov1.src_reg`
- `AMOUNT = lsh.imm`
- `WIDTH = 64`

Validation checks performed:

- bounds: `idx + 5 <= insn_cnt`
- all ops must be ALU64
- both MOVs must be reg-to-reg copies with zero `off` and `imm`
- first temp must not alias source or second destination
- both copies must originate from the same source register
- `0 < N < 64`
- `0 < rsh_amount < 64`
- exact complement relation: `N + rsh_amount == 64`
- final OR must combine the second copy with the first temp

Semantic summary:

- This is the two-copy 64-bit rotate idiom.
- It is fixed-order, unlike the 4-insn parser.
- It is the only unmasked parser that requires a second explicit copy.

#### C. `bpf_jit_rotate_mask_matches()`

Location: `kernel/bpf/jit_directives.c:1368-1380`

Purpose:

- Proves that an `and64 tmp, mask` is compatible with a 32-bit rotate shape.
- Accepts only immediate masks.
- Computes:
  - `low_mask = (1U << (32 - rot_amount)) - 1`
  - `high_mask = ~low_mask`
- Accepts `mask == low_mask` or `mask == high_mask`

Validation checks performed:

- `0 < rot_amount < 32`
- immediate mask must match one of the two exact derived masks

Structural importance:

- This helper is the only thing distinguishing the masked 32-bit parsers from generic shift-and-or sequences.
- It is the part most likely to be weakened by an unsafe refactor.

#### D. `bpf_jit_parse_rotate_5insn_masked()`

Location: `kernel/bpf/jit_directives.c:1383-1484`

Exact instruction pattern accepted:

- `site_len == 5`
- Instruction 0:
  - `BPF_ALU64 | BPF_MOV | BPF_X`
  - `off == 0`, `imm == 0`
  - temp must differ from source
- Instruction 1:
  - `BPF_ALU64 | BPF_AND | BPF_K`
  - `off == 0`
  - destination must be the temp register
  - note: register-masked `AND_X` is rejected
- Instructions 2 and 3:
  - one must be `BPF_ALU64 | BPF_RSH | BPF_K`
  - one must be `BPF_ALU64 | BPF_LSH | BPF_K`
  - order may be either
  - `rsh` must target the temp register
  - `lsh` must target the original source register
  - immediates must satisfy `0 < N < 32`, `0 < rsh_amount < 32`, and `N + rsh_amount == 32`
- Instruction 4:
  - `BPF_ALU64 | BPF_OR | BPF_X`
  - `off == 0`, `imm == 0`
  - destination must be the original source register
  - source must be the temp register
- Mask proof:
  - `bpf_jit_rotate_mask_matches(N, and_insn->imm)` must hold

Canonical params extracted:

- `DST_REG = mov.src_reg`
- `SRC_REG = mov.src_reg`
- `AMOUNT = lsh.imm`
- `WIDTH = 32`

Validation checks performed:

- bounds: `idx + 5 <= insn_cnt`
- fixed ALU64 instruction class
- immediate-only AND mask
- optional shift commutation
- in-place destination on the original source register
- strict 32-bit complement relation
- exact mask proof via `bpf_jit_rotate_mask_matches()`

Semantic summary:

- This is the single-copy masked 32-bit rotate idiom.
- It is the masked analog of the 4-insn parser.
- The result is written back into the original register, not a second copy.

#### E. `bpf_jit_parse_rotate_6insn()`

Location: `kernel/bpf/jit_directives.c:1501-1601`

Exact instruction pattern accepted:

- `site_len == 6`
- Instruction 0:
  - `BPF_ALU64 | BPF_MOV | BPF_X`
  - `off == 0`, `imm == 0`
- Instruction 1:
  - `BPF_ALU64 | BPF_AND | BPF_K`
  - `off == 0`
  - destination must be instruction 0's temp
- Instruction 2:
  - `BPF_ALU64 | BPF_RSH | BPF_K`
  - `off == 0`
  - destination must be the temp register
  - immediate is `32 - N`
- Instruction 3:
  - `BPF_ALU64 | BPF_MOV | BPF_X`
  - `off == 0`, `imm == 0`
  - source must match instruction 0's source
  - temp must differ from source and second destination
- Instruction 4:
  - `BPF_ALU64 | BPF_LSH | BPF_K`
  - `off == 0`
  - destination must be instruction 3's destination
  - immediate is `N`
- Instruction 5:
  - `BPF_ALU64 | BPF_OR | BPF_X`
  - `off == 0`, `imm == 0`
  - destination must be instruction 3's destination
  - source must be instruction 0's temp
- Mask proof:
  - `bpf_jit_rotate_mask_matches(N, and_insn->imm)` must hold

Canonical params extracted:

- `DST_REG = mov2.dst_reg`
- `SRC_REG = mov1.src_reg`
- `AMOUNT = lsh.imm`
- `WIDTH = 32`

Validation checks performed:

- bounds: `idx + 6 <= insn_cnt`
- fixed ALU64 instruction class
- immediate-only AND mask
- fixed instruction order
- second copy must share original source
- temp must not alias source or final destination
- strict 32-bit complement relation
- exact mask proof via `bpf_jit_rotate_mask_matches()`

Semantic summary:

- This is the two-copy masked 32-bit rotate idiom.
- It is the masked analog of the 5-insn two-copy parser.

#### F. `bpf_jit_validate_rotate_rule()`

Location: `kernel/bpf/jit_directives.c:1613-1657`

Dispatcher behavior:

- Rejects `BPF_JIT_ROT_RORX` if BMI2 is unavailable.
- Dispatches by `rule->site_len`:
  - 4 -> `bpf_jit_parse_rotate_4insn()`
  - 5 -> `bpf_jit_parse_rotate_5insn()` first, then `bpf_jit_parse_rotate_5insn_masked()`
  - 6 -> `bpf_jit_parse_rotate_6insn()`
  - anything else -> reject
- On success, writes canonical params:
  - `DST_REG`
  - `SRC_REG`
  - `AMOUNT`
  - `WIDTH`

Observations:

- The 5-insn dispatch path is overloaded: one site length means either unmasked 64-bit or masked 32-bit.
- That makes the function compact, but it also hides the conceptual distinction between "shape family" and "site length".
- This is one of the reasons the rotate family feels larger than the raw emitter-side complexity would suggest.

### 1.4 Shared vs unique logic across the four parsers

Shared across all four:

- bounds checks (`idx + len <= insn_cnt`)
- reg-to-reg MOV copies with `off == 0`, `imm == 0`
- immediate-only shifts
- exact complement proof between left and right shift amounts
- final `OR_X` combine with zero `off`/`imm`
- normalization into the same four canonical params

Shared only within the two masked parsers:

- forced 32-bit semantic width
- `AND_K` proof step
- `bpf_jit_rotate_mask_matches()` usage
- ALU64-only instruction class

Shared only within the two two-copy parsers:

- two separate MOV copies from the same original source
- explicit non-aliasing between temp and final destination
- final destination may differ from source register

Shared only within the two in-place parsers:

- canonical `DST_REG == SRC_REG`
- result written back into the original source register

Unique to `bpf_jit_parse_rotate_4insn()`:

- width inference from MOV class
- support for both 32-bit and 64-bit forms
- support for commuted `lsh/rsh` order without a mask

Unique to `bpf_jit_parse_rotate_5insn()`:

- only unmasked 64-bit two-copy shape
- fixed instruction order

Unique to `bpf_jit_parse_rotate_5insn_masked()`:

- only masked in-place 32-bit shape
- commuted shift order allowed

Unique to `bpf_jit_parse_rotate_6insn()`:

- only masked two-copy 32-bit shape
- fixed instruction order

### 1.5 Concrete refactoring plan for ROTATE

#### What can become a shared rotate skeleton

The best refactor is not a fully generic mini-DSL. The practical sweet spot is a small spec-driven common parser with thin per-shape wrappers.

Recommended structure:

```c
struct rotate_parse_spec {
	u8 site_len;
	u8 fixed_width;          /* 0 => infer from MOV class */
	bool masked;
	bool two_copy;
	bool allow_shift_swap;
};

static bool bpf_jit_parse_rotate_common(..., const struct rotate_parse_spec *spec,
					struct bpf_jit_rotate_shape *shape);
```

That common skeleton should own the logic that is currently repeated in all four parsers:

- initial bounds check
- first MOV validation
- optional second MOV validation
- shift extraction and complement validation
- final OR validation
- canonical shape fill

It should also call small shared helpers:

- `rotate_infer_or_check_width()`
- `rotate_match_shift_pair()`
- `rotate_match_optional_mask()`
- `rotate_fill_shape()`

#### What should remain per-shape

These should stay as four small wrappers or four compact cases inside the common parser:

- exact instruction slot layout
  - where the optional `AND_K` sits
  - where the optional second MOV sits
- width mode
  - inferred 32/64 for 4-insn
  - fixed 64 for 5-insn two-copy
  - fixed 32 for masked forms
- topology
  - in-place vs separate destination copy
- shift ordering policy
  - commuted allowed for 4-insn and 5-insn masked
  - fixed order for 5-insn two-copy and 6-insn masked

#### Estimated LOC after refactoring

Current rotate bucket:

- about 461 LOC in `jit_directives.c`

Realistic post-refactor target without reducing any functionality:

- about 250 to 280 LOC

Estimated savings:

- about 180 to 210 LOC

#### Risk to correctness or security model

Risk level: medium

Why the risk is real:

- ROTATE is a fail-closed validator feeding native code emission.
- A refactor bug can silently broaden the accepted language, not just break a helper.
- The masked 32-bit forms are especially sensitive because the mask proof is the thing distinguishing a safe rotate match from an arbitrary shift-and-or sequence.

Main failure modes to watch:

- accidentally accepting `AND_X` or arbitrary `AND_K`
- confusing 32-bit masked semantics with 64-bit rotate semantics
- mishandling temp/dst alias constraints in two-copy shapes
- changing the meaning of `AMOUNT` even though the emitter still interprets it as "left rotate amount, emit right complement"

Security impact if refactored correctly:

- none; this is structural only

Security impact if refactored incorrectly:

- potentially wrong native code selection, which is exactly the class of bug this validator layer exists to prevent

Recommended safety bar for such a refactor:

- preserve emitter-side defensive checks
- add positive tests for all four accepted shapes
- add negative tests for:
  - bad complement amounts
  - bad masks
  - aliasing temp/dst cases
  - wrong opcode class
  - non-zero `off`/`imm`
  - unsupported site lengths

## Part 2: Logging

### 2.1 The eight logging/accounting functions

| Function | Needed? | Assessment |
| --- | --- | --- |
| `bpf_jit_recompile_log_ctx()` at `jit_directives.c:55` | no, as a function | Trivial getter around `bpf_prog_main_aux(prog)->jit_recompile_log` |
| `bpf_jit_recompile_log_appendv()` at `jit_directives.c:66` | yes | This is the actual append primitive |
| `bpf_jit_recompile_prog_log()` at `jit_directives.c:88` | maybe | Thin varargs wrapper over `log_appendv`; acceptable if callers need a public formatter |
| `bpf_jit_recompile_rule_log()` at `jit_directives.c:98` | maybe, but overbuilt | Useful conceptually, but implemented with unnecessary double formatting |
| `bpf_jit_recompile_log_alloc()` at `jit_directives.c:133` | yes, if custom log stays | Core lifecycle setup |
| `bpf_jit_recompile_log_copy_to_user()` at `jit_directives.c:161` | yes, if custom log stays | Core lifecycle finalize |
| `bpf_jit_recompile_log_free()` at `jit_directives.c:179` | yes, if custom log stays | Core lifecycle teardown |
| `bpf_jit_recompile_note_rule()` at `jit_directives.c:188` | no, as currently shaped | Only increments `jit_recompile_num_applied` when `applied == true`; `rule` argument adds no value |

Bottom line:

- Truly essential custom logic is only:
  - append
  - allocation
  - final user copy
  - teardown
- Everything else is wrapper-level ceremony.

### 2.2 Rule-log prefix logic

Current behavior in `bpf_jit_recompile_rule_log()`:

- formats the caller message into `char msg[192]`
- computes the site range prefix
- calls `bpf_jit_recompile_prog_log()` with a second format string

Problems:

- two formatting passes for one logical line
- extra fixed-size stack buffer
- one wrapper calling another wrapper after re-fetching the same log context
- prefix logic is centralized, but not in the cheapest form

Recommendation:

- Do not inline the prefix logic into every call site. That would increase duplication.
- Do simplify it into a single append path.

Better shape:

- one helper that appends `rule %u: form %u site ...: ` directly to the buffer
- then appends the caller's `fmt`/`va_list`
- then appends `\n`

That preserves centralized formatting while removing the double-formatting detour.

### 2.3 Alloc/copy_to_user/free lifecycle

Current implementation:

- allocates a `struct bpf_jit_recompile_log`
- allocates a separate kernel buffer
- appends strings into the kernel buffer
- copies back to userspace once at the end
- frees both allocations

Assessment:

- For a bounded max-64K diagnostic buffer, this is somewhat over-engineered in allocation shape and under-engineered in semantics.

Over-engineered aspects:

- two allocations where one would do
- separate `alloc/copy/free` helpers for a very simple buffer
- copies `min(user_size, kernel_size)` bytes instead of `min(len + 1, ...)`, so it may copy a large zero-filled tail

Under-engineered aspects:

- partial invalid log attributes silently disable logging instead of returning `-EINVAL`
- no truncation accounting or `log_size_actual`
- no fixed-vs-ring semantics

The current code is therefore not "too complex because the logging problem is hard". It is "custom in a place where the kernel already has a mature logging utility".

### 2.4 Comparison with verifier logging in `kernel/bpf/log.c`

Reference points:

- `struct bpf_verifier_log` has built-in scratch storage at `include/linux/bpf_verifier.h:605-620`
- attr validation is in `kernel/bpf/log.c:16-40`
- the streaming append path is in `kernel/bpf/log.c:60-139`
- finalize/truncation handling is in `kernel/bpf/log.c:226-297`
- `bpf_log()` is exported at `kernel/bpf/log.c:318-330`

Why the verifier log is a better architectural model:

- it already solves "bounded BPF diagnostic log to userspace"
- it already validates log attributes
- it already handles truncation semantics
- it already provides a public append helper
- it avoids a separately allocated large log buffer by using an embedded temp buffer

Most likely simplification path:

- replace the custom JIT recompile log object with `struct bpf_verifier_log`
- call `bpf_vlog_init()` on syscall entry
- use `bpf_log()` from the recompile path
- call `bpf_vlog_finalize()` on syscall exit

Expected effect:

- substantial LOC reduction in `jit_directives.c`
- fewer custom edge cases
- better consistency with the rest of kernel BPF diagnostics

Risk:

- low
- the main user-visible change would be exact truncation semantics and possibly return codes, not functionality or security

## Part 3: Overall architectural coupling and duplication

### 3.1 Duplicated checks between validator and emitter

There is meaningful duplication in three layers.

#### A. Rule/form/native-choice dispatch duplication

- `bpf_jit_native_choice_valid()` in `jit_directives.c:620`
- `bpf_jit_validate_canonical_site()` in `jit_directives.c:2322-2389`
- `bpf_jit_try_emit_rule()` in `bpf_jit_comp.c:3376-3462`

The same mapping is expressed multiple times:

- canonical form -> allowed native choice
- canonical form -> validator
- canonical form -> emitter

This is not wrong, but it is repetitive and easy to desynchronize.

#### B. CPU feature duplication

Feature gates appear in both validator and emitter:

- CMOV:
  - validator at `jit_directives.c:954`
- BMI2 / RORX:
  - validator at `jit_directives.c:1621-1624`
  - emitter at `bpf_jit_comp.c:2288-2314`
- MOVBE:
  - validator at `jit_directives.c:2080-2083`
  - emitter at `bpf_jit_comp.c:2633-2642`

Some duplication is justified as defense-in-depth, but architecturally this is also an x86 leak into the generic control-plane file.

#### C. Param shape duplication

Nearly every emitter revalidates canonical params:

- type checks
- width/range checks
- direction/ordering enums

Examples:

- `emit_canonical_select()` at `bpf_jit_comp.c:1320-1426`
- `emit_canonical_rotate()` at `bpf_jit_comp.c:2253-2330`
- `emit_canonical_endian_fusion()` at `bpf_jit_comp.c:2618-2655`
- `emit_canonical_bitfield_extract()` at `bpf_jit_comp.c:3303-3345`

Judgment:

- Keeping emitters defensive is correct.
- The problem is not the existence of defensive checks.
- The problem is that there is no shared way to express which checks are contractual vs merely defensive.

### 3.2 Is the validator -> params -> emitter interface clean?

It is mixed.

#### Clean forms

These are genuinely canonical:

- ROTATE
- WIDE_MEM
- ADDR_CALC
- ENDIAN_FUSION
- BITFIELD_EXTRACT

Why they are clean:

- the emitter consumes normalized semantic params
- the emitter does not need the original BPF site
- the validator can reject many source shapes while still producing the same canonical params

ROTATE is the cleanest example:

- four source parsers collapse into one 4-field canonical interface
- emitter logic is independent of which parser matched

#### Leaky forms

`ZERO_EXT_ELIDE` is leaky:

- validator stores the original ALU32 instruction fields directly into params at `jit_directives.c:1921-1974`
- emitter reconstructs a `struct bpf_insn` and calls the legacy ALU32 emitter at `bpf_jit_comp.c:2557-2580`
- that is not a canonical lowering contract; it is raw instruction replay with one tail insn removed

`BRANCH_FLIP` is even leakier:

- validator copies whole BPF body slices onto the heap and stores the pointers in canonical params at `jit_directives.c:2140-2252`
- emitter remeasures and re-emits those raw BPF bodies using `emit_linear_bpf_insn()` at `bpf_jit_comp.c:2993-3073`
- the so-called canonical params are carrying archived BPF bytecode, not a canonical semantic description

Conclusion:

- `struct bpf_jit_canonical_params` is currently playing three different roles:
  - true canonical IR
  - serialized raw BPF instruction fields
  - transport for heap pointers
- That is the clearest abstraction leak in the current design.

### 3.3 Helper granularity

There are too many tiny helpers in some places, but not in the places that matter most.

Examples of overly fine-grained helpers:

- duplicated `bpf_jit_rule_form()`:
  - `jit_directives.c:615`
  - `bpf_jit_comp.c:3347`
- tiny range wrappers:
  - `bpf_jit_compute_site_end()` at `jit_directives.c:669`
  - `bpf_jit_site_range_valid()` at `jit_directives.c:674`
- tiny param writers:
  - `bpf_jit_param_set_reg()` at `jit_directives.c:774`
  - `bpf_jit_param_set_imm()` at `jit_directives.c:781`
  - `bpf_jit_param_set_ptr()` at `jit_directives.c:788`
  - `bpf_jit_param_set_value()` at `jit_directives.c:794`
- tiny stage/lifecycle wrappers:
  - `bpf_jit_recompile_real_func_cnt()` at `jit_directives.c:320`
  - `bpf_jit_recompile_stage_begin()` at `jit_directives.c:325`
  - `bpf_jit_recompile_stage_end()` at `jit_directives.c:331`
  - `bpf_jit_recompile_next_func()` at `jit_directives.c:356`
  - `bpf_jit_recompile_image_prog()` at `jit_directives.c:406`
  - `bpf_jit_recompile_ksym_prog()` at `jit_directives.c:416`
- x86 staged getters that just expose common aux fields:
  - `bpf_jit_recompile_has_staged_image()` through `bpf_jit_recompile_staged_num_exentries()` at `bpf_jit_comp.c:5587-5621`

By contrast, some larger helpers are good and should stay:

- `bpf_jit_has_interior_edge()` at `jit_directives.c:694-745`
- `emit_linear_bpf_insn()` at `bpf_jit_comp.c:2880-2991`
- `emit_bitfield_extract_core()` behind the bitfield emitter

The current file shape has an uneven granularity problem:

- lots of 3- to 8-line wrappers
- plus a few 200+ line orchestration functions

### 3.4 Is generic validation doing redundant work?

Yes, partly.

Redundant or mostly redundant:

- generic site range check in `bpf_jit_validate_rule()` at `jit_directives.c:2408-2412`
- then many per-form parsers re-check `idx + len <= insn_cnt`
- generic native-choice validation at `jit_directives.c:2414-2418`
- then emitter dispatch re-checks native choice in `bpf_jit_try_emit_rule()`
- generic side-effect rejection at `jit_directives.c:2420-2425`
- then most pure-ALU per-form parsers already accept only instruction classes that cannot contain stores/calls

Not redundant:

- `bpf_jit_has_interior_edge()` at `jit_directives.c:2430-2434`

Reason:

- none of the local parsers can detect jumps from outside the site into the interior
- that is a global control-flow property and is the right job for a generic pass

Recommendation:

- remove duplicated local bounds checks where the parser is only called from validated entry points
- keep interior-edge validation
- keep emitter defensive checks, but centralize them where possible

### 3.5 Snapshot/rollback and staged-image abstraction

Overall judgment:

- the staged commit/abort design is justified
- the complexity is mostly real, not invented

Why it is justified:

- multi-subprog JIT needs two passes
- subprog references must be rewritten to staged addresses
- kallsyms/extable/priv-stack ownership changes must be staged and then committed
- RCU synchronization is required before freeing old live images

The real architectural problem is not "too many abstractions" in the large.
It is "too many tiny wrappers around a still-monolithic orchestration function".

Examples:

- `bpf_jit_recompile_prog_images()` is still a 228-LOC phase machine at `jit_directives.c:2844-3071`
- but it bounces through many tiny helper functions and x86 accessors to do very direct field access

The code would be easier to audit if it were refactored in one of two directions:

- fewer trivial wrappers and more explicit field access
- or fewer tiny wrappers plus more phase-level helpers

The current midpoint is the least clear one.

### 3.6 Which generic helpers could be replaced by existing kernel APIs?

Directly replaceable or largely replaceable:

- custom JIT recompile logging
  - replace with `struct bpf_verifier_log`, `bpf_vlog_init()`, `bpf_log()`, `bpf_vlog_finalize()`
- x86 staged-field getters
  - replace with static inline field accessors in common headers

Possibly worth promoting to common helpers:

- `bpf_pseudo_call_insn()` at `jit_directives.c:562`
  - kernel already has `bpf_pseudo_func()` as a common inline in `include/linux/bpf.h`
  - verifier has a private `bpf_pseudo_call()` helper in `kernel/bpf/verifier.c`
  - exposing a common inline would remove another one-off helper

Not realistically replaceable with existing kernel APIs:

- per-form semantic validators
- interior-edge detection
- canonical param synthesis
- policy-rule overlap logic

Reason:

- verifier CFG state and instruction semantics are not retained in a reusable runtime API after load
- these checks are specific to this re-JIT facility

Conclusion:

- only a minority of the 518 LOC generic-helper bucket can be replaced by pre-existing kernel APIs
- but those replaceable parts are exactly the highest-boilerplate ones

## Part 4: Concrete reduction plan

### 4.1 Safe mechanical refactoring

| Priority | Opportunity | Change | Estimated LOC saved | Risk | Functionality / security impact |
| --- | --- | --- | ---: | --- | --- |
| P1 | Reuse verifier logging infrastructure | Replace custom JIT log object/functions with `bpf_vlog_init()`, `bpf_log()`, `bpf_vlog_finalize()` | 70-100 | Low | Diagnostics only; no security change |
| P2 | Inline trivial staged getters | Replace x86 out-of-line `bpf_jit_recompile_staged_*` getters with common static inlines | 25-40 | Low | No behavior change |
| P3 | Remove dead-thin wrappers | Inline or collapse `bpf_jit_recompile_log_ctx()`, `bpf_jit_recompile_note_rule()`, duplicated `bpf_jit_rule_form()` | 20-35 | Low | No behavior change |
| P4 | Collapse tiny stage/ksym wrappers | Merge `shadow_ksym_prepare` into `shadow_ksym_add`; inline `real_func_cnt`, `next_func`, `image_prog`, `ksym_prog` where they are only trivial projections | 30-50 | Low | No behavior change |
| P5 | Reduce repeated bounds boilerplate | Let generic validator prove site range once, then pass validated slices into per-form parsers | 20-40 | Low to Medium | No intended behavior change; keep fail-closed semantics |
| P6 | Simplify rule logging path | Keep centralized rule prefixing, but remove the extra `msg[192]` plus second format pass | 15-25 | Low | No security change; tiny log-format risk |
| P7 | Centralize form/native-choice metadata | Replace duplicated switch-level choice validation with a small table or shared metadata helper | 20-40 | Low to Medium | No functionality change if defensive checks remain |

Safe mechanical subtotal:

- about 200 to 330 LOC

### 4.2 Needs careful design review

| Priority | Opportunity | Change | Estimated LOC saved | Risk | Functionality / security impact |
| --- | --- | --- | ---: | --- | --- |
| P1 | Unify the ROTATE family | Introduce a spec-driven common rotate skeleton and keep only thin per-shape wrappers | 180-210 | Medium | No intended functionality change, but validator correctness is security-sensitive |
| P2 | Clean up canonical param leakage | Give `ZERO_EXT_ELIDE` and `BRANCH_FLIP` a cleaner interface than raw instruction replay / pointer-valued params | 30-70 | Medium | Improves structure; must preserve fail-closed behavior |
| P3 | Move arch feature knowledge out of generic validator | Replace x86 `boot_cpu_has()` checks in `jit_directives.c` with backend capability helpers or metadata | 15-30 | Medium | No functionality change; improves layering |
| P4 | Compact active-rule representation | Store active rules separately or compact after validation so lookup/emitter do not have to reason about inactive entries | 20-40 | Medium | No intended behavior change; policy error semantics need review |
| P5 | Rebalance recompile orchestration granularity | Replace tiny field wrappers with phase-level helpers inside `bpf_jit_recompile_prog_images()` | 20-50 | Medium | Mostly auditability and maintainability |

Careful-design subtotal:

- about 265 to 400 LOC

### 4.3 Total achievable reduction

Conservative, functionality-preserving estimate:

- about 400 to 550 LOC

Aggressive but still functionality-preserving estimate:

- about 550 to 650 LOC

What is not included in those numbers:

- dropping rarely used forms
- dropping `RORX`
- reducing coverage of masked rotate variants
- any security-model simplification

Those would save more LOC, but they would also reduce functionality, so they are out of scope for this estimate.

## Final judgment

The two biggest structural findings are:

1. ROTATE is the single largest overgrown validator family, but it is overgrown because the same topology checks are written four times. It is the highest-value refactor target.
2. The validator -> params -> emitter contract is inconsistent across forms. ROTATE/WIDE/LEA/ENDIAN/BITFIELD are genuinely canonical; ZERO_EXT and BRANCH_FLIP are not.

The logging layer is a smaller but cleaner win:

- it duplicates a kernel BPF facility that already exists
- it adds little architectural value of its own
- it can likely be simplified with low risk

If the goal is maximum LOC reduction with low risk, start with:

1. logging reuse
2. staged getter / trivial wrapper cleanup
3. duplicated form/native-choice metadata cleanup

If the goal is maximum architectural payoff, do ROTATE next, but only with a negative-test-heavy refactor because that validator is part of the fail-closed security boundary.
