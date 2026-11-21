import KProgFormal.ClightRefinement.Arm64CompareOperands

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.RhsCall

private structure Pieces where
  call : CC.Stmt
  readSet : CC.Stmt
  tail : CC.Stmt
  flags : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual CMP RHS call constructors changed"
      pure actual.getAppArgs
    let suffix ← peel (← Lean.Elab.Term.elabTerm (← `(Operands.rhs)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel suffix[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let read ← peel body[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_rhs_call (← Lean.Meta.mkAppM ``Pieces.mk
      #[read[0]!, read[1]!, body[1]!, suffix[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_rhs_call_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def modifiedCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
def readSet : CC.Stmt := by run_tac cachePart (← `(pieces.readSet))
def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))
def flags : CC.Stmt := by run_tac cachePart (← `(pieces.flags))
def body : CC.Stmt := .Ssequence (.Ssequence modifiedCall readSet) tail

/-- Preserve both original RHS and flag loops, including all pending operations. -/
theorem rhs_source : Operands.rhs = .Ssequence (.Sloop body .Sbreak) flags := rfl

def tailCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq flags k)
def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'108) Arm64Nop.handler e le
    (.Kseq readSet (.Kseq tail (tailCont k)))

def width (narrow : Bool) : CC.Val := Arm64Width.argument (Dispatch.flags narrow)
def arguments (b : CC.Block) (ofs : CC.Integers.Ptrofs) (source : BitVec 64) (narrow : Bool) : List CC.Val :=
  [.Vptr b ofs, .Vlong source, .Vint (1#32), .Vint (0#32), width narrow]

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modifiedCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual modified call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_modified_target actual.getAppArgs[1]!
private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modifiedCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual modified call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_modified_args actual.getAppArgs[2]!
private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong, CC.tuchar, CC.tuchar, CC.tuchar]
private theorem call_source : modifiedCall = .Scall (some Arm64Program._t'108) target actualArgs := rfl
private theorem target_type : CC.Cop.classifyFun (CC.typeof target) =
    .f parameterTypes CC.tulong CC.cc_default := rfl
private theorem function_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_modified) =
    .Tfunction parameterTypes CC.tulong CC.cc_default := rfl

/-- Decode the actual packed AUX expression and retain each original argument cast. -/
private theorem args_eval (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (source : BitVec 64) (narrow : Bool)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow)) :
    CC.doEvalExprlist world e le m actualArgs parameterTypes = some (arguments b ofs source narrow) := by
  cases narrow <;>
    simp +decide only [actualArgs, parameterTypes, arguments, width, Dispatch.flags, Arm64Width.argument,
      CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, entry, src, aux, effective,
      CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuint, CC.tint, CC.tuchar, CC.tulong, CC.tptr, CC.Archi.ptr64] <;> rfl

private theorem call_step (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (source : BitVec 64) (narrow : Bool)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_modified = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_modified))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow)) :
    CC.Step2 world (.State Arm64Nop.handler modifiedCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_modified)
        (arguments b ofs source narrow) (.Kcall (some Arm64Program._t'108) Arm64Nop.handler e le k) m) := by
  rw [call_source]
  apply CC.Step.call (tyargs := parameterTypes) (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · exact target_type
  · apply CC.doEvalExpr_sound
    simp only [target, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    exact args_eval world e le m b ofs source narrow entry src aux effective
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact function_type

set_option hygiene false in
/-- Execute the original loop/sequence prefix and all five real argument casts
at AUX256, for W/X and arbitrary incoming caller state and memory. -/
theorem enter_bound (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (source : BitVec 64) (narrow : Bool)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_modified = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_modified))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow)) :
    InternalRun world 5 (.State Arm64Nop.handler Operands.rhs k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_modified)
        (arguments b ofs source narrow) (callCont k e le) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [rhs_source, body, CC.doStep] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic|
      exact InternalRun.step trivial
        (call_step world block b ofs e le m _ source narrow binding unshadowed entry src aux effective)
        (InternalRun.refl _)))

namespace Linked
open Arm64ProgramEntryLinked (ge)

private theorem modified_binding : ∃ block,
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_modified = some block ∧
    CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_modified) := by
  refine ⟨(CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_modified).get (by decide +kernel), ?_, ?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

/-- The actual linked world supplies the real modified-helper definition. -/
theorem enter (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (source : BitVec 64) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow)) :
    InternalRun ge 5 (.State Arm64Nop.handler Operands.rhs k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_modified)
        (arguments b ofs source narrow) (callCont k e le) m) := by
  obtain ⟨block, binding⟩ := modified_binding
  exact enter_bound ge block b ofs e le m k source narrow binding unshadowed entry src aux effective

end Linked
end KProgFormal.ClightRefinement.Arm64Compare.RhsCall
