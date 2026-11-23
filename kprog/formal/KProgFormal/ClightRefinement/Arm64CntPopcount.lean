import KProgFormal.ClightRefinement.Arm64NumericProgram
import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.ClightRefinement.Arm64CntNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Popcount

abbrev handler := Arm64Numeric.f_kprog_x86_popcount_value

/-- Numerical values of the three actual C assignments and final return.
The source execution below checks them against the exported function body. -/
private def first (value : BitVec 64) :=
  value - ((value >>> 1) &&& (0x5555555555555555#64))
private def second (value : BitVec 64) :=
  (first value &&& (0x3333333333333333#64)) +
    ((first value >>> 2) &&& (0x3333333333333333#64))
private def third (value : BitVec 64) :=
  (second value + (second value >>> 4)) &&& (0x0f0f0f0f0f0f0f0f#64)
private def returned (value : BitVec 64) :=
  (third value * (0x0101010101010101#64)) >>> 56

private theorem bytes : ∀ byte : BitVec 8,
    returned (byte.setWidth 64) = (DPSFP.simd_count_bytes byte).setWidth 64 := by
  decide +kernel

set_option hygiene false in
/-- Execute the complete original C helper, including its true function
entry and return, for an arbitrary 64-bit argument and entire heap. -/
private theorem execute (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 11
      (.Callstate (.Internal handler) [.Vlong value] k m)
      (.Returnstate (.Vlong (returned value)) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:30] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual shared popcount helper transitions: {i}"
        finished := true
        break
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [
        CC.doStep,CC.doFunctionEntry2,handler,Arm64Numeric.f_kprog_x86_popcount_value,
        CC.listNorepet,CC.varNames,CC.listDisjoint,CC.doAllocVariables,CC.bindParameterTemps,
        CC.createUndefTemps,CC.PTree.gss,CC.doEvalExpr,CC.typeof,
        CC.Cop.semBinaryOperation,CC.Cop.semSub,CC.Cop.classifySub,
        CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semMul,
        CC.Cop.semAnd,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
        CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.tulong,
        CC.Val.subl,CC.Val.addl,CC.Val.mull,CC.Val.andl,CC.Val.shrlu,
        CC.Integers.Int64.sub,CC.Integers.Int64.add,CC.Integers.Int64.mul,
        CC.Integers.Int64.and,CC.Integers.Int64.shru,
        CC.Integers.Int.ltu,CC.Integers.MI.ltu,
        CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int64.repr,
        CC.Integers.MI.sub,CC.Integers.MI.add,CC.Integers.MI.mul,
        CC.Integers.MI.and,CC.Integers.MI.shru,
        CC.blocksOfEnv,CC.emptyEnv,empty,CC.Mem.freeList,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,
        first,second,third,returned] <;> try rfl))
    unless finished do throwError "shared popcount helper has further source transitions"

/-- The real CNT caller supplies a byte, and the complete C call returns
the imported per-byte count with the entire heap and continuation retained. -/
theorem execute_byte (world : CC.CGenv) (byte : BitVec 8) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 11
      (.Callstate (.Internal handler) [.Vlong (byte.setWidth 64)] k m)
      (.Returnstate (.Vlong ((DPSFP.simd_count_bytes byte).setWidth 64)) (CC.callCont k) m) := by
  simpa only [bytes byte] using execute world (byte.setWidth 64) k m

/-- The original shifted-and-masked argument is the actual zero-extended
byte supplied to the shared C helper. -/
theorem byte_operand (value : BitVec 64) (slot : Fin 8) :
    (value >>> (8 * slot.val)) &&& (255#64) =
      ((value >>> (8 * slot.val)).setWidth 8).setWidth 64 := by
  change (value >>> (8 * slot.val)) &&& (BitVec.allOnes 8).setWidth 64 = _
  rw [BitVec.and_setWidth_allOnes 56 8]
  exact (BitVec.setWidth_eq_append
    (x := (value >>> (8 * slot.val)).setWidth 8) (w := 64) (by decide)).symm

/-- All eight actual CNT helper arguments retain the mature per-byte result
and the original memory and return continuation. -/
theorem execute_slice (world : CC.CGenv) (value : BitVec 64) (slot : Fin 8)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 11
      (.Callstate (.Internal handler) [.Vlong ((value >>> (8 * slot.val)) &&& (255#64))] k m)
      (.Returnstate (.Vlong ((DPSFP.simd_count_bytes
        ((value >>> (8 * slot.val)).setWidth 8)).setWidth 64)) (CC.callCont k) m) := by
  rw [byte_operand]
  exact execute_byte world _ k m

end KProgFormal.ClightRefinement.Arm64Cnt.Popcount
