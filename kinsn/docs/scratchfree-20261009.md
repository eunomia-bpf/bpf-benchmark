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
