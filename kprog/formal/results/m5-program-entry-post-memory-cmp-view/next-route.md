# Next M5 actual code admission for same-provider post-memory execution

Accepted this batch: PostMemoryControlNative executes original post-memcpy
JCC/CBZ/TBNZ source prefix once and feeds actual CMP/CALL/RET effects; the
PostMemoryReturnNative path adds real100 terminal transitions/freeList;
PostMemoryObserver preserves original MemoryReturn.resultWord exactly;
SourceReturnNative.execute preserves original provider prefixTrace from
Callstate to Returnstate and records four native facts on real live heap;
PostMemoryCmpView derives X3/X4/PC/error/code/fetch from exact original
provider NZCV/X3/X4 input views. No fresh current CMP state/word-match premise
is needed at that execute theorem. The view is a representation update, not
a new native/helper instruction. Actual native/helper memory execution and
full global program/input-oracle correspondence retain their domains.

FIRST NEXT SOURCE: UNIQUE
results/m5-program-entry-post-memory-code-admission/Proof.lean ->
KProgFormal/ClightRefinement/Arm64ProgramEntryPostMemoryCodeAdmission.lean.
Draft/canonical/label are uncreated. Read LinkReturnNative.Admission,
PostMemoryCmpView.code/pc/compare_fetch, CmpNative.resources/pc,
CmpBgtNative.pc and the imported fetch_inst definition. All Admission fields
are code/fetch/decoder facts; they depend on program and actual read_pc, not
arbitrary GPR/flags data. Prove transport of SAME Admission between full
native states with equal actual program and PC, retaining the original
instruction certificates, true imported BL target and continuation fetch.

ACTUAL TWO-SITE CODE: Real SUBS/B.GT reaches either its imported target
(from the actual decoded immediate at originalPC+4) or originalPC+8. Bind
actual BL/RET/decoded-continuation code at those TWO real sites once. Their
real BL immediates may differ. Use actual mature chosen ConditionHolds12
on same provider X3/X4 subtraction flags to select the corresponding true
Admission and actual callOffset, transporting code through unchanged program
and PC observations. Do not introduce an arbitrary callback or assumed
source/native theorem for every possible provider map. Do not guess bytes or
identify source token64 with physicalPC. Source raw64/tag9 and the actual
continuation are already separately witnessed by Observation.

Then use original MemoryCalls.compose output gprs/flags/vectors to derive
PostMemoryCmpView and choose that actual code Admission. Invoke existing
PostMemoryCmpView.execute on the SAME actual current Packet and memoryRun;
real helper/provider values then determine operands and branch choice rather
than a fresh reached native-state match. MemoryCalls.compose supplies actual
source helper execution/provider trace; native physical helper execution,
physical memory/provenance and global code/output observer are still explicit
separate obligations. Preserve original eight helper input families,300
provider inputs,352 stores/free, original98-provider/twelve-handler/fourteen
native prefix, cache/trace/rights/SP and source caller/return contracts.

OBSERVER: Actual original result XOR1/2/4/8 and byte80 are C oracle result
observers, not an invented guest instruction stream. MemoryReturn.resultWord
is the existing formal source observer; same-result equality is checked.
ReferenceMain.executeArm exports SINGLE-INSTRUCTION native state/events/fault,
not a completed independent whole-program scalar observer. Preserve this
scope and complete actual global/input/output correspondence before claims.

Complete related actual source/handler/caller/native/code-PC, then one batched
root/full check under EX formal-full-check + SH timing; prior root
b2247113a/1147/public970 and V1a3d6c178 retain their old scope. V owns makecheck.
Remaining universal O1/O2/O4 operand/fault/dispatcher domains and recount
precede M6; historical14 fixture/3 current-resource/353 full-call-resource-
prefix/0 universal ISA-family counts stay scoped.

FIRST COMMAND AFTER AUTHORING:
python3 /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/run.py program-entry-post-memory-code-admission-stage1 lake env lean -j1 results/m5-program-entry-post-memory-code-admission/Proof.lean

SH timing CPU17/nice0/j1/32GiB/original200000-heartbeat/512-recursion caps.
Direct PASS -> MOVE SAME canonical -> focused/public/record/ordinary own
commit+push, original hooks/locks/git/private own index. Consume every finite
task within turn; raw attempts and peer work stay. Existing committed marker
means inspect shared-staged-after/index-sync then ordinary push EXISTING hash;
no duplicate commit or history rewrite. Frozen runtime/C/Clight/ISA/reference/
oracles/benchmark/settings/design/paper stay as found.
