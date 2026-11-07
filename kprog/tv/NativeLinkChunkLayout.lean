import NativeLinkGuardedEmission

/-! The common binding validator and group cursor establish a logical byte
partition. Local relocation records rebase into the same canonical writer
at every final executable base. -/
namespace KProgTV.NativeLinkChunkLayout
open KProgFormal.Reference NativeLinkPatchTable

structure Chunk where
  offset : BitVec 32
  size : BitVec 32
  deriving DecidableEq

/-- The successful unsigned bounds and positive native size in binding_validate. -/
def ValidChunk (total : BitVec 32) (chunk : Chunk) : Prop :=
  chunk.offset.toNat≤total.toNat ∧ 0<chunk.size.toNat ∧
    chunk.size.toNat≤(total-chunk.offset).toNat

/-- group_prepare starts its u32 cursor at zero, compares each chunk offset,
adds the accepted size, and compares the final cursor with the total. -/
def CheckedGroup (total : BitVec 32) : BitVec 32 → List Chunk → Prop
  | cursor,[] => cursor=total
  | cursor,chunk::rest => chunk.offset=cursor ∧ ValidChunk total chunk ∧
      CheckedGroup total (cursor+chunk.size) rest

def Ordered (first second : Chunk) : Prop :=
  first.offset.toNat+first.size.toNat≤second.offset.toNat

def Owns (chunk : Chunk) (address : Nat) : Prop :=
  chunk.offset.toNat≤address ∧ address<chunk.offset.toNat+chunk.size.toNat

/-- Every accepted cursor addition is exact in Nat and bounded by total. -/
theorem valid_end (total : BitVec 32) (chunk : Chunk) (valid : ValidChunk total chunk) :
    (chunk.offset+chunk.size).toNat=chunk.offset.toNat+chunk.size.toNat ∧
      chunk.offset.toNat+chunk.size.toNat≤total.toNat := by
  obtain ⟨start,positive,size⟩ := valid
  have bound := total.isLt
  simp only [BitVec.toNat_sub] at size
  simp only [BitVec.toNat_add]
  omega

theorem checked_lower (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) :
    ∀ chunk∈chunks, cursor.toNat≤chunk.offset.toNat := by
  induction chunks generalizing cursor with
  | nil => intro chunk member; simp at member
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      have endpoint := valid_end total head valid
      intro chunk member
      rcases List.mem_cons.mp member with same | inside
      · subst chunk; exact Nat.le_of_eq (congrArg BitVec.toNat position.symm)
      · have lower := ih (cursor+head.size) tailChecked chunk inside
        rw [←position,endpoint.1] at lower
        have start := congrArg BitVec.toNat position
        omega

theorem checked_ordered (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) : chunks.Pairwise Ordered := by
  induction chunks generalizing cursor with
  | nil => exact List.Pairwise.nil
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      apply List.pairwise_cons.mpr
      refine ⟨?_,ih (cursor+head.size) tailChecked⟩
      intro chunk member
      have lower := checked_lower total (cursor+head.size) rest tailChecked chunk member
      rw [←position,(valid_end total head valid).1] at lower
      exact lower

theorem checked_size_sum (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) :
    cursor.toNat+(chunks.map (fun chunk => chunk.size.toNat)).sum=total.toNat := by
  induction chunks generalizing cursor with
  | nil => simpa only [List.map_nil,List.sum_nil,Nat.add_zero] using congrArg BitVec.toNat checked
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      have tailSize := ih (cursor+head.size) tailChecked
      rw [←position,(valid_end total head valid).1] at tailSize
      simp only [List.map_cons,List.sum_cons]
      rw [←position]
      omega

/-- Each logical native byte belongs to a checked chunk. -/
theorem checked_coverage (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) (address : Nat)
    (lower : cursor.toNat≤address) (upper : address<total.toNat) :
    ∃ chunk∈chunks, Owns chunk address := by
  induction chunks generalizing cursor with
  | nil => change cursor=total at checked; subst cursor; omega
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      by_cases inside : address<head.offset.toNat+head.size.toNat
      · exact ⟨head,List.mem_cons_self,by unfold Owns; rw [position]; exact ⟨lower,by simpa only [position] using inside⟩⟩
      · have endpoint := valid_end total head valid
        have nextLower : (cursor+head.size).toNat≤address := by rw [←position,endpoint.1]; omega
        obtain ⟨chunk,member,owns⟩ := ih (cursor+head.size) tailChecked nextLower
        exact ⟨chunk,List.mem_cons_of_mem head member,owns⟩

/-- Ordered half-open intervals give unique chunk ownership. -/
theorem ordered_unique (chunks : List Chunk) (ordered : chunks.Pairwise Ordered)
    (first second : Chunk) (firstMember : first∈chunks) (secondMember : second∈chunks)
    (address : Nat) (firstOwns : Owns first address) (secondOwns : Owns second address) : first=second := by
  induction chunks with
  | nil => simp at firstMember
  | cons head rest ih =>
      obtain ⟨headOrder,tailOrder⟩ := List.pairwise_cons.mp ordered
      rcases List.mem_cons.mp firstMember with firstHead | firstTail
      · subst first
        rcases List.mem_cons.mp secondMember with same | secondTail
        · exact same.symm
        · have apart := headOrder second secondTail
          unfold Ordered Owns at *
          omega
      · rcases List.mem_cons.mp secondMember with secondHead | secondTail
        · subst second
          have apart := headOrder first firstTail
          unfold Ordered Owns at *
          omega
        · exact ih tailOrder firstTail secondTail

/-- A local record's complete consumed span fits its owning chunk. -/
def Fits (chunk : Chunk) (record : Record) : Prop :=
  record.offset.toNat+recordSpan record≤chunk.size.toNat

def rebase (chunk : Chunk) (record : Record) : Record :=
  {record with offset := chunk.offset+record.offset}

theorem rebase_span (chunk : Chunk) (record : Record) :
    recordSpan (rebase chunk record)=recordSpan record := rfl

theorem rebase_offset (total : BitVec 32) (chunk : Chunk) (record : Record)
    (valid : ValidChunk total chunk) (fits : Fits chunk record) :
    (rebase chunk record).offset.toNat=chunk.offset.toNat+record.offset.toNat := by
  have endpoint := valid_end total chunk valid
  have bound := total.isLt
  change (chunk.offset+record.offset).toNat=_
  simp only [BitVec.toNat_add]
  unfold Fits at fits
  omega

theorem rebase_bounds (total : BitVec 32) (chunk : Chunk) (record : Record)
    (valid : ValidChunk total chunk) (fits : Fits chunk record) :
    chunk.offset.toNat≤(rebase chunk record).offset.toNat ∧
      (rebase chunk record).offset.toNat+recordSpan (rebase chunk record)≤
        chunk.offset.toNat+chunk.size.toNat := by
  rw [rebase_offset total chunk record valid fits,rebase_span]
  unfold Fits at fits
  omega

/-- Rebased records name exactly the local chunk-base patch, including the
final CALL displacement and literal target at wrapping64-bit addresses. -/
theorem rebase_materialize (total : BitVec 32) (chunk : Chunk) (record : Record)
    (valid : ValidChunk total chunk) (fits : Fits chunk record) (base : Word) :
    materialize base (rebase chunk record)=materialize (base+chunk.offset.zeroExtend 64) record := by
  have offset := rebase_offset total chunk record valid fits
  have globalBound := (rebase chunk record).offset.isLt
  have chunkBound := chunk.offset.isLt
  have recordBound := record.offset.isLt
  have wide : (rebase chunk record).offset.zeroExtend 64=
      chunk.offset.zeroExtend 64+record.offset.zeroExtend 64 := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_setWidth,BitVec.toNat_add]
    omega
  unfold materialize
  rw [wide]
  simp only [rebase,BitVec.add_assoc]

/-- Local interval separation survives the checked u32 rebase. -/
theorem rebase_separated (total : BitVec 32) (chunk : Chunk) (first second : Record)
    (valid : ValidChunk total chunk) (firstFits : Fits chunk first) (secondFits : Fits chunk second)
    (apart : RecordSeparated first second) : RecordSeparated (rebase chunk first) (rebase chunk second) := by
  unfold RecordSeparated at *
  rw [rebase_offset total chunk first valid firstFits,rebase_offset total chunk second valid secondFits,
    rebase_span,rebase_span]
  rcases apart with forward | backward
  · exact Or.inl (by omega)
  · exact Or.inr (by omega)

theorem cross_chunk_separated (total : BitVec 32) (first second : Chunk)
    (firstValid : ValidChunk total first) (secondValid : ValidChunk total second)
    (ordered : Ordered first second) (left right : Record)
    (leftFits : Fits first left) (rightFits : Fits second right) :
    RecordSeparated (rebase first left) (rebase second right) := by
  have leftBounds := rebase_bounds total first left firstValid leftFits
  have rightBounds := rebase_bounds total second right secondValid rightFits
  unfold RecordSeparated Ordered at *
  exact Or.inl (by omega)


/-- Every group member carries the same accepted total bounds. -/
theorem checked_valid (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) : ∀ chunk∈chunks, ValidChunk total chunk := by
  induction chunks generalizing cursor with
  | nil => intro chunk member; simp at member
  | cons head rest ih =>
      obtain ⟨position,valid,tailChecked⟩ := checked
      intro chunk member
      rcases List.mem_cons.mp member with same | inside
      · subst chunk; exact valid
      · exact ih (cursor+head.size) tailChecked chunk inside

/-- Accepted groups give an exact logical cover and a unique owner for every
byte before the total native size. -/
theorem checked_partition (total : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total 0 chunks) (address : Nat) (inside : address<total.toNat) :
    ∃ owner∈chunks, Owns owner address ∧
      ∀ candidate∈chunks, Owns candidate address → candidate=owner := by
  obtain ⟨owner,member,owns⟩ := checked_coverage total 0 chunks checked address (by simp) inside
  refine ⟨owner,member,owns,?_⟩
  intro candidate candidateMember candidateOwns
  exact ordered_unique chunks (checked_ordered total 0 chunks checked)
    candidate owner candidateMember member address candidateOwns owns

def globalRecords (chunks : List Chunk) (records : Chunk → List Record) : List Record :=
  chunks.flatMap (fun chunk => (records chunk).map (rebase chunk))

/-- The only within-chunk premise is the producer's local field separation;
checked group bounds derive every cross-chunk separation relation. -/
theorem global_records_separated (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) (records : Chunk → List Record)
    (fits : ∀ chunk∈chunks, ∀ record∈records chunk, Fits chunk record)
    (within : ∀ chunk∈chunks, (records chunk).Pairwise RecordSeparated) :
    (globalRecords chunks records).Pairwise RecordSeparated := by
  unfold globalRecords
  apply List.pairwise_flatMap.mpr
  constructor
  · intro chunk member
    apply List.pairwise_map.mpr
    exact List.Pairwise.imp_of_mem
      (fun leftMember rightMember apart => rebase_separated total chunk _ _
        (checked_valid total cursor chunks checked chunk member)
        (fits chunk member _ leftMember) (fits chunk member _ rightMember) apart)
      (within chunk member)
  · apply List.Pairwise.imp_of_mem _ (checked_ordered total cursor chunks checked)
    intro first second firstMember secondMember ordered left leftMember right rightMember
    obtain ⟨localLeft,localLeftMember,rfl⟩ := List.mem_map.mp leftMember
    obtain ⟨localRight,localRightMember,rfl⟩ := List.mem_map.mp rightMember
    exact cross_chunk_separated total first second
      (checked_valid total cursor chunks checked first firstMember)
      (checked_valid total cursor chunks checked second secondMember) ordered localLeft localRight
      (fits first firstMember localLeft localLeftMember) (fits second secondMember localRight localRightMember)

/-- The canonical physical table follows from accepted chunk metadata and
local record construction at every executable base. -/
theorem physical_table_separated (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) (records : Chunk → List Record)
    (fits : ∀ chunk∈chunks, ∀ record∈records chunk, Fits chunk record)
    (within : ∀ chunk∈chunks, (records chunk).Pairwise RecordSeparated) (base : Word) :
    ((globalRecords chunks records).map (materialize base)).Pairwise Separated :=
  materialized_table_separated base _ (global_records_separated total cursor chunks checked records fits within)

/-- Chunk serialization composes with the existing canonical final-code CALL
relation, keeping the complete architectural state and exact effect trace. -/
theorem chunk_table_preservation (total : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total 0 chunks) (records : Chunk → List Record)
    (fits : ∀ chunk∈chunks, ∀ record∈records chunk, Fits chunk record)
    (within : ∀ chunk∈chunks, (records chunk).Pairwise RecordSeparated)
    (base : Word) (code : Memory)
    (valid : ∀ record∈globalRecords chunks records, OriginalValid code (materialize base record))
    (accepted : ∀ record∈globalRecords chunks records, AcceptedRecord base record) :
    TranslationValidation (intendedCalls ((globalRecords chunks records).map (materialize base)))
      (emittedCalls ((globalRecords chunks records).map (materialize base))
        (applyTable ((globalRecords chunks records).map (materialize base)) code)) Eq :=
  record_table_preservation base _ code
    (global_records_separated total 0 chunks checked records fits within) valid accepted

/-- Chunk-local fields and globally rebased fields materialize to exactly the
same ordered patch list. -/
theorem global_materialize (total cursor : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total cursor chunks) (records : Chunk → List Record)
    (fits : ∀ chunk∈chunks, ∀ record∈records chunk, Fits chunk record) (base : Word) :
    (globalRecords chunks records).map (materialize base)=
      chunks.flatMap (fun chunk => (records chunk).map (materialize (base+chunk.offset.zeroExtend 64))) := by
  unfold globalRecords
  rw [List.map_flatMap]
  apply congrArg List.flatten
  apply List.map_congr_left
  intro chunk member
  rw [List.map_map]
  apply List.map_congr_left
  intro record recordMember
  exact rebase_materialize total chunk record (checked_valid total cursor chunks checked chunk member)
    (fits chunk member record recordMember) base


/-- chunk_reloc_bytes selects a complete global span and serializes its
unsigned offset minus the owning chunk offset. -/
def Selected (chunk : Chunk) (record : Record) : Prop :=
  chunk.offset.toNat≤record.offset.toNat ∧
    record.offset.toNat+recordSpan record≤chunk.offset.toNat+chunk.size.toNat

def localize (chunk : Chunk) (record : Record) : Record :=
  {record with offset := record.offset-chunk.offset}

theorem selected_local_fits (chunk : Chunk) (record : Record) (selected : Selected chunk record) :
    Fits chunk (localize chunk record) := by
  have bound := record.offset.isLt
  have chunkBound := chunk.offset.isLt
  unfold Fits localize recordSpan
  change (record.offset-chunk.offset).toNat+(if record.isCall then 5 else 8)≤chunk.size.toNat
  simp only [BitVec.toNat_sub]
  unfold Selected recordSpan at selected
  omega

/-- The exact serialized local record reconstructs the original global
record, including its target and call/literal selector. -/
theorem rebase_localize (chunk : Chunk) (record : Record) :
    rebase chunk (localize chunk record)=record := by
  have offset : chunk.offset+(record.offset-chunk.offset)=record.offset := by
    rw [BitVec.add_comm]
    exact BitVec.sub_add_cancel _ _
  cases record
  simp only [rebase,localize,offset]

theorem serialized_materialize (total : BitVec 32) (chunk : Chunk) (record : Record)
    (valid : ValidChunk total chunk) (selected : Selected chunk record) (base : Word) :
    materialize (base+chunk.offset.zeroExtend 64) (localize chunk record)=materialize base record := by
  have same := rebase_materialize total chunk (localize chunk record) valid
    (selected_local_fits chunk record selected) base
  rw [rebase_localize] at same
  exact same.symm

/-- A complete selected field has the same unique chunk owner as its first
byte. Selection retains the full5B/8B consumed span. -/
theorem selected_unique (total : BitVec 32) (chunks : List Chunk)
    (checked : CheckedGroup total 0 chunks) (first second : Chunk)
    (firstMember : first∈chunks) (secondMember : second∈chunks) (record : Record)
    (firstSelected : Selected first record) (secondSelected : Selected second record) : first=second := by
  have positive : 0<recordSpan record := by unfold recordSpan; split <;> omega
  unfold Selected at firstSelected secondSelected
  exact ordered_unique chunks (checked_ordered total 0 chunks checked) first second firstMember secondMember
    record.offset.toNat ⟨firstSelected.1,by omega⟩ ⟨secondSelected.1,by omega⟩

end KProgTV.NativeLinkChunkLayout

#print axioms KProgTV.NativeLinkChunkLayout.valid_end
#print axioms KProgTV.NativeLinkChunkLayout.checked_lower
#print axioms KProgTV.NativeLinkChunkLayout.checked_ordered
#print axioms KProgTV.NativeLinkChunkLayout.checked_size_sum
#print axioms KProgTV.NativeLinkChunkLayout.checked_coverage
#print axioms KProgTV.NativeLinkChunkLayout.ordered_unique
#print axioms KProgTV.NativeLinkChunkLayout.rebase_span
#print axioms KProgTV.NativeLinkChunkLayout.rebase_offset
#print axioms KProgTV.NativeLinkChunkLayout.rebase_bounds
#print axioms KProgTV.NativeLinkChunkLayout.rebase_materialize
#print axioms KProgTV.NativeLinkChunkLayout.rebase_separated
#print axioms KProgTV.NativeLinkChunkLayout.cross_chunk_separated

#print axioms KProgTV.NativeLinkChunkLayout.checked_valid

#print axioms KProgTV.NativeLinkChunkLayout.checked_partition

#print axioms KProgTV.NativeLinkChunkLayout.global_records_separated

#print axioms KProgTV.NativeLinkChunkLayout.physical_table_separated

#print axioms KProgTV.NativeLinkChunkLayout.chunk_table_preservation

#print axioms KProgTV.NativeLinkChunkLayout.global_materialize

#print axioms KProgTV.NativeLinkChunkLayout.selected_local_fits

#print axioms KProgTV.NativeLinkChunkLayout.rebase_localize

#print axioms KProgTV.NativeLinkChunkLayout.serialized_materialize

#print axioms KProgTV.NativeLinkChunkLayout.selected_unique
