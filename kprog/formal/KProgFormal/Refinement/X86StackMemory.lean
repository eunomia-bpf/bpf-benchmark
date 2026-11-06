import KProgFormal.Refinement.X86Push

namespace KProgFormal.Refinement.X86StackMemory

open Reference
open Reference.X86 (StackWidth)
open X86Pop (widthCode)

/-- Full-field immediate/memory PUSH routes share the actual generated stack
transfer; memory reads are taken before changing RSP. -/
def pushImmediate (width : StackWidth) (value nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  X86Push.transferStep width value [] nextPc s

def pushMemory (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Bt.readOperand width.registerWidth (.memory address) s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) => X86Push.transferStep width value events nextPc s

/-- The POP destination EA is decoded with the advanced RSP. Its stack load
still reads the old RSP, and a destination write fault commits no register or
memory change. The generated store preserves every byte outside the operand. -/
def popMemory (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Bt.readOperand width.registerWidth (.memory (s.gpr 4)) s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      if permitted s.memory.writable address width.bytes then
        let memory := X86Push.store width s.memory address value
        let advanced := generatedX86PushPopRspAt .pop (s.gpr 4) (widthCode width)
        ⟨{ s with gpr := (fun r => if r = 4 then advanced else s.gpr r), memory := memory, pc := nextPc },
          events ++ [.memory .write address (valueBytes value width.bytes) true], none⟩
      else ⟨s, events ++ [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem push_immediate_refines (width : StackWidth) (value nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.pushImmediate width value nextPc) s (pushImmediate width value nextPc s) := by
  unfold Reference.X86.Step
  rw [show pushImmediate width value nextPc s =
    Reference.X86.step (.pushImmediate width value nextPc) s from
      X86Push.transfer_refines width value [] nextPc s]
  exact ⟨rfl, rfl, rfl⟩

theorem push_memory_step (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    pushMemory width address nextPc s = Reference.X86.step (.pushMemory width address nextPc) s := by
  simp only [pushMemory, X86Bt.read_refines, Reference.X86.step, X86Push.transfer_refines]
  cases width <;> rfl

theorem pop_memory_step (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    popMemory width address nextPc s = Reference.X86.step (.popMemory width address nextPc) s := by
  have bytes_eq : width.registerWidth.bytes = width.bytes := by cases width <;> rfl
  simp only [popMemory, X86Bt.read_refines, bytes_eq, Reference.X86.step, writeMemory,
    X86Push.store_refines, (X86Pop.stack_address_refines width (s.gpr 4)).2]
  cases read : Reference.X86.readSource s (.memory (s.gpr 4)) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, events⟩
      dsimp only
      split <;> rename_i h <;> simp only [h, ↓reduceIte]

theorem push_memory_refines (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.pushMemory width address nextPc) s (pushMemory width address nextPc s) := by
  rw [push_memory_step]
  exact ⟨rfl, rfl, rfl⟩

theorem pop_memory_refines (width : StackWidth) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.popMemory width address nextPc) s (popMemory width address nextPc s) := by
  rw [pop_memory_step]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86StackMemory
