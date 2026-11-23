# Actual CNEG numeric suffix

The proof executes the original width-8 CNEG suffix from Condition.after to
its actual scalar-writer call. Width and full-mask preparation take 18
Clight transitions. Case 65, conditional unsigned negation, mask application,
result copy and the inner-loop exit take 20 transitions for either Boolean
condition. The constructed execution therefore takes 38 transitions; the
public theorem exposes the execution count existentially.

The result is the original 64-bit value when the condition is false and its
64-bit modular negation when true. The execution preserves the entire heap,
caller environment, pending writer continuation and twelve original inputs
and materialized observations. Premises identify opcode 65, width 8, the
reached scalar operand and the normalized Boolean from the condition proof.
The source identity names the actual exported Clight statements.

Focused build 254 passed in 8.862 seconds, and two public type/axiom queries
passed in 1.556 seconds, at the original 200000-heartbeat/512-depth caps.
Checks used CPU 17, one worker, 32 GiB and the shared timing lock. The proof
reuses imported Clight semantics and integer arithmetic. Its axiom queries
report standard logic and inherited CC.externalFunctionsSem and
CC.inlineAssemblySem.

The retained attempts document the reduction from generic simplification to
concrete source-site reductions and a shared retained-key transport lemma.
Numeric preparation, arithmetic and input preservation now pass together.
The existing writer proof supplies the next composition boundary. Complete
handler dispatch, original caller allocation/free and the eighth native step
are the next M5 worklist items; the complete program prefix reaches seven
calls. V coordinates whole confirmation. Raw evidence remains under
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
