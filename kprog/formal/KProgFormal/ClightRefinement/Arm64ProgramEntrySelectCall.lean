import KProgFormal.ClightRefinement.Arm64ProgramEntryCompareCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntrySelectCall

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)

def arguments (b : CC.Block) : List CC.Val :=
  [.Vptr b 0, .Vint (28#32), .Vlong (5#64), .Vlong (1#64),
    .Vlong (2#64), .Vlong (255#64), .Vint (8#32), .Vint (0#32), .Vlong (0#64)]

def initialTemps (b : CC.Block) : CC.TempEnv :=
  (((((((((CC.createUndefTemps Arm64Nop.handler.fn_temps).set Arm64Program._entry (.Vptr b 0)).set
    Arm64Program._op (.Vint (28#32))).set Arm64Program._dst (.Vlong (5#64))).set
    Arm64Program._src (.Vlong (1#64))).set Arm64Program._src2 (.Vlong (2#64))).set
    Arm64Program._src3 (.Vlong (255#64))).set Arm64Program._flags (.Vint (8#32))).set
    Arm64Program._aux (.Vint (0#32))).set Arm64Program._imm (.Vlong (0#64))

/-- Bind all nine actual arguments and the complete original generic frame. -/
theorem entry_valid (before : CC.Mem) (b : CC.Block) :
    CC.FunctionEntry2 world Arm64Nop.handler (arguments b) before
      (Arm64Nop.allocation world before).1 (initialTemps b) (Arm64Nop.allocation world before).2 :=
  .intro Arm64NopDeclarations.vars_norepet Arm64NopDeclarations.params_norepet
    Arm64NopDeclarations.params_temps_disjoint (Arm64MovImmediate.allocated_bound world before) rfl

private structure Parts where
  call : CC.Stmt
  next : CC.Stmt

private def parts : Parts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCompareCall.afterCompare)) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original CSEL caller sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_select_caller (← Lean.Meta.mkAppM ``Parts.mk actual.getAppArgs)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_select_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
def afterSelect : CC.Stmt := by run_tac cachePart (← `(parts.next))

/-- The next real source call after CMP, with its untouched successor. -/
theorem source : Arm64ProgramEntryCompareCall.afterCompare = .Ssequence call afterSelect := rfl

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original CSEL call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_select_target actual.getAppArgs[1]!

private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original CSEL arguments changed"
    Lean.Elab.Tactic.closeMainGoal `actual_select_arguments actual.getAppArgs[2]!

private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),
    CC.tuint, CC.tulong, CC.tulong, CC.tulong, CC.tulong, CC.tuchar, CC.tuint, CC.tulong]

private theorem call_source : call = .Scall none target actualArgs := rfl
private theorem target_type : CC.Cop.classifyFun (CC.typeof target) =
    .f parameterTypes CC.tvoid CC.cc_default := rfl

private theorem execute_not_local : Arm64ProgramFixture._kprog_arm64_program_execute ∉
    CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel

private theorem target_eval (initial : CC.Mem) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 le m target =
      some (.Vptr Arm64ProgramEntryLinked.executeBlock 0) := by
  have absent : (Arm64ProgramEntryAllocation.allocation initial).1.get
      Arm64ProgramFixture._kprog_arm64_program_execute = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm)
      execute_not_local
  have symbol : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_execute =
      some Arm64ProgramEntryLinked.executeBlock := Arm64ProgramEntryLinked.execute_binding.1
  simp only [target, CC.doEvalExpr, CC.lvalOfVar, absent, symbol,
    CC.doDerefLoc, CC.accessMode, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]

private theorem args_source : actualArgs =
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
      (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
      (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
      .Econst_int (28#32) CC.tuint, .Econst_int (5#32) CC.tint,
      .Econst_int (1#32) CC.tint, .Econst_int (2#32) CC.tint,
      .Econst_int (255#32) CC.tint, .Econst_int (8#32) CC.tint,
      .Econst_int (0#32) CC.tuint, .Econst_int (0#32) CC.tint] := rfl

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist, head, cast, rest]

set_option hygiene false in
private theorem args_eval_bound (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (b : CC.Block)
    (header : e.get Arm64ProgramFixture.___a64_entry =
      some (b, .Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)) :
    CC.doEvalExprlist world e le m actualArgs parameterTypes = some (arguments b) := by
  simp only [args_source, parameterTypes, arguments]
  run_tac do
    let raw := #[(← `(CC.Val.Vptr b 0)), (← `(CC.Val.Vint (28#32))),
      (← `(CC.Val.Vint (5#32))), (← `(CC.Val.Vint (1#32))), (← `(CC.Val.Vint (2#32))),
      (← `(CC.Val.Vint (255#32))), (← `(CC.Val.Vint (8#32))),
      (← `(CC.Val.Vint (0#32))), (← `(CC.Val.Vint (0#32)))]
    for i in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| refine eval_cons (v := $(raw[i]!)) ?_ ?_ ?_))
      if i == 0 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, header] <;> rfl))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))

    Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))

set_option hygiene false in
private theorem args_eval {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExprlist world (Arm64ProgramEntryAllocation.allocation initial).1 le m actualArgs parameterTypes =
      some (arguments entry.block) := by
  have header : (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block, .Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  exact args_eval_bound _ le m entry.block header

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile
    (Arm64ProgramEntryAllocation.allocation initial).1 le (.Kseq afterSelect k)

/-- Execute the genuine original CSEL call and all nine source argument casts. -/
theorem enter {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (arguments entry.block)
        (callCont initial le k) m) := by
  have handler_type : CC.typeOfFundef (.Internal Arm64Nop.handler) =
      .Tfunction parameterTypes CC.tvoid CC.cc_default := rfl
  have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
  have funct : CC.Genv.findFunct world.genv_genv (.Vptr Arm64ProgramEntryLinked.executeBlock 0) =
      some (.Internal Arm64Nop.handler) := by
    have binding : CC.Genv.findFunctPtr world.genv_genv Arm64ProgramEntryLinked.executeBlock =
        some (.Internal Arm64Nop.handler) := Arm64ProgramEntryLinked.execute_binding.2
    simp only [CC.Genv.findFunct, zero, ite_true, binding]
  have next : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterSelect k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Nop.handler)
        (arguments entry.block)
        (callCont initial le k) m) := by
    apply CC.doStep_sound
    simp only [call_source, CC.doStep, target_type, target_eval, args_eval entry le m,
      funct, handler_type, ite_true, callCont]
  have sequence : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterSelect k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := by
    apply CC.doStep_sound
    simp only [CC.doStep, source]
  have selected : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterSelect k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := .step trivial sequence (.refl _)
  have invoked : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterSelect k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (arguments entry.block)
        (callCont initial le k) m) := .step trivial next (.refl _)
  exact selected.trans invoked

/-- The actual void-call continuation resumes the unchanged source successor. -/
theorem leave (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2 (.Returnstate .Vundef (callCont initial le k) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterSelect k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntrySelectCall
