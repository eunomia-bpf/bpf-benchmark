# kprog optimizations

Operator, 2026-11-14: "然后你要想办法优化一下, LTO + native 我觉得到 40% 性能进步是完全肯定可以的. 先确保管线正确, 然后开始考虑优化. 每一个优化也得记录在哪里怎么做的."

Every optimization of the native path is recorded here: where it lives, how it works, which pipeline step it belongs to (design.md 编译流水线: step 1 compiler flags when P is produced, step 3 link-time optimization), how its correctness is checked, and its effect in the combined configuration (all pieces on together; the operator: "不需要这样细粒度区分. 只需要都做就好."). The lane that lands an optimization adds or updates its row in the same commit. Effects are per-call native/eBPF on the combined configuration, with the run directory.

PERF 2026-11-19T09:46:49Z: Phase-1 LOCK correction in the generator and shared
x86 I retains atomic memory effects in both B and native. It is a pipeline
correctness change, with no runtime gain claimed. All C/LTO pieces remain
on. Host checks pass 17,424 hardware flag/memory cases, 80,000 concurrent
increments, private-stack/recovery cases and 22 B/native compilations.
Coordinator batch 327120 measures this together with 2eb36bad9; previous
BCC 1.016x predates the fix. Source and exact scope are recorded in
results/lock-prefix-review-20261119; actual stock/app coverage and timing
are pending. Native O3 and the frozen benchmark remain unchanged.

| Optimization | Step | Where (code, switch) | How | Commit | Correctness check | Status |
|---|---|---|---|---|---|---|
| Immutable scalar map configuration in IR LTO | Trusted load-time LTO | native_loader.cpp, native_loader_context_lto.hpp, perf_context_lto.cpp and existing module direct-value query | Use the kernel's RDONLY_PROG/frozen/no-writer condition; snapshot loaded singleton ARRAY data, bind scalar globals through map IDs and BTF offsets, and fold complete integer loads before O3. Volatile scalar reads can fold; atomic and aggregate accesses stay intact. | this commit | Contrary scalar snapshots and mutable/aggregate/atomic boundaries pass; real BCC sys_exit proof text 418→305 B with the source-derived workload setting count_by_process=0. Four raw entry extractions, compiler/loader builds and active x86 module syntax checks pass; immutable-config-lto-20261116. | Source integrated with context/function/helper/map LTO. Host BCC value is not a guest capture. Kernel eligibility, actual loaded values, installed bytes, body/helper/map profiles and per-call effects pending coherent publication after C's round. |
| Bind map update/delete operations | Link-time native calls | native_loader.cpp, native_loader_link_schema.hpp, native_link x86.rs and existing module FD query | Query only known source map operations, bind facts through loaded map IDs to native names, then select the target from proven native RDI provenance. Direct sibling transfers share selection. Delete both old ordinal array-update emitters. | this commit | 49 linker tests pass (3 existing ignored), including reversed native map order and missing-fact generic calls; production linker/loader builds and active x86 module syntax checks pass. See map-ops-binding-20261116. | Source integrated with the other LTO pieces. Actual FD-query guest behavior, installed bytes and per-call effects await coherent publication after C's round. Arm retains generic operations pending sound argument provenance. |
| Shared native tail-frame metadata | Native load / frame contract | native_loader.cpp, ordinary and registered direct-native entry | Share the existing verifier-visible stub marker; derive reachability from linked counter relocations as well as source facts and retain the marker map through load. | 3821bf1dc | Three host stream-contract cases, including map FD zero, and loader rebuild pass; cilium-cb-frame-20261116/stub.json. | Correctness completion for direct fallback. New-kernel guest frame, installed bytes and per-call effects remain queued after C's round with the combined image. |
| Kernel-derived public cb and one native frame mask | P layout / native entry | core-answers.py, Cilium native context, native-link, direct loader and x86 native JIT | Derive public cb from sk_buff.cb plus qdisc_skb_cb.data and retain the intended tc_classid clear. Kernel saves only the registers moved out of P; direct and registered images carry that same mask, including tail cleanup. | ed85c9c02 / kernel 83e0fabe355d | Host layout passes at cb 48/classid 46, preserving surrounding bytes; 48 linker tests pass (3 existing ignored); loader and seven Cilium P objects rebuild. See cilium-cb-frame-20261116. | Mask-zero images remove 14 wrapper bytes by instruction accounting; rebuilt cil_from_container P adds 6 B for the intended classid clear. Actual installed bytes, packet comparison and per-call time pending publication after C's round through the frozen recipe. |
| Numeric helper sibling exits | Linker / B generation | native_link x86_helper_provenance.rs and x86.rs; shared generator / x86_abi.py | Resolve singleton or finite helper IDs at indirect JMP, retain the native entry exit, and model the existing helper followed by caller return in B. Uniform sibling-call optimization stays enabled. | this commit | 49 Rust tests; 48 native execution cases with argument, stack and epilogue checks; actual compiler fixture B passes stock on the sole kernel. | Pipeline support only; no timing gain claimed. See numeric-helper-tail/README.md. |
| B debug-variable updates | B compiler | packet_bounds_ir.cpp, normal path | Drop nonexecuting dbg.value/declare/assign intrinsics before B instruction selection; keep instruction locations, function/type/global metadata and BTF. Original frontend IR for checked-native stays unchanged. | this commit | Map fixture:128B code/32B map/1062B BTF types and function info exact;20ordinary instruction locations retained, one diagnostic line record removed.60identity/4context-width/normal backend pass (e8c0f32cf). | Source/focused checks; base publication and actual100K effect pending. Existing100K control unchanged;1512837debug updates/backend getStableDebugLoc diagnosis recorded. No runtime gain. |
| Monotonic clock call linkage | LTO | native_link x86 runtime_call_target; loader link-schema/kernel-symbol cache | Bind actual bpf_ktime_get_ns calls/tail transfers directly to the same boot kernel ktime_get_mono_fast_ns. Keep helper IDs/address observations, original helper availability and proof semantics; normal plans/cachev41 bind the boot fact. | 51fcc939f, fbee52b39; this receipt | 44 Rust tests pass; seven ELF/execution call shapes and missing/zero negatives; actual ten-type kernel queries and serialized XDP plan match independent kallsyms. See clock-lto/report.md. | Paired base published17:42:02Z; image d4b19c9f published17:47:36Z with actual shipped CLI64eb98aa/runtimeSO928a1558/shim19f2f67a matching canonical inputs. Removes wrapper instructions, not clock read. Actual timed Katran map-plan audit and combined timing remain open; no gain claim. |
| One boot-kernel LTO fact set | LTO | loader native_loader_lto.hpp and normal native-link structured plan | Collect ARRAY/hash/LPM/probe facts from boot BTF/kallsyms, include them in the cache identity, and apply all LTO pieces together. Four layout selectors, optional load-site selector and six shell wrappers deleted; recovery metadata accompanies the ABI. | 73ef21ede, bde7aae19, 971dc5f25, d50c6994a, d34ba357f; this result commit | Actual boot BTF equals canonical ELF; 38/38 facts equal independent C resolver, loader syntax passes, 13 map executions, 8 code-table targets and 320 native + 320 shared-simulator executions pass. Both metadata recovery and loader/linker pairing incidents retained in normal-layout-plan/report.md. | Normal paired base and actual functional probe/map/ARRAY tests now pass after the runtime symbol-cache fix e1e96deff; see lto-symbol-cache/report.md. No new performance claim. |
| Relative tables with the real entry context | phase 1 | normal linker/B compiler; native_jump_table_context.c | Finite code-table state is specialized using existing liveness semantics while the actual single KPROBE context supplies index and case operands. Native compiler keeps jump tables, target CPU and sibling calls enabled. | 7e4eabb78, 2d7297ec1; this result commit | Eight code targets, 512 native + 512 full shared-simulator host executions; normal B compilation and actual original/generated B stock loads pass. See table-context-stock/report.md. | Actual checked-native installation now passes on the normal paired base (lto-symbol-cache/report.md); application tables remain open. Checked PIC/table/sibling restrictions were removed; no timing or native code-size gain claimed. |
| Boot LTO symbols in the runtime cache | phase 1 / LTO | native_loader_lto.hpp required symbols and native_loader.cpp kallsyms cache | Retain all seven symbols requested by the normal boot-layout writer, deduplicating names already used by helpers. The runtime filtered cache must supply the same facts as the standalone full-kallsyms resolver. | e1e96deff; result 83d9ab8d9 | Loader syntax passes; first real functional runs exposed the missing nmi_uaccess_okay despite correct boot facts. Registered table B verification and checked compilation passed, native installation failed before binding. | Corrected same-base publication and all five actual functional subsets pass, including both checked installations. See lto-symbol-cache/report.md; first failures retained, no off path or fallback. |
| Helper identity through actual control flow | phase 1 / LTO | native_link x86_helper_provenance and relative-table CFG targets | Bind a register call only when all reachable predecessors agree on its helper identity; model copies, partial writes, call clobbers and table edges. Keep observed helper-ID/address values; use the same facts for tail-frame setup. Remove lexical tracking and adjacency lookahead. | 399a6bab0; this result commit | 38 Rust tests pass (one existing ignored); host counterexample checks correct helper target and numeric observation. Actual rebuilt Tetragon has 252 resolved helper calls including 39 R13 sites with distinct IDs 4/113. | Source/host support; actual full proof reaches a separate shared-rodata table-range failure. No kernel/base publication, app acceptance or performance gain. |
| Referenced anonymous code-table ranges | phase 1 / LTO support | native_link readonly table_span, proof and kernel PC32 binding | Split an anonymous section container into the actually referenced table slots, bounded by all source entry-table starts; preserve nested code identities and rebase PC32 addends in both links. | a7383af15, f94aa8daf; this result commit | 39 Rust tests pass (one existing ignored); two clang roots retain eight slots each and pass 128 native host cases. Normal B and 64 full shared-simulator cases pass. Actual rebuilt Tetragon root now rewrites proof (12003 blob bytes/81 nested relocations); same-source KPROBE reference and generated B stock loads pass (IDs5/7). See rodata-spans/report.md. | Source/host and fixture stock support; remaining real objects and application B/stock/checked acceptance open. No runtime/code-size gain claimed. |
| Immutable map-pointer table linkage | phase 1 | x86_readonly_relocs, normal proof/kernel binding and x86_map_tables B lowering | Preserve nested symbolic map pointers, bind full-width capabilities, and specialize dead-private-base indexed selections into existing MAP/value-tag operations. Flags/index and CFG entries retain their semantics. | 8d4c8b24c, c551f3566, 01ad66426, 3d834a0e4; this result commit | Actual OTel shape has 16 slots; real clang fixture has eight. 20 native/full shared-simulator pointer/tag cases, three dataflow refusals and missing-capability refusal pass; 34 Rust tests pass. Relative-code regression 320+320 passes. See map-pointer-tables/report.md and map-table-b/report.md. | Valid eight-map lookup/scalar-root normal B compilation and 128 native/full shared-simulator host cases also pass (map-table-lookup/report.md); fixture stock/checked installation also passes after e1e96deff (lto-symbol-cache/report.md); application acceptance remains open. No binary/base publication or app/performance gain claimed. |
| Checked simulator native flags | trusted compiler | compile_sim_ir.cpp and trusted_specializer.py checked emitter | Remove forced no-jump-table/no-sibling attributes and PIC; use O3, target CPU, sibling calls and omit-frame-pointer with kernel GPR/no-red-zone constraints. Normal linker binds the resulting real code table and private input capability. | 6e8b11208, a7af36eaf, 99c31dd2e, e3cd8ee93; this result commit | 512 checked-table host cases, 25 physical packet-context cases, 8 safe fault cases/two SIGILL children/unknown-asm rejection pass. See checked-codegen/report.md. | Paired base publication and actual checked-native table installation pass after e1e96deff; see lto-symbol-cache/report.md. No runtime or app size gain claimed. |
| Unused private input reads | candidate | checked compiler's unspecified-input capability | The actual checked table starts with 24 volatile reads whose values do not reach its context arithmetic; inspect whether trusted input semantics permit removal or consolidation. | not implemented | Actual object/disassembly retained in checked-codegen; fixture has 191 executable bytes. | Candidate after phase 1 and actual-app attribution; no measured runtime cost or optimization claim. |
| Shared ARRAY and normal helper LTO | LTO | native_link x86 runtime-array/probe-read/per-CPU path | Always share dynamic ARRAY routines, include kernel-string reads with their fault-recovery metadata, and use the checked per-CPU lowering. Remove three independent opt-ins, expanded ARRAY off variant, and duplicate legacy CPU routine. | this commit | 33 Rust tests pass (one existing ignored),6 real map host cases and6 named/numeric helper-shape cases match; normal-map-helper-lto/report.md. | Kernel layout inputs still need migration into the normal link-plan facts; remaining layout selectors/wrappers are open. |
| Exact-map and actual-pointer lookup dispatch | LTO | native_link x86 normal kernel path | Always trace RDI map provenance through control flow, use exact map identities for typed LTO, and dispatch dynamic maps with their real pointer/helper. Remove positional/truncated-name selection, duplicate linear tracker, and both CLI opt-ins. | this commit | 34 Rust tests pass (one existing ignored) and6 actual clang/proof/kernel-link map host cases pass;33 tests after helper consolidation. See normal-map-helper-lto/report.md. | No isolated timing; runtime-layout/helper selector consolidation follows. |
| Kernel-resolved tail-counter frame | LTO | native_link x86 tail-call path, normal kernel relocation | Always emit kind10 for the counter-pointer displacement after final chunk/branch layout; kernel binds the one current JIT frame. Target-entry offset remains a separate kernel fact. Removed CLI selector and stale unrelocated path. | this commit | 36 Rust tests pass (one existing ignored), including production immediate/PLT helper ELF and saved/live-RBP patch regressions. See normal-tail-lto/report.md. | Normal-path cleanup 2026-11-15T02:12:10Z; no new timing claim. |
| Linker-owned GPR memset/memcpy | LTO | native_link x86_memory, normal proof/kernel path; opt-in and off branch removed | Bind standard memory calls to the existing checked GPR routines and share equal routines. Normal operation no longer depends on a candidate wrapper. | this commit | 38 Rust tests pass, including actual emitted-routine/proof/kernel roundtrips;22 normal-output repeats and6 map-LTO cases pass. See normal-memory-lto/report.md. | First LTO-selector removal under coordinator01:23; remaining map/layout/helper selectors are next, no new timing or isolated-gain claim. |
| Relative jump-table relocation preservation | LTO support | native_link `x86_readonly_relocs.rs`, normal proof path | Copies nested PC32 code-table relocations into proof rodata; derives the actual table base from clang's LEA/MOVSXD/ADD/JMP sequence and remaps each target to the rewritten instruction boundary, including table-slot bias. | this commit | 38 Rust tests pass; all8 actual clang proof targets match source boundaries,320 native host cases match source reference, malformed target rejected;22 real-object parity and6 map-LTO host cases pass. | Proof/kernel rebinding and dead-private-state B dispatch implemented. Actual native/shared-simulator host results match320 cases each; live carry/partial-register counterexamples refuse lowering. Stock and single-context checks pending; see relative-table-b-host/report.md. No app speed or size claim. |
| Non-PIC map-address binding | LTO | native_link `x86_non_pic.rs`, normal linker path (temporary switch removed under operator00:33 cleanup) | R_X86_64_32/32S/64 map-address MOV or PC32 LEA becomes full-width MOVABS with the existing live map-patch ABI; proof objects use the existing symbolic GOT-load ABI. Named-map provenance remains available for combined lookup LTO. | this commit | 36 Rust tests pass; four address forms preserve high pointer bits and DATASEC member offsets keep their live binding. Real clang/proof/B decoder/lookup LTO passes six host executions; 22 existing real-object proof allocations/relocations equal the prior binary across the normal-path change (distinct binary hashes). See non-pic-map-addresses/report.md. | First HARD-native compatibility step; absolute memory references, jump tables and application timing remain open. No speed or size gain claimed. |
| Array and per-CPU array lookup inlining | LTO | native_link `select_lookup_site`, `--runtime-known-map-lookups` | a lookup whose map is a proven named Array or PerCPU map becomes the bounds check and address arithmetic the kernel's array_map_gen_lookup emits | 6cf9f5cd9 | 22 real objects byte-identical with the switch off; OTel 325 sites inlined | on |
| Shared typed hash lookup | LTO | native_link select_lookup_site/resolve_lookup_site_target; existing kernel __htab_map_lookup_elem | Hash/LRU/per-CPU/map-in-map callers keep the boot kernel raw lookup call, shared across programs and loads; caller value/per-CPU/LRU processing remains. Delete the per-program 2444 B emitter and its layout/fixture code. | 48af2849d; this forward change | Host layout/link/postprocess subsets pending; next BCC stats-1 comparison uses frozen entry defaults. | Normal path, no selector or new kernel allocation. Installed bytes/per-call after publication pending. |
| Runtime array dispatch | LTO | native_link, `--runtime-array-layout PATH` | array lookups in runtime-map mode use the target kernel's bpf_array layout from the boot BTF (elem_size 288, index_mask 292, value 304) | 9f51cfee7 | 27 host tests, 28 real link commands byte-identical with it off | on |
| Kernel and user memory reads as direct loads | LTO | native_link probe-read emitter, `--runtime-probe-read-layout PATH`, `--abi-load-sites true` | bpf_probe_read_kernel/user calls become direct loads with an EX_TYPE_BPF exception-table entry; a fault clears the destination and returns -EFAULT as the helper does | de0c62bd9, c2bb11c15 | kernel 36/36 executions in both configurations; 121 fault cases each way | on |
| smp_processor_id as a per-CPU load | LTO | native_link `helper_call_name` (`__native_x86_cpu_number`, `__native_x86_this_cpu_off`) | the helper call becomes a GS-relative per-CPU read, as the kernel inlines it | existing | Three actual emitted GS-load variants execute on the host (legacy CPU, direct CPU, full-width task); actual Tracee 172-entry proof parity/CLI success. Whole-app kernel results pending. | on |
| LPM trie lookup | LTO | native_link LPM emitter | runtime map type and BTF layout dispatch; fixed 12-byte key data compared with BE XOR/BSR, preserving longest match, intermediate nodes and invalid-prefix fallback | 74dd78efc | 65590 host oracle vectors; 3360 actual stock/native kernel executions in both configurations | combined with read/hash/array; stats-on per-call 0.889810x (x86_kvm_corpus_20261114_112435_142525), throughput 0.843922x stats-off (115024_659937); below target  Spatial profile after combined CPU/CMOV flags: LPM3587.61 sampledcycles/entry vs previous3606.32; helper bytes unchanged outside three proven kernel-address fields. This is attribution, not per-lookup latency or a component timing. |
| Extra LFENCE removed | LTO | kprog/x86/native_lab/native_link/src/x86_probe_read.rs | the probe-read emitter put an LFENCE before each user-memory access, copied from the barrier in the generic copy_from_user path; the kernel's nofault copy that bpf_probe_read_user uses is STAC, copy, CLAC with no LFENCE, so the emitter now matches it (OTel unwinder 33098 to 33095 bytes, 696 read sites) | 85db641d2 | real kernel 18+18 executions in both configurations, default bytes equal | combined read/hash/LPM/shared-array: per-call 0.889810x, stats-off throughput 0.843922x; extra fence removal alone does not solve regression |
| Target-CPU code generation | step 1 | `kprog/build/otel-native.py --combined-codegen` (OTel); other apps remain C | `-march=native`, same original linked/physical IR and GPR-only ABI | this commit | Original physical bitcode equal; disabled full ELF7e678147 reproduced exactly; actual candidate ef44985c193e | Combined with CMOV/sibling/runtime LTO; Combined3x180: per-call1.11335x stats1 run145101_018174; primary frozenmedian throughput1.04432x stats0 run151641_871572. Both appOK/0errors, below target; checked guest resident20-23, so not exclusive-host acceptance. |
| Katran map-lookup sinking | step 1 | kprog/build native_specialize_maps.py | map lookups sunk into the C unit before codegen | 529dd6d35 | same-day A/B 102.69 vs 103.11 ns/run | dropped: no gain |
| Branchless select (cmov) removal | step 1 | `otel-native.py --combined-codegen`, `-mllvm -x86-cmov-converter-force-all=true` | Convert dependency-heavy selects into branches; OTel root28937->27118B,140->0 CMOV,613->692 jcc | this commit | No SIMD register operands; real main proof CLI PASS; 10-second combined guest appOK; zero collector/workload errors | Compiler-proven root Spill/Reload442->209 (byte-equal reassembled sections). Clean45s root sample1831.11 vsJIT2257.21 cycles/entry (body-only1.23270x; earlier native2874.76). Combined3x180 collected: per-call1.11335x; stats-off throughput1.04432x, below target. Own windows/frame yields retained; concurrent checked guest documented. |
| Kernel string reads and direct per-CPU helpers | LTO | `x86_probe_read.rs`, `--runtime-probe-read-strings` with existing read layout; `--runtime-percpu-loads` | Kernel-str byte loop with existing R11 fault recovery, exact NUL/count/error rules; GS current-task/CPU loads reuse target facts and helper-anchor rebasing. User-str and missing-fact cases retain original paths. Default off; proof unchanged. | this commit | 33 Rust tests; 191 string vectors/121 faults; 3 emitted per-CPU variants; 11 real default output groups equal; Tracee 172 proof/kernel CLI pairs pass offline | C lane can activate in combined configuration; kernel-string/whole-app result pending; no gain claim |
| llvmbpf code-generation diagnostic | step 1 diagnostic | vendor/llvmbpf existing API, kernel-compatible mode and explicit GPR-only target features; raw 20261114-llvmbpf-diagnostic | Same original BPF program, 204 normal resource-address relocations; O3 generic, O3 arrowlake-s, O2 arrowlake-s. Captured verifier per-CPU MOV offset -1 is unsupported and was not replaced by a fake instruction. | this commit | All three source AOT runs succeed, no SIMD registers with explicit disabled features; actual source/addresses/options retained. | All three GPR text sizes 35089B; diagnostic only, no app execution or gain; source stream differs from verifier-pruned JIT. P/default flags unchanged. |
| Sibling calls permitted | step 1 | `otel-native.py --combined-codegen`, `-foptimize-sibling-calls` | Relax four upstream `disable-tail-calls=true` IR attribute groups to false; preserve semantic IR | this commit | llvm-as verification PASS; emitted full ELF equals previous targetCPU+CMOV candidate ef44985c193e, so no extra machine-code effect here | Enabled in combined candidate; no isolated timing. |
| Jump tables investigated | step 1 | OTel combined producer; `-fno-jump-tables` retained with actual reason | Enabling tables yields25899B root but creates anonymous `.data.rel.ro` tables containing16 live map pointers; current linker has no DATASEC identity for that compiler table | this commit | Actual main proof fails `mutable section .data.rel.ro offset 0x0 lacks its data symbol`; rejected object/all stderr retained in raw20261114-otel-combined-codegen | Disabled where linker cannot bind the table. CPU/CMOV/sibling and every implemented runtime LTO remain on together; no fake resource symbols. |
| LPM child-load overlap | LTO | x86_lpm_lookup.rs, existing --runtime-lpm-layout opt-in | Sole-kernel max_prefixlen=data_size*8 makes12-byte shape96bits; read next child before prefix work, skip full-depth bit96, consume only after matching, preserve generic fallback ABI | this commit | 65,590 host vectors;33 Rust tests/1 existing ignored;11real-object default full proof+kernel metadata groups equal;3,360 actual stock/native executions across both configurations,12-byte inline+4-byte generic fallback | Combined corrected3x180 result: stats-off frozen median throughput1.161336x (run180807_307289), stats-on aggregate per-call1.129008x (174202_766748), below1.20. Each14native replacements/0loader failures. No isolated-component gain attribution; co-resident heavy guests/host compilers and missing first live baseline boundary disclosed. |

Compiler cost (B generation, without changing P or runtime semantics): the static known-helper specializer selects the existing dispatcher case before macro expansion. OTel original C731104B expanded to1011998390B, of which624205306B was the helper switch. The change derives70 case/body pairs from the unchanged C dispatcher; dynamic/unmatched IDs keep its original path. On a real Cilium proof26calls, preprocessed97,335,470->46,844,405B with identical allocated B bytes and202relocations.62archived Cilium proofs change only3272literal call spellings; actual OTel read_task_struct/stop stock verification and checked-C installation pass, both B and checked-native allocated bytes/relocations equal old accepted inputs. Full OTel main B compile complete: allocated bytes and all3339 allocated relocations equal,1,011,998,390->370,116,027 preprocessed bytes (-63.43%); frontend3623.10s on shared E-cores, no controlled speedup/RSS claim. Actual checked main now reaches verifier with512-byte frame but fails tailcall ctx typing; still no main acceptance. No runtime gain or M4 completion is inferred. Evidence: static-helper-specialization-result.json.

Verified compiler cost: `trusted_specializer.py` now reuses the exact pre-bounds LLVM IR that produced B when compiling the checked native program after stock acceptance. Source and IR SHA256 bind that reuse; old artifacts without the record retain fresh compilation. Cached/fresh native allocations and relocations match; source/IR mutations fail before native output. Actual sole-kernel checked-C fixtures pass 1,680 stock/native oracle executions, with reuse records and no second C frontend invocation in both request archives. This removes a redundant frontend invocation, not a measured runtime gain or OTel-main acceptance. Evidence: frontend-ir-reuse-result.json and frontend-ir-reuse-evidence.tar.gz.

Latest combined OTel measurement (all pieces together; corrected source maps and same ef449 P): stats-off median throughput **1.161336x**, stats-on aggregate per-call **1.129008x**; both3x180, appOK, zero workload/collector errors and14native replacements each. Target1.20 remains open. Stats-off paired ratios1.198247/1.198220/0.969553; no sample dropped. Selected actual-owned metric windows (full query clocks, inside measurement) have native frame/attempt0.923701->0.923337 and dispatch/attempt0.241308->0.238901; Python frames0->228545 and other family/error counters differ, so do not assert exact semantic equivalence from the throughput ratio. Census24G and checked48G guests were resident; first stats1 baseline boundary was missed live and marked retrospective. Full receipt/collection scripts/raw logs: otel-corrected-all-lto-timing-result.{json,tar.gz}. No isolated runtime-LTO timings or checked-C whole-app acceptance.

Compiler-private scalar spill packing diagnostic (2026-11-14): the actual OTel ctx rejection follows known tag1 stored at fp-388 becoming unconstrained32 on reload. Four sole-kernel load-only cases reproduce it: independent8byte-aligned u32 accepts, upper-half and either paired-half variant reject tail-call scalar ctx. Thus pair-only packing also loses verifier precision and is not a compiler fix. No simulator/ISA/default changes; next investigate spill lifetimes or codegen that keeps scalar slots independent. Receipt: scalar-spill-precision-result.json.

Follow-up: all12 matched B backend cases (O2/O3 with deferred/reverse allocation; basic/split-size/rematerialization/loop-IV variants) retain520-byte frames. Conservative CFG spill analysis finds no noninterfering pair (partial writes keep whole old slots live); it does not prove minimum register demand. Two more actual sole-kernel cases show64-bit whole-word store/reload plus half extraction preserves tag1 even when the other half is runtime-unknown. This is a candidate lowering mechanism, not an implemented full compiler transform or OTel-main acceptance. See scalar-spill-codegen-result.json and full verifier logs.

Optional B backend (2026-11-14): `KPROG_BPF_WHOLE_WORD_SPILLS=1` selects
`kprog/x86/whole_word_spills.py` between physical register allocation and frame
layout in `trusted_specializer.compile_simulator`; the default value is zero.
It stores two final compiler-private scalar spills in one aligned word,
preserves the other half on stores and uses explicit shifts for truncation.
The fixture's original and corrected programs each match 1,060 actual stock
kernel executions, including overflow and a live register across a block
boundary. The initial self-copy counterexample is retained. Default and
explicit-zero objects equal the previous compiler command byte for byte;
the optional pipeline also preserves allocated bytes for an independent
register fixture. Corrected OTel main now passes stock verification and checked
native installation (20e909db6). The automatic selector also emits exactly the
retained accepted main MIR, choosing slots17/18 and27 accesses (dd3fd2845;
`otel-whole-word-corrected/backend-main-parity.json`). The fresh whole-app startup also installed `perf_unwind_native` as checked
native41 at21:12:37Z (request3; `otel-whole-word-live-main/report.md`).
Remaining application startup, execution and own-counters continue. Runtime P and the pre-bounds IR used by the checked
native compiler retain their existing definitions. This is B generation for
verification feasibility; the combined runtime ratios retain their prior
scope. Evidence: `whole-word-spill-values/report.md`, and raw
`20261114-scalar-spill-precision/backend/{result,commands}.json`.

Optional tracing-context B lowering (`c5e3ba2c2`):
`KPROG_BPF_CONTEXT_LOADS=1` forwards `--canonical-ctx-loads` to the B IR
compiler. For KPROBE constant loads rooted in the original context, it keeps
the root operand and encodes the proven displacement in the memory instruction,
including an empty tied-register identity barrier. The load width, volatility
and narrow-result zero extension are preserved. Default zero retains the
existing B compiler invocation. This phase1 compiler representation change
targets the modified-context rejection seen in census body70; host byte/width
checks and actual stock-kernel load tests pass for8/16/32/64-bit reads at80:
four original forms reject and four rewritten forms load. `5a75da273` requires
an explicitly tied empty identity; untied outputs retain their representation.
Both refined fixture objects equal those loaded in the kernel. Evidence:
`context-loads/report.md`; whole archived-body replay is queued after the active
OTel job, with24GiB AS/CPU19 and the frontend IR retained for reuse.
The shared simulator C, runtime P and pre-bounds IR used by checked native
compilation retain their definitions. Whole-body replay and runtime effects
remain to be measured; combined LTO timing retains its existing scope.

Optional packet-field identity matching: `KPROG_BPF_STRICT_IDENTITIES=1`
forwards `--strict-identities` in the B-only IR stage. A packet field inferred
through empty asm must have an explicitly tied output (`=r,0`). The default
zero preserves the prior matcher. An actual untied-output counterexample
returns0 before transformation and in strict mode, versus1 with the old
matcher. Original/strict native executions match an independent reference in
all60 cases. Legal BPF untied constraints and service flag forwarding also
pass. Default bitcode equals the prior compiler; two retained Cilium inputs
have zero eligible predicates and provide compatibility controls only.
Both options together preserve the context-only bitcode and the exact
previously kernel-tested fixture ELF bytes. This changes B guard inference;
runtime P and the checked-native frontend input retain their definitions.
Evidence: `packet-identities/report.md` (a267788ea/3ed4d58e9/977e9acef/42959d7d7).
Whole-application acceptance and combined runtime timing retain their scope.

Candidate after the current OTel work (advisor21:21, not implemented): bind
`bpf_ktime_get_ns` to the same kernel monotonic clock implementation at link
time. C's Katran profile attributes34% of BPF time to that path. First check
which clock implementation the sole kernel helper actually uses; preserving
its clock basis and concurrency rules is required. The sample share is not a
predicted gain: removing a wrapper leaves the clock-read cost. This candidate
will use the combined LTO configuration and focused correctness checks before
any performance claim.

Compiler storage (354bfbcbb): after successful preprocessing, each temporary
piece C/expanded input is removed once its tokens are joined. The canonical
simulator C and joined input stay. A two-piece comparison against the prior
compiler loaded from git into memory produces identical joined/default B
bytes; explicit0/previous backend/optional allocated-output controls pass
(0e4593e46/bffd94728, `preprocess-cleanup/report.md`). No runtime gain is
claimed; existing live services retain their imported function.

Optional B spill groups (4c2c594c0):
`KPROG_BPF_WHOLE_WORD_SPILLS_ALL=1` with whole-word spills enabled selects
independent scalar pairs throughout the physical spill list, including pairs
before a later non-scalar spill. Its default is zero and the existing
single-pair CLI selection stays unchanged for the running OTel service.
Selected scalar slots still require direct four-byte accesses; the same
whole-word masking and physical-register liveness mechanism is reused.
This addresses the known fp-544 stack class with a32-byte packing opportunity;
it changes B storage only. Sparse frame-ID tests reduce544->512 and80->48;
actual stock kernel rejects the original544-byte form, and the small control
plus both packed forms match3180 actual reference executions. Existing
single-pair MIR/selection equals the prior compiler with the mode off.
Evidence: `spill-groups/report.md`; service wiring and actual-body replay
remain next. No application acceptance or runtime gain is claimed.

Spill-group register-pressure follow-up (54477bc97 / 2a372dc99): reuse a dead
store source when possible; otherwise save live scratch registers in private
eight-byte slots and restore them after the whole-word update. Nine variants
pass9540 kernel executions, including restoring and using a live context
pointer. Measured depths16->8/16->16/16->24 show that temporary saves can
outweigh packing. Service/default-byte checks pass; real main replay still
fails on a `dead` load annotation. Mode remains default-off, no whole-body
acceptance or performance gain. See spill-groups/report.md.

2026-11-15 hotspot follow-up: `replay_hotspot_spills.py` streams retained
request 5 from the existing service archive and tests the existing all-pairs
mode on its actual pre-PEI MIR, with machine-instruction verification. The
original 25 spill slots include ten scalar slots; five selected pairs need
18 scratch-save sites. Job 819162 finished: actual depth is 552 bytes against the original 576,
still beyond 512; codegen took 359.08 s. The 19,809-block conservative lifetime
analysis found no noninterfering pairs. Archived bounds invocation lacks the
current explicit canonical/strict options, so fresh normal B replay remains
necessary. See hotspot-spills/report.md. Production compilation and the mode
default are unchanged; no stock acceptance or runtime gain is claimed.

Target-BTF CO-RE audit (9ab6012a8 / b244f3cfc): all13 relocation kinds match
original-ELF/libbpf answers on the sole kernel (22 fixture records). Existing
resolved Tracee/BCC reports also match, but selected direct-native producers
bypass them. Static127-object audit finds differing answers in Tracee, three
BCC objects and43 Tetragon objects;601 records remain unobserved. The resolved
producer choice stays explicit/default-off, with existing writable DATASEC
binding. This is correctness work with no speedup claim; see core-audit/report.md.

Optional target-BTF widened zero comparisons (768932a16):
`--widen-zero-compare` defaults false and uses the original ELF's actual load
and first consuming zero jump to select32/64-bit comparison semantics. It
preserves the existing explicit error for other unsupported widened uses.
Six CPU/predicate cases pass6210 sole-kernel BPF executions against emitted
userspace native code; v2 cmp64 and v3/v4 cmp32 both exercised. Disabled
all-kind bitcode/reports equal the prior binary, and retained Tracee370-query
bitcode is identical with off/on. This is a correctness extension with no
runtime-gain claim; `core-zero-compare/report.md`. Producer selection remains
C's integration task; every LTO piece stays in the combined configuration.

Katran next combined configuration (operator/advisor23:41, preparation only):
use existing KATRAN_SAME_SOURCE=1 and KATRAN_SAME_SOURCE_CODEGEN override to
apply the18:40 target CPU/forced-CMOV/sibling-call flags, retaining existing
no-jump-table/general-register constraints, with every current LTO piece.
C owns producer/timing changes; PERFs subset timing follows remainingOTel.
The clock candidate calls exactly ktime_get_mono_fast_ns: the sole kernel's
bpf_ktime_get_ns already returns that function (kernel/bpf/helpers.c:178), so
direct link binding can remove the wrapper, not the clock-read cost or change
its NMI/order semantics. It remains unimplemented pending the combined baseline.
C4 accounting is now committed in katran-c4-accounting/report.md:1.075982x
successful-send throughput decomposes into1.058541x attempted rate and1.016477x
admission fraction. Correct raw profile denominators are208.42M eBPF/217.10M
native; program-text samples73.174->71.620 per million do not establish the
previously quoted6percent body slowdown. Inlined-helper work is included in
that bucket. No new performance gain or serial45percent fraction is inferred.

Katran profile scope follow-up (be28ce768): source proves measurement_start
brackets warmup as well as sampling, but shim BPF deltas begin after warmup.
The saved profile hasone60s warmup+one60s sample, and124/121s clock spans.
Its samples divided by measured-only calls are not matched-window per-call
costs. The8.86percent remains a global capture share, not a C4 serial bound.
C receives the read-only start/end-counter observer change; no frozen runner,
workload, profile-admission gate or new optimization is introduced here.

2026-11-15 PERF: simulator frontend GPR cells (this commit; report
`results/perf_20261113/register-cells/report.md`). One indexed value/tag view
replaces repeated sixteen-way reads/tag dispatch/writes, with the named state
ABI and independent entry-input draws preserved. Real preprocessing shrinks
26–31% over eight 100/1K scalar/pointer direct/indirect cases. Four freshly
compiled small normal-B variants have byte-identical allocated sections;
6423 dispatch/7057 route/102816 storage comparisons, 50605 hardware MUL vectors
and full CompCert pointer-binding parsing pass. Wider CPU suite still fails
its unsupported movups case; raw failures retained. This reduces compiler
input, not native execution time; 1K pointer CPP remains 61.7MB and 10K/100K
stay stopped. No base/image/kernel change; all native LTO pieces stay combined.

2026-11-15T07:36:53Z PERF: scheduled code tables (this commit; report
`results/perf_20261113/scheduled-table/report.md`). The normal linker tracks
the formed target through the schedule; B captures existing CODE identity
before index clobbers and retains the scheduled effects and final JMP,
replacing early goto fusion. Private result/flag liveness and external entry
conditions remain. 41 Rust, 64 native +64 normal-B/shared-simulator vectors,
shared-table64 and map-capability20/3 regressions pass. Actual OTel hotspot
full proof39127B/28 nested relocs and shared C6945 instructions now generate;
full B/stock/app remain open. This enables unified jump-table codegen without
changing upstream source. No execution speedup measured; all LTO stays on.

Scheduled-table follow-up (1408eb095,c24fee460,b3b2cbfbf; this result commit):
normal CLI published in the same base, final45c33e7e after removing unused
pre-CFG register-write code. Actual stock source/B loads pass with the
production mutable input-map binding; actual registered replay verifies B,
compiles checked native and installs program11 (status0). Both earlier fixture
binding/path failures are retained. This completes the fixture's load path,
not KPROBE execution, OTel acceptance or a measured runtime optimization.
All LTO stays together; actual app and body/size targets remain open.

2026-11-15 BMI2 B preprocessing specialization: constant SHIFTX,
SHIFTX_MEM, BZHI and BZHI_MEM now select their shared handler directly in
the generated specialization contract. The generic dispatcher uses the same
extracted shift bodies; BMI2 shifts preserve flags and memory forms retain
the packed displacement/count encoding and recovery behavior. This changes
B generation only. Native CPU/shared-simulator and normal B compilation
checks are in `kprog/test/check_bmi2_specialization.py`; measured preprocessing
reduction and completed checks will be recorded with the result receipt.
Full OTel B acceptance and application behavior remain open; all native LTO
remains on together.

BMI2 receipt (bd07827e3/d1044c7fb/1c2518cf7/027cce145): chain207,
whole-state566 and Lean dispatch proofs pass; 16 native/shared-C fixtures
cover4,032 cases, including nonzero memory displacement, and generic/direct
normal B has identical allocated sections for16/16. Same-input OTel CPP is
431,680,679→384,511,544 bytes (-10.93%); render/proof/CPP18.98s, no runtime
speed claim. Full B/stack/app acceptance remains open. Exact identities,
commands and retained initial failures: `../results/perf_20261113/bmi2-specialization/report.md`.
MOV_LOAD/STORE remain242.8MB; shared load writeback is the next candidate.

2026-11-15 shared MOV_LOAD writeback: memory/context/stack branches now
compute the existing value, width and optional pointer/tag before a single
destination write. This avoids expanding register-write and stack-release
bookkeeping once per branch. Address calculation, volatile reads, saved facts,
memory-recovery early exit and RSP scalarization keep their original order.
Validation/reprofile receipts follow; no runtime performance claim. All native
LTO remains on together.

2026-11-15 all-pairs spill lowering is the single normal B backend policy
(coordinator08:48): the environment switch and CLI selection are removed,
as is the old last-pair-only automatic path. Every eligible scalar pair uses
the existing dead-source reuse/live-scratch preservation implementation.
Diagnostic explicit-pair inputs remain callers of the same lowering body.
Retired switch/old-path comparison tests are replaced by current multi-pair,
register-pressure and normal-backend checks. No full OTel acceptance claim.

2026-11-15 receipts: common MOV_LOAD writeback2c6ae7717 reduces same-input
OTel CPP384,511,544→309,459,472B (-19.52%; -28.31% including BMI2).
Independent load713/stack117782/new pointer-RSP-recovery14 pass; old
helper-output oracle still fails to link before/after and is reported.
Actual CPU4032 cases and all16 normal B allocated sets match before/after.
All-pairs sole policy8f48bf443 passes host grouping/pressure and stock9,540
executions/zero mismatches; original544B rejection/packed512B acceptance
retained. Reports: `../results/perf_20261113/load-writeback/report.md` and
`../results/perf_20261113/all-pairs-single/report.md`. Full OTel B/app and
runtime performance remain open; native LTO stays together.

2026-11-15 shared tagged-store call: the MOV store default arm now has
one STORE_ADDR_TAGGED invocation. The removed condition's true arm already
required the destination tag to be STACK, making its tag argument identical
to the general arm. Address/value evaluation, alias erase/save, unknown-store
fact clearing and freed-stack inputs stay in the same order. This removes
duplicate preprocessing of the same body; it changes no P or benchmark.
Native CPU/shared-C memory/flag and normal-B baseline fixtures are committed
in2647a9aca. Completed validation and CPP sizes follow in the result receipt.

Shared-store receipt (b30e228e0): same-input OTel CPP309,459,472→289,568,784B
(-6.43%; cumulative-32.92% including BMI2/load writeback). Native/shared-C
full memory+flags512 cases pass before/after, all16 normal B allocated sets
match, independent store1,292,621 checks pass. Old removed-helper oracle
still has its baseline link failure, reported explicitly. All LTO stays
together; full OTel B/stack/app and runtime claims remain open. Exact
identities/commands: `../results/perf_20261113/store-writeback/report.md`.

2026-11-15 existing write-helper lifetime validation (0e89749a9/dd9be72a8):
current x86/ARM64 output oracle passes200 cases each with explicit zero/nonzero
free inputs, concrete output pointers and caller-fact checks. The retired
WRITE_ARG_PTR/fault test is replaced; full scoped load/store target now exits0.
This is validation of existing LTO/helper behavior, no production change or
speed claim. Earlier failures and corrected kernel-outcome assumption remain
in `../results/perf_20261113/helper-output-oracle/report.md`; full host-input
matching, actual OTel B/app and M4–M6 stay open.

2026-11-15 pre-SROA width constants: three running-compiler snapshots locate
the actual OTel cost in SROA/PromoteMemToReg/IDF calculation. The shared width
contract is now evaluated with one captured byte argument and byte result;
immutable instruction/read/write width locals remain constant through the C
frontend. No optimizer flag/pass is disabled. A diagnostic width gate had25–28
pre-optimizer branches via ordinary/function locals and0 through captured
constant contract locals. Actual handler/normal-B validation follows; this
does not yet claim a full OTel compile or runtime improvement. All LTO stays on.

Pre-SROA receipt (3f27add92/c25ed3354/a7b399a9a): actual write probe78→12
branches before LLVM passes,65,538 width semantic cases and scoped suite pass,
CPU/shared-C512 store+4,032 BMI2 cases pass with normal B compilation. Actual
B instruction sections change in16 store/six32-bit shift fixtures; ten BMI2
allocated sets match prior output, and generic/direct matches16/16. Full
changed-B stock execution and OTel improvement remain unmeasured. Revised
actual frontend queued910213 behind preserved original898093, same one
build; input locks now release before optimizer work. Initial compile failure
and all diagnostics: `../results/perf_20261113/pre-sroa-constants/report.md`.

Actual frontend follow-up: the original optimized stage failed with LLVM OOM
under16GiBAS after2,564.727s/maxRSS16,620,472KiB, before B generation.
The revised width/selector frontend started normally on the same native,
proof and metadata; CPP grows289,568,784→297,172,962B (+2.63%). At10:25UTC
it remains running, so the isolated graph reduction is not yet a full compile
improvement. Raw command/error/resources: `../results/perf_20261113/otel-frontend-oom/report.md`.
All LTO and normal optimization flags remain together; no runtime gain claimed.

Current checked-C packet regression also passes25 host native/reference
executions after the width/selector change (XDP/TC/cgroup_skb, complete context
bytes and qdisc prefix). The canonical test build now replaces its own known
products while preserving previous raw metadata/logs; production fresh input
generation is unchanged. Earlier directory/cross-filesystem failures remain
in `../results/perf_20261113/checked-packet-constants/report.md`. This adds host
checked-C coverage, not changed-B kernel execution or application acceptance.

2026-11-15 immutable entry ABI: RAW/XDP/SKB entry macros now declare their
fixed ABI kind constant, so Clang can remove other-context load/store routes
before SROA. The selector is never assigned after entry; context translation,
helper arguments and all state transitions remain the existing bodies. The
state-struct execution path retains its runtime selector. Real store graph
probes and current native/B/checked-C subsets provide the validation below;
the active OTel frontend keeps its previously captured input. No flag or LTO
selection changes and no runtime speed claim.

The store width contract and tagged-store width/tag captures are also immutable
at their existing initialization points. Their evaluation count, byte conversion,
branch selection and volatile store order are unchanged. The generated store
header and its generator change together; the shared body still handles runtime
width/tag inputs. This extends early constant propagation through the nested
store macros, without a second compiler path or a flag change.

Store-arm selection now initializes its immutable byte with the same conditional
expression instead of assigning it in an if/else. The condition still executes
once, with the same two arm constants. This keeps a fixed decoded register's
arm visible to Clang before SSA; runtime register dispatch remains supported.

Store-constant receipt1af8005a5/6d515de02/69c74d4c6: actual stack-store probe
branches436→226 and400→192, memory-store436→331 and400→298. CPU512store/
4032BMI2 and complete scoped oracle suite pass; normal B allocated sections
match their previous outputs32/32, checked-C packet host25 pass. One bounded
actual OTel frontend921682 is queued behind preserved910213, same canonical
build, normal flags and all LTO. Full compilation/runtime gains remain open.
Exact commands/results: `../results/perf_20261113/store-constants/report.md`.

2026-11-15 single aliased-store fact invalidation: EXEC_STORE's ordinary-address
arm now lets STORE_ADDR_TAGGED invalidate the saved pointer facts for the range.
It already performs the identical invalidation before the volatile write; the
removed earlier pass had no intervening reads of those facts. Source value,
destination address and register tags are captured/read in the same order,
and post-store fact saving stays in place. Before changing the body,4,224
independent aliased-stack cases pass (complete arena bytes, all saved facts,
flags, zero/nonzero free-byte choices and draw counts). Validation and graph
measurement follow; P, normal flags and combined LTO are unchanged.

Single-invalidation receipt1e66d1be8: new4,224 independent alias-store cases
pass before/after; full scoped suite/512native-store/25checked-packet host
checks pass,16 normal B allocated outputs unchanged. Memory-store preSSA
branches331→309/298→276, stack probes unchanged. No full compile/runtime
claim; queued921682 captures current source after preserved910213 ends.
Commands/results: `../results/perf_20261113/store-erase/report.md`.

2026-11-15 compiler continuation06a15fa2f/f05269a4a reuses the same normal
bounds/MIR/all-pairs/llc body after a completed optimized frontend. It changes
no optimization policy or emitted B:16 normal fixtures retain their allocated
bytes, two actual frontend continuations match normal B, six stale/incomplete
identity cases stop before compilation. This avoids repeated frontend work
when diagnosing the pipeline, not native runtime work; actual OTel completion
is still pending. `../results/perf_20261113/frontend-resume/report.md`.

2026-11-15 read-only scalar object spans: section-symbol PC32 references now
retain the containing immutable ELF data object's extent, including interior
addresses and overlapping aliases. Direct symbol references already use that
boundary. This avoids copying unrelated jump tables from the same container;
code-table spans keep their existing handling. Actual Tracee seven failures
and the new start/interior regression reproduce the old whole-section error.
Validation follows; this is linker correctness, not a measured runtime gain.

Scalar-span receipt84b895d26:42Rust/1existingignored,128proof→kernel host
executions and64full shared-simulator cases/normalB pass. Same Tracee native
ELF165/172→172/172 proofs, previous165 proof files byte-identical. Paired CLI
c500c99e published in place; loader/bounds/checked hashes unchanged. Stock
reference+generated KPROBE accepted after using production private input-map
binding; original plain-libbpf binding failure is retained. Whole app/native
installation/equal-work performance remain open. Exact scope/results:
`../results/perf_20261113/scalar-rodata/report.md`.

2026-11-15 host input fidelity: x86/ARM64 shared headers now use the same
explicit unspecified-input entry on host as B/CompCert. The host-only zero
shortcut is removed. Lifetime/alias/RSP oracles exercise that real route,
with zero and nonzero choices and exact draw counts, rather than replacing
its macro in tests. Small native host fixtures explicitly choose their input
environment; B/CompCert expressions, P and all LTO are unchanged. Existing
CPU observer zero choices remain a limited test domain, with hardware input
matching and full AST/formal work still open. Validation follows; no speed claim.

Host-route receipt080a1aa08/8ef77c1a1: the old header fails four independent
oracle groups once their overrides are removed; the explicit route passes all
scoped zero/nonzero/draw-count checks.925344x86/1474560ARM full storage/
distinct-stream comparisons pass under UBSan. CPU512store/4032BMI2 and map/
table/context host checks pass,32 normal B allocated outputs unchanged. CPU
control still has4864/8960 mismatches under its explicit zero input choice;
hardware input matching and full formal work remain open. All failures, exact
scope and raw recordings: `../results/perf_20261113/host-input-route/report.md`.

2026-11-15T11:59:17Z finite-control input fidelity: replace the observer body's zero choices with hardware stack-release words recorded by ptrace hardware breakpoints/single-step before the simulator runs. Initialization choices are explicitly zero and overwritten by the complete driver input state; body input identity/count/consumption is checked. Native body bytes, full-state comparator, production compiler and all LTO unchanged. Validation follows; no runtime speed or complete formal claim.

2026-11-15T12:04:35Z control-witness receipt: ac64269b7/86237b0cd/7c9d57c48, final35forms/8960cases zero mismatches against4864 earlier;5376 actual hardware RET-release words supplied before simulator. Independent raw analysis checks target/slot/bytes;35 original native spans identical, comparator and fields unchanged. Fullflags remain raw (XOR0x202 outside preexisting0x8d5 mask). Finite corpus only, universal input/AST/M4–M6 open; P/B/flags/LTO unchanged. ../results/perf_20261113/control-hardware-witness/report.md.

2026-11-15T12:22:51Z full-pointer code tables (HARD-native correctness prerequisite): unified-flag label-address fixture emits LEA plus indexed64 indirect JMP and eight R_X86_64_64 code slots; old c500 treats them as map pointers and fails. c3ae14b00 preserves rewritten instruction identity/finite CFG targets in proof and image-relative runtime pointer records(kind12);4c975b57b keeps indexed dispatch through normal B finite CODE lowering after the actual base-register liveness check, retaining all case bodies/index values.43 Rust/1 existing ignored and1024 native+1024 shared-C cases/normal B compile pass; relative320+320 and private-state refusal regressions pass. d16064f1a records sole kernel bdfa49b694e1 image+target binding; compiled kernel/CLI publication and actual kernel acceptance still pending. No flags, producer or LTO switches changed; no performance claim. Raw /workspaces/kprog-raw/perf/20261115-absolute-code-tables; receipt follows.

2026-11-15T12:45:01Z absolute-table completion receipt:5b2f7829e observes all72ctxbytes as well as64-bit native/32-bit entry return in1024+1024 cases, normal B succeeds. d16064f1a/bdfa kernel+boot completed, but publisher957999 overlapped C timing12:23:08–12:23:57; this resource violation and hashes retained, no performance inference. Later pair961621 waited entireCowner948426 end then publishedCLI dbac8784(loader/bounds/checked unchanged). First stock wrong-client argv failure kept;4bad0ac65/corrected964453 stock accepts generated B3/360xlated/178JIT, load-only. Checked native kind12/app acceptance still open; allLTOon, image2aed unchanged. ../results/perf_20261113/absolute-code-tables/report.md.

2026-11-15T13:33:52Z base correctness prerequisite:3814e66fc couples bzImage/modules/install, current external native modules and sole-image packaging, removing -o vmlinux suppression of module-BTF refresh. Resolves the real Katran tunnel4 setup failure left by kernel-only publication.842installed/image module bytes match, official configdiff empty (only generated ARCH heading differs), both10s Katran phases appOK/native16replaced. Currentimageaf3f9d4e/core8cafa600/BTF27ae;000f463ef fresh default bootfacts. Native stage/image1174 matches, oldimage78Tetragon entries removed/31otherchanges retained. AllLTOon; no speed/equalwork/allapp or checked-native claim. ../results/perf_20261113/base-consistency/report.md.

2026-11-15T14:06:00Z shipped-linker support:4de9a3227/840fd2c2d guest confirms imageaf3 contains exact repoCLI dbac; actual proof/kernel linking converts PC32 map address to full64bit binding, six boundary executions pass. Component only, no runtime speed claim. No rebuild needed for C Katran; production-fPIC retained per6584e1127, one A/A+one A/B. All LTO unchanged/on. ../results/perf_20261113/image-pc32/report.md.

2026-11-15T14:22:20Z normal B compiler:1c5f8b7d7 removes packet-bounds context/identity selectors and unsafe off branch; caller/base binary4827e435 published together.60 native cases/4width exact BPF encoding/negatives/real service/normal all-pairs backend pass; old default fails untied-provenance check. ALL switch already removed8f48bf443. No speed claim, image compiler copy waits next C packaging; all LTO unchanged/on. ../results/perf_20261113/bounds-single/report.md.

2026-11-15T14:57Z P-SPECIALIZE progress:8c5d1d183/02fb4e139 constant instruction arguments enter one inline I; finite helper cases and helper-state effects share it. Same OTel P/proof/maps CPP297172962→5729367B(-98.07%,5.25x),0.275s/90980KiB CPP only.96c004c0f suppresses internal debug clones, retains-g/BTF; toy debugvars12075→76. Latest table1024+1024/normalB+independent helper clobber/64B oracle pass, initial-inline CPU4032 passes. Full frontend cost/B size/stack/app remains OPEN: controls stillSROA,paused for C timing; final5.73MB frontend+scale queued. No P/native flags/runtime speed change; allLTOon. ../results/perf_20261113/inline-interpreter/report.md.

2026-11-15T15:42Z P-SPECIALIZE refinement:9fc382606 compiles all57shared handler families separately and instantiates constant-opcode call wrappers from one dispatch chain. Latest1024native+1024fullctx/normalB and helper oracle pass. ec574a17f/4d9fb9aa9 normal anonymous-stage continuation equals ordinary allocatedB (fixture360B/postPEIframe0). Actual OTel completeB/frame pending Ctiming; P/native flags/allLTOunchanged, no runtimegainclaim. d5d890c4c shared work leases correct the recorded15:27–32 compiler/timing overlap. ../results/perf_20261113/inline-families/report.md.

2026-11-15T16:18Z P-SPECIALIZE measurement: current all-family OTel CPP6,019,192B/5.506x (earlier5.73MB was pre-family). Scale observer now adds actual post-PEI stackSize per subprogram, rather than treating direct R10 depth as a frame; completed CPP/B data survives later observation failure. Validation and actual OTel/scale B/frame results pending behind C timing; no runtime gain or new optimization selector. ../results/perf_20261113/inline-families/report.md.

2026-11-15T16:20:06Z cc83b5d48 frame observer validated after C timing release:576/zero/missing/duplicate parser cases pass; actual normal anonymous continuation matches ordinary allocated B sections (360codeB, fixtureframe0). OTel resumed automatically under timingSH/imageSH, full B/frame still pending. No runtime gain claim; all LTO unchanged/on. ../results/perf_20261113/inline-families/frame-observer-check.json.

2026-11-15T16:22Z all-family inline-I scale100/1000: eight normal B builds pass, actual frames0–32B; optimized frontends0.478–2.146s/115–180MiB RSS, Bcode248–20240B. Pointer1000:2.081/2.146s,183276/184004KiB,20224/20240codeB,24Bframe. CPP3.67→3.83MB as fixed handler definitions dominate; scalar folding caveat in report. Actual OTel frontend still running, parent P-SPECIALIZE/runtime goals open; allLTO unchanged/on. ../results/perf_20261113/inline-families/report.md.

2026-11-15T16:24:32Z full OTel hotspot all-family I completes: same6945-insnP/proof/maps, CPP6019192B, frontend254.634CPU s/5539808KiB RSS (3096.438wall includes47min explicit pause), normalB1103248codeB/137906slots/actualframe448B. Below512 is a frame result, not stock/checked/app acceptance; historical576/552 also differ in compiler/bounds/storage. Commands/hashes/resources in ../results/perf_20261113/inline-families/otel-complete.json; allLTO unchanged/on, no runtime gain.10K/100K continue.

2026-11-15T16:25:42Z inline-I10K allfour shapes complete normalB/frame under8GiBAS. Scalar frontend11.609/11.894s,~400MiB; pointer26.272/25.672s,~920MiB. CPP4.79–5.41MB, B504/328/200480/200624B,frames0/0/32/40. Old same-named scalar failure5693s/70.47GiB is retained, no isolated ratio claimed across pipeline changes/scalar folding.100K stillrunning; allLTO unchanged/on, runtime/stock acceptance open. ../results/perf_20261113/inline-families/scale-10k/.

2026-11-15T16:54Z cab373d96 B-only debug cleanup on actual100K scalar/direct: identical completedfrontend2aa1cd7b, B allocated448codeB/frame0 exact. Olddebug-bearing machine stage894.162CPU s/2567276KiB→34.847CPU s/244708KiB; newbounds6.365CPU s, finalobject7.759s, frameobserver8.013s. Cfrontend not repeated; no nativeP/runtime gain. Candidate descriptors closed, canonicalcontrol intact, installedbasepublication stillpending. ../results/perf_20261113/inline-families/scale-100k-debug/.

2026-11-15T17:22Z P-SPECIALIZE measurement complete: all16scale shapes nowactualsole-kernel/outputPASS; pointer100K16GiB retries365.485/380.316CPU s,8889824/8890424KiB, B2000480/2000624B,frames32/40.8GiBfailurekept. Bmetadata compiler1965published17:11underimageEX/noQEMU; image/loader/linker unchanged. OTel448B remainscompile/frame only, nowhole-app acceptance/runtimegain. ../results/perf_20261113/inline-families/pointer-16g/.

2026-11-15T17:54Z clock linkage replay receipt (86a95222e): actual boot plan through normal native->proof->kernel fixture gives10B runtime blob and one16B kind1 relocation to the exact fast-clock symbol. All intermediates are anonymous; analysis accepts saved Katran plans without changing the published linker/image. Actual timed-object map/helper audit remains open; no runtime speed claim. `perf_20261113/clock-lto/runtime-audit.json`.

2026-11-15T18:01Z phase1 whole-app follow-up (612c9fc18): checked OTel functional launcher drops removed-route manifest and consumes sole-image native590aa121 with current64eb/1965 tools; actual app startup running on16-19/16GiB/imageSH, allLTO together. No stock/checked acceptance or performance gain yet. `perf_20261113/otel-current-app/`.

2026-11-15T18:11Z phase1 kernel correctness: fresh OTel590aa stock B verifies/checked compile completes but native install524. Old-boot real map-value regression reproduces524;099357174783 (master5c3c95a4d) prevents map literals falling through kind12 image rebasing. Sole in-place kernel/modules/image rebuild pending; first Make OUTPUT leakage failure fixed606ae1d0e. AllLTO stays on, no runtime gain claimed. `perf_20261113/map-image-relocs/` and `otel-current-app/requests.json`.

2026-11-15T18:24Z phase1 retry after099 kernel publication: three real map/value/image cases execute42/304/42; fresh read_task_struct verifies24 and checked-installs27 on sole imagefc5336c2. Next perf_unwind_stop stock attempt rejects speculative nullable-pointer sign shift before its null branch. The sign flag's PHI incoming edge establishes pointer==NULL, so compiler equality-edge folding is the next general correction. All LTO remains on; app status error and performance goals remain open. `perf_20261113/otel-current-app/retry1/`.

2026-11-15T18:33:39Z phase1 B compiler equality-edge folding: use each PHI incoming branch's exact integer/NULL equality to fold its expression with LLVM's strict simplifier. Original branch/other edges remain; original shared-I and checked-native frontend stay unchanged. Old published tool fails the focused regression; candidate30 boundary comparisons plus existing60 identity/context/backend cases pass. Actual archived perf_unwind_stop frontend folds one incoming expression. All LTO stays enabled together; real stock/app acceptance remains next. `perf_20261113/equality-edges/`.

2026-11-15T18:34:45Z equality-edge toola7d9ab49 published18:34:22Z in sole base underimageEX; sole imagefc5336c2/kernel099 stay installed. External checked service uses the new base B compiler; image-bundled1965 remains recorded separately. Fresh OTel checked retry2 launcher1155245 runs16-19/imageSH, all LTO on. Actual stock/install/app result remains pending. `perf_20261113/equality-edges/README.md`.

2026-11-15T18:36:33Z actual equality-edge outcome: perf_unwind_stop stock31 and checked-native34 install successfully; B202088 executable bytes/one exact incoming fold. Fresh read_task_struct also verifies24/installs27. Next perf_unwind_native reaches an unsupported `dead` reload marker in MIR spill lowering, so whole-app startup remains open; all LTO stays enabled. `perf_20261113/otel-current-app/retry2-progress.json`.

2026-11-15T18:50:51Z phase1 MIR dead-destination support: whole_word_spills.py accepts `dead $wN = LDW32` and treats the destination as a definition for scratch liveness. Two existing parser patterns change. Actual sole-kernel regression matches1060 executions; affected suite10600 executions/11cases including the expected544B rejection and passing512B packed frame. P/shared-I/allLTO stay intact; actual OTel native-entry replay follows the dedicated Katran window. `perf_20261113/dead-spill/`.

2026-11-15T19:44:34Z Katran combined all-LTO fixed-frequency pair completes: AA173.857457→178.067376ns/call, AB177.013829→175.770415; requested AB/AA gives1.031460153x per call and1.031074566x mean throughput. Both3x180/stats1, Make0/appOK,73 host controls restore exactly per run. Actual plan/proof/12386B neutral blob/288B relocation replay matches byte identities;8fast-clock sites and60/66named map sites confirmed. Native body7965B/installed12418B/JIT13641B; pure-body runtime remains a matched-profile task.20%/30%/body-speed targets stay open. `kprog/results/katran-c-hdr-20261115/fixed-frequency/`.

2026-11-15T20:05:43Z profile staging correction: first body diagnostic stops before boot because repository and /var/tmp are separate filesystems. Canonical module/image/perf use symbolic links plus a read-only perf-input mount; one-image's existing copy fallback also becomes symbolic links. Completed owned tar/module copies and the failed input link are replaced/removed with a path inventory and cleanup log; raw timing/profile-failure data stays. This changes input transport only; actual official counters and measured object identities remain recorded. Body profile retry follows.

2026-11-15T20:33:06Z Katran body diagnostic: exact live-JIT/shim-window CPU-clock attribution gives program-text59.604569->52.271865 sampled ns/call; retained native source45.892902 plus6.378963 unmapped/expanded/runtime. Installed payload match uses this boot per-CPU symbols and masks568 call/map immediate bytes;11818 others exact. JIT text includes inlined helpers, so no pure-body1.50x claim. Original fixed-frequency AB/AA1.031460153x stays timing observation; allLTO/imagefc5336c2 unchanged. `katran-c-hdr-20261115/fixed-frequency/profile/source-costs.json`.

2026-11-15T20:39:04Z phase1 OTel main retained-MIR replay (a96cefb82): current dead-marker fix passes6packedpairs/693accesses/llc machine verification in8.78s, B991592codeB. Largest R10 access784B; native localobject408B plus40x8/12x4 spills exposes separate register-pressure issue. No stock/checked/app acceptance claimed; diagnose B backend from retained optimized IR before repeating frontend. NativeP/flags/allLTO unchanged. `perf_20261113/dead-spill/actual-main.json`.

2026-11-15T20:53:47Z compact word-key hash LTO: replaces4duplicated4/8/12/16 bodies with508B general jhash2+memcmp/nulls lookup for positive word-multiple keys, covering actualKatranVIP20B. Kernelbyte-key path and value/perCPU/LRU postprocessing unchanged; no newflag/schema/keylengthcap, allLTO together. Actualemittedx86 passes49178 kernel-reference/unaligned/guard/collision/hash/nullretry/ABI vectors and44Rusttests(1existingignored). CLI/base/imagepublication andfixedfrequency runtimegain stillpending; no speedclaim. `perf_20261113/word-hash-lto/`.

2026-11-15T21:26:08Z compact word-key LTO publication:585706fe1 now in soleimageb6ed6a16/CLIfb611, boot/kernel/modules unchanged. SameactualKatranP c0dc/proof8768, oldtimedplan replay neutralblob12386→11016B,288Brelocs; actualinstalledsize/newtimedplan andruntimegain pending currentfixedfrequencyAA/AB1211116(start21:17:36). Image matches1252stagefiles,89Tetragon additions/changes fromC noted; Katran producer unchanged. Plannedsmoke fails beforeboot onmissingobservationdir,73hostcontrols restoreexact; callerforwardfix only. No app/body-speed claim from packaging/replay. `perf_20261113/word-hash-lto/publication.json`.

2026-11-15T21:43:53Z B compiler constant identities: fold only exactly tiedempty integerconstant asm/no stackalign/nothrow, preserving variable/pointer/untied/clobber/realasm cases. RetainedOTelmain408Balloca/5642asm includesconstant offsets; candidate exposesbits toLLVM without changingI/P/nativeflags/allLTO. Existing18constant+60identity+30equality/fourwidthcontext/normalbackend checksPASS. Actualframe/stock/app outcome andbasepublication pending; currentKatranb6ed run unchanged. `perf_20261113/constant-identities/`.

2026-11-15T22:37:22Z compact word-hash actual outcome: fixedfrequency AA+AB3x180 completes22:09:49 onb6ed, bothappOK/73controlsrestored. AB/AA percall1.015468249x/throughput0.994091729x vsprior1.031460153/1.031074566; installed12418→11048B/P7965unchanged. Actualnewtimedplan proof/blob/relocs replayexact. Subsequentprofile5f60(C66c32loader) matches10448unmasked codebytes and gives59.348604→68.159874sampledtextns/call; retained45.572898/generated22.586976, newhash-tailhotspot. Code shrinks but measuredspeeddoesnotimprove; samplesincludeinlinehelpers/purebodytargetOPEN. AllLTOtogether. `katran-c-hdr-20261115/word-hash-lto/`.

2026-11-15T22:38:59Z B constantfold actualmain: same retained frontend/controlframe784 stays784 after2225exactconstantfolds; object2176496→1132336B/code314528B(prioractual991592), observedchildCPU16.59→5.90s, spills52→47. ConservativeCFG analysis7739blocks/max45liveslots/zero proven noninterferingpairs; no speculativecoloringimplemented. Privateframe+shadowstate needsactualIR diagnosis; smallerB is not stock/appacceptance. Publishedbase a7d unchanged/allLTOtogether. `perf_20261113/constant-identities/actual-main.json`.

2026-11-15T22:43:31Z phase1 constant closure: exact tiedinteger identity elimination now propagates newlyexposed integerconstant expressions through LLVM ConstantFoldInstruction/worklist before their nextidentity. This reachesconstantchains inonecompilerpass; live/pointer/untied/clobber/throw/alignstack forms remainopaque, sharedI/P/flags/allLTO unchanged. Regression catches asecondidentity hiddenbehindadd;20actualconstant/negative+60identity+30equality+normalbackendPASS. InitialbuildhitLLVM SmallSetVector inlinecapacity64 assertion;32inlinecapacity fixesit withunboundedheapgrowth, failurelogkept. Actualmain/frame andpublication next, no acceptanceclaim. `perf_20261113/constant-identities/closure-checks.json`.

2026-11-15T22:45:33Z constantclosure actualmain completed: code305376B/object1123368B,47spills/max44conservative live, frame784 unchanged;2225identitiesfold. It adds no foldableidentity onthismain, although pureconstantsreducecode. Phase1 remainsopen andbasea7d unchanged. Coordinator22:42 nextKatran constant-key unroll takespriority. Historical pausedClangs911032/1038827/1041837/1046429 endedexactPID aftercancellingobsolete ownqueuedfollowers, releasing~39.45GiB RSS; inputs/logs kept, receipt `perf_20261113/retired-controls.json`.

2026-11-15T22:52:58Z forward constant-length hash: one emitter specializes4/8/12/16/20 straightlinehash+memcmp blocks chosenbylivekey_size, coveringKatranVIP20 andrestoring short-key speedstructure. Otherwordlengths use thesamegeneral generator/nonwordexistingkernelhelper; no limits/flags/schema/sourceP changes. Actual2480Bfixture49178kernel-reference/guard/collision/null/retry/ABI and45Rust(1existingignored)PASS; decoded constanthashblocksbranchfree. AllLTO together; publication/profile/fixedfrequencycounterpair next, no runtimegainclaim. `perf_20261113/constant-word-hash/`.

2026-11-15T23:26:51Z fixedword72a2 published23:20:14Z/current741f8227/CLIf7de4bfc; kernel/modules/native1252files stable, payload12958B. Directone-image corpus1x10s/stats1 botharmsOK/run232350_572949; fullmetricsfollowC breadthround, noAA/observer/removedwrapper. ReferenceMay-build linkerreplay sameP/currentfacts10164B/27externalcalls vscompact11016/18; matchingentry/noLFENCE. Profileboundary correction: compacttext52.27→68.16 includes hash movedfromkernel20.58→8.25/tablewalk14.76→11.72; capturedBPFchain146.78→146.23 andretainedsource45.89→45.57 nearlyflat. PurebodytargetOPEN; details `katran-c-hdr-20261115/may-linker-comparison/`.

2026-11-15T23:30:05Z timing-settings correction:23:22:11 shortKatran1x10launch occurred after23:21:43 noticefreezingdefault3x180/read23:28. Lane mistake recorded/app raw retained, no speedclaim. Subsequent runs useunchangedcorpusdefaults/allowedAPPS+stats only; no removedAA/observer/wrappers. ActualshortcheckbothOK/native12990B/JIT13641B. FullcomparisonfollowsC breadthround.

2026-11-15T23:39:39Z phase1 B private arena: normalizevolatile onlynon-atomicmemory whoseallunderlyingroots arelocalalloca union.x86_sim_stack_mem; mixed/nonlocal/atomic/otherlocaltypes preserved. ExistingClight VolatileLoad/Store.nonvol has ordinaryMem/E0 forlocalblocks; sharedI/P/flags/allLTO unchanged. Actualhost20helpermutations+20mixedaliases+30otheraccesses andexisting20constant/60identity/30equality/normalbackendPASS. Actualmainframe/stock/app next; basea7d/image741 unchanged. `perf_20261113/private-stack/`.

2026-11-15T23:44:28Z privatearena actualmain:18581accesses normalized; B305376→295336B/object1116648,7690blocks/47spills(46x8+1x4), frameSTILL784. Code reduces3.29% but stackallocation persists; no acceptanceclaim/basepublication. Nextobserveoptimizedarena addressescapes/spillorigins fromretainedfrontend/anonymousMIR, no nativeP rerun. `perf_20261113/private-stack/actual-main.json`.

2026-11-15T23:52:30Z phase1 recovernarrowspillshapes: actual8B descriptor mayhaveONLYdirect STW32/LDW32 offset0; normalizeit to4B beforeexistingallpairs packer. Everyusechecked, fullwidth/nonzerooffset/address-taking retained; no flags/gates/sourceI/P change. Existing11cases+newwide-descriptor casecompilePASS; full64/offset/escape negatives pass, newframe48B. Actualkernel1060executions/case andactualOTelframe next. `perf_20261113/narrow-spill/`.

2026-11-16T00:00:45Z helper source/kernel identity class: unboundplan adds UAPI-generated helpername fromeach SupportedHelper.id atSAMEkallsyms implementationaddress, retainingkernelspelling. FixesTracee sys_enter_submit bpf_probe_read/helper4 andbpf_probe_read_str/helper45 vscompat names; nevermaps4 to113. Existingcontextquery alreadyaliasesboth. Productionresolver/newactualkernelcomparison compiles; ten-typekerneltest next. No upstream/P/flags/kernel/bench changes or speedclaim. `perf_20261113/helper-source-alias/`.

2026-11-16T00:05:12Z alias00a402b4 actualten-typekernelPASS: unboundread4/readstr45 publicnames equalcompatkallsyms ANDloadedprogramget_func_proto; alloriginaltype/clock checks/wrongtypefailure retained. Tracee ELFundefinedhelperaudit showsitsothernames alreadySupported. Nextloader-onlyimagepublication, C defaultentry3x180 round; no source/bench changes. `perf_20261113/helper-source-alias/kernel-checks.json`.

2026-11-16T00:05:12Z narrowstorage finalresult:12kernelcases/11660realexecutionsPASS/newwidecase1060/frame48. ActualOTelmain narrowsZEROslots becauseevery8Bslotalsofullwidthused; code295336/frame784 unchanged. EarlySTW32 examples werenotproofnarrow-only; correctedCOORD. Normalizedlivenessstill44/0pairs, no speculativecoloring/rematerialization implemented. `perf_20261113/narrow-spill/actual-results.json`.

2026-11-16T00:21:28Z coordinator00:15 no-new-refusal correction: ambiguous spilldeclarations nowretain declaredwidth andnormalizationcontinues; removednewScalar-spill-not-unique exception. Duplicate-slot regression +existing12compilecasesPASS/raw20261116-narrow-spill-preserve; validinputtransformation unchanged. No program exclusion/gate or benchchange.

2026-11-16T00:43:26Z helperalias00a402 publishedfc408f64 at00:07:50, shippedloaderc296f028/linkerf7de4bfc/shim19f2f67a exact; kernel/modules/baseB/native1252files stable. Actualapplication result followsC defaultbreadthround. OTel diagnostic no-slot-sharing exposes417spills/211narrow+206wide/105pairs, butframe2920 andcode463200 worsenbaseline784/295336; productionflagsstay.

2026-11-16T00:43:26Z referenceLRU finding:16helperanchors align, LRU sites5304 and5743/5831 occupyreferenceintervals withzeroexternal lookups andzero ref-byte35 writes inentireoutput. TheyselectARRAY/PERCPU_ARRAY code instead ofLRU operation;3743 keepsgenericlookup. Oldfirst-unused BPFspec fallback(70sourcevs66nativecalls) differscurrentpointerfacts. Thisis staticreference replay/currentfacts; branchfrequencyandhistoricalMayliveidentity remainopen. RequestedtimingafterCround/defaultentry willretainworkdifference. Native1.50 target applieswhole nativeexecution, percoordinator00:19; purebodytargetwithdrawn. `katran-c-hdr-20261115/may-linker-comparison/lru-reference.md`.

2026-11-16T00:54:57Z prepared the requested May/current linker comparison: shared image refresh gains build-only --linker-input and --linker-rebuild operations; each replaces the sole canonical linker/image while preserving the archive and master source. The default refresh behavior stays the same. Shell syntax and both Make dry-runs pass. Execution follows C's breadth round through the unchanged corpus defaults; current fc408f64 remains installed. `katran-c-hdr-20261115/may-linker-comparison/publication-plan.md`.

2026-11-16T01:18:28Z phase 1 B live integer identities: exact tied empty integer register templates now become LLVM freeze of the input, preserving defined bits and concrete undef/poison register semantics. Pointer, untied, memory-clobber, stack-aligned and throwing forms retain their treatment. Kernel context origin recognition follows the freeze. Shared I, native P, compile flags and all-LTO settings stay unchanged. Actual host checks pass 30 scalar, 60 identity/context, 30 equality-edge and 70 helper/alias cases. Actual OTel frame and stock acceptance follow; the published base compiler remains a7d. `perf_20261113/live-identities/`.

2026-11-16T01:21:25Z live-identity actual OTel outcome: 280 identities normalized, code295336->289560B, spills47->52, frame784->824B. Smaller code accompanies a larger frame. Phase 1 and stock acceptance remain open; candidate is unpromoted and base a7d stays installed. `perf_20261113/live-identities/actual-main.json`.

2026-11-16T01:26:05Z Katran reference work comparison reaches live November 14 bytes: 9560 unmasked payload bytes match; all27 live external targets resolve as expected. LRU5304/5743/5831 array expansions have0/0/6 cpu-clock samples. Header has no branch trace, so exact branch counts remain unavailable from retained data. This establishes a real code/work difference, without assigning historical speed gains to these sparse samples. `katran-c-hdr-20261115/may-linker-comparison/nov14-lru-profile.md`.

2026-11-16T01:39:11Z B empty memory barriers: remove only void/no-argument empty asm with exactly memory clobber, no stack alignment or unwind. Real helper/memory asm and typed identities keep their effects; volatile globals stay. Host30scalar/60identity/30equality plus20helper/20mixed/40other cases pass, including helper mutation across the removed barriers and retained real nop. Actual retained OTel frame follows; base compiler/shared I/native P/flags unchanged, all LTO together. `perf_20261113/empty-barriers/`.

2026-11-16T01:47:45Z empty-barrier real main result:646 removed, code289560->288400B, frame824 unchanged. Actual typed calls are map_lookup110, trace_printk108, probe_read_user24 and tail_call1; the243 call-minus-one asm operations are unresolved-target guards. Helper memory effects are the next observed class; base a7d stays installed. `perf_20261113/empty-barriers/actual-main.json`.

2026-11-16T01:54:11Z B helper memory contracts: describe lookup-key readonly/nocapture and probe-read destination writeonly/source readonly/nocapture; preserve argument and kernel-internal read/write effects, mutable map and possible aliasing. Sole-kernel implementation reviewed. Real stock TC baseline1060+normalized1060 executions pass key/probe/fault-zero/overlap/unrelated-storage cases; existing host subset passes. Native P/shared I/flags/base untouched, all LTO together. Actual OTel frame follows. `perf_20261113/helper-memory/`.

2026-11-16T01:58:25Z helper memory actual OTel outcome:134 calls described, code288400/frame824/52spills unchanged; no measured gain and no base promotion. Next inspect byte-precise spill liveness because the previous diagnostic treated partial stores as whole-slot reads. `perf_20261113/helper-memory/actual-main.json`.

2026-11-16T02:02:34Z corrected spill-liveness diagnostic: partial stores define written bytes without inventing reads; wide loads and dead-store clobbers retain interference. Four CFG/partial/upper/dead-store regressions pass. Real main50live slots/328live bytes/zero noninterfering pairs; code288400/frame824 unchanged. This provides no safe whole-slot coalescing gain; no B rewrite or base promotion. `perf_20261113/byte-spill-liveness/`.

2026-11-16T02:20:09Z BCC load regression: native .rodata4118/target_family4116 versus loaded map4106/BTF4104 exposed the default native-footprint/offset assumption. Existing DATASEC-by-name resolver is now canonical for entry-referenced globals; obsolete native-offset path and kernel_data_layout flag deleted. Host plus actual kernel seven-global/three-map, byte preservation and entry-scope tests pass. Whole BCC/default timing follows the round; image fc408f64 stays. Post-round queue will publish loader and retry BCC before current/reference Katran on the same loader. `perf_20261113/bcc-data-layout/`.

2026-11-16T03:13:03Z finite helper joins: Cilium tail_ipv4_policy CALL RAX selects23/155. CFG provenance retains finite alternatives; proof keeps path-selected numeric call and installation dispatches to the actual helpers, preserving IDs and arguments. Existing helper ABI clobbers flags. Actual object production proof7365B and47active Rust tests pass, including both branches in executable code and unknown-path rejection. All LTO remains on; application/B/timing follow combined publication, with no gain claimed. `perf_20261113/finite-helper-joins/`.

2026-11-16T03:20:11Z direct native upload capacity: replaced the512-entry module array with dynamic chunk storage and next-endpoint creation, retaining blob/reloc/site wire formats. Deleted loader chunk-count refusal. Actual loader/kernel627->1->1025 chunk programs return exact expected counts, detecting lost code and stale tails; existing recovery/wire cases pass. Sole canonical module rebuilt, image fc408f64 pending combined publication; all LTO remains on and no timing gain claimed. `perf_20261113/dynamic-chunks/`.

2026-11-16T03:40:59Z phase1 native-first checked execution: preserve B generation/verifier diagnostics and run original P unverified when B fails. Typed verifier exit2 separates this from transport/binding/native failures. Actual kernel five-case regression passes native execution after generation/stock rejection, accepted checked execution, and propagation of unrelated/native errors. Existing9 service/host wire cases pass. No benchmark or all-LTO change; source awaits publication after active round, complete B/app acceptance open. `perf_20261113/native-first/`.

2026-11-16T04:07:09Z phase1 relative-table schedule: actual OTel perf_unwind_native overwrites its dead R8 table base before JMP R9, then cases observe the new value. Track original private bits through scheduled writes and seed case-CFG liveness with the remaining bits; preserve scheduled definitions and existing flag/partial-bit protections. Actual5234-instruction proof renders852964B C;47Rust tests/128native/128shared-simulator cases and both generated stock B variants pass. Actual OTel B compile1332986 pending; P/native flags/all LTO/image unchanged, no runtime gain claimed. `perf_20261113/relative-schedule/`.

2026-11-16T04:24:05Z relative-table actual OTel result: B generation now completes (970888B object);704B direct stack extent remains. Matching-source/context/map-shape stock replay rejects stack write-576 at instruction1. No stock or full-app acceptance claim. `perf_20261113/relative-schedule/actual-b.json` and actual-stock.json.

2026-11-16T04:35:18Z phase1 native-first preparation scope: BCC count_v4.zero BTF error occurs before BPF_PROG_LOAD. Record verify-preparation failures and try original P as requested; native/capability failures still propagate. Six actual kernel cases pass, including artifact failure native execution and real EBADF/native failure propagation. Underlying asm-named extern BTF metadata remains open; no timing/all-LTO change. `perf_20261113/native-first/kernel-preparation-results.json` and btf-extern-observation/.

2026-11-16T04:55:48Z phase1 native-first application result: BCC preparation retry043640_944453 completes app OK with25 distinct bodies,25 native installed,25 B generated and23 B passing stock after e4b9a57fe. Remaining two B failures are retained and run direct native; underlying BTF/stack fixes remain open. One10-second functional observation, no performance claim. Timing and checked six-app batches continue without image, flag or frozen benchmark changes. `perf_20261113/native-first/bcc-preparation-functional.json`.

2026-11-16T05:02:51Z phase1 asm-named B map externs: restore missing debug attachments from actual zero-length byte-array LLVM globals in .ksyms. Actual BCC tcp_v4_connect_ret now has BTF VAR count_v4.zero and passes matching-context/map-shape stock replay; executable B bytes remain identical. Two aliased fixture declarations and existing ordinary metadata pass. Full app stock count and sched_switch stack failure remain open; no P/LTO/benchmark/image change. `perf_20261113/map-extern-btf/`.

2026-11-16T05:15:41Z phase1 generator loop convergence: Tetragon event_wake_up_new_task exact stack-pointer alternatives grow without convergence inside linker-local memcpy/memset. Widen growing offset sets at backedges to the existing unknown element, retaining exact ReturnAddress joins. The actual738-instruction proof renders157638B C; ADD copy-loop native/full-shared-simulator64 cases agree with72B stack/one continuation. Actual B compile remains running; INC pointer-tag defect is reproduced and assigned to FORMAL. No native speed, stock/app acceptance or image claim. `perf_20261113/loop-pointer-analysis/`.

2026-11-16T05:23:57Z loop-convergence actual B result: Tetragon event_wake_up_new_task produces1772968B B. Matching bpf_fork_v511 source/context/map-shape replay reaches stock and rejects stack-752 at instruction1. This is generation recovery, not stock acceptance. `perf_20261113/loop-pointer-analysis/tetragon-stock.json`.

2026-11-16T05:26:05Z phase1 loader string pools: Tracee sys_enter_submi hits .rodata.str1.1 without BTF. Compiler string-section symbols now bind by section offset to the actual pool map; named globals retain BTF-by-name offsets. Focused host RX/live-string update and actual kernel no-BTF map identity tests pass, alongside existing typed-global/missing-symbol checks. Whole Tracee retry follows publication after the round. `perf_20261113/native-string-pool/`.

2026-11-16T05:50:39Z phase1 Tetragon helper ABI: console G identifies native event_execve probe-copy stack overrun. Producer helper asm leaves argument registers input-only, allowing invalid reuse across real helper clobbers. Actual-header host regression reproduces23 vs24 at arity1/input1. C owns producer repair; tests/evidence committed without a native-performance or corrected-app claim. `perf_20261113/tetragon-helper-abi/` and tetragon-native-console/panic.txt.

2026-11-16T06:25:11Z phase1 scalar spill widths: local machine-definition facts prove zero upper32 halves for eligible full64 scalar spills, then reuse normal whole-word packing. BCC sched_switch direct B stack616→424B, actual matching-context/map-shape stock replay PASSES.47 descriptors/31 pairs;11660 real-kernel fixture executions pass, with high/pointer/unknown/clobbered/escaping cases retained. This is B storage/acceptance, not native speed or code size; whole-app confirmation follows. `perf_20261113/scalar-width/`.

2026-11-16T06:42:38Z BCC functional confirmation of scalar spill/BTF repairs: app 063540_522999 completes with 25 native / 25 B generated / 25 stock accepted, up from 23 stock accepted. All 25 attempts install through the checked configuration. This is acceptance evidence, not a native speed/code-size result. `perf_20261113/bcc-all-stock/result.json`.

2026-11-16T06:53:42Z phase1 PERF_EVENT context LTO: normal loader converts embedded P IR before proof/data/helper binding, using boot-kernel BTF regs/data pointer layouts. Helpers and tail calls retain physical ctx; non-perf inputs retain their path. Embedded-object and production loader subsets each pass 256 cases across four widths and partial period/addr offsets; unconverted object fails 256. Retained OTel native_tracer_entry IR lowers ten loads and normal entry proof succeeds. Current producer IR payload and actual paired own-unwind counters remain pending, so the old unequal-work gains do not count. All LTO remains on. `perf_20261113/perf-context-lto/`.

2026-11-16T07:23:13Z phase1 B dead frame-address definitions: remove unused pure MOV_rr frame-index/FI_ri definitions before LLVM18 PEI can split them into a dead MOV and a reading ADD. Preserve local/helper/successor uses. Retained OTel original and candidate both reproduce3 errors; new pass removes3 and passes MachineVerifier, but stack remains704B. Backend13 cases and kernel12720 value executions pass, with544B original rejection retained. Native P/I/flags/allLTO unchanged; no stock-app or speed claim. `perf_20261113/dead-frame-address/`.

2026-11-16T07:25:46Z phase1 Tetragon helper ABI: ordinary typed C calls replace the bare-helper inline-asm wrappers for all arities and void tail calls. Clang now accounts for all SysV caller-saved registers/stack alignment, removing the source of stale probe-read pointer/count arguments. The obsolete workaround is deleted (39 fewer header lines); existing CFG helper joins remain supported. Actual-header regression improves from arity1 input1 failure to224/224 vectors. Canonical P rebuild/publication/runtime G retry remain pending with C; no new speed or app-success claim. `perf_20261113/tetragon-helper-abi/after.json`.

2026-11-16T07:39:50Z Tetragon G final ABI form: read-write RAX and argument operands plus remaining SysV clobbers, preserving explicit helper CALL sites. Supersedes the ordinary-C-call form after real plan replay exposed its numeric helper tail exits. Final224/224 register vectors and actual-plan conditional-helper proof/kernel emission pass (46B input,633B image,2relocations). Canonical P/runtime retry remains pending; flags/allLTO unchanged. `perf_20261113/tetragon-helper-abi/read-write.json`.

2026-11-16T09:01:39Z phase1 section entry retention: embedded LLVM aggregation now preserves explicitly sectioned program roots, and trusted PERF_EVENT LTO retains the selected entry before O3. Ordinary internal helper linkage, native machine-object generation and uniform flags stay unchanged. Public/loader/static context subsets each pass256 cases; actual OTel perf_go_labels survives aggregation and trusted conversion/proof. No app counter parity or timing gain yet. `perf_20261113/perf-entry-roots/`.


2026-11-16T10:43:11Z — Phase 1 generated-function correctness: 0f5c55894 moves the
existing exact constant-leaf lowering into one shared implementation used by
producer lowering and trusted runtime LTO. Supplied current-load instruction
semantics determine native bodies before O3. Both compilers pass six constants
by 48 real ABI vectors; absent-facts producer output stays byte-identical.
Public/loader/static PERF_EVENT regressions each pass 256 contexts. This is
runtime compiler wiring, with no performance claim or image publication;
metadata extraction, P/B binding and nonconstant bodies remain open.
Receipts: perf_20261113/runtime-bpf-functions.

2026-11-16T10:49:00Z — Phase 1 generated-function binding: 338d5b7df consumes original
per-program func_info/BTF metadata and exact source bytes before runtime LTO,
entry proof extraction and the trusted P/B request. Body facts and program type
participate in the cache key. Host original-offset/name extraction, two body
values across 48 ABI vectors, cache identity/reuse, and three 256-context
regressions pass. Real capture/app installation and nonconstant CEL remain
open; the active benchmark image is unchanged. Receipts: runtime-bpf-functions/loader-report.json.

2026-11-16T10:59:46Z — Phase 1 live binding evidence: 701d034e9/649692654 exercises
original func_info offsets against live BTF on the sole kernel. Original BPF
execution and the native artifact from its captured constant callee both return
9. Empty BTF Params does not replace the actual native prototype. Fixture-only
I/O/semantic evidence, with no app performance or native-kernel installation
claim; image and timing entry unchanged. runtime-bpf-functions/live-report.json.

2026-11-16T11:08:42Z — Phase 1 original function capture: dae9cdac4 writes load-specific
original func_info before native replacement starts, using the original FD's
program/BTF identity and each pre-call record stride. The real shim plus live
BTF consumer and runtime LTO pass the sole-kernel execution subset (BPF/native
both 9, original stride 16). Host tests cover same-code/different-table records
and output errors. This closes the capture component; nonconstant CEL and real
app installation remain open. No runtime gain or image publication is claimed.
Receipts: runtime-bpf-functions/shim-capture-report.json.

2026-11-16T11:31:29Z — Phase 1 nonconstant captured bodies: 3e7355e51/63547fcfe reuse
canonical BPF lowering through a text-IR process boundary, preserve actual
R1–R5 before optimization, and link bodies into the existing native LTO tool.
6095819c3 preserves unaligned load/store semantics; 89330803f tracks normal
canonical object/header dependencies. Seven functions x256 native vectors and
proof entries pass, as do constant/default-output and three context regressions.
Actual shim/live-BTF R1+R2 execution returns 13 in BPF and native. One producer
flag set remains; no new library build, vendor edit, benchmark change or image
publication. Actual app installation and checked-B acceptance remain open.
Receipts: runtime-bpf-functions/nonconstant-report.json.

2026-11-16T11:54:25Z — Phase 1 actual CEL compiler coverage: 3bce4215f exports bodies
from unmodified upstream Tetragon celbpf.CompileFn and executes nineteen
numeric/boundary vectors through runtime native LTO and native proof extraction.
All pass. This is source/ABI coverage, not app installation, simulator-B stock
acceptance or performance. One flag set and the published image remain intact.
Receipts: runtime-bpf-functions/upstream-cel-report.json.

2026-11-16T12:20:01Z — Phase 1 CEL verification coverage: add a focused runtime-context/stack/indirect-call wrapper around the four distinct actual upstream CEL bodies, then generate B from that same P through shared I and the normal B compiler. The existing stock loader gains a single-object invocation. Tests are ready; stock acceptance and actual app installation remain open. Production code, the unified producer flags and the frozen benchmark stay unchanged.

2026-11-16T12:32:02Z — Installed-size audit before further LTO optimization: [BCC/OTel per-piece evidence and gaps](../results/perf_20261113/lto-piece-audit/README.md) separates combined per-call observations from unknown individual contributions. Current all-record installed totals are BCC 38,841/7,965 B and OTel 330,814/167,504 B (native/JIT); P entry bytes are not the target. BCC 0.917x records the CPU-budget/environment difference, with cause still open. No component was removed by treating missing measurements as zero gain. The IR-linker default/build location now uses the sole base (3c9b453cf); binary relocation waits under imageEX. CEL B check 1504177 stopped at unresolved indirect-call proof before B generation; cel-b-first-failure.json preserves it.

2026-11-16T12:41:24Z — Attribution diagnostics: existing native-link --show reports appended ARRAY/read/hash/LPM byte spans. A retained-plan test compares BCC sys_enter/sys_exit and OTel native_tracer_entry/perf_unwind_native payloads to prior bytes, with show on/off. No optimization or emission policy changes; measured per-call contributions still need the matching counters/profile.

2026-11-16T12:51:12Z — Installed-size attribution result: four actual retained BCC/OTel payloads and show on/off bytes/relocations pass parity. BCC sys_exit contains 2444 B shared hash +490 B reads in 3465 B payload (installed separately3483 B); OTel native_tracer_entry has 2444 hash/255 reads/67 ARRAY/330 LPM in10459 B. Native-unwinder capture is absent; V8 uses its own actual plan. This identifies code growth, not an isolated per-call gain or new optimization. See lto-piece-audit/ranges.json and README.md.

2026-11-16T12:57:17Z — Phase 1 defined-code indirect CALL support: x86_code_provenance.rs starts from actual PC32 LEA relocations to included function entries (section plus address), follows full-width register/private-stack copies within basic blocks, and preserves the original CALL. Partial writes, overlaps, unknown aliases, RSP changes, calls and block boundaries erase affected facts. This relaxes the existing unresolved-call failure for proven image-code targets, without a helper guess or app-name rule. Source subset/round-trip execution tests are queued; no app/B stock or performance claim.

2026-11-16T13:06:47Z — Phase1 code-pointer result: source643fbf278/d3833a6e9 with test-type correctionb5f88b9d2 passes51 Rust tests (3 opt-in cases ignored in the general run),32 constructed native executions and64 actual retained upstream CEL executions after production proof/kernel-link round-trip. First compile errors stay raw. This resolves the host non-tail CALL subset; B stock verification and actual Tetragon installation stay open. runtime-bpf-functions/code-pointer-report.json. No new optimization/image publication.

2026-11-16T13:17:00Z — Phase1 next verification step: 0924b7f1a reuses the retained actual-CEL proof from the passing host test, then the same shared I/normal B compiler and existing libbpf stock loader. CPU16, sole-kernel one-vCPU/2GiB guest under imageSH; no timing lock or image publication. B generation/stock outcome pending in 20261116-code-pointer-stock, with build artifacts archived even on compiler failure.

2026-11-16T13:41:56Z — Coordinator shared-hash request: retain the existing raw hash helper relocations, so all programs call the sole kernel implementation already used by the eBPF JIT. Delete x86_hash_lookup.rs, its retired byte-emitter driver, and unused runtime hash layout fields; loader cache advances to v42. This removes the duplicated custom constant-key machine code, keeps typed/LRU/per-CPU/map-in-map postprocessing and introduces no new kernel helper/resource lifetime. Per-call and installed-byte comparison remains pending after coherent publication; old measurements are preserved.

2026-11-16T13:52:22Z — Shared-kernel-hash host subset passes: 48 Rust tests plus the retained four-program range audit, loader syntax and 27 relevant layout facts independently resolved from live and canonical BTF. BCC sys_exit payload 3465→1021 B, OTel sampling entry 10459→8015 B, V8 39963→37519 B; each removes exactly 2444 B while retaining raw kernel calls. No-hash sys_enter stays 123 B. Installed bytes/per-call remain unmeasured. The initial raw-BTF identity diagnostic failure is retained; semantic field comparisons pass despite dedup/type-ID differences. Receipts: perf_20261113/shared-kernel-hash/.

2026-11-16T13:55:39Z — Phase 1 finite indirect-call generation: carry exact full-width RSP-relative spill values through the existing CFG reaching-definition join. Partial/overlapping/unknown-alias writes, stack adjustments and calls erase uncertain spill facts; original native instructions and runtime dispatch stay unchanged. Seven focused tests cover spill/reload, finite joins, unknown joins, partial writes/loads, alias/RSP clobbers, call frames and helper-relocation precedence. Actual retained CEL shared-I/B/stock replay follows; no app/stock/performance claim yet.

2026-11-16T14:00:04Z — Phase 1 CEL generator result: the same retained proof now produces B (18 entry instructions, one subprogram, 440 executable B bytes). Stock loading stops in libbpf extern resolution because the diagnostic guest omitted the existing kprog_unspecified_input provider module. Add that module load to this guest target and retry the exact B; original failed log/build archive retained. No verifier acceptance, application or speed claim. runtime-bpf-functions/generator-indirect-spills-outcome.json.

2026-11-16T14:03:38Z — Phase 1 actual-CEL coverage: the four-body B/stock recipe now rebuilds the current canonical linker through the existing image-exclusive build target before proof extraction, includes the existing unspecified-input provider in its stock guest, and archives artifacts even when B generation fails. This avoids retrying the retired release linker for an already-fixed source class. Dry run passes; the batch queues after timing users release the image lock. This is diagnostic pipeline maintenance, with no new LTO optimization or performance claim.

2026-11-16T14:07:17Z — Correction to the CEL diagnostic failure cause above: stock_native_input.h represents kprog_unspecified_input as an extern array, and native_loader.cpp binds it to a private mutable array map. It is not a module kfunc. Reuse existing scheduled_table_stock.cpp for production relocation followed by stock bpf_prog_load; remove the unnecessary module load from both CEL diagnostic targets. The earlier module hypothesis/retry and stopped four-body queue remain recorded. No changes to B instructions or simulator semantics. Both corrected Make dry runs pass.

2026-11-16T19:33:52Z — Known lookup operation selection: retain complete named call targets (including ARRAY_OF_MAPS and LRU_PERCPU_HASH), and select the sole kernel trie_lookup_elem for known LPM map types. This avoids generic ARRAY/LPM dispatch for proven named arguments. Unknown native arguments retain their actual dynamic maps. No new per-call check; all existing LTO stays on. Host ELF/retained-plan subset queued under results/known-lookup-targets-20261116. Installed bytes and per-call body/helper/map effects await coherent publication after C baseline. OTel PMU baseline: inline LPM 4286.97 and ARRAY dispatch 1279.95 sampled cycles per root invocation, with external ownership/skid limits as recorded in otel-regression-20261116.

2026-11-16T19:36:34Z — Known lookup subset passes: 49 linker tests, production linker/loader builds. Retained OTel sampling entry 8001 to 7604 payload B (397 B dispatch removal); Katran payload unchanged, two outer calls now bound. Host fact variants only; installed bytes/per-call measurement pending. Receipt: results/known-lookup-targets-20261116/report.json.

2026-11-16T19:38:47Z — Named-map facts across resolved jump tables: reuse helper provenance's existing immutable-table destinations and erase local map identities at every destination. Unknown indirect branches retain generic lookups as before. This replaces the whole-function loss of map facts caused merely by a known switch table, with no new per-call check or refusal. Three adversarial edge shapes cover bypassing either map load. Host tests and retained OTel V8 replay queued; installed/per-call effects pending.

2026-11-16T19:41:46Z — Resolved-table subset: 50 linker tests and production builds pass. Retained OTel V8 with bound LPM fact loses 397 payload B; separate table-dataflow contribution remains unmeasured. See known-lookup-targets-20261116/cfg-report.json. Actual native-unwinder map metadata retained in checked-six-apps request 3 provides next replay input; dynamic inner ARRAY lowering remains P-map-CFG.

2026-11-16T19:51:05Z — Share selected ARRAY/PERCPU_ARRAY routines within each native image. The constant-bound body is emitted once per identical machine-byte shape, and call sites retain one direct local call. This replaces per-site copied bounds/address/per-CPU sequences; dynamic maps still use actual-type dispatch. Distinct bounds, value sizes, offsets and per-CPU bases remain distinct bodies. No new runtime type check or refusal. The actual native-unwinder host audit exposed 736 B of duplication; subset execution covers shared calls, bounds, distinct value offsets and per-CPU bases. Installed bytes and body/helper/map per-call results await publication after C baseline. Results: known-lookup-targets-20261116.

2026-11-16T19:56:32Z — Shared selected ARRAY subset passes: 51 linker tests, 3 existing ignored, production builds pass. Bound-fact replay payload changes: Katran 10528→9424 B; OTel entry 7604→7300 B; V8 37115→36027 B; native unwinder 30956→30383 B (three bodies totaling 91 B). The unwinder still adds 163 B versus absent named facts. No installed or per-call gain claimed; local CALL/RET remains a measurement cost. Receipt: results/known-lookup-targets-20261116/shared-report.json.

2026-11-16T20:08:52Z — Actual inner ARRAY type in trusted IR LTO: existing FD pointer query also returns inner_map_meta type, four module copies together; loader carries those actual types for map handles, excluding DATASEC values. The existing compiler infers a common type through immutable pointer tables, PHI/select and lookup returns. Proven dynamic ARRAY lookups call one shared body with sole-kernel BTF offsets and live per-map bounds/mask/stride; direct named arrays keep linker constant specialization. No new per-call type check or refusal. Missing/mixed/mutable-table/arithmetic identities retain their original helper call. P flags and all existing LTO stay on. Host positive/negative/actual OTel subsets queued under results/inner-array-lto-20261116. Actual query execution, B stock and installed/per-call effects remain publication checks.

2026-11-16T20:14:50Z — Inner ARRAY actual-IR refinement: the first host batch passes its fixtures and both active x86 module syntax checks but selects zero real OTel sites. Canonical O3 IR shows numeric helper IDs behind the compat header's empty, tied-register asm, and full-width pointer/integer PHI copies. Recognize that declared identity without deleting the side-effecting barrier; nonempty asm and narrowed handles retain generic calls. Additional positive barrier execution and negative cases cover those forms. The IR inspection helper was renamed from inspect.py after shadowing the Python standard module; the failed inspection is retained in the turn evidence. Real-app effectiveness remains open until retry.

2026-11-16T20:26:39Z — Coordinator 20:20 route correction: inner type and value size now come from bpf_map__inner_map of the original source ELF, bound to actual source map IDs; the four module response changes and parser changes are removed forward, leaving modules byte-identical to before this item. Common inner value sizes specialize the shared ARRAY stride; mixed/unknown sizes retain live stride. Type inference still preserves mixed-type and modified-handle semantics. The successful earlier host retry selected 68 actual OTel sites in one 36 B body; payload30383→30419 B, not an installed/per-call gain. The no-module libbpf route and constant-size body are queued for subset validation before returning to the requested hash/LRU regression guest.

2026-11-16T20:50:02Z — Inner ARRAY libbpf route validated: 11 cases/2520 native execution vectors; actual16 OTel templates and source-section byte preservation pass; loader/compiler and active x86 syntax pass. 68 real OTel sites share a27 B body, host payload30383→30410 B. Four modules unchanged. Installed/per-call/B-stock pending; source/runtime claims kept separate. Next priority is coordinator20:20 hash-regression diagnostics; static caller LRU sequence unchanged across f45. See both results directories.

2026-11-16T21:10:49Z — Shared kernel hash regression diagnostic, image6641a7e1 unchanged. Result-local adapter af310d7e9 and analysis98f6819b0 preserve all production LTO; retained2444B hash is substituted only in the direct-native diagnostic, with a5B entry jump and shifted ABI/relocations. Katran shared case210136_729192 completes: JIT/native207.044/204.532ns per call, installed13641/10546B, throughput2505432/2440796pps. Native root cycles per call:211.142 remaining program text (includes other inline work),3.360 ARRAY dispatch,2.500 LPM dispatch; external hash155.885 lacks exclusive caller ownership. These are cycles, not a fabricated ns split or pure body. Copy case is installed12995B, six calls redirected and retained routine bytes match except fallback displacement; timing remains in progress. OTel both cases follow. Static and installed-call evidence preserve generic LRU marking; eviction cost remains under comparison. Results: shared-hash-regression-20261116.

2026-11-16T21:13:55Z — Katran retained-hash pair complete, diagnostic1x60s/image6641a7e1/20-23: shared/copy native204.532/205.781ns per call,10546/12995 installed B,2440796/2428858pps; JIT controls207.044/205.679ns. No per-call recovery from the copied routine despite2449B extra. Copy hash68.560cycles/call plus external hash97.009 versus shared external155.885; those external roots are not exclusively owned. Caller LRU marking and generic dispatch remain. OTel cases are next in the same live queue; no production source/image change follows this single-sample result. Receipts: shared-hash-regression-20261116/README.md and both costs.json.

2026-11-16T21:24:21Z — OTel shared-hash diagnostic211320_080784 completes: JIT/native4156.394/5286.145ns per root/app call,167504/303930 installed B. All production LTO stays on. Disjoint native text cycles include tail programs: remaining3570.823,LPM4333.540,ARRAY1429.922,userprobe2393.348,kernelprobe9.365; external hash1934.717 is not exclusively owned. No metric scrape means exact unwind work is unmeasured; actual native tail execution is sampled. OTel copy comparison remains in progress; no source optimization follows this partial pair. Source/results shared-hash-regression-20261116.

2026-11-16T21:34:39Z — OTel retained-hash diagnostic pair complete: shared/copy5286.145/5158.974native ns per call,303930/330869installed B; ownJIT4156.394/4095.347ns. Control-normalized copied gain1.00960x costs26939B extra; main native unwinder/hotspot have no typed raw hash and stay unchanged. Eleven copied routines match runtime code,30calls redirected. Exact LPM/ARRAY/probe ranges remain dominant in both cases; root cycles and unowned external costs stay distinct from ns. Production shared routine stays. comparison.json and both app/cost/link receipts under shared-hash-regression-20261116. Historical throughput regression is not explained by this small hash effect; next is Katran sample decay.

2026-11-16T22:09:48Z — Queued LTO source entry/kernel subset confirmation: current P475/475 entry extractions and239/239 captured kernel emissions pass with runtime ABI and no disabled LTO piece. Fresh Tracee169 actual load plans replace missing old layout facts; diagnostic installed JIT/native2068774/1693847B across167 measurement-window programs. No per-call optimization gain is inferred from this host confirmation; runtime LTO fact gaps, Tetragon generated CEL, B stock and Cilium equal packet path remain open. No image/base publication during C baseline round. Results host-link-replay-20261116.

2026-11-16T22:35:33Z — Post-cleanup Katran stats-on baseline 215758_610196: JIT/native 185.812/187.283 ns per call (0.99215x), installed 13641/10546 B (0.7731 native/JIT). These aggregate arm counters and three workload series precede the lookup/map-ops batch; per-sample BPF times are not retained. Shared hash stays enabled; the old monotone decay did not repeat and worker queue contention remains a lead, not an established cause. New batch publication/check runs under image/timing locks with the frozen entry; official effects remain pending.

2026-11-16T22:55:25Z — Conditional Jcc function-tail pipeline fix: existing discovery now retains the real callee, and the inverse original condition guards the existing unconditional tail rewrite and its ABI/relocations. No new check, refusal, switch or helper. All 51 existing tests, four native fixture forms/16 executions and current-P host replay475 entries/239 kernel emissions pass. Fixture31/39B is not app installed size; current image96a677d6826f predates this fix, so app per-call/body/helper/map/installed effects and B stock remain pending. Results conditional-tail-20261116.

2026-11-16T22:57:44Z — LPM live-symbol collection correction: keep trie_lookup_elem in the existing kallsyms wanted set. The new generic named-LPM op selected it but its address was filtered out before lookup, causing OTel perf_unwind_native and Cilium cil_xdp_entry native-load failures on image96a677d6826f. One added wanted-name entry fixes the collection class without a runtime check/refusal or changed dispatch policy. Canonical loader build passes; actual image loads, per-call body/helper/map split and installed bytes remain pending. Failed runs224734_587583/225345_805000 stay. BCC diagnostic25/25 native installed7962B vs7965B JIT; no official timing gain inferred.

2026-11-16T23:05:09Z — Lookup/map-ops batch functional check on image96a677d6826f completes. BCC JIT/native144.191/145.304 ns per call and7965/7962 installed B; Tracee367.539/319.616 ns and2068774/1690844 B; Katran174.749/172.907 ns and13641/9442 B. One10-second sample is diagnostic, with no PMU split; these are not official per-call gains or per-piece attribution. OTel/Cilium LPM-target and Tetragon conditional-tail failures retain all raw and are corrected in source by a53922beb/3940c4bee. Next image keeps all LTO on and repeats the frozen check.

2026-11-16T23:30:36Z — Conditional-Jcc pipeline fix3940c4bee now passes the actual Tetragon policy/CEL native load on image603cacfb442a: run232540_669421 app ok,288 native replacement events, zero native-load failures,287/225 JIT/native measurement-window records (corrected after reading both inventories). This closes the real-context native-load gap of the earlier host-only subset; B generation/stock and official per-call attribution remain open. Detailed installed/counter records are in native-load-corrections-20261116/tetragon.json.

2026-11-17T10:47:47Z — Multi-day helper item 1a: current-task BTF reuses the existing full-width GS load, matching both kernel helper bodies and verifier lowering. Jiffies gains an optional same-boot symbol in the existing LTO layout and a fresh qword load at each eligible call, with no GS prefix, cached tick or per-call check. Compact signed-disp32 globals use 8 B; other addresses use 10 B. Older facts retain the original kernel helper. Existing executable fixtures now cover the BTF spelling and changed 64-bit jiffies values, plus the compact address encoding. Host validation is queued under timing SH on CPU 19; installed app bytes and per-call/body/helper/map effects are pending reserved clock and leaf-batch2 publications. Local call-site text grows 4 B for task BTF and normally 3 B for jiffies before layout; no app gain or half-size claim follows from static call counts. Source and host receipts: results/task-btf-inline-20261117.

2026-11-17T11:00:43Z — Item 1a host validation passes: one focused Rust test, 44 others filtered, including executable BTF GS-pointer and fresh full-width jiffies values; the compact signed-disp32 encoding and absent optional-fact case pass. Existing read/fault/policy/nesting vectors pass in the same fixture. Loader layout writer template instantiation passes C++20 with warnings treated as errors. Test and header recipes run on CPU19 under timing SH, with raw under /workspaces/kprog-raw/perf/task-btf-inline-20261117 and small receipts in results/task-btf-inline-20261117. No image/guest or app-level time/size measurement by PERF; those remain queued behind the coordinator's reserved publications.

2026-11-17T11:41:33Z — Item 1b user-string/compat-string leaf source is prepared. User strings preserve masked-pointer access, word-tail zeroing, word-fault byte retry, count/int-return conversion and full error zeroing; compat calls reuse one user/string and one kernel/string leaf per image with the existing task-size split. R9 bit32 preserves SMAP cleanup while R9D keeps the original count. First host run passes two tests (43 filtered), including 4693 user-string vectors/239 source faults and nine compat-string vectors. Original scalar/kernel-string/compat payloads remain byte-identical at 366/370/284/827 B. New user-string body400 B and compat-string fixture775 B are host payloads, not installed app totals. Valid BPF destination ranges are assumed; kernel usercopy instrumentation and hardware SMAP protection are outside this host evidence. Final rerun after equivalent selector-guard reduction is queued as PID2528303 under timing SH/CPU19, raw /workspaces/kprog-raw/perf/user-string-leaf-20261117. Source commit, installed bytes and per-call/body/helper/map effects remain pending; no image or guest. Recipe3a16eae2e and first-pass receipts are in results/user-string-leaf-20261117.

2026-11-17T11:55:22Z — Item 1b final source rerun passes both focused Rust tests, 43 filtered. All six emitted payloads match the first pass; retained scalar/kernel-string/compat bytes still match the earlier scalar batch. The 4693 user-string vectors and nine compat-string vectors pass, with exact source-site recovery and shared leaf/dispatcher target checks. Source and final host receipts land together in this step; the two build-input files are released for the queued clock image and batch-2 handoff. No app-level gain or installed-byte result yet; final host-summary.json and host-output.txt are in results/user-string-leaf-20261117.

2026-11-17T12:45:12Z — Applied coordinator batch-2 LTO after the clock image snapshot. UID/GID now reaches one 53 B shared body per calling program, reading live current->cred UID/GID with initial-user-namespace identity conversion; six vectors include changed credentials and NULL current. Existing GS/call-slot mechanisms are reused, with no duplicate validation or additional empty error catch. Kernel strings use DEC's loop flag and skip the redundant successful NUL store: host body284→282 B, compat-string fixture775→773 B; existing193 kernel-string and4693 user-string vectors pass. Scalar kernel/user, user-string and scalar-compat payloads remain byte-identical. Clock naming changes no byte literals;15 vectors pass. Full linker suite43 passed/3 existing opt-in ignored, canonical loader build passes; proof fixtures stay in persistent raw. Results/leaf-batch2-20261117 records host evidence. Cilium agent switches and flag dependency propagation are a separate producer step; installed app bytes and per-call/body/helper/map effects remain unmeasured until the scheduled batch.

2026-11-17T13:13:47Z — Batch-2 Cilium producer: loaded lxc/host/xdp variants use the agent-generated frozen-workload switches, including monitoring aggregation 0, CT flags 7, policy audit/verdict notification, routing/host endpoint and XDP CIDR filter as applicable. Addresses remain runtime values; common machine flags stay O3. Six native compile recipe families now depend on their flag-defining Makefile, preventing stale P after flag edits; Tetragon already rebuilds through its phony recipe. Dry run schedules seven Cilium objects, actual canonical producer passes at 13:09:03Z with manifest regenerated, under timing SH/image EX on CPU19. Host linker suite and loader passed separately (8b31e4533). Installed bytes, per-call/body/helper/map effects and equal packet paths remain pending Omp batch-2 image/check/timing; producer section sizes are not the installed-size metric. Receipts: results/leaf-batch2-20261117.

2026-11-17T13:26:13Z — Joined clock/current-task/user-string/tail-frame image cb4bd4d8 subset results are complete, before batch2. Katran run124541_839520 is196.6/318.9 eBPF/native ns per call (0.616x), installed13641/9783B; throughput sample ratios0.560/0.863/0.591. This does not isolate the clock or probe change. BCC aggregate1.205x has about2.08x native sched event counts; Tracee1.822x has substantial sample spread. No equal-work target or per-piece gain claim follows. Body/helper/map split is absent, installed half-size remains unmet, quiet repeats remain in Omp schedule. Readout and provenance: results/leaf-batch2-20261117/clock-batch-readout.md.

2026-11-17T14:06:36Z — Shared-helper pipeline correction: local E8 calls and E9 tail jumps reach the same shared leaf while preserving their original opcode. Probe, UID, clock, ARRAY and LPM paths use the existing common redirection; duplicated clock/map predicates are removed. External kernel-helper relocation slots remain E8, with no module/format/check addition. Canonical linker suite and all retained pre-existing leaf body/recovered-site byte comparisons pass under timing SH/image EX on CPU19. Actual counts and mixed-opcode/native-return cases are recorded in results/shared-helper-tail-20261117/host-output.txt. No app per-call/body/helper/map or installed-size gain is inferred; image/check and any affected-app timing stay with Omp. Raw /workspaces/kprog-raw/perf/shared-helper-tail-20261117/host-20261117T135709Z-2591610.

2026-11-17T14:11:32Z — Compact live-global operands in probe-read leaves: signed-disp32 absolute SIB loads/TEST retain 64-bit address size and live USER_PTR_MAX, SMAP capability and virtual-width values. Wide addresses retain MOVABS and fold field displacements. Existing policy/recovery/cleanup logic stays; no module/schema/refusal or flag change. Full canonical linker suite passes under timing SH/image EX on CPU19, including wide and compact execution variants and signed-address boundary decoding. Local payload sizes and full output are in results/compact-probe-globals-20261117/host.json and host-output.txt; these are not installed app bytes or per-call/body/helper/map gains. Omp schedules image/check/app timing. Raw /workspaces/kprog-raw/perf/compact-probe-globals-20261117/host-20261117T141057Z-2595751.

2026-11-17T14:31:53Z — Constant-scalar-read foundation: existing register constant propagation consumes the code-table destinations already resolved by helper provenance, joining every edge at original ELF addresses. Unresolved/non-boundary edges and unsupported local calls keep existing unknown facts, with no load refusal or runtime guard. Existing memory routine specialization can now use those facts. Full canonical linker suite and prior leaf/recovery byte comparisons pass under timing SH/image EX on CPU19. This slice does not yet emit constant-size probe leaves or change the loader/module schema. Results/constant-probe-size-20261117 records actual tests/raw; installed app and per-call effects remain unmeasured. Raw /workspaces/kprog-raw/perf/constant-probe-size-20261117/host-20261117T143116Z-2601279.

2026-11-17T15:11:42Z — Constant-size scalar probe reads: each existing domain leaf uses a fixed count only when all direct and compat callers agree on the low-u32 RSI value. Internal helper branch metadata preserves the fact through layout, conditional tails and numeric joins. Known terminal helper branches retain their original-site facts. Counted qword loops and fixed tails preserve load/fault/store order and full-size zeroing, without cloning policy bodies or adding a per-call check, size limit, switch or public schema. Full canonical linker suite and retained generic payload/recovery comparisons pass under timing SH/image EX; actual count/width/policy/SMAP/zero/fault and helper-binding cases are in results/constant-probe-size-20261117/copy-host-output.txt. Host sizes are not installed app bytes or per-call effects; Omp schedules image/check/timing. Raw /workspaces/kprog-raw/perf/constant-probe-size-20261117/copy-retry2-20261117T151059Z-2610649.

2026-11-17T15:33:20Z — Known ARRAY address arithmetic: positive non-power-of-two strides through 127 use 64-bit IMUL imm8. Nonzero value offsets fold both additions into one 64-bit LEA (disp8 when signed displacement fits); zero offset retains the shorter ADD. Existing SIB scales, bounds, masks, per-CPU loads and unsupported-stride behavior stay as before. Stride24/offset304 arithmetic is 16 to 12 local bytes and three to two instructions. Host tests cover wide products, signed displacements and lookup bounds; retained probe/clock/UID bytes are compared unchanged. Application per-call/body/helper/map and installed bytes remain pending Omp timing. Results: results/array-arithmetic-20261117; raw /workspaces/kprog-raw/perf/array-arithmetic-20261117/host-20261117T153243Z-2617474.

2026-11-17T15:40:20Z — LPM encoding: the existing nonzero BSR paths use XOR63/XOR95 instead of NEG/ADD; the clamp CMP still supplies subsequent flags. Memory operands use disp8 when the existing signed offset fits, with explicit ModRM positions preserving SIB. No new runtime checks, facts, limits, flags or module/schema changes. Full host suite, all differing-bit/prefix/flag cases, compact/wide layouts, memory operand decodes, compressed-trie fixture and generic call ABI pass; previous probe/ARRAY/clock/UID files stay identical. Results: results/lpm-compact-20261117; raw /workspaces/kprog-raw/perf/lpm-compact-20261117/host-20261117T153941Z-2620871. Local bytes are recorded separately; app per-call/body/helper/map and installed bytes await Omp batch.

2026-11-17T15:41:34Z — LPM host receipt a9bfdebb7: fixture330→284B (14 short displacements save42B; two XOR substitutions save4B). Full suite51 passed/3 existing ignored;98 operand decodes,34920 bit/prefix/flag executions,65590 trie/ABI cases pass;203 previous payload/recovery files identical. These are local routine bytes; per-call/body/helper/map, throughput and installed native/JIT bytes remain pending app timing. Detailed receipt: results/lpm-compact-20261117/README.md.

2026-11-17T15:48:35Z — Known large memory counts: Routine retains the full u64 RDX count independently of the existing512-byte unroll policy. Larger known counts emit a counted32-byte GPR loop with fixed remainder; unknown counts keep the original dynamic body and small known counts keep their original unrolled bytes. No per-call length dispatch, new limit, refusal, flag, schema or module change. Full host suite and large exact-tail/guard/unaligned/return checks pass; full-width counters including u64::MAX are decoded without impossible allocations. Old small/dynamic memory payloads and other leaf/ARRAY/LPM bytes compare unchanged. Results: results/known-large-memory-20261117; raw /workspaces/kprog-raw/perf/known-large-memory-20261117/host-20261117T154720Z-2625131. Local sizes are not app per-call or installed native/JIT bytes; Omp schedules the target-app batch.

2026-11-17T15:50:54Z — Known-large-memory host receipt b1da87fe4: full suite52 passed/3 existing ignored;225 pre-change small/dynamic bodies and204 other payload/recovery files identical. Current668-byte zero-fill126→55 local bytes, arbitrary-fill141→70, copy168→86;4096-byte zero-fill126→40.36 full-width count/dispatch decode cases and expanded real unaligned/guard/return/source-preservation fixtures pass. This finishes item1d source/host work, with all existing LTO on. App per-call/body/helper/map, throughput and installed native/JIT remain pending Omp batch. Detailed receipt: results/known-large-memory-20261117/README.md.

2026-11-17T16:09:33Z — Remaining-helper prioritization, not a new optimization: BCC retained event-output ownership27% and map writes18% dominate body9%; current map-op binding already exists. Results/bcc-helper-costs-20261117 compares both historical arms with the separate joined-clock counter mix. The stage audit finds0/346 manifest entries enable the original-prototype query, leaving the normal native FD path on static helper names, including a context-sensitive helper25 difference. Pipeline repair proposal is posted to the coordinator for the frozen loader-core class; no production change, per-call gain or installed-size gain is claimed. Existing runs remain recorded, and missing current PMU is not a gate.

2026-11-17T16:17:21Z — LRU reference-byte CMP/MOV operands use zero displacement or signed disp8 when fitting; other offsets keep disp32. One common emitter replaces two duplicate emitters. Existing null guard, conditional zero-to-one reference update, value-pointer arithmetic and flags remain intact. Offset35 saves6 local bytes (same-shape postprocess25→19B), with no instruction-count gain or new per-call check, flag, limit, resolver or module change. Full host suite includes signed operand decodes, null/state/idempotence and read-only nonzero-reference execution. Existing probe/ARRAY/LPM/clock/UID and memory payloads compare identical. Results: results/lru-displacements-20261117; raw /workspaces/kprog-raw/perf/lru-displacements-20261117/host-20261117T161644Z-2634254. App per-call and installed bytes remain pending Omp batch; all LTO stays on.

2026-11-17T16:19:48Z — LRU displacement receipt26fc730d5: full suite53 passed/3 existing ignored;60 decoded operand cases,32 reference-state executions and a read-only nonzero-reference node pass. All627 prior payload/recovery files stay identical (204 other leaves/metadata,423 memory bodies). Offset35 same-shape postprocess25→19B; zero offset17B, wide128/255 unchanged25B. Instruction count and map work are unchanged. Results/lru-displacements-20261117/README.md records local evidence; application per-call/throughput and installed native/JIT remain pending Omp batch.

2026-11-17T16:30:43Z — Probe routine-local branch sizing uses the existing iced-x86 encoder before user/kernel scalar/string builders return bytes and recovery metadata. Instruction-offset maps move protected load sites and nested helper relocations together; existing append shifts to global offsets once. External E8 slots, protected-load lengths/R11 destination and all read policy/fault/zeroing behavior stay intact. Compat dispatch external jumps are unchanged. No new runtime check, limit, flag, resolver or module/schema change. Full host suite and 24 synthetic branch/call/load/append cases pass; mapped source-load bytes are compared against retained forms, with other leaves and memory bodies identical. Results: results/probe-short-branches-20261117; raw /workspaces/kprog-raw/perf/probe-short-branches-20261117/host-20261117T162945Z-2638683. Local sizes are not app installed bytes or per-call gains; Omp schedules image/check/target timing with all LTO on.

2026-11-17T16:36:15Z — Probe branch-sizing receipt d92c85898:54 tests passed/3 existing ignored,24 synthetic edge/call/recovery/append cases;98 probe forms preserve mapped source instruction bytes/lengths/R11 destinations,439 other files remain identical. Compact generic kernel/user351→285 /355→281 local bytes; compact strings267→221 /385→313; fixed8 compact221/225→179/179; compat scalar819→679 and string765→647. No instruction-count, app per-call or installed-byte gain claimed. Publication receipt filename repair4cda301b1 retained the successful test evidence and first workflow exit1; no source/test rerun was needed. Details: results/probe-short-branches-20261117/README.md.

2026-11-17T16:47:40Z — LPM and clock reuse the existing routine-local branch sizing step. Real external helper relocations are carried through sizing, then shifted once at shared-leaf append. LPM keeps its generic helper and stack ABI; clock keeps both preemption calls and the original fast-clock fallback. All external E8+zero slots, targets, branch behavior and live work remain intact. No new runtime check, refusal, option, fact, schema or module/kernel change. Full host suite, LPM trie/guard/prefix matrix, clock formula/preemption/fallback vectors and exact shared-slot contracts pass; probe and other leaf/memory payloads remain identical. Results: results/map-clock-short-branches-20261117; raw /workspaces/kprog-raw/perf/map-clock-short-branches-20261117/host-20261117T164250Z-2668290. Actual local sizes recorded separately; per-call/throughput and installed native/JIT remain pending Omp app batch, with all LTO on.

2026-11-17T16:53:41Z — LPM/clock short-branch receipt0ef3671ce: clock341→306 and LPM284→243 local bytes; instruction and external helper-call counts unchanged. Full suite54 passed/3 existing ignored,65590 LPM trie cases,34920 bit/prefix cases,15 clock vectors and exact real-target/shared-slot checks pass. All633 unrelated files stay byte-identical. Results/map-clock-short-branches-20261117/README.md records provenance, lock wait and batch-image inclusion caveat. App per-call/throughput and installed native/JIT remain unmeasured for this step; all LTO stays on.

2026-11-17T17:26:46Z — UID/GID leaf: the existing u32 BTF facts and published-credential immutability permit one qword load when UID immediately precedes GID on x86; nonadjacent layouts retain independent fields. Existing operand encoding and local sizing shorten field displacements and the null-current branch. Live IDs, original null -EINVAL, caller lifetime and packing semantics remain intact; no new per-call layout/namespace check, flag, refusal, limit or module/schema change. Full host suite and guard/read-only/unaligned/random/sentinel cases use nine synthetic layouts plus the sole kernel actual BTF. Other leaf and memory bytes compare unchanged. Results: results/uid-packed-load-20261117; raw /workspaces/kprog-raw/perf/uid-packed-load-20261117/retry-20261117T171823Z-2677411. Actual local sizes recorded separately; app per-call/throughput and installed native/JIT remain pending Omp timing, with all LTO on.

2026-11-17T17:29:38Z — UID receipt235f08262: sole-kernel BTF task_cred3328/uid8/gid12,4-byte fields; adjacent immutable pair uses one qword load, with separate fields for other layouts. Actual kernel leaf53→34 local bytes, original fixture53→31.54 tests passed/3 existing ignored;5330 real host executions across ten layouts,634 unrelated files identical. First fixture compile failure and repair remain recorded in results/uid-packed-load-20261117/README.md. No per-call/installed-app gain claimed; Tracee batch-2 image predates this later source. All LTO on, app validation/timing remains Omp-owned.

2026-11-17T17:41:08Z — Known scalar probe-read error zeroing retains the existing full original count: zero count emits no stores, other constants use a bounded qword loop and fixed 4/2/1 tail, with RAX error and original destination preserved after partial faults. Unknown scalar/string paths remain byte-identical; no new check, flag, limit, policy clone, helper identity or ABI. Existing execution/fault/policy cases and full-u32 bounded-loop decoding pass; source-load bytes/lengths/R11 metadata retain their meaning after local sizing. Results: results/fixed-error-zeroing-20261117; raw /workspaces/kprog-raw/perf/fixed-error-zeroing-20261117/host-20261117T174028Z-2683911. Local byte savings are not whole-app installed/per-call/body/helper/map/throughput results; those remain for Omp with all LTO on.

2026-11-17T17:42:29Z — Known-count error-zeroing actual receipt: source a5bb61c40, host 2683911 exited 0 at 17:41:13Z; 54 tests passed, 3 existing ignored. All 88 fixed execution forms and 14 count encodings pass; 98 forms preserve protected-load bytes/lengths/R11 after mapping. The 45 generic/unrelated leaf/metadata files and 423 memory bodies are identical. Compact scalar 8B kernel/user 179→146 local bytes, zero-count 168→127; 144B kernel/user 196→176 / 200→180. Primary effect is smaller cold error handling; no per-call/installed/body/helper/map claim without Omp target timing. Production net +22 lines, existing test +17 lines, no fixture growth; redundant setup parameter removed. Results: results/fixed-error-zeroing-20261117. All LTO remains on.

2026-11-17T18:00:36Z — ARRAY lookup returns directly from success and miss paths instead of jumping to a shared RET. Known ARRAY/per-CPU bodies lose one hot success-path jump and one local byte; runtime ARRAY loses one success and one miss-path jump and three bytes. Generic non-ARRAY dispatch still uses its original aligned E8 helper CALL, including original arguments. No new check, flag, limit, layout fact or module/relocation ABI. Full host suite, real key/bounds/mask/wide-product/fallback execution, both CALL/JMP entry slots and decoder return assertions pass. Results: results/array-returns-20261117; raw /workspaces/kprog-raw/perf/array-returns-20261117/host-20261117T175955Z-2692136. Local instruction/byte effects only; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp timing with all LTO on.

2026-11-17T18:02:47Z — ARRAY direct-return actual receipt: source eecc7e859, host2692136 exit0 at18:00:40Z; 54 tests passed, 3 existing ignored. Existing key/bounds/mask/wide-product/per-CPU-sharing/generic ABI and relocation tests pass, with no unconditional return jump in decoded routines. All221 prior leaf/metadata +423 memory files identical. Current known max3/max4096 stride24 value304 fixtures23/25B, each one byte smaller by layout; runtime64B against prior67B. Known success and runtime success/miss each lose a JMP, generic aligned E8 fallback is unchanged. Production net-1line, existing tests+14, no new driver/check/flag/limit/ABI. Per-call/body/helper/map/throughput/installed native/JIT remain Omp batch measurements, not inferred gains. Separate zero-tail inventory is partial: named-reloc bounds72B BCC/12024B Tracee; all239 historical plans fail current schema for missing cpu_tlbstate, so no emitted numeric-helper count or sharing candidate is claimed. Results: results/array-returns-20261117 and results/zero-tail-inventory-20261117. All LTO on.

2026-11-17T18:09:46Z — Runtime ARRAY field encoding reuses the existing displacement encoder for map_type/max_entries/index_mask/elem_size, and selects imm8 for positive type constants through 127. Other types retain all32bits; the existing i32 offset acceptance stays. Live u32 field reads, key/mask/bounds, wide product, direct returns and generic aligned E8 helper/arguments stay intact. No new runtime check, flag, limit, layout fact, encoder or ABI. Host tests include36 offset/type decoder cases plus existing lookup/fallback and relocation execution; unrelated leaf/memory files compare identical. Results: results/runtime-array-operands-20261117; raw /workspaces/kprog-raw/perf/runtime-array-operands-20261117/host-20261117T180906Z-2696608. Only local bytes change, not instruction or map/helper counts; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp measurement with all LTO on.

2026-11-17T18:13:18Z — Runtime ARRAY operands actual receipt: d226f71d0, host2696608 exited0 at18:09:51Z. Full suite55 passed/3 existing ignored;36 offset/type boundary cases plus existing key/bounds/mask/wide-product/generic ABI/shared branch+relocation execution pass. All223 unrelated leaf/metadata and423 memory files identical. Actual routine64→49B: type comparison saves6B, other3fields save3B each; same instructions/live u32 reads/map work. Generic dispatch reaches alignment35/E8 slot39; both remain accepted. Existing encoder reused, production net-1line, no new runtime check/flag/limit/ABI. Results results/runtime-array-operands-20261117. Body/helper/map/percall/throughput and installed native/JIT stay pending Omp target batch, all LTO on.

2026-11-17T18:21:18Z — Clock field ModRM operands reuse the existing memory displacement encoder; the old disp helper becomes the field wrapper, with the one nonmemory tkr_size immediate conversion kept inline. Same signed-offset acceptance, live loads, arithmetic, latch/version/preempt/stable/cycle checks, GS accesses and actual kernel fallback calls. No new runtime check, flag, limit, encoder or ABI. Full host suite, 102 field register/width/offset decoder cases and existing15 clock formula/preemption/fallback vectors pass; all3 actual-target E8 slots survive compaction and final shared offset once. Unrelated leaf/memory bytes identical. Results: results/clock-field-operands-20261117; raw /workspaces/kprog-raw/perf/clock-field-operands-20261117/host-20261117T182038Z-2700640. Only local size is measured; app per-call/body/helpers/maps/throughput and installed native/JIT remain for Omp timing with all LTO on.

2026-11-17T18:24:30Z — Clock field operand actual receipt: source046786855, host2700640 exit0 at18:21:23Z; full suite56 passed/3 existing ignored. All102 decoder combinations and15 existing clock execution vectors pass; three supplied-target E8 slots survive local compaction and final shared placement. All223 other leaf/metadata and423 memory bodies identical. Actual fixture306→247B: five zero offsets save4B each, thirteen short offsets save3B each. Same instructions, live reads, latch/version/preempt/stable/cycle behavior, GS and tkr_size immediate; production net+1line replaces old helper with existing-encoder wrapper. No new check/flag/limit/ABI. Results results/clock-field-operands-20261117. App percall/body/helpers/maps/throughput and installed native/JIT remain Omp all-LTO measurements. Next pipeline work is complete actual load-fact capture, not another stale-plan replay or invented runtime data.

2026-11-17T19:06:41Z — Phase1 capture repair receipt (no native optimization or speed claim): b949c4247 uses the frozen guest recipe and supported native-link override, with a single committed adapter exposed through the result mount. Actual functional captures OTel14/BCC25/Cilium47/Tetragon39 kernel requests linked successfully without archive errors. All14 OTel layouts supply cpu_tlbstate. Request counts are not installed-program counts. Source LTO pieces remain on; image remains the existing one, so these runs do not measure later unpublished LTO code. The sequential batch2708492 continues; paired-input host replay is queued separately. No benchmark/shared Makefile/native-source change. Results results/current-link-capture-20261117.

2026-11-17T19:38:42Z — Phase1 current-input closure: all6 functional apps status ok, actual paired kernel requests14/25/47/39/169/1 and no capture errors. Current host linker replays295/295 with no index errors after29.71s build; receipt7693b6276, capture/replay scripts b949c4247/a1e4ac935. Old schema limit is resolved with supplied live facts, not defaults/guesses/checks. Generic-tail sharing bounds1548B Tetragon/11268B Tracee do not establish half-size; no sharing code added. Existing-image installed native/original-JIT ratios0.80/1.61/0.80/0.83/0.85/0.71 are recorded in installed-baseline.txt with paired program counts. They are not later-LTO speed/installed gains. 0689a10a4 fixes only bool-to-integer summary rendering, without re-emission or raw mutation. Omp next image/check/target batch may take tested all-LTO code without further PERF confirmation.

2026-11-17T20:19:58Z — Phase1 original-program helper query diagnostic (results/helper-context-query-20261117). Same shipped image, all LTO on, control/query native manifests only: BCC installs 25/25 programs in each and all 25 kernel requests emit. Six used CALL bindings in four entries switch from generic output/stack functions to the kernel TP/raw-TP prototypes. Openat proof and kernel source establish the physical-context distinction; actual E8 relocation targets confirm emission. Installed bytes stay 12803 native / 7965 JIT (1.61x), no per-call/body/helper/map/throughput gain or B/stock result inferred. Production source and defaults are unchanged; the existing original-FD query and deletion of its obsolete opt-in plumbing stay with the coordinator under Freeze. This is pipeline evidence before another helper optimization, not a completed performance fix.

2026-11-17T20:45:53Z — Phase1 inline helper entry labels: native_link/src/x86.rs uses the existing replacement emitter for the first direct-load or tail-call stub chunk, retaining the original call label; later chunks stay synthetic. Previously a conditional branch to a replaced call or removed preceding NOP could skip the helper body. Baseline production-rewriter test failed after compiling; forward fix passes 57 tests (3 existing ignored), including 96 named/numeric, zero/nonzero-base, branch/fallthrough/live-value/tail-miss executions. All 647 unrelated payload/metadata files are identical; current sole main linker emits all 295 actual six-app requests. No new runtime check, switch, helper policy, emitter, frame or memory-barrier change. Results results/inline-helper-labels-20261117. Neutral host bytes are not installed bytes; app per-call/body/helper/map/throughput and installed-size effects await owner publication/check/target timing with all LTO on.

2026-11-17T20:51:15Z — Inline helper label actual-input receipt: source 10b79579a, comparison bb86bb333. Seven of 295 neutral payloads change (OTel4/Cilium1/Tracee2), with eight actual incoming source branches to tail-call/current-task replacements; the other 288 payload/relocation/map/ABI sets are byte-identical. OTel/Cilium/Tracee request-set bytes shrink 761/217/596 respectively; these are layout observations, not installed-size or per-call gains. Exact symbols and branch offsets in results/inline-helper-labels-20261117/comparison.json. Branch execution frequencies and app body/helper/map/throughput/installed effects remain for owner image/check/timing; previous runs remain recorded. Existing linker file identity already binds the template cache, so no cache check or version field is added.

2026-11-17T21:15:19Z — Dead helper target IDs (LTO, native_link/src/x86.rs): after ordinary helper resolution, remove only an adjacent unpatched MOV EAX/RAX whose immediate maps to that helper and has no incoming direct/table label. Reuse existing helper provenance, decoder and label mapping. Proof, finite dispatch, tail-call miss state, other registers and nonadjacent values remain. No new runtime check, flag, helper catalogue or DCE framework. Baseline regression compiled then failed; forward source58 passed/3 existing ignored, 56 argument/return/helper-count executions, seven proof shapes and tail miss pass; all647 unrelated files identical. Guest main remains unchanged during source tests; rebuild/295-request replay waits image EX. Static sites Katran59/OTel444/Tetragon1643 are opportunities, not emitted/installed savings. Results results/dead-helper-ids-20261117; per-call/body/helper/map/throughput/installed and new image remain pending, all LTO on.

2026-11-17T21:34:56Z — Next-item dispatch inspection only (results/map-dispatch-review-20261117): 162/295 retained neutral images have ARRAY fallback CALL into LPM and an aligned generic E8 frame in LPM. Existing ARRAY frames total2268 B per request set; no source/fusion or saving is applied. The direct module requires external E8 slots, so keep that ABI. A later existing-emitter fusion can remove the internal ARRAY-to-LPM call/return and stack adjustments with the final E8 frame preserved; dynamic frequency, app per-call/body/helper/map and installed-size effect remain unmeasured. Do not mutate the Rust cohort while dead-ID canonical replay is queued.

2026-11-17T21:49:07Z — Map-dispatch fusion ABI preflight only (results/map-dispatch-review-20261117, recipe370eea291): actual retained ARRAY/LPM fragments and captured layout facts pass6832 host functional cases, old/fused via CALL/JMP entry. ARRAY/LPM result/bounds/live values, guard keys, generic arguments/count and exact SysV stack alignment match; generic callback frame is16 B shallower. Test fragments307->293 B remove existing14-byte ARRAY fallback frame while preserving final external E8 and identical LPM body. No production source, real kernel helper, app timing or installed-size change. Canonical dead-ID main/replay remains queued; production fusion waits for that cohort boundary.

2026-11-17T22:01:45Z — ARRAY/LPM fusion production recipe e56472ef5 and receipt publisher ca8cde57a are queued as host 2776222 / publisher 2776223 under results/map-dispatch-fusion-20261117. They sequence after dead-ID replay/publication before source mutation, then use timing SH/image EX. Scope: reuse the ARRAY prefix and LPM body, remove one nested generic frame, keep final external E8 and existing layout-absent/proof behavior. Syntax validation passed. Actual rewriter regression, full host suite, unchanged leaf bytes, canonical build and all 295 captured-request replay are pending; no production, installed-size or per-call gain yet. Earlier 6,832-case retained-fragment preflight remains separate evidence.

2026-11-17T22:08:35Z — Tail-transition encoding review (results/tail-encoding-review-20261117, reader38cc97063): all206 retained kind10 sites recognized, Cilium87/OTel13/Tetragon59/Tracee47, BCC/Katran0. Three rel8 branches plus short map-bound/function/entry operands offer21B per stub,4,326B static request-set opportunity. Kernel indirect JIT already uses these encodings. Counter displacement must remain four bytes for the frozen relocation ABI. No source transformation, execution, installed or per-call gain; queued dead-ID/fusion cohort unchanged.

2026-11-17T22:16:58Z — Tail short-encoding production recipe520d7d1d5/cc721e609 queued as host2782317/publisher2782318, after fusion2776222/2776223. Existing compactor runs before opaque chunks with a temporary end label, maps the counter instruction then keeps its original four-byte displacement field. Layout operands and signed entry ADD use existing short encodings. The regression covers24 layout/frame/mask/long-cleanup shapes, followed by full tests/byte parity/canonical build/295 actual requests. Source mutation and measured effects are pending. Inventoryd12934d61 remains a static4326B opportunity only; Omp owns installed/per-call/body/helper/map/throughput measurements with all LTO on.

2026-11-17T22:24:20Z — Tail encoding host preflightbb7811b7b passes98,880 executions on all206 retained stubs: old/short x two four-byte counter displacements x120 bounds/count/slot/index cases per stub. Branch result, successful target, original ctx/map/narrowed index, selected counter increment and synthetic stack exit agree; bounds-miss RAX12 preserved. Test fragments18,956->14,630B. No kernel helper address executes, production source unchanged, no stock/installed/per-call/body/helper/map/throughput gain claimed. Queue520d7d1d5/cc721e609 still supplies actual Rust/ELF/metadata validation once its resource sequence completes. Results/tail-encoding-review-20261117 retains actual receipts/raw location.

2026-11-17T22:33:48Z — Production link entry is testable without live CLI replacement (results/link-entry-replay-20261117). Host58 tests pass/4ignored; captured-input entry runs295/295 original requests with0 failures. Source2c46d5c52 actual dead-ID neutral bytes: Katran9550->9255, OTel132859->130635, Tetragon294145->285911; BCC11028, Cilium180945, Tracee1747558 unchanged.54 changed/241 identical payloads, all helper targets/map counts/masks/recovery shapes equal. CLI size/mtime unchanged. No installed/per-call/body/helper/map/throughput claim; old canonical build is still pending, all LTO on.

2026-11-17T22:43:32Z — ARRAY/LPM wrapper fusion host tests completed (results/map-dispatch-fusion-20261117). Existing ARRAY prefix enters the existing LPM body without a nested frame, final external E8 retained; facts-absent and proof behavior stay. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.

2026-11-17T22:43:47Z — Actual ARRAY/LPM fusion emission: bcc/set: 25/25 emit, 0 fused, 11028 -> 11028 neutral B; cilium/agent: 47/47 emit, 24 fused, 180945 -> 180609 neutral B; katran: 1/1 emit, 1 fused, 9255 -> 9241 neutral B; otelcol-ebpf-profiler/profiling: 14/14 emit, 3 fused, 130635 -> 130593 neutral B; tetragon/observer: 39/39 emit, 18 fused, 285911 -> 285659 neutral B; tracee/monitor: 169/169 emit, 116 fused, 1747558 -> 1745934 neutral B. All request/error records and helper/map/mask/recovery observations are retained in comparison.json; no installed/per-call/body/helper/map/throughput gain claimed. Owner image/check/affected-app timing remains pending with all LTO on.

2026-11-17T22:47:12Z — Tail short-encoding host tests completed (results/tail-short-encodings-20261117). Three local branch encodings and layout operands compact before opaque chunks; the physical kind10 field remains four bytes and maps after compaction. All live checks and target work stay. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.

2026-11-17T22:47:27Z — Tail encoding actual host comparison: bcc/set: 25/25 emit, 11028 -> 11028 neutral B, 0 tail slots, 0 counter-slot multiset differences; cilium/agent: 47/47 emit, 180609 -> 178766 neutral B, 87 tail slots, 0 counter-slot multiset differences; katran: 1/1 emit, 9241 -> 9241 neutral B, 0 tail slots, 0 counter-slot multiset differences; otelcol-ebpf-profiler/profiling: 14/14 emit, 130593 -> 130320 neutral B, 13 tail slots, 0 counter-slot multiset differences; tetragon/observer: 39/39 emit, 285659 -> 284403 neutral B, 59 tail slots, 0 counter-slot multiset differences; tracee/monitor: 169/169 emit, 1745934 -> 1744902 neutral B, 47 tail slots, 0 counter-slot multiset differences. Requests/errors and helper-target observations retained in comparison.json. No installed/per-call/body/helper/map/throughput gain claimed; Omp owns image/check/affected-app timing with all LTO on.

2026-11-17T22:50:20Z — Fusion final host receipt: source b44b673aa/replay990c7d987,59 tests pass/4ignored,120 rewriter executions,647 unchanged helper files,295/295 actual emissions.162 wrappers each14B smaller (2268B total); helper/map/mask observations equal. Recovery readers950d1c73f/603352a95 show every ARRAY prefix/LPM body byte-identical, exactly deleted fallback RET recovery site removed per fusion, all other shapes unchanged. Actual tail source795483604/replay810f87f45 subsequently pass59 tests/4ignored,24 narrow/wide/frame/mask/cleanup cases,295 emissions and206 unchanged counter-slot multisets. Tail neutral reductions:Cilium1843,OTel273,Tetragon1256,Tracee1032 B (4404 total), BCC/Katran unchanged. Static stub opportunity was4326B; extra78B full-image encoding/layout difference is not yet classified. Canonical CLI remains unchanged; installed/time gains remain unmeasured, all LTO on.

2026-11-17T22:58:51Z — Tail encoding attribution completed (reader e8c96f9b3, results/tail-short-encodings-20261117/layout-delta). All206 actual new stubs byte-match the independently tested transformation and mapped4B counter fields:4326B. Remaining78B is15 original-source conditional branches6->2B plus6 JMPs5->2B, all21 mapped targets preserved, zero lost/gained source rows or other width changes. Every request delta is exactly attributed:4404=4326+78. No instruction/work removal or installed/per-call claim; no source/build/guest/test rerun for this receipt.

2026-11-17T23:25:24Z — Named map CFG host tests completed (results/map-provenance-cfg-20261117). Existing named-map lowering consumes identities agreed by all reachable predecessor paths; no new runtime code, helper or flag is introduced by the analysis. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.

2026-11-17T23:29:24Z — Named-map CFG source9cf2726e0, readera806bedfe: 60 tests pass/4 existing opt-in; 649 unrelated files identical;295/295 actual requests emit. OTel130320→129734B, Tetragon284403→284119B, Tracee1744902→1744643B; BCC/Cilium/Katran identical. Existing112 lookup/update identities plus80 push/pop identities gained (111 lookup,1update);17payloads change,6helper-target multisets change; prior identities/sites/maps/masks/tail-slot observations preserved. Tracee two programs grow4/21B and remain listed. Host-neutral bytes sum1129B smaller; installed/per-call/throughput/body/helpers/maps await Omp image/check/target batch. Results: results/map-provenance-cfg-20261117.

2026-11-17T23:38:57Z — Current zero-tail inventory (results/current-zero-tails-20261117, reader6d9973af3/505d62384) closes earlier239-plan missing-fact/numeric-call gap using all295 successful production emissions. Exact duplicated suffixes give Tetragon1552B/45copies and Tracee11268B/313copies local bounds; BCC/OTel/Cilium/Katran have0duplicates. All591 suffixes carry RET recovery sites; source-load recovery sites and relocations number0. Bounds are0.546/0.646 percent of captured neutral totals, after6B per duplicate successRET/errorJMP charge, before prefix retargeting/sizing. Source sharing, installed/time/body/helper/map/throughput effects remain open. Existing canonical CLI/base/image preserved for checked guest.

2026-11-17T23:47:29Z — Structural shared zero-tail host tests completed (results/shared-zero-tails-20261117). Identical error tails share one existing suffix with local success returns; policy/copy/cleanup and source-load metadata remain explicit. The full existing host matrix also executes a duplicate leaf through the shared suffix. No runtime selector, flag or helper is added. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.

2026-11-17T23:50:44Z — Shared zero tails sourcea4d1e0588, reader4558ded49:61 host tests pass/4 existing opt-in;96 additional full-matrix driver invocations;647/649 old files identical,2 compat blobs changed with identical source-status metadata. All295 captured requests emit. Tetragon284119→282567B (33payloads), Tracee1744643→1733375B (140payloads), four other apps identical;12820 neutral B smaller,0growth cases. All358 duplicate prefixes retain policy/copy/cleanup bytes and mapped branches/returns/shared targets. Helper/map/mask/recovery/R11/tail observations match. Success path stays, error path adds shared jump. Initial compile errors and fixture-cmp stop remain explicit. Installed/per-call/throughput/body/helpers/maps pending Omp all-LTO batch. results/shared-zero-tails-20261117.

2026-11-18T00:06:52Z — Known LPM candidate inventory reader68a75af61: all295actual emissions inspected, independent boot anchors agree. OTel52named sites/52kernel trie calls in8requests; Cilium32/32 in22; others0. OTel perf_unwind_native has4kernel trie calls alongside an existing293B generic native ARRAY/LPM range. Exact LPM binding currently bypasses that native body. Candidate is loaded MapMeta.type/key_size→private12-data-byte LPM kind in open schema/linker, reusing existing native routine while retaining other shape targets. Source implementation, current loaded candidate emission, installed/per-call/body/helper/map effects remain open. Results/known-lpm-sites-20261118 records provenance and next tests. Original-FD helper query remains core-owned phase1 work.

2026-11-18T00:14:31Z — Named LPM host tests completed (results/named-lpm-20261118). Exact loaded LPM key shapes reuse existing shared trie code; other shapes retain current kernel targets. Loader translation-unit shape tests and actual ELF target binding cover activation; original captured plans supply compatibility coverage. Runtime guards stay, with no new helper identity, flag or refusal. See actual before/after and unrelated-byte logs. Captured-request emission, installed bytes and body/helper/map/per-call/throughput remain pending.

2026-11-18T00:20:01Z — Named LPM sourcef98d0c87c/execution5da837c51:actual loaded LPM type/key16 selects private lpm12; exact named native RDI+existing layout routes to current shared native ARRAY/LPM body. Other shapes/absent layout keep current kernel target.18 loader TU shape cases and8 ELF binding cases pass;4hit/miss/prefix executions and full62tests/4opt-in pass. All841old fixture files identical,295legacy captured requests emit withbyte-identical blob/relocs/maps/ABI. Legacy compatibility is separate from new-kind activation. Initial host-execution fixture omitted kernel epilogue and SIGSEGV raw is kept; corrected RET fixture passed. No new trie body, runtime flag or refusal. Actual selected app paths/installed/per-call/body/helpers/maps/throughput pending Omp frozen batch; possible added routine bytes must be counted. results/named-lpm-20261118.

2026-11-18T00:30:22Z — Phase1 binding prerequisite: helper-fd-boundary-20261118 drafts a common original-program FD query, one line added/six obsolete opt-in lines deleted, patchcontextcheck0. Existing registered source-ID loader already obtains realFD and uses same companion loader; currentstock verifiedmodule andtimingmodule containexisting queryendpoint.33completedTracee requestrows allpositiveID (31success/2error),partialcoverage retained. Draft isunapplied, C++/kernel checks andactualtargetbinding remain owner work; context-onlyrequests needseparate actualprogram/aux semantics. No per-call or installed effect claimed. Core/module/image remainunchanged andallLTO stayson.

2026-11-18T00:58:47Z — Produced BCC global coverage (context-and-globals-20261118):25actual inputcode inventories have0bound target_family/target_pid/targ_tgid refs and3LINUX_KERNEL_VERSION refs. Current Kconfig addressbinder omitsreadonlyscalarfacts; actualloaderTUfixture exposes frozenfact gap(return1,mutablepasses), owner9-line draftappliesincontext only. Scalarbytescomefromexistingreadonlymap snapshot, notkernelversionguess. Draft/source application andper-call/installed/body/helper/map effects remainpendingownerbatch. Context-onlyprototype query also requiresownedprogramlifetime; checkedB loaderclosesitsFD beforeprintingID anddirect-native mustcontinuewhenBfails. No newruntimecode/flag/check/protocol orguest/imagechange here.

2026-11-18T01:21:45Z — Native trie child addressing (results/lpm-body-20261118): replace per-level stride8 IMUL with SIB scale and equivalent NOT/AND bit selector. Existing62 tests pass/4opt-in;295actual emissions pass,157ranges each8B smaller,1256neutralB total(Cilium192/Katran8/OTel8/Tetragon136/Tracee912;BCCsame),0growth. Helper/map/mask/recovery observations match. Compiled-kernel host body diagnostic: native deep median128.919→109.935ns(1.173x), kernel104.630ns; full/miss native costs stay about4.09/3.41ns. Both original bodies/explicit host patches/rawsamples retained. Ordinary-return stable-host diagnostic establishes body cost only; app per-call/throughput/body/helpers/maps and installed bytes remain Omp frozen batch work, allLTO on. CanonicalCLI/base/image and checkedguest2754970 stay in use.

2026-11-18T01:30:10Z — Trie prefix limit (results/lpm-body-20261118/prefix-limit): existing mismatch condition exits on query<node before common-prefix work; the remaining limit is node. Remove two CMOVs and one MOV per visited node, comparisons5→4, same guards/fallback/child/flags/lifetime contract. Existing62tests/4opt-in and295actual emissions pass;157ranges each7B smaller(1099neutralB),0growth,helper/map/mask/recovery observations match. Same-driver host deep native median109.935→101.173ns(1.087x),first-bit miss3.408→2.744ns(1.242x),full-hit~4.09ns; same-run compiledkernel deep103.979ns. Stable-host ordinary-return body diagnostic; app per-call/throughput/body/helpers/maps andinstalled/JIT effects remain Omp frozen all-LTO batch work. CanonicalCLI/base/image and checkedTracee2754970 stay in use.

2026-11-18T01:37:50Z — Trie node flag byte (results/lpm-body-20261118/flag-byte): existing bit0 live test changesF7/imm32→F6/imm8, like sole-kernel testb; same predicate/branch/helper/child/lifetime.62tests/4opt-in pass, including104760flag/prefix cases and65590trie/guard/ABI vectors;295actual emissions pass.157ranges each3B smaller,471neutralB(Cilium72/Katran3/OTel3/Tetragon51/Tracee342;BCCsame),0growth. Helper/map/mask observations match.157recovery lengths7→4 andfollowing offsets−3 are fully attributed with identical destinations/other lengths. Host native deep median107.675ns versusprior101.173, kernel108.507versus103.979; fullhit4.217versus4.085. Allsamples retained; size gain measured, isolated app speed remains open. Omp frozen all-LTO batch measuresinstalled/per-call/body/helpers/maps/throughput afterpeerlease2754970.

2026-11-18T01:59:08Z — Exact LPM entry (results/lpm-body-20261118/known-entry): retain actual loaded Lpm12 through LocalLpm patches, remap its direct query entry with existing compact_at, share one guarded worker with dynamic callers, and omit type/data-size dispatch plus generic fallback for all-exact callers. Existing query/tree/helper ABI and other-shape/proof routes stay.62tests/4opt-in pass,16 binding combinations and8 executions plus mixed-entry targets pass;295legacy blob/reloc/map/ABI sets byte-identical. Legacy compatibility is distinct from actual new-image kind activation. Pre-source host direct slice full-hit guarded4.090→known2.715ns(1.506x),deep109.756→106.384ns(1.032x); allseries/alignment limits retained. App installed bytes/per-call/body/helpers/maps/throughput remain Omp frozen all-LTO batch work after peer lease; no newruntimecheck/flag/refusal/helper or duplicated worker.

2026-11-18T02:04:41Z — Exact LPM source79ece52c1 follow-up extends the existing bitwise reference to both guarded/exact emitters:209520 vectors pass; full62tests/4opt-in and295 legacy artifact sets stay identical. Compact/wide fixture bodies225→187 /267→223B. Matrix-only follow-up leaves production at79ece52c1; allraw reports stay under candidate-20261118T020123Z-2865866. Actual loaded-kind activation, installed/per-call/body/helpers/maps/throughput remain Omp frozen all-LTO batch work after checkedguestlease2754970.

2026-11-18T02:32:33Z — Helper-tail audit (results/helper-tail-forms-20261118):295 actual captures contain41935 ordinary helper sites/6501 lookups and0single/conditional/numeric-join helper tails. All84direct trie relocations and157generic fallback relocs areE8. A tail-specific LPM extension has0observed sites in this set. Temporary14-line trace patch is preserved as evidence and removed from production; clean-source soleunit rebuild/full62tests/4opt-in and295byte-identical artifact sets pass. Production stays79ece52c1+matrix9ebfac020; allLTOon, app installed/per-call effects still Omp batch work. No source optimization/gate/flag or speed claim added.

2026-11-18T20:40:00Z — Hand-written helper reimplementations removed (design.md 编译流水线 keeps only relocation binding, array/percpu lookup inlining, readonly folding and hash-family direct calls). Deleted src/x86_probe_read.rs, x86_ktime.rs, x86_task.rs, x86_lpm_lookup.rs, x86_runtime_array.rs (1,704 lines) with their fixtures, the LinkPlan kernel_layout chain in main.rs, and the loader kernel_symbols entries they consumed (cpu_number dropped; ktime_get_mono_fast_ns kept for the mono-fast remap). Rows above that describe those routines are dead as written: shared ARRAY+helper routine fusion, runtime array dispatch, kernel/user memory reads as direct loads, smp_processor_id as a per-CPU load, LPM trie lookup and child-load overlap, probe-read LFENCE and kernel-string reads. Surviving and still active: relocation binding, ARRAY/PERCPU_ARRAY lookup inlining from LookupSiteSpec, readonly folding, hash-family direct calls, the tail-call inline stub (kind10 counter plus four offset keys) and the bpf_ktime_get_ns -> ktime_get_mono_fast_ns remap. Check: cargo test --release 43 pass/4 ignored/0 fail (was 62/4/0; 19 tests removed with the leaves); loader native_loader and native_loader_shared build clean; fidelity check-loader-kallsyms passes (103 symbols); a real Tetragon proof object links to 14,826 B with 216 relocs and 26 map patch sites.

PERF 2026-11-19T05:48:41Z: Queue reconciled with `07d9c4c96`. Hand-written task/clock/probe/LPM/runtime-ARRAY routines and their leaf specialization experiments are retired; retained reports are historical evidence, not pending candidates. Byte-only follow-ups are closed on the operator's 11-18 instruction. The next runtime work is helper C inlining in checked-sim-c, using the same checked simulator input; relocation binding, known ARRAY/PERCPU_ARRAY, readonly folding, hash kernel calls and the tail stub survive. No new performance result is claimed by this queue update.

PERF 2026-11-19T06:00:59Z: C ARRAY helper in checked-sim-c LTO (`compile_sim_ir.cpp`, `trusted_specializer.py`, `micro-prog/inline_array.py`). Trusted named map handles select ARRAY before native compilation; the C body follows kernel array_map_lookup_elem and boot BTF fields, then llvm-link/O3 inline it with the checked frontend. Direct-value globals, unknown handles and other map types keep kernel calls. No new runtime dispatch/check or machine-code helper. Host: 1,008 bounds cases, two generic-call cases, 25 BCC frontends (zero eligible ARRAY), one checked OTel system_analysis call removed, and production compile API/native proof links pass. OTel proof text/relocs 1542/7 → 1572/6; installed bytes and body/helpers/maps per-call/throughput await OMP's checked-sim-c app batch. Results: checked-array-c-20261119.

PERF 2026-11-19T06:19:32Z: Checked-sim-c C probe wrappers (`inline_probe.c`, `compile_sim_ir.cpp`, `trusted_specializer.py`) inline the existing user/kernel common body around kernel copy_from_user_nofault/copy_from_kernel_nofault. Preserve u32 length, signed int result and full zeroing on error; kernel copies retain policy, SMAP, pagefault state and recovery. Loader LTO/link-schema headers bind the two existing copy functions. Compat/string helpers retain their calls. Selected-helper metadata avoids compiling an unused C module; ARRAY remains on. Host builds, 96 wrapper cases/u32/compat, four proof/kernel bindings, all25 BCC production compile APIs (37 kernel-probe sites) and ARRAY/OTel regression pass. No app runtime, body/helpers/maps or installed-byte gain claimed yet; OMP combined batch pending. Results checked-probe-c-20261119.

PERF 2026-11-19T06:35:06Z: Analysis-only B uses O1 in trusted_specializer.py (frontend and B backend) to avoid the retained superlinear O3/GVN dispatcher compile. Native P and final native LTO remain O3; all C helper pieces stay enabled. Preserve g for required BTF: g0 and line-tables fail libbpf open on a typed map extern, g succeeds. Fresh BCC fentry_vfs_read/inet_sock_set_state generation, libbpf open, cached-frontend reuse and native O3/proof compilation pass; Tetragon request6 continues as a long host job. This is generation/verification-pipeline work, not an app speed result or new stock acceptance. Results b-analysis-flags-20261119.

PERF 2026-11-19T07:10:39Z: Native private-arena normalization in compile_sim_ir.cpp transfers the existing packet_bounds_ir.cpp rule to the reused frontend: only non-atomic volatile accesses whose every underlying object is a local union.x86_sim_stack_mem become ordinary Mem operations. Global/context/mixed/other-local/atomic effects remain. Host scope/execution tests,25 BCC compile/proof replays and ARRAY/OTel regression pass; all C helper pieces stay on. Runtime/body/helpers/maps/installed bytes await the combined batch. Results native-private-stack-20261119.

PERF 2026-11-19T07:26:12Z: Native private-arena normalization landed as5be6df084; scope controls and1344 executions,25 BCC proof/compile APIs and ARRAY/OTel regressions pass. Tetragon B O1 result is incomplete: final emission hits4096B, retained-MIR diagnostic shows max direct R10 offset5776. Production limits unchanged; O3-after-common-contracts experiment af6ef8d95 reuses existing IR and is pending. No new app runtime or stock acceptance is claimed.

PERF 2026-11-19T07:46:41Z: After stock B acceptance, compile_sim_ir.cpp replaces only the exact invalid call-minus-one and null-store fault forms with llvm.assume(false). B, ordinary program checks, recoverable probe errors and direct-native fallback retain their behavior. Host verified-domain/ordinary-check execution tests, recoverable probe tests,25 BCC compile/proof replays and ARRAY/OTel regressions pass; all C helper pieces stay on. Runtime/body/helpers/maps/installed bytes await the combined batch. Results native-verified-paths-20261119.

PERF 2026-11-19T07:55:23Z: Native original integer identity normalization in compile_sim_ir.cpp
now mirrors the existing B freeze contract for exact empty =r,0 integer
asm. This exposes constants/live register values to O3; pointer, clobber and
newly generated address-base barriers remain.1024 execution cases,3072 prior
verified-path cases,25 BCC production compile/proof links and probe/ARRAY/OTel
regressions pass. BCC host proof .text47,597 ->19,263B against ba366fcb3;
installed bytes and per-call/body/helpers/maps/throughput await the combined
checked-sim-c batch. All C helper pieces stay on; no B/runtime check added.
Receipts results/native-integer-identities-20261119.

PERF 2026-11-19T08:05:59Z: The phase1 post-contracts O3 experiment does not remove
the Tetragon B stack failure: packing1322.171s succeeds, final llc16.463s
fails the unchanged4096B compiler bound. Production flags/limits stay.
Native base-root audit finds42/42 unknown generated bases in BCC request17,
even after constant-freeze folding; no speculative private-base fast path
was added. Evidence results/b-analysis-flags-20261119/post-contract-result.json
and results/native-base-roots-20261119. Native C pieces remain enabled;
no new runtime gain or stock acceptance is claimed.

PERF 2026-11-19T08:17:44Z: Combined checked-native cohort through ff02957cc passes actual
BCC checked-corpus: programs/native/B-generated/B-stock25/25/25/25,25 checked
native,0 fallback,0 failures, app ok. Installed native20,043B vsJIT7,965B.
This establishes the post-verification compilation contract and combined
helper functionality; the existing1x10s functional run supplies no official
runtime gain. Evidence results/native-cohort-check-20261119/coverage.json,
raw run x86_kvm_corpus_20261119_081018_746542. Official combined timing follows.

PERF 2026-11-19T08:53:11Z: Image5c974db3050f completes the frozen six-app functional
check, native14/25/113/288/169/1 with0 loader failures. Main checked-sim-c
BCC3x180s stats1 is running on the installed07:53 compiler cohort through
ff02957cc; later source2eb36bad9 is not measured by that binary. Read-only
arithmetic canonicalization exposes1 of42 retained private bases,41 remain
unknown; no production optimization or runtime gain is inferred. Results
native-cohort-timing-20261119 and native-base-roots-20261119. Lock-prefix
fidelity953453b7f is the next phase1 item, ahead of optional alias work.

PERF 2026-11-19T09:23:54Z: Combined checked-native cohort through ff02957cc
is now timed: BCC 3 x 180 s, stats on, run 085534_233511, programs/native/
B-generated/B-stock 25/25/25/25, 0 fallback/failures, app ok. Per call
107.7→106.0 ns (1.016x), throughput 1.018x, sample ratios 1.013/1.020/1.022,
0 workload errors; installed 20,043 B vs JIT 7,965 B. All prior C/native
pieces are on; later 2eb36bad9 is not in the installed compiler. This measures the combined cohort rather
than separate piece effects; body/helpers/maps were not profiled. Runtime
targets remain open. Lost LOCK semantics in shared I is a confirmed phase1
defect affecting B and native, recorded without discarding the measurement.
Evidence results/native-cohort-timing-20261119 and lock-prefix-review-20261119.

PERF 2026-11-19T10:48:19Z: Combined freeze/LOCK cohort 3f80b472e now has
actual BCC confirmation: run 101802_025374, 3 x 180 s, stats on, app ok,
programs/native/B-generated/B-stock 25/25/25/25 with no fallback/failures.
Per call 103.8→103.1 ns (1.007x), throughput 1.006x; sample ratios
1.015/0.995/1.006, zero workload errors. Installed 8,628 B versus JIT
7,965 B. The old cohort was 107.7→106.0 ns and 20,043 native bytes; both
arms changed between runs, and this combined result isolates neither
freeze nor LOCK. Runtime goals remain open; no new body/helper/map shares
are inferred. Evidence: results/lock-prefix-review-20261119/combined.

PERF 2026-11-19T10:52:22Z: Phase-1 released-alias repair is applied in shared x86 I:
fixed loads now receive the same post-load released-stack observation as
RSP/indexed reads, while keeping fixed offsets and base barriers. All 48
address cases, eight ordinary/four fault cases, LOCK regressions, 22 B/native
compilations and 1,024 barrier executions pass. This is correctness work;
no runtime gain is claimed. BCC functional coverage and installed bytes are
pending, all C/LTO pieces on. The completed 1.007x measurement precedes this
change. See results/released-alias-20261119.

PERF 2026-11-19T11:08:16Z: Released-alias correctness fix b77ae773c now passes the
canonical BCC functional check: run105515_135901, 25 programs/native/B-
generated/B-stock, all checked with zero fallback/failures, host0/appok.
Installed bytes remain8,628 native versus7,965 JIT. This confirms source
integration with all C/LTO pieces on; the functional1x10s run is not a new
speed measurement. Latest official combined result remains1.007x per call
and1.006x throughput before this fix. Runtime targets remain open. See
results/released-alias-20261119/coverage.json and functional-installed.txt.

PERF 2026-11-19T11:31:24Z: Phase-1 B constant ALU32 folding: exact constant
i32 self moves now fold in the existing IR pass, exposing size/helper-ID
dispatch facts. Four constants and live/clobber/wide preservation controls
pass through the rebuilt sole tools and real BPF emission. Shared I and
native conversion remain unchanged; no runtime improvement is claimed.
The retained Tetragon frontend replay, stock acceptance and fresh app
confirmation remain open. See results/constant-alu32-20261119.

PERF 2026-11-19T11:43:27Z: Constant-ALU32 B pass 0cb83f15d passes the
canonical BCC stock/native functional check (113739_128860): 25/25/25/25,
all checked, zero fallback/failures; installed 8,628 native/7,965 JIT bytes.
No speed ratio comes from this 1 x 10 s check. Tetragon backend passes;
packing/emission/stock remain open. A retained installed-binding audit
also finds the checked path still uses generic TP output/stack helpers
and generic map writes; these are separate phase-1/1e work, with no
performance gain claimed yet. See results/checked-helper-binding-20261119.
