import KProgFormal.Reference.AArch64
import KProgFormal.Refinement.Arm64Fmov
import KProgFormal.Generated.GeneratedArm64Reduction
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64Reduction

open Reference
open Reference.AArch64 (ReductionOp)

def operation : ReductionOp → GeneratedArm64Reduction.Reduction
  | .count => .cnt | .unsignedSum => .uaddlv

/-- The handler invokes its generated 64-bit primitive on the active low/high
halves, then either concatenates byte counts or adds the two widened sums. -/
def handlerValue (op : ReductionOp) (wide : Bool) (value : BitVec 128) : BitVec 128 :=
  let low := GeneratedArm64Reduction.value (operation op) (value.setWidth 64)
  let high := if wide then GeneratedArm64Reduction.value (operation op) ((value >>> 64).setWidth 64) else 0
  match op with
  | .count => low.setWidth 128 ||| (high.setWidth 128 <<< 64)
  | .unsignedSum => (low + high).setWidth 128

set_option maxRecDepth 4096 in
set_option maxHeartbeats 4000000 in
theorem value_refines (op : ReductionOp) (wide : Bool) (value : BitVec 128) :
    handlerValue op wide value = Reference.AArch64.reductionValue op wide value := by
  cases op <;> cases wide <;>
    simp only [handlerValue, operation, Reference.AArch64.reductionValue,
      Reference.AArch64.vectorBytes, Reference.AArch64.byteCount, littleEndian,
      GeneratedArm64Reduction.value, GeneratedArm64Reduction.popCountBits,
      Bool.false_eq_true, if_false, if_true, List.range_succ, List.range_zero,
      List.map_append, List.map_cons, List.map_nil, List.foldl_append, List.foldl_cons,
      List.foldl_nil, List.nil_append, List.cons_append, List.append_nil, littleEndian] <;>
    bv_decide (config := { timeout := 60 })

def handlerStep (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ s with vector0 := handlerValue op wide s.vector0, pc := s.pc + 4 }, [], none⟩

theorem step_refines (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) :
    handlerStep op wide s = Reference.AArch64.step (.reduction op wide) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.reductionStep, value_refines]

theorem handler_refines (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.reduction op wide) s (handlerStep op wide s) := (step_refines op wide s).symm

/-- The two numeric operation codes select the existing generated reduction;
AUX=16 activates the high half and every other AUX follows the actual low-half
branch. Native decoding binds the valid 8B/16B source arrangement. -/
def decodeOperation (opcode : Nat) : Option ReductionOp :=
  if opcode = GeneratedArm64Reduction.code .cnt then some .count
  else if opcode = GeneratedArm64Reduction.code .uaddlv then some .unsignedSum
  else none

theorem decode_operation_code (op : ReductionOp) :
    decodeOperation (GeneratedArm64Reduction.code (operation op)) = some op := by
  cases op <;> rfl

def dispatch (opcode aux : Nat) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeOperation opcode).map (fun op => handlerStep op (aux == 16) s)

theorem dispatch_refines (op : ReductionOp) (aux : Nat) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Reduction.code (operation op)) aux s =
      some (Reference.AArch64.step (.reduction op (aux == 16)) s) := by
  simp only [dispatch, decode_operation_code]
  change some (handlerStep op (aux == 16) s) = _
  rw [step_refines]

/-- The final production dispatcher chain checks FMOV first, followed by the
two reduction opcodes. It preserves rejection for every unrelated opcode. -/
def dispatchTail (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register)
    (width : Reference.AArch64.Width) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  if opcode = GeneratedArm64DispatchSingleton.code .fmov then
    Arm64Fmov.dispatch opcode aux src2 dst src width s
  else dispatch opcode aux s

theorem tail_fmov_refines (bank : Reference.AArch64.Register) (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatchTail (GeneratedArm64DispatchSingleton.code .fmov) (GeneratedArm64Fmov.code direction)
      bank.val dst src (Arm64Fmov.operandWidth direction) s =
      some (Reference.AArch64.step (.fmovBank bank (Arm64Fmov.nativeMove direction dst src)) s) := by
  simp only [dispatchTail, ↓reduceIte]
  exact Arm64Fmov.dispatch_refines bank direction dst src s

theorem tail_fmov_legacy_refines (direction : GeneratedArm64Fmov.Fmov)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    dispatchTail (GeneratedArm64DispatchSingleton.code .fmov) (GeneratedArm64Fmov.code direction)
      255 dst src (Arm64Fmov.operandWidth direction) s =
      some (Reference.AArch64.step (.fmovBank 0 (Arm64Fmov.nativeMove direction dst src)) s) := by
  simp only [dispatchTail, ↓reduceIte]
  exact Arm64Fmov.dispatch_legacy_refines direction dst src s

theorem tail_reduction_refines (op : ReductionOp) (aux src2 : Nat)
    (dst src : Reference.AArch64.Register) (width : Reference.AArch64.Width)
    (s : Reference.AArch64.State) :
    dispatchTail (GeneratedArm64Reduction.code (operation op)) aux src2 dst src width s =
      some (Reference.AArch64.step (.reduction op (aux == 16)) s) := by
  have other : GeneratedArm64Reduction.code (operation op) ≠ GeneratedArm64DispatchSingleton.code .fmov := by
    cases op <;> decide
  simp only [dispatchTail, if_neg other]
  exact dispatch_refines op aux s

theorem tail_other (opcode aux src2 : Nat) (dst src : Reference.AArch64.Register)
    (width : Reference.AArch64.Width) (s : Reference.AArch64.State)
    (notFmov : opcode ≠ 35) (notCnt : opcode ≠ 36) (notSum : opcode ≠ 37) :
    dispatchTail opcode aux src2 dst src width s = none := by
  simp [dispatchTail, GeneratedArm64DispatchSingleton.code, dispatch, decodeOperation,
    GeneratedArm64Reduction.code, notFmov, notCnt, notSum]

end KProgFormal.Refinement.Arm64Reduction
