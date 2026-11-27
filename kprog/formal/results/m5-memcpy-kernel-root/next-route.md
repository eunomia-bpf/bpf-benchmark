# Compose the actual kernel memcpy path and bind its physical pair accesses

Current source: Arm64MemcpyIterationPhysical executes the original true
unsigned guard4, SAME complete reader/store body and actual unsigned
increment/backedge3 once. Actual destination load extends copied-prefix i+1
on the same Packet and preserves source flag/frontiers/frames plus both exact
admitted native byte-body states and ordered read/write history.

Current native: Arm64KernelMemcpyCode binds the real sole-kernel generic
memcpy first14 words. Committed artifact.json and inspect_artifact.py record
memcpy.o/vmlinux identical function bytes, input hashes/kernel revision/source/
loader symbol selection and the three entry aliases. Actual generic556B has
BTI, ADD X4,X1,X2; ADD X5,X0,X2; CMP/B.HI128; CMP/B.HI32; CMP/B.LO16;
LDP X6,X7,[X1]; LDP X12,X13,[X4,-16]; STP X6,X7,[X0];
STP X12,X13,[X5,-16]; RET. Runtime entry has BTI and MOPS alternatives.
Current Prologue executes the two actual ADDs on the SAME program/machine,
starting explicitly generic origin+4 after the landing pad, reaching +12 and
true pointer ends with arbitrary count/addresses and complete memory frame.
SmallGates executes EACH of the three actual CMP/branch pairs for count16;
actual flags derive and all three fall through, preserving GPRs/history/code.
Their inputs retain current comparison fetch plus next original-PC+4 branch
fetch. These are actual constituent steps; next compose them into one path.

FIRST SUBSTANTIVE SOURCE: UNIQUE results/m5-memcpy-kernel-small-prefix/Proof.lean
-> KProgFormal/ClightRefinement/Arm64KernelMemcpySmallPrefix.lean, both new.
Read Prologue.execute, SmallGates.execute/first/after and Code.transport.
On ONE Code origin and actual initial native machine at origin+4, count16
and no-error, execute the two ADDs and all three real CMP/branch pairs in
order. Derive each next current PC/program/no-error/count and both fetches
from that SAME original code certificate. Retain all eight actual Reference
steps/states and empty event/fault deltas, original source/destination/count,
computed X4/X5, actual final flags, full memory/profile/history/environment
frame, and final PC=origin+36 at the real first LDP. No fresh state/current
code/count premises for later comparisons. Use actual imported ISA bodies,
not local arithmetic or guessed helper loops.

Then bind the actual two LDP and two STP at count16. The two load addresses
repeat the same16bytes, as do both stores. Preserve those genuine repeated
native access events and pairSingleAccess/platform/permission/fault domains.
Relate their final physical bytes/permissions to the actual source16-byte
copy/copy-prefix, retaining different actual memory traces at their stated
observation granularity; the per-byte admitted fragment remains its own code
contract. Reuse completed imported checked memory/LDST pair semantics. Close
BTI landing-pad execution in the mature LNSym fork with its explicit branch-
protection projection/platform domain, then bind the actual runtime entry
alternative and genuine RET/LR code. Arm/Insts/BR/Hints.lean currently executes
NOP and takes its explicit Unimplemented result for the actual BTI hint;
record the concrete regression and fix that mature library path, preserving
all other hint/error domains. Runtime MOPS live patching is a distinct actual
feature/code binding; generic-path proofs keep that domain explicit. No
kernel/runtime/benchmark edits are needed for these proof steps.

Continue actual memset/native helper environment, tag transfer/clobbers/
free/caller, SAME original98-provider/fourteen-call entry packet and true
global code/provenance/physical input/output. Remaining universal O1/O2/O4
operand/fault/dispatcher domains and recount precede M6. Original XOR/resultWord/
byte80 source observer, single-step ReferenceMain and provider representations
retain their roles. Historical14 fixture/3 current-resource/353 full-call-
resource-prefix/0 universal ISA-family counts retain scope. LNSym aggregate
experimental Memcpy/VCG sorry/skip_proof results keep experimental scope;
completed imported operators supply this route.

First command AFTER authoring:

```
python3 /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/run.py memcpy-kernel-small-prefix-stage1 lake env lean -j1 results/m5-memcpy-kernel-small-prefix/Proof.lean
```

SH timing, CPU17/nice0/j1/32GiB, original200000/512 caps. Inspect directPASS,
MOVE SAME canonical, focus/public/record/ordinary own commit+push. Retain all
attempts. Consume all finite tasks in-turn. Existing committed marker means
inspect shared-staged-after/index sync and ordinary push SAME existing hash.
One full/root at related batch end under SH timing+EX formal-full-check;
V owns unified makecheck. Preserve raw/peer work/index and runtime/C/Clight/
ISA/reference/oracles/benchmark/settings/design/paper. End with exact state,
last and one readable COORD notice, with no detached finite task or STOP.
