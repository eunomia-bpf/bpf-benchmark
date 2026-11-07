# Lane F handoff to C, A and V

The operator's 2026-11-07 23:50 UTC lane consolidation transfers F's continuing
work to C, A and V. F's current item is published as
415e5fb2a2c4a2812c561043f47a5b74bad2f997. Its six result files match
the working tree and current HEAD; remote master includes that commit.
F's detached experiment and publication jobs are closed.

All project commands continue through the operator's bws.sh into
/workspaces/repository. Each published source epoch keeps its own native
inputs, simulator headers, binary hashes, canonical reference and raw diagnostics.
Universal simulator, specialization-token and link-transformation laws supply
the safety argument. Generic batch readers supply runtime observations.

## Priority 1: registered service and native resources

C takes x86-64 kernel-module/binding interfaces and A takes AArch64 interfaces.
The generic resource collector and Makefile are in
binding/entry-resource-batch/. From the repository root:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/binding/entry-resource-batch/Makefile replay
~~~

Latest result 415e5fb2a retains 609 matching host metadata queries and joins A's
741f96936 ARM registered-service control: one fresh generation, compilation,
binding and native execution, return 2, source ID 3 to native ID 8.
Kernel-owned native bytes, worker copy, service receipt and selected fixture
share SHA256 de7821296054060c79cf4ff821a0939b63e8b01b8efb75e8c5b68deb987dfe2c.
The scalar control has maps=[]; map-capability/lifetime observations are in
negative/inline-memory-batches/, published by F as 9ef2d9a63 and 8c977e3a3.
The resource batch pins 58 inputs and preserves the captured native-input bundle.

A owns the successor helper-guard module epoch and its portable transport/Katran
runtime queue. The retained scalar run uses module 0fd8117f; A's later guarded
module 8a57874a remains a separate build/runtime epoch. C and A record actual
closed runtime archives in their coverage tables.

## Priorities 2 and 3: application correctness and batch reconciliation

C and A take application-batch reconciliation in their respective coverage
tables. application-batches/collect.py is the existing shared archive reader;
README.md, summary.json, terminal-outcomes.tsv, failures.jsonl.gz and
resource-cmp-increment.json preserve its published observations.

F publication d6d5b037353a6b47a1863648265f0d6124ffca17 records 26 cohorts,
104 terminal requests, 100 generated sources, 98 compiled objects and 83 bound
replies, with 81 pinned artifacts. Whole-application phases, workload output
hashes, source/bound IDs and original diagnostics retain their separate scopes.
The earlier ARM OTel integration is 124a0b3b5.

The following newer producer publications are available for successor coverage
integration: A 1350ca763 ARM Tetragon and C 0e941d27e x86 OTel. Their owners
retain the actual original requests, application outcome and verifier statistics.
Current C/A application queues retain ownership of their captured inputs.

R retains timing ownership and same-work counters. The Timing requests section
of COORDINATION.md supplies the stage2, load-time and application commands.
BCC and Katran timing publications retain their own runtime/source epochs.

## Priority 4: differential fidelity, safety and universal interfaces

C takes x86-64 differential replays after simulator changes; A takes AArch64
replays and the static hardware handoff. The common harness is
kprog/fidelity/Makefile, generate.py, driver.c, reference_check.py and the
architecture-specific reference-path adapters. V owns the single canonical
reference for each ISA and the universal formal obligations.

| Receiver | Existing entry points and results | Continuing item |
| --- | --- | --- |
| C | differential/x86-production-current/Makefile; kprog/fidelity/x86_reference_path.py | Replay changed x86 semantics against the CPU, compiled simulator and V reference, with source and executable pins. |
| A | kprog/fidelity/Makefile; kprog/fidelity/run-arm64.sh; differential/arm64-current-core/; differential/arm64-contract-aliases/Makefile | Replay changed ARM semantics under QEMU and retain the static binary/hardware run handoff. |
| V | differential/replay-inputs/collect.py, inputs.json and replay-observations.tsv | Consume replay rows into kprog/results/kprog_verification_20261107/coverage.tsv, preserving taxonomy and formal statuses. |
| C and A | negative/x86-trusted-sp/Makefile; negative/arm64-trusted-sp/Makefile; negative/inline-memory-batches/collect.py | Maintain generic rejection suites at zero unsafe accepts and retain exact diagnostics for each source epoch. |
| A and V | negative/arm64-exclusive-convergence-review/; differential/arm64-current-bank32/exclusive/observed-projection/ | Join actual retry CFG/status observations with canonical exclusive-store, progress and termination interfaces. |

F's replay publication 92441b38ac8110766058094409f9758fa3cbd68c contains
16 source epochs, 222 operation/source rows and 163 pinned artifacts.
V's 518d33529 consumes the adopted ARM alias correspondence.

| Numeric token catalog | Sampled three-way | Explicit monitor | Pending replay |
| --- | ---: | ---: | ---: |
| x86, 75 tokens | 66 | 0 | 9 |
| AArch64, 71 tokens | 67 | 1 | 3 |

The remaining ARM tokens are ARM64_OP_ADRP_GOT, ARM64_OP_ADRP_RODATA and
ARM64_OP_RET, whose link/ABI domains remain explicit interfaces. The numeric
catalog and requested semantic-family taxonomy retain their separate meanings.
Pending x86 tokens are enumerated in differential/replay-inputs/numeric-token-input.tsv.

Latest full production x86 result 01ce447e
records 1,144 forms and 292,864 CPU/C/canonical cases, with zero differences.
Its initial command and saved-state control completion preserve their original
exit statuses and trace identities. The retained full raw trace and compressed
archive stay in the Workspace; published summaries identify their SHA256 values.

The ARM core handoff records 807 forms and 826,368 QEMU/C/canonical cases.
The adopted immediate-alias batch adds 60 groups and 61,440 cases across
ADD/SUB/AND/ORR/EOR, 32/64-bit widths and raw/direct routes.
Its production C/Python correspondence retains the original compiled epoch.
The exclusive-monitor observation keeps its explicit monitor premise.
Hardware ARM performance follows the operator's later scheduling.

## Retained helper/map, cost, TCB and scale evidence

helper-map/x86-trusted-service/Makefile and kprog/fidelity/stage2.py retain
the 13 standard helper/map correctness cases and return values.
helper-map/ contains the later common-service microbatch observations.

The 2026-11-06 load-time and scale results are in
kprog/results/kprog_fidelity_20261106/load-time/ and
kprog/results/kprog_fidelity_20261106/scale/. Their commands and source epochs
remain in their READMEs. kprog/fidelity/scale.py, scale_probe.c and
scale_native_probe.c supply the generic size-sweep mechanisms.
The 2026-11-07 TCB inventory is in tcb/, using kprog/fidelity/tcb.py.
Further component-cost attribution follows the operator's deferred priority 5.

## Retained state and closure

/workspaces/.agent-state/kprog-lanes/F/ retains last.md, publication receipts,
original closed logs and historical diagnostic exits. Exit files belong to their
named epochs. Published collectors and archives distinguish repaired successors
from initial diagnostics.

C/A/V continue from the existing Workspace, shared build caches and source
ownership. Papers, existing Workspace STOP, captured kernels/modules, shared
index and active C/A/V/R processes retain their current state.
The coordinator notice records the published handoff, then F creates its local
empty STOP file and exits its loop.
