# Original MOV_IMM and MOVK source composition

`Arm64ProgramEntryMovPair.execute` composes the existing original fixture
segments on the same reached heap. MOVK consumes the first call's actual
Storage, scalar word/tag0 and priority temporary. The single origin-provider
trace is retained; setup and the provider are not replayed.

The owned-storage observer equivalence lifts the first call's complete
register relation to the reached allocation frontier. The actual first free's
nextblock equation and allocation monotonicity derive the second call's
canonical bound. After MOVK, the same equivalence returns the complete nested
register update to the original caller frontier. Both context/caller frames
compose. Final scalar word/tag0, writable Storage, both real frees, their raw
contents/frontiers and released permissions are retained. The first release
is witnessed at the middle heap, the second at the final heap.

Mark and priority are unrestricted uint32 inputs, widened to the actual
uint64 call parameters. The theorem starts at original afterSetup and reaches
the original afterKeep successor. The actual wrapper/setup prefix is recorded in m5-entry-mov-prefix. Fetched
native instruction-sequence and physical ABI/provenance admission, all outcomes
and final return remain M5 work. No ISA family is completed.

Focused source check passes 229 jobs and one public type/axiom query at the
original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. Whole `lake build KProgFormal` proof-library/root confirmation passes 280
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-pair`. M5/M6 remain open.
