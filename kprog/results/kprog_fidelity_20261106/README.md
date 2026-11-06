# Lane F fidelity and safety evidence

- `differential/README.md`: real x86 CPU matrix and counterexamples; static
  AArch64 harness delivered. Both Spark core types pass the width-fix matrix
  on hardware; both also pass the newer register-cell replay.
- `negative/README.md`: baseline findings and fresh bound-path sweeps on both
  ISAs; original14x86reject, but the15th stack-base flag case accepts on both
  ISAs. Arm also retains three ABI acceptances. These are open safety bugs.
  Exact diagnostics and repair ownership are retained.
- `helper-map/README.md`: all13 x86 cases pass bound execution; after immutable
  readonly-data binding repair, all13 Arm QEMU cases also pass exact results,
  return values and nonzero-generation checks. The earlier12/13 is retained.
- Generation-bound load time and helper/map timing: exact requests entered
  under "Timing requests" in `/workspaces/.agent-state/kprog-lanes/COORDINATION.md`
  for lane R, which owns timing.
- `tcb/README.md`: component line counts, including the simulator-proof
  preparation function and native-proof kernel patch in the recovery snapshot.

- `scale/README.md`: all16 native-size cells attempted;9 accepted/correct,
  3 compile deadlines and4 Clang source-location exhaustion failures.
