import NativeLinkByteLayout
import KProgFormal.Reference.AArch64

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

/-- Exact-byte transfer carries the frozen object image to its linked base.
Readability and initialization are supplied by the receiving allocator/copy. -/
theorem readonly_image_transfer (source destination : Memory)
    (sourceBase destinationBase : Word) (data : List Byte)
    (copied : Transfer source destination sourceBase destinationBase data.length)
    (image : NativeLinkLiteral.ReadOnly.Image data sourceBase source)
    (readable : ∀ i<data.length,
      destination.readable (destinationBase+BitVec.ofNat 64 i)=true)
    (initialized : ∀ i<data.length,
      destination.initialized (destinationBase+BitVec.ofNat 64 i)=true) :
    NativeLinkLiteral.ReadOnly.Image data destinationBase destination := by
  intro i bounded
  exact ⟨(copied i bounded).trans (image i bounded).1,
    readable i bounded,initialized i bounded⟩

/-- The actual linked bytes supply the C finite-copy law after final transfer.
The original alias address and canonical read observation are preserved. -/
theorem readonly_transferred_load (source destination : Memory)
    (sourceBase destinationBase alias displacement : Word) (data : List Byte)
    (width : Nat)
    (copied : Transfer source destination sourceBase destinationBase data.length)
    (image : NativeLinkLiteral.ReadOnly.Image data sourceBase source)
    (readable : ∀ i<data.length,
      destination.readable (destinationBase+BitVec.ofNat 64 i)=true)
    (initialized : ∀ i<data.length,
      destination.initialized (destinationBase+BitVec.ofNat 64 i)=true) :
    NativeLinkLiteral.ReadOnly.objectLoad data destinationBase
      (alias-destinationBase+displacement) width destination=
      readMemory destination (alias+displacement)
        (NativeLinkLiteral.ReadOnly.loadWidth width) := by
  rw [NativeLinkLiteral.ReadOnly.object_load_matches _ _ _ _ _
    (readonly_image_transfer _ _ _ _ _ copied image readable initialized),
    NativeLinkLiteral.ReadOnly.alias_address]

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

#print axioms KProgTV.NativeLinkFinalImage.readonly_image_transfer
#print axioms KProgTV.NativeLinkFinalImage.readonly_transferred_load

namespace KProgTV.NativeLinkFinalImage
open KProgFormal.Reference

/-- Platform handler at an actually registered load site. This is not an
ISA change or a table-membership check. Raw ordered events are retained as
an inner diagnostic trace; matching the B platform observation is a separate
premise. In particular, no successful zero-valued memory read is invented. -/
def recoverRead {State : Type} (resume : State → State)
    (effect : Transition State) : Transition State :=
  match effect.fault with
  | some (.read _ _) => { effect with state := resume effect.state, fault := none }
  | _ => effect

/-- Registered exception metadata leaves every successful step untouched. -/
theorem recovery_success {State : Type} (resume : State → State)
    (effect : Transition State) (success : effect.fault = none) :
    recoverRead resume effect = effect := by simp [recoverRead,success]

/-- This isolated read-recovery profile leaves all other faults explicit.
Whether the physical registered handler catches another exception class must
be related separately before applying this profile to the real platform. -/
theorem recovery_nonread {State : Type} (resume : State → State)
    (effect : Transition State) (reason : Fault)
    (fault : effect.fault = some reason)
    (nonread : ∀ address count, reason ≠ .read address count) :
    recoverRead resume effect = effect := by
  cases reason <;> simp_all [recoverRead]

/-- Recovery retains the full raw fault prefix. The final platform's event
projection and O3 checked-event predicate must account for a handled fault. -/
theorem recovery_raw_trace {State : Type} (resume : State → State)
    (effect : Transition State) :
    (recoverRead resume effect).events = effect.events := by
  unfold recoverRead
  cases effect.fault with
  | none => rfl
  | some reason => cases reason <;> rfl

/-- Stock x86 saved-frame handler: clear an entire physical GPR (or resume
only), then advance by the actual recorded native instruction length.
Its application requires physical frame/table/site/extent correspondence. -/
def x86LoadResume (destination : Option X86.Register) (length : Nat)
    (state : X86.State) : X86.State :=
  { state with
    gpr := fun register => if destination = some register then 0 else state.gpr register
    pc := state.pc + BitVec.ofNat 64 length }

/-- The stock handler's full-register zeroing is independent of the native
MOV width. This does not assert equality with partial-register B writeback. -/
theorem x86_recovered_load (state : X86.State) (width : X86.ScalarWidth)
    (destination : X86.Register) (address next : Word) (length : Nat)
    (fault : readMemory state.memory address width.bytes = .error (.read address width.bytes)) :
    recoverRead (x86LoadResume (some destination) length)
      (X86.moveStep width (.register (.low destination)) (.memory address) next state) =
      ⟨x86LoadResume (some destination) length state,[.fault (.read address width.bytes)],none⟩ := by
  simp [recoverRead,X86.moveStep,X86.scalarRead,X86.readSource,fault]

/-- The handler leaves memory, flags, SIMD and every other GPR intact. -/
theorem x86_resume_frame (state : X86.State) (destination : X86.Register) (length : Nat) :
    (x86LoadResume (some destination) length state).gpr destination = 0 ∧
    (x86LoadResume (some destination) length state).memory = state.memory ∧
    (x86LoadResume (some destination) length state).rflags = state.rflags ∧
    (x86LoadResume (some destination) length state).xmm0 = state.xmm0 ∧
    (x86LoadResume (some destination) length state).pc = state.pc+BitVec.ofNat 64 length ∧
    (∀ register, register ≠ destination →
      (x86LoadResume (some destination) length state).gpr register = state.gpr register) := by
  refine ⟨by simp [x86LoadResume],rfl,rfl,rfl,rfl,?_⟩
  intro register different
  simp [x86LoadResume,Ne.symm different]

/-- ARM saved-frame recovery clears the selected whole X register, with
field31 discarded as XZR, then advances one instruction. SP is unchanged.
Physical X5 must not be confused with stock BPF's DONT_CLEAR sentinel. -/
def arm64LoadResume (destination : Option AArch64.Register)
    (state : AArch64.State) : AArch64.State :=
  { (match destination with
      | some register => AArch64.writeReg state register 0
      | none => state) with pc := state.pc+4 }

/-- The scalar non-writeback load's raw read fault is handled separately
from alignment faults. No register, memory or event is borrowed from a
successful transfer, and the actual full X destination is cleared. -/
theorem arm64_recovered_load (state : AArch64.State) (width : AArch64.MemoryWidth)
    (destination base : AArch64.Register) (offset : Word)
    (signedTo : Option AArch64.Width)
    (aligned : AArch64.spAlignmentFault state base = none)
    (fault : readMemory state.memory (AArch64.memoryBase state base+offset) width.bytes =
      .error (.read (AArch64.memoryBase state base+offset) width.bytes)) :
    recoverRead (arm64LoadResume (some destination))
      (AArch64.memoryStep ⟨width,.load destination signedTo,base,offset⟩ state) =
      ⟨arm64LoadResume (some destination) state,
        [.fault (.read (AArch64.memoryBase state base+offset) width.bytes)],none⟩ := by
  simp [recoverRead,AArch64.memoryStep,aligned,fault]

/-- XZR recovery discards the clear and changes only PC. -/
theorem arm64_resume_xzr (state : AArch64.State) :
    arm64LoadResume (some 31) state = { state with pc := state.pc+4 } := by
  simp [arm64LoadResume,AArch64.writeReg]
  congr 1
  funext register
  have different : register.val ≠ 31 := by have := register.isLt; omega
  change (if register.val = 31 then 0 else state.gpr register) = state.gpr register
  simp [different]

end KProgTV.NativeLinkFinalImage
#print axioms KProgTV.NativeLinkFinalImage.recovery_success
#print axioms KProgTV.NativeLinkFinalImage.recovery_nonread
#print axioms KProgTV.NativeLinkFinalImage.recovery_raw_trace
#print axioms KProgTV.NativeLinkFinalImage.x86_recovered_load
#print axioms KProgTV.NativeLinkFinalImage.x86_resume_frame
#print axioms KProgTV.NativeLinkFinalImage.arm64_recovered_load
#print axioms KProgTV.NativeLinkFinalImage.arm64_resume_xzr

namespace KProgTV.NativeLinkFinalImage
open KProgFormal.Reference

/-- Native X5 really is a destination. A physical ARM encoding must keep it
separate from stock BPF's DONT_CLEAR value5 when instantiating this model. -/
theorem arm64_resume_x5 (state : AArch64.State) :
    (arm64LoadResume (some 5) state).gpr 5 = 0 ∧
    (arm64LoadResume (some 5) state).sp = state.sp := by
  constructor
  · change (if (5 : Nat) = 5 then (0 : Word) else state.gpr 5) = 0
    rfl
  · rfl

end KProgTV.NativeLinkFinalImage
#print axioms KProgTV.NativeLinkFinalImage.arm64_resume_x5
