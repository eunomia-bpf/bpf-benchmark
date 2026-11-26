import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkComplete
import KProgFormal.ClightRefinement.Arm64MovKeepLinked

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnRaw
open Arm64Producer (HeaderLocal)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  body : CC.Stmt
  setup : CC.Stmt
  readCall : CC.Stmt
  storeLR : CC.Stmt
  tail : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original callee source changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryLinkLabels.callee)) none) ``CC.Stmt.Sloop 2
    let body ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let setup ← peel body[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_return_raw_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,body[0]!,setup[0]!,setup[1]!,body[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_return_raw_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
def readCall : CC.Stmt := by run_tac cachePart (← `(parts.readCall))
def storeLR : CC.Stmt := by run_tac cachePart (← `(parts.storeLR))
def tail : CC.Stmt := by run_tac cachePart (← `(parts.tail))
theorem source : Arm64ProgramEntryLinkLabels.callee = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence setup tail := rfl
theorem setup_source : setup = .Ssequence readCall storeLR := rfl
theorem store_source : storeLR = .Sassign (.Evar Arm64ProgramFixture.___a64_lr CC.tulong)
    (.Etempvar Arm64ProgramFixture._t'149 CC.tulong) := rfl

def outerCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
def storeCont (k : CC.Cont) : CC.Cont := .Kseq tail (outerCont k)
def readCont (k : CC.Cont) : CC.Cont := .Kseq storeLR (storeCont k)
def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'149 (.Vlong 64)

theorem call_source : readCall = .Scall (some Arm64ProgramFixture._t'149)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_raw
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tulong CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (30#32) CC.tuint] := rfl

/-- Original fixture declaration rows64/65 retain their positions in the
actual merged world; reader_binding checks the complete linked lookups. -/
def readerBlock (tags : Bool) : CC.Block := CC.Positive.ofNat (if tags then 65 else 64)

theorem reader_binding (tags : Bool) :
    CC.Genv.findSymbol world.genv_genv
      (if tags then Arm64ProgramFixture._kprog_arm64_program_tag else Arm64ProgramFixture._kprog_arm64_program_raw) =
      some (readerBlock tags) ∧
    CC.Genv.findFunctPtr world.genv_genv (readerBlock tags) = some (.Internal (Arm64RegisterReads.reader tags)) := by
  cases tags <;> constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_raw = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_raw ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal (Arm64RegisterReads.reader false)) [.Vptr entry.block 0,.Vlong 30]
        (.Kcall (some Arm64ProgramFixture._t'149) Arm64ProgramFixture.f_arm64_execute_compile
          (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding := reader_binding false
  change CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_raw = _ ∧ _ at binding
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (readerBlock false) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    exact eval_cons (v := .Vint (30#32)) (by rfl) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Both complete original raw/tag helpers use the same actual current X30
word/tag observation and preserve the complete reached memory. -/
theorem readers {initial : CC.Mem} (entry : HeaderLocal initial) (m : CC.Mem) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    InternalRun world 28 (.Callstate (.Internal (Arm64RegisterReads.reader false)) [.Vptr entry.block 0,.Vlong 30] k m)
      (.Returnstate (.Vlong 64) (CC.callCont k) m) ∧
    InternalRun world 28 (.Callstate (.Internal (Arm64RegisterReads.reader true)) [.Vptr entry.block 0,.Vlong 30] k m)
      (.Returnstate (.Vint (9#32)) (CC.callCont k) m) := by
  have actual : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (30 : Fin 31).val =
      some (.Vlong 64,.Vint ((9#8).setWidth 32)) := by
    simpa only [show (30 : Fin 31).val = 30 by decide +kernel,
      show (9#8).setWidth 32 = (9#32) by decide +kernel] using observed
  have calls := Arm64RegisterReads.gpr_calls_bound world Arm64MovKeep.Linked.reader_layout
    (by decide +kernel) (fun _ => none) m.nextblock entry.block 0 (30 : Fin 31) m k (.Vlong 64) 64 (9#8) actual rfl
  exact ⟨calls.1,calls.2.1⟩

theorem invoke {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    InternalRun world 30
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'149) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.Callstate (.Internal (Arm64RegisterReads.reader false)) [.Vptr entry.block 0,.Vlong 30] cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k) (.refl _)
  have helper := (readers entry m cont observed).1
  have leave : InternalRun world 1 (.Returnstate (.Vlong 64) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans helper).trans leave

set_option hygiene false in
private theorem enter {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall (readCont k) (allocation initial).1 le m) := by
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,source,body_source,setup_source,outerCont,storeCont,readCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Original callee loop, complete raw function/caller and sequence resume
reach the REAL LR assignment with captured t149, on the same current heap. -/
theorem execute {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    InternalRun world 34
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile storeLR (storeCont k) (allocation initial).1 (temps le) m) := by
  have resume : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (readCont k) (allocation initial).1 (temps le) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile storeLR (storeCont k) (allocation initial).1 (temps le) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ((enter le m k).trans (invoke entry le m (readCont k) observed)).trans resume

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnRaw
