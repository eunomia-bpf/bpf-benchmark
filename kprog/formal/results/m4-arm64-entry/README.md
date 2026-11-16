# M4 ARM entry continuations

`c/Arm64Entry.c` expands the actual RAW, XDP and SKB entry macros, then calls
a typed continuation borrowing their live locals. Register cells remain separate;
the view takes their addresses. Private bytes and payload are passed without
reading or initializing them. The SKB root takes the actual context-cast callee;
its identity and kernel effects remain a platform obligation. XDP initialization
uses the existing full-pointer context import under CompCert, with the original
native initializer preserved.

The default 160-byte/bias 96 export has 3 functions/840,530B and regenerates exactly.
`make clight` and all eleven Clight modules/48 Lean jobs pass; four axiom queries
report only `propext`, `Classical.choice`, `Quot.sound`. The native and adapter
oracles each check 448 initialized continuations per storage profile, including
six capacity/bias pairs and distinct SKB cast results. The historical native
header also passes 448 cases. One cast refusal per mode and two adapter context
refusals preserve their prefixes. Six mutations detect coordinate aliases,
vector-lane swaps, helper-context aliases, wrong X0 binding, cast bypass and
truncated packet pointers. Tests write private storage before reading it.

Native context fixture XDP 1,152 B/TC 1,896 B/four relocations and dispatcher fixture
socket 11,104 B/XDP 15,320 B/eight relocations match the previous header exactly.
Both streamed current builds match normal compilation. These are fixture checks,
not whole-default byte coverage. Preprocessed extraction TU 316,867 B is not an
application expansion factor.

Run `make clight` and `lake build KProgFormal.Clight.Arm64Entry` from
`kprog/formal`; the Makefile includes both entry oracle modes. Full commands,
streamed historical/mutant checks, profile recipes and logs are retained under
`/workspaces/kprog-raw/formal/m4-arm64-entry` (`validate.py`, `commands.json`,
`validation-results.json`, `validation-terminal.json`, `all-clight-lean.log`,
`axioms.log`, `fidelity-*/comparison.json`). Small receipts are in `result.json`.

This is an entry-segment export with an explicit continuation hole. It does not
bind arbitrary producer label/PC tables or migrate a refinement theorem. Only
the default entry profile is exported; other profile checks execute host C.
M4 remains open, followed by all 2,065 M5 refinements/recount and M6 retirement.

A direct export probe of the existing complete `arm64_execute_compile.bpf.c`
fixture still exits2 at the GNU `KPROG_ARM64_MOV_PTR_TAG_PATH` expression inside
`RUN_OP`. The numerical facade used by the instruction root has not yet been
bound in this program context. Its preprocessed fixture is26,822,809B; this is
not an application scale result. `program-probe.log` and
`program-preprocess.log` retain the failure and expansion for the next M4 step.
