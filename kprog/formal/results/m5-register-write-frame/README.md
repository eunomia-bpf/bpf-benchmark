# Full register contract for the actual scalar writer

The actual producer resource now retains four allocation-bound flag locals,
the vector array and their initialized pointer slots. `of_header` obtains them
from the same concrete header/loop execution already used by `RegisterView`;
the 98-visit producer APIs retain that stronger Storage automatically. No new
run, independent storage witness or pointer-alias assumption is introduced.
The writer's `Result.storage` preserves these same roots and bindings.

`Result.flags` and `Result.vector` prove exact reader preservation for all four
flags and all 32 SIMD pairs, including refused or undefined reads. They use
actual allocated-local separation from both written cells and reuse the real
exported vector layout/slot lemmas. Imported load validity supplies reader
bounds. The established producer reader frontier remains unchanged and stays
distinct from the original caller frontier.

`Result.represents` now combines the existing GPR/SP correspondence with those
frames and LNSym's public read-over-write laws. It proves the complete existing
`Arm64Registers.Represents` relation after the actual writer against the mature
GPR write: all ordinary GPRs, SP, SIMD registers and NZCV. The explicit identity
cell map, invocation pointer/provenance origins and pre-relation remain inputs.
Unselected pointer-valued registers and tags are preserved. Native extraFlags
remain in the updated native record.

`write_represents` derives both successful stores, all 67 internal transitions
and this full post-relation from the same source resource. Width 4 writes a
full zero-extended 32-bit value to the eight-byte word cell; width 8 keeps all
bits; both clear the scalar tag. `write_all_behaviors` additionally proves
that every finite relational execution is a silent prefix of that same return,
every stuck endpoint is that return and no infinite execution exists. Proposed
execution traces are arbitrary; silence is proved from the actual internal run.

This is a full register-representation contract for the exported scalar-writer
procedure, not a complete ISA-instruction refinement. Genuine caller/control
composition, source inlining in the generic execute handler, native instruction
fetch/step, physical memory/alias admissibility and other instruction families
remain M5. Producer continuation `(entry*) -> uint` and generic execute's
nine-argument void procedure are separate boundaries; no source edge is
fabricated. Complete ISA-handler refinements remain 0, M5/M6 remain open.
Next is the actual generic MOV_IMM path and its mature move-wide semantics.

`validation.json` records focused/full builds, seven public type/axiom queries,
all 23 byte-identical exports and raw logs. Proof limits remain 200000 heartbeats
and 512 recursion; one worker/32 GiB, timing SH, CPU17 builds and CPU18 queries.
C/runtime/benchmarks are unchanged, so native primitive checks were not repeated.
M5/M6 closure still requires fresh full Lake and make checks.
