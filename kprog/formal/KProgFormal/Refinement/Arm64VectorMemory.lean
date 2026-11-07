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

end KProgFormal.Refinement.Arm64VectorMemory
