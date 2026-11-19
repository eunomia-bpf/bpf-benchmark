# Shared atomic RMW implementation boundary

PERF 2026-11-19T09:15:57Z. Source assessment before changing the active cohort.

The affected accepted forms extend beyond INC: generator lines 877–889 map
memory destination/register and memory destination/immediate ALU operations
to `ALU_MEM_REG` and `ALU_MEM_IMM`. Shared I lines 2080 and 2125 also perform
separate reads and writes. Memory XCHG is currently refused by the existing
encoder at line 983; it does not silently enter the register-only XCHG arm.
XADD and CMPXCHG have liveness handling but no encoder arm. Their existing
generation failures are separate from the lost-prefix bug.

A retained LOCK bit must reach all three memory ALU bodies. The generic
width contract consumes the entire width byte, so adding an unmasked bit
to the existing width field would itself break width semantics. Plain
instructions retain their current path. The locked path needs one atomic
operation returning the actual old value, with flags computed from that
value and the successful result. ADC/SBB must capture incoming carry once;
INC/DEC preserve incoming carry. A retry must not publish speculative flags.

Address handling remains shared: the effective address includes the index,
scale and displacement; RSP is a private-arena offset, not a usable pointer.
The existing recovery branch at I:1444 precedes memory access. Stack writes
at I:765 and tagged stores at I:949 erase private pointer metadata and model
released bytes; calling either after an atomic write would perform a second,
non-atomic store and can overwrite another thread's update. Their metadata
effects need separating from the actual memory update. A LOCK operation on
private storage also carries ordering and cannot simply lose its prefix.

`atomic.c` and the local `probe-atomics` Make entry assess Clang's actual
native and BPF lowering for fetch-old ADD and compare-exchange at all four
operand widths. This is a compiler feasibility test, not shared-I semantics,
stock acceptance, concurrency coverage or a runtime result. It introduces
no source-path refusal or fallback. A narrow BPF compiler failure must stay
visible rather than being replaced with a plain read/write.

FORMAL already has an atomic platform boundary in
`kprog/formal/c/Platform.h:88` and the Arm64 shared C uses it at
`arm64_sim_local_bpf.h:1815`. That boundary's old/new, ordering and fault
relations remain explicit proof obligations (formal README, Arm64 atomic
section); its presence alone supplies no x86 correctness proof. Shared-I
changes need a specific freeze defect-class entry and corresponding x86
formal binding. No shared interpreter, compiler or generator input changed
in this assessment.
