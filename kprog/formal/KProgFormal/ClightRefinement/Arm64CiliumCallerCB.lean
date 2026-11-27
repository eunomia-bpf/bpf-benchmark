import KProgFormal.ClightRefinement.Arm64CiliumCallerContextPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerCB
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext (ABI abiType)

structure Declaration where
  stage : CC.Stmt
  assign : CC.Stmt
  next : CC.Stmt
  source : stage = .Ssequence assign next

private noncomputable def declarations : Array Declaration := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerContext.next true)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:5] do
      let source ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless source.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original cb sequence absent"
      unless source.getAppArgs[0]!.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "original cb assignment absent"
      rows := rows.push (← Lean.Meta.mkAppM ``Declaration.mk
        #[current,source.getAppArgs[0]!,source.getAppArgs[1]!,← Lean.Meta.mkEqRefl current])
      current := source.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_cb_declarations
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

noncomputable def declaration (i : Fin 5) : Declaration :=
  declarations[i.val]'(by change i.val < 5;exact i.isLt)
noncomputable def row (i : Fin 5) : CC.Stmt := (declaration i).assign
noncomputable def after : CC.Stmt := (declaration 4).next
noncomputable def arrayExpr : CC.Expr :=
  .Efield (.Evar ___a64_sim_abi abiType) _cb (CC.tarray CC.tuint 5)
def offset (i : Fin 5) : Int := 16+4*(i.val : Int)

theorem row_source : ∀ i : Fin 5,row i =
    .Sassign (.Ederef (.Ebinop .Oadd arrayExpr (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
      (CC.tptr CC.tuint)) CC.tuint) (.Econst_int (CC.Integers.Int.repr 0) CC.tint) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial
theorem source : Arm64CiliumCallerContext.next true =
    ((List.finRange 5).map row).foldr CC.Stmt.Ssequence after := rfl

private theorem indices : ∀ i : Fin 5,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i ∧
    CC.Integers.Ptrofs.add (16#64) (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 4)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val))) =
      CC.Integers.Ptrofs.repr (offset i) := by decide +kernel

theorem store_row {m before : CC.Mem} (abi : ABI m) (i : Fin 5)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 1 (.State procedure (row i) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le after) ∧
      CC.Mem.store .Mint32 before abi.block (offset i) (.Vint (0#32)) = some after ∧
      CC.Mem.load .Mint32 after abi.block (offset i) = some (.Vint (0#32)) ∧
      (∀ b,b ≠ abi.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) ∧
      (∀ c o,o+CC.sizeChunk c ≤ 16 →
        CC.Mem.load c after abi.block o = CC.Mem.load c before abi.block o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have bound := i.isLt
  have valid : CC.Mem.validAccess before .Mint32 abi.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have permission := CC.Mem.perm_implies
        (CC.Mem.rangePerm_perm _ _ _ _ _ _ abi.owned o (by unfold offset at lower;omega)
          (by change o < offset i+4 at upper;unfold offset at upper;omega))
        (by decide : CC.permOrder .Freeable .Writable = true)
      simpa only [CC.Mem.perm,access] using permission
    · change ((offset i) % 4 == 0) = true
      have align : offset i % 4 = 0 := by unfold offset;omega
      simp only [align,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint32 before abi.block (offset i)
      (.Vint (0#32)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have array : CC.doEvalExpr ge (allocation m).1 le before arrayExpr = some (.Vptr abi.block (16#64)) := by
    simp only [arrayExpr,CC.doEvalExpr,CC.lvalOfVar,abi.binding,
      CC.doDerefLoc,abiType,CC.accessMode,CC.typeof,CC.lvalOfField,
      Arm64CiliumCallerContext.layout.1,Arm64CiliumCallerContext.layout.2.2.2]
    rfl
  have add : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr abi.block (16#64))
      (CC.tarray CC.tuint 5) (.Vint (CC.Integers.Int.repr i.val)) CC.tint before =
      some (.Vptr abi.block (CC.Integers.Ptrofs.repr (offset i))) := by
    change some (CC.Val.Vptr abi.block (CC.Integers.Ptrofs.add (16#64)
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 4)
        (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val))))) = _
    rw [(indices i).2]
  have address : CC.EvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd arrayExpr (.Econst_int (CC.Integers.Int.repr i.val) CC.tint) (CC.tptr CC.tuint))
      (.Vptr abi.block (CC.Integers.Ptrofs.repr (offset i))) :=
    .Ebinop .Oadd _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ array) (.Econst_int _ _) add
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tuint before abi.block
      (CC.Integers.Ptrofs.repr (offset i)) .Full (.Vint (0#32)) = some after := by
    change CC.Mem.store .Mint32 before abi.block
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i))) (.Vint (0#32)) = some after
    rw [(indices i).1]
    exact stored
  have step : CC.Step2 ge (.State procedure (row i) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le after) := by
    rw [row_source]
    apply CC.Step.assign
    · exact .Ederef _ _ _ _ address
    · exact .Econst_int _ _
    · rfl
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (row i) k (allocation m).1 le before) := by
    rw [row_source];trivial
  refine ⟨after,.step internal step (.refl _),stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),?_,
    FrameBelow.store abi.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  intro c o lower
  apply CC.Mem.load_store_other stored c abi.block o
  have beforeCell : 16 ≤ offset i := by unfold offset;omega
  have apart : o+CC.sizeChunk c ≤ offset i := Int.le_trans lower beforeCell
  exact .inr (.inl apart)

theorem run_rows {m before : CC.Mem} (abi : ABI m) (rows : List (Fin 5))
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ finalMem,
      InternalRun ge (3*rows.length)
        (.State procedure (rows.foldr (fun i next => .Ssequence (row i) next) rest)
          k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le finalMem) ∧
      (∀ i ∈ rows,CC.Mem.load .Mint32 finalMem abi.block (offset i) = some (.Vint (0#32))) ∧
      (∀ i ∉ rows,CC.Mem.load .Mint32 finalMem abi.block (offset i) =
        CC.Mem.load .Mint32 before abi.block (offset i)) ∧
      (∀ b,b ≠ abi.block → ∀ c o,CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      (∀ c o,o+CC.sizeChunk c ≤ 16 →
        CC.Mem.load c finalMem abi.block o = CC.Mem.load c before abi.block o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before,.refl _,?_,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro i member;cases member
    · intro i absent;rfl
    · intro b different c o;rfl
    · intro c o lower;rfl
  | cons head tail ih =>
    let next := tail.foldr (fun i next => .Ssequence (row i) next) rest
    obtain ⟨middle,headRun,stored,headRead,headBlocks,headLow,headFrame,headAccess,headNext⟩ :=
      store_row abi head access le (.Kseq next k)
    have first : InternalRun ge 3
        (.State procedure (.Ssequence (row head) next) k (allocation m).1 le before)
        (.State procedure next k (allocation m).1 le middle) :=
      .step trivial (CC.doStep_sound _ _ _ _ rfl)
        (headRun.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
    obtain ⟨finalMem,tailRun,tailRead,tailOther,tailBlocks,tailLow,tailFrame,tailAccess,tailNext⟩ :=
      ih (headAccess.trans access)
    have headOther (i : Fin 5) (different : i ≠ head) :
        CC.Mem.load .Mint32 middle abi.block (offset i) =
          CC.Mem.load .Mint32 before abi.block (offset i) := by
      have ne : i.val ≠ head.val := fun same => different (Fin.ext same)
      have separate : offset i+4 ≤ offset head ∨ offset head+4 ≤ offset i := by
        unfold offset;omega
      exact CC.Mem.load_store_other stored .Mint32 abi.block (offset i) (.inr separate)
    refine ⟨finalMem,?_,?_,?_,?_,?_,headFrame.trans tailFrame,
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
      exact (tailOther i notTail).trans (headOther i ne)
    · intro b different c o
      exact (tailBlocks b different c o).trans (headBlocks b different c o)
    · intro c o lower
      exact (tailLow c o lower).trans (headLow c o lower)

/-- Execute the five ORIGINAL cbzero stores,retaining both ABI pointer
fields through the same disjoint stores. -/
theorem execute {m before : CC.Mem} (abi : ABI m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ finalMem,
      InternalRun ge 15
        (.State procedure (Arm64CiliumCallerContext.next true) k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le finalMem) ∧
      (∀ i,CC.Mem.load .Mint32 finalMem abi.block (offset i) = some (.Vint (0#32))) ∧
      (∀ b,b ≠ abi.block → ∀ c o,CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      (∀ c o,o+CC.sizeChunk c ≤ 16 →
        CC.Mem.load c finalMem abi.block o = CC.Mem.load c before abi.block o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  obtain ⟨finalMem,run,reads,_,blocks,low,frame,access,next⟩ :=
    run_rows abi (List.finRange 5) access le k after
  refine ⟨finalMem,?_,(fun i => reads i (by simp)),blocks,low,frame,access,next⟩
  rw [source,List.foldr_map]
  simpa only [List.length_finRange] using run

theorem entry (m : CC.Mem) (abi : ABI m) (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Arm64CiliumCallerContextPrefix.Inputs abi ctx ctxOfs results resultOffsets)
    (k : CC.Cont) :
    ∃ traceFirst traceSecond finalMem,
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
      (∀ i,CC.Mem.load .Mint32 finalMem abi.block (offset i) = some (.Vint (0#32))) ∧
      FrameBelow m.nextblock m finalMem ∧ finalMem.access = (allocation m).2.access ∧
      finalMem.nextblock = (allocation m).2.nextblock := by
  obtain ⟨traceFirst,_,_,traceSecond,_,afterPointer,contextRun,_,_,_,_,
      dataRead,endRead,contextFrame,contextAccess,contextNext⟩ :=
    Arm64CiliumCallerContextPrefix.execute m abi ctx ctxOfs results resultOffsets inputs k
  let temps : CC.TempEnv := ((Arm64CiliumCallerLink.initialTemps (.Vptr ctx ctxOfs)).set _t'1
    (.Vptr (results false) (resultOffsets false))).set _t'2 (.Vptr (results true) (resultOffsets true))
  obtain ⟨finalMem,cbRun,cbReads,_,low,cbFrame,cbAccess,cbNext⟩ :=
    execute abi contextAccess temps k
  refine ⟨traceFirst,traceSecond,finalMem,?_,
    (low .Mint64 0 (by decide)).trans dataRead,
    (low .Mint64 8 (by decide)).trans endRead,
    cbReads,contextFrame.trans cbFrame,cbAccess.trans contextAccess,cbNext.trans contextNext⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,temps] using star_trans contextRun cbRun.sound

end KProgFormal.ClightRefinement.Arm64CiliumCallerCB
