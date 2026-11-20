# Cilium table-result spill observations

PERF 2026-11-19T21:27:36Z. The original relative-table rejection is reproduced on
requests22,40,58. The first consumed code-address bits are RAX8..31 after
MOV AL,5 followed by a DWORD spill. The original register/flag liveness
analysis treats that store as an observation and rejects the lowering.

The committed `make memory` diagnostic uses the existing provisional CFG
solely to obtain dispatch edges and the existing ABI pointer analysis.
It emits no program and changes no production lowering. It inventories
stack accesses, follows all CFG branches from the rejected spill until the
first direct cell access, and asks the existing register-mask liveness
analysis about each readback's retained upper24bits.

| request | private spill offset from entry RSP | spill PC | first direct readback PC | readback register | upper24bits dead afterward |
|---|---:|---:|---:|---|---|
|22|-248|3735|8953 (0x22f9)|ESI|yes|
|40|-268|3693|9152 (0x23c0)|EDI|yes|
|58|-268|3697|9156 (0x23c4)|EDI|yes|

Each has one first direct readback, with no unresolved memory aliases on
that prefix in the provisional ABI inventory. Each prefix also has five
helper call sites: two map lookups, two map updates, and a tail call.
Their tracked stack pointer arguments start above the saved cell: request22
has roots-232,-208,-104 versus cell[-248,-244); requests40/58 have
roots-248,-224,-112 versus cell[-268,-264). These pointer roots alone are
not a proof about helper memory effects. Two unresolved aliases elsewhere
in each whole function remain in the full raw inventory; neither is on this
spill-to-first-access prefix.

This locates a path toward preserving observations without binding a physical
code base: prove the upper bits dead through the private spill, including
helper effects and every path, then extend the compiler's current liveness
analysis. The current compiler still rejects these requests. The existing
guard is unchanged; no code bits are zeroed or discarded by this diagnostic.
Future coverage must also examine any later table rejection after this first
one is resolved. No native, B, stock or runtime improvement is claimed.

Raw `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/prefix-20261119T212638Z`; log `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/prefix-20261119T212638Z.log`.
`memory-result.json` retains the focused facts. The initial whole-function
inventory remains at `memory-20261119T212500Z`, and the first readback version
at `readback-20261119T212700Z`, both under the same persistent raw directory.
Workers311804,312395,314409 are terminal; all raw data stays.

PERF 2026-11-19T21:29:29Z: provenance refinement `32a4c7907` repeats the ABI inventory
on the **original native instructions**, using the provisional graph only
for the table's dispatch edges. The rejected replacement supplies no ABI
instruction effects. Results agree: the same three spill offsets and first
readbacks, all three upper-bit dead results, no unresolved prefix aliases,
and the same helper pointer roots. Final raw `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/original-20261119T212852Z`, log `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/original-20261119T212852Z.log`;
worker315898 is terminal. `memory-result.json` now records this stronger
input provenance. The helper memory proof and production repair stay open.

PERF 2026-11-20T00:21:48Z: `d4c5c074e`/`02f011386` extend the diagnostic
past the first readback until overwrite or function exit. Each of requests
22/40/58 visits114 instructions, encounters the same single direct readback
with dead upper24register bits, and reaches exit without another direct read
or overwrite of those spilled bits. There are no unresolved memory aliases
on these paths. The cell itself remains live in memory through exit; this
does not establish that it is private or that helpers cannot observe it.

The complete lifetime adds one helper omitted by the earlier prefix: a
`bpf_perf_event_output` at9107/9309/9313. Its data pointer starts at private
offset-208/-224/-224, above the respective saved cell-248/-268/-268. Each
lifetime also includes the previous five lookup/update/tail-call sites.
Pointer roots and local register liveness alone remain insufficient to
justify elision: prior escapes, callback memory effects and implicit pointer
stores still need an actual preservation argument. The existing native
escape regression again passes all8executions, both local-readback checks,
and the production escaped-spill rejection. Both make targets exit0.
`lifetime-result.json` retains the complete inventory and escape result;
raw `lifetime-final-20261120T002144Z` stays under the persistent raw directory
above. No production lowering, native/B/stock acceptance or speed result
changes in this step.

## A prior escape defeats local readback liveness

PERF 2026-11-19T22:00:21Z. `94c995e19` exposes the existing ABI's final incoming states
to the diagnostic, replacing its frame inspection of ABI internals. The
analysis transfer functions and production lowering remain unchanged.
The full-width MOV inventory finds no proven private pointer stores in these
three functions; request22 has one unresolved source at PC8918,
`mov QWORD PTR [rsp+0xb8],r14`. Requests40/58 have no such records.
This inventory alone does not discharge helper effects, implicit spills,
or a pointer escaping before the particular store under consideration.

`escape.S`/`escape.py` provide an actual native regression for that last
obligation. Both functions spill a value after MOV AL,5, load it into ESI,
and use only SIL locally. The same existing bound native-effect analysis
finds bits8..31 dead after that local readback in both. One function also
saves the spill address through an external pointer **before** the spill;
it later reads the word through that alias and returns it.

Four native inputs execute in each function. The private-only case always
returns5; the escaped case returns5,0x12345605,0xdeadbe05,0xffffff05.
Thus the locally dead readback does not make the original spill unobservable.
The current production guard still rejects the escaped definition, as the
regression requires. A future spill-liveness extension must preserve that
negative case while proving the private-only case. No memory-elision
implementation was landed, and shared I is unchanged.

The fixture compiles real assembly, executes it through a shared object, and
gets instruction effects from the canonical native-link proof output.
All four recorded compiler/link commands return0; all eight native results
and both readback-mask checks pass. It uses hostCPU20 and imageSH only while
reading the linker; no guest, image build or timing lock.
`escape-result.json` records final raw `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/escape-guard-20261119T215743Z`. Earlier native fixture raw
`/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/escape-fixture-20261119T215605Z` remains. Workers326802,328070,
328762 are terminal. No B/stock/current-app/runtime gain is claimed.
