import KProgFormal.ClightRefinement.Arm64MovImmediate

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.Dispatch

open Arm64NumericProgram

private structure Pieces where
  widthCall : CC.Stmt
  widthSet : CC.Stmt
  nopTest : CC.Expr
  adrpTest : CC.Stmt
  adrpCondition : CC.Expr
  adrpBranch : CC.Stmt
  movTest : CC.Stmt
  movCondition : CC.Expr
  selectorCall : CC.Stmt
  pointerTest : CC.Expr
  pointerBranch : CC.Stmt
  scalarBranch : CC.Stmt
  following : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual MOV dispatch shape changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let nop ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    let adrp ← peel nop[2]! ``CC.Stmt.Ssequence 2
    let adrpGate ← peel adrp[1]! ``CC.Stmt.Sifthenelse 3
    let mov ← peel adrpGate[2]! ``CC.Stmt.Ssequence 2
    let movGate ← peel mov[1]! ``CC.Stmt.Sifthenelse 3
    let call ← peel movGate[1]! ``CC.Stmt.Ssequence 2
    let pointer ← peel call[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_mov_dispatch (← Lean.Meta.mkAppM ``Pieces.mk
      #[width[0]!, width[1]!, nop[0]!, adrp[0]!, adrpGate[0]!, adrpGate[1]!,
        mov[0]!, movGate[0]!, call[0]!, pointer[0]!, pointer[1]!, pointer[2]!, movGate[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  Lean.Elab.Tactic.closeMainGoal `actual_mov_part actual

private def widthCall : CC.Stmt := by
  run_tac cachePart (← `(pieces.widthCall))
private def widthSet : CC.Stmt := by
  run_tac cachePart (← `(pieces.widthSet))
private def nopTest : CC.Expr := by
  run_tac cachePart (← `(pieces.nopTest))
private def adrpTest : CC.Stmt := by
  run_tac cachePart (← `(pieces.adrpTest))
private def adrpCondition : CC.Expr := by
  run_tac cachePart (← `(pieces.adrpCondition))
private def adrpBranch : CC.Stmt := by
  run_tac cachePart (← `(pieces.adrpBranch))
private def movTest : CC.Stmt := by
  run_tac cachePart (← `(pieces.movTest))
private def movCondition : CC.Expr := by
  run_tac cachePart (← `(pieces.movCondition))
private def selectorCall : CC.Stmt := by
  run_tac cachePart (← `(pieces.selectorCall))
private def pointerTest : CC.Expr := by
  run_tac cachePart (← `(pieces.pointerTest))
private def pointerBranch : CC.Stmt := by
  run_tac cachePart (← `(pieces.pointerBranch))
def scalarBranch : CC.Stmt := by
  run_tac cachePart (← `(pieces.scalarBranch))
private def following : CC.Stmt := by
  run_tac cachePart (← `(pieces.following))

private def pointerGate : CC.Stmt := .Sifthenelse pointerTest pointerBranch scalarBranch
private def movSequence : CC.Stmt := .Ssequence movTest
  (.Sifthenelse movCondition (.Ssequence selectorCall pointerGate) following)
private def adrpSequence : CC.Stmt := .Ssequence adrpTest
  (.Sifthenelse adrpCondition adrpBranch movSequence)
private def nopGate : CC.Stmt := .Sifthenelse nopTest .Sskip adrpSequence

def body : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) nopGate

theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation : CC.Cont := .Kloop1 body .Sbreak .Kstop
private def widthCont : CC.Cont := .Kseq widthSet (.Kseq nopGate continuation)
private def selectorCont : CC.Cont := .Kseq pointerGate continuation

def flags (narrow : Bool) : BitVec 8 := if narrow then 4 else 8
private def widthWord (narrow : Bool) : BitVec 64 := if narrow then 4 else 8

def dispatchEnv (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  ((Arm64Nop.resultEnv le (flags narrow)).set Arm64Program._t'2827 (.Vint 0)).set
    Arm64Program._t'2826 (.Vint 1)

def scalarEnv (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  (dispatchEnv le narrow).set Arm64Program._t'5 (.Vlong 0)

private theorem enter_width_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow))) :
    InternalRun world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (flags narrow)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m) := by
  have execution : steps world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m) =
      some (CC.E0, .Callstate (.Internal Arm64Program.f_arm64_width_effective)
        [Arm64Width.argument (flags narrow)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m) ∧
      InternalPath world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m) := by
    simp [body_source, body, widthCall, widthCont, continuation, steps, InternalPath, InternalState,
      CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.Cop.classifyFun, CC.typeof,
      CC.lvalOfVar, unshadowed, widthBinding.1, CC.doDerefLoc,
      CC.accessMode, CC.Genv.findFunct, widthBinding.2, hflags,
      Arm64Width.cast_argument, CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams,
      CC.Integers.MI.zero, Arm64Program.f_arm64_width_effective, CC.E0, CC.Eapp,
      CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq]
  exact internalRun_of_steps execution.2 execution.1

private theorem enter_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow))) :
    InternalRun ge 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (flags narrow)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m) :=
  enter_width_bound ge (CC.Positive.ofNat 66) width_binding e le m narrow unshadowed hflags

set_option hygiene false in
private theorem after_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_mov_path = none)
    (hop : le.get Arm64Program._op = some (.Vint 1)) :
    InternalRun ge 17
      (.Returnstate (Arm64Width.result (flags narrow))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_mov_path)
        [.Vlong 1, .Vlong (widthWord narrow)]
        (.Kcall (some Arm64Program._t'5) Arm64Nop.handler e (dispatchEnv le narrow) selectorCont) m) := by
  cases narrow <;>
    run_tac do
      for _ in [:17] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic|
          first | rfl | simp +decide [CC.doStep, CC.setOpttemp, widthCont, selectorCont, continuation,
            widthSet, nopGate, nopTest, adrpSequence, adrpTest, adrpCondition,
            movSequence, movTest, movCondition, selectorCall, flags, widthWord, dispatchEnv,
            Arm64Nop.resultEnv, Arm64Width.result, Arm64Width.argument, CC.PTree.gss, CC.PTree.gso,
            hop, CC.doEvalExpr, CC.doEvalExprlist, CC.typeof, CC.Cop.classifyFun,
            CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Genv.findFunct,
            unshadowed, selector_binding.1, selector_binding.2,
            CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams, Arm64Numeric.f_kprog_arm64_mov_path,
            CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
            CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
            CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
            CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
            CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
            CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
            CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
            CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
            CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one,
            CC.Integers.MI.zero, CC.Integers.MI.one, CC.Eapp, CC.E0,
            CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem after_selector (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool) :
    InternalRun ge 3
      (.Returnstate (.Vlong 0)
        (.Kcall (some Arm64Program._t'5) Arm64Nop.handler e (dispatchEnv le narrow) selectorCont) m)
      (.State Arm64Nop.handler scalarBranch continuation e (scalarEnv le narrow) m) := by
  have execution : steps ge 3
      (.Returnstate (.Vlong 0)
        (.Kcall (some Arm64Program._t'5) Arm64Nop.handler e (dispatchEnv le narrow) selectorCont) m) =
      some (CC.E0, .State Arm64Nop.handler scalarBranch continuation e (scalarEnv le narrow) m) ∧
      InternalPath ge 3 (.Returnstate (.Vlong 0)
        (.Kcall (some Arm64Program._t'5) Arm64Nop.handler e (dispatchEnv le narrow) selectorCont) m) := by
    simp [steps, InternalPath, InternalState, CC.doStep, CC.setOpttemp, selectorCont, scalarEnv,
      pointerGate, pointerTest, CC.doEvalExpr, CC.PTree.gss, CC.typeof,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tulong, CC.Integers.Int64.eq, CC.Integers.MI.eq,
      CC.Integers.Int64.zero, CC.Integers.MI.zero, CC.E0, CC.Eapp]
  exact internalRun_of_steps execution.2 execution.1

/-- Execute the actual generic handler through width calculation, NOP/ADRP/MOV
selection, the real Numeric selector call and its scalar-branch decision.
The eager SRC read is the next statement, not silently skipped. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (widthUnshadowed : e.get Arm64Program._arm64_width_effective = none)
    (selectorUnshadowed : e.get Arm64Program._kprog_arm64_mov_path = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (hop : le.get Arm64Program._op = some (.Vint 1)) :
    InternalRun ge 53 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m)
      (.State Arm64Nop.handler scalarBranch continuation e (scalarEnv le narrow) m) := by
  have enter := enter_width e le m narrow widthUnshadowed hflags
  have width := Arm64Width.internal ge (flags narrow)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m
  have choose := after_width e le m narrow selectorUnshadowed hop
  have selector := selector_internal ge (widthWord narrow) m
    (.Kcall (some Arm64Program._t'5) Arm64Nop.handler e (dispatchEnv le narrow) selectorCont)
  have finish := after_selector e le m narrow
  simpa only [CC.callCont] using (((enter.trans width).trans choose).trans selector).trans finish

/-- Actual nine-argument procedure boundary; only op/width are inspected in
this prefix, and the other incoming Clight values remain unrestricted. -/
def arguments (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) : List CC.Val :=
  [ignored.entry, .Vint 1, ignored.dst, ignored.src, ignored.src2, ignored.src3,
    Arm64Width.argument (flags narrow), ignored.aux, ignored.imm]

def initialTemps (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) : CC.TempEnv :=
  (((((((((CC.createUndefTemps Arm64Nop.handler.fn_temps).set
    Arm64Program._entry ignored.entry).set Arm64Program._op (.Vint 1)).set
    Arm64Program._dst ignored.dst).set Arm64Program._src ignored.src).set
    Arm64Program._src2 ignored.src2).set Arm64Program._src3 ignored.src3).set
    Arm64Program._flags (Arm64Width.argument (flags narrow))).set
    Arm64Program._aux ignored.aux).set Arm64Program._imm ignored.imm

private theorem enter (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    CC.FunctionEntry2 ge Arm64Nop.handler (arguments ignored narrow) m
      (Arm64Nop.allocation ge m).1 (initialTemps ignored narrow) (Arm64Nop.allocation ge m).2 :=
  .intro Arm64NopDeclarations.vars_norepet Arm64NopDeclarations.params_norepet
    Arm64NopDeclarations.params_temps_disjoint
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Nop.allocation ge m)).symm) rfl

private theorem selector_not_local :
    Arm64Program._kprog_arm64_mov_path ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem selector_unshadowed (m : CC.Mem) :
    (Arm64Nop.allocation ge m).1.get Arm64Program._kprog_arm64_mov_path = none := by
  simpa only [CC.emptyEnv, CC.PTree.gempty] using
    CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Nop.allocation ge m)).symm)
      selector_not_local

private theorem flags_temp (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    (initialTemps ignored narrow).get Arm64Program._flags =
      some (Arm64Width.argument (flags narrow)) := by
  simp +decide only [initialTemps, CC.PTree.gss, CC.PTree.gso]

private theorem op_temp (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    (initialTemps ignored narrow).get Arm64Program._op = some (.Vint 1) := by
  simp +decide only [initialTemps, CC.PTree.gss, CC.PTree.gso]

/-- Start from the actual generic Callstate, allocate all its real locals
once, and reach the genuine scalar branch in 54 internal transitions. Both
helper names are proved unshadowed by that allocation. Only the real fresh
frame is allocated; caller bytes and both permission maps remain exact. -/
theorem call_dispatch (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    InternalRun ge 54
      (.Callstate (.Internal Arm64Nop.handler) (arguments ignored narrow) .Kstop m)
      (.State Arm64Nop.handler scalarBranch continuation (Arm64Nop.allocation ge m).1
        (scalarEnv (initialTemps ignored narrow) narrow) (Arm64Nop.allocation ge m).2) ∧
      FrameBelow m.nextblock m (Arm64Nop.allocation ge m).2 := by
  have first : InternalRun ge 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments ignored narrow) .Kstop m)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop (Arm64Nop.allocation ge m).1
        (initialTemps ignored narrow) (Arm64Nop.allocation ge m).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (enter m ignored narrow)) (.refl _)
  have dispatch := body_dispatch (Arm64Nop.allocation ge m).1 (initialTemps ignored narrow)
    (Arm64Nop.allocation ge m).2 narrow (Arm64Nop.entry_unshadowed ge m) (selector_unshadowed m)
    (flags_temp ignored narrow) (op_temp ignored narrow)
  exact ⟨first.trans dispatch, Arm64Nop.entry_frame ge m⟩

namespace Keep

private def cacheFollowing (index : Nat) : Lean.Elab.Tactic.TacticM Unit := do
  let actual ← Lean.Meta.withTransparency .all
    (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(following)) none))
  unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
    throwError "actual MOVK gate changed"
  Lean.Elab.Tactic.closeMainGoal `actual_movk_gate actual.getAppArgs[index]!

private def test : CC.Expr := by run_tac cacheFollowing 0
/-- The actual opcode-5 branch, including destination read and merge. -/
def branch : CC.Stmt := by run_tac cacheFollowing 1
private def alternative : CC.Stmt := by run_tac cacheFollowing 2
private theorem following_source : following = .Sifthenelse test branch alternative := rfl

def temps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  ((Arm64Nop.resultEnv le (flags narrow)).set Arm64Program._t'2827 (.Vint 0)).set
    Arm64Program._t'2826 (.Vint 0)

set_option hygiene false in
private theorem after_width (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (hop : le.get Arm64Program._op = some (.Vint 5)) :
    InternalRun world 16
      (.Returnstate (Arm64Width.result (flags narrow))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m)
      (.State Arm64Nop.handler branch continuation e (temps le narrow) m) := by
  cases narrow <;>
    run_tac do
      for _ in [:16] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic|
          first | rfl | simp +decide [CC.doStep, CC.setOpttemp, widthCont, continuation,
            widthSet, nopGate, nopTest, adrpSequence, adrpTest, adrpCondition,
            movSequence, movTest, movCondition, flags, widthWord, temps, following_source, test,
            Arm64Nop.resultEnv, Arm64Width.result, Arm64Width.argument, CC.PTree.gss, CC.PTree.gso,
            hop, CC.doEvalExpr, CC.doEvalExprlist, CC.typeof, CC.Cop.classifyFun,
            CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Genv.findFunct,

            CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams, Arm64Numeric.f_kprog_arm64_mov_path,
            CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
            CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
            CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
            CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
            CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
            CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
            CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
            CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
            CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one,
            CC.Integers.MI.zero, CC.Integers.MI.one, CC.Eapp, CC.E0,
            CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- MOVK bypasses the MOV selector and reaches its own branch in 26 body
transitions, retaining the real width call and all actual control decisions. -/
theorem body_dispatch_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (widthUnshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (hop : le.get Arm64Program._op = some (.Vint 5)) :
    InternalRun world 26 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m)
      (.State Arm64Nop.handler branch continuation e (temps le narrow) m) := by
  have enter := enter_width_bound world widthBlock widthBinding e le m narrow widthUnshadowed hflags
  have width := Arm64Width.internal world (flags narrow)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le widthCont) m
  have choose := after_width world e le m narrow hop
  simpa only [CC.callCont] using (enter.trans width).trans choose

theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (narrow : Bool)
    (widthUnshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (hop : le.get Arm64Program._op = some (.Vint 5)) :
    InternalRun ge 26 (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop e le m)
      (.State Arm64Nop.handler branch continuation e (temps le narrow) m) :=
  body_dispatch_bound ge (CC.Positive.ofNat 66) width_binding e le m narrow widthUnshadowed hflags hop

def arguments (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) : List CC.Val :=
  [ignored.entry, .Vint 5, ignored.dst, ignored.src, ignored.src2, ignored.src3,
    Arm64Width.argument (flags narrow), ignored.aux, ignored.imm]

def initialTemps (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) : CC.TempEnv :=
  (((((((((CC.createUndefTemps Arm64Nop.handler.fn_temps).set
    Arm64Program._entry ignored.entry).set Arm64Program._op (.Vint 5)).set
    Arm64Program._dst ignored.dst).set Arm64Program._src ignored.src).set
    Arm64Program._src2 ignored.src2).set Arm64Program._src3 ignored.src3).set
    Arm64Program._flags (Arm64Width.argument (flags narrow))).set
    Arm64Program._aux ignored.aux).set Arm64Program._imm ignored.imm

private theorem enter (world : CC.CGenv) (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    CC.FunctionEntry2 world Arm64Nop.handler (arguments ignored narrow) m
      (Arm64Nop.allocation world m).1 (initialTemps ignored narrow) (Arm64Nop.allocation world m).2 :=
  .intro Arm64NopDeclarations.vars_norepet Arm64NopDeclarations.params_norepet
    Arm64NopDeclarations.params_temps_disjoint
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Nop.allocation world m)).symm) rfl

/-- Start at the real nine-argument opcode-5 call and allocate its actual
locals once. The caller frontier is preserved through this 27-step prefix. -/
theorem call_dispatch_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    InternalRun world 27
      (.Callstate (.Internal Arm64Nop.handler) (arguments ignored narrow) .Kstop m)
      (.State Arm64Nop.handler branch continuation (Arm64Nop.allocation world m).1
        (temps (initialTemps ignored narrow) narrow) (Arm64Nop.allocation world m).2) ∧
      FrameBelow m.nextblock m (Arm64Nop.allocation world m).2 := by
  have first : InternalRun world 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments ignored narrow) .Kstop m)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body .Kstop (Arm64Nop.allocation world m).1
        (initialTemps ignored narrow) (Arm64Nop.allocation world m).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (enter world m ignored narrow)) (.refl _)
  have hflags : (initialTemps ignored narrow).get Arm64Program._flags =
      some (Arm64Width.argument (flags narrow)) := by
    simp +decide only [initialTemps, CC.PTree.gss, CC.PTree.gso]
  have hop : (initialTemps ignored narrow).get Arm64Program._op = some (.Vint 5) := by
    simp +decide only [initialTemps, CC.PTree.gss, CC.PTree.gso]
  have rest := body_dispatch_bound world widthBlock widthBinding (Arm64Nop.allocation world m).1 (initialTemps ignored narrow)
    (Arm64Nop.allocation world m).2 narrow (Arm64Nop.entry_unshadowed world m) hflags hop
  exact ⟨first.trans rest, Arm64Nop.entry_frame world m⟩

theorem call_dispatch (m : CC.Mem) (ignored : Arm64Nop.IgnoredArguments) (narrow : Bool) :
    InternalRun ge 27
      (.Callstate (.Internal Arm64Nop.handler) (arguments ignored narrow) .Kstop m)
      (.State Arm64Nop.handler branch continuation (Arm64Nop.allocation ge m).1
        (temps (initialTemps ignored narrow) narrow) (Arm64Nop.allocation ge m).2) ∧
      FrameBelow m.nextblock m (Arm64Nop.allocation ge m).2 :=
  call_dispatch_bound ge (CC.Positive.ofNat 66) width_binding m ignored narrow

end Keep

end KProgFormal.ClightRefinement.Arm64MovImmediate.Dispatch
