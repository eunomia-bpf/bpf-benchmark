# Immutable map tables: B generation and host semantics

Recorded 2026-11-15. Source: liveness refactor `c551f3566`, capability lowering
`01ad66426`, following proof/kernel relocation support `8d4c8b24c`.

The normal B generator now reads nested absolute map relocations as symbolic
capabilities. It recognizes the actual adjacent PC32 LEA and indexed 64-bit
load shape, binds every relocated slot to the real source capability, and
emits existing MOV_LOAD_MAP_PTR operations with the MAP or MAP_VALUE tag.
Literal slots remain exact scalar values. No unresolved pointer bytes become
constants, and fully consumed pointerful read-only objects are removed from B.

Fusion requires a private table base that is dead after the load and no control
flow entry into the load. It preserves the index and flags; unsupported partial,
escaping or segment-qualified accesses remain explicit failures. The existing
relative-code-table bit-level liveness analysis is shared rather than replaced.
No shared ISA/formal header or producer source was changed.

| Check | Result |
|---|---|
| Actual clang fixture through production proof writer/kernel rewrite | 8 symbolic map slots |
| Native image versus full shared simulator | 20/20 full-width pointer and tag cases |
| Capability modes | MAP handle and direct MAP_VALUE, eight indices plus two null defaults each |
| Dataflow counterexamples | Live private base, branch into load and partial pointer read all refused |
| Missing source map capability | Refused |
| Rust linker subset | 34 passed, 1 existing ignored |
| Relative-code-table regression after shared parser/ABI changes | 320 native + 320 shared-simulator cases, 8 targets, 2 private-state refusals |

The negative dataflow cases are explicit instruction-model mutations, not claims
of separately compiled native counterexamples. The native and simulator both use
the same full-width host map addresses. The host adapter observes RAX and its
tag before the simulator's integer entry return; MAP_VALUE uses offset zero.
The fixture returns a map pointer and is a component check, not a valid complete
BPF root or an application run.

Raw data: `/workspaces/kprog-raw/perf/20261115-map-table-b`.
The first two host attempts failed on a test integration function name and a
missing generated semicolon; their complete commands, errors and exit codes
are retained beside the final passing run. `collect.py` copies bounded receipts
and hashes the one canonical fixture build. Host shared-library flags in
`final/commands.json` apply to the host model adapter, not the native P producer.

Only the Cargo unit-test executable was rebuilt for the new proof writer. The
normal production linker/base was not published. The relative-code regression
uses the explicitly retained CLI artifact with SHA256
`31806730e4d268e89b51806d2e0207812dc5e1b869e974d6f3304e5f90169955`
to build its older code-table fixture, then exercises the current Python B
generator. It does not demonstrate new map-relocation support in that binary.

Still open: a valid root consuming the selected map with a helper, its normal B
compilation, stock acceptance and checked-native installation; application
tables; nonzero value addends, absolute code and local-data pointer tables;
formal obligations. No throughput, per-call speed or native code-size gain is
claimed. Existing queued publication/kernel jobs and running census/scale jobs
were preserved.
