# Typed ARM helper C roots

All95 actual `ARM64_SIM_BPF_CALL_*` bodies now export through typed-callee
roots in the existing addressing translation unit. The explicit C parameter
table copies the pinned libbpf declarations, including its conditional fastcall
token. Repeated inclusion instantiates declarations/definitions; builds never
generate C from a separate semantic contract. `Arm64Addressing` now has138
functions/22,050,154 bytes. `Arm64Numeric` remains21/171,547 bytes.

Each root's callee parameter shadows libbpf's BPF-only numeric function pointer,
so Clight can execute an ordinary supplied function pointer. The root still
invokes its original production macro. Existing exported clobber, argument and
context bodies are called at the original sites; there is no runtime helper-ID
switch or second helper implementation. The parameter's type alone does not
identify a kernel helper: M5 must bind the actual selected helper/callee and
its complete kernel effects through the platform relation. This extraction
is not a proof of those effects or the production caller binding.
The names/IDs are public libbpf identities. The selected kernel target may
have a different symbol name; M5 must bind the actual `get_func_proto` target,
rather than infer helper semantics from spelling or substitute another ID.

Four void-helper GNU result expressions share a statement adapter for CompCert;
native compilation retains the original expression, zero result and ordering.
XDP refresh's extraction path reuses the established full-pointer field boundary,
committing data before reading data_end. Native assignments remain unchanged.
This avoids using a plain host UAPI32 field as the model of a verifier-widened
native pointer. The existing platform import still needs its concrete native/
Clight interpretation in M5; no new import or pointer-value fallback is added.

The compiler checks all95 callee types against libbpf; the oracle also checks
all95 numeric IDs. Runtime checks exercise12 helper bodies across1,280 complete
private-state cases: scalar/u32/pointer/void results, map arguments, variadic
arguments, five-argument dynptr operations, external memory effects, zero/error
returns, metadata transfer and caller clobbers. Hooks check the call precedes
clobbers and the result is written before the first clobber draw. One separate
full64-bit-length refusal case reaches the callee without a narrowed length.
These are supplied platform-callee fixtures exercising the real surrounding C,
not executions or proofs of the95 kernel helpers.

Together with the prior instruction/libc/control cases, historical4a2b31f48,
current-native and CompCert-adapter modes each capture12,823 complete states/
28,557,200 bytes. Every serialized byte, callback event and ordered prefix agrees,
without masks. Independent physical-context tests cover all three XDP adjustment
helpers:6 native-host cases and18 adapter cases, including high64 pointer values,
refresh after helper success/error and first/second read refusal prefixes.
Process-local pointer objects are checked directly outside the cross-process
capture; host UAPI32 fields are not claimed equal to the high64 adapter view.
The prior adapter physical-read refusal check also remains green.

Six new negative cases pass: one intentionally wrong callee return type fails
its ABI compilation assertion; runtime assertions catch effects before the void
call, a nonzero void result, wrong refresh field, truncated pointer and swapped
map arguments. All11 retained negatives also pass. The common recipe accepts
exact named negative cases so a changed subset can be checked without rebuilding
every negative fixture. An early matrix varied an unused length axis for all
helper types; it passed, remains in raw data and was reduced before the final
comparison. No failed assertion was removed or input domain narrowed in the C.

Final `make clight`, all ten Clight modules/47 Lake jobs, deterministic exports
and eight AST-root/program axiom queries pass. Only the standard three axioms
occur. The final138-function ARM module builds in230 seconds with CPU15,
actual `-j1` and the unchanged32GiB address-space limit. Extraction CPP is
2,306,299 bytes, not an application-scale expansion factor. The expanded BPF
fixture retains11,104 socket bytes and adds15,320 XDP bytes, covering all four
void forms and three refresh paths. Both allocated sections and all eight
relocations exactly match historical5aeda3e2e; current replay equals ordinary
compilation. Compile-fixture parity is not whole-default byte coverage or an
application/runtime result.

The separate PERF review confirms the pinned Clight `VolatileLoad/Store.nonvol`
rules use ordinary memory operations and an empty trace for non-global local
blocks. This supports its private-arena event interpretation; eliminating or
reordering accesses still needs value, memory and alias preservation across
real helpers. That O2/compiler correspondence remains M5 work, not a new gate.

Reproduce the common comparison from `kprog/formal` with CPU15/32GiB and
`python3 results/m4-arm64-execute/compare.py --output <new-raw-dir>`; repeat
`--mutation <exact-name>` for a focused subset. Commands, signatures, initial/
final captures, negative checks and final confirmation remain under
`/workspaces/kprog-raw/formal/m4-arm64-helpers`.

M4 still needs entry/program-continuation binding, remaining real producer/
storage profiles, platform correspondence and whole-default bytes. The empty
return-to table root is not program closure. Then M5 must migrate all2,065
actual Clight-vs-LNSym/x86lean refinements and recount O1/O2/O4; M6 and the final
whole-library `lake build`/`make check` follow. No refinement theorem migrated
in this extraction step; inherited discrepancies remain unresolved.
