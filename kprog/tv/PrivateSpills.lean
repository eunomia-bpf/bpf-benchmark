import KProgFormal.Reference.X86
import Std.Tactic.BVDecide

namespace KProgTV.PrivateSpills
open KProgFormal.Reference


@[simp] theorem store_readable (m : Memory) (address value : Word) (count : Nat) :
    (storeMemory m address value count).readable = m.readable := rfl

@[simp] theorem store_writable (m : Memory) (address value : Word) (count : Nat) :
    (storeMemory m address value count).writable = m.writable := rfl

/-- The actual two eight-byte compiler spill slots below BPF r10. -/
def privateByte (frame address : Word) : Prop :=
  (address - (frame - (16#64))).toNat < 16

def AgreesOutside (frame : Word) (first second : Memory) : Prop :=
  first.readable = second.readable ∧ first.writable = second.writable ∧
    ∀ address, ¬ privateByte frame address →
      first.value address = second.value address ∧
      first.initialized address = second.initialized address

/-- Includes architectural wraparound: the upper slot remains inside the
sixteen-byte private frame even when the frame straddles address zero. -/
theorem upper_slot_private (frame address : Word)
    (inside : (address - (frame - (8#64))).toNat < 8) : privateByte frame address := by
  change address - (frame - (8#64)) < (8#64) at inside
  change address - (frame - (16#64)) < (16#64)
  unfold Word at *
  bv_decide

theorem two_spills_preserve_guest (m : Memory) (frame pointer limit : Word) :
    AgreesOutside frame m
      (storeMemory (storeMemory m (frame - (8#64)) pointer 8) (frame - (16#64)) limit 8) := by
  refine ⟨rfl, rfl, ?_⟩
  intro address outside
  have upper : ¬ (address - (frame - (8#64))).toNat < 8 :=
    fun inside => outside (upper_slot_private frame address inside)
  have lower : ¬ (address - (frame - (16#64))).toNat < 8 := by
    simp only [privateByte] at outside
    omega
  simp only [storeMemory, upper, lower, ite_false]
  trivial

theorem guest_bytes_preserved (frame address : Word) (count : Nat) (first second : Memory)
    (same : AgreesOutside frame first second)
    (guest : ∀ i < count, ¬ privateByte frame (address + BitVec.ofNat 64 i)) :
    bytesAt first address count = bytesAt second address count := by
  apply List.map_congr_left
  intro i inside
  exact (same.2.2 _ (guest i (List.mem_range.mp inside))).1


theorem guest_reads_preserved (frame address : Word) (count : Nat) (first second : Memory)
    (same : AgreesOutside frame first second)
    (guest : ∀ i < count, ¬ privateByte frame (address + BitVec.ofNat 64 i)) :
    readMemory first address count = readMemory second address count := by
  have bytes := guest_bytes_preserved frame address count first second same guest
  have init : initializedAt first address count = initializedAt second address count := by
    apply Bool.eq_iff_iff.mpr
    simp only [initializedAt, permitted, List.all_eq_true]
    constructor
    · intro h i inside
      rw [← (same.2.2 _ (guest i (List.mem_range.mp inside))).2]
      exact h i inside
    · intro h i inside
      rw [(same.2.2 _ (guest i (List.mem_range.mp inside))).2]
      exact h i inside
  simp only [readMemory, wordAt, same.1, bytes, init]


theorem plus_index_sub (address offset : Word) : address + offset - address = offset := by
  rw [BitVec.add_comm address offset]
  exact BitVec.add_sub_cancel offset address

/-- Each compiler spill stores all eight bits of every byte; reloading must
recover the actual source word, rather than a value supplied by a premise. -/
theorem spill_bytes (m : Memory) (address value : Word) :
    bytesAt (storeMemory m address value 8) address 8 = valueBytes value 8 := by
  simp only [bytesAt, storeMemory, valueBytes, List.range_succ, List.range_zero,
    List.map_append, List.map_cons, List.map_nil, List.map_singleton,
    List.append_assoc, List.nil_append, List.cons_append, List.append_nil, plus_index_sub]
  simp

theorem spill_word (m : Memory) (address value : Word) :
    wordAt (storeMemory m address value 8) address 8 = value := by
  rw [wordAt, spill_bytes]
  simp only [valueBytes, List.range_succ, List.range_zero, List.map_append, List.map_cons,
    List.map_nil, List.map_singleton, List.append_assoc, List.nil_append,
    List.cons_append, littleEndian, List.append_nil]
  unfold Word at *
  bv_decide


theorem spill_initialized (m : Memory) (address value : Word) :
    initializedAt (storeMemory m address value 8) address 8 = true := by
  simp only [initializedAt, permitted, storeMemory, List.range_succ, List.range_zero,
    List.all_append, List.all_cons, List.all_nil, plus_index_sub]
  simp

theorem spill_read (m : Memory) (address value : Word)
    (readable : permitted m.readable address 8 = true) :
    readMemory (storeMemory m address value 8) address 8 =
      .ok (value, .memory .read address (valueBytes value 8) true) := by
  have permission : permitted (storeMemory m address value 8).readable address 8 = true := readable
  simp only [readMemory, permission, ite_true, spill_word, spill_bytes, spill_initialized]

theorem upper_spill_preserves_guest (m : Memory) (frame value : Word) :
    AgreesOutside frame m (storeMemory m (frame - (8#64)) value 8) := by
  refine ⟨rfl, rfl, ?_⟩
  intro address outside
  have upper : ¬ (address - (frame - (8#64))).toNat < 8 :=
    fun inside => outside (upper_slot_private frame address inside)
  simp only [storeMemory, upper, ite_false]
  trivial

theorem above_frame_guest (frame offset : Word) (small : offset < (8#64)) :
    ¬ privateByte frame (frame + offset) := by
  change ¬ frame + offset - (frame - (16#64)) < (16#64)
  unfold Word at *
  bv_decide

theorem sub8_twice (frame : Word) : (frame - (8#64)) - (8#64) = frame - (16#64) := by
  unfold Word at *
  bv_decide

theorem upper_spill_reload (m : Memory) (frame pointer limit : Word)
    (readable : permitted m.readable (frame - (8#64)) 8 = true) :
    readMemory (storeMemory (storeMemory m (frame - (8#64)) pointer 8)
        (frame - (16#64)) limit 8) (frame - (8#64)) 8 =
      .ok (pointer, .memory .read (frame - (8#64)) (valueBytes pointer 8) true) := by
  have same := upper_spill_preserves_guest
    (storeMemory m (frame - (8#64)) pointer 8) (frame - (8#64)) limit
  rw [sub8_twice] at same
  have equal := guest_reads_preserved (frame - (8#64)) (frame - (8#64)) 8 _ _ same
    (fun i small => above_frame_guest _ _ (by
      simp only [BitVec.lt_def, BitVec.toNat_ofNat]
      omega))
  rw [← equal]
  exact spill_read m (frame - (8#64)) pointer readable


def projectEvent (frame : Word) : Event → Option Event
  | event@(.memory .read address bytes _) =>
      if (address = frame - (8#64) ∨ address = frame - (16#64)) ∧ bytes.length = 8 then none else some event
  | event@(.memory .write address bytes _) =>
      if (address = frame - (8#64) ∨ address = frame - (16#64)) ∧ bytes.length = 8 then none else some event
  | event => some event

theorem slot_bytes_private (frame address : Word)
    (slot : address = frame - (8#64) ∨ address = frame - (16#64)) (i : Nat) (small : i < 8) :
    privateByte frame (address + BitVec.ofNat 64 i) := by
  have bound : i < 2^64 := by omega
  rcases slot with upper | lower
  · rw [upper]
    apply upper_slot_private
    simpa only [plus_index_sub, BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound] using small
  · rw [lower]
    simp only [privateByte, plus_index_sub, BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]
    omega

/-- Only complete accesses to the actual two private slots can be erased.
Atomic, helper, exclusive/order and fault effects are always retained. -/
theorem erased_event_private (frame : Word) (event : Event)
    (gone : projectEvent frame event = none) :
    ∃ kind address bytes initialized,
      event = .memory kind address bytes initialized ∧ bytes.length = 8 ∧
      ∀ i < 8, privateByte frame (address + BitVec.ofNat 64 i) := by
  cases event with
  | memory kind address bytes initialized =>
      cases kind with
      | read =>
          simp only [projectEvent] at gone
          split at gone
          · rename_i slot
            exact ⟨.read, address, bytes, initialized, rfl, slot.2,
              fun i small => slot_bytes_private frame address slot.1 i small⟩
          · simp at gone
      | write =>
          simp only [projectEvent] at gone
          split at gone
          · rename_i slot
            exact ⟨.write, address, bytes, initialized, rfl, slot.2,
              fun i small => slot_bytes_private frame address slot.1 i small⟩
          · simp at gone
      | atomic => simp [projectEvent] at gone
  | helper => simp [projectEvent] at gone
  | fault => simp [projectEvent] at gone
  | exclusive => simp [projectEvent] at gone

theorem guest_memory_event_retained (frame address : Word) (kind : AccessKind)
    (bytes : List Byte) (initialized : Bool) (guest : ¬ privateByte frame address) :
    projectEvent frame (.memory kind address bytes initialized) =
      some (.memory kind address bytes initialized) := by
  have outside : ¬ (address = frame - (8#64) ∨ address = frame - (16#64)) := by
    intro slot
    exact guest (by simpa using slot_bytes_private frame address slot 0 (by decide))
  cases kind <;> simp [projectEvent, outside]


theorem read_event_retained (m : Memory) (frame address value : Word) (count : Nat) (event : Event)
    (read : readMemory m address count = .ok (value, event))
    (guest : ¬ privateByte frame address) : projectEvent frame event = some event := by
  by_cases permission : permitted m.readable address count = true
  · simp only [readMemory, permission, ite_true, Except.ok.injEq, Prod.mk.injEq] at read
    rw [← read.2]
    exact guest_memory_event_retained frame address .read _ _ guest
  · simp [readMemory, permission] at read

/-- Applying the same actual write to related memories preserves every guest
byte and initialization bit outside the frame, including wrapping accesses. -/
theorem store_agrees {frame : Word} {first second : Memory}
    (same : AgreesOutside frame first second) (base value : Word) (count : Nat) :
    AgreesOutside frame (storeMemory first base value count) (storeMemory second base value count) := by
  refine ⟨same.1, same.2.1, ?_⟩
  intro address outside
  by_cases inside : (address - base).toNat < count
  · simp only [storeMemory, inside, ite_true]
    trivial
  · simpa only [storeMemory, inside, ite_false] using same.2.2 address outside


/-- Exact reads survive a byte-disjoint actual store, including wrapping
addresses and initialization bits. Uses the single reference memory model. -/
theorem read_disjoint_store (m : Memory) (destination value address : Word)
    (written count : Nat)
    (apart : ∀ i < count, ¬ ((address + BitVec.ofNat 64 i) - destination).toNat < written) :
    readMemory (storeMemory m destination value written) address count =
      readMemory m address count := by
  have bytes : bytesAt (storeMemory m destination value written) address count = bytesAt m address count := by
    apply List.map_congr_left
    intro i inside
    simp only [storeMemory, apart i (List.mem_range.mp inside), ite_false]
  have init : initializedAt (storeMemory m destination value written) address count = initializedAt m address count := by
    apply Bool.eq_iff_iff.mpr
    simp only [initializedAt, permitted, List.all_eq_true]
    constructor
    · intro h i inside
      simpa only [storeMemory, apart i (List.mem_range.mp inside), ite_false] using h i inside
    · intro h i inside
      simpa only [storeMemory, apart i (List.mem_range.mp inside), ite_false] using h i inside
  simp only [readMemory, wordAt, store_readable, bytes, init]

end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.two_spills_preserve_guest
#print axioms KProgTV.PrivateSpills.guest_bytes_preserved

#print axioms KProgTV.PrivateSpills.guest_reads_preserved

#print axioms KProgTV.PrivateSpills.spill_word

#print axioms KProgTV.PrivateSpills.upper_spill_reload

#print axioms KProgTV.PrivateSpills.erased_event_private

#print axioms KProgTV.PrivateSpills.store_agrees

#print axioms KProgTV.PrivateSpills.read_disjoint_store

namespace KProgTV.PrivateSpills
open KProgFormal.Reference

/-- Every finite history of disjoint real writes preserves the exact slot
read, including initialization, permissions and wrapping addresses. -/
theorem read_disjoint_stores (memory : Memory) (address : Word) (count : Nat)
    (writes : List (Word × Word × Nat))
    (apart : ∀ write ∈ writes, ∀ index < count,
      ¬((address + BitVec.ofNat 64 index) - write.1).toNat < write.2.2) :
    readMemory (writes.foldl (fun current write =>
      storeMemory current write.1 write.2.1 write.2.2) memory) address count =
      readMemory memory address count := by
  induction writes generalizing memory with
  | nil => rfl
  | cons write rest ih =>
      simp only [List.foldl_cons]
      rw [ih (storeMemory memory write.1 write.2.1 write.2.2)
        (fun item inside => apart item (List.mem_cons_of_mem _ inside))]
      exact read_disjoint_store memory write.1 write.2.1 address write.2.2 count
        (apart write (by simp))
end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.read_disjoint_stores

namespace KProgTV.PrivateSpills
open KProgFormal.Reference

/-- A helper may change all memory outside the selected caller-owned bytes.
This is a proof relation, not a runtime predicate or a claim that the helper
is globally read-only. Permissions and initialization belong to the frame. -/
def FrameOn (owned : Word → Bool) (before after : Memory) : Prop :=
  ∀ address, owned address = true →
    after.value address = before.value address ∧
    after.readable address = before.readable address ∧
    after.writable address = before.writable address ∧
    after.initialized address = before.initialized address

theorem frame_on_refl (owned : Word → Bool) (memory : Memory) :
    FrameOn owned memory memory := by
  intro address inside
  exact ⟨rfl,rfl,rfl,rfl⟩

theorem frame_on_trans (owned : Word → Bool) (first middle last : Memory)
    (left : FrameOn owned first middle) (right : FrameOn owned middle last) :
    FrameOn owned first last := by
  intro address inside
  obtain ⟨v,r,w,i⟩ := left address inside
  obtain ⟨v',r',w',i'⟩ := right address inside
  exact ⟨v'.trans v,r'.trans r,w'.trans w,i'.trans i⟩

/-- Exact successful reads, initialization observations and read faults all
survive a local helper frame; addresses retain architectural wraparound. -/
theorem frame_on_read (owned : Word → Bool) (before after : Memory)
    (frame : FrameOn owned before after) (address : Word) (count : Nat)
    (inside : ∀ index < count, owned (address + BitVec.ofNat 64 index) = true) :
    readMemory after address count = readMemory before address count := by
  have bytes : bytesAt after address count = bytesAt before address count := by
    apply List.map_congr_left
    intro index member
    exact (frame _ (inside index (List.mem_range.mp member))).1
  have readable : permitted after.readable address count = permitted before.readable address count := by
    apply Bool.eq_iff_iff.mpr
    simp only [permitted,List.all_eq_true]
    constructor
    · intro allowed index member
      rw [←(frame _ (inside index (List.mem_range.mp member))).2.1]
      exact allowed index member
    · intro allowed index member
      rw [(frame _ (inside index (List.mem_range.mp member))).2.1]
      exact allowed index member
  have initialized : initializedAt after address count = initializedAt before address count := by
    apply Bool.eq_iff_iff.mpr
    simp only [initializedAt,permitted,List.all_eq_true]
    constructor
    · intro allowed index member
      rw [←(frame _ (inside index (List.mem_range.mp member))).2.2.2]
      exact allowed index member
    · intro allowed index member
      rw [(frame _ (inside index (List.mem_range.mp member))).2.2.2]
      exact allowed index member
  simp only [readMemory,wordAt,bytes,readable,initialized]

/-- An actual disjoint write can mutate helper/map memory while retaining all
caller-owned bytes and permissions; no such write is erased from the trace. -/
theorem frame_on_store (owned : Word → Bool) (memory : Memory)
    (destination value : Word) (count : Nat)
    (apart : ∀ address, owned address = true → ¬(address-destination).toNat < count) :
    FrameOn owned memory (storeMemory memory destination value count) := by
  intro address inside
  simp only [storeMemory,apart address inside,ite_false]
  exact ⟨True.intro,True.intro,True.intro,True.intro⟩

theorem frame_on_stores (owned : Word → Bool) (memory : Memory)
    (writes : List (Word × Word × Nat))
    (apart : ∀ write ∈ writes, ∀ address, owned address = true →
      ¬(address-write.1).toNat < write.2.2) :
    FrameOn owned memory (writes.foldl (fun current write =>
      storeMemory current write.1 write.2.1 write.2.2) memory) := by
  induction writes generalizing memory with
  | nil => exact frame_on_refl owned memory
  | cons write rest ih =>
      simp only [List.foldl_cons]
      exact frame_on_trans owned memory _ _
        (frame_on_store owned memory write.1 write.2.1 write.2.2
          (apart write (by simp)))
        (ih _ (fun item member => apart item (List.mem_cons_of_mem _ member)))
end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.frame_on_refl
#print axioms KProgTV.PrivateSpills.frame_on_trans
#print axioms KProgTV.PrivateSpills.frame_on_read
#print axioms KProgTV.PrivateSpills.frame_on_store
#print axioms KProgTV.PrivateSpills.frame_on_stores

namespace KProgTV.PrivateSpills
open KProgFormal.Reference

/-- Actual native near CALL writes its complete fall-through at RSP-8.
The source may itself read memory: those reads precede the stack write. -/
theorem x86_call_stack_write (state : X86.State) (source : X86.ScalarSource)
    (target next : Word) (reads : List Event)
    (sampled : X86.scalarRead state .w64 source = .ok (target,reads))
    (writable : permitted state.memory.writable (state.gpr 4-8) 8 = true)
    (canonical : X86.canonicalTarget state.addressWidth target = true) :
    X86.step (.call source next) state =
      ⟨{ state with
          gpr := (fun r => if r=4 then state.gpr 4-8 else state.gpr r),
          memory := storeMemory state.memory (state.gpr 4-8) next 8, pc := target },
        reads ++ [.memory .write (state.gpr 4-8) (valueBytes next 8) true],none⟩ := by
  simp only [BitVec.ofNat_eq_ofNat] at *
  simp_all [X86.step,X86.callStep,X86.pushTransfer,X86.StackWidth.bytes,writeMemory,BitVec.ofNat_eq_ofNat]

/-- A CALL can preserve allocated caller bytes without preserving its own
return slot. Disjointness is stated at wrapping architectural addresses. -/
theorem x86_call_owned_frame (state : X86.State) (source : X86.ScalarSource)
    (target next : Word) (reads : List Event)
    (sampled : X86.scalarRead state .w64 source = .ok (target,reads))
    (writable : permitted state.memory.writable (state.gpr 4-8) 8 = true)
    (canonical : X86.canonicalTarget state.addressWidth target = true)
    (owned : Word → Bool)
    (apart : ∀ address, owned address = true → ¬(address-(state.gpr 4-8)).toNat < 8) :
    FrameOn owned state.memory (X86.step (.call source next) state).state.memory := by
  rw [x86_call_stack_write state source target next reads sampled writable canonical]
  exact frame_on_store owned state.memory (state.gpr 4-8) next 8 apart

/-- An arbitrary returning helper body keeps the real saved return address
when its footprint preserves every byte of that separate slot. No premise
requires memory outside the slot to be unchanged. -/
theorem x86_helper_return_slot (state body : X86.State)
    (source : X86.ScalarSource) (target next : Word) (reads : List Event)
    (sampled : X86.scalarRead state .w64 source = .ok (target,reads))
    (writable : permitted state.memory.writable (state.gpr 4-8) 8 = true)
    (canonical : X86.canonicalTarget state.addressWidth target = true)
    (readable : permitted state.memory.readable (state.gpr 4-8) 8 = true)
    (slot : Word → Bool)
    (inside : ∀ index < 8, slot (state.gpr 4-8+BitVec.ofNat 64 index) = true)
    (bodyFrame : FrameOn slot (X86.step (.call source next) state).state.memory body.memory) :
    readMemory body.memory (state.gpr 4-8) 8 =
      .ok (next,.memory .read (state.gpr 4-8) (valueBytes next 8) true) := by
  have preserved := frame_on_read slot _ body.memory bodyFrame (state.gpr 4-8) 8 inside
  rw [x86_call_stack_write state source target next reads sampled writable canonical] at preserved
  exact preserved.trans (spill_read state.memory (state.gpr 4-8) next readable)

/-- Actual RET restores the original RSP plus its unsigned imm16 release
and returns to the CALL fall-through. All helper results, memory and other
registers remain exactly those of the real returning body. -/
theorem x86_helper_return_step (state body : X86.State)
    (source : X86.ScalarSource) (target next ignored : Word) (reads : List Event)
    (sampled : X86.scalarRead state .w64 source = .ok (target,reads))
    (writable : permitted state.memory.writable (state.gpr 4-8) 8 = true)
    (canonical : X86.canonicalTarget state.addressWidth target = true)
    (readable : permitted state.memory.readable (state.gpr 4-8) 8 = true)
    (slot : Word → Bool)
    (inside : ∀ index < 8, slot (state.gpr 4-8+BitVec.ofNat 64 index) = true)
    (bodyFrame : FrameOn slot (X86.step (.call source next) state).state.memory body.memory)
    (stack : body.gpr 4 = state.gpr 4-8)
    (returnCanonical : X86.canonicalTarget body.addressWidth next = true)
    (release : BitVec 16) :
    X86.step (.returnNear release ignored) body =
      ⟨{ body with
          gpr := (fun r => if r=4 then state.gpr 4+release.setWidth 64 else body.gpr r),
          pc := next },[.memory .read (state.gpr 4-8) (valueBytes next 8) true],none⟩ := by
  have saved := x86_helper_return_slot state body source target next reads sampled writable
    canonical readable slot inside bodyFrame
  have restored : state.gpr 4-8+8 = state.gpr 4 := BitVec.sub_add_cancel _ _
  simp only [BitVec.ofNat_eq_ofNat] at *
  simp_all [X86.step,X86.returnStep,BitVec.ofNat_eq_ofNat]

end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.x86_call_stack_write
#print axioms KProgTV.PrivateSpills.x86_call_owned_frame
#print axioms KProgTV.PrivateSpills.x86_helper_return_slot
#print axioms KProgTV.PrivateSpills.x86_helper_return_step

namespace KProgTV.PrivateSpills
open KProgFormal.Reference

/-- Compose actual CALL stack mutation and the selected helper's local
footprint. Caller allocation and return-slot preservation are separate:
the caller region must exclude the slot that CALL actually overwrites. -/
theorem x86_helper_owned_frame (state body : X86.State) (source : X86.ScalarSource)
    (target next : Word) (reads : List Event)
    (sampled : X86.scalarRead state .w64 source = .ok (target,reads))
    (writable : permitted state.memory.writable (state.gpr 4-8) 8 = true)
    (canonical : X86.canonicalTarget state.addressWidth target = true)
    (owned : Word → Bool)
    (apart : ∀ address, owned address = true → ¬(address-(state.gpr 4-8)).toNat < 8)
    (bodyFrame : FrameOn owned (X86.step (.call source next) state).state.memory body.memory) :
    FrameOn owned state.memory body.memory :=
  frame_on_trans owned state.memory _ body.memory
    (x86_call_owned_frame state source target next reads sampled writable canonical owned apart)
    bodyFrame

end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.x86_helper_owned_frame
