# Value-Stability map_inline Redesign: BPF-side Read-Only Criterion

## Scope and Ground Rules

1. This is a read-only investigation document.
2. No benchmark run was started.
3. No daemon process was spawned.
4. No kernel source was changed.
5. `vendor/linux-framework/` was read only for verifier/JIT risk references.
6. Invalidation, ReJIT-back-on-write, userspace mutation handling, and v1 tracker history are intentionally out of scope.
7. The output is limited to the proposed static criterion: no live BPF program writes the map.
8. The current framework must not filter programs out of ReJIT; failures surface in results instead of exclusions (`CLAUDE.md:5`).
9. Benchmark apps must load BPF through real application startup, not framework-side `.bpf.o` loaders (`CLAUDE.md:12`).
10. Framework code must collect raw counter measurements only and must not compute aggregation or summaries (`CLAUDE.md:15`).
11. The v3 daemon owns per-pass orchestration but every bytecode transform remains a separate `bpfopt --pass <name>` CLI invocation (`CLAUDE.md:86`).
12. The v3 daemon invokes `bpfopt` externally and calls kernel ReJIT through `kernel-sys` (`CLAUDE.md:96`).
13. Runner Python is the stable socket/JSON boundary during v3 migration (`CLAUDE.md:96`).
14. Standalone CLI crates must not depend on each other at compile time (`CLAUDE.md:103`).
15. `kernel-sys` is the only crate that may directly issue BPF syscalls (`CLAUDE.md:118`).
16. `docs/tmp/bpfopt_design_v3.md` is named as authoritative for bpfopt-suite in the repo-facing plan (`docs/kernel-jit-optimization-plan.md:43`).
17. The kernel optimization plan lists bpfopt-suite as a userspace optimization suite built around `bpfopt`, `bpfprof`, and the ReJIT daemon (`docs/kernel-jit-optimization-plan.md:128`).
18. The kernel optimization plan says runner Python remains stable during v3 migration (`docs/kernel-jit-optimization-plan.md:407`).
19. The kernel optimization plan repeats fail-fast behavior for missing verifier features and failed steps (`docs/kernel-jit-optimization-plan.md:409`).
20. The current pass registry marks `map_inline` as requiring verifier states and map values, and as producing verifier states (`bpfopt/crates/bpfopt/src/passes/mod.rs:81`).
21. The current CLI accepts `--verifier-states`, `--map-values`, and `--map-ids` (`bpfopt/crates/bpfopt/src/main.rs:120`).
22. The current CLI requires all three inputs for `map_inline` (`bpfopt/crates/bpfopt/src/main.rs:421`).
23. The current runner plan generator already adds `--map-values` and `--map-ids` for passes whose metadata needs map values (`runner/libs/rejit_plan.py:78`).

## Executive Result

24. The proposed contract is directionally useful, but the profitable subset is narrower than the wording first suggests.
25. The static criterion "no live BPF program writes this map" can safely widen candidates from constant-key-only to runtime-key lookup sites.
26. That widening only helps when the replacement can preserve lookup miss semantics.
27. For runtime keys, "all entries identical value" cannot blindly become a constant load on HASH or LPM_TRIE maps.
28. A HASH lookup with a runtime key still needs membership testing because `bpf_map_lookup_elem()` returns NULL on a missing key.
29. The safe runtime-key form is an if/else membership chain over snapshot keys.
30. If all matched entries have identical values, the matched arm can load the same constants, but the chain is still needed unless the key domain is proven total.
31. The pointer question is the hardest correctness issue.
32. `BPF_PSEUDO_MAP_VALUE` creates verifier-tracked map-value pointers only for fixed map-value addresses accepted by the verifier (`vendor/linux-framework/kernel/bpf/verifier.c:18105`).
33. It is not a general mechanism for fabricating a pointer to an arbitrary HASH snapshot entry.
34. Therefore the minimum safe new path should scalarize fixed value loads rather than synthesize a general `r0` pointer.
35. The existing pass already has a use classifier that looks for removable lookup/null-check patterns and fixed scalar loads (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:978`).
36. The existing pass already rewrites direct pseudo-map-value loads for the constant-key case (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1664`).
37. The new pass should keep the constant-key path and add a runtime-key path only when post-lookup uses are scalarizable.
38. Empirically, Katran has the cleanest hot unlock: `vip_map` has 4 lookup sites, no direct write-helper target in the object scan, and the corpus runner populates one VIP (`runner/libs/app_runners/katran.py:613`).
39. Cilium has many helper-read-only maps, but the hot service/backend/IP policy maps are large by declared capacity, so the small-chain unlock is likely concentrated in small control/filter maps.
40. Tracee has many skipped current sites, but most are map-in-map outer lookups, ARRAY/PERCPU_ARRAY scratch/config maps, or BPF-written state maps.
41. Tetragon has very high lookup counts, but most are ARRAY/PERCPU_ARRAY/map-in-map or BPF-written state; its small read-only HASH unlock is low.
42. Otel has a possible `interpreter_offsets` candidate if the live entry count is <= 10, but its declared max is 32 and several maps are directly mutated.
43. Realistic corpus geomean upper bound from this redesign alone is about 0.3% to 1.5%.
44. A very optimistic upper bound is about 2% to 3% if Cilium snapshots show hot small HASH/LPM maps and scalarization succeeds.
45. The expected hot-path unlock is small unless the daemon can prove small live entry counts for Cilium service/filter maps and the pass can scalarize their value uses.

## Current Contract

46. The current contract is effectively `key=const && value=snapshot-known -> const result load`.
47. The current pass locates map lookup helper calls by scanning instructions (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:133`).
48. The current pass then iterates lookup sites through a pass loop (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:728`).
49. The pass resolves map metadata from canonical map IDs and verifier states (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:803`).
50. Unsupported map types are skipped with diagnostics rather than rewritten (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:914`).
51. Constant key extraction is called before the current rewrite is built (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:933`).
52. The direct value rewrite uses a pseudo-map-value load, map offset, and fixed scalar load replacements (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1664`).
53. The current metadata model stores only map type, key size, value size, max entries, and map ID (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:29`).
54. The current map support table allows ARRAY, PERCPU_ARRAY, HASH, and LRU_HASH for direct value access (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:37`).
55. The current support table excludes PERCPU_HASH from direct pseudo-map-value access (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:44`).
56. The current support table treats ARRAY_OF_MAPS and HASH_OF_MAPS as map-in-map (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:64`).
57. The current extractor requires verifier state at the lookup call PC (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:324`).
58. The current extractor requires all verifier state occurrences at the PC to agree (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:364`).
59. A current test asserts there is no non-verifier fallback after a first-round rewrite (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1762`).
60. The deep dive found helper-style map lookups had no successful current rewrites (`docs/tmp/map_inline_deepdive_20260505.md:41`).
61. The deep dive states the current direct path works only for constant-key verifier state and map values (`docs/tmp/map_inline_deepdive_20260505.md:69`).
62. The deep dive states the helper-call path is matched but all observed helper sites were skipped by the current constraints (`docs/tmp/map_inline_deepdive_20260505.md:74`).
63. The deep dive records Cilium as having many current direct-map successes but no helper lookup successes (`docs/tmp/map_inline_deepdive_20260505.md:182`).
64. The deep dive records Katran as having 68 helper lookup sites and zero current map_inline applications (`docs/tmp/map_inline_deepdive_20260505.md:183`).
65. The Cilium/Katran design note concluded that a broad "inline all lookups" design was not justified under the older framing (`docs/tmp/map_inline_cilium_katran_design_20260506.md:1048`).
66. This document reframes the target to the narrower BPF-side read-only condition and reaches a more selective recommendation.

## Proposed Contract Refinement

67. The proposed criterion is static: scan live BPF bytecode and prove no live BPF program writes the target map.
68. The daemon has access to a per-program snapshot function that reads original bytecode and map IDs (`daemon/src/bpf.rs:68`).
69. The daemon already reads a program's `used_maps` through `kernel_sys::prog_map_ids` (`daemon/src/bpf.rs:131`).
70. `kernel-sys` already exposes live program enumeration via `prog_get_next_id` (`bpfopt/crates/kernel-sys/src/lib.rs:478`).
71. `kernel-sys` already exposes open-by-program-ID via `prog_get_fd_by_id` and `prog_try_get_fd_by_id` (`bpfopt/crates/kernel-sys/src/lib.rs:492`).
72. `kernel-sys` already exposes referenced map IDs for an open program fd (`bpfopt/crates/kernel-sys/src/lib.rs:620`).
73. The daemon therefore does not need a new syscall boundary for live-program enumeration.
74. The daemon does need new analysis code to combine live program enumeration, bytecode scan, map-id binding, and direct map-value store detection.
75. A helper-only scan is insufficient for the true criterion.
76. Katran increments `stats` through direct stores after `bpf_map_lookup_elem` (`runner/repos/katran/katran/lib/bpf/balancer.bpf.c:41`).
77. Katran updates `stats` fields through returned map-value pointers in the XDP path (`runner/repos/katran/katran/lib/bpf/balancer.bpf.c:1039`).
78. Cilium increments metrics through a returned map-value pointer (`runner/repos/cilium/bpf/lib/metrics.h:58`).
79. Otel increments the `metrics` map through a returned map-value pointer (`runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:47`).
80. The write proof must reject both explicit update/delete helpers and direct stores through `PTR_TO_MAP_VALUE`.
81. The write proof should also reject callback-driven writes when a helper such as map iteration can call code that mutates values.
82. The user called out `bpf_for_each_map_elem` write callbacks; the helper ID exists in the kernel UAPI helper list but the production proof must bind callback effects to maps.
83. The production proof can start conservative: unknown callback effect means `bpf_writable=true`.
84. The proof must be fail-fast: missing bytecode, missing map IDs, parse errors, or unsupported helper/callback patterns should produce a hard error or an explicit non-inlineable status, not silent optimism (`CLAUDE.md:70`).
85. The side input should carry positive evidence, not hide maps from metadata.
86. Hiding maps before metadata would resemble filtering and would make missing proof less visible.
87. Current `MapInfo` comments say callers must filter maps out before constructing metadata if they do not want them inlined (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:22`).
88. For this redesign, an explicit `bpf_writable` field is better than pre-filtering because it preserves diagnostics and the no-filtering culture (`CLAUDE.md:5`).

## Snapshot Forms and Correctness

89. Form A is "all entries have identical value".
90. Form B is "small entry count, emit if/else chain over snapshot keys".
91. Form C is "large ARRAY, skip because kernel JIT already inlines array lookup".
92. Form D is "large HASH, skip because chain is too long".
93. Form E is "PERCPU_HASH where all CPU values are equal".
94. Form F is "small LPM_TRIE, emit longest-prefix chain".
95. Form A is only a full helper-call replacement without key comparison when miss semantics are impossible or irrelevant.
96. For HASH and LPM_TRIE with runtime keys, miss semantics remain relevant.
97. Therefore Form A should be implemented as "after membership match, load common value" for runtime HASH/LPM keys.
98. A pure unconditional constant value load is safe for an existing constant key known to be present.
99. A pure unconditional constant value load is also safe for a map whose key domain is provably total for the possible key values.
100. ARRAY maps may have totality when bounds are checked or verifier-proven, but these are already low value because kernel JIT handles common array lookup patterns.
101. The current pass already checks ARRAY out-of-range for constant keys (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:958`).
102. PERCPU_HASH equal-value collapse has the same miss-semantics problem as HASH.
103. PERCPU_HASH equal-value collapse can load constants on matched keys if the values are equal across CPUs and entries.
104. PERCPU_HASH cannot skip the key membership check for runtime keys unless totality is proven.
105. LPM_TRIE equal-value collapse can load constants on matched prefixes.
106. LPM_TRIE cannot skip the prefix-match chain because a key may match no prefix.
107. The rewrite must preserve the original NULL and non-NULL control flow.
108. If the original program immediately null-checks the lookup result, the no-match arm can jump to the original null path.
109. If the original program does not null-check and dereferences directly, the pass must be at least as conservative as the verifier: only scalarize safe fixed loads.
110. If the returned pointer escapes to a helper, subprogram, store, or pointer arithmetic pattern not understood by the pass, the runtime-key path should skip.
111. This matches the current pass's conservative use classification around R0 and null checks (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:978`).

## Latest Result Sources

112. Latest multi-app corpus result used for Cilium, Katran, Tetragon, and Otel: `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`.
113. That result was generated at `2026-05-05T18:06:47.519134+00:00`.
114. Latest Tracee result with map_inline data used here: `corpus/results/x86_kvm_corpus_20260506_064719_038586/details/result.json`.
115. That Tracee result was generated at `2026-05-06T06:55:28.838996+00:00`.
116. Successful per-step workdirs are temporary in the daemon path; the command code tars workdirs only for failure/error cases (`daemon/src/commands.rs:490`).
117. The daemon writes `map-values.json` into the per-step workdir when a program references maps (`daemon/src/commands.rs:545`).
118. The daemon writes map snapshot metadata and entries into `map-values.json` (`daemon/src/commands.rs:1025`).
119. Because successful workdirs are not retained, runtime map IDs and entry snapshots are not available for most successful latest-result sites.
120. The empirical tables below therefore use ELF map names and BTF metadata from `.bpf.o` artifacts, plus runner/source estimates for entry counts.
121. Where a runtime map ID is unavailable, the table says `not retained`.
122. This is an artifact retention limitation, not a pass correctness condition.
123. Production v3 implementation will have runtime map IDs in the daemon at pass time through `snapshot_program` and `canonicalize_for_prog` (`daemon/src/bpf.rs:68`, `daemon/src/bpf.rs:278`).

## Static Object Scan Method

124. I scanned BPF objects in `corpus/build/<app>/` with `llvm-objdump -dr --no-show-raw-insn`.
125. I read map BTF with `bpftool btf dump file ... format raw`.
126. I associated a helper call with a map relocation when the nearest preceding `R_BPF_64_64` map relocation was within 12 BPF instructions.
127. The scan tracked helper IDs for lookup, update, delete, and map iteration.
128. The scan separately counted dynamic/no-close-map helper calls where no nearby relocation identifies the map.
129. Dynamic calls matter for map-in-map and helper calls through map pointers.
130. The scan is conservative for eligibility estimates.
131. The scan is not a complete implementation of `bpf_writable`.
132. The scan does not fully prove direct map-value stores.
133. Direct map-value stores are specifically called out in source examples above and must be included in production.
134. The scan does not prove callback write effects.
135. Unknown callback effects must conservatively mark the target map writable.
136. Entry counts were not retained in successful map-values artifacts, so estimates use runner setup and max_entries.
137. The daemon already has `map_get_next_key` for map snapshot enumeration (`bpfopt/crates/kernel-sys/src/lib.rs:869`).
138. The daemon command currently iterates map keys while writing map-values snapshots (`daemon/src/commands.rs:1025`).
139. Adding exact `entry_count` to side input is a small schema extension, not a new data source.
140. Adding `all_values_equal` is likewise computed from the same snapshot entries.
141. Adding `bpf_writable` needs the live-program global analysis above.

## Part A: Cilium Latest Result

142. Cilium app label in the latest multi-app result: `cilium/agent`.
143. Cilium status in that result: `ok`.
144. Cilium had 25 map_inline pass attempts.
145. Cilium had 342 current map_inline matched sites.
146. Cilium had 279 current map_inline applied sites.
147. Cilium had 63 current map_inline skipped sites.
148. Cilium pass statuses were 22 ok, 2 skipped_missing_states, and 1 failed_rejit.
149. Current skip reasons were dominated by unsupported map types and key-state failures.
150. The current successes are mostly direct constant-key map-value loads, not helper-call runtime-key rewrites.
151. The deep dive reports Cilium as the largest current success case for direct-map rewriting (`docs/tmp/map_inline_deepdive_20260505.md:182`).
152. The new contract targets the remaining helper-call sites where map contents are BPF-side read-only.

## Cilium Helper-Referenced Map Table

153. Table fields: ELF map, runtime map ID, type, key bytes, value bytes, max entries, lookup sites, direct write helpers, entry estimate, category.
154. `direct write helpers` means update/delete/helper writes with a direct map relocation in the object scan.
155. It does not include direct stores through returned map-value pointers; those are discussed in notes.
156. `not retained` means the successful result did not keep the runtime map-values workdir.
157. `cilium_metrics` | not retained | PERCPU_HASH | 8 | 16 | 65536 | lookups 540 | helper writes 528 | entry count unknown | reject: BPF-written.
158. `cilium_xdp_scratch` | not retained | PERCPU_ARRAY | unknown | unknown | 1 | lookups 145 | helper writes 0 | entry count 1 | skip: ARRAY/PERCPU_ARRAY already JIT-friendly and scratch pointer semantics.
159. `cilium_ipcache_v2` | not retained | LPM_TRIE | 24 | 24 | 512000 | lookups 124 | helper writes 0 | entry count likely large | skip unless live snapshot <= 10.
160. `cilium_percpu_trace_id` | not retained | PERCPU_ARRAY | 4 | 8 | 1 | lookups 114 | helper writes 0 | entry count 1 | skip: array-like.
161. `cilium_ratelimit` | not retained | LRU_HASH | 8 | 16 | 1024 | lookups 89 | helper writes 89 | entry count dynamic | reject: BPF-written.
162. `cilium_ratelimit_metrics` | not retained | HASH | 4 | 8 | 64 | lookups 89 | helper writes 89 | entry count dynamic | reject: BPF-written.
163. `cilium_lb4_services_v2` | not retained | HASH | 12 | 12 | 65536 | lookups 70 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
164. `cilium_devices` | not retained | ARRAY | 4 | 16 | 4096 | lookups 62 | helper writes 0 | entry count unknown | kernel-already-inlined ARRAY.
165. `cilium_snat_v6_external` | not retained | LRU_HASH | 38 | 56 | 524288 | lookups 57 | helper writes 375 | entry count dynamic | reject: BPF-written.
166. `cilium_policy_v2` | not retained | LPM_TRIE | 12 | 12 | 16384 | lookups 54 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
167. `cilium_ipv6_frag_datagrams` | not retained | LRU_HASH | 40 | 4 | 8192 | lookups 53 | helper writes 53 | entry count dynamic | reject: BPF-written.
168. `cilium_lb6_services_v2` | not retained | HASH | 24 | 12 | 65536 | lookups 46 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
169. `cilium_ipv4_frag_datagrams` | not retained | LRU_HASH | 12 | 4 | 8192 | lookups 43 | helper writes 43 | entry count dynamic | reject: BPF-written.
170. `cilium_policystats` | not retained | LRU_PERCPU_HASH | 12 | 16 | 200 | lookups 36 | helper writes 36 | entry count dynamic | reject: BPF-written.
171. `cilium_snat_v4_external` | not retained | LRU_HASH | 14 | 40 | 524288 | lookups 36 | helper writes 190 | entry count dynamic | reject: BPF-written.
172. `cilium_lxc` | not retained | HASH | 20 | 48 | 65536 | lookups 35 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
173. `cilium_lb4_backends_v3` | not retained | HASH | 4 | 12 | 65536 | lookups 28 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
174. `cilium_lb6_backends_v3` | not retained | HASH | 4 | 24 | 65536 | lookups 24 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
175. `cilium_runtime_config` | not retained | ARRAY | 4 | 8 | 256 | lookups 22 | helper writes 0 | entry count unknown | kernel-already-inlined ARRAY.
176. `cilium_node_map_v2` | not retained | HASH | 20 | 4 | 16384 | lookups 21 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
177. `cilium_snat_v6_alloc_retries` | not retained | PERCPU_ARRAY | 4 | 4 | 33 | lookups 20 | helper writes 0 | entry count unknown | skip: array-like.
178. `ipv6_nat_entry_storage` | not retained | PERCPU_ARRAY | 4 | 56 | 1 | lookups 20 | helper writes 0 | entry count 1 | skip: scratch storage.
179. `cilium_lb6_reverse_nat` | not retained | HASH | 2 | 18 | 65536 | lookups 19 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
180. `cilium_auth_map` | not retained | HASH | 12 | 8 | 524288 | lookups 18 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
181. `cilium_ct_any6_global` | not retained | LRU_HASH | 38 | 56 | 4096 | lookups 17 | helper writes 9 | entry count dynamic | reject: BPF-written.
182. `cilium_ct_any4_global` | not retained | LRU_HASH | 14 | 56 | 4096 | lookups 16 | helper writes 8 | entry count dynamic | reject: BPF-written.
183. `cilium_lb_affinity_match` | not retained | HASH | 8 | 1 | 65536 | lookups 16 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
184. `ipv6_ct_tuple_storage` | not retained | PERCPU_ARRAY | 4 | 38 | 1 | lookups 15 | helper writes 0 | entry count 1 | skip: scratch storage.
185. `cilium_lb4_reverse_nat` | not retained | HASH | 2 | 6 | 65536 | lookups 14 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
186. `cilium_snat_v4_alloc_retries` | not retained | PERCPU_ARRAY | 4 | 4 | 33 | lookups 14 | helper writes 0 | entry count unknown | skip: array-like.
187. `ct_tuple_storage` | not retained | PERCPU_ARRAY | 4 | 38 | 1 | lookups 13 | helper writes 0 | entry count 1 | skip: scratch storage.
188. `nat_target_storage` | not retained | PERCPU_ARRAY | 4 | 28 | 1 | lookups 13 | helper writes 0 | entry count 1 | skip: scratch storage.
189. `cilium_egress_gw_policy_v6` | not retained | LPM_TRIE | 36 | 40 | 16384 | lookups 12 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
190. `cilium_lb4_affinity` | not retained | LRU_HASH | 16 | 16 | 65536 | lookups 9 | helper writes 18 | entry count dynamic | reject: BPF-written.
191. `cilium_nodeport_neigh6` | not retained | LRU_HASH | 16 | 8 | 524288 | lookups 9 | helper writes 4 | entry count dynamic | reject: BPF-written.
192. `cilium_throttle` | not retained | HASH | 8 | 56 | 65535 | lookups 9 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
193. `cilium_lb4_maglev` | not retained | HASH_OF_MAPS | 2 | 4 | 65536 | lookups 8 | helper writes 0 | entry count unknown | skip: map-in-map.
194. `cilium_lb6_maglev` | not retained | HASH_OF_MAPS | 2 | 4 | 65536 | lookups 8 | helper writes 0 | entry count unknown | skip: map-in-map.
195. `cilium_subnet_map` | not retained | LPM_TRIE | 24 | 4 | 1024 | lookups 8 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
196. `trace_ctx_storage` | not retained | PERCPU_ARRAY | 4 | 8 | 1 | lookups 8 | helper writes 0 | entry count 1 | skip: scratch storage.
197. `__config_debug_lb` | not retained | unknown config | unknown | unknown | unknown | lookups 7 | helper writes 0 | entry count unknown | skip pending metadata.
198. `cilium_lb6_affinity` | not retained | LRU_HASH | 24 | 16 | 65536 | lookups 7 | helper writes 14 | entry count dynamic | reject: BPF-written.
199. `cilium_egress_gw_policy_v4` | not retained | LPM_TRIE | 12 | 8 | 16384 | lookups 6 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
200. `cilium_lb4_reverse_sk` | not retained | LRU_HASH | 16 | 8 | 262144 | lookups 6 | helper writes 8 | entry count dynamic | reject: BPF-written.
201. `cilium_ipmasq_v6` | not retained | LPM_TRIE | 20 | 1 | 16384 | lookups 5 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
202. `cilium_per_cluster_ct_any4` | not retained | ARRAY_OF_MAPS | 4 | 4 | 256 | lookups 5 | helper writes 0 | entry count unknown | skip: map-in-map.
203. `cilium_per_cluster_snat_v4_external` | not retained | ARRAY_OF_MAPS | 4 | 4 | 256 | lookups 5 | helper writes 0 | entry count unknown | skip: map-in-map.
204. `cilium_skip_lb4` | not retained | HASH | 16 | 1 | 100 | lookups 5 | helper writes 0 | entry count likely small | if/else chain if snapshot <= 10.
205. `cilium_tail_call_buffer4` | not retained | PERCPU_ARRAY | 4 | 60 | 1 | lookups 5 | helper writes 5 | entry count 1 | reject: BPF-written scratch.
206. `cilium_tail_call_buffer6` | not retained | PERCPU_ARRAY | 4 | 96 | 1 | lookups 5 | helper writes 5 | entry count 1 | reject: BPF-written scratch.
207. `cilium_l2_responder_v4` | not retained | HASH | 8 | 8 | 4096 | lookups 4 | helper writes 0 | entry count unknown | skip unless live snapshot <= 10.
208. `cilium_lb4_source_range` | not retained | LPM_TRIE | 12 | 1 | 1000 | lookups 4 | helper writes 0 | entry count unknown | if/else LPM only if snapshot <= 10.
209. `cilium_lb6_source_range` | not retained | LPM_TRIE | 24 | 1 | 1000 | lookups 4 | helper writes 0 | entry count unknown | if/else LPM only if snapshot <= 10.
210. `cilium_nodeport_neigh4` | not retained | LRU_HASH | 4 | 8 | 524288 | lookups 4 | helper writes 4 | entry count dynamic | reject: BPF-written.
211. `cilium_vtep_map` | not retained | HASH | 4 | 16 | 8 | lookups 4 | helper writes 0 | entry count <= 8 | if/else chain candidate.
212. `cilium_lb6_reverse_sk` | not retained | LRU_HASH | 32 | 20 | 262144 | lookups 3 | helper writes 4 | entry count dynamic | reject: BPF-written.
213. `cilium_skip_lb6` | not retained | HASH | 32 | 1 | 100 | lookups 3 | helper writes 0 | entry count likely small | if/else chain if snapshot <= 10.
214. `cilium_srv6_policy_v4` | not retained | LPM_TRIE | 12 | 16 | 16384 | lookups 3 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.
215. `cilium_srv6_vrf_v4` | not retained | LPM_TRIE | 12 | 4 | 16384 | lookups 3 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.
216. `cilium_l2_responder_v6` | not retained | HASH | 24 | 8 | 4096 | lookups 2 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.
217. `cilium_mcast_group_outer_v4_map` | not retained | HASH_OF_MAPS | 4 | 4 | 1024 | lookups 2 | helper writes 0 | entry count unknown | skip: map-in-map.
218. `cilium_nodeport_nat_buffer` | not retained | PERCPU_ARRAY | 4 | 18 | 1 | lookups 2 | helper writes 2 | entry count 1 | reject: BPF-written scratch.
219. `fib_params_storage` | not retained | PERCPU_ARRAY | 4 | 68 | 1 | lookups 2 | helper writes 0 | entry count 1 | skip: scratch storage.
220. `cilium_cidr_v4_dyn` | not retained | LPM_TRIE | 8 | 1 | 1024 | lookups 1 | helper writes 0 | entry count unknown | LPM chain if snapshot <= 10.
221. `cilium_cidr_v4_fix` | not retained | HASH | 8 | 1 | 1024 | lookups 1 | helper writes 0 | entry count unknown | if/else if snapshot <= 10.
222. `cilium_cidr_v6_dyn` | not retained | LPM_TRIE | 20 | 1 | 1024 | lookups 1 | helper writes 0 | entry count unknown | LPM chain if snapshot <= 10.
223. `cilium_cidr_v6_fix` | not retained | HASH | 20 | 1 | 1024 | lookups 1 | helper writes 0 | entry count unknown | if/else if snapshot <= 10.
224. `cilium_encrypt_state` | not retained | ARRAY | 4 | 1 | 1 | lookups 1 | helper writes 0 | entry count 1 | kernel-already-inlined ARRAY.
225. `cilium_ipmasq_v4` | not retained | LPM_TRIE | 8 | 1 | 16384 | lookups 1 | helper writes 0 | entry count unknown | LPM chain if snapshot <= 10.
226. `cilium_srv6_policy_v6` | not retained | LPM_TRIE | 24 | 16 | 16384 | lookups 1 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.
227. `cilium_srv6_sid` | not retained | HASH | 16 | 4 | 16384 | lookups 1 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.
228. `cilium_srv6_vrf_v6` | not retained | LPM_TRIE | 36 | 4 | 16384 | lookups 1 | helper writes 0 | entry count unknown | skip unless snapshot <= 10.

## Cilium Category Estimate

229. Cilium current candidate baseline is 342 matched current map_inline sites.
230. Cilium current applied count is 279, already mostly direct constant-key loads.
231. Helper-read-only by direct helper scan is large, but true BPF-side read-only must reject direct value stores.
232. BPF-written examples include `cilium_metrics`, where the source both increments existing values and updates missing values (`runner/repos/cilium/bpf/lib/metrics.h:58`).
233. Cilium all-values-equal form without membership check: likely zero safe HASH/LPM runtime-key sites.
234. Cilium all-values-equal matched-arm scalarization: possible if live snapshots show equal values, but no retained snapshots prove this.
235. Cilium if/else chain with max_entries <= 10: `cilium_vtep_map` gives 4 sites.
236. Cilium if/else chain with likely small entry count but max > 10: `cilium_skip_lb4`, `cilium_skip_lb6`, CIDR fix/dyn, source-range, and policy/LB maps need live snapshots.
237. Cilium kernel-already-inlined ARRAY category includes devices, runtime config, scratch, trace IDs, and one-entry storage maps.
238. Cilium too-many HASH category includes service, backend, LXC, node, auth, reverse NAT, affinity, and throttle maps unless live snapshot entry_count <= 10.
239. Conservative Cilium unlock estimate: 10 to 20 sites.
240. Snapshot-optimistic Cilium unlock estimate: 40 to 90 sites if the synthetic corpus loads only a handful of service/policy/LPM entries.
241. Hot-path confidence is moderate-low because the high-count maps are either large or BPF-written.

## Part A: Katran Latest Result

242. Katran app label in the latest multi-app result: `katran`.
243. Katran status in that result: `ok`.
244. Katran had 3 map_inline pass attempts.
245. Katran had 68 current map_inline matched sites.
246. Katran had 0 current map_inline applied sites.
247. Katran had 68 current map_inline skipped sites.
248. The deep dive records Katran as 68 matched helper sites and zero applications (`docs/tmp/map_inline_deepdive_20260505.md:183`).
249. Current Katran skip reasons are mostly key-state extraction failures.
250. This is the clearest app where runtime-key if/else scalarization changes the outcome.
251. The runner configures Katran maps before the workload through real app setup, preserving app-level loading constraints (`runner/libs/app_runners/katran.py:605`).
252. The runner sets `VIP_NUM = 0` and `REAL_NUM = 1` (`runner/libs/app_runners/katran.py:35`).
253. The runner updates one VIP entry in `vip_map` (`runner/libs/app_runners/katran.py:613`).
254. The runner updates one real server in `reals` (`runner/libs/app_runners/katran.py:616`).
255. The runner fills every `ch_rings` entry (`runner/libs/app_runners/katran.py:619`).

## Katran Helper-Referenced Map Table

256. `stats` | not retained | PERCPU_ARRAY | 4 | 16 | 1024 | lookups 33 | helper writes 0 | entry count active counters | reject true-read-only because direct stores mutate counters.
257. `reals` | not retained | ARRAY | 4 | 20 | 4096 | lookups 6 | helper writes 0 | entry count 1 configured | kernel-already-inlined ARRAY.
258. `server_id_stats` | not retained | PERCPU_ARRAY | 4 | 16 | 512 | lookups 4 | helper writes 0 | entry count unknown | skip: array-like stats.
259. `vip_map` | not retained | HASH | 20 | 8 | 512 | lookups 4 | helper writes 0 | entry count 1 configured | strong if/else chain candidate.
260. `vip_to_down_reals_map` | not retained | HASH_OF_MAPS | 20 | 4 | 512 | lookups 4 | helper writes 0 | entry count unknown | skip: map-in-map.
261. `ctl_array` | not retained | ARRAY | 4 | 8 | 16 | lookups 3 | helper writes 0 | entry count configured | kernel-already-inlined ARRAY.
262. `hc_ctrl_map` | not retained | ARRAY | 4 | 4 | 4 | lookups 3 | helper writes 0 | entry count small | kernel-already-inlined ARRAY.
263. `ch_rings` | not retained | ARRAY | 4 | 4 | 33554944 | lookups 2 | helper writes 0 | entry count huge | kernel-already-inlined ARRAY.
264. `hc_pckt_macs` | not retained | ARRAY | 4 | 6 | 2 | lookups 2 | helper writes 0 | entry count <= 2 | kernel-already-inlined ARRAY.
265. `hc_pckt_srcs_map` | not retained | ARRAY | 4 | 20 | 2 | lookups 2 | helper writes 0 | entry count <= 2 | kernel-already-inlined ARRAY.
266. `hc_reals_map` | not retained | HASH | 4 | 20 | 4096 | lookups 2 | helper writes 0 | entry count unknown | if/else only if snapshot <= 10.
267. `hc_stats_map` | not retained | PERCPU_ARRAY | 4 | 40 | 1 | lookups 2 | helper writes 0 | entry count 1 | skip: stats array.
268. `lru_mapping` | not retained | ARRAY_OF_MAPS | 4 | 4 | 128 | lookups 2 | helper writes 0 | entry count unknown | skip: map-in-map.
269. `lru_miss_stats` | not retained | PERCPU_ARRAY | 4 | 4 | 4096 | lookups 2 | helper writes 0 | entry count counters | skip/reject due stats semantics.
270. `quic_stats_map` | not retained | PERCPU_ARRAY | 4 | 104 | 1 | lookups 2 | helper writes 0 | entry count 1 | skip/reject due stats semantics.
271. `reals_stats` | not retained | PERCPU_ARRAY | 4 | 16 | 4096 | lookups 2 | helper writes 0 | entry count counters | reject true-read-only because direct stores mutate counters.
272. `server_id_map` | not retained | ARRAY | 4 | 4 | 16777214 | lookups 2 | helper writes 0 | entry count unknown | kernel-already-inlined ARRAY.
273. `vip_miss_stats` | not retained | ARRAY | 4 | 20 | 1 | lookups 2 | helper writes 0 | entry count 1 | kernel-already-inlined ARRAY.
274. `cntrs_array` | not retained | PERCPU_ARRAY | 4 | 8 | 512 | lookups 1 | helper writes 0 | entry count counters | skip: array-like stats.
275. `hc_key_map` | not retained | HASH | 20 | 4 | 512 | lookups 1 | helper writes 0 | entry count unknown | if/else only if snapshot <= 10.
276. `per_hckey_stats` | not retained | PERCPU_ARRAY | 4 | 8 | 512 | lookups 1 | helper writes 0 | entry count counters | skip: array-like stats.
277. Dynamic/no-close-map helper calls in Katran: lookup 3, update 4.
278. Katran dynamic updates target LRU inner maps through map-in-map pointers in source (`runner/repos/katran/katran/lib/bpf/balancer.bpf.c:166`).
279. Katran also updates existing LRU entries through returned map-value pointers (`runner/repos/katran/katran/lib/bpf/balancer.bpf.c:619`).
280. Those dynamic LRU maps are not safe under the read-only criterion.

## Katran Category Estimate

281. Katran all-values-equal unconditional form: no safe hot HASH site without membership check.
282. Katran `vip_map` if/else chain: 4 sites.
283. Katran `vip_map` entry count estimate: 1, from runner map setup (`runner/libs/app_runners/katran.py:613`).
284. Katran `vip_map` key size: 20 bytes, so comparison is a struct-key compare rather than one 64-bit compare.
285. Katran ARRAY category: `reals`, `ctl_array`, `hc_ctrl_map`, `ch_rings`, `hc_pckt_*`, `server_id_map`, and `vip_miss_stats`.
286. Katran HASH too-many/unknown category: `hc_reals_map` and `hc_key_map`, unless snapshots prove <= 10 entries.
287. Katran BPF-written/reject category: stats, reals_stats, LRU inner maps, and other counters with direct stores.
288. Conservative Katran unlock estimate: 4 sites.
289. Snapshot-optimistic Katran unlock estimate: 4 to 6 sites.
290. Katran hot-path value is better than the count suggests because `vip_map` is on the packet load-balancing path.
291. Katran macro gain is bounded because the array-heavy real selection path already benefits from kernel-side array handling.

## Part A: Tracee Latest Result

292. Tracee app label in the latest single-app result: `tracee/monitor`.
293. Tracee status in that result: `ok`.
294. Tracee had 158 map_inline pass attempts.
295. Tracee had 3057 current map_inline matched sites.
296. Tracee had 133 current map_inline applied sites.
297. Tracee had 2924 current map_inline skipped sites.
298. Tracee pass statuses were 155 ok and 3 failed_rejit.
299. Current skipped sites are dominated by key-state failures and map-in-map outer key failures.
300. The deep dive records Tracee as having many map-in-map/version-map skips (`docs/tmp/map_inline_deepdive_20260505.md:410`).
301. The new runtime-key small-chain path does not solve most map-in-map outer lookup failures.

## Tracee Helper-Referenced Map Table

302. `events_map_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 405 | helper writes 0 | entry unknown | skip: map-in-map.
303. `scratch_map` | not retained | PERCPU_ARRAY | 4 | 368 | 2 | lookups 270 | helper writes 0 | entry <= 2 | skip: scratch array.
304. `task_info_map` | not retained | LRU_HASH | 4 | 200 | 10240 | lookups 259 | helper writes 122 | dynamic | reject: BPF-written.
305. `process_tree_map_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 247 | helper writes 1 | dynamic | reject/skip: map-in-map and written.
306. `proc_info_map` | not retained | LRU_HASH | 4 | 368 | 30720 | lookups 246 | helper writes 115 | dynamic | reject: BPF-written.
307. `binary_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
308. `cgroup_id_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
309. `comm_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
310. `mnt_ns_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
311. `pid_ns_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
312. `uid_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
313. `uts_ns_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 244 | helper writes 0 | unknown | skip: map-in-map.
314. `pid_filter_version` | not retained | HASH_OF_MAPS | 2 | 4 | 64 | lookups 235 | helper writes 0 | unknown | skip: map-in-map.
315. `config_map` | not retained | ARRAY | 4 | 272 | 1 | lookups 140 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
316. `event_data_map` | not retained | PERCPU_ARRAY | 4 | 32536 | 1 | lookups 130 | helper writes 0 | entry 1 | skip: scratch array.
317. `sys_32_to_64_map` | not retained | HASH | 4 | 4 | 1024 | lookups 119 | helper writes 0 | likely static table | skip unless snapshot <= 10.
318. `containers_map` | not retained | HASH | 4 | 1 | 10240 | lookups 112 | helper writes 3 | dynamic | reject: BPF-written.
319. `bufs` | not retained | PERCPU_ARRAY | 4 | 32768 | 2 | lookups 64 | helper writes 0 | entry <= 2 | skip: scratch array.
320. `modules_map` | not retained | HASH | 8 | 1 | 660 | lookups 64 | helper writes 1 | dynamic | reject: BPF-written.
321. `recent_deleted_module_map` | not retained | LRU_HASH | 8 | 8 | 50 | lookups 42 | helper writes 1 | dynamic | reject: BPF-written.
322. `logs_count` | not retained | HASH | 88 | 16 | 4096 | lookups 37 | helper writes 37 | dynamic | reject: BPF-written.
323. `expected_sys_call_table` | not retained | ARRAY | 4 | 8 | 500 | lookups 25 | helper writes 0 | static | kernel-already-inlined ARRAY.
324. `args_map` | not retained | HASH | 8 | 48 | 10240 | lookups 23 | helper writes 41 | dynamic | reject: BPF-written.
325. `netconfig_map` | not retained | ARRAY | 4 | 8 | 1 | lookups 18 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
326. `io_file_path_cache_map` | not retained | LRU_HASH | 24 | 4096 | 5 | lookups 16 | helper writes 16 | dynamic | reject: BPF-written despite small max.
327. `ksymbols_map` | not retained | HASH | 64 | 8 | 1024 | lookups 16 | helper writes 0 | unknown | skip unless snapshot <= 10.
328. `netflowmap` | not retained | LRU_HASH | 41 | 9 | 65535 | lookups 12 | helper writes 6 | dynamic | reject: BPF-written.
329. `data_filter_exact_version` | not retained | HASH_OF_MAPS | 8 | 4 | 64 | lookups 10 | helper writes 0 | unknown | skip: map-in-map.
330. `data_filter_lpm_bufs` | not retained | PERCPU_ARRAY | 4 | 260 | 1 | lookups 10 | helper writes 0 | entry 1 | skip: scratch array.
331. `data_filter_prefix_version` | not retained | HASH_OF_MAPS | 8 | 4 | 64 | lookups 10 | helper writes 0 | unknown | skip: map-in-map.
332. `data_filter_suffix_version` | not retained | HASH_OF_MAPS | 8 | 4 | 64 | lookups 10 | helper writes 0 | unknown | skip: map-in-map.
333. `file_type_filter` | not retained | ARRAY | 4 | 4 | 2 | lookups 10 | helper writes 0 | entry <= 2 | kernel-already-inlined ARRAY.
334. `file_write_path_filter` | not retained | ARRAY | 4 | 64 | 3 | lookups 9 | helper writes 0 | entry <= 3 | kernel-already-inlined ARRAY.
335. `kconfig_map` | not retained | HASH | 4 | 4 | 10240 | lookups 7 | helper writes 0 | unknown | skip unless snapshot <= 10.
336. `file_read_path_filter` | not retained | ARRAY | 4 | 64 | 3 | lookups 6 | helper writes 0 | entry <= 3 | kernel-already-inlined ARRAY.
337. `signal_data_map` | not retained | PERCPU_ARRAY | 4 | 32072 | 1 | lookups 6 | helper writes 0 | entry 1 | skip: scratch array.
338. `data_filter_bufs` | not retained | PERCPU_ARRAY | 4 | 256 | 1 | lookups 5 | helper writes 0 | entry 1 | skip: scratch array.
339. `elf_files_map` | not retained | LRU_HASH | 24 | 1 | 64 | lookups 5 | helper writes 11 | dynamic | reject: BPF-written.
340. `events_map` | not retained | HASH | 4 | 64 | 794 | lookups 4 | helper writes 0 | unknown | skip unless snapshot <= 10.
341. `bpf_attach_map` | not retained | LRU_HASH | 4 | 32 | 1024 | lookups 3 | helper writes 4 | dynamic | reject: BPF-written.
342. `bpf_attach_tmp_map` | not retained | LRU_HASH | 4 | 32 | 1024 | lookups 3 | helper writes 3 | dynamic | reject: BPF-written.
343. `inodemap` | not retained | LRU_HASH | 8 | 128 | 65535 | lookups 3 | helper writes 4 | dynamic | reject: BPF-written.
344. `file_modification_map` | not retained | LRU_HASH | 16 | 4 | 10240 | lookups 2 | helper writes 4 | dynamic | reject: BPF-written.
345. `bpf_prog_load_map` | not retained | LRU_HASH | 4 | 8 | 1024 | lookups 1 | helper writes 2 | dynamic | reject: BPF-written.
346. `cgrpctxmap_eg` | not retained | LRU_HASH | 48 | 198 | 4096 | lookups 1 | helper writes 1 | dynamic | reject: BPF-written.
347. `cgrpctxmap_in` | not retained | LRU_HASH | 48 | 198 | 4096 | lookups 1 | helper writes 1 | dynamic | reject: BPF-written.
348. `entrymap` | not retained | LRU_HASH | 4 | 48 | 2048 | lookups 1 | helper writes 2 | dynamic | reject: BPF-written.
349. `module_context_map` | not retained | PERCPU_ARRAY | 4 | 16 | 1 | lookups 1 | helper writes 1 | entry 1 | reject: written scratch.
350. `net_heap_event` | not retained | PERCPU_ARRAY | 4 | 32536 | 1 | lookups 1 | helper writes 0 | entry 1 | skip: scratch array.
351. `new_module_map` | not retained | HASH | 8 | 16 | 330 | lookups 1 | helper writes 2 | dynamic | reject: BPF-written.
352. `prog_array` | not retained | PROG_ARRAY | 4 | 4 | 15 | lookups 1 | helper writes 0 | unknown | skip: not value inline target.
353. `sockmap` | not retained | LRU_HASH | 8 | 8 | 65535 | lookups 1 | helper writes 1 | dynamic | reject: BPF-written.
354. `stack_pivot_syscalls` | not retained | HASH | 4 | 4 | 794 | lookups 1 | helper writes 0 | unknown | skip unless snapshot <= 10.
355. `suspicious_syscall_source_syscalls` | not retained | HASH | 4 | 4 | 794 | lookups 1 | helper writes 0 | unknown | skip unless snapshot <= 10.
356. Dynamic/no-close-map helper calls in Tracee: lookup 253, update 2.

## Tracee Category Estimate

357. Tracee all-values-equal unconditional form: not safe for runtime HASH keys.
358. Tracee if/else chain by declared max <= 10: essentially none for read-only HASH maps; the small maps are mostly ARRAY or BPF-written LRU/HASH.
359. Tracee if/else chain by possible live snapshot <= 10: `events_map`, syscall sets, ksymbols/config hashes, and filter hashes may qualify if empty/small.
360. Tracee kernel-already-inlined ARRAY category is large and includes config, buffers, filters, and syscall-table arrays.
361. Tracee map-in-map skip category dominates the largest version-filter lookup counts.
362. Tracee BPF-written category includes task/process info, containers, args, logs, netflow, attach, inode, and module state.
363. Conservative Tracee unlock estimate: 0 to 10 sites.
364. Snapshot-optimistic Tracee unlock estimate: 10 to 30 sites, but most are unlikely to be the dominant current skip mass.
365. Hot-path confidence is low because the highest-count read-only sites are map-in-map outer maps or arrays.

## Part A: Tetragon Latest Result

366. Tetragon app label in the latest multi-app result: `tetragon/observer`.
367. Tetragon status in that result: `ok`.
368. Tetragon had 287 map_inline pass attempts.
369. Tetragon had 3318 current map_inline matched sites.
370. Tetragon had 0 current map_inline applied sites.
371. Tetragon had 3318 current map_inline skipped sites.
372. Tetragon pass statuses were 243 ok and 44 skipped_missing_states.
373. The deep dive records Tetragon as a high-match, zero-apply case under current constraints (`docs/tmp/map_inline_deepdive_20260505.md:218`).
374. The new criterion helps only the subset that is non-writable, non-array, non-map-in-map, small, and scalarizable.

## Tetragon Helper-Referenced Map Table

375. `execve_map` | not retained | HASH | 4 | 896 | 1 | lookups 1005 | helper writes 9 | entry dynamic | reject: BPF-written.
376. `process_call_heap` | not retained | PERCPU_ARRAY | 4 | 25696 | 1 | lookups 771 | helper writes 0 | entry 1 | skip: scratch array.
377. `tg_errmetrics_map` | not retained | LRU_PERCPU_HASH | 12 | 4 | 1024 | lookups 716 | helper writes 575 | dynamic | reject: BPF-written.
378. `argfilter_maps` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 588 | helper writes 0 | unknown | skip: map-in-map.
379. `config_map` | not retained | ARRAY | 4 | 736 | 1 | lookups 289 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
380. `heap_ro_zero` | not retained | ARRAY | 4 | 16384 | 1 | lookups 261 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
381. `string_maps_heap` | not retained | PERCPU_ARRAY | 4 | unknown | 1 | lookups 179 | helper writes 0 | entry 1 | skip: scratch array.
382. `string_postfix_maps` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 179 | helper writes 0 | unknown | skip: map-in-map.
383. `string_postfix_maps_heap` | not retained | PERCPU_ARRAY | 4 | 132 | 1 | lookups 179 | helper writes 0 | entry 1 | skip: scratch array.
384. `string_prefix_maps` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 179 | helper writes 0 | unknown | skip: map-in-map.
385. `tg_stats_map` | not retained | PERCPU_ARRAY | 4 | 14336 | 1 | lookups 177 | helper writes 0 | counters | reject/skip: stats semantics.
386. `enforcer_missed_notifications` | not retained | HASH | 12 | 4 | 128 | lookups 168 | helper writes 84 | dynamic | reject: BPF-written.
387. `buffer_heap_map` | not retained | PERCPU_ARRAY | 4 | 4352 | 1 | lookups 151 | helper writes 0 | entry 1 | skip: scratch array.
388. `policy_stats` | not retained | ARRAY | 4 | 80 | 1 | lookups 150 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
389. `filter_map` | not retained | ARRAY | 4 | 4096 | 1 | lookups 143 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
390. `tg_mb_paths` | not retained | ARRAY_OF_MAPS | 4 | 4 | 10 | lookups 124 | helper writes 0 | unknown | skip: map-in-map.
391. `string_prefix_maps_heap` | not retained | PERCPU_ARRAY | 4 | 260 | 1 | lookups 123 | helper writes 0 | entry 1 | skip: scratch array.
392. `substring_map` | not retained | ARRAY | 4 | 100 | 1 | lookups 123 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
393. `tg_conf_map` | not retained | ARRAY | 4 | 48 | 1 | lookups 121 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
394. `fdinstall_map` | not retained | LRU_HASH | 16 | 4104 | 1 | lookups 120 | helper writes 198 | dynamic | reject: BPF-written.
395. `string_maps_8` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 120 | helper writes 0 | unknown | skip: map-in-map.
396. `retprobe_map` | not retained | HASH | 16 | 24 | 1024 | lookups 112 | helper writes 197 | dynamic | reject: BPF-written.
397. `sleepable_preload` | not retained | HASH | 8 | 4100 | 1 | lookups 109 | helper writes 108 | dynamic | reject: BPF-written.
398. `tg_mbset_map` | not retained | HASH | 256 | 8 | 1024 | lookups 89 | helper writes 0 | unknown | skip unless snapshot <= 10.
399. `enforcer_data` | not retained | HASH | 8 | 12 | 1 | lookups 87 | helper writes 87 | dynamic | reject: BPF-written.
400. `socktrack_map` | not retained | LRU_HASH | 8 | 16 | 1 | lookups 84 | helper writes 102 | dynamic | reject: BPF-written.
401. `tg_cgtracker_map` | not retained | HASH | 8 | 8 | 1 | lookups 74 | helper writes 2 | dynamic | reject: BPF-written.
402. `string_maps_7` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 72 | helper writes 0 | unknown | skip: map-in-map.
403. `heap` | not retained | PERCPU_ARRAY | 4 | 4104 | 1 | lookups 69 | helper writes 0 | entry 1 | skip: scratch array.
404. `tg_mb_sel_opts` | not retained | ARRAY | 4 | 12 | 10 | lookups 62 | helper writes 0 | entry <= 10 | kernel-already-inlined ARRAY.
405. `string_maps_4` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 54 | helper writes 0 | unknown | skip: map-in-map.
406. `addr4lpm_maps` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 51 | helper writes 0 | unknown | skip: map-in-map.
407. `addr6lpm_maps` | not retained | ARRAY_OF_MAPS | 4 | 4 | 8 | lookups 51 | helper writes 0 | unknown | skip: map-in-map.
408. `policy_conf` | not retained | ARRAY | 4 | 1 | 1 | lookups 51 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
409. `tg_ipv6_ext_heap` | not retained | PERCPU_ARRAY | 4 | 8 | 1 | lookups 51 | helper writes 0 | entry 1 | skip: scratch array.
410. `data_heap` | not retained | PERCPU_ARRAY | 4 | 32768 | 1 | lookups 45 | helper writes 0 | entry 1 | skip: scratch array.
411. `ratelimit_heap` | not retained | PERCPU_ARRAY | 4 | 352 | 1 | lookups 42 | helper writes 0 | entry 1 | skip: scratch array.
412. `ratelimit_map` | not retained | LRU_HASH | 224 | 8 | 1 | lookups 42 | helper writes 42 | dynamic | reject: BPF-written.
413. `tg_mbset_gen` | not retained | ARRAY | 4 | 8 | 1 | lookups 42 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
414. `policy_filter_maps` | not retained | HASH_OF_MAPS | 4 | 4 | 128 | lookups 34 | helper writes 0 | unknown | skip: map-in-map.
415. `override_tasks` | not retained | HASH | 8 | 4 | 1 | lookups 32 | helper writes 32 | dynamic | reject: BPF-written.
416. `tg_parents_bin` | not retained | LRU_HASH | 4 | 792 | 1 | lookups 28 | helper writes 9 | dynamic | reject: BPF-written.
417. `execve_map_stats` | not retained | PERCPU_ARRAY | 4 | 8 | 3 | lookups 18 | helper writes 0 | counters | skip/reject stats semantics.
418. `execve_msg_heap_map` | not retained | PERCPU_ARRAY | 4 | 5824 | 1 | lookups 15 | helper writes 0 | entry 1 | skip: scratch array.
419. `sleepable_offload` | not retained | HASH | 8 | 4 | 1 | lookups 14 | helper writes 14 | dynamic | reject: BPF-written.
420. `tg_execve_joined_info_map_stats` | not retained | PERCPU_ARRAY | 4 | 8 | 3 | lookups 12 | helper writes 0 | counters | skip/reject stats semantics.
421. `write_offload` | not retained | HASH | 8 | 16 | 1 | lookups 8 | helper writes 8 | dynamic | reject: BPF-written.
422. `cgroup_rate_map` | not retained | PERCPU_HASH | 8 | 40 | 1 | lookups 7 | helper writes 8 | dynamic | reject: BPF-written.
423. `cgroup_rate_options_map` | not retained | ARRAY | 4 | 16 | 1 | lookups 7 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
424. `throttle_heap_map` | not retained | PERCPU_ARRAY | 4 | 160 | 1 | lookups 7 | helper writes 0 | entry 1 | skip: scratch array.
425. `execve_heap` | not retained | PERCPU_ARRAY | 4 | 4112 | 1 | lookups 6 | helper writes 0 | entry 1 | skip: scratch array.
426. `exit_heap_map` | not retained | PERCPU_ARRAY | 4 | 40 | 1 | lookups 6 | helper writes 0 | entry 1 | skip: scratch array.
427. `ima_hash_map` | not retained | HASH | 8 | 66 | 1024 | lookups 6 | helper writes 8 | dynamic | reject: BPF-written.
428. `regs_map` | not retained | ARRAY | 4 | 296 | 1 | lookups 6 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
429. `tg_cgrps_msg_heap` | not retained | PERCPU_ARRAY | 4 | 4312 | 1 | lookups 6 | helper writes 0 | entry 1 | skip: scratch array.
430. `tg_execve_joined_info_map` | not retained | LRU_HASH | 8 | 16 | 8192 | lookups 5 | helper writes 6 | dynamic | reject: BPF-written.
431. `execve_map_update_data` | not retained | ARRAY | 4 | 131080 | 1 | lookups 4 | helper writes 0 | entry 1 | kernel-already-inlined ARRAY.
432. `tg_cgrps_tracking_map` | not retained | HASH | 8 | 144 | 32768 | lookups 4 | helper writes 6 | dynamic | reject: BPF-written.
433. `execve_val` | not retained | PERCPU_ARRAY | 4 | 896 | 1 | lookups 3 | helper writes 0 | entry 1 | skip: scratch array.
434. `m1` | not retained | HASH | 4 | 4 | 1 | lookups 3 | helper writes 0 | entry <= 1 | if/else chain candidate, likely test-only.
435. `tg_binary_heap` | not retained | PERCPU_ARRAY | 4 | 792 | 1 | lookups 3 | helper writes 0 | entry 1 | skip: scratch array.
436. `ids_map` | not retained | PERCPU_ARRAY | 4 | 8 | 1 | lookups 2 | helper writes 0 | entry 1 | skip: scratch array.
437. `loader_heap` | not retained | PERCPU_ARRAY | 4 | 4168 | 1 | lookups 2 | helper writes 0 | entry 1 | skip: scratch array.
438. `m2` | not retained | HASH | 4 | 4 | 1 | lookups 2 | helper writes 0 | entry <= 1 | if/else chain candidate, likely test-only.
439. `tg_cgrps_tracking_heap` | not retained | PERCPU_ARRAY | 4 | 144 | 1 | lookups 2 | helper writes 0 | entry 1 | skip: scratch array.
440. Dynamic/no-close-map helper calls in Tetragon: lookup 298, delete 1.

## Tetragon Category Estimate

441. Tetragon all-values-equal unconditional form: no broad safe runtime-key HASH application.
442. Tetragon if/else chain by declared max <= 10 and read-only HASH: `m1` and `m2`, 5 total sites.
443. Tetragon if/else chain by possible live snapshot <= 10: `tg_mbset_map` could qualify if the snapshot is tiny, but key size 256 makes it expensive.
444. Tetragon kernel-already-inlined ARRAY category is very large.
445. Tetragon map-in-map skip category is also large.
446. Tetragon BPF-written category includes the highest-count HASH maps.
447. Conservative Tetragon unlock estimate: 5 sites.
448. Snapshot-optimistic Tetragon unlock estimate: 5 to 15 sites.
449. Hot-path confidence is low because the viable named HASH candidates look test-like or cold.

## Part A: Otel Latest Result

450. Otel app label in the latest multi-app result: `otelcol-ebpf-profiler/profiling`.
451. Otel status in that result: `ok`.
452. Otel had 13 map_inline pass attempts.
453. Otel had 1593 current map_inline matched sites.
454. Otel had 1192 current map_inline applied sites.
455. Otel had 401 current map_inline skipped sites.
456. The deep dive records Otel as a high direct-map success case with remaining unsupported/key-state skips (`docs/tmp/map_inline_deepdive_20260505.md:321`).
457. Otel's current successes reduce the room left for helper-call runtime-key rewriting.

## Otel Helper-Referenced Map Table

458. `metrics` | not retained | metadata unknown in extracted table | unknown | unknown | unknown | lookups 37 | helper writes 0 in direct relocation scan | counters | reject true-read-only due direct stores.
459. `per_cpu_records` | not retained | metadata unknown | unknown | unknown | unknown | lookups 9 | helper writes 0 | unknown | likely array/percpu scratch; skip pending metadata.
460. `pid_page_to_mapping_info` | not retained | metadata unknown | unknown | unknown | unknown | lookups 8 | helper writes 0 | unknown | skip pending metadata.
461. `reported_pids` | not retained | metadata unknown | unknown | unknown | unknown | lookups 6 | helper writes 4 | dynamic | reject: BPF-written.
462. `interpreter_offsets` | not retained | HASH | 8 | 40 | 32 | lookups 4 | helper writes 0 | entry count unknown | if/else only if snapshot <= 10.
463. `exe_id_to_22_stack_deltas` | not retained | HASH_OF_MAPS | 8 | 4 | 4096 | lookups 2 | helper writes 0 | unknown | skip: map-in-map.
464. `stack_delta_page_to_info` | not retained | HASH | 16 | 8 | 40000 | lookups 2 | helper writes 0 | unknown | skip unless snapshot <= 10.
465. `unwind_info_array` | not retained | ARRAY | 4 | 12 | 16384 | lookups 2 | helper writes 0 | unknown | kernel-already-inlined ARRAY.
466. Dynamic/no-close-map helper calls in Otel: lookup 6.
467. Otel `metrics` has lookup then direct increment in source (`runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:47`).
468. Otel `reported_pids` has lookup, update, and delete paths in source (`runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:115`).
469. Otel runner starts the real profiler workload with language idlers instead of a framework-side loader (`runner/libs/app_runners/otel_profiler.py:121`).

## Otel Category Estimate

470. Otel all-values-equal unconditional form: no clear safe runtime-key HASH site.
471. Otel if/else chain candidate: `interpreter_offsets`, 4 sites if live entries <= 10.
472. Otel possible but less likely candidate: `stack_delta_page_to_info`, 2 sites if live entries <= 10 despite max 40000.
473. Otel kernel-already-inlined ARRAY category: `unwind_info_array`.
474. Otel BPF-written category: `metrics` and `reported_pids`.
475. Conservative Otel unlock estimate: 0 to 4 sites.
476. Snapshot-optimistic Otel unlock estimate: 4 to 6 sites.
477. Hot-path confidence is low to moderate.

## Cross-App Category Totals

478. Cilium conservative candidate sites: 10 to 20.
479. Cilium snapshot-optimistic candidate sites: 40 to 90.
480. Katran conservative candidate sites: 4.
481. Katran snapshot-optimistic candidate sites: 4 to 6.
482. Tracee conservative candidate sites: 0 to 10.
483. Tracee snapshot-optimistic candidate sites: 10 to 30.
484. Tetragon conservative candidate sites: 5.
485. Tetragon snapshot-optimistic candidate sites: 5 to 15.
486. Otel conservative candidate sites: 0 to 4.
487. Otel snapshot-optimistic candidate sites: 4 to 6.
488. Five-app conservative candidate total: about 19 to 43 sites.
489. Five-app snapshot-optimistic candidate total: about 63 to 147 sites.
490. The conservative total is small relative to the current match counts.
491. The optimistic total depends mostly on retained live entry counts, not on declared max_entries.
492. The site count overstates performance if a candidate is cold.
493. The site count understates performance if a small candidate is on a per-packet path like Katran `vip_map`.

## Part B: Bytecode Form for 5-Entry HASH

494. The source pattern is `r1 = &map; r2 = &key; call bpf_map_lookup_elem`.
495. The replacement should use the existing key pointer if the verifier state proves it points to initialized stack bytes.
496. If the key pointer cannot be resolved to stack bytes or a known initialized memory region, skip.
497. The pass should not compare directly against packet memory unless it can prove packet bounds, alignment, and lifetime.
498. The current verifier-state machinery already extracts key values only from verifier-known state (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:324`).
499. The new runtime-key path needs a sibling extractor for key location and size, not key constant value.
500. For a 20-byte key, emit five 32-bit loads or two 64-bit loads plus one 32-bit load depending alignment.
501. For unaligned stack offsets, emit byte loads and assemble comparisons, or emit naturally aligned smaller loads.
502. Favor byte/word-safe comparisons over verifier-fragile unaligned 64-bit loads.
503. A 5-entry chain can be straight-line conditional branches.
504. Pseudocode:
505. `load key chunk 0 into r6`
506. `if r6 != entry0.chunk0 goto entry1`
507. `load key chunk 1 into r6`
508. `if r6 != entry0.chunk1 goto entry1`
509. `...`
510. `matched entry0: load value constants; goto non_null_continuation`
511. `entry1: compare chunks`
512. `matched entry1: load value constants; goto non_null_continuation`
513. `...`
514. `no_match: goto null_continuation`
515. If the original non-NULL continuation expects value fields loaded from `r0 + off`, scalarization must replace those loads with immediate moves.
516. If the original code expects `r0` to remain a usable pointer, this minimal path must skip.
517. If an entry's value field is 64-bit and fits BPF immediate encoding, use `mov64_imm` or `lddw` as needed.
518. The instruction helper constructors include immediate moves and memory loads (`bpfopt/crates/bpfopt/src/insn.rs:310`, `bpfopt/crates/bpfopt/src/insn.rs:359`).
519. Existing code already has pseudo map fd/index helpers for map references (`bpfopt/crates/bpfopt/src/insn.rs:323`).
520. The new runtime chain should not require pseudo map fd/index for scalar values.

## Pointer Return Problem

521. The original helper returns `PTR_TO_MAP_VALUE_OR_NULL`.
522. The verifier models nullable map-value pointers explicitly in comments and type states (`vendor/linux-framework/kernel/bpf/verifier.c:101`).
523. After a null check, the verifier can refine the pointer to a non-null map-value pointer.
524. `BPF_PSEUDO_MAP_VALUE` can be converted into `PTR_TO_MAP_VALUE` by the verifier (`vendor/linux-framework/kernel/bpf/verifier.c:18105`).
525. The verifier also validates fd_array indexes for pseudo map values during program load/ReJIT (`vendor/linux-framework/kernel/bpf/verifier.c:22163`).
526. But arbitrary HASH entries do not have stable bytecode-addressable value offsets in the way an ARRAY value can.
527. The current pass's pseudo-map-value direct path is therefore a constant-key, fixed-value-address optimization.
528. It should not be generalized into "set `r0` to pointer for any matched HASH key".
529. Creating a new snapshot map and doing a lookup in that map would preserve pointer semantics but would reintroduce a helper call.
530. Creating a new snapshot map would also complicate daemon ownership and side-input materialization.
531. The minimum viable design should avoid new maps.
532. The minimum viable design should rewrite only sites where the returned value is consumed through fixed scalar loads that the pass can replace.
533. The current build-site rewrite already constructs rewrites from snapshot values for constant keys (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1250`).
534. The new chain emitter can reuse the value-load replacement part while replacing constant-key selection with runtime-key comparison.

## 5-Entry Bytecode Sketch

535. Assume key size 8 bytes, value use is one 64-bit load at value offset 0, and original code has an immediate null check.
536. Original:
537. `r1 = map_ref`
538. `r2 = fp - key_off`
539. `call 1`
540. `if r0 == 0 goto null_path`
541. `r7 = *(u64 *)(r0 + 0)`
542. `... non_null_path ...`
543. Replacement:
544. `r6 = *(u64 *)(fp - key_off)`
545. `if r6 != key0 goto L1`
546. `r7 = value0_imm64`
547. `goto non_null_path`
548. `L1: if r6 != key1 goto L2`
549. `r7 = value1_imm64`
550. `goto non_null_path`
551. `L2: if r6 != key2 goto L3`
552. `r7 = value2_imm64`
553. `goto non_null_path`
554. `L3: if r6 != key3 goto L4`
555. `r7 = value3_imm64`
556. `goto non_null_path`
557. `L4: if r6 != key4 goto null_path`
558. `r7 = value4_imm64`
559. `goto non_null_path`
560. This removes the helper call and all map lookup overhead.
561. It preserves no-match behavior by branching to the original null path.
562. It does not set `r0` to a pointer.
563. It is valid only if all later uses of `r0` are removed or irrelevant.
564. If the original code tests `r0` and then loads multiple fields, each load gets replaced by the matched arm's constants.
565. If different fields are used on different branches, the emitter needs per-branch value materialization.
566. If values are larger than used fields, only used fields need immediate materialization.
567. This is why scalarization is more practical than pointer synthesis.

## Struct-Key Feasibility

568. Struct keys such as Cilium service keys and Katran VIP keys are feasible.
569. Key bytes are in BPF stack memory at the helper call in common compiled patterns.
570. The emitter can compare each chunk in little-endian byte order exactly as stored in the map snapshot.
571. For a 20-byte key, a robust form is five 32-bit compares.
572. For a 12-byte key, use three 32-bit compares.
573. For a 24-byte key, use six 32-bit compares or three 64-bit compares if aligned.
574. For a 36-byte key, use nine 32-bit compares.
575. For a 256-byte key such as Tetragon `tg_mbset_map`, the code size is too high unless entry count is tiny and site is hot.
576. The pass should enforce a maximum compare byte budget, not just entry count.
577. Suggested first budget: `entry_count * key_size <= 240` bytes.
578. That admits 10 entries with 24-byte keys.
579. That admits 5 entries with 48-byte keys.
580. That rejects 10 entries with 256-byte keys.
581. The branch-offset budget is fine for these sizes because BPF conditional jumps use signed 16-bit offsets and the chain is small.
582. The verifier will require initialized stack reads.
583. If the key lives in packet memory, the pass should skip unless verifier states prove packet bounds on every emitted load.
584. Packet-key direct comparison is not needed for Katran `vip_map` if the program already materializes the flow key on stack before the helper.

## LPM_TRIE Feasibility

585. LPM_TRIE can be expressed as straight-line longest-prefix comparisons.
586. Snapshot entries include a prefix length and key bytes.
587. Sort snapshot entries by descending prefix length.
588. For each entry, compare full prefix bytes.
589. For a partial final prefix byte, mask both runtime key byte and snapshot key byte with the prefix mask.
590. On first match, emit the scalarized value loads and jump to the non-null continuation.
591. If no prefix matches, jump to the null continuation.
592. This preserves longest-prefix semantics because longer prefixes are checked first.
593. No loops are required.
594. Suggested first implementation limit: <= 10 entries and <= 40-byte key size.
595. Cilium LPM maps have key sizes up to 36 bytes in the observed object table.
596. The LPM chain can become code-size heavy because every candidate prefix may need many byte/word compares.
597. LPM should be phase two after HASH scalarization.
598. The first pass can still expose `entry_count` and `bpf_writable` for LPM diagnostics.
599. If LPM values are 1-byte policy flags, scalarization is attractive.
600. If LPM values are structs and the original pointer escapes, skip.

## Verifier Acceptance Risks

601. The verifier performs CFG validation through `check_cfg` (`vendor/linux-framework/kernel/bpf/verifier.c:19243`).
602. The emitted if/else chain is acyclic and should satisfy CFG validation.
603. Conditional branches are checked by `check_cond_jmp_op` (`vendor/linux-framework/kernel/bpf/verifier.c:17774`).
604. The emitted comparisons use ordinary scalar registers and immediate constants.
605. Stack and memory reads are checked by `check_mem_access` (`vendor/linux-framework/kernel/bpf/verifier.c:8006`).
606. Fixed stack reads are checked by `check_stack_read_fixed_off` (`vendor/linux-framework/kernel/bpf/verifier.c:5855`).
607. Map accesses are checked by `check_map_access` (`vendor/linux-framework/kernel/bpf/verifier.c:6539`).
608. Pointer alignment is checked by `check_ptr_alignment` (`vendor/linux-framework/kernel/bpf/verifier.c:6942`).
609. Pointer arithmetic is checked by `adjust_ptr_min_max_vals` (`vendor/linux-framework/kernel/bpf/verifier.c:15166`).
610. Helper calls are checked by `check_helper_call` (`vendor/linux-framework/kernel/bpf/verifier.c:11943`).
611. The new chain removes a helper call, so it removes that helper-call check at the site.
612. It adds stack loads and scalar branches, so stack initialization and alignment become the main verifier risks.
613. If using `BPF_PSEUDO_MAP_VALUE`, verifier pseudo map value conversion is checked in the load path (`vendor/linux-framework/kernel/bpf/verifier.c:18105`).
614. The minimum scalarization design avoids new pseudo map value use for runtime HASH entries.
615. Bounded loop risk is absent because the chain is straight-line.
616. Max stack depth should not increase if the emitter reuses registers only (`vendor/linux-framework/kernel/bpf/verifier.c:7205`).
617. Register pressure is a practical risk because BPF has limited general registers.
618. The emitter should reserve one or two scratch registers only when liveness analysis proves they are dead or can be safely saved.
619. The current pass already mutates instruction streams and tracks rewrites through `Program` abstractions.
620. ReJIT verifier logs remain the final acceptance signal because each pass candidate is immediately ReJITed by the daemon (`CLAUDE.md:86`).

## JIT Risk

621. The generated instructions are ordinary loads, immediate moves, jumps, and scalar comparisons.
622. Kernel JITs compile these patterns routinely.
623. The main JIT risk is not correctness but code size and instruction-cache pressure.
624. An if/else chain over 10 entries with 20-byte keys can add roughly 70 to 140 BPF instructions before value materialization.
625. That code growth may be acceptable for a hot lookup with high helper cost.
626. It may be harmful for cold sites or large keys.
627. Therefore the pass needs hard limits on entry count, key byte budget, emitted instruction count, and scalarized value-use count.
628. The existing fail-fast culture argues against silently falling back to an unsafe form (`CLAUDE.md:70`).
629. A skipped site should report a precise reason such as `runtime_key_chain_too_large`, `value_pointer_escapes`, or `bpf_writable`.

## Part C: Performance Model

630. A HASH `bpf_map_lookup_elem` helper has fixed helper-call overhead plus hash computation, bucket lookup, key compare, locking/RCU details, and verifier/JIT call boundary cost.
631. A realistic order-of-magnitude estimate for HASH lookup is 80 to 250 cycles for hot-cache small maps.
632. A cold or contended lookup can be substantially higher.
633. PERCPU_HASH can be similar or slightly higher depending per-CPU value handling.
634. LPM_TRIE lookup can be higher than HASH because it walks trie nodes and compares prefixes.
635. ARRAY lookup is much cheaper and often JIT-inlined by the kernel, so framework-side replacement has near-zero helper-call savings.
636. An inline if/else chain with one 8-byte key and N entries costs roughly 2 to 4 cycles per failed compare on hot JITed code, plus branch prediction effects.
637. A 20-byte struct key with five 32-bit chunks costs roughly 5 compares and 5 conditional branches per entry in the worst case.
638. For N=1 and a 20-byte key, the inline chain may cost 10 to 25 cycles.
639. For N=5 and a 20-byte key, worst-case no-match can cost 50 to 120 cycles.
640. For N=10 and a 20-byte key, worst-case no-match can cost 100 to 240 cycles.
641. Hit distribution matters.
642. If the first entry is the common hit, average cost can be much lower.
643. If keys are uniformly distributed or mostly misses, average cost approaches half-chain or full-chain cost.
644. Crossover for 8-byte keys is likely around N=8 to N=16.
645. Crossover for 20-byte keys is likely around N=4 to N=10.
646. Crossover for 36-byte LPM keys is likely around N=3 to N=6 unless values are very hot and helper cost is high.
647. These are estimates and should be validated only by external analysis, not framework summaries (`CLAUDE.md:15`).
648. The pass should default to N=10 as a correctness-friendly ceiling and allow future analysis-side tuning.
649. The pass should also apply an emitted-instruction ceiling to avoid pathological code size.

## Per-App Performance Expectation

650. Cilium expected hit-rate product is uncertain.
651. Cilium small control/filter maps may have high branch locality but fewer hot invocations.
652. Cilium service/backend maps may be hot, but declared max entries are large and live entry counts were not retained.
653. Cilium expected macro speedup under conservative candidates: about 0.1% to 0.7%.
654. Cilium optimistic speedup if hot small live snapshots are proven: about 0.5% to 2%.
655. Katran `vip_map` is likely hot on every packet path.
656. Katran `vip_map` has one configured entry in the corpus setup (`runner/libs/app_runners/katran.py:613`).
657. Katran expected site speedup for `vip_map` lookup can be large at the site level, likely 2x to 8x for that lookup operation.
658. Katran macro app speedup is bounded by other packet work and already-cheap array paths.
659. Katran expected app-level speedup contribution: about 0.5% to 3%.
660. Tracee expected hit-rate product is low because the largest skipped groups are not small read-only HASH candidates.
661. Tracee expected app-level speedup contribution: about 0% to 0.5%.
662. Tetragon expected hit-rate product is low for the new small-HASH path.
663. Tetragon expected app-level speedup contribution: about 0% to 0.5%.
664. Otel expected hit-rate product is low to moderate only if `interpreter_offsets` has <= 10 live entries.
665. Otel expected app-level speedup contribution: about 0% to 0.5%.
666. Across the 18-app corpus, only five apps are investigated here.
667. Even within the five apps, current direct-map successes already captured many constant-key cases in Cilium and Otel.
668. The realistic upper-bound corpus geomean improvement from this redesign alone is 0.3% to 1.5%.
669. A hard optimistic upper bound is 2% to 3%.
670. Anything above that would require hot small read-only runtime-key maps in additional apps or a separate map-in-map design.

## Part D: map-values.json Side Input

671. `map-values.json` is written by the daemon command path (`daemon/src/commands.rs:545`).
672. The current writer includes map ID, map name, type, key size, value size, max entries, partial flag, and entries (`daemon/src/commands.rs:1025`).
673. The current CLI parser reads map-values metadata, entries, null keys, inner map IDs, and partial status (`bpfopt/crates/bpfopt/src/main.rs:1068`).
674. The side input should add `entry_count`.
675. `entry_count` should be the number of entries successfully captured before any partial cutoff.
676. The side input should add `all_values_equal`.
677. `all_values_equal` should be true only when every captured entry value is byte-identical.
678. For PERCPU maps, `all_values_equal` should require equality across CPUs and entries for the bytes that would be scalarized.
679. The side input should add `bpf_writable`.
680. `bpf_writable=false` should mean the daemon proved no live BPF program can write that map through helper calls or direct stores.
681. `bpf_writable=true` should mean a write exists or the proof is unsupported/unknown.
682. To keep fail-fast diagnostics, a richer field is better: `bpf_write_status = readonly | writable | unknown`.
683. `unknown` should block the new runtime-key path and surface in diagnostics.
684. The current constant-key path can remain governed by existing semantics.
685. The new runtime-key path must require `bpf_write_status=readonly`.
686. The side input should include optional proof counters: `writer_program_ids`, `write_helper_sites`, `direct_store_sites`, and `unknown_callback_sites`.
687. These proof counters are diagnostics, not performance summaries.
688. They do not violate the no-framework-summary rule because they are raw safety evidence, not benchmark aggregation (`CLAUDE.md:15`).
689. Avoid adding generic informational-only fields such as `limitations`, per repo rules (`CLAUDE.md:70` and user-provided AGENTS instruction).

## Does the Daemon Already Have the Data?

690. The daemon has per-target program bytecode through `snapshot_program` (`daemon/src/bpf.rs:68`).
691. The daemon has the target program's used map IDs through `prog_map_ids` (`daemon/src/bpf.rs:131`).
692. The daemon canonicalizes map references into a stable fd_array before invoking bpfopt (`daemon/src/bpf.rs:278`).
693. The daemon can enumerate live programs through existing `kernel-sys::prog_get_next_id` (`bpfopt/crates/kernel-sys/src/lib.rs:478`).
694. The daemon can open live programs through existing `kernel-sys::prog_try_get_fd_by_id` (`bpfopt/crates/kernel-sys/src/lib.rs:501`).
695. The daemon can read each program's map IDs through existing `kernel_sys::prog_map_ids` (`bpfopt/crates/kernel-sys/src/lib.rs:620`).
696. Therefore the raw kernel data source exists.
697. The daemon does not currently compute cross-program map writability in the inspected command path.
698. The command path snapshots only the program being optimized before writing side inputs (`daemon/src/commands.rs:526`).
699. Minimum daemon work is to add a live-program scan before map-values emission.
700. The scan should enumerate live program IDs.
701. It should open each program with `prog_try_get_fd_by_id` to tolerate unload races during enumeration (`bpfopt/crates/kernel-sys/src/lib.rs:501`).
702. It should read original bytecode and map IDs for each successfully opened program.
703. It should canonicalize map references or otherwise bind pseudo map references to real map IDs.
704. It should scan helper calls that use direct map references.
705. It should build dataflow from helper lookup returns to direct stores into map values.
706. It should conservatively mark unknown dynamic map pointers as writable for the maps they may alias.
707. For map-in-map inner maps, the first implementation can conservatively mark dynamic inner-map writes as unknown/writable.
708. This is fail-fast and avoids unsafe optimism.
709. The daemon should write the proof result into map-values for every map referenced by the target program.

## bpfopt Pass Code Changes

710. Keep existing constant-key direct-value path.
711. Keep existing map-in-map handling unchanged unless a separate design extends it.
712. Add schema fields to map-values parsing.
713. Add a runtime-key path after map metadata lookup and before current constant-key skip finalization.
714. The runtime-key path should require `bpf_write_status=readonly`.
715. The runtime-key path should require `entry_count <= N`.
716. The runtime-key path should require `entries_partial=false` because a partial snapshot cannot prove no missed keys.
717. The runtime-key path should require all snapshot keys and values to be available.
718. The runtime-key path should require a resolvable runtime key location.
719. The runtime-key path should require scalarizable post-lookup uses.
720. The runtime-key path should reject pointer escapes.
721. The runtime-key path should reject direct stores through the returned value pointer.
722. The runtime-key path should emit a straight-line chain for HASH/LRU_HASH first.
723. LRU_HASH can be treated like HASH only if BPF-side readonly is proved.
724. LRU behavior may still change due kernel internal eviction if userspace mutates, but userspace mutation is out of scope for this investigation.
725. Since userspace mutation handling is out of scope, do not design ReJIT-back or invalidation here.
726. Add a second emitter for LPM_TRIE after HASH scalarization is stable.
727. Add diagnostics for every skip reason.
728. Avoid adding any benchmark ratio or summary fields.
729. The report can include raw site counters and reasons because current pass already records matched/applied/skipped site details (`docs/tmp/map_inline_deepdive_20260505.md:39`).

## Runner Changes

730. No runner flag change is needed for the new side-input fields.
731. The runner already attaches `--map-values` and `--map-ids` when pass metadata requests map values (`runner/libs/rejit_plan.py:78`).
732. The pass metadata already declares `needs_map_values=true` for map_inline (`bpfopt/crates/bpfopt/src/passes/mod.rs:81`).
733. The runner remains the stable Python boundary per v3 (`CLAUDE.md:96`).
734. Changing runner Python for this redesign would violate the intended v3 ownership split unless it is a bug fix.
735. Therefore minimum runner change is zero lines.

## kernel-sys Changes

736. No new syscall wrapper is strictly required for live program enumeration.
737. `prog_get_next_id` already exists (`bpfopt/crates/kernel-sys/src/lib.rs:478`).
738. `prog_try_get_fd_by_id` already exists (`bpfopt/crates/kernel-sys/src/lib.rs:501`).
739. `prog_map_ids` already exists (`bpfopt/crates/kernel-sys/src/lib.rs:620`).
740. `map_get_next_key` already exists for snapshot enumeration (`bpfopt/crates/kernel-sys/src/lib.rs:869`).
741. New kernel-sys work may be limited to exposing any missing original-bytecode helper if daemon code cannot already call it from `snapshot_program`.
742. The inspected daemon snapshot code already reads original bytecode as part of `snapshot_program` (`daemon/src/bpf.rs:68`).
743. Therefore kernel-sys LoC should be zero to small.
744. Any future syscall addition must stay in `kernel-sys`, not in `bpfopt` or `bpfrejit-daemon` directly (`CLAUDE.md:118`).

## Minimum-Changes Implementation Path

745. Step 1: extend daemon map-values schema with `entry_count`, `all_values_equal`, and `bpf_write_status`.
746. Step 2: compute `entry_count` and `all_values_equal` while already snapshotting map entries.
747. Step 3: add daemon live-program write scanner using existing kernel-sys enumeration helpers.
748. Step 4: implement helper-call write detection with direct map relocation binding.
749. Step 5: implement direct map-value store detection conservatively.
750. Step 6: mark unsupported dynamic/callback cases as `unknown` or `writable`.
751. Step 7: parse new schema in bpfopt.
752. Step 8: add runtime-key key-location extraction.
753. Step 9: add HASH/LRU_HASH if/else scalarization emitter.
754. Step 10: keep LPM_TRIE behind a separate follow-up patch or feature gate.
755. Step 11: add focused tests for correctness branches, not trivial getters.
756. Good tests should cover missing-key null path, matched-key scalar loads, pointer escape rejection, writable-map rejection, partial snapshot rejection, and struct-key compare encoding.
757. These tests have clear bug-detection purpose and comply with unit-test quality rules.

## Rough LoC Estimate

758. Daemon schema extension: 60 to 100 LoC.
759. Daemon entry_count/all_values_equal computation: 30 to 60 LoC.
760. Daemon live-program enumeration integration: 60 to 120 LoC.
761. Daemon helper write scanner: 100 to 180 LoC.
762. Daemon direct map-value store scanner: 180 to 350 LoC.
763. bpfopt schema parsing and metadata fields: 50 to 90 LoC.
764. bpfopt key-location extractor: 120 to 220 LoC.
765. bpfopt HASH if/else scalarization emitter: 220 to 380 LoC.
766. bpfopt diagnostics/report integration: 80 to 140 LoC.
767. Focused tests: 180 to 300 LoC.
768. Minimal HASH-only total: about 900 to 1400 gross LoC.
769. Adding LPM_TRIE emitter and tests: plus 180 to 320 LoC.
770. Full HASH+LPM robust total: about 1100 to 1700 gross LoC.

## Top Risks

771. Risk 1: Direct-store proof is harder than helper-call proof.
772. Direct stores are common in stats and state maps.
773. A helper-only proof would falsely mark maps like Katran `stats`, Cilium `cilium_metrics`, and Otel `metrics` as read-only.
774. That would be incorrect because their BPF programs mutate returned values (`runner/repos/katran/katran/lib/bpf/balancer.bpf.c:1039`, `runner/repos/cilium/bpf/lib/metrics.h:58`, `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:47`).
775. Risk 2: Pointer semantics may block many high-value sites.
776. Runtime-key lookup replacement cannot generally fabricate a HASH map-value pointer.
777. Scalarization only helps sites whose value use is fixed and local.
778. Pointer escapes, stores, helper arguments, or subprogram calls force skips.
779. Risk 3: Candidate hotness may be too low.
780. The cleanest Katran unlock is hot but only 4 sites.
781. Cilium may unlock more sites only if live entry counts are tiny.
782. Tracee and Tetragon have many matched sites but most are not small read-only HASH/LPM scalarization candidates.
783. Risk 4: Code size can erase helper-call savings.
784. Large struct keys and N=10 chains can approach the cost of a hot helper lookup.
785. Risk 5: Verifier state extraction for runtime key location may be fragile.
786. Missing stack initialization proof should skip instead of guessing.

## Recommendation

787. Implement the redesign only as a narrow runtime-key scalarization path.
788. Do not implement a general "return pointer to snapshot value" path for HASH.
789. Keep the current constant-key pseudo-map-value path.
790. Add daemon-side static BPF-side read-only proof and expose it through map-values.
791. Start with HASH/LRU_HASH, entry_count <= 10, key-byte budget <= 240, full snapshot only, readonly proof required, and scalarizable uses only.
792. Defer LPM_TRIE until the HASH path proves useful.
793. Defer map-in-map.
794. Defer any userspace mutation or invalidation topic because it is out of scope.
795. This path is consistent with v3 because daemon owns kernel/live-program inspection, bpfopt remains a pure bytecode CLI, and runner Python stays unchanged (`CLAUDE.md:96`, `bpfopt/crates/bpfopt/src/main.rs:120`, `runner/libs/rejit_plan.py:78`).
796. It is also consistent with fail-fast because unknown writability blocks the new path instead of assuming safety (`CLAUDE.md:70`).

## Honest Bottom Line

797. The proposed read-only criterion is correct as a safety gate but not sufficient as a performance guarantee.
798. The helper-call savings are real when the map is small, the key is runtime-variable, the site is hot, and the value use is scalarizable.
799. Katran `vip_map` is the best example.
800. Cilium may have useful small control/filter map wins, but current artifacts do not retain live snapshots needed to prove the most interesting entry counts.
801. Tracee and Tetragon likely unlock fewer hot sites than their raw current skip counts imply.
802. Otel has limited remaining room because many constant-key/direct cases already apply today.
803. Expected unlock is small for hot paths unless Cilium live snapshots show small hot read-only service/filter maps.
804. Recommended implementation is still worthwhile if treated as a bounded, diagnostics-heavy pass extension rather than a broad redesign.

## Appendix: Result Summary Ledger

805. Cilium latest result source: `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`.
806. Cilium generated_at: `2026-05-05T18:06:47.519134+00:00`.
807. Cilium map_inline passes: 25.
808. Cilium current matched/applied/skipped: 342/279/63.
809. Cilium statuses: ok 22, skipped_missing_states 2, failed_rejit 1.
810. Katran latest result source: `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`.
811. Katran generated_at: `2026-05-05T18:06:47.519134+00:00`.
812. Katran map_inline passes: 3.
813. Katran current matched/applied/skipped: 68/0/68.
814. Katran statuses: ok 3.
815. Tracee latest result source: `corpus/results/x86_kvm_corpus_20260506_064719_038586/details/result.json`.
816. Tracee generated_at: `2026-05-06T06:55:28.838996+00:00`.
817. Tracee map_inline passes: 158.
818. Tracee current matched/applied/skipped: 3057/133/2924.
819. Tracee statuses: ok 155, failed_rejit 3.
820. Tetragon latest result source: `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`.
821. Tetragon generated_at: `2026-05-05T18:06:47.519134+00:00`.
822. Tetragon map_inline passes: 287.
823. Tetragon current matched/applied/skipped: 3318/0/3318.
824. Tetragon statuses: ok 243, skipped_missing_states 44.
825. Otel latest result source: `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`.
826. Otel generated_at: `2026-05-05T18:06:47.519134+00:00`.
827. Otel map_inline passes: 13.
828. Otel current matched/applied/skipped: 1593/1192/401.
829. Otel statuses: ok 13.

## Appendix: Read-Only Commands Used

830. `rg` was used for fast source search.
831. `jq` was used to inspect existing `result.json` files.
832. `llvm-objdump -dr --no-show-raw-insn` was used to inspect BPF object disassembly.
833. `bpftool btf dump file ... format raw` was used to inspect map BTF.
834. `nl -ba` and `sed` were used to collect source line references.
835. No `make vm-*` command was run.
836. No workload driver was run.
837. No daemon was spawned.
838. No source code file was edited.
839. No `vendor/linux-framework/` file was edited.

## Appendix: Implementation Acceptance Checklist

840. The daemon emits `bpf_write_status` for every referenced map.
841. The daemon emits `entry_count` for every referenced map snapshot.
842. The daemon emits `all_values_equal` only from complete snapshots.
843. The daemon marks partial snapshots as not eligible for runtime-key chains.
844. The daemon treats unknown write effects as not eligible.
845. bpfopt rejects runtime-key chains when `bpf_write_status` is not readonly.
846. bpfopt rejects runtime-key chains when key location is unavailable.
847. bpfopt rejects runtime-key chains when any value pointer use escapes.
848. bpfopt rejects runtime-key chains when the emitted instruction budget is exceeded.
849. bpfopt preserves original NULL control flow.
850. bpfopt preserves original non-NULL scalar value semantics.
851. bpfopt does not add framework performance aggregation.
852. runner Python remains unchanged.
853. All BPF syscalls remain behind `kernel-sys`.
854. ReJIT failures surface through existing result error paths.
855. No BPF program is filtered out of ReJIT.

