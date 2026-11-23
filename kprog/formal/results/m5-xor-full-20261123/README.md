# Complete XOR-batch confirmation, 2026-11-23

`make check` passed the default Lean library/reference build (518 jobs) and
x86 semantic comparisons through REP MOVS/STOS and CALL/RET/LEAVE/UD2.
REP covered2150 full-state transitions, with1360 CPU cases and80 restart
faults; CALL/RET covered1659 canonical transitions and476 CPU cases.

The command then exited2 at the existing native-fault marker assertion in
`tools/check_x86_divide_handler.py:73`. The generated first fault object,
`build/divide-handler/fault_8_False.o`, ends with `r0 = 0; exit` where the
oracle requires the original native-fault marker. The complete disassembly
and traceback are retained in the compressed log. Coordinator runtime work
owns the repair; the oracle retains its existing assertion. The earlier
safe-return-to-`assume(false)` correspondence defect remains the follow-up.

This is a failed complete confirmation, with the successful preceding stages
recorded above. Later Makefile stages remain to execute after the correction.
The previous ARM numeric recursion failure has been corrected and its module
passed in this default build. Full ISA family and dispatcher-step composition
continue as tracked by the worklist and component receipts.

The run took204.10s at the original200000/512 proof budgets, one worker,
32GiB and shared timing/exclusive full-check ownership. Ordinary input
metadata recorded zero changed, added or removed inputs during the actual
run. HEAD8736192af and raw command/output metadata are retained. The next
independent logic-helper source belongs to the following focused batch.
