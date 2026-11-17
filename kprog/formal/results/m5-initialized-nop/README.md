# Linked NOP contract with a source-constructed entry

`Arm64InitializedNop.initialized_nop_contract` begins with the proved successful
initialization of the actual linked program globals. The actual producer call
then constructs its live entry through all 98 input visits. This supplies the
concrete register relation previously assumed by the linked NOP contract.
Provider outcomes, post-memories and native invocation bindings stay explicit;
no starting GPR/tag/table/flag/vector contents or successful global initMem are
assumed.

For arbitrary ignored operand values and flags, the real generic handler at
block 85, with width callee 66, executes the actual 19-transition NOP procedure.
Its entry argument is the source-constructed pointer. Every finite handler
execution is a silent prefix of that return, infinite execution is impossible,
and every observed top-level return is Vundef with the concrete register
relation for the mature NOP step at PC + 4. The actual native fetch and no-error
premises remain explicit.

The producer's caller frontier begins at global block 189. The proof derives
that the reached producer frontier is at least 189, then preserves exact global
contents and both permission maps through producer setup and handler allocation,
execution and free. This includes the existing function, readonly-string and
stderr resources. The final register relation uses the OLD reached producer
frontier; it does not equate that frontier with the handler's later nextblock.

The source pauses before invoking continuation(entry*) returning uint. The
handler procedure takes nine arguments and returns void. These are separate
semantic boundaries, with no invented Step2 edge or closed-program claim.
Native memory/permission/provenance binding, physical aliases/ABI, runtime
provider availability and complete handler/control refinement remain open.
M5/M6 and O1/O2/O4 recount remain open; complete ISA-handler refinement count
is 0.

Focused Lake passes 172 jobs and full Lake passes 299 jobs. The public
type/axiom query passes; the axiom list contains only ordinary
propext/Classical.choice/Quot.sound and the previously imported external/assembly
semantics. No new semantic axiom, provider implementation or C body is added.
All 23 exports (243488732 bytes) remain byte-identical to 9c617740f. Every check
passes on its first attempt at unchanged proof limits; full Lake ran once on
final source. Existing primitive source/ABI checks are not duplicated.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64InitializedNop
lake env lean -j1 results/m5-initialized-nop/Query.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-initialized-nop. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
