import KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryVectors

open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntrySource (expression statement)
open Arm64Producer

/-- Imported pointer addition depends on the element size, not the rest of
the composite world. All values, including invalid pointer operands, are kept. -/
theorem pointer_add (first second : CC.CompositeEnv) (element : CC.Ty)
    (sameSize : CC.sizeof first element = CC.sizeof second element)
    (sign : CC.Signedness) (base index : CC.Val) :
    CC.Cop.semAddPtrInt first element sign base index =
      CC.Cop.semAddPtrInt second element sign base index := by
  unfold CC.Cop.semAddPtrInt
  rw [sameSize]

/-- Congruence for the imported binary evaluator. The operation premise
retains invalid operands and failures as well as successful pointer results. -/
theorem binary_evaluation (first second : CC.CGenv) (firstEnv secondEnv : CC.Env)
    (temps : CC.TempEnv) (m : CC.Mem) (op : CC.Binop)
    (actualLeft sourceLeft actualRight sourceRight : CC.Expr) (actualType sourceType : CC.Ty)
    (left : CC.doEvalExpr first firstEnv temps m actualLeft =
      CC.doEvalExpr second secondEnv temps m sourceLeft)
    (right : CC.doEvalExpr first firstEnv temps m actualRight =
      CC.doEvalExpr second secondEnv temps m sourceRight)
    (operation : ∀ lhs rhs, CC.Cop.semBinaryOperation first.genv_cenv op lhs
        (CC.typeof actualLeft) rhs (CC.typeof actualRight) m =
      CC.Cop.semBinaryOperation second.genv_cenv op lhs
        (CC.typeof sourceLeft) rhs (CC.typeof sourceRight) m) :
    CC.doEvalExpr first firstEnv temps m (.Ebinop op actualLeft actualRight actualType) =
      CC.doEvalExpr second secondEnv temps m (.Ebinop op sourceLeft sourceRight sourceType) := by
  simp only [CC.doEvalExpr, left, right]
  cases CC.doEvalExpr second secondEnv temps m sourceLeft with
  | none => rfl
  | some lhs =>
    cases CC.doEvalExpr second secondEnv temps m sourceRight with
    | none => rfl
    | some rhs => exact operation lhs rhs

private theorem dereference_lvalue (first second : CC.CGenv) (firstEnv secondEnv : CC.Env)
    (temps : CC.TempEnv) (m : CC.Mem) (actual source : CC.Expr) (actualTy sourceTy : CC.Ty)
    (evaluated : CC.doEvalExpr first firstEnv temps m actual =
      CC.doEvalExpr second secondEnv temps m source) :
    CC.doEvalLvalue first firstEnv temps m (.Ederef actual actualTy) =
      CC.doEvalLvalue second secondEnv temps m (.Ederef source sourceTy) := by
  simp only [CC.doEvalLvalue, evaluated]

/-- The actual vector-array fields and their pointer arithmetic transport
without any whole-world or successful/readable-memory assumption. -/
theorem vector_lvalue (initial before : CC.Mem) (temps : CC.TempEnv) (i : Fin 64) :
    CC.doEvalLvalue world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
        (expression (nullVectorTarget i)) =
      CC.doEvalLvalue ge (allocation initial).1 temps before (nullVectorTarget i) := by
  let field : CC.Expr := .Efield (.Evar Arm64Entry._entry headerType)
    (if i.val < 32 then Arm64Entry._vector_lo else Arm64Entry._vector_hi)
    (CC.tarray (CC.tptr CC.tulong) 32)
  let index : CC.Expr := .Econst_int (CC.Integers.Int.repr (i.val % 32)) CC.tint
  have fieldEval := (Arm64ProgramEntryFields.allocated_header initial before temps temps
    (if i.val < 32 then Arm64Entry._vector_lo else Arm64Entry._vector_hi)
    (CC.tarray (CC.tptr CC.tulong) 32)).2
  have indexEval : CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression index) = CC.doEvalExpr ge (allocation initial).1 temps before index := by
    simp only [index, expression, CC.doEvalExpr]
  have added : ∀ lhs rhs, CC.Cop.semBinaryOperation world.genv_cenv .Oadd lhs
      (CC.typeof (expression field)) rhs (CC.typeof (expression index)) before =
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd lhs
      (CC.typeof field) rhs (CC.typeof index) before := by
    intro lhs rhs
    change CC.Cop.semAddPtrInt world.genv_cenv (CC.tptr CC.tulong) .Signed lhs rhs =
      CC.Cop.semAddPtrInt ge.genv_cenv (CC.tptr CC.tulong) .Signed lhs rhs
    apply pointer_add world.genv_cenv ge.genv_cenv (CC.tptr CC.tulong)
    change (8 : Int) = 8
    rfl
  have indexed := binary_evaluation world ge _ _ temps before .Oadd
    (expression field) field (expression index) index
    (Arm64ProgramEntrySource.sourceType (CC.tptr (CC.tptr CC.tulong)))
    (CC.tptr (CC.tptr CC.tulong)) fieldEval indexEval added
  have address := dereference_lvalue world ge _ _ temps before _ _
    (Arm64ProgramEntrySource.sourceType (CC.tptr CC.tulong)) (CC.tptr CC.tulong) indexed
  simpa only [nullVectorTarget, expression, field, index] using address

/-- Transport the real null cast and vector-pointer assignment, keeping the
exact source post-memory and allowing the actual continuation. -/
theorem vector_assignment (initial before after : CC.Mem) (temps : CC.TempEnv)
    (sourceCont actualCont : CC.Cont) (i : Fin 64)
    (stepped : CC.doStep ge
      (.State producer (nullVectorStore i) sourceCont (allocation initial).1 temps before) =
      some (CC.E0, .State producer .Sskip sourceCont (allocation initial).1 temps after)) :
    CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (statement (nullVectorStore i)) actualCont
        (Arm64ProgramEntryAllocation.allocation initial).1 temps before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip actualCont
        (Arm64ProgramEntryAllocation.allocation initial).1 temps after) := by
  apply Arm64ProgramEntryAssignments.assignment ge world producer
    Arm64ProgramFixture.f_arm64_execute_compile _ _ temps temps sourceCont actualCont
    (nullVectorTarget i) (.Ecast (.Econst_int 0 CC.tint) (CC.tptr CC.tvoid))
    (expression (nullVectorTarget i)) (expression (.Ecast (.Econst_int 0 CC.tint) (CC.tptr CC.tvoid)))
    before after CC.Mptr rfl rfl rfl
  · exact vector_lvalue initial before temps i
  · simp only [expression, CC.doEvalExpr]; rfl
  · exact stepped

private theorem source_vector_lvalue (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv)
    (entry : HeaderLocal m) (i : Fin 64) :
    CC.doEvalLvalue world (allocation m).1 le before (nullVectorTarget i) =
      some (entry.block, nullVectorOffset i, .Full) := by
  by_cases low : i.val < 32
  all_goals simp [nullVectorTarget, low, headerType, CC.doEvalLvalue, CC.doEvalExpr,
    CC.lvalOfVar, CC.doDerefLoc, CC.lvalOfField, CC.typeof, CC.accessMode, entry.binding, layout,
    null_vector_layout.1, null_vector_layout.2.1, null_vector_layout.2.2.1,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
    CC.Cop.ptrofsOfInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
    CC.tptr, CC.tarray, CC.tint, nullVectorOffset]
  all_goals rfl

/-- The actual generated function writes one null vector pointer, preserving
other vectors, the scalar header and all other local/caller resources. -/
theorem vector_write (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (i : Fin 64) (rest : CC.Stmt)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (.Ssequence (statement (nullVectorStore i)) rest) k
          (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load CC.Mptr after entry.block (96 + 8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (96 + 8 * (j.val : Int))) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr entry.block (96 + 8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        change ofs < 96 + 8 * (i.val : Int) + 8 at upper
        rw [null_vector_layout.2.2.2]
        omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((96 + 8 * (i.val : Int)) % 8 == 0) = true
      have aligned : (96 + 8 * (i.val : Int)) % 8 = 0 := by omega
      simp only [aligned, beq_self_eq_true]
  have existsStore : ∃ after, CC.Mem.store CC.Mptr before entry.block (96 + 8 * (i.val : Int))
      (.Vlong 0) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr before (.Vptr entry.block (nullVectorOffset i)) (.Vlong 0) = some after := by
    simpa only [CC.Mem.storev, null_vector_offsets] using stored
  have target := source_vector_lvalue ge rfl m before le entry i
  have assigned : CC.doStep ge
      (.State producer (nullVectorStore i) (.Kseq rest k) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    simp only [nullVectorStore, CC.doStep, target]
    rw [show CC.typeof (nullVectorTarget i) = CC.tptr CC.tulong from rfl]
    change (match CC.Mem.storev CC.Mptr before (.Vptr entry.block (nullVectorOffset i)) (.Vlong 0) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have actualAssigned := vector_assignment m before after le (.Kseq rest k) (.Kseq rest k) i assigned
  have run : InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (statement (nullVectorStore i)) rest) k
        (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
        (Arm64ProgramEntryAllocation.allocation m).1 le after) :=
    .step trivial (.seq _ _ _ _ _ _ _)
      (.step trivial (Arm64ProgramEntryAssignments.assignment_sound world _ _ _ _ _ _ _ _ actualAssigned)
        (.step trivial (.skip_seq _ _ _ _ _ _) (.refl _)))
  refine ⟨after, run, CC.Mem.load_store_same stored, ?_, ?_, ?_,
    FrameBelow.store entry.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : 96 + 8 * (j.val : Int) + 8 ≤ 96 + 8 * (i.val : Int) ∨
        96 + 8 * (i.val : Int) + 8 ≤ 96 + 8 * (j.val : Int) := by omega
    exact CC.Mem.load_store_other stored CC.Mptr entry.block _ (.inr separate)
  · intro j
    apply CC.Mem.load_store_other stored
    right; left
    have bound := j.isLt
    change 8 * (j.val : Int) + 8 ≤ 96 + 8 * (i.val : Int)
    omega
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound entry.binding different))

private theorem run_vectors (m : CC.Mem) (entry : HeaderLocal m) (rows : List (Fin 64))
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (rows.foldr (fun i next => .Ssequence (statement (nullVectorStore i)) next) rest)
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (96 + 8 * (i.val : Int))) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro j; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headScalars, headLocals, headFrame, headAccess, headNext⟩ :=
      vector_write m before le k entry head
        (tail.foldr (fun i next => .Ssequence (statement (nullVectorStore i)) next) rest) access
    obtain ⟨after, tailRun, tailRead, tailOther, tailScalars, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one,
        Nat.add_comm] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have notHead : i ≠ head := by intro same; apply absent; simp [same]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i notHead)
    · intro j
      exact (tailScalars j).trans (headScalars j)
    · intro id ty block bound different chunk ofs
      exact (tailLocals id ty block bound different chunk ofs).trans
        (headLocals id ty block bound different chunk ofs)

/-- Cache the actual production tail after the next64 statements; the
kernel checks the complete vector-initialization source equation. -/
private def productionParts : { last : CC.Stmt // Arm64ProgramEntryAssignments.afterHeader =
    (List.ofFn (fun i => statement (nullVectorStore i))).foldr CC.Stmt.Ssequence last } := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryAssignments.afterHeader)) none
    for _ in [:64] do
      let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual vector-pointer initialization has fewer than64 statements"
      current := body.getAppArgs[1]!
    let rows ← Lean.Elab.Term.elabTerm (← `(List.ofFn (fun i => statement (nullVectorStore i)))) none
    let rhs ← Lean.Meta.mkAppM ``List.foldr #[Lean.mkConst ``CC.Stmt.Ssequence, current, rows]
    let target ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    Lean.Elab.Tactic.closeMainGoal `production_vector_parts
      (← Lean.Meta.mkAppOptM ``Subtype.mk #[some target.getAppArgs[0]!,
        some target.getAppArgs[1]!, some current, some (← Lean.Meta.mkEqRefl rhs)])

def afterNullVectors : CC.Stmt := productionParts.val

theorem production_vector_source : Arm64ProgramEntryAssignments.afterHeader =
    (List.ofFn (fun i => statement (nullVectorStore i))).foldr CC.Stmt.Ssequence afterNullVectors :=
  productionParts.property

/-- All64 actual vector pointer stores execute from the actual header
successor to the real production tail, retaining all scalar header loads. -/
theorem vectors_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 192
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAssignments.afterHeader
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterNullVectors
          k (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ j : Fin 12, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, read, _, scalars, other, frame, finalAccess, next⟩ :=
    run_vectors m entry (List.finRange 64) afterNullVectors le k before access
  refine ⟨after, ?_, (fun i => read i (List.mem_finRange i)), scalars, other, frame, finalAccess, next⟩
  have mapped : List.ofFn (fun i => statement (nullVectorStore i)) =
      (List.finRange 64).map (fun i => statement (nullVectorStore i)) := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [production_vector_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

/-- Actual header and vector initialization compose in source order with
all pointer observations/resources derived at the same reached memory. -/
theorem header_and_vectors (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun world 228 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAssignments.beforeHeader
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterNullVectors
          k (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, middle, headRun, headReads, headLocals, headFrame, headAccess, headNext⟩ :=
    Arm64ProgramEntryAssignments.header_initialized m before le k access
  obtain ⟨after, tailRun, nullReads, scalars, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
    vectors_initialized m middle entry le k (headAccess.trans access)
  refine ⟨entry, cells, after, headRun.trans tailRun, ?_, nullReads, ?_, headFrame.trans tailFrame,
    tailAccess.trans headAccess, tailNext.trans headNext⟩
  · intro i
    exact (scalars i).trans (headReads i)
  · intro id ty block bound different chunk ofs
    exact (tailLocals id ty block bound different chunk ofs).trans
      (headLocals id ty block bound different chunk ofs)

end KProgFormal.ClightRefinement.Arm64ProgramEntryVectors
