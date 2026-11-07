import Composition
import KProgFormal.Reference.X86
import Std.Tactic.BVDecide

/-! Universal native-link relocation obligations, independent of programs.
The checked cast/byte writer below mirrors x86 relocation kind1 at the Rust
producer/kernel emitter boundary. Decoding uses only the canonical ISA.
No helper identity/prototype or compiler correctness is assumed discharged. -/
namespace KProgTV.NativeLinkRelocation
open KProgFormal.Reference

/-- The existing kernel emitter's signed32 round-trip guard, expressed as
word bits. It rejects a distant target rather than silently truncating. -/
def checkedRel32 (slot target : Word) : Option (BitVec 32) :=
  let delta := target-(slot+(5#64))
  let narrow := delta.setWidth 32
  if narrow.signExtend 64=delta then some narrow else none

def callBytes (displacement : BitVec 32) : Array Byte :=
  #[0xe8,displacement.setWidth 8,(displacement >>> 8).setWidth 8,
    (displacement >>> 16).setWidth 8,(displacement >>> 24).setWidth 8]

theorem checked_rel32_target (slot target : Word) (displacement : BitVec 32)
    (accepted : checkedRel32 slot target=some displacement) :
    slot+(5#64)+displacement.signExtend 64=target := by
  dsimp only [checkedRel32] at accepted
  split at accepted
  · rename_i fits
    have same := Option.some.inj accepted
    rw [← same,fits]
    rw [BitVec.add_comm]
    exact BitVec.sub_add_cancel target (slot+(5#64))
  · contradiction

/-- The shared five-byte E8 slot, for every32-bit displacement, decodes to
its actual architectural relative CALL. This is not another decoder. -/
theorem decode_call_bytes (s : X86.State) (displacement : BitVec 32) :
    X86.decode (callBytes displacement) s=
      .ok (.call (.immediate (s.pc+(5#64)+displacement.signExtend 64)) (s.pc+(5#64))) := by
  have roundtrip : BitVec.ofNat 32
      (displacement.toNat % 256 + (displacement.toNat >>> 8) % 256 * 256 +
        (displacement.toNat >>> 16) % 256 * 65536 +
        (displacement.toNat >>> 24) % 256 * 16777216)=displacement := by
    apply BitVec.eq_of_toNat_eq
    have bound := displacement.isLt
    simp +decide [Nat.shiftRight_eq_div_pow,BitVec.toNat_ofNat] at *
    omega
  unfold callBytes
  canonical_x86_decode
  all_goals rw [roundtrip]

/-- Every successful kind1 relocation reaches exactly its bound target;
full CALL state/events/fault then use the SAME canonical instruction. -/
theorem checked_call_decode (s : X86.State) (target : Word) (displacement : BitVec 32)
    (accepted : checkedRel32 s.pc target=some displacement) :
    X86.decode (callBytes displacement) s=.ok (.call (.immediate target) (s.pc+(5#64))) := by
  rw [decode_call_bytes,checked_rel32_target s.pc target displacement accepted]

/-- Symbolic CALL after the existing load-time range check. This guard is
an emitter acceptance condition, not a newly inserted native instruction. -/
def intendedCall (target : Word) : BlockStep X86.State := fun before events after =>
  ∃ displacement effect, checkedRel32 before.pc target=some displacement ∧
    X86.Step (.call (.immediate target) (before.pc+(5#64))) before effect ∧
    effect.events=events ∧ effect.state=after

/-- The emitted CALL uses its real patched bytes and canonical decoder and
step. No decoded target, architectural result or effects are supplied. -/
def relocatedCall (target : Word) : BlockStep X86.State := fun before events after =>
  ∃ displacement instruction effect, checkedRel32 before.pc target=some displacement ∧
    X86.decode (callBytes displacement) before=.ok instruction ∧
    X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

/-- Universal one-transformation native-to-emitted relation. CALL memory,
control, register and fault behavior is exactly the single canonical ISA;
all caller states and all successfully ranged bound targets are covered. -/
theorem rel32_call_preservation (target : Word) :
    TranslationValidation (intendedCall target) (relocatedCall target) Eq := by
  constructor
  intro n p events next relation source
  subst p
  obtain ⟨displacement,effect,accepted,step,trace,state⟩ := source
  have emitted : relocatedCall target n events next :=
    ⟨displacement,.call (.immediate target) (n.pc+(5#64)),effect,accepted,
      checked_call_decode n target displacement accepted,step,trace,state⟩
  exact ⟨next,by simpa only [List.append_nil] using Execution.next emitted (Execution.refl next),rfl⟩

/-- Reverse preservation rules out an additional emitted control/memory
check hidden by the presentation: every emitted step is the intended CALL. -/
theorem relocated_call_reflects (target : Word) (before after : X86.State) (events : List Event)
    (run : relocatedCall target before events after) : intendedCall target before events after := by
  obtain ⟨displacement,instruction,effect,accepted,decoded,step,trace,state⟩ := run
  have same : instruction=.call (.immediate target) (before.pc+(5#64)) :=
    Except.ok.inj (decoded.symm.trans (checked_call_decode before target displacement accepted))
  subst instruction
  exact ⟨displacement,effect,accepted,step,trace,state⟩

/-- The four-byte immediate patch changes no code byte outside that range,
including initialization state, and changes no memory permissions. This is
written with the single reference memory writer, not another memory model. -/
theorem immediate_patch_preserves_outside (code : Memory) (slot : Word)
    (displacement : BitVec 32) (address : Word)
    (outside : ¬(address-(slot+(1#64))).toNat<4) :
    let patched := storeMemory code (slot+(1#64)) (displacement.zeroExtend 64) 4
    patched.value address=code.value address ∧ patched.initialized address=code.initialized address ∧
      patched.readable=code.readable ∧ patched.writable=code.writable := by
  simp only [storeMemory,outside,ite_false]
  trivial

end KProgTV.NativeLinkRelocation
#print axioms KProgTV.NativeLinkRelocation.checked_rel32_target
#print axioms KProgTV.NativeLinkRelocation.decode_call_bytes
#print axioms KProgTV.NativeLinkRelocation.checked_call_decode

#print axioms KProgTV.NativeLinkRelocation.rel32_call_preservation

#print axioms KProgTV.NativeLinkRelocation.relocated_call_reflects

#print axioms KProgTV.NativeLinkRelocation.immediate_patch_preserves_outside
