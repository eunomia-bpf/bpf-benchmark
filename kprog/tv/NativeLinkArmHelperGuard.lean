import NativeLinkArmHelper

/-! The actual far-writer acceptance range discharges the canonical address
reconstruction premise. The near path keeps its existing BL26 range. -/
namespace KProgTV.NativeLinkArmHelperGuard
open KProgFormal.Reference KProgTV KProgTV.NativeLinkArmHelper

/-- Exact unsigned C shift/constant comparison before the first word store. -/
def farAccepted (target : Word) : Bool := target >>> 48 == (0xffff#64)

theorem far_accepted (target : Word) : farAccepted target=true ↔ Kernel48 target := by
  simp [farAccepted,Kernel48]

theorem far_acceptance_exact (target : Word) :
    farAccepted target=true ↔ reconstructed target=target := by
  exact (far_accepted target).trans (reconstructed_exact target).symm

def checkedFar (code : Memory) (slot target : Word) : Option Memory :=
  if farAccepted target then some (emit4 code slot (farWords target)) else none

theorem far_success (code : Memory) (slot target : Word) (emitted : Memory) :
    checkedFar code slot target=some emitted ↔
      Kernel48 target ∧ emitted=emit4 code slot (farWords target) := by
  by_cases profile : Kernel48 target
  · have guard : farAccepted target=true := (far_accepted target).mpr profile
    simp only [checkedFar,guard,ite_true,Option.some.injEq]
    exact ⟨fun same => ⟨profile,same.symm⟩,fun pair => pair.2.symm⟩
  · have guard : farAccepted target=false := Bool.eq_false_iff.mpr (fun accepted =>
      profile ((far_accepted target).mp accepted))
    simp [checkedFar,guard,profile]

theorem far_refusal (code : Memory) (slot target : Word) (rejected : farAccepted target=false) :
    checkedFar code slot target=none := by
  simp [checkedFar,rejected]

local instance guardDecidable (delta : Word) : Decidable (NativeLinkArmBL26.kernelGuard delta) := by
  unfold NativeLinkArmBL26.kernelGuard
  infer_instance

def checkedHelper (code : Memory) (slot target : Word) : Option Memory :=
  if NativeLinkArmBL26.kernelGuard (target-slot) then some (nearCode code slot target)
  else checkedFar code slot target

theorem helper_success (code : Memory) (slot target : Word) (emitted : Memory) :
    checkedHelper code slot target=some emitted ↔
      (NativeLinkArmBL26.kernelGuard (target-slot) ∨ Kernel48 target) ∧
      emitted=helperCode code slot target := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-slot)
  · simp only [checkedHelper,helperCode,near,ite_true,true_or,true_and,Option.some.injEq]
    exact eq_comm
  · simp [checkedHelper,helperCode,near,far_success]

theorem accepted_far_entry (code : Memory) (state : AArch64.State) (target : Word)
    (emitted : Memory) (accepted : checkedFar code state.pc target=some emitted) :
    AArch64.step (.branchRegister true 10) (materialized state target)=
      ⟨{AArch64.writeReg (AArch64.writeReg state 10 target) 30 (state.pc+(16#64))
        with pc:=target},[],none⟩ := by
  exact supported_far_reference state target ((far_success _ _ _ _).mp accepted).1

/-- Every accepted near/far entry reaches the exact bound target. The complete
state records preserve each body's actual X10 and link-register values. -/
theorem accepted_helper_entry (code : Memory) (state : AArch64.State) (target : Word)
    (emitted : Memory) (accepted : checkedHelper code state.pc target=some emitted) :
    (if NativeLinkArmBL26.kernelGuard (target-state.pc) then
      AArch64.step (.branchLink (target-state.pc)) state
     else AArch64.step (.branchRegister true 10) (materialized state target))=
    (if NativeLinkArmBL26.kernelGuard (target-state.pc) then
      ⟨{AArch64.writeReg state 30 (state.pc+(4#64)) with pc:=target},[],none⟩
     else ⟨{AArch64.writeReg (AArch64.writeReg state 10 target) 30 (state.pc+(16#64))
       with pc:=target},[],none⟩) := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-state.pc)
  · simp only [near,ite_true]
    exact NativeLinkArmBL26.branch_result state target
  · simp only [checkedHelper,near,ite_false] at accepted
    simp only [near,ite_false]
    exact accepted_far_entry code state target emitted accepted

theorem accepted_block_preservation (code : Memory) (slot target : Word) (emitted : Memory)
    (padding : NearPadding code slot) (accepted : checkedHelper code slot target=some emitted) :
    TranslationValidation
      (Execution (tokenStep (fun index : Fin 4 =>
        symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (helperInstruction slot target index))))
      (tokenStep (fun index : Fin 4 =>
        decodedSite emitted (slot+BitVec.ofNat 64 (4*index.val)))) Eq := by
  rw [((helper_success _ _ _ _).mp accepted).2]
  exact helper_block_preservation code slot target padding

theorem accepted_block_reflects (code : Memory) (slot target : Word) (emitted : Memory)
    (padding : NearPadding code slot) (accepted : checkedHelper code slot target=some emitted)
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite emitted (slot+BitVec.ofNat 64 (4*index.val)))) before events after) :
    Execution (tokenStep (fun index : Fin 4 =>
      symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (helperInstruction slot target index))) before events after := by
  rw [((helper_success _ _ _ _).mp accepted).2] at run
  exact helper_block_reflects code slot target padding before after events run

end KProgTV.NativeLinkArmHelperGuard
#print axioms KProgTV.NativeLinkArmHelperGuard.far_accepted
#print axioms KProgTV.NativeLinkArmHelperGuard.far_acceptance_exact
#print axioms KProgTV.NativeLinkArmHelperGuard.far_success
#print axioms KProgTV.NativeLinkArmHelperGuard.far_refusal
#print axioms KProgTV.NativeLinkArmHelperGuard.helper_success
#print axioms KProgTV.NativeLinkArmHelperGuard.accepted_far_entry
#print axioms KProgTV.NativeLinkArmHelperGuard.accepted_helper_entry
#print axioms KProgTV.NativeLinkArmHelperGuard.accepted_block_preservation
#print axioms KProgTV.NativeLinkArmHelperGuard.accepted_block_reflects
