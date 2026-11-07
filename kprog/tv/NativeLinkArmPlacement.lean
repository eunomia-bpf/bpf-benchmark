import NativeLinkArmHelperGuard
import NativeLinkFinalImage

/-! ARM word-index output positions and final-PC target calculations meet in
the common storage/copy relation. Canonical decoding uses final addresses. -/
namespace KProgTV.NativeLinkArmPlacement
open KProgFormal.Reference KProgTV NativeLinkArmHelper NativeLinkArmHelperGuard
open _root_.KProgTV.NativeLinkFinalImage (view Transfer store_view transfer_slice view_bytes)

theorem word_index_position (image final : Word) (start offset : Nat) (aligned : offset%4=0) :
    image+BitVec.ofNat 64 (4*(start+offset/4))=
      (final+BitVec.ofNat 64 offset)+(image+BitVec.ofNat 64 (4*start)-final) := by
  have arithmetic : 4*(start+offset/4)=4*start+offset := by omega
  rw [arithmetic,BitVec.ofNat_add]
  calc
    image+(BitVec.ofNat 64 (4*start)+BitVec.ofNat 64 offset)=
        (image+BitVec.ofNat 64 (4*start))+BitVec.ofNat 64 offset := (BitVec.add_assoc _ _ _).symm
    _=((image+BitVec.ofNat 64 (4*start)-final)+final)+BitVec.ofNat 64 offset := by
      rw [BitVec.sub_add_cancel]
    _=final+BitVec.ofNat 64 offset+(image+BitVec.ofNat 64 (4*start)-final) := by ac_rfl

theorem final_word_position (final : Word) (offset : Nat) (aligned : offset%4=0) :
    final+BitVec.ofNat 64 (4*(offset/4))=final+BitVec.ofNat 64 offset := by
  have arithmetic : 4*(offset/4)=offset := by omega
  rw [arithmetic]

theorem emit4_view (storage : Memory) (delta slot : Word) (words : Fin 4 → BitVec 32) :
    view (emit4 storage (slot+delta) words) delta=emit4 (view storage delta) slot words := by
  have add4 (a b : Word) : a+b+4=(a+4)+b := by unfold Word at *; bv_decide
  have add8 (a b : Word) : a+b+8=(a+8)+b := by unfold Word at *; bv_decide
  have add12 (a b : Word) : a+b+12=(a+12)+b := by unfold Word at *; bv_decide
  simp only [emit4,add4,add8,add12,store_view]

/-- The module's full16B bound keeps all four helper words within the
JIT's reported native word count. -/
theorem slot_word_bounds (words offset : Nat) (fits : offset+16≤4*words) (index : Fin 4) :
    offset/4+index.val<words := by
  have bound:=index.isLt
  omega

/-- The actual ARM copy shape: reported scratch words to the writable pack,
then the successful whole-pack text finalization. Cursor and count use words. -/
theorem jit_word_copy (scratch writable final : Memory)
    (scratchBase writableBase finalBase : Word) (cursor words packBytes : Nat)
    (wordCopy : Transfer scratch writable scratchBase
      (writableBase+BitVec.ofNat 64 (4*cursor)) (4*words))
    (finalize : Transfer writable final writableBase finalBase packBytes)
    (fits : 4*cursor+4*words≤packBytes) :
    Transfer scratch final scratchBase (finalBase+BitVec.ofNat 64 (4*cursor)) (4*words) := by
  exact _root_.KProgTV.NativeLinkFinalImage.transfer_trans scratch writable final scratchBase _ _ (4*words)
    wordCopy (_root_.KProgTV.NativeLinkFinalImage.transfer_subrange writable final writableBase finalBase
      packBytes (4*cursor) (4*words) finalize fits)

/-- Final slot determines BL bits; the physical slot selects temporary stores. -/
def stagedNear (storage : Memory) (physical slot target : Word) : Memory :=
  storeMemory storage physical ((NativeLinkArmBL26.kernelEncoding (target-slot)).setWidth 64) 4

theorem near_view (storage : Memory) (delta slot target : Word) :
    view (stagedNear storage (slot+delta) slot target) delta=nearCode (view storage delta) slot target := by
  exact store_view storage delta slot _ 4

local instance guardDecidable (delta : Word) : Decidable (NativeLinkArmBL26.kernelGuard delta) := by
  unfold NativeLinkArmBL26.kernelGuard
  infer_instance

def stagedHelper (storage : Memory) (physical slot target : Word) : Option Memory :=
  if NativeLinkArmBL26.kernelGuard (target-slot) then some (stagedNear storage physical slot target)
  else checkedFar storage physical target

theorem helper_view (storage : Memory) (delta slot target : Word) :
    (stagedHelper storage (slot+delta) slot target).map (fun emitted => view emitted delta)=
      checkedHelper (view storage delta) slot target := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-slot)
  · simp only [stagedHelper,checkedHelper,near,ite_true]
    change some (view (stagedNear storage (slot+delta) slot target) delta)=_
    rw [near_view]
  · simp only [stagedHelper,checkedHelper,near,ite_false,checkedFar]
    cases accepted : farAccepted target
    · rfl
    · change some (view (emit4 storage (slot+delta) (farWords target)) delta)=_
      rw [emit4_view]
      rfl

theorem accepted_view (storage emitted : Memory) (delta slot target : Word)
    (accepted : stagedHelper storage (slot+delta) slot target=some emitted) :
    checkedHelper (view storage delta) slot target=some (view emitted delta) := by
  rw [←helper_view,accepted]
  rfl

/-- Copy correspondence supplies each complete4B instruction of a contained
16B slot; the storage delta changes fetch locations and preserves code bits. -/
theorem copied_slot_fetch (emitted final : Memory) (temporaryBase finalBase : Word)
    (total offset : Nat) (copied : Transfer emitted final temporaryBase finalBase total)
    (fits : offset+16≤total) (index : Fin 4) :
    bytesAt final (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)) 4=
      bytesAt (view emitted (temporaryBase-finalBase))
        (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)) 4 := by
  rw [view_bytes]
  have position : finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)+(temporaryBase-finalBase)=
      temporaryBase+BitVec.ofNat 64 (offset+4*index.val) := by
    rw [BitVec.ofNat_add]
    unfold Word at *
    bv_decide (config := { acNf := true })
  rw [position,BitVec.add_assoc,←BitVec.ofNat_add]
  exact transfer_slice emitted final temporaryBase finalBase total (offset+4*index.val) 4 copied (by
    have bound:=index.isLt
    omega)

theorem copied_site_iff (emitted final : Memory) (temporaryBase finalBase : Word)
    (total offset : Nat) (copied : Transfer emitted final temporaryBase finalBase total)
    (fits : offset+16≤total) (index : Fin 4)
    (before after : AArch64.State) (events : List Event) :
    decodedSite final (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)) before events after ↔
      decodedSite (view emitted (temporaryBase-finalBase))
        (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)) before events after := by
  unfold decodedSite
  constructor <;> intro run
  all_goals
    obtain ⟨pc,instruction,effect,decoded,step,trace,state⟩:=run
    have bytes:=copied_slot_fetch emitted final temporaryBase finalBase total offset copied fits index
    rw [←pc] at bytes
  · exact ⟨pc,instruction,effect,by rw [bytes] at decoded; exact decoded,step,trace,state⟩
  · exact ⟨pc,instruction,effect,by rw [bytes]; exact decoded,step,trace,state⟩

/-- A successfully staged helper slot retains its full canonical block relation
at final executable addresses, through the same finite-prefix Composition law. -/
theorem accepted_final_block (storage emitted final : Memory) (temporaryBase finalBase target : Word)
    (total offset : Nat) (copied : Transfer emitted final temporaryBase finalBase total)
    (fits : offset+16≤total)
    (padding : NearPadding (view storage (temporaryBase-finalBase)) (finalBase+BitVec.ofNat 64 offset))
    (accepted : stagedHelper storage
      ((finalBase+BitVec.ofNat 64 offset)+(temporaryBase-finalBase))
      (finalBase+BitVec.ofNat 64 offset) target=some emitted) :
    TranslationValidation
      (Execution (tokenStep (fun index : Fin 4 =>
        symbolicSite (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val))
          (helperInstruction (finalBase+BitVec.ofNat 64 offset) target index))))
      (tokenStep (fun index : Fin 4 =>
        decodedSite final (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)))) Eq := by
  have validation:=accepted_block_preservation (view storage (temporaryBase-finalBase))
    (finalBase+BitVec.ofNat 64 offset) target (view emitted (temporaryBase-finalBase)) padding
    (accepted_view storage emitted (temporaryBase-finalBase) (finalBase+BitVec.ofNat 64 offset) target accepted)
  constructor
  intro before other events after related run
  obtain ⟨last,steps,equal⟩:=validation.block related run
  refine ⟨last,?_,equal⟩
  exact Execution.of_step_imp (fun {first trace next} head => by
    obtain ⟨index,step⟩:=head
    exact ⟨index,(copied_site_iff emitted final temporaryBase finalBase total offset copied fits index first next trace).mpr step⟩) steps

theorem accepted_final_reflects (storage emitted final : Memory) (temporaryBase finalBase target : Word)
    (total offset : Nat) (copied : Transfer emitted final temporaryBase finalBase total)
    (fits : offset+16≤total)
    (padding : NearPadding (view storage (temporaryBase-finalBase)) (finalBase+BitVec.ofNat 64 offset))
    (accepted : stagedHelper storage
      ((finalBase+BitVec.ofNat 64 offset)+(temporaryBase-finalBase))
      (finalBase+BitVec.ofNat 64 offset) target=some emitted)
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite final (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)))) before events after) :
    Execution (tokenStep (fun index : Fin 4 =>
      symbolicSite (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val))
        (helperInstruction (finalBase+BitVec.ofNat 64 offset) target index))) before events after := by
  have stagedRun : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite (view emitted (temporaryBase-finalBase))
        (finalBase+BitVec.ofNat 64 offset+BitVec.ofNat 64 (4*index.val)))) before events after :=
    Execution.of_step_imp (fun {first trace next} head => by
      obtain ⟨index,step⟩:=head
      exact ⟨index,(copied_site_iff emitted final temporaryBase finalBase total offset copied fits index first next trace).mp step⟩) run
  exact accepted_block_reflects (view storage (temporaryBase-finalBase))
    (finalBase+BitVec.ofNat 64 offset) target (view emitted (temporaryBase-finalBase)) padding
    (accepted_view storage emitted (temporaryBase-finalBase) (finalBase+BitVec.ofNat 64 offset) target accepted)
    before after events stagedRun

end KProgTV.NativeLinkArmPlacement
#print axioms KProgTV.NativeLinkArmPlacement.word_index_position
#print axioms KProgTV.NativeLinkArmPlacement.final_word_position
#print axioms KProgTV.NativeLinkArmPlacement.emit4_view
#print axioms KProgTV.NativeLinkArmPlacement.near_view
#print axioms KProgTV.NativeLinkArmPlacement.helper_view
#print axioms KProgTV.NativeLinkArmPlacement.accepted_view
#print axioms KProgTV.NativeLinkArmPlacement.copied_slot_fetch
#print axioms KProgTV.NativeLinkArmPlacement.copied_site_iff
#print axioms KProgTV.NativeLinkArmPlacement.accepted_final_block
#print axioms KProgTV.NativeLinkArmPlacement.accepted_final_reflects
#print axioms KProgTV.NativeLinkArmPlacement.slot_word_bounds
#print axioms KProgTV.NativeLinkArmPlacement.jit_word_copy
