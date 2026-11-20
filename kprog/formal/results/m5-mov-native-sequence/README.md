# Fetched MOVZ/MOVN followed by MOVK

The live production generator's normalize_alias and encode preserve one
native instruction per simulator call. MOVZ/MOVN becomes a full shifted,
optionally complemented and width-masked MOV_IMM operand; MOVK is a separate
call. A hypothetical two-native-word literal fused into one source call is
not the production mapping and is not used here.

`Arm64MovPairNative.steps` reuses the mature fetched/decoded wide-move and
MOVK proofs for exactly those two admitted words. The original full source
mark binds to Wide.literal from the actual decoded first fields. No numeric
bound on mark or priority is added. This operand equality is an explicit
instruction/source admission, not a claim that every arbitrary uint32 mark
has a matching single MOVZ/MOVN encoding. Other MOV encodings remain work.

The second fetch and no-error condition are derived from the original
program and the actual first poststate. The first and second complete
reference transitions retain PC+4/PC+8, memory/program/history and all
non-written state, with an empty event/fault delta for each word. Cursor and
register update identities use the imported machine's distinct fields;
there is no local ISA body, decoder, program or code-generation change.

Focused native check passes 232 jobs and three public type/axiom queries at
original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. The initial finite proof normalization failures are
retained in raw. Whole `lake build KProgFormal` proof-library/root confirmation passes 283
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-mov-native-sequence`.
M5/M6 remain open; completed ISA-family count is zero.
