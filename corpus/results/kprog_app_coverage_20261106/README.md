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
