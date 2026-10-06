# ARM64 ReverseSim Formal Verification Plan

This note records a concrete plan for formally validating the ARM64
ReverseSim/eBPF simulator prototype under `native-sim/arm64`. It is a design
and audit document, not a benchmark result.

## Current State

The repository has an ARM64 ReverseSim prototype:

- `native-sim/arm64/README.md` describes the current scope as C-authored
  simulator macros for the AArch64 subset emitted by current micro native
  builds, generated micro proof objects, and a hardcoded BPF load smoke.
- `native-sim/arm64/arm64_sim.h` enumerates the supported instruction classes,
  including move, ALU, shift, multiply/divide, `EXTR`, bitfield operations,
  byte-reversal, comparisons, `CCMP`, conditional selects, loads/stores,
  `LDP`/`STP`, and a small vector-like subset for the current micro programs.
- `native-sim/arm64/arm64_sim_local_bpf.h` contains the verifier-facing eBPF
  macro implementation.
- `runner/mk/build.mk` builds ARM64 simulator proof objects through
  `host-arm64-sim-proofs`, but ARM64 corpus native artifacts are not currently
  produced in the same way as x86 native artifacts.

This means ARM64 already has a useful proof prototype, but not a complete
production-faithful native-in-kernel ARM64 path and not a formal specification
checked against the official architecture semantics.

## Verification Goal

The target theorem should be limited and explicit:

For every accepted ARM64 proof artifact in the supported subset, starting from
the same BPF runtime ABI state, executing the generated eBPF proof program
performs the same architectural state transition and observable external events
as executing the linked native AArch64 instruction stream, up to explicitly
modeled helper/map/tail-call contracts.

Observable results include:

- return value;
- writes to modeled BPF-visible memory, including packet, stack, map value,
  rodata-local state, and skb/XDP ABI scratch where applicable;
- helper, map, kfunc, and tail-call boundary events;
- control-flow reachability and termination for the generated artifact.

The proof should not claim safety or equivalence for arbitrary AArch64 code. It
only covers instructions, addressing modes, relocation shapes, and ABI events
that the generator accepts.

## Non-Goals

Do not try to verify the entire ARM64 architecture in this project.

Do not try to prove Linux helper implementations correct. Helper/map/kfunc
boundaries should be modeled as external events with pre/postconditions.

Do not prove the C compiler correct as part of the first milestone. The first
paper-grade claim can trust the fixed simulator build toolchain in the same way
kernel/verifier builds are trusted. A later stronger result could generate the
simulator from a machine-readable semantics.

Do not use differential testing alone as proof. Running against QEMU, FVP, or
real hardware is valuable for bug finding, but it is not the formal argument.

## Trusted References

ARM64/AArch64 has an official architecture specification. The relevant layer is
the AArch64 execution state and the A64 instruction set, as specified by the Arm
Architecture Reference Manual for A-profile architecture.

Useful semantic sources:

- Arm official pseudocode / machine-readable instruction descriptions.
- Sail AArch64 semantics, usable as a machine-checkable reference.
- Isla/Islaris-style validation against authoritative ISA semantics.
- Arm official C reference simulator, if licensing and integration are
  practical.

The repository already records this direction in `docs/nativebpf_idea.md`:
trusted simulator sources can include a handwritten reference simulator, a
simulator generated from a machine-checkable ISA spec such as Sail, or Arm's
official C reference simulator.

## Formal Model

The model should be small and close to the emitted native code.

Architectural state:

- `X0..X30`, `SP`, and `PC`;
- `NZCV` flags;
- only the vector/FP state that the accepted subset actually uses, currently
  represented by the `D0/Q0`-style micro subset in the simulator;
- little-endian memory regions used by the proof artifact.

Memory regions:

- BPF entry ABI object for XDP/skb;
- packet data and packet end;
- modeled native stack;
- map value memory;
- rodata/local data materialized by relocations;
- helper-visible stack arguments.

External events:

- `bpf_map_lookup_elem`, `bpf_map_update_elem`, `bpf_map_delete_elem`;
- time/current-task helpers, if retained in scope;
- kfunc calls;
- tail-call dispatch;
- native-link helper-call or relocation events.

Unsupported instructions must fail before load or at generation/build time. A
runtime fallback, trap path, or synthetic repair is not an acceptable proof
mechanism.

## Main Proof Obligations

### O1. Decode Correctness

For each A64 word in the linked native proof object, the generator must decode
the same instruction and operands that the official A64 decoder would decode.
The generated `ARM64_SIM_RUN_OP*` macro arguments must be a faithful
serialization of that decoded instruction.

Required checks:

- instruction class;
- destination/source registers;
- immediate fields;
- width fields;
- shift/extend modifiers;
- condition codes;
- addressing mode, pre/post-index bits, pair-load/store layout;
- relocation target identity and addend.

### O2. Handler Semantics

Each `ARM64_OP_*` handler must refine the official A64 semantics for the
accepted operand subset.

Priority order:

1. Pure bitvector operations: `MOV`, `MOVK`, `ADD`, `SUB`, `AND`, `ORR`,
   `EOR`, `BIC`, shifts, `MUL`, `UMULL`, `UDIV`.
2. Flag operations: `CMP`, `TST`, `CCMP`, `NZCV`, and condition-code
   evaluation.
3. Selection and bit manipulation: `CSEL`, `CINC`, `CSET`, `EXTR`, `UBFX`,
   `SBFX`, `UBFIZ`, `BFXIL`, `BFI`, `REV`, `REV16`, `SXTH`.
4. Memory operations: `LOAD`, `STORE`, `LDP`, `STP`, including pre/post index
   behavior.
5. The current `D0/Q0` subset, if it remains accepted.

The first implementation can use SMT bitvector equivalence per handler and per
operand-shape. A later implementation can connect directly to Sail/Isla.

### O3. Control Flow

The proof must show that generated labels, branches, calls, returns, and
return-trampoline handling match the native blob's control flow.

No branch may be justified by proof-only facts. Conditional branches must depend
only on architectural flags or values computed by the native instruction stream.

### O4. Memory and ABI Equivalence

The simulator must not add memory safety checks that native ARM64 does not
execute. If a generated artifact would access outside the modeled memory shape,
generation, compilation, verification, or load should fail.

The entry ABI must be specified precisely:

- XDP initial register state;
- skb initial register state;
- ABI object layout and offsets;
- stack base/bias and modeled stack extent;
- return-value convention;
- skb scratch copy-out behavior.

Offsets such as skb `cb`, `data_end`, and `data` should be generated from the
same kernel BTF/offset source as native code, not copied as unexplained magic
constants.

### O5. External ABI Contracts

Helper, map, kfunc, and tail-call behavior should be modeled as event contracts.
The simulator proof only needs to show that native and eBPF proof code call the
same external operation with equivalent arguments and consume the return under
the same register/memory convention.

Current micro-only helper stubs that return fixed values, such as returning zero
for current UID/PID/CPU helpers, must be explicitly scoped as smoke-test
behavior. They are not production-faithful helper semantics.

### O6. Proof Object Integrity

The generated proof program must be tied to the exact native blob:

- hash or record the native proof object input;
- record the native-link mode, target arch, and relocation metadata;
- record the accepted instruction inventory;
- reject if a native instruction lacks a simulator handler;
- reject if a relocation has no modeled external event;
- reject if the generated proof code contains benchmark-specific shortcuts.

### O7. Verifier Representation Erasure

The current ARM64 simulator carries verifier-friendly tags such as scalar, ABI,
packet, packet end, stack, map pointer, map value, relocation address, and
rodata address. These tags are not architectural ARM64 state.

Before claiming formal equivalence, the implementation must satisfy one of two
paths:

1. Remove the tags and make the ARM64 simulator match the x86 simulator's
   architectural-state-only contract.
2. Prove an erasure invariant: removing all tags leaves the same architectural
   register bits, memory effects, control flow, external events, and return
   value. Tags may only choose a verifier-compatible C representation for a
   value that the native instruction stream has already computed; they must not
   introduce new safety facts, bounds facts, alias facts, or branch facts.

This is the highest-risk design point in the current ARM64 prototype.

## Recommended Architecture

Use a three-layer validation stack.

Layer 1: instruction semantics.

- Define the supported ARM64 subset in a declarative table.
- For each instruction form, map native decode fields to semantic parameters.
- Prove each handler equivalent to the reference semantics under that form's
  preconditions.

Layer 2: proof generation.

- Treat `native-link --mode proof` output as the native artifact.
- Decode the artifact.
- Generate proof macros from decoded instructions.
- Emit a machine-readable manifest with instruction inventory, relocations,
  helper events, stack requirements, and unsupported-feature checks.

Layer 3: integration contract.

- Define BPF runtime ABI state.
- Define helper/map/tail-call events.
- Prove that the generated eBPF proof program and native ARM64 blob produce the
  same trace of external events and final observable state.

## Tooling Options

Pragmatic first milestone:

- Use SMT bitvector checks for pure instruction handlers.
- Use generated random and exhaustive tests for small-width corner cases.
- Differential-test decoded native snippets against real ARM64 hardware or QEMU
  for bug finding.
- Generate an instruction coverage report from every proof object.

Stronger milestone:

- Use Sail AArch64 or Isla as the authoritative reference for instruction
  semantics.
- Generate SMT obligations or proof terms from the accepted instruction subset.
- Keep the handwritten C macro implementation, but continuously validate it
  against the reference.

Strongest milestone:

- Generate the simulator handlers from the reference semantics, or prove the C
  handlers in Coq/Lean against the extracted semantics.
- Prove the generator's decode-to-macro translation.
- Minimize the handwritten trusted code base.

## Phased Plan

### Phase 0: Freeze the Supported Subset

Generate an inventory of every ARM64 instruction form emitted by current micro
proof objects and ARM64 native-link proof mode.

Deliverables:

- `native-sim/arm64/simulator-spec.md`;
- generated instruction-form inventory;
- explicit unsupported-instruction list;
- top-level README correction if it still calls ARM64 only a placeholder.

### Phase 1: Remove Ambiguous Semantics

Audit the current tag system and helper stubs.

Deliverables:

- decision on tag removal vs tag-erasure proof;
- helper stubs split into smoke-only vs production-event-mode;
- generated stack-size and ABI-offset metadata;
- fail-fast checks for every unsupported relocation/helper/instruction.

### Phase 2: Prove Pure Scalar Handlers

Start with instructions that do not touch memory or external calls.

Deliverables:

- SMT checks for ALU, shifts, multiply/divide, `EXTR`, bitfield, `REV`, and
  conditional-select instructions;
- corner-case corpus for width truncation, zero register, sign extension,
  shift masks, division by zero, and flag setting.

### Phase 3: Prove Flags and Branches

Validate `NZCV`, `CCMP`, condition-code evaluation, and branch lowering.

Deliverables:

- equivalence checks against reference condition-code semantics;
- proof that generated branch labels preserve native control flow;
- rejection tests for unsupported branch shapes.

### Phase 4: Prove Memory and ABI

Validate load/store address calculation and memory effects.

Deliverables:

- exact memory-region model;
- stack offset bounds derived from the native artifact;
- load/store/LDP/STP proofs for accepted addressing forms;
- ABI entry/return proof for XDP and skb micro programs.

### Phase 5: Model External Events

Replace smoke-only helper assumptions with explicit event contracts.

Deliverables:

- event semantics for map lookup/update/delete;
- event semantics for time/current-task helpers used by accepted artifacts;
- tail-call/kfunc event model, or explicit out-of-scope rejection.

### Phase 6: Translation Validation in CI

Every generated proof object should emit a validation report.

Deliverables:

- native blob hash;
- instruction inventory;
- relocation inventory;
- accepted subset version;
- SMT/proof status;
- verifier/load status;
- differential-test status, clearly labeled as testing rather than proof.

## Paper-Grade Claim Boundary

Safe claim after Phases 0-4:

"For the accepted ARM64 micro proof artifacts and supported A64 instruction
subset, the verifier-facing eBPF simulator is translation-validated against the
native ARM64 proof object and its instruction handlers are checked against an
authoritative A64 semantics for the covered scalar/control-flow/memory forms."

Unsafe claim until Phase 5+:

"The ARM64 simulator verifies arbitrary native BPF applications" or "all helper
and map behavior is formally equivalent."

Unsafe claim unless the tag issue is resolved:

"The simulator is architectural-state-only." The current implementation has
proof representation tags, so it must either remove them or prove erasure.

## Immediate Action Items

1. Add `native-sim/arm64/simulator-spec.md` mirroring the x86 simulator spec,
   but adapted to AArch64 state, `NZCV`, fixed-width A64 instructions, and
   ARM64 entry ABI.
2. Generate a current instruction inventory from all ARM64 proof objects.
3. Decide whether the tag system is temporary verifier scaffolding to remove or
   a representation layer with a formal erasure invariant.
4. Separate smoke-test helper stubs from production helper event semantics.
5. Add fail-fast validation for unsupported instruction forms, relocations, and
   helper events.
6. Start SMT checks for pure scalar handlers before memory and helper events.

