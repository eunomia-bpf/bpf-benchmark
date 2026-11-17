# NOP procedure in the actual linked program

The same nineteen-transition procedure proof now accepts a Clight environment
and an actual internal width-function binding. The standalone theorem is an
instance of this proof. `Arm64LinkedNop.lean` supplies the genuine binding in
the complete linked Entry/Program environment: the unchanged generic handler
resolves at block 85 and its internal width callee at block 66. The handler
lookup certificate undergoes ordinary declaration kernel checking; no
alternate NOP-only body or continuation is supplied.

For arbitrary caller memory, ignored Clight operand values, flags byte and
call continuation, all nineteen actual transitions allocate, execute and free
the real locals while retaining every old byte and both permission maps.
At Kstop, every finite Step2 execution is a silent prefix of that run and
can finish at its unique endpoint; a stuck endpoint is that return, and an
infinite execution is impossible. Proposed traces are arbitrary, not assumed
silent. The actual initialized-memory instance preserves the 188 global
blocks and the data-global access maps established by the preceding step.

Every observed top-level return retains the existing concrete register
relation for GPRs, SP, vectors and NZCV, alongside LNSym's actual NOP step.
The pointer origins, physical origins, cell map, starting representation and
fetch/error facts are explicit inputs. This is not complete native-entry
admissibility or full architectural memory/events/fault/control refinement.
The producer/continuation ABI gap remains open. Complete ISA-handler coverage
is still zero; M5 and then remaining M6 continue.

The low generic proof imports no linked-program module: the linked foundation
already reaches NopCall through OriginCache/Registers/NopEntry. Keeping the
new instance above that chain avoids an import cycle. No Step2 transport
between different composite or symbol environments is assumed.

Focused Lake passes 147 jobs. Seven public type/axiom queries and three linked
execution/resource examples pass. The examples require Binding.ge, verify the
actual width binding, and check post-call string47/string48/stderr0/width66
permissions for both Cur and Max after initialized execution. Source facts
use the three standard axioms; execution statements additionally mention
Clean's imported external/assembly semantic relations, with no new semantic
or native-reflection axiom. Full Lake passes 289 jobs; all 23 exports
(243488732 bytes) remain byte-identical to 9c617740f. The affected producer
prefix passes in 503 seconds at unchanged proof limits.

Reproduce from kprog/formal, each command under timing SH, CPU17 or18,
`ulimit -v 33554432`, LEAN_NUM_THREADS=1, default200000 heartbeats/512recDepth:

```
lake build KProgFormal.ClightRefinement.Arm64LinkedNop
lake env lean -j1 results/m5-linked-nop/Query.lean
lake env lean -j1 results/m5-linked-nop/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-linked-nop. The first focused run's
namespace-selection error remains there; the forward fix uses the actual
namespace and qualifies the NOP allocation, keeping default proof budgets.
Production C, generated export contents and frozen benchmark paths stay
unchanged. Last full native make check remains PASS at 5236c0e96; fresh full
Lake and make check remain required for actual M5/M6 completion.
