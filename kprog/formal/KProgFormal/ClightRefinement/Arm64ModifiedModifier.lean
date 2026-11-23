import KProgFormal.ClightRefinement.Arm64ModifiedPrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.Modifier
open Read (handler modify)
open Arm64Compare.RhsCall (width)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_modifier_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private structure ModParts where
  input : CC.Stmt
  kind : CC.Stmt
  shift : CC.Stmt
  mask : CC.Stmt
  amount : CC.Stmt
  switch : CC.Stmt
  output : CC.Stmt

private def modParts : ModParts := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual modifier sequence changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(modify)) none) ``CC.Stmt.Sloop 2
    let input ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let kind ← peel input[1]! ``CC.Stmt.Ssequence 2
    let shift ← peel kind[1]! ``CC.Stmt.Ssequence 2
    let rest ← peel shift[1]! ``CC.Stmt.Ssequence 2
    let mask ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel rest[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_mod_parts (← Lean.Meta.mkAppM ``ModParts.mk
      #[input[0]!, kind[0]!, shift[0]!, mask[0]!, mask[1]!, tail[0]!, tail[1]!])

private def modInput : CC.Stmt := by run_tac cachePart (← `(modParts.input))
private def modKind : CC.Stmt := by run_tac cachePart (← `(modParts.kind))
private def modShift : CC.Stmt := by run_tac cachePart (← `(modParts.shift))
private def modMask : CC.Stmt := by run_tac cachePart (← `(modParts.mask))
private def modAmount : CC.Stmt := by run_tac cachePart (← `(modParts.amount))
private def modSwitch : CC.Stmt := by run_tac cachePart (← `(modParts.switch))
private def modOutput : CC.Stmt := by run_tac cachePart (← `(modParts.output))
def body : CC.Stmt := .Ssequence modInput (.Ssequence modKind (.Ssequence modShift
    (.Ssequence (.Ssequence modMask modAmount) (.Ssequence modSwitch modOutput))))

/-- Exact original standalone modifier loop and all its pending code. -/
theorem modify_source : modify = .Sloop body .Sbreak := rfl

private def switchExpr : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modSwitch)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual modifier switch changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_expr actual.getAppArgs[0]!
private def switchCases : CC.LStmts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modSwitch)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_mod_cases actual.getAppArgs[1]!
private theorem switch_source : modSwitch = .Sswitch switchExpr switchCases := rfl

private def caseOne : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases))) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual case1 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_case actual.getAppArgs[0]!

@[irreducible] private def deadCases : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases))) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual case1 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_dead_cases actual.getAppArgs[1]!
private theorem case_one : CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases) =
    .Ssequence caseOne deadCases := by
  unfold caseOne deadCases
  rfl

private def valueExpr : CC.Expr := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual LSL0 case changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(caseOne)) none) ``CC.Stmt.Ssequence 2
    let body ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let update ← peel body[1]! ``CC.Stmt.Sset 2
    Lean.Elab.Tactic.closeMainGoal `actual_lsl0_expression update[1]!

private def caseMask : CC.Stmt := by
  run_tac do
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(caseOne)) none))
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[0]!)
    Lean.Elab.Tactic.closeMainGoal `actual_lsl0_mask body.getAppArgs[0]!

private theorem case_shape : caseOne = .Ssequence
    (.Ssequence caseMask (.Sset Arm64Program.___kprog_a64_mod_value valueExpr)) .Sbreak := rfl

def amountMask (narrow : Bool) : BitVec 32 := if narrow then 31 else 63
def mask (narrow : Bool) : BitVec 64 := if narrow then 4294967295 else BitVec.ofInt 64 (-1)
def result (value : BitVec 64) (narrow : Bool) : BitVec 64 := value &&& mask narrow

theorem result_wide (value : BitVec 64) : result value false = value := by
  have all : BitVec.ofInt 64 (-1) = BitVec.allOnes 64 := by decide +kernel
  simp only [result, mask, Bool.false_eq_true, ite_false, all, BitVec.and_allOnes]

private theorem shift_zero (world : CC.CGenv) (m : CC.Mem) (rhs : BitVec 64) :
    CC.Cop.semBinaryOperation world.genv_cenv .Oshl (.Vlong rhs) CC.tulong (.Vint (0#32)) CC.tuchar m =
      some (.Vlong rhs) := by
  change some (CC.Val.Vlong (rhs <<< 0)) = some (CC.Val.Vlong rhs)
  rw [BitVec.shiftLeft_zero]

private theorem mask_and (world : CC.CGenv) (m : CC.Mem) (value bits : BitVec 64) :
    CC.Cop.semBinaryOperation world.genv_cenv .Oand (.Vlong value) CC.tulong
      (.Vlong bits) CC.tulong m = some (.Vlong (value &&& bits)) := rfl

private theorem value_eval (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (value : BitVec 64) (narrow : Bool)
    (hv : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong value))
    (ha : le.get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)))
    (hm : le.get Arm64Program._t'6 = some (.Vlong (mask narrow))) :
    CC.doEvalExpr world e le m valueExpr = some (.Vlong (result value narrow)) := by
  simp only [valueExpr, CC.doEvalExpr, hv, ha, hm, CC.typeof, shift_zero, mask_and, result]

private theorem value_step {world : CC.CGenv} {e : CC.Env} {le : CC.TempEnv}
    {m : CC.Mem} {k : CC.Cont} (value : BitVec 64) (narrow : Bool)
    (hv : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong value))
    (ha : le.get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)))
    (hm : le.get Arm64Program._t'6 = some (.Vlong (mask narrow))) :
    CC.Step2 world (.State handler (.Sset Arm64Program.___kprog_a64_mod_value valueExpr) k e le m)
      CC.E0 (.State handler .Sskip k e (le.set Arm64Program.___kprog_a64_mod_value (.Vlong (result value narrow))) m) := by
  apply CC.Step.set
  apply CC.doEvalExpr_sound
  exact value_eval world e le m value narrow hv ha hm

def prefixTemps (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) : CC.TempEnv :=
  ((((le.set Arm64Program.___kprog_a64_mod_value (.Vlong value)).set
    Arm64Program.___kprog_a64_mod (.Vint (1#32))).set Arm64Program.___kprog_a64_mod_shift (.Vint (0#32))).set
    Arm64Program._t'5 (.Vint (amountMask narrow))).set Arm64Program.___kprog_a64_mod_amount (.Vint (0#32))
def readyTemps (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) : CC.TempEnv :=
  (((prefixTemps le narrow value).set Arm64Program._t'6 (.Vlong (mask narrow))).set
    Arm64Program._t'6 (.Vlong (mask narrow))).set Arm64Program._t'6 (.Vlong (mask narrow))
def maskTemps (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) : CC.TempEnv :=
  (readyTemps le narrow value).set Arm64Program.___kprog_a64_mod_value (.Vlong (result value narrow))
def finalTemps (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) : CC.TempEnv :=
  (maskTemps le narrow value).set Arm64Program._result (.Vlong (result value narrow))
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

private theorem ready_reads (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) :
    (readyTemps le narrow value).get Arm64Program.___kprog_a64_mod_value = some (.Vlong value) ∧
    (readyTemps le narrow value).get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)) ∧
    (readyTemps le narrow value).get Arm64Program._t'6 = some (.Vlong (mask narrow)) := by
  dsimp only [readyTemps, prefixTemps]
  refine ⟨?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

set_option hygiene false in
private theorem modifier_prefix (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) (narrow : Bool)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint (1#32)))
    (hshift : le.get Arm64Program._shift = some (.Vint (0#32)))
    (hwidth : le.get Arm64Program._width = some (width narrow)) :
    InternalRun world 18 (.State handler modify k e le m)
      (.State handler modSwitch (.Kseq modOutput (continuation k)) e (prefixTemps le narrow value) m) := by
  cases narrow <;>
  run_tac do
    for i in [:18] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [continuation, body, modInput, modKind, modShift, modMask, modAmount, modOutput, modify_source, prefixTemps, readyTemps, maskTemps, finalTemps, amountMask, mask, result, width, Arm64Compare.Dispatch.flags, Arm64Width.argument, case_shape, caseMask, Arm64Program.s_kprog_arm64_program_modified_5, Arm64Program.s_kprog_arm64_program_modified_6, Arm64Program.s_kprog_arm64_program_modified_7, CC.doStep, hinput, hkind, hshift, hwidth, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof,

        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem case_enter (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) (narrow : Bool) :
    CC.Step2 world
      (.State handler modSwitch (.Kseq modOutput (continuation k)) e (prefixTemps le narrow value) m) CC.E0
      (.State handler (.Ssequence caseOne deadCases) (.Kswitch (.Kseq modOutput (continuation k)))
        e (prefixTemps le narrow value) m) := by
  rw [switch_source, ← case_one]
  apply CC.Step.switch (v := .Vint (1#32)) (n := 1)
  · apply CC.doEvalExpr_sound
    simp +decide only [switchExpr, CC.doEvalExpr, prefixTemps, CC.PTree.gss, CC.PTree.gso]
  · rfl

set_option hygiene false in
private theorem case_tail (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) (narrow : Bool)
    (hwidth : le.get Arm64Program._width = some (width narrow)) :
    InternalRun world 19 (.State handler (.Ssequence caseOne deadCases)
        (.Kswitch (.Kseq modOutput (continuation k))) e (prefixTemps le narrow value) m)
      (.State handler modOutput (continuation k) e (maskTemps le narrow value) m) := by
  cases narrow with
  | false =>
    run_tac do
      for i in [:19] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        if i == 14 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact value_step value false
            (ready_reads le false value).1 (ready_reads le false value).2.1
            (ready_reads le false value).2.2))
        else
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [continuation, body, modInput, modKind, modShift, modMask, modAmount, modOutput, modify_source, prefixTemps, readyTemps, maskTemps, finalTemps, amountMask, mask, result, width, Arm64Compare.Dispatch.flags, Arm64Width.argument, case_shape, caseMask, Arm64Program.s_kprog_arm64_program_modified_5, Arm64Program.s_kprog_arm64_program_modified_6, Arm64Program.s_kprog_arm64_program_modified_7, CC.doStep, hwidth, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
          CC.doEvalExpr, CC.typeof,

          CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
          CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
      CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
          CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
          CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
          CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
          CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
          CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
          CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
          CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
          CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
          CC.Integers.MI.zero, CC.Integers.MI.one,
          BitVec.shiftLeft_zero, BitVec.and_allOnes,
          CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

  | true =>
    run_tac do
      for i in [:19] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        if i == 14 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact value_step value true
            (ready_reads le true value).1 (ready_reads le true value).2.1
            (ready_reads le true value).2.2))
        else
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [continuation, body, modInput, modKind, modShift, modMask, modAmount, modOutput, modify_source, prefixTemps, readyTemps, maskTemps, finalTemps, amountMask, mask, result, width, Arm64Compare.Dispatch.flags, Arm64Width.argument, case_shape, caseMask, Arm64Program.s_kprog_arm64_program_modified_5, Arm64Program.s_kprog_arm64_program_modified_6, Arm64Program.s_kprog_arm64_program_modified_7, CC.doStep, hwidth, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
          CC.doEvalExpr, CC.typeof,

          CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
          CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
      CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
          CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
          CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
          CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
          CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
          CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
          CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
          CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
          CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
          CC.Integers.MI.zero, CC.Integers.MI.one,
          BitVec.shiftLeft_zero, BitVec.and_allOnes,
          CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem modifier_exit (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) (narrow : Bool) :
    InternalRun world 3 (.State handler modOutput (continuation k) e (maskTemps le narrow value) m)
      (.State handler .Sskip k e (finalTemps le narrow value) m) := by
  run_tac do
    for i in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [continuation, body, modInput, modKind, modShift, modMask, modAmount, modOutput, modify_source, prefixTemps, readyTemps, maskTemps, finalTemps, amountMask, mask, result, width, Arm64Compare.Dispatch.flags, Arm64Width.argument, case_shape, caseMask, Arm64Program.s_kprog_arm64_program_modified_5, Arm64Program.s_kprog_arm64_program_modified_6, Arm64Program.s_kprog_arm64_program_modified_7, CC.doStep, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof,

        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Execute the actual standalone LSL0 loop for W/X, retaining both source
width masks, exact temporary writes, the whole heap and original caller k. -/
theorem execute_lsl_zero (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) (narrow : Bool)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint (1#32)))
    (hshift : le.get Arm64Program._shift = some (.Vint (0#32)))
    (hwidth : le.get Arm64Program._width = some (width narrow)) :
    InternalRun world 41 (.State handler modify k e le m)
      (.State handler .Sskip k e (finalTemps le narrow value) m) := by
  exact ((modifier_prefix world e le m k value narrow hinput hkind hshift hwidth).trans
    (InternalRun.step trivial (case_enter world e le m k value narrow)
      (case_tail world e le m k value narrow hwidth))).trans
    (modifier_exit world e le m k value narrow)


private def prefixTempsOne (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((((le.set Arm64Program.___kprog_a64_mod_value (.Vlong value)).set
    Arm64Program.___kprog_a64_mod (.Vint (1#32))).set Arm64Program.___kprog_a64_mod_shift (.Vint (1#32))).set
    Arm64Program._t'5 (.Vint (31#32))).set Arm64Program.___kprog_a64_mod_amount (.Vint (1#32))
private def readyTempsOne (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (((prefixTempsOne le value).set Arm64Program._t'6 (.Vlong (4294967295#64))).set
    Arm64Program._t'6 (.Vlong (4294967295#64))).set Arm64Program._t'6 (.Vlong (4294967295#64))
private def maskTempsOne (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (readyTempsOne le value).set Arm64Program.___kprog_a64_mod_value (.Vlong ((value <<< 1) &&& (4294967295#64)))
private def finalTempsOne (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (maskTempsOne le value).set Arm64Program._result (.Vlong ((value <<< 1) &&& (4294967295#64)))

private theorem ready_one_reads (le : CC.TempEnv) (value : BitVec 64) :
    (readyTempsOne le value).get Arm64Program.___kprog_a64_mod_value = some (.Vlong value) ∧
    (readyTempsOne le value).get Arm64Program.___kprog_a64_mod_amount = some (.Vint (1#32)) ∧
    (readyTempsOne le value).get Arm64Program._t'6 = some (.Vlong (4294967295#64)) := by
  dsimp only [readyTempsOne, prefixTempsOne]
  refine ⟨?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

private theorem shift_one (world : CC.CGenv) (m : CC.Mem) (value : BitVec 64) :
    CC.Cop.semBinaryOperation world.genv_cenv .Oshl (.Vlong value) CC.tulong
      (.Vint (1#32)) CC.tuchar m = some (.Vlong (value <<< 1)) := rfl

private theorem value_step_one {world : CC.CGenv} {e : CC.Env} {le : CC.TempEnv}
    {m : CC.Mem} {k : CC.Cont} (value : BitVec 64)
    (hv : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong value))
    (ha : le.get Arm64Program.___kprog_a64_mod_amount = some (.Vint (1#32)))
    (hm : le.get Arm64Program._t'6 = some (.Vlong (4294967295#64))) :
    CC.Step2 world (.State handler (.Sset Arm64Program.___kprog_a64_mod_value valueExpr) k e le m)
      CC.E0 (.State handler .Sskip k e (le.set Arm64Program.___kprog_a64_mod_value
        (.Vlong ((value <<< 1) &&& (4294967295#64)))) m) := by
  apply CC.Step.set
  apply CC.doEvalExpr_sound
  simp only [valueExpr, CC.doEvalExpr, hv, ha, hm, CC.typeof, shift_one, mask_and]

private theorem case_enter_one (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) :
    CC.Step2 world
      (.State handler modSwitch (.Kseq modOutput (continuation k)) e (prefixTempsOne le value) m) CC.E0
      (.State handler (.Ssequence caseOne deadCases) (.Kswitch (.Kseq modOutput (continuation k)))
        e (prefixTempsOne le value) m) := by
  rw [switch_source, ← case_one]
  apply CC.Step.switch (v := .Vint (1#32)) (n := 1)
  · apply CC.doEvalExpr_sound
    simp +decide only [switchExpr, CC.doEvalExpr, prefixTempsOne, CC.PTree.gss, CC.PTree.gso]
  · rfl

set_option hygiene false in
private theorem run_lsl_one (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint (1#32)))
    (hshift : le.get Arm64Program._shift = some (.Vint (1#32)))
    (hwidth : le.get Arm64Program._width = some (width true)) :
    InternalRun world 41 (.State handler modify k e le m)
      (.State handler .Sskip k e (finalTempsOne le value) m) := by
  run_tac do
    for i in [:41] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 18 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact case_enter_one world e le m k value))
      else if i == 33 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact value_step_one value
          (ready_one_reads le value).1 (ready_one_reads le value).2.1 (ready_one_reads le value).2.2))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [continuation, body,
          modInput, modKind, modShift, modMask, modAmount, modOutput, modify_source,
          prefixTempsOne, readyTempsOne, maskTempsOne, finalTempsOne, width,
          Arm64Compare.Dispatch.flags, Arm64Width.argument, case_shape, caseMask,
          Arm64Program.s_kprog_arm64_program_modified_5, Arm64Program.s_kprog_arm64_program_modified_6,
          Arm64Program.s_kprog_arm64_program_modified_7, CC.doStep, hinput, hkind, hshift, hwidth,
          CC.setOpttemp, CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
          CC.Cop.semSwitchArg, CC.Cop.classifySwitch, CC.Cop.semBinaryOperation, CC.Cop.semAnd,
          CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
          CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
          CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
          CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong, CC.Val.ofBool,
          CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.and, CC.Integers.Int.cmpu, CC.Integers.Int.eq,
          CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.Int.repr, CC.Integers.Int64.repr,
          CC.Integers.Int.unsigned, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
          CC.Integers.MI.repr, CC.Integers.Int64.and, CC.Integers.MI.and, CC.Integers.MI.unsigned,
          CC.Integers.MI.cmpu, CC.Integers.MI.eq, CC.Integers.MI.zero, CC.Integers.MI.one,
          CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
          Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Execute the original width-four LSL1 modifier through its true output and
loop exit, deriving the returned word and preserving the complete heap/e/k. -/
theorem execute_lsl_one (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint (1#32)))
    (hshift : le.get Arm64Program._shift = some (.Vint (1#32)))
    (hwidth : le.get Arm64Program._width = some (width true)) :
    ∃ le', InternalRun world 41 (.State handler modify k e le m)
      (.State handler .Sskip k e le' m) ∧
      le'.get Arm64Program._result = some (.Vlong ((value <<< 1) &&& (4294967295#64))) :=
  ⟨finalTempsOne le value, run_lsl_one world e le m k value hinput hkind hshift hwidth,
    by simp only [finalTempsOne, CC.PTree.gss]⟩

end KProgFormal.ClightRefinement.Arm64Modified.Modifier
