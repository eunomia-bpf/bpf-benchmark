import KProgFormal.Refinement.Arm64Memory

namespace KProgFormal.Refinement.Arm64Atomic

open Reference Reference.AArch64

/-- The LDADD handler writes X for64-bit accesses and W for the three
smaller widths, after capturing the typed atomic fetch result. -/
def destinationWidth : MemoryWidth → Width
  | .double => .w64
  | _ => .w32

theorem loaded_value (width : MemoryWidth) (value : Word) :
    narrow (Arm64Memory.loadResult width none value) (destinationWidth width) =
      memoryLoadValue width none value := by
  cases width <;>
    simp only [destinationWidth, Arm64Memory.loadResult, Arm64Memory.valueWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask, narrow,
      memoryLoadValue, MemoryWidth.bits, MemoryWidth.bytes, Width.bits,
      Reference.Word, Nat.reduceMul] <;> bv_decide

/-- Numeric projection of the actual typed fetch-add. The old value and source
are captured before storing or destination writeback; base/data/target aliases
retain the same incoming address and operand. Pointer tags and the physical
atomic primitive remain the explicit compiler/platform relation. -/
def bodyWith (combine : Word → Word → Word) (width : MemoryWidth) (dst src base : Register) (s : State) : Transition State :=
  let address := Arm64Memory.baseValue s base
  let addend := Arm64Register.readReg s src
  let old := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width)
    (wordAt s.memory address 8)
  let memory := Arm64Memory.store width s.memory address (combine old addend)
  let loaded := Arm64Memory.loadResult width none old
  ⟨{ Arm64Register.writeReg s dst loaded (destinationWidth width) with
      memory := memory, pc := s.pc + 4 },
    [.memory .atomic address (bytesAt s.memory address width.bytes)
      (initializedAt s.memory address width.bytes)], none⟩

def body (width : MemoryWidth) (dst src base : Register) (s : State) : Transition State :=
  bodyWith (· + ·) width dst src base s

def logicalBody (set : Bool) (width : MemoryWidth) (dst src base : Register)
    (s : State) : Transition State :=
  bodyWith (atomicLogicalValue set) width dst src base s

/-- Success has the canonical complete state and atomic old-byte observation.
Alignment and read/write permissions describe the native platform access;
the C body uses its existing atomic primitive at that resolved address. -/
theorem body_refines (i : AtomicAddInstruction) (s : State)
    (stackAlignment : spAlignmentFault s i.base = none)
    (atomicAlignment : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = none)
    (readable : permitted s.memory.readable (memoryBase s i.base) i.width.bytes = true)
    (writable : permitted s.memory.writable (memoryBase s i.base) i.width.bytes = true) :
    body i.width i.dst i.src i.base s = step (.atomicAdd i) s := by
  simp only [body, bodyWith, step, atomicAddStep, atomicRmwStep, stackAlignment, atomicAlignment,
    Arm64Memory.base_refines, Arm64Memory.load_value, Arm64Register.read_refines,
    Arm64Memory.store_refines, Arm64Register.write_refines, loaded_value,
    readMemory, writeMemory, readable, writable, ↓reduceIte]

/-- The simulator AUX low two bits select the same acquire/release profile.
Destination31 supplies STADD's acquire suppression, for every raw AUX word. -/
def ordering (aux : BitVec 32) (dst : Register) : Bool × Bool :=
  ((aux &&& 1 != 0) && (dst.val != 31), aux &&& 2 != 0)

theorem ordering_refines (aux : BitVec 32) (dst src base : Register) (width : MemoryWidth) :
    ordering aux dst =
      (⟨width, aux &&& 1 != 0, aux &&& 2 != 0, dst, src, base⟩ : AtomicAddInstruction).ordering := rfl

/-- Every architectural SP fault preserves the incoming state and atomic memory. -/
theorem stack_fault (i : AtomicAddInstruction) (s : State) (fault : Fault)
    (failed : spAlignmentFault s i.base = some fault) :
    step (.atomicAdd i) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, atomicAddStep, atomicRmwStep, failed]

/-- Architectural atomic alignment faults also precede every register/memory
commit. The current LSE/LSE2 profile supplies the resolved alignment predicate. -/
theorem alignment_fault (i : AtomicAddInstruction) (s : State) (fault : Fault)
    (stackAlignment : spAlignmentFault s i.base = none)
    (failed : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = some fault) :
    step (.atomicAdd i) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, atomicAddStep, atomicRmwStep, stackAlignment, failed]

/-- OR and AND-with-complement implement LDSET and LDCLR over the same
captured address/source, zero-extended old result and complete atomic state. -/
theorem logical_body_refines (set : Bool) (i : AtomicAddInstruction) (s : State)
    (stackAlignment : spAlignmentFault s i.base = none)
    (atomicAlignment : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = none)
    (readable : permitted s.memory.readable (memoryBase s i.base) i.width.bytes = true)
    (writable : permitted s.memory.writable (memoryBase s i.base) i.width.bytes = true) :
    logicalBody set i.width i.dst i.src i.base s = step (.atomicLogical set i) s := by
  simp only [logicalBody, bodyWith, step, atomicLogicalStep, atomicRmwStep,
    stackAlignment, atomicAlignment, Arm64Memory.base_refines, Arm64Memory.load_value,
    Arm64Register.read_refines, Arm64Memory.store_refines, Arm64Register.write_refines,
    loaded_value, readMemory, writeMemory, readable, writable, ↓reduceIte]

theorem logical_stack_fault (set : Bool) (i : AtomicAddInstruction) (s : State) (fault : Fault)
    (failed : spAlignmentFault s i.base = some fault) :
    step (.atomicLogical set i) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, atomicLogicalStep, atomicRmwStep, failed]

theorem logical_alignment_fault (set : Bool) (i : AtomicAddInstruction) (s : State) (fault : Fault)
    (stackAlignment : spAlignmentFault s i.base = none)
    (failed : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = some fault) :
    step (.atomicLogical set i) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, atomicLogicalStep, atomicRmwStep, stackAlignment, failed]

/-- Numeric C dispatch of bpf_arm64_native_lab_atomic8: the u64 argument is
narrowed to u8 before the selected fetch primitive; its old result is u8. -/
def byteFetchValue (operation : BitVec 32) (old : Byte) (argument : Word) : Byte :=
  if operation = 0 then old + argument.setWidth 8
  else if operation = 1 then old ||| argument.setWidth 8
  else old &&& argument.setWidth 8

theorem byte_fetch_add (old argument : Word) :
    byteFetchValue 0 (old.setWidth 8) argument = (old + argument).setWidth 8 := by
  simp only [byteFetchValue, ↓reduceIte]
  unfold Word at *
  bv_decide

theorem byte_fetch_set (old argument : Word) :
    byteFetchValue 1 (old.setWidth 8) argument = (atomicLogicalValue true old argument).setWidth 8 := by
  simp only [byteFetchValue, atomicLogicalValue, ↓reduceIte]
  unfold Word at *
  bv_decide

theorem byte_fetch_clear (old argument : Word) :
    byteFetchValue 2 (old.setWidth 8) (~~~argument) = (atomicLogicalValue false old argument).setWidth 8 := by
  simp only [byteFetchValue, atomicLogicalValue, ↓reduceIte]
  unfold Word at *
  bv_decide

/-- One-byte stores depend precisely on the low byte, at wrapping addresses. -/
theorem byte_store_congr (memory : Memory) (address first second : Word)
    (same : first.setWidth 8 = second.setWidth 8) :
    storeMemory memory address first 1 = storeMemory memory address second 1 := by
  unfold storeMemory
  congr 1
  funext a
  dsimp only
  split
  · rename_i inside
    have zero : (a-address).toNat = 0 := by omega
    simpa only [zero, Nat.mul_zero, BitVec.ushiftRight_zero] using same
  · rfl

theorem byte_word (memory : Memory) (address : Word) :
    wordAt memory address 1 = (memory.value address).setWidth 64 := by
  simp [wordAt, bytesAt, littleEndian, List.range_succ]

theorem byte_loaded (memory : Memory) (address : Word) :
    GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth .byte)
      (wordAt memory address 8) = (memory.value address).setWidth 64 := by
  rw [Arm64Memory.load_value, MemoryWidth.bytes, byte_word]

/-- The typed byte primitive captures its incoming address, source and old
byte before either memory or destination changes. Atomic indivisibility and
ordering are the physical primitive interface, as for the wider fetch forms. -/
def byteKfuncBody (operation : BitVec 32) (complement : Bool)
    (dst src base : Register) (s : State) : Transition State :=
  let address := Arm64Memory.baseValue s base
  let source := Arm64Register.readReg s src
  let argument := if complement then ~~~source else source
  let old := s.memory.value address
  let memory := storeMemory s.memory address
    ((byteFetchValue operation old argument).setWidth 64) 1
  ⟨{ Arm64Register.writeReg s dst (old.setWidth 64) .w32 with
      memory := memory, pc := s.pc + 4 },
    [.memory .atomic address (bytesAt s.memory address 1)
      (initializedAt s.memory address 1)], none⟩

/-- The byte kfunc ADD path implements the existing typed C body. -/
theorem byte_kfunc_add_body (dst src base : Register) (s : State) :
    byteKfuncBody 0 false dst src base s = body .byte dst src base s := by
  unfold byteKfuncBody body bodyWith
  dsimp only
  rw [byte_loaded]
  simp only [Bool.false_eq_true, ↓reduceIte, Arm64Memory.store_refines,
    MemoryWidth.bytes, destinationWidth, Arm64Memory.loadResult,
    Arm64Memory.valueWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask]
  have loaded (old : Byte) : BitVec.and (old.setWidth 64) (255#64) = old.setWidth 64 := by
    change old.setWidth 64 &&& (255#64) = old.setWidth 64
    unfold Byte at *
    bv_decide
  rw [loaded]
  have memory :
      storeMemory s.memory (Arm64Memory.baseValue s base)
        ((byteFetchValue 0 (s.memory.value (Arm64Memory.baseValue s base))
          (Arm64Register.readReg s src)).setWidth 64) 1 =
      storeMemory s.memory (Arm64Memory.baseValue s base)
        ((s.memory.value (Arm64Memory.baseValue s base)).setWidth 64 + Arm64Register.readReg s src) 1 := by
    apply byte_store_congr
    simp only [byteFetchValue, ↓reduceIte]
    generalize s.memory.value (Arm64Memory.baseValue s base) = old
    generalize Arm64Register.readReg s src = source
    unfold Word Byte at *
    bv_decide
  rw [memory]

/-- LDSET passes the uncomplemented source, LDCLR passes its complement and
selects AND. Their whole byte-memory and register/PC frames match the C body. -/
theorem byte_kfunc_logical_body (set : Bool) (dst src base : Register) (s : State) :
    byteKfuncBody (if set then 1 else 2) (!set) dst src base s =
      logicalBody set .byte dst src base s := by
  unfold byteKfuncBody logicalBody bodyWith
  dsimp only
  rw [byte_loaded]
  simp only [Arm64Memory.store_refines, MemoryWidth.bytes, destinationWidth,
    Arm64Memory.loadResult, Arm64Memory.valueWidth,
    GeneratedArm64Width.narrow, GeneratedArm64Width.mask]
  have loaded (old : Byte) : BitVec.and (old.setWidth 64) (255#64) = old.setWidth 64 := by
    change old.setWidth 64 &&& (255#64) = old.setWidth 64
    unfold Byte at *
    bv_decide
  rw [loaded]
  have memory :
      storeMemory s.memory (Arm64Memory.baseValue s base)
        ((byteFetchValue (if set then 1 else 2) (s.memory.value (Arm64Memory.baseValue s base))
          (if !set then ~~~Arm64Register.readReg s src else Arm64Register.readReg s src)).setWidth 64) 1 =
      storeMemory s.memory (Arm64Memory.baseValue s base)
        (atomicLogicalValue set ((s.memory.value (Arm64Memory.baseValue s base)).setWidth 64)
          (Arm64Register.readReg s src)) 1 := by
    apply byte_store_congr
    cases set <;> simp only [Bool.not_true, Bool.not_false, Bool.false_eq_true,
      ↓reduceIte, byteFetchValue, atomicLogicalValue]
    all_goals
      generalize s.memory.value (Arm64Memory.baseValue s base) = old
      generalize Arm64Register.readReg s src = source
      unfold Word Byte at *
      bv_decide
  rw [memory]

/-- Byte alignment follows from the canonical ISA; SP and access permissions
remain the same premises as in the existing per-operation refinement. -/
theorem byte_kfunc_add_refines (dst src base : Register) (acquire release : Bool) (s : State)
    (stackAlignment : spAlignmentFault s base = none)
    (readable : permitted s.memory.readable (memoryBase s base) 1 = true)
    (writable : permitted s.memory.writable (memoryBase s base) 1 = true) :
    byteKfuncBody 0 false dst src base s =
      step (.atomicAdd ⟨.byte, acquire, release, dst, src, base⟩) s := by
  rw [byte_kfunc_add_body]
  refine body_refines (⟨.byte, acquire, release, dst, src, base⟩ : AtomicAddInstruction) s stackAlignment ?_ readable writable
  simp [atomicAlignmentFault, MemoryWidth.bytes, Nat.mod_one]

theorem byte_kfunc_logical_refines (set : Bool) (dst src base : Register)
    (acquire release : Bool) (s : State)
    (stackAlignment : spAlignmentFault s base = none)
    (readable : permitted s.memory.readable (memoryBase s base) 1 = true)
    (writable : permitted s.memory.writable (memoryBase s base) 1 = true) :
    byteKfuncBody (if set then 1 else 2) (!set) dst src base s =
      step (.atomicLogical set ⟨.byte, acquire, release, dst, src, base⟩) s := by
  rw [byte_kfunc_logical_body]
  refine logical_body_refines set (⟨.byte, acquire, release, dst, src, base⟩ : AtomicAddInstruction) s stackAlignment ?_ readable writable
  simp [atomicAlignmentFault, MemoryWidth.bytes, Nat.mod_one]


end KProgFormal.Refinement.Arm64Atomic


#print axioms KProgFormal.Refinement.Arm64Atomic.byte_kfunc_add_body
#print axioms KProgFormal.Refinement.Arm64Atomic.byte_kfunc_logical_body
#print axioms KProgFormal.Refinement.Arm64Atomic.byte_kfunc_add_refines
#print axioms KProgFormal.Refinement.Arm64Atomic.byte_kfunc_logical_refines
