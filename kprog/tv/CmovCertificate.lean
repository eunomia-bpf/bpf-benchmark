import CompiledBlocks
import KProgFormal.Reference.X86
import Std.Tactic.BVDecide
import BPFPath

namespace KProgTV.CmovCertificate
open KProgFormal.Reference
open KProgTV.BPF

def noExternals : Environment where
  immediate := fun _ _ _ => .error "unexpected external BPF immediate"
  helperCall := fun _ _ => .error "unexpected helper in CMOV block"
  helper := fun _ _ _ => .error "unexpected helper in CMOV block"

def entry (native : X86.State) : State where
  regs := fun r => match r.val with
    | 1 => native.gpr 0
    | 2 => native.gpr 2
    | 3 => native.rflags
    | 10 => 0x10000
    | _ => 0
  memory := native.memory
  pc := 0

def cmovBytes : X86.CmovWidth → Array Byte
  | .w16 => #[0x66, 0x0f, 0x44, 0xc2]
  | .w32 => #[0x0f, 0x44, 0xc2]
  | .w64 => #[0x48, 0x0f, 0x44, 0xc2]

def compiled : X86.CmovWidth → Array Byte
  | .w16 => Compiled.tv_cmov16
  | .w32 => Compiled.tv_cmov32
  | .w64 => Compiled.tv_cmov64

/-- Every byte of native opcode/operands/length is decoded by V's reference. -/
theorem native_decode (width : X86.CmovWidth) (s : X86.State) :
    X86.decode (cmovBytes width) s =
      .ok (.cmov width 4 0 (.register 2) (s.pc + BitVec.ofNat 64 (cmovBytes width).size)) := by
  cases width <;> rfl

def positions : X86.CmovWidth → Bool → List Nat
  | .w16, true => [0,1,2,3,4,5,6,7]
  | .w16, false => [0,1,2,7]
  | .w32, true => [0,1,2,3,4,5,6]
  | .w32, false => [0,1,2,4,5,6]
  | .w64, true => [0,1,2,3,4]
  | .w64, false => [0,1,2,4]

def summary (width : X86.CmovWidth) (s : X86.State) :
    Except String (Word × Bool × Option Fault × List Event) := do
  let result ← BPFPath.evaluate noExternals (compiled width)
    (positions width (X86.condition s.rflags 4)) (entry s)
  pure (result.state.regs 0, result.state.halted, result.fault, result.events)

set_option maxRecDepth 100000
set_option maxHeartbeats 400000

theorem compiled_value (width : X86.CmovWidth) (s : X86.State) :
    summary width s = .ok
      (X86.cmovValue width (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2), true, none, []) := by
  cases flag : s.rflags[6] <;>
    have mask : s.rflags &&& (64#64) = (if s.rflags[6] then 64#64 else 0#64) := by bv_decide
  all_goals
    simp only [flag, Bool.false_eq_true, Bool.true_eq, if_true, if_false] at mask
    cases width <;>
      simp [summary, compiled, positions, BPFPath.evaluate, BPF.execute, BPF.source, BPF.alu,
        BPF.comparison, BPF.setReg, entry, Except.bind, Except.map, Except.pure,
        Bind.bind, Pure.pure, Except.instMonad,
        mask, flag, X86.cmovValue, X86.condition, BitVec.getLsbD_eq_getElem] <;>
      (try simp only [mask]) <;> (try simp) <;> (try dsimp) <;>
      generalize s.gpr 0 = old <;> generalize s.gpr 2 = sourceValue <;> bv_decide

/-- The scalar result comes from actual byte-decoded execution, not a forced
branch or a second implementation of the native condition/value semantics. -/
theorem compiled_execution (width : X86.CmovWidth) (s : X86.State) :
    ∃ result : Transition State,
      Execution (BPFPath.instructionStep noExternals (compiled width))
        (entry s) result.events result.state ∧
      (result.state.regs 0, result.state.halted, result.fault, result.events) =
        (X86.cmovValue width (X86.condition s.rflags 4) (s.gpr 0) (s.gpr 2), true, none, []) := by
  have value := compiled_value width s
  cases evaluated : BPFPath.evaluate noExternals (compiled width)
      (positions width (X86.condition s.rflags 4)) (entry s) with
  | error error => simp [summary, evaluated, Except.bind, Except.pure, Except.map,
      Bind.bind, Pure.pure, Except.instMonad] at value
  | ok result =>
      refine ⟨result, BPFPath.evaluate_sound _ _ _ _ _ evaluated, ?_⟩
      simpa [summary, evaluated, Except.bind, Except.pure, Except.map,
      Bind.bind, Pure.pure, Except.instMonad] using value

end KProgTV.CmovCertificate

#print axioms KProgTV.CmovCertificate.compiled_value
#print axioms KProgTV.CmovCertificate.compiled_execution
