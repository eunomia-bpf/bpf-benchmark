import KProgFormal.ClightRefinement.X86RegisterReadValue

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspRelease

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_rsp_release_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def release : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 with
    | .Ssequence _ (.Ssequence _ (.Ssequence _ release)) => release | _ => .Sskip))

private def gate : CC.Expr := by
  run_tac cachePart (← `(match release with | .Sifthenelse test _ _ => test | _ => .Econst_int 0 CC.tint))
private def body : CC.Stmt := by
  run_tac cachePart (← `(match release with | .Sifthenelse _ (.Sloop body _) _ => body | _ => .Sskip))
private theorem release_source : release = .Sifthenelse gate (.Sloop body .Sbreak) .Sskip := rfl
private def saveOld : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence save _ => save | _ => .Sskip))
private def reads : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence reads _) => reads | _ => .Sskip))
private def choice : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence _ choice) => choice | _ => .Sskip))
private theorem body_source : body = .Ssequence saveOld (.Ssequence reads choice) := rfl
private def readCells : CC.Stmt := by
  run_tac cachePart (← `(match reads with | .Ssequence first _ => first | _ => .Sskip))
private def readNew : CC.Stmt := by
  run_tac cachePart (← `(match reads with | .Ssequence _ (.Ssequence next _) => next | _ => .Sskip))
private def saveNew : CC.Stmt := by
  run_tac cachePart (← `(match reads with | .Ssequence _ (.Ssequence _ next) => next | _ => .Sskip))
private theorem reads_source : reads = .Ssequence readCells (.Ssequence readNew saveNew) := rfl
private def test : CC.Expr := by
  run_tac cachePart (← `(match choice with | .Sifthenelse test _ _ => test | _ => .Econst_int 0 CC.tint))
private def growing : CC.Stmt := by
  run_tac cachePart (← `(match choice with | .Sifthenelse _ yes _ => yes | _ => .Sskip))
private theorem choice_source : choice = .Sifthenelse test growing .Sskip := rfl

def temps (le : CC.TempEnv) (cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs)
    (old next : BitVec 64) : CC.TempEnv :=
  (((le.set X86_program_profile_bpf.___x86_release_old__5 (.Vlong old)).set
    X86_program_profile_bpf._t'143 (.Vptr cellsBlock cellsOffset)).set
    X86_program_profile_bpf._t'144 (.Vlong next)).set
    X86_program_profile_bpf.___x86_release_new__5 (.Vlong next)

/-- The real RSP release branch reads the saved old offset and the actual
new cell. A non-increasing signed raw offset takes the source's no-release
branch and exits both real loops without changing memory. -/
theorem unchanged (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs)
    (old next : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (newSp : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong next))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt next old = false) :
    InternalRun ge 20
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory)
      (.State function .Sskip k e (temps le cellsBlock cellsOffset old next) memory) := by
  have tableAddress := X86RegisterReadValue.table_address ge layout bindingBlock (0 : CC.Integers.Ptrofs)
  have valueAddress := X86RegisterReadValue.value_address ge layout cellsBlock (cellsOffset + 64)
  have pointerAddress := X86RegisterReadValue.pointer_address ge layout cellsBlock (cellsOffset + 64)
  have cellAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr cellsBlock cellsOffset) (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint (CC.Integers.Int.repr 4)) CC.tint memory = some (.Vptr cellsBlock (cellsOffset + 64)) := by
    simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint,
      CC.sizeof, layout.cell, X86RegisterLayout.layout.2.2.2.1]
    rfl
  have pointerCast (bits : BitVec 64) :
      CC.Cop.semCast (.Vlong bits) (CC.tptr CC.tvoid) CC.tlong memory = some (.Vlong bits) := rfl
  have longCast (bits : BitVec 64) :
      CC.Cop.semCast (.Vlong bits) CC.tlong CC.tlong memory = some (.Vlong bits) := rfl
  have comparison : CC.Cop.semBinaryOperation ge.genv_cenv .Ogt (.Vlong next) CC.tlong
      (.Vlong old) CC.tlong memory = some (.Vint (0#32)) := by
    change some (CC.Val.ofBool (CC.Integers.Int64.cmp .Cgt next old)) = _
    rw [nonIncreasing]
    rfl
  have guard : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq (.Vint (4#32)) CC.tuchar
      (.Vint (CC.Integers.Int.repr 4)) CC.tuint memory = some (.Vint (1#32)) := rfl
  have trueValue : CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
  have falseValue : CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl
  have structAccess (name : CC.Ident) : CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have unionAccess : CC.accessMode (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  dsimp only [CC.tint, CC.tuchar, CC.tuint, CC.tptr, CC.tlong] at cellAdd guard comparison pointerCast longCast trueValue falseValue
  have entered : InternalRun ge 5
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e le memory)
      (.State function body (.Kloop1 body .Sbreak k) e le memory) := by
    change InternalRun ge 5
      (.State function .Sskip (.Kloop1 _ .Sbreak (.Kseq release k)) e le memory)
      (.State function body (.Kloop1 body .Sbreak k) e le memory)
    apply internalRun_of_steps
    all_goals simp +decide only [steps, InternalPath, InternalState, CC.doStep, release_source, gate,
      CC.doEvalExpr, CC.typeof, CC.tint, CC.tuchar, CC.tuint, destination, guard, trueValue,
      CC.Eapp, CC.E0, List.nil_append, true_and, ite_true]
  have loaded : InternalRun ge 12
      (.State function body (.Kloop1 body .Sbreak k) e le memory)
      (.State function choice (.Kloop1 body .Sbreak k) e (temps le cellsBlock cellsOffset old next) memory) := by
    apply internalRun_of_steps
    all_goals simp +decide only [steps, InternalPath, InternalState, CC.doStep, body_source, reads_source,
      saveOld, readCells, readNew, saveNew, temps, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      tableAddress, valueAddress, pointerAddress, structAccess, unionAccess, ptrAccess, unsigned0, cellAdd,
      CC.Mem.loadv, binding, oldSp, cells, newSp, CC.PTree.gss, CC.PTree.gso,
      pointerCast, longCast, CC.tint, CC.tlong,
      CC.Eapp, CC.E0, List.nil_append, true_and]
  have finished : InternalRun ge 3
      (.State function choice (.Kloop1 body .Sbreak k) e (temps le cellsBlock cellsOffset old next) memory)
      (.State function .Sskip k e (temps le cellsBlock cellsOffset old next) memory) := by
    apply internalRun_of_steps
    all_goals simp +decide only [steps, InternalPath, InternalState, CC.doStep, choice_source, test, temps,
      CC.doEvalExpr, CC.typeof, CC.tint, CC.tlong, CC.PTree.gss, CC.PTree.gso, comparison, falseValue,
      CC.Eapp, CC.E0, List.nil_append, true_and, ite_false, Bool.false_eq_true]
  exact (entered.trans loaded).trans finished

end KProgFormal.ClightRefinement.X86RegisterWriteRspRelease
