# Lane A: AArch64 application artifact coverage, 2026-11-06

Baseline generation: **1,090/1,136 staged native proof objects generated C**,
covering all six application directories. The remaining 46 Tetragon objects fail on unresolved indirect `blr` targets;
all failures and call-register details are retained.
The [baseline table](baseline/table.md), [per-artifact CSV](baseline/coverage.csv),
[command log](baseline/commands.jsonl), and [outcome log](baseline/programs.jsonl)
retain every case. The generator/header snapshot and generated-source/native-input
archive are in `baseline/`. These are artifact counts, not a current inventory
of programs loaded during application startup.

| Application | Staged proof objects | Manifest program entries |
| --- | ---: | ---: |
| BCC | 34 | 29 |
| Cilium | 82 | 89 |
| Katran | 6 | 3 |
| OTel | 30 | 26 |
| Tetragon | 809 | 236 |
| Tracee | 175 | 114 |

Inputs: `vendor/build/native-bpf/arm64/stage/`, dated September 30 in this
checkout. Original manifests are copied into [inventory/](inventory/).
Objects include subroutines and configuration variants; manifests have
truncated-name entries and are not a complete current startup inventory.
No program, helper object, or failing artifact was excluded.

The initial pilot failed to compile: compact generation calls the removed
`arm64_apply_width` function. Its full console output is retained in
[baseline/pilot-compile.log](baseline/pilot-compile.log). The compact generator
also adds a fuel limit and a zero-return exit. Both renderer forms invent
one-entry array map definitions for unresolved app symbols; the app harness
uses XDP entry ABI for every program. Several helper macros return zero
instead of calling the helper. Baseline generation success is therefore **not
verified native safety or generation-bound application execution**. Verifier
checks and application executions remain unmeasured at this checkpoint.

Exact initial command, from the repository root:

```sh
taskset -c 16-19 make -C kprog/arm64 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --report-dir /workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/baseline --output-dir /workspaces/repository/kprog/arm64/app-coverage-baseline'
```

Generation ran on `master`, starting from `075c64b6e`; other lanes committed
`5d3757d35` and `8d4d57957` during enumeration. Neither touched the AArch64
generator/header snapshot. Unrelated dirty work was preserved. QEMU timings
will be functional diagnostics only; lane R owns performance measurement.

The app binding dependency was reported in the shared lane coordination file:
`native_loader_load_from_fd_with_manifest_path_btf_and_attach` does not populate
`FdLoadOptions.proof_insns`. The existing app entrypoint therefore uploads
unbound native code. A native-link `.proof.o` is native ELF input, not the
simulator BPF proof required by the generation-bound path. Lane T owns that
binding API; acceptance of separate XDP artifacts cannot close that gap.

## Compact-path removal and first QEMU load

The compact interpreter has been deleted, including its step table, fuel
limit, unknown-PC exit, and zero-return completion. App generation now uses
the same instruction-by-instruction label renderer as micro generation. The
first BCC artifact (`biosnoop.blk_account_io_merge_bio`) now compiles and loads
in full-system AArch64 QEMU. Its [raw loader output](label-pilot/verify/bcc_biosnoop_blk_account_io_merge_bio.stdout)
and [table](label-pilot/table.md) record **1/1 diagnostic XDP acceptance**.
The map/ABI/helper caveats above still apply; no app workload ran in this check.

Reproduce the isolated diagnostic using the result-local Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=label-pilot
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=label-pilot
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile summarize PHASE=label-pilot
```

The load harness packages an existing AArch64 BusyBox/libc initramfs, the
AArch64 reversesim loader, and compiled artifacts into image layers, exposing
only the result directory to the guest. It uses two vCPUs, 2 GiB RAM, host CPUs
16-19, the framework AArch64 `Image`, and QEMU TCG (`-cpu max`). It does not
rebuild a shared kernel, module, or runtime image. `BASE_INITRAMFS` and `KERNEL`
can be supplied to the Makefile. The default base is a local supervisor
artifact named explicitly in that Makefile, not an application runtime image.
Each completed compiler/loader attempt has its own raw record; rerunning
compilation reuses completed outcomes. The compiler deadline is 120 seconds
per case and loader deadline is 60 seconds. Failures stay in the table.

Validation: Python syntax checks, the BCC generation/compile regression, and
the QEMU load all passed. The concurrent shared formal check currently fails
in lane V's layout migration at `KProgFormal.CrossIsaRev`: duplicate
`GeneratedArm64Width.Width.enumToBitVec` imports. No formal file was changed
by this compact-removal increment; lane V is resolving the migration.

## Uninitialized-stack diagnostic

Lane F's negative suite accepts `ldur x0, [sp, #-8]; ret` with the production
simulator, whose backing stack is zero-initialized. A snapshot-only experiment
removed that initialization and made the backing union volatile. The resulting
BPF is exactly an uninitialized `r10 - 8` read followed by `exit`; QEMU still
accepted it. [Compiled instructions](uninitialized-stack-fix/compiled-bpf.asm)
and [verifier log](uninitialized-stack-fix/verify/uninitialized_stack.verifier.log)
retain the evidence. This experiment does **not** close the negative failure.
No production stack change was made by lane A.

The framework kernel's `include/linux/bpf.h:bpf_allow_uninit_stack` permits
uninitialized stack reads for `CAP_PERFMON` callers, and `verifier.c` assigns
that premise to `env->allow_uninit_stack`. The root guest uses that privileged
verifier contract. Removing simulator initialization alone cannot establish
the stricter negative-suite property. F owns the production stack correction;
this additional verifier premise was reported to F/T in coordination.

## Subsequent checkpoints

The label-rendered census also completed all 1,136 inputs: 1,090 generated and
46 Tetragon helper-identification failures. Extending the shared helper table
with IDs 36, 58, 109, 130 and 181 makes **all 46 failures generate**, as recorded
in [helper-ids/](helper-ids/). Together the two label-rendered checkpoints cover
all 1,136 staged inputs at generation. This closes the observed missing-helper
identification failures, not callback semantics, map/ABI fidelity, verification,
or application execution. The new macros call the actual helpers; their ABI
oracle checks distinct argument lanes, pointer order, u32 narrowing and negative
return values.

The [label-all table](label-all/table.md) and [per-artifact CSV](label-all/coverage.csv)
record compile/load outcomes including pending work. The first 29 completed
BCC load checks yielded 9 acceptances, 15 verifier rejections and 5 load
preparation failures. Cilium also has a diagnostic acceptance. Most large
compiles have reached the 120-second diagnostic deadline under concurrent
lane work; they remain timeout errors, not claims of unsupported instructions.
The initial compile invocation enumerated only 326 generated inputs while
generation was still running; rerun `compile PHASE=label-all` after it exits to
cover the rest. Compiler and verifier outcomes checkpoint independently.

[Manifest pairing](inventory/pairing.csv) covers all 497 manifest entries:
466 pair uniquely and 31 have ambiguous truncated names; no entry lacks a
candidate after applying both native-loader filename conventions. These
remain manifest entries, not a measured startup inventory. Do not resolve an
ambiguous program by choosing an arbitrary candidate.

The portable diagnostic kernel/initramfs is built and its standalone Makefile
has passed QEMU TCG locally. [DGX-SPARK.md](DGX-SPARK.md) gives the concrete
transfer and hardware replay commands and distinguishes them from the still
unavailable six-app generation-bound workload command.

Helper validation: `helper-contract-check` passed the affected Lean theorem,
generated-file freshness, the vendored libbpf ID check, 74 identity-table cases
and 84 helper-call/ABI cases. The full `make -C kprog/formal check` retry
stopped at a concurrently changed x86 CMOV route oracle (96,848 failures),
before the Arm helper tests; its complete log is retained under `helper-ids/`.
The first requested Arm negative + 29-case build completed nine positive
compiles before A interrupted it to avoid a second lane writing the shared
output directory. A restarted with isolated output paths and `--no-generate`;
that build is still running. The retained progress log is a checkpoint, not a
completed pass. Both invocations and the collision are recorded in coordination. No new helper macro is substituted with a zero return.

The missing-helper retry compile/load batch has now completed: **46 generated,
11 compiled, 35 compiler timeouts; all 11 compiled artifacts were rejected by
the diagnostic XDP verifier**. Their helper calls are now visible instead of
being unidentified during generation. Full raw compiler and verifier logs and
the [updated table](helper-ids/table.md) are retained. They require the actual
application program types/contexts and map bindings for an app-path result.

To resume the existing census without replacing completed records:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=label-all
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=label-all
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile summarize PHASE=label-all
```

The result-local compiler also accepts disjoint index slices through
`COMPILE_ARGS='start stop'` over successfully generated records. Active slices
116:152 cover Katran/OTel and 915:1090 cover Tracee, while the initial 326-case
queue advances through the earlier records. This changes scheduling only;
the full table includes every object and all unfinished cases. Completed
verifier records are reused with their original raw logs and failure status.

The next QEMU checkpoint adds diagnostic load outcomes from Katran, OTel and
Tracee as well as BCC/Cilium. Across `label-all` and `helper-ids`, each of the
six applications now has generated-artifact verifier outcomes; these still
are not startup/application coverage or bound execution. Rejection classes in
the CSVs are derived from the complete verifier logs, including unavailable
helpers for the XDP type, packet-end arithmetic, packet offsets, synthetic-map
member accesses, map-value bounds, register fills and 32-bit pointer arithmetic.

Scheduling checkpoint: the original compile queues were stopped with their
completed records retained, then restarted using per-artifact file locks.
This prevents two overlapping resume invocations from writing the same object
or JSON record simultaneously. The complete default queue and the Tracee tail
queue now share those locks; they retain and reuse every completed success or
failure. The earlier progress logs remain alongside the current logs.

Binding update, 07:54 UTC: T has now implemented optional simulator-object
lookup through the manifest C entrypoint (`simulator_object`,
`simulator_program`) and passed a helper-proof fixture. The original-map
fixture still mismatches (`0xCCCCCCCC` observed, `2` expected). The earlier
entrypoint description records the baseline; A app ABI/map generation, real
startup inventory, complete verifier closure, bound QEMU workloads and their
same-work counters remain unfinished. The portable archive is a diagnostic
artifact replay, not a six-app performance bundle.

Micro-build failure checkpoint, 07:58 UTC: the isolated rebuild reports
`bcc_runqlat_log2_histogram_bucket` compile failure, clang exit 135, after
1449.848 seconds. The existing driver emits a compact compiler error and
continues the remaining cases; see `helper-ids/micro-build-isolated-progress.log`.
The production stack header changed during that compile, so its cause has not
been isolated. No architecture-wide build success is claimed. This is separate
from the passing helper identity/ABI checks and the retained app artifact scan.

## Register representation and restart recovery

The corrected register-cell representation compiles all 29 unchanged micro
artifacts. In full-system QEMU, **28/29 original-input result checks pass**;
`trace_event_type_switch_dispatch` reaches the verifier limit of 1,000,001
processed instructions. Its full verifier rejection is retained in
[register-cells-v2/](register-cells-v2/table.md). The earlier candidate's
invalid-register write bug was caught by the existing host oracles and fixed
before promotion. The six register, writeback, operand, flag, select and helper
host oracles pass (6,401 / 6,401 / 21,688 / 1,152 / 192 / 84 cases).

Each register and tag remains the same named local. A single table of pointers
to those locals replaces repeated 31-arm accessor expansion. SP, XZR, absent
and invalid register behavior and the generated width selector are preserved.
No workload or native instruction was changed. Longer compiler retries and
loader deadlines are explicit command arguments; completed failures are kept.
Sources, original inputs, compiled objects and frozen simulator/contracts are
archived beside each table. These are simulator result checks on stock QEMU,
not generation-bound application workload counters.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile register-cell-host-check PHASE=register-cells-v2
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=register-cells-v2 COMPILE_ARGS='0 29 900'
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=register-cells-v2
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile summarize PHASE=register-cells-v2
```

After the container restart, completed records were reused. Interrupted guest
logs were preserved under `register-cells/verify/interrupted-0834/`; the two
900-second compiler retries both compile and pass their unchanged QEMU results
in `register-cells-long/`. Seven of eight resumed result checks pass in
`register-cells-runlong/`; the eighth is the same event-type verifier complexity
failure. The original 60-second deadlines remain in `register-cells/`.

## Real helper calls

The 71-helper ABI increment replaces every existing zero-return body and every
incorrect helper alias with an actual typed Linux helper call. It adds the five
missing IDs20/54/87/99/155 seen by CFG target analysis. Lean table identity,
unique names/increasing IDs, independent libbpf IDs,73 table checks and142
argument/result checks pass. Frozen sources and logs are retained under
[real-helper-abi/](real-helper-abi/README.md). The old delegate-rank checks are
removed with the incorrect aliases; exact helper identity is now checked for
every call. Callback handling, caller-clobber/entry definedness, actual context
projection and map pairing remain active integration defects, not accepted
cases. The fresh1136-artifact generation census exposes four further missing
ID86/88 sites, which lane A is repairing next.

## Complete source-generation census

**1,136/1,136 staged artifacts now generate** across the full typed-helper scan
and its repaired-site retry. The helper union is75 real Linux IDs, checked by
Lean, independent libbpf declarations,77 table tests and150 argument/result
cases. [The full census](complete/table.md) links each artifact to its actual
attempt directory through [coverage.csv](complete/coverage.csv); attempts.jsonl
retains both original and repaired generation attempts. The original1136
entries remain present. [Helper validation](real-helper-abi-complete/README.md)
contains the exact frozen inputs and raw logs.

Compilation is continuing from checkpoints. Four repaired large artifacts
reached900-second compiler deadlines; those failures remain visible. A
mechanical constant-op dispatcher is being validated to reduce C front-end
expansion, while preserving the canonical C bodies. This table is not an
inventory of real application startup, verifier completion, bound execution or
same-work workload counters. Those parts of lane A remain active.

## Event-dispatch verifier failure closed

The unchanged `trace_event_type_switch_dispatch` native artifact and original
input now pass the full-system QEMU result check: retval2 and result16.
[compare-gt/](compare-gt/table.md) retains the accepted proof and verifier log;
`register-cells-v2/` retains its earlier1M-instruction rejection. Together with
the preceding28 unchanged-input passes, this closes that29-case functional
batch. A fresh full29-case run with the mechanically specialized dispatcher is
also running.

The fix composes adjacent `CMP; B.GT` only when no other control-flow edge
enters between them. It still computes every NZCV flag with the existing SUB
contract, and exposes the equivalent signed comparison directly to clang and
the verifier. Two Lean theorems prove the32/64-bit equivalence for all operand
bits;8648 C checks compare the old/new branch, all flags and unchanged GPRs.
No native instruction, workload, input, loop bound or memory guard changes.
Both the normal compiler and a separately retained no-unroll trial pass; the
normal compiler result establishes this fix.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compare-cond-proof
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compare-cond-generate compare-cond-host compile PHASE=compare-gt COMPILE_ARGS='0 1 900'
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=compare-gt
```

## Constant-opcode expansion completed

The mechanical dispatcher now compiles all four repaired large artifacts that
previously exceeded the900-second limit: three Cilium functions and Tracee's
`lkm_seeker_modtree_loop`. [known-helper-complete/table.md](known-helper-complete/table.md)
keeps the exact compiler commands and original native artifacts. All29 original
micro inputs/goldens compile and pass full-system QEMU again in
[known-micro/table.md](known-micro/table.md), with raw verification logs archived.
The unchanged497-form native CPU matrix also matches508,928 states with zero
mismatches in `direct-dispatch-v3/differential/host.txt`.

`generate_sim_dispatch.py` runs the canonical C predicates to classify71 literal
opcodes into36 C arms (including the rejection arm), then copies those bodies.
It adds no Python instruction semantics. The formal check verifies generated
source identity. These are compiler/functional checks, not app startup counts,
generation-bound application execution or throughput measurements.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile direct-header-check
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile generate-micro-cases PHASE=known-micro-source
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile specialize-constant-dispatch PHASE=known-micro SOURCE_PHASE=known-micro-source
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile verify summarize PHASE=known-micro COMPILE_ARGS='0 29 900'
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile direct-differential PHASE=direct-dispatch-v3
```

Use fresh phase names for new attempts; the committed archives preserve this
run's source/header versions and outputs. Entry/clobber definedness, native
stack-address observations, modified unary operations and real app integration
are active repair work, and no accepted negative case is waived by these results.

## Shifted unary producer bug closed

`MVN` and `NEG` previously discarded trailing source modifiers. The producer
now carries the actual modifier in AUX, and the canonical dispatcher applies
its existing typed modifier contract before the existing unary contract. The
old unshifted host API is preserved. Real assembled W/X variants at shift0,
1,3,31 and X32/63, including MVN ROR, match every register, NZCV and V0 over
70forms and71,680 native CPU states, zero mismatches. The original native
encodings, full-state driver, exact source/header snapshot and static replay
binary are archived in `unary-shifts/replay.tar.gz`; raw per-form counts are in
`unary-shifts/differential/forms.tsv`. No unsafe native case is executed.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile direct-header-generate unary-check unary-artifacts PHASE=unary-shifts
```

## Bounded indirect control and real LR restored

The generator joins finite target definitions over the actual CFG, invalidates
stale/caller-clobbered targets, and emits runtime target switches for BR/BLR.
Each RET reads its actual operand (including restored X30), with per-site legal
continuations. Separate CODE and outer RETURN tags prevent scalar zero or a
matching scalar offset from impersonating a return address. A CMP-derived fact
requires every incoming edge to execute that CMP.

[bounded-return-v2/table.md](bounded-return-v2/table.md) records four native-matched
full-system QEMU passes: both BR alternatives and both nested BLR/saved-LR
alternatives return2 and write41/42, exactly as the unchanged native fixtures.
Six CFG join/stale/clobber/narrowing/bypass regressions,4470 scene checks and13
CALL/RET cases pass. [The omitted reachable target](bounded-return-negative/table.md)
and [two scalar return forgeries](return-forgery/table.md) are rejected by the
verifier. Their unsafe native objects are never executed. Reachable unknown-PC
defaults contain an invalid-helper instruction, so they cannot occur in any
accepted verifier program; they introduce no native guard, trap, fuel or
assumption about which branch executes. All sources and raw logs are retained.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile bounded-check control-host-check compile verify summarize PHASE=bounded-return-v2 COMPILE_ARGS='0 4 900'
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile bounded-negative-check PHASE=bounded-return-negative
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile return-negative-check PHASE=return-forgery
```

These checks establish control dispatch for the recorded fixtures. The native
absolute code/stack-address relation, every app's real entry context and
original map bindings still require integration and artifact TV; neither
logical offsets nor these tests establish that relation. This is active repair
work, with no exemption for a failing program or accepted negative.

## ABI state dependencies and remaining accepted findings

The constructor now distinguishes defined native input bits from unspecified
entry/call-clobbered GPRs, SIMD state and NZCV. It preserves blind private
callee saves, tracks partial W/MOVK/shift/bitfield/mask dependencies, joins
all CFG paths and separates local call contexts. Helpers use their real typed
parameter widths, invalidate caller-saved state, and check tail-call arguments.
Entry/local returns require balanced native SP. This analysis supplies no
initial values, runtime guard or new native instruction semantics.

All27 encoded effect regressions pass. All42 original micro/helper-map
programs still generate; the13 helper/map cases compile again. The29 micro C
sources are byte-identical to the fresh29/29 full-system QEMU passes in
[control-return-micro/table.md](control-return-micro/table.md). The source-identity
check is reproducible with `abi-positive-identity`.

The actual generation-bound load-only negative trial retains all17 current F
fixtures:9 verifier rejections,1 loader rejection,5 constructor rejections,
and **two accepted bugs**: absolute SP flags and entry-X30 address flags.
The three older undefined-entry/flags/helper-clobber acceptances are now
constructor rejections; the return-register overwrite is verifier-rejected.
No unsafe native fixture is executed. The two address observations require a
real native-base/entry-state relation and remain required repair work, not
accepted cases or exemptions. [Exact outcomes](abi-negative-final/outcomes.json),
[constructor/effect/positive artifacts](abi-constructor-artifacts.tar.gz) and
[paired kernel/initramfs/tools](abi-bound-runtime.tar.gz) retain the full trial.

The [immutable1136-artifact constructor census](defined-frozen/table.md) records
430 generated and706 rejected across all six apps, with no entry removed.
[Constructor, input and command archive](defined-frozen/constructor-inputs.tar.gz)
preserves its exact version independently of subsequent checker fixes.
Compilation of every generated entry is running. Many staged FUNC_LOCAL
subprograms need their true callers/entry state, and helper memory effects need
integration; these are actual failures to close. This remains an artifact
census, not the actual application startup inventory or a native TV certificate.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile abi-effect-check PHASE=abi-effects-tail
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile abi-negative-bound PHASE=abi-negative-final
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile abi-stage2-build PHASE=abi-stage2-final
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile generate-frozen PHASE=defined-frozen
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=defined-frozen COMPILE_ARGS='0 430 900'
```

The negative target exits nonzero while either accepted bug remains. For fresh
attempts use fresh phase names; the existing snapshots and outcomes stay intact.

## Real application QEMU runtime preflight

The ARM application runtime image and exported QEMU root are built, including
all six upstream applications and the current verified-runtime loader/shim.
The first attempt exposed missing `katran_transport.bpf.o`; building the
existing source fixed packaging. The next startup exposed old module symbol
versions; rebuilding all11 ARM modules against the paired kernel fixed it.
No module or program was skipped. The root Makefile also dropped
`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF` from QEMU's exported environment;
the whitelist now forwards it. The guest's actual `native_loader_mode` event
confirms that flag is saved for the native phase and cleared during baseline.

BCC/set then completed baseline startup with the actual upstream tools. Its
[raw startup inventory](runtime-preflight-2/startup-loads.csv) retains all74
completed BPF load attempts, including probes. All23 named loads other than
`libbpf_nametest` have a candidate in the existing native manifest; this name
match does not certify bytecode/native equivalence or current attachment.
[Exact load metadata](runtime-preflight-2/startup-loads.jsonl) retains PID/TID,
program ID/type, attach-BTF fields and every attempted load. The QEMU guest's
wall clock began in1970; host logs retain the actual2026UTC provenance.

The host container was OOM-killed at12:15UTC after baseline_start returned OK
and before workload measurement completed. This run supplies startup evidence,
not same-work counters or verified native application success.
[All preflight logs and interrupted result files](runtime-preflight-2/runtime-preflight.tar.gz)
are preserved, including both earlier failures. A recovery run is active from
the pinned kernel/module pair. App context/map/proof completion and both address
findings remain required work; nothing is waived by this preflight.

## MOV-to-SP destination fixed

The pointer-write path formerly ignored SP destinations, so a valid
`mov sp,x3` could silently drop a saved-SP restore. It now writes the SP cell.
The balanced native regression subtracts32, savesSP, adds16, restoresSP fromX3,
subtracts the saved address and restores the entry stack. Real AArch64 execution
returns0; the generated proof also verifies and returns0 under full-system
QEMU. [Raw verifier/run result](sp-write/table.md), exact source/header and
native fixtures are archived in `sp-write/`. This fixes the destination write;
the separate absoluteSP/LR address-state findings remain active.

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile sp-write-check compile verify summarize PHASE=sp-write COMPILE_ARGS='0 1 180 1 1024' KERNEL=/workspaces/repository/kprog/arm64/build/app-qemu-paired/Image
```

## Recovered real BCC baseline and native-start failure

The post-restart `qemu-verified-app APP=bcc/set` run completed the real upstream
BCC baseline with 23 resident programs. [Resident counters](bcc-baseline-recovery/resident-counters.csv)
retain each full BTF entry name, ID, type, run count, run time and code sizes.
The [app record](bcc-baseline-recovery/bcc__set.json) retains the unchanged two-second
stress-ng workload output. [The full raw run](bcc-baseline-recovery/raw-run.tar.gz)
includes both shim logs, BTF program/map inventories and translated/JIT bytecode;
[host console](bcc-baseline-recovery/host-console.log) records the authoritative
`PLATFORM=qemu ARCH=arm64 make corpus` invocation. Guest dates start at the Unix
epoch; this run happened on 2026-11-06 UTC and QEMU timing is functional only.

The app has `status: error`: native startup lacked generation-bound simulator
proofs in the packaged manifest, and opensnoop exited before registration. The
baseline counters are real; no post-native counters or same-work comparison was
produced. This completed run supplements the earlier interrupted startup census,
whose feature probes, retries and 74 load attempts remain intact. Capture again
with `make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile runtime-complete-capture PHASE=<new-directory>`.

## Complete ARM linker readonly extents

The real BCC load diagnostics exposed two linker defects: ARM proof emission
copied only 16 bytes of every readonly target and used the relocation addend
as its section offset, ignoring a named object's own offset. It now preserves
the complete named ELF object (or section), keeps the original relocation
addend, and reports malformed extents. This fixes the actual 32-byte
`sys_exit.zero` and 120-byte runqlat histogram initializer proofs: both changed
from verifier rejection for out-of-bounds map-update input to verifier acceptance.
These are selected-proof load diagnostics with original BPF sections/maps;
app startup and matching-work execution are separate observations.

[All 67 native-link Rust tests and the release build passed](readonly-link/check.log).
The focused regression includes 8/32/120-byte objects, a nonzero object base,
interior and section addends, and an invalid extent. [Replay inputs and raw
before/after verifier evidence](readonly-link/replay.tar.gz) preserve both
original native objects and old/new proof outputs. Run `make -f
corpus/results/kprog_arm64_app_coverage_20261106/Makefile native-link-check
native-link-build` to repeat the component checks.

## Real BCC entries, raw contexts and stack memory effects

All 23 resident BCC entries now generate and compile with their original BPF
sections, source map/DATASEC declarations, full BTF entry names and complete
native readonly extents. [Every selected-proof attempt](memory-extension/bcc-proof-attempts.csv)
and [the phase table](memory-extension/bcc-table.md) retain all 23 entries in
every phase. The final compact-tag diagnostic accepts 21 proofs; the other two
stop before verification because capable's source declaration has zero stack-map
capacity, which the real app sets at startup. There are zero verifier rejections
in that phase. These counts describe resident baseline entries; startup probes
and transient loads remain in the separate raw startup census.

The simulator now uses the real tracing context, preserves verifier pointer
typing on native 64-bit loads, sizes private arenas from reachable SP allocation,
and tracks opaque ABI bytes across helpers, libc copies and joins. Every partial
store invalidates all overlapped pointer tags. Memory helpers update tags using
actual arguments and lengths; string helpers forget pointer provenance without
claiming that untouched suffix bytes were initialized. Packed 64-bit tag-word
updates preserve verifier-known fields within the 512-byte BPF stack limit.
A branch-local empty assembly constraint prevents LLVM from speculating an
invalid stack-arena address for a kernel pointer. Restricted stack-pointer ORR
uses the proved 16-byte entry-alignment relation and retains its actual ORR bits.

Validation: 35 ABI assembly cases, 11,200 ASan/UBSan memory cases, 64 complete
store byte/tag cases, 150 typed helper cases, all 29 unchanged-input full-system
QEMU micro runs, 13 helper/map compilations, and the full 340-module formal gate
with both instruction wires and all retained C/Rust checks passed. Six forged
return proofs reject in load-only QEMU checks; unsafe native code never executes.
The [replay archive](memory-extension/replay.tar.gz) retains sources, snapshots,
objects and failed attempts, including the oversized full-width tag experiment.
[Validation logs](memory-extension/) retain the original failures and final checks.

The actual application comparison still has an error after its 23-program
baseline: generation-bound startup exposed map configuration, readonly binding
and tracing relocation failures. SP/initial-LR numeric-address findings also
remain active defects. This increment does not claim a complete native safety
certificate, successful BCC treatment, or matching work. The native binder and
numeric/reference representation fixes continue from these recorded failures.

## Interior readonly references on the bound native path

Kernel-mode ARM linking now includes the named object's own section offset.
The Python decoder also preserves relocation addends instead of stripping
`+0x...` from the symbol and losing the offset. [The checked fixture outcomes](readonly-interior-checked/outcomes.json)
cover bytes 7, 64 and 119 of a 120-byte object at section offset 16. Original
source, simulator and generation-bound native runs all return 98, 71 and 18,
respectively; every native run records a nonzero generation. Three simulator
mutants that erase the addend return 7 and fail the exact expected-result check.
All 67 linker tests pass, including checks against the emitted native ADR target;
the 29 zero-addend micro sources exactly match the full-QEMU-passed sources.

[Replay inputs, compiled artifacts and runtime](readonly-interior-checked/replay.tar.gz)
include the matched context-v2 kernel and initramfs. Extract into a new directory,
then run `make -C runtime run`; on an ARM KVM host, use
`make -C runtime run ACCEL=kvm CPU=host`. These are functional checks. The
[full build/run log](readonly-interior-checked/build-and-qemu.log) preserves the
exact commands and library/kernel pairing.

## Actual six-app startup census and matched runtime preparation

[The runtime phase table](runtime-context-v2/table.md) and
[app records](runtime-context-v2/app-outcomes.csv) describe completed attempts of
all six applications. [All 302 startup load attempts](runtime-context-v2/all-startup-loads.jsonl)
include 291 successful loads, two syscall failures and nine unfinished attempts;
feature probes and transient loads are retained. These load counts differ from
resident snapshots and measured BPF-counter rows. The original run archives,
shim logs, stdout/stderr, lifecycle records, bytecode and partial captures remain
in [runtime-context-v2/](runtime-context-v2/).

BCC recorded 23 baseline counter rows; OTel recorded 12. No native treatment
completed. Cilium/Katran stopped at missing veth support in the old image,
Tetragon lacked its alignment-check object, OTel's shim socket refused a request,
and Tracee reached the existing 1,800-second lifecycle timeout. The latter's
partial evidence was retained. These are failures to close, not exclusions.

The new lane-owned runtime uses the matched context-v2 Image/EFI image, full
stock module tree, all 11 ARM kinsn modules and the compatible source-context
loader. Tetragon's missing alignment checker is now built from unchanged
upstream source with its own compiler flags. The package lives under
`kprog/arm64/build/app-runtime-v2/`; its image is
`bpf-benchmark/runner-runtime:arm64-a-context-v2`. The BCC manifest carries all
23 exact source BTF selectors and simulator objects. The first real startup with
that package reached the native binder and exposed map-layout, readonly identity
and tracing relocation errors; its raw result is archived here. The subsequent
retry uses the compatible runtime-capacity library and the existing lifecycle
timeout knob, preserving the two-start workload and counter collection.

## Immutable BCC native/proof pairs

[The frozen-pairing result](bcc-frozen-pairing/README.md) retains all 23 regenerated
and compiled proofs with the exact copied native ELFs used to link them. The
runtime manifest now installs both halves from that phase, so later native-stage
changes cannot silently invalidate the pairing. Application binder failures
remain active; this result establishes pairing and compilation only.

## Exact readonly object identity

The ARM producer now emits one `.rodata.native.N` DATASEC per native object,
plus ignored ELF section `.native_lab.rodata` with version-1 JSON containing
the exact canonical native symbol, proof section, proof variable and whole
object size. Instruction interior addends remain separate. This prevents
multiple independently placed constants from sharing one affine map binding.

[The metadata checks](readonly-object-metadata/checks.json) inspect all 23 real
BCC proof ELFs and a compiled fixture with two identical 120-byte constants
at distinct canonical identities. Every private map has one complete variable
at offset zero and exactly one metadata record. All 23 programs regenerate
and compile; all 35 ABI cases pass. [Replay inputs and compiled artifacts](readonly-object-metadata/replay.tar.gz)
retain the actual pairs, sources, objects and logs. The loader's consumption of
this exact metadata and native layout is the next binding integration step;
these producer checks alone do not establish application execution.

## Complete scalar FMOV register bank

The four scalar FMOV directions now select the actual V0–V31 register through
SRC2; the previous decoder accepted nonzero operands while the C handler
always accessed V0. The C state retains every 128-bit vector independently.
Scalar vector writes clear their upper lanes, and ABI analysis tracks all
32 cells separately, including helper clobbers and undefined cross-bank reads.

[Three QEMU comparisons](fmov-bank-checked/outcomes.json) each write and read
all 32 cells. Source BPF, simulator proof and generation-bound native code agree
on 137438954000, 528 and 528 with return value 2 and generation 1. The initial
fixture omitted its packet bounds check and correctly failed verification;
that raw attempt is retained. The repaired native fixture includes its real
packet bounds check. No proof-only packet constraint was added.

All 29 original micro programs compile and pass full-system QEMU. The 163 ABI
cases and 1,024 sanitizer value/state checks pass. Lane V's full 342-module
formal/C/Rust/wire check passes with its independent 32-bank reference and
expanded existing FMOV oracle; its original V0 theorems and cases remain.
[The replay archive](fmov-bank-checked/replay.tar.gz) includes both attempts,
compiled artifacts, frozen simulator headers, logs and a portable matched
kernel/initramfs under `runtime/`. Run `make -C runtime run` after extraction;
on DGX Spark use `make -C runtime run ACCEL=kvm CPU=host`.

## Cilium runtime native compiler architecture

The actual matched ARM guest started Cilium's baseline, then native proof
linking failed on `tail_drop_notify` saving X28. Its runtime compiler had
hardcoded the x86 architecture define and omitted ARM's reserved-register
flags. It now uses the actual compiler host architecture, the same ARM target
and X18/X26–X28 reservations as the static native backend, and matching
architecture defines in both preprocessing audits. BPF source/configuration
and workload are unchanged.

All 13 Python tests pass, including both host architectures and all three
compiler/preprocessor paths. [Replaying the captured failing configuration](cilium-native-arch/link-results.json)
compiles an AArch64 ELF and links all eight native functions, including
`tail_drop_notify`. [The captured inputs and rebuilt objects](cilium-native-arch/replay.tar.gz)
retain the exact configuration headers, unchanged native ABI overlay, compiler
arguments, every link outcome and unit-test log. The next application retry
uses this compiler repair together with the readonly binder integration.

## Completed matched-runtime census and first BCC native replacements

[The next actual six-app table](runtime-context-v3/table.md) records 239 raw
baseline counter rows: BCC 23, Cilium 53, OTel 12 and Tracee 151. Every row is
retained in [resident-counters.csv](runtime-context-v3/resident-counters.csv).
The [614 startup attempts](runtime-context-v3/all-startup-loads.jsonl) retain
577 successful loads, 28 failures and nine unfinished loads, including feature
probes and transients. [Nine BCC native replacements](runtime-context-v3/native-replacements.jsonl)
are recorded before startup stops. No native workload measurement completed.

Canonical DATASEC matching fixes vfsstat's real `.bss` and original readonly
configuration map reuse. The remaining BCC failures are private readonly object
identity and the stack-trace map's application-configured value size (declared
zero, actual 1016). Exact readonly identity integration and zero-size adoption
are the next loader revision. The full raw run archives preserve every attempt.

Cilium's captured native compiler failure is repaired above. All 94 Tetragon
upstream ARM BPF objects are now built and installed using unchanged upstream
source and flags, closing the missing-object packaging errors. Katran's
`EINVAL` comes from pinning NAPI threads to guest CPUs 5/6 with only two vCPUs;
the recipe now exposes the existing CPU knob with eight vCPUs by default.
Separate runtime directories keep an older guest's kernel, libraries and root
filesystem intact while the next revision is built.

The latest built runtime is `app-runtime-v3` with matched frozen context-v2
kernel/modules and DATASEC loader revision `15b253cb4`; its exact build and
run logs are retained here. Full end-to-end native results are still being
repaired and measured; these startup records do not establish matching work.

## Native proof ELF pairing at the loader lookup boundary

The actual readonly binder caught an additional packaging defect: the runtime
stage retained an inherited native `.proof.o`, even after the raw native ELF
and simulator artifact were updated. The loader implicitly selected that stale
file. BCC pairing now records the exact generated native proof ELF and installs
it at the loader's first lookup candidate, `<object>.<symbol>.proof.o`.

[All 23 ELF checks](bcc-native-proof-pairing/checks.json) compare staged text,
readonly bytes and ABI sections against the exact native proof used to generate
the simulator. Every comparison passes, and all 23 simulator objects compile.
[The readonly extent records](bcc-native-proof-pairing/readonly-extents.json)
retain inherited and correctly paired SYS_EXIT/RUNQLAT extents.
[The replay archive](bcc-native-proof-pairing/replay.tar.gz) includes native,
native-proof and simulator artifacts together. Runtime binder checks remain
strict; the following startup retry uses the complete matched triple.

## Native finite helper dispatch and complete CFG joins

ARM native linking now propagates all known helper IDs through the CFG, joins
both incoming paths, preserves register copies and conditional selections,
and kills facts on writes and call clobbers. A known ID on one path no longer
licenses a call reached through an unknown map-load path. The old regression
that accepted that case now requires rejection. Finite multi-helper calls
emit real native comparison/call arms with a common continuation, matching
the simulator's verifier-visible dispatch. There is no native runtime guard.

Helper-ID loads used as arguments or held in callee-saved registers remain.
The initial real native test exposed a dropped X24 assignment; its wrong
packet value and full logs are retained alongside the repaired result.
[Three final bound QEMU comparisons](helper-dispatch-result/outcomes.json)
produce matching 0/1/15 results with return value 2 and generation 1. The
joined dispatch pre-seeds the helper register with the alternate ID so a
removed assignment cannot pass by chance. A proof that omits helper14 rejects
both standalone and through actual generation-bound loading, without executing
the invalid candidate. All 69 Rust tests and both release builds pass.

[The replay archive](helper-dispatch-result/replay.tar.gz) retains all attempts,
compiled inputs, exact outcomes and a matched portable kernel/initramfs under
`runtime/`. Run `make -C runtime run` after extraction, or on Spark use
`make -C runtime run ACCEL=kvm CPU=host`. Finite local CODE branches/calls and
actual native address projection remain active integration work.

## Exact architectural memory access width

The ARM load/store byte-value generators now emit one actual BPF access of
the native instruction's width, instead of splitting it into byte accesses.
Volatile BPF inline assembly fixes the requested width; host-only aliases use
`aligned(1),may_alias`, so valid unaligned native addresses do not cause C
alignment undefined behavior. Lean value APIs and existing value oracles remain
unchanged. No bounds guard or event normalization is added.

[All eight compiled access fixtures](memory-width-result/bpf-accesses.json)
contain exactly one requested 1/2/4/8-byte load or store at pointer+3. The 1,024
unaligned ASan/UBSan cases and both 20,024-case existing load/store oracles pass.
All 29 unchanged-input micro cases pass full-system QEMU; all 23 real BCC
proofs recompile. [The full 345-module formal/C/Rust/wire check](memory-width-result/full-check.log)
passes with these generated outputs. [Replay artifacts](memory-width-result/replay.tar.gz)
retain sources, complete simulator snapshots, compiled BPF and raw outcomes.
This closes the scalar access-width bridge finding; CPU-feature-dependent
pair atomicity and complete per-application certificates continue as active
implementation and validation work.

## Eight-vCPU runtime retry: Tetragon and Katran baseline counters

[The recovered runtime-v4 census](runtime-context-v4/README.md) retains 23 BCC,
287 Tetragon and one Katran baseline program-counter rows. All 480 startup
attempts and ten native replacements are recorded. Eight guest CPUs close
Katran's CPU-affinity startup error; installing all upstream ARM objects lets
Tetragon reach its baseline workload. Native startup still exposes the exact
artifact/stub failures recorded there, with no native workload counter rows.
The BCC payload archive captures the stale proof lookup fixed by aefcd9c71;
its manifest is extracted from that payload. The next run uses the repaired
triple pairing and strict all-probe generation-bound startup artifacts.

## Typed helpers for actual startup programs

[The startup-helper increment](startup-helper-checked/README.md) adds real
coarse-time and function-IP calls (IDs160/173), preserving all75 existing
helpers. The154 ABI cases,79 identity cases and unchanged full345-module
formal/C/Rust/wire retry pass. All six captured ARM startup pairs compile;
the separate loader startup failure remains under active repair.

## Preserve entry ABI and indexed frame allocation

[The ARM entry-ABI repair](entry-abi-result/README.md) honors the existing
preserve-entry option and keeps SP writeback when stripping paired saves,
including tail-call cleanup. All71 Rust cases and both release builds pass.
Two source/simulator/bound QEMU cases retain a real helper call and a local
slot in an indexed32-byte frame; both produce37, return2 and generation1.
The exact native proof is packaged with each paired simulator. Portable
kernel/initrd replay and Spark KVM commands are included in its archive.

## Strict application startup on ARM

[The common libbpf startup now passes](startup-bound-result/README.md): all six
loads are replaced on the generation-bound path for both original flags0/8,
with main return127 and generation1. ARM helper tail relocations and transitive
resolved tail-branch callees are preserved. Both additional subprogram controls
produce37, return2 and generation1; all73 Rust tests pass. Earlier failed
attempts, including the nested native crash, are retained in the matched
portable replay archive. No probe/name bypass is used. The five startup
selectors and complete artifact triples are installed in each app manifest
for the next strict corpus run.

## Retained replays after runtime cleanup

[Cilium replay now uses its committed input archive](retained-replay-check/README.md)
and again compiles AArch64 plus all eight native functions after the oldv2
runtime was removed. Lane-A superseded runtime/proof-build cleanup inventories
are recorded there; all raw results and portable result archives remain.
Only the currentv5 application runtime root/image are retained for execution.
