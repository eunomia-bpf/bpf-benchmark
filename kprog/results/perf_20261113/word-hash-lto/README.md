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

Queued confirmation, 2026-11-15T21:09:06Z: the existing image publisher1208082 waits for
C's whole Tracee timing parent1197138 to exit, then acquires imageEX. Proxy
1208081 holds imageSH for that active pair. Validation1211115 follows completed
image production under imageSH: existing actual-plan replay and1x10s Katran
startup, with live JIT/cache observations retained. Timing1211116 follows the
validation process ending and runs the existing fixed-frequency one A/A plus
one A/B,3x180s/stats1,CPU0–7, all LTO, timingEX then imageSH. Publication and
new timings have not started at this checkpoint. No runtime gain is claimed.

Each job uses the committed Make recipes and run_verified_make launcher,
setsid/nohup and a hard address-space bound; persistent raw directories are
`20261115-word-hash-lto/{image,validation,timing}` under /workspaces/kprog-raw/perf.
The queue waits on process/resource order. Supplementary observation or smoke
status does not discard a completed measurement. Actual application errors,
exit statuses and observer diagnostics will remain with the raw outputs.

Publication completes21:17:35Z, exit0, sole imageb6ed6a16 and CLIfb611.
Boot, kernel config, ELF and both external modules match the before state;
the shipped CLI, loader and shim match their packaging inputs. All1252 native
stage files match the image. The89 stage differences from the previous image
are C's Tetragon work:59 additions and30 changes; Katran's input stays c0dc.

New-code replay on the prior actual timed plan keeps proof87686129 and reduces
the neutral runtime payload12386→11016B, with288B relocations. This is an
11.06% payload reduction, with actual installed size and new timed binding
still to be measured. The prior per-call/body targets remain open.

The separate smoke stops before boot because its observation directory was
not created; all73 host controls restore exactly. The caller now creates the
selected observation directory. Syntax passes; no separate application success
is claimed. The existing fixed-frequency pair starts21:17:36Z and continues,
with its own per-arm observation directories already created. Its actual
application/counter outcomes will be retained. No smoke failure or missing
supplementary observation discards the scheduled measurements.
