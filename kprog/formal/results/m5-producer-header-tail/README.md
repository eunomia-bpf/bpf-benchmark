# Actual remaining header fields and callback bindings

`Arm64ProducerHeaderTail.lean` binds the sixteen exported field assignments after
the null vector-pointer stores. The nine source-local types include the volatile
stack union and payload array; b/q are address views of that union. Both callback
symbols and their actual internal function bodies are bound at Entry blocks 59
and 60. Capacity, payload-word count, tag-byte count and bias read back exactly
as Vint160, Vint20, Vint24 and Vlong96. The first three RHS expressions produce
64-bit values before their actual C casts into the 32-bit fields.

Real HeaderLocal ranges construct every mixed-width store and its outcome.
Each actual sequence/assignment/skip takes three internal transitions. The full
tail takes 48 transitions with exact typed readback, preserving all 76 earlier
pointer slots, other declared-local loads, caller bytes/Cur/Max permissions,
access and nextblock. Source composition with the earlier header stages takes
276 transitions and retains all 92 typed readbacks at the same actual entry.
Both existing BorrowedCacheStorage contracts are constructed at that reached
pre-loop state from the preserved actual scalar header pointers.

The stage access map matching actual allocation remains explicit. The run uses
the Entry environment; the memory contract uses the Program composite layout.
The following 32-element pointer loop, linked consumer and lifetime, provider
ABI/native origins/memory/control, full handler migration and O1/O2/O4 recount
remain M5. No callback, external or assembly boundary executes in this segment.
Complete ISA-handler count remains zero; remaining M6 follows M5.

Focused build passes 158 jobs, all eight compiled public type/axiom queries
pass, and full Lake passes 284 jobs with zero failures. The next-source query
binds the actual loop initializer, body, increment and consumer tail. All 23
exports remain byte-identical to 9c617740f (243488732 B). Work uses timing SH,
CPU17, one worker, 32 GiB AS and default 200000 heartbeats/512 recursion depth.
Source/layout/local/callback facts use only the three standard axioms; offsets
use propext. Internal runs additionally mention the imported opaque external
and assembly relations. No semantic or native-reflection axiom is added.

Expression evaluation is split into finite groups and address-of uses a small
bound-local lemma, retaining default proof limits. Index constructors avoid
unreduced numeral projections. Input and stored values are separate for the
three long-to-int casts. The failed attempts stay in raw alongside final logs.

Reproduce from kprog/formal with the stated CPU/memory bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerHeaderTail
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header-tail/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header-tail/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw: /workspaces/kprog-raw/formal/m5-producer-header-tail. Canonical C, exports,
pinned semantics and frozen benchmark paths are unchanged by this proof step.
Last complete native make check passed at 5236c0e96; it is not repeated for these
Lean-only additions.

Continuation: [the vector-loop proof](../m5-producer-vector-loop/README.md) now
executes all 32 iterations and reaches the actual consumer sequence, preserving
all 92 field observations and both cache contracts in 638 composed transitions.
Consumer execution and lifetime remain open. The validation counts above
record this earlier header-tail checkpoint.
