import KProgFormal.ClightRefinement.Arm64CnegReadEntry
import KProgFormal.ClightRefinement.Arm64ConditionGe

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Condition
open Arm64ProgramEntryLinked (ge)

private structure Pieces where
  input : CC.Stmt
  normalize : CC.Stmt
  copyTaken : CC.Stmt
  after : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original CNEG condition sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(ReadEntry.tail)) none)
    let condition ← peel root[0]!
    let first ← peel condition[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_cneg_condition
      (← Lean.Meta.mkAppM ``Pieces.mk #[first[0]!,first[1]!,condition[1]!,root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cneg_condition_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def branch : CC.Stmt := ReadEntry.tail
private def input : CC.Stmt := by run_tac cachePart (← `(pieces.input))
private def normalize : CC.Stmt := by run_tac cachePart (← `(pieces.normalize))
private def copyTaken : CC.Stmt := by run_tac cachePart (← `(pieces.copyTaken))
def after : CC.Stmt := by run_tac cachePart (← `(pieces.after))

/-- The actual CNEG condition prefix and untouched numeric/writer suffix. -/
theorem branch_source : branch = .Ssequence (.Ssequence (.Ssequence input normalize) copyTaken) after := rfl
private def inputCont (k : CC.Cont) : CC.Cont := .Kseq normalize (.Kseq copyTaken (.Kseq after k))
def loads (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) : CC.TempEnv :=
  (((le.set Arm64Program._t'7055 (.Vptr (blocks 0) (0#64))).set Arm64Program._t'7056 (.Vptr (blocks 1) (0#64))).set
    Arm64Program._t'7057 (.Vptr (blocks 2) (0#64))).set Arm64Program._t'7058 (.Vptr (blocks 3) (0#64))
def temps (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) (z : BitVec 1) : CC.TempEnv :=
  (((loads le blocks).set Arm64Program._t'55 (.Vint (z.setWidth 32))).set
    Arm64Program._t'56 (.Vint (z.setWidth 32))).set Arm64Program.___kprog_a64_cneg_taken (.Vint (z.setWidth 32))
private def callCont (e : CC.Env) (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'55) Arm64Nop.handler e (loads le blocks) (inputCont k)
private def field (i : Fin 4) : CC.Ident := [Arm64Program._n,Arm64Program._z,Arm64Program._c,Arm64Program._v][i]
private def offset (i : Fin 4) : CC.Z := 64 + 8 * (i.val : Int)
private def pointer (i : Fin 4) : CC.Expr :=
  .Efield (.Ederef (.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
    (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field i) (CC.tptr CC.tuchar)
private theorem four_cases : ∀ i : Fin 4, i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by decide +kernel
private theorem address (b : CC.Block) (i : Fin 4) :
    CC.lvalOfField ge (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr) (field i) (.Vptr b (0#64)) =
      some (b,CC.Integers.Ptrofs.repr (offset i),.Full) := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem offset_unsigned : ∀ i : Fin 4,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i := by decide +kernel
private theorem condition_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_condition = some (CC.Positive.ofNat 69) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 69) = some (.Internal Arm64Program.f_kprog_arm64_program_condition) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

private def callStmt : CC.Stmt :=
  .Scall (some Arm64Program._t'55)
    (.Evar Arm64Program._kprog_arm64_program_condition
      (.Tfunction [CC.tulong,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar] CC.tint CC.cc_default))
    [.Etempvar Arm64Program._aux CC.tuint,.Etempvar Arm64Program._t'7055 (CC.tptr CC.tuchar),
     .Etempvar Arm64Program._t'7056 (CC.tptr CC.tuchar),.Etempvar Arm64Program._t'7057 (CC.tptr CC.tuchar),
     .Etempvar Arm64Program._t'7058 (CC.tptr CC.tuchar)]
private theorem input_source : input =
    .Ssequence (.Sset Arm64Program._t'7055 (pointer 0))
      (.Ssequence (.Sset Arm64Program._t'7056 (pointer 1))
        (.Ssequence (.Sset Arm64Program._t'7057 (pointer 2))
          (.Ssequence (.Sset Arm64Program._t'7058 (pointer 3)) callStmt))) := rfl

/-- All four actual header-pointer loads and the real linked condition call. -/
private theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b : CC.Block) (blocks : Fin 4 → CC.Block)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_condition = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b (0#64)))
    (aux : le.get Arm64Program._aux = some (.Vint (10#32)))
    (reads : ∀ i, CC.Mem.load CC.Mptr m b (offset i) = some (.Vptr (blocks i) (0#64))) :
    InternalRun ge 16 (.State Arm64Nop.handler branch k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
        (Arm64ConditionGe.arguments (.Vptr (blocks 0) (0#64)) (.Vptr (blocks 1) (0#64))
          (.Vptr (blocks 2) (0#64)) (.Vptr (blocks 3) (0#64))) (callCont e le blocks k) m) := by
  have loaded (le' : CC.TempEnv) (hentry : le'.get Arm64Program._entry = some (.Vptr b (0#64))) (i : Fin 4) :
      CC.doEvalExpr ge e le' m (pointer i) = some (.Vptr (blocks i) (0#64)) := by
    simp only [pointer,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.typeof,CC.doDerefLoc,
      CC.accessMode,CC.tptr,address,CC.Mem.loadv,offset_unsigned,reads] <;> rfl
  have l0 := loaded le entry 0
  have l1 := loaded (le.set Arm64Program._t'7055 (.Vptr (blocks 0) (0#64)))
    (by simpa +decide only [CC.PTree.gso] using entry) 1
  have l2 := loaded ((le.set Arm64Program._t'7055 (.Vptr (blocks 0) (0#64))).set Arm64Program._t'7056 (.Vptr (blocks 1) (0#64)))
    (by simpa +decide only [CC.PTree.gso] using entry) 2
  have l3 := loaded (((le.set Arm64Program._t'7055 (.Vptr (blocks 0) (0#64))).set Arm64Program._t'7056 (.Vptr (blocks 1) (0#64))).set Arm64Program._t'7057 (.Vptr (blocks 2) (0#64)))
    (by simpa +decide only [CC.PTree.gso] using entry) 3
  have execution : steps ge 16 (.State Arm64Nop.handler branch k e le m) =
      some (CC.E0,.Callstate (.Internal Arm64Program.f_kprog_arm64_program_condition)
        (Arm64ConditionGe.arguments (.Vptr (blocks 0) (0#64)) (.Vptr (blocks 1) (0#64))
          (.Vptr (blocks 2) (0#64)) (.Vptr (blocks 3) (0#64))) (callCont e le blocks k) m) ∧
      InternalPath ge 16 (.State Arm64Nop.handler branch k e le m) := by
    simp +decide [steps,InternalPath,InternalState,CC.doStep,branch_source,input_source,callStmt,
      callCont,inputCont,loads,l0,l1,l2,l3,entry,aux,unshadowed,condition_binding.1,condition_binding.2,
      Arm64ConditionGe.arguments,CC.setOpttemp,CC.PTree.gss,CC.PTree.gso,
      CC.doEvalExpr,CC.doEvalExprlist,CC.doDerefLoc,CC.lvalOfVar,CC.typeof,CC.accessMode,
      CC.Cop.classifyFun,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.tulong,CC.tuchar,CC.tptr,CC.Archi.ptr64,
      CC.Genv.findFunct,CC.typeOfFundef,CC.typeOfFunction,CC.typeOfParams,
      Arm64Program.f_kprog_arm64_program_condition,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int64.repr,CC.Integers.Int.repr,CC.Integers.MI.repr,
      CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,CC.Integers.MI.eq,CC.Integers.MI.zero,
      CC.E0,CC.Eapp]
  exact internalRun_of_steps execution.2 execution.1

set_option hygiene false in
private theorem after_result (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (blocks : Fin 4 → CC.Block) (z : BitVec 1) :
    InternalRun ge 7 (.Returnstate (.Vint (z.setWidth 32)) (callCont e le blocks k) m)
      (.State Arm64Nop.handler after k e (temps le blocks z) m) := by
  have bit_cases : ∀ z : BitVec 1, z=0#1 ∨ z=1#1 := by decide +kernel
  rcases bit_cases z with rfl|rfl
  all_goals
    run_tac do
      for _ in [:7] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,callCont,inputCont,
          normalize,copyTaken,temps,loads,CC.setOpttemp,CC.PTree.gss,CC.PTree.gso,
          CC.doEvalExpr,CC.typeof,CC.Cop.boolVal,CC.Cop.classifyBool,CC.Cop.semCast,CC.Cop.classifyCast,
          CC.Cop.castIntInt,CC.tint,CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
          CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The real CNEG condition site: four current header pointer loads, actual
GE callee and caller truth normalization. Same full heap/e/k and exact7temps;
numeric negation/writeback remains the untouched source successor. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block (0#64)) s)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_condition = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block (0#64)))
    (aux : le.get Arm64Program._aux = some (.Vint (10#32))) :
    InternalRun ge 51 (.State Arm64Nop.handler branch k e le m)
      (.State Arm64Nop.handler after k e
        (temps le (fun i => (storage.flags i).block) (BitVec.ofBool (ConditionHolds (10#4) s.machine))) m) := by
  have offsets : ∀ i : Fin 4,
      8 * ((Arm64ProducerEntryView.flagIndex i).val : Int) = offset i := by decide +kernel
  have zero : (0 : CC.Integers.Ptrofs) = (0#64) := by rfl
  have reads (i : Fin 4) : CC.Mem.load CC.Mptr m entry.block (offset i) =
      some (.Vptr (storage.flags i).block (0#64)) := by
    simpa only [offsets i,zero] using storage.flagPointers i
  have first := enter e le m k entry.block (fun i => (storage.flags i).block) unshadowed entryRead aux reads
  have called := Arm64ConditionGe.from_storage storage s represented ge
    (callCont e le (fun i => (storage.flags i).block) k)
  have resultEq : Arm64ConditionGe.result ((read_flag .N s.machine).setWidth 8)
      ((read_flag .V s.machine).setWidth 8) =
      .Vint ((BitVec.ofBool (ConditionHolds (10#4) s.machine)).setWidth 32) := by
    rw [Arm64ConditionGe.native_result]
    cases outcome : ConditionHolds (10#4) s.machine <;> rfl
  rw [resultEq] at called
  have last := after_result e le m k (fun i => (storage.flags i).block) (BitVec.ofBool (ConditionHolds (10#4) s.machine))
  simpa only [CC.callCont,callCont] using (first.trans called).trans last

theorem taken_value (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) (z : BitVec 1) :
    (temps le blocks z).get Arm64Program.___kprog_a64_cneg_taken = some (.Vint (z.setWidth 32)) := by
  simp only [temps,CC.PTree.gss]

/-- Every other temporary retains its actual incoming observation. -/
theorem temps_other (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) (z : BitVec 1) (id : CC.Ident)
    (outside : id ∉ [Arm64Program._t'7055,Arm64Program._t'7056,Arm64Program._t'7057,Arm64Program._t'7058,
      Arm64Program._t'55,Arm64Program._t'56,Arm64Program.___kprog_a64_cneg_taken]) :
    (temps le blocks z).get id = le.get id := by
  simp at outside
  simp only [temps,loads,CC.PTree.gso _ _ _ _ (Ne.symm outside.2.2.2.2.2.2),
    CC.PTree.gso _ _ _ _ (Ne.symm outside.2.2.2.2.2.1),CC.PTree.gso _ _ _ _ (Ne.symm outside.2.2.2.2.1),
    CC.PTree.gso _ _ _ _ (Ne.symm outside.2.2.2.1),CC.PTree.gso _ _ _ _ (Ne.symm outside.2.2.1),
    CC.PTree.gso _ _ _ _ (Ne.symm outside.2.1),CC.PTree.gso _ _ _ _ (Ne.symm outside.1)]

end KProgFormal.ClightRefinement.Arm64Cneg.Condition
