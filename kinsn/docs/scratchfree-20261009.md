# Scratch-free prototype proof sequences (2026-10-09 task)

This report is being completed alongside the implementation. Final native-byte
and per-operation proof-length results will be added after all families pass.

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
