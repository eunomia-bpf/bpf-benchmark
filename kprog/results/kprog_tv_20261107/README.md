# Translation validation increments, 2026-11-07 UTC

`checked-store-spills-final.log` records exit0 for private-spills-check and the
complete checked-first-block-check with its dependencies. The canonical store
transition now supplies complete native/BPF state shapes, actual execution
witnesses, equal ordered events/fault and corresponding PC for every first
fault and success. It runs on two actual memories with equal permissions;
the proof's private spilled memory is never replaced with native memory.
The previous equal-memory observation theorem is derived as its Eq instance.

`PrivateSpills.store_agrees` proves identical canonical writes preserve every
outside-frame byte and initialization bit, including wraparound.
`SimpleCheckedBlocks.store_with_spills` instantiates this relation and carries
both transitions to the exact accepted expanded verifier artifact. All short
writes and faults are retained by the trace projection. Its axioms are
propext/Classical.choice/Lean.ofReduceBool/Quot.sound, without sorryAx;
store_agrees uses only propext. Exact composing sources and generated program
arrays/checked snapshot inputs are in checked-store-spills-inputs.tar.gz.

This is a block composition result. Original-entry store/return paths and
whole-invocation/CPU-profile/binding composition still remain before claiming
the first whole-program certificate. No runtime, ISA, benchmark or paper changed.

Original-entry accepted and faulted store paths
---------------------------------------------

`checked-entry-stores-return-final.log` records exit0 for the exact source
`SimpleCheckedBlocks.lean`, after rebuilding its strengthened store dependency.
`passed_guards_store` composes the original entry, both passed guards and all
actual stores up to the first fault or return successor. Exact state-edge
identities, complete architectural shapes, actual spilled memory, exact ordered
writes/fault and corresponding PCs remain explicit. No writable-memory premise
was added. The canonical transition additionally proves no fault iff the BPF
store path reaches PC27.

`passed_guards_complete` appends the actual native trampoline and expanded
BPF JA/EXIT precisely on the no-fault branch, returning2 at native PC84 and
halted BPF PC29. A first fault appends no return and retains both exact
transition witnesses and full architectural shapes. Both original entry states,
guest-memory relation and exact projected read/write/fault trace are retained.
The two previously published rejection paths plus this result cover all guard
outcomes under the stated mapped-context/private-frame entry conditions.

Axioms remain propext/Classical.choice/Lean.ofReduceBool/Quot.sound, without
sorryAx. The initial statement elaboration error (untyped existential witnesses),
its corrected check, and frozen final sources/program inputs are retained in
checked-entry-stores-return-inputs.tar.gz. Whole-invocation safety composition,
CPU-profile and actual emitted-artifact binding are still explicit remaining
obligations; this does not declare a whole-program certificate or validate other
programs. No runtime/ISA/benchmark/paper changed.

Concrete simple safety for every native prefix, with acceptance and binding
-------------------------------------------------------------------------

`checked-simple-bound-prefix-final.log` records exit0 and no sorryAx for
matched_invocation, every_native_prefix_checked and bound_native_prefix_checked.
The first theorem exhausts all guard outcomes and constructs actual complete
native/proof executions, guest-memory agreement and exactly equal projected
traces. The canonical native end is closed: PC84 has no next instruction;
a first store fault can only repeat its already present fault event/state in
the prefix relation, whose state carries no halted bit. The strengthened store
certificate proves this fact from the same byte-decoded transitions, not a
second ISA or added runtime behavior.

The generic execution_checked_of_complete theorem uses determinism to extend
a complete-execution result to EVERY finite native execution prefix. It uses
only propext and no termination bound/fuel. Projected events retain their exact
identity, so every native event is among the actual proof execution's checked
events. bound_native_prefix_checked composes this concrete TV with explicit
verifier acceptance, admitted proof entry and exact Artifact equality binding
(code, entry, ABI and metadata); native bytes and entry are used to define the
executed step. The concrete theorems retain the existing
propext/Classical.choice/Lean.ofReduceBool/Quot.sound axioms.

Exactly the real-world bridges still required here are verifier soundness for
the accepted B under the bound context/platform and admitted initial state;
reference-ISA faithfulness to the selected CPU (lane F's hardware obligation);
and the trusted kernel/loader binding of that accepted snapshot, entry/ABI,
context expansion and specialization metadata to the emitted native artifact
and actual invocation. In particular before sets the explicit Cortex-A72
split-pair profile; the real invocation must establish it, rather than silently
changing a CPU profile in the proof. The Lean kernel and the existing
native_decide reduction oracle remain proof-checking trust. No all-program or
actual CPU-profile binding discharge is claimed by these conditional theorems.

Sources/program inputs, initial elaboration errors and final commands are
retained in checked-simple-prefix-inputs.tar.gz; source pins and dependency
check output are adjacent. Full existing dependency recheck follows separately.

Full existing dependency refresh for 083cc64b9
--------------------------------------------

`checked-simple-bound-full.log` records exit0 for the complete existing
`make -C kprog/tv checked-first-block-check`, including BPF semantics/platform,
canonical AArch64, regenerated exact native/clang/context/expanded arrays,
private spills, entry/guard/store certificates and concrete prefix/binding
safety. Every final theorem retains the reported axioms and no sorryAx.
This closes the pending dependency refresh; actual invocation/profile/emission
binding continues independently.

Actual ARM JIT entry binding and per-load theorem instances
---------------------------------------------------------

The opt-in capture_checked path records each final RX entry directly from the
ARM JIT callback's final_ip, together with blob/generation/ABI/extent and the
pinned source identity. Records reset with the checked snapshot on mutation;
readers obtain an immutable snapshot under blobs_lock. The loader checks the
reported entry against bpf_prog_info function ranges and exact JIT bytes before
writing emitted.bin and the final successful load.json. There is no byte search
or new default/performance admission rule. Matching module/loader versions are
needed only for the opted-in diagnostic export.

Both are actual loads of the same simple P, with distinct native IDs,
generations and RX addresses:

| source/native ID | generation | native bytes | expanded B insns | JIT entry | JIT offset | Lean instance |
| --- | --- | --- | --- | --- | --- | --- |
| 6/7 | 4 | 84 | 29 | 0xffff80008355d8b8 | 40 | PASS, conditional prefix safety |
| 6/8 | 8 | 84 | 29 | 0xffff80008355d970 | 40 | PASS, conditional prefix safety |

Actual full original/bound executions return2 with the exact8-byte packet change
and120 untouched bytes. Both generated SimpleEmitted modules prove that actual
emitted native/checked B equal the certified byte arrays, that the reported RX
entry selects those exact JIT bytes, and instantiate accepted_bound_prefix_checked
with the full per-load Artifact (entry/ABI/checked snapshot/emission metadata).
actual_jit_entry uses only propext; prefix safety retains the existing
propext/choice/ofReduceBool/Quot.sound and no sorryAx.

Validation: emitted-runtime.log contains the final-source ARM library/capture
build and real QEMU executions plus x86 host library build. The complete
simple-emitted-check and both Lean instances pass in emitted-certificates.log.
The36 site/JIT corruptions reject, including an intact decoy blob elsewhere.
Two metadata-consistent corruptions (native AND JIT store changed together;
actual checked B store changed) reject at the corresponding Lean byte-identity
theorems. Existing14 metadata/4 instruction/9 multichunk negatives and all41
retained x86 captures plus old ARM exports still pass; x86 module/control builds
pass. Raw negative output is in emitted-negatives.log. Two initial harness
mistakes (rfl term diagnostic wording; trying a log exporter on x86's directly
saved directory) are retained in the source/input archive, with the correct
actual-record controls and no production behavior weakened.

Remaining obligations are the actual kernel invocation/initial-state and
CPU-profile bridge (including Cortex-A72 split-pair semantics and native-PC
relocation), relocated-program final-patch TV, other micros/apps, and the
priority5 native-only trusted loading component. The kernel/JIT wrapper and
binding/capture code remain trusted, alongside verifier/platform soundness,
canonical ISA hardware faithfulness and the stated Lean reduction oracle.
Inventory remains not_validated until invocation obligations are discharged;
these successful per-load conditional theorems do not claim full pipeline
admission or all-program TV. No paper, benchmark, shared runtime image or native
ISA implementation changed. Exact source/program/negative inputs and source
pins are in emitted-inputs.tar.gz and emitted-source-pins.txt.

Canonical instruction and byte-fetch PC relocation
-------------------------------------------------

`SimplePCRelocation.all_instructions` proves PC translation for all21 actual
native instructions, retaining the entire architectural state and exact ordered
memory/fault effects; it covers both pair-access profiles and every first fault.
`step_at` lifts this to the real byte-decoded ARM64Path.step at any RX base and
any actual aligned program position. Native bytes are decoded only by V's
canonical semantics; existing exact decoder certificates are reused. No ISA,
ABI input or runtime code is changed. Both theorems use only propext/Quot.sound,
without sorryAx or a new bitvector reduction oracle.

The repository make target passes (pc-relocation-final.log); exact inputs and
initial finite-index/memory-match/range proof-development errors are retained in
pc-relocation-inputs.tar.gz. This is instruction/fetch transport. Lifting whole
executions and the per-load prefix safety theorem to actual RX addresses, plus
the actual initial-state/CPU-profile bridge, remains active.

Priority2: native callee-save ABI derivation and bound execution
--------------------------------------------------------------

F's actual load-only finding was `mov rbx,0x123456789abcdef0; mov eax,2; ret`
with zero ABI preservation metadata. Entry prologue stripping had been the only
source of the mask, so a bare body escaped host preservation. Native-link now
plans entry stripping once, collects actual writes over ALL reachable native
symbols (after entry register renaming/drop decisions), and fixes the mask
BEFORE tail-call cleanup is emitted. It accounts for subregister, implicit,
read/write and conditional writes to the existing four BPF-backed nonvolatile
registers RBX/R13/R14/R15. Rewritten instruction streams, including contiguous
raw builder chunks, are checked against that same mask. Kernel-mode .proof.o
metadata must cover the actual requirements; clearing its mask cannot override
them. The existing verifier/JIT binding checks then carry the same exact mask.

The final frozen HEAD+T-only source includes F's published LEA repair and excludes
C's unrelated ROOT partial-write WIP. Its source blob was checked byte-for-byte
against the private-index publication candidate. `x86-abi-unit.log`:79 Rust tests
pass. `x86-abi-elf.log`:15 real ELF cases pass,12 cleared metadata variants reject,
and declared supersets remain accepted. `x86-abi-kernel.log`: all6 actual KVM
controls load through the production manifest/proof/binding path. The actual
JIT is inspected for PUSH before and POP after the full native body, before
running safe positive controls; all6 then return2/packet0.

| native body | actual required mask | observed JIT preservation | result |
| --- | --- | --- | --- |
| bare RBX write | 0x1 | RBX | PASS |
| bare R13 write | 0x2 | R13 | PASS |
| bare R14 write | 0x4 | R14 | PASS |
| bare R15 write | 0x8 | R15 | PASS |
| all four | 0xf | RBX,R13,R14,R15 | PASS |
| caller-save EAX control | 0 | no requested nonvolatile save | PASS |

No unsafe old-mask native program was executed. The first KVM attempt lacked
an explicit source_btf_symbol selector and stopped at manifest selection; the
correct explicit selector was used for final tests. Initial private-source
syntax/test placement errors and the earlier pre-LEA-source receipts are retained
in x86-abi-inputs.tar.gz. Each final runtime record retains actual generations,
checked snapshots/native/JIT bytes and disassembly. Source/binary pins are
adjacent. The linker is a private debug build; this is correctness evidence,
not performance data. Kernel/image defaults and native ISA semantics are unchanged.

This closes the reported bare-write derivation hole for the existing four-bit
preservation contract. RBP/R12 retain their existing reserved/native frame ABI;
this increment does not prove that contract or replace translation validation.
The accepted B/native correspondence, SP flags and actual entry/CPU-profile
obligations remain separate. The producer/iced decoding and kernel binding are
trusted until the native-only loader and canonical TV discharge those layers.

Complete execution/prefix transport to actual captured RX addresses
-----------------------------------------------------------------

SimpleExecutionRelocation proves every native successor stays aligned within
0..84 (including the real return boundary), lifts canonical steps and complete
executions to any RX base, and transports the closed return/fault condition.
These invariants use only propext/Quot.sound. every_RX_prefix_checked then proves
that EVERY finite native execution at the rebased entry has only events checked
for the same expanded B. Full state is preserved with only PC translated; memory,
ordered guest effects and actual first faults remain unchanged. No executable
alignment/bounds guard, new entry input or second ISA is introduced.

Both actual GEN4/GEN8 SimpleEmitted records now additionally instantiate
accepted_RX_prefix_checked at their callback-reported concrete RX addresses,
using the same actual native/checked B byte identities and full Artifact binding.
The theorem retains explicit acceptance, admitted proof entry, verifier/platform
soundness and EntryConditions. It has the existing propext/choice/ofReduceBool/
Quot.sound and no sorryAx. The repository checker and both instances pass in
actual-rx-prefix-final.log. Both metadata-consistent native/JIT and checked-B
byte corruption controls still reject at the exact Lean identity theorems
(actual-rx-prefix-negatives.log). Source/program inputs and initial proof
normalization errors are retained in actual-rx-prefix-inputs.tar.gz.

The relative-PC-to-actual-RX execution obligation is now proved. The actual
invocation/initial-state and selected CPU-profile bridge remains explicit;
other micros/apps, relocated final-patch TV and the priority5 native-only loader
remain active. The complete dependency refresh against current canonical
sources follows separately; no full real-world invocation discharge is claimed.

`actual-rx-prefix-full.log` closes the pending complete dependency refresh:
`make simple-emitted-check` exits0 after rebuilding the canonical AArch64/BPF
models, exact arrays/platform/private entry/guard/store proofs, PC/execution
transport and BOTH actual RX-address theorem instances. The36 site corruptions
also reject in this run; all positive theorem axioms remain as stated without
sorryAx. This refresh includes current canonical sources, not only old cached
checker modules. Invocation/initial-state/profile work continues separately.


Actual-entry invocation and ABI preservation
-------------------------------------------

`invocation-abi-final.log` checks SimpleInvocationABI plus both actual GEN4/GEN8
accepted-entry instances. All 21 actual instructions and every RX prefix
preserve SP, all SIMD registers and x12..x30. The actual-entry state identity is
proved from explicit PC/x0/split-pair premises. The composed conclusion covers
all native events and host ABI preservation, using the existing exact B/native
identities, full artifact binding and admitted-verifier-entry hypothesis.
The ABI/entry identity proofs have only propext/Quot.sound; composed safety has
the existing propext/choice/ofReduceBool/Quot.sound and no sorryAx.

The same run repeats all36 emission/site/JIT corruptions and both coherent
native/JIT and checked-B byte mutations. Source/generated instances, raw
successful log and earlier proof-development failures are retained in
invocation-abi-inputs.tar.gz, with source pins adjacent. The entry contract,
proof-entry admissibility, verifier/platform soundness, canonical ISA/hardware
connection and immutable kernel binding remain explicit trusted obligations.
The tested target is the existing Cortex-A72/no-LSE2 QEMU recipe; runtime CPU
profile metadata enforcement is not claimed by this increment.

`invocation-abi-full.log` records EXIT0 for the complete `simple-emitted-check`
dependency chain after adding the actual-entry/ABI module: canonical models,
clang arrays, context/private entry, every guard/store/return path, actual RX
transport, ABI/entry identity and both accepted-entry instances. This supersedes
the earlier leaf-only validation for the new module. It does not supply a
runtime CPU-profile metadata check or certify another program.


`simple_packet`: fresh actual artifact and complete guard states
-------------------------------------------------------------

`packet-capture.log` contains two actual generation-bound QEMU Cortex-A72 loads
of the 68-byte native entry, paired with freshly compiled 200-byte B and the
26-instruction expanded B actually checked by the verifier. The source proof,
first native and second native controls all return2, write the exact expected
8 bytes and preserve the remaining120 bytes. Stable historical captures and
capture-IO failure propagation also pass. `packet-final.log` checks the complete
native/checked-B guard post-states and successor correspondence for arbitrary
inputs, repeats the36 emission/site corruptions for each simple-family fixture,
and repeats actual default-simple capture after parameterizing the harness.

The generated native/proof/checked arrays and source ELF/capture identities are
checked in Lean. Guard proofs retain the existing propext/choice/ofReduceBool/
Quot.sound dependencies; checked guard/successor facts use propext/Quot.sound
(or fewer). Initial hardcoded-simple extent rejection, generated array
recursion/normalization limits and the initial missing compiled dependency
are retained separately; final input checking uses the existing native_decide
for the exact finite byte-array prefix, with its printed axiom dependency.
Raw inputs, exact source/binary pins and failures are retained in packet-inputs.tar.gz.

This is a component certificate for simple_packet. Its entry/private-spill,
store/fault, return and every-prefix/accepted invocation composition remains
active. No application or other micro is certified by this result.


`simple_packet`: complete actual entry/guard block
------------------------------------------------

`packet-guard-full.log` records EXIT0 for the complete guard dependency refresh.
`packet-entry-final.log` adds successful original native LDP/physical entry,
actual virtual XDP context transport and the complete entry-through-guard block.
It retains every full state, both guest reads, the private-spill memory relation
and the exact corresponding store/reject successors. The two context-step
proofs have only propext/Quot.sound; the complete block has the existing
propext/choice/ofReduceBool/Quot.sound and no sorryAx. Entry memory/frame and
kernel context-conversion agreement remain explicit premises/trusted base.

Three coherent mutations reject at their semantic theorem: LDP destination at
PacketEntryCertificate.decode0, spill address at prefix_instruction, and
context offset at PacketCheckedPlatform.second_virtual. All preceding modules
are freshly rebuilt against each modified array definition. Earlier proof
normalization, typed-existential, source-root/search-path and finite-decision
errors are retained in packet-entry-inputs.tar.gz with final source, exact
generated arrays and mutation logs. No new runtime/image/native instruction or
performance condition is introduced. The store/fault, return and complete
accepted-invocation/ABI/RX obligations for simple_packet remain active.


`simple_packet`: complete guard rejection and every rejected prefix
----------------------------------------------------------------

`packet-return-final.log` proves the actual native return trampoline and
expanded BPF jump/EXIT for every return value. It composes both guard-rejection
outcomes from original entry through their real exits with full states,
private-memory relation and exact guest-event projection. The complete native
return ends at PC68, matching the inline artifact boundary. A deterministic
execution/closed-return argument then checks every arbitrary native execution
prefix on either rejection outcome under explicit soundness for the exact B.
All axioms are the existing propext/choice/ofReduceBool/Quot.sound, with no
sorryAx. New source, exact generated arrays and proof logs are retained in
packet-return-inputs.tar.gz. The actual RX/ABI/binding and store/fault path
composition remains active; this is not a whole-program certificate yet.
