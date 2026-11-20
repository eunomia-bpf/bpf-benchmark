# Actual-world warm SP reader and all executions

The existing warm STACK tail now takes a linked world and its four required
layout facts. The previous standalone APIs instantiate that same source proof.
sp_read_warm_bound composes the real 35-transition SP prefix and 36-transition
warm materializer, with actual loads, imported wrapped addition and unchanged
memory. It invokes no origin provider on the warm path.

Arm64ProgramEntryWarmRead.read applies the actual linked layout and the complete
register representation to return native SP in 71 internal transitions through
the actual callCont. No new source post-state or native-value premise is added.
The preceding entry/MOV contracts now derive this warm cache and register view.

all_behaviors proves every relational execution is a silent prefix of that
same-memory return, every stuck endpoint is that return, and no infinite run
exists. Candidate traces are arbitrary; silence and external determinism are
not assumptions. These are helper contracts, not completed ADD_IMM or ISA-family
refinement. Physical ABI/provider/other-handler/all-program obligations remain.
The next ADD_IMM path selects the tagged pointer writer, not scalar tag0.

Focused actual-world check passes 220 jobs and four public type/axiom queries at
original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. The initial finite failures were adjacent documentation
comments and explicit64-bit literal normalization. Dependency rebuilds and all
failed logs are retained. Whole proof-library confirmation follows this batch.
Raw: `/workspaces/kprog-raw/formal/m5-warm-sp-reader`.
M5/M6 remain open; completed ISA-family count is zero.
