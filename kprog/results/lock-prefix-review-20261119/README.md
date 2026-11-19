# Locked x86 memory operations: phase-1 source trace

The coordinator's 2eb36bad9 receipt identifies a lost `lock incq` prefix in
the checked configuration. Source tracing confirms where it disappears:

- `kprog/x86/micro-prog/generate_micro_sim_proofs.py:182` removes `lock `
  before creating `NativeInsn`; its `raw` text is also the stripped string.
  `NativeInsn` at line 94 has no retained lock field.
- `encode()` at line 820 maps a memory `inc` to `X86_OP_ALU_MEM_UNARY`,
  carrying only width, memory-address auxiliary bits and the ALU operation.
  `append_step()` at line 1431 consumes that encoding for shared simulator C.
- `kprog/x86/x86_sim_local_bpf.h:2052` implements that unary memory arm as
  a read, arithmetic/flag calculation and a separate write. The original
  locked operation cannot be reconstructed from the lost encoding.

B and checked native are compiled from this same C, so correcting only the
native LLVM lowering would leave the verifier's representation inconsistent.
The class needs prefix preservation, a shared atomic RMW operation, and
retained width/flags/fault behavior. Audit the memory exchange forms too.
No new refusal, program exclusion, runtime check or mode switch is a fix.

Next: after the active batch, reproduce with real locked/plain assembly,
trace emitted B and native instructions, then implement the class in the
generator and shared operation with FORMAL. The shared interpreter header
is frozen; this source review changes neither it nor the active cohort.
The current results remain recorded with this correctness limitation;
this finding adds no benchmark admission gate or automatic rerun.
