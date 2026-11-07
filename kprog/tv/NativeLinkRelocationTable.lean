import NativeLinkRelocation

/-! Universal code-patch table preservation for native-link kind1.
All code-byte operations use Reference.Memory and every instruction is
interpreted by the canonical X86 decoder. -/
namespace KProgTV.NativeLinkRelocationTable
open KProgFormal.Reference NativeLinkRelocation

structure Patch where
  slot : Word
  target : Word
  displacement : BitVec 32

def applyPatch (code : Memory) (patch : Patch) : Memory :=
  storeMemory code (patch.slot+(1#64)) (patch.displacement.zeroExtend 64) 4

def applyTable : List Patch → Memory → Memory
  | [],code => code
  | patch::rest,code => applyTable rest (applyPatch code patch)

/-- Reference stores recover every written byte across wrapping addresses. -/
theorem stored_bytes (code : Memory) (address value : Word) (count : Nat)
    (bounded : count≤2^64) :
    bytesAt (storeMemory code address value count) address count=valueBytes value count := by
  apply List.map_congr_left
  intro i inside
  have small : i<count := List.mem_range.mp inside
  have boundedIndex : i<2^64 := by omega
  have difference : (address+BitVec.ofNat 64 i)-address=BitVec.ofNat 64 i := by
    rw [BitVec.add_comm]
    exact BitVec.add_sub_cancel _ _
  have offset : ((address+BitVec.ofNat 64 i)-address).toNat=i := by
    rw [difference]
    simp only [BitVec.toNat_ofNat,Nat.mod_eq_of_lt boundedIndex]
  simp only [storeMemory,offset,small,ite_true]

/-- Immediate writes retain the E8 opcode immediately before the field. -/
theorem opcode_preserved (code : Memory) (patch : Patch) :
    (applyPatch code patch).value patch.slot=code.value patch.slot := by
  have outside : ¬(patch.slot-(patch.slot+(1#64))).toNat<4 := by
    unfold Word at *
    bv_decide
  exact (immediate_patch_preserves_outside code patch.slot patch.displacement patch.slot outside).1

/-- The five fetched bytes after an accepted placeholder patch are exactly
its E8 opcode and four displacement bytes for every32-bit value. -/
theorem written_call_bytes (code : Memory) (patch : Patch)
    (opcode : code.value patch.slot=(0xe8#8)) :
    (bytesAt (applyPatch code patch) patch.slot 5).toArray=callBytes patch.displacement := by
  have widenShift (value : BitVec 32) (shift : Nat) :
      (value.setWidth 64 >>> shift).setWidth 8=(value >>> shift).setWidth 8 := by
    rw [← BitVec.setWidth_ushiftRight (by decide : 32≤64)]
    exact BitVec.setWidth_setWidth_of_le _ (by decide : 8≤64)
  have splitBytes : bytesAt (applyPatch code patch) patch.slot 5=
      (applyPatch code patch).value patch.slot ::
        bytesAt (applyPatch code patch) (patch.slot+(1#64)) 4 := by
    simp +decide [bytesAt,List.range_succ,List.range_zero,List.map_append,
      List.map_cons,List.map_nil,List.map_singleton,BitVec.add_assoc]
  rw [splitBytes,opcode_preserved,opcode]
  rw [show bytesAt (applyPatch code patch) (patch.slot+(1#64)) 4=
      valueBytes (patch.displacement.zeroExtend 64) 4 from
        stored_bytes code _ _ 4 (by decide)]
  simp +decide [valueBytes,callBytes,List.range_succ,List.range_zero,List.map_append,
    List.map_cons,List.map_nil,List.map_singleton]
  exact ⟨widenShift _ 8,widenShift _ 16,widenShift _ 24⟩

/-- Every table retains the code permissions supplied by its allocator. -/
theorem table_permissions (patches : List Patch) (code : Memory) :
    (applyTable patches code).readable=code.readable ∧
      (applyTable patches code).writable=code.writable := by
  induction patches generalizing code with
  | nil => exact ⟨rfl,rfl⟩
  | cons patch rest ih => exact ih (applyPatch code patch)

/-- A retainedSpan byte lies outside the immediate field of a writer. -/
def OutsideWrite (address : Word) (patch : Patch) : Prop :=
  4≤(address-(patch.slot+(1#64))).toNat

def Protects (live writer : Patch) : Prop :=
  ∀ i<5, OutsideWrite (live.slot+BitVec.ofNat 64 i) writer

def Separated (first second : Patch) : Prop :=
  Protects first second ∧ Protects second first

theorem patch_value_outside (code : Memory) (patch : Patch) (address : Word)
    (outside : OutsideWrite address patch) :
    (applyPatch code patch).value address=code.value address := by
  exact (immediate_patch_preserves_outside code patch.slot patch.displacement address (by
    change 4≤(address-(patch.slot+(1#64))).toNat at outside
    omega)).1

/-- The ordered list of relocations retains every retainedSpan code byte. -/
theorem table_value_outside (patches : List Patch) (code : Memory) (address : Word)
    (outside : ∀ patch ∈ patches, OutsideWrite address patch) :
    (applyTable patches code).value address=code.value address := by
  induction patches generalizing code with
  | nil => rfl
  | cons patch rest ih =>
    exact (ih (applyPatch code patch) (fun p member => outside p (List.mem_cons_of_mem patch member))).trans
      (patch_value_outside code patch address (outside patch (List.mem_cons_self)))

theorem table_span_outside (patches : List Patch) (code : Memory) (slot : Word) (count : Nat)
    (outside : ∀ patch ∈ patches, ∀ i<count, OutsideWrite (slot+BitVec.ofNat 64 i) patch) :
    bytesAt (applyTable patches code) slot count=bytesAt code slot count := by
  apply List.map_congr_left
  intro i member
  exact table_value_outside patches code _ (fun patch inside => outside patch inside i (List.mem_range.mp member))

/-- Every record keeps its complete emitted CALL span through all later
records. The separation invariant applies uniformly to arbitrary table sizes. -/
theorem table_call_bytes (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (opcodes : ∀ patch ∈ patches, code.value patch.slot=(0xe8#8)) :
    ∀ patch ∈ patches, (bytesAt (applyTable patches code) patch.slot 5).toArray=
      callBytes patch.displacement := by
  induction patches generalizing code with
  | nil => intro patch member; simp at member
  | cons head rest ih =>
    obtain ⟨apart,tailApart⟩ := List.pairwise_cons.mp separated
    have tailOpcodes : ∀ p∈rest, (applyPatch code head).value p.slot=(0xe8#8) := by
      intro p member
      have retainedSpan : OutsideWrite p.slot head := by
        simpa +decide using (apart p member).2 0 (by decide)
      exact (patch_value_outside code head p.slot retainedSpan).trans
        (opcodes p (List.mem_cons_of_mem head member))
    intro p member
    rcases List.mem_cons.mp member with same | inside
    · subst p
      have retainedSpan := table_span_outside rest (applyPatch code head) head.slot 5
        (fun p member i small => (apart p member).1 i small)
      change (bytesAt (applyTable rest (applyPatch code head)) head.slot 5).toArray=_
      rw [retainedSpan]
      exact written_call_bytes code head (opcodes head List.mem_cons_self)
    · exact ih (applyPatch code head) tailApart tailOpcodes p inside

/-- Final table bytes decode to each record's exact bound target, with the
same canonical instruction and fall-through for every invocation state. -/
theorem table_call_decode (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (opcodes : ∀ patch ∈ patches, code.value patch.slot=(0xe8#8))
    (accepted : ∀ patch ∈ patches, checkedRel32 patch.slot patch.target=some patch.displacement)
    (patch : Patch) (member : patch∈patches) (s : X86.State) (position : s.pc=patch.slot) :
    X86.decode (bytesAt (applyTable patches code) s.pc 5).toArray s=
      .ok (.call (.immediate patch.target) (s.pc+(5#64))) := by
  rw [position,table_call_bytes patches code separated opcodes patch member]
  simpa only [position] using checked_call_decode s patch.target patch.displacement (by
    simpa only [position] using accepted patch member)

/-- The symbolic table selects the bound record at the current native PC. -/
def intendedCalls (patches : List Patch) : BlockStep X86.State := fun before events after =>
  ∃ patch ∈ patches, before.pc=patch.slot ∧ intendedCall patch.target before events after

/-- Execution fetches the final whole-table code bytes at the actual PC. -/
def emittedCalls (patches : List Patch) (code : Memory) : BlockStep X86.State :=
  fun before events after => ∃ patch ∈ patches, before.pc=patch.slot ∧
    ∃ instruction effect, X86.decode (bytesAt code before.pc 5).toArray before=.ok instruction ∧
      X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

/-- A complete well-formed table preserves every canonical CALL outcome,
full architectural successor, ordered memory event and fault. -/
theorem table_call_preservation (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (opcodes : ∀ patch ∈ patches, code.value patch.slot=(0xe8#8))
    (accepted : ∀ patch ∈ patches, checkedRel32 patch.slot patch.target=some patch.displacement) :
    TranslationValidation (intendedCalls patches) (emittedCalls patches (applyTable patches code)) Eq := by
  constructor
  intro n p events next relation source
  subst p
  obtain ⟨patch,member,position,displacement,effect,range,step,trace,state⟩ := source
  have emitted : emittedCalls patches (applyTable patches code) n events next :=
    ⟨patch,member,position,.call (.immediate patch.target) (n.pc+(5#64)),effect,
      table_call_decode patches code separated opcodes accepted patch member n position,step,trace,state⟩
  exact ⟨next,by simpa only [List.append_nil] using Execution.next emitted (Execution.refl next),rfl⟩

/-- Every final code-table step reflects the original bound CALL contract. -/
theorem table_call_reflects (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (opcodes : ∀ patch ∈ patches, code.value patch.slot=(0xe8#8))
    (accepted : ∀ patch ∈ patches, checkedRel32 patch.slot patch.target=some patch.displacement)
    (before after : X86.State) (events : List Event)
    (run : emittedCalls patches (applyTable patches code) before events after) :
    intendedCalls patches before events after := by
  obtain ⟨patch,member,position,instruction,effect,decoded,step,trace,state⟩ := run
  have same : instruction=.call (.immediate patch.target) (before.pc+(5#64)) :=
    Except.ok.inj (decoded.symm.trans
      (table_call_decode patches code separated opcodes accepted patch member before position))
  subst instruction
  exact ⟨patch,member,position,patch.displacement,effect,
    by simpa only [position] using accepted patch member,step,trace,state⟩

end KProgTV.NativeLinkRelocationTable
#print axioms KProgTV.NativeLinkRelocationTable.stored_bytes
#print axioms KProgTV.NativeLinkRelocationTable.opcode_preserved
#print axioms KProgTV.NativeLinkRelocationTable.written_call_bytes
#print axioms KProgTV.NativeLinkRelocationTable.table_permissions

#print axioms KProgTV.NativeLinkRelocationTable.patch_value_outside

#print axioms KProgTV.NativeLinkRelocationTable.table_value_outside

#print axioms KProgTV.NativeLinkRelocationTable.table_span_outside

#print axioms KProgTV.NativeLinkRelocationTable.table_call_bytes

#print axioms KProgTV.NativeLinkRelocationTable.table_call_decode

#print axioms KProgTV.NativeLinkRelocationTable.table_call_preservation

#print axioms KProgTV.NativeLinkRelocationTable.table_call_reflects
