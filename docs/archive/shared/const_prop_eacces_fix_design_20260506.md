# const_prop EACCES helper-arg safety check design, 2026-05-06

Scope: design only. This document describes a P0 fix for `const_prop` verifier
rejections caused by replacing helper pointer-argument setup with scalar
immediates. No runner behavior, pass code, benchmark config, or result format is
changed by this document.

Primary background:

- `docs/tmp/bpfopt_eacces_high_rejection_20260506.md`, especially section 8.
- Current source inspected at `bpfopt/crates/bpfopt/src/passes/const_prop.rs`.
- Helper ABI source inspected in `vendor/linux-framework/include/uapi/linux/bpf.h`,
  `vendor/linux-framework/include/linux/bpf.h`, and helper proto definitions under
  `vendor/linux-framework/kernel/` and `vendor/linux-framework/net/`.

## 1. Problem summary

In the selected KVM smoke corpus, `const_prop` is the first failing pass for
182/189 selected-app EACCES failures and 140/145 tracee+cilium EACCES failures.
The concentrated verifier symptoms are helper arguments that became scalar:

| helper/site | observed tracee+cilium count | relevant expected type |
|---|---:|---|
| `bpf_probe_read_kernel#113` | 108 | memory destination pointer in `R1` |
| `bpf_map_lookup_elem#1` | 21 | map pointer in `R1`, key pointer in `R2` |
| `bpf_skb_change_tail#38` | 4 | skb context pointer in `R1` |
| `bpf_tail_call#12` | 3 | context pointer in `R1`, map pointer in `R2` |
| skb/ringbuf/perf helpers | smaller tail | context/map/memory/ringbuf pointer args |

Representative failure: tracee prog 20 `sys_enter_submit` reaches
`bpf_probe_read_kernel#113` with `R1 type=scalar expected=fp, pkt, pkt_meta,
map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_`. The high-level failure
mode is that `const_prop` uses a verifier exact constant fact keyed by `(pc, reg)`
and emits a plain `MOV`/`LD_IMM64` into that register. The immediate preserves the
numeric value but loses verifier provenance such as `fp`, `ctx`, `map_ptr`,
`map_value`, packet pointer, ringbuf memory, trusted pointer, or dynptr.

## 2. Current const_prop behavior

The current pass has three relevant pieces.

### 2.1 Oracle wiring

`VerifierExactConstOracle::from_states()` builds exact scalar facts from verifier
delta states at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:120-143`.
For each `VerifierInsnKind::InsnDeltaState`, it records observations keyed by
`(state.pc, regno)` at `const_prop.rs:124-134`, keeps only consensus facts at
`const_prop.rs:137-140`, and stores them in `facts`.

`OracleExactAccumulator::observe()` explicitly invalidates non-scalar states at
`const_prop.rs:77-85`. That means the current bug is not that a non-scalar
verifier state is directly emitted. The more precise failure is that a scalar
exact fact at a sensitive program point can be used to replace an instruction
whose original bytecode was still required to construct or preserve typed pointer
provenance before a helper call.

The pass constructs the oracle in `ConstPropPass::run()` at
`const_prop.rs:190`, computes block entry states at `const_prop.rs:191`, then
simulates each CFG block and records replacements at `const_prop.rs:195-203`.
`analyze_instruction()` later applies oracle post-state facts to the simulated
state at `const_prop.rs:425`.

### 2.2 ALU/MOV replacement

For ALU/ALU64 instructions, `analyze_instruction()` calls
`fold_alu_instruction()` at `const_prop.rs:401-408`.

`fold_alu_instruction()` currently:

- reads the destination register exact value from the oracle first via
  `oracle.exact_for_instruction(pc, insn.dst_reg(), ...)` at
  `const_prop.rs:436-438`;
- falls back to local `evaluate_alu_result()` if the oracle has no exact fact at
  `const_prop.rs:438`;
- skips only already-immediate `MOV K` at `const_prop.rs:440-443`;
- emits a constant-load candidate for every other foldable ALU/MOV at
  `const_prop.rs:443`;
- returns the replacement if the candidate differs from the original instruction
  at `const_prop.rs:446`.

There is no check here for whether the destination register, or a later alias of
that destination register, will be consumed as a typed helper argument before it
is redefined.

### 2.3 Constant emission

`emit_constant_load()` at `const_prop.rs:688-697` emits only plain scalar forms:

- `BpfInsn::mov32_imm(dst_reg, imm)` for 32-bit ALU results at
  `const_prop.rs:689-691`;
- `BpfInsn::mov64_imm(dst_reg, imm)` if the 64-bit value fits signed imm32 at
  `const_prop.rs:693-695`;
- plain `emit_ldimm64(dst_reg, value)` otherwise at `const_prop.rs:696`.

These forms do not carry pseudo source-register tags. The pass already avoids
folding typed `LD_IMM64` pseudo immediates such as map FDs/map values by marking
nonzero `src_reg` `LD_IMM64` as unknown at `const_prop.rs:381-391`, and there is
a unit test for that at `const_prop.rs:1023-1031`. That protection does not cover
ALU/MOV instructions that feed helper argument registers.

### 2.4 Diagnostics today

Current `const_prop` diagnostics are emitted at `const_prop.rs:290-299`:

- `const_prop_alu_materialized`
- `const_prop_branch_folded_taken`
- `const_prop_branch_folded_not_taken`
- `const_prop_cleanup_removed_insns`

The fix should add `const_prop_helper_arg_refused` next to these counters. The
prompt referenced older line numbers around `const_prop.rs:268-273`; in the
current file, the diagnostic vector is at `const_prop.rs:290-299`.

## 3. Desired safety property

Before replacing an ALU/MOV instruction with a scalar immediate, `const_prop`
must conservatively answer:

Would the value defined by this instruction reach the next helper call, inside
the same basic block, as an argument register whose helper ABI requires a typed
pointer-like value rather than an arbitrary scalar?

If yes or unknown, refuse the replacement. If no, keep existing behavior.

This is deliberately narrower than proving all verifier provenance. It targets
the dominant EACCES mode while preserving scalar-only constant propagation and
branch folding.

Non-goals:

- Do not change ReJIT filtering, pass lists, or runner behavior.
- Do not implement runtime helper ABI probing.
- Do not infer full verifier types in `bpfopt`.
- Do not rewrite helper calls or typed pointer materialization.
- Do not disable all oracle facts globally unless later validation shows this
  narrower gate is insufficient.

## 4. Helper ABI table

Add a new internal module:

- `bpfopt/crates/bpfopt/src/passes/const_prop_helpers.rs`

Export only pass-internal lookup APIs, for example:

- `helper_arg_type(helper_id: i32, arg_reg: u8) -> HelperArgClass`
- `helper_arg_requires_pointer(helper_id: i32, arg_reg: u8) -> HelperArgDecision`

The module should be added as `mod const_prop_helpers;` in
`bpfopt/crates/bpfopt/src/passes/mod.rs`, but not publicly re-exported.

### 4.1 Data source

Use a static table derived from the project kernel headers and helper proto
definitions:

- Helper ids come from `___BPF_FUNC_MAPPER` in
  `vendor/linux-framework/include/uapi/linux/bpf.h:5924-5964` and
  `vendor/linux-framework/include/uapi/linux/bpf.h:6034-6058`.
- Argument type names come from `enum bpf_arg_type` in
  `vendor/linux-framework/include/linux/bpf.h:832-887`.
- `struct bpf_func_proto` stores `arg1_type` through `arg5_type` at
  `vendor/linux-framework/include/linux/bpf.h:920-944`.
- Standard helper proto mappings are returned from `bpf_base_func_proto()` at
  `vendor/linux-framework/kernel/bpf/helpers.c:2051-2076`.
- Network helper proto mappings for skb helpers are under
  `vendor/linux-framework/net/core/filter.c` dispatch sites such as
  `filter.c:8341`, `filter.c:8373`, `filter.c:8737`, and `filter.c:8741`.

Do not scrape these files at runtime. Runtime vmlinux/BTF extraction is higher
risk, can fail in benchmark environments, and would add hidden capability
dependencies to a pure bytecode pass. A hardcoded static table is deterministic,
reviewable, and adequate for the current supported corpus.

### 4.2 Arg classification

Represent helper args by the pass-level question, not by the exact kernel enum:

| class | examples | gate behavior |
|---|---|---|
| `Unused` | `ARG_DONTCARE` or missing `argN_type` | no refusal |
| `ScalarOk` | `ARG_ANYTHING`, integer flags, integer indexes | no refusal |
| `ConstSize` | `ARG_CONST_SIZE`, `ARG_CONST_SIZE_OR_ZERO`, `ARG_CONST_ALLOC_SIZE_OR_ZERO` | no refusal for pointer provenance; scalar is legal |
| `PointerRequired` | ctx, map ptr, map key/value, mem, uninit mem, ringbuf mem, dynptr, BTF ptr, stack, timer, spin lock, func ptr, const str, arena | refuse if reached from candidate |
| `UnknownHelper` | helper id absent from table, nonstandard call, kfunc dispatch not represented | refuse if reached from candidate |

Treat all pointer-like base types and pointer-extended variants as
`PointerRequired`, including nullable or read-only/write-only flag variants:

- `ARG_CONST_MAP_PTR`
- `ARG_PTR_TO_MAP_KEY`
- `ARG_PTR_TO_MAP_VALUE`
- `ARG_PTR_TO_MAP_VALUE_OR_NULL`
- `ARG_PTR_TO_MEM`
- `ARG_PTR_TO_MEM_OR_NULL`
- `ARG_PTR_TO_UNINIT_MEM`
- `ARG_PTR_TO_FIXED_SIZE_MEM`
- `ARG_PTR_TO_CTX`
- `ARG_PTR_TO_CTX_OR_NULL`
- `ARG_PTR_TO_RINGBUF_MEM`
- `ARG_PTR_TO_DYNPTR`
- `ARG_PTR_TO_BTF_ID` and nullable/trusted/percpu variants
- `ARG_PTR_TO_SOCKET`, `ARG_PTR_TO_SOCK_COMMON`, stack, spin lock, timer, func,
  const string, kptr exchange destination, and arena pointer classes

Do not mark `ARG_ANYTHING` as pointer required. Several high-frequency helpers
use `ARG_ANYTHING` for offsets, flags, indexes, or unsafe source pointers that
the verifier intentionally accepts as scalar.

### 4.3 Specific high-frequency helpers

The table must cover at least these helpers before enabling the gate:

| helper | id source | proto source | required pointer args |
|---|---|---|---|
| `bpf_map_lookup_elem#1` | `uapi/linux/bpf.h:5926` | `kernel/bpf/helpers.c:50-57` | `R1=ARG_CONST_MAP_PTR`, `R2=ARG_PTR_TO_MAP_KEY` |
| `bpf_get_smp_processor_id#8` | `uapi/linux/bpf.h:5933` | `kernel/bpf/helpers.c:160-165` and raw variant `helpers.c:633-637` | none |
| `bpf_skb_store_bytes#9` | `uapi/linux/bpf.h:5934` | `net/core/filter.c:1736-1745` | `R1=ARG_PTR_TO_CTX`, `R3=ARG_PTR_TO_MEM | MEM_RDONLY` |
| `bpf_tail_call#12` | `uapi/linux/bpf.h:5937` | `kernel/bpf/core.c:3046-3056` | `R1=ARG_PTR_TO_CTX`, `R2=ARG_CONST_MAP_PTR` |
| `bpf_perf_event_output#25` | `uapi/linux/bpf.h:5950` | generic `kernel/bpf/helpers.c:648-657`, tracing `kernel/trace/bpf_trace.c:695-703`, skb `net/core/filter.c:4693-4701` | `R1=ARG_PTR_TO_CTX`, `R2=ARG_CONST_MAP_PTR`, `R4=ARG_PTR_TO_MEM` |
| `bpf_skb_change_tail#38` | `uapi/linux/bpf.h:5963` | `net/core/filter.c:3859-3866` | `R1=ARG_PTR_TO_CTX` |
| `bpf_probe_read_kernel#113` | `uapi/linux/bpf.h:6038` | `kernel/trace/bpf_trace.c:241-248` | `R1=ARG_PTR_TO_UNINIT_MEM`; `R3=ARG_ANYTHING` is not pointer-gated |
| `bpf_ringbuf_reserve#131` | `uapi/linux/bpf.h:6056` | `kernel/bpf/ringbuf.c:551-557` | `R1=ARG_CONST_MAP_PTR` |
| `bpf_ringbuf_submit#132` | `uapi/linux/bpf.h:6057` | `kernel/bpf/ringbuf.c:593-598` | `R1=ARG_PTR_TO_RINGBUF_MEM | OBJ_RELEASE` |

The implementation should not stop at these helpers. Build the initial static
table for all standard helpers visible in the vendored kernel, roughly 100+
entries, so unknown-helper refusal is a safety fallback rather than the common
path in supported apps.

## 5. Window and flow check

The gate should run only for ALU/MOV materialization candidates, not branch
folding. A candidate is:

- current `pc`;
- original instruction `insn`;
- destination register `dst = insn.dst_reg()`;
- CFG block bounds `[block.start, block.end)`;
- replacement that would be emitted by `fold_alu_instruction()`.

The check answers whether the value defined at `pc` is the reaching definition
for a pointer-required helper argument before being overwritten or leaving the
current block.

### 5.1 Integrating block context

`fold_alu_instruction()` currently receives only `(insns, pc, state, oracle)` at
`const_prop.rs:429-434`, so it cannot know block end. Change the internal call
chain so `simulate_block()` passes `block.end` or a small `ConstPropSafetyCtx`
into `analyze_instruction()` and `fold_alu_instruction()`.

Design shape:

- `simulate_block(insns, start, end, state, oracle, replacements, stats)`
- `analyze_instruction(insns, pc, block_end, state, oracle, stats)`
- `fold_alu_instruction(insns, pc, block_end, state, oracle, stats)`

The first `simulate_block()` call used by `solve_block_entry_states()` passes no
replacement map today (`const_prop.rs:319-325`). It should also pass no mutable
diagnostic stats, because the fixed-point analysis must not count hypothetical
refusals repeatedly. Only the second simulation in `run()` that actually records
replacements should update `helper_arg_refused`.

### 5.2 Forward alias tracking

Start with one reaching-definition token:

- `TrackedValue { defining_pc: pc, regs: {dst} }`

Scan forward from `pc + insn_width(&insns[pc])` to `block_end`, advancing by
`insn_width()`. Stop at block end.

For each instruction:

1. If it is a normal helper call (`insn.is_call() && insn.src_reg() == 0`):
   inspect helper id `insn.imm`.
2. For each `R1..R5` that currently aliases the candidate value, ask the helper
   ABI table whether that helper argument is pointer-required.
3. If the helper id is unknown, refuse conservatively if any alias is in `R1..R5`.
4. If any matching helper arg is pointer-required, refuse the candidate.
5. Regardless of whether refused, stop at the helper call. Helper calls clobber
   caller-saved registers and are the immediate safety boundary this gate is
   protecting.

For non-call instructions, update aliases:

- For `MOV64_REG dst, src` or `MOV32_REG dst, src`:
  remove `dst` from aliases first; if `src` is an alias, insert `dst`.
- For ALU ops, loads, stores, `LD_IMM64`, and immediate MOV into a tracked reg:
  remove any defined destination register from aliases. These are new definitions
  and break the candidate flow.
- For stores, no register alias is created; only kill none unless the insn also
  defines a register.
- For conditional/unconditional jumps inside the block, stop and return safe
  for this local gate. Cross-edge reasoning is intentionally not part of P0.
- For kfunc or pseudo calls (`insn.is_call() && insn.src_reg() != 0`), refuse if
  any alias is in `R1..R5`, because the helper ABI table does not describe kfunc
  BTF arguments.

This is a forward def-use scan from the candidate to the call. It is equivalent
to the requested single-basic-block backward "nearest def" check, but it fits the
existing `fold_alu_instruction()` decision point and avoids building SSA.

### 5.3 Redefinition examples

Refuse:

```text
pc:   r1 += -8              ; candidate would become mov r1, scalar
pc+1: r2 = 64
pc+2: r3 = ...
pc+3: call bpf_probe_read_kernel#113
```

`R1` remains an alias at the helper, and helper #113 requires
`R1=ARG_PTR_TO_UNINIT_MEM`.

Refuse through move:

```text
pc:   r6 += -8              ; candidate defines r6
pc+1: r1 = r6               ; alias r1
pc+2: call bpf_probe_read_kernel#113
```

`R1` is an alias at the helper.

Do not refuse after redefinition:

```text
pc:   r1 += 1               ; candidate defines r1
pc+1: r1 = r10
pc+2: r1 += -8
pc+3: call bpf_probe_read_kernel#113
```

The candidate value is killed at `pc+1`; the helper observes a later definition.

Do not refuse scalar-only helper:

```text
pc:   r1 += 1
pc+1: call bpf_get_smp_processor_id#8
```

Helper #8 takes no pointer args and has no argument proto fields, so the
candidate is not helper-arg unsafe.

## 6. Unknowns and conservative fallback

Use fail-safe decisions:

- Unknown helper id: if candidate value reaches any `R1..R5` at the call, refuse.
- Nonzero `src_reg` call, including kfunc/pseudo dispatch: if candidate reaches
  any `R1..R5`, refuse.
- Malformed `LD_IMM64` width near block end: treat as unsafe in the scan rather
  than trying to reason around a malformed instruction stream.
- Missing static table entry for a helper that appears in supported corpus:
  refuse first, then update the table in a later patch with a test.

This intentionally trades some lost ALU materialization for retained-program
coverage. The current failure rate is high enough that false negatives are more
expensive than false positives.

## 7. Integration details

### 7.1 Stats

Add an internal stats struct for the second simulation pass:

- `helper_arg_refused: usize`

Only increment when a candidate replacement would otherwise be emitted and the
helper-arg gate refuses it. Do not count non-foldable instructions.

Expose it as:

- `const_prop_helper_arg_refused=<n>`

Add this to the existing diagnostics vector at `const_prop.rs:294-299`, next to
the four counters added by the recent const_prop diagnostics work. This is raw
pass diagnostic metadata, not a performance aggregation or benchmark summary.

`sites_applied` should remain `replacements.len()` at `const_prop.rs:286-293`.
The refused counter is separate; it must not be folded into `sites_skipped` unless
the pass already has a structured skipped-site convention for this type of
diagnostic.

### 7.2 Replacement timing

Run the helper gate after computing the candidate constant and before
`replacement_if_changed()` returns it:

1. `result = oracle.exact_for_instruction(...).or_else(evaluate_alu_result)?`
2. build `candidate = emit_constant_load(...)`
3. if candidate equals original, return `None`
4. if helper gate says unsafe, increment `helper_arg_refused` and return `None`
5. otherwise return candidate

Checking after candidate construction avoids counting instructions where the pass
would not change bytecode. Checking before inserting into `replacements` keeps the
rest of the address-map/remap logic unchanged.

### 7.3 Branch folding remains separate

`fold_jump_instruction()` at `const_prop.rs:449-462` should not use the helper
arg gate. Branch folding replaces a conditional jump with `JA` or `NOP`; it does
not directly materialize a scalar into helper argument registers. Any future
branch-folding verifier issue should be diagnosed separately.

### 7.4 Module boundaries

Keep helper ABI code pass-private:

- no new crate-level syscall dependency;
- no dependency from `bpfopt` to daemon or `bpfprof`;
- no runtime kernel calls;
- use `kernel_sys::BPF_FUNC_*` constants for ids where available instead of
  duplicate numeric literals in implementation code;
- keep source comments short and focused on ABI provenance.

This respects the existing no CLI cross-dependency and `kernel-sys` syscall
boundary rules.

## 8. Helper table rollout

Recommended rollout:

1. Land the static table with all standard helpers in the vendored kernel's
   `___BPF_FUNC_MAPPER`, marking only known pointer-like args as
   `PointerRequired`.
2. Add a focused table coverage test for the high-frequency helpers in section
   4.3.
3. Add const_prop flow tests in section 9.
4. Run the supported corpus smoke and inspect only raw pass diagnostics and
   verifier acceptance. Do not add framework-side summaries.

The initial table can be manually hardcoded in about 200-300 lines if the enum is
compressed to `[HelperArgClass; 5]` rows and scalar/unused args are omitted or
represented by defaults. Runtime extraction from vmlinux BTF is not recommended
for this P0 fix.

## 9. Validation plan

Unit tests should be bug-detection tests, not tautologies.

1. `bpf_probe_read_kernel` direct arg refuse:
   candidate defines `R1`, next helper is #113, table requires
   `R1=PointerRequired`, expect original instruction preserved and
   `const_prop_helper_arg_refused=1`.
2. `bpf_map_lookup_elem` map/key refuse:
   candidate defines `R1` or moves through another reg into `R1` before helper #1,
   expect refusal for `ARG_CONST_MAP_PTR`; separately cover `R2` key pointer if
   compact enough.
3. Scalar helper does not refuse:
   candidate reaches `R1` before `bpf_get_smp_processor_id#8`, expect existing
   const-prop materialization still happens and refused counter stays zero.
4. Cross-BB does not over-refuse:
   candidate in one block, helper in successor block. P0 single-BB window should
   not refuse solely because of the successor helper. This locks in the intended
   conservative scope and avoids accidental whole-CFG scans without type proof.
5. Redefinition kills alias:
   candidate defines `R1`, a later instruction redefines `R1`, then helper #113.
   Expect no refusal because the candidate no longer reaches the helper.
6. Alias move refuses:
   candidate defines `R6`, `R1 = R6`, then helper #113. Expect refusal.

Smoke validation:

- Rerun tracee and cilium KVM smoke first, because they account for 140/145
  tracee+cilium EACCES failures attributed to `const_prop`.
- Then rerun the selected supported apps where `const_prop` was the first EACCES
  pass.
- Check that `const_prop` EACCES drops materially, especially at helper #113 and
  helper #1.
- Check raw pass reports for `const_prop_helper_arg_refused` and
  `sites_applied`. The expected effect is a moderate loss of ALU materialization,
  not a broad disablement of branch folding.

Do not add benchmark-framework aggregation, ratios, geomeans, win/loss summaries,
or markdown rollups as part of validation. Use external analysis scripts if
performance interpretation is needed.

## 10. Risks and mitigations

| risk | trigger | mitigation |
|---|---|---|
| Over-conservative refusal | table marks a scalar arg as pointer-required | derive rows from `struct bpf_func_proto`; keep `ARG_ANYTHING` and const-size classes scalar-ok |
| Missed helper id | new kernel helper not in table | unknown helper id refuses if candidate reaches `R1..R5`; add table rows later |
| Cross-BB false negative | candidate in BB1 reaches helper in BB2 | accepted P0 limitation; if EACCES remains, extend to bounded successor scan with CFG/type proof |
| Redefinition false positive | candidate killed before helper | alias tracking removes redefined regs before helper inspection |
| kfunc helper gap | `src_reg != 0` call with BTF arg types | refuse if candidate reaches `R1..R5`; kfunc-specific ABI table is out of scope |
| Lost optimization | many arg-setup ALU ops no longer materialize | expected tradeoff; preserve branch folding and scalar-only chains |
| Table drift | vendored kernel helper ABI changes | table coverage tests for high-frequency helpers; update table when kernel vendor changes |

## 11. Estimated implementation size

Estimated code size for the follow-up implementation:

| area | estimate |
|---|---:|
| static helper ABI table | 250 lines |
| helper arg lookup/classification | 80 lines |
| single-BB alias/flow gate | 100 lines |
| const_prop call-chain/stats integration | 30 lines |
| focused unit tests | 150 lines |
| total | about 600 lines |

Risk: medium. Correctness risk is mostly false negatives in unusual cross-BB
flows and table mistakes. The design is intentionally fail-safe for unknown
helper/kfunc cases.

## 12. Interaction with current work

This fix is local to `const_prop`. It does not conflict with the recent `#204`
diagnostic counters: the new counter is appended to the existing diagnostic list.
It also does not conflict with the DCE narrowing work; DCE's remaining `!read_ok`
failures are a separate issue and should not be hidden by this gate.

The gate should not add pass exclusions, ReJIT filtering, or runner-side special
cases. If a program still fails ReJIT after this fix, the framework should record
that raw error naturally.

## 13. Implementation decision

Recommended P0 patch:

- Add pass-private static helper ABI metadata in
  `bpfopt/crates/bpfopt/src/passes/const_prop_helpers.rs`.
- Thread block-end context and mutable stats through the replacement-recording
  simulation path.
- Gate only ALU/MOV constant materialization before inserting replacements.
- Refuse candidate replacements whose value reaches a pointer-required helper arg
  in `R1..R5` before redefinition or block exit.
- Refuse unknown helper/kfunc cases if candidate reaches `R1..R5`.
- Preserve branch folding and scalar-only const-prop behavior.

This addresses the observed `R# type=scalar expected=...` helper-argument
EACCES mode without disabling `const_prop` wholesale.
