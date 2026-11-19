import KProgFormal.ClightRefinement.Arm64ProgramEntryTail

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLoop

open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntrySource (sourceType expression statement)
open Arm64Producer
open Arm64ProgramEntryVectors (binary_evaluation)

/-- The imported pointer operation transports renamed element types by size,
including invalid operands and failed results. -/
theorem pointer_add_types (actual source : CC.CompositeEnv) (actualTy sourceTy : CC.Ty)
    (size : CC.sizeof actual actualTy = CC.sizeof source sourceTy)
    (sign : CC.Signedness) (base index : CC.Val) :
    CC.Cop.semAddPtrInt actual actualTy sign base index =
      CC.Cop.semAddPtrInt source sourceTy sign base index := by
  unfold CC.Cop.semAddPtrInt
  rw [size]

theorem index_name : Arm64ProgramEntrySource.temporaryName Arm64Entry._i = Arm64Entry._i := by
  decide +kernel

private theorem index_not_ctx : Arm64Entry._i ≠ Arm64Entry._ctx := by decide +kernel

theorem index_same : expression vectorLoopIndex = vectorLoopIndex := by
  simp only [vectorLoopIndex, expression, index_name, if_neg index_not_ctx]
  rfl

private theorem index_eval (initial before : CC.Mem) (temps : CC.TempEnv) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression vectorLoopIndex) =
    CC.doEvalExpr ge (allocation initial).1 temps before vectorLoopIndex := by
  rw [index_same]
  simp only [vectorLoopIndex, CC.doEvalExpr]

private theorem dereference_lvalue (first second : CC.CGenv) (firstEnv secondEnv : CC.Env)
    (temps : CC.TempEnv) (m : CC.Mem) (actual source : CC.Expr) (actualTy sourceTy : CC.Ty)
    (evaluated : CC.doEvalExpr first firstEnv temps m actual =
      CC.doEvalExpr second secondEnv temps m source) :
    CC.doEvalLvalue first firstEnv temps m (.Ederef actual actualTy) =
      CC.doEvalLvalue second secondEnv temps m (.Ederef source sourceTy) := by
  simp only [CC.doEvalLvalue, evaluated]

private theorem dereference_read (first second : CC.CGenv) (firstEnv secondEnv : CC.Env)
    (temps : CC.TempEnv) (m : CC.Mem) (actual source : CC.Expr) (actualTy sourceTy : CC.Ty)
    (evaluated : CC.doEvalExpr first firstEnv temps m actual =
      CC.doEvalExpr second secondEnv temps m source)
    (dereferenced : ∀ block offset, CC.doDerefLoc actualTy m block offset .Full =
      CC.doDerefLoc sourceTy m block offset .Full) :
    CC.doEvalExpr first firstEnv temps m (.Ederef actual actualTy) =
      CC.doEvalExpr second secondEnv temps m (.Ederef source sourceTy) := by
  simp only [CC.doEvalExpr, evaluated]
  cases CC.doEvalExpr second secondEnv temps m source with
  | none => rfl
  | some value => cases value <;> first | rfl | exact dereferenced _ _

private theorem address_read (first second : CC.CGenv) (firstEnv secondEnv : CC.Env)
    (temps : CC.TempEnv) (m : CC.Mem) (actual source : CC.Expr) (actualTy sourceTy : CC.Ty)
    (evaluated : CC.doEvalLvalue first firstEnv temps m actual =
      CC.doEvalLvalue second secondEnv temps m source) :
    CC.doEvalExpr first firstEnv temps m (.Eaddrof actual actualTy) =
      CC.doEvalExpr second secondEnv temps m (.Eaddrof source sourceTy) := by
  simp only [CC.doEvalExpr, evaluated]

/-- Actual header-array indexing transports with stride eight for arbitrary
index temporaries, retaining every evaluation failure. -/
theorem target_eval (initial before : CC.Mem) (temps : CC.TempEnv) (high : Bool) :
    CC.doEvalLvalue world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (vectorLoopTarget high)) =
    CC.doEvalLvalue ge (allocation initial).1 temps before (vectorLoopTarget high) := by
  let field : CC.Expr := .Efield (.Evar Arm64Entry._entry headerType)
    (if high then Arm64Entry._vector_hi else Arm64Entry._vector_lo)
    (CC.tarray (CC.tptr CC.tulong) 32)
  have fieldEval := (Arm64ProgramEntryFields.allocated_header initial before temps temps
    (if high then Arm64Entry._vector_hi else Arm64Entry._vector_lo)
    (CC.tarray (CC.tptr CC.tulong) 32)).2
  have added : ∀ lhs rhs, CC.Cop.semBinaryOperation world.genv_cenv .Oadd lhs
      (CC.typeof (expression field)) rhs (CC.typeof (expression vectorLoopIndex)) before =
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd lhs
      (CC.typeof field) rhs (CC.typeof vectorLoopIndex) before := by
    intro lhs rhs
    rw [index_same]
    change CC.Cop.semAddPtrInt world.genv_cenv (CC.tptr CC.tulong) .Unsigned lhs rhs =
      CC.Cop.semAddPtrInt ge.genv_cenv (CC.tptr CC.tulong) .Unsigned lhs rhs
    apply pointer_add_types world.genv_cenv ge.genv_cenv _ _
    change (8 : Int) = 8
    rfl
  have indexed := binary_evaluation world ge _ _ temps before .Oadd
    (expression field) field (expression vectorLoopIndex) vectorLoopIndex
    (sourceType (CC.tptr (CC.tptr CC.tulong))) (CC.tptr (CC.tptr CC.tulong))
    fieldEval (index_eval initial before temps) added
  have address := dereference_lvalue world ge _ _ temps before _ _
    (sourceType (CC.tptr CC.tulong)) (CC.tptr CC.tulong) indexed
  simpa only [vectorLoopTarget, expression, field] using address

/-- Actual vector source-array indexing transports its anonymous record type
with stride sixteen, followed by the imported field/address operations. -/
theorem value_eval (initial before : CC.Mem) (temps : CC.TempEnv) (high : Bool) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (vectorLoopValue high)) =
    CC.doEvalExpr ge (allocation initial).1 temps before (vectorLoopValue high) := by
  let array : CC.Expr := .Evar Arm64Entry.___a64_vectors vectorArrayType
  let indexed : CC.Expr := .Ebinop .Oadd array vectorLoopIndex (CC.tptr vectorType)
  let base : CC.Expr := .Ederef indexed vectorType
  have arrayEval := (Arm64ProgramEntryExpressions.allocated_local initial before temps
    Arm64Entry.___a64_vectors vectorArrayType (by decide +kernel)).2.1
  have size : CC.sizeof world.genv_cenv (sourceType vectorType) =
      CC.sizeof ge.genv_cenv vectorType := by decide +kernel
  have added : ∀ lhs rhs, CC.Cop.semBinaryOperation world.genv_cenv .Oadd lhs
      (CC.typeof (expression array)) rhs (CC.typeof (expression vectorLoopIndex)) before =
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd lhs
      (CC.typeof array) rhs (CC.typeof vectorLoopIndex) before := by
    intro lhs rhs
    rw [index_same]
    change CC.Cop.semAddPtrInt world.genv_cenv (sourceType vectorType) .Unsigned lhs rhs =
      CC.Cop.semAddPtrInt ge.genv_cenv vectorType .Unsigned lhs rhs
    exact pointer_add_types world.genv_cenv ge.genv_cenv _ _ size _ _ _
  have indexedEval := binary_evaluation world ge _ _ temps before .Oadd
    (expression array) array (expression vectorLoopIndex) vectorLoopIndex
    (sourceType (CC.tptr vectorType)) (CC.tptr vectorType)
    arrayEval (index_eval initial before temps) added
  have baseEval := dereference_read world ge _ _ temps before _ _
    (sourceType vectorType) vectorType indexedEval (by intro block offset; rfl)
  have field := Arm64ProgramEntryFields.field_lvalue 1 base
    (if high then Arm64Entry._hi else Arm64Entry._lo) CC.tulong
    (allocation initial).1 (Arm64ProgramEntryAllocation.allocation initial).1 temps temps before
    (by rfl) (by rfl) baseEval
  have address := address_read world ge _ _ temps before _ _
    (sourceType (CC.tptr CC.tulong)) (CC.tptr CC.tulong) field
  simpa only [vectorLoopValue, expression, base, indexed, array] using address

/-- Reuse the imported source store witness and every frame/readback fact.
The actual assignment has the same post-memory because its addresses/values
have already been transported; no second memory construction is needed. -/
theorem store_step (initial before : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal initial) (vectors : VectorLocal initial) (high : Bool) (i : Fin 32)
    (index : temps.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation initial).2.access) :
    ∃ after, CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (statement (vectorLoopStore high)) k
        (Arm64ProgramEntryAllocation.allocation initial).1 temps before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k
        (Arm64ProgramEntryAllocation.allocation initial).1 temps after) ∧
      CC.Mem.load CC.Mptr after entry.block ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i)) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨
          ofs + CC.sizeChunk chunk ≤ (if high then 352 else 96) + 8 * (i.val : Int) ∨
          (if high then 352 else 96) + 8 * (i.val : Int) + 8 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, stepped, read, other, frame, finalAccess, next⟩ :=
    vector_loop_store_step initial before temps k entry vectors high i index access
  refine ⟨after, ?_, read, other, frame, finalAccess, next⟩
  apply Arm64ProgramEntryAssignments.assignment ge world producer
    Arm64ProgramFixture.f_arm64_execute_compile _ _ temps temps k k
    (vectorLoopTarget high) (vectorLoopValue high)
    (expression (vectorLoopTarget high)) (expression (vectorLoopValue high))
    before after CC.Mptr rfl rfl rfl
  · exact target_eval initial before temps high
  · exact value_eval initial before temps high
  · exact stepped

def loopBody : CC.Stmt := statement vectorLoopBody
def loopIncrement : CC.Stmt := statement vectorLoopIncrement
def loop : CC.Stmt := statement vectorLoop

private theorem test_source : expression vectorLoopTest = vectorLoopTest := by
  change CC.Expr.Ebinop .Olt (expression vectorLoopIndex)
    (.Econst_int 32 (sourceType CC.tint)) (sourceType CC.tint) = _
  rw [index_same]
  rfl

private theorem increment_expression :
    expression (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint) =
      .Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint := by
  change CC.Expr.Ebinop .Oadd (expression vectorLoopIndex)
    (.Econst_int 1 (sourceType CC.tint)) (sourceType CC.tuint) = _
  rw [index_same]
  rfl

private theorem increment_source : loopIncrement = vectorLoopIncrement := by
  change CC.Stmt.Sset (Arm64ProgramEntrySource.temporaryName Arm64Entry._i)
    (expression (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint)) = _
  rw [index_name, increment_expression]
  rfl

/-- The unsigned comparison arithmetic is reused; these expressions do not
consult either allocation environment. -/
theorem test_eval (initial before : CC.Mem) (temps : CC.TempEnv) (i : Fin 33)
    (index : temps.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression vectorLoopTest) = some (.Vint (if i.val < 32 then 1 else 0)) := by
  rw [test_source]
  have source := vector_loop_test_bound world initial before temps i index
  simpa only [vectorLoopTest, vectorLoopIndex, CC.doEvalExpr] using source

theorem increment_eval (initial before : CC.Mem) (temps : CC.TempEnv) (i : Fin 32)
    (index : temps.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint) =
      some (.Vint (CC.Integers.Int.repr (i.val + 1))) := by
  have source := vector_loop_increment_bound world initial before temps i index
  simpa only [vectorLoopIndex, CC.doEvalExpr] using source

private def productionParts : { last : CC.Stmt // Arm64ProgramEntryTail.beforeLoop =
    .Ssequence (.Ssequence (.Sset Arm64Entry._i (.Econst_int 0 CC.tint)) loop) last } := by
  run_tac do
    let first ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryTail.beforeLoop)) none
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "actual vector loop continuation sequence changed"
    let last := body.getAppArgs[1]!
    let head ← Lean.Elab.Term.elabTerm
      (← `(CC.Stmt.Ssequence (.Sset Arm64Entry._i (.Econst_int 0 CC.tint)) loop)) none
    let rhs ← Lean.Meta.mkAppM ``CC.Stmt.Ssequence #[head, last]
    let target ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    Lean.Elab.Tactic.closeMainGoal `production_loop_parts
      (Lean.mkAppN (Lean.mkConst ``Subtype.mk [.succ .zero])
        #[target.getAppArgs[0]!, target.getAppArgs[1]!, last, (← Lean.Meta.mkEqRefl rhs)])

def afterLoop : CC.Stmt := productionParts.val

theorem production_loop_source : Arm64ProgramEntryTail.beforeLoop =
    .Ssequence (.Ssequence (.Sset Arm64Entry._i (.Econst_int 0 CC.tint)) loop) afterLoop :=
  productionParts.property

/-- The successor is the actual body from the checked initialization spine. -/
theorem actual_body : afterLoop = Arm64ProgramEntrySource.body := by rfl

theorem iteration (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 11
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1
          (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (i.val + 1)))) after) ∧
      CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset false i)) ∧
      CC.Mem.load CC.Mptr after entry.block (352 + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset true i)) ∧
      (∀ chunk block ofs,
        (block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 96 + 8 * (i.val : Int) ∨
          96 + 8 * (i.val : Int) + 8 ≤ ofs) →
        (block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 352 + 8 * (i.val : Int) ∨
          352 + 8 * (i.val : Int) + 8 ≤ ofs) →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  let loopK := CC.Cont.Kloop1 loopBody loopIncrement k
  let stores := CC.Stmt.Ssequence (statement (vectorLoopStore false)) (statement (vectorLoopStore true))
  obtain ⟨middle, lowStep, lowRead, lowOther, lowFrame, lowAccess, lowNext⟩ :=
    store_step m before le (.Kseq (statement (vectorLoopStore true)) loopK)
      entry vectors false i index access
  obtain ⟨after, highStep, highRead, highOther, highFrame, highAccess, highNext⟩ :=
    store_step m middle le loopK entry vectors true i index (lowAccess.trans access)
  have test := test_eval m before le ⟨i.val, by have h := i.isLt; omega⟩ index
  change CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation m).1 le before (expression vectorLoopTest) =
    some (.Vint (if i.val < 32 then 1 else 0)) at test
  rw [ite_eq_left i.isLt] at test
  have branch : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sifthenelse (expression vectorLoopTest) .Sskip .Sbreak)
        (.Kseq stores loopK) (Arm64ProgramEntryAllocation.allocation m).1 le before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq stores loopK) (Arm64ProgramEntryAllocation.allocation m).1 le before) := by
    simp only [CC.doStep, test]
    rfl
  have increment : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile loopIncrement (.Kloop2 loopBody loopIncrement k)
        (Arm64ProgramEntryAllocation.allocation m).1 le after) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kloop2 loopBody loopIncrement k)
        (Arm64ProgramEntryAllocation.allocation m).1 (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (i.val + 1)))) after) := by
    rw [increment_source]
    simp only [vectorLoopIncrement, CC.doStep, increment_eval m after le i index]
  have run : InternalRun world 11
      (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1
        (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (i.val + 1)))) after) :=
    .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ rfl)
        (.step trivial (CC.doStep_sound world _ _ _ branch)
          (.step trivial (CC.doStep_sound world _ _ _ rfl)
            (.step trivial (CC.doStep_sound world _ _ _ rfl)
              (.step trivial (CC.doStep_sound world _ _ _ lowStep)
                (.step trivial (CC.doStep_sound world _ _ _ rfl)
                  (.step trivial (CC.doStep_sound world _ _ _ highStep)
                    (.step trivial (CC.doStep_sound world _ _ _ rfl)
                      (.step trivial (CC.doStep_sound world _ _ _ increment)
                        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)))))))))))
  refine ⟨after, run, ?_, highRead, ?_, lowFrame.trans highFrame,
    highAccess.trans lowAccess, highNext.trans lowNext⟩
  · exact (highOther CC.Mptr entry.block (96 + 8 * (i.val : Int))
      (.inr (.inl (by change 96 + 8 * (i.val : Int) + 8 ≤ 352 + 8 * (i.val : Int); omega)))).trans lowRead
  · intro chunk block ofs outsideLow outsideHigh
    exact (highOther chunk block ofs outsideHigh).trans (lowOther chunk block ofs outsideLow)

theorem initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 4 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTail.beforeLoop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile loop (.Kseq afterLoop k) (Arm64ProgramEntryAllocation.allocation m).1
        (le.set Arm64Entry._i (.Vint 0)) before) := by
  rw [production_loop_source]
  exact .step trivial (CC.doStep_sound world _ _ _ rfl)
    (.step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ rfl)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _))))

theorem exit (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (index : le.get Arm64Entry._i = some (.Vint 32)) :
    InternalRun world 6
      (.State Arm64ProgramFixture.f_arm64_execute_compile loop (.Kseq afterLoop k) (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterLoop k (Arm64ProgramEntryAllocation.allocation m).1 le before) := by
  have test := test_eval m before le ⟨32, by decide⟩ index
  have branch : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sifthenelse (expression vectorLoopTest) .Sskip .Sbreak)
        (.Kseq (.Ssequence (statement (vectorLoopStore false)) (statement (vectorLoopStore true)))
          (.Kloop1 loopBody loopIncrement (.Kseq afterLoop k)))
        (Arm64ProgramEntryAllocation.allocation m).1 le before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sbreak
        (.Kseq (.Ssequence (statement (vectorLoopStore false)) (statement (vectorLoopStore true)))
          (.Kloop1 loopBody loopIncrement (.Kseq afterLoop k)))
        (Arm64ProgramEntryAllocation.allocation m).1 le before) := by
    simp only [CC.doStep, test]
    rfl
  exact .step trivial (CC.doStep_sound world _ _ _ rfl)
    (.step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ branch)
        (.step trivial (CC.doStep_sound world _ _ _ rfl)
          (.step trivial (CC.doStep_sound world _ _ _ rfl)
            (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _))))))

private theorem pair_separate (high side : Bool) (i j : Fin 32) (different : j ≠ i) :
    (if high then 352 else 96 : Int) + 8 * (j.val : Int) + 8 ≤
      (if side then 352 else 96 : Int) + 8 * (i.val : Int) ∨
    (if side then 352 else 96 : Int) + 8 * (i.val : Int) + 8 ≤
      (if high then 352 else 96 : Int) + 8 * (j.val : Int) := by
  have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
  have ib := i.isLt
  have jb := j.isLt
  cases high <;> cases side <;> simp only [Bool.false_eq_true, ite_false, ite_true] <;> omega

private theorem iteration_frame (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 11
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1
          (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (i.val + 1)))) after) ∧
      (∀ high : Bool, CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ (high : Bool) (j : Fin 32), j ≠ i → CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block ((if high then 352 else 96) + 8 * (j.val : Int))) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 96 ∨ 608 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, run, lowRead, highRead, keep, frame, finalAccess, next⟩ :=
    iteration m before le k entry vectors i index access
  refine ⟨after, run, ?_, ?_, ?_, frame, finalAccess, next⟩
  · intro high; cases high
    · exact lowRead
    · exact highRead
  · intro high j different
    exact keep _ _ _ (.inr (pair_separate high false i j different))
      (.inr (pair_separate high true i j different))
  · intro chunk block ofs outside
    have ib := i.isLt
    apply keep chunk block ofs
    · rcases outside with h | h | h
      · exact .inl h
      · exact .inr (.inl (Int.le_trans h (by omega)))
      · exact .inr (.inr (Int.le_trans (by omega) h))
    · rcases outside with h | h | h
      · exact .inl h
      · exact .inr (.inl (Int.le_trans h (by omega)))
      · exact .inr (.inr (Int.le_trans (by omega) h))

private theorem suffix (fuel start : Nat) (total : start + fuel = 32)
    (m : CC.Mem) (entry : HeaderLocal m) (vectors : VectorLocal m)
    (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr start)))
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun world (11 * fuel)
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile loop k (Arm64ProgramEntryAllocation.allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ (high : Bool) (i : Fin 32), start ≤ i.val → CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ (high : Bool) (i : Fin 32), i.val < start → CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block ((if high then 352 else 96) + 8 * (i.val : Int))) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 96 ∨ 608 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction fuel generalizing start before le with
  | zero =>
    have start32 : start = 32 := by omega
    subst start
    refine ⟨before, le, .refl _, index, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro id different; rfl
    · intro high i lower; have bound := i.isLt; omega
    · intro high i earlier; rfl
    · intro chunk block ofs outside; rfl
  | succ fuel ih =>
    have bound : start < 32 := by omega
    let i : Fin 32 := ⟨start, bound⟩
    obtain ⟨middle, headRun, headRead, headOther, headOutside, headFrame, headAccess, headNext⟩ :=
      iteration_frame m before le k entry vectors i index access
    obtain ⟨after, finalLe, tailRun, tailIndex, tailTemps, tailRead, tailEarlier, tailOutside,
      tailFrame, tailAccess, tailNext⟩ :=
      ih (start + 1) (by omega) middle
        (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (start + 1))))
        (by exact CC.PTree.gss _ _ _) (headAccess.trans access)
    refine ⟨after, finalLe, ?_, tailIndex, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [Nat.mul_succ, Nat.add_comm] using headRun.trans tailRun
    · intro id different
      exact (tailTemps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm different))
    · intro high j lower
      by_cases same : j = i
      · subst j
        exact (tailEarlier high i (by change start < start + 1; omega)).trans (headRead high)
      · have ne : j.val ≠ start := fun h => same (Fin.ext h)
        exact tailRead high j (by omega)
    · intro high j earlier
      have different : j ≠ i := by intro same; have eq := congrArg Fin.val same; change j.val = start at eq; omega
      exact (tailEarlier high j (by omega)).trans (headOther high j different)
    · intro chunk block ofs outside
      exact (tailOutside chunk block ofs outside).trans (headOutside chunk block ofs outside)

/-- All32 actual iterations populate both vector pointer arrays and preserve
all observations outside their exact header range. -/
theorem vectors_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (vectors : VectorLocal m) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun world 362
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTail.beforeLoop k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterLoop k (Arm64ProgramEntryAllocation.allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 96 ∨ 608 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after, finalLe, loopRun, finalIndex, temps, read, _, outside, frame, finalAccess, next⟩ :=
    suffix 32 0 rfl m entry vectors before (le.set Arm64Entry._i (.Vint 0))
      (.Kseq afterLoop k) (CC.PTree.gss _ _ _) access
  refine ⟨after, finalLe,
    ((initialized m before le k).trans loopRun).trans
      (exit m after finalLe k finalIndex), finalIndex, ?_,
    (fun high i => read high i (Nat.zero_le _)), outside, frame, finalAccess, next⟩
  intro id different
  exact (temps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm different))

/-- The actual header construction and live pointer loop reach the real
production body in638 steps, retaining92 typed readbacks and all resources. -/
theorem header_initialized_before_body (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ vectors : VectorLocal m, ∃ after finalLe,
      InternalRun world 638 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAssignments.beforeHeader
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterLoop
          k (Arm64ProgramEntryAllocation.allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  obtain ⟨entry, cells, sources, middle, headRun, scalarReads, _, tailReads,
    headLocals, headFrame, headAccess, headNext⟩ :=
    Arm64ProgramEntryTail.header_initialized_before_loop m before le k access
  let vectors := Classical.choice (vector_local m)
  obtain ⟨after, finalLe, loopRun, index, temps, vectorReads, outside, loopFrame, loopAccess, loopNext⟩ :=
    vectors_initialized m middle entry vectors le k (headAccess.trans access)
  refine ⟨entry, cells, sources, vectors, after, finalLe, headRun.trans loopRun,
    index, temps, ?_, vectorReads, ?_, ?_, headFrame.trans loopFrame,
    loopAccess.trans headAccess, loopNext.trans headNext⟩
  · intro i
    have keep := outside CC.Mptr entry.block (8 * (i.val : Int)) (.inr (.inl (by
      change 8 * (i.val : Int) + 8 ≤ 96
      have bound := i.isLt
      omega)))
    exact keep.trans (scalarReads i)
  · intro i
    exact (outside (tailChunk i) entry.block (tailOffset i)
      (.inr (.inr ((tail_layout.2.2.2.1 i).1)))).trans (tailReads i)
  · intro id ty block binding different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact (outside chunk block ofs (.inl (distinct _ _ _ _ binding entry.binding different))).trans
      (headLocals id ty block binding different chunk ofs)

end KProgFormal.ClightRefinement.Arm64ProgramEntryLoop
