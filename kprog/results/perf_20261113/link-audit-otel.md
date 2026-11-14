# OTel actual-link audit, 2026-11-14

The known-map transformations are active. This does not establish a performance benefit: the completed array-only and array+hash timings remain 0.980x and 0.965x throughput.

Job164729 finished04:01:33Z, Make0/application OK, run `corpus/results/x86_kvm_corpus_20261114_040028_424344`. This is a 1x10s stats-on diagnostic on CPUs16–19,4vCPU/16G with pinned linker48af2849d. It predates the shared image refresh66e9e88f. Original launch and observed identities are retained; it is not a floor round.

The capture has28 runtime CLI invocations:14 proof and14 kernel. All succeeded, and every ON replay output matches the corresponding captured bytes. Proof ON/OFF bytes remain identical. Every kernel image, relocation set and map-patch file changes; ABI files remain identical. Eleven separately labelled synthetic host regression invocations also remain in the archive. Fourteen kernel entries include transient read_task_struct and custom__generic; CLI success does not imply14 successful BPF installations or14 measured programs.

| Static call sites | Switch OFF | Switch ON |
|---|---:|---:|
| Generic map lookup |492|124|
| All helper calls |2341|2016|
| perf_unwind_native generic lookup |110|76|

The325 eliminated helper calls are array/percpu-array inlining. Another43 generic calls are retargeted to the existing typed hash helper, preserving a helper call. In perf_unwind_native,26 calls are eliminated and8 retargeted.

The76 remaining generic calls in perf_unwind_native are fully accounted for by the retained binary and source:

| Remaining category | Sites | Evidence |
|---|---:|---|
| Returned inner ARRAY pointers |68|Four frames, each16 bsearch lookups plus1 final lookup;17 RDI arguments copied from R15 and51 reloaded from RSP+0x58. These registers/slots hold the preceding outer lookup result.|
| Outer HASH_OF_MAPS switch joins |4|The16 named outer maps converge before each generic call; current conservative block provenance clears at joins.|
| Named LPM lookup |4|Actual plan explicitly supplies kind=call for pid_page_to_mapping_info, retaining generic dispatch.|

The per-site offsets, argument bytes, result stores and image/relocation/map-patch hashes are in `link-audit-remaining-sites.json`. Original ELF disassembly and upstream source excerpts are in the full archive. The source declares all16 inner map templates as ARRAY and unrolls4 native frames; this is evidence about this artifact, not authority to assume an arbitrary returned map has that type.

Reproduction uses the captured input and actual plan, with only --runtime-known-map-lookups toggled:

```sh
make -f kprog/perf/native-context/Makefile link-audit-replay LINK_AUDIT_REPLAY=/workspaces/kprog-raw/perf/20261114-link-audit-otel/replay-fresh
```

The original replay directory is immutable evidence; choose a fresh output directory. Capture groups, pinned binary/wrapper, commands, plans, complete ON/OFF outputs, all counter snapshots and application logs are retained under `/workspaces/kprog-raw/perf/20261114-link-audit-otel` and byte-compared in `link-audit-otel-results.tar.gz`; receipt `link-audit-otel-results.json` embeds per-entry results.

Map address0 in CLI plans is a placeholder subsequently patched by C++; this audit does not certify the final map ID or lifetime binding. These are static site counts, not dynamic calls or cycle savings. The next candidate is a separate default-off link-time dispatcher using actual runtime ARRAY layout, with generic dispatch for other map types; owner design discussion is recorded in COORDINATION. No workload, app source, kernel, image, default linker bytes, paper or validity gate changed for this collection.
