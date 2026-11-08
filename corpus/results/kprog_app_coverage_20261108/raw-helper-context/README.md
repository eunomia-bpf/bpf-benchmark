# x86 RAW helper context identity

RAW entry initializes helper_ctx and helper_abi_base to the actual entry CTX, matching native RDI. The existing exact-base expression selects CTX when an argument equals CTX and retains the argument for every other value, so its RAW mapping is the identity. XDP and SKB retain their current ABI projections. This two-line entry-state correction matches ARM ae04d80a6 and introduces runtime predicates/gates/limits0.

Existing helper dispatch specification/oracle freshness, slot and route host checks return0, including19458 route cases; host.log retains all compiler warnings. Those checks cover helper routing independently of the RAW entry composition. Original38 on this captured source is queued after the current paired application chain; actual native/compiler/verifier stages will follow in safety/. Current whole-application epochs retain their captured source. Universal entry-ABI/compiled-B closure remains in V coverage.
