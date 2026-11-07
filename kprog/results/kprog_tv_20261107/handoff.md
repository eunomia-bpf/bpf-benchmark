# Lane T completion and handoff

Recorded 2026-11-07T23:56:25.747138+00:00; coverage snapshot `afd128c3bb337fab63be3510e818d04d50bb36e0`. V receives all remaining O4
formal work, the21 O4 rows and the O4 summary in
`kprog/results/kprog_verification_20261107/coverage.tsv` and its README.
C receives x86-64 kernel-module and binding-interface implementation work;
A receives AArch64 implementation work. Common binding headers follow C/A
coordination. This records the operator's three-lane transition.

The completed current item is `139d1cff8236f6b797e7c6a8e72419ef814fb4d9`:
`NativeLinkArmExclusive.lean`,16 universal audits plus16 existing generic BPF
auxiliary audits,131072 actual kernel-matcher cases and8 continuation/boundary
controls pass. Its25 Git source pins and both compressed/raw log identities
were rechecked for this handoff. Current T detached checks are collected;
14 closed controls were retired after publication. T source/result paths for
this item are clean. Workspace STOP and shared incremental caches remain.

## Immediate retry frontier: V formal work, A implementation

A's `caba065cbc51e4165a27a614b7c31c3672a794de` records six native retry sites:
BCC three requests/four sites and Tetragon one request/two sites. The forms are
LDXR/LDAXR, ADD, STXR/STLXR and CBNZ; Tetragon source PCs are0x248/0x288.
A's current `Arm64Exclusive.lean` retry-edge work and V's
`failed_store`/`store_core_refines` provide per-attempt state, status, monitor,
effects and fault interfaces. T's generic kind9 component supplies exact
opcode/descriptor binding, instruction boundaries, fresh Boolean visits and
finite-prefix block preservation. V takes native CFG identity, safety
invariant, dynamic environment alignment and progress/termination contracts;
A takes the scoped kernel/generator mechanism and its actual ARM regressions.

The prior convergence candidate is patch SHA256
`2480264e275e8dafab9f745b36f788075f2d32d373771b3780c1bf0005dcb2f3`,
archived in
`kprog/results/kprog_fidelity_20261107/negative/arm64-exclusive-convergence-review/inputs.tar.gz`,
member `candidate/exclusive-convergence-candidate.patch`.
Its eligibility uses the enclosing bound region and a changed visit counter.
The F README/audit preserves the exact abstract-state/SCC review. Completion
requires retry-region/native CFG identity, a progress/termination contract and
candidate-specific delayed-branch/callchain evidence. Current canonical inputs
include repeated failure choices. Canonical34-case regressions and historical
pre-region loader refusals retain their separate source epochs. The current
kernel and captured application bytes remain the runtime baseline.

## Universal modules and evidence transferred to V

All module names below are under `kprog/tv/`; all JSON receipts below are under
`kprog/results/kprog_tv_20261107/`. Each receipt retains its checked source epoch,
source hashes, axiom audit and archive identities. Live warm caches follow
successor work; each receipt identifies the artifact it checked.

| Remaining formal item | Lean modules | Published evidence | Receiving lane |
| --- | --- | --- | --- |
| Actual native PC/control coverage, field alignment, common-input/definedness closure, O1/O2 and actual-B/link composition | `Composition.lean`, `SimulatorComposition.lean`, `BPF.lean`, `BPFPath.lean`, `BPFPlatform.lean` | `generic-program-composition.json`, `generic-simulator-composition.json` | V |
| Actual Rust/iced construction, complete instruction/field/PC mapping, mixed record separation, GOT/RIP/SIB/table consumers, serializer and chunk identities | `NativeLinkRelocation.lean`, `NativeLinkRelocationTable.lean`, `NativeLinkLiteral.lean`, `NativeLinkPatchTable.lean`, `NativeLinkMovabs.lean`, `NativeLinkGuardedEmission.lean`, `NativeLinkChunkLayout.lean`, `NativeLinkByteLayout.lean`, `NativeLinkChunkPlanner.lean` | `generic-native-link-rel32.json`, `generic-native-link-relocation-table.json`, `generic-native-link-relocation-layout.json`, `generic-native-link-literal.json`, `generic-native-link-patch-table.json`, `generic-native-link-movabs.json`, `generic-native-link-guarded-emission.json`, `generic-native-link-chunk-layout.json`, `generic-native-link-byte-layout.json`, `generic-native-link-chunk-planner.json` | V |
| Actual JIT size/cursor/copy/finalization values, final-fixup separation and execution lifetime | `NativeLinkFinalImage.lean`, `NativeLinkArmPlacement.lean` | `generic-native-link-final-image.json`, `generic-native-link-arm-placement.json` | V |
| ARM kinds2/3 complete native fields/tables/final text and caller/callee state/effects | `NativeLinkArmBL26.lean`, `NativeLinkArmHelper.lean`, `NativeLinkArmHelperGuard.lean`, `NativeLinkArmPlacement.lean` | `generic-native-link-arm-bl26.json`, `generic-native-link-arm-helper.json`, `generic-native-link-arm-helper-guard.json`, `generic-native-link-arm-placement.json` | V |
| ARM kind4 per-CPU environment/address transport and MRS replacement | V's canonical `Reference/AArch64.lean` MRS/TPIDR_EL1/EL2 work; existing generic store/copy modules supply placement | `PERCPU_MRS_KIND4` row and ARM module source; V's successor canonical publication supplies the new ISA input | V |
| ARM kind9 actual C byte/field/scanner/group correspondence, source PCs and dynamic exclusive environment; retry CFG/invariant/progress | `NativeLinkArmExclusive.lean`, `Composition.lean`, `BPF.lean`; `kprog/formal/KProgFormal/Refinement/Arm64Exclusive.lean` | `generic-native-link-arm-exclusive.json`, A `caba065cb`, F convergence-review archive | V |
| Private ownership, spill insertion/reload/control and actual compiler frame preservation | `PrivateSpillProjection.lean`; `PrivateSpills.lean` retains the earlier fixed two-slot memory lemmas | `generic-private-spill-projection.json`; current projection/compiled-B rows carry production obligations | V |
| Readonly kind8 extents/layout/permissions/lifetime and native/proof addresses | `NativeLinkLiteral.lean`, `NativeLinkByteLayout.lean`, `NativeLinkFinalImage.lean` supply existing memory/layout components | `READONLY_DATA_KIND8`, shared binding sources | V |
| Helper identity/prototype, intrinsic count/return/memory effects, tail-call targets/control/lifetime and physical invocation/return ABI | `Composition.lean`, `SimulatorComposition.lean`, ARM helper modules and existing relocation/literal modules | `trusted-inline-memory-binding.json`, `trusted-native-resources.json`, helper/tail-call/entry/full-binding rows | V |

The active universal modules and generic receipts supply the current evidence.
Historical individual-program proof, certificate and validation material remains
frozen. The trusted inputs carried into composition are accepted-B verifier
soundness, the single canonical ISA with F hardware/QEMU fidelity evidence,
kernel binding/C implementation correspondence and the per-receipt Lean/axiom
inputs. Actual compiler/output, ABI and production correspondence conditions
remain explicit in the rows below.

## Kernel and binding implementation transferred to C/A

| Receiving lane | Work and implementation paths | Published base and continuation |
| --- | --- | --- |
| C | x86 module `kinsn/module/x86/bpf_x86_native_lab.c`; native-only service/capsule/resource/context/entry binding and x86 JIT final-byte interfaces; associated tests under `kprog/tv/` | `c94fbff015cfcf2a6b253a26122e9991036c558b` resource capability and `697bea0ea4326472119c137b306d298621a9a218` memcpy binding; `trusted-native-resources.json` and `trusted-inline-memory-binding.json`. Tested x86 resource module SHA256 `57e6f868da0768526965fdd0a789c4d7080358efe4439edb1f0e32c5136ceb9f`; exact binary/sources/logs in `trusted-native-resources.raw.tar.gz`. C's paired entry-resource caller/linker and application queues remain with C. |
| A | ARM module `kinsn/module/arm64/bpf_arm64_native_lab.c`; common binding interfaces, checked far-helper adoption, per-CPU MRS/exclusive metadata, scoped retry mechanism and whole-app ARM execution | `9357a045c9f6132df85c9d655f5e9db2d4450785` checks far target upper16 bits before stores and propagates ERANGE; canonical near/far bytes retain their established profiles. A's `22896239a`/`5442185b5` publish the coherent incremental build and frozen source/module identities. A/current.json and existing queues identify the actual control/Katran/application collection. |
| C and A | Common `kinsn/module/include/native_lab_binding.h`, `native_lab_checked.h`, `native_lab_checked_wire.h`, `native_lab_context.h`, `native_lab_exclusive.h`, `native_lab_group.h`, `native_lab_input.h`, `native_lab_map_offset.h`, `native_lab_trusted.h`, `native_lab_trusted_wire.h`; application proof classification, kernel-owned P, entry/ABI/metadata/resource identity and lifetime | `SUBMIT_RESOURCES`0x77 uses80B envelope plus copied unique signed32 FD vector, actual bpf_map_get references, capsule MAP identity/shape queries and the existing MAX_USED_MAPS64 bound. Original64B SUBMIT and strict registered-service/application-proof controls retain their tests. Transport has30 expected refusals,3 positive case outcomes and1 suite summary. The shared group header's observed two extra blank lines remain a separately pinned physical difference. |

C/A take production changes and actual architecture-specific regression loads;
V takes the corresponding formal laws and O4 coverage publication. Shared
incremental caches, captured runtime sources, archived raw results and both
Workspace/local lane coordination files retain their ownership.

## All21 O4 rows transferred to V

The snapshot has7 `proved-conditional`,6 `partial-universal-component`,
7 `pending-universal-law` and1 `trusted-kernel-implementation` row. The exact
completion field and publication receipt of every row follow.

| O4 row | Status | Lean/source anchor | Evidence | Completion and receiver |
| --- | --- | --- | --- | --- |
| `REL32_KIND1_SLOT` | `proved-conditional` | `kprog/tv/NativeLinkRelocation.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-rel32.json` | V: Connect actual serialized records and emitted code through generic layout/binding. |
| `REL32_KIND1_TABLE` | `proved-conditional` | `kprog/tv/NativeLinkFinalImage.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-final-image.json` | V: Establish actual Rust/iced field/image and kernel copy/size/cursor correspondence, final-fixup separation and executable lifetime; compose complete PC/ABI/compiler, other consumers and ARM forms. |
| `REL32_KIND1_RECORD_LAYOUT` | `proved-conditional` | `kprog/tv/NativeLinkChunkLayout.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-chunk-layout.json` | V: Derive actual Rust within-chunk interval/instruction correspondence and actual executable chunk-base/code-byte identity; retain target/range and full binding. |
| `HELPER_CALL_KIND2` | `partial-universal-component` | `kprog/tv/NativeLinkArmPlacement.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-arm-placement.json` | V: Adopt checked emitter in coherent ARM module/image; extract actual native-link fields/tables/PCs and C word-copy/cursor/finalization identities, later-fixup separation/executable lifetime and complete helper/caller/entry ABI. |
| `HELPER_CALL_BL26_KIND3` | `proved-conditional` | `kprog/tv/NativeLinkArmBL26.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-arm-bl26.json` | V: Connect actual native-link field/table layout, existing offset/placeholder/kernel-target guards, final executable bytes/PC and supported helper/entry ABI through implementation correspondence. |
| `PERCPU_MRS_KIND4` | `pending-universal-law` | `kinsn/module/arm64/bpf_arm64_native_lab.c` | `kinsn/module/arm64/bpf_arm64_native_lab.c` | V: Prove per-CPU environment/address transport and replacement state/effects under supported ABI. |
| `MAP_POINTER_KIND5` | `partial-universal-component` | `kprog/tv/NativeLinkFinalImage.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-final-image.json` | V: Establish actual Rust/iced field/image and kernel copy/size/cursor correspondence, final-fixup separation and executable lifetime; compose complete PC/ABI/compiler, other consumers and ARM forms. |
| `MAP_VALUE_KIND6` | `partial-universal-component` | `kprog/tv/NativeLinkFinalImage.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-final-image.json` | V: Establish actual Rust/iced field/image and kernel copy/size/cursor correspondence, final-fixup separation and executable lifetime; compose complete PC/ABI/compiler, other consumers and ARM forms. |
| `HELPER_POINTER_KIND7` | `partial-universal-component` | `kprog/tv/NativeLinkFinalImage.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-final-image.json` | V: Establish actual Rust/iced field/image and kernel copy/size/cursor correspondence, final-fixup separation and executable lifetime; compose complete PC/ABI/compiler, other consumers and ARM forms. |
| `READONLY_DATA_KIND8` | `pending-universal-law` | `kinsn/module/include/native_lab_group.h` | `kinsn/module/include/native_lab_group.h` | V: Prove generic extent/layout equality, map lifetime and native/proof readonly address/effect correspondence. |
| `EXCLUSIVE_FAILURE_KIND9` | `partial-universal-component` | `kprog/tv/NativeLinkArmExclusive.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-arm-exclusive.json` | V: Extract actual C byte/field/scanner and sealed-group descriptor coverage; align native/linked PCs and every dynamic platform exclusive input/monitor outcome, then V specialized-body/actual compiled-B/private-frame/ABI composition. |
| `CHUNK_AND_CODE_LAYOUT` | `partial-universal-component` | `kprog/tv/NativeLinkFinalImage.lean` | `kprog/results/kprog_tv_20261107/generic-native-link-final-image.json` | V: Establish actual Rust/iced field/image and kernel copy/size/cursor correspondence, final-fixup separation and executable lifetime; compose complete PC/ABI/compiler, other consumers and ARM forms. |
| `PRIVATE_SPILL_PROJECTION` | `proved-conditional` | `kprog/tv/PrivateSpillProjection.lean` | `kprog/results/kprog_tv_20261107/generic-private-spill-projection.json` | V: Derive ownership/public separation and native-to-projected execution from actual compiler/frame transformation. |
| `SPILL_INSERTION_RELOAD_CONTROL` | `pending-universal-law` | `kprog/tv/PrivateSpillProjection.lean` | `kprog/tv/PrivateSpillProjection.lean` | V: Prove private ownership and architectural/reload/control preservation for every actual compiled artifact; apply projection adapter. |
| `HELPER_IDENTITY_AND_ABI` | `pending-universal-law` | `kinsn/module/include/native_lab_group.h` | `kprog/results/kprog_tv_20261107/trusted-inline-memory-binding.json` | V: Compose universal intrinsic memory/return/count and actual compiler laws with stable targets, complete helper ABI and ordered memory/helper events; C retains whole-application replay. |
| `TAIL_CALL_BINDING` | `pending-universal-law` | `kinsn/module/include/native_lab_group.h` | `kinsn/module/include/native_lab_group.h` | V: Prove target/lifetime/control/ABI and effects through actual producer, verifier and JIT paths. |
| `ACTUAL_COMPILED_B` | `pending-universal-law` | `kprog/tv/Composition.lean` | `kprog/tv/Composition.lean` | V: Prove generic compiler/output, definedness and dispatch/PC preservation; supply universal linkLaw. |
| `INVOCATION_ENTRY_ABI` | `pending-universal-law` | `kinsn/module/include/native_lab_binding.h` | `kinsn/module/include/native_lab_binding.h` | V: Establish universal physical entry and wrapper/body/return preservation for every supported ABI. |
| `FULL_ARTIFACT_BINDING` | `trusted-kernel-implementation` | `kinsn/module/include/native_lab_trusted.h` | `kprog/results/kprog_tv_20261107/trusted-native-resources.json` | V: Connect kernel snapshot, actual resource object/metadata identity, verifier instantiation and final emit to full Artifact equality through universal serialization/layout/C/ABI correspondence; C/A supply coherent application adoption. |
| `GENERIC_BLOCK_RELATION` | `proved-conditional` | `kprog/tv/SimulatorComposition.lean` | `kprog/results/kprog_tv_20261107/generic-simulator-composition.json` | V: Discharge actual native PC/control coverage, metadata/operand alignment, common-input/definedness closure, supported ABI and universal actual compiler/link preservation; V completes remaining tokens. |
| `GENERIC_CHECKED_EFFECTS` | `proved-conditional` | `kprog/tv/SimulatorComposition.lean` | `kprog/results/kprog_tv_20261107/generic-simulator-composition.json` | V: Establish production entry/admission, actual decoded/native coverage, metadata/definedness/ABI and actual compiled-B/link laws; retain verifier soundness, canonical ISA fidelity and kernel binding as trusted inputs. |

T's final published source/result paths are clean. Current detached T work is
collected and its closed raw/control files are retired. The permanent Workspace
STOP and shared caches remain. This handoff transfers continuation to C/A/V;
the local T STOP closes the local loop after the handoff publication.
