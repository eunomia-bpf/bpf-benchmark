# kprog optimizations

Operator, 2026-11-14: "然后你要想办法优化一下, LTO + native 我觉得到 40% 性能进步是完全肯定可以的. 先确保管线正确, 然后开始考虑优化. 每一个优化也得记录在哪里怎么做的."

Every optimization of the native path is recorded here: where it lives, how it works, which pipeline step it belongs to (design.md 编译流水线: step 1 compiler flags when P is produced, step 3 link-time optimization), how its correctness is checked, and its effect in the combined configuration (all pieces on together; the operator: "不需要这样细粒度区分. 只需要都做就好."). The lane that lands an optimization adds or updates its row in the same commit. Effects are per-call native/eBPF on the combined configuration, with the run directory.

| Optimization | Step | Where (code, switch) | How | Commit | Correctness check | Status |
|---|---|---|---|---|---|---|
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
