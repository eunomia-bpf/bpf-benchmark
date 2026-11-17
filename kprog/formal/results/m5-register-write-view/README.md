# Scalar writer storage and native GPR/SP view

`Result.storage` preserves the original producer's allocation-bound tables,
all 62 cell write permissions, SP local and SP value in the actual writer's
post-memory. It uses the two-store result's real local bindings and load/access
preservation. The table and SP data are retained directly from the same source
witness; no second producer execution or new storage choice is introduced.

`storage_gpr` follows the actual exported header layout and both pointer tables
to equate the checked reader with imported raw word/tag loads. Imported
`Mem.perm_valid_block`, through the existing `checked_load`, discharges reader
bounds at the real nextblock. This corrects the previous handoff's overly
cautious statement about deriving bounds: successful imported loads do prove
block liveness. Failed loads are preserved too. The caller frontier and the
producer's allocated-register reader frontier remain distinct.

`Result.gpr` gives one complete bank equation at the unchanged reader frontier.
The selected ordinary cell returns the actual full64 or zero-extended32 value
and scalar tag0; every other cell retains its previous read, including pointers,
undefined values and failures. `Result.sp` retains the real signed-long SP read.

`Result.gpr_update` relates every GPR observation to LNSym's public `w` operation
using its own read-over-write laws and the existing provenance materialization.
The cell map is explicitly identity; arbitrary supplied maps are not assumed
injective. `Result.sp_update` preserves the old SP representation and agrees
with the external machine's unchanged SP. The native state retains extraFlags.
These results apply to the same `Result` whose 67 actual Clight transitions and
successful stores were proved in the preceding scalar-writer step.

This is GPR-bank/SP correspondence, not a complete register-state or instruction
refinement. Flags/vector preservation needs their actual producer pointer
bindings: Storage currently retains the tables and SP, and cannot rule out an
arbitrary flag/vector header pointer aliasing a written cell. The next step is
to retain the source-derived header/vector roots and finish that frame, then
connect the genuine caller and data-writing handler. SP/XZR destinations,
pointer writes, native physical aliasing, memory/events/fault/fetch/control and
full handler migration/recount remain M5. Complete ISA-handler refinements stay
0; M5 and M6 remain open.

Focused and final validation, six public type/axiom queries and all 23 unchanged
Clight exports are recorded in `validation.json`. Proofs use the normal 200000
heartbeats/512 recursion, one Lean worker, a 32 GiB address-space limit and the
shared timing lock, CPU17 builds/CPU18 queries and publication. C and runtime
are unchanged, so native primitive checks were not repeated. M5/M6 closure
still requires fresh complete Lake and make checks.
