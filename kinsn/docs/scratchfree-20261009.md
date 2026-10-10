# Scratch-free prototype proof sequences (2026-10-09 task)

All 96 non-debug operations have proofs with only declared register outputs and
explicit memory accesses. There are no incidental stack writes, save/restore
borrows, or leftover BPF temporaries. **69 operations match June native bytes
on every commonly native-accepted sampled allocation; 21 retain differences;
six operations were absent in June.**

The per-operation [CSV](scratchfree-20261009-operations.csv) contains all 96
operations, June and pre-task October proof-length ranges, current ranges and
capacity bounds, byte lengths, allocation counts, and each exception's reason.
Exact per-allocation proof lengths and native hex are retained in the external
`allocations.csv` and `rows-final.json`.

## Declared memory arithmetic outputs

For x86 memory ADD/SUB/AND/OR/XOR32/64, XORW direct-memory and XORB indexed-memory,
the data output is the lowest BPF register R0 through R9 excluding destination,
base, and the active index. Its final value is the zero-extended operand read.
Destination and data register are the only outputs; memory is unchanged and
there is exactly one ordered operand read. Both proof and native implement this
contract. Indexed address formation uses only that declared output.

These forms require an operand register to compute the operation without
borrowing program state. They therefore retain a native difference from June:
a load into the data output followed by register arithmetic replaces the single
memory-source arithmetic instruction. Current LLVM and bytecode recognizers
have no emission sites for these memory arithmetic forms; future users must
account for both outputs. Register/immediate forms retain destination-only
semantics. Direct proof length decreases from 5 to 3; indexed proof length
from 5 + 2^scale to 3 + 2^scale.

## Byte arithmetic and division

Scalar byte ADD/SUB/XOR write only destination, including source=destination.
A source-byte decision tree completes before destination writes. ADD/SUB leaves
use three instructions per set source bit: add/subtract its power of two and
correct byte carry/borrow in destination. Their proof lengths are 3583 for
register source, 3*popcount(imm8) for nonzero immediate, and 1 for zero. XOR
lengths are 766 and 1. All three scalar native emitters regain June bytes.

DIVL declares a divisor output: the lowest R0..R9 excluding R0, R3 and source,
left holding zero-extended source32. R0 and R3 are quotient/remainder outputs.
The ten-instruction proof replaces fifteen instructions with spills. Native
code captures the divisor before either implicit input, assembles EDX:EAX,
clears the hardware high half, tests divisor for zero, uses DIV64 only on the
nonzero path, and truncates both outputs to 32 bits. This retains a necessary
June difference: unguarded DIV32 can fault on zero or quotient overflow.

Lean byte identities use bit-lane lemmas, arithmetic modulo proofs, and a
kernel-checked exhaustive eight-bit operand identity. No compiler-trust axiom
is admitted; the unchanged project audit enforces this.

## High-byte stores and population count

High-byte stores dispatch on original source bits 15:8 and execute one immediate
byte store. The 766-instruction proof has no register output. Native uses June's
AH/CH/DH/BH store when encodable; otherwise it copies source into the JIT's
unmapped R11, shifts R11, and stores its low byte. All mapped registers remain
unchanged. Twenty sampled extended-register allocations are newly accepted;
all commonly accepted sampled MOVB allocations match June bytes.

POPCNT copies source into destination, counts the low seven bits with a decision
tree, then processes bits 7 through 63 using conditional one-bit rotations.
The running count remains in destination bits 6:0. It writes no other register
or memory. Proof length increases from October's 196 to 28,954; native returns
to the single June POPCNT. The proof's branches are all forward and fit signed
16-bit offsets, and its descriptor capacity fits the kernel's unsigned 16-bit
field.

The complete Lean build passes 939 jobs with the standard worker configuration.
The unchanged axiom audit checks 3,519 declarations and reports zero non-standard
axioms; only `propext`, `Quot.sound`, and `Classical.choice` are used. Certificates
observe every mapped register, every memory byte, and ordered accesses. Both
architecture modules build with `KCFLAGS=-Werror`, the host unit suite passes,
and `make lint` passes. No VM or benchmark was run for this task.


## Comparison provenance and limits

The baseline is the actual paper snapshot `e9956b814b38` (June 4 sources under
`module/`), extracted read-only. Current sources are under `kinsn/module/`.
The supplied October comparison harness originally used `69f9a30f6` as baseline;
that is not June. Its generator and operand allocation sampler were reused,
but the baseline sources were replaced with the June archive. Stale libraries
for operations absent from June were removed. The six absent operations are
SHLXL, SHLXQ, SHRXL, SHRXQ, BZHIL and BZHIQ. They are not counted as identical.

The comparison tests 6,838 allocations across 96 operations: 4,918 native
allocations accepted by both revisions (4,092 identical and 826 different),
20 newly accepted MOVB high-store allocations, 1,822 allocations rejected by
both, and 78 allocations of the six June-absent operations. No sampled June
native allocation is newly rejected. Eight emitted LEA allocations have an
existing proof rejection for dst=index; this predates this task and remains an
error. Byte identity for those emissions is recorded, without treating them
as accepted operation proofs. All 5,008 accepted proof allocations were checked
for register writes, incidental stores, descriptor bounds, and branch targets.

Native byte identity is stated for the supplied sampled allocations, not every
possible machine allocation. Proof-length ranges in the CSV use those same
samples. `descriptor_capacity` is an allocation upper bound and can exceed the
actual length. The formulas below cover the changed families beyond the
sampler's immediate values. No timing, MCA result, VM, or benchmark result is
claimed.

## Remaining native differences

| Operation(s) | Why June cannot implement the declared semantics |
|---|---|
| ADDQ/ADDL, SUBQ/SUBL, ANDQ/ANDL, ORQ/ORL, XORQ/XORL, XORW and XORB (12 operations) | Memory form declares zero-extended loaded operand as data output; native load plus register ALU replaces June memory ALU. Scalar forms identical when supported. |
| DIVL | Declared low32 divisor output; zero-divisor guard and wide division avoid #DE; quotient/remainder truncate to32. |
| ROLW | END16 requires zero extension; June ROL16 preserves upper48 bits; keep MOVZX correction. |
| MOVBE16 | Load16 must zero extend; June MOVBE16 preserves upper48 bits; keep MOVZX correction. |
| CMP_CMOVE, CMP_CMOVNE, CMP_CMOVB (3 operations) | False conditional MOV32 preserves destination64; June CMOV32 clears upper32 even on false; keep MOV R11D,src32 plus CMOV64. Value64 remains identical. |
| ARM64 REV16_W | END16 keeps only swapped low16; June REV16_W also swaps bits31:16; keep UXTH. |
| ARM64 CSEL_NE | Named condition register is the predicate; incoming NZCV is arbitrary; keep local TST before CSEL. |
| ARM64 CSET_X_COND | Named register zero predicates must be computed locally; keep CMP/CCMP chain before CSET. |

The 12 memory-ALU operations retain identical scalar bytes where those forms
exist; the operation-wide classification is “different” because of memory
forms. CMOV64 variants likewise remain identical.

DIVL emits 34 bytes for sampled ordinary low-register sources and 35 for
extended sources. For source R1 and declared divisor output R2, the complete
34-byte stream is:

```text
89fe 89d2 48c1e220 89c0 4809d0 31d2 4885f6 7405 48f7f6 eb05 4889c2 31c0 89c0 89d2
```

The guarded arithmetic block is `31d2 4885f6 7405 48f7f6 eb05 4889c2 31c0`:
clear RDX, test divisor, jump over DIV64 on zero, and supply the zero-divisor
quotient/remainder. DIV64 with high half zero cannot overflow; final MOV32
instructions truncate both outputs. Every form/source stream is in external
`division-bytes.json`. June's unguarded DIV32 is 2–3 bytes and can fault.

## Selector and recognizer audit

* `llvm-backend/llvm/llvm/lib/Target/BPF/BPFKinsnSelect.cpp:142,306` selects
  ROLW for standalone 16-bit endian operations without a high-bit-zero bound.
  Those operations require zero extension. Its `collectMovbeBE` at line 510
  matches byte-load ladders and low16 masks; MOVBE16 must also clear the high
  destination bits. Keeping MOVZX in both emitters preserves those patterns.
* `bpfopt/llvm/src/bpf_kinsn_bytecode.hpp:1773,1786,2133,2173` maps endian
  operations and byte-load fusions to MOVBE and REV. ARM64 standalone END16
  can see nonzero upper bits, so single REV16_W is insufficient. The corrected
  REV16+UXTH is retained. Load16+swap sites can have known zero high bits, but
  the shared standalone operation must implement the complete contract.
* LLVM `BPFISelLowering.cpp:1094,1163` and `BPFInstrInfo.td:938` select
  compare/conditional-move forms and tie dst to old. `BPFAsmPrinter.cpp:620`
  encodes comparison and value widths. There is no explicit full-64-bit bound
  requiring old dst's high32 to be zero in the operation's accepted payload.
  Its conditional BPF MOV32 leaves dst unchanged on false. The retained
  R11D+CMOV64 sequence implements that contract; changing false to clear high32
  would change the original conditional-move expansion for arbitrary inputs.
* Bytecode conditional selection at `bpf_kinsn_bytecode.hpp:2224` matches
  zero comparisons and MOV64 diamonds; conditional-set matching at line 2301
  checks a same-width/same-mode chain of two through four zero predicates.
  Both insert separate flag-preparation operations. CSEL/CSET still need local
  preparation to satisfy their named-register proof contracts independently
  of incoming NZCV; the proofs need no hidden flags-state admission check.
* BEXTR's June emitter reads both original source and control before writing
  destination. Its current proof dispatches start/length before any destination
  write, including operand aliases, so the June bytes already match. LLVM
  `BPFKinsnSelect.cpp:668` requires a positive contiguous mask, a single-use
  right-shift result, and start+length≤64. Bytecode extraction at
  `bpf_kinsn_bytecode.hpp:1268` checks the same bounds and chooses a dead
  control register for its explicit MOV outside the operation.
* ARM rotate and SHLD/SHRD recognition require removed original temporaries
  to be dead (bytecode), or virtual intermediates to have a single use
  (LLVM). Complementary shifts/counts define the same result as the restored
  June instruction. The new operation proofs themselves borrow no temporary.
* No LLVM or bytecode recognizer emits the memory-ALU forms or DIVL. Their new
  declared data/divisor outputs therefore require no existing selector change.
  Future callers must account for those outputs.

## Proof lengths and verifier work

Twenty-five operations change at least one sampled proof length in this run.
Seventy-one have unchanged lengths. “October” below is the saved pre-task
current module in the supplied October harness. June and October lengths for
every operation and every sampled allocation are retained separately.

| Changed family | Pre-task October length | New exact length / maximum |
|---|---:|---|
| ARM EXTR_W / EXTR_X | 1–5 | 1+5*n; max156 /316 |
| SHLDL/SHLDQ/SHRDL/SHRDQ | 6 | distinct5+5*r; self1+5*r; max160 /320 |
| SHLB / SHRB | 8–194 in samples | immediate0 or≥8:1; immediate1..7:1022; CL:7241 |
| Scalar ADDB / SUBB | 7 | immediate nonzero3*popcount:≤24, zero1; RR3583 |
| Scalar XORB | 7 | immediate1; RR766 |
| High-byte MOVB store | 5 | 766; ordinary store stays1 |
| POPCNTQ | 196 | 28954 |
| Memory ALU (12 ops) | direct5; indexed5+2^scale | direct3; indexed3+2^scale |
| DIVL | 15 | 10 |

Here `n` is the decoded left-rotate count, `r=imm` for SHLD and `r=width-imm`
for SHRD. June lengths often included additional architectural shadow/spill
operations; the per-operation CSV reports those separately.

The largest proof in the entire catalogue is now POPCNTQ's 28,954 instructions;
BEXTR's existing 25,214 is next. These fit the unsigned16 descriptor count.
All sampled branches are forward, in bounds, and fit signed16 offsets; the
largest sampled offset is24,831. `validate_kinsn_proof_seq` in
`vendor/linux-framework/kernel/bpf/verifier.c:3669` bounds count by descriptor
capacity and forbids calls/exits and pseudo loads. No kernel check was added.
The general verifier processed-instruction budget is1,000,000; static proof
length is below that budget, but path exploration and multiple expansions
also consume it. Actual VM verifier acceptance and load time were not measured,
as requested. The larger decision trees and repeated rotations can increase
load time; restored native bytes concern runtime code only.

## Verification evidence

* `lake build`: 939 jobs, all successful. The audit implementation is unchanged;
  3,519 declarations checked, zero non-standard axioms, no `sorry`.
  Coverage-table names match the complete 96-operation module catalogue.
* Both module builds pass with `KCFLAGS=-Werror` through the existing configured
  x86 and cross-compiled arm64 kernel build trees. No kernel build or VM run was
  needed. The host suite `make -C tests/unittest run` and `make lint` pass.
* Actual C proof/native checks: 2,363,904 exhaustive byte-arithmetic cases;
  822,272 byte-shift cases; 13,200 memory-ALU cases; 2,112 division-proof cases
  plus 2,112 host-native division executions; 14,336 high-byte store proof/native
  pairs; 1,560 population-count proof cases; 5,120 host-native CL-rotate executions
  including zero counts and dst=CL. Register aliases, high-bit lanes,
  former spill offsets, division zero/overflow, and write bounds are included.
* All 5,008 accepted sampled proofs pass the catalogue-wide output/store/branch
  scan. Comparison preserves each sampled native byte stream and proof length.

External evidence directory:
`/workspaces/.agent-state/bpf-benchmark-supervisor/scratchfree-20261009/`.
`compare_bytes.py` regenerates native comparison and old/new lengths;
`check_all_outputs.py` scans actual instantiated C proofs; `check_*.py` contain
the host semantic checks. `harness.py` is the adapted supplied generator.
`lean-final.log`, `build-x86-final.log`, `build-arm64-final.log`, `unit-final.log`
and `lint-final.log` retain successful check output. The baseline and current
shared libraries are retained under `harness/`; no digest is used as evidence.

## Pushed implementation steps

1. `cf39e96a7`: destination-only ARM rotation proofs; restore June EXTR.
2. `d721c529a`: destination-only double-shift proofs; restore June SHLD/SHRD.
3. `9cbcf8f62`: destination-only byte shifts; restore June SHL/SHR.
4. `7c94a6058`: declare memory-ALU data outputs; eliminate their spills.
5. `1d1728d76`: scratch-free byte arithmetic, DIVL, high-byte stores and POPCNT;
   full-state Lean proofs and coverage updates.

Each finished implementation step was committed and pushed on master, with an
origin/master fetch and merge before push. Other agents' work was left intact.
This report and its per-operation CSV are committed as the final documentation
step; its commit identifier is reported in the task reply.
