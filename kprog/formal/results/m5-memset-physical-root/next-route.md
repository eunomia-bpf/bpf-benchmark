# Continue actual memcpy byte reads and complete native helper memory

The root now imports Arm64MemsetStorePhysical. Its actual original producer
bias/index/action route executes both real tag and byte stores once, then the
SAME effects refine one genuine fetched STRB W1,[X0]. Actual View/Resources
supply writable ranges, allocation separation, caller frame and current View.
Source indices64..79 map through bias96 to physical origin-32..-17. The mapped
relation retains arbitrary uninitialized contents/source Vundef, permissions,
initialization elsewhere and the complete native frame. One real ordered
write event appends to the native history; source private tag stores retain
their implementation role. Exact input relation/code/register bindings remain
visible. This is the actual per-byte route, with complete native helper-loop
execution and whole-program integration continuing next.

First substantive source: create UNIQUE
results/m5-memcpy-physical-byte-read/Proof.lean ->
KProgFormal/ClightRefinement/Arm64MemcpyPhysicalByteRead.lean (both new).
Read MemsetPhysicalByte.Represents/address, MemsetByteNative.reference_step,
MemcpyReadByte.builtin/execute/of_packet (original nine-transition volatile
read route), MemsetPointerState.Packet.written, ClobberMemoryState.Packet,
and imported LNSym MemoryMode.read and LDST/Reg_imm.

Consume the actual source Mint8 load at a mapped Fin160 index. Derive native
read permission and initialized=true from that successful concrete source
load and Represents: the source Vint byte rules out Vundef. Derive the same
native byte, preserving all memory/profile/other native fields while
appending its genuine read event. Use imported MemoryMode.read checked1,
not a second local memory interpreter. Source memory remains the SAME heap.
Then pair the real original C reader with fetched imported LDRB W3,[X1]
(the candidate word39400023 must be kernel-decoded before use), retaining
native zero-extension/register frame, actual PC+4 and source continuation.
Actual source packet.written supplies the completed memset source bytes;
keep its real source/tag/vector/ABI/SP/provider/caller facts.

The paired memcpy store needs that loaded W3 while retaining X1 as the source
pointer. Generalize the mature byte-store proof to its actual data-register
field, preserving the current W1 interface, or add the actual STRB W3,[X0]
instance through the shared imported instruction proof. Decode actual word
39000003. Preserve source address/index setup and private tag store. Do not
replace true helper execution with fabricated provider outcomes or an assumed
source/native theorem. Prove actual base increments/length/branch code and
finite sequences before claiming a full native helper loop.

LNSym's Experiments/Memcpy files were inspected: Memcpy.lean:61 and the tail
of MemCpyVCG.lean contain sorry; the VCG experiment also has skip_proof. The
new byte route uses completed imported checked memory and instruction
semantics, with exact actual axiom queries. Aggregate experimental memcpy
results retain their experimental scope and are not imported as completed
callee proofs. No upstream change is needed for these byte operations.

Continue full helper/environment, actual original global program/physical
input/output observations, universal O1/O2/O4 handler/operand/fault/dispatcher
domains and recount before M6. Existing source XOR/resultWord/byte80 observer
and provider input views keep their precise roles. Historical14 fixture/3
current-resource/353 full-call-resource-prefix/0 universal ISA-family counts
retain their scoped meaning.

First command after authoring:

```
python3 /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/run.py memcpy-physical-byte-read-stage1 lake env lean -j1 results/m5-memcpy-physical-byte-read/Proof.lean
```

SH timing, CPU17/nice0/j1/32GiB and original200000/512 caps. Inspect direct
receipt before moving SAME passing draft canonical, then focused/public/
record/ordinary own commit+push. Preserve every failed receipt. Consume all
finite tasks within turn. Existing committed marker: inspect shared-staged-
after/index sync and push SAME existing hash ordinarily. One root/full batch
under SH timing+EX formal-full-check; V owns unified makecheck. Frozen runtime,
C/Clight/ISA/reference/oracles/benchmark/settings/design/paper and peer work
stay as found. End with state/last, raw receipt and one readable COORD notice.
