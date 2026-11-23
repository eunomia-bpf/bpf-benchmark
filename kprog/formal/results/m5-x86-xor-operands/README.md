# Actual XOR operand reads through arithmetic dispatch

Both XOR read cases now execute the original gates, real first call, both
complete scalar reader bodies and original caller assignments through the
arithmetic dispatcher. Distinct register indices use the actual first-test0;
equal indices with distinct lane shifts retain its actual first-test1.
The full input heap remains unchanged. The shared actual reader tail supplies
both results; no assumed callee execution or intermediate result is used.

The scalar/non-RSP/non-stack-tag and shift-range domain is the same as the
existing ordinary reader theorem. Equal register/lane inputs retain the
separately checked zero shortcut. Final XOR arithmetic, flags and writeback
remain next; this does not complete an instruction-family refinement.

Focused174 jobs pass in1.91s and the direct-import type/axiom query passes.
See [Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and compressed focused log. Original200000/512 budgets, one worker,32GiB and
shared timing are unchanged. Raw attempts remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`. Root integration follows
this component batch; whole-check status is retained in the batch receipt.
