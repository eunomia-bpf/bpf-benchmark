# Known LPM sites and the existing native trie routine

The next per-call opportunity is to reuse the existing native trie routine
for a map already bound to the kernel trie operation. The native linker
currently sends generic map calls through its native ARRAY/LPM dispatch,
while an exact LPM map's plan selects the kernel trie function directly.
The first step counts actual sites and direct calls before adding a new
kind, metadata or code path.

The reader uses all 295 current production emissions, including numeric
calls and generated functions. It correlates captured addresses with the
sole kernel System.map, retaining independent helper and raw-hash anchor
comparisons for every request. It records named-map lookup diagnostics,
actual external trie CALL relocations and coexisting generic native trie
ranges. Counts describe code, with hotness and per-call gain still open.
It changes zero input facts, programs, source, images, guests or workloads.

The BCC helper-context fix remains in the loader core: CompanionLoad carries
prog_type/context_helpers and maps, while build_native_link_args receives
that companion and no original program FD (native_loader_link_schema.hpp:
54–57; native_loader.cpp:2224–2244,3368). The normal FD entry retains the FD
and the opt-in query at native_loader.cpp:4195–4201. Extending the open
headers with a second helper catalogue would duplicate the authoritative
query. Omp owns that core correctness fix; this LPM inventory is independent.

2026-11-18T00:06:52Z — Reader 68a75af61 completed all 295 requests under timing SH on CPU19, exit0 at00:02:07Z. Each request's independent helper and raw-HASH anchors agrees with its captured generic-map-helper boot slide. These correlations identify actual raw trie CALL relocations; they add zero facts to an input plan.

| App | Requests | Named LPM sites | Direct trie calls | Requests with calls | Also have native generic trie |
| --- | ---: | ---: | ---: | ---: | ---: |
| BCC | 25 | 0 | 0 | 0 | 0 |
| Cilium | 47 | 32 | 32 | 22 | 11 |
| Katran | 1 | 0 | 0 | 0 | 0 |
| OTel | 14 | 52 | 52 | 8 | 1 |
| Tetragon | 39 | 0 | 0 | 0 | 0 |
| Tracee | 169 | 0 | 0 | 0 | 0 |

All 52 OTel sites use pid_page_to_mapping_info. They occur in native_tracer_entry (2), perf_unwind_native (4), perf_unwind_hotspot (28), perf_unwind_v8 (8), perf_unwind_dotnet (6), perf_unwind_php (1), custom__generic (2) and tracepoint__sched_process_free (1). perf_unwind_native already has one 293-byte native ARRAY/LPM range and also makes four direct kernel trie calls. Cilium's names are cilium_lb4_source_range (2), cilium_cidr_v4_dyn (1), cilium_ipcache_v2 (17) and cilium_policy_v2 (12). These are static calls; runtime frequencies and per-call benefit remain measurements.

Source class: native_loader.cpp:2788–2793 selects Call plus trie_lookup_elem for an exact LPM map, and native_loader_link_schema.hpp:158–170 serializes its named lookup spec. x86.rs:1580–1607 then emits the raw target, while runtime_array::share and lpm_lookup::share only intercept the generic bpf_map_lookup_elem target at x86.rs:1833/1867. x86_lpm_lookup.rs:14–21 specializes the existing native trie body to12 data bytes, with other shapes using the kernel helper. Thus exact knowledge can select the kernel operation while bypassing an existing native fast body.

The smallest forward candidate stays in the open schema/linker paths: use the already-loaded MapMeta.type/key_size at native_loader_link_schema.hpp:158–170 to identify LPM with a16-byte kernel key (4 prefix bytes +12 data bytes). Represent that private lookup kind in native-link, then feed its existing native lookup path. Keep every other shape's current direct kernel target. Reusing the existing generic ARRAY/LPM routine first avoids a second trie body; its remaining type tests and possible additional installed routine bytes must be counted. A later direct worker entry can remove redundant dispatch if the app timing supports it. This uses loaded map facts and exact native RDI provenance, with the same trie walk and helper observations. It introduces zero new kernel helper identity, refusal, runtime mode switch or map catalogue.

Validation for that candidate: a focused named-map binding fixture with eligible/ineligible shapes and generic/kernel targets; existing 65590 trie/guard/ABI and34920 bit/prefix/flag executions; full linker suite and all295 captures. Old plans lack the new private kind, so label their unchanged replay as compatibility coverage; current loaded-shape candidate emission requires actual header serialization in the next image, or an explicitly scoped host fixture. The frozen image/check/OTel stats-on default timing then measures installed native/JIT bytes, per-call, throughput and body/helpers/maps; Cilium shape selection follows actual loaded facts. Count only actual generated and installed paths.

The helper-context query remains at native_loader.cpp:4195–4201, where the original FD is present. CompanionLoad at2224–2244 and build_native_link_args at3368 receive no original FD. The open schema cannot perform that authoritative original-program query as currently called. The existing coordinator-owned core query and obsolete flag plumbing remain the phase1 fix, using the already recorded BCC diagnostic; duplicating helper-name variants in an LTO header would add a second resolver.

Raw: /workspaces/kprog-raw/perf/known-lpm-sites-20261118/host-20261118T000207Z-2824534. Host2824534 is terminal. Source, canonical CLI/base/image and peer checked Tracee guest2754970 remain unchanged.
