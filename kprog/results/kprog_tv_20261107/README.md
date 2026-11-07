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
