import KProgFormal.Generated.NativeLinkSource

/-!
Universal refinement of the source-extracted shared literal resolver, serializer
and chunk selector. Extraction recognizes complete source bodies; these laws
quantify arbitrary records, retained maps, callback results and images. Linux
C/compiler, map callback/provenance and reference primitives retain their usual
platform contracts. Final producer edits, executable ownership and the readonly
object relation have separate interfaces in NativeLinkProducerImage.
-/
namespace KProgFormal.NativeLinkSourceRefinement
open Reference NativeLinkProducer NativeLinkProducerImage NativeLinkSource

/-- C offsets come from clang's layout of the extracted real record declaration;
Rust and loader serialization use the same little-endian field sequence. -/
theorem wire_abi : recordOffsets = [0,4,8] ∧ recordSize = 16 := by decide

theorem source_wire (r : Record) : serialize r = wire r := rfl

theorem source_record_copy (r : Record) : readRecord (serialize r) = some r :=
  wire_roundtrip r

theorem chunk_wire_copy (chunk : Chunk) (records : List Record) :
    readRecords ((chunkWire chunk records).length / recordSize) (chunkWire chunk records) =
      some (chunkRecords chunk records) :=
  kernel_record_copy _

theorem chunk_selected (chunk : Chunk) (records : List Record)
    (localRecord : Record) (member : localRecord ∈ chunkRecords chunk records) :
    ∃ r ∈ records, slotSelected chunk r ∧ localRecord = localize chunk r := by
  obtain ⟨r, selected, same⟩ := List.mem_map.mp member
  obtain ⟨inside, selected⟩ := List.mem_filter.mp selected
  exact ⟨r, inside, of_decide_eq_true selected, same.symm⟩

theorem scope_slot_size (kind : BitVec 32)
    (scope : kind = 5 ∨ kind = 6 ∨ kind = 7 ∨ kind = 8) :
    slotBytes kind = anchorSize kind := by
  rcases scope with h | h | h | h <;> subst kind <;> decide

theorem chunk_record_fields (chunk : Chunk) (records : List Record)
    (localRecord : Record) (member : localRecord ∈ chunkRecords chunk records)
    (scope : localRecord.kind = 5 ∨ localRecord.kind = 6 ∨ localRecord.kind = 7 ∨ localRecord.kind = 8) :
    ∃ r ∈ records,
      chunk.start + localRecord.offset.toNat = r.offset.toNat ∧
      localRecord.kind = r.kind ∧ localRecord.target = r.target ∧
      localRecord.offset.toNat + anchorSize r.kind ≤ chunk.size := by
  obtain ⟨r, inside, selected, same⟩ := chunk_selected chunk records localRecord member
  subst localRecord
  have sameSize := scope_slot_size r.kind scope
  have selected : Selected chunk r := by
    simpa only [slotSelected, sameSize, Selected] using selected
  have h := local_record_correspondence chunk r selected
  exact ⟨r, inside, h.1, h.2.1, h.2.2.1, h.2.2.2.1⟩

/-- The same retained map ID and exact offset passed to its direct-value API. -/
def TargetWitness (kind : BitVec 32) (encoded : Word) (m : Map) (target : Word) : Prop :=
  m.id = encoded.setWidth 32 ∧
  if kind = mapPointer then
    (encoded >>> 32).setWidth 32 = (0 : BitVec 32) ∧ target = m.address
  else
    ((encoded >>> 32).setWidth 32 : BitVec 32).toNat < m.valueSize.toNat ∧
    ∃ callback base, m.directValue = some callback ∧
      callback ((encoded >>> 32).setWidth 32) = some base ∧
      target = base + (((encoded >>> 32).setWidth 32 : BitVec 32).zeroExtend 64)

theorem source_map_success (kind : BitVec 32) (encoded target : Word) (maps : List Map)
    (success : mapTarget kind encoded maps = some target) :
    ∃ m ∈ maps, TargetWitness kind encoded m target := by
  induction maps with
  | nil => simp [mapTarget] at success
  | cons m rest ih =>
    simp only [mapTarget] at success
    split at success
    next different =>
      obtain ⟨selected, member, witness⟩ := ih success
      exact ⟨selected, List.mem_cons_of_mem m member, witness⟩
    next same =>
      have identity : m.id = encoded.setWidth 32 := by simpa using same
      refine ⟨m, List.mem_cons_self, identity, ?_⟩
      split at success
      next pointer =>
        simp only [pointer, ite_true]
        split at success
        next zero => exact ⟨zero, (Option.some.inj success).symm⟩
        next => contradiction
      next value =>
        simp only [value, ite_false]
        split at success
        next bounded =>
          cases callbackEq : m.directValue with
          | none => simp [callbackEq] at success
          | some callback =>
            simp only [callbackEq] at success
            cases baseEq : callback ((encoded >>> 32).setWidth 32) with
            | none => simp [baseEq] at success
            | some base =>
              simp only [baseEq] at success
              change some (base + (((encoded >>> 32).setWidth 32 : BitVec 32).zeroExtend 64)) = some target at success
              exact ⟨bounded, callback, base, rfl, baseEq, (Option.some.inj success).symm⟩
        next => contradiction

/-- Lookup commits to its first matching retained object, including its error. -/
theorem source_first_match (kind : BitVec 32) (encoded : Word) (m : Map) (rest : List Map)
    (identity : m.id = encoded.setWidth 32) :
    mapTarget kind encoded (m::rest) = mapTarget kind encoded [m] := by
  simp only [mapTarget, identity, bne_self_eq_false, Bool.false_eq_true, ite_false]

/-- Kind5 reaches the original object's address with the packed zero offset. -/
theorem map_pointer_kind5 (identity : BitVec 32) (maps : List Map) (target : Word)
    (success : mapTarget mapPointer (packTarget identity 0) maps = some target) :
    ∃ m ∈ maps, m.id = identity ∧ target = m.address := by
  obtain ⟨m, member, witness⟩ := source_map_success _ _ _ _ success
  have fields := pack_target_identity identity 0
  have detail := witness.2
  simp only [ite_true] at detail
  exact ⟨m, member, witness.1.trans fields, detail.2⟩

/-- Kind6 passes the packed offset to the callback and adds it once. -/
theorem map_value_kind6 (identity offset : BitVec 32) (maps : List Map) (target : Word)
    (success : mapTarget mapValue (packTarget identity offset) maps = some target) :
    ∃ m ∈ maps, m.id = identity ∧ offset.toNat < m.valueSize.toNat ∧
      ∃ callback base, m.directValue = some callback ∧ callback offset = some base ∧
        target = base + offset.zeroExtend 64 := by
  obtain ⟨m, member, identityEq, witness⟩ := source_map_success _ _ _ _ success
  have different : mapValue ≠ mapPointer := by decide
  simp only [different, ite_false, pack_target_offset] at witness
  exact ⟨m, member, identityEq.trans (pack_target_identity _ _), witness⟩

/-- Every successful current C literal write is the exact eight-byte copy.
The source and result preserve full kind/target identity through resolution. -/
theorem source_literal_success (r : Record) (length : Nat) (destination emitted : Image)
    (maps : List Map) (success : emitLiteral r length destination maps = some emitted) :
    r.offset.toNat + 8 ≤ length ∧
      ∃ target, (if r.kind = helperPointer then some r.target else mapTarget r.kind r.target maps) =
        some target ∧ emitted = copy destination r.offset.toNat (fromList (le64 target)) 0 8 := by
  unfold emitLiteral at success
  split at success
  next bounded =>
    cases resolved : (if r.kind = helperPointer then some r.target else mapTarget r.kind r.target maps) with
    | none => simp [resolved] at success
    | some target =>
      simp only [resolved] at success
      change some (copy destination r.offset.toNat (fromList (le64 target)) 0 8) = some emitted at success
      exact ⟨bounded, target, rfl, (Option.some.inj success).symm⟩
  next => contradiction

theorem source_literal_byte (r : Record) (length : Nat) (destination emitted : Image)
    (maps : List Map) (success : emitLiteral r length destination maps = some emitted) :
    ∃ target, (if r.kind = helperPointer then some r.target else mapTarget r.kind r.target maps) =
      some target ∧ ∀ i < 8, emitted (r.offset.toNat+i) = (fromList (le64 target)) i := by
  obtain ⟨_, target, resolved, same⟩ := source_literal_success r length destination emitted maps success
  refine ⟨target, resolved, ?_⟩
  intro i inside
  rw [same, copy_byte _ _ _ 0 8 i inside]
  simp only [Nat.zero_add]

theorem source_literal_frame (r : Record) (length : Nat) (destination emitted : Image)
    (maps : List Map) (success : emitLiteral r length destination maps = some emitted)
    (i : Nat) (outside : i < r.offset.toNat ∨ r.offset.toNat+8 ≤ i) :
    emitted i = destination i := by
  obtain ⟨_, _, _, same⟩ := source_literal_success r length destination emitted maps success
  rw [same]
  exact copy_frame _ _ _ _ _ _ outside

theorem helper_pointer_kind7 (r : Record) (length : Nat) (destination : Image) (maps : List Map)
    (kind : r.kind = helperPointer) (fits : r.offset.toNat+8 ≤ length) :
    emitLiteral r length destination maps =
      some (copy destination r.offset.toNat (fromList (le64 r.target)) 0 8) := by
  simp [emitLiteral, fits, kind, Option.map]

/-- Metadata8's original byte image and packed global object coordinate persist. -/
theorem readonly_kind8 (resolve : Resolution) (image : Image) (identity offset : BitVec 32) :
    applyRecord resolve image ⟨0, readonlyData, packTarget identity offset⟩ = image ∧
      (((packTarget identity offset) >>> 32).setWidth 32 : BitVec 32) = offset :=
  ⟨readonly_record_identity _ _ _ rfl, pack_target_offset _ _⟩

/-- Successful C size_t literal arithmetic derives from the wire's u32 offset. -/
theorem literal_offset_defined (offset : BitVec 32) : offset.toNat+8 < 2^64 := by
  have bound := offset.isLt
  omega

/-- Producer kind selection and packed target use the original same-map row. -/
theorem source_bind_pointer (site : BitVec 32) (length : Nat) (identity : BitVec 32)
    (address valueAddress : Word) (valueSize : BitVec 32) (fits : site.toNat+8 ≤ length) :
    bindMapRecord site length identity address address valueAddress valueSize =
      some ⟨site,mapPointer,packTarget identity 0⟩ := by
  simp [bindMapRecord, fits]

/-- Successful value binding retains the complete difference in its u32 field;
the existing value-size branch establishes the integer conversion domain. -/
theorem source_bind_value (site : BitVec 32) (length : Nat) (identity : BitVec 32)
    (symbolAddress mapAddress valueAddress : Word) (valueSize : BitVec 32)
    (record : Record) (different : symbolAddress ≠ mapAddress)
    (success : bindMapRecord site length identity symbolAddress mapAddress valueAddress valueSize = some record) :
    ∃ offset : BitVec 32,
      record = ⟨site,mapValue,packTarget identity offset⟩ ∧
      offset.toNat = symbolAddress.toNat-valueAddress.toNat ∧ offset.toNat < valueSize.toNat := by
  simp only [bindMapRecord, different, ite_false] at success
  split at success
  next =>
    split at success
    next domain =>
      have bound := valueSize.isLt
      have conversion : symbolAddress.toNat-valueAddress.toNat < 2^32 := by omega
      refine ⟨BitVec.ofNat 32 (symbolAddress.toNat-valueAddress.toNat), (Option.some.inj success).symm, ?_, ?_⟩
      · exact Nat.mod_eq_of_lt conversion
      · simpa only [BitVec.toNat_ofNat, Nat.mod_eq_of_lt conversion] using domain.2.2
    next => contradiction
  next => contradiction

/-- The generated case domain has exactly the source loop's legal widths and
complete in-object byte spans, for objects of every finite size. -/
theorem source_readonly_case_domain (length offset width : Nat) :
    (offset,width) ∈ readonlyCases length ↔ width ∈ ([1,2,4,8] : List Nat) ∧ offset+width ≤ length := by
  simp only [readonlyCases, readonlyWidths, List.mem_flatMap, List.mem_map,
    List.mem_range, Prod.mk.injEq]
  constructor
  · rintro ⟨w, member, i, bound, same, equal⟩
    subst w; subst i
    have positive : 0 < width := by
      have choices : width=1 ∨ width=2 ∨ width=4 ∨ width=8 := by simpa using member
      omega
    exact ⟨member, by omega⟩
  · rintro ⟨member, bound⟩
    exact ⟨width, member, offset, by omega, rfl, rfl⟩

/-- Every sized native/proof object uses precisely the shared ELF byte slice. -/
theorem source_sized_object (data : List Byte) (sectionSize offset size : Nat)
    (readonlySection unnamedBss : Bool) (positive : size ≠ 0)
    (fits : offset+size ≤ data.length) :
    x86ObjectBytes data sectionSize offset size readonlySection unnamedBss =
      some ((data.drop offset).take size,0) ∧
      ((data.drop offset).take size).length = size := by
  constructor
  · unfold x86ObjectBytes
    rw [if_pos positive, if_pos fits]
  · simp only [List.length_take, List.length_drop]
    omega

/-- Every zero-sized readonly label retains the whole section bytes and its
within-section displacement, matching the shared producer routine. -/
theorem source_section_object (data : List Byte) (sectionSize offset : Nat)
    (unnamedBss : Bool) (positive : 0 < data.length) (fits : offset ≤ data.length) :
    x86ObjectBytes data sectionSize offset 0 true unnamedBss = some (data,offset) := by
  simp [x86ObjectBytes, positive, fits, Option.bind]

/-- The proof ELF and native append paths copy the same canonical object
bytes. Their different output placements retain the full byte identity. -/
theorem source_object_copies (data : List Byte) (proof native : Image)
    (proofOffset nativeOffset i : Nat) (inside : i < data.length) :
    copy proof proofOffset (fromList data) 0 data.length (proofOffset+i) =
      copy native nativeOffset (fromList data) 0 data.length (nativeOffset+i) := by
  rw [copy_byte _ _ _ 0 _ i inside, copy_byte _ _ _ 0 _ i inside]

/-- Total image-level resolution of the successful shared C path. The default
value remains unreachable on the successful branches used in these theorems. -/
def sourceResolution (maps : List Map) : Resolution := fun kind target =>
  (if kind = helperPointer then some target else mapTarget kind target maps).getD 0

theorem source_literal_refines (r : Record) (length : Nat) (destination emitted : Image)
    (maps : List Map) (success : emitLiteral r length destination maps = some emitted)
    (literal : r.kind ≠ 8) :
    emitted = applyRecord (sourceResolution maps) destination r := by
  obtain ⟨_, target, resolved, same⟩ := source_literal_success r length destination emitted maps success
  have targetEq : sourceResolution maps r.kind r.target = target := by
    simp only [sourceResolution, resolved, Option.getD_some]
  simp only [applyRecord, literal, ite_false, targetEq]
  exact same

theorem source_scoped_record_refines (r : Record) (length : Nat) (destination emitted : Image)
    (maps : List Map) (success : emitScopedRecord r length destination maps = some emitted) :
    emitted = applyRecord (sourceResolution maps) destination r := by
  unfold emitScopedRecord at success
  split at success
  next metadata =>
    have kind : r.kind = 8 := metadata
    rw [readonly_record_identity _ _ _ kind]
    exact (Option.some.inj success).symm
  next literal =>
    split at success
    next => exact source_literal_refines r length destination emitted maps success literal
    next => contradiction

/-- Every successful ordered selected-kind C loop equals S5's image operation.
The statement quantifies all images, records, overlaps and orderings. Other
relocation kinds retain their own transformation/consumer interfaces. -/
theorem source_scoped_loop_refines (length : Nat) (maps : List Map)
    (destination emitted : Image) (records : List Record)
    (success : emitScopedRecords length maps destination records = some emitted) :
    emitted = applyRecords (sourceResolution maps) destination records := by
  induction records generalizing destination emitted with
  | nil => exact (Option.some.inj success).symm
  | cons record rest ih =>
    cases first : emitScopedRecord record length destination maps with
    | none => simp [emitScopedRecords, first] at success
    | some next =>
      have later : emitScopedRecords length maps next rest = some emitted := by
        simpa only [emitScopedRecords, first, Option.bind_some] using success
      rw [ih next emitted later, source_scoped_record_refines _ _ _ _ _ first]
      rfl

/-- Counts of actual kref/module primitives and their source-level owners.
The split teardown state retains the module during the capsule callback. -/
structure Ownership where
  capsuleRefs : Nat
  moduleRefs : Nat
  transient : Nat
  programs : Nat
  callbacks : Nat
  deriving DecidableEq, Repr

def Balanced (s : Ownership) : Prop :=
  s.capsuleRefs = s.transient + s.programs ∧
  s.moduleRefs = s.programs + s.callbacks

def initialOwnership : Ownership := ⟨1,0,1,0,0⟩

/-- The operations implement the recognized kref_get/put, fresh-aux retain and
core callback/module_put ordering. The primitive's owner premises describe
its legal C invocation domain, uniformly for every program. -/
inductive OwnershipStep : Ownership → Ownership → Prop
  | getTransient (s : Ownership) (live : s.capsuleRefs > 0) :
      OwnershipStep s {s with capsuleRefs := s.capsuleRefs+1, transient := s.transient+1}
  | putTransient (s : Ownership) (owned : s.transient > 0) :
      OwnershipStep s {s with capsuleRefs := s.capsuleRefs-1, transient := s.transient-1}
  | retainProgram (s : Ownership) (live : s.capsuleRefs > 0) :
      OwnershipStep s {s with capsuleRefs := s.capsuleRefs+1, moduleRefs := s.moduleRefs+1, programs := s.programs+1}
  | releaseProgram (s : Ownership) (owned : s.programs > 0) :
      OwnershipStep s {s with capsuleRefs := s.capsuleRefs-1, programs := s.programs-1, callbacks := s.callbacks+1}
  | releaseModule (s : Ownership) (owned : s.callbacks > 0) :
      OwnershipStep s {s with moduleRefs := s.moduleRefs-1, callbacks := s.callbacks-1}

inductive OwnershipRun : Ownership → Ownership → Prop
  | refl (s : Ownership) : OwnershipRun s s
  | next {first middle last : Ownership} : OwnershipRun first middle →
      OwnershipStep middle last → OwnershipRun first last

theorem initial_balanced : Balanced initialOwnership := ⟨rfl,rfl⟩

theorem ownership_step_balanced (first last : Ownership) (balanced : Balanced first)
    (step : OwnershipStep first last) : Balanced last := by
  cases step <;> simp only [Balanced] at * <;> omega

theorem ownership_run_balanced (first last : Ownership) (balanced : Balanced first)
    (run : OwnershipRun first last) : Balanced last := by
  induction run with
  | refl => exact balanced
  | next _ step ih => exact ownership_step_balanced _ _ ih step

/-- Every finite legal history retains both capsule storage and its module
while any emitted program remains live, including after its request closes. -/
theorem execution_retains_objects (s : Ownership) (run : OwnershipRun initialOwnership s)
    (executing : s.programs > 0) : s.capsuleRefs > 0 ∧ s.moduleRefs > 0 := by
  have balanced := ownership_run_balanced _ _ initial_balanced run
  unfold Balanced at balanced
  omega

/-- The sole capsule final-release point follows all program owner releases.
Both modules' complete free_blob bodies then put each retained map token. -/
theorem capsule_release_after_programs (s : Ownership) (run : OwnershipRun initialOwnership s)
    (lastReference : s.capsuleRefs = 0) : s.programs = 0 ∧ s.transient = 0 := by
  have balanced := ownership_run_balanced _ _ initial_balanced run
  unfold Balanced at balanced
  omega

/-- Every callback executes with its module reference, including the callback
that frees the capsule and its retained maps. -/
theorem callback_retains_module (s : Ownership) (run : OwnershipRun initialOwnership s)
    (callback : s.callbacks > 0) : s.moduleRefs > 0 := by
  have balanced := ownership_run_balanced _ _ initial_balanced run
  unfold Balanced at balanced
  omega

end KProgFormal.NativeLinkSourceRefinement
