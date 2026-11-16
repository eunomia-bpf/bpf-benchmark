# M4 producer payload layout binding

The borrowed entry now carries typed payload load/store callbacks. Their bodies
expand the producer's actual macros, preserving its compact rank expressions
and volatile accesses. The generic C handlers call those bodies. The whole
program export define installs the binding at the end of the canonical ARM
header, after the producer's profile declarations. Native builds keep their
existing route. No second rank algorithm or numerical model is introduced.

The regression assembles `oracles/arm64_payload_profile.S`, then invokes the real
ARM parser/layout collector/renderer through `tools/export_arm64_payload_fixture.py`.
Its sole C output is `build/arm64_payload_profile.bpf.c`. Only the header include
is relocated for that build directory. The producer selects a 32-byte frame,
bias 32, and three payload words for logical slots 0,1,3. Two native `memcpy` calls
exercise storage and retrieval through logical slot 3/physical slot 2. The second
copy must restore overwritten destination metadata. The actual direct handlers
remain in the exported program; two existing numeric C adapters cover their
shift-expression syntax.

The native and two bound C modes agree on 16 cases/58,560 observation bytes each.
Independent expectations check high64 payload/return arithmetic and all 304
inputs per case. Zeroing callback indices, truncating load values and truncating
store values each fail that expectation; the normal object and executable are
restored. All raw attempts, including the initial two-word fixture and parser/
path diagnostics, remain under `/workspaces/kprog-raw/formal/m4-arm64-payload-profile`.
`make clight`, all 15 Clight modules/52 Lean jobs, five deterministic re-exports
and seven standard-axiom queries pass. Three mature linker computations resolve
136 actual definitions each and preserve their count. The producer export has
4 functions/2,938,946B; the callback-enabled handler module has 111/11,542,084B.
Native sections/relocations remain exact: producer socket 4,232 B/four relocations,
context XDP 1,152 B/TC 1,896 B/four relocations, dispatcher socket 11,104 B/
XDP 15,320 B/eight relocations. Normal current builds match streamed current builds.
Five existing modes still match 12,823 whole frames/28,557,200B and 840 closed RAW
return/input-stream cases/4,042,080B each, without masks. The receipt JSON records
all export and preprocessing sizes; these are extraction measurements, not
application compiler performance.

Reproduce with `make clight` in `kprog/formal`, then the Clight Lake targets and
`lake env lean -j1 oracles/test_arm64_program_link.lean`. The Makefile assembles
and renders the actual producer fixture before exporting and running it. The
full-frame comparison recipe remains `results/m4-arm64-execute/compare.py
--program --mutation helper-update-arg-swap --output <new-raw-directory>`.

This binds the producer's full and compact payload operations. It does not
establish all declaration-layout correspondence, arbitrary producer control-flow
closure, platform relations or whole-default compiled-byte coverage. The
stack-disabled context fixture remains context-only. M4 stays open; all 2,065
M5 refinements/recount and M6 retirement follow. No theorem migration is inferred
from these C/AST/link/finite-oracle checks.
