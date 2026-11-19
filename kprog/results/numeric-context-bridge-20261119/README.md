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

PERF 2026-11-19T13:13:49Z: Prepared the small forward repair in fix-forward.patch.
The stock macro carries a tied abstract scalar plus a concrete operand in an
assembly comment; B emits its ordinary unknown scalar and native lowering
selects the concrete operand. It adds no kernel operation, helper body,
mode or runtime check. The existing regression now also emits B and records
its disassembly, and six side-effect cases detect evaluating the operand
more than once. This B emission is not a stock-verifier acceptance claim.

run_fix.sh waits for batch EX, then timing SH and image EX before applying
the repair and rebuilding the sole checked tools through checked-sim-stage.
It retains the exact applied diff, build log and native/B component outputs.
It starts no image or guest. Production source is unchanged until those
leases are acquired; host results and the production commit remain pending.

PERF 2026-11-19T13:38:04Z: Native bit preservation is fixed in the production header
and compiler. The first applied candidate built and emitted B, but failed
21 of 30 numeric cases: Clang lowers +r as =r,r,0, putting the explicit
concrete input first. The initial converter selected the tied scalar. That
failed candidate and all rows remain in first-repair-result.json and raw
fix-20261119T131416Z-407693. The current patch selects operand zero and
records the operand-order reason in the compiler.

Canonical checked-sim-stage rebuilt the sole tools in place under timing
SH/image EX. Actual worker416559 finished successfully at13:37:02Z: all
30 numeric/lane/single-evaluation cases and six ABI controls pass. Stock B
emission succeeds: fixed-stock-disassembly.txt shows numeric_value returns
the ordinary unspecified-input scalar, while fixed-native.ll returns its
argument and numeric_once returns the old value with exactly one increment.
The assembly comment adds no B instruction, kernel operation or native
helper call. True unspecified/entry/exclusive cases are unchanged. This is
a component fidelity result, not a corpus path hit, stock-B load, per-call
gain or installed-byte measurement.

Successful raw: /workspaces/kprog-raw/perf/numeric-context-bridge-20261119/reproduce-20261119T133702Z-416559.
Rebuild log: /workspaces/kprog-raw/perf/numeric-context-bridge-20261119/rebuild-concrete-operand-20261119.log.
The sole image remains94484bec285d; subsequent checked app confirmation
follows the coordinator's queued Tracee batch, with all C/LTO pieces on.
