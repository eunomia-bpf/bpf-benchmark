# OTel native unwind proof: compiler-order diagnosis

The exact v8 perf_unwind_native simulator C now produces an ELF BPF object
(4,967,000bytes), without native/source/ISA changes. Direct clang O2 and O1
both exhausted32GiB during SROA/PromoteMemToReg. Frontend IR is188MiB;
instcombine+simplifycfg before SROA completes in16GiB and leaves142MiB;
SROA+instcombine+simplifycfg then leaves55MiB. Standard default<O2> and the
unchanged BPF backend complete successfully. Every stage log/exit, exact
source/compiler inputs/object and all IR hashes are retained.

This establishes compilation, not verifier admission or OTel app success.
No simulator semantics or native instructions were changed. Huge intermediate
IR remains in the lane-owned rebuildable cache, reproducible from the source.
The archived commands use /workspaces/repository and the frozen v8 phase.

A fresh14-program v15 preclean compilation remains active. read_task_struct
completes all five stages; stop initially revealed LLVM18's one-iteration
instcombine fixpoint diagnostic. The corrected otel-stop-v16 compile now
completes **all five stages**, with explicit max-iterations=16 and standard
O2 in its own module invocation. Its exact record, source, frozen contracts
and compiled object are archived. No verifier or application claim follows
from this compile. The earlier failed diagnostic (incorrectly nesting module
O2 in a function-pass pipeline) is also preserved.

Reusable command (fresh phase with generated program rows):
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile-preclean
PHASE=NEW_PHASE COMPILE_ARGS='0 14 3600 1 16384'. It freezes the same simulator,
uses the same source, records every subprocess and propagates failures. Direct
clang O2 remains the existing compile action; there is no automatic retry or
silent pipeline change for cached records.

The reusable16-iteration compiler also completes both real BCC opensnoop
and tcplife proof objects (all five stages, exact inputs/records archived).
It does not fix their stack overflow: lowest direct frame offsets remain
-880 and-584 respectively. Those verifier failures remain open and require
a simulator-state/layout improvement, not a larger compiler stack allowance.
