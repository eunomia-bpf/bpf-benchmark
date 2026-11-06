import KProgFormal.Refinement.Arm64Memory
import KProgFormal.Generated.GeneratedArm64PairMem

namespace KProgFormal.Refinement.Arm64PairMemory

open Reference
open Reference.AArch64 (PairMemoryInstruction MemoryWidth Width)

def opcode (i : PairMemoryInstruction) : GeneratedArm64PairMem.Op :=
  if i.load then .ldp else .stp

def accessWidth (i : PairMemoryInstruction) : MemoryWidth :=
  match i.width with | .w32 => .word | .w64 => .double

def address (i : PairMemoryInstruction) (s : Reference.AArch64.State) : Reference.Word :=
  Arm64Memory.baseValue s i.base + GeneratedArm64MemOffset.value false false i.offset 0

/-- The actual pair handler uses WIDTH as the second-element stride. The old
64-bit-only slotOffset contract is deliberately not used for W pairs. -/
def secondAddress (i : PairMemoryInstruction) (address : Reference.Word) : Reference.Word :=
  address + BitVec.ofNat 64 (GeneratedArm64Width.code (Arm64Register.handlerWidth i.width))

def pairRegisters (i : PairMemoryInstruction) (s : Reference.AArch64.State)
    (first second : Reference.Word) : Reference.AArch64.State :=
  Arm64Register.writeReg (Arm64Register.writeReg s i.first first i.width) i.second second i.width

theorem fields_refine (i : PairMemoryInstruction) (s : Reference.AArch64.State) :
    address i s = Reference.AArch64.memoryBase s i.base + i.offset ∧
    (accessWidth i).bytes = i.width.bytes ∧
    GeneratedArm64PairMem.slotCount (opcode i) = 2 ∧
    (GeneratedArm64PairMem.access (opcode i) == .load) = i.load ∧
    (∀ a, secondAddress i a = a + BitVec.ofNat 64 i.width.bytes) := by
  cases load : i.load <;> cases width : i.width <;>
    simp [address, Arm64Memory.base_refines, GeneratedArm64MemOffset.value,
      accessWidth, opcode, GeneratedArm64PairMem.slotCount, GeneratedArm64PairMem.access,
      secondAddress, Arm64Register.handlerWidth, GeneratedArm64Width.code,
      Reference.AArch64.MemoryWidth.bytes, Reference.AArch64.Width.bytes, load, width]

theorem registers_refine (i : PairMemoryInstruction) (s : Reference.AArch64.State)
    (first second : Reference.Word) :
    pairRegisters i s first second = Reference.AArch64.pairRegisters i s first second := by
  simp only [pairRegisters, Reference.AArch64.pairRegisters, Arm64Register.write_refines]

/-- Architectural access events group the handler's byte ladders, just as for
a scalar load/store. The profile selects one double-sized access for FEAT_LSE2
or two ordered element accesses. These are architectural events in the
sequential memory model; simulator spills remain private. -/
def handlerStep (i : PairMemoryInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let address := address i s
  let secondAddress := secondAddress i address
  let width := accessWidth i
  let count := GeneratedArm64PairMem.slotCount (opcode i) * width.bytes
  let finish := fun first second events =>
    (⟨{ pairRegisters i s first second with pc := s.pc + 4 }, events, none⟩ : Transition Reference.AArch64.State)
  if GeneratedArm64PairMem.access (opcode i) == .load then
    if s.pairSingleAccess then
      if permitted s.memory.readable address count then
        finish (GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width) (wordAt s.memory address 8))
          (GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width) (wordAt s.memory secondAddress 8))
          [.memory .read address (bytesAt s.memory address count) (initializedAt s.memory address count)]
      else
        let fault := Fault.read address count
        ⟨s, [.fault fault], some fault⟩
    else
      match Arm64Memory.read width s.memory address with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (first, event) =>
          match Arm64Memory.read width s.memory secondAddress with
          | .error fault => ⟨s, [event, .fault fault], some fault⟩
          | .ok (second, secondEvent) => finish first second [event, secondEvent]
  else
    let first := Arm64Register.readReg s i.first
    let second := Arm64Register.readReg s i.second
    if s.pairSingleAccess then
      if permitted s.memory.writable address count then
        let memory := Arm64Memory.store width (Arm64Memory.store width s.memory address first)
          secondAddress second
        ⟨{ s with memory := memory, pc := s.pc + 4 },
          [.memory .write address (valueBytes first width.bytes ++ valueBytes second width.bytes) true], none⟩
      else
        let fault := Fault.write address count
        ⟨s, [.fault fault], some fault⟩
    else
      match Arm64Memory.write width s.memory address first with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (memory, event) =>
          match Arm64Memory.write width memory secondAddress second with
          | .error fault => ⟨{ s with memory := memory }, [event, .fault fault], some fault⟩
          | .ok (memory, secondEvent) =>
              ⟨{ s with memory := memory, pc := s.pc + 4 }, [event, secondEvent], none⟩

theorem step_refines (i : PairMemoryInstruction) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none) :
    handlerStep i s = Reference.AArch64.step (.pairMemory i) s := by
  have fields := fields_refine i s
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.pairMemoryStep, alignment,
    fields.1, fields.2.1, fields.2.2.1, fields.2.2.2.1, fields.2.2.2.2,
    Arm64Memory.read_refines, Arm64Memory.write_refines, Arm64Memory.store_refines,
    Arm64Memory.load_value, Arm64Register.read_refines, registers_refine]
  rfl

theorem handler_refines (i : PairMemoryInstruction) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none) :
    Reference.AArch64.Step (.pairMemory i) s (handlerStep i s) := (step_refines i s alignment).symm

end KProgFormal.Refinement.Arm64PairMemory
