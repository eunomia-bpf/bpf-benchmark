# Actual raw producer context and origin tags

The source equation binds the actual five exported assignments after SP-zero:
helper context, helper ABI base and x0 union pointer receive the context temp;
x30 receives RETURN tag 10 and x0 receives ABI tag 1. All five names are distinct,
and the real union pointer member has offset zero. No alternative simulator
or replacement handler is introduced.

The cast domain reuses `Arm64Registers.ValueRep`: a scalar 64-bit value or
an abstract pointer with an explicit physical origin. Undefined and other
value forms do not acquire invented native bits. Allocation supplies each
actual local binding and writable typed range. Each real store constructs
its memory outcome rather than assuming success, executes three internal
transitions, and reads back its exact typed value. The finite composition
covers all five assignments in fifteen transitions. The preceding 24 tag
clears and SP-zero compose with it in ninety transitions, retaining those
observations and every other declared-local load. Caller bytes, Cur/Max
permissions, access and allocation frontier are preserved.

The stage access map and actual context temp binding remain explicit premises.
No external or assembly boundary executes here; no input-provider purity,
complete native memory/origin/control correspondence or ISA-handler refinement
is claimed. Remaining header fields, vector pointers and the actual borrowed consumer
remain M5 work, followed by full handler migration and O1/O2/O4 recount.
M5 and M6 stay open; complete ISA-handler count stays zero.

Focused build passes 154 jobs and all seven compiled public type/axiom queries
pass. Source/allocation/cast facts use the three standard axioms; internal runs
also mention the imported opaque external/assembly relations, without executing
either boundary. Final context/header batch confirmation passes 282 jobs under timing SH;
see `../m5-producer-header/validation.json`. Default proof
limits, one Lean worker, CPU 17 and 32 GiB AS are retained. All Lean checks, including focused
checks and queries, take timing SH under the coordinator's 12:10 notice.
Raw attempts: `/workspaces/kprog-raw/formal/m5-producer-context`.

Reproduce from `kprog/formal`, with the stated CPU/memory bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerContext
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-context/Query.lean
```

Last complete native `make check` passed at `5236c0e96`; it is not rerun for
this Lean-only change. Canonical C, generated exports, imported semantics and
frozen benchmark paths remain unchanged.
