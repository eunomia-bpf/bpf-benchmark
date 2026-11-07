import KProgFormal.Reference.Memory
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

end KProgTV.PrivateSpills
#print axioms KProgTV.PrivateSpills.two_spills_preserve_guest
#print axioms KProgTV.PrivateSpills.guest_bytes_preserved

#print axioms KProgTV.PrivateSpills.guest_reads_preserved

#print axioms KProgTV.PrivateSpills.spill_word

#print axioms KProgTV.PrivateSpills.upper_spill_reload

#print axioms KProgTV.PrivateSpills.erased_event_private

#print axioms KProgTV.PrivateSpills.store_agrees
