import KProgFormal.ClightRefinement.Arm64ProducerHeaderTail

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

private def vectorLoopParts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(beforeVectorLoop)) none
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "loop/consumer sequence changed"
    let continuation := body.getAppArgs[1]!
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "loop initializer sequence changed"
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "vector pointer loop changed"
    let rest ← Lean.Meta.mkAppM ``Prod.mk #[loop.getAppArgs[1]!, continuation]
    Lean.Elab.Tactic.closeMainGoal `actual_vector_loop_parts
      (← Lean.Meta.mkAppM ``Prod.mk #[loop.getAppArgs[0]!, rest])

def vectorLoopIndex : CC.Expr := .Etempvar Arm64Entry._i CC.tuint
def vectorLoopTarget (high : Bool) : CC.Expr :=
  .Ederef (.Ebinop .Oadd
    (.Efield (.Evar Arm64Entry._entry headerType)
      (if high then Arm64Entry._vector_hi else Arm64Entry._vector_lo)
      (CC.tarray (CC.tptr CC.tulong) 32)) vectorLoopIndex (CC.tptr (CC.tptr CC.tulong)))
    (CC.tptr CC.tulong)
def vectorLoopValue (high : Bool) : CC.Expr :=
  .Eaddrof (.Efield (.Ederef (.Ebinop .Oadd
    (.Evar Arm64Entry.___a64_vectors vectorArrayType) vectorLoopIndex (CC.tptr vectorType))
    vectorType) (if high then Arm64Entry._hi else Arm64Entry._lo) CC.tulong) (CC.tptr CC.tulong)
def vectorLoopStore (high : Bool) : CC.Stmt :=
  .Sassign (vectorLoopTarget high) (vectorLoopValue high)
def vectorLoopTest : CC.Expr :=
  .Ebinop .Olt vectorLoopIndex (.Econst_int 32 CC.tint) CC.tint
def vectorLoopBody : CC.Stmt :=
  .Ssequence (.Sifthenelse vectorLoopTest .Sskip .Sbreak)
    (.Ssequence (vectorLoopStore false) (vectorLoopStore true))
def vectorLoopIncrement : CC.Stmt :=
  .Sset Arm64Entry._i (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint)
def vectorLoop : CC.Stmt := .Sloop vectorLoopBody vectorLoopIncrement
def afterVectorLoop : CC.Stmt := vectorLoopParts.2.2

theorem vector_loop_source : beforeVectorLoop = .Ssequence
    (.Ssequence (.Sset Arm64Entry._i (.Econst_int 0 CC.tint)) vectorLoop) afterVectorLoop := rfl

theorem vector_loop_body_source : vectorLoopParts.1 = vectorLoopBody := rfl
theorem vector_loop_increment_source : vectorLoopParts.2.1 = vectorLoopIncrement := rfl

def vectorLoopHeaderOffset (high : Bool) (i : Fin 32) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add
    (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (if high then 352 else 96)))
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Integers.Ptrofs.of_intu (CC.Integers.Int.repr i.val)))
def vectorLoopSourceOffset (high : Bool) (i : Fin 32) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add
    (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 16)
      (CC.Integers.Ptrofs.of_intu (CC.Integers.Int.repr i.val))))
    (CC.Integers.Ptrofs.repr (if high then 8 else 0))

theorem vector_loop_offsets : ∀ high : Bool, ∀ i : Fin 32,
    CC.Integers.Ptrofs.unsigned (vectorLoopHeaderOffset high i) =
      (if high then 352 else 96) + 8 * (i.val : Int) ∧
    CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset high i) =
      16 * (i.val : Int) + (if high then 8 else 0) := by decide +kernel

theorem vector_loop_target_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv)
    (entry : HeaderLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalLvalue world (allocation m).1 le before (vectorLoopTarget high) =
      some (entry.block, vectorLoopHeaderOffset high i, .Full) := by
  cases high
  all_goals simp [vectorLoopTarget, vectorLoopIndex, headerType, CC.doEvalLvalue, CC.doEvalExpr,
    CC.lvalOfVar, CC.doDerefLoc, CC.lvalOfField, CC.typeof, CC.accessMode, entry.binding, index, layout,
    null_vector_layout.1, null_vector_layout.2.1, null_vector_layout.2.2.1,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
    CC.Cop.ptrofsOfInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
    CC.tptr, CC.tarray, CC.tuint, vectorLoopHeaderOffset]
  all_goals rfl

theorem vector_loop_target (m before : CC.Mem) (le : CC.TempEnv)
    (entry : HeaderLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalLvalue ge (allocation m).1 le before (vectorLoopTarget high) =
      some (entry.block, vectorLoopHeaderOffset high i, .Full) :=
  vector_loop_target_bound ge rfl m before le entry high i index

theorem vector_loop_value_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv)
    (vectors : VectorLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr world (allocation m).1 le before (vectorLoopValue high) =
      some (.Vptr vectors.block (vectorLoopSourceOffset high i)) := by
  have size := vector_layout.2.1
  simp only [vectorType, CC.sizeof, vector_layout.1] at size
  cases high
  all_goals simp [vectorLoopValue, vectorLoopIndex, vectorType, vectorArrayType,
    CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc, CC.lvalOfField,
    CC.typeof, CC.accessMode, vectors.binding, index, layout, vector_layout.1, size,
    vector_layout.2.2.1, vector_layout.2.2.2.1,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
    CC.Cop.ptrofsOfInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
    CC.tptr, CC.tarray, CC.tuint, vectorLoopSourceOffset]
  all_goals rfl

theorem vector_loop_value (m before : CC.Mem) (le : CC.TempEnv)
    (vectors : VectorLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before (vectorLoopValue high) =
      some (.Vptr vectors.block (vectorLoopSourceOffset high i)) :=
  vector_loop_value_bound ge rfl m before le vectors high i index

theorem vector_loop_test_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 33)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr world (allocation m).1 le before vectorLoopTest =
      some (.Vint (if i.val < 32 then 1 else 0)) := by
  simp only [vectorLoopTest, vectorLoopIndex, CC.doEvalExpr, index]
  change some (CC.Val.ofBool
    (CC.Integers.Int.cmpu .Clt (CC.Integers.Int.repr i.val) 32)) = _
  have arithmetic : ∀ j : Fin 33, CC.Val.ofBool
      (CC.Integers.Int.cmpu .Clt (CC.Integers.Int.repr j.val) 32) =
      CC.Val.Vint (if j.val < 32 then 1 else 0) := by decide +kernel
  rw [arithmetic]

theorem vector_loop_test (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 33)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before vectorLoopTest =
      some (.Vint (if i.val < 32 then 1 else 0)) :=
  vector_loop_test_bound ge m before le i index

theorem vector_loop_increment_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr world (allocation m).1 le before
      (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint) =
      some (.Vint (CC.Integers.Int.repr (i.val + 1))) := by
  simp only [vectorLoopIndex, CC.doEvalExpr, index]
  change some (CC.Val.Vint (CC.Integers.Int.add (CC.Integers.Int.repr i.val) 1)) = _
  have arithmetic : ∀ j : Fin 32, CC.Integers.Int.add (CC.Integers.Int.repr j.val) 1 =
      CC.Integers.Int.repr (j.val + 1) := by decide +kernel
  rw [arithmetic]

theorem vector_loop_increment (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    CC.doEvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd vectorLoopIndex (.Econst_int 1 CC.tint) CC.tuint) =
      some (.Vint (CC.Integers.Int.repr (i.val + 1))) :=
  vector_loop_increment_bound ge m before le i index

/-- The actual loop store is constructible from the allocated header resource;
its frame is stated for arbitrary typed observations outside that slot. -/
theorem vector_loop_store_step_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, CC.doStep world
        (.State producer (vectorLoopStore high) k (allocation m).1 le before) =
        some (CC.E0, .State producer .Sskip k (allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i)) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨
          ofs + CC.sizeChunk chunk ≤ (if high then 352 else 96) + 8 * (i.val : Int) ∨
          (if high then 352 else 96) + 8 * (i.val : Int) + 8 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have base : (if high then 352 else 96 : Int) = 352 ∨
          (if high then 352 else 96 : Int) = 96 := by cases high <;> simp
      have lo : (0 : Int) ≤ ofs := by rcases base with h | h <;> omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        change ofs < (if high then 352 else 96) + 8 * (i.val : Int) + 8 at upper
        rw [null_vector_layout.2.2.2]
        rcases base with h | h <;> omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change (((if high then 352 else 96 : Int) + 8 * (i.val : Int)) % 8 == 0) = true
      have aligned : ((if high then 352 else 96 : Int) + 8 * (i.val : Int)) % 8 = 0 := by
        cases high <;> omega
      simp only [aligned, beq_self_eq_true]
  have existsStore : ∃ after, CC.Mem.store CC.Mptr before entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int))
      (.Vptr vectors.block (vectorLoopSourceOffset high i)) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr before (.Vptr entry.block (vectorLoopHeaderOffset high i))
      (.Vptr vectors.block (vectorLoopSourceOffset high i)) = some after := by
    simpa only [CC.Mem.storev, (vector_loop_offsets high i).1] using stored
  have target := vector_loop_target_bound world layout m before le entry high i index
  have value := vector_loop_value_bound world layout m before le vectors high i index
  have assigned : CC.doStep world
      (.State producer (vectorLoopStore high) k (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip k (allocation m).1 le after) := by
    simp only [vectorLoopStore, CC.doStep, target, value]
    rw [show CC.typeof (vectorLoopTarget high) = CC.tptr CC.tulong from rfl]
    rw [show CC.typeof (vectorLoopValue high) = CC.tptr CC.tulong from rfl]
    change (match CC.Mem.storev CC.Mptr before (.Vptr entry.block (vectorLoopHeaderOffset high i))
        (.Vptr vectors.block (vectorLoopSourceOffset high i)) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip k (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  refine ⟨after, assigned, CC.Mem.load_store_same stored, ?_,
    FrameBelow.store entry.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  intro chunk block ofs separate
  exact CC.Mem.load_store_other stored chunk block ofs separate

theorem vector_loop_store_step (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (high : Bool) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, CC.doStep ge
        (.State producer (vectorLoopStore high) k (allocation m).1 le before) =
        some (CC.E0, .State producer .Sskip k (allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i)) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨
          ofs + CC.sizeChunk chunk ≤ (if high then 352 else 96) + 8 * (i.val : Int) ∨
          (if high then 352 else 96) + 8 * (i.val : Int) + 8 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  vector_loop_store_step_bound ge rfl m before le k entry vectors high i index access

/-- One successful iteration of the actual exported loop, including the test,
both stores, and the uint32 counter increment. -/
theorem vector_loop_iteration_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 11
        (.State producer vectorLoop k (allocation m).1 le before)
        (.State producer vectorLoop k (allocation m).1
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
  let loopK := CC.Cont.Kloop1 vectorLoopBody vectorLoopIncrement k
  let stores := CC.Stmt.Ssequence (vectorLoopStore false) (vectorLoopStore true)
  obtain ⟨middle, lowStep, lowRead, lowOther, lowFrame, lowAccess, lowNext⟩ :=
    vector_loop_store_step_bound world layout m before le (.Kseq (vectorLoopStore true) loopK)
      entry vectors false i index access
  obtain ⟨after, highStep, highRead, highOther, highFrame, highAccess, highNext⟩ :=
    vector_loop_store_step_bound world layout m middle le loopK entry vectors true i index (lowAccess.trans access)
  have test := vector_loop_test_bound world m before le ⟨i.val, by have h := i.isLt; omega⟩ index
  change CC.doEvalExpr world (allocation m).1 le before vectorLoopTest =
    some (.Vint (if i.val < 32 then 1 else 0)) at test
  rw [ite_eq_left i.isLt] at test
  have branch : CC.doStep world
      (.State producer (.Sifthenelse vectorLoopTest .Sskip .Sbreak)
        (.Kseq stores loopK) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq stores loopK) (allocation m).1 le before) := by
    simp only [CC.doStep, test]
    rfl
  have increment : CC.doStep world
      (.State producer vectorLoopIncrement (.Kloop2 vectorLoopBody vectorLoopIncrement k)
        (allocation m).1 le after) =
      some (CC.E0, .State producer .Sskip (.Kloop2 vectorLoopBody vectorLoopIncrement k)
        (allocation m).1 (le.set Arm64Entry._i (.Vint (CC.Integers.Int.repr (i.val + 1)))) after) := by
    simp only [vectorLoopIncrement, CC.doStep, vector_loop_increment_bound world m after le i index]
  have run : InternalRun world 11
      (.State producer vectorLoop k (allocation m).1 le before)
      (.State producer vectorLoop k (allocation m).1
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

theorem vector_loop_iteration (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun ge 11
        (.State producer vectorLoop k (allocation m).1 le before)
        (.State producer vectorLoop k (allocation m).1
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
      after.nextblock = before.nextblock :=
  vector_loop_iteration_bound ge rfl m before le k entry vectors i index access

/-- Initialization reaches the actual loop with an unsigned zero counter. -/
theorem vector_loop_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 4 (.State producer beforeVectorLoop k (allocation m).1 le before)
      (.State producer vectorLoop (.Kseq afterVectorLoop k) (allocation m).1
        (le.set Arm64Entry._i (.Vint 0)) before) := by
  rw [vector_loop_source]
  exact .step trivial (CC.doStep_sound world _ _ _ rfl)
    (.step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ rfl)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _))))

theorem vector_loop_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 4 (.State producer beforeVectorLoop k (allocation m).1 le before)
      (.State producer vectorLoop (.Kseq afterVectorLoop k) (allocation m).1
        (le.set Arm64Entry._i (.Vint 0)) before) :=
  vector_loop_initialized_bound ge m before le k

/-- At counter32 the actual break exits to the source consumer sequence. -/
theorem vector_loop_exit_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (index : le.get Arm64Entry._i = some (.Vint 32)) :
    InternalRun world 6
      (.State producer vectorLoop (.Kseq afterVectorLoop k) (allocation m).1 le before)
      (.State producer afterVectorLoop k (allocation m).1 le before) := by
  have test := vector_loop_test_bound world m before le ⟨32, by decide⟩ index
  have branch : CC.doStep world
      (.State producer (.Sifthenelse vectorLoopTest .Sskip .Sbreak)
        (.Kseq (.Ssequence (vectorLoopStore false) (vectorLoopStore true))
          (.Kloop1 vectorLoopBody vectorLoopIncrement (.Kseq afterVectorLoop k)))
        (allocation m).1 le before) =
      some (CC.E0, .State producer .Sbreak
        (.Kseq (.Ssequence (vectorLoopStore false) (vectorLoopStore true))
          (.Kloop1 vectorLoopBody vectorLoopIncrement (.Kseq afterVectorLoop k)))
        (allocation m).1 le before) := by
    simp only [CC.doStep, test]
    rfl
  exact .step trivial (CC.doStep_sound world _ _ _ rfl)
    (.step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ branch)
        (.step trivial (CC.doStep_sound world _ _ _ rfl)
          (.step trivial (CC.doStep_sound world _ _ _ rfl)
            (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _))))))

theorem vector_loop_exit (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (index : le.get Arm64Entry._i = some (.Vint 32)) :
    InternalRun ge 6
      (.State producer vectorLoop (.Kseq afterVectorLoop k) (allocation m).1 le before)
      (.State producer afterVectorLoop k (allocation m).1 le before) :=
  vector_loop_exit_bound ge m before le k index

private theorem vector_pair_separate (high side : Bool) (i j : Fin 32) (different : j ≠ i) :
    (if high then 352 else 96 : Int) + 8 * (j.val : Int) + 8 ≤
      (if side then 352 else 96 : Int) + 8 * (i.val : Int) ∨
    (if side then 352 else 96 : Int) + 8 * (i.val : Int) + 8 ≤
      (if high then 352 else 96 : Int) + 8 * (j.val : Int) := by
  have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
  have ib := i.isLt
  have jb := j.isLt
  cases high <;> cases side <;> simp only [Bool.false_eq_true, ite_false, ite_true] <;> omega

private theorem vector_loop_iteration_frame (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (vectors : VectorLocal m) (i : Fin 32)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr i.val)))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 11
        (.State producer vectorLoop k (allocation m).1 le before)
        (.State producer vectorLoop k (allocation m).1
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
    vector_loop_iteration_bound world layout m before le k entry vectors i index access
  refine ⟨after, run, ?_, ?_, ?_, frame, finalAccess, next⟩
  · intro high; cases high
    · exact lowRead
    · exact highRead
  · intro high j different
    exact keep _ _ _ (.inr (vector_pair_separate high false i j different))
      (.inr (vector_pair_separate high true i j different))
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

private theorem vector_loop_suffix (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (fuel start : Nat) (total : start + fuel = 32)
    (m : CC.Mem) (entry : HeaderLocal m) (vectors : VectorLocal m)
    (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (index : le.get Arm64Entry._i = some (.Vint (CC.Integers.Int.repr start)))
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun world (11 * fuel)
        (.State producer vectorLoop k (allocation m).1 le before)
        (.State producer vectorLoop k (allocation m).1 finalLe after) ∧
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
      vector_loop_iteration_frame world layout m before le k entry vectors i index access
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

/-- All 32 actual iterations reach the source consumer sequence.  Both pointer
arrays are populated, all other typed header/local observations are framed. -/
theorem vector_pointers_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (entry : HeaderLocal m)
    (vectors : VectorLocal m) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun world 362
        (.State producer beforeVectorLoop k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
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
    vector_loop_suffix world layout 32 0 rfl m entry vectors before (le.set Arm64Entry._i (.Vint 0))
      (.Kseq afterVectorLoop k) (CC.PTree.gss _ _ _) access
  refine ⟨after, finalLe,
    ((vector_loop_initialized_bound world m before le k).trans loopRun).trans
      (vector_loop_exit_bound world m after finalLe k finalIndex), finalIndex, ?_,
    (fun high i => read high i (Nat.zero_le _)), outside, frame, finalAccess, next⟩
  intro id different
  exact (temps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm different))

theorem vector_pointers_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (vectors : VectorLocal m) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun ge 362
        (.State producer beforeVectorLoop k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ chunk block ofs, block ≠ entry.block ∨ ofs + CC.sizeChunk chunk ≤ 96 ∨ 608 ≤ ofs →
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  vector_pointers_initialized_bound ge rfl m before entry vectors le k access

/-- The reached tail calls the actual continuation temporary with &entry. -/
theorem vector_loop_consumer_source : afterVectorLoop = .Ssequence
    (.Scall (some Arm64Entry._t'131)
      (.Etempvar Arm64Entry._continuation
        (CC.tptr (.Tfunction [CC.tptr headerType] CC.tuint CC.cc_default)))
      [.Eaddrof (.Evar Arm64Entry._entry headerType) (CC.tptr headerType)])
    (.Sreturn (some (.Etempvar Arm64Entry._t'131 CC.tuint))) := rfl

/-- Complete header construction and its vector loop, at the same allocated
entry, reaching the actual consumer sequence with all 92 field observations. -/
theorem header_initialized_before_consumer_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ vectors : VectorLocal m, ∃ after finalLe,
      InternalRun world 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  obtain ⟨entry, cells, sources, middle, headRun, scalarReads, _, tailReads,
    headLocals, headFrame, headAccess, headNext⟩ :=
    header_initialized_before_loop_bound world layout symbols m before le k access
  let vectors := Classical.choice (vector_local m)
  obtain ⟨after, finalLe, loopRun, index, temps, vectorReads, outside, loopFrame, loopAccess, loopNext⟩ :=
    vector_pointers_initialized_bound world layout m middle entry vectors le k (headAccess.trans access)
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

theorem header_initialized_before_consumer (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ vectors : VectorLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalLe.get id = le.get id) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_initialized_before_consumer_bound ge rfl (fun store => (payload_callback_binding store).1) m before le k access

/-- Both borrowed caches survive the complete actual vector-pointer loop. -/
theorem header_caches_before_consumer_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after finalLe,
      InternalRun world 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, _, _, after, finalLe, run, _, _, reads, _, _, _, frame, afterAccess, next⟩ :=
    header_initialized_before_consumer_bound world layout symbols m before le k access
  obtain ⟨stack, stackStorage⟩ := header_cache_storage false m after entry cells (afterAccess.trans access) reads
  obtain ⟨returns, returnStorage⟩ := header_cache_storage true m after entry cells (afterAccess.trans access) reads
  exact ⟨stack, returns, after, finalLe, run, stackStorage, returnStorage, frame, afterAccess, next⟩

theorem header_caches_before_consumer (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_caches_before_consumer_bound ge rfl (fun store => (payload_callback_binding store).1) m before le k access

end KProgFormal.ClightRefinement.Arm64Producer
