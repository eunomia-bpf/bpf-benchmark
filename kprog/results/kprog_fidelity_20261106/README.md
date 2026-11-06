# Lane F fidelity and safety evidence

- `differential/README.md`: real x86 CPU matrix and counterexamples; static
  AArch64 harness delivered. Both Spark core types pass the width-fix matrix
  on hardware; both also pass the newer register-cell replay.
- `negative/README.md`: current17-case bound suites reject16 on x86 and15 on
  Arm. All11 original negatives reject on both; stack-base flags still accept
  on both, and Arm entry return-address flags also accept. These remain open
  safety bugs. Earlier ABI/return findings and their repairs stay recorded.
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

Latest replay: x86721forms/738304realCPUcases/zero; Arm563forms/576512QEMUcases/zero. Canonicalreference116x86forms/118784cases and300Armforms/307200cases agree, with605/263 missing-reference forms explicitly retained. Current75Arm controls retain1024SPflag mismatches. See differential/README.md for scope and static hardware handoffs.

Scale follow-up: the unchanged10036-instruction pointer-direct fixture now passes in a frozen experimental compiler/representation path (30055BPF instructions, result5015, retval2). Exactsourceandtracearchives are under scale/. Original production-header compile repair remains active; experimental headers are not promoted.
