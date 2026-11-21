import KProgFormal.ClightRefinement.Arm64ProgramEntryMulCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCompareCall

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)

def arguments (b : CC.Block) : List CC.Val :=
  [.Vptr b 0, .Vint (23#32), .Vlong (4#64), .Vlong (1#64),
    .Vlong (255#64), .Vlong (255#64), .Vint (8#32), .Vint (256#32), .Vlong (0#64)]

def initialTemps (b : CC.Block) : CC.TempEnv :=
  (((((((((CC.createUndefTemps Arm64Nop.handler.fn_temps).set Arm64Program._entry (.Vptr b 0)).set
    Arm64Program._op (.Vint (23#32))).set Arm64Program._dst (.Vlong (4#64))).set
    Arm64Program._src (.Vlong (1#64))).set Arm64Program._src2 (.Vlong (255#64))).set
    Arm64Program._src3 (.Vlong (255#64))).set Arm64Program._flags (.Vint (8#32))).set
    Arm64Program._aux (.Vint (256#32))).set Arm64Program._imm (.Vlong (0#64))

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
      (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryMulCall.afterMul)) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original CMP-register caller sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_compare_caller (← Lean.Meta.mkAppM ``Parts.mk actual.getAppArgs)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_compare_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
def afterCompare : CC.Stmt := by run_tac cachePart (← `(parts.next))

/-- The next real source call after MUL, with its untouched successor. -/
theorem source : Arm64ProgramEntryMulCall.afterMul = .Ssequence call afterCompare := rfl

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original CMP-register call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_compare_target actual.getAppArgs[1]!

private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original CMP-register arguments changed"
    Lean.Elab.Tactic.closeMainGoal `actual_compare_arguments actual.getAppArgs[2]!

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

private def auxExpr : CC.Expr := by
  run_tac do
    let mut actual ← Lean.Elab.Term.elabTerm (← `(actualArgs)) none
    for _ in [:7] do
      actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual)
      unless actual.isAppOfArity ``List.cons 3 do throwError "actual AUX argument list changed"
      actual := actual.getAppArgs[2]!
    actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual)
    unless actual.isAppOfArity ``List.cons 3 do throwError "actual AUX argument absent"
    Lean.Elab.Tactic.closeMainGoal `actual_packed_aux actual.getAppArgs[1]!

private theorem aux_type : CC.typeof auxExpr = CC.tuint := rfl

/-- The original packed AUX expression retains modifier1 and shift0. -/
private theorem aux_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExpr world e le m auxExpr = some (.Vint (256#32)) := by
  simp +decide [auxExpr, CC.doEvalExpr, CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuint, CC.tint,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.shl, CC.Integers.Int.and, CC.Integers.Int.or,
    CC.Val.shl, CC.Val.and, CC.Val.or, CC.Integers.MI.shl, CC.Integers.MI.and, CC.Integers.MI.or]

private theorem args_source : actualArgs =
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
      (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
      (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
      .Econst_int (23#32) CC.tuint, .Econst_int (4#32) CC.tint,
      .Econst_int (1#32) CC.tint, .Econst_int (255#32) CC.tuint,
      .Econst_int (255#32) CC.tuint, .Econst_int (8#32) CC.tint,
      auxExpr, .Econst_int (0#32) CC.tint] := rfl

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
    let raw := #[(← `(CC.Val.Vptr b 0)), (← `(CC.Val.Vint (23#32))),
      (← `(CC.Val.Vint (4#32))), (← `(CC.Val.Vint (1#32))), (← `(CC.Val.Vint (255#32))),
      (← `(CC.Val.Vint (255#32))), (← `(CC.Val.Vint (8#32))),
      (← `(CC.Val.Vint (256#32))), (← `(CC.Val.Vint (0#32)))]
    for i in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| refine eval_cons (v := $(raw[i]!)) ?_ ?_ ?_))
      if i == 0 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, header] <;> rfl))
      else if i == 7 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact aux_eval _ _ _))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
      if i == 7 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| rw [aux_type]; rfl))
      else
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
    (Arm64ProgramEntryAllocation.allocation initial).1 le (.Kseq afterCompare k)

/-- Execute the genuine original CMP-register call and all nine source argument casts. -/
theorem enter {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
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
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterCompare k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Nop.handler)
        (arguments entry.block)
        (callCont initial le k) m) := by
    apply CC.doStep_sound
    simp only [call_source, CC.doStep, target_type, target_eval, args_eval entry le m,
      funct, handler_type, ite_true, callCont]
  have sequence : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterCompare k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := by
    apply CC.doStep_sound
    simp only [CC.doStep, source]
  have selected : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterCompare k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := .step trivial sequence (.refl _)
  have invoked : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterCompare k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (arguments entry.block)
        (callCont initial le k) m) := .step trivial next (.refl _)
  exact selected.trans invoked

/-- The actual void-call continuation resumes the unchanged source successor. -/
theorem leave (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2 (.Returnstate .Vundef (callCont initial le k) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterCompare k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryCompareCall
