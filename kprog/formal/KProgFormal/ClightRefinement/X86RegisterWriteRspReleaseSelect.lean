import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseLoop

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseSelect

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_select_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def oldTest : CC.Expr := by
  run_tac cachePart (← `(match X86RegisterWriteRspReleaseLoop.iteration with
    | .Ssequence (.Ssequence _ (.Sifthenelse test _ _)) _ => test
    | _ => .Econst_int 0 CC.tint))
private def zero : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterWriteRspReleaseLoop.iteration with
    | .Ssequence (.Ssequence _ (.Sifthenelse _ _ zero)) _ => zero
    | _ => .Sskip))
private def nextTest : CC.Expr := by
  run_tac cachePart (← `(match X86RegisterWriteRspReleaseLoop.iteration with
    | .Ssequence _ (.Sifthenelse test _ _) => test
    | _ => .Econst_int 0 CC.tint))

/-- The original short-circuit decisions retain the whole-word and byte arms. -/
theorem source : X86RegisterWriteRspReleaseLoop.iteration =
    .Ssequence
      (.Ssequence X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_108
        (.Sifthenelse oldTest X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_109 zero))
      (.Sifthenelse nextTest X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110
        X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111) := rfl

def index (slot : Fin 6) : BitVec 32 := BitVec.ofNat 32 (8 * slot.val)
def offset (slot : Fin 6) : BitVec 64 := (index slot).setWidth 64 - 48#64

def whole (slot : Fin 6) (old next : BitVec 64) : Bool :=
  CC.Integers.Int64.cmp .Cge (offset slot) old &&
    CC.Integers.Int64.cmp .Cle (offset slot + 8#64) next

def arm (slot : Fin 6) (old next : BitVec 64) : CC.Stmt :=
  if whole slot old next then X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110
  else X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111

def temps (le : CC.TempEnv) (slot : Fin 6) (old next : BitVec 64) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'117
    (CC.Val.ofBool (CC.Integers.Int64.cmp .Cge (offset slot) old))).set
    X86_program_profile_bpf._t'118 (CC.Val.ofBool (whole slot old next))

/-- All six real word positions fit the source unsigned eight-byte guard. -/
private theorem fits : ∀ slot : Fin 6,
    CC.Integers.Int.cmpu .Cle (index slot + BitVec.ofInt 32 8) (BitVec.ofInt 32 48) = true := by decide +kernel

/-- The actual guard, signed offset comparisons and two Boolean assignments
select the untouched word or byte source arm in nine transitions. This
checks every slot and arbitrary signed old/new raw SP, with no store/provider premise. -/
theorem choose (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (old next : BitVec 64)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 = some (.Vint (index slot)))
    (observedOffset : le.get X86_program_profile_bpf.___x86_release_off__5 = some (.Vlong (offset slot)))
    (observedOld : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (observedNext : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next)) :
    InternalRun ge 9 (.State function X86RegisterWriteRspReleaseLoop.iteration k e le memory)
      (.State function (arm slot old next) k e (temps le slot old next) memory) := by
  have eightLong : BitVec.ofInt 64 (CC.Integers.Int.signed (BitVec.ofInt 32 8)) = (8#64) := rfl
  have fit := fits slot
  dsimp only [CC.Integers.Int.cmpu] at fit
  rw [source]
  cases first : CC.Integers.Int64.cmp .Cge (offset slot) old <;>
    cases last : CC.Integers.Int64.cmp .Cle (offset slot + 8#64) next <;>
    apply internalRun_of_steps
  all_goals simp +decide only [steps, InternalPath, InternalState,
    X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_108,
    X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_109,
    oldTest, nextTest, zero, arm, whole, temps, CC.doStep, CC.doEvalExpr, CC.typeof,
    observedIndex, observedOffset, observedOld, observedNext,
    CC.PTree.gss, CC.PTree.gso,
    first, last, fit, eightLong, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tint, CC.tuint, CC.tlong, CC.tbool,
    CC.Integers.Int.cmpu, CC.Integers.Int64.add, CC.Integers.Int.add, CC.Integers.MI.add,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0,
    Bool.and_false, Bool.and_true, Bool.false_and, Bool.true_and,
    List.nil_append, true_and, ite_true, ite_false, Bool.false_eq_true]
  all_goals rfl

/-- Genuine table-write release reads, loop entry and both source comparisons
compose to the actual first word/byte arm in38 transitions. Every selector
input is derived from the same original execution, not assumed afterward. -/
theorem from_table (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs)
    (old next : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (newSp : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong next))
    (increasingOffset : CC.Integers.Int64.cmp .Cgt next old = true) :
    InternalRun ge 38
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory)
      (.State function (arm (0 : Fin 6) old next)
        (X86RegisterWriteRspReleaseLoop.loopContinuation (X86RegisterWriteRspRelease.releaseContinuation k)) e
        (temps (X86RegisterWriteRspReleaseLoop.temps
          (X86RegisterWriteRspRelease.temps le cellsBlock cellsOffset old next)) (0 : Fin 6) old next) memory) := by
  let ready := X86RegisterWriteRspReleaseLoop.temps
    (X86RegisterWriteRspRelease.temps le cellsBlock cellsOffset old next)
  have readyIndex : ready.get X86_program_profile_bpf.___x86_release_i__5 = some (.Vint (index (0 : Fin 6))) := by
    simp +decide [ready, X86RegisterWriteRspReleaseLoop.temps, index, CC.PTree.gss, CC.PTree.gso]
  have readyOffset : ready.get X86_program_profile_bpf.___x86_release_off__5 = some (.Vlong (offset (0 : Fin 6))) := by
    simp only [ready, X86RegisterWriteRspReleaseLoop.temps, CC.PTree.gss]
    rfl
  have readyOld : ready.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old) := by
    simp +decide [ready, X86RegisterWriteRspReleaseLoop.temps, X86RegisterWriteRspRelease.temps,
      CC.PTree.gss, CC.PTree.gso]
  have readyNext : ready.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next) := by
    simp +decide [ready, X86RegisterWriteRspReleaseLoop.temps, X86RegisterWriteRspRelease.temps,
      CC.PTree.gss, CC.PTree.gso]
  exact (X86RegisterWriteRspReleaseLoop.from_table ge layout function e le k memory bindingBlock cellsBlock
    cellsOffset old next binding destination oldSp cells newSp increasingOffset).trans
    (choose ge function e ready
      (X86RegisterWriteRspReleaseLoop.loopContinuation (X86RegisterWriteRspRelease.releaseContinuation k))
      memory (0 : Fin 6) old next readyIndex readyOffset readyOld readyNext)

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseSelect
