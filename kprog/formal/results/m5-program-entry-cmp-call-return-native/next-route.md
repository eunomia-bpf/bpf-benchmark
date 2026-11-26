# Next M5 post-memory source/control composition

Accepted current modules: Arm64ProgramEntryLinkNative (CALL68/three stores and
fetched mature BL), Arm64ProgramEntryReturnNative (RET_TO84/repeated LR store
and kernel-decoded RET X30), Arm64ProgramEntryLinkReturnNative (same actual
code Admission, source152, true native return PC and LR=callerPC+4),
Arm64ProgramEntryLinkReturnFrame (complete native state and derived current
source Packet/flags/resources), Arm64ProgramEntryCmpCallReturnNative (one
original CMP updated Packet and four real fetched SUBS/B.GT/BL/RET steps).
Current native register/code/fetch domains remain explicit. Observation retains
actual source64/tag9 and source LR64 readbacks alongside the PC-derived native
LR and genuinely fetched continuation; there is no raw64=physicalPC premise.

FIRST NEXT SOURCE: UNIQUE
results/m5-program-entry-post-memory-control-native/Proof.lean ->
KProgFormal/ClightRefinement/Arm64ProgramEntryPostMemoryControlNative.lean.
Both are uncreated. Read Arm64ProgramEntryTbnzComplete.from_memcpy, the new
CmpCallReturnNative.complete and original ReturnComplete.from_memcpy. Use the
SAME actual completed memcpy Packet/frame and original ctx.mark/saved result.
Invoke the complete source JCC/CBZ/TBNZ prefix once; its reached temporary env,
result and ctx feed the new actual CMP/CALL/RET composition. Retain all original
source label/caller shapes and actual CMP/link/repeated-LR Effects, final live
Packet, copied bytes, provider arrays and caller frame. Current native CMP
operand representation, genuine code/fetch and call Admission remain explicit;
its four-step suffix must consume THAT actual updated packet, not a second
source invocation, invented post-state or extra provider run. Reached flags
and resources derive from values/complete, rather than fresh caller premises.

SOURCE OBSERVER: oracles/arm64_execute_compile.bpf.c lines22-47 shows result
XOR1/2/4/8 is the original oracle's result observation around simulator macro
calls. Preserve its actual C execution/observable value. Relate it to the real
existing reference output contract, after inspecting the actual reference
fixture/tool implementation; do not invent guest instructions for oracle C
checksum statements. Earlier handoffs' phrase native checksum instructions
was an overly broad next-step description. The global source-label/native-code
map and full output-observer correspondence are still work, with the repeated
CURRENT/TARGET macro values kept as local source coordinates. Bind actual code
bytes/decodes and original labels, rather than guessing a physical layout or
identifying repeated source coordinates at one native PC.

Then connect actual native/helper memory and events, same source entry's
original98 provider inputs/twelve handler/fourteen native prefix and two memory
helpers, complete original terminal/free/low32 return observer, remaining
universal handler/operand/fault/dispatcher O1/O2/O4 domains and recount. M6
follows. Preserve actual300 helper provider inputs/352 stores/free/traces and
all prior cache/provenance/caller/code domains; no fixture scope becomes a
universal ISA family by relabeling. Previous root b2247113a/1147/public970 and
V1a3d6c178 retain their earlier scope. Complete related handler/caller/native/
code-PC before one root/full batch under EX formal-full-check and SH timing;
V owns makecheck.

FIRST COMMAND AFTER AUTHORING:
python3 /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/run.py program-entry-post-memory-control-native-stage1 lake env lean -j1 results/m5-program-entry-post-memory-control-native/Proof.lean

All checks/publications: SH timing, CPU17/nice0/j1/32GiB/original200000-heartbeat/
512-recursion caps, original hooks/locks/git/private own index. Direct finalPASS
-> MOVE SAME canonical -> focused/public/record/ordinary own commit+push.
Consume finite tasks within the turn and preserve peer work and every raw
attempt. A committed marker requires shared-staged-after/index-sync inspection
then ordinary push EXISTING hash; no duplicate commit/history rewrite.
