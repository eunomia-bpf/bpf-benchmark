# Native numeric-context bridge fidelity

The private NUMERIC primitive preserves its input bits while dropping pointer
provenance (`native_lab_input.h:33`). The shared SKB reader uses it for narrow
reads of packet-pointer fields (`x86_sim_local_bpf.h:1396`). CompCert's view
also preserves the pointer bits.

The stock proof header instead discards the supplied value and reads the
ordinary unspecified-input map. That is a conservative proof abstraction,
but the native compiler reuses that frontend and turns the map read into
`freeze poison`. The original value may already be gone. This component
regression checks the concrete native result, including the narrow-lane
operation, rather than assuming a proof-only abstraction preserves it.

Use the actual stock wrapper, sole compile-sim-ir and native O3 code. Six
plain-value controls catch host-call ABI mistakes; 24 numeric cases compare
real native execution with the documented bit-preserving operation. The
Make assertion fails on a real mismatch and retains all rows/IR/commands.
It does not load a BPF program or change a benchmark, production input,
compiler, header, module or image. No effect on any corpus app is inferred.

The detached recipe holds timing SH/image SH, CPU18 and a 4 GiB address-space
bound. It waits behind the active image/check/timing batch. At preparation
time the suspected mismatch has not been executed or confirmed.

Worker400746 was queued at2026-11-19T12:46:11Z from committed recipe
2a716ab6d. Raw:
`/workspaces/kprog-raw/perf/numeric-context-bridge-20261119/reproduce-20261119T124611Z-400746`.
Launcher: `/workspaces/kprog-raw/perf/numeric-context-bridge-launch-20261119.log`.
It is waiting for timing SH; no compilation/execution result yet. A setup or
compiler failure must be distinguished from the final bit-preservation
assertion, whose `result.json` records actual executed rows.

PERF 2026-11-19T13:00:39Z: The component worker completed at 12:52:08Z. All five
compiler/disassembly steps succeeded and all six plain ABI controls passed.
Actual native execution produced 16 mismatches among 24 numeric cases; the
Make exit is 2 from the final bit-preservation assertion, not a setup or
compiler failure. `result.json` contains every executed row. For example,
NUMERIC(0x123456789abcdef0) returned zero rather than its argument, and lane 4
returned zero rather than 0x12345678.

The retained optimized.ll:7-22 returns the input in plain_value and constant
zero in both numeric functions. The causal boundary is
`kprog/stock-path/include/stock_native_input.h:22`, which discards the input,
followed by `kprog/x86/compile_sim_ir.cpp:125-142`, which freezes the
unspecified-input read. This confirms the native concrete-bit loss in this
component; it does not establish a corpus path hit, B verification failure,
or effect on a measured speed ratio. The shared SKB reader's narrow packet
pointer conversion at x86_sim_local_bpf.h:1396 is the identified caller.

The phase-1 fix must preserve the concrete operand until native lowering
while keeping B's conservative scalar abstraction. Truly unspecified inputs
remain a separate case. No production compiler/header/loader change is made
during batch369379. Its immutable image/check/timing inputs stay in place.
