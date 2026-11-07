import NativeLinkByteLayout

/-! The x86 emitter writes temporary storage and calculates relative targets
from final_ip. Address translation commutes with the canonical memory writer;
byte-exact transfer into final text then preserves canonical decode and steps. -/
namespace KProgTV.NativeLinkFinalImage
open KProgFormal.Reference NativeLinkPatchTable

/-- A code-storage view at final addresses. Architectural data state, helper
identities and target values keep their original addresses. -/
def view (storage : Memory) (delta : Word) : Memory :=
  ⟨fun address => storage.value (address+delta),
   fun address => storage.readable (address+delta),
   fun address => storage.writable (address+delta),
   fun address => storage.initialized (address+delta)⟩

/-- Only the write location moves to temporary storage. The already computed
final-PC displacement and bound target retain their exact bits. -/
def staged (delta : Word) : Patch → Patch
  | .call patch => .call {patch with slot:=patch.slot+delta}
  | .literal slot target => .literal (slot+delta) target

theorem translated_difference (address slot delta : Word) :
    address+delta-(slot+delta)=address-slot := by bv_decide

theorem store_view (storage : Memory) (delta slot value : Word) (count : Nat) :
    view (storeMemory storage (slot+delta) value count) delta=
      storeMemory (view storage delta) slot value count := by
  unfold view storeMemory
  simp only [translated_difference]

theorem staged_address (delta : Word) (patch : Patch) :
    writeAddress (staged delta patch)=writeAddress patch+delta := by
  cases patch <;> simp only [staged,writeAddress]
  bv_decide

theorem staged_size (delta : Word) (patch : Patch) :
    writeSize (staged delta patch)=writeSize patch := by cases patch <;> rfl

theorem staged_value (delta : Word) (patch : Patch) :
    writeValue (staged delta patch)=writeValue patch := by cases patch <;> rfl

theorem patch_view (storage : Memory) (delta : Word) (patch : Patch) :
    view (applyPatch storage (staged delta patch)) delta=
      applyPatch (view storage delta) patch := by
  unfold applyPatch
  rw [staged_address,staged_value,staged_size,store_view]

/-- Every ordered mixed CALL/literal table commutes with the storage view.
Rel32 bits were calculated at final addresses before write locations move. -/
theorem table_view (patches : List Patch) (storage : Memory) (delta : Word) :
    view (applyTable (patches.map (staged delta)) storage) delta=
      applyTable patches (view storage delta) := by
  induction patches generalizing storage with
  | nil => rfl
  | cons patch rest ih =>
      simp only [List.map_cons,applyTable,ih,patch_view]

theorem view_bytes (storage : Memory) (delta base : Word) (count : Nat) :
    bytesAt (view storage delta) base count=bytesAt storage (base+delta) count := by
  apply List.map_congr_left
  intro i member
  change storage.value (base+BitVec.ofNat 64 i+delta)=_
  congr 1
  bv_decide

/-- Successful memcpy/text-copy correspondence for one finite code range.
This interface concerns byte values; final text permissions come from its
allocator, while architectural data memory stays in the canonical state. -/
def Transfer (source destination : Memory) (sourceBase destinationBase : Word) (count : Nat) : Prop :=
  ∀ i<count, destination.value (destinationBase+BitVec.ofNat 64 i)=source.value (sourceBase+BitVec.ofNat 64 i)

theorem transfer_trans (first middle last : Memory) (a b c : Word) (count : Nat)
    (left : Transfer first middle a b count) (right : Transfer middle last b c count) :
    Transfer first last a c count := by
  intro i bounded
  exact (right i bounded).trans (left i bounded)

/-- A full-range copy supplies every contained fetch, at wrapping64 addresses. -/
theorem transfer_slice (source destination : Memory) (sourceBase destinationBase : Word) (total offset count : Nat)
    (copied : Transfer source destination sourceBase destinationBase total) (fits : offset+count≤total) :
    bytesAt destination (destinationBase+BitVec.ofNat 64 offset) count=
      bytesAt source (sourceBase+BitVec.ofNat 64 offset) count := by
  apply List.map_congr_left
  intro i member
  have bounded : offset+i<total := by have := List.mem_range.mp member; omega
  have same := copied (offset+i) bounded
  simpa only [BitVec.ofNat_add,BitVec.add_assoc] using same

/-- A whole-pack text copy supplies an embedded chunk at its exact pack
cursor. Copy sizes and chunk bounds are natural-number byte counts. -/
theorem transfer_subrange (source destination : Memory) (sourceBase destinationBase : Word)
    (total offset count : Nat) (copied : Transfer source destination sourceBase destinationBase total)
    (fits : offset+count≤total) :
    Transfer source destination (sourceBase+BitVec.ofNat 64 offset)
      (destinationBase+BitVec.ofNat 64 offset) count := by
  intro i bounded
  have same := copied (offset+i) (by omega)
  simpa only [BitVec.ofNat_add,BitVec.add_assoc] using same

/-- The actual three-stage x86 copy shape: emitter scratch to instruction
buffer, instruction buffer to writable pack, then complete pack to final text. -/
theorem copy_pipeline (scratch instruction writable final : Memory)
    (scratchBase instructionBase writablePack finalPack : Word) (packSize cursor count : Nat)
    (first : Transfer scratch instruction scratchBase instructionBase count)
    (second : Transfer instruction writable instructionBase
      (writablePack+BitVec.ofNat 64 cursor) count)
    (third : Transfer writable final writablePack finalPack packSize)
    (fits : cursor+count≤packSize) :
    Transfer scratch final scratchBase (finalPack+BitVec.ofNat 64 cursor) count := by
  exact transfer_trans scratch writable final scratchBase _ _ count
    (transfer_trans scratch instruction writable scratchBase instructionBase _ count first second)
    (transfer_subrange writable final writablePack finalPack packSize cursor count third fits)

/-- Later patch stages preserve an emitted native range when their writes
lie in the other JIT regions. This is the final-fixup separation interface. -/
theorem transfer_after_table (source destination : Memory) (sourceBase destinationBase : Word)
    (count : Nat) (copied : Transfer source destination sourceBase destinationBase count)
    (later : List Patch)
    (outside : ∀ i<count, ∀ patch∈later, OutsideWrite (destinationBase+BitVec.ofNat 64 i) patch) :
    Transfer source (applyTable later destination) sourceBase destinationBase count := by
  intro i bounded
  exact (table_value_outside later destination _ (outside i bounded)).trans (copied i bounded)

/-- The temporary emitter, per-instruction buffer, writable pack and final
text may have distinct addresses. Their composed copy retains every fetch. -/
theorem finalized_fetch (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total offset count : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total)
    (fits : offset+count≤total) :
    bytesAt final (finalBase+BitVec.ofNat 64 offset) count=
      bytesAt (applyTable patches (view storage (scratchBase-finalBase)))
        (finalBase+BitVec.ofNat 64 offset) count := by
  rw [←table_view,view_bytes]
  have base : finalBase+BitVec.ofNat 64 offset+(scratchBase-finalBase)=
      scratchBase+BitVec.ofNat 64 offset := by bv_decide
  rw [base]
  exact transfer_slice _ _ _ _ _ _ _ copied fits

/-- Canonical decode at the final architectural PC consumes the exact final
bits, including relative targets computed using final_ip. -/
theorem finalized_decode (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total offset count : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total)
    (fits : offset+count≤total) (state : X86.State)
    (pc : state.pc=finalBase+BitVec.ofNat 64 offset) :
    X86.decode (bytesAt final state.pc count).toArray state=
      X86.decode (bytesAt (applyTable patches (view storage (scratchBase-finalBase))) state.pc count).toArray state := by
  rw [pc,finalized_fetch patches storage final scratchBase finalBase total offset count copied fits]

/-- Every canonical successor is retained. Runtime fetch and data state use
the final PC; the temporary-storage view supplies code bytes only. -/
def instructionStep (code : Memory) (base : Word) (total count : Nat) : BlockStep X86.State :=
  fun before events after =>
    (∃ offset, before.pc=base+BitVec.ofNat 64 offset ∧ offset+count≤total) ∧
    ∃ instruction effect, X86.decode (bytesAt code before.pc count).toArray before=.ok instruction ∧
      X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

theorem finalized_step_iff (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total count : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total)
    (before after : X86.State) (events : List Event) :
    instructionStep final finalBase total count before events after ↔
      instructionStep (applyTable patches (view storage (scratchBase-finalBase)))
        finalBase total count before events after := by
  constructor <;> intro run
  all_goals
    obtain ⟨range,instruction,effect,decoded,step,trace,state⟩ := run
    obtain ⟨offset,pc,fits⟩ := range
    have same := finalized_decode patches storage final scratchBase finalBase total offset count copied fits before pc
  · exact ⟨⟨offset,pc,fits⟩,instruction,effect,same.symm.trans decoded,step,trace,state⟩
  · exact ⟨⟨offset,pc,fits⟩,instruction,effect,same.trans decoded,step,trace,state⟩

/-- This universal link transformation composes with Composition and keeps
full state, ordered effects, faults and every canonical allowed successor. -/
theorem finalized_instruction_preservation (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total count : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total) :
    TranslationValidation
      (instructionStep (applyTable patches (view storage (scratchBase-finalBase))) finalBase total count)
      (instructionStep final finalBase total count) Eq := by
  constructor
  intro before other events after related run
  subst other
  have head := (finalized_step_iff patches storage final scratchBase finalBase total count copied before after events).mpr run
  exact ⟨after,by simpa only [List.append_nil] using Execution.next head (Execution.refl after),rfl⟩

/-- The existing table target theorem reaches actual copied final text. -/
theorem finalized_call_decode (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total offset : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total)
    (fits : offset+5≤total) (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid (view storage (scratchBase-finalBase)) patch)
    (record : NativeLinkRelocationTable.Patch) (member : Patch.call record∈patches)
    (state : X86.State) (pc : state.pc=finalBase+BitVec.ofNat 64 offset)
    (slot : state.pc=record.slot)
    (accepted : NativeLinkRelocation.checkedRel32 record.slot record.target=some record.displacement) :
    X86.decode (bytesAt final state.pc 5).toArray state=
      .ok (.call (.immediate record.target) (state.pc+(5#64))) := by
  rw [finalized_decode patches storage final scratchBase finalBase total offset 5 copied fits state pc]
  exact table_call_decode patches (view storage (scratchBase-finalBase)) separated valid record member state slot accepted

/-- Fixed MOVABS consumer preservation also reaches actual final text. -/
theorem finalized_movabs_decode (patches : List Patch) (storage final : Memory)
    (scratchBase finalBase : Word) (total offset : Nat)
    (copied : Transfer
      (applyTable (patches.map (staged (scratchBase-finalBase))) storage)
      final scratchBase finalBase total)
    (fits : offset+10≤total) (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid (view storage (scratchBase-finalBase)) patch)
    (state : X86.State) (pc : state.pc=finalBase+BitVec.ofNat 64 offset)
    (dst : X86.Register) (target : Word)
    (member : Patch.literal (state.pc+(2#64)) target∈patches)
    (header : (view storage (scratchBase-finalBase)).value state.pc=NativeLinkMovabs.rex dst ∧
      (view storage (scratchBase-finalBase)).value (state.pc+(1#64))=NativeLinkMovabs.opcode dst)
    (retained : NativeLinkMovabs.HeaderProtected patches state.pc) :
    X86.decode (bytesAt final state.pc 10).toArray state=
      .ok (.move .w64 (.register (.low dst)) (.immediate target) (state.pc+(10#64))) := by
  rw [finalized_decode patches storage final scratchBase finalBase total offset 10 copied fits state pc]
  exact NativeLinkMovabs.table_movabs_decode patches (view storage (scratchBase-finalBase)) separated valid state dst target member header retained

end KProgTV.NativeLinkFinalImage
#print axioms KProgTV.NativeLinkFinalImage.translated_difference
#print axioms KProgTV.NativeLinkFinalImage.store_view
#print axioms KProgTV.NativeLinkFinalImage.staged_address
#print axioms KProgTV.NativeLinkFinalImage.staged_size
#print axioms KProgTV.NativeLinkFinalImage.staged_value
#print axioms KProgTV.NativeLinkFinalImage.patch_view
#print axioms KProgTV.NativeLinkFinalImage.table_view
#print axioms KProgTV.NativeLinkFinalImage.view_bytes
#print axioms KProgTV.NativeLinkFinalImage.transfer_trans
#print axioms KProgTV.NativeLinkFinalImage.transfer_slice
#print axioms KProgTV.NativeLinkFinalImage.finalized_fetch
#print axioms KProgTV.NativeLinkFinalImage.finalized_decode
#print axioms KProgTV.NativeLinkFinalImage.finalized_step_iff
#print axioms KProgTV.NativeLinkFinalImage.finalized_instruction_preservation
#print axioms KProgTV.NativeLinkFinalImage.finalized_call_decode
#print axioms KProgTV.NativeLinkFinalImage.finalized_movabs_decode

#print axioms KProgTV.NativeLinkFinalImage.transfer_subrange
#print axioms KProgTV.NativeLinkFinalImage.copy_pipeline
#print axioms KProgTV.NativeLinkFinalImage.transfer_after_table
