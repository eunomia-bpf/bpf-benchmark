# Immutable map-pointer table: proof and kernel linker support

2026-11-15, source 8d4c8b24c. The historical OTel table-enabled object contains
an anonymous `.data.rel.ro` section with sixteen `R_X86_64_64` entries naming
the eight-through-23 stack-delta maps. Every addend is zero. This is static
evidence of a compiler output shape; the old producer route is not rebuilt,
deployed or used for an application performance claim.

The linker previously sent the section-symbol reference through its mutable
DATASEC path and failed because the compiler table has no source variable
symbol. It now treats standard RELRO tables as immutable after relocation,
preserves live map identities as nested proof relocations, and emits ordinary
full-width map-patch slots when binding the kernel image. Actual map lifetimes
and addresses still come from the loader's existing capability mechanism.
Mutable application data keeps its live DATASEC behavior.

The regression fixture is actual clang output built with the unified native
flag shape, with eight distinct map addresses and an out-of-range null case.
It traverses the real production rewrite and proof-object writer, then rewrites
the proof with the complete normal boot fact bundle. Eight source relocations
become eight symbolic proof relocations and eight kernel map patches. Ten host
executions preserve exact pointer identity, including pointer bits above 32.
Missing capabilities and an interior map-handle addend fail explicitly; no
pointer bytes or relocation addends are silently discarded. Nonzero data-value
addends and absolute code/local-data pointer tables remain separate work.

Final Rust result: 34 passed, zero failed, one existing ignored. The earlier
test build failed on an inferred empty-map type and is retained; the corrected
and final runs passed. All log/command receipts are included. Canonical fixture
products remain under `/var/tmp/kprog-tmp/perf/map-pointer-tables`; full raw
logs remain `/workspaces/kprog-raw/perf/20261115-map-pointer-tables`.

This step establishes proof/kernel linker support only. B's readonly parser
still rejects nested absolute map-pointer relocations, so generator lowering
that preserves capability tags is next. It must not read unresolved pointer
slots as raw zero bytes. No B acceptance, checked-native installation, app
equal-work, throughput/per-call gain or app code-size target is claimed here.

Only the Cargo unit-test executable was rebuilt. The runtime linker alias,
existing normal CLI artifact, installed base and image are unchanged while the
census holds image SH. Pending paired publication will build the current
source under image EX. No running job was stopped, no raw data deleted and no
second checkout/source copy was made. `collect.py` binds actual ELF evidence
and bounded receipts without copying historical compiled objects.
