# Full-word actual MOVK and the fetched native step

`Arm64MovKeep.Native.reference_word_step` reuses the existing mature checked
W/X MOVK proof at the low 16 bits of an arbitrary uint64 immediate. The proved
merge equivalence retains the full Clight argument while matching the native
halfword fields. Actual fetch, decode certificate, legal column and pre-error
admission remain explicit. PC advances by four with no new event or fault.

`Arm64ProgramEntryMovCall.keep_corresponds` binds the actual original fixture
Scall, all argument casts, scalar read, merge, writer, free and real successor
to that fetched LNSym step. Actual scalar word/tag loads and the complete
pre-register relation derive the native DST value. Unrestricted uint32
priority is widened for the actual call; truncation is used only for decoded
native fields and the proved merge equivalence. It retains 206 real internal
transitions, post-free scalar word/tag0, writable Storage, complete native-step
register relation at the original frontier and actual caller/free/release facts.

This closes the full-word ordinary MOVK correspondence for the reached source
segment. The preceding unrestricted MOV_IMM fetched instruction sequence,
physical ABI/provenance/provider validity, all outcomes
and final return remain separate M5 work. Actual wrapper/setup composition is
recorded in m5-entry-mov-prefix. Completed ISA-family count is zero.

Focused source check passes 229 jobs and two public type/axiom queries at the
original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. The initial finite failure was a Fin literal projection
normalization and redundant completed-goal tactics; it is retained in raw.
Whole `lake build KProgFormal` proof-library/root confirmation passes 280
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-native`. M5/M6 remain open.
