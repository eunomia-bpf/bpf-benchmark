import KProgFormal.ClightRefinement.Arm64ProgramEntryAfterMemcpy
import KProgFormal.ClightRefinement.Arm64ProgramEntryResultCondition

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJcc

open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  outer : CC.Stmt
  after : CC.Stmt
  selector : CC.Stmt
  selection : CC.Stmt
  inner : CC.Stmt
  mark : CC.Stmt
  condition : CC.Stmt
  decision : CC.Stmt
  finish : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original JCC source shape changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryAfterMemcpy.branches)) none) ``CC.Stmt.Ssequence 2
    let outer ← peel root[0]! ``CC.Stmt.Sloop 2
    let selected ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let choice ← peel selected[1]! ``CC.Stmt.Sifthenelse 3
    let inner ← peel choice[1]! ``CC.Stmt.Sloop 2
    let body ← peel inner[0]! ``CC.Stmt.Ssequence 2
    let left ← peel body[0]! ``CC.Stmt.Ssequence 2
    let pair ← peel left[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `original_jcc_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,root[1]!,selected[0]!,selected[1]!,inner[0]!,pair[0]!,pair[1]!,left[1]!,body[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `original_jcc_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def outer : CC.Stmt := by run_tac cachePart (← `(parts.outer))
def after : CC.Stmt := by run_tac cachePart (← `(parts.after))
def selector : CC.Stmt := by run_tac cachePart (← `(parts.selector))
def selection : CC.Stmt := by run_tac cachePart (← `(parts.selection))
def inner : CC.Stmt := by run_tac cachePart (← `(parts.inner))
def mark : CC.Stmt := by run_tac cachePart (← `(parts.mark))
def conditionCall : CC.Stmt := by run_tac cachePart (← `(parts.condition))
def decision : CC.Stmt := by run_tac cachePart (← `(parts.decision))
def finish : CC.Stmt := by run_tac cachePart (← `(parts.finish))
theorem source : Arm64ProgramEntryAfterMemcpy.branches = .Ssequence (.Sloop outer .Sbreak) after := rfl
theorem outer_source : outer = .Ssequence selector selection := rfl
theorem inner_source : inner = .Ssequence (.Ssequence (.Ssequence mark conditionCall) decision) finish := rfl
theorem mark_source : mark = .Sset Arm64ProgramFixture._t'161 (Arm64ProgramEntryBody.contextExpr 0) := rfl

def markTemps (le : CC.TempEnv) (value : BitVec 32) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'161 (.Vint value)

/-- The source reads the mark field through its actual linked composite offset. -/
theorem mark_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (block : CC.Block) (ofs : CC.Integers.Ptrofs) (value : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr block ofs))
    (read : CC.Mem.loadv .Mint32 m
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 8))) = some (.Vint value)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile mark k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (markTemps le value) m) := by
  have field := Arm64ProgramEntryBody.context_read (allocation initial).1 le m block ofs 0 value ctx read
  rw [mark_source]
  apply CC.doStep_sound
  simp only [CC.doStep,field,markTemps]

/-- The reached condition code is the real unsigned C remainder. -/
def code (mark : BitVec 32) : Fin 15 :=
  ⟨mark.toNat % 15,Nat.mod_lt _ (by decide)⟩

theorem remainder_cast (value : BitVec 32) :
    (value % (15#32)).setWidth 64 = BitVec.ofNat 64 (code value).val := by
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_setWidth,BitVec.toNat_umod,BitVec.toNat_ofNat,code]

private theorem flag_metadata : ∀ i : Fin 4,
    Arm64ProgramEntryAllocation.localName
      (Arm64Producer.headerSourceName (Arm64ProducerEntryView.flagIndex i)) = Arm64ProgramEntryBody.flagName i ∧
    Arm64ProgramEntryAllocation.localType
      (Arm64Producer.headerSourceType (Arm64ProducerEntryView.flagIndex i)) = CC.tuchar := by decide +kernel

theorem flag_binding {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (i : Fin 4) :
    (allocation initial).1.get (Arm64ProgramEntryBody.flagName i) = some ((storage.flags i).block,CC.tuchar) := by
  simpa only [(flag_metadata i).1,(flag_metadata i).2] using
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ (storage.flags i).binding

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_condition = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_condition ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

theorem call_source : conditionCall = .Scall (some Arm64ProgramFixture._t'134)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_condition
      (.Tfunction [CC.tulong,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar]
        CC.tint CC.cc_default))
    [.Ebinop .Omod (.Etempvar Arm64ProgramFixture._t'161 CC.tuint)
      (.Econst_int (CC.Integers.Int.repr 15) CC.tint) CC.tuint,
     .Eaddrof (.Evar Arm64ProgramFixture.___a64_n CC.tuchar) (CC.tptr CC.tuchar),
     .Eaddrof (.Evar Arm64ProgramFixture.___a64_z CC.tuchar) (CC.tptr CC.tuchar),
     .Eaddrof (.Evar Arm64ProgramFixture.___a64_c CC.tuchar) (CC.tptr CC.tuchar),
     .Eaddrof (.Evar Arm64ProgramFixture.___a64_v CC.tuchar) (CC.tptr CC.tuchar)] := rfl

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

private def flagExpr (i : Fin 4) : CC.Expr :=
  .Eaddrof (.Evar (Arm64ProgramEntryBody.flagName i) CC.tuchar) (CC.tptr CC.tuchar)

private theorem flag_eval {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 4) :
    CC.doEvalExpr world (allocation initial).1 le m (flagExpr i) = some (.Vptr (storage.flags i).block 0) := by
  simp only [flagExpr,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,flag_binding storage i]
  rfl

private def remainderExpr : CC.Expr := .Ebinop .Omod
  (.Etempvar Arm64ProgramFixture._t'161 CC.tuint) (.Econst_int (CC.Integers.Int.repr 15) CC.tint) CC.tuint

theorem remainder_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (value : BitVec 32) :
    CC.doEvalExpr world e (markTemps le value) m remainderExpr = some (.Vint (value % (15#32))) := by
  simp +decide only [remainderExpr,CC.doEvalExpr,markTemps,CC.PTree.gss,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semMod,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.tuint,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.modu,CC.Integers.MI.modu,
    CC.Cop.castIntInt,ite_false]
  rfl

/-- The real linked call receives the C remainder and the four allocated
flag addresses, with the actual original caller continuation. -/
theorem call_step {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 32) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile conditionCall k (allocation initial).1
        (markTemps le value) m) CC.E0
      (.Callstate (.Internal Arm64ConditionAll.handler)
        (Arm64ConditionAll.arguments (code value).val (fun i => (storage.flags i).block))
        (.Kcall (some Arm64ProgramFixture._t'134) Arm64ProgramFixture.f_arm64_execute_compile
          (allocation initial).1 (markTemps le value) k) m) := by
  have binding : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_condition =
      some (CC.Positive.ofNat 69) ∧ CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 69) =
        some (.Internal Arm64ConditionAll.handler) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [call_source]
  apply CC.Step.call
    (tyargs := [CC.tulong,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar])
    (tyres := CC.tint) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 69) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    change CC.doEvalExprlist world (allocation initial).1 (markTemps le value) m
      [remainderExpr,flagExpr 0,flagExpr 1,flagExpr 2,flagExpr 3]
      [CC.tulong,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar,CC.tptr CC.tuchar] = _
    refine eval_cons (remainder_eval _ _ _ value) ?_ ?_
    · change some (CC.Val.Vlong (CC.Integers.Int64.repr
        (CC.Integers.Int.unsigned (value % (15#32))))) = _
      simp only [CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int.unsigned,
        CC.Integers.MI.unsigned,BitVec.ofInt_natCast,BitVec.toNat_umod,BitVec.toNat_ofNat,code]
    refine eval_cons (flag_eval storage _ 0) (by rfl) ?_
    refine eval_cons (flag_eval storage _ 1) (by rfl) ?_
    refine eval_cons (flag_eval storage _ 2) (by rfl) ?_
    exact eval_cons (flag_eval storage _ 3) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

def truth (value : BitVec 32) (s : Reference.AArch64.State) : BitVec 32 :=
  if ConditionHolds (BitVec.ofNat 4 (code value).val) s.machine then 1#32 else 0#32

def conditionTemps (le : CC.TempEnv) (value : BitVec 32) (s : Reference.AArch64.State) : CC.TempEnv :=
  (markTemps le value).set Arm64ProgramFixture._t'134 (.Vint (truth value s))

/-- Complete the actual linked condition function and its true caller return.
The source loads follow from represented allocated storage. -/
theorem invoke {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 32) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile conditionCall k (allocation initial).1
        (markTemps le value) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (conditionTemps le value s) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'134) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 (markTemps le value) k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile conditionCall k (allocation initial).1
        (markTemps le value) m)
      (.Callstate (.Internal Arm64ConditionAll.handler)
        (Arm64ConditionAll.arguments (code value).val (fun i => (storage.flags i).block)) cont m) :=
    .step (by rw [call_source]; trivial) (call_step storage le k value) (.refl _)
  obtain ⟨count,run⟩ := Arm64ConditionAll.from_storage storage s represented world (code value) cont
  have leave : InternalRun world 1
      (.Returnstate (.Vint (truth value s)) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (conditionTemps le value s) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(enter.trans run).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryJcc
