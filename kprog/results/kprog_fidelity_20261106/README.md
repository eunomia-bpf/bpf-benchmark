# Lane F fidelity and safety evidence

- `differential/README.md`: real x86 CPU matrix and counterexamples; static
  AArch64 harness delivered, with a QEMU-user execution smoke. Real Arm
  hardware execution belongs to the coordinator and remains pending.
- `negative/README.md`: baseline findings and fresh bound-path sweeps on both
  ISAs; all 11 unsafe fixtures reject on each bound path, with exact diagnostics.
- `helper-map/README.md`: all 13 x86 stage2 cases pass bound native result/return-value checks.
- Generation-bound load time and helper/map timing: exact requests entered
  under "Timing requests" in `/workspaces/.agent-state/kprog-lanes/COORDINATION.md`
  for lane R, which owns timing.
- `tcb/README.md`: component line counts, including the simulator-proof
  preparation function and native-proof kernel patch in the recovery snapshot.
