# Shared actual operand-reader tail

Starting at the original LHS call state, this theorem executes both complete
scalar reader bodies, their actual returns, the RHS call and both source value
copies through the arithmetic dispatcher. It assumes neither a callee execution
certificate nor an intermediate read result. Source registers, layout, helper
bindings and caller cell/tag loads retain the same explicit domain as before.

The non-XOR operand proof now reuses this tail after its actual gate/call prefix.
Its existing public statements and genuine214/222/230/230-step entry result are
unchanged. The shared tail also supports the two actual XOR read-gate cases,
whose first-test temporary maps differ.

The tail's focused169 jobs pass; the refactored entry and exhaustive XOR-selector
check passes173 jobs in8.06s. Four public type/axiom queries cover the tail and
the three existing operand/entry interfaces. See [Query.lean](Query.lean),
[public.txt](public.txt), [validation.json](validation.json) and compressed log.
Original200000/512 budgets, one worker,32GiB and shared timing are unchanged.
Raw evidence remains under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
The latest complete check and unresolved DIV correspondence defect remain
recorded in [the batch receipt](../m5-reader-batch-20261123/README.md).
