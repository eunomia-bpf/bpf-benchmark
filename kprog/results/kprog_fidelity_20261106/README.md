# Lane F fidelity and safety evidence

- `differential/README.md`: real x86 CPU matrix and counterexamples; static
  AArch64 harness delivered, with a QEMU-user execution smoke. Real Arm
  hardware execution belongs to the coordinator and remains pending.
- `negative/README.md`: 11 fixtures on each ISA, including an accepted Arm
  uninitialized-stack finding and exact diagnostics for every rejection.
- Generation-bound load time and helper/map timing: exact requests entered
  under "Timing requests" in `/workspaces/.agent-state/kprog-lanes/COORDINATION.md`
  for lane R, which owns timing.
- TCB component line counts: pending.
