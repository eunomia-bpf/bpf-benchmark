Linking the actual Arm64 fixture to the shared C handlers
=======================================================

`Arm64ProgramEntryLinked.linked_source` checks the complete result of Clean's
`CC.Link.linkProgram`: actual Fixture first, generic Program second. The cache
contains references to original source rows, not copied or synthesized C bodies.
The merged composite environment is rebuilt by the imported linker.

The result has 197 global definitions and 14 composites. Every original fixture
identifier remains in order. The external execute declaration resolves to the
unchanged internal generic C body at block 72, with its real void/nine-argument
signature. Native input remains at 59, payload callbacks at 60/61, and the actual
context/signed32 wrapper at 88. The environment's global-symbol frontier is 198;
this is not yet a proof of initial-memory allocation or native physical bounds.
Each original fixture composite retains its complete computed layout, while
additional composites remain in the linked environment.

Closed reflexivity is constructed directly for the kernel to check, following
the existing source-link proof technique. This avoids deep meta-level `rfl`
normalization without increasing proof limits. Bounded source-row slices avoid
unnecessary indexed-row bound elaboration. The complete link equality checks
all rows, and wellformedness checks the imported composite construction.

The actual entry route now uses this environment through
`Arm64ProgramEntryAllocation.world`, with no old/new mode. Allocation, layouts,
native-input/callback bindings and the reached architectural register relation
have been rechecked in that linked world.
ProviderAt, context ValueRep and native ABI bindings remain explicit. Genuine
handler/native execution, native input/original-context/all-outcome admission,
relative caches/physical memory/ranges/aliases/control, return correspondence
and O1/O2/O4 recount remain M5 work. Completed ISA-family count remains 0;
M6 follows M5.

From `kprog/formal`, using original proof limits:

```
ulimit -v 33554432
export LEAN_NUM_THREADS=1
taskset -c 17 nice -n 0 lake build KProgFormal.ClightRefinement.Arm64ProgramEntryLinkedBindings
taskset -c 17 nice -n 0 lake env lean -j1 results/m5-program-entry-linked/Query.lean
```

`LinkProbe.lean` records small computed metadata of the imported merge. Those
computations plan source-row references; the theorem checks the complete merge
in the kernel. Probe outputs and failed elaboration attempts are retained in
`/workspaces/kprog-raw/formal/m5-program-entry-linked`.
No C/runtime/compiler/kernel/image/base/benchmark/paper/design change is made.
Fresh final Lake/make check and frozen-byte confirmation remain due after M5/M6.

The complete foundation/bindings subset passed 42 jobs and all 12 public
type/axiom queries passed. All facts use standard Lean logic, with no new
axiom. The original proof limits are unchanged. Earlier elaboration and kernel
lookup failures remain in the raw logs. The light focused compiler was returned
from nice19 to normal priority after its VmPeak snapshot was below 7 GiB: the
coordination condition applies nice19 to full builds and compiles above 16 GiB.
Full builds retain nice19. The initial foundation receipt recorded entry-world
migration as pending.
The completed migration is recorded below and in validation.json.

The linked-world allocation subset passed 149 jobs, tail 171, call 174 and the
complete reached-body/register subset 197. Eight additional public type/axiom
queries passed. The same 98 ordered traces, 92 typed header readbacks and caller
resources remain, with the native/provider/context contracts explicit. Existing
wrapper/input/callback binding facts are reused. A generic zero-offset call
lemma and direct kernel checks replace deep concrete-environment `rfl` steps;
no statement, C body or proof cap was weakened. One full Lake confirmation
passed 360 jobs at nice19 on CPU17, with one worker and 32 GiB address space. The final make check and frozen-byte confirmation
remain due after M5/M6.
