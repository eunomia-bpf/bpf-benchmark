# Restored-work PMU: residual cost and common LPM opportunity

Both phases resolve to QEMU PID1165484 and their own in-phase symbols. Entry ratio remains0.990618681x. Grouping joins JIT/native names before comparing; separate native-only symbol rows are not whole-group regressions.

| Group | eBPF sampled periods/entry | Native | Native/eBPF |
|---|---:|---:|---:|
| unwinder | 987.932 | 789.484 | 0.799128 |
| trie_lookup_elem | 2378.270 | 2768.336 | 1.164012 |
| array_map_lookup_elem | 205.000 | 118.431 | 0.577715 |
| hash | 652.580 | 674.533 | 1.033639 |
| copy_from_user_nofault | 1462.690 | 1704.251 | 1.165148 |

The native unwind body is about20% lower and arrays about42% lower by this PMU normalization. The positive differences concentrate in the unchanged kernel trie lookup (+16.4%) and copy-from-user-nofault (+16.5%); combined hash functions are +3.4%. These are sampling estimates, not exact per-call kernel ns or proof of different helper latency. Both trie phases share dominant offsets105/148/286 and both copy phases102/91/108; path frequency, query distribution and cache state remain possible contributors.

Both actual unwinders have four trie call sites targeting the same boot-kernel function. Native builds the prefix96 key using movbe stores; JIT uses bswap plus stores. Both probe paths call the same bpf_probe_read_user helper with normal destination/size/source ordering. Static snippets do not establish the cause of the PMU difference and do not justify an ISA flag change on their own.

A concrete general optimization opportunity exists in the current interfaces: perf_context_lto.cpp already imports the common C LPM implementation from native-helpers.h with boot-BTF offsets and an actual map shape. Its map-type facts are necessary to select that lowering. The captured unwinder plan identifies all four pid_page_to_map sites as generic `kind: call`, with no LPM shape/key size; frozen_ir.rs re-emits from embedded IR using immutable facts but supplies no map-type input. This establishes the captured route remains direct kernel calls, not that an earlier successful lowering was lost. A next implementation must propagate actual LPM map shape through the permitted loader headers/linker and reuse that common implementation for every app, without choosing by app/program/map names or changing kernel/framework/settings. No production patch or performance improvement is claimed yet.

`residual-cost.json` preserves grouping, actual call windows and exact matching plan facts/SHA. The partial cache ELF3fdabd877365437a.proof.o failed llvm-nm (truncated section-header table); it is an observer capture artifact, not a failed installed program. The collector now inventories every canonical proof, records parse failures, retains all raw bytes in the archive and selects the one parseable actual perf_unwind_native symbol. The original failed collector receipt/log are preserved. Re-run collection only, not the completed guest or PMU pass. Full archival retry is a separate finite CPU19 job; raw205918 stays protected until committed archive/full-file/Git verification.
