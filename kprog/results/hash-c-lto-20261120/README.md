# Plain HASH native C lookup

The C body follows the sole kernel's plain HASH helper: Jenkins hash with the
actual map seed, the selected bucket's RCU nulls chain, stored-hash and full-key
comparison, retry on a different bucket's nulls marker, and an eight-byte-rounded
key offset to the value. B retains helper 1. LRU, per-CPU and map-of-maps behavior
is outside this body and keeps its existing calls.

The installed compiler's existing lookup hook imports this C body for exact map
identities and immutable key sizes; no compiler source change or tool build is
needed. The fixture checks distinct 8/16-byte maps and a retained generic call.
The driver compares hashing with the actual kernel `jhash.h`, exercises guarded
keys, collisions, seeds, bucket counts and value padding, and supplies a changed
nulls marker through shared memory. Application selection follows host validation.

2026-11-20T04:18:18Z — Plain HASH59763bf01 production subset652047 completes0. Sole-kernel stock accepts fresh helper-call B in18instructions. The actual compile_checked_simulator API selects the C HASH body and passes112kernel-hash-grounded hit/hash-miss/key-miss/empty cases across4seeds/7bucket counts. Native/proof entry sizes190/184B are reported as component sizes, with no byte target or runtime gain inferred. Existing ARRAY1008/two generic controls, probe99/eight links, LPM805830direct/18819production cases all pass in the same configuration. Host hash1032/lookup143388/nulls restart1/generic589 receipts and first failed dynamic-selector diagnostic stay in results/hash-c-lto-20261120/report.json/evidence.tar.gz. Installed compiler remains353368B/Nov19 22:14; no tool build/change. Next actual OTel guest uses prefix/private-binding/HASH together, all LTO on; prior1033.533→4875.659ns/call regression stays retained. Application coverage, per-call/throughput and formal helper refinement remain open.
