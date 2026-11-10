# Verified-track audit recovery

Operator order: the 2026-11-09 21:50 change-necessity audit, sections 5 and 6.
Each step is a forward commit, with its own push. Runtime checks added total 0.

## Step 1: stock six-register entry by default

The existing CK/linux kinsn-free tree at commit 390ef9011c7d saves
RBX/R13/R14/R15/R12/RBP around P and restores them before the stock return.
The current native-link default selects its existing stock-entry-frame feature.
B retains RSP returning to entry and the interpreter's existing return-target
dispatch. The six saved-entry values and callee equality arm are removed.
The incremental kernel recipe now builds the committed CK source directly.
The verifier source remains the stock source used by the existing kinsn-free line.

The prior fixed f05af452e positive tail replay completes at guest/make exit0.
Its original native/BPF fixtures and physical R12/RBP/RSP observation are retained
in step1-tail-raw.tar.gz. The 96b fixed census continues with its captured runtime.
One final same-model app and safety replay follows the requested restoration steps.

## Step 2: original x86 stack metadata

Forward commits undo the x86 hunks of 5d8c38d3a, b1d4012f1, 670b6e430, 8001a5459, b3c912c1e, a3a4470c3, ebe984e0f and 53dc94561. The declaration block matches aee6b236d exactly: architectural bytes plus one pointer and one byte tag per selected word. Scalar forwarding values, validity bits and their generator selection are removed. The later SP-lifetime reading semantics and stock load-fault recovery remain. The four read-only helper selections return to their earlier helper wrappers. ARM representation changes remain lane A ownership.

## Step 3a: ordinary helper and copy arguments

The x86 f7c517c0a output-below-SP fault arm and its helper/copy/fill wrapper selections are removed. memcpy uses its original source argument for scalar and pointer-shaped values. The ordinary read semantics, native count, helper calls and exception-table load recovery remain. Published safety inputs, including the cases added by 25a373adf, retain their original source and annotations for the final replay.

## Step 3b: original context selection and native copy extent

Context selection again maps XDP, TC and cgroup-SKB to their typed layouts and every other program type to raw. The 17-family generation-failure branch and its dedicated rejection test are removed. The old x86 transport copy uses the submitted extent through vmemdup_user; the added 1GiB E2BIG arm is removed. The active stock transport already uses the submitted extent directly.

CK commit c1b9c1370976 removes the armed-image subprogram pre-verifier error and its prepare function/prototype. B now reaches the ordinary verifier and JIT subprogram machinery. The stock verifier source remains byte-identical to c23719abc330.

## Step 3c: native branch instructions

Forward hunks remove the x86 changes of 731a91ee6, 165ac4100 and 334996eb8: external retpoline/return-thunk/ENDBR compiler flags, relocation kind12, the native thunk resolver and its loader/module cases, and the mitigation-specific test/patch. Native helper dispatch again uses the SIB-indirect call; successful tail transfer uses jmp RCX. The existing bounded target dataflow and stock six-register tail cleanup remain. The positive tail fixture uses the same call/jump/return semantics through direct instructions. Kernel commit e1e9040825d4 carries the matching resolver/kind deletion; stock emit_return remains the stock epilogue policy.

The original positive tail regression exposed the ABI scanner treating an existing ENDBR64 instruction as a prologue boundary. Its existing architectural-NOP decoding stays in the generator and ABI scanner; compiler hardening flags and external-thunk relocations are removed. Initial targeted test result18/19 and the follow-up outputs are retained in the build logs.

## Step 4: original BPF frontend and affected source units

The Tetragon JIT build uses its original upstream C/frontend/helper assembly. Five canonical header inputs carry the recorded path-loop/length/data-event/namespace changes through a Clang file overlay; all source edits remain in the main checkout. The broad native compatibility tree is retired from the JIT frontend. Existing debug-function identities select62 affected ELF units;32 remaining upstream objects retain their bytes. Shared ELF program sections keep the upstream sibling function sources. Original generic_calls helper masks and their BPF assembly stay upstream. Tracee uses its existing paired main buffer/clamp unit; support objects and userspace binary come from the upstream image. The Makefile paired-source target records exact source membership, commands, original/selected hashes and build output under C/audit-recovery. The same-model whole-application startup measures the resulting baseline and native coverage.

## Fixed replay inputs

The final safety/census prepare target stores regular copies of the kernel, module, loader and native-link beside the selected committed model. All subsequent guests use those same files, while current build caches keep their own paths. Selftest native objects rebuild from the original published C with the restored compiler flags. The original selftest and ISA case annotations remain in the replay input tables. This is experiment input selection and archiving; runtime admission predicates added0.

## Canonical kernel source pin

The parent kernel gitlink selects the combined kinsn-free source 7d6b7d663680309da44f7a1a7904c93db90baffe. It includes the approved x86 six-register frame and A approved ARM full frame, original stock verifier, ordinary subprogram path and existing relocation kinds. The existing CK worktree supplies incremental builds; the existing vendor working files remain available to their readers. Fresh checkouts select this single kernel line. Historical May29 direct-native measurements retain their recorded image/kernel artifacts.

## Replay setup observation at354fdbee9

The first fixed-input replay records ISA48:10 positive infrastructure errors,37 pipeline errors and1 specialization rejection; native risk executions0. The shared diagnostic is an unbound kprog_unspecified_input proof extern. All315 selftest entries were attempted:137 generation failures,149 load failures and29 resource failures. Census27 uses the archived external-thunk P objects and records24 generation failures plus3 transport failures. These rows identify setup and old-input effects; the corrected replay supplies coverage and safety outcomes.

Canonical libnativeloader now adopts the existing stock transport: B loads as an ordinary verifier program, P occupies one submitted extent, and unspecified entry values use the existing ordinary mutable input map. The latest first-load verifier log behavior and original native branch instructions remain. Incremental library/trusted-loader builds return0. The initial six-app installer reached its legacy bpf_x86_alu insertion. The replay bootstrap selects its existing skip-kinsn option after loading the stock module. Frozen workload/framework sources retain9f3855f6f. Complete initial receipts are step5-setup-raw.tar.gz; step5-setup.json holds counts.

## Complete native replay payloads

step5-native-inputs.json describes the ordered archive parts, full SHA256 and per-object payload hashes. The39,298,431-byte gzip archive contains complete native directories/manifests, captured Cilium configuration/source inputs, plugin/compatibility inputs and all compiler/manifest commands and logs. Native object / manifest record counts are Tetragon62/225, Tracee3/114, OTel16/26 and Cilium4/68. OTel includes its program and data objects.

Tetragon producer records drop from237 to225. step5-tetragon-input-delta.json lists all12 previous-only records: four helper function exports and eight source-match aliases. This producer row difference stays explicit; the whole-app run measures actual loaded programs and installation drops against the best4 row. The27-body historical census still carries its original external-thunk objects; the setup archive preserves its outcomes and input scope.

Corrected replay model5afa9bf29c5eebd3db96593c8e49e135540e6c17 uses the canonical stock loader, source snapshot and regular runtime file copies. The controller queues ISA48 then upstream315; a separate branch builds the matching image and runs all six complete startups with1 sample and2-second work intervals. Functional startup results stay separate from R timing results.

## Fixed stock-path ISA48 result

Model5afa9bf29 completed48/48 published ISA cases:10 valid executed,29 verifier rejected,1 specialization rejected and8 accepted load-only findings. Risk native executions0; suite guest exit1 is retained. Native case hashes match both the original ABI9cbac28ec and earlier six-save96b561e22 cohorts. step5-isa48.json lists every row change, exact runtime hashes and the full raw archive hash.

Compared with the earlier six-save result, verifier rejections drop32→29 and accepted load-only findings rise5→8. The three changed rows are the published helper/memset/memcpy output cases after the requested output-fault-arm reverts. The other accepted labels are the earlier uninitialized-stack, immediate-push-branch and stack-base-flags observations plus the two register-exit labels under physical callee preservation. All eight retain their original case annotations and load-only behavior. The coordinator has the new three-case disposition request under Notices; any additional production predicate follows the operator approval rule. The315 selftests and six-app startup continue on the same5afa source/runtime model.

The application mount namespace maps the frozen corpus/results output path onto C/audit-recovery/application/corpus-results for subsequent invocations. Generated work/results stay in the lane scratch directory while framework paths retain their original spelling. The active5afa guest keeps its original namespace; its boot-ID-specific metadata is collected into the lane archive at completion.

## Container workdir and canonical module name

The second application setup reached the container driver and captured its original legacy module installation error. step5-app-setup-raw.tar.gz holds its complete output and boot-specific corpus metadata. Inspection found two source trees in the inherited image: /paper-tree has the exact9f3855f6f driver SHA dcfcf4f4eb5eed197c8dcb294428749d937bf871de407eeef2838b038d8285c9; the frozen launcher selects /workspaces/repository. The image recipe now copies the existing May29 tree to that actual workdir and overlays only the allowed Cilium native-P compiler helper.

The canonical stock module build name is bpf_kprog_stock, using the same kprog_stock.c body. Its real module name and artifact basename agree with the frozen bpf_*.ko enumeration. The image module directory carries that stock module; the guest registers its existing service before the original driver starts. The default stock guest/replay module paths follow the canonical output. Current guests retain their captured files; the next matched replay uses the named module consistently across suites and applications. Framework/workload source changes0; production admission predicates added0.

The canonical module-name incremental build returns0. The before/after .text sections both hash to260f071c2f37b3b7369ba77dda47df9506cda89db45a654698836410435126c9. modinfo reports bpf_kprog_stock. Build output and the text-identity receipt are included under module-name/ in step5-app-setup-raw.tar.gz. Modelaf422c391 uses the named module and actual frozen workdir for the matched replay; its safety queue follows the existing315 writer through a pidfd wait.

## Frozen six-app baseline and snapshot RPC restoration

All six original application baselines reached their workload measurement on modelaf422c391. Each then reported unknown cmd:snapshot_maps before its native phase. step5-app-rpc-setup.json records baseline program counts and all installation drops versus25/1/14/2/5/4: each native count is0 at this measurement-interface stage. Complete app/workload/kernel logs and metadata are in step5-app-rpc-setup-raw.tar.gz; outer return0 and corpus statuserror retain their separate meanings.

Shim commit9220b9b44 restores the exact177-line May29 snapshot RPC block and dispatch removed by6c0a727c5. This produces the original measurement map artifacts alongside the current native replacement/fallback code. Incremental shim build succeeds; a real socket request returns ok/programs0/map_refs0 for the empty local control. The image builds that shim in C scratch and selects the existing SKIP_REJIT=norejit mode used byb0b0824c2. The original driver then retains its native post startup while omitting bytecode rewriting. Framework/workload source edits0; admission predicates added0. The verifier model/runtime files remainaf422c391; runtime_adapter_head identifies this measurement-interface successor.

## Completed upstream315 at5afa

All315 original upstream entries were attempted:58 installed,91 verifier rejected,137 generation failures and29 resource failures. Native execution requests0. The two failure-annotated accepted rows remain dynptr_fail.c/test_dynptr_reg_type and verifier_lsm.c/no_null_check; all original annotations stay published. The accepted count includes56 success-annotated rows;7 success-annotated rows reached verifier rejection.

Compared with original ABI9cb:43 installation gains,0 installation drops and70 stage changes. Compared with earlier six-save96b:41 installation gains,0 installation drops and68 stage changes. Generation failures change202→137 and resource failures30→29. These compare the combined audit/source-input cohorts; individual edit attribution remains separate. step5-selftests315-5afa.json lists every changed row, accepted failure annotations, full counts and ordered raw archive parts. The57,926,892-byte archive includes all286 actual success/failure request archives, compiler/verifier logs and the complete submission table. The canonical-name af315 queue retains its own runtime/input files and outcome records.

## Matched canonical module replay ataf422c391

Both published suites completed on the same af422c391 kernel/module/linker/loader/model copies. ISA48 records10 valid executions,29 verifier rejections,1 specialization rejection and8 accepted load-only findings, with risk native executions0 and guest exit1. Upstream315 records58 installed,91 verifier rejections,137 generation failures and29 resource failures, with execution requests0. Its315 per-program stages match5afa exactly; the canonical module name retains identical .text. Both failure-annotated accepted rows remain listed. The fixed-name replay changes0 selftest stages relative5afa; its full own raw records remain separate.

step5-matched-af-safety.json and its ordered raw parts hold the actual matched outcomes, runtime/input hashes and every request archive. The six-app snapshot-RPC successor keeps these verifier/runtime artifacts and records its measurement adapter revision separately. Safety acceptance and application native installation remain open items, with every observed finding retained under its original annotation.

## Complete BCC payload input

The first native-phase successor reached real service requests and native installation. BCC stopped at its original manifest lookup because the inherited image carries the other five payload directories. The recipe now exports the already committed control/bcc payload from bcc-frozen-config-set/raw.tar.gz:8 native objects and29 manifest records for the frozen eight-tool CLI, retaining live my_pid. Its objects carry0 external x86 thunks. image.json records the original archive and every extracted payload file hash.

Image realpath inspection confirms the original /opt/bpf-benchmark/native-bpf/x86_64 lookup already aliases /artifacts/user/native-bpf/x86_64 through its parent. The four fresh payloads were active throughout the prior run; the source-path attribution in the preliminary Notice is corrected there. The original mapping remains and only BCC input coverage changes. Current app/service rows retain their actual native SHA and adapter/model identities. The existing writer continues to expose the remaining application failures before the BCC successor starts.

## OTel startup/measurement overlap case

The OTel post shim log starts synchronous native loading at guest186.913249 and receives measure_start at191.367608,4.454359seconds later, while source capture/insertion remains in flight. The frozen driver then reports an empty tracked set. The first request is read_task_struct/type17 with system_analysis and with_debug_output maps. The successful second request is Cilium cil_xdp_entry/type6. The earlier preliminary OTel installation attribution is corrected in Notices; actual request identities are retained.

The existing shim_native_loads_inflight scope spans capture and insertion. Measurement-RPC serialization with this existing scope is proposed to the coordinator under the operator approval rule for new gates; code added0. The original framework/source and native acceptance path remain fixed. otel-startup-overlap.json and raw archive preserve this observation and the two actual request archives. The ongoing six-app run continues to expose every other failure.

The external application recipe forwards the original guest apps parameter and accepts an independent scratch output directory. Defaults remain the full six-app list and original lane scratch path. This lets the complete BCC eight-tool retry use its own image/import, compiler/service records and guest while the existing six-app writer continues. Both use the same af422c391 verifier/runtime files. Application workloads and framework bytes retain their frozen definitions.

## Complete BCC startup retry on the matched model

The independent full eight-tool BCC startup uses adapter b7440a7be, the complete control8/29 payload and the same af422c391 verifier/runtime. Baseline records25 programs and completes the original2-second stress-ng workload. The native startup completes4 verified native installations: fentry_vfs_read, sys_enter, tracepoint__syscalls__sys_enter_open and tcp_v4_connect. Its fifth generated/compiled request, sched_wakeup, reaches the native-chunk ioctl and returns ENOENT after corpus metadata records the measurement error. This is a kernel native-chunk load error; verifier rejections observed0.

| Application | Baseline programs | B generated/compiled | Verified native installed | Specialization failures | Verifier rejections | Kernel chunk load errors | Startup remaining | Best installed | Installation drop |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| BCC eight-tool set |25|5|4|0|0|1|20|25|21|

The original driver reaches measure_start on the first tool socket at guest206.583986 while its capability program remains in synchronous native loading. Other tool sockets already contain the four installed programs. The resulting native-phase error is the original empty tracked-program error; post-phase work counters remain pending a completed startup. The baseline workload returns0 and its25 program counters and original stdout remain archived. Outer guest/make0 accompanies corpus metadata status=error. The21-program installation drop combines one native-chunk error with20 programs whose startup stops before a completed service result; their verifier outcomes remain open. These counters describe this run's startup frontier.

bcc-startup-retry.json publishes each actual request entry, source/native identity, stage and compile timing, plus the baseline program rows and exact reproduction command. bcc-startup-retry-raw.tar.gz includes all five request archives, source/runtime identities, the complete original corpus output, compiler records and image metadata. The measurement serialization case posted for OTel now includes this BCC evidence; coordinator disposition remains pending and waiting-code additions remain0. The ongoing six-app writer continues with its original service/compiler state.

## Cilium completed-request frontier

The ongoing six-app startup has21 completed Cilium native requests in service rows2-22:21 B programs generated and compiled,17 installed and4 verifier rejected. The old best installed count is14; this frontier records an aggregate gain of3. Actual complete program membership, per-prior-program gains/drops and post-phase work counters follow the whole-app terminal. The writer continues with its original fixed af422c391 model/runtime.

| Entry | Service row | Stage/error class | Raw verifier signal |
| --- | ---: | --- | --- |
| cil_from_container |6|BTF write permission|only read is supported; store u16 to trusted sk_buff+124|
| tail_handle_ipv4_cont |12|packet bounds|invalid access to packet, off=0 size=4|
| tail_ipv4_to_endpoint |18|pointer bitwise operation|R0 bitwise operator &= on pointer prohibited|
| cil_from_netdev |19|pointer bitwise operation|R2 bitwise operator &= on pointer prohibited|

cilium-startup-frontier22.json records every completed request, full entry, source ID, load context, compile timing and native/simulator object identity. The raw archive retains all22 complete success/failure archives, including the OTel first request and its exact load-stage error. The17 Cilium installations include two separate tail_drop_notify source-program instances; each retains its own source ID. Submitted native object hashes identify the full uploaded ELF, with the selected entry recorded alongside each hash.

OTel read_task_struct reaches a native-chunk ioctl ENOENT, before B verifier submission. The generic phrase used in the earlier preliminary Notice is corrected to kernel native-chunk load failure. In the fixed module source this ioctl first resolves the active request capsule; native_lab_active_capsule returns ENOENT for an inactive/abandoned request. This source behavior and the measured startup/teardown ordering support the existing lifecycle-overlap case. Its exact raw record remains distinct from the four actual Cilium verifier rejections. The proposed measurement waiting behavior still awaits coordinator disposition; production code additions0.

## Historical best installed rows and individual comparison

best-installed-reference.json reconstructs all51 accepted historical requests directly from their committed raw archives. Actual counts equal the requested reference: BCC25, Katran1, Cilium14, OTel2, Tracee5 and Tetragon4. Each row retains the full entry, original source/native program IDs, load context, map metadata, native/B/proof object hashes, source identities and nested archive locator/hash. This is an observation ledger for the existing outcomes. The original accepted native bytes and compiler/source epochs remain qualified by their own records.

| Application | Historical best installed | Current snapshot installed | Historical entry roles observed installed | Current comparison state |
| --- | ---: | ---: | ---: | --- |
| BCC |25|4|4|21 installation drops:1 native-chunk load error and20 interrupted startup rows|
| Katran |1|pending|pending|application phase queued|
| Cilium |14|17|11|3 old entry roles remain loading at service row22|
| OTel |2|0|0|2 installation drops:read_task_struct chunk ENOENT and perf_unwind_stop startup interrupted|
| Tracee |5|pending|pending|application phase queued|
| Tetragon |4|pending|pending|application phase queued|

The BCC comparison uses its completed independent full eight-tool retry; OTel and Cilium use the fixed first22-request snapshot of the ongoing six-app run. All share the af422c391 verifier/runtime, with adapter/image identities recorded separately. Each historical row lists current candidates and its actual state. The three Cilium pending roles are cil_to_container, cil_to_netdev and tail_ipv4_ct_ingress. Its aggregate17 installations include new entry roles and a second tail_drop_notify instance; the old14 roles receive their own individual comparison. Multiple current source instances remain separate records. Entry-role presence and the full native/source/context identity observations express distinct comparison scopes. Final instance-level drops follow the complete whole-app outcome.

Historical input locators are undefined-flags/bcc-katran (26), cilium-prepared-end/whole-current (14), ghost-adoption/tracee (5), and whole-five-step-0700/applications.tar.gz with tetragon-current-assets (4) and otel-final-modules (2). Every selected historical request carries status0 and its complete native/B/proof objects. The exact archive SHA and nested member chain make each of the51 original records directly recoverable. Current snapshot input SHA values identify the already published result files; runtime code additions0.

## Native-load and measurement lifetime synchronization

Coordinator01:30 prioritizes the BCC/OTel native-chunk ENOENT. The shim now uses one rwlock for the existing bound-load scope and existing list/measurement RPC snapshots. The bound load holds read ownership through capture, synchronous proof submission and program-table insertion; its existing cleanup releases ownership on each return. list_progs, measure_start and measure_finish take write ownership before their state snapshot. Each path acquires this lifetime lock before state_mutex. This orders RPC observations and application teardown after the in-flight load. Existing verifier admission/fallback behavior and the frozen framework/workload remain current.

The code delta is13 added/1 removed lines across three shim files, with added checks/admission predicates0. Incremental shared-library build completes0. Existing host selftest records7 passes/1 failure: t8_report_scoped_reload_unchanged reaches the host dependency error failed to spawn kinsnprober rc=2. Its complete output and build warnings remain in load-lifecycle-build-raw.tar.gz. load-lifecycle-fix.json records source/binary identities and exact scope. A separate full BCC/OTel startup replay follows on the same af422c391 verifier/kernel/module/linker/loader/P copies with this measurement adapter; actual replay outcomes determine the ENOENT resolution. The ongoing six-app writer retains its existing loaded image and compiler.
