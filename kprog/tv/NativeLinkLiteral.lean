import NativeLinkRelocationTable

/-! Universal metadata resolution and the shared eight-byte literal writer.
Memory and byte order come from the canonical reference library. Retained maps
and callback results are kernel environment inputs. -/
namespace KProgTV.NativeLinkLiteral
open KProgFormal.Reference

inductive MapKind | pointer | value
  deriving DecidableEq

structure RetainedMap where
  id : BitVec 32
  address : Word
  valueSize : BitVec 32
  directValue : BitVec 32 → Option Word

def encodeMap (id offset : BitVec 32) : Word :=
  id.zeroExtend 64 ||| (offset.zeroExtend 64 <<< 32)

def mapId (encoded : Word) : BitVec 32 := encoded.setWidth 32

def mapOffset (encoded : Word) : BitVec 32 := (encoded >>> 32).setWidth 32

theorem map_id_encoding (id offset : BitVec 32) : mapId (encodeMap id offset)=id := by
  unfold mapId encodeMap
  bv_decide

theorem map_offset_encoding (id offset : BitVec 32) : mapOffset (encodeMap id offset)=offset := by
  apply BitVec.eq_of_getLsbD_eq
  intro i bounded
  simp +decide [mapOffset,encodeMap,BitVec.zeroExtend,bounded]
  simp [show 32+i<64 by omega,show ¬32+i<32 by omega,
    Nat.add_sub_cancel_left,show i<64 by omega,bounded]

/-- The callback returns the kernel direct-value base for the supplied offset.
Successful value resolution adds that same offset exactly once. -/
def mapTarget (kind : MapKind) (map : RetainedMap) (offset : BitVec 32) : Option Word :=
  match kind with
  | .pointer => if offset=0 then some map.address else none
  | .value => if offset.toNat<map.valueSize.toNat then
      (map.directValue offset).map (fun base => base+offset.zeroExtend 64)
    else none

/-- Resolve the first retained map with the stable ID, as the kernel loop does. -/
def resolveMap (kind : MapKind) : List RetainedMap → Word → Option Word
  | [],_ => none
  | map::rest,encoded => if map.id=mapId encoded then mapTarget kind map (mapOffset encoded)
      else resolveMap kind rest encoded

def TargetWitness (kind : MapKind) (map : RetainedMap) (offset : BitVec 32) (target : Word) : Prop :=
  match kind with
  | .pointer => offset=0 ∧ target=map.address
  | .value => offset.toNat<map.valueSize.toNat ∧
      ∃ base, map.directValue offset=some base ∧ target=base+offset.zeroExtend 64

theorem map_target_sound (kind : MapKind) (map : RetainedMap) (offset : BitVec 32) (target : Word)
    (accepted : mapTarget kind map offset=some target) : TargetWitness kind map offset target := by
  cases kind with
  | pointer =>
      simp only [mapTarget] at accepted
      split at accepted
      · simp_all [TargetWitness]
      · contradiction
  | value =>
      simp only [mapTarget] at accepted
      split at accepted
      next bounded =>
        cases response : map.directValue offset with
        | none => simp [response] at accepted
        | some base =>
            simp only [response,Option.map_some,Option.some.injEq] at accepted
            have result : base+offset.zeroExtend 64=target := by simpa using accepted
            exact ⟨bounded,base,response,result.symm⟩
      next => contradiction

theorem resolve_map_sound (kind : MapKind) (maps : List RetainedMap) (encoded target : Word)
    (accepted : resolveMap kind maps encoded=some target) :
    ∃ map ∈ maps, map.id=mapId encoded ∧ TargetWitness kind map (mapOffset encoded) target := by
  induction maps with
  | nil => simp [resolveMap] at accepted
  | cons map rest ih =>
      simp only [resolveMap] at accepted
      split at accepted
      next identity => exact ⟨map,List.mem_cons_self,identity,map_target_sound _ _ _ _ accepted⟩
      next =>
        obtain ⟨selected,inside,identity,witness⟩ := ih accepted
        exact ⟨selected,List.mem_cons_of_mem map inside,identity,witness⟩

/-- A first matching ID commits lookup to that retained object and its result. -/
theorem first_matching_map (kind : MapKind) (map : RetainedMap) (rest : List RetainedMap)
    (encoded : Word) (identity : map.id=mapId encoded) :
    resolveMap kind (map::rest) encoded=mapTarget kind map (mapOffset encoded) := by
  simp only [resolveMap,identity,ite_true]

theorem pointer_offset_rejected (map : RetainedMap) (rest : List RetainedMap) (encoded : Word)
    (identity : map.id=mapId encoded) (offset : mapOffset encoded≠0) :
    resolveMap .pointer (map::rest) encoded=none := by
  rw [first_matching_map _ _ _ _ identity]
  simp only [mapTarget,offset,ite_false]

def emitLiteral (code : Memory) (slot target : Word) : Memory := storeMemory code slot target 8

theorem literal_bytes (code : Memory) (slot target : Word) :
    bytesAt (emitLiteral code slot target) slot 8=valueBytes target 8 :=
  NativeLinkRelocationTable.stored_bytes code slot target 8 (by decide)

theorem literal_word (code : Memory) (slot target : Word) :
    wordAt (emitLiteral code slot target) slot 8=target := by
  unfold wordAt
  rw [literal_bytes]
  simp +decide [valueBytes,littleEndian,List.range_succ,List.range_zero,List.map_append,
    List.map_cons,List.map_nil,List.map_singleton]
  unfold Word at *
  bv_decide

theorem literal_permissions (code : Memory) (slot target : Word) :
    (emitLiteral code slot target).readable=code.readable ∧
      (emitLiteral code slot target).writable=code.writable := ⟨rfl,rfl⟩

theorem literal_outside (code : Memory) (slot target address : Word)
    (outside : 8≤(address-slot).toNat) :
    (emitLiteral code slot target).value address=code.value address ∧
      (emitLiteral code slot target).initialized address=code.initialized address := by
  have bound : ¬(address-slot).toNat<8 := by omega
  simp only [emitLiteral,storeMemory,bound,ite_false,and_self]

theorem literal_initialized (code : Memory) (slot target : Word) :
    initializedAt (emitLiteral code slot target) slot 8=true := by
  apply List.all_eq_true.mpr
  intro i inside
  have small : i<8 := List.mem_range.mp inside
  have difference : (slot+BitVec.ofNat 64 i)-slot=BitVec.ofNat 64 i := by
    rw [BitVec.add_comm]
    exact BitVec.add_sub_cancel _ _
  have offset : ((slot+BitVec.ofNat 64 i)-slot).toNat=i := by
    rw [difference]
    simp only [BitVec.toNat_ofNat,Nat.mod_eq_of_lt (show i<2^64 by omega)]
  simp only [emitLiteral,storeMemory,offset,small,ite_true]

/-- Canonical memory consumption observes the complete resolved target and
one exact initialized eight-byte read at its actual address. -/
theorem literal_read (code : Memory) (slot target : Word)
    (allowed : permitted code.readable slot 8=true) :
    readMemory (emitLiteral code slot target) slot 8=
      .ok (target,.memory .read slot (valueBytes target 8) true) := by
  have readable : permitted (emitLiteral code slot target).readable slot 8=true := allowed
  simp only [readMemory,readable,ite_true,literal_word,literal_bytes,literal_initialized]

/-- The physical literal has the target resolved from the same retained object,
including the direct-value callback and its accepted value offset. -/
theorem map_literal_matches (kind : MapKind) (maps : List RetainedMap)
    (encoded target slot : Word) (code : Memory)
    (accepted : resolveMap kind maps encoded=some target) :
    wordAt (emitLiteral code slot target) slot 8=target ∧
      ∃ map ∈ maps, map.id=mapId encoded ∧ TargetWitness kind map (mapOffset encoded) target :=
  ⟨literal_word code slot target,resolve_map_sound kind maps encoded target accepted⟩

/-- Kernel acceptance uses the immutable original bytes for the placeholder
check and the current emitted image as the write destination. -/
def checkedLiteral (original destination : Memory) (base : Word) (length : Nat)
    (offset : BitVec 32) (target : Word) : Option Memory :=
  let slot := base+offset.zeroExtend 64
  if offset.toNat+8≤length ∧ bytesAt original slot 8=List.replicate 8 (0#8) then
    some (emitLiteral destination slot target)
  else none

theorem checked_literal_sound (original destination : Memory) (base : Word) (length : Nat)
    (offset : BitVec 32) (target : Word) (emitted : Memory)
    (accepted : checkedLiteral original destination base length offset target=some emitted) :
    offset.toNat+8≤length ∧
      bytesAt original (base+offset.zeroExtend 64) 8=List.replicate 8 (0#8) ∧
      emitted=emitLiteral destination (base+offset.zeroExtend 64) target ∧
      wordAt emitted (base+offset.zeroExtend 64) 8=target := by
  simp only [checkedLiteral] at accepted
  split at accepted
  next checks =>
    have same := Option.some.inj accepted
    exact ⟨checks.1,checks.2,same.symm,by rw [← same]; exact literal_word _ _ _⟩
  next => contradiction

theorem checked_literal_range_rejected (original destination : Memory) (base : Word) (length : Nat)
    (offset : BitVec 32) (target : Word) (outside : length<offset.toNat+8) :
    checkedLiteral original destination base length offset target=none := by
  simp only [checkedLiteral,show ¬offset.toNat+8≤length by omega,false_and,ite_false]

theorem checked_literal_placeholder_rejected (original destination : Memory) (base : Word) (length : Nat)
    (offset : BitVec 32) (target : Word)
    (changed : bytesAt original (base+offset.zeroExtend 64) 8≠List.replicate 8 (0#8)) :
    checkedLiteral original destination base length offset target=none := by
  simp only [checkedLiteral,changed,and_false,ite_false]

/-- Every valid u32 offset plus the literal size fits the supported 64-bit size_t. -/
theorem literal_size_arithmetic (offset : BitVec 32) : offset.toNat+8<2^64 := by
  have bound := offset.isLt
  omega

namespace ReadOnly
open KProgFormal.Reference

/-- Exact width/offset cases emitted by readonly_load_declarations. -/
def casesFor (data : List Byte) : List (Nat × Nat) :=
  [1,2,4,8].flatMap (fun width =>
    (List.range (data.length+1-width)).map (fun offset => (offset,width)))

theorem case_domain (data : List Byte) (offset width : Nat) :
    (offset,width) ∈ casesFor data ↔
      width ∈ ([1,2,4,8] : List Nat) ∧ offset+width≤data.length := by
  simp only [casesFor,List.mem_flatMap,List.mem_map,List.mem_range,
    Prod.mk.injEq]
  constructor
  · rintro ⟨w,member,i,bound,⟨same,eq⟩⟩
    subst w; subst i
    have positive : 0<width := by
      have choices : width=1 ∨ width=2 ∨ width=4 ∨ width=8 := by simpa using member
      omega
    exact ⟨member,by omega⟩
  · rintro ⟨member,bound⟩
    exact ⟨width,member,offset,by omega,rfl,rfl⟩

/-- Zero-initialized uint64_t followed by the selected fixed-size memcpy. -/
def copiedBytes (data : List Byte) (offset bytes : Nat) : List Byte :=
  (List.range bytes).map (fun i => (data[offset+i]?).getD 0)

/-- Immutable object bytes, permission and initialization at their linked base.
The surrounding program relation carries this image through guest transitions. -/
def Image (data : List Byte) (base : Word) (memory : Memory) : Prop :=
  ∀ i, i<data.length →
    memory.value (base+BitVec.ofNat 64 i)=(data[i]?).getD 0 ∧
    memory.readable (base+BitVec.ofNat 64 i)=true ∧
    memory.initialized (base+BitVec.ofNat 64 i)=true

theorem byte_address (base offset : Word) (i : Nat) :
    base+offset+BitVec.ofNat 64 i=base+BitVec.ofNat 64 (offset.toNat+i) := by
  simp [BitVec.ofNat_add,BitVec.ofNat_toNat,BitVec.add_assoc]

theorem copied_bytes (data : List Byte) (base offset : Word) (memory : Memory)
    (image : Image data base memory) (width : Nat)
    (fits : offset.toNat+width≤data.length) :
    copiedBytes data offset.toNat width=bytesAt memory (base+offset) width := by
  unfold copiedBytes bytesAt
  apply List.map_congr_left
  intro i inside
  have bound : i<width := List.mem_range.mp inside
  rw [byte_address]
  exact (image (offset.toNat+i) (by omega)).1.symm

theorem image_readable (data : List Byte) (base offset : Word) (memory : Memory)
    (image : Image data base memory) (width : Nat)
    (fits : offset.toNat+width≤data.length) :
    permitted memory.readable (base+offset) width=true := by
  apply List.all_eq_true.mpr
  intro i inside
  have bound : i<width := List.mem_range.mp inside
  rw [byte_address]
  exact (image (offset.toNat+i) (by omega)).2.1

theorem image_initialized (data : List Byte) (base offset : Word) (memory : Memory)
    (image : Image data base memory) (width : Nat)
    (fits : offset.toNat+width≤data.length) :
    initializedAt memory (base+offset) width=true := by
  apply List.all_eq_true.mpr
  intro i inside
  have bound : i<width := List.mem_range.mp inside
  rw [byte_address]
  exact (image (offset.toNat+i) (by omega)).2.2

def loadWidth (width : Nat) : Nat := if width=0 then 8 else width

/-- Finite C switch cases return copied bytes; the C default uses its ordinary
memory operation. Effects here are the architectural observation of that read. -/
def objectLoad (data : List Byte) (base offset : Word) (width : Nat)
    (memory : Memory) : Except Fault (Word × Event) :=
  if (offset.toNat,width) ∈ casesFor data then
    let copied := copiedBytes data offset.toNat width
    .ok (littleEndian 64 copied,.memory .read (base+offset) copied true)
  else readMemory memory (base+offset) (loadWidth width)

/-- Every finite case and its ordinary default implement the same canonical read. -/
theorem object_load_matches (data : List Byte) (base offset : Word) (width : Nat)
    (memory : Memory) (image : Image data base memory) :
    objectLoad data base offset width memory=readMemory memory (base+offset) (loadWidth width) := by
  unfold objectLoad
  split
  next selected =>
    have domain := (case_domain data offset.toNat width).mp selected
    have fits := domain.2
    have cases : width=1 ∨ width=2 ∨ width=4 ∨ width=8 := by simpa using domain.1
    have effective : loadWidth width=width := by simp only [loadWidth,if_neg (by omega : width≠0)]
    rw [effective]
    rw [readMemory,image_readable data base offset memory image width fits,if_pos rfl]
    unfold wordAt
    rw [←copied_bytes data base offset memory image width fits,
      image_initialized data base offset memory image width fits]
  next => rfl

/-- The production alias adjustment retains the original pointer arithmetic. -/
theorem alias_address (base alias displacement : Word) :
    base+(alias-base+displacement)=alias+displacement := by
  rw [←BitVec.add_assoc,BitVec.add_comm base (alias-base),BitVec.sub_add_cancel]

structure Object where
  base : Word
  data : List Byte

/-- __builtin_constant_p chooses an object representation. Each choice keeps its
own symbol identity and offset, including shifted aliases and default loads. -/
def dataLoad (memory : Memory) (alias displacement : Word) (width : Nat)
    (constantChoice : Object → Bool) : List Object → Except Fault (Word × Event)
  | [] => readMemory memory (alias+displacement) (loadWidth width)
  | object::rest =>
    if constantChoice object then
      objectLoad object.data object.base (alias-object.base+displacement) width memory
    else dataLoad memory alias displacement width constantChoice rest

/-- Universal over object count, bytes, base choices and aliases. Production
read widths are1/2/4/8 bytes; raw width0 retains the existing8-byte default.
The image relation is the link premise; C/compiler and physical map transport
connect this mathematical finite-case law to each implementation stage. -/
theorem data_load_matches (objects : List Object) (memory : Memory)
    (alias displacement : Word) (width : Nat) (constantChoice : Object → Bool)
    (images : ∀ object ∈ objects, Image object.data object.base memory) :
    dataLoad memory alias displacement width constantChoice objects=
      readMemory memory (alias+displacement) (loadWidth width) := by
  induction objects with
  | nil => rfl
  | cons object rest ih =>
    simp only [dataLoad]
    split
    · rw [object_load_matches _ _ _ _ _ (images object List.mem_cons_self),alias_address]
    · exact ih (fun object inside => images object (List.mem_cons_of_mem _ inside))

end ReadOnly

end KProgTV.NativeLinkLiteral

#print axioms KProgTV.NativeLinkLiteral.map_id_encoding
#print axioms KProgTV.NativeLinkLiteral.map_offset_encoding
#print axioms KProgTV.NativeLinkLiteral.map_target_sound
#print axioms KProgTV.NativeLinkLiteral.resolve_map_sound
#print axioms KProgTV.NativeLinkLiteral.first_matching_map
#print axioms KProgTV.NativeLinkLiteral.pointer_offset_rejected
#print axioms KProgTV.NativeLinkLiteral.literal_bytes
#print axioms KProgTV.NativeLinkLiteral.literal_word
#print axioms KProgTV.NativeLinkLiteral.literal_permissions
#print axioms KProgTV.NativeLinkLiteral.literal_outside
#print axioms KProgTV.NativeLinkLiteral.map_literal_matches

#print axioms KProgTV.NativeLinkLiteral.checked_literal_sound
#print axioms KProgTV.NativeLinkLiteral.literal_size_arithmetic

#print axioms KProgTV.NativeLinkLiteral.literal_initialized
#print axioms KProgTV.NativeLinkLiteral.literal_read
#print axioms KProgTV.NativeLinkLiteral.checked_literal_range_rejected
#print axioms KProgTV.NativeLinkLiteral.checked_literal_placeholder_rejected

#print axioms KProgTV.NativeLinkLiteral.ReadOnly.case_domain
#print axioms KProgTV.NativeLinkLiteral.ReadOnly.object_load_matches
#print axioms KProgTV.NativeLinkLiteral.ReadOnly.data_load_matches
