import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterAddress

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterWord
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  mask : CC.Stmt
  action : CC.Stmt
  other : CC.Stmt
  fast : CC.Stmt
  assignment : CC.Stmt
  after : CC.Stmt
private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original aligned word store changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterAddress.after)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let rest ← peel outer[1]! ``CC.Stmt.Ssequence 2
    let choice ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    let fast ← peel choice[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_aligned_word_store
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,rest[0]!,choice[2]!,choice[1]!,fast[0]!,fast[1]!])

noncomputable def fast : CC.Stmt := parts.fast
noncomputable def assignment : CC.Stmt := parts.assignment
noncomputable def after : CC.Stmt := parts.after
noncomputable def lhs : CC.Expr := .Ederef
  (.Ebinop .Oadd
    (.Efield (.Evar ___a64_stack (CC.tvolatile (.Tunion __5191 CC.noattr)))
      _q (CC.tvolatile (CC.tarray CC.tulong 4)))
    (.Ebinop .Oshr (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tulong)
      (.Econst_int (CC.Integers.Int.repr 3) CC.tint) CC.tulong) (CC.tptr CC.tulong)) CC.tulong
noncomputable def rhs : CC.Expr := .Etempvar ___a64_stw_value CC.tulong

theorem source : Arm64CiliumCallerMemoryWriterAddress.after = .Ssequence parts.mask
    (.Ssequence parts.action
      (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_stw_action CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) fast parts.other)) := rfl
theorem fast_source : fast = .Ssequence assignment after := rfl
theorem assignment_source : assignment = .Sassign lhs rhs := rfl

private noncomputable def stackComposite : CC.Composite := by
  run_tac do
    let info ← Lean.getConstInfo ``Arm64CiliumCallerHeaderTailValues.union_layout
    let ty := info.type
    unless ty.isAppOfArity ``And 2 do throwError "original layout certificate is not a conjunction"
    let lookup := ty.getAppArgs[0]!
    unless lookup.isAppOfArity ``Eq 3 do throwError "original stack lookup is not an equality"
    let rhs := lookup.getAppArgs[2]!
    unless rhs.isAppOfArity ``Option.some 2 do throwError "original checked stack composite absent"
    Lean.Elab.Tactic.closeMainGoal `original_checked_stack_composite rhs.getAppArgs[1]!

private theorem stack_lookup : ge.genv_cenv.get __5191 = some stackComposite := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private theorem field_offset :
    CC.unionFieldOffset ge.genv_cenv _q stackComposite.co_members = .OK (0,.Full) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem stack_layout :
    ge.genv_cenv.get __5191 = some stackComposite ∧
    CC.unionFieldOffset ge.genv_cenv _q stackComposite.co_members = .OK (0,.Full) :=
  ⟨stack_lookup,field_offset⟩

private noncomputable def stackTy : CC.Ty := CC.tvolatile (.Tunion __5191 CC.noattr)
private noncomputable def fieldTy : CC.Ty := CC.tvolatile (CC.tarray CC.tulong 4)
private noncomputable def fieldExpr : CC.Expr := .Efield (.Evar ___a64_stack stackTy) _q fieldTy
private noncomputable def shiftExpr : CC.Expr :=
  .Ebinop .Oshr (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tulong)
    (.Econst_int (CC.Integers.Int.repr 3) CC.tint) CC.tulong
private noncomputable def addressExpr : CC.Expr := .Ebinop .Oadd fieldExpr shiftExpr (CC.tptr CC.tulong)

private theorem field_value {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem) :
    CC.doEvalExpr ge (allocation m).1 le before fieldExpr = some (.Vptr (header.block 0) 0) := by
  have binding : (allocation m).1.get ___a64_stack = some (header.block 0,stackTy) := header.binding 0
  have stackValue : CC.doEvalExpr ge (allocation m).1 le before (.Evar ___a64_stack stackTy) =
      some (.Vptr (header.block 0) 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,binding,ite_true]
    rfl
  have fieldLoc : CC.lvalOfField ge stackTy _q (.Vptr (header.block 0) 0) =
      some (header.block 0,0,.Full) := by
    simp only [stackTy,CC.lvalOfField,CC.tvolatile,CC.tattr,stack_lookup,field_offset]
    rfl
  rw [fieldExpr,CC.doEvalExpr,stackValue]
  simp only [CC.typeof,fieldLoc] <;> rfl

private theorem shift_value (e : CC.Env) (le : CC.TempEnv) (before : CC.Mem)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le before shiftExpr = some (.Vlong (0#64)) := by
  simp only [shiftExpr,CC.doEvalExpr,index]
  rfl

private theorem lhs_form : lhs = .Ederef addressExpr CC.tulong := rfl

/-- Small expression certificates retain the original q[index>>3] address,
actual linked lookup and actual allocated union binding, with no address oracle. -/
theorem target {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64))) :
    CC.doEvalLvalue ge (allocation m).1 le before lhs = some (header.block 0,0,.Full) := by
  have addressValue : CC.doEvalExpr ge (allocation m).1 le before addressExpr =
      some (.Vptr (header.block 0) 0) := by
    rw [addressExpr,CC.doEvalExpr,field_value header le before,shift_value (allocation m).1 le before index]
    rfl
  rw [lhs_form,CC.doEvalLvalue,addressValue]

/-- Current permissions derive the original aligned64 store inside the actual
32-byte stack union; no successful-store premise or earlier allocator bridge. -/
theorem writable {m before : CC.Mem} (header : Storage m)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before .Mint64 (header.block 0) 0 .Writable = true := by
  have owned := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 0)).2.2
  have range : CC.Mem.rangePerm (allocation m).2 (header.block 0) 0 32 .Cur .Freeable = true := owned
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have hi : o < (32 : Int) := by
      change o < 8 at upper
      omega
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ range o lower hi)
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · rfl

structure Store {m before : CC.Mem} (header : Storage m) (value : BitVec 64) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 before (header.block 0) 0 (.Vlong value) = some after
  read : CC.Mem.load .Mint64 after (header.block 0) 0 = some (.Vlong value)
  otherBlocks : ∀ b,b ≠ header.block 0 → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o
  caller : FrameBelow m.nextblock before after
  access : after.access = before.access
  frontier : after.nextblock = before.nextblock

theorem write {m before : CC.Mem} (header : Storage m) (value : BitVec 64)
    (access : before.access = (allocation m).2.access) : Nonempty (Store (before := before) header value) := by
  have valid := writable header access
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 before (header.block 0) 0 (.Vlong value) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 0)).1
  exact ⟨⟨after,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩

theorem bound_frame {m before : CC.Mem} {header : Storage m} {value : BitVec 64}
    (result : Store (before := before) header value)
    {id : CC.Ident} {ty : CC.Ty} {block : CC.Block}
    (binding : (allocation m).1.get id = some (block,ty)) (different : id ≠ ___a64_stack) :
    ∀ c o,CC.Mem.load c result.after block o = CC.Mem.load c before block o :=
  result.otherBlocks block ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding (header.binding 0) different)

theorem cache_values {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (result : Store (before := cache.after) header base) :
    CC.Mem.load .Mint64 result.after (locals.block 3) 0 = some (.Vlong base) ∧
    CC.Mem.load .Mint8unsigned result.after (locals.block 5) 0 = some (.Vint (1#32)) := by
  exact ⟨(bound_frame result (locals.binding 3) (by decide +kernel) .Mint64 0).trans cache.returnRead,
    (bound_frame result (locals.binding 5) (by decide +kernel) .Mint8unsigned 0).trans cache.validRead⟩

/-- Consume precisely the derived stack store in the original assignment.
TempEnv is unchanged and the real source value is an explicit temporary invariant. -/
theorem execute {m before : CC.Mem} (header : Storage m) (value : BitVec 64)
    (result : Store (before := before) header value) (le : CC.TempEnv)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (stored : le.get ___a64_stw_value = some (.Vlong value)) (k : CC.Cont) :
    InternalRun ge 1 (.State procedure assignment k (allocation m).1 le before)
      (.State procedure .Sskip k (allocation m).1 le result.after) := by
  have rhsEval : CC.doEvalExpr ge (allocation m).1 le before rhs = some (.Vlong value) := stored
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tulong before (header.block 0) 0 .Full (.Vlong value) =
      some result.after := result.stored
  have step : CC.Step2 ge (.State procedure assignment k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le result.after) := by
    rw [assignment_source]
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _ (target header le before index)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ rhsEval
    · rfl
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure assignment k (allocation m).1 le before) := by
    rw [assignment_source];trivial
  exact .step internal step (.refl _)

/-- Enter the original fast sequence, execute its actual word store, and reach
its original tag/unmaterialization continuation, using the same derived memory. -/
theorem advance {m before : CC.Mem} (header : Storage m) (value : BitVec 64)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (stored : le.get ___a64_stw_value = some (.Vlong value)) (k : CC.Cont) :
    ∃ result : Store (before := before) header value,
      InternalRun ge 3 (.State procedure fast k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le result.after) := by
  obtain ⟨result⟩ := write header value access
  have assigned := execute header value result le index stored (.Kseq after k)
  refine ⟨result,?_⟩
  rw [fast_source]
  exact .step trivial (CC.Step.seq _ _ _ _ _ _ _)
    (assigned.trans (.step trivial (CC.Step.skip_seq _ _ _ _ _ _) (.refl _)))

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterWord
