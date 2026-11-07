import NativeLinkByteLayout

/-! Exact complete-field boundary scan used by plan_blob_chunks. Its Nat
cursor corresponds to the loader's bounded size_t offset and accepted u32
chunk metadata. Canonical relocation materialization remains shared. -/
namespace KProgTV.NativeLinkChunkPlanner
open KProgFormal.Reference NativeLinkPatchTable NativeLinkChunkLayout

def Crosses (cursor finish : Nat) (record : Record) : Prop :=
  cursor<record.offset.toNat ∧ record.offset.toNat<finish ∧
    finish<record.offset.toNat+recordSpan record

instance (cursor finish : Nat) (record : Record) : Decidable (Crosses cursor finish record) :=
  inferInstanceAs (Decidable (_ ∧ _ ∧ _))

def adjust (cursor finish : Nat) (record : Record) : Nat :=
  if Crosses cursor finish record then record.offset.toNat else finish

def choose : Nat → Nat → List Record → Nat
  | _,finish,[] => finish
  | cursor,finish,record::rest => choose cursor (adjust cursor finish record) rest

/-- A safe boundary lies outside the interior of every complete consumed span. -/
def SafeCut (records : List Record) (point : Nat) : Prop :=
  ∀ record∈records, point≤record.offset.toNat ∨ record.offset.toNat+recordSpan record≤point

theorem span_positive (record : Record) : 0<recordSpan record := by
  unfold recordSpan; split <;> omega

theorem span_bounded (record : Record) : recordSpan record≤8 := by
  unfold recordSpan; split <;> omega

theorem adjust_bounds (cursor finish : Nat) (record : Record) (progress : cursor<finish) :
    cursor<adjust cursor finish record ∧ adjust cursor finish record≤finish := by
  unfold adjust
  split
  · rename_i active
    unfold Crosses at active
    omega
  · exact ⟨progress,Nat.le_refl _⟩

theorem choose_bounds (cursor finish : Nat) (records : List Record) (progress : cursor<finish) :
    cursor<choose cursor finish records ∧ choose cursor finish records≤finish := by
  induction records generalizing finish with
  | nil => exact ⟨progress,Nat.le_refl _⟩
  | cons record rest ih =>
      have head := adjust_bounds cursor finish record progress
      have tail := ih (adjust cursor finish record) head.1
      exact ⟨tail.1,Nat.le_trans tail.2 head.2⟩

/-- Each final cut is either the initial end or a field start visited by the
actual scan, independently of record order. -/
theorem choose_outcome (cursor finish : Nat) (records : List Record) :
    choose cursor finish records=finish ∨
      ∃ record∈records, choose cursor finish records=record.offset.toNat := by
  induction records generalizing finish with
  | nil => exact Or.inl rfl
  | cons record rest ih =>
      rcases ih (adjust cursor finish record) with same | changed
      · by_cases active : Crosses cursor finish record
        · exact Or.inr ⟨record,List.mem_cons_self,by simpa only [choose,adjust,if_pos active] using same⟩
        · exact Or.inl (by simpa only [choose,adjust,if_neg active] using same)
      · obtain ⟨writer,inside,position⟩ := changed
        exact Or.inr ⟨writer,List.mem_cons_of_mem record inside,position⟩

/-- If the scan retains its initial end, every visited crossing guard at
that end is false. Monotone lowering supplies the converse reasoning. -/
theorem choose_fixed (cursor finish : Nat) (records : List Record) (progress : cursor<finish)
    (same : choose cursor finish records=finish) :
    ∀ record∈records, ¬Crosses cursor finish record := by
  induction records generalizing finish with
  | nil => intro record member; simp at member
  | cons head rest ih =>
      have headBounds := adjust_bounds cursor finish head progress
      have tailBounds := choose_bounds cursor (adjust cursor finish head) rest headBounds.1
      have fixedHead : adjust cursor finish head=finish := by change choose cursor (adjust cursor finish head) rest=finish at same; omega
      have inactive : ¬Crosses cursor finish head := by
        intro active
        have position : adjust cursor finish head=head.offset.toNat := by simp only [adjust,if_pos active]
        unfold Crosses at active
        omega
      have fixedTail : choose cursor finish rest=finish := by simpa only [choose,fixedHead] using same
      intro record member
      rcases List.mem_cons.mp member with first | later
      · subst record; exact inactive
      · exact ih finish progress fixedTail record later

/-- Pairwise complete-span separation supplies the relation for any two
members, including identical member selections. -/
theorem member_intervals (records : List Record) (apart : records.Pairwise RecordSeparated)
    (first second : Record) (firstMember : first∈records) (secondMember : second∈records) :
    first=second ∨ RecordSeparated first second := by
  induction records with
  | nil => simp at firstMember
  | cons head rest ih =>
      obtain ⟨headApart,tailApart⟩ := List.pairwise_cons.mp apart
      rcases List.mem_cons.mp firstMember with firstHead | firstTail
      · subst first
        rcases List.mem_cons.mp secondMember with secondHead | secondTail
        · exact Or.inl secondHead.symm
        · exact Or.inr (headApart second secondTail)
      · rcases List.mem_cons.mp secondMember with secondHead | secondTail
        · subst second
          exact Or.inr (headApart first firstTail).symm
        · exact ih tailApart firstTail secondTail

theorem member_start_safe (records : List Record) (apart : records.Pairwise RecordSeparated)
    (writer : Record) (member : writer∈records) : SafeCut records writer.offset.toNat := by
  intro record inside
  rcases member_intervals records apart record writer inside member with same | separated
  · subst record; exact Or.inl (Nat.le_refl _)
  · unfold RecordSeparated at separated
    rcases separated with before | after
    · exact Or.inr before
    · exact Or.inl (by omega)

/-- Every accepted initial boundary advances to another safe boundary. The
scan's exact crossing predicate and the capacity bound retain whole fields. -/
theorem choose_safe (cursor capacity total : Nat) (records : List Record)
    (apart : records.Pairwise RecordSeparated) (cursorBound : cursor<total)
    (capacityPositive : 0<capacity) (cursorSafe : SafeCut records cursor)
    (fits : ∀ record∈records, record.offset.toNat+recordSpan record≤total)
    (sizes : ∀ record∈records, recordSpan record≤capacity) :
    SafeCut records (choose cursor (min (cursor+capacity) total) records) := by
  have progress : cursor<min (cursor+capacity) total := by omega
  rcases choose_outcome cursor (min (cursor+capacity) total) records with same | changed
  · have inactive := choose_fixed cursor (min (cursor+capacity) total) records progress same
    rw [same]
    intro record member
    have inBounds := fits record member
    have small := sizes record member
    have initial := cursorSafe record member
    have guard := inactive record member
    unfold Crosses at guard
    omega
  · obtain ⟨writer,member,position⟩ := changed
    rw [position]
    exact member_start_safe records apart writer member

/-- Each serialized chunk's end equals the loader's exact boundary scan. -/
def PlannedEnds (total : BitVec 32) (capacity : Nat) (records : List Record) (chunks : List Chunk) : Prop :=
  ∀ chunk∈chunks, chunk.offset.toNat+chunk.size.toNat=
    choose chunk.offset.toNat (min (chunk.offset.toNat+capacity) total.toNat) records

/-- Checked metadata and the exact planner recurrence propagate safe boundaries
through every chunk in the native byte partition. -/
theorem planned_ends_safe (total cursor : BitVec 32) (capacity : Nat) (records : List Record)
    (chunks : List Chunk) (checked : CheckedGroup total cursor chunks)
    (planned : PlannedEnds total capacity records chunks)
    (apart : records.Pairwise RecordSeparated) (capacityPositive : 0<capacity)
    (cursorSafe : SafeCut records cursor.toNat)
    (fits : ∀ record∈records, record.offset.toNat+recordSpan record≤total.toNat)
    (sizes : ∀ record∈records, recordSpan record≤capacity) :
    ∀ chunk∈chunks, SafeCut records (chunk.offset.toNat+chunk.size.toNat) := by
  induction chunks generalizing cursor with
  | nil => intro chunk member; simp at member
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      have endpoint := valid_end total head valid
      have cursorBound : head.offset.toNat<total.toNat := by
        have positive := valid.2.1
        omega
      have currentSafe : SafeCut records head.offset.toNat := by simpa only [position] using cursorSafe
      have headSafe := choose_safe head.offset.toNat capacity total.toNat records apart cursorBound
        capacityPositive currentSafe fits sizes
      rw [←planned head List.mem_cons_self] at headSafe
      have nextSafe : SafeCut records (cursor+head.size).toNat := by
        rw [←position,endpoint.1]
        exact headSafe
      intro chunk member
      rcases List.mem_cons.mp member with first | later
      · subst chunk; exact headSafe
      · exact ih (cursor+head.size) tailChecked
          (fun part inside => planned part (List.mem_cons_of_mem head inside)) nextSafe chunk later

/-- Every complete global field is selected by one unique actual chunk. This
connects first-byte ownership to the loader's whole-span selection predicate. -/
theorem planned_selection_complete (total : BitVec 32) (capacity : Nat) (records : List Record)
    (chunks : List Chunk) (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity records chunks)
    (apart : records.Pairwise RecordSeparated) (capacityPositive : 0<capacity)
    (fits : ∀ record∈records, record.offset.toNat+recordSpan record≤total.toNat)
    (sizes : ∀ record∈records, recordSpan record≤capacity) (record : Record) (member : record∈records) :
    ∃ owner∈chunks, Selected owner record ∧
      ∀ candidate∈chunks, Selected candidate record → candidate=owner := by
  have ends := planned_ends_safe total 0 capacity records chunks checked planned apart capacityPositive
    (by intro patch inside; exact Or.inl (by simp)) fits sizes
  have positive := span_positive record
  have limit := fits record member
  obtain ⟨owner,ownerMember,owns⟩ := checked_coverage total 0 chunks checked record.offset.toNat
    (by simp) (by omega)
  have safeEnd := ends owner ownerMember record member
  have selected : Selected owner record := by unfold Selected Owns at *; omega
  refine ⟨owner,ownerMember,selected,?_⟩
  intro candidate candidateMember candidateSelected
  exact selected_unique total chunks checked candidate owner candidateMember ownerMember record candidateSelected selected


def serialized (chunks : List Chunk) (records : List Record) : List Record :=
  globalRecords chunks (fun chunk => NativeLinkByteLayout.selectedRecords chunk records)

/-- Rebasing the actual selected local fields reconstructs precisely the
complete-span filter of original records, including their target and kind. -/
theorem serialized_identity (chunks : List Chunk) (records : List Record) :
    serialized chunks records=chunks.flatMap (fun chunk => records.filter (fun record =>
      chunk.offset.toNat≤record.offset.toNat &&
        record.offset.toNat+recordSpan record≤chunk.offset.toNat+chunk.size.toNat)) := by
  simp only [serialized,globalRecords,NativeLinkByteLayout.selectedRecords,List.map_map,
    Function.comp_def,rebase_localize,List.map_id_fun',id]

theorem serialized_separated (total : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total 0 chunks) (records : List Record)
    (apart : records.Pairwise RecordSeparated) : (serialized chunks records).Pairwise RecordSeparated := by
  apply global_records_separated total 0 chunks checked
    (fun chunk => NativeLinkByteLayout.selectedRecords chunk records)
  · intro chunk member
    exact NativeLinkByteLayout.selected_records_fit chunk records
  · intro chunk member
    exact NativeLinkByteLayout.selected_records_separated chunk records apart

/-- Complete planner coverage gives equality of record membership in both
directions after actual filtering, local serialization and global rebase. -/
theorem serialized_membership (total : BitVec 32) (capacity : Nat) (records : List Record)
    (chunks : List Chunk) (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity records chunks)
    (apart : records.Pairwise RecordSeparated) (capacityPositive : 0<capacity)
    (fits : ∀ record∈records, record.offset.toNat+recordSpan record≤total.toNat)
    (sizes : ∀ record∈records, recordSpan record≤capacity) (record : Record) :
    record∈serialized chunks records ↔ record∈records := by
  rw [serialized_identity]
  constructor
  · intro member
    obtain ⟨chunk,chunkMember,selectedMember⟩ := List.mem_flatMap.mp member
    exact (List.mem_filter.mp selectedMember).1
  · intro member
    obtain ⟨chunk,chunkMember,selected,unique⟩ := planned_selection_complete total capacity records chunks
      checked planned apart capacityPositive fits sizes record member
    apply List.mem_flatMap.mpr
    refine ⟨chunk,chunkMember,List.mem_filter.mpr ⟨member,?_⟩⟩
    simpa only [Bool.and_eq_true,decide_eq_true_eq] using selected

theorem separated_nodup (records : List Record) (apart : records.Pairwise RecordSeparated) : records.Nodup := by
  change records.Pairwise (fun first second => first≠second)
  apply apart.imp
  intro first second separated same
  subst second
  have positive := span_positive first
  unfold RecordSeparated at separated
  omega

/-- Complete-span separation controls exact record multiplicity as well as
membership, so serialized reconstruction retains each record once. -/
theorem nodup_count [DecidableEq Record] (records : List Record) (nodup : records.Nodup) (record : Record) :
    records.count record=if record∈records then 1 else 0 := by
  induction records with
  | nil => simp
  | cons head rest ih =>
      obtain ⟨absent,tailNodup⟩ := List.nodup_cons.mp nodup
      by_cases same : record=head
      · subst record
        simp [List.count_cons,absent,List.count_eq_zero_of_not_mem absent]
      · simp [List.count_cons,same,Ne.symm same,ih tailNodup]

/-- The actual planner's selected tables contain exactly the original record
multiset. Every wire-order theorem can consume this derived permutation. -/
theorem serialized_permutation (total : BitVec 32) (capacity : Nat) (records : List Record)
    (chunks : List Chunk) (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity records chunks)
    (apart : records.Pairwise RecordSeparated) (capacityPositive : 0<capacity)
    (fits : ∀ record∈records, record.offset.toNat+recordSpan record≤total.toNat)
    (sizes : ∀ record∈records, recordSpan record≤capacity) : records.Perm (serialized chunks records) := by
  classical
  apply List.perm_iff_count.mpr
  intro record
  rw [nodup_count records (separated_nodup records apart),
    nodup_count (serialized chunks records)
      (separated_nodup _ (serialized_separated total chunks checked records apart))]
  simp only [serialized_membership total capacity records chunks checked planned apart capacityPositive fits sizes]

/-- Encoded piece containment supplies the complete record bounds/separation;
accepted chunk metadata and exact planner ends supply whole-field coverage
and therefore the full serialized record permutation. -/
theorem layout_serialized_permutation (total : BitVec 32) (capacity : Nat) (chunks : List Chunk)
    (pieces : List NativeLinkByteLayout.Piece)
    (fits : ∀ piece∈pieces, NativeLinkByteLayout.Fits piece)
    (imageSize : NativeLinkByteLayout.byteLength pieces=total.toNat)
    (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity (NativeLinkByteLayout.records 0 pieces) chunks)
    (capacityBound : 8≤capacity) :
    (NativeLinkByteLayout.records 0 pieces).Perm
      (serialized chunks (NativeLinkByteLayout.records 0 pieces)) := by
  have bound : NativeLinkByteLayout.byteLength pieces≤2^32 := by have small := total.isLt; omega
  have apart := NativeLinkByteLayout.records_separated 0 pieces fits (by simpa using bound)
  apply serialized_permutation total capacity _ chunks checked planned apart (by omega)
  · intro record member
    have recordBound := (NativeLinkByteLayout.records_bounds 0 pieces fits (by simpa using bound) record member).2
    rw [Nat.zero_add,imageSize] at recordBound
    exact recordBound
  · intro record member
    exact Nat.le_trans (span_bounded record) capacityBound


/-- Readonly metadata uses a one-byte placement anchor in the actual loader.
Such an integer interval contributes the identity step to the boundary scan. -/
theorem unit_anchor_preserves (cursor finish start : Nat) :
    (if cursor<start ∧ start<finish ∧ finish<start+1 then start else finish)=finish := by
  split <;> omega

/-- The loader's supported128/16384 capacities and u32 native image domain
place its cursor additions and modeled span ends inside64-bit size_t. -/
theorem loader_arithmetic_bounds (total : BitVec 32) (cursor capacity : Nat)
    (cursorBound : cursor≤total.toNat) (capacityBound : capacity≤16384) (record : Record) :
    cursor+capacity<2^64 ∧ record.offset.toNat+recordSpan record<2^64 := by
  have totalBound := total.isLt
  have offsetBound := record.offset.isLt
  have size := span_bounded record
  omega


/-- Encoded-piece layout, the actual planner scan and serialized reconstruction
compose directly with canonical final-code CALL translation validation. -/
theorem planned_call_table_preservation (total : BitVec 32) (capacity : Nat) (chunks : List Chunk)
    (pieces : List NativeLinkByteLayout.Piece)
    (fits : ∀ piece∈pieces, NativeLinkByteLayout.Fits piece)
    (imageSize : NativeLinkByteLayout.byteLength pieces=total.toNat)
    (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity (NativeLinkByteLayout.records 0 pieces) chunks)
    (capacityBound : 8≤capacity) (base : Word) (code : Memory)
    (valid : ∀ record∈serialized chunks (NativeLinkByteLayout.records 0 pieces), OriginalValid code (materialize base record))
    (accepted : ∀ record∈serialized chunks (NativeLinkByteLayout.records 0 pieces), AcceptedRecord base record) :
    TranslationValidation
      (intendedCalls ((serialized chunks (NativeLinkByteLayout.records 0 pieces)).map (materialize base)))
      (emittedCalls ((serialized chunks (NativeLinkByteLayout.records 0 pieces)).map (materialize base))
        (applyTable ((serialized chunks (NativeLinkByteLayout.records 0 pieces)).map (materialize base)) code)) Eq := by
  apply NativeLinkByteLayout.wire_table_preservation pieces fits
    (by have bound := total.isLt; omega) _
    (layout_serialized_permutation total capacity chunks pieces fits imageSize checked planned capacityBound)
    base code valid accepted

/-- The complete MOVABS consumption theorem receives its wire permutation
from the planner proof, with original template/PC/field locations derived
from the same encoded image. -/
theorem planned_movabs_preservation (code : Memory) (base : Word)
    (before after : List NativeLinkByteLayout.Piece) (dst : X86.Register) (target : Word)
    (total : BitVec 32) (capacity : Nat) (chunks : List Chunk)
    (fits : ∀ piece∈before++NativeLinkByteLayout.movabsPiece dst target::after, NativeLinkByteLayout.Fits piece)
    (imageSize : NativeLinkByteLayout.byteLength (before++NativeLinkByteLayout.movabsPiece dst target::after)=total.toNat)
    (checked : CheckedGroup total 0 chunks)
    (planned : PlannedEnds total capacity (NativeLinkByteLayout.records 0 (before++NativeLinkByteLayout.movabsPiece dst target::after)) chunks)
    (capacityBound : 8≤capacity)
    (image : bytesAt code base (NativeLinkByteLayout.byteLength (before++NativeLinkByteLayout.movabsPiece dst target::after))=
      NativeLinkByteLayout.byteImage (before++NativeLinkByteLayout.movabsPiece dst target::after))
    (accepted : NativeLinkGuardedEmission.CheckedTable code code
      ((serialized chunks (NativeLinkByteLayout.records 0 (before++NativeLinkByteLayout.movabsPiece dst target::after))).map (materialize base)))
    (valid : ∀ record∈serialized chunks (NativeLinkByteLayout.records 0 (before++NativeLinkByteLayout.movabsPiece dst target::after)),
      OriginalValid code (materialize base record)) :
    TranslationValidation (NativeLinkMovabs.intended (base+BitVec.ofNat 64 (NativeLinkByteLayout.byteLength before)) dst target)
      (NativeLinkMovabs.emitted
        (applyTable ((serialized chunks (NativeLinkByteLayout.records 0 (before++NativeLinkByteLayout.movabsPiece dst target::after))).map (materialize base)) code)
        (base+BitVec.ofNat 64 (NativeLinkByteLayout.byteLength before))) Eq := by
  apply NativeLinkByteLayout.wire_movabs_preservation code base before after dst target fits
    (by have bound := total.isLt; omega) image _
    (layout_serialized_permutation total capacity chunks _ fits imageSize checked planned capacityBound)
    accepted valid

end KProgTV.NativeLinkChunkPlanner

#print axioms KProgTV.NativeLinkChunkPlanner.span_positive
#print axioms KProgTV.NativeLinkChunkPlanner.span_bounded
#print axioms KProgTV.NativeLinkChunkPlanner.adjust_bounds
#print axioms KProgTV.NativeLinkChunkPlanner.choose_bounds
#print axioms KProgTV.NativeLinkChunkPlanner.choose_outcome
#print axioms KProgTV.NativeLinkChunkPlanner.choose_fixed
#print axioms KProgTV.NativeLinkChunkPlanner.member_intervals
#print axioms KProgTV.NativeLinkChunkPlanner.member_start_safe
#print axioms KProgTV.NativeLinkChunkPlanner.choose_safe
#print axioms KProgTV.NativeLinkChunkPlanner.planned_ends_safe
#print axioms KProgTV.NativeLinkChunkPlanner.planned_selection_complete

#print axioms KProgTV.NativeLinkChunkPlanner.serialized_identity

#print axioms KProgTV.NativeLinkChunkPlanner.serialized_separated

#print axioms KProgTV.NativeLinkChunkPlanner.serialized_membership

#print axioms KProgTV.NativeLinkChunkPlanner.separated_nodup

#print axioms KProgTV.NativeLinkChunkPlanner.nodup_count

#print axioms KProgTV.NativeLinkChunkPlanner.serialized_permutation

#print axioms KProgTV.NativeLinkChunkPlanner.layout_serialized_permutation

#print axioms KProgTV.NativeLinkChunkPlanner.unit_anchor_preserves

#print axioms KProgTV.NativeLinkChunkPlanner.loader_arithmetic_bounds

#print axioms KProgTV.NativeLinkChunkPlanner.planned_call_table_preservation

#print axioms KProgTV.NativeLinkChunkPlanner.planned_movabs_preservation
