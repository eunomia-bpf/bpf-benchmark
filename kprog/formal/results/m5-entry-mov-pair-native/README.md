# Both original source calls and the two fetched native steps

`Arm64ProgramEntryMovPairNative.corresponds` consumes the existing same-heap
source call-pair result and the mature fetched MOVZ/MOVN/MOVK sequence proof.
It derives the full register relation at the original caller frontier to the
actual second reference step's state. Both reference event/fault deltas are
empty, with the sequence proof retaining PC+8 and the complete native frame.

The real source Star, ordered origin-provider trace, final scalar word/tag0,
writable Storage, caller frame and both actual frees/contents/frontiers and
released permissions remain outputs. No post-memory, final register relation,
successful store/free or second-state fetch/error condition is assumed.

First decoded fields bind the full normalized MOV_IMM source operand through
Wide.literal. This is required instruction/source admission, not an added
numeric mark bound or a claim of a matching single encoding for every uint32.
The source mark and priority remain unrestricted; physical ABI/provenance,
provider trace/production validity, later control and full outcome/final-return
correspondence remain M5 obligations. Completed ISA-family count is zero.

Focused source/native check passes 234 jobs and one public type/axiom query
at original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. Whole `lake build KProgFormal` proof-library/root confirmation passes 283
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-pair-native`. M5/M6 remain open.
