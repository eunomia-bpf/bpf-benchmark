import KProgFormal.ClightRefinement.Arm64ProgramEntryCbzComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTbnz

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

private structure Parts where
  body : CC.Stmt
  readCall : CC.Stmt
  branchCall : CC.Stmt
  saveTaken : CC.Stmt
  choice : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original TBNZ source changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCbzLabels.takenBody)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let left ← peel body[0]! ``CC.Stmt.Ssequence 2
    let pair ← peel left[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_tbnz_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,pair[0]!,pair[1]!,left[1]!,body[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_tbnz_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def readCall : CC.Stmt := by run_tac cachePart (← `(parts.readCall))
def branchCall : CC.Stmt := by run_tac cachePart (← `(parts.branchCall))
def saveTaken : CC.Stmt := by run_tac cachePart (← `(parts.saveTaken))
def choice : CC.Stmt := by run_tac cachePart (← `(parts.choice))
theorem source : Arm64ProgramEntryCbzLabels.takenBody = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence (.Ssequence (.Ssequence readCall branchCall) saveTaken) choice := rfl

theorem call_source : readCall = .Scall (some Arm64ProgramFixture._t'140)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tulong CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
        (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
        (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (CC.Integers.Int.repr 4) CC.tuint] := rfl

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_read = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_read ∉
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

theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0,.Vlong (BitVec.ofNat 64 4)]
        (.Kcall (some Arm64ProgramFixture._t'140) Arm64ProgramFixture.f_arm64_execute_compile
          (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding :
      CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 66) =
        some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ ?_ ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    · rfl
    refine eval_cons (v := .Vint (CC.Integers.Int.repr 4)) ?_ ?_ ?_
    · rfl
    · rfl
    · rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Complete the actual X4 scalar reader and return to this original call site. -/
theorem read {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (raw : BitVec 64)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 4 = some (.Vlong raw,.Vint 0)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'140 (.Vlong raw)) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'140) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0,.Vlong (4#64)] cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k) (.refl _)
  have run := Arm64RegisterReads.gpr_read_nonrelative_bound world Arm64MovKeep.Linked.reader_layout
    (fun _ => none) m.nextblock entry.block 0 (4 : Fin 31) m cont (.Vlong raw) raw (0#8)
    observed rfl (by decide) (by decide)
  have leave : InternalRun world 1
      (.Returnstate (.Vlong raw) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'140 (.Vlong raw)) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(enter.trans run).trans leave⟩

/-- The same completed helper map supplies X4 and its actual scalar tag. -/
theorem current_read {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'140 (.Vlong (gprs 3))) m) := by
  apply read entry le m k (gprs 3)
  exact packet.registers 3

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k)
def branchCont (k : CC.Cont) : CC.Cont := .Kseq saveTaken (.Kseq choice (loopCont k))
def readCont (k : CC.Cont) : CC.Cont := .Kseq branchCall (branchCont k)
def temps (le : CC.TempEnv) (raw : BitVec 64) : CC.TempEnv := le.set Arm64ProgramFixture._t'140 (.Vlong raw)

/-- The original loop enters the actual full64 X4 reader, restores its true
caller and reaches the real Numeric test call with the same helper outcome. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall (branchCont k) (allocation initial).1
        (temps le (gprs 3)) m) := by
  have start : InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall (readCont k) (allocation initial).1 le m) := by
    rw [source,body_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))
  obtain ⟨readCount,reads⟩ := current_read packet le (readCont k)
  have resume : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (readCont k) (allocation initial).1
        (temps le (gprs 3)) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall (branchCont k) (allocation initial).1
        (temps le (gprs 3)) m) := .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(start.trans reads).trans resume⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryTbnz
