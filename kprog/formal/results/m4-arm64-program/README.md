# M4 ARM program bindings

`c/Arm64Program.c` expands the canonical instruction, libc and 95 helper bodies
against the borrowed `Arm64Entry` view. Register cells, coordinates, flags,
vector lanes and private storage remain the caller's live objects. No dense
register cast, state copy or second numerical model is introduced. Vector-lane
accessors retain their native expansion; an entry hook constructs the view only
in the extraction binding. The common constructor records actual declaration
sizes, including stack-disabled storage, and leaves private bytes/payload unread.

`Arm64ProgramFixture.c` and `Arm64ProgramContext.c` include the existing fixtures
without editing or copying their bodies. The actual labels, CALL and nonempty
RET table remain in that source. Calls resolve to genuine exported C handlers,
with typed external helper/kfunc targets still supplied by the platform.
libbpf's section attributes are retained without declaration-splitting pragmas.

The handler module exports 111 functions/11,497,120B, including its shared width
helper. The two-function CALL/RET fixture is 668,616 B; the two-function XDP/SKB
fixture is 1,858,226 B. Entry remains 3 functions, now 837,600 B. All four regenerate
exactly. `make clight`, all 14 Clight modules/51 Lean jobs and eight axiom queries
pass; only `propext`, `Classical.choice`, `Quot.sound` are reported. The mature
`CC.Link.linkProgramsRenaming` computation links each fixture with the handler
and numeric modules and checks their internal definitions (134 per fixture).
This is a link computation, not a refinement theorem.

Historical C, current native/adapter C and borrowed native/adapter C have exact
28,557,200B captures per mode: 12,823 complete frames, including 7,788 borrowed
handler/libc/helper cases and 5,035 retained control-root cases. The independent
memory dispatcher oracle also passes its scalar, signed, paired, exclusive,
atomic, provenance and refusal checks. The actual closed RAW fixture executes
840 cases per mode, with exact return values and complete input streams:
4,042,080B each. Nothing is masked. XDP helper functions are exported and checked
through typed-helper oracles; the closed runtime comparison is RAW only.

Five new negatives catch vector/GPR/context reference aliases, coordinate-cache
aliasing and a wrong target in the actual return table. The existing clobber
negative is retained. The final reduced oracle capture again matches historical
C byte for byte. Both native fixtures retain exact allocated bytes/relocations:
context XDP 1,152 B/TC 1,896 B/four relocations and dispatcher socket 11,104 B/
XDP 15,320 B/eight relocations; streamed current builds equal normal compilation.

Extraction preprocessing is 367,022 B for the program calls plus 1,408,251 B for the
shared handler TU. These are formal extraction measurements, not an application
expansion factor or a native compiler speed improvement. Full payload layouts
are bound here; sparse payload ranks, real producer profiles, platform relations
and whole-default byte coverage remain M4 work. The stack-disabled fixture
checks context operations only; general private-memory/helper behavior for that
declaration profile remains unbound. Existing ARM RET discrepancies
remain open. M5 still requires all 2,065 refinements/recount, followed by M6 and
the whole-library checks.

Reproduce from `kprog/formal` with `make clight`, the 14 Clight module Lake targets,
and `lake env lean -j1 oracles/test_arm64_program_link.lean`. The existing
`results/m4-arm64-execute/compare.py --program --mutation clobber-vector31-high
--output <new-raw-directory>` runs all five full-frame/closed-program phases.
Complete recipes/results remain under `/workspaces/kprog-raw/formal/m4-arm64-program`:
`closed-frames/`, `finish-retry/`, `make-clight.log`, `all-clight-lean.log`,
`link.log`, `final-frames.json` and `final-frames.log`. Initial orchestration,
SEC-parser and ineffective-unused-macro negative attempts remain as evidence;
the corrected terminal runs determine the results above.
