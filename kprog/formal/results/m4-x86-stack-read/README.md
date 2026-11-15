# x86 private-stack read C-subset checks

The owned, released and ghost-fact read primitives share declaration/output
bodies with their original native expression/initializer forms. Three actual
roots bring X86Pointer to26 functions. Generic arena bindings gain the existing
16/32-bit views; active byte/word/dword/qword views refer to the same storage.
Inactive views may remain absent. Previous b/q-only fixtures explicitly name
their used fields. CompCert inline adapters take the actual binding by reference.

Historical and current native/host-adapter modes each pass133,974 read/frame
and1,462,272 metadata/frame cases. Six capacities include partial words and
producer-sized200/376 arenas. Widths include all byte codes and high operands.
The tests retain byte defaulting, aligned q/d/w and unaligned byte paths,
release-boundary draws, full frames and lazy nonstack ghost payloads. Fact
checks preserve the original matching of the final partial metadata word;
they do not add a physical-window condition the original body did not have.

Four guarded sizes exercise owned/released reads; two distinct-address fault
probes check physical access before inaccessible SP or free input. Another224
facade/output probes protect the arena at SP observation and check repeated
OFF/WIDTH capture counts. They retain the C expression's unspecified argument
order at the final width-mask call. The real inline adapter adds4,296
read/metadata binding/frame cases with unused references absent. Seven semantic
mutations fail: fixed capacity, bad byte shift, wrong release boundary, skipped
physical read, lost width capture, wrong ghost boundary and eager payload.

`make clight` and `lake build KProgFormal.Clight.X86Pointer
KProgFormal.Clight.X86Context` pass. Export repeats exactly970,802B; three root
queries use only the usual Lean axioms. Native allocated sections/relocations
are unchanged against the historical headers: stack2856B/8relocs,
ordinary1448B/11relocs and contextXDP360B/TC760B/4relocs. All current replays
match normal compilation. Fixtures were not loaded or timed.

Full inline export still exits2 at MOVBE width/shared-read GNU expressions.
CPP2,593,834B is the extraction TU only. Clight/native arena-view identity,
volatile effects, pointer fragments, permissions, initialization and faults
remain M5 proof obligations. The C's original definedness conditions remain;
these tests do not totalize undefined source expressions. M4/full handlers and
default coverage, all2,065 refinements/recounts, M6 and whole-library checks
remain pending.
