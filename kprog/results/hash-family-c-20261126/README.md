# Key-size C hash-family calls (P3)

Coordinator assignment 2026-11-26T06:25Z: use header C routines returning the
hash-table element for HASH, LRU_HASH, PERCPU_HASH and HASH_OF_MAPS. Preserve the
LTO value-returning entry and native-link's existing direct-call postprocessing.
The module derives its private layout from the boot kernel BTF at build time;
both loaders select its key-size symbol when present and otherwise retain
`__htab_map_lookup_elem`. The x86 full timing run stays frozen.

The host check reuses the kernel-header oracle and guarded-key/collision/nulls
restart driver, adding an assertion relating the element and value entries.
The offline target reuses the existing whole-stage linker check for both ISAs.
Raw check results and guest logs will be retained here as they complete.
