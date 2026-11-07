import KProgFormal.Refinement.Arm64AddressedMemory
import KProgFormal.Generated.GeneratedArm64DispatchSingleton
import KProgFormal.Generated.GeneratedArm64DqMem
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64VectorMemory
open Reference

/-- The actual D-load lane transfer plus the generated upper-half action. -/
def dLoad (old : BitVec 128) (low : Word) : BitVec 128 :=
  let high : Word := if GeneratedArm64DqMem.clearHigh .loadD0 then 0 else (old >>> 64).setWidth 64
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem d_load_refines (old : BitVec 128) (m : Memory) (address : Word) :
    dLoad old (wordAt m address 8) = littleEndian 128 (bytesAt m address 8) := by
  simp [dLoad, GeneratedArm64DqMem.clearHigh, if_true, wordAt,
    bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

/-- Both transferred Q lanes form the one 128-bit architectural value. -/
def qLoad (low high : Word) : BitVec 128 :=
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem q_load_refines (m : Memory) (address : Word) :
    qLoad (wordAt m address 8) (wordAt m (address + 8) 8) =
      littleEndian 128 (bytesAt m address 16) := by
  simp [qLoad, wordAt, bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

/-- Each low D lane store emits exactly eight source bytes. Truncating the
vector to the generated memory word does not change any of those bytes. -/
theorem d_store_bytes (value : BitVec 128) :
    (List.range 8).map (fun n => (value >>> (8 * n)).setWidth 8) =
      valueBytes (value.setWidth 64) 8 := by
  unfold valueBytes
  apply List.map_congr_left
  intro n member
  have nBound : n < 8 := List.mem_range.mp member
  apply BitVec.eq_of_getLsbD_eq
  intro bit bitBound
  have lowBound : 8 * n + bit < 64 := by omega
  simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
  simp [bitBound, lowBound]

open Reference.AArch64 (Register)

/-- The no-writeback D0 instruction corresponding to the two production
singletons. Other vector banks and Q-width effects are not substituted here. -/
def dInstruction (load : Bool) (base : Register) (offset : Word) :
    Reference.AArch64.Instruction :=
  .vectorMemory ⟨.double, load, 0, base, .immediate offset, .none⟩

/-- Compose the actual DQ direction/high-clear selectors with the generated
native-eight-byte memory primitives. Permission/fault branches are the checked
memory model, not new runtime guards inserted into the C macro. -/
def dStep (load : Bool) (base : Register) (offset : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let op := if load then GeneratedArm64DqMem.Op.loadD0 else .storeD0
  let address := Arm64Memory.baseValue s base +
    GeneratedArm64MemOffset.value false false offset 0
  if GeneratedArm64DqMem.access op = .load then
    match Arm64Memory.read .double s.memory address with
    | .error fault => ⟨s, [.fault fault], some fault⟩
    | .ok (value, event) => ⟨{ s with vector0 := dLoad s.vector0 value, pc := s.pc + 4 }, [event], none⟩
  else
    match Arm64Memory.write .double s.memory address (s.vector0.setWidth 64) with
    | .error fault => ⟨s, [.fault fault], some fault⟩
    | .ok (memory, event) => ⟨{ s with memory := memory, pc := s.pc + 4 }, [event], none⟩

theorem d_step_refines (load : Bool) (base : Register) (offset : Word)
    (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dStep load base offset s = Reference.AArch64.step (dInstruction load base offset) s := by
  cases load <;>
    simp only [dStep, dInstruction, Reference.AArch64.step,
      Reference.AArch64.vectorMemoryStep, alignment, Reference.AArch64.memoryOffset,
      Arm64Memory.base_refines, GeneratedArm64MemOffset.value, GeneratedArm64DqMem.access,
      Arm64Memory.read_refines, Arm64Memory.write_refines,
      Reference.AArch64.VectorMemoryWidth.bytes, Reference.AArch64.VectorMemoryWidth.scale,
      Reference.AArch64.MemoryWidth.bytes, readMemory, writeMemory,
      Bool.false_eq_true, reduceCtorEq, ↓reduceIte, Nat.reducePow,
      Reference.AArch64.readVector_zero, Reference.AArch64.writeVector_zero]
  · by_cases permittedWrite : permitted s.memory.writable (Reference.AArch64.memoryBase s base + offset) 8 = true <;>
      simp [permittedWrite, d_store_bytes]
  · by_cases permittedRead : permitted s.memory.readable (Reference.AArch64.memoryBase s base + offset) 8 = true <;>
      simp [permittedRead, d_load_refines]

/-- Generated index modifiers feed the same D-width address, including W
zero/sign extension, the native X index, scaling by eight and ZR indexes. -/
def dOffset (s : Reference.AArch64.State) : Reference.AArch64.MemoryOffset → Word
  | .immediate value => value
  | .register index kind scaled =>
      GeneratedArm64Mod.value (Arm64AddressedMemory.modifier kind)
        (Arm64Register.readReg s index) (BitVec.ofNat 64 (if scaled then 3 else 0)) .w64

theorem d_offset_refines (s : Reference.AArch64.State) (offset : Reference.AArch64.MemoryOffset) :
    dOffset s offset = Reference.AArch64.memoryOffset s 3 offset := by
  cases offset with
  | immediate value => rfl
  | register index kind scaled =>
      simpa only [dOffset, Arm64Register.read_refines, Reference.AArch64.memoryOffset,
        Arm64AddressedMemory.indexValue] using
        Arm64AddressedMemory.index_refines kind (Reference.AArch64.readReg s index)
          ⟨if scaled then 3 else 0, by split <;> decide⟩

def dIndexedStep (load : Bool) (base : Register) (offset : Reference.AArch64.MemoryOffset)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  dStep load base (dOffset s offset) s

theorem d_indexed_refines (load : Bool) (base : Register) (offset : Reference.AArch64.MemoryOffset)
    (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dIndexedStep load base offset s = Reference.AArch64.step
      (.vectorMemory ⟨.double, load, 0, base, offset, .none⟩) s := by
  rw [dIndexedStep, d_step_refines load base (dOffset s offset) s alignment]
  simp only [dInstruction, Reference.AArch64.step, Reference.AArch64.vectorMemoryStep,
    alignment, Reference.AArch64.VectorMemoryWidth.scale, Reference.AArch64.memoryOffset,
    d_offset_refines]

/-- This two-arm dispatcher uses the production singleton predicates. Its
result is absent for every other opcode, retaining the rest of the chain. -/
def dispatchD (op : GeneratedArm64DispatchSingleton.SingletonOp) (base : Register)
    (offset : Word) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if GeneratedArm64DispatchSingleton.loadD0Handled op then some (dStep true base offset s)
  else if GeneratedArm64DispatchSingleton.storeD0Handled op then some (dStep false base offset s)
  else none

theorem dispatch_d_load_refines (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dispatchD .loadD0 base offset s = some (Reference.AArch64.step (dInstruction true base offset) s) := by
  change some (dStep true base offset s) = _
  rw [d_step_refines true base offset s alignment]

theorem dispatch_d_store_refines (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dispatchD .storeD0 base offset s = some (Reference.AArch64.step (dInstruction false base offset) s) := by
  change some (dStep false base offset s) = _
  rw [d_step_refines false base offset s alignment]

theorem dispatch_d_other (op : GeneratedArm64DispatchSingleton.SingletonOp)
    (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (notLoad : op ≠ .loadD0) (notStore : op ≠ .storeD0) :
    dispatchD op base offset s = none := by
  simp [dispatchD, GeneratedArm64DispatchSingleton.loadD0Handled,
    GeneratedArm64DispatchSingleton.storeD0Handled, notLoad, notStore]

open Reference.AArch64

/-- Numeric-state slice of MEM_PREPOST_STEP: retain the zero-delta fast
path and the separate SP/GPR writes. Values are materialized native words;
address/provenance and successful-transfer witnesses remain external. -/
def bumpBase (s : State) (base : Register) (delta : Word) : State :=
  if delta = 0 then s
  else if base.val = 31 then { s with sp := s.sp + delta }
  else Arm64Register.writeReg s base (Arm64Register.readReg s base + delta) .w64

theorem write_base_read (s : State) (base : Register) :
    writeMemoryBase s base (memoryBase s base) = s := by
  by_cases h : base.val = 31
  · simp [writeMemoryBase, memoryBase, h]
  · simp only [writeMemoryBase, memoryBase, h, ↓reduceIte, writeReg]
    congr 1
    funext r
    split
    · rename_i equal
      simp only [readReg, show base.val < 31 by omega, ↓reduceDIte]
      congr 1
      apply Fin.ext
      exact equal.symm
    · rfl

theorem bump_refines (s : State) (base : Register) (delta : Word) :
    bumpBase s base delta = writeMemoryBase s base (memoryBase s base + delta) := by
  by_cases zero : delta = 0
  · simp [bumpBase, zero, write_base_read]
  · by_cases stack : base.val = 31
    · simp only [bumpBase, if_neg zero, if_pos stack, writeMemoryBase, memoryBase]
      simp [stack, show ¬base.val < 31 by omega]
    · simp only [bumpBase, if_neg zero, if_neg stack, writeMemoryBase,
        Arm64Register.read_refines, Arm64Register.write_refines]
      simp [stack, memoryBase, readReg, show base.val < 31 by omega, narrow, Width.bits]
/-- The generated pre/post deltas together update the incoming native base
once. This is base-update algebra; the intervening vector memory transition
and its fault behavior still require a separate composition theorem. -/
theorem writeback_base_refines (mode : Writeback) (s : State) (base : Register) (delta : Word) :
    bumpBase (bumpBase s base
      (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta)) base
      (GeneratedArm64MemPrepost.postDelta (Arm64AddressedMemory.flags mode) delta) =
    writeMemoryBase s base (memoryBase s base + (if mode = .none then 0 else delta)) := by
  cases mode <;>
    simp [Arm64AddressedMemory.flags, GeneratedArm64MemPrepost.preDelta,
      GeneratedArm64MemPrepost.postDelta, GeneratedArm64MemPrepost.preWriteback,
      GeneratedArm64MemPrepost.postWriteback, GeneratedArm64MemPrepost.flags,
      bump_refines, write_base_read]

/-- Successful native-eight-byte D0 transfer. No invented C permission
branch appears here: admissibility supplies the accessible-memory witness.
Values are the materialized numeric projection; tag/address transport remains
an Entry/O4 obligation. The one event records the native-width read or write. -/
def dSuccess (load : Bool) (address : Word) (s : State) : Transition State :=
  if load then
    ⟨{ s with vector0 := dLoad s.vector0 (GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth .double) (wordAt s.memory address 8)), pc := s.pc + 4 },
     [.memory .read address (bytesAt s.memory address 8) (initializedAt s.memory address 8)], none⟩
  else
    ⟨{ s with memory := Arm64Memory.store .double s.memory address (s.vector0.setWidth 64), pc := s.pc + 4 }, [.memory .write address (valueBytes (s.vector0.setWidth 64) 8) true], none⟩

theorem base_bump (s : State) (base : Register) (delta : Word) :
    memoryBase (bumpBase s base delta) base = memoryBase s base + delta := by
  rw [bump_refines]
  by_cases stack : base.val = 31
  · simp [writeMemoryBase, memoryBase, stack, show ¬base.val < 31 by omega]
  · simp [writeMemoryBase, memoryBase, writeReg, stack, show base.val < 31 by omega]

theorem base_success (load : Bool) (address : Word) (s : State) (base : Register) :
    memoryBase (dSuccess load address s).state base = memoryBase s base := by
  cases load <;> rfl

/-- Vector data and memory updates do not overwrite the integer base cell;
therefore the pre-access base update commutes with a successful D0 transfer. -/
theorem bump_success (load : Bool) (address : Word) (s : State) (base : Register) (delta : Word) :
    dSuccess load address (bumpBase s base delta) =
      { dSuccess load address s with state := bumpBase (dSuccess load address s).state base delta } := by
  simp only [bump_refines, base_success]
  cases load <;> by_cases stack : base.val = 31 <;>
    simp only [dSuccess, writeMemoryBase, stack, writeReg,
      Bool.false_eq_true, ↓reduceIte]

/-- Numeric C-body order: generated pre-update, suppressed/immediate address,
transfer, generated post-update. It never fabricates a runtime fault check. -/
def dWritebackCore (load : Bool) (mode : Writeback) (base : Register) (delta : Word)
    (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s base (GeneratedArm64MemPrepost.preDelta flags delta)
  let offset := GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset flags) false delta 0
  let transferred := dSuccess load (Arm64Memory.baseValue before base + offset) before
  { transferred with state := bumpBase transferred.state base (GeneratedArm64MemPrepost.postDelta flags delta) }

theorem d_writeback_core_eq (load : Bool) (mode : Writeback) (base : Register)
    (delta : Word) (s : State) :
    dWritebackCore load mode base delta s =
      let address := memoryBase s base + (if mode = .post then 0 else delta)
      let transferred := dSuccess load address s
      { transferred with state := if mode = .none then transferred.state else
          writeMemoryBase transferred.state base (memoryBase s base + delta) } := by
  simp only [dWritebackCore, Arm64Memory.base_refines, base_bump, BitVec.add_assoc,
    Arm64AddressedMemory.access_offset_refines, bump_success]
  rw [writeback_base_refines]
  cases mode with
  | none => simp [Reference.Word, write_base_read]
  | pre => simp [Reference.Word, base_success]
  | post => simp [Reference.Word, base_success]

/-- The original SP is checked before pre-indexing. The address may be
unaligned: ordinary D loads/stores require no extra natural alignment. This
whole-state theorem covers successful admitted memory accesses; the canonical
faults and the C body's pre-update-on-fault are not silently identified. -/
theorem d_writeback_refines (load : Bool) (mode : Writeback) (base : Register)
    (delta : Word) (s : State)
    (alignment : spAlignmentFault s base = none)
    (accessible : permitted (if load then s.memory.readable else s.memory.writable)
      (memoryBase s base + (if mode = .post then 0 else delta)) 8 = true) :
    dWritebackCore load mode base delta s =
      step (.vectorMemory ⟨.double, load, 0, base, .immediate delta, mode⟩) s := by
  rw [d_writeback_core_eq]
  cases mode <;> cases load <;> by_cases stack : base.val = 31 <;>
    simp_all [dSuccess, step, vectorMemoryStep, memoryOffset,
      VectorMemoryWidth.bytes, VectorMemoryWidth.scale,
      Arm64Memory.load_value, Arm64Memory.store_refines, MemoryWidth.bytes,
      d_load_refines, d_store_bytes, writeMemoryBase, writeReg, Reference.Word]

/-- The two production singleton predicates now select the actual successful
pre/access/post core. Other operations retain their own dispatcher arms. -/
def dispatchDSuccess (op : GeneratedArm64DispatchSingleton.SingletonOp) (mode : Writeback)
    (base : Register) (delta : Word) (s : State) : Option (Transition State) :=
  if GeneratedArm64DispatchSingleton.loadD0Handled op then
    some (dWritebackCore true mode base delta s)
  else if GeneratedArm64DispatchSingleton.storeD0Handled op then
    some (dWritebackCore false mode base delta s)
  else none

theorem dispatch_d_success_refines (load : Bool) (mode : Writeback) (base : Register)
    (delta : Word) (s : State)
    (alignment : spAlignmentFault s base = none)
    (accessible : permitted (if load then s.memory.readable else s.memory.writable)
      (memoryBase s base + (if mode = .post then 0 else delta)) 8 = true) :
    dispatchDSuccess (if load then .loadD0 else .storeD0) mode base delta s =
      some (step (.vectorMemory ⟨.double, load, 0, base, .immediate delta, mode⟩) s) := by
  cases load with
  | false =>
      change some (dWritebackCore false mode base delta s) = _
      rw [d_writeback_refines false mode base delta s alignment accessible]
  | true =>
      change some (dWritebackCore true mode base delta s) = _
      rw [d_writeback_refines true mode base delta s alignment accessible]

theorem dispatch_d_success_other (op : GeneratedArm64DispatchSingleton.SingletonOp)
    (mode : Writeback) (base : Register) (delta : Word) (s : State)
    (notLoad : op ≠ .loadD0) (notStore : op ≠ .storeD0) :
    dispatchDSuccess op mode base delta s = none := by
  simp [dispatchDSuccess, GeneratedArm64DispatchSingleton.loadD0Handled,
    GeneratedArm64DispatchSingleton.storeD0Handled, notLoad, notStore]


/-- Architectural Q observation joins only two equal-direction, contiguous
8-byte effects. Any other trace, including fault/helper/exclusive events,
passes through unchanged. The original two events remain in `qSuccess`;
joining is an explicit observation of this sequential memory model and does
not prove single-copy atomicity or concurrency guarantees for C/platforms. -/
def joinQEvents (events : List Event) : List Event :=
  match events with
  | [.memory kind address low firstInit, .memory secondKind secondAddress high secondInit] =>
      if kind = secondKind ∧ secondAddress = address + 8 ∧ low.length = 8 ∧ high.length = 8 then
        [.memory kind address (low ++ high) (firstInit && secondInit)]
      else events
  | _ => events

def observeQ (result : Transition State) : Transition State :=
  { result with events := joinQEvents result.events }

theorem q_observation_state (result : Transition State) : (observeQ result).state = result.state := rfl

theorem q_observation_fault (result : Transition State) : (observeQ result).fault = result.fault := rfl

theorem join_q_pair (kind : AccessKind) (address : Word) (low high : List Byte) (firstInit secondInit : Bool)
    (lowLength : low.length = 8) (highLength : high.length = 8) :
    joinQEvents [.memory kind address low firstInit, .memory kind (address + 8) high secondInit] =
      [.memory kind address (low ++ high) (firstInit && secondInit)] := by
  simp only [joinQEvents, lowLength, highLength, true_and, and_self, ↓reduceIte]

/-- Joining preserves every ordered byte's access kind, wrapping address
and value. Initialization is the explicit conjunction in `join_q_pair`. -/
theorem q_byte_positions (kind : AccessKind) (address : Word) (low high : List Byte)
    (lowLength : low.length = 8) :
    (low ++ high).mapIdx (fun n value => (kind, address + BitVec.ofNat 64 n, value)) =
      low.mapIdx (fun n value => (kind, address + BitVec.ofNat 64 n, value)) ++
      high.mapIdx (fun n value => (kind, address + 8 + BitVec.ofNat 64 n, value)) := by
  simp [List.mapIdx_append, lowLength, BitVec.ofNat_add, BitVec.add_assoc, Nat.add_comm, BitVec.add_comm]
  congr 1
  funext n value
  ac_rfl

theorem q_read_bytes (m : Memory) (address : Word) :
    bytesAt m address 8 ++ bytesAt m (address + 8) 8 = bytesAt m address 16 := by
  simp [bytesAt, List.range_succ, Reference.Word, BitVec.add_assoc]

theorem q_read_initialized (m : Memory) (address : Word) :
    (initializedAt m address 8 && initializedAt m (address + 8) 8) = initializedAt m address 16 := by
  simp [initializedAt, permitted, List.range_succ, Reference.Word, BitVec.add_assoc, Bool.and_assoc]

theorem q_store_bytes (value : BitVec 128) :
    valueBytes (value.setWidth 64) 8 ++ valueBytes ((value >>> 64).setWidth 64) 8 =
      (List.range 16).map (fun n => (value >>> (8 * n)).setWidth 8) := by
  rw [← d_store_bytes value]
  unfold valueBytes
  rw [show List.range 16 = List.range 8 ++ (List.range 8).map (fun n => 8 + n) from (List.range_add (n := 8) (m := 8))]
  rw [List.map_append, List.map_map]
  congr 1
  apply List.map_congr_left
  intro n member
  have nBound : n < 8 := List.mem_range.mp member
  apply BitVec.eq_of_getLsbD_eq
  intro bit bitBound
  have lowBound : 8 * n + bit < 64 := by omega
  simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
  simp [bitBound, lowBound, Nat.mul_add, Nat.add_assoc]

/-- Actual two-lane Q transfer: no C permission guard is invented. Both read
lanes use the same incoming sequential memory; stores retain low then high
updates and their two separate events. Faulting and concurrent accesses are
not inferred from this admitted-success body. -/
def qSuccess (load : Bool) (address : Word) (s : State) : Transition State :=
  if load then
    let low := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth .double) (wordAt s.memory address 8)
    let high := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth .double) (wordAt s.memory (address + 8) 8)
    ⟨{ s with vector0 := qLoad low high, pc := s.pc + 4 },
      [.memory .read address (bytesAt s.memory address 8) (initializedAt s.memory address 8),
       .memory .read (address + 8) (bytesAt s.memory (address + 8) 8) (initializedAt s.memory (address + 8) 8)], none⟩
  else
    let low := s.vector0.setWidth 64
    let high := (s.vector0 >>> 64).setWidth 64
    let memory := Arm64Memory.store .double (Arm64Memory.store .double s.memory address low) (address + 8) high
    ⟨{ s with memory := memory, pc := s.pc + 4 },
      [.memory .write address (valueBytes low 8) true, .memory .write (address + 8) (valueBytes high 8) true], none⟩

/-- Grouped architectural observation is derived from the two concrete lane
values/events; it is not a semantic equality supplied by a caller. -/
def qGroupedSuccess (load : Bool) (address : Word) (s : State) : Transition State :=
  if load then
    ⟨{ s with vector0 := qLoad (wordAt s.memory address 8) (wordAt s.memory (address + 8) 8), pc := s.pc + 4 },
      [.memory .read address (bytesAt s.memory address 16) (initializedAt s.memory address 16)], none⟩
  else
    ⟨{ s with memory := (storeMemory (storeMemory s.memory address (s.vector0.setWidth 64) 8)
        (address + 8) ((s.vector0 >>> 64).setWidth 64) 8), pc := s.pc + 4 },
      [.memory .write address ((List.range 16).map (fun n => (s.vector0 >>> (8 * n)).setWidth 8)) true], none⟩

theorem q_success_observation (load : Bool) (address : Word) (s : State) :
    observeQ (qSuccess load address s) = qGroupedSuccess load address s := by
  cases load <;>
    simp only [qSuccess, qGroupedSuccess, observeQ, Bool.false_eq_true, ↓reduceIte,
      Arm64Memory.load_value, Arm64Memory.store_refines, MemoryWidth.bytes]
  · rw [join_q_pair .write address _ _ true true (by simp [valueBytes]) (by simp [valueBytes]), q_store_bytes]
    rfl
  · rw [join_q_pair .read address _ _ _ _ (by simp [bytesAt]) (by simp [bytesAt]), q_read_bytes, q_read_initialized]

theorem q_grouped_base (load : Bool) (address : Word) (s : State) (base : Register) :
    memoryBase (qGroupedSuccess load address s).state base = memoryBase s base := by cases load <;> rfl

theorem q_grouped_bump (load : Bool) (address : Word) (s : State) (base : Register) (delta : Word) :
    qGroupedSuccess load address (bumpBase s base delta) =
      { qGroupedSuccess load address s with state := bumpBase (qGroupedSuccess load address s).state base delta } := by
  simp only [bump_refines, q_grouped_base]
  cases load <;> by_cases stack : base.val = 31 <;>
    simp only [qGroupedSuccess, writeMemoryBase, stack, writeReg, Bool.false_eq_true, ↓reduceIte]

/-- The two lane accesses occur between the actual pre/post base updates.
Its observation groups events only; the complete numeric state is unchanged. -/
def qWritebackCore (load : Bool) (mode : Writeback) (base : Register) (delta : Word)
    (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s base (GeneratedArm64MemPrepost.preDelta flags delta)
  let offset := GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset flags) false delta 0
  let transferred := qSuccess load (Arm64Memory.baseValue before base + offset) before
  { transferred with state := bumpBase transferred.state base (GeneratedArm64MemPrepost.postDelta flags delta) }

def qGroupedWritebackCore (load : Bool) (mode : Writeback) (base : Register) (delta : Word)
    (s : State) : Transition State :=
  let flags := Arm64AddressedMemory.flags mode
  let before := bumpBase s base (GeneratedArm64MemPrepost.preDelta flags delta)
  let offset := GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset flags) false delta 0
  let transferred := qGroupedSuccess load (Arm64Memory.baseValue before base + offset) before
  { transferred with state := bumpBase transferred.state base (GeneratedArm64MemPrepost.postDelta flags delta) }

theorem q_writeback_observation (load : Bool) (mode : Writeback) (base : Register) (delta : Word) (s : State) :
    observeQ (qWritebackCore load mode base delta s) = qGroupedWritebackCore load mode base delta s := by
  unfold qWritebackCore qGroupedWritebackCore
  have observed := q_success_observation load
    (Arm64Memory.baseValue (bumpBase s base (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta)) base +
      GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset (Arm64AddressedMemory.flags mode)) false delta 0)
    (bumpBase s base (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta))
  cases raw : qSuccess load
    (Arm64Memory.baseValue (bumpBase s base (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta)) base +
      GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset (Arm64AddressedMemory.flags mode)) false delta 0)
    (bumpBase s base (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta))
  simp only [raw, observeQ] at observed ⊢
  rw [← observed]

theorem q_grouped_writeback_eq (load : Bool) (mode : Writeback) (base : Register) (delta : Word) (s : State) :
    qGroupedWritebackCore load mode base delta s =
      let address := memoryBase s base + (if mode = .post then 0 else delta)
      let transferred := qGroupedSuccess load address s
      { transferred with state := if mode = .none then transferred.state else
          writeMemoryBase transferred.state base (memoryBase s base + delta) } := by
  simp only [qGroupedWritebackCore, Arm64Memory.base_refines, base_bump, BitVec.add_assoc,
    Arm64AddressedMemory.access_offset_refines, q_grouped_bump]
  rw [writeback_base_refines]
  cases mode with
  | none => simp [Reference.Word, write_base_read]
  | pre => simp [Reference.Word, q_grouped_base]
  | post => simp [Reference.Word, q_grouped_base]

/-- Successful Q0 refinement in the canonical sequential model, retaining
original SP alignment and all sixteen byte permissions. Grouped events and
pre/post writeback are proved, not assumed. Concurrent atomicity/order and
faulting writeback remain separate platform/body obligations. -/
theorem q_writeback_observed_refines (load : Bool) (mode : Writeback) (base : Register)
    (delta : Word) (s : State) (alignment : spAlignmentFault s base = none)
    (accessible : permitted (if load then s.memory.readable else s.memory.writable)
      (memoryBase s base + (if mode = .post then 0 else delta)) 16 = true) :
    observeQ (qWritebackCore load mode base delta s) =
      step (.vectorMemory ⟨.quad, load, 0, base, .immediate delta, mode⟩) s := by
  rw [q_writeback_observation, q_grouped_writeback_eq]
  simp only [qGroupedSuccess, q_load_refines]
  cases mode <;> cases load <;> by_cases stack : base.val = 31 <;>
    simp_all [qGroupedSuccess, step, vectorMemoryStep, memoryOffset,
      VectorMemoryWidth.bytes, VectorMemoryWidth.scale, q_load_refines,
      writeMemoryBase, writeReg, Reference.Word]

end KProgFormal.Refinement.Arm64VectorMemory
