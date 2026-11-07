import NativeLinkLiteral

/-! One ordered table for existing x86 rel32 and shared literal writes.
Canonical Memory supplies every mutation and canonical X86 supplies CALL.
The layout predicate ranges over the complete consumed span of each record. -/
namespace KProgTV.NativeLinkPatchTable
open KProgFormal.Reference NativeLinkRelocation NativeLinkLiteral

inductive Patch
  | call (record : NativeLinkRelocationTable.Patch)
  | literal (slot target : Word)

def writeAddress : Patch → Word
  | .call record => record.slot+(1#64)
  | .literal slot _ => slot

def writeSize : Patch → Nat
  | .call _ => 4
  | .literal _ _ => 8

def writeValue : Patch → Word
  | .call record => record.displacement.zeroExtend 64
  | .literal _ target => target

def spanStart : Patch → Word
  | .call record => record.slot
  | .literal slot _ => slot

def spanSize : Patch → Nat
  | .call _ => 5
  | .literal _ _ => 8

def expectedBytes : Patch → Array Byte
  | .call record => callBytes record.displacement
  | .literal _ target => (valueBytes target 8).toArray

def OriginalValid (code : Memory) : Patch → Prop
  | .call record => code.value record.slot=(0xe8#8)
  | .literal _ _ => True

def applyPatch (code : Memory) (patch : Patch) : Memory :=
  storeMemory code (writeAddress patch) (writeValue patch) (writeSize patch)

def applyTable : List Patch → Memory → Memory
  | [],code => code
  | patch::rest,code => applyTable rest (applyPatch code patch)

def OutsideWrite (address : Word) (writer : Patch) : Prop :=
  writeSize writer≤(address-writeAddress writer).toNat

def Protects (live writer : Patch) : Prop :=
  ∀ i<spanSize live, OutsideWrite (spanStart live+BitVec.ofNat 64 i) writer

def Separated (first second : Patch) : Prop :=
  Protects first second ∧ Protects second first

theorem patch_outside (code : Memory) (patch : Patch) (address : Word)
    (outside : OutsideWrite address patch) :
    (applyPatch code patch).value address=code.value address ∧
      (applyPatch code patch).initialized address=code.initialized address := by
  have guard : ¬(address-writeAddress patch).toNat<writeSize patch := by
    unfold OutsideWrite at outside
    omega
  simp only [applyPatch,storeMemory,guard,ite_false,and_self]

theorem table_permissions (patches : List Patch) (code : Memory) :
    (applyTable patches code).readable=code.readable ∧
      (applyTable patches code).writable=code.writable := by
  induction patches generalizing code with
  | nil => exact ⟨rfl,rfl⟩
  | cons patch rest ih => exact ih (applyPatch code patch)

theorem table_value_outside (patches : List Patch) (code : Memory) (address : Word)
    (outside : ∀ patch∈patches, OutsideWrite address patch) :
    (applyTable patches code).value address=code.value address := by
  induction patches generalizing code with
  | nil => rfl
  | cons patch rest ih =>
      exact (ih (applyPatch code patch) (fun p member => outside p (List.mem_cons_of_mem patch member))).trans
        (patch_outside code patch address (outside patch List.mem_cons_self)).1

theorem table_span_outside (patches : List Patch) (code : Memory) (slot : Word) (count : Nat)
    (outside : ∀ patch∈patches, ∀ i<count, OutsideWrite (slot+BitVec.ofNat 64 i) patch) :
    bytesAt (applyTable patches code) slot count=bytesAt code slot count := by
  apply List.map_congr_left
  intro i member
  exact table_value_outside patches code _ (fun patch inside => outside patch inside i (List.mem_range.mp member))

theorem single_patch_bytes (code : Memory) (patch : Patch) (valid : OriginalValid code patch) :
    (bytesAt (applyPatch code patch) (spanStart patch) (spanSize patch)).toArray=expectedBytes patch := by
  cases patch with
  | call record => exact NativeLinkRelocationTable.written_call_bytes code record valid
  | literal slot target => exact congrArg List.toArray (literal_bytes code slot target)

/-- Each final consumed span retains its intended bytes across every earlier
and later mixed write, with all addresses interpreted at the final base. -/
theorem table_patch_bytes (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch) :
    ∀ patch∈patches, (bytesAt (applyTable patches code) (spanStart patch) (spanSize patch)).toArray=
      expectedBytes patch := by
  induction patches generalizing code with
  | nil => intro patch member; simp at member
  | cons head rest ih =>
      obtain ⟨apart,tailApart⟩ := List.pairwise_cons.mp separated
      have tailValid : ∀ p∈rest, OriginalValid (applyPatch code head) p := by
        intro p member
        cases p with
        | literal slot target => trivial
        | call record =>
            have retainedSpan : OutsideWrite record.slot head := by
              simpa +decide [spanStart,spanSize] using (apart (.call record) member).2 0 (by change 0<5; decide)
            exact (patch_outside code head record.slot retainedSpan).1.trans
              (valid (.call record) (List.mem_cons_of_mem head member))
      intro p member
      rcases List.mem_cons.mp member with same | inside
      · subst p
        have retainedSpan := table_span_outside rest (applyPatch code head) (spanStart head) (spanSize head)
          (fun p member i small => (apart p member).1 i small)
        change (bytesAt (applyTable rest (applyPatch code head)) (spanStart head) (spanSize head)).toArray=_
        rw [retainedSpan]
        exact single_patch_bytes code head (valid head List.mem_cons_self)
      · exact ih (applyPatch code head) tailApart tailValid p inside

theorem table_literal_word (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (slot target : Word) (member : Patch.literal slot target∈patches) :
    wordAt (applyTable patches code) slot 8=target := by
  have bytes := table_patch_bytes patches code separated valid (.literal slot target) member
  change (bytesAt (applyTable patches code) slot 8).toArray=(valueBytes target 8).toArray at bytes
  have sameBytes := congrArg Array.toList bytes
  simp only [List.toList_toArray] at sameBytes
  unfold wordAt
  rw [sameBytes,← literal_bytes code slot target]
  exact literal_word code slot target

theorem table_call_decode (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (record : NativeLinkRelocationTable.Patch) (member : Patch.call record∈patches)
    (s : X86.State) (position : s.pc=record.slot)
    (accepted : checkedRel32 record.slot record.target=some record.displacement) :
    X86.decode (bytesAt (applyTable patches code) s.pc 5).toArray s=
      .ok (.call (.immediate record.target) (s.pc+(5#64))) := by
  have bytes := table_patch_bytes patches code separated valid (.call record) member
  change (bytesAt (applyTable patches code) record.slot 5).toArray=callBytes record.displacement at bytes
  rw [position,bytes]
  simpa only [position] using checked_call_decode s record.target record.displacement (by
    simpa only [position] using accepted)

def intendedCalls (patches : List Patch) : BlockStep X86.State := fun before events after =>
  ∃ record, Patch.call record∈patches ∧ before.pc=record.slot ∧ intendedCall record.target before events after

def emittedCalls (patches : List Patch) (code : Memory) : BlockStep X86.State :=
  fun before events after => ∃ record, Patch.call record∈patches ∧ before.pc=record.slot ∧
    ∃ instruction effect, X86.decode (bytesAt code before.pc 5).toArray before=.ok instruction ∧
      X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

/-- Actual final mixed-table code refines the intended canonical CALL at
all selected PCs, retaining its complete state, ordered events and faults. -/
theorem mixed_call_preservation (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (accepted : ∀ record, Patch.call record∈patches →
      checkedRel32 record.slot record.target=some record.displacement) :
    TranslationValidation (intendedCalls patches) (emittedCalls patches (applyTable patches code)) Eq := by
  constructor
  intro n p events next relation source
  subst p
  obtain ⟨record,member,position,displacement,effect,range,step,trace,state⟩ := source
  have emitted : emittedCalls patches (applyTable patches code) n events next :=
    ⟨record,member,position,.call (.immediate record.target) (n.pc+(5#64)),effect,
      table_call_decode patches code separated valid record member n position (accepted record member),step,trace,state⟩
  exact ⟨next,by simpa only [List.append_nil] using Execution.next emitted (Execution.refl next),rfl⟩

theorem mixed_call_reflects (patches : List Patch) (code : Memory)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (accepted : ∀ record, Patch.call record∈patches →
      checkedRel32 record.slot record.target=some record.displacement)
    (before after : X86.State) (events : List Event)
    (run : emittedCalls patches (applyTable patches code) before events after) :
    intendedCalls patches before events after := by
  obtain ⟨record,member,position,instruction,effect,decoded,step,trace,state⟩ := run
  have same : instruction=.call (.immediate record.target) (before.pc+(5#64)) :=
    Except.ok.inj (decoded.symm.trans
      (table_call_decode patches code separated valid record member before position (accepted record member)))
  subst instruction
  exact ⟨record,member,position,record.displacement,effect,
    by simpa only [position] using accepted record member,step,trace,state⟩

/-- Every protected instruction fetch has exactly its original decoder
result, for arbitrary state, byte count and mixed-table ordering. -/
theorem table_decode_outside (patches : List Patch) (code : Memory) (s : X86.State) (count : Nat)
    (outside : ∀ patch∈patches, ∀ i<count, OutsideWrite (s.pc+BitVec.ofNat 64 i) patch) :
    X86.decode (bytesAt (applyTable patches code) s.pc count).toArray s=
      X86.decode (bytesAt code s.pc count).toArray s := by
  rw [table_span_outside patches code s.pc count outside]

/-- The span witness is static layout evidence at the selected PC. Execution
uses the canonical byte decoder and instruction step on the supplied image. -/
def retainedInstruction (patches : List Patch) (code : Memory) (count : Nat) : BlockStep X86.State :=
  fun before events after =>
    (∀ patch∈patches, ∀ i<count, OutsideWrite (before.pc+BitVec.ofNat 64 i) patch) ∧
    ∃ instruction effect, X86.decode (bytesAt code before.pc count).toArray before=.ok instruction ∧
      X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

theorem retained_instruction_preservation (patches : List Patch) (code : Memory) (count : Nat) :
    TranslationValidation (retainedInstruction patches code count)
      (retainedInstruction patches (applyTable patches code) count) Eq := by
  constructor
  intro n p events next relation source
  subst p
  obtain ⟨outside,instruction,effect,decoded,step,trace,state⟩ := source
  have emitted : retainedInstruction patches (applyTable patches code) count n events next :=
    ⟨outside,instruction,effect,(table_decode_outside patches code n count outside).trans decoded,step,trace,state⟩
  exact ⟨next,by simpa only [List.append_nil] using Execution.next emitted (Execution.refl next),rfl⟩

theorem retained_instruction_reflects (patches : List Patch) (code : Memory) (count : Nat)
    (before after : X86.State) (events : List Event)
    (run : retainedInstruction patches (applyTable patches code) count before events after) :
    retainedInstruction patches code count before events after := by
  obtain ⟨outside,instruction,effect,decoded,step,trace,state⟩ := run
  exact ⟨outside,instruction,effect,(table_decode_outside patches code before count outside).symm.trans decoded,
    step,trace,state⟩

/-- Serialized x86 call/shared literal records retain u32 offsets and u64
bound targets. Kind selects the existing5B or8B consumed span. -/
structure Record where
  offset : BitVec 32
  target : Word
  isCall : Bool

def recordSpan (record : Record) : Nat := if record.isCall then 5 else 8

def materialize (base : Word) (record : Record) : Patch :=
  let slot := base+record.offset.zeroExtend 64
  if record.isCall then
    .call ⟨slot,record.target,(record.target-(slot+(5#64))).setWidth 32⟩
  else .literal slot record.target

def RecordSeparated (first second : Record) : Prop :=
  first.offset.toNat+recordSpan first≤second.offset.toNat ∨
    second.offset.toNat+recordSpan second≤first.offset.toNat

def AcceptedRecord (base : Word) (record : Record) : Prop :=
  match materialize base record with
  | .call patch => checkedRel32 patch.slot patch.target=some patch.displacement
  | .literal _ _ => True

set_option maxHeartbeats 4000000 in
/-- Ordered typed metadata intervals protect both complete consumed spans
at every final64-bit base, including wrapping address addition. -/
theorem ordered_records_separated (base : Word) (first second : Record)
    (ordered : first.offset.toNat+recordSpan first≤second.offset.toNat) :
    Separated (materialize base first) (materialize base second) := by
  have firstBound := first.offset.isLt
  have secondBound := second.offset.isLt
  have sizeBound : recordSpan first≤8 := by
    unfold recordSpan
    split <;> omega
  have wordOrder : first.offset.zeroExtend 64+BitVec.ofNat 64 (recordSpan first)≤second.offset.zeroExtend 64 := by
    change (first.offset.zeroExtend 64+BitVec.ofNat 64 (recordSpan first)).toNat≤
      (second.offset.zeroExtend 64).toNat
    simp only [BitVec.toNat_add,BitVec.toNat_setWidth,BitVec.toNat_ofNat]
    omega
  rcases first with ⟨firstOffset,firstTarget,firstCall⟩
  rcases second with ⟨secondOffset,secondTarget,secondCall⟩
  cases firstCall <;> cases secondCall
  all_goals constructor
  all_goals intro i bounded
  all_goals have indices : i=0 ∨ i=1 ∨ i=2 ∨ i=3 ∨ i=4 ∨ i=5 ∨ i=6 ∨ i=7 := by simp only [materialize,spanSize,Bool.false_eq_true,ite_false,ite_true] at bounded; omega
  all_goals rcases indices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals dsimp only [OutsideWrite,materialize,writeAddress,writeSize,spanStart,spanSize,recordSpan] at *
  all_goals first
    | omega
    | (change (4#64)≤(_ : Word); unfold Word at *; bv_decide)
    | (change (8#64)≤(_ : Word); unfold Word at *; bv_decide)

theorem record_offsets_separated (base : Word) (first second : Record)
    (apart : RecordSeparated first second) :
    Separated (materialize base first) (materialize base second) := by
  rcases apart with forward | backward
  · exact ordered_records_separated base first second forward
  · obtain ⟨secondProtected,firstProtected⟩ := ordered_records_separated base second first backward
    exact ⟨firstProtected,secondProtected⟩

theorem materialized_table_separated (base : Word) (records : List Record)
    (apart : records.Pairwise RecordSeparated) :
    (records.map (materialize base)).Pairwise Separated := by
  apply List.pairwise_map.mpr
  exact apart.imp (fun {first second} interval => record_offsets_separated base first second interval)

theorem materialized_table_ranges (base : Word) (records : List Record)
    (accepted : ∀ record∈records, AcceptedRecord base record) :
    ∀ patch, Patch.call patch∈records.map (materialize base) →
      checkedRel32 patch.slot patch.target=some patch.displacement := by
  intro patch member
  obtain ⟨record,inside,same⟩ := List.mem_map.mp member
  have range := accepted record inside
  unfold AcceptedRecord at range
  rw [same] at range
  exact range

/-- Typed record layout, existing range acceptance and initial opcode facts
supply the whole mixed-table canonical CALL TV instance. -/
theorem record_table_preservation (base : Word) (records : List Record) (code : Memory)
    (apart : records.Pairwise RecordSeparated)
    (valid : ∀ record∈records, OriginalValid code (materialize base record))
    (accepted : ∀ record∈records, AcceptedRecord base record) :
    TranslationValidation (intendedCalls (records.map (materialize base)))
      (emittedCalls (records.map (materialize base)) (applyTable (records.map (materialize base)) code)) Eq := by
  apply mixed_call_preservation _ code (materialized_table_separated base records apart)
  · intro patch member
    obtain ⟨record,inside,rfl⟩ := List.mem_map.mp member
    exact valid record inside
  · exact materialized_table_ranges base records accepted

end KProgTV.NativeLinkPatchTable

#print axioms KProgTV.NativeLinkPatchTable.patch_outside
#print axioms KProgTV.NativeLinkPatchTable.table_permissions
#print axioms KProgTV.NativeLinkPatchTable.table_value_outside
#print axioms KProgTV.NativeLinkPatchTable.table_span_outside
#print axioms KProgTV.NativeLinkPatchTable.single_patch_bytes
#print axioms KProgTV.NativeLinkPatchTable.table_patch_bytes
#print axioms KProgTV.NativeLinkPatchTable.table_literal_word
#print axioms KProgTV.NativeLinkPatchTable.table_call_decode
#print axioms KProgTV.NativeLinkPatchTable.mixed_call_preservation
#print axioms KProgTV.NativeLinkPatchTable.mixed_call_reflects

#print axioms KProgTV.NativeLinkPatchTable.ordered_records_separated
#print axioms KProgTV.NativeLinkPatchTable.record_offsets_separated
#print axioms KProgTV.NativeLinkPatchTable.materialized_table_separated
#print axioms KProgTV.NativeLinkPatchTable.materialized_table_ranges
#print axioms KProgTV.NativeLinkPatchTable.record_table_preservation

#print axioms KProgTV.NativeLinkPatchTable.table_decode_outside
#print axioms KProgTV.NativeLinkPatchTable.retained_instruction_preservation
#print axioms KProgTV.NativeLinkPatchTable.retained_instruction_reflects
