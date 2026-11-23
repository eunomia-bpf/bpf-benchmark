import KProgFormal.ClightRefinement.X86ShiftLeft
import KProgFormal.ClightRefinement.X86WidthShape

namespace KProgFormal.ClightRefinement.X86ApplyWidth

def length (size : X86.Size) : Nat :=
  X86WidthShape.length (BitVec.ofNat 8 size.bytes)

/-- The original width-selecting assignments and final AND return exactly
x86lean's width-truncated word for every value, with all caller memory intact. -/
theorem internal (ge : CC.CGenv) (value : BitVec 64) (size : X86.Size)
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_apply_width)
        [.Vlong value, X86ShiftLeft.argument size] k m)
      (.Returnstate (.Vlong (X86.Value.trunc size value)) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, length, X86WidthShape.length,
      X86ShiftLeft.argument, X86.Size.bytes, X86.Size.mask, X86.Value.trunc,
      CC.doStep, CC.doFunctionEntry2, X86_program_profile_bpf.f_x86_apply_width,
      CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
      CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.semAnd,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.repr,
      CC.Integers.Int64.repr, CC.Integers.MI.repr, CC.Integers.Int64.and, CC.Integers.MI.and,
      CC.callCont, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, empty, CC.Eapp, CC.E0]

end KProgFormal.ClightRefinement.X86ApplyWidth
