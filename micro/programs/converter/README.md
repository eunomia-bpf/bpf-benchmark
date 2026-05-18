# Native ASM to Handcraft Converter Experiment

Status: archived experiment, 2026-05-18.

This directory keeps the native-asm-to-handcraft experiment artifacts out of the
normal `micro/programs` build surface. The converter path is not the current
production direction for kinsn work.

Contents:

- `*.md`: generated per-benchmark code-comparison reports used as converter
  input. The `## Native ASM` section was the source of truth.
- `*.handcraft.c`: generated handcraft BPF programs containing raw BPF plus
  machine-level kinsn calls.
- `native_asm_to_handcraft.py`: earlier strict converter prototype.
- `native_asm_to_handcraft_bpf_cf.py`: later converter variant that kept
  program-level control flow as ordinary BPF.

## Goal

The experiment tested whether native x86 generated from the micro C programs
could be mechanically translated into handcraft BPF:

- non-control-flow x86 instructions become machine-level kinsns;
- final x86 emission is one named x86 instruction per kinsn;
- verifier-facing `instantiate_insn()` proves enough BPF semantics for load;
- program-level control flow remains verifier-visible ordinary BPF branch,
  call, and exit instructions.

The broader question was whether this could replace or bypass bpfopt by running
"native-like" code through kinsns.

## Result

The experiment is useful as a native-parity probe, but not as the production
execution model.

Documented passing handcraft cases: 6 / 29.

Passing cases:

- `simple`
- `simple_packet`
- `bitmap_popcount_scan`
- `trace_event_type_switch_dispatch`
- `packet_checksum_fold`
- `siphash_rotate64_mixer`

Latest focused failing case:

```sh
SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 \
  BENCH="bcc_runqlat_log2_histogram_bucket" make micro
```

Result:

- `native`: 1600 ns
- `kernel`: 1420 ns
- `kernel_handcraft`: verifier rejected load
- failure: `processed 1000001 insns`
- result path:
  `micro/results/x86_kvm_micro_20260518_035204_272971`

Removing shadow-flag lowering for branch-only `cmp/test` and visible
`cmp; cmovb` reduced verifier pressure from `max_states_per_insn=37` to `8`,
but the case still exceeded the verifier processed-insn limit around a
variable-shift/scalar proof (`r6 <<= r7`).

## Lessons

### kinsn Is Not an x86 VM

The main conclusion is that kinsn should not be treated as a complete x86
execution model. It works best as a local machine-level extension for BPF IR:
small, basic-block-local instruction forms that the normal BPF JIT does not
recover from ordinary BPF bytecode.

Good kinsn targets:

- `lea`
- rotate
- indexed load
- endian indexed load
- direct machine ALU forms
- `popcnt` / BMI bitmap forms
- narrow local `cmov` / `setcc` only when the producer and consumer can be
  proven locally without global flag state

Bad kinsn targets for the current ABI:

- whole-function native x86 execution
- program-level `jcc` / `jmp`
- global shadow flags across blocks or loops
- native PC simulation
- general x86 stack/ABI emulation

### Converter Became Too Much Like a Compiler

`native_asm_to_handcraft_bpf_cf.py` stopped being a mechanical translator. It
had to parse and lower:

- `cmp/test -> jcc`
- `cmp/test -> cmov`
- branch operand snapshots
- BPF-readable operand materialization
- scratch register choices
- width normalization

That was useful for diagnosis, but it violates the intended boundary. A clean
converter should only do selector choice, x86 operand payload fill, and ordinary
BPF branch relocation.

### Raw BPF Control Flow Was Necessary

Branch kinsns and proof-offset payloads were the wrong direction for this
experiment. Userspace would have to provide verifier-facing branch offsets that
are not x86 operands. That creates an unsafe and hard-to-maintain boundary.

The safer boundary is:

- `jcc`, `jmp`, local `call`, and `ret` are ordinary BPF control-flow
  instructions;
- userspace only patches ordinary BPF branch `off` fields;
- kinsn payloads never carry verifier proof offsets, target PCs, abstract
  states, liveness, or scratch choices.

This gives up final `cmp/test; jcc` parity, but keeps the verifier CFG visible.

### Shadow Flags Do Not Scale

Shadow flags are dangerous as a default proof mechanism. The bcc log2 bucket
case showed that `cmp; cmovb` with stack-shadow `GE/ZF/CF` can explode verifier
state in a tight loop. Converting visible `cmov` to ordinary BPF conditional
move fixed that specific pressure, but it also lost final x86 `cmp; cmov`
parity.

Any future flag-producing kinsn should be limited to local, tightly bounded
patterns or redesigned so it does not create loop-carried precise stack state.

### Pointer Proof and Scalar Proof Need Different Precision

Verifier-critical pointer facts must remain visible as ordinary BPF comparisons
or verifier-native pointer arithmetic. The verifier cannot recover packet bounds
from a scalar flag slot like:

```c
flag = data <= data_end;
if (!flag)
    abort;
```

Pure scalar values do not always need exact verifier proof. The bcc variable
shift failure suggests that exact scalar simulation in loops can overwhelm the
verifier even when memory safety is not at stake. A future kinsn proof model
should distinguish:

- safety-critical pointer/range/provenance facts, which need precise verifier
  visibility;
- pure scalar hot-path values, which may only need conservative scalar
  abstraction for verifier safety.

### Native-Only Registers Are a Boundary Problem

Raw BPF branches can only branch over BPF-visible registers or values loaded
from verifier-visible memory. Native-only x86 registers (`r9`, `r10`, `r11`,
`r12`, `rsp`) live in module-owned shadow state for proof, but the final native
execution does not execute the proof stores. Any branch over those values needs
careful materialization into BPF-readable state. This is another reason the
converter grew beyond simple translation.

## Current Recommendation

Do not continue this converter as a production path.

Use it as an archived oracle for:

- seeing which native x86 instruction forms matter;
- checking what final JIT parity might buy;
- understanding verifier failure modes for candidate kinsns.

The active kinsn direction should be:

- bpfopt or LLVM backend emits kinsns only for basic-block-local patterns;
- no branch kinsns in the default model;
- no whole-function x86 emulation;
- no global shadow flags as a default proof mechanism;
- verifier-facing proofs stay small and local.

For source-available programs, LLVM backend integration may be cleaner than
bpfopt because LLVM already owns instruction selection, liveness, and
basic-block structure. For live ReJIT and existing bytecode, bpfopt is still the
right bytecode-only path.
