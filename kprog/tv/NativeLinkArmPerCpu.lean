import NativeLinkArmHelper
import NativeLinkFinalImage
import KProgFormal.Refinement.Arm64Register

/-! Universal kind4 per-CPU MRS word resolution and final-code consumption.
Instruction semantics and access profiles come from canonical AArch64. -/
namespace KProgTV.NativeLinkArmPerCpu
open KProgFormal.Reference KProgTV NativeLinkArmHelper
open _root_.KProgTV.NativeLinkFinalImage (Transfer transfer_slice view store_view)

/-- The kernel's two literal words retain the actual X10 destination. -/
def selectedSource (vhe : Bool) : AArch64.ThreadPointerRegister := if vhe then .el2 else .el1

def selectedWord (vhe : Bool) : BitVec 32 := if vhe then 0xd53cd04a else 0xd538d08a

def selectedInstruction (vhe : Bool) : AArch64.Instruction := .readThreadPointer (selectedSource vhe) 10

theorem selected_decode (vhe : Bool) :
    AArch64.decode (wordBytes (selectedWord vhe))=.ok (selectedInstruction vhe) := by
  cases vhe <;> rfl

/-- The u32 descriptor offset plus the complete4B span fits size_t on ARM64. -/
theorem offset_span_u64 (offset : BitVec 32) : offset.toNat+4<2^64 := by
  have bounded:=offset.isLt
  omega

/-- The production offset&3 guard is exactly alignment modulo4. -/
theorem alignment_mask (offset : BitVec 32) : (offset &&& 3).toNat=offset.toNat%4 := by
  have same : offset &&& 3=offset%(4#32) := by bv_decide
  rw [same,BitVec.toNat_umod]
  rfl

/-- The existing current-image placeholder check follows alignment and bounds. -/
def Accepted (offset : BitVec 32) (length : Nat) (current : BitVec 32) : Prop :=
  offset.toNat%4=0 ∧ offset.toNat+4≤length ∧ current=0xd538d08a

instance acceptedDecidable (offset : BitVec 32) (length : Nat) (current : BitVec 32) :
    Decidable (Accepted offset length current) := by unfold Accepted; infer_instance

def checkedWord (offset : BitVec 32) (length : Nat) (current : BitVec 32) (vhe : Bool) : Option (BitVec 32) :=
  if offset.toNat%4≠0 then none
  else if length<offset.toNat+4 then none
  else if current≠0xd538d08a then none else some (selectedWord vhe)

theorem word_acceptance (offset : BitVec 32) (length : Nat) (current output : BitVec 32) (vhe : Bool) :
    checkedWord offset length current vhe=some output ↔
      Accepted offset length current ∧ output=selectedWord vhe := by
  by_cases aligned : offset.toNat%4=0 <;>
    by_cases fits : offset.toNat+4≤length <;>
    by_cases placeholder : current=0xd538d08a <;>
    simp [checkedWord,Accepted,aligned,fits,placeholder,Nat.not_lt,eq_comm] <;> omega

/-- Every rejected descriptor returns before the word store. -/
theorem word_refusal (offset : BitVec 32) (length : Nat) (current : BitVec 32) (vhe : Bool)
    (rejected : ¬Accepted offset length current) : checkedWord offset length current vhe=none := by
  cases actual : checkedWord offset length current vhe with
  | none => rfl
  | some output => exact False.elim (rejected ((word_acceptance _ _ _ _ _).mp actual).1)

theorem aligned_word_index (offset : BitVec 32) (start length : Nat) (current : BitVec 32)
    (accepted : Accepted offset length current) :
    4*(start+offset.toNat/4)=4*start+offset.toNat ∧ offset.toNat/4<length/4 := by
  obtain ⟨aligned,fits,_⟩:=accepted
  omega

def emitWord (code : Memory) (slot : Word) (vhe : Bool) : Memory :=
  storeMemory code slot ((selectedWord vhe).zeroExtend 64) 4

def checkedCode (code : Memory) (slot : Word) (offset : BitVec 32) (length : Nat) (vhe : Bool) : Option Memory :=
  (checkedWord offset length (littleEndian 32 (bytesAt code slot 4)) vhe).map
    (fun word => storeMemory code slot (word.zeroExtend 64) 4)

theorem code_success (code emitted : Memory) (slot : Word) (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code slot offset length vhe=some emitted) :
    Accepted offset length (littleEndian 32 (bytesAt code slot 4)) ∧ emitted=emitWord code slot vhe := by
  unfold checkedCode at accepted
  cases actual : checkedWord offset length (littleEndian 32 (bytesAt code slot 4)) vhe with
  | none => simp [actual] at accepted
  | some word =>
      have facts:=(word_acceptance _ _ _ _ _).mp actual
      rw [actual] at accepted
      change some (storeMemory code slot (word.zeroExtend 64) 4)=some emitted at accepted
      have same := Option.some.inj accepted
      exact ⟨facts.1,by rw [←same,facts.2]; rfl⟩

theorem emitted_bytes (code : Memory) (slot : Word) (vhe : Bool) :
    (bytesAt (emitWord code slot vhe) slot 4).toArray=wordBytes (selectedWord vhe) := by
  rw [emitWord,NativeLinkRelocationTable.stored_bytes _ _ _ 4 (by decide)]
  rfl

theorem emitted_outside (code : Memory) (slot address : Word) (vhe : Bool)
    (outside : 4≤(address-slot).toNat) :
    (emitWord code slot vhe).value address=code.value address ∧
      (emitWord code slot vhe).initialized address=code.initialized address := by
  simp only [emitWord,storeMemory,show ¬(address-slot).toNat<4 by omega,ite_false,and_self]

theorem emitted_permissions (code : Memory) (slot : Word) (vhe : Bool) :
    (emitWord code slot vhe).readable=code.readable ∧ (emitWord code slot vhe).writable=code.writable := by
  exact ⟨rfl,rfl⟩

theorem emitted_decode (code : Memory) (slot : Word) (vhe : Bool) :
    AArch64.decode (bytesAt (emitWord code slot vhe) slot 4).toArray=.ok (selectedInstruction vhe) := by
  rw [emitted_bytes]
  exact selected_decode vhe

/-- The writable-pack view moves storage addresses while retaining MRS bits. -/
theorem emitted_view (storage : Memory) (delta slot : Word) (vhe : Bool) :
    view (emitWord storage (slot+delta) vhe) delta=emitWord (view storage delta) slot vhe := by
  exact store_view storage delta slot _ 4

/-- A successful whole-pack transfer supplies the entire4B instruction. -/
theorem accepted_final_decode (code emitted final : Memory) (temporaryBase finalBase : Word)
    (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code (temporaryBase+offset.zeroExtend 64) offset length vhe=some emitted)
    (copied : Transfer emitted final temporaryBase finalBase length) :
    AArch64.decode (bytesAt final (finalBase+offset.zeroExtend 64) 4).toArray=.ok (selectedInstruction vhe) := by
  obtain ⟨fields,equal⟩:=code_success code emitted _ offset length vhe accepted
  have widened : offset.zeroExtend 64=BitVec.ofNat 64 offset.toNat := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_setWidth,BitVec.toNat_ofNat]
  rw [widened,transfer_slice emitted final temporaryBase finalBase length offset.toNat 4 copied fields.2.1]
  rw [←widened,equal]
  exact emitted_decode code _ vhe

/-- Every resolved access profile, including denial, has exact canonical
full-state/effect behavior at final executable addresses. -/
theorem accepted_final_preservation (code emitted final : Memory) (temporaryBase finalBase : Word)
    (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code (temporaryBase+offset.zeroExtend 64) offset length vhe=some emitted)
    (copied : Transfer emitted final temporaryBase finalBase length) :
    TranslationValidation
      (Execution (symbolicSite (finalBase+offset.zeroExtend 64) (selectedInstruction vhe)))
      (decodedSite final (finalBase+offset.zeroExtend 64)) Eq := by
  exact (site_preservation final _ _ (accepted_final_decode code emitted final temporaryBase finalBase offset length vhe accepted copied)).execution

theorem accepted_final_reflects (code emitted final : Memory) (temporaryBase finalBase : Word)
    (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code (temporaryBase+offset.zeroExtend 64) offset length vhe=some emitted)
    (copied : Transfer emitted final temporaryBase finalBase length)
    (before after : AArch64.State) (events : List Event)
    (run : Execution (decodedSite final (finalBase+offset.zeroExtend 64)) before events after) :
    Execution (symbolicSite (finalBase+offset.zeroExtend 64) (selectedInstruction vhe)) before events after := by
  exact Execution.of_step_imp
    (fun head => site_reflects final _ _ (accepted_final_decode code emitted final temporaryBase finalBase offset length vhe accepted copied) _ _ _ head) run

/-- Binding the chosen physical TP register to this invocation's CPU-local
word connects the emitted native instruction to canonical materialization. -/
theorem resolved_value (state : AArch64.State) (vhe : Bool) (perCpu : Word)
    (profile : state.threadPointer (selectedSource vhe)=some perCpu) :
    AArch64.step (selectedInstruction vhe) state=AArch64.step (.moveImmediate .w64 10 perCpu) state := by
  exact KProgFormal.Refinement.Arm64Register.thread_pointer_read_refines _ _ _ _ profile

theorem resolved_result (state : AArch64.State) (vhe : Bool) (perCpu : Word)
    (profile : state.threadPointer (selectedSource vhe)=some perCpu) :
    AArch64.step (selectedInstruction vhe) state=
      ⟨{AArch64.writeReg state 10 perCpu with pc:=state.pc+4},[],none⟩ := by
  simp only [selectedInstruction,AArch64.step,AArch64.readThreadPointerStep,profile]

theorem denied_result (state : AArch64.State) (vhe : Bool)
    (profile : state.threadPointer (selectedSource vhe)=none) :
    AArch64.step (selectedInstruction vhe) state=
      ⟨state,[.fault (.systemRegister (selectedSource vhe).encoding)],some (.systemRegister (selectedSource vhe).encoding)⟩ := by
  exact KProgFormal.Refinement.Arm64Register.thread_pointer_denied _ _ _ profile

end KProgTV.NativeLinkArmPerCpu
#print axioms KProgTV.NativeLinkArmPerCpu.selected_decode
#print axioms KProgTV.NativeLinkArmPerCpu.alignment_mask
#print axioms KProgTV.NativeLinkArmPerCpu.offset_span_u64
#print axioms KProgTV.NativeLinkArmPerCpu.word_acceptance
#print axioms KProgTV.NativeLinkArmPerCpu.word_refusal
#print axioms KProgTV.NativeLinkArmPerCpu.aligned_word_index
#print axioms KProgTV.NativeLinkArmPerCpu.code_success
#print axioms KProgTV.NativeLinkArmPerCpu.emitted_bytes
#print axioms KProgTV.NativeLinkArmPerCpu.emitted_outside
#print axioms KProgTV.NativeLinkArmPerCpu.emitted_permissions
#print axioms KProgTV.NativeLinkArmPerCpu.emitted_decode
#print axioms KProgTV.NativeLinkArmPerCpu.emitted_view
#print axioms KProgTV.NativeLinkArmPerCpu.accepted_final_decode
#print axioms KProgTV.NativeLinkArmPerCpu.accepted_final_preservation
#print axioms KProgTV.NativeLinkArmPerCpu.accepted_final_reflects
#print axioms KProgTV.NativeLinkArmPerCpu.resolved_value
#print axioms KProgTV.NativeLinkArmPerCpu.resolved_result
#print axioms KProgTV.NativeLinkArmPerCpu.denied_result

namespace KProgTV.NativeLinkArmPerCpu
open KProgFormal.Reference KProgTV NativeLinkArmHelper
open KProgTV.NativeLinkFinalImage (Transfer)

/-- The final copied MRS implements canonical scalar materialization for this
invocation's resolved thread-pointer profile, retaining the complete step. -/
theorem accepted_final_resolved_site (code emitted final : Memory)
    (temporaryBase finalBase : Word) (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code (temporaryBase+offset.zeroExtend 64) offset length vhe=some emitted)
    (copied : Transfer emitted final temporaryBase finalBase length)
    (before after : AArch64.State) (events : List Event) (perCpu : Word)
    (profile : before.threadPointer (selectedSource vhe)=some perCpu) :
    decodedSite final (finalBase+offset.zeroExtend 64) before events after ↔
      symbolicSite (finalBase+offset.zeroExtend 64) (.moveImmediate .w64 10 perCpu)
        before events after := by
  have decoded := accepted_final_decode code emitted final temporaryBase finalBase
    offset length vhe accepted copied
  have same := resolved_value before vhe perCpu profile
  constructor
  · intro run
    obtain ⟨position,effect,step,trace,state⟩ := site_reflects final _ _ decoded before after events run
    refine ⟨position,effect,?_,trace,state⟩
    simpa only [AArch64.Step,same] using step
  · rintro ⟨position,effect,step,trace,state⟩
    refine ⟨position,selectedInstruction vhe,effect,?_,?_,trace,state⟩
    · rw [position]
      exact decoded
    · simpa only [AArch64.Step,same] using step

/-- The copied native instruction changes X10 and PC exactly as the resolved
reference move. Every other canonical state field and the empty trace follow. -/
theorem accepted_final_resolved_frame (code emitted final : Memory)
    (temporaryBase finalBase : Word) (offset : BitVec 32) (length : Nat) (vhe : Bool)
    (accepted : checkedCode code (temporaryBase+offset.zeroExtend 64) offset length vhe=some emitted)
    (copied : Transfer emitted final temporaryBase finalBase length)
    (before after : AArch64.State) (events : List Event) (perCpu : Word)
    (profile : before.threadPointer (selectedSource vhe)=some perCpu) :
    decodedSite final (finalBase+offset.zeroExtend 64) before events after ↔
      before.pc=finalBase+offset.zeroExtend 64 ∧ events=[] ∧
      after={AArch64.writeReg before 10 perCpu with pc:=before.pc+4} := by
  rw [accepted_final_resolved_site code emitted final temporaryBase finalBase
    offset length vhe accepted copied before after events perCpu profile]
  simp [symbolicSite,AArch64.Step,AArch64.step,AArch64.narrow,AArch64.Width.bits,
    eq_comm,and_assoc,and_left_comm,and_comm]

end KProgTV.NativeLinkArmPerCpu
#print axioms KProgTV.NativeLinkArmPerCpu.accepted_final_resolved_site
#print axioms KProgTV.NativeLinkArmPerCpu.accepted_final_resolved_frame
