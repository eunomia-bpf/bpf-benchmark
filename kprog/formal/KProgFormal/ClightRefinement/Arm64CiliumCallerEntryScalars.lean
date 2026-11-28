import KProgFormal.ClightRefinement.Arm64CiliumCallerStackTags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerEntryScalars
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerDefaults (Declaration)

private noncomputable def declarations : Array Declaration := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerStackTags.afterStackTags)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:2] do
      let source ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless source.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual SP/is_xdp sequence absent"
      let assign ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source.getAppArgs[0]!)
      unless assign.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "actual SP/is_xdp assignment absent"
      let lhs := assign.getAppArgs[0]!
      unless lhs.isAppOfArity ``CC.Expr.Evar 2 do throwError "actual SP/is_xdp is not a local assignment"
      rows := rows.push (← Lean.Meta.mkAppM ``Declaration.mk
        #[lhs.getAppArgs[0]!,lhs.getAppArgs[1]!,assign.getAppArgs[1]!,
          current,source.getAppArgs[0]!,source.getAppArgs[1]!,
          ← Lean.Meta.mkEqRefl current,← Lean.Meta.mkEqRefl source.getAppArgs[0]!])
      current := source.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_sp_xdp_defaults
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

noncomputable def declaration (i : Fin 2) : Declaration :=
  declarations[i.val]'(by change i.val < 2;exact i.isLt)
noncomputable def row (i : Fin 2) : CC.Stmt := (declaration i).assign
noncomputable def name (i : Fin 2) : CC.Ident := (declaration i).name
noncomputable def ty (i : Fin 2) : CC.Ty := (declaration i).ty
noncomputable def rhs (i : Fin 2) : CC.Expr := (declaration i).rhs
noncomputable def after : CC.Stmt := (declaration 1).next
def narrow (i : Fin 2) : Bool := i.val==1
def chunk (i : Fin 2) : CC.Chunk := if narrow i then .Mint8unsigned else .Mint64
def value (i : Fin 2) : CC.Val := if narrow i then .Vint (1#32) else .Vlong (0#64)
def inputValue (i : Fin 2) : CC.Val := if narrow i then .Vint (1#32) else .Vint (0#32)

theorem row_source (i : Fin 2) : row i = .Sassign (.Evar (name i) (ty i)) (rhs i) :=
  (declaration i).assign_source
theorem source : Arm64CiliumCallerStackTags.afterStackTags =
    ((List.finRange 2).map row).foldr CC.Stmt.Ssequence after := rfl
theorem after_source : after = .Ssequence s_trusted_arm64_arm64_sim_xdp_25 s_trusted_arm64_arm64_sim_xdp_9287 := rfl

theorem declared : ∀ i : Fin 2,(name i,ty i) ∈ procedure.fn_vars := by decide +kernel
theorem names_distinct : ∀ i j : Fin 2,i ≠ j → name i ≠ name j := by decide +kernel
private theorem modes : ∀ i : Fin 2,CC.accessMode (ty i) = .By_value (chunk i) ∧
    CC.sizeof ge.genv_cenv (ty i) = CC.sizeChunk (chunk i) := by decide +kernel

private theorem constants (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) : ∀ i : Fin 2,
    CC.doEvalExpr ge e le m (rhs i) = some (inputValue i) ∧
    CC.Cop.semCast (inputValue i) (CC.typeof (rhs i)) (ty i) m = some (value i) ∧
    CC.Val.loadResult (chunk i) (value i) = value i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

structure Locals (m : CC.Mem) where
  block : Fin 2 → CC.Block
  binding : ∀ i,(allocation m).1.get (name i) = some (block i,ty i)

theorem local_storage (m : CC.Mem) : Nonempty (Locals m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have witness : ∀ i,∃ block,(allocation m).1.get (name i) = some (block,ty i) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) names (declared i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

theorem locals_separate {m : CC.Mem} (locals : Locals m) {i j : Fin 2} (different : i ≠ j) :
    locals.block i ≠ locals.block j :=
  (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ (locals.binding i) (locals.binding j) (names_distinct i j different)

private theorem aligned : ∀ i : Fin 2,(0 % CC.alignChunk (chunk i) == 0) = true := by decide +kernel

theorem writable {m before : CC.Mem} (locals : Locals m) (i : Fin 2)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before (chunk i) (locals.block i) 0 .Writable = true := by
  have owned := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (locals.binding i)).2.2
  rw [(modes i).2] at owned
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned o lower (by simpa only [Int.zero_add] using upper))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · exact aligned i

/-- Each actual SP/is_xdp assignment derives its successful store from the
same real local allocation;all other blocks remain untouched. -/
theorem store_row {m before : CC.Mem} (locals : Locals m) (i : Fin 2)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ finalMem,
      InternalRun ge 1 (.State procedure (row i) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le finalMem) ∧
      CC.Mem.store (chunk i) before (locals.block i) 0 (value i) = some finalMem ∧
      CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i) ∧
      (∀ b,b ≠ locals.block i → ∀ c o,CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  have valid := writable locals i access
  obtain ⟨finalMem,stored⟩ : ∃ finalMem,CC.Mem.store (chunk i) before (locals.block i) 0
      (value i) = some finalMem := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have assigned : CC.doAssignLoc ge.genv_cenv (ty i) before (locals.block i) 0 .Full (value i) =
      some finalMem := by
    simp only [CC.doAssignLoc,(modes i).1]
    exact stored
  have step : CC.Step2 ge (.State procedure (row i) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le finalMem) := by
    rw [row_source]
    apply CC.Step.assign
    · exact .Evar_local _ _ _ (locals.binding i)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ (constants (allocation m).1 le before i).1
    · exact (constants (allocation m).1 le before i).2.1
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (row i) k (allocation m).1 le before) := by
    rw [row_source];trivial
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (locals.binding i)).1
  have read : CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i) := by
    have h := CC.Mem.load_store_same stored
    rw [(constants (allocation m).1 le before i).2.2] at h
    exact h
  exact ⟨finalMem,.step internal step (.refl _),stored,read,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

theorem first_source : (declaration 0).stage = Arm64CiliumCallerStackTags.afterStackTags := rfl
theorem chain : (declaration 0).next = (declaration 1).stage := rfl

private theorem visit {m before : CC.Mem} (locals : Locals m) (i : Fin 2)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ afterMem,
      InternalRun ge 3 (.State procedure (declaration i).stage k (allocation m).1 le before)
        (.State procedure (declaration i).next k (allocation m).1 le afterMem) ∧
      CC.Mem.load (chunk i) afterMem (locals.block i) 0 = some (value i) ∧
      (∀ b,b ≠ locals.block i → ∀ c o,CC.Mem.load c afterMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before afterMem ∧ afterMem.access = before.access ∧
      afterMem.nextblock = before.nextblock := by
  obtain ⟨afterMem,assigned,stored,read,other,frame,rights,frontier⟩ :=
    store_row locals i access le (.Kseq (declaration i).next k)
  have body : (declaration i).assign = row i := rfl
  have run : InternalRun ge 3
      (.State procedure (declaration i).stage k (allocation m).1 le before)
      (.State procedure (declaration i).next k (allocation m).1 le afterMem) := by
    rw [(declaration i).stage_source,body]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (assigned.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  exact ⟨afterMem,run,read,other,frame,rights,frontier⟩

/-- Original signed64 SPzero then uchar is_xdp=1, on the same current heap. -/
theorem execute {m before : CC.Mem} (locals : Locals m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ finalMem,
      InternalRun ge 6 (.State procedure Arm64CiliumCallerStackTags.afterStackTags k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le finalMem) ∧
      (∀ i : Fin 2,CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i)) ∧
      (∀ b,b ≠ locals.block 0 → b ≠ locals.block 1 → ∀ c o,
        CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  obtain ⟨middle,spRun,spRead,spOther,spFrame,spAccess,spNext⟩ := visit locals 0 access le k
  obtain ⟨finalMem,xdpRun,xdpRead,xdpOther,xdpFrame,xdpAccess,xdpNext⟩ :=
    visit locals 1 (spAccess.trans access) le k
  have different : (0 : Fin 2) ≠ 1 := by decide
  have readSP := (xdpOther (locals.block 0) (locals_separate locals different) (chunk 0) 0).trans spRead
  refine ⟨finalMem,?_,?_,?_,spFrame.trans xdpFrame,xdpAccess.trans spAccess,xdpNext.trans spNext⟩
  · rw [chain] at spRun
    simpa only [first_source,after] using spRun.trans xdpRun
  · intro i
    by_cases zero : i=0
    · subst i;exact readSP
    · have one : i=1 := Fin.ext (by omega)
      subst i;exact xdpRead
  · intro b notSP notXDP c o
    exact (xdpOther b notXDP c o).trans (spOther b notSP c o)

end KProgFormal.ClightRefinement.Arm64CiliumCallerEntryScalars
