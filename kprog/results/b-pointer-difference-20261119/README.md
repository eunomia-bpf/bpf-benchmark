# Guarded pointer subtraction in B

PERF 2026-11-19T17:08:12Z: Fixture and normal-backend recipe139745020 follow the
retained Tracee failures in tracee-live-failures-20261119. Their frontend
and bounds IR retain a numeric stack-pointer subtraction inside its tag
branch; emitted B computes it before the tag test and stock rejects the
scalar path. This experiment first isolates that backend behavior.

The source saves either a stack pointer/tag4 or scalar bits/tag0 in volatile
locals, then reads them together. The subtraction is evaluated only in the
existing tag4 branch. This preserves the correlation the verifier can use
on each path. Native execution returns115 on the stack path and the original scalar bits
on the scalar path for16context combinations. No arena byte is read.

The test uses the production frontend flags, packet-bounds and actual
_compile_simulator_backend (including spill packing), and saves both LLVM
stages and B disassembly. Native compilation uses the pre-B frontend
through compile-sim-ir and O3. Host execution is not stock-B acceptance;
inspect the emitted control flow before calling the small case a B failure
reproduction. The retained application remains the actual rejection evidence.

Worker117270, queued17:06:13Z, raw
/workspaces/kprog-raw/perf/b-pointer-difference-20261119/test-20261119T170613Z-117270
waits timing SH / image SH, CPU19/4GiB, behind the coordinator's image build.
Launcher /workspaces/kprog-raw/perf/b-pointer-difference-launch-20261119.log.
At17:07:38Z only queued/run.log exist; no compile or execution result yet.
It starts no guest or image and changes no production input.

Next: inspect actual frontend/bounds/B/native results, then test an exact
B-only lowering that anchors pointer-difference arithmetic to its existing
branch. An equivalent side-effect BPF subtraction template is a candidate,
not implemented or proved. Native pre-B semantics, pointer capabilities
and all limits remain. Before changing frozen packet_bounds_ir.cpp, record
this separate defect class with exact evidence in freeze-open.tsv; its
previous constant-ALU32 scope is not this class. Coordinator owns memoryAsm
and helper cleanup, so those paths stay untouched.

- LANE PERF 2026-11-19T17:37:53Z: B pointer-difference candidate is limited to packet_bounds_ir.cpp: exact i64 subtraction of two ptrtoint operands becomes equivalent side-effect BPF subtraction in its original block. Native pre-B frontend and coordinator-owned files are untouched. Prepared only, not yet compiled or validated. Freeze exception6738e5efd cites actual Tracee27/30 mapping; evidence filename corrected forward. Regression bd6587ebe moves the native-base read before the branch and matches arena-start subtraction; baseline151259 waits timing SH then image SH on CPU19/4GiB, raw /workspaces/kprog-raw/perf/b-pointer-difference-20261119/test-20261119T173540Z-151259. The previous small fixture passed16native cases but did not reproduce hoisting. I restored timing SH after reading the later all-host-work instruction. No image, guest or current check input is changed.

PERF 2026-11-19T17:41:16Z: bd6587ebe baseline151259 completed0: all16native cases pass. Small B tag test13 precedes subtraction16; this fixture still does not reproduce the application hoist. Candidate4efe79d40 (+26production lines) is unvalidated. Committed validator7bd0ffea5, worker155130, raw /workspaces/kprog-raw/perf/b-pointer-difference-20261119/fix-20261119T174026Z-155130, holds batchEX and waits timingSH behind OMP checked Katran136061; next imageEX, sole packet-bounds rebuild, exact fixture/four IR boundaries, prior ALU32 controls and retained Tracee27 frontend-to-B replay. No repeated C frontend or guest. Current image/check results belong to the coordinator. I leave its files and staged producer changes intact.

PERF 2026-11-19T17:54:57Z: Worker155130 completed0 at17:41:44Z. The sole packet-bounds
compiler includes4efe79d40. All16native cases pass, exact i64 ptrtoint-pair
selection and three exclusion controls pass, and existing ALU32 four
constant/three preservation controls pass with B emission. Retained
Tracee27 frontend-to-B replay passes without repeating the C frontend.
Its mapped tag4 test is now PC966 and subtraction970, with the non-stack
branch skipping to975; previously subtraction959 preceded tag test962.
All15ptrtoint-pair differences in this request are anchored. The small
fixture still is not the original hoist reproduction. These are B
control-flow and host semantic results; stock acceptance remains to be
measured. fixed-result.json records commands and raw paths, and
fixed-tracee27-excerpt.txt contains the mapped disassembly.

PERF 2026-11-19T17:57:15Z: Confirmation worker186985 is detached and queued
on batch EX, then timing SH/image SH, behind the coordinator image/check.
Raw: /workspaces/kprog-raw/perf/b-pointer-difference-20261119/confirm-20261119T175715Z-186985.
c805cb4ec adds the stock fixture load/scalar TEST_RUN and retained30 backend
replay; abd9bea3e exposes the sole probe read-only inside virtme's fresh
temporary directory. No production input is changed. No guest or stock
result has run at this checkpoint. The fixture's scalar TEST_RUN uses the
kernel's default XDP context; the16native controls are separate evidence.
