# Compact word-key hash LTO

The same-profile Katran analysis finds a real capability gap: its20-byte VIP
keys select the generic raw kernel hash because the former LTO body handles
only4/8/12/16 bytes. htab_map_hash and lookup_nulls_elem_raw remain visible in
both arms. See katran-c-hdr-20261115/fixed-frequency/profile/ for sampled hot
instructions and exact source/payload provenance; no individual speedup is
inferred from those samples.

The replacement emits one compact Jenkins word-key loop and exact memcmp
walk, rather than four duplicated fixed-size lookup bodies. It follows the
sole kernel jhash2 chunk/final order for every positive key length divisible
by four, including20. The existing kernel byte-key path remains for other
lengths. Live seed and bucket reads, full hash and key comparison, nulls-marker
retry, raw return and caller value/perCPU/LRU postprocessing stay intact.
No new flag, key-length cap, schema or producer edit is introduced. All LTO
still selects the combined configuration.

The actual508-byte emitted routine passes49178 kernel-reference vectors across
4..128-byte keys: unaligned/page-end inputs, same-hash collisions, mismatched
full hashes, misses, wrong-marker retry, and original byte-key call ABI. The
complete linker suite passes44 tests with one preexisting ignored timing test.
The before/current full-object blob sizes, actual guest operation and runtime
speed remain pending paired publication and fixed-frequency Katran timing.
Production CLI/base/image have not been replaced in this step.

Raw compilation, machine-code fixture and execution diagnostics remain at
/workspaces/kprog-raw/perf/20261115-word-hash-lto/. The test fixture directory
moved there intact from its completed temporary path; no raw data was deleted.
