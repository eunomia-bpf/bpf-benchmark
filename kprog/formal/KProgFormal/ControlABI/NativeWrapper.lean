import X86.CheckedMemory
import Std

/-! The native wrapper uses the mature x86lean stack primitives. Its native
JIT branch passes zero physical BPF stack depth, and saves RBX/R13/R14/R15 in
source order before copying the linked image. The inverse order precedes LEAVE
and the stock return. Access permissions and final executable-image embedding
are the existing kernel platform contracts.
-/
namespace KProgFormal.ControlABI.NativeWrapper
open X86

/-- Actual upstream little-endian eight-byte writes reload every source bit,
including at wrapping addresses. -/
theorem word_store_load (memory : X86.Mem) (address value : X86.Val) :
    (memory.writeSize .q address value).readSize .q address = value := by
  simp [X86.Mem.writeSize, X86.Mem.readSize, X86.Size.bytes,
    X86.Mem.writeN, X86.Mem.readN, X86.Mem.read, X86.Mem.write, BitVec.add_assoc]
  apply BitVec.eq_of_getLsbD_eq_iff.mpr
  intro i bound
  have bits : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨
    i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 ∨
    i = 16 ∨ i = 17 ∨ i = 18 ∨ i = 19 ∨ i = 20 ∨ i = 21 ∨ i = 22 ∨ i = 23 ∨
    i = 24 ∨ i = 25 ∨ i = 26 ∨ i = 27 ∨ i = 28 ∨ i = 29 ∨ i = 30 ∨ i = 31 ∨
    i = 32 ∨ i = 33 ∨ i = 34 ∨ i = 35 ∨ i = 36 ∨ i = 37 ∨ i = 38 ∨ i = 39 ∨
    i = 40 ∨ i = 41 ∨ i = 42 ∨ i = 43 ∨ i = 44 ∨ i = 45 ∨ i = 46 ∨ i = 47 ∨
    i = 48 ∨ i = 49 ∨ i = 50 ∨ i = 51 ∨ i = 52 ∨ i = 53 ∨ i = 54 ∨ i = 55 ∨
    i = 56 ∨ i = 57 ∨ i = 58 ∨ i = 59 ∨ i = 60 ∨ i = 61 ∨ i = 62 ∨ i = 63 := by omega
  rcases bits with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl |
    rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals simp

end KProgFormal.ControlABI.NativeWrapper

namespace KProgFormal.ControlABI.NativeWrapper
open X86

/-- PUSH places the full saved word at the mature machine's new stack pointer. -/
theorem push_saved_word (state : Cpu) (value : Val) :
    (state.push .q value).readMem .q ((state.push .q value).regs.get .rsp) = value := by
  simp [Cpu.push, Cpu.readMem, Cpu.writeMem, Cpu.setReg, Regs.get_set_same,
    Value.writeView, word_store_load, Size.bytes]

/-- The primitive stack round trip restores the incoming stack and word;
all flags, vectors and unrelated machine components retain their real values. -/
theorem push_pop (state : Cpu) (value : Val) :
    (state.push .q value).popValue .q =
      (value, {state with mem := (state.push .q value).mem}) := by
  have word := push_saved_word state value
  simp only [Cpu.popValue, word]
  simp [Cpu.push, Cpu.writeMem, Cpu.setReg, Value.writeView, Size.bytes,
    Regs.set, Regs.get, BitVec.sub_add_cancel]

end KProgFormal.ControlABI.NativeWrapper

namespace KProgFormal.ControlABI.NativeWrapper
open X86

/-- The real LEAVE and RET operations implement the native wrapper's unwind.
Only the two saved words, a live model and the architectural canonical-target
condition are required. All other incoming register/flag/vector values are free. -/
theorem leave_return (state : Cpu) (callerFrame returnAddress : Val)
    (live : state.ms = none)
    (savedFrame : state.readMem .q (state.regs.get .rbp) = callerFrame)
    (savedReturn : state.readMem .q (state.regs.get .rbp + 8) = returnAddress)
    (canonicalReturn : canonical returnAddress = true) :
    step {op := .ret 0, len := 1} (step {op := .leave, len := 1} state) =
      { (state.setReg .q .rsp (state.regs.get .rbp + 16)).setReg .q .rbp callerFrame
        with rip := returnAddress } := by
  simp [step, Cpu.stopped, live, Op.lockIllegal, Cpu.popValue, Cpu.readMem,
    Cpu.setReg, Cpu.setRip, Value.writeView, Regs.get, Regs.set, Size.bytes] at *
  simp_all [BitVec.add_assoc]

end KProgFormal.ControlABI.NativeWrapper

#print axioms KProgFormal.ControlABI.NativeWrapper.word_store_load
#print axioms KProgFormal.ControlABI.NativeWrapper.push_pop
#print axioms KProgFormal.ControlABI.NativeWrapper.leave_return

namespace KProgFormal.ControlABI.NativeWrapper
open X86

/-- Kernel callee-save emission uses these upstream stack/register operations. -/
def saveRegister (state : Cpu) (register : GPR) : Cpu :=
  state.push .q (state.regs.get register)

def restoreRegister (state : Cpu) (register : GPR) : Cpu :=
  let (value, popped) := state.popValue .q
  popped.setReg .q register value

/-- Every native callee-save register has the same exact one-slot law.
The same law also covers a saved copy of RSP. -/
theorem save_restore_register (state : Cpu) (register : GPR) :
    restoreRegister (saveRegister state register) register =
      {state with mem := (saveRegister state register).mem} := by
  simp only [restoreRegister, saveRegister, push_pop]
  simp only [Cpu.setReg, Value.writeView]
  congr 1
  cases register <;> rfl

end KProgFormal.ControlABI.NativeWrapper
