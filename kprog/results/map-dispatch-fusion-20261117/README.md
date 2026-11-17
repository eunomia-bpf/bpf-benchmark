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
