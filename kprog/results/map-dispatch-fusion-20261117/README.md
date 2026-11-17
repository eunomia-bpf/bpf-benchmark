# ARRAY/LPM dispatcher fusion

The smallest change is to reuse the existing ARRAY prefix and LPM body in one
shared lookup wrapper. It removes one internal aligned CALL frame; the final
generic helper keeps the external E8 ABI. Live type/bounds/key/map/RCU semantics,
ARRAY-only and LPM-only facts, proof mode, and benchmark settings stay as before.
No new runtime check, switch, helper catalogue or dispatcher framework.

The preceding retained-fragment ABI preflight is recorded in
../map-dispatch-review-20261117 (370eea291, b50200fbd). It passes 6,832 functional
cases, with 307 -> 293 fragment bytes and 16 B less generic callback stack.
Those are host fragment facts, not production or installed/time measurements.

This committed one-shot recipe waits for dead-ID build/replay job 2760806 and
publisher 2765360 before touching Rust source, then obtains timing SH/image EX.
The focused regression runs before the fix, through the actual object rewriter,
and checks nested call count plus CALL/JMP results, absent layout facts, original
arguments, one generic callback and stack alignment. After the fix, the full
unit subset, unrelated payload comparison and all 295 captured requests run.
Canonical main replacement is under image EX. No second build/source tree,
image publication or guest is created. Preserve executing scripts and all raw.

Run with setsid/nohup: `bash kprog/results/map-dispatch-fusion-20261117/run-host.sh`.
Raw parent: `/workspaces/kprog-raw/perf/map-dispatch-fusion-20261117`.
Production source and measurements are pending until the run actually finishes.
Omp owns image/check/affected-app timing with all LTO on. Report installed bytes,
per-call body/helpers/maps and throughput there; this recipe supplies no timing.

## Active unit-entry recipe, 2026-11-17

The exclusive-main-build queue was replaced after99a3a5e72 established the same
production link(Args) entry in the existing unit executable. At22:37:29-30Z,
only our waiting processes2760806/2765360/2776222/2776223/2782317/2782318 ended143,
via their exact waiting tail/flock children, in reverse dependency order.
All their raw directories remain; fusion/tail had applied no source. Checked
Tracee2754970 continues with the original canonical CLI. The historical recipe
above describes that stopped attempt; this paragraph describes the active one.

Current run-host.sh uses timingSH/imageSH, preserves CLI size/mtime, executes
the baseline/fix/full suite and source commit/push, then builds only the normal
unit executable and invokes production link(Args) with all295 captured requests.
The actual preceding dead-ID baseline is the successful unit replay at
/workspaces/kprog-raw/perf/link-entry-replay-20261117/host-20261117T223029Z-2788020/replay/replay.json.
No canonical CLI build is claimed: source/build receipts are named unit/test,
and the frozen image recipe will build the sole canonical CLI later under
imageEX. Same BPF code path and original arguments, no facts synthesized,
extra product or benchmark change. Omp owns image/check/affected-app timing.

First active host2791985 ended101 at22:40:54Z; publisher2791986 ended1 because
no completed replay existed. Baseline compiled and failed as intended: three
CALLs versus expected two. Forward production fusion then passed58 existing
tests and CALL cases, but the new test rejected the legacy unshared numeric
JMP when both ARRAY/LPM layouts are absent (E9 vs incorrectly assumed E8).
The wrapper's final helper still uses E8; no production change is needed for
that synthetic no-wrapper shape. fix-test.py narrows the assertion and removes
an unused initial callback-count assignment. It introduces no runtime change.

resume-host.sh applies only that test correction to the already-fused source,
copies the actual initial baseline/failing-suite logs, and resumes full tests,
parity, source commit/push and unit replay. Do not run apply.py/run-host.sh again:
production fusion and the regression are already applied once. Failed raw stays
at host-20261117T223923Z-2791985. The test does not establish that the frozen
module accepts an external E9; it preserves existing facts-absent linker output.
Actual shared wrappers and their final relocation still require E8.
