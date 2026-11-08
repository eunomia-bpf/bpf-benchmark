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
def body (width : MemoryWidth) (dst src base : Register) (s : State) : Transition State :=
  let address := Arm64Memory.baseValue s base
  let addend := Arm64Register.readReg s src
  let old := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width)
    (wordAt s.memory address 8)
  let memory := Arm64Memory.store width s.memory address (old + addend)
  let loaded := Arm64Memory.loadResult width none old
  ⟨{ Arm64Register.writeReg s dst loaded (destinationWidth width) with
      memory := memory, pc := s.pc + 4 },
    [.memory .atomic address (bytesAt s.memory address width.bytes)
      (initializedAt s.memory address width.bytes)], none⟩

/-- Success has the canonical complete state and atomic old-byte observation.
Alignment and read/write permissions describe the native platform access;
the C body uses its existing atomic primitive at that resolved address. -/
theorem body_refines (i : AtomicAddInstruction) (s : State)
    (stackAlignment : spAlignmentFault s i.base = none)
    (atomicAlignment : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = none)
    (readable : permitted s.memory.readable (memoryBase s i.base) i.width.bytes = true)
    (writable : permitted s.memory.writable (memoryBase s i.base) i.width.bytes = true) :
    body i.width i.dst i.src i.base s = step (.atomicAdd i) s := by
  simp only [body, step, atomicAddStep, stackAlignment, atomicAlignment,
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
  simp only [step, atomicAddStep, failed]

/-- Architectural atomic alignment faults also precede every register/memory
commit. The current LSE/LSE2 profile supplies the resolved alignment predicate. -/
theorem alignment_fault (i : AtomicAddInstruction) (s : State) (fault : Fault)
    (stackAlignment : spAlignmentFault s i.base = none)
    (failed : atomicAlignmentFault s (memoryBase s i.base) i.width.bytes = some fault) :
    step (.atomicAdd i) s = ⟨s, [.fault fault], some fault⟩ := by
  simp only [step, atomicAddStep, stackAlignment, failed]

end KProgFormal.Refinement.Arm64Atomic
