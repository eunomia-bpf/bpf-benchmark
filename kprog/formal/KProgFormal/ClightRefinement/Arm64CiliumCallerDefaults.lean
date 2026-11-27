import KProgFormal.ClightRefinement.Arm64CiliumCallerCB

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerDefaults
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext (ABI)

structure Declaration where
  name : CC.Ident
  ty : CC.Ty
  rhs : CC.Expr
  stage : CC.Stmt
  assign : CC.Stmt
  next : CC.Stmt
  stage_source : stage = .Ssequence assign next
  assign_source : assign = .Sassign (.Evar name ty) rhs

private noncomputable def declarations : Array Declaration := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerCB.after)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:9] do
      let source ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless source.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original default sequence absent"
      let assign ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source.getAppArgs[0]!)
      unless assign.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "original default assignment absent"
      let lhs := assign.getAppArgs[0]!
      unless lhs.isAppOfArity ``CC.Expr.Evar 2 do throwError "original default is not a local assignment"
      rows := rows.push (← Lean.Meta.mkAppM ``Declaration.mk
        #[lhs.getAppArgs[0]!,lhs.getAppArgs[1]!,assign.getAppArgs[1]!,
          current,source.getAppArgs[0]!,source.getAppArgs[1]!,
          ← Lean.Meta.mkEqRefl current,← Lean.Meta.mkEqRefl source.getAppArgs[0]!])
      current := source.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_nine_defaults
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

noncomputable def declaration (i : Fin 9) : Declaration :=
  declarations[i.val]'(by change i.val < 9;exact i.isLt)
noncomputable def row (i : Fin 9) : CC.Stmt := (declaration i).assign
noncomputable def name (i : Fin 9) : CC.Ident := (declaration i).name
noncomputable def ty (i : Fin 9) : CC.Ty := (declaration i).ty
noncomputable def rhs (i : Fin 9) : CC.Expr := (declaration i).rhs
noncomputable def after : CC.Stmt := (declaration 8).next
def narrow (i : Fin 9) : Bool := i.val==1 || i.val==4 || i.val==5 || i.val==6
def chunk (i : Fin 9) : CC.Chunk := if narrow i then .Mint8unsigned else .Mint64
def value (i : Fin 9) : CC.Val := if narrow i then .Vint (0#32) else .Vlong (0#64)

def inputValue (i : Fin 9) : CC.Val :=
  if i.val==2 || i.val==3 then .Vint (0#32) else value i

theorem row_source (i : Fin 9) : row i = .Sassign (.Evar (name i) (ty i)) (rhs i) :=
  (declaration i).assign_source
theorem source : Arm64CiliumCallerCB.after =
    ((List.finRange 9).map row).foldr CC.Stmt.Ssequence after := rfl
theorem after_source : after = s_trusted_arm64_arm64_sim_xdp_9299 := rfl

theorem declared : ∀ i : Fin 9,(name i,ty i) ∈ procedure.fn_vars := by decide +kernel
theorem names_distinct : ∀ i j : Fin 9,i ≠ j → name i ≠ name j := by decide +kernel
theorem not_abi : ∀ i : Fin 9,name i ≠ ___a64_sim_abi := by decide +kernel
private theorem modes : ∀ i : Fin 9,CC.accessMode (ty i) = .By_value (chunk i) ∧
    CC.sizeof ge.genv_cenv (ty i) = CC.sizeChunk (chunk i) := by decide +kernel

private theorem constants (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) : ∀ i : Fin 9,
    CC.doEvalExpr ge e le m (rhs i) = some (inputValue i) ∧
    CC.Cop.semCast (inputValue i) (CC.typeof (rhs i)) (ty i) m = some (value i) ∧
    CC.Val.loadResult (chunk i) (value i) = value i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

structure Locals (m : CC.Mem) where
  block : Fin 9 → CC.Block
  binding : ∀ i,(allocation m).1.get (name i) = some (block i,ty i)

theorem local_storage (m : CC.Mem) : Nonempty (Locals m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have witness : ∀ i,∃ block,(allocation m).1.get (name i) = some (block,ty i) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) names (declared i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

theorem locals_separate {m : CC.Mem} (locals : Locals m) {i j : Fin 9} (different : i ≠ j) :
    locals.block i ≠ locals.block j :=
  (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ (locals.binding i) (locals.binding j) (names_distinct i j different)

theorem abi_separate {m : CC.Mem} (abi : ABI m) (locals : Locals m) (i : Fin 9) :
    abi.block ≠ locals.block i := by
  apply (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ abi.binding (locals.binding i)
  exact (not_abi i).symm

private theorem aligned : ∀ i : Fin 9,(0 % CC.alignChunk (chunk i) == 0) = true := by decide +kernel

theorem writable {m before : CC.Mem} (locals : Locals m) (i : Fin 9)
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

/-- Each original typed default derives its successful store from the
same real local allocation;all other blocks remain untouched. -/
theorem store_row {m before : CC.Mem} (locals : Locals m) (i : Fin 9)
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


/-- Each actual local is distinct from every other default and from ABI.
All nine original sequence/store/skip steps therefore retain earlier reads. -/
theorem run_rows {m before : CC.Mem} (abi : ABI m) (locals : Locals m)
    (rows : List (Fin 9)) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ finalMem,
      InternalRun ge (3*rows.length)
        (.State procedure (rows.foldr (fun i next => .Ssequence (row i) next) rest)
          k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le finalMem) ∧
      (∀ i ∈ rows,CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i)) ∧
      (∀ i ∉ rows,CC.Mem.load (chunk i) finalMem (locals.block i) 0 =
        CC.Mem.load (chunk i) before (locals.block i) 0) ∧
      (∀ c o,CC.Mem.load c finalMem abi.block o = CC.Mem.load c before abi.block o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before,.refl _,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro i member;cases member
    · intro i absent;rfl
    · intro c o;rfl
  | cons head tail ih =>
    let next := tail.foldr (fun i next => .Ssequence (row i) next) rest
    obtain ⟨middle,headRun,stored,headRead,headOther,headFrame,headAccess,headNext⟩ :=
      store_row locals head access le (.Kseq next k)
    have first : InternalRun ge 3
        (.State procedure (.Ssequence (row head) next) k (allocation m).1 le before)
        (.State procedure next k (allocation m).1 le middle) :=
      .step trivial (CC.doStep_sound _ _ _ _ rfl)
        (headRun.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
    obtain ⟨finalMem,tailRun,tailRead,tailOther,tailABI,tailFrame,tailAccess,tailNext⟩ :=
      ih (headAccess.trans access)
    have distinct (i : Fin 9) (different : i ≠ head) :
        CC.Mem.load (chunk i) middle (locals.block i) 0 =
          CC.Mem.load (chunk i) before (locals.block i) 0 :=
      headOther (locals.block i) (locals_separate locals different) (chunk i) 0
    refine ⟨finalMem,?_,?_,?_,?_,headFrame.trans tailFrame,
      tailAccess.trans headAccess,tailNext.trans headNext⟩
    · simpa only [List.foldr_cons,List.length_cons,Nat.mul_add,Nat.mul_one,Nat.add_comm,next]
        using first.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have ne : i ≠ head := by intro same;apply absent;simp only [same,List.mem_cons_self]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (distinct i ne)
    · intro c o
      exact (tailABI c o).trans (headOther abi.block (abi_separate abi locals head) c o)

theorem execute {m before : CC.Mem} (abi : ABI m) (locals : Locals m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ finalMem,
      InternalRun ge 27
        (.State procedure Arm64CiliumCallerCB.after k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le finalMem) ∧
      (∀ i,CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i)) ∧
      (∀ c o,CC.Mem.load c finalMem abi.block o = CC.Mem.load c before abi.block o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  obtain ⟨finalMem,run,reads,_,abiReads,frame,access,next⟩ :=
    run_rows abi locals (List.finRange 9) access le k after
  refine ⟨finalMem,?_,(fun i => reads i (by simp)),abiReads,frame,access,next⟩
  rw [source,List.foldr_map]
  simpa only [List.length_finRange] using run

/-- The SAME original entry/context/CB run delegates once to the real9local
default suffix. Both pointers and all5CB words survive on the same heap. -/
theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (k : CC.Cont) :
    ∃ locals : Locals m,∃ traceFirst traceSecond finalMem,
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) [.Vptr ctx ctxOfs] k m)
        (CC.Eapp traceFirst traceSecond)
        (.State procedure after k (allocation m).1
          (((Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)).set _t'1
            (.Vptr (results false) (resultOffsets false))).set _t'2
              (.Vptr (results true) (resultOffsets true))) finalMem) ∧
      CC.Mem.load .Mint64 finalMem abi.block 0 =
        some (.Vptr (results false) (resultOffsets false)) ∧
      CC.Mem.load .Mint64 finalMem abi.block 8 =
        some (.Vptr (results true) (resultOffsets true)) ∧
      (∀ i,CC.Mem.load .Mint32 finalMem abi.block (Arm64CiliumCallerCB.offset i) =
        some (.Vint (0#32))) ∧
      (∀ i,CC.Mem.load (chunk i) finalMem (locals.block i) 0 = some (value i)) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨locals⟩ := local_storage m
  obtain ⟨traceFirst,traceSecond,afterCB,cbRun,dataRead,endRead,cbReads,cbFrame,cbAccess,cbNext⟩ :=
    Arm64CiliumCallerCB.entry m abi ctx ctxOfs results resultOffsets inputs k
  let temps : CC.TempEnv := ((Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)).set _t'1
    (.Vptr (results false) (resultOffsets false))).set _t'2 (.Vptr (results true) (resultOffsets true))
  obtain ⟨finalMem,defaultRun,reads,abiReads,frame,access,next⟩ :=
    execute abi locals cbAccess temps k
  refine ⟨locals,traceFirst,traceSecond,finalMem,?_,
    (abiReads .Mint64 0).trans dataRead,(abiReads .Mint64 8).trans endRead,
    (fun i => (abiReads .Mint32 (Arm64CiliumCallerCB.offset i)).trans (cbReads i)),
    reads,cbFrame.trans frame,access.trans cbAccess,next.trans cbNext⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,temps] using star_trans cbRun defaultRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerDefaults
