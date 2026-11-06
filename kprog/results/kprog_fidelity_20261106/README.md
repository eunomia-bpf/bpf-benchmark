# Lane F fidelity and safety evidence

- `differential/README.md`: real x86 CPU matrix and counterexamples; static
  AArch64 harness delivered. Both Spark core types pass the width-fix matrix
  on hardware; both also pass the newer register-cell replay.
- `negative/README.md`: current bound suites reject16/17 on x86 and23/29 on
  Arm, including repaired SP alignment, LDP and writeback overlap. Four new
  exclusive-store failure branches are accepted safety findings. All11 original negatives
  reject on both; stack-base flags still accept
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

The canonical Arm memory/pair replay now checks543forms/556032cases on the
identical saved CPU inputs: zero CPU differences,4096 unchanged model SP/WSP
differences, and24 encoding forms still in the active canonical coverage queue.

Canonical bitfield closure adds70 full-bank boundary/alias forms and71680
QEMU/C/reference agreements, full formal check PASS. The original matrix now
checks553/567 forms (566272 cases), CPU differences0, model SP differences4096,
with14 memory encodings still active. Static bitfield hardware handoff included.

The instruction-family audit adds8 exclusive forms/8192QEMUcases:4096
STXR/STLXR mismatches after explicitCLREX (CPU failure/no-write versus model
success/write). Four corresponding unsafe bound-load failure branches are
accepted; exact counterexamples and all25 permanent Arm outcomes are retained.

Canonical exclusive semantics now cover reservation ranges, fresh failure
choices, conditional writes, faults and acquire/release effects. All 82 new
wire cases, 10 precise rejections and the full 352-module formal check pass.
See differential/arm64-exclusive/canonical/README.md; the four production
exclusive failure-branch safety findings remain active.

The expanded six-flag x86 replay covers 799 forms / 818176 hardware cases,
including every active CMOV/SET/Jcc condition and alias. The saved-state
canonical replay checks 452 forms / 462848 cases with zero CPU differences
and 10240 existing simulator stack-address differences; 347 forms remain
explicitly unhandled in this reference snapshot. Raw CPU replay has 11264
stack-address observations. Exact per-form inputs, commands and frozen source
are in differential/x86-full-conditions/README.md (or x86-full-conditions/
relative to this directory); the preceding 745-form result is retained.

Canonical x86 path closure:525 forms/537600 savedCPU cases now checked,
CPU differences0, model stack-address differences10240. The37 Jcc/JMP sequences
and36 unary forms newly agree in all cases;274 encodings remain explicit.
The checked finite-path interface validates real decode extents and every
successor, with2053 full-state/40 rejection cases and full formal check PASS.
See differential/x86-control-reference/README.md (x86-control-reference/ here).

Arm memory closure: original567 forms/580608 savedCPU states nowALLcanonical
checked(CPU0/modelSP4096/no missingdecoder). New255 full-bank memoryforms/65280
QEMU/C/reference cases agreeafterfixingD0upper64clear; itsunsafeGEN1baseline
nowverifierrejects. All359Lean/allC/Rust/wires passincombinedrootcheck.
ExclusiveCLREX8forms/8192observedcases nowagreewithexplicitfailurefixture.
The30-caseArm bound suite rejects28, retainingonlynumericSP/entryLRaccepts.
See differential/arm64-memory-complete/ and negative/arm64-current-choice/.

The requested helper/map timing replay is recorded in helper-map/timed-x86/:
all117 samples match expected results/retval2. TCB after-memory/ now inventories
shared input/metadata contracts and loader/module support explicitly, with
exact counted-source bytes. Pure simple15 load-time confirmation remains open.
