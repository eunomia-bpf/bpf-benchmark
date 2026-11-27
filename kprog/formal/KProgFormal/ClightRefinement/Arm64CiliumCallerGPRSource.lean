import KProgFormal.ClightRefinement.Arm64CiliumCallerDefaults
import KProgFormal.ClightRefinement.Arm64ProducerRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64Producer (RegisterDeclaration)

private noncomputable def declarations : Array (CC.Stmt × RegisterDeclaration) := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller GPR source shape changed"
      pure node.getAppArgs
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerDefaults.after)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:31] do
      let stage ← peel current ``CC.Stmt.Ssequence 2
      let word ← peel stage[0]! ``CC.Stmt.Ssequence 2
      let tag ← peel stage[1]! ``CC.Stmt.Ssequence 2
      let branch ← peel word[0]! ``CC.Stmt.Sifthenelse 3
      let comparison ← peel branch[0]! ``CC.Expr.Ebinop 4
      let index ← peel comparison[1]! ``CC.Expr.Econst_int 2
      let wordStore ← peel word[1]! ``CC.Stmt.Sassign 2
      let wordField ← peel wordStore[0]! ``CC.Expr.Efield 3
      let wordVar ← peel wordField[0]! ``CC.Expr.Evar 2
      let tagStore ← peel tag[0]! ``CC.Stmt.Sassign 2
      let tagVar ← peel tagStore[0]! ``CC.Expr.Evar 2
      let zero ← peel branch[1]! ``CC.Stmt.Sset 2
      let provided ← peel branch[2]! ``CC.Stmt.Ssequence 2
      let call ← peel provided[0]! ``CC.Stmt.Scall 3
      let destination ← peel call[0]! ``Option.some 2
      let declaration ← Lean.Meta.mkAppM ``RegisterDeclaration.mk
        #[index[0]!,wordVar[0]!,tagVar[0]!,zero[0]!,destination[1]!,tag[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[current,declaration])
      current := tag[1]!
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt,Lean.mkConst ``RegisterDeclaration]
    Lean.Elab.Tactic.closeMainGoal `actual_caller_register_declarations
      (← Lean.Meta.mkArrayLit rowType rows.toList)

noncomputable def declaration (i : Fin 31) : RegisterDeclaration :=
  (declarations[i.val]'(by change i.val < 31;exact i.isLt)).2
noncomputable def stage (i : Fin 31) : CC.Stmt :=
  (declarations[i.val]'(by change i.val < 31;exact i.isLt)).1
noncomputable def after : CC.Stmt := (declaration 30).rest

/-- The mature syntactic schema is checked against EACH whole original
statement,including the actual callee,types,temporaries,word/tag and suffix. -/
theorem source : ∀ i : Fin 31,stage i = (declaration i).body := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem first_source : stage 0 = Arm64CiliumCallerDefaults.after := rfl
theorem last_source : after = Arm64CiliumCallerInitializers.start := rfl
theorem chain : ∀ i : Fin 30,
    (declaration ⟨i.val,by omega⟩).rest = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem indices : ∀ i : Fin 31,(declaration i).index = CC.Integers.Int.repr i.val := by decide +kernel
theorem branches : ∀ i : Fin 31,
    CC.Integers.Int.eq (declaration i).index (30#32) = (i.val==30) := by decide +kernel
theorem cell_names : ∀ i : Fin 31,
    (declaration i).word = Arm64CiliumCallerInitializers.name false i ∧
    (declaration i).tag = Arm64CiliumCallerInitializers.name true i := by decide +kernel
theorem temporaries_distinct : ∀ i : Fin 31,(declaration i).inputTemp ≠ (declaration i).resultTemp := by decide +kernel

private theorem resolved :
    (CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input).bind
      (CC.Genv.findFunctPtr ge.genv_genv) = some Arm64OriginCache.inputFunction := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem callee_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some Arm64OriginCache.inputFunction :=
  (Option.bind_eq_some_iff (x := CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input)
    (f := CC.Genv.findFunctPtr ge.genv_genv) (b := Arm64OriginCache.inputFunction)).mp resolved

private theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
  have absent : Arm64Entry._native_lab_entry_input ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent

def inputIndex (i : Fin 30) : Fin 31 := ⟨i.val,by have := i.isLt;omega⟩
noncomputable def continuation {m : CC.Mem} (i : Fin 31) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  let d := declaration i
  .Kcall (some d.inputTemp) procedure (allocation m).1 le
    (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))

/-- SAME actual caller environment,original source and actual global callee.
The existing generic Clight lemma supplies5internal steps;no old producer
allocator,successful callback or returned input word is assumed. -/
theorem call_ready {m before : CC.Mem} (i : Fin 30) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 5
      (.State procedure (stage (inputIndex i)) k (allocation m).1 le before)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (m := m) (inputIndex i) le k) before) := by
  obtain ⟨block,symbol,function⟩ := callee_lookup
  have different : CC.Integers.Int.eq (declaration (inputIndex i)).index (30#32) = false := by
    rw [branches]
    exact beq_eq_false_iff_ne.mpr (Nat.ne_of_lt i.isLt)
  rw [source]
  have run := Arm64Producer.declaration_call_body ge procedure (allocation m).1
    block ⟨symbol,function⟩ (declaration (inputIndex i)) before le k (unshadowed m) different
  exact internalRun_of_steps run.2 run.1

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSource
