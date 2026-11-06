# Arm scalar, pair and SIMD memory fidelity

The expanded production-encoder observer executes **255 forms ×256 states =
65280 QEMU cases**, with **zero CPU/simulator/reference differences** and no
unhandled canonical encoding. It covers scalar widths/sign extension, scaled
and unscaled loads/stores, pre/post writeback, UXTW/LSL/SXTW/SXTX register
addressing, zero/index/base aliases, D0/Q0 loads/stores, and W/X pair offset and
pre/post forms. It initializes and compares all31 GPRs, SP/NZCV, all32 distinct
vectors and the memory window. Bases/indexes are bounded for valid accesses;
remaining register, flag, vector and memory inputs include boundary/random data.
Rows are observer forms; aliases may share an encoding and counts from separate
matrices must not be added as distinct ISA coverage.

The preceding235-form run exposed **3328 differences on all13 LDR D0 rows**:
CPU clears V0[127:64], C preserved the old high word. The same saved inputs
compare with zero CPU/reference differences and3328 C/reference differences.
`../arm64-memory-matrix/` retains every counterexample. The fix adds the
architectural high-clear property to the generated D/Q contract and consumes
it in the production transfer handler after its one D lane read. Q loads still
load both lanes and stores preserve their source register. The intermediate
235-form repaired CPU run is retained in `../arm64-memory-matrix-fixed/`.

The permanent load-only negative in `../../negative/arm64-vector-clear/`
loads Q0(high1), then D0, stores Q0 and branches on the high word. Native D0
clears that word and reaches the NULL dereference; the old model falsely kept
it nonzero. The actual bound loader accepted it with generation1 before the
fix and now rejects `R1 invalid mem access 'scalar'`. Unsafe native code was
never executed.

The single canonical AArch64 reference now decodes these address modes and all
SIMD banks/widths, retaining old constructors/interfaces. It checks incoming SP
alignment, captures old base/index before alias writes, and commits pre/post
writeback only after a successful transfer. Pair faults preserve ordered first
access effects, including a committed first store before a second-store fault.
Constrained-unpredictable scalar/pair writeback overlap, reserved index modes
and reserved SIMD sizes reject precisely. Nonzero vector operands require an
explicit full input vector bank.

**Validation:**959 full-state/event/fault examples and18 precise rejections
pass, including all old Arm/exclusive wire cases. Generated modifier/packed
prepost offset/base-delta proofs and existing ordinary scalar/pair full-state
refinements compose with the new addressing steps. D/Q load-value lemmas match
the canonical128-bit memory value and D upper clearing. The displayed theorem
dependencies in `axioms.log.gz` are propext, Classical.choice, Lean.ofReduceBool
and Quot.sound; no new axiom declaration or admitted theorem is introduced.
These value/state results do not assert a compiled BPF memory-event projection
or an exclusive-monitor/ordering theorem.

The combined root `make check` passes **all359 Lean modules and all C/Rust/
encoding/wire checks** (V's check-x86-popcount-memory-full.log, exit0). Four old
DQ route models also incorrectly expected preservation; V repaired those exact
expected values without dropping their cases, and this commit includes that
handoff. Initial root check failure on the concurrent POPCNT arm checker and
private check failure on the stale singleton expectation remain in separate
logs; neither is called passing.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-memory-complete FAMILY=memory CASES=256 OUT=../results/kprog_fidelity_20261106/differential/arm64-memory-complete
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-memory-complete snapshot reference
# The preserved preceding235-form findings return1:
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-memory-complete before-reference
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-memory-complete axioms
taskset -c 8-15 prlimit --as=12884901888 -- make -C kprog/formal check
```

The last root command was run by V; F builds/observers used16–23. All actual
harness inputs, production header/import snapshots, generated C/native code and
static executable are in `harness-artifacts.tar.gz`. The canonical source/
executable are frozen in `canonical-source.tar.gz`/`reference.gz`; the private
source base was23f3c6931 with the documented canonical/exclusive/X86-path/memory
and DQ overlays. `full-check-source.tar.gz` separately retains the combined
root check source, including other lanes' then-uncommitted inputs, identified
by `source-provenance.txt`. Archiving them does not promote those code changes.
The generator script archived at publication includes later matrix extensions;
rebuild the archived generated C/assembly to reproduce an earlier row set.

The static hardware handoff is `../cpu-differential-arm64-memory-complete.gz`:
use it with ARM64_HANDOFF and the existing kprog/fidelity/run-arm64.sh. These
are functional QEMU results, not Arm hardware/performance measurements.
