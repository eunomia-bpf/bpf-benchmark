import KProgFormal.ClightRefinement.Arm64CiliumCallerABIEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerContextGPR
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def name (i : Fin 3) : CC.Ident :=
  if i.val=0 then ___a64_x0 else if i.val=1 then ___a64_x30_tag else ___a64_x0_tag
noncomputable def allocType (i : Fin 3) : CC.Ty :=
  if i.val=0 then .Tunion _arm64_sim_gpr CC.noattr else CC.tuchar
def assignType (i : Fin 3) : CC.Ty := if i.val=0 then CC.tptr CC.tvoid else CC.tuchar
def chunk (i : Fin 3) : CC.Chunk := if i.val=0 then .Mint64 else .Mint8unsigned
def value (ctx : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 3) : CC.Val :=
  if i.val=0 then .Vptr ctx ofs else if i.val=1 then .Vint (10#32) else .Vint (1#32)
noncomputable def lhs (i : Fin 3) : CC.Expr :=
  if i.val=0 then .Efield (.Evar (name i) (allocType i)) _ptr (CC.tptr CC.tvoid)
  else .Evar (name i) (allocType i)
noncomputable def rhs (i : Fin 3) : CC.Expr :=
  if i.val=0 then .Ecast (.Etempvar _ctx (CC.tptr (.Tstruct _xdp_md CC.noattr))) (CC.tptr CC.tvoid)
  else .Econst_int (if i.val=1 then 10#32 else 1#32) CC.tuint
noncomputable def row (i : Fin 3) : CC.Stmt := .Sassign (lhs i) (rhs i)

noncomputable def after : CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerABIBase.after)) none
    for _ in [:3] do
      let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual R0 context/tag initializer sequence changed"
      body := exposed.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_after_context_gpr body

theorem source : Arm64CiliumCallerABIBase.after =
    (List.ofFn row).foldr CC.Stmt.Ssequence after := rfl

private noncomputable def composite : CC.Composite :=
  (ge.genv_cenv.get _arm64_sim_gpr).get (by decide +kernel)
theorem pointer_layout :
    ge.genv_cenv.get _arm64_sim_gpr = some composite ∧
    CC.unionFieldOffset ge.genv_cenv _ptr composite.co_members = .OK (0,.Full) := by decide +kernel
theorem declared : ∀ i : Fin 3,(name i,allocType i) ∈ procedure.fn_vars := by decide +kernel
theorem names_distinct : ∀ i j : Fin 3,i ≠ j → name i ≠ name j := by decide +kernel
private theorem modes : ∀ i : Fin 3,CC.accessMode (assignType i) = .By_value (chunk i) ∧
    CC.sizeof ge.genv_cenv (allocType i) = CC.sizeChunk (chunk i) := by decide +kernel
private theorem cases3 : ∀ i : Fin 3,i=0 ∨ i=1 ∨ i=2 := by decide +kernel

structure Storage (m : CC.Mem) where
  block : Fin 3 → CC.Block
  binding : ∀ i,(allocation m).1.get (name i) = some (block i,allocType i)

theorem storage (m : CC.Mem) : Nonempty (Storage m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have witness : ∀ i,∃ block,(allocation m).1.get (name i) = some (block,allocType i) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) names (declared i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

theorem separate {m : CC.Mem} (resource : Storage m) {i j : Fin 3} (different : i ≠ j) :
    resource.block i ≠ resource.block j :=
  (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ (resource.binding i) (resource.binding j) (names_distinct i j different)

private theorem writable {m before : CC.Mem} (resource : Storage m) (i : Fin 3)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before (chunk i) (resource.block i) 0 .Writable = true := by
  have owned := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (resource.binding i)).2.2
  rw [(modes i).2] at owned
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned o lower (by simpa only [Int.zero_add] using upper))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · rcases cases3 i with rfl | rfl | rfl <;> decide

private theorem lhs_eval {m : CC.Mem} (resource : Storage m) (le : CC.TempEnv) (before : CC.Mem) (i : Fin 3) :
    CC.doEvalLvalue ge (allocation m).1 le before (lhs i) = some (resource.block i,0,.Full)  := by
  have b0 : (allocation m).1.get ___a64_x0 =
      some (resource.block 0,.Tunion _arm64_sim_gpr CC.noattr) := resource.binding 0
  have b1 : (allocation m).1.get ___a64_x30_tag = some (resource.block 1,CC.tuchar) := resource.binding 1
  have b2 : (allocation m).1.get ___a64_x0_tag = some (resource.block 2,CC.tuchar) := resource.binding 2
  rcases cases3 i with rfl | rfl | rfl
  all_goals simp [lhs,name,allocType,CC.doEvalLvalue,CC.doEvalExpr,CC.lvalOfVar,
    b0,b1,b2,CC.lvalOfField,CC.doDerefLoc,CC.accessMode,CC.typeof,
    pointer_layout.1,pointer_layout.2,CC.Integers.Ptrofs.zero,CC.Integers.Ptrofs.add,
    CC.Integers.Ptrofs.repr,CC.Integers.MI.zero,CC.Integers.MI.add,CC.Integers.MI.repr]
  all_goals rfl

private theorem lhs_type : ∀ i : Fin 3,CC.typeof (lhs i) = assignType i := by decide +kernel

private theorem casts (ctx : CC.Block) (ofs : CC.Integers.Ptrofs) (before : CC.Mem) :
    ∀ i : Fin 3,
      CC.Cop.semCast (value ctx ofs i) (CC.typeof (rhs i)) (assignType i) before = some (value ctx ofs i) ∧
      CC.Val.loadResult (chunk i) (value ctx ofs i) = value ctx ofs i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem store_row {m before : CC.Mem} (resource : Storage m) (i : Fin 3)
    (access : before.access = (allocation m).2.access) (ctx : CC.Block) (ofs : CC.Integers.Ptrofs)
    (le : CC.TempEnv) (k : CC.Cont) (input : le.get _ctx = some (.Vptr ctx ofs)) :
    ∃ afterMem,
      InternalRun ge 1 (.State procedure (row i) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le afterMem) ∧
      CC.Mem.load (chunk i) afterMem (resource.block i) 0 = some (value ctx ofs i) ∧
      (∀ b,b ≠ resource.block i → ∀ c o,CC.Mem.load c afterMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before afterMem ∧ afterMem.access = before.access ∧
      afterMem.nextblock = before.nextblock := by
  have valid := writable resource i access
  obtain ⟨afterMem,stored⟩ : ∃ afterMem,CC.Mem.store (chunk i) before (resource.block i) 0
      (value ctx ofs i) = some afterMem := by
    simp only [CC.Mem.store,valid,ite_true];exact ⟨_,rfl⟩
  have assigned : CC.doAssignLoc ge.genv_cenv (assignType i) before (resource.block i) 0 .Full
      (value ctx ofs i) = some afterMem := by
    simp only [CC.doAssignLoc,(modes i).1];exact stored
  have evalRhs : CC.doEvalExpr ge (allocation m).1 le before (rhs i) = some (value ctx ofs i) := by
    rcases cases3 i with rfl | rfl | rfl
    all_goals simp [rhs,value,CC.doEvalExpr,input,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tptr]
  have step : CC.Step2 ge (.State procedure (row i) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le afterMem) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _ (lhs_eval resource le before i)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ evalRhs
    · rw [lhs_type];exact (casts ctx ofs before i).1
    · rw [lhs_type];exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have read := CC.Mem.load_store_same stored
  rw [(casts ctx ofs before i).2] at read
  have internal : InternalState (.State procedure (row i) k (allocation m).1 le before) := by
    unfold row;trivial
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (resource.binding i)).1
  exact ⟨afterMem,.step internal step (.refl _),read,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

private theorem visit {m before : CC.Mem} (resource : Storage m) (i : Fin 3)
    (access : before.access = (allocation m).2.access) (ctx : CC.Block) (ofs : CC.Integers.Ptrofs)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) (input : le.get _ctx = some (.Vptr ctx ofs)) :
    ∃ afterMem,
      InternalRun ge 3 (.State procedure (.Ssequence (row i) rest) k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le afterMem) ∧
      CC.Mem.load (chunk i) afterMem (resource.block i) 0 = some (value ctx ofs i) ∧
      (∀ b,b ≠ resource.block i → ∀ c o,CC.Mem.load c afterMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before afterMem ∧ afterMem.access = before.access ∧
      afterMem.nextblock = before.nextblock := by
  obtain ⟨afterMem,assigned,read,other,frame,rights,frontier⟩ :=
    store_row resource i access ctx ofs le (.Kseq rest k) input
  refine ⟨afterMem,?_,read,other,frame,rights,frontier⟩
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (assigned.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- Actual R0 pointer, R30 tag10, R0 tag1 stores; all other blocks retain their loads. -/
theorem execute {m before : CC.Mem} (resource : Storage m)
    (access : before.access = (allocation m).2.access) (ctx : CC.Block) (ofs : CC.Integers.Ptrofs)
    (le : CC.TempEnv) (k : CC.Cont) (input : le.get _ctx = some (.Vptr ctx ofs)) :
    ∃ finalMem,
      InternalRun ge 9 (.State procedure Arm64CiliumCallerABIBase.after k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le finalMem) ∧
      (∀ i : Fin 3,CC.Mem.load (chunk i) finalMem (resource.block i) 0 = some (value ctx ofs i)) ∧
      (∀ b,(∀ i : Fin 3,b ≠ resource.block i) → ∀ c o,
        CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  let rest1 := CC.Stmt.Ssequence (row 1) (.Ssequence (row 2) after)
  let rest2 := CC.Stmt.Ssequence (row 2) after
  obtain ⟨first,r0Run,r0Read,r0Other,r0Frame,r0Access,r0Next⟩ :=
    visit resource 0 access ctx ofs le k rest1 input
  obtain ⟨second,r30Run,r30Read,r30Other,r30Frame,r30Access,r30Next⟩ :=
    visit resource 1 (r0Access.trans access) ctx ofs le k rest2 input
  obtain ⟨finalMem,tagRun,tagRead,tagOther,tagFrame,tagAccess,tagNext⟩ :=
    visit resource 2 (r30Access.trans (r0Access.trans access)) ctx ofs le k after input
  have r0Current := (tagOther (resource.block 0) (separate resource (by decide : (0 : Fin 3) ≠ 2)) (chunk 0) 0).trans
    ((r30Other (resource.block 0) (separate resource (by decide : (0 : Fin 3) ≠ 1)) (chunk 0) 0).trans r0Read)
  have r30Current := (tagOther (resource.block 1) (separate resource (by decide : (1 : Fin 3) ≠ 2)) (chunk 1) 0).trans r30Read
  refine ⟨finalMem,?_,?_,?_,(r0Frame.trans r30Frame).trans tagFrame,
    tagAccess.trans (r30Access.trans r0Access),tagNext.trans (r30Next.trans r0Next)⟩
  · rw [source]
    exact (r0Run.trans r30Run).trans tagRun
  · intro i
    rcases cases3 i with rfl | rfl | rfl
    · exact r0Current
    · exact r30Current
    · exact tagRead
  · intro b different c o
    exact (tagOther b (different 2) c o).trans ((r30Other b (different 1) c o).trans (r0Other b (different 0) c o))

end KProgFormal.ClightRefinement.Arm64CiliumCallerContextGPR
