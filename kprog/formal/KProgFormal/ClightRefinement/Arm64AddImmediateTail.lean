import KProgFormal.ClightRefinement.Arm64AddImmediatePrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Tail

private structure Pieces where
  opSet : CC.Stmt
  tagCall : CC.Stmt
  tagSet : CC.Stmt
  candidate : CC.Stmt
  selection : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original ADD tail constructors changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Operands.tail)) none)
    let rest ← peel root[1]!
    let tag ← peel rest[0]!
    let result ← peel rest[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_add_tail (← Lean.Meta.mkAppM ``Pieces.mk
      #[root[0]!, tag[0]!, tag[1]!, result[0]!, result[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_tail_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def opSet : CC.Stmt := by run_tac cachePart (← `(pieces.opSet))
private def tagCall : CC.Stmt := by run_tac cachePart (← `(pieces.tagCall))
private def tagSet : CC.Stmt := by run_tac cachePart (← `(pieces.tagSet))
private def candidate : CC.Stmt := by run_tac cachePart (← `(pieces.candidate))
def selection : CC.Stmt := by run_tac cachePart (← `(pieces.selection))

/-- This arithmetic fragment is assembled from the original handler tail. -/
theorem source : Operands.tail = .Ssequence opSet
    (.Ssequence (.Ssequence tagCall tagSet) (.Ssequence candidate selection)) := rfl

private def opTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program.___a64_alu_op (.Vint 0)
private def tagCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'14) Arm64Nop.handler e (opTemps le)
    (.Kseq tagSet (.Kseq (.Ssequence candidate selection) k))

def candidateTemps (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  (((((opTemps le).set Arm64Program._t'14 (.Vint (4#32))).set
    Arm64Program.___a64_alu_src_tag (.Vint (4#32))).set
    Arm64Program.___kprog_alu64_res (.Vlong (0#64))).set
    Arm64Program.___kprog_alu64_res (.Vlong (lhs + rhs))).set
    Arm64Program.___a64_alu_result (.Vlong (lhs + rhs))

private theorem tag_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_tag) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tuint CC.cc_default := rfl

private theorem call_tag (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_tag = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_tag))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_tag = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong (32#64))) :
    CC.Step2 world (.State Arm64Nop.handler tagCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag) [.Vptr b ofs, .Vlong (32#64)]
        (.Kcall (some Arm64Program._t'14) Arm64Nop.handler e le k) m) := by
  unfold tagCall
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong])
    (tyres := CC.tuint) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist, CC.doEvalExpr, entry, src, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact tag_type

set_option hygiene false in
private theorem enter_tag (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_tag = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_tag))
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_tag = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong (32#64)))
    (aux : le.get Arm64Program._aux = some (.Vint (0#32))) :
    InternalRun world 6 (.State Arm64Nop.handler Operands.tail k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_tag)
        [(.Vptr b ofs), .Vlong (32#64)] (tagCont k e le) m) := by
  have entry' : (opTemps le).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [opTemps, CC.PTree.gso, entry]
  have src' : (opTemps le).get Arm64Program._src = some (.Vlong (32#64)) := by
    simp +decide only [opTemps, CC.PTree.gso, src]
  run_tac do
    for _ in [:5] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, source, opSet,
        tagCall, tagCont, opTemps, CC.doEvalExprlist, CC.doEvalExpr, CC.doEvalLvalue,
        CC.lvalOfVar, CC.doDerefLoc, CC.typeof, CC.accessMode,
        unshadowed, binding.1, binding.2, CC.Genv.findFunct, CC.Cop.classifyFun,
        tag_type,
        entry, src, aux, CC.PTree.gss, CC.PTree.gso,
        CC.Cop.semBinaryOperation, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tulong, CC.tptr,
        CC.Archi.ptr64, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.repr,
        CC.Integers.MI.repr, CC.Integers.Int64.repr,
        CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq,
        CC.Integers.Int.zero, CC.Integers.MI.zero, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.step trivial
      (call_tag world block b ofs e (opTemps le) m _ binding unshadowed entry' src') (InternalRun.refl _)))

set_option hygiene false in
private theorem after_tag (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (lhs rhs : BitVec 64)
    (left : le.get Arm64Program.___a64_alu_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___a64_alu_rhs = some (.Vlong rhs)) :
    InternalRun world 22
      (.Returnstate (.Vint (4#32)) (tagCont k e le) m)
      (.State Arm64Nop.handler selection k e (candidateTemps le lhs rhs) m) := by
  run_tac do
    for _ in [:22] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, tagCont, tagSet,
        candidate, opTemps, candidateTemps, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof, left, right,
        CC.selectSwitch, CC.selectSwitchCase, CC.selectSwitchDefault, CC.seqOfLabeledStatement,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.unsigned, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
        CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int64.repr,
        CC.Integers.Int64.add, CC.Integers.MI.add, CC.Integers.Int.signed, CC.Integers.MI.signed, CC.Integers.Int.zero, CC.Integers.MI.zero,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil,
        ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Execute the actual STACK tag call and inline ADD candidate, preserving all
memory and the original continuation. The eager candidate is retained even
when the subsequent selection chooses the raw pointer writer. -/
theorem evaluate (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (lhs rhs : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_tag = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong (32#64)))
    (aux : le.get Arm64Program._aux = some (.Vint (0#32)))
    (left : le.get Arm64Program.___a64_alu_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___a64_alu_rhs = some (.Vlong rhs)) :
    InternalRun Arm64ProgramEntryLinked.ge 43
      (.State Arm64Nop.handler Operands.tail k e le m)
      (.State Arm64Nop.handler selection k e (candidateTemps le lhs rhs) m) := by
  have enter := enter_tag Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 65)
    Arm64AddOperandReads.Linked.bindings.2.1 b ofs e le m k unshadowed entry src aux
  have tag := Arm64AddOperandReads.sp_tag Arm64ProgramEntryLinked.ge (.Vptr b ofs) m (tagCont k e le)
  have finish := after_tag Arm64ProgramEntryLinked.ge e le m k lhs rhs left right
  simpa only [CC.callCont] using (enter.trans tag).trans finish

end KProgFormal.ClightRefinement.Arm64AddImmediate.Tail
