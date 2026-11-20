import KProgFormal.ClightRefinement.Arm64MovImmediateSuffix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovKeep

open Arm64NumericProgram
open Arm64MovImmediate

private structure Pieces where
  body : CC.Stmt
  readCall : CC.Stmt
  dstSet : CC.Stmt
  tail : CC.Stmt
  writeCall : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual MOVK scalar branch changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Dispatch.Keep.branch)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let read ← peel body[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_movk_parts (← Lean.Meta.mkAppM ``Pieces.mk
      #[loop[0]!, read[0]!, read[1]!, body[1]!, root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let actual ← Lean.Meta.withTransparency .all
    (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm source none))
  Lean.Elab.Tactic.closeMainGoal `actual_movk_part actual

private def body : CC.Stmt := by run_tac cachePart (← `(pieces.body))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))
private def dstSet : CC.Stmt := by run_tac cachePart (← `(pieces.dstSet))
private def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))
def writeCall : CC.Stmt := by run_tac cachePart (← `(pieces.writeCall))

theorem branch_source : Dispatch.Keep.branch = .Ssequence
    (.Sloop (.Ssequence (.Ssequence readCall dstSet) tail) .Sbreak) writeCall := rfl

def readCont : CC.Cont := .Kseq dstSet (.Kseq tail
  (.Kloop1 body .Sbreak (.Kseq writeCall Dispatch.continuation)))

def aux (column : Fin 4) : BitVec 32 := BitVec.ofNat 32 (16 * column.val * 65536)
def mask (column : Fin 4) : BitVec 64 := (65535#64) <<< (16 * column.val)
def mergeWord (old : BitVec 64) (imm : BitVec 64) (column : Fin 4) : BitVec 64 :=
  (old &&& ~~~(mask column)) ||| ((imm <<< (16 * column.val)) &&& mask column)

def writerTempsWord (le : CC.TempEnv) (old : BitVec 64) (imm : BitVec 64) (column : Fin 4) : CC.TempEnv :=
  ((((((le.set Arm64Program._t'6 (.Vlong old)).set
    Arm64Program.___kprog_a64_movk_dst (.Vlong old)).set
    Arm64Program.___kprog_a64_movk_imm (.Vlong imm)).set
    Arm64Program.___kprog_a64_movk_shift (.Vlong (BitVec.ofNat 64 (16 * column.val)))).set
    Arm64Program.___kprog_a64_movk_mask (.Vlong (mask column))).set
    Arm64Program.___kprog_a64_movk_result (.Vlong (mergeWord old imm column))).set
    Arm64Program.___a64_l_value__1 (.Vlong (mergeWord old imm column))

/-- The original immediate16 interfaces instantiate the full-word path. -/
def merge (old : BitVec 64) (imm : BitVec 16) (column : Fin 4) : BitVec 64 :=
  mergeWord old (imm.setWidth 64) column

def writerTemps (le : CC.TempEnv) (old : BitVec 64) (imm : BitVec 16) (column : Fin 4) : CC.TempEnv :=
  writerTempsWord le old (imm.setWidth 64) column

/-- Only the selected halfword contributes to the result; the actual caller
parameter and compiler immediate temporary remain full-width values. -/
theorem mergeWord_low16 (old imm : BitVec 64) (column : Fin 4) :
    mergeWord old imm column = merge old (imm.setWidth 16) column := by
  have low : imm &&& ((BitVec.allOnes 16).setWidth 64) = (imm.setWidth 16).setWidth 64 := by
    rw [BitVec.and_setWidth_allOnes 48 16, BitVec.setWidth_eq_append (v := 16) (w := 64) (by decide)]
    rfl
  change (old &&& ~~~((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val))) |||
      ((imm <<< (16 * column.val)) &&& ((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val))) =
    (old &&& ~~~((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val))) |||
      ((((imm.setWidth 16).setWidth 64) <<< (16 * column.val)) &&&
        ((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val)))
  rw [← BitVec.shiftLeft_and_distrib, low, ← BitVec.shiftLeft_and_distrib,
    ← BitVec.setWidth_and, BitVec.and_allOnes]

private theorem reader_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong]
      CC.tulong CC.cc_default := rfl

/-- The actual MOVK expression calls the combined reader on DST, not SRC. -/
theorem read_call_bound (world : CC.CGenv) (readerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some readerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv readerBlock = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry : CC.Block)
    (reg : BitVec 64) (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg)) :
    InternalRun world 5 (.State Arm64Nop.handler Dispatch.Keep.branch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong reg]
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m) := by
  have execution : steps world 5
      (.State Arm64Nop.handler Dispatch.Keep.branch Dispatch.continuation e le m) =
      some (CC.E0, .Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong reg]
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m) ∧
      InternalPath world 5 (.State Arm64Nop.handler Dispatch.Keep.branch Dispatch.continuation e le m) := by
    simp [branch_source, body, readCall, readCont, dstSet, tail, steps, InternalPath, InternalState,
      CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.typeof, CC.Cop.classifyFun,
      CC.lvalOfVar, unshadowed, binding.1, CC.doDerefLoc,
      CC.accessMode, CC.Genv.findFunct, binding.2, hentry, hdst,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.tptr, CC.tulong, CC.tvoid,
      reader_type, CC.E0, CC.Eapp, CC.Integers.MI.zero,
      CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq]
  exact internalRun_of_steps execution.2 execution.1

theorem read_call (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry : CC.Block)
    (reg : BitVec 64) (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg)) :
    InternalRun ge 5 (.State Arm64Nop.handler Dispatch.Keep.branch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong reg]
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m) :=
  read_call_bound ge (CC.Positive.ofNat 76) reader_binding e le m entry reg unshadowed hentry hdst

/-- The real zero-register read returns zero without touching any memory. -/
theorem read_zr (world : CC.CGenv) (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 55 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [entry, .Vlong 31] k m) (.Returnstate (.Vlong 0) (CC.callCont k) m) := by
  run_tac do
    for _ in [:55] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The source bit operation equals LNSym's public insertion operator. -/
theorem merge_eq_partInstall (old : BitVec 64) (imm : BitVec 16) (column : Fin 4) :
    merge old imm column = BitVec.partInstall (16 * column.val) 16 imm old := by
  change (old &&& ~~~((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val))) |||
      (((imm.setWidth 64) <<< (16 * column.val)) &&&
        ((BitVec.allOnes 16).setWidth 64 <<< (16 * column.val))) = _
  rw [← BitVec.shiftLeft_and_distrib, ← BitVec.setWidth_and, BitVec.and_allOnes]

def operandsWord (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block) (reg imm : BitVec 64)
    (column : Fin 4) : Arm64Nop.IgnoredArguments :=
  ⟨.Vptr entry 0, .Vlong reg, unused.src, unused.src2, unused.src3, .Vint (aux column), .Vlong imm⟩

/-- Source operands from the live MOVK encoder; the unused SRC values retain
arbitrary incoming values, since this branch reads DST only. -/
def operands (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block) (reg : BitVec 64)
    (imm : BitVec 16) (column : Fin 4) : Arm64Nop.IgnoredArguments :=
  ⟨.Vptr entry 0, .Vlong reg, unused.src, unused.src2, unused.src3,
    .Vint (aux column), .Vlong (imm.setWidth 64)⟩

private theorem inputs (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (reg : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool) :
    let le := Dispatch.Keep.temps (Dispatch.Keep.initialTemps (operands unused entry reg imm column) narrow) narrow
    le.get Arm64Program._entry = some (.Vptr entry 0) ∧
    le.get Arm64Program._dst = some (.Vlong reg) := by
  simp +decide only [Dispatch.Keep.temps, Dispatch.Keep.initialTemps, operands,
    Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso]

private theorem reader_not_local :
    Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

/-- The actual allocated opcode-5 procedure reaches its real DST reader call
in 32 transitions; this prefix does not assume a read outcome. -/
theorem call_read (before : CC.Mem) (unused : Arm64Nop.IgnoredArguments)
    (entry : CC.Block) (reg : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool) :
    let le := Dispatch.Keep.temps (Dispatch.Keep.initialTemps (operands unused entry reg imm column) narrow) narrow
    InternalRun ge 32
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry reg imm column) narrow) .Kstop before)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong reg]
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler (Arm64Nop.allocation ge before).1 le readCont)
        (Arm64Nop.allocation ge before).2) ∧
      FrameBelow before.nextblock before (Arm64Nop.allocation ge before).2 := by
  have unshadowed : (Arm64Nop.allocation ge before).1.get Arm64Program._kprog_arm64_program_read = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using
      CC.allocVariables_env_other
        (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Nop.allocation ge before)).symm)
        reader_not_local
  have temps := inputs unused entry reg imm column narrow
  have dispatch := Dispatch.Keep.call_dispatch before (operands unused entry reg imm column) narrow
  exact ⟨dispatch.1.trans (read_call _ _ _ entry reg unshadowed temps.1 temps.2), dispatch.2⟩

private theorem long_and (cenv : CC.CompositeEnv) (m : CC.Mem) (a b : BitVec 64) :
    CC.Cop.semBinaryOperation cenv .Oand (.Vlong a) CC.tulong (.Vlong b) CC.tulong m =
      some (.Vlong (a &&& b)) := rfl
private theorem long_or (cenv : CC.CompositeEnv) (m : CC.Mem) (a b : BitVec 64) :
    CC.Cop.semBinaryOperation cenv .Oor (.Vlong a) CC.tulong (.Vlong b) CC.tulong m =
      some (.Vlong (a ||| b)) := rfl
private theorem long_not (m : CC.Mem) (a : BitVec 64) :
    CC.Cop.semUnaryOperation .Onotint (.Vlong a) CC.tulong m = some (.Vlong (~~~a)) := rfl
private theorem long_shift (cenv : CC.CompositeEnv) (m : CC.Mem) (a : BitVec 64) (c : Fin 4) :
    CC.Cop.semBinaryOperation cenv .Oshl (.Vlong a) CC.tulong
      (.Vlong (BitVec.ofNat 64 (16*c.val))) CC.tulong m =
      some (.Vlong (a <<< (16*c.val))) := by
  rcases c with ⟨c, bound⟩
  have cases : c = 0 ∨ c = 1 ∨ c = 2 ∨ c = 3 := by omega
  rcases cases with rfl | rfl | rfl | rfl <;> rfl

private def resultExpr : CC.Expr := by
  run_tac do
    let source ← Lean.Meta.withTransparency .all
      (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_execute_5)) none))
    unless source.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MOVK result sequence changed"
    let assignment ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source.getAppArgs[0]!)
    unless assignment.isAppOfArity ``CC.Stmt.Sset 2 do throwError "actual MOVK result assignment changed"
    Lean.Elab.Tactic.closeMainGoal `actual_movk_result assignment.getAppArgs[1]!

private def leftExpr : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all
      (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(resultExpr)) none))
    unless actual.isAppOfArity ``CC.Expr.Ebinop 4 do throwError "actual MOVK merge changed"
    Lean.Elab.Tactic.closeMainGoal `actual_movk_left actual.getAppArgs[1]!
private def rightExpr : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all
      (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(resultExpr)) none))
    unless actual.isAppOfArity ``CC.Expr.Ebinop 4 do throwError "actual MOVK merge changed"
    Lean.Elab.Tactic.closeMainGoal `actual_movk_right actual.getAppArgs[2]!
private theorem result_source : resultExpr = .Ebinop .Oor leftExpr rightExpr CC.tulong := rfl

private theorem left_type : CC.typeof leftExpr = CC.tulong := rfl
private theorem right_type : CC.typeof rightExpr = CC.tulong := rfl

private theorem eval_merge (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (old : BitVec 64) (imm : BitVec 64) (column : Fin 4)
    (hdst : le.get Arm64Program.___kprog_a64_movk_dst = some (.Vlong old))
    (himm : le.get Arm64Program.___kprog_a64_movk_imm = some (.Vlong imm))
    (hshift : le.get Arm64Program.___kprog_a64_movk_shift = some (.Vlong (BitVec.ofNat 64 (16*column.val))))
    (hmask : le.get Arm64Program.___kprog_a64_movk_mask = some (.Vlong (mask column))) :
    CC.doEvalExpr world e le m resultExpr = some (.Vlong (mergeWord old imm column)) := by
  have left : CC.doEvalExpr world e le m leftExpr = some (.Vlong (old &&& ~~~mask column)) := by
    simp only [leftExpr, CC.doEvalExpr, hdst, hmask, CC.typeof, long_not, long_and]
  have right : CC.doEvalExpr world e le m rightExpr =
      some (.Vlong ((imm <<< (16*column.val)) &&& mask column)) := by
    simp only [rightExpr, CC.doEvalExpr, himm, hshift, hmask, CC.typeof, long_shift, long_and]
  simp only [result_source, CC.doEvalExpr, left, right, left_type, right_type, long_or, mergeWord]

private def readyTemps (le : CC.TempEnv) (old : BitVec 64) (imm : BitVec 64) (column : Fin 4) : CC.TempEnv :=
  (((((le.set Arm64Program._t'6 (.Vlong old)).set
    Arm64Program.___kprog_a64_movk_dst (.Vlong old)).set
    Arm64Program.___kprog_a64_movk_imm (.Vlong imm)).set
    Arm64Program.___kprog_a64_movk_shift (.Vlong (BitVec.ofNat 64 (16 * column.val)))).set
    Arm64Program.___kprog_a64_movk_mask (.Vlong (mask column)))

private theorem ready_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (old : BitVec 64) (imm : BitVec 64) (column : Fin 4) (k : CC.Cont) :
    CC.doStep world (.State Arm64Nop.handler (.Sset Arm64Program.___kprog_a64_movk_result resultExpr)
      k e (readyTemps le old imm column) m) =
      some (CC.E0, .State Arm64Nop.handler .Sskip k e
        ((readyTemps le old imm column).set Arm64Program.___kprog_a64_movk_result
          (.Vlong (mergeWord old imm column))) m) := by
  have hdst : (readyTemps le old imm column).get Arm64Program.___kprog_a64_movk_dst = some (.Vlong old) := by
    rw [readyTemps, CC.PTree.gso _ _ _ _ (by decide +kernel),
      CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gss]
  have himm : (readyTemps le old imm column).get Arm64Program.___kprog_a64_movk_imm = some (.Vlong imm) := by
    rw [readyTemps, CC.PTree.gso _ _ _ _ (by decide +kernel),
      CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gss]
  have hshift : (readyTemps le old imm column).get Arm64Program.___kprog_a64_movk_shift =
      some (.Vlong (BitVec.ofNat 64 (16*column.val))) := by
    rw [readyTemps, CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gss]
  have hmask : (readyTemps le old imm column).get Arm64Program.___kprog_a64_movk_mask = some (.Vlong (mask column)) :=
    CC.PTree.gss _ _ _
  simp only [CC.doStep, eval_merge world e _ m old imm column hdst himm hshift hmask]

set_option hygiene false in
/-- The source merge begins at the actual reader's returned value and memory;
no read result or post-memory is supplied by this control/bit-operation lemma. -/
theorem after_read_word_bound (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (old : BitVec 64) (imm : BitVec 64) (column : Fin 4)
    (himm : le.get Arm64Program._imm = some (.Vlong imm))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column))) :
    InternalRun world 26
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.State Arm64Nop.handler writeCall Dispatch.continuation e (writerTempsWord le old imm column) m) := by
  rcases column with ⟨column, bound⟩
  have columns : column = 0 ∨ column = 1 ∨ column = 2 ∨ column = 3 := by omega
  rcases columns with rfl | rfl | rfl | rfl
  all_goals
    run_tac do
      let reduce ← `(tactic|
        simp +decide only [CC.doStep, CC.setOpttemp, readCont, body,
          dstSet, tail, writerTempsWord, aux, mask, mergeWord,
          Arm64Program.s_kprog_arm64_program_execute_4, Arm64Program.s_kprog_arm64_program_execute_5,
          CC.PTree.gss, CC.PTree.gso, himm, haux, CC.doEvalExpr, CC.typeof,
          CC.seqOfLabeledStatement, CC.selectSwitch, CC.selectSwitchCase, CC.Cop.semSwitchArg,
          long_and, long_or, long_not, long_shift,
          CC.Cop.semBinaryOperation, CC.Cop.semShr, CC.Cop.semShl, CC.Cop.semShift, CC.Cop.classifyShift,
          CC.Cop.semAnd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
          CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
          CC.typeconv, CC.removeAttributes, CC.tattr, CC.Archi.ptr64,
          CC.tuint, CC.tint, CC.tulong, CC.tuchar,
          CC.Integers.Int.ltu, CC.Integers.Int64.ltu, CC.Integers.MI.ltu,
          CC.Integers.Int.iwordsize, CC.Integers.Int64.iwordsize, CC.Integers.MI.iwordsize,
          CC.Integers.Int.shru, CC.Integers.Int64.shl, CC.Integers.MI.shru, CC.Integers.MI.shl,
          CC.Integers.Int.and, CC.Integers.MI.and, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
          CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
          CC.Integers.Int.unsigned, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
          CC.Eapp, CC.E0, List.nil_append, List.append_nil, ite_false, ite_true, eq_self] <;> try rfl)
      for count in [:26] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        if count == 20 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact ready_step world e le m old imm ⟨_, bound⟩ _))
        else
          Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

theorem after_read_bound (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (old : BitVec 64) (imm : BitVec 16) (column : Fin 4)
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column))) :
    InternalRun world 26
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.State Arm64Nop.handler writeCall Dispatch.continuation e (writerTemps le old imm column) m) :=
  after_read_word_bound world e le m old (imm.setWidth 64) column himm haux

theorem after_read (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (old : BitVec 64) (imm : BitVec 16) (column : Fin 4)
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column))) :
    InternalRun ge 26
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.State Arm64Nop.handler writeCall Dispatch.continuation e (writerTemps le old imm column) m) :=
  after_read_bound ge e le m old imm column himm haux

private theorem writer_type : CC.typeOfFundef (.Internal Arm64RegisterWrite.procedure) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
      CC.tulong, CC.tuchar] CC.tvoid CC.cc_default := rfl
private theorem pointer_zero :
    CC.Integers.Ptrofs.eq CC.Integers.Ptrofs.zero CC.Integers.Ptrofs.zero = true := rfl
private theorem byte_size : ¬ (8 : Nat) ≥ 32 := by decide

private theorem writer_step (world : CC.CGenv) (writerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some writerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv writerBlock = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg : BitVec 64) (old : BitVec 64) (imm : BitVec 64) (column : Fin 4) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    CC.doStep world (.State Arm64Nop.handler writeCall Dispatch.continuation e (writerTempsWord le old imm column) m) =
      some (CC.E0, .Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong (mergeWord old imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTempsWord le old imm column) Dispatch.continuation) m) := by
  have entryTemp : (writerTempsWord le old imm column).get Arm64Program._entry = some (.Vptr entry 0) := by
    simp +decide only [writerTempsWord, CC.PTree.gss, CC.PTree.gso, hentry]
  have dstTemp : (writerTempsWord le old imm column).get Arm64Program._dst = some (.Vlong reg) := by
    simp +decide only [writerTempsWord, CC.PTree.gss, CC.PTree.gso, hdst]
  have widthTemp : (writerTempsWord le old imm column).get Arm64Program.___a64_l_width =
      some (Arm64RegisterWrite.width narrow) := by
    simp +decide only [writerTempsWord, CC.PTree.gss, CC.PTree.gso, hwidth]
  have valueTemp : (writerTempsWord le old imm column).get Arm64Program.___a64_l_value__1 = some (.Vlong (mergeWord old imm column)) :=
    CC.PTree.gss _ _ _
  cases narrow <;>
    simp only [CC.doStep, writeCall, Arm64RegisterWrite.arguments, Arm64RegisterWrite.width,
      CC.typeof, CC.Cop.classifyFun, CC.doEvalExpr, CC.doEvalExprlist,
      CC.lvalOfVar, unshadowed, binding.1, CC.doDerefLoc, CC.accessMode,
      CC.Genv.findFunct, binding.2, writer_type, entryTemp, dstTemp, widthTemp, valueTemp,
      byte_size, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Archi.ptr64,
      CC.tptr, CC.tulong, CC.tuchar, CC.tvoid,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int.repr, CC.Integers.MI.repr,
      pointer_zero,
      ite_true, ite_false, Bool.false_eq_true, eq_self] <;> rfl

/-- The real writer call follows the 26-transition merge. Its start state
is the actual reader return, so a reader's post-memory remains explicit. -/
theorem writer_call_word_bound (world : CC.CGenv) (writerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some writerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv writerBlock = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg old : BitVec 64) (imm : BitVec 64) (column : Fin 4) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (himm : le.get Arm64Program._imm = some (.Vlong imm))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun world 27
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong (mergeWord old imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTempsWord le old imm column) Dispatch.continuation) m) := by
  exact (after_read_word_bound world e le m old imm column himm haux).trans
    (.step trivial (CC.doStep_sound _ _ _ _
      (writer_step world writerBlock binding e le m entry reg old imm column narrow unshadowed hentry hdst hwidth)) (.refl _))

theorem writer_call_bound (world : CC.CGenv) (writerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some writerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv writerBlock = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg old : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun world 27
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong (merge old imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTemps le old imm column) Dispatch.continuation) m) :=
  writer_call_word_bound world writerBlock binding e le m entry reg old (imm.setWidth 64) column narrow
    unshadowed hentry hdst himm haux hwidth

theorem writer_call (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg old : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun ge 27
      (.Returnstate (.Vlong old)
        (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong (merge old imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTemps le old imm column) Dispatch.continuation) m) :=
  writer_call_bound ge (CC.Positive.ofNat 79) writer_binding e le m entry reg old imm column narrow
    unshadowed hentry hdst himm haux hwidth

/-- Concrete actual DST31 read, merge and writer edge. The reader executes
all 55 transitions and its zero result is derived, with unchanged memory. -/
theorem zr_writer_call (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (readerUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writerUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong 31))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun ge 87
      (.State Arm64Nop.handler Dispatch.Keep.branch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong 31, .Vlong (merge 0 imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTemps le 0 imm column) Dispatch.continuation) m) := by
  have enter := read_call e le m entry 31 readerUnshadowed hentry hdst
  have read := read_zr ge (.Vptr entry 0) m
    (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont)
  have finish := writer_call e le m entry 31 0 imm column narrow writerUnshadowed hentry hdst himm haux hwidth
  simpa only [CC.callCont] using (enter.trans read).trans finish

end KProgFormal.ClightRefinement.Arm64MovKeep
