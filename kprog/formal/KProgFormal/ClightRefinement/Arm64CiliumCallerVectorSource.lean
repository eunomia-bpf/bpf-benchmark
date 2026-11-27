import KProgFormal.ClightRefinement.Arm64CiliumCallerLR
import KProgFormal.ClightRefinement.Arm64ProducerVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def vectorTag : CC.Ident := __5189
noncomputable def vectorType : CC.Ty := Arm64Producer.vectorTypeFor vectorTag
noncomputable def vectorArrayType : CC.Ty := Arm64Producer.vectorArrayTypeFor vectorTag

private noncomputable def rows : Array (CC.Stmt × CC.Ident × CC.Stmt) := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller vector source changed"
      pure node.getAppArgs
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerFlags.vectorStart)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:64] do
      let outer ← peel current ``CC.Stmt.Ssequence 2
      let inner ← peel outer[0]! ``CC.Stmt.Ssequence 2
      let call ← peel inner[0]! ``CC.Stmt.Scall 3
      let result ← peel call[0]! ``Option.some 2
      let pair ← Lean.Meta.mkAppM ``Prod.mk #[result[1]!,outer[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[current,pair])
      current := outer[1]!
    let tailType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Ident,Lean.mkConst ``CC.Stmt]
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt,tailType]
    Lean.Elab.Tactic.closeMainGoal `actual_caller_vector_sites (← Lean.Meta.mkArrayLit rowType rows.toList)

noncomputable def stage (i : Fin 64) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 64;exact i.isLt)).1
noncomputable def temporary (i : Fin 64) : CC.Ident :=
  (rows[i.val]'(by change i.val < 64;exact i.isLt)).2.1
noncomputable def rest (i : Fin 64) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 64;exact i.isLt)).2.2
noncomputable def after : CC.Stmt := rest 63

/-- EACH whole original vector call/store/target/type/index/temporary/suffix
matches the mature schema with the actual caller's anonymous vector tag. -/
theorem source : ∀ i : Fin 64,stage i =
    .Ssequence (Arm64Producer.vectorInitializerFor vectorTag (temporary i) i) (rest i) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem first_source : stage 0 = Arm64CiliumCallerFlags.vectorStart := rfl
theorem chain : ∀ i : Fin 63,rest ⟨i.val,by omega⟩ = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

private noncomputable def composite : CC.Composite :=
  (ge.genv_cenv.get vectorTag).get (by decide +kernel)

theorem layout_data :
    ge.genv_cenv.get vectorTag = some composite ∧ composite.co_sizeof = 16 ∧
    (∀ i : Fin 64,CC.fieldOffset ge.genv_cenv (Arm64Producer.vectorField i) composite.co_members =
      .OK (Arm64Producer.vectorFieldOffset i,.Full)) := by decide +kernel

theorem layout : Nonempty (Arm64Producer.VectorLayout ge vectorTag) :=
  ⟨⟨composite,layout_data.1,layout_data.2.1,layout_data.2.2⟩⟩
theorem array_size : CC.sizeof ge.genv_cenv vectorArrayType = 512 := by decide +kernel
theorem declared : (Arm64Entry.___a64_vectors,vectorArrayType) ∈ procedure.fn_vars := by decide +kernel

structure Storage (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get Arm64Entry.___a64_vectors = some (block,vectorArrayType)
  fresh : m.nextblock.toNat ≤ block.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0 512 .Cur .Writable = true

theorem storage (m : CC.Mem) : Nonempty (Storage m) := by
  have noDuplicates : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) noDuplicates declared
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  have range : CC.Mem.rangePerm (allocation m).2 block 0 512 .Cur .Freeable = true := by
    simpa only [array_size] using owned.2.2
  exact ⟨⟨block,binding,owned.1,CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)⟩⟩

noncomputable def continuation {m : CC.Mem} (i : Fin 64) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  Arm64Producer.vectorContinuationFor procedure (allocation m).1 vectorTag (temporary i) i (rest i) le k

/-- Actual ge callee and actual environment reach the original provider
without an old producer allocator or an assumed successful vector read. -/
theorem call_ready {m before : CC.Mem} (i : Fin 64) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 3 (.State procedure (stage i) k (allocation m).1 le before)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (m := m) i le k) before) := by
  have absent : Arm64Entry._native_lab_entry_input ∉ CC.varNames procedure.fn_vars := by decide +kernel
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv,CC.PTree.gempty] using
      CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent
  obtain ⟨block,symbol,function⟩ := Arm64CiliumCallerGPRSource.callee_lookup
  have run := Arm64Producer.vector_call_body ge procedure (allocation m).1 block ⟨symbol,function⟩
    vectorTag (temporary i) i (rest i) before le k unshadowed
  rw [source]
  exact internalRun_of_steps run.2 run.1

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSource
