import KProgFormal.ClightRefinement.Arm64MovImmediateDispatch
import KProgFormal.ClightRefinement.Arm64ReadNone

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.Suffix

open Arm64NumericProgram

private structure Pieces where
  readBody : CC.Stmt
  readCall : CC.Stmt
  operandSet : CC.Stmt
  selection : CC.Stmt
  writeCall : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual MOV scalar branch changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Dispatch.scalarBranch)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let read ← peel body[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_mov_scalar_parts (← Lean.Meta.mkAppM ``Pieces.mk
      #[loop[0]!, read[0]!, read[1]!, body[1]!, root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  Lean.Elab.Tactic.closeMainGoal `actual_mov_scalar_part actual

private def readBody : CC.Stmt := by run_tac cachePart (← `(pieces.readBody))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))
private def operandSet : CC.Stmt := by run_tac cachePart (← `(pieces.operandSet))
private def selection : CC.Stmt := by run_tac cachePart (← `(pieces.selection))
private def writeCall : CC.Stmt := by run_tac cachePart (← `(pieces.writeCall))

/-- The exact scalar branch of the exported generic handler. -/
theorem scalar_source : Dispatch.scalarBranch = .Ssequence
    (.Sloop (.Ssequence (.Ssequence readCall operandSet) selection) .Sbreak) writeCall := rfl

def readCont : CC.Cont := .Kseq operandSet (.Kseq selection
  (.Kloop1 readBody .Sbreak (.Kseq writeCall Dispatch.continuation)))

/-- Keep the actual eager-reader result in the compiler temporary even when
MOV_IMM subsequently replaces the operand by its immediate. -/
def writerTempsRead (le : CC.TempEnv) (read value : BitVec 64) : CC.TempEnv :=
  (((le.set Arm64Program._t'4 (.Vlong read)).set Arm64Program.___kprog_a64_io_operand (.Vlong read)).set
    Arm64Program.___kprog_a64_io_operand (.Vlong value)).set Arm64Program.___a64_l_value (.Vlong value)

def writerTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv := writerTempsRead le 0 value

private theorem reader_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong]
      CC.tulong CC.cc_default := rfl

private theorem writer_type : CC.typeOfFundef (.Internal Arm64RegisterWrite.procedure) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
      CC.tulong, CC.tuchar] CC.tvoid CC.cc_default := rfl

theorem read_call_bound (world : CC.CGenv) (readerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some readerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv readerBlock = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (src : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry : CC.Block)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong src)) :
    InternalRun world 5 (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong src]
        (.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le readCont) m) := by
  have execution : steps world 5
      (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m) =
      some (CC.E0, .Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0, .Vlong src]
        (.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le readCont) m) ∧
      InternalPath world 5 (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m) := by
    simp [scalar_source, readBody, readCall, readCont, operandSet, selection, steps, InternalPath, InternalState,
      CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.typeof, CC.Cop.classifyFun,
      CC.lvalOfVar, unshadowed, binding.1, CC.doDerefLoc,
      CC.accessMode, CC.Genv.findFunct, binding.2, hentry, hsrc,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.tptr, CC.tulong, CC.tvoid,
      reader_type, CC.E0, CC.Eapp, CC.Integers.MI.zero,
      CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq]
  exact internalRun_of_steps execution.2 execution.1

private theorem pointer_zero :
    CC.Integers.Ptrofs.eq CC.Integers.Ptrofs.zero CC.Integers.Ptrofs.zero = true := rfl
private theorem byte_size : ¬ (8 : Nat) ≥ 32 := by decide

private theorem writer_step_bound (world : CC.CGenv) (writerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some writerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv writerBlock = some (.Internal Arm64RegisterWrite.procedure))
    (read : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg : BitVec 64) (value : BitVec 64) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    CC.doStep world (.State Arm64Nop.handler writeCall Dispatch.continuation e (writerTempsRead le read value) m) =
      some (CC.E0, .Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong value, Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTempsRead le read value) Dispatch.continuation) m) := by
  have entryTemp : (writerTempsRead le read value).get Arm64Program._entry = some (.Vptr entry 0) := by
    simp +decide only [writerTempsRead, CC.PTree.gss, CC.PTree.gso, hentry]
  have dstTemp : (writerTempsRead le read value).get Arm64Program._dst = some (.Vlong reg) := by
    simp +decide only [writerTempsRead, CC.PTree.gss, CC.PTree.gso, hdst]
  have widthTemp : (writerTempsRead le read value).get Arm64Program.___a64_l_width =
      some (Arm64RegisterWrite.width narrow) := by
    simp +decide only [writerTempsRead, CC.PTree.gss, CC.PTree.gso, hwidth]
  have valueTemp : (writerTempsRead le read value).get Arm64Program.___a64_l_value = some (.Vlong value) :=
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

set_option hygiene false in
theorem after_read_bound (world : CC.CGenv) (writerBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some writerBlock ∧
      CC.Genv.findFunctPtr world.genv_genv writerBlock = some (.Internal Arm64RegisterWrite.procedure))
    (read : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg : BitVec 64) (value : BitVec 64) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun world 18
      (.Returnstate (.Vlong read)
        (.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le readCont) m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong value, Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTempsRead le read value) Dispatch.continuation) m) := by
  cases narrow <;>
    run_tac do
      let reduce ← `(tactic|
        first | rfl | simp +decide only [CC.doStep, CC.setOpttemp, readCont, readBody,
          operandSet, selection, writerTempsRead, Arm64Program.s_kprog_arm64_program_execute_2,
          CC.PTree.gss, CC.PTree.gso, hop, himm, CC.doEvalExpr, CC.typeof,
          CC.seqOfLabeledStatement, CC.selectSwitch, CC.selectSwitchCase, CC.Cop.semSwitchArg,
          CC.tuint, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
          CC.Eapp, CC.E0, List.nil_append, List.append_nil, ite_false, ite_true, eq_self] <;> try rfl)
      for _ in [:17] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic|
        exact InternalRun.step trivial
          (CC.doStep_sound _ _ _ _ (writer_step_bound world writerBlock binding read e le m entry reg value _ unshadowed hentry hdst hwidth))
          (InternalRun.refl _)))

/-- This is the real caller edge to the writer, after the mandatory NONE read
and immediate switch. No standalone writer return is substituted for a call. -/
theorem writer_call_register (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (reg : BitVec 64) (value : BitVec 64) (narrow : Bool)
    (readUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 255))
    (hdst : le.get Arm64Program._dst = some (.Vlong reg))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun ge 78 (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry 0, .Vlong reg, .Vlong value, Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTemps le value) Dispatch.continuation) m) := by
  have first := read_call_bound ge (CC.Positive.ofNat 76) reader_binding 255 e le m entry readUnshadowed hentry hsrc
  have read := read_none ge (.Vptr entry 0) m
    (.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le readCont)
  have select := after_read_bound ge (CC.Positive.ofNat 79) writer_binding 0 e le m entry reg value narrow writeUnshadowed hentry hdst hop himm hwidth
  simpa only [CC.callCont, writerTemps] using (first.trans read).trans select

/-- Preserve the original ordinary-register caller API. -/
theorem writer_call (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (entry : CC.Block) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (readUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 255))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun ge 78 (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        (Arm64RegisterWrite.arguments entry i value narrow)
        (.Kcall none Arm64Nop.handler e (writerTemps le value) Dispatch.continuation) m) := by
  exact writer_call_register e le m entry (BitVec.ofNat 64 i.val) value narrow
    readUnshadowed writeUnshadowed hentry hsrc hdst hop himm hwidth

theorem after_writer_bound (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    InternalRun world 3
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e le Dispatch.continuation) m)
      (.State Arm64Nop.handler .Sskip .Kstop e le m) := by
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

theorem after_writer (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    InternalRun ge 3
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e le Dispatch.continuation) m)
      (.State Arm64Nop.handler .Sskip .Kstop e le m) :=
  after_writer_bound ge e le m

/-- Execute the scalar branch's actual read, selection, writer call and return
to its caller's end statement. The real generic local frame is still live. -/
theorem scalar_write {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (e : CC.Env) (le : CC.TempEnv) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (readUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 255))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    ∃ after, Arm64RegisterWrite.Result storage i value narrow after ∧
      InternalRun ge 148
        (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le before)
        (.State Arm64Nop.handler .Sskip .Kstop e (writerTemps le value) after) := by
  obtain ⟨after, result⟩ := Arm64RegisterWrite.write storage i value narrow
  obtain ⟨middle, word, tag⟩ := result.stores
  have call := writer_call e le before entry.block i value narrow
    readUnshadowed writeUnshadowed hentry hsrc hdst hop himm hwidth
  have write := Arm64RegisterWrite.execute_stores_bound ge composites_same
    (.Kcall none Arm64Nop.handler e (writerTemps le value) Dispatch.continuation) rfl
    m before middle after entry storage i value narrow word tag
  have finish := after_writer e (writerTemps le value) after
  exact ⟨after, result, (call.trans write).trans finish⟩

/-- The same actual caller reaches the XZR writer and returns without any
store. Its 38 writer transitions retain the eager SP read. -/
theorem scalar_zr {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (e : CC.Env) (le : CC.TempEnv) (value : BitVec 64) (narrow : Bool)
    (readUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 255))
    (hdst : le.get Arm64Program._dst = some (.Vlong 31))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    InternalRun ge 119
      (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le before)
      (.State Arm64Nop.handler .Sskip .Kstop e (writerTemps le value) before) := by
  have call := writer_call_register e le before entry.block 31 value narrow
    readUnshadowed writeUnshadowed hentry hsrc hdst hop himm hwidth
  have write := Arm64RegisterWrite.execute_zr_bound ge composites_same
    (.Kcall none Arm64Nop.handler e (writerTemps le value) Dispatch.continuation) rfl
    m before entry storage value narrow
  exact (call.trans write).trans (after_writer e (writerTemps le value) before)

end KProgFormal.ClightRefinement.Arm64MovImmediate.Suffix
