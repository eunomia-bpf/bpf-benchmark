# Actual MOV immediate dispatch and Numeric source binding

The actual generic export contains function calls to the Numeric selector and
the program reader/writer wrappers. The previous two-unit Entry/Program world
left the selector external, so an interpreter probe stopped at transition 28.
`Arm64NumericProgram.linked_source` now kernel-checks the imported
`CC.Link.linkProgram` over that complete world and the complete Numeric export.
It resolves six existing declarations and appends 15 definitions, for 203
global definitions. The original 188 symbol positions and composite environment
are unchanged. No C body or source unit is filtered or replaced manually.

The cache contains 11 groups of references to original source rows. Its data
were obtained from the real linker; the full `linked_source` equality checks
every result in the kernel. No evaluated result serves as a proof, and no unsafe
or native-reflection declaration is used. `SourceRows.lean` reproduces the
metadata selection. The original two-unit foundation remains the input to this
extension and its existing component contracts remain valid in that environment.

Actual symbol/body bindings retain width at block 66, Numeric mov_path at 67,
program read at 76, program write at 79 and generic execute at 85. These are
Clight blocks, not native addresses. The 23-transition selector proof executes
the actual Numeric body for op1 and every 64-bit width argument, returning
scalar-path0 with unchanged memory. Each transition uses imported doStep_sound
and kernel reduction, retaining unvisited alternatives.

`Dispatch.body_dispatch` proves 53 actual body transitions through width
calculation, NOP/ADRP/MOV selection, the real Numeric selector call and its
scalar-branch decision. The complete exported body is retained by a definitional
source equation. `Dispatch.call_dispatch` additionally executes the real
function entry, for 54 transitions from the nine-argument generic Callstate.
Both global helper names are proved unshadowed in its actual allocated local
environment. Caller bytes and both permission maps are preserved; the only
memory change in this prefix is allocation of the actual function frame.
Unused incoming Clight values remain unrestricted. Width codes 4 and 8 are
covered by this prefix theorem.

The actual next scalar branch eagerly calls the SRC reader before its immediate
switch; it is not silently skipped. `Replay.lean` concretely reaches return in
203 transitions for both widths with SRC=NONE255 and a small storage fixture.
That replay and its counts are metadata only. The generic reading/writing/freeing
suffix, symbolic memory/resource transport, native move-wide/fetch semantics
and full instruction refinement remain unproved. The new initialized global
world needs nextblock204; the old initialized world ends at189 and must not be
silently reused as a full new-world initialization witness. Producer callback
and generic nine-argument void boundaries remain distinct.

No runtime/C/benchmark path changed. All 23 regenerated Clight exports remain
byte-identical. `validation.json` records focused builds, the single final Lake
build, twelve public type/axiom queries, replay/cache queries and retained failed
attempts at normal 200000-heartbeat/512-recursion limits. All host work uses the
shared timing lock, one worker, 32 GiB and CPUs17/18. Complete ISA-handler
refinements stay 0; M5/M6 remain open. Final closure still requires fresh full
Lake and make checks.
