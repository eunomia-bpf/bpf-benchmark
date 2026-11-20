# Actual MOV_IMM call with cold SP and frame release

`Arm64MovImmediate.LinkedCall.entry_call` composes the actual nine-argument
handler with destination 1, SRC32, NONE secondary sources, FLAGS8, AUX0 and
an unrestricted widened uint32 mark. It uses the sole fixture/handler/Numeric
world. The actual allocated frame, width 97, selector 98, reader 66, origin
input 59 and writer 107 are retained.

The proof transports the full register relation to the allocated frontier,
derives header loads and cold cache validity there, and reuses the framed
cold-reader/write suffix. Its provider trace and supplied memory stay in
the execution. Both cache stores and both GPR stores are derived through
the existing writable resources. The admitted STACK origin reply and its
frame remain explicit invocation inputs; availability and production validity
of that contract are separate obligations.

All generic locals' Freeable ranges follow from actual allocation and retained
permissions. The proof derives the actual free-list execution and complete
permission release. The register relation returns to the ORIGINAL caller
frontier before transport across that free, and the same producer Storage
survives. Final allocation frontier and raw written contents are retained;
the original producer caller's bytes and Cur/Max permissions are preserved.
The register effect is the existing ordinary `nativeUpdate`. The call returns
through any valid caller continuation, using the universal trace-preserving
Clight continuation law, with the same memory and trace.

The actual fixture callsite/mark load/successor and fetched native instruction
sequence remain M5 work. This theorem neither restricts mark to 16 bits nor
establishes a native MOVZ correspondence for arbitrary mark. Unrestricted
MOVK priority, physical-memory/ABI admission, all-outcome/final-return proofs
and other ISA families also remain.

Focused 226 jobs and the public type/axiom query pass at original caps,
CPU 17, nice 0, one worker and 32 GiB address space. The whole
`lake build KProgFormal` proof library/root passes 275 jobs, confirming both
steps on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Executable/tool builds are excluded under the current directive.
One initial proof failure required unfolding a local memory alias in a
permission equality; its raw log is retained and limits are unchanged.
Validation lists inherited logic/external-semantics axioms. Raw:
`/workspaces/kprog-raw/formal/m5-mov-first-call`. M5/M6 remain open;
completed ISA-family count is zero.
