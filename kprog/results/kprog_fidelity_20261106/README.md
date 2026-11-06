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

Actual-SP observer follow-up: x86733forms/750592cases retain11264 address-state differences; Arm567forms/580608cases retain4096. All earlier721/563forms still agree. Canonical CPU comparisons are zero for144x86/419Arm forms; rawmodeldifferences and missingreferenceencodings are retained. Arm77controls confirm MOVSP repair and realnonzeroSP capture while retaining1024SP-flag counterexamples. See differential/README.md.

Scale recovery follow-up: all four10K shapes now have accepted, correct
artifacts, with32/32 additional native-CPU/kernel-proof input pairs matching.
The first100K native fixture (100036 scalar/direct instructions) also passes,
with88BPF instructions after folding and eight more native/proof input pairs
matching. Verifier timing and allocation traces, all earlier failures, and the
experimental factoring path are documented in scale/README.md. LEA-to-RSP's
focused post-repair replay is31forms/31744cases with zero mismatches; the
remaining broader SP/address observations stay open.

Scale completion: all16 requested x86 size/shape cells now have accepted, correct artifacts, including allfour100K shapes. All32 additional100K nativeCPU/proof inputpairs match. Pointer/direct and pointer/indirect retain300054/300047BPF instructions and verify in90.264/133.029ms. Exact experimental compiler paths, earlier failures and separate allocation peaks remain in scale/README.md. The newer independent Arm replay checks523forms/535552cases against the sameCPUtrace, CPUdifferences0, modelSPdifferences4096, remainingdecoderforms44.

Latest complete x86 CPU replay after the LEA repair:733forms/750592cases,
723forms zero differences and ten SP-related rows with10240 raw differences.
Only the repaired LEA-to-RSP row changed from the preceding full run; all
remaining counterexample inputs are retained. See differential/README.md.

SP-alignment follow-up: the newly accepted Arm SP fault now rejects during
specialization; all40 real-encoding ABI regressions and all29 positive proof
builds pass, and three valid alignment controls remain bound-load accepted.
The18-case Arm suite retains only its two prior numeric-address accepts.
The full32-vector FMOV observer adds128forms/131072QEMUcases with zero
CPU/simulator/reference differences and a static hardware handoff.
