# Resumed frozen ARM artifact census

The pre-migration compilation queue completed, and all369 compiled artifacts
were submitted to the existing full-system QEMU load harness. The table keeps
all1136 staged artifacts, including706 generator failures and61 compilation
failures. Results are43 verifier accepted,300 verifier rejected and26 loader
failures. No program or failure is removed from the denominator.

The61 compiler failures are60 LLVM out-of-memory exits under the recorded
per-command address-space cap and one900-second compile timeout. These are
resource failures, not an unsupported-program declaration; their exact
commands/source/compiler diagnostics remain in compilation-logs.tar.gz.

This is the historical defined-frozen source/header checkpoint, with the
harness XDP ABI. It is not the current real-application ABI/map integration
and does not imply bound execution or application completion. The snapshot
predates subsequent context/source-map/numeric-state repairs. Current actual
application results and the new six-app runtime are recorded separately.

The table and per-artifact CSV give counts and failure classes; raw generation
records, constructor inputs, generated sources, compiled objects, compiler
logs, verifier logs and simulator snapshot are retained in the adjacent
archives. The original interrupted compile log and final recovery log are
preserved in the lane state; the completed recovery log is included here.
