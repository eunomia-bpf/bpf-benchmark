# Shared formal batch confirmation

The make-check2 default Lean build passed485 jobs. The following C/reference
stage stopped on the historical numeric-helper map fixture. The named-helper,
inline-exit and final-ADD correction passed102 focused comparisons; the source
and evidence are in [the map receipt](../map-reference-20261122/README.md).
The42 actual-root type/axiom queries passed:37 V/ARM interfaces in2.14s and
five aux-decoding interfaces in2.05s. Their semantic assumptions are the existing
logical and CompCert external/assembly axioms.

Logs: [whole attempt](make-check2.txt.gz), [root37](root-public37.txt.gz),
[aux5](root-decode5.txt.gz), [invocation results](validation.json).
Raw failed/successful diagnostics remain at
`/workspaces/kprog-raw/V/x86-alu-decode-20261122`.

The original make-check1 has a partial434/484 log and its terminal result absent;
its controller ended before a terminal receipt was written. That evidence remains
in the preceding x86-entry-storage raw directory. The current completed attempt
records an added peer ARM call module during the run; initial source inputs retain
their sizes/timestamps. The next complete confirmation includes the current tree.
Per-instruction/full-dispatcher and O1/O2/O4/M5/M6 work continues.

## Architectural-fault regression

make-check3 completed the current Lean build and native reference suites through
REP MOVS/STOS (2150 complete-state transitions, including80 CPU restart faults)
and CALL/RET/LEAVE/UD2 (1659 complete-state transitions). It stopped at
`check_x86_divide_handler.py:73`, which retains the BPF fault rejection marker.
The [whole output](make-check3.txt.gz) records exit2 after201.86s.

Runtime commitaaca40148 changed the fault arm to `r0 = 0; exit;` while
`compile_sim_ir.cpp:208` still converts that arm to `llvm.assume(false)`.
The new returning B arm can be reachable and accepted. Acceptance alone thus
supplies insufficient evidence for the native unreachability assumption.
The constant DIV0 artifact is build/divide-handler/fault_8_False.{c,o,asm};
zero-divisor, overflow and AX-alias negative cases retain the existing assertion.
The original native/B fault correspondence requires correction in the runtime
owner's implementation; the oracle assertion stays intact.

This is a concrete remaining full-check failure. All failure logs stay in raw
storage and this receipt. The source-size/mtime record also lists the peer
Arm64SelectCaller addition during this attempt. The accepted source inputs
retain their initial metadata. Verification continues on the independent
per-instruction source proofs while the runtime owner corrects this defect.
