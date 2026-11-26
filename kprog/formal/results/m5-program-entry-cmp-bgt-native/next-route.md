# Next M5 native control and code route

Accepted current modules: Arm64ProgramEntryJccNative, Arm64ProgramEntryJccSourceNative,
Arm64ProgramEntryJccDecoded, Arm64ProgramEntryRegisterBranchNative (Cbz/Tbnz),
Arm64ProgramEntryCmpNative, Arm64ProgramEntryCmpBgtNative. These connect complete
original source callers to genuine imported fetched steps on explicit current
packet/register/code domains. The first JCC real CURRENT64/TARGET32 is -32;
CBZ W3 is +32; TBNZ X4,#63 is -32. Source false XOR1/2/4/8 and common source
labels remain real source paths; their native fallthrough/code map is continuing
work. Native helper memory/event correspondence remains explicit continuing work.

The original CURRENT/TARGET macro coordinates repeat across source sites. Each
local fetched form has its checked relative displacement; a global physical
layout and the true source labels are a separate relation. Repeated source
coordinates do not establish a shared physical-PC map or a composed native
program. Keep each actual fetch admission and discharge the global map from
real code; do not silently identify different source sites at one native PC.

FIRST NEXT SOURCE: UNIQUE results/m5-program-entry-link-native/Proof.lean ->
KProgFormal/ClightRefinement/Arm64ProgramEntryLinkNative.lean (uncreated).
Read Arm64ProgramEntryLinkComplete.lean Result/execute (68 genuine source steps),
Arm64ProgramEntryLinkCall/LinkWriter/LinkWritten/LinkLabels and ReturnComplete
from_call (152 original source transitions including full RET_TO84). Actual
source LR local=64, X30 raw64/tag9, three actual CALL stores and repeated LR store
in RET_TO remain in effects, source calls, packet and caller frame.

Reuse mature BR.exec_uncond_branch_imm/Uncond_branch_imm_inst.branch_taken_pc:
BL op1 imm26 writes X30=originalPC+4 and selects the actual signed branch target.
Use genuine instruction.valid/decoded/fetch/noError and exact complete state,
old histories and empty increments. No hand-written ISA arithmetic. Preserve all
fields except PC/X30, plus complete resources/code. Then mature plain RET X30
(opc2/op2=31/op3=0/op4=0/Rn30; word0xd65f03c0) uses the captured true LR and
preserves it. A fetched BL -> fetched RET sequence derives return PC=callerPC+4;
current code at BL's actual target supplies the genuine RET fetch.

CODE RELATION: source raw64/tag9 and RET_TO switch64 are source control tokens.
Relate token64 to the real continuation PC via actual code/admission; do not
replace a code relation with raw64=physicalPC or guess target bytes. Existing
Reference.Provenance.AArch64 materialize handles stack4/return10; code9 is kept
numeric and labels are explicitly separate there. Arm64Registers.ValueRep is
scalar/pointer coordinate representation, not an existing native-code map.
Retain this distinction when composing LinkComplete.Result.link/lr_readback and
ReturnComplete.execute's original source observed raw64/tag9 guard/switch.
The same completed memcpy packet, updated CMP flags and genuine stored/read
values feed this route, not a second producer/provider invocation.

Then complete remaining native/code/PC and false-path source checksums, bind
actual helper/provider memory/events, universal handler/fault/dispatcher O1/O2/O4
domains and recount; M6 follows. Original source entry ResultStackRights invokes
all98 provider inputs/twelve handler calls with derived resources/SP=-32 and
complete original source return; retain both helpers' actual300 provider inputs,
352 stores/free/traces, thirteenth/fourteenth MOV Results and true caller frame.

FIRST COMMAND AFTER AUTHORING:
python3 /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/run.py program-entry-link-native-stage1 lake env lean -j1 results/m5-program-entry-link-native/Proof.lean

Resources: shared timing lock, CPU17/nice0/j1/32GiB/original200000-heartbeat/512
recursion caps. Direct finalPASS -> MOVE SAME canonical -> focused/public/record/
ordinary own commit+push with original hooks/locks/git/private own index. Consume
finite tasks within turn, preserve peer work and every raw attempt. Existing
committed marker means index/shared-staged-after inspection then ordinary push
EXISTING hash, never duplicate commit/history rewrite. Whole related root/full
batch follows complete handler/caller/native/code-PC under EX formal-full-check
and SH timing. V owns makecheck; previous root/full receipts retain their scope.
