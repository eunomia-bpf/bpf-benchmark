import KProgFormal.ClightRefinement.Arm64CiliumCallerTableEntry
import KProgFormal.ClightRefinement.Arm64ProducerFlags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerFlags
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64Producer (FlagDeclaration flagWord)

/-- Extract all four original calls/stores from the SAME table successor. -/
private noncomputable def declarations : Array (CC.Stmt × FlagDeclaration) := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller flag source changed"
      pure node.getAppArgs
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerInitializers.afterTables)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:4] do
      let outer ← peel current ``CC.Stmt.Ssequence 2
      let inner ← peel outer[0]! ``CC.Stmt.Ssequence 2
      let call ← peel inner[0]! ``CC.Stmt.Scall 3
      let result ← peel call[0]! ``Option.some 2
      let store ← peel inner[1]! ``CC.Stmt.Sassign 2
      let target ← peel store[0]! ``CC.Expr.Evar 2
      let d ← Lean.Meta.mkAppM ``FlagDeclaration.mk #[target[0]!,result[1]!,outer[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[current,d])
      current := outer[1]!
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt,Lean.mkConst ``FlagDeclaration]
    Lean.Elab.Tactic.closeMainGoal `actual_caller_flags (← Lean.Meta.mkArrayLit rowType rows.toList)

noncomputable def declaration (i : Fin 4) : FlagDeclaration :=
  (declarations[i.val]'(by change i.val < 4;exact i.isLt)).2
noncomputable def stage (i : Fin 4) : CC.Stmt :=
  (declarations[i.val]'(by change i.val < 4;exact i.isLt)).1
noncomputable def after : CC.Stmt := (declaration 3).rest

theorem source : ∀ i : Fin 4,stage i = (declaration i).body := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem first_source : stage 0 = Arm64CiliumCallerInitializers.afterTables := rfl
theorem chain : ∀ i : Fin 3,
    (declaration ⟨i.val,by omega⟩).rest = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem names :
    (declaration 0).name = ___a64_n ∧ (declaration 1).name = ___a64_z ∧
    (declaration 2).name = ___a64_c ∧ (declaration 3).name = ___a64_v := by decide +kernel
theorem declared : ∀ i : Fin 4,((declaration i).name,CC.tuchar) ∈ procedure.fn_vars := by decide +kernel
theorem distinct : ∀ i j : Fin 4,i ≠ j → (declaration i).name ≠ (declaration j).name := by decide +kernel

noncomputable def vectorStart : CC.Stmt := by
  run_tac do
    let node ← Lean.Elab.Term.elabTerm (← `(after)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node)
    unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual LR/vector sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_vector_start exposed.getAppArgs[1]!

theorem after_source : after =
    .Ssequence (.Sassign (.Evar ___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint)) vectorStart := rfl

noncomputable def continuation {m : CC.Mem} (i : Fin 4) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  (declaration i).continuationFor procedure (allocation m).1 le k

private theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
  have absent : Arm64Entry._native_lab_entry_input ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent

/-- Three original internal steps reach the actual global input callee. -/
theorem call_ready {m before : CC.Mem} (i : Fin 4) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 3 (.State procedure (stage i) k (allocation m).1 le before)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (m := m) i le k) before) := by
  obtain ⟨block,symbol,function⟩ := Arm64CiliumCallerGPRSource.callee_lookup
  have run := Arm64Producer.flag_call_body ge procedure (allocation m).1 block ⟨symbol,function⟩
    (declaration i) before le k (unshadowed m)
  rw [source]
  exact internalRun_of_steps run.2 run.1

structure Store (m supplied : CC.Mem) (i : Fin 4) (value : BitVec 64) where
  block : CC.Block
  after : CC.Mem
  binding : (allocation m).1.get (declaration i).name = some (block,CC.tuchar)
  stored : CC.Mem.storev .Mint8unsigned supplied (.Vptr block 0)
    (.Vint (flagWord value)) = some after
  read : CC.Mem.load .Mint8unsigned after block 0 = some (.Vint (flagWord value))
  bit : flagWord value = (0#32) ∨ flagWord value = (1#32)
  otherBlocks : ∀ b,b ≠ block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Current write rights and the actual795-local binding derive the real
byte store;the old producer allocation is never an input to this witness. -/
theorem store {m supplied : CC.Mem} (i : Fin 4) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) : Nonempty (Store m supplied i value) := by
  have noDuplicates : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  obtain ⟨block,binding⟩ :=
    allocated_local_binding (Arm64CiliumCallerLink.allocated m) noDuplicates (declared i)
  have storage := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  have owned := storage.2.2
  have valid : CC.Mem.validAccess supplied .Mint8unsigned block 0 .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,by decide⟩
    apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned o lower (by change o < (1 : Int) at upper ⊢;exact upper))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint8unsigned supplied block 0
      (.Vint (flagWord value)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have read : CC.Mem.load .Mint8unsigned after block 0 = some (.Vint (flagWord value)) := by
    have loaded := CC.Mem.load_store_same stored
    rcases Arm64Producer.flag_word_bit value with zero | one <;>
      simpa [CC.Val.loadResult,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext, *] using loaded
  exact ⟨⟨block,after,binding,stored,read,Arm64Producer.flag_word_bit value,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store storage.1 stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩

/-- The mature four-step return/store body runs with the actual caller env. -/
theorem writeback {m supplied : CC.Mem} (i : Fin 4) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Store m supplied i value,
      InternalRun ge 4 (.Returnstate (.Vlong value) (continuation (m := m) i le k) supplied)
        (.State procedure (declaration i).rest k (allocation m).1
          (le.set (declaration i).inputTemp (.Vlong value)) writes.after) := by
  obtain ⟨writes⟩ := store i value access
  have run := Arm64Producer.flag_return_body ge procedure (allocation m).1 (declaration i)
    supplied writes.after le k value writes.block writes.binding writes.stored
  exact ⟨writes,internalRun_of_steps run.2 run.1⟩

/-- A SAME actual call,explicit external outcome and actual byte store;
the full trace and supplied heap are retained rather than replaced. -/
theorem input_returns {m before supplied : CC.Mem} (i : Fin 4) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ writes : Store m supplied i value,
      CC.Star (CC.Step2 ge) (.State procedure (stage i) k (allocation m).1 le before)
        trace (.State procedure (declaration i).rest k (allocation m).1
          (le.set (declaration i).inputTemp (.Vlong value)) writes.after) := by
  obtain ⟨writes,suffix⟩ := writeback i value access le k
  have externalStep : CC.Star (CC.Step2 ge)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (continuation (m := m) i le k) before)
      trace (.Returnstate (.Vlong value) (continuation (m := m) i le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0,CC.Eapp])
  refine ⟨writes,?_⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (call_ready i le k).sound (star_trans externalStep suffix.sound)

end KProgFormal.ClightRefinement.Arm64CiliumCallerFlags
