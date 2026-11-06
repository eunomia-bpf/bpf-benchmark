# Lane C: application proof-artifact coverage, 2026-11-06

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
