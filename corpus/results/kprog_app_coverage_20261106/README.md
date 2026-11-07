# Lane C: application proof-artifact coverage, 2026-11-06

[Captured source-map producer](source-maps.md) preserves original map identity
and value offsets through native/proof generation; actual generation-bound KVM
map execution passes. BCC phase13 reaches37 bound replacements, then stops on
six tracepoint-stack and one context-load verifier rejection; both are being fixed.

[External helper tail-jump repair](tail-helpers.md) preserves direct, GOT,
numeric-ID and subprogram tail-helper operations through proof/kernel linking.
All four forms pass actual bound startup controls; unknown targets reject.

[Production strict startup](strict-runtime.md) replaces all six successful
programs of the tested libbpf object startup with generation-bound native
programs, with source load flags0 and8. Complete corpus-app coverage remains
in progress.

[Startup helper checkpoint](startup-helpers.md): typed helpers160/173,
exact anonymous-bytecode selection, and private strict-shim startup regressions
pass. Full six-application coverage and matching-work timing remain incomplete.

Current application coverage is incomplete. The latest [readonly identity
checkpoint](readonly-layout.md) records actual-load denominators, BCC25/25
proof generation/compilation,23 verifier acceptances and two map-preparation
failures. Transient startup loads remain required; no six-app verified timing
claim follows. Earlier checkpoints below are retained chronologically.

Generation checkpoint: **1,136/1,136 native proof objects generated C**:
1,054 staged objects from five applications plus 82 archived Cilium objects.
No encoding/specialization error was reported. Compilation and KVM load scans
are in progress; [tables.md](tables.md) and [coverage.csv](coverage.csv) record
the checkpoint, including pending cases. No timing claim is made.

These are **artifact counts, not counts of programs loaded by the six apps**.
The staged manifests contain BCC 29, Katran 3, OTel 26, Tetragon 235 and
Tracee 114 program-name entries; the archived Cilium manifest contains 89.
Objects additionally include helper functions and configuration variants;
some manifest entries have ambiguous truncated names. A current six-app
startup inventory and native-object pairing remain unfinished. No app,
program, failed artifact, or helper function was excluded from the scan.

The original app smoke generator assigns every artifact XDP entry ABI.
Consequently its stock-verifier acceptances are recorded as artifact
acceptances, not established coverage of tracing or other app program types.
The June Tracee records named by the lane prompt are workload-derived micro
kernels, not the complete Tracee program population.

Inputs: checkout `075c64b6ed5abb78ea33f10dbd8bae8e81963ec5`, with unrelated
formal/vendor work preserved; `vendor/build/native-bpf/x86/stage/` and
the `native-cilium/` member of
`corpus/results/cilium_native_lab_20261009/current-native-artifacts.tar.gz`.
The Cilium archive is historical evidence, not a current runtime-config pair.
Copied manifests are in [inventory/](inventory/). Generated sources and native
proof inputs are retained in each phase's `generated-sources.tar.gz`.

Commands, from the repository root:

```sh
taskset -c 8-15 make -C kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --report-dir /workspaces/repository/corpus/results/kprog_app_coverage_20261106/baseline --output-dir /workspaces/repository/kprog/x86/app-coverage-baseline'
# Extract archived native-cilium objects into a separate proof root, then:
taskset -c 8-15 make -C kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root /workspaces/repository/kprog/x86/app-coverage-cilium-input --report-dir /workspaces/repository/corpus/results/kprog_app_coverage_20261106/cilium-baseline --output-dir /workspaces/repository/kprog/x86/app-coverage-cilium-baseline'
make -f corpus/results/kprog_app_coverage_20261106/Makefile compile
make -f corpus/results/kprog_app_coverage_20261106/Makefile compile PHASE=cilium-baseline
make -f corpus/results/kprog_app_coverage_20261106/Makefile verify
make -f corpus/results/kprog_app_coverage_20261106/Makefile verify PHASE=cilium-baseline
make -f corpus/results/kprog_app_coverage_20261106/Makefile summarize
```

The compiler uses six workers per invocation and a 120-second per-object
timeout, retaining full stderr and stdout. Completion records allow rerunning
the compile/verify commands without repeating finished cases. The first
baseline compile invocation saw 779 generated files while generation was
running; rerun it to cover the remaining 275. The guest uses the framework
`vendor/build/x86/linux/arch/x86/boot/bzImage`, ordinary BPF verifier loads,
four vCPUs, 8 GiB memory, and host affinity 8-15. It does not load a native
execution module. These are diagnostic load checks, not benchmark timings.

Generation commands and full output are in each phase's `commands.jsonl`;
`programs.jsonl` maps each name to its input and generated source. Compiler
and loader invocations/output are under `compile/` and `verify/`; nonempty
`.verifier.log` files distinguish verifier rejection from libbpf object-open
or relocation errors. A missing extern BTF definition is a load preparation
failure, not a verifier rejection. Every completed failure remains recorded.

Changes at this checkpoint: the app smoke tool can retain raw commands and
per-program outcomes and generate without compiling. Its compiler can find
the simulator header when the output directory is outside `kprog/x86`.
The result-local Makefile and scripts compile and verify independently and
derive the coverage table from raw records. No workload or app runner changed.

Semantic findings that prevent interpreting baseline acceptance as a native
safety proof:

- Large programs (217 of the 1,054 staged artifacts) take the chunked path,
  which inserts a dispatch fuel limit, an unknown-PC exit, and zero-return
  fallback. These violate `kprog/x86/README.md` and need removal.
- The simulator inserts stack-window and pointer checks ending in
  `__builtin_trap`; BPF compilation reports an unsupported `abort` call.
- Helper PID/UID/CPU bodies return zero, unhandled helper IDs default to zero,
  and the simulator's custom helper numbers differ from Linux helper IDs
  used by register-indirect calls. OTel `custom__generic` becomes a trivial
  early exit after its PID call is modeled as zero. Accepted artifacts and
  raw logs are retained; none has been called generation-bound execution.

Before changing the simulator, its headers and generated contracts were
copied under `baseline/simulator/`. Generated working sources were pointed
at that snapshot so in-flight baseline compiles retain their original
semantics. The source archives preserve the original relative includes.

Next: finish compile/load enumeration, fix the frequent missing semantics,
rerun the table with correct program ABI/map relocations, inventory real app
startup, then execute passing native programs with generation-bound proofs
and add exact commands to the shared coordination file for lane R timing.

## Label-renderer follow-up

The generator now uses its existing label renderer for large programs as well:
295 lines implementing bounded chunk dispatch were removed. No instruction
handler or C simulator header changed. The subsequent `unbounded` census
generates 1,052/1,054 staged objects and 82/82 archived Cilium objects. The
two Tetragon `try_preload_arg` self-recursive entries now fail explicitly with
`unsupported unresolved call target`, instead of entering a bounded simulator
that can fabricate a return. Both failures and the earlier successful
generation records remain available.

A second fix rejects register/memory indirect JMP operands in both the
encoder and label renderer. Previously `branch_target("rax")` returned zero,
silently turning `jmp rax` into a direct jump to the entry label. Direct
`jmp 0` remains supported. The `label` and `cilium-label` phases rerun the
complete input population after both fixes; the `unbounded` phases retain the
intermediate results. Generate them using the first two commands above with
the report/output directory suffix changed to the phase name. Compile,
verify, and summarize using the result Makefile with `PHASE=<phase>`.

Regression command:

```sh
taskset -c 8-15 make -f corpus/results/kprog_app_coverage_20261106/Makefile dispatch-regression
```

The test compiles the actual old and current generated C and an independent
native x86 loop. Only the old generator's chunk-selection threshold and chunk
size are reduced to keep the reproducer small. Results are
`old=0 current=10001 native=10001`; a 2,049-instruction emission check also
confirms the large program retains every instruction and no chunk/fuel loop.
Register and memory indirect jumps both raise explicit errors; direct zero
remains distinct. The same test compares all 29 current micro sources with
the old renderer: all 29 are identical. The old generator is retained in
`baseline/simulator.tar.gz`; extract that archive under `baseline/` before
reproducing the regression in a fresh checkout. See
[dispatch-regression.log](dispatch-regression.log).

Validation also ran
`taskset -c 8-15 make -C kprog/x86 micro-proofs-build MICRO_SIM_PROOF_ARGS='--jobs 2'`:
24/29 micro artifacts and the negative artifact compile. The five failures
are `bpf_local_call_fanout_dispatch`, `katran_lb_consistent_hash_select`,
`packed_header_bitfield_decode`, `tetragon_process_event_arg_filter`, and
`bpftrace_comm_key_fnv_hash`, all at existing simulator stack traps. Their
generated sources are identical to the baseline renderer; the failures were
retained in [micro-proofs-build.log](micro-proofs-build.log).

The required full `make -C kprog/formal check` was attempted and stopped at a
missing `KProgFormal.Generated.GeneratedArm64Mod` compiled import while lane V
was moving the shared formal tree. This is not a passing full-formal result;
[formal-check.log](formal-check.log) preserves the failure. Rerun after V's
validated-layout announcement; no V-owned files were staged here.

Active compilation continues on CPUs 8-15, with case results checkpointed
individually. Baseline and unbounded jobs may still be running: inspect their
`compile.make.log` and process list before launching another copy of a phase.
Working baseline sources suppress only repeated C23-label diagnostics after
the first noisy records; raw earlier output is retained. This pragma and the
header-snapshot include change affect diagnostics/paths, not instruction
semantics. Log archives are snapshots of completed records, not a declaration
that every queued case has finished. Coverage CSV output now uses LF line
endings so `git diff --check` can validate it.

Generation-bound application execution has not occurred: lane A confirmed
that the shim C entrypoint never sets `FdLoadOptions.proof_insns`, and lane T
owns the binding API work. The current app native path is unbound. Correct
program ABI/map linking and helper semantics also remain unfinished. No exact
generation-bound app Make command exists yet, so no app timing request has
been fabricated for lane R. Artifact acceptances remain in the table and raw
logs; they are not relabeled as native execution or current loaded-app
coverage.

The final label generation totals are **1,052/1,054 staged plus 82/82 archived
Cilium**, with the same two explicit recursion failures. The indirect-JMP fix
does not change any generated application C source in this population; all
1,134 successful sources match the preceding unbounded generation. Cilium's
82 completed compile/load records are reused under `cilium-label/`, with zero
new loads claimed; [source-equivalence.json](cilium-label/source-equivalence.json)
records that comparison. A fresh label compilation is running for the other
applications. The `baseline-tail` batch processes the final 275 baseline
records in parallel with the original first 779 and writes to the same raw
baseline directories; these are disjoint work queues, not extra artifacts.

The second full-formal attempt reached 42 Arm64 helper-idents oracle
mismatches during lane A's helper extension; see
[formal-check-stable.log](formal-check-stable.log). A subsequently announced
its targeted helper checks passing, and `formal-check-retry.log` records the
next full attempt, which fails in V's in-progress
`KProgFormal.Refinement.X86Cmov` proofs. No full-formal green result is
asserted by this checkpoint. The dispatch regression also checks that a
timed-out app smoke subprocess retains complete stdout/stderr and propagates
its timeout, rather than losing its raw diagnostics.

Lane V changed the shared x86 CMOV macro at 07:19 UTC during the unbounded
compile queue. Raw records from that interval remain retained; the header
variant and possible affected completed cases are in
`unbounded/header-variants/`. In-flight cases may also span that edit. At
07:21 UTC, all future unbounded/label compiler inputs were pinned to the
original saved headers. The baseline was already pinned; Cilium's unbounded
compile/load scan finished before the edit. Interpret the unbounded compiler
census with this version caveat. The fresh label scan consistently uses the
saved headers, including their documented unresolved helper/stack semantics.

Before committing, F and V added separate operand-packing fixes to the same
generator file. Only C's chunk-removal and indirect-JMP hunks are staged by
this result; their packing hunks remain untouched. The C-only generator is
also saved as `simulator/generator-label.py` in the simulator archive. The
scoped regression command is the one above with
`GENERATOR=/workspaces/repository/corpus/results/kprog_app_coverage_20261106/baseline/simulator/generator-label.py`;
[dispatch-regression-scoped.log](dispatch-regression-scoped.log) records the
passing native/indirect-jump/timeout tests and the 29 unchanged micro sources
for that C-only revision. Later encoder fixes can legitimately change the
micro source comparison.

Each phase's `compiled-objects.tar.gz` retains the completed successful BPF
compiler outputs, alongside the generated source/input archives and raw load
logs. Failed/in-flight compiler outputs remain in the work directories; no
program failure was dropped. The expanded baseline KVM batch attempted 185
compiled artifacts: 43 accepted and 142 failed (132 verifier rejections and
10 load-preparation failures). Cilium's separate batch adds two accepted
artifacts. These counts are artifact observations with the ABI/helper
limitations above. The running queues and the table can advance beyond this
checkpoint. The shared coordination file now requests R's public `make corpus`
stock-control inventory for all six applications, to obtain current loaded
program names/types/IDs without introducing a new launcher.

## Completed baseline artifact census

All 1,136 baseline artifact attempts are complete: 187 compiled; 45 were
accepted by the stock verifier, 132 rejected by it, and 10 failed during
libbpf load preparation. The other 949 failed compilation, including 137
compiler timeouts. No baseline case remains pending. These are available
native artifact counts, not a current loaded-program denominator.

| Application | Native artifacts/generated | Compiled | Accepted | Verifier rejected | Load preparation failed | Compile failed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | 34 | 10 | 0 | 0 | 10 | 24 |
| cilium | 82 | 2 | 2 | 0 | 0 | 80 |
| katran | 6 | 3 | 1 | 2 | 0 | 3 |
| otelcol-ebpf-profiler | 30 | 3 | 3 | 0 | 0 | 27 |
| tetragon | 809 | 165 | 35 | 130 | 0 | 644 |
| tracee | 175 | 4 | 4 | 0 | 0 | 171 |

The 45 accepted artifact names are in [accepted-artifacts.csv](accepted-artifacts.csv).
They have not been presented as generation-bound app executions. The final
verification command resumed recorded cases (no duplicate loads were needed):
`make -f corpus/results/kprog_app_coverage_20261106/Makefile verify`.
See `baseline/verify-final.make.log`. The unbounded and label queues remain
active; take their next checkpoint after completion rather than relaunching
active workers.


## Recovery and zero-address direct-call correction

The 08:34 UTC container restart stopped the two post-fix compiler queues.
Completed per-program records survived; neither queue is currently running.
The completed baseline table above remains unchanged.

The two previously described "self-recursive" `try_preload_arg` failures
were a native-link relocation bug. The original Tetragon source calls
`read_reg`; its native implementation starts at `.text` offset zero.
Reachability discovery skipped that address, and rewriting left the old
relative call displacement in the moved entry. The proof therefore called
its own entry instead of `read_reg`. Both zero-address exclusions are removed.
A regression builds a two-function ELF object with the callee at zero and
checks that discovery includes it and that the rewritten CALL reaches its
new, nonzero address.

`taskset -c 8-23 make -f corpus/results/kprog_app_coverage_20261106/Makefile zero-address-call`
passes all 54 native-link unit tests and regenerates both affected proofs,
each with `try_preload_arg` and `read_reg` (2,547 native bytes, six relocations).
`taskset -c 8-23 make -f corpus/results/kprog_app_coverage_20261106/Makefile zero-address-sources`
generates both simulator sources successfully. This closes their generation
failure; compilation, verifier acceptance with the actual application ABI/maps,
and generation-bound execution remain required and are not claimed here.
Logs: [link/test](zero-address-call.log),
[source generation](zero-address-sources.log). The
[artifact archive](zero-address-call/artifacts.tar.gz) retains the replacement
proof objects, generated C sources and per-program generation records.


## Finite-target dispatch and real helper calls

The native-CFG analysis resolves every indirect target in all 1,136 archived
artifacts, with the two repaired `read_reg` inputs substituted explicitly.
It joins reaching values across branches, invalidates overwritten/partial/
implicit destinations, follows native calls/returns, and invalidates helper
caller-saved registers. It has no native execution counter. Unknown targets
fail generation. The emitter dispatches on the actual register value; code
offsets and helper IDs have separate tags. A surviving unmatched dispatch
fails compilation instead of producing a runtime default return.

| Application | Artifacts analyzed | Finite target analysis succeeded |
| --- | ---: | ---: |
| bcc | 34 | 34 |
| cilium | 82 | 82 |
| katran | 6 | 6 |
| otelcol-ebpf-profiler | 30 | 30 |
| tetragon | 809 | 809 |
| tracee | 175 | 175 |

The inventory found register-indirect calls in 940 artifacts and no indirect
JMPs. The new JMP support is exercised by assembled native fixtures. Exactly
47 corpus call sites have multiple helper IDs; [multi-helper-sites.json](multi-helper-sites.json)
retains their names, PCs and targets. These require native-link dispatch too:
its previous last-seen helper tracking can select the wrong member of a CFG
join. The proof-side analysis alone does not repair that native lowering.

The 65 helpers observed in these artifacts now use Linux IDs and real typed
calls, including PID14, UID15, CPU8 and time5. The previous default-zero and
PID/UID/CPU zero bodies are removed. `bpf_attach_map`, `bpf_attach_tmp_map`
and `bpf_prog_load_map` are data symbols, not helpers. The shared declaration
reader and app extern handling now distinguish them. [helper-abi.json](helper-abi.json)
records return/argument types from vendored libbpf; the same manifest was
handed to A. C owns the simulator/header changes; V owns the corresponding
65-row formal mirror and its host instantiations.

Validation through the result Makefile:

- `indirect-regression indirect-bpf`: actual native assembly and generated C
  agree for both inputs to two-target JMP, CMOV and nested indirect CALL
  fixtures (42/17, 42/17 and 6/14); all three BPF objects compile.
- `indirect-kvm`: all six verifier/test-run checks return their exact expected
  values. Raw JSON records include the commands and complete loader output.
- `helper-abi-regression`: all 65 Linux IDs/signatures and 130 direct/ID routes
  pass, with nonzero returns and high-bit argument canaries. IDs0/999 fail
  compilation with the required unresolved-helper diagnostic.
- `dispatch-regression cmov-regression`: the native 10,001-iteration loop still
  returns10,001 (old fuel path returns0); unknown jumps fail; timeout logs
  survive; all three retained CMOV host grids pass, including eager memory
  faults and false32 upper clearing. The CMOV register-source temporary is
  no longer volatile, so a finite register target remains visible to clang.
- `micro-proofs-build MICRO_CONFIG=../../micro/config/micro_stage2.yaml` via
  `make -C kprog/x86` builds all13 cases after fixing named-helper GOT call
  classification. This was the pre-helper-transition build checkpoint;
  helper65 and ABI changes require the subsequent fresh checks.

The manifest generation-bound fixture attempt is retained in
[indirect-bound-kvm.log](indirect-bound-kvm.log). It reaches correct original
BPF results, then native-link rejects native indirect JMP/code CALL. No
successful bound execution is claimed. T has supplied validated kind7 helper
pointer literals for the required multi-helper native table lowering; C owns
its finite CFG/linker implementation.

Fresh phase `finite` generates **1,136/1,136** sources with these helpers and
F's raw-stack/operand repairs. Its complete header/include/generator snapshot
was frozen before compiling. The compiler queue and both interrupted historical
`unbounded`/`label` queues are resumed, retaining every completed record.
`make -f corpus/results/kprog_app_coverage_20261106/Makefile summarize` updates
[tables.md](tables.md) and [coverage.csv](coverage.csv); pending rows remain
explicit. These remain XDP artifact diagnostics until actual app ABI/maps and
loaded-program inventory are paired.

F's new generation-bound negatives exposed **three accepted ABI safety bugs**:
undefined entry GPRs, undefined entry flags, and a helper-clobbered register can
select an unsafe arm that current zero initializers hide. F retains the actual
accepted sidecars under `kprog/results/kprog_fidelity_20261106/negative/`;
unsafe programs were never executed. C owns the definedness/liveness repair,
including opaque callee-save handling; these findings remain open. Actual
context projection, callback helper ABI, code-address/base binding, native
multi-target lowering and the six-app runtime arm also remain required work.
Neither this target census nor its verifier acceptances certify an application
or close the full operator goal.

The [finite-target archive](finite-targets.tar.gz) contains every per-artifact
CFG record; [indirect artifacts](indirect-artifacts.tar.gz) contains assembled
fixtures, generated C/BPF, ABI test sources and complete KVM/compiler records.
[Fresh generation archive](finite/generated-sources.tar.gz) retains all1,136
source/input pairs and the frozen complete simulator/include snapshot.
The complete disassembly-site inventory is in [indirect-sites.tar.gz](indirect-sites.tar.gz).


## Undefined entry and helper-clobber repair

The generator now checks native ABI definedness before emitting an artifact.
It joins register bit masks and flags over native control flow, follows calls
and returns, and tracks opaque private-stack saves. Only RDI/context and RSP
are entry inputs. Helper caller-saved GPRs and condition flags become
unspecified; reads must be established again by native instructions. Blind
callee-save PUSH/POP remains valid. No runtime check, seed widening, trap,
fuel or fallback was added to accepted programs.

Bit masks matter: `MOVBE SI,[...]` followed by `SHL ESI,16` discards the
unspecified upper16 and produces a defined32-bit result with zero-extended
upper64. Its CF can still be unspecified. The checker preserves that distinction;
BMI SHLX/SHRX/SARX/RORX destinations are writes, not reads of old values.
The reported packet parser failure was this checker precision bug, not an
absent RSI entry argument or an application exclusion.

`make -f corpus/results/kprog_app_coverage_20261106/Makefile abi-positive-compile`
generates and compiles all42 original micro/helper-map programs (29+13).
Regression cases also accept blind saves/discarded-bit shifts and reject
observed opaque copies, partial return registers and undefined shift carry.
`abi-regression indirect-kvm` retains all six native-matched KVM dispatch results.

`abi-bound-kvm` builds the full14-case F negative suite and uses the production
manifest loader with T's paired kernel/module. Result: **8 verifier rejections,
1 loader rejection and5 specialization rejections; zero accepted findings or
infrastructure failures**. The three formerly accepted ABI cases now fail for
the actual undefined register/flag premise before upload. Unsafe native code
was never executed. This closes these three concrete findings, not all remaining
ABI/noninterference or artifact-composition obligations.

Raw logs: [positive build](abi-positive-compile.log),
[full bound sweep](abi-bound-kvm.log), [regression](abi-regression.log).
[ABI artifacts](abi-definedness-artifacts.tar.gz) retains all14 native inputs,
proof/build records, manifests, verifier logs, all42 positive C/BPF outputs and
the checker snapshot. A is adapting the same effect-analysis approach.

The first `defined` census encountered disappearing live stage inputs during
another native rebuild; its command/error records are retained. The replacement
`defined-pinned` census explicitly reads the immutable proof copies from phase
`finite`, preserving all1136 original inputs rather than depending on mutable
vendor outputs. New constructor failures remain listed and must be resolved
with correct caller/entry ABI roles and actual loaded-program pairing. They are
not program exclusions. The earlier `finite` and historical compiler scans
continue from their cached per-case records.

The final checker also requires entry/subroutine returns to restore their native
stack position, rejecting a scalar POP into RSP before return. The census tool
now accepts an explicit frozen generator; `defined-final` pins Python modules,
helper declarations, C headers and native proof copies together. Its raw
constructor outcomes supersede the earlier mutable-input/version diagnostics;
all earlier records remain retained.


## PUSH immediate and memory, POP memory: accepted safety bug repaired

The production constructor formerly encoded every nonregister PUSH as
`PUSH REG_NONE` (zero) and discarded POP memory destinations. The real bound
loader accepted a candidate whose native `push 1; pop rax` selected an unsafe
packet-end dereference while the simulator selected the safe zero arm. The
unsafe native candidate was never executed. The before-fix acceptance is kept
in `pushpop-before-bound/outcomes.json` inside the archive below.

PUSH now preserves sign-extended immediate values and memory sources; POP
preserves memory destinations. Operand-size16 uses a two-byte stack step.
Memory PUSH computes its address before decrementing SP; memory POP computes
its destination after incrementing SP, including indexed addresses. Definedness
tracks those stack effects and known index literals. Both forms use the existing
full-field `RUN_OP` route, removing two shortcuts that would lose AUX/IMM.
The generated C/Python/Lean dispatch contracts agree; no ISA operation or
runtime assertion was inserted.

Commands, all through this directory's Makefile:

- `pushpop-host`: all9 native/simulator cases return matching expected values.
- `pushpop-kvm`: all9 generated programs pass the verifier and actual test run.
- `pushpop-after-kvm`: the previously accepted unsafe candidate is rejected by
  the real generation-bound verifier (`proof_bound=1`).
- `pushpop-formal`: focused Lean specialization build passes; independent
  specialization host467 and register PUSH/POP route31504 checks pass.
- `abi-positive-compile`: all42 original micro/helper-map programs still
  generate and compile.

[Raw before/after, native, proof, KVM and source artifacts](pushpop-artifacts.tar.gz)
retain all commands and verifier logs. [Bound rejection](pushpop-after-kvm.log),
[nine KVM runs](pushpop-kvm.log), [host comparison](pushpop-host.log),
[focused formal checks](pushpop-formal.log), and
[42-program regression](pushpop-positive.log) are preserved separately.
This closes the concrete PUSH/POP producer defect; full helper memory effects,
base/address fidelity and six-application verified runtime integration remain
active required work.


## Verified corpus runtime selection

The existing two-start framework now distinguishes the generation-bound native
arm through `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`, alongside
`BPFREJIT_SHIM_NATIVE_LOADER=post` and an application manifest containing
`simulator_object`/`simulator_program` for every native entry. The baseline
starts with native controls cleared; the second startup restores the exact
manifest and bound-proof requirement. Workload launch, sample collection,
raw tool output and per-program run count/time collection use the existing
identical `measure_app_phase` path. No extra throughput assertion or filtering
was introduced. Lifecycle mode is `verified_native_loader`; without the
requirement the existing unbound native arm remains available.

The loader refuses an empty proof before native upload. The shim refuses an
unmatched application program and subjects Tetragon's runtime-generated stats
helper to the verified manifest path. It negotiates bound-proof ABI version1
before calling the shared loader, so an older library cannot silently ignore
the requirement. Successful replacement logs `bound_required=1` and the actual
original/native program IDs. Existing libbpf feature-probe handling is retained.

`make -f corpus/results/kprog_app_coverage_20261106/Makefile runtime-kvm`
uses normal libbpf startup intercepted by the production shim. It executes the
installed native program, independently inspects its actual translated image
through a fresh descriptor, and finds a nonzero-generation sidecar with
retval127. Missing proof, missing manifest entry and incompatible loader ABI
all terminate startup with97. This small integration fixture is not a substitute
loader for corpus applications and is not six-app timing data.
`runtime-python` passes13 lifecycle tests, including clearing/restoring the
bound requirement across phases. Library/shim builds and raw KVM startup logs
are retained in [runtime artifacts](verified-runtime-artifacts.tar.gz).

The application command shape is `BPFREJIT_SHIM_NATIVE_LOADER=post
BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1
BPFREJIT_SHIM_NATIVE_MANIFEST=<complete-app-manifest> make corpus` with the
normal app/sample controls. Complete manifests and actual program ABI/map
pairing are still being built; no application is handed to R as a successful
verified timing run at this checkpoint. App event/sample/action/drop counters
must be paired with actual startup results before a same-work timing claim.


## Helper write effects and complete finite-phase verifier snapshot

`helper_abi.py` records eight narrow kernel contracts that overwrite the full
requested output region on both success and error. These are stronger than
`ARG_PTR_TO_UNINIT_MEM`; string reads cannot initialize an untouched suffix.
The definedness checker applies the actual constant u32 byte extent and joins
all finite helper callees. Probe/copy helpers propagate opaque private-stack
source bytes and saved pointer provenance into the destination; copying a
saved unknown register does not initialize its value. Unknown native-stack
source relations remain explicit constructor failures requiring resolution.

`helper-effects-regression` passes23 cases: written prefixes, untouched suffixes,
opaque copies, defined copy prefixes and multi-target call joins.
`abi-positive-compile` still generates/compiles all42 micro/helper-map programs.
The immutable `helper-effects` constructor census finishes all1136 inputs:
421 generate and715 reject. The prior `defined-final` snapshot generated549;
the new source-footprint check exposes129 previously unchecked stack relations,
while other precision repairs admit one additional case. All outcomes are
retained. These rejections are active defects/precision work, not exclusions.

The completed `finite` compiler phase has937 successful compiles out of1136.
The resumed verifier run now covers every one:40 artifact acceptances and897
failures, split by verifier rejection versus preparation failure in
[tables.md](tables.md). These diagnostics use the frozen pre-definedness
simulator and XDP artifact ABI, and do not certify a whole application.
The table now includes both definedness phases and current error categories;
[coverage.csv](coverage.csv) retains individual status/cause rows.

Commands: `helper-effects-census`, `helper-effects-regression`,
`verify PHASE=finite`, and `summarize`, all via this directory's Makefile.
[Census/verification archive](helper-effects-artifacts.tar.gz) retains both
1136-record snapshots, frozen Python/header/helper inputs, commands,23-case
regression, all finite verifier records and42-case build log. Native source
proof copies remain those retained in the earlier finite input archive.


## Native return-slot provenance

The constructor now tracks the entry return token and finite actual CALL return
continuations through full-width stack/register copies. RET follows the saved
token's continuation rather than assuming the current syntactic call context.
Partial writes and arithmetic updates invalidate return provenance; blind
MOV/PUSH/POP/XCHG saves/restores remain valid. Entry fallthrough also requires
the original outer return slot. No runtime assertion or stack-write ban was
added. Memory arithmetic now invalidates saved-pointer metadata consistently.

`ret-regression` passes11 cases including partial/arithmetic corruption,
internal-call corruption, preserved outer saves/exchanges and internal token
POP/PUSH. `ret-after-kvm` records constructor rejection before upload of
`mov QWORD PTR [rsp],0; mov eax,2; ret`. Its archived before-fix outcome was
already **verifier rejected** for an invalid BPFfp+0 stack write, not an
accepted finding; unsafe native was never executed. The change closes the
constructor's missing provenance premise without misreporting that baseline.
All42 existing sources generate/compile and all23 helper-effect regressions pass.

[Return artifacts](ret-artifacts.tar.gz) retain before/after input, frozen source,
proof, bound load logs and regression records. Absolute native code/stack-address
observation and general return-target translation remain active fidelity work;
this constructor result alone does not discharge those obligations.

## Partial-width arithmetic dependency repair

ADD/SUB/ADC/SBB now propagate the defined low-bit prefix instead of requiring
all source bits to be defined before an instruction whose upper output may be
discarded. An unknown bit can carry/borrow into every higher bit. CMP/TEST may
produce unobserved unspecified flags; observing those flags still rejects.
TEST's CF/OF are independently defined by the instruction. This changes only
constructor dependency analysis; native instruction semantics remain in C.

All20 arithmetic regressions pass, including low16 results, unknown high-bit
observations, carry dependencies and private-stack arithmetic. Existing23
helper-effect and11 return-provenance regressions pass, and all42 existing
micro/helper-map sources generate and compile. The two opaque-value tests now
actually observe TEST flags through a branch rather than discard them.

The frozen `arithmetic` census completes1136/1136:429 generated,707 constructor
failures retained. It newly generates Katran `balancer_ingress` and seven
Cilium artifacts, with no previously generated artifact rejected. Generated
counts are BCC33/34, OTel28/30, Cilium58/82, Tetragon193/809, Katran5/6 and
Tracee112/175. These remain staged-artifact counts, not actual loaded-program
coverage or verified application runs. The updated full table and cause rows
are in [tables.md](tables.md) and [coverage.csv](coverage.csv).

Commands: `make -f corpus/results/kprog_app_coverage_20261106/Makefile
arithmetic-regression helper-effects-regression ret-regression`,
`abi-positive-compile`, and `arithmetic-census`. The interrupted census resumed
through `make -C kprog/x86 app-proofs-build` with `--offset 352` and the same
frozen generator/proof root, preserving all earlier records. The final command
exits1 for the retained constructor failures. Full formal checking is owned by
lane V under the shared one-check rule; C stopped its duplicate invocation and
does not report that invocation as a pass. [Raw arithmetic evidence](arithmetic-artifacts.tar.gz)
contains all1136 outcomes/commands, frozen constructor/header inputs, generated
sources,42-case compilation records and focused regression output.

## Native helper dispatch through CFG joins

The native linker now joins reaching helper definitions instead of using the
last helper seen in file order. It retains every reachable literal/GOT target,
intersects knowledge across unknown predecessors and invalidates partial,
implicit and call-clobbered writes. A native-code callee cannot be assumed to
preserve registers merely because a canonical external helper does. Original
helper-ID loads remain present, including when the ID is observed after a call.

For several possible IDs, the linker emits LEA plus an indexed native CALL
through a finite per-site table; its target is the original ID register.
Table entries are zero-valued kind7 canonical-helper relocation slots, checked
and patched by the existing generation-bound loader. Joined GOT helper loads
retain their actual, separately bound pointer values. No runtime guard, trap,
last-target choice or synthetic flag condition was added.

`native-dispatch-test` passes65 Rust tests (including existing Arm map resolver
regressions). Six actual CPU observations check both inputs of joined IDs,
CMOV-selected IDs and joined GOT addresses, checking the selected callee as
well as the native return. All three generated BPF proofs compile.
`native-dispatch-kvm` runs the production manifest/linker/binding path: kernel
and native return14/15/2 respectively; native program inspection finds2/2/1
nonzero-generation chunks. These fixtures establish dispatch integration and
execution, not six-application coverage or complete ISA-fidelity discharge.

Reproduce with `make -f corpus/results/kprog_app_coverage_20261106/Makefile
native-dispatch-test native-dispatch-kvm`. The linker and loader build into
isolated C directories; KVM uses a copied matched x86 kernel/module from lane T
(the11:10/11:25 pair). The first load attempt incorrectly supplied the prepared
proof as a raw object and was processed twice; its failed diagnostic is kept.
The corrected fixture uses the production raw-object/sibling-proof convention
and explicitly requires both prebuilt and bound proofs. No loader change was
needed for that correction.

C's first full `make -C kprog/formal check` attempt stopped at lane V's
concurrently edited `Refinement/Arm64Logic.lean` goals; that failure is retained.
V corrected its logic lift and reran the sole full check to exit0 (333 Lean
jobs, wire suites, retained C oracles and12 map-selection Rust regressions).
The [complete final check log](native-dispatch-formal-final.log.gz) records
that workspace pass. All65 Rust cases and three generation-bound cases also
pass on the final C source. [Native dispatch evidence](native-dispatch-artifacts.tar.gz) contains
commands, full logs, production source inputs, native/proof objects, zero-slot
relocations, manifests, the isolated linker/probe, and the copied VM pair.
Native code-target dispatch and actual app entry/map pairing remain active
work; no application timing command is added from these fixture results.

## Native code-target dispatch and relocation

Finite native register jumps and calls now retain their actual code targets.
The linker discovers address-taken functions, follows same-section CFG edges,
and re-anchors every LEA to the target instruction's new encoded offset after
RET/helper expansion and ABI edits. PC32 references likewise use instruction
offsets rather than stale source byte offsets, including an interior target
following a removed NOP. Unknown/mixed targets remain explicit errors; the
verifier-visible proof dispatch uses the existing finite native target sets.
No runtime assertion, guard, fallback or instruction substitution was added.

`native-dispatch-test` passes66 Rust tests. `code-dispatch-kvm` passes four
production generation-bound cases: two-target JMP, CMOV-selected JMP, nested
indirect CALL and a cross-section PC32 interior target. All four native return
values match BPF (42/42/6/42), with one nonzero-generation chunk each. Eight
actual CPU observations cover both inputs. All four BPF proofs compile.
The actual emitted native stream contains its register-indirect transfer;
its code-pointer LEAs target the corresponding relocated instructions.

The first shared-worktree formal attempt encountered lane V's in-progress
BMI2 parser change; its failure is retained. The final check ran from an
immutable committed-source export plus only this pending Rust change:
`make -C /workspaces/.agent-state/kprog-lanes/C/code-check-source/kprog/formal check`
passes335 Lean jobs, both wire suites, all retained C oracles and12 map Rust
regressions. The export's source revision is recorded in
[code-dispatch-source-revision.txt](code-dispatch-source-revision.txt).
[Raw code-dispatch evidence](code-dispatch-artifacts.tar.gz) preserves producer
source, commands, logs, objects, manifests, emitted blobs, CPU observations,
bound results and that isolated formal input/output. Reproduce via
`make -f corpus/results/kprog_app_coverage_20261106/Makefile
native-dispatch-test code-dispatch-kvm`.

## Actual six-application x86 startup inventory

The retained lane R runs now supply actual startup loads: the five-app run
`x86_kvm_corpus_20261106_114826_062263` and Katran run
`x86_kvm_corpus_20261106_113727_795524`. Every attempt is paired by PID/TID with
its syscall outcome. Resident counts match that application's actual load IDs
to the captured global inventory; other applications' IDs do not enter the
count. All probes, transient programs, retries and failed attempts remain in
the raw records. A resident snapshot is not the total number loaded over time.

| Application | Load attempts | Successful loads | Failed loads | Resident load IDs | Actual generation-bound app coverage |
| --- | ---: | ---: | ---: | ---: | --- |
| BCC | 77 | 77 | 0 | 25 | pairing in progress |
| OTel | 17 | 16 | 1 | 13 | pairing in progress |
| Cilium | 221 | 210 | 11 | 92 | pairing in progress |
| Tetragon | 311 | 308 | 3 | 81 | pairing in progress |
| Tracee | 162 | 162 | 0 | 151 | pairing in progress |
| Katran | 6 | 6 | 0 | 1 | pairing in progress |

These are stock application startup results, not verified-native success.
Proof-generation/verifier outcomes for these actual programs will be recorded
as their full-context/map pairs are constructed, independently of the1136
staged-artifact diagnostics. No application timing request follows from a
fixture or a name-only pairing. Run `make -f
corpus/results/kprog_app_coverage_20261106/Makefile startup-inventory` once to
capture this snapshot. [Startup records](startup-x86-artifacts.tar.gz) contain
all794 attempts, full raw logs, original inventories, names/types/IDs, attach
metadata, per-load errors and the extraction command. There are no unpaired
load outcomes or unfinished attempts in this snapshot.

## Real BCC entry proofs and source load context

The actual BCC resident snapshot now pairs all25 load IDs with full source BTF
symbols, original BPF program sections and unchanged upstream map/DATASEC
declarations. Full BTF selectors distinguish entries whose kernel names share
15-byte prefixes. The first source/header and CO-RE compilation failures are
retained in phases1–2; phases3–6 retain the subsequent verifier diagnostics.
Phase4's tentative frame sizing from memory operands was corrected before
publication: only the minimum reachable native RSP determines allocated frame
extent. An arbitrary access below RSP cannot enlarge the proof arena.

| Actual application snapshot | Resident entries | Proof generated | Compiled | Verifier accepted | Verifier rejected | Load preparation failed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| BCC, final `bcc-real-7` | 25 | 25 | 25 | 23 | 0 | 2 |

The two preparation failures are capable's stackmap declarations with
`max_entries=0`; the upstream loader supplies their actual capacity. They remain
active integration work with live source-map reuse. These diagnostic loads do
not establish an application run, and the77 actual startup load attempts
(including probes and transient loads) remain the complete startup denominator.
No program is discarded or classified as unsupported.

The generic renderer now accepts the actual raw context and program section,
includes original source declarations, preserves complete native readonly
objects in a separate `.rodata.native` DATASEC, and applies PC-relative symbol
interior offsets at the actual load width. Relocation forms without implemented
semantics still produce recorded constructor errors. Raw context kind2 is
distinct from XDP0/SKB1: a host regression checks exact64-bit loads at all four
packet ABI offsets (0/8/80/208) stay scalar. Constant ABI load offsets retain
their constants through compilation; volatile pointer loads preserve each
native load. The LEA readonly fast path avoids an irrelevant indexed-address
calculation that had produced pointer-plus-pointer verifier rejection.

`raw-context-kvm` passes actual generation-bound readonly-tail32/signed-byte
loads and a256-byte allocated frame (return2217943569/4294967172/1, generation1
each). An initialized access at `[RSP-1024]` without allocation is rejected by
the proof verifier with an explicit frame-pointer arithmetic diagnostic; that
unsafe native fixture is never executed. An earlier mixed C++/library/kernel
ABI failure is retained as infrastructure failure, not negative verifier
success. Source/body SP and return-slot correspondence, numeric address
observers and complete architectural flags remain cross-lane fidelity work;
these fixture successes do not discharge those obligations.

The production shim now calls the versioned source-context loader entry and
forwards actual intercepted `prog_flags` and the flag-qualified token FD.
The16-byte ABI checks offsets as well as size; a missing new export is fatal.
Both x86 and Arm shim builds pass using vendored BPF UAPI headers. Real shim
startup tests with flags0 and `BPF_F_TEST_STATE_FREQ=8` both execute the bound
native program (generation1, return127); logs confirm actual captured flags
and token FD=-1. An actual older bound-proof ABI1 library without the new
context export exits97 at symbol resolution, before any old-entry fallback.
This forwards existing source load metadata without changing
the application's launch/workload or adding an admission condition.

The final isolated full formal check passes (`make -C
/workspaces/.agent-state/kprog-lanes/C/raw-check-source/kprog/formal check`):
Lean build, wire suites, retained host oracles and12 map resolver regressions.
Its immutable input is revision26325bd48 plus the three C simulator/generator
changes. The first failed generic-memory fixture build is preserved, along
with the corrected final check. The repeated1136 staged-artifact census still
reports429 generated and707 recorded constructor failures; it is separate from
actual application coverage.

Commands:

```sh
make -f corpus/results/kprog_app_coverage_20261106/Makefile raw-entry-host
make -f corpus/results/kprog_app_coverage_20261106/Makefile bcc-real-generate PHASE=bcc-real-7
make -f corpus/results/kprog_app_coverage_20261106/Makefile bcc-real-compile PHASE=bcc-real-7
make -f corpus/results/kprog_app_coverage_20261106/Makefile bcc-real-verify PHASE=bcc-real-7
make -f corpus/results/kprog_app_coverage_20261106/Makefile raw-context-kvm context-runtime-kvm
make -f corpus/results/kprog_app_coverage_20261106/Makefile raw-entry-census summarize
```

[Raw entry evidence](raw-entry-artifacts.tar.gz) preserves every BCC phase,
per-entry compile/verifier logs, source snapshots, readonly/frame tests,
context ABI startup logs and matched kernel/module/library inputs. The
[frozen census archive](raw-entry-census-artifacts.tar.gz) holds all1136 outcomes
and their generated source/proof objects. The
[formal input and complete logs](raw-formal-artifacts.tar.gz) preserve both
formal outcomes. The actual upstream BCC startup on an isolated runtime image
is the next test; no application timing request has been added.

## LEA stack-pointer destination

`LEA RSP,[RSP+offset]` now preserves the relative RSP representation consumed
by stack memory operations. The previous source-RSP arm materialized a private
arena pointer for every destination, including RSP itself; the next stack
operation interpreted that pointer as an offset. The existing pointer-add
JSON contract now generates the destination-sensitive selector for both C and
Lean. The full LEA refinement covers both destination classes, and a theorem
shows the RSP result is independent of the private arena base. This repairs
that representation bug; numeric entry-SP, flags and source/body frame
correspondence remain active work.

The retained before/after host case reports the old arena pointer versus the
required offset-16, then checks a stack store/load and balanced final RSP.
Actual native and generation-bound KVM execution both return42, generation1.
The readonly/frame positives and actual unsafe-frame verifier rejection still
pass. The LEA route oracle now covers48,553 cases, retaining its original
32,369 cases and adding RSP destinations.

The isolated full formal check passes on revision178e6e84e plus the seven LEA
contract/implementation/oracle files. All29 workload-derived micro proofs and
the negative artifact compile against copied source and the changed header,
including siphash. Initial missing-header snapshot failures are retained.
The shared generated micro files and caches were not modified by these checks.
The fresh BCC phase8 again generates/compiles25/25, accepts23, and retains the
same two loader-configured map preparation failures, with no verifier rejects.
The complete1136-artifact census remains429 generated/707 recorded failures;
coverage readers now also consume the raw JSON records compressed during
coordinated disk cleanup, preserving their previous outcomes.

Reproduce the focused checks with `make -f
corpus/results/kprog_app_coverage_20261106/Makefile sp-lea-prepare sp-lea-host
raw-context-kvm`. The full-check export, original native assembly, before/after
observations, all compiler/verifier logs and raw proof/native objects are in
[LEA evidence](sp-lea-artifacts.tar.gz).

## Frozen runtime packaging

The separate `paired-runtime` image target packages lane T's immutable
context-v2 x86 kernel, stock module tree and15 custom modules, plus the
context-aware shim/loader. All15 modules pass actual KVM insertion together;
this avoids the duplicate-BTF failure observed when shared kernel/module
outputs moved during other builds. The `verified-bcc` final image stage adds
the BCC proof manifest while preserving the existing upstream app binaries.

Three attempted BCC corpus setups retain their full raw logs. The first filled
the guest's Docker scratch tmpfs; the second ingested the image but exhausted
`/tmp` while extracting the stock module tree. The third used private
disk-backed `/var/tmp`, `/tmp` and `/lib/modules`, then was stopped during
installation to release virtme's shared QMP3636 port for lane R. The caller
now uses taskset without `--pin`, so it does not reserve that port. No BCC
workload began in these attempts; no app success or timing request follows.
Only C's interrupted scratch disk was removed; logs and the image are retained.
[Installation evidence](runtime-install-artifacts.tar.gz) preserves the commands,
errors, package manifests, file hashes and successful15-module insertion log.
The paired image can be built with `make -f
corpus/results/kprog_app_coverage_20261106/Makefile paired-runtime-image`.


## Strict BCC application startup capture

The real upstream BCC corpus run `x86_kvm_corpus_20261106_165952_867436`
uses the required-bound native loader arm. It replaces24 startup loads before
missing manifests stop eight five-instruction global-data probes. Those probes
load the application's `libbpf_global` map-value pointer at offset16 and store42.
This is a startup failure, with no native workload result or timing request.
The completed baseline retains its raw per-program work counters and stress-ng
output. The earlier77 successful-load BCC inventory remains the full startup
denominator;24 replacements are progress in this attempt, not full coverage.

The package now places the canonical native proof at the loader's first sibling
lookup path and checks exact readonly object identities and contents against
the simulator ELF. An inherited stale proof sibling can no longer take
precedence. All25 resident entries and five known startup probe definitions are
packaged; the captured map probes and later transient types are being added.

[Raw startup evidence](bcc-strict-startup-artifacts.tar.gz) includes all75 captured
bytecode files, all three corpus records, complete caller logs, package manifest
and original program pairing. It also preserves failed setup attempts: an
incorrect app selector selected no app; an explicit noop override attempted a
load-time bytecode plan. The corrected command uses `bcc/set` and the native
loader without that pass override:

```bash
make -f corpus/results/kprog_app_coverage_20261106/bcc-strict.mk package image capture-image
make -f corpus/results/kprog_app_coverage_20261106/bcc-strict.mk corpus \
  IMAGE=bpf-benchmark/kprog-bcc:c-20261106-12 \
  IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/bcc-runtime-12.image.tar
```

Only the current application image tar is kept. Completed guest Docker disks,
module extraction roots and temporary directories are removed after the guest
exits; raw results and the shared paired base image remain available.


## Source-frame and literal context-load repairs (19:00 UTC checkpoint)

The BPF lifter now derives the frame extent through register copies, joins,
back edges and spilled pointers, and updates both the LLVM allocation and its
frame-top GEP. It does not initialize source stack bytes. The captured six-
instruction helper113 program previously allocated one byte while its helper
wrote eight bytes, corrupting the native return address. The exact old native
program faults on the CPU; the repaired program returns -14 after one eight-byte
helper write. Derived24-byte and joined frames retain24 bytes; a loop or spilled
pointer conservatively retains the architectural512-byte frame. The generated
proof also loads on the generation-bound path (one chunk, nonzero generation).
Three source local-call regressions still return165,177,165 on the CPU.

Raw context reads now use the existing proved exact-width, literal-displacement
primitive. This preserves the original u32 loads at context offsets88 and96,
closing the BCC capability-entry verifier failure. All25 paired resident BCC
proofs generate and compile. Real application startup attempt14 accepts18
application replacements; four native-reference admission failures remain and
three entries are not reached because their tools stop. Attempt15, with current
feature-probe pass-through, reproduces those four failures. These EINVALs occur
after proof verification reaches EXIT and must not be counted as stock-verifier
rejections. Two missing native references identify `htab_map_update_elem`;
the remaining helper identities are being diagnosed. No full bound BCC workload
or timing result is claimed.

| Application | Successful startup loads in retained inventory | Resident programs | Paired proofs generated/compiled | Bound application replacements in latest attempt | Outstanding in that attempt |
|---|---:|---:|---:|---:|---|
| BCC |77|25|25/25|18|4 native-reference admission errors;3 not reached|
| OTel |16|13|pending actual-pair rebuild|not attempted|actual-pair rebuild|
| Cilium |210|92|pending actual-pair rebuild|not attempted|actual-pair rebuild|
| Tetragon |308|81|pending actual-pair rebuild|not attempted|actual-pair rebuild|
| Katran |6|1|1/1 (phase4)|not attempted|stock verifier: expanded stack context passed to XDP helper|
| Tracee |162|151|pending actual-pair rebuild|not attempted|actual-pair rebuild|

Startup-load counts include libbpf feature probes; they are preserved as raw
inventory, not counted as resident application programs. Per operator instruction
those probes pass through unchanged. The historical artifact tables above remain
diagnostic populations, not application coverage denominators. All outstanding
entries stay in scope.

[Source-frame evidence](source-frame-artifacts.tar.gz) retains native/proof
objects, LLVM IR, CPU observations, full phase14 compiler records, captured source
loads and attempts14/15 raw corpus results. Reproduction uses
`make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk`
with targets `source-frame-cpu`, `source-frame-cfg-proof`,
`source-frame-call-proofs`, `source-frame-bound-build`, `source-frame-kvm`,
`fixed-load-prepare` and `fixed-load-bcc-compile` (the prepare target creates a
new phase and must run before compilation). The source-frame repair is shared
with AArch64; native source lifting is architecture independent.

All completed attempt disks, image tars and scratch roots are deleted after
exit. The current attempt16 is running with a private helper-binding diagnostic;
its raw results will remain after its disposable image and disks are removed.


## Bound map-update call identity (attempt16)

The required-bound loader uses the public `bpf_map_update_elem` identity for
call-based map updates. LLVM may merge calls from distinct maps into one proof
call, whose verifier `map_ptr_state` is then poisoned; the original map-specific
`htab_map_update_elem` reference cannot match that call. The public helper
retains the exact operation and passes the existing kernel identity check.
Unbound native map-specific optimization stays unchanged.

Attempt16 accepts23 of25 actual resident BCC programs, closing the capable-exit,
tcpconnect-return and biosnoop-completion admission errors. The remaining two
opensnoop programs fail the existing reference check for native `memset`, whose
proof contains expanded stores. The raw result records startup error and no
native workload timing. Shutdown also records a separate 9p/netfs loop-disk
NULL-call panic after the application failure; it is preserved verbatim.
[Raw attempt16 evidence](bound-helper-artifacts.tar.gz) includes full logs,
captures, exact package and raw corpus result. Disposable disk, image tar and
scratch roots were removed after exit.

Embedding an exact SysV byte-loop memset in the paired native ELF exposed a
separate linker defect: an undefined symbol before a local callee caused symbol
lookup to return immediately. Both x86 symbol scans now continue past undefined
symbols. The existing local-call relocation regression now includes that ordering;
all76 native-link tests pass. No kernel reference check is relaxed.


## Original context at helper calls

Native XDP/SKB context reads use an expanded pointer-width ABI, whereas public
kernel helpers require the original kernel context. The simulator now records
both addresses and translates exactly that ABI base at helper-context arguments;
raw contexts, offset pointers and ordinary memory arguments retain their identity.
XDP adjustment helpers refresh the expanded data/end pointers after the call.
The JSON-generated C/Lean address selector and an external-call composition
refinement both build. The focused host regression checks exact-base translation,
offset/raw identity and the refreshed packet window. Existing helper dispatch
still passes18,690 cases; stack arm/write-lane checks pass117,782/1,401,654 cases.

A real KVM generation-bound XDP fixture calls adjust_head(0), reloads the window,
writes42 and returns XDP_PASS. Baseline and native both report result42/retval2;
the native load has one chunk and a nonzero generation. This is a functional
regression, not an application timing result.

Katran's actual balancer entry now generates and compiles. Its finite indirect
helper dispatch uses the same unreachable-invalid-helper marker as AArch64:
unknown target construction still fails; any non-eliminated marker is rejected
by the verifier. It never supplies an executable fallback. Exact8-byte stack
stores also remain one store at unaligned offsets, preventing LLVM from hoisting
pointer byte-extraction arithmetic. Phase4 passes the old pointer-spill error;
phase5 additionally passes the XDP helper-context error and reaches a partial
`bpl` write to a register holding a verifier map pointer. Phase6 tests an exact
volatile byte-store representation for that remaining issue; it is not adopted
in the production register-write contract at this checkpoint.

[Packet-context evidence](packet-context-artifacts.tar.gz) contains the fixture,
raw KVM output, host/Lean logs and Katran phases1–5. Reproduce with targets
`packet-helper-contract`, `packet-helper-host`, `packet-stack-host`,
`packet-helper-bound-build`, `packet-helper-kvm`, `katran-real-5`, and
`katran-verify KATRAN_PHASE=katran-real-5` under `strict-runtime.mk`.


## BCC: all25 application programs run generation-bound

Real upstream corpus run `x86_kvm_corpus_20261106_192927_028755` completes with
`status: ok` and `mode: verified_native_loader`. All25 resident application
programs generate proofs, compile, pass bound admission and replace the originals;
there are zero specialization failures or verifier rejections. All52 libbpf
feature-probe loads remain unchanged as instructed. No application program is
excluded. The upstream BCC tool set starts and the existing workload completes
in both arms; no workload, launcher or application source was changed.

| Application | Application programs | Proof generated | Compiled | Bound verifier accepted | Specialization failed | Verifier rejected |
|---|---:|---:|---:|---:|---:|---:|
| BCC |25|25|25|25|0|0|

The same four stressors run in both arms. Raw bogo-op counts are:

| Stressor | JIT | Bound native |
|---|---:|---:|
| syscall |8434|514|
| cap |436024|436591|
| set |31324|31673|
| sockfd |340324|318564|

These are functional measurements on CPUs12–15, not final timing. The syscall
sample finishes in3 seconds in the native arm versus2 seconds in the baseline;
all four stressors report success. The raw counts, elapsed/user/system times,
stdout/stderr and per-program run counts are retained without imposing a
count-equality or minimum-work requirement. No application performance ratio is
claimed from this short run.

The last two opensnoop failures were closed by embedding an exact20-byte SysV
memset byte loop in the native ELF. Its real local-callee instructions appear in
both the canonical proof and executed native blob; no external-helper reference
waiver was added. A rerun caught an unaligned8-byte stack-store regression in the
previous increment. The forward repair restores the original byte ladder for
unaligned stores and puts an identity compiler barrier inside its64-bit arm,
preventing pointer-extraction hoisting while retaining aligned pointer spills.
The existing117,782 stack-arm and1,401,654 write-lane cases pass, all25 proofs
compile again, and the complete application run above passes.

[BCC complete evidence](bcc-complete-artifacts.tar.gz) includes exact paired
source/native/proof/simulator objects, every compile record, the runtime package,
all captured loads, the failed preceding run and both complete raw result trees.
`bcc-complete-18/programs.json` lists every accepted symbol;
`bcc-complete-18/workload-counters.json` extracts only raw per-stressor counters.
The runtime package is `bcc-runtime-18`, with image
`bpf-benchmark/kprog-bcc:c-20261106-18`. Reproduce with:

```bash
make -f corpus/results/kprog_app_coverage_20261106/bcc-strict.mk image corpus
```

Lane R's timing request uses the same target with
`CPUS=0-7 SAMPLES=3 WORKLOAD_DURATION=30`. The target deletes its image tar,
guest disk and scratch roots as soon as the guest exits. The immutable runtime
package and Docker image permit immediate re-export for that next run. The
other five applications remain active work; this is BCC completion only.
