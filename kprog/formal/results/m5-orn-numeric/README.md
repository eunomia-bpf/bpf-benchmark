# Actual ORN32 numeric suffix

The proof executes the original width4 assignment and actual mask-choice
chain, then selects real switch case53 and performs OR-NOT, low32 masking,
result copying and inner-loop exit. The result is derived from actual
operand temporaries and reaches result__7 at the original writer.
Preparation takes18 transitions; calculation/copy/exit takes16. The full
heap, caller environment and original input temporaries are retained.

Focused build264 and two public type/axiom queries pass at original
200000/512 caps, CPU17, one worker, 32GiB and shared timing lock. The source
identities are checked against the exported Clight statements. Queries
record the existing Clight external-function/assembly assumptions and
standard logic. V coordinates whole confirmation. The next composition
runs both real readers and the original scalar writer on the same heap.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
