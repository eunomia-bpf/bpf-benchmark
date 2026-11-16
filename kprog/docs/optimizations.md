# kprog optimizations

Operator, 2026-11-14: "然后你要想办法优化一下, LTO + native 我觉得到 40% 性能进步是完全肯定可以的. 先确保管线正确, 然后开始考虑优化. 每一个优化也得记录在哪里怎么做的."

Every optimization of the native path is recorded here: where it lives, how it works, which pipeline step it belongs to (design.md 编译流水线: step 1 compiler flags when P is produced, step 3 link-time optimization), how its correctness is checked, and its effect in the combined configuration (all pieces on together; the operator: "不需要这样细粒度区分. 只需要都做就好."). The lane that lands an optimization adds or updates its row in the same commit. Effects are per-call native/eBPF on the combined configuration, with the run directory.

| Optimization | Step | Where (code, switch) | How | Commit | Correctness check | Status |
|---|---|---|---|---|---|---|
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
| Typed hash lookup dispatch | LTO | native_link hash lookup emitter (kprog/build hash-lookup-kernel) | lookups into Hash, LRU, PerCPUHash and HashOfMaps go straight to the map type's lookup routine instead of the generic helper | 48af2849d | 25 host tests, 22 default-off byte comparisons | on |
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
