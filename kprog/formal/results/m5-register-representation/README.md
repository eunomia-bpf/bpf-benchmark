# M5 concrete architectural-register representation

`Arm64Registers.Represents` extends the four-byte NZCV relation to all 31 GPRs,
the distinct SP and both halves of all 32 vector registers. It reads the actual
entry through `Arm64EntryMemory`, including the individually supplied union
and tag locations and the embedded vector pointer arrays. The additional SP
field offset/type is kernel-checked against the actual exported composite.
No dense replacement C frame or initialized dummy storage is constructed.

GPR union values retain either their complete scalar bits or their abstract
Clight pointer. `ValueRep` requires an explicit native origin for a pointer's
block and adds its full pointer offset. An unbound block and undefined value
are refused by the relation; neither is mapped to zero. This binding does not
by itself prove native range disjointness, aliasing or permissions. A separate
storage-cell map relates architectural GPRs to the actual pointer-table slots;
the proof does not assume that an arbitrary producer's compact map is identity.

All 256 byte tags use the existing M3 provenance materialization: STACK and
RETURN add their respective invocation origins, and other tags retain their
numeric bits. SP uses its signed-long storage bits as a logical offset plus
the stack origin. Vectors require defined low/high 64-bit values matching the
full LNSym 128-bit cell. NZCV retains the previous exact scalar-byte relation.
The relation's uniqueness theorem proves that the same entry and bindings
determine every covered GPR, SP, vector and NZCV bit. It uses kernel BitVec
lemmas, including reconstruction from both vector halves; no native checker
or observation mask supplies the result.

The existing raw caller frame proves stability of the entire register
relation without a heap-decoder stability premise. A native cursor update
preserves it. `call_corresponds` combines these facts with the actual 19-step
NOP call certificate and the complete checked LNSym/reference post-state.
`return_corresponds` covers every relational return at `Kstop`, with arbitrary
proposed trace, result and complete memory. The native step advances PC by
four and preserves all other native fields, including memory profiles and
histories; this step does not yet relate those fields to Clight storage.

These are conditional representation laws. Actual producer entry/cell-map
admissibility, pointer-block and invocation-origin bindings, origin-cache and
return bookkeeping, sparse stack payload, native memory/permissions and
compiled-label/general caller control remain to be proved. In particular,
the relation requires successful reads of every covered register; it does
not assert that every source profile already supplies them. Extra native
flag bits and nonregister state remain outside this register relation. The
complete ISA-handler count stays zero; all 2,065 migrations and O1/O2/O4
recount, then M6 and final whole-package checks, remain outstanding.

All 23 unchanged exports and twelve proof modules pass 160 Lake jobs, including
the existing M3 provenance dependencies. All seven axiom queries and four
public type prints pass. Layout, uniqueness, frame and cursor laws use only
standard Lean axioms; call/return laws additionally expose the existing opaque
external/assembly relations, without external determinism assumptions. Builds
used CPU 17, 32 GiB AS and `-j1`; queries used CPU 19 and 16 GiB AS. Default
heartbeat and recursion limits remain unchanged. Canonical C, all exported
AST sources, external semantic sources and frozen benchmark paths remain
exact to `7e9eb7b9d`. No compiler, kernel, guest, base or image changed.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64Registers
lake env lean -j1 results/m5-register-representation/Axioms.lean
```

Commands and axiom output are retained here; raw builds stay at
`/workspaces/kprog-raw/formal/m5-register-representation`.
