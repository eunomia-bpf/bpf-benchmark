# M5 internal execution and all behaviors at the NOP return boundary

The previous proofs exhibited one actual Clight NOP execution. This step
proves that other executions at its `Kstop` procedure boundary cannot emit
different traces, become stuck elsewhere or continue forever.

`InternalExecution` certifies paths over the existing `CC.Step2` relation.
Its state predicate excludes only a currently executing builtin or external
function. It does not reject code because an unexecuted branch contains one.
Internal-step uniqueness uses the mature expression, assignment and function
entry determinism lemmas directly. The general upstream step-determinism law
is deliberately not used: that law depends on external-call determinism
assumptions. Axiom queries show the standard Lean axioms and the two existing
opaque external/assembly relations, with neither determinism assumption.

`InternalRun` records the complete states and the number of real transitions.
`InternalPath` checks the sources visited by the existing `doStep`; actual
successful execution is separately supplied by `steps`. No new interpreter,
Clight semantic rule, ISA operation or external-call implementation is added.
The generic prefix theorem quantifies over arbitrary relational traces. It
proves that every finite execution can finish at the certified stuck endpoint;
the endpoint-uniqueness and no-infinite-execution theorems close the other cases.
No silence, fairness or determinism premise is imposed on a proposed execution.

The actual exported width function has a six-step certificate. The real NOP
body composes four entry/call, six width and seven completion transitions.
Function entry and successful deallocation give the complete 19-step call
certificate, with the existing exact caller-memory frame. Public executable
and relational contracts remain intact, now derived from these certificates.
`Arm64Nop.call_all_behaviors` supplies the finite-prefix, unique stuck-endpoint
and no-infinite-execution laws at `Kstop`. `return_flags_correspond` transports
the concrete NZCV/LNSym relation through every relational return, allowing an
arbitrary proposed trace, result and memory rather than assuming the exhibited
execution or an empty trace.

This is a procedure-boundary result. A `Kcall` return can resume its caller;
general caller-control and compiled-label/native-PC composition remain open.
It is not a claim about Clight's integer-valued whole-program final-state
relation. Producer admissibility, compact cell mapping, pointer/native-memory,
SP/return and sparse payload representation also remain M5 obligations.
The complete ISA-handler count remains zero; all 2,065 migrations and O1/O2/O4
recount, then M6 and final whole-package checks, remain outstanding.

All 23 unchanged exports and eleven proof modules pass 144 Lake jobs. All 17
axiom queries and three public type prints pass. Proof workers used CPU 17,
32 GiB AS and `-j1`; queries used CPU 19 and 16 GiB AS. Default heartbeat and
recursion limits remain unchanged. An initial universally quantified path
certificate exceeded the default budget; matching the already computed
interpreter transition removed that duplication. Earlier syntax/induction
diagnostics and the timeout remain in raw. Canonical C, exports, external
semantic sources and frozen benchmark paths stay exact to `0ba296ea3`.
No compiler, kernel, guest, base or image changed.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64NopEntry
lake env lean -j1 results/m5-internal-runs/Axioms.lean
```

Commands and axiom output are retained here. Raw builds and diagnostics stay
at `/workspaces/kprog-raw/formal/m5-internal-runs`.
