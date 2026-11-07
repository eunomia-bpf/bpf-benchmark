import NativeLinkRelocationTable
import KProgFormal.Reference.AArch64
import Std.Tactic.BVDecide

/-! Universal AArch64 kind3 relative helper-call encoding. Canonical AArch64
supplies decoding and the complete link-register/control transition. The
kernel signed division/cast/mask writer feeds the actual emitted-step relation. -/
namespace KProgTV.NativeLinkArmBL26
open KProgFormal.Reference

def displacement (immediate : BitVec 26) : Word := immediate.signExtend 64 <<< 2

def checked (slot target : Word) : Option (BitVec 26) :=
  let delta:=target-slot
  let immediate:=(delta>>>2).setWidth 26
  if displacement immediate=delta then some immediate else none

/-- The existing aligned signed26-unit emitter guard, written in64-bit words.
Signed division uses the same truncation toward zero as the kernel expression. -/
def kernelGuard (delta : Word) : Prop :=
  delta &&& 3=0 ∧ (BitVec.ofInt 64 (-(2^25))).sle (delta.sdiv 4)=true ∧
    (delta.sdiv 4).sle (BitVec.ofInt 64 (2^25-1))=true

theorem signed_div_four (delta : Word) :
    delta.sdiv 4=if delta.msb then -((-delta)>>>2) else delta>>>2 := by
  have unsigned (value : Word) : value / (4#64)=value>>>2 := by
    change value / (BitVec.twoPow 64 2)=value>>>2
    exact BitVec.udiv_twoPow_eq_of_lt (by decide)
  unfold Word at *
  cases sign : delta.msb <;>
    simp [BitVec.sdiv_eq,sign,unsigned,show (4#64).msb=false from rfl]

theorem guard_equivalence (delta : Word) :
    kernelGuard delta ↔ displacement ((delta>>>2).setWidth 26)=delta := by
  unfold kernelGuard displacement
  rw [signed_div_four]
  unfold Word at *
  bv_decide

theorem checked_target (slot target : Word) (immediate : BitVec 26)
    (accepted : checked slot target=some immediate) : slot+displacement immediate=target := by
  dsimp only [checked] at accepted
  split at accepted
  · rename_i fits
    have same:=Option.some.inj accepted
    rw [←same,fits,BitVec.add_comm]
    exact BitVec.sub_add_cancel _ _
  · contradiction

def encoding (immediate : BitVec 26) : BitVec 32 := 0x94000000 ||| immediate.zeroExtend 32

def branchBytes (immediate : BitVec 26) : Array Byte :=
  (valueBytes ((encoding immediate).zeroExtend 64) 4).toArray

theorem bytes_word (immediate : BitVec 26) :
    littleEndian 32 (branchBytes immediate).toList=encoding immediate := by
  simp +decide [branchBytes,valueBytes,littleEndian,List.range_succ,List.range_zero,List.map_append]
  unfold Word at *
  bv_decide

/-- A masked32-bit word fact transports to the canonical decoder's Nat view. -/
theorem nat_mask (word mask result : BitVec 32) (same : word &&& mask=result) :
    word.toNat &&& mask.toNat=result.toNat := by
  rw [←BitVec.toNat_and,same]

theorem nat_mask_ne (word mask result : BitVec 32) (apart : word &&& mask≠result) :
    word.toNat &&& mask.toNat≠result.toNat := by
  intro same
  apply apart
  apply BitVec.eq_of_toNat_eq
  simpa only [BitVec.toNat_and] using same

/-- Every26-bit field decodes through the shared canonical AArch64 decoder. -/
theorem decode_branch_bytes (immediate : BitVec 26) :
    AArch64.decode (branchBytes immediate)=.ok (.branchLink (displacement immediate)) := by
  have first : (encoding immediate).toNat &&& 0xfffff0ff≠0xd503305f :=
    nat_mask_ne _ (0xfffff0ff#32) (0xd503305f#32) (by unfold encoding; bv_decide)
  have load : (encoding immediate).toNat &&& 0xbfff7c00≠0x885f7c00 :=
    nat_mask_ne _ (0xbfff7c00#32) (0x885f7c00#32) (by unfold encoding; bv_decide)
  have store : (encoding immediate).toNat &&& 0xbfe07c00≠0x88007c00 :=
    nat_mask_ne _ (0xbfe07c00#32) (0x88007c00#32) (by unfold encoding; bv_decide)
  have pair1 : (encoding immediate).toNat &&& 0x7f800000≠0x29000000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29000000#32) (by unfold encoding; bv_decide)
  have pair2 : (encoding immediate).toNat &&& 0x7f800000≠0x28800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x28800000#32) (by unfold encoding; bv_decide)
  have pair3 : (encoding immediate).toNat &&& 0x7f800000≠0x29800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29800000#32) (by unfold encoding; bv_decide)
  have scaled : (encoding immediate).toNat &&& 0x3b000000≠0x39000000 :=
    nat_mask_ne _ (0x3b000000#32) (0x39000000#32) (by unfold encoding; bv_decide)
  have mode1 : (encoding immediate).toNat &&& 0x3b200c00≠0x38000000 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000000#32) (by unfold encoding; bv_decide)
  have mode2 : (encoding immediate).toNat &&& 0x3b200c00≠0x38000400 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000400#32) (by unfold encoding; bv_decide)
  have mode3 : (encoding immediate).toNat &&& 0x3b200c00≠0x38000c00 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000c00#32) (by unfold encoding; bv_decide)
  have mode4 : (encoding immediate).toNat &&& 0x3b200c00≠0x38200800 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38200800#32) (by unfold encoding; bv_decide)
  have nop : (encoding immediate).toNat≠0xd503201f := by
    intro same
    have eq : encoding immediate=(0xd503201f#32) := BitVec.eq_of_toNat_eq same
    have apart : encoding immediate≠(0xd503201f#32) := by unfold encoding; bv_decide
    exact apart eq
  have branch : (encoding immediate).toNat &&& 0xfc000000=0x94000000 :=
    nat_mask _ (0xfc000000#32) (0x94000000#32) (by unfold encoding; bv_decide)
  have field : BitVec.ofNat 26 (encoding immediate).toNat=immediate := by
    change (encoding immediate).setWidth 26=immediate
    unfold encoding
    bv_decide
  generalize replaced : branchBytes immediate=bytes
  have size : bytes.size=4 := by
    rw [←replaced]
    simp only [branchBytes,List.size_toArray,valueBytes,List.length_map,List.length_range]
  have word : littleEndian 32 bytes.toList=encoding immediate := by
    rw [←replaced]
    exact bytes_word immediate
  simp only [AArch64.decode,size,ne_eq,not_true_eq_false,
    if_false,word,first,load,store,pair1,pair2,pair3,or_self,
    beq_eq_false_iff_ne.mpr scaled,beq_eq_false_iff_ne.mpr mode1,beq_eq_false_iff_ne.mpr mode2,
    beq_eq_false_iff_ne.mpr mode3,beq_eq_false_iff_ne.mpr mode4,Bool.or_self,nop,branch,if_true,field,
    Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  rfl

theorem checked_displacement (slot target : Word) (immediate : BitVec 26)
    (accepted : checked slot target=some immediate) : displacement immediate=target-slot := by
  dsimp only [checked] at accepted
  split at accepted
  · rename_i fits
    have same:=Option.some.inj accepted
    rw [←same]
    exact fits
  · contradiction

theorem checked_rejects (slot target : Word) (outside : ¬kernelGuard (target-slot)) :
    checked slot target=none := by
  dsimp only [checked]
  have mismatch : displacement (((target-slot)>>>2).setWidth 26)≠target-slot := by
    intro same
    exact outside ((guard_equivalence _).mpr same)
  exact if_neg mismatch

/-- Alignment makes signed division and the retained low26 shift field agree. -/
theorem kernel_field (delta : Word) (aligned : delta &&& 3=0) :
    (delta.sdiv 4).setWidth 26=(delta>>>2).setWidth 26 := by
  rw [signed_div_four]
  unfold Word at *
  bv_decide

def kernelEncoding (delta : Word) : BitVec 32 :=
  (0x94000000#32) ||| ((delta.sdiv (4#64)).setWidth 32 &&& (0x03ffffff#32))

/-- The actual C cast/mask/or construction has the same encoded word. -/
theorem kernel_word (delta : Word) (aligned : delta &&& 3=0) :
    kernelEncoding delta=encoding ((delta>>>2).setWidth 26) := by
  unfold kernelEncoding
  have field:=kernel_field delta aligned
  generalize delta.sdiv 4=quotient at field ⊢
  unfold encoding Word at *
  bv_decide

theorem checked_decode (slot target : Word) (immediate : BitVec 26)
    (accepted : checked slot target=some immediate) :
    AArch64.decode (branchBytes immediate)=.ok (.branchLink (target-slot)) := by
  rw [decode_branch_bytes,checked_displacement slot target immediate accepted]

/-- Reference.Memory gives the exact four native bytes of the emitted word. -/
theorem written_bytes (code : Memory) (slot : Word) (immediate : BitVec 26) :
    (bytesAt (storeMemory code slot ((encoding immediate).zeroExtend 64) 4) slot 4).toArray=
      branchBytes immediate := by
  exact congrArg List.toArray
    (NativeLinkRelocationTable.stored_bytes code slot ((encoding immediate).zeroExtend 64) 4 (by decide))

theorem written_decode (code : Memory) (slot target : Word) (immediate : BitVec 26)
    (accepted : checked slot target=some immediate) :
    AArch64.decode (bytesAt (storeMemory code slot ((encoding immediate).zeroExtend 64) 4) slot 4).toArray=
      .ok (.branchLink (target-slot)) := by
  rw [written_bytes]
  exact checked_decode slot target immediate accepted

theorem kernel_checked (slot target : Word) (guard : kernelGuard (target-slot)) :
    checked slot target=some (((target-slot)>>>2).setWidth 26) := by
  dsimp only [checked]
  rw [if_pos ((guard_equivalence _).mp guard)]

/-- Direct cast/mask/or storage from the kernel branch reaches canonical decode. -/
theorem kernel_written_decode (code : Memory) (slot target : Word) (guard : kernelGuard (target-slot)) :
    AArch64.decode (bytesAt (storeMemory code slot
      ((kernelEncoding (target-slot)).zeroExtend 64) 4) slot 4).toArray=
      .ok (.branchLink (target-slot)) := by
  rw [kernel_word (target-slot) guard.1]
  exact written_decode code slot target _ (kernel_checked slot target guard)

/-- Complete canonical state includes every GPR/vector, SP, flags, memory and
exclusive inputs. BL sets X30 to PC+4 and transfers directly to the bound target. -/
theorem branch_result (state : AArch64.State) (target : Word) :
    AArch64.step (.branchLink (target-state.pc)) state=
      ⟨{AArch64.writeReg state 30 (state.pc+4) with pc:=target},[],none⟩ := by
  have next : state.pc+(target-state.pc)=target := by
    rw [BitVec.add_comm]
    exact BitVec.sub_add_cancel _ _
  simp only [AArch64.step,next]

def intended (target : Word) : BlockStep AArch64.State := fun before events after =>
  ∃ immediate effect, checked before.pc target=some immediate ∧
    AArch64.Step (.branchLink (target-before.pc)) before effect ∧
      effect.events=events ∧ effect.state=after

def emitted (code : Memory) (target : Word) : BlockStep AArch64.State := fun before events after =>
  kernelGuard (target-before.pc) ∧ ∃ instruction effect,
    AArch64.decode (bytesAt (storeMemory code before.pc
      ((kernelEncoding (target-before.pc)).zeroExtend 64) 4) before.pc 4).toArray=
      .ok instruction ∧ AArch64.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

theorem bl26_preservation (code : Memory) (target : Word) :
    TranslationValidation (intended target) (emitted code target) Eq := by
  constructor
  intro before other events after related run
  subst other
  obtain ⟨immediate,effect,accepted,step,trace,state⟩:=run
  have guard : kernelGuard (target-before.pc) := by
    apply (guard_equivalence _).mpr
    dsimp only [checked] at accepted
    split at accepted
    · assumption
    · contradiction
  have head : emitted code target before events after :=
    ⟨guard,.branchLink (target-before.pc),effect,
      kernel_written_decode code before.pc target guard,step,trace,state⟩
  exact ⟨after,by simpa only [List.append_nil] using Execution.next head (Execution.refl after),rfl⟩

theorem emitted_reflects (code : Memory) (target : Word) (before after : AArch64.State)
    (events : List Event) (run : emitted code target before events after) :
    intended target before events after := by
  obtain ⟨guard,instruction,effect,decoded,step,trace,state⟩:=run
  have same : instruction=.branchLink (target-before.pc) :=
    Except.ok.inj (decoded.symm.trans (kernel_written_decode code before.pc target guard))
  subst instruction
  exact ⟨_,effect,kernel_checked before.pc target guard,step,trace,state⟩

theorem emitted_architecture (code : Memory) (target : Word) (before after : AArch64.State)
    (events : List Event) (run : emitted code target before events after) :
    after={AArch64.writeReg before 30 (before.pc+4) with pc:=target} ∧ events=[] := by
  obtain ⟨immediate,effect,accepted,step,trace,state⟩:=emitted_reflects code target before after events run
  unfold AArch64.Step at step
  rw [branch_result] at step
  subst effect
  exact ⟨state.symm,trace.symm⟩

end KProgTV.NativeLinkArmBL26
#print axioms KProgTV.NativeLinkArmBL26.guard_equivalence
#print axioms KProgTV.NativeLinkArmBL26.checked_target
#print axioms KProgTV.NativeLinkArmBL26.bytes_word
#print axioms KProgTV.NativeLinkArmBL26.nat_mask
#print axioms KProgTV.NativeLinkArmBL26.nat_mask_ne
#print axioms KProgTV.NativeLinkArmBL26.decode_branch_bytes

#print axioms KProgTV.NativeLinkArmBL26.signed_div_four
#print axioms KProgTV.NativeLinkArmBL26.checked_displacement
#print axioms KProgTV.NativeLinkArmBL26.checked_rejects
#print axioms KProgTV.NativeLinkArmBL26.kernel_field
#print axioms KProgTV.NativeLinkArmBL26.kernel_word
#print axioms KProgTV.NativeLinkArmBL26.checked_decode
#print axioms KProgTV.NativeLinkArmBL26.written_bytes
#print axioms KProgTV.NativeLinkArmBL26.written_decode
#print axioms KProgTV.NativeLinkArmBL26.branch_result
#print axioms KProgTV.NativeLinkArmBL26.bl26_preservation
#print axioms KProgTV.NativeLinkArmBL26.emitted_reflects
#print axioms KProgTV.NativeLinkArmBL26.emitted_architecture

#print axioms KProgTV.NativeLinkArmBL26.kernel_checked
#print axioms KProgTV.NativeLinkArmBL26.kernel_written_decode
