# Producer execution in the linked program

The linked program foundation now lives in `Arm64LinkedProgram.lean`, below
`Arm64Producer.lean`. The producer's ge uses that actual linked environment.
The input declaration resolves to block 64 and the payload callbacks to 184/185;
their source bodies and types are retained. The old standalone input-binding
construction and duplicate binding-only entry witnesses are removed. Exact
allocation comparison with the standalone export remains a genuine theorem.

All producer initialization and lifetime proofs now target this environment.
Their existing statements retain the allocated resources, typed readbacks,
cache contracts, caller framing and explicit provider outcomes. The new query
requires the 638-transition header/loop and 640-transition conditional call
witnesses to inhabit InternalRun Binding.ge. Provider calls keep externalCall
premises in the actual linked Genv.toSenv; no old/new Senv equality or outcome
is assumed. The three returning-continuation transitions retain their precise
Freeable-local resource premise and revocation result.

The new linked foundation imports only the existing exports, declaration/model
facts and Clean's linker. Its source/layout preservation and kernel-checked
link equation are reused rather than introducing a parallel producer route.
The previous binding receipt's Query/Next use the new foundation and genuine
parent entry witnesses. Superseded proof build products are removed after the
replacement check; the cleanup log records the move and removal. Raw data stays.

A genuine continuation body, provider/native origins and admissibility, native
memory/events/faults/control and XDP/SKB obligations remain M5, followed by full
handler migration and O1/O2/O4 recount. Complete ISA-handler count remains zero;
remaining M6 follows M5. This change does not supply a concrete provider or
continuation body and does not alter production C or frozen benchmark paths.

Focused Lake passes 161 jobs, eleven public type/axiom queries and the explicit
linked-execution queries pass. The updated binding receipt's fifteen queries
and ABI inspection also pass. Full Lake passes 287 jobs with zero failures;
all 23 exports remain byte-identical to 9c617740f, 243488732 bytes. All original
failed attempts and the timing-window wait details remain in raw/state. The
531-second initialization-prefix check passes without raising proof limits.
Source/binding facts use the three standard axioms; execution proofs also
mention imported external/assembly relations. All builds/checks use timing SH, CPU 17/18, one worker, 32 GiB address space and
default 200000 heartbeats/512 recursion depth. No semantic/native-reflection
axiom or raised proof limit is introduced.

Reproduce from kprog/formal with those bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerLifetime
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-unified-producer/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-unified-producer/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw: /workspaces/kprog-raw/formal/m5-unified-producer. Last full native make check
remains PASS at 5236c0e96, not repeated for Lean-only changes. Final M5/M6 closure
still requires full Lake and make check.
