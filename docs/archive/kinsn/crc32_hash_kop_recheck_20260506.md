# CRC32 + Hash kop Recheck for Production Corpus

Date: 2026-05-06.
Scope: cilium, katran, tracee, tetragon, otelcol-ebpf-profiler.
Mode: read-only static investigation of cached BPF artifacts and available upstream BPF sources.
Primary question: did the 2026-03-29 CRC32 study miss enough CRC32, PCLMULQDQ, or hash-acceleration sites in the production corpus to justify a kop pass?

## Executive Verdict

1. Direct CRC32/CRC32C byte-step sites in these five apps: 0.
2. PCLMULQDQ/PMULL-worthy long-buffer CRC/hash loops in these five apps: 0.
3. Jenkins `__jhash_mix` sites in loaded/cached BPF objects: 15 total.
4. Jenkins `__jhash_final` sites in loaded/cached BPF objects: 15 total.
5. Cilium accounts for 14 of 15 `__jhash_mix` sites and 13 of 15 `__jhash_final` sites.
6. Katran accounts for 1 of 15 `__jhash_mix` sites and 2 of 15 `__jhash_final` sites.
7. Tracee has one actual Murmur32 word-stream loop plus seven fixed Murmur-style mix rounds.
8. djb2, FNV-1a, SipHash, and direct CRC table-step loops were not found in the scanned BPF objects.
9. Maglev permutation loops were not found in BPF; Cilium and Katran consume precomputed lookup tables/maps.
10. Confirmed byte-by-byte memcmp/string-equality loops were not found in the scanned BPF objects.
11. The only hash family with visible concentration is Jenkins tuple hashing.
12. Jenkins count is below the `>= 50` implement threshold and below the 20-site threshold if counting only true `__jhash_mix`.
13. If counting `__jhash_mix` plus `__jhash_final` as one broad Jenkins family, the count is 30 macro bodies, making it second-priority at best.
14. A Jenkins semantic kop would be difficult because it is a three-word state transform, not a single-register instruction replacement.
15. A PCLMULQDQ replacement would not preserve Jenkins/Murmur semantics and would change hash distribution.
16. The prior CRC32 verdict remains correct for the supported production corpus.
17. The prior CRC32 report was narrower for direct CRC32C, but this recheck does not find a missed production-corpus CRC opportunity.
18. The practical action is not a CRC/hash pass; prioritize existing rotate32 work, then reassess the remaining Jenkins/Murmur cost after rotate32 lands.

## A. Methodology

### Inputs

1. Required plan document read: `docs/kernel-jit-optimization-plan.md`.
2. Required project instruction document read: `CLAUDE.md`.
3. Required prior CRC document found at actual path: `docs/tmp/20260329/crc32_kop_research_20260329.md`.
4. Required prior bit-ops document found at actual path: `docs/tmp/20260329/bit_ops_kop_research_20260329.md`.
5. Required prior ANDN document read: `docs/tmp/andn_kop_research_20260430.md`.
6. The user-requested top-level CRC and bit-ops paths did not exist in this checkout.
7. The dated `docs/tmp/20260329/` paths were used instead.
8. Cilium runner inspected: `runner/libs/app_runners/cilium.py`.
9. Katran runner inspected: `runner/libs/app_runners/katran.py`.
10. Tracee runner inspected: `runner/libs/app_runners/tracee.py`.
11. Tetragon runner inspected: `runner/libs/app_runners/tetragon.py`.
12. OTel profiler runner inspected: `runner/libs/app_runners/otel_profiler.py`.
13. Cilium cached BPF artifacts scanned under `corpus/build/cilium/`.
14. Katran cached BPF artifacts scanned under `corpus/build/katran/`.
15. Tracee cached BPF artifacts scanned under `corpus/build/tracee/`.
16. Tetragon cached BPF artifacts scanned under `corpus/build/tetragon/`.
17. OTel profiler cached BPF artifacts scanned under `corpus/build/opentelemetry-ebpf-profiler/`.
18. Cilium source cross-check used `runner/repos/cilium/bpf/`.
19. Katran source cross-check used `runner/repos/katran/katran/lib/bpf/`.
20. Katran Jenkins source cross-check used `runner/repos/katran/katran/lib/linux_includes/jhash.h`.
21. OTel profiler source cross-check used `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/`.
22. Tracee upstream source was not present as a repository checkout.
23. Tracee object DWARF/BTF strings contain source references under `runner/repos/tracee/`, so object metadata was used.
24. Tetragon upstream source was not present as a repository checkout.
25. Tetragon object DWARF/BTF strings contain source/path/policy metadata, so object metadata was used.

### Tools

1. `find` enumerated cached `.bpf.o` and `.o` files.
2. `rg` searched source trees and object strings.
3. `llvm-objdump -d` inspected eBPF instruction streams.
4. `llvm-objdump -d --no-show-raw-insn` made loop bodies readable.
5. `llvm-nm -n` identified named hash functions in Tracee.
6. `llvm-strings` inspected BTF/DWARF strings and embedded source snippets.
7. `bpftool version` was checked; offline object scanning was used instead of live program dump.
8. No app was started.
9. No live `bpftool prog dump xlated id <id>` was run because no benchmark workload was launched.
10. No benchmarks were run.
11. No runner behavior was changed.
12. No source code was modified.

### Pattern Signatures

1. Direct CRC32C table-step signature:
2. `acc ^= byte_i`.
3. `idx = acc & 0xff`.
4. `acc >>= 8`.
5. `acc ^= table[idx]`.
6. Constants checked included reflected CRC32C and CRC32 polynomials.
7. Direct CRC constants checked included `0x82f63b78`.
8. Direct CRC constants checked included `0xedb88320`.
9. Direct CRC constants checked included `0x1edc6f41`.
10. Direct CRC constants checked included `0x04c11db7`.
11. Jenkins `__jhash_mix` signature used the six rotate distances from the macro.
12. Jenkins `__jhash_mix` rotate sequence: `4, 6, 8, 16, 19, 4`.
13. Jenkins `__jhash_final` signature used the seven rotate distances from the macro.
14. Jenkins `__jhash_final` rotate sequence: `14, 11, 25, 16, 4, 14, 24`.
15. The scanner allowed compiler interleaving where the final `rol32(..., 14)` appears before the last mix `rol32(..., 4)`.
16. djb2 signature checked: `hash = ((hash << 5) + hash) ^ byte`.
17. FNV-1a signature checked: `hash = (hash ^ byte) * FNV_PRIME`.
18. Murmur32 signature checked through constants `0xcc9e2d51` and `0x1b873593`.
19. Maglev signature checked for in-BPF permutation loops over `(j * x + offset) % M`.
20. String/memcmp signature checked for byte loop compare, known helper names, and `BPF_FUNC_strncmp` calls.

### Counting Rules

1. Site counts are static object counts, not dynamic hotness.
2. Duplicate architecture artifact trees were not double-counted.
3. Tetragon's 94 root objects were counted once from `corpus/build/tetragon/`.
4. Tracee root objects and LSM support objects were counted once from `corpus/build/tracee/`.
5. Cilium source test objects were ignored because the runner loads production agent artifacts.
6. Katran cached extras were scanned but separated from the runner-pulled objects.
7. `jhash_mix` and `jhash_final` are reported separately.
8. The verdict threshold for Jenkins is based primarily on true `__jhash_mix` sites.
9. A secondary note reports Jenkins mix+final macro bodies because a semantic Jenkins kop may need to cover both.
10. Murmur32 is reported as an "other hash" finding, not as djb2/FNV.
11. Cilium constant-length `memcmp` lowering is not counted as a byte loop.
12. Katran four-word IPv6 equality is not counted as a byte loop.
13. Tracee/Tetragon policy strings are not counted without confirmed byte-loop code.
14. Maglev map/table lookup is not counted as permutation.
15. User-space hash/permutation code is not counted as a BPF kop opportunity.

### Limitations

1. This is a static read-only scan.
2. No live Cilium agent startup was performed.
3. Cilium can compile/load BPF variants based on build config and runtime features.
4. The cached Cilium objects reflect the current runner artifact set, not every possible upstream feature combination.
5. Tracee upstream BPF C source was absent from this checkout.
6. Tetragon upstream BPF C source was absent from this checkout.
7. Object strings and disassembly were used where source was absent.
8. No run-count or run-time weighting was attempted.
9. No result JSONs were read or produced for this report.
10. The report does not estimate hotness from benchmark counters.
11. The report does not propose any framework-side aggregation.
12. The report does not modify `docs/kernel-jit-optimization-plan.md`.

## B. Per-app Site Counts

### Summary Table

| app | objects scanned | CRC32-direct | jhash-mix | jhash-final | djb2/FNV | other hash | Maglev loop | memcmp byte loop | string-eq loop | primary locations |
| --- | ---: | ---: | ---: | ---: | ---: | --- | ---: | ---: | ---: | --- |
| cilium | 7 | 0 | 14 | 13 | 0 | 0 | 0 | 0 | 0 | `bpf_overlay.bpf.o`, `bpf_xdp.bpf.o` |
| katran | 5 | 0 | 1 | 2 | 0 | 0 | 0 | 0 | 0 | `balancer.bpf.o` |
| tracee | 3 | 0 | 0 | 0 | 0 | 1 loop + 7 fixed Murmur rounds | 0 | 0 | 0 | `tracee.bpf.o:murmur32` |
| tetragon | 94 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | none |
| otelcol-ebpf-profiler | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | none |
| total | 112 | 0 | 15 | 15 | 0 | 1 loop + 7 fixed Murmur rounds | 0 | 0 | 0 | Cilium/Katran Jenkins, Tracee Murmur |

### Cilium Counts

1. Scanned object: `corpus/build/cilium/bpf_alignchecker.bpf.o`.
2. `bpf_alignchecker.bpf.o` CRC32-direct: 0.
3. `bpf_alignchecker.bpf.o` jhash-mix: 0.
4. `bpf_alignchecker.bpf.o` jhash-final: 0.
5. `bpf_alignchecker.bpf.o` djb2/FNV: 0.
6. `bpf_alignchecker.bpf.o` Maglev loop: 0.
7. `bpf_alignchecker.bpf.o` confirmed memcmp/string loop: 0.
8. Scanned object: `corpus/build/cilium/bpf_host.bpf.o`.
9. `bpf_host.bpf.o` CRC32-direct: 0.
10. `bpf_host.bpf.o` jhash-mix: 0.
11. `bpf_host.bpf.o` jhash-final: 0.
12. `bpf_host.bpf.o` djb2/FNV: 0.
13. `bpf_host.bpf.o` Maglev loop: 0.
14. `bpf_host.bpf.o` confirmed memcmp/string loop: 0.
15. Scanned object: `corpus/build/cilium/bpf_lxc.bpf.o`.
16. `bpf_lxc.bpf.o` CRC32-direct: 0.
17. `bpf_lxc.bpf.o` jhash-mix: 0.
18. `bpf_lxc.bpf.o` jhash-final: 0.
19. `bpf_lxc.bpf.o` djb2/FNV: 0.
20. `bpf_lxc.bpf.o` Maglev loop: 0.
21. `bpf_lxc.bpf.o` confirmed memcmp/string loop: 0.
22. Scanned object: `corpus/build/cilium/bpf_overlay.bpf.o`.
23. `bpf_overlay.bpf.o` CRC32-direct: 0.
24. `bpf_overlay.bpf.o` jhash-mix: 4.
25. `bpf_overlay.bpf.o` jhash-final: 4.
26. `bpf_overlay.bpf.o` djb2/FNV: 0.
27. `bpf_overlay.bpf.o` Maglev loop: 0.
28. `bpf_overlay.bpf.o` confirmed memcmp/string loop: 0.
29. `bpf_overlay.bpf.o` Jenkins cluster `LBB21_300`: 2 mix + 1 final.
30. `bpf_overlay.bpf.o` Jenkins cluster `LBB21_391`: 2 mix + 1 final.
31. `bpf_overlay.bpf.o` Jenkins cluster `LBB23_105`: 0 mix + 1 final.
32. `bpf_overlay.bpf.o` Jenkins cluster `LBB23_198`: 0 mix + 1 final.
33. Scanned object: `corpus/build/cilium/bpf_sock.bpf.o`.
34. `bpf_sock.bpf.o` CRC32-direct: 0.
35. `bpf_sock.bpf.o` jhash-mix: 0.
36. `bpf_sock.bpf.o` jhash-final: 0.
37. `bpf_sock.bpf.o` djb2/FNV: 0.
38. `bpf_sock.bpf.o` Maglev loop: 0.
39. `bpf_sock.bpf.o` confirmed memcmp/string loop: 0.
40. `bpf_sock.bpf.o` source has two value `memcmp` calls, but Cilium lowers constant lengths through unrolled XOR chunks.
41. Scanned object: `corpus/build/cilium/bpf_wireguard.bpf.o`.
42. `bpf_wireguard.bpf.o` CRC32-direct: 0.
43. `bpf_wireguard.bpf.o` jhash-mix: 0.
44. `bpf_wireguard.bpf.o` jhash-final: 0.
45. `bpf_wireguard.bpf.o` djb2/FNV: 0.
46. `bpf_wireguard.bpf.o` Maglev loop: 0.
47. `bpf_wireguard.bpf.o` confirmed memcmp/string loop: 0.
48. Scanned object: `corpus/build/cilium/bpf_xdp.bpf.o`.
49. `bpf_xdp.bpf.o` CRC32-direct: 0.
50. `bpf_xdp.bpf.o` jhash-mix: 10.
51. `bpf_xdp.bpf.o` jhash-final: 9.
52. `bpf_xdp.bpf.o` djb2/FNV: 0.
53. `bpf_xdp.bpf.o` Maglev loop: 0.
54. `bpf_xdp.bpf.o` confirmed memcmp/string loop: 0.
55. `bpf_xdp.bpf.o` Jenkins cluster `LBB6_177`: 2 mix + 1 final.
56. `bpf_xdp.bpf.o` Jenkins cluster `LBB7_177`: 2 mix + 1 final.
57. `bpf_xdp.bpf.o` Jenkins cluster `LBB8_538`: 2 mix + 1 final.
58. `bpf_xdp.bpf.o` Jenkins cluster `LBB11_195`: 0 mix + 1 final.
59. `bpf_xdp.bpf.o` Jenkins cluster `LBB12_297`: 0 mix + 1 final.
60. `bpf_xdp.bpf.o` Jenkins cluster `LBB14_176`: 0 mix + 1 final.
61. `bpf_xdp.bpf.o` Jenkins cluster `LBB14_334`: 0 mix + 1 final.
62. `bpf_xdp.bpf.o` Jenkins cluster `LBB15_181`: 2 mix + 1 final.
63. `bpf_xdp.bpf.o` Jenkins cluster `LBB15_274`: 2 mix + 1 final.
64. Cilium app total CRC32-direct: 0.
65. Cilium app total jhash-mix: 14.
66. Cilium app total jhash-final: 13.
67. Cilium app total djb2/FNV: 0.
68. Cilium app total Maglev loop: 0.
69. Cilium app total confirmed memcmp/string loop: 0.

### Cilium Source Cross-check

1. `runner/repos/cilium/bpf/lib/hash.h:13` defines `__hash_from_tuple_v4`.
2. `runner/repos/cilium/bpf/lib/hash.h:15` calls `jhash_3words`.
3. `runner/repos/cilium/bpf/lib/hash.h:25` defines `__hash_from_tuple_v6`.
4. `runner/repos/cilium/bpf/lib/hash.h:32` calls `__jhash_mix`.
5. `runner/repos/cilium/bpf/lib/hash.h:36` calls `__jhash_mix`.
6. `runner/repos/cilium/bpf/lib/hash.h:38` calls `__jhash_final`.
7. `runner/repos/cilium/bpf/lib/jhash.h:18` defines `__jhash_mix`.
8. `runner/repos/cilium/bpf/lib/jhash.h:28` defines `__jhash_final`.
9. `runner/repos/cilium/bpf/lib/jhash.h:50` has a `while (length > 12)` in the generic source.
10. In scanned Cilium objects, the tuple-hash uses are constant/specialized enough that no dynamic byte-stream jhash loop was found.
11. `runner/repos/cilium/bpf/lib/lb.h:1095` defines `lb6_select_backend_id_maglev`.
12. `runner/repos/cilium/bpf/lib/lb.h:1115` computes `__hash_from_tuple_v6(...) % LB_MAGLEV_LUT_SIZE`.
13. `runner/repos/cilium/bpf/lib/lb.h:1116` reads a backend id from a Maglev LUT.
14. `runner/repos/cilium/bpf/lib/lb.h:1839` defines `lb4_select_backend_id_maglev`.
15. `runner/repos/cilium/bpf/lib/lb.h:1862` computes `__hash_from_tuple_v4(...) % LB_MAGLEV_LUT_SIZE`.
16. `runner/repos/cilium/bpf/lib/lb.h:1863` reads a backend id from a Maglev LUT.
17. These Cilium Maglev paths are table lookup paths, not in-BPF permutation generation.
18. `runner/repos/cilium/bpf/lib/encap.h:120` calls `hash_from_tuple_v4`.
19. `runner/repos/cilium/bpf/lib/encap.h:132` calls `hash_from_tuple_v6`.
20. These encap calls explain some `bpf_overlay.bpf.o` Jenkins clusters.
21. `runner/repos/cilium/bpf/lib/csum.h:40` handles SCTP conditionally.
22. `runner/repos/cilium/bpf/lib/csum.h:43` notes SCTP packets use CRC32C.
23. `runner/repos/cilium/bpf/lib/csum.h:48` says there is not a good way to calculate CRC32C in eBPF.
24. That Cilium path disables checksum readjustment instead of implementing CRC32C.
25. `runner/repos/cilium/bpf/bpf_sock.c:167` has a value `memcmp`.
26. `runner/repos/cilium/bpf/bpf_sock.c:656` has a value `memcmp`.
27. `runner/repos/cilium/bpf/include/bpf/builtins.h:298` defines `__bpf_memcmp`.
28. `runner/repos/cilium/bpf/include/bpf/builtins.h:303` requires constant length.
29. `runner/repos/cilium/bpf/include/bpf/builtins.h:314` dispatches through a switch.
30. `runner/repos/cilium/bpf/include/bpf/builtins.h:315-387` emits fixed-width XOR chunks.
31. The Cilium memcmp implementation is not a dynamic byte-by-byte loop.

### Katran Counts

1. Scanned object: `corpus/build/katran/balancer.bpf.o`.
2. `balancer.bpf.o` CRC32-direct: 0.
3. `balancer.bpf.o` jhash-mix: 1.
4. `balancer.bpf.o` jhash-final: 2.
5. `balancer.bpf.o` djb2/FNV: 0.
6. `balancer.bpf.o` Maglev loop: 0.
7. `balancer.bpf.o` confirmed memcmp/string loop: 0.
8. `balancer.bpf.o` `jhash_2words` path accounts for one final-only 5-tuple hash.
9. `balancer.bpf.o` `jhash` IPv6 source path accounts for one mix plus one final.
10. Scanned object: `corpus/build/katran/healthchecking.bpf.o`.
11. `healthchecking.bpf.o` CRC32-direct: 0.
12. `healthchecking.bpf.o` jhash-mix: 0.
13. `healthchecking.bpf.o` jhash-final: 0.
14. `healthchecking.bpf.o` djb2/FNV: 0.
15. `healthchecking.bpf.o` Maglev loop: 0.
16. `healthchecking.bpf.o` confirmed memcmp/string loop: 0.
17. Scanned object: `corpus/build/katran/healthchecking_ipip.bpf.o`.
18. `healthchecking_ipip.bpf.o` CRC32-direct: 0.
19. `healthchecking_ipip.bpf.o` jhash-mix: 0.
20. `healthchecking_ipip.bpf.o` jhash-final: 0.
21. `healthchecking_ipip.bpf.o` djb2/FNV: 0.
22. `healthchecking_ipip.bpf.o` Maglev loop: 0.
23. `healthchecking_ipip.bpf.o` confirmed memcmp/string loop: 0.
24. Scanned object: `corpus/build/katran/xdp_pktcntr.bpf.o`.
25. `xdp_pktcntr.bpf.o` CRC32-direct: 0.
26. `xdp_pktcntr.bpf.o` jhash-mix: 0.
27. `xdp_pktcntr.bpf.o` jhash-final: 0.
28. `xdp_pktcntr.bpf.o` djb2/FNV: 0.
29. `xdp_pktcntr.bpf.o` Maglev loop: 0.
30. `xdp_pktcntr.bpf.o` confirmed memcmp/string loop: 0.
31. Scanned object: `corpus/build/katran/xdp_root.bpf.o`.
32. `xdp_root.bpf.o` CRC32-direct: 0.
33. `xdp_root.bpf.o` jhash-mix: 0.
34. `xdp_root.bpf.o` jhash-final: 0.
35. `xdp_root.bpf.o` djb2/FNV: 0.
36. `xdp_root.bpf.o` Maglev loop: 0.
37. `xdp_root.bpf.o` confirmed memcmp/string loop: 0.
38. Katran app total CRC32-direct: 0.
39. Katran app total jhash-mix: 1.
40. Katran app total jhash-final: 2.
41. Katran app total djb2/FNV: 0.
42. Katran app total Maglev loop: 0.
43. Katran app total confirmed memcmp/string loop: 0.
44. The runner pulls `balancer.bpf.o`, `healthchecking_ipip.bpf.o`, and `xdp_root.bpf.o`.
45. `healthchecking.bpf.o` and `xdp_pktcntr.bpf.o` were scanned as cached extras.

### Katran Source Cross-check

1. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:25` defines `get_packet_hash`.
2. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:29` calls `jhash_2words`.
3. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:30` calls `jhash` over the IPv6 source words.
4. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:34` calls `jhash_2words` for IPv4.
5. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:143` computes `get_packet_hash(...) % RING_SIZE`.
6. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:146` looks up `ch_rings`.
7. The BPF program consumes a precomputed ring.
8. The BPF program does not generate the Maglev permutation.
9. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:235` documents a `__builtin_memcmp` workaround.
10. `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:236-239` compares four IPv6 words.
11. That comparison is a fixed word equality sequence, not a byte loop.
12. `runner/repos/katran/katran/lib/linux_includes/jhash.h:55` defines `jhash`.
13. `runner/repos/katran/katran/lib/linux_includes/jhash.h:61` has `while (length > 12)`.
14. `runner/repos/katran/katran/lib/linux_includes/jhash.h:65` calls `__jhash_mix`.
15. `runner/repos/katran/katran/lib/linux_includes/jhash.h:94` calls `__jhash_final`.
16. The compiled IPv6 source hash with length 16 generates one Jenkins mix and one final.
17. The compiled IPv4/ports path generates final-only `jhash_2words`.
18. Katran user-space C++ contains Maglev permutation generation, but that is not BPF code.

### Tracee Counts

1. Scanned object: `corpus/build/tracee/tracee.bpf.o`.
2. `tracee.bpf.o` CRC32-direct: 0.
3. `tracee.bpf.o` jhash-mix: 0.
4. `tracee.bpf.o` jhash-final: 0.
5. `tracee.bpf.o` djb2/FNV: 0.
6. `tracee.bpf.o` Maglev loop: 0.
7. `tracee.bpf.o` confirmed memcmp/string loop: 0.
8. `tracee.bpf.o` other hash: one real `murmur32` word-stream loop.
9. `tracee.bpf.o` other hash: seven additional fixed Murmur-style rounds.
10. `tracee.bpf.o` named hash function: `murmur32`.
11. `tracee.bpf.o` named hash function: `hash_u32_and_u64`.
12. `tracee.bpf.o` named hash function: `hash_task_id`.
13. `murmur32` loop body contains multiply by `0xcc9e2d51`.
14. `murmur32` loop body contains rotate-left style shifts.
15. `murmur32` loop body contains multiply by `0x1b873593`.
16. `murmur32` loop body folds into the accumulator and advances the input.
17. `murmur32` tail/finalization emits one fixed Murmur-style round.
18. `hash_u32_and_u64` emits three fixed Murmur-style rounds.
19. `hash_task_id` emits three fixed Murmur-style rounds.
20. Total Tracee Murmur `c1/c2` round signatures: 8.
21. Only one of those signatures is a data-dependent loop body.
22. Scanned object: `corpus/build/tracee/lsm_support/kprobe_check.bpf.o`.
23. `lsm_support/kprobe_check.bpf.o` CRC32-direct: 0.
24. `lsm_support/kprobe_check.bpf.o` jhash-mix: 0.
25. `lsm_support/kprobe_check.bpf.o` jhash-final: 0.
26. `lsm_support/kprobe_check.bpf.o` djb2/FNV: 0.
27. `lsm_support/kprobe_check.bpf.o` Maglev loop: 0.
28. `lsm_support/kprobe_check.bpf.o` confirmed memcmp/string loop: 0.
29. Scanned object: `corpus/build/tracee/lsm_support/lsm_check.bpf.o`.
30. `lsm_support/lsm_check.bpf.o` CRC32-direct: 0.
31. `lsm_support/lsm_check.bpf.o` jhash-mix: 0.
32. `lsm_support/lsm_check.bpf.o` jhash-final: 0.
33. `lsm_support/lsm_check.bpf.o` djb2/FNV: 0.
34. `lsm_support/lsm_check.bpf.o` Maglev loop: 0.
35. `lsm_support/lsm_check.bpf.o` confirmed memcmp/string loop: 0.
36. Tracee object strings contain path, cgroup, ksymbol, and `strncmp` names.
37. Tracee disassembly did not confirm a byte-by-byte equality loop for those names.
38. Tracee object scan did not find `BPF_FUNC_strncmp` helper calls.
39. Tracee app total CRC32-direct: 0.
40. Tracee app total jhash-mix: 0.
41. Tracee app total jhash-final: 0.
42. Tracee app total djb2/FNV: 0.
43. Tracee app total Maglev loop: 0.
44. Tracee app total confirmed memcmp/string loop: 0.
45. Tracee app total other hash: 1 real Murmur loop + 7 fixed Murmur rounds.

### Tetragon Counts

1. Scanned 94 root BPF objects under `corpus/build/tetragon/`.
2. Tetragon CRC32-direct total: 0.
3. Tetragon jhash-mix total: 0.
4. Tetragon jhash-final total: 0.
5. Tetragon djb2/FNV total: 0.
6. Tetragon Maglev loop total: 0.
7. Tetragon confirmed memcmp/string loop total: 0.
8. Tetragon other hash total: 0.
9. Tetragon object strings include policy and string-prefix map names.
10. Tetragon object strings include `string_prefix_maps`.
11. Tetragon object strings include `string_prefix_lpm_trie`.
12. Tetragon disassembly did not show a confirmed byte-loop string comparison.
13. Tetragon disassembly did not show direct CRC32 table-step loops.
14. Tetragon disassembly did not show Jenkins rotate sequences.
15. Tetragon disassembly did not show Murmur constants.
16. Tetragon disassembly did not show djb2 multiply/add byte loops.
17. Tetragon disassembly did not show FNV prime multiply byte loops.
18. Tetragon disassembly did not show in-BPF Maglev permutation loops.
19. Tetragon source was absent, so this is object-driven evidence.

### OTel profiler Counts

1. Scanned object: `corpus/build/opentelemetry-ebpf-profiler/generic_probe.bpf.o`.
2. `generic_probe.bpf.o` CRC32-direct: 0.
3. `generic_probe.bpf.o` jhash-mix: 0.
4. `generic_probe.bpf.o` jhash-final: 0.
5. `generic_probe.bpf.o` djb2/FNV: 0.
6. `generic_probe.bpf.o` Maglev loop: 0.
7. `generic_probe.bpf.o` confirmed memcmp/string loop: 0.
8. Scanned object: `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o`.
9. `native_stack_trace.bpf.o` CRC32-direct: 0.
10. `native_stack_trace.bpf.o` jhash-mix: 0.
11. `native_stack_trace.bpf.o` jhash-final: 0.
12. `native_stack_trace.bpf.o` djb2/FNV: 0.
13. `native_stack_trace.bpf.o` Maglev loop: 0.
14. `native_stack_trace.bpf.o` confirmed memcmp/string loop: 0.
15. `native_stack_trace.bpf.o` contains stack delta/map lookup logic, not symbol hashing.
16. Scanned object: `corpus/build/opentelemetry-ebpf-profiler/sched_monitor.bpf.o`.
17. `sched_monitor.bpf.o` CRC32-direct: 0.
18. `sched_monitor.bpf.o` jhash-mix: 0.
19. `sched_monitor.bpf.o` jhash-final: 0.
20. `sched_monitor.bpf.o` djb2/FNV: 0.
21. `sched_monitor.bpf.o` Maglev loop: 0.
22. `sched_monitor.bpf.o` confirmed memcmp/string loop: 0.
23. OTel source grep found userspace Go CRC/FNV use outside loaded BPF objects.
24. OTel BPF support sources did not contain the requested hash implementations in the loaded objects.
25. OTel app total CRC32-direct: 0.
26. OTel app total jhash-mix: 0.
27. OTel app total jhash-final: 0.
28. OTel app total djb2/FNV: 0.
29. OTel app total Maglev loop: 0.
30. OTel app total confirmed memcmp/string loop: 0.

## C. Verdict Updates

### CRC32C scalar step8/step64

1. Production-corpus site count in this recheck: 0.
2. Threshold class: `< 20`.
3. Recommendation: confirm prior "not worth" verdict for the production corpus.
4. The only previously identified direct CRC32C opportunity was loxilb SCTP.
5. loxilb is not in the supported seven-app corpus.
6. Cilium explicitly avoids eBPF CRC32C for SCTP checksum adjustment.
7. No app in this scope implements `__crc32c_le` style table stepping in BPF.
8. No direct CRC32 constants were found in the scanned BPF objects.
9. A scalar CRC32C kop pass should not be added for these apps.
10. If future corpus evidence changes, a scalar CRC32C pass should remain restricted to exact semantic CRC32C patterns.
11. Estimated kop module delta if revived: x86 120-180 LoC.
12. Estimated kop module delta if revived: arm64 100-160 LoC.
13. Estimated BPF opt pass delta if revived: 500-900 LoC.
14. Difficulty if revived: medium.
15. Primary risk if revived: false-positive detection changing checksum semantics.
16. Required constraint: no `vendor/linux-framework/` edits.
17. Required constraint: only module/JIT and pass work, not framework data aggregation.
18. Current verdict: do not implement.

### PCLMULQDQ or PMULL buffer hash/CRC

1. Production-corpus site count: 0.
2. Threshold class: `< 20`.
3. Recommendation: not worth.
4. PCLMULQDQ is attractive for long CRC buffers, not for the observed tuple hashes.
5. Jenkins hash is not CRC32.
6. Murmur32 is not CRC32.
7. Replacing Jenkins/Murmur with CRC/PCLMUL would change hash distribution.
8. A semantics-preserving PCLMUL sequence for Jenkins was not identified.
9. A generic buffer kop would need memory range semantics beyond a scalar peephole.
10. A generic buffer kfunc would require verifier and helper ABI design outside this low-risk kop class.
11. x86 SIMD use also raises kernel context and save/restore constraints.
12. arm64 PMULL has analogous SIMD/crypto extension constraints.
13. Estimated module delta for a real generic buffer kfunc: high and not comparable to rotate32.
14. Estimated pass delta for safe buffer recognition: high.
15. Difficulty: high.
16. Current verdict: do not implement.

### Jenkins `__jhash_mix` / `__jhash_final`

1. Production-corpus true `__jhash_mix` count: 15.
2. Production-corpus `__jhash_final` count: 15.
3. Broad Jenkins macro-body count: 30.
4. Threshold class by true mix count: `< 20`.
5. Threshold class by mix+final count: `20-50`.
6. Recommendation: second-priority only if Jenkins macro bodies are counted as one family; otherwise not worth.
7. The concentration is almost entirely Cilium.
8. Cilium count: 14 mix + 13 final.
9. Katran count: 1 mix + 2 final.
10. Tracee count: 0.
11. Tetragon count: 0.
12. OTel count: 0.
13. A Jenkins mix is a three-register state transform.
14. The existing kop model is more naturally suited to single-result scalar instructions.
15. A single Jenkins-mix kop would need to return or update three values.
16. Packing three 32-bit words into one 64-bit result is not enough.
17. Multiple koperation for one macro would reduce the advantage.
18. A verifier-visible multi-output kfunc would be larger than rotate32.
19. PCLMULQDQ is not an exact replacement.
20. The best immediate benefit for Jenkins likely comes from the rotate32 pass.
21. Jenkins macro bodies contain many rotates.
22. If rotate32 lands, Jenkins cost should be remeasured before any Jenkins-specific pass.
23. Estimated x86 module delta for exact Jenkins mix/final support: 150-250 LoC per primitive, but ABI design may dominate.
24. Estimated arm64 module delta for exact Jenkins mix/final support: 150-250 LoC per primitive, with similar ABI caveats.
25. Estimated optimizer pass delta: 700-1200 LoC.
26. Difficulty: high.
27. Current verdict: do not implement before rotate32; reassess only if post-rotate counters show Jenkins still dominates.

### Murmur32 round

1. Production-corpus real loop count: 1.
2. Production-corpus fixed round count: 7.
3. Production-corpus total round signature count: 8.
4. Threshold class: `< 20`.
5. Recommendation: not worth.
6. The only app with Murmur evidence is Tracee.
7. The only dynamic Murmur loop is `tracee.bpf.o:murmur32`.
8. `hash_u32_and_u64` and `hash_task_id` are fixed small sequences.
9. Murmur32 uses multiplies, rotates, XOR, and accumulator multiply/add.
10. No hardware instruction maps directly to the whole round.
11. PCLMULQDQ is not semantically equivalent.
12. rotate32 can reduce the rotate component without a Murmur-specific pass.
13. Estimated x86 module delta for a Murmur round kop: 120-180 LoC.
14. Estimated arm64 module delta for a Murmur round kop: 120-180 LoC.
15. Estimated optimizer pass delta: 400-700 LoC.
16. Difficulty: medium.
17. Current verdict: do not implement.

### djb2 / FNV-1a / SipHash byte-stream hash

1. Production-corpus djb2 count: 0.
2. Production-corpus FNV-1a count: 0.
3. Production-corpus SipHash count: 0.
4. Threshold class: `< 20`.
5. Recommendation: not worth.
6. OTel uses FNV/CRC in userspace Go code, not in loaded BPF objects.
7. Tracee/Tetragon BPF objects do not show these byte-stream loops.
8. Cilium/Katran BPF tuple hashing uses Jenkins, not djb2/FNV/SipHash.
9. Current verdict: do not implement.

### Maglev permutation

1. Production-corpus in-BPF Maglev permutation count: 0.
2. Threshold class: `< 20`.
3. Recommendation: not worth.
4. Cilium BPF performs tuple hash plus Maglev LUT lookup.
5. Cilium BPF does not generate Maglev permutations.
6. Katran BPF performs tuple hash plus `ch_rings` lookup.
7. Katran BPF does not generate Maglev permutations.
8. Katran Maglev generation is user-space C++.
9. No BPF kop pass should target Maglev permutation in this corpus.

### memcmp / string-equality byte loops

1. Production-corpus confirmed byte-loop count: 0.
2. Threshold class: `< 20`.
3. Recommendation: not worth.
4. Cilium value `memcmp` uses constant-length unrolled XOR chunks.
5. Katran IPv6 equality uses four word comparisons.
6. Tracee object strings mention path/cgroup filters and `strncmp`, but no confirmed byte loop was found.
7. Tetragon object strings mention string-prefix maps, but no confirmed byte loop was found.
8. No `BPF_FUNC_strncmp` helper call was identified in the scanned objects.
9. A generic string compare kfunc would be substantially larger than a scalar kop.
10. Current verdict: do not implement.

## D. Cross-check vs Prior Research

### Versus `crc32_kop_research_20260329.md`

1. Prior CRC32 research focused on direct SCTP CRC32C table-step patterns.
2. Prior direct CRC32C finding: loxilb had two `dp_sctp_csum()` update sites.
3. Prior Cilium finding: SCTP CRC32C was mentioned but not implemented in BPF.
4. This recheck agrees on direct CRC32C for Cilium: 0 sites.
5. This recheck extends the corpus emphasis to cilium, katran, tracee, tetragon, and otelcol.
6. This recheck confirms no direct CRC32C sites in those production apps.
7. This recheck adds Jenkins counts that the prior direct-CRC study did not enumerate.
8. This recheck adds Tracee Murmur evidence that the prior direct-CRC study did not enumerate.
9. The broader methodology changes the evidence set, but not the CRC32 verdict.
10. The prior corpus included loxilb, which is now removed from supported apps.
11. The production-corpus CRC32 opportunity is therefore lower than the prior loxilb-driven opportunity.
12. The prior warning that Jenkins should not be treated as CRC32 remains correct.
13. This report explicitly rejects PCLMULQDQ as a semantic replacement for Jenkins/Murmur.

### Versus `bit_ops_kop_research_20260329.md`

1. Prior bit-ops research found POPCNT/CLZ/CTZ/PDEP/PEXT opportunities were effectively absent.
2. This report did not find hidden hash-loop uses that would change those POPCNT/CLZ/CTZ conclusions.
3. Jenkins and Murmur use rotates, multiplies, adds, and XORs.
4. The relevant bit operation for this recheck is rotate32, not POPCNT/LZCNT/TZCNT/PDEP/PEXT.
5. The bit-ops report's broad negative result remains compatible with this scan.
6. Any observed benefit to Jenkins/Murmur should first be captured through rotate32.
7. A hash-specific pass would duplicate part of rotate32's expected benefit.

### Versus `andn_kop_research_20260430.md`

1. Prior ANDN research found about 45 de-duplicated ANDN-style opportunities.
2. This recheck found fewer true Jenkins mix sites than the ANDN site count.
3. This recheck found 15 true Jenkins mix sites.
4. This recheck found 30 broad Jenkins mix/final macro bodies.
5. The Jenkins family is comparable to or smaller than ANDN by static count.
6. ANDN is a direct single-instruction peephole.
7. Jenkins is a semantic multi-register hash transform.
8. Jenkins therefore has lower implementation attractiveness than ANDN at a similar or lower site count.
9. The ANDN low-ROI conclusion supports caution here.
10. A Jenkins pass should not outrank simpler scalar idiom work.

### Methodology Difference Summary

1. Prior CRC32 methodology: direct CRC table-step pattern scan.
2. Current methodology: direct CRC plus Jenkins, Murmur, djb2/FNV, Maglev, and byte compare signatures.
3. Prior CRC32 corpus included loxilb.
4. Current requested production corpus excludes loxilb.
5. Prior CRC32 output was mostly a CRC-specific verdict.
6. Current output separates semantic hash families.
7. The broader scan found more hash code, but not more CRC32 code.
8. The added hash code is not PCLMULQDQ-amenable without changing semantics.
9. The implementation recommendation remains conservative.

## E. Top 3 Actionable Recommendations

### 1. Do not implement CRC32/PCLMULQDQ for this production corpus

1. Site count: 0 direct CRC32C sites.
2. Site count: 0 PCLMULQDQ-worthy long-buffer sites.
3. Expected per-site savings: not applicable because no sites exist.
4. Rationale: no target pattern in cilium, katran, tracee, tetragon, or otelcol BPF objects.
5. Rationale: Cilium explicitly avoids SCTP CRC32C in BPF.
6. Rationale: Jenkins/Murmur cannot be replaced by CRC32/PCLMUL without semantic hash changes.
7. Action: leave CRC32 kop out of the near-term implementation queue.

### 2. Let rotate32 absorb the practical Jenkins/Murmur opportunity first

1. Site count: 15 Jenkins mix sites.
2. Site count: 15 Jenkins final sites.
3. Site count: 1 Tracee Murmur loop plus 7 fixed Murmur rounds.
4. Expected per-site savings: rotate idiom savings are plausible, hash-specific savings are unproven.
5. Jenkins mix has 6 rotates per macro.
6. Jenkins final has 7 rotates per macro.
7. Tracee Murmur rounds include rotate idioms.
8. Action: after rotate32 lands, remeasure jhash-heavy Cilium objects and Tracee `murmur32`.
9. Action: only consider a hash-specific pass if post-rotate raw counters still show a hot residual.

### 3. Keep Maglev and string compare out of kop scope

1. Site count: 0 in-BPF Maglev permutation loops.
2. Site count: 0 confirmed byte-by-byte string/memcmp loops.
3. Expected per-site savings: not applicable for absent patterns.
4. Cilium Maglev is tuple hash plus LUT read.
5. Katran Maglev is tuple hash plus ring lookup.
6. Katran permutation generation is user-space C++.
7. Cilium memcmp is constant-length unrolled XOR chunks.
8. Katran IPv6 compare is four fixed word compares.
9. Action: do not build Maglev or string-equality koperation from current evidence.

## Appendix 1. Object Scan Ledger

### Cilium Object Ledger

1. `corpus/build/cilium/bpf_alignchecker.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
2. `corpus/build/cilium/bpf_host.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
3. `corpus/build/cilium/bpf_lxc.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
4. `corpus/build/cilium/bpf_overlay.bpf.o`: CRC32 0; jhash mix/final 4/4; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
5. `corpus/build/cilium/bpf_sock.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
6. `corpus/build/cilium/bpf_wireguard.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
7. `corpus/build/cilium/bpf_xdp.bpf.o`: CRC32 0; jhash mix/final 10/9; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.

### Katran Object Ledger

1. `corpus/build/katran/balancer.bpf.o`: CRC32 0; jhash mix/final 1/2; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
2. `corpus/build/katran/healthchecking.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
3. `corpus/build/katran/healthchecking_ipip.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
4. `corpus/build/katran/xdp_pktcntr.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
5. `corpus/build/katran/xdp_root.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.

### Tracee Object Ledger

1. `corpus/build/tracee/tracee.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 1 loop + 7 fixed rounds; Maglev 0; memcmp/string loop 0.
2. `corpus/build/tracee/lsm_support/kprobe_check.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
3. `corpus/build/tracee/lsm_support/lsm_check.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.

### OTel Object Ledger

1. `corpus/build/opentelemetry-ebpf-profiler/generic_probe.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
2. `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.
3. `corpus/build/opentelemetry-ebpf-profiler/sched_monitor.bpf.o`: CRC32 0; jhash mix/final 0/0; djb2/FNV 0; Murmur 0; Maglev 0; memcmp/string loop 0.

### Tetragon Object Ledger

1. `corpus/build/tetragon/bpf_alignchecker.o`: all target hash/CRC/Maglev/string-loop counts 0.
2. `corpus/build/tetragon/bpf_cgroup.o`: all target hash/CRC/Maglev/string-loop counts 0.
3. `corpus/build/tetragon/bpf_cgroup_mkdir.o`: all target hash/CRC/Maglev/string-loop counts 0.
4. `corpus/build/tetragon/bpf_cgroup_mkdir_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
5. `corpus/build/tetragon/bpf_cgroup_release.o`: all target hash/CRC/Maglev/string-loop counts 0.
6. `corpus/build/tetragon/bpf_cgroup_release_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
7. `corpus/build/tetragon/bpf_cgroup_rmdir.o`: all target hash/CRC/Maglev/string-loop counts 0.
8. `corpus/build/tetragon/bpf_cgroup_rmdir_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
9. `corpus/build/tetragon/bpf_cgtracker.o`: all target hash/CRC/Maglev/string-loop counts 0.
10. `corpus/build/tetragon/bpf_enforcer.o`: all target hash/CRC/Maglev/string-loop counts 0.
11. `corpus/build/tetragon/bpf_execve_bprm_commit_creds.o`: all target hash/CRC/Maglev/string-loop counts 0.
12. `corpus/build/tetragon/bpf_execve_event.o`: all target hash/CRC/Maglev/string-loop counts 0.
13. `corpus/build/tetragon/bpf_execve_event_v310.o`: all target hash/CRC/Maglev/string-loop counts 0.
14. `corpus/build/tetragon/bpf_execve_event_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
15. `corpus/build/tetragon/bpf_execve_event_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
16. `corpus/build/tetragon/bpf_execve_event_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
17. `corpus/build/tetragon/bpf_execve_map_update.o`: all target hash/CRC/Maglev/string-loop counts 0.
18. `corpus/build/tetragon/bpf_execve_map_update_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
19. `corpus/build/tetragon/bpf_execve_map_update_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
20. `corpus/build/tetragon/bpf_execve_map_update_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
21. `corpus/build/tetragon/bpf_exit.o`: all target hash/CRC/Maglev/string-loop counts 0.
22. `corpus/build/tetragon/bpf_exit_v310.o`: all target hash/CRC/Maglev/string-loop counts 0.
23. `corpus/build/tetragon/bpf_exit_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
24. `corpus/build/tetragon/bpf_fmodret_enforcer.o`: all target hash/CRC/Maglev/string-loop counts 0.
25. `corpus/build/tetragon/bpf_fork.o`: all target hash/CRC/Maglev/string-loop counts 0.
26. `corpus/build/tetragon/bpf_fork_v310.o`: all target hash/CRC/Maglev/string-loop counts 0.
27. `corpus/build/tetragon/bpf_fork_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
28. `corpus/build/tetragon/bpf_generic_fentry.o`: all target hash/CRC/Maglev/string-loop counts 0.
29. `corpus/build/tetragon/bpf_generic_fentry_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
30. `corpus/build/tetragon/bpf_generic_fentry_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
31. `corpus/build/tetragon/bpf_generic_fentry_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
32. `corpus/build/tetragon/bpf_generic_fexit.o`: all target hash/CRC/Maglev/string-loop counts 0.
33. `corpus/build/tetragon/bpf_generic_fexit_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
34. `corpus/build/tetragon/bpf_generic_fexit_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
35. `corpus/build/tetragon/bpf_generic_fexit_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
36. `corpus/build/tetragon/bpf_generic_kprobe.o`: all target hash/CRC/Maglev/string-loop counts 0.
37. `corpus/build/tetragon/bpf_generic_kprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
38. `corpus/build/tetragon/bpf_generic_kprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
39. `corpus/build/tetragon/bpf_generic_kprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
40. `corpus/build/tetragon/bpf_generic_lsm_core.o`: all target hash/CRC/Maglev/string-loop counts 0.
41. `corpus/build/tetragon/bpf_generic_lsm_core_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
42. `corpus/build/tetragon/bpf_generic_lsm_core_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
43. `corpus/build/tetragon/bpf_generic_lsm_ima_bprm_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
44. `corpus/build/tetragon/bpf_generic_lsm_ima_bprm_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
45. `corpus/build/tetragon/bpf_generic_lsm_ima_file_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
46. `corpus/build/tetragon/bpf_generic_lsm_ima_file_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
47. `corpus/build/tetragon/bpf_generic_lsm_output.o`: all target hash/CRC/Maglev/string-loop counts 0.
48. `corpus/build/tetragon/bpf_generic_lsm_output_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
49. `corpus/build/tetragon/bpf_generic_lsm_output_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
50. `corpus/build/tetragon/bpf_generic_rawtp.o`: all target hash/CRC/Maglev/string-loop counts 0.
51. `corpus/build/tetragon/bpf_generic_rawtp_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
52. `corpus/build/tetragon/bpf_generic_rawtp_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
53. `corpus/build/tetragon/bpf_generic_rawtp_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
54. `corpus/build/tetragon/bpf_generic_retkprobe.o`: all target hash/CRC/Maglev/string-loop counts 0.
55. `corpus/build/tetragon/bpf_generic_retkprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
56. `corpus/build/tetragon/bpf_generic_retkprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
57. `corpus/build/tetragon/bpf_generic_retkprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
58. `corpus/build/tetragon/bpf_generic_retuprobe.o`: all target hash/CRC/Maglev/string-loop counts 0.
59. `corpus/build/tetragon/bpf_generic_retuprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
60. `corpus/build/tetragon/bpf_generic_retuprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
61. `corpus/build/tetragon/bpf_generic_retuprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
62. `corpus/build/tetragon/bpf_generic_tracepoint.o`: all target hash/CRC/Maglev/string-loop counts 0.
63. `corpus/build/tetragon/bpf_generic_tracepoint_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
64. `corpus/build/tetragon/bpf_generic_tracepoint_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
65. `corpus/build/tetragon/bpf_generic_tracepoint_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
66. `corpus/build/tetragon/bpf_generic_uprobe.o`: all target hash/CRC/Maglev/string-loop counts 0.
67. `corpus/build/tetragon/bpf_generic_uprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
68. `corpus/build/tetragon/bpf_generic_uprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
69. `corpus/build/tetragon/bpf_generic_uprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
70. `corpus/build/tetragon/bpf_generic_usdt.o`: all target hash/CRC/Maglev/string-loop counts 0.
71. `corpus/build/tetragon/bpf_generic_usdt_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
72. `corpus/build/tetragon/bpf_generic_usdt_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
73. `corpus/build/tetragon/bpf_generic_usdt_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
74. `corpus/build/tetragon/bpf_loader.o`: all target hash/CRC/Maglev/string-loop counts 0.
75. `corpus/build/tetragon/bpf_loader_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
76. `corpus/build/tetragon/bpf_lseek.o`: all target hash/CRC/Maglev/string-loop counts 0.
77. `corpus/build/tetragon/bpf_lseek_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
78. `corpus/build/tetragon/bpf_map_test_p1.o`: all target hash/CRC/Maglev/string-loop counts 0.
79. `corpus/build/tetragon/bpf_map_test_p2.o`: all target hash/CRC/Maglev/string-loop counts 0.
80. `corpus/build/tetragon/bpf_map_test_p3.o`: all target hash/CRC/Maglev/string-loop counts 0.
81. `corpus/build/tetragon/bpf_multi_enforcer.o`: all target hash/CRC/Maglev/string-loop counts 0.
82. `corpus/build/tetragon/bpf_multi_kprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
83. `corpus/build/tetragon/bpf_multi_kprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
84. `corpus/build/tetragon/bpf_multi_kprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
85. `corpus/build/tetragon/bpf_multi_retkprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
86. `corpus/build/tetragon/bpf_multi_retkprobe_v53.o`: all target hash/CRC/Maglev/string-loop counts 0.
87. `corpus/build/tetragon/bpf_multi_retkprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
88. `corpus/build/tetragon/bpf_multi_retuprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
89. `corpus/build/tetragon/bpf_multi_retuprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
90. `corpus/build/tetragon/bpf_multi_uprobe_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
91. `corpus/build/tetragon/bpf_multi_uprobe_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
92. `corpus/build/tetragon/bpf_multi_usdt_v511.o`: all target hash/CRC/Maglev/string-loop counts 0.
93. `corpus/build/tetragon/bpf_multi_usdt_v61.o`: all target hash/CRC/Maglev/string-loop counts 0.
94. `corpus/build/tetragon/bpf_prog_iter.o`: all target hash/CRC/Maglev/string-loop counts 0.

## Appendix 2. Pattern-specific Negative Evidence

### Direct CRC32C

1. Cilium direct CRC32C table-step loops: none.
2. Katran direct CRC32C table-step loops: none.
3. Tracee direct CRC32C table-step loops: none.
4. Tetragon direct CRC32C table-step loops: none.
5. OTel direct CRC32C table-step loops: none.
6. Cilium source mentions CRC32C only to avoid computing it in eBPF.
7. Katran source grep did not find CRC32/CRC32C BPF code.
8. OTel BPF source grep did not find CRC32/CRC32C BPF code.
9. Tracee object strings did not show direct CRC code in the loaded object.
10. Tetragon object strings did not show direct CRC code in the loaded objects.

### Jenkins

1. Cilium Jenkins evidence is concrete and compiled.
2. Cilium Jenkins source is tuple hashing in `lib/hash.h`.
3. Cilium Jenkins compiled locations are `bpf_overlay.bpf.o` and `bpf_xdp.bpf.o`.
4. Katran Jenkins evidence is concrete and compiled.
5. Katran Jenkins source is `get_packet_hash`.
6. Katran Jenkins compiled location is `balancer.bpf.o`.
7. Tracee Jenkins evidence: none.
8. Tetragon Jenkins evidence: none.
9. OTel Jenkins evidence: none.
10. Broad Jenkins macro bodies: 30.
11. True Jenkins mix bodies: 15.
12. True Jenkins final bodies: 15.

### Murmur

1. Tracee Murmur evidence is concrete and compiled.
2. Tracee `murmur32` has one loop body.
3. Tracee `murmur32` also has fixed tail/finalization logic.
4. Tracee `hash_u32_and_u64` has fixed Murmur-style rounds.
5. Tracee `hash_task_id` has fixed Murmur-style rounds.
6. Cilium Murmur evidence: none.
7. Katran Murmur evidence: none.
8. Tetragon Murmur evidence: none.
9. OTel loaded BPF Murmur evidence: none.
10. Murmur is not CRC32.

### djb2/FNV/SipHash

1. Cilium djb2 evidence: none.
2. Cilium FNV evidence: none.
3. Cilium SipHash evidence: none.
4. Katran djb2 evidence: none.
5. Katran FNV evidence: none.
6. Katran SipHash evidence: none.
7. Tracee djb2 evidence: none.
8. Tracee FNV evidence: none.
9. Tracee SipHash evidence: none.
10. Tetragon djb2 evidence: none.
11. Tetragon FNV evidence: none.
12. Tetragon SipHash evidence: none.
13. OTel loaded BPF djb2 evidence: none.
14. OTel loaded BPF FNV evidence: none.
15. OTel loaded BPF SipHash evidence: none.
16. OTel userspace Go FNV/CRC references are not BPF kop targets.

### Maglev

1. Cilium Maglev lookup path exists.
2. Cilium Maglev permutation loop in BPF: none.
3. Katran Maglev ring lookup exists.
4. Katran Maglev permutation loop in BPF: none.
5. Tracee Maglev evidence: none.
6. Tetragon Maglev evidence: none.
7. OTel Maglev evidence: none.

### memcmp/string-equality

1. Cilium source has constant-length value `memcmp`.
2. Cilium compiled dynamic byte compare loop: none.
3. Katran source has four-word IPv6 equality.
4. Katran compiled dynamic byte compare loop: none.
5. Tracee object strings mention path and cgroup filters.
6. Tracee confirmed dynamic byte compare loop: none.
7. Tetragon object strings mention string-prefix maps.
8. Tetragon confirmed dynamic byte compare loop: none.
9. OTel confirmed dynamic byte compare loop: none.
10. No string kop is justified by this evidence.

## Appendix 3. Site Count Surprises

1. Cilium's Jenkins concentration is real but narrow.
2. Cilium has 27 Jenkins macro bodies if mix and final are counted together.
3. Those Cilium bodies are concentrated in only two objects.
4. `bpf_xdp.bpf.o` has the larger Cilium share.
5. `bpf_overlay.bpf.o` has the smaller Cilium share.
6. Katran's production BPF does less hash work than expected.
7. Katran has only one true Jenkins mix site in the scanned objects.
8. Katran's Maglev permutation is not in BPF.
9. Tracee has Murmur32 code but not a large family of filename/path hash loops.
10. Tracee's string/path filtering names do not translate into confirmed byte-loop hash sites.
11. Tetragon's 94 objects did not reveal the expected string hashing or byte-loop equality hot spots.
12. OTel profiler stack symbol hashing appears outside the loaded BPF objects in this artifact set.
13. The production-corpus CRC32 count is lower than the old loxilb-centered intuition.
14. The strongest "hash" opportunity is still mostly a rotate opportunity.

## Appendix 4. Implementation Priority Matrix

| family | static sites | semantic risk | module difficulty | pass difficulty | priority |
| --- | ---: | --- | --- | --- | --- |
| CRC32C direct scalar | 0 | low if exact | medium | medium | no |
| PCLMULQDQ buffer CRC/hash | 0 | high | high | high | no |
| Jenkins mix only | 15 | medium-high | high | high | no |
| Jenkins mix+final broad family | 30 | medium-high | high | high | second-priority only after rotate32 data |
| Murmur32 round | 8 signatures, 1 loop | medium | medium | medium | no |
| djb2/FNV/SipHash | 0 | medium | medium | medium | no |
| Maglev permutation | 0 | high | high | high | no |
| memcmp/string loop | 0 confirmed | high | high | high | no |

## Appendix 5. Final Answer to the Research Question

1. The prior CRC32 study did not miss a production-corpus CRC32 opportunity.
2. The prior CRC32 study did not count Jenkins/Murmur because those are not CRC32.
3. Counting Jenkins/Murmur now still does not produce a strong hash-kop case.
4. CRC32/PCLMULQDQ should not be implemented for cilium, katran, tracee, tetragon, or otelcol on current evidence.
5. A Jenkins-specific pass is below the primary threshold and has poor ABI shape.
6. A Murmur-specific pass is below threshold and mostly overlaps rotate32.
7. Maglev and string compare should remain out of scope.
8. The next useful action is post-rotate32 measurement of Cilium Jenkins-heavy objects and Tracee `murmur32`.
