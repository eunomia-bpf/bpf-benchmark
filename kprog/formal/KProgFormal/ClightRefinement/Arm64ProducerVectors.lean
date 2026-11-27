import KProgFormal.ClightRefinement.Arm64ProducerFlags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def vectorTypeFor (tag : CC.Ident) : CC.Ty := .Tstruct tag CC.noattr
def vectorArrayTypeFor (tag : CC.Ident) : CC.Ty := CC.tarray (vectorTypeFor tag) 32

def vectorType : CC.Ty := .Tstruct Arm64Entry.__2854 CC.noattr
def vectorArrayType : CC.Ty := CC.tarray vectorType 32

private def vectorComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry.__2854).get (by decide +kernel)

theorem vector_layout :
    ge.genv_cenv.get Arm64Entry.__2854 = some vectorComposite ∧
    CC.sizeof ge.genv_cenv vectorType = 16 ∧
    CC.fieldOffset ge.genv_cenv Arm64Entry._lo vectorComposite.co_members = .OK (0, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Entry._hi vectorComposite.co_members = .OK (8, .Full) ∧
    CC.sizeof ge.genv_cenv vectorArrayType = 512 ∧
    (Arm64Entry.___a64_vectors, vectorArrayType) ∈ producer.fn_vars := by decide +kernel

def vectorStart : CC.Stmt := by
  run_tac do
    let body ← Lean.Elab.Term.elabTerm (← `((flagDeclaration 3).rest)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "producer LR declaration no longer precedes vectors"
    Lean.Elab.Tactic.closeMainGoal `actual_vector_start exposed.getAppArgs[1]!

theorem lr_zero_source : (flagDeclaration 3).rest =
    .Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong)
      (.Econst_int (0#32) CC.tint)) vectorStart := by rfl

private def vectorParts : List (CC.Stmt × CC.Ident) × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(vectorStart)) none
    let mut front : Array Lean.Expr := #[]
    for _ in [:64] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer no longer has all 64 vector input declarations"
      let init := body.getAppArgs[0]!
      let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf init)
      unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer vector call/store sequence changed"
      let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf exposed.getAppArgs[0]!)
      unless call.isAppOfArity ``CC.Stmt.Scall 3 do
        throwError "producer vector input call changed"
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
      unless result.isAppOfArity ``Option.some 2 do
        throwError "producer vector input temporary changed"
      front := front.push (← Lean.Meta.mkAppM ``Prod.mk #[init, result.getAppArgs[1]!])
      body := body.getAppArgs[1]!
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt, Lean.mkConst ``CC.Ident]
    let rows ← Lean.Meta.mkListLit rowType front.toList
    Lean.Elab.Tactic.closeMainGoal `actual_vector_parts (← Lean.Meta.mkAppM ``Prod.mk #[rows, body])

private theorem vector_count : vectorParts.1.length = 64 := by rfl

def vectorInputTemp (i : Fin 64) : CC.Ident :=
  (vectorParts.1[i.val]'(by rw [vector_count]; exact i.isLt)).2

def afterVectorInputs : CC.Stmt := vectorParts.2

def vectorField (i : Fin 64) : CC.Ident :=
  if i.val % 2 == 0 then Arm64Entry._lo else Arm64Entry._hi

def vectorFieldOffset (i : Fin 64) : Int := if i.val % 2 == 0 then 0 else 8

def vectorTargetFor (tag : CC.Ident) (i : Fin 64) : CC.Expr :=
  .Efield (.Ederef (.Ebinop .Oadd (.Evar Arm64Entry.___a64_vectors (vectorArrayTypeFor tag))
    (.Econst_int (CC.Integers.Int.repr (i.val / 2)) CC.tint) (CC.tptr (vectorTypeFor tag))) (vectorTypeFor tag))
    (vectorField i) CC.tulong

def vectorStoreFor (tag temporary : CC.Ident) (i : Fin 64) : CC.Stmt :=
  .Sassign (vectorTargetFor tag i) (.Etempvar temporary CC.tulong)

def vectorInitializerFor (tag temporary : CC.Ident) (i : Fin 64) : CC.Stmt :=
  .Ssequence (.Scall (some temporary)
    (.Evar Arm64Entry._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (6#32) CC.tint]) (vectorStoreFor tag temporary i)

def vectorTarget (i : Fin 64) : CC.Expr := vectorTargetFor Arm64Entry.__2854 i
def vectorStore (i : Fin 64) : CC.Stmt := vectorStoreFor Arm64Entry.__2854 (vectorInputTemp i) i
def vectorInitializer (i : Fin 64) : CC.Stmt := vectorInitializerFor Arm64Entry.__2854 (vectorInputTemp i) i

private theorem vector_initializers_source : vectorParts.1.map Prod.fst = List.ofFn vectorInitializer := by rfl

theorem vector_inputs_source : vectorStart =
    (List.ofFn vectorInitializer).foldr CC.Stmt.Ssequence afterVectorInputs := by
  have source : vectorStart = (vectorParts.1.map Prod.fst).foldr CC.Stmt.Ssequence afterVectorInputs := rfl
  rw [vector_initializers_source] at source
  exact source

def vectorStage (n : Nat) : CC.Stmt :=
  ((List.ofFn vectorInitializer).drop n).foldr CC.Stmt.Ssequence afterVectorInputs

theorem first_vector_stage : vectorStage 0 = vectorStart := by
  simpa only [vectorStage, List.drop_zero] using vector_inputs_source.symm

theorem vector_stage_next (i : Fin 64) :
    vectorStage i.val = .Ssequence (vectorInitializer i) (vectorStage (i.val + 1)) := by
  simp only [vectorStage]
  rw [List.drop_eq_getElem_cons (by simpa only [List.length_ofFn] using i.isLt)]
  simp only [List.getElem_ofFn, List.foldr_cons]

theorem final_vector_stage : vectorStage 64 = afterVectorInputs := by
  have bound : (List.ofFn vectorInitializer).length ≤ 64 := by simp
  simp only [vectorStage, List.drop_of_length_le bound, List.foldr_nil]

def vectorPointerOffset (i : Fin 64) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add
    (CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 16)
        (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr (i.val / 2)))))
    (CC.Integers.Ptrofs.repr (vectorFieldOffset i))

theorem vector_field_offsets : ∀ i : Fin 64,
    CC.fieldOffset ge.genv_cenv (vectorField i) vectorComposite.co_members =
      .OK (vectorFieldOffset i, .Full) := by decide +kernel

theorem vector_offsets : ∀ i : Fin 64,
    CC.Integers.Ptrofs.unsigned (vectorPointerOffset i) = 8 * (i.val : Int) := by decide +kernel

/-- Actual allocated vector-array resource, with no assumed contents. -/
structure VectorLocal (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType)
  fresh : m.nextblock.toNat ≤ block.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0 512 .Cur .Writable = true

theorem vector_local (m : CC.Mem) : Nonempty (VectorLocal m) := by
  obtain ⟨block, binding, fresh, _, range⟩ :=
    local_storage m Arm64Entry.___a64_vectors vectorArrayType vector_layout.2.2.2.2.2
  rw [vector_layout.2.2.2.2.1] at range
  exact ⟨⟨block, binding, fresh, CC.Mem.rangePerm_implies range
    (by decide : CC.permOrder .Freeable .Writable = true)⟩⟩

def vectorContinuationFor (f : CC.Function) (e : CC.Env) (tag temporary : CC.Ident)
    (i : Fin 64) (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some temporary) f e le (.Kseq (vectorStoreFor tag temporary i) (.Kseq rest k))

def vectorContinuation (i : Fin 64) (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  vectorContinuationFor producer (allocation m).1 Arm64Entry.__2854 (vectorInputTemp i)
    i (vectorStage (i.val + 1)) le k

/-- The real call prefix with explicit function, environment, symbol and successor. -/
theorem vector_call_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (inputBlock : CC.Block)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction)
    (tag temporary : CC.Ident) (i : Fin 64) (rest : CC.Stmt)
    (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Entry._native_lab_entry_input = none) :
    steps world 3 (.State f (.Ssequence (vectorInitializerFor tag temporary i) rest) k e le memory) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (vectorContinuationFor f e tag temporary i rest le k) memory) ∧
    InternalPath world 3 (.State f (.Ssequence (vectorInitializerFor tag temporary i) rest) k e le memory) := by
  simp +decide [steps, InternalPath, InternalState, vectorInitializerFor, vectorContinuationFor,
    CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.typeof,
    CC.tptr, CC.tint, CC.tuint, CC.tulong, CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
    CC.Integers.MI.zero, CC.typeOfFundef, Arm64OriginCache.inputFunction,
    Arm64OriginCache.inputEF, unshadowed, inputBinding.1, inputBinding.2,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.E0, CC.Eapp]

theorem vector_input_ready_bound (world : CC.CGenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 64) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 3 (.State producer (vectorStage i.val) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (vectorContinuation i m le k) memory) := by
  rw [vector_stage_next i]
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  have run := vector_call_body world producer (allocation m).1 (CC.Positive.ofNat 64) inputBinding
    Arm64Entry.__2854 (vectorInputTemp i) i (vectorStage (i.val + 1)) memory le k unshadowed
  exact internalRun_of_steps run.2 run.1

theorem vector_store_exists (m supplied : CC.Mem) (localVector : VectorLocal m)
    (i : Fin 64) (value : BitVec 64) (access : supplied.access = (allocation m).2.access) :
    ∃ after, CC.Mem.store .Mint64 supplied localVector.block (8 * (i.val : Int))
      (.Vlong value) = some after := by
  have writable : CC.Mem.validAccess supplied .Mint64 localVector.block
      (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < (512 : Int) := by change ofs < 8 * (i.val : Int) + 8 at upper; omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 localVector.block 0 512 .Cur .Writable
        localVector.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      have aligned : (8 * (i.val : Int)) % 8 = 0 := by omega
      simp only [aligned, beq_self_eq_true]
  unfold CC.Mem.store
  rw [writable]
  exact ⟨_, rfl⟩

/-- The vector target needs only its own composite record, stride and fields. -/
structure VectorLayout (world : CC.CGenv) (tag : CC.Ident) where
  composite : CC.Composite
  binding : world.genv_cenv.get tag = some composite
  size : composite.co_sizeof = 16
  offsets : ∀ i : Fin 64, CC.fieldOffset world.genv_cenv (vectorField i) composite.co_members =
    .OK (vectorFieldOffset i, .Full)

theorem vector_layout_bound (world : CC.CGenv) (layout : world.genv_cenv = ge.genv_cenv) :
    Nonempty (VectorLayout world Arm64Entry.__2854) := by
  refine ⟨⟨vectorComposite, ?_, ?_, ?_⟩⟩
  · rw [layout]; exact vector_layout.1
  · simpa only [vectorType, vectorTypeFor, CC.sizeof, vector_layout.1] using vector_layout.2.1
  · rw [layout]; exact vector_field_offsets

/-- Shared return/store execution, independent of the function and anonymous tag. -/
theorem vector_return_body_stored (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (tag temporary : CC.Ident) (i : Fin 64) (rest : CC.Stmt) (supplied after : CC.Mem) (block : CC.Block)
    (shape : VectorLayout world tag)
    (actualBinding : e.get Arm64Entry.___a64_vectors = some (block, vectorArrayTypeFor tag))
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (stored : CC.Mem.storev .Mint64 supplied (.Vptr block (vectorPointerOffset i))
      (.Vlong value) = some after) :
    InternalRun world 4
      (.Returnstate (.Vlong value) (vectorContinuationFor f e tag temporary i rest le k) supplied)
      (.State f rest k e (le.set temporary (.Vlong value)) after) := by
  have address : CC.doEvalLvalue world e
      (le.set temporary (.Vlong value)) supplied (vectorTargetFor tag i) =
      some (block, vectorPointerOffset i, .Full) := by
    simp [vectorTargetFor, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc,
      CC.lvalOfField, CC.typeof, CC.accessMode, vectorTypeFor, vectorArrayTypeFor,
      shape.binding, shape.size, shape.offsets i, actualBinding,
      CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
      CC.Cop.ptrofsOfInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
      CC.tptr, CC.tarray, CC.tint, vectorPointerOffset]
  have assignment : CC.doStep world
      (.State f (vectorStoreFor tag temporary i) (.Kseq rest k)
        e (le.set temporary (.Vlong value)) supplied) =
      some (CC.E0, .State f .Sskip (.Kseq rest k)
        e (le.set temporary (.Vlong value)) after) := by
    simp only [vectorStoreFor, CC.doStep, address, CC.doEvalExpr, CC.PTree.gss, CC.typeof]
    simp [vectorTargetFor, CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
      CC.doAssignLoc, CC.accessMode, stored]
  have r0 : CC.doStep world (.Returnstate (.Vlong value) (vectorContinuationFor f e tag temporary i rest le k) supplied) =
      some (CC.E0, .State f .Sskip
        (.Kseq (vectorStoreFor tag temporary i) (.Kseq rest k)) e
        (le.set temporary (.Vlong value)) supplied) := rfl
  have r1 : CC.doStep world (.State f .Sskip
        (.Kseq (vectorStoreFor tag temporary i) (.Kseq rest k)) e
        (le.set temporary (.Vlong value)) supplied) =
      some (CC.E0, .State f (vectorStoreFor tag temporary i) (.Kseq rest k)
        e (le.set temporary (.Vlong value)) supplied) := rfl
  have r3 : CC.doStep world (.State f .Sskip (.Kseq rest k)
        e (le.set temporary (.Vlong value)) after) =
      some (CC.E0, .State f rest k e
        (le.set temporary (.Vlong value)) after) := rfl
  exact .step trivial (CC.doStep_sound world _ _ _ r0)
    (.step trivial (CC.doStep_sound world _ _ _ r1)
      (.step trivial (CC.doStep_sound world _ _ _ assignment)
        (.step trivial (CC.doStep_sound world _ _ _ r3) (.refl _))))

/-- Original full interface delegates once to the same stored execution body. -/
theorem vector_return_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (tag temporary : CC.Ident) (i : Fin 64) (rest : CC.Stmt) (m supplied after : CC.Mem)
    (localVector : VectorLocal m) (shape : VectorLayout world tag)
    (actualBinding : e.get Arm64Entry.___a64_vectors = some (localVector.block, vectorArrayTypeFor tag))
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (stored : CC.Mem.storev .Mint64 supplied (.Vptr localVector.block (vectorPointerOffset i))
      (.Vlong value) = some after) :
    InternalRun world 4
      (.Returnstate (.Vlong value) (vectorContinuationFor f e tag temporary i rest le k) supplied)
      (.State f rest k e (le.set temporary (.Vlong value)) after) :=
  vector_return_body_stored world f e tag temporary i rest supplied after localVector.block shape
    actualBinding le k value stored


/-- One shared memory witness and readback/frame construction for every visit. -/
theorem vector_input_returns_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (inputBlock : CC.Block)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction)
    (unshadowed : e.get Arm64Entry._native_lab_entry_input = none)
    (tag temporary : CC.Ident) (i : Fin 64) (rest : CC.Stmt) (m before supplied : CC.Mem)
    (localVector : VectorLocal m) (shape : VectorLayout world tag)
    (actualBinding : e.get Arm64Entry.___a64_vectors = some (localVector.block, vectorArrayTypeFor tag))
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ after, CC.Star (CC.Step2 world)
      (.State f (.Ssequence (vectorInitializerFor tag temporary i) rest) k e le before)
      trace (.State f rest k e (le.set temporary (.Vlong value)) after) ∧
      CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) = some (.Vlong value) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 supplied localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  obtain ⟨after, stored⟩ := vector_store_exists m supplied localVector i value access
  have storev : CC.Mem.storev .Mint64 supplied (.Vptr localVector.block (vectorPointerOffset i))
      (.Vlong value) = some after := by
    simpa only [CC.Mem.storev, vector_offsets] using stored
  have suffix := vector_return_body world f e tag temporary i rest m supplied after localVector shape
    actualBinding le k value storev
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (vectorContinuationFor f e tag temporary i rest le k) before)
      trace (.Returnstate (.Vlong value) (vectorContinuationFor f e tag temporary i rest le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  have prefixRun := vector_call_body world f e inputBlock inputBinding tag temporary i rest before le k unshadowed
  refine ⟨after, ?_, CC.Mem.load_store_same stored, ?_, ?_,
    FrameBelow.store localVector.fresh stored, CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
      star_trans (internalRun_of_steps prefixRun.2 prefixRun.1).sound
        (star_trans call suffix.sound)
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : 8 * (j.val : Int) + 8 ≤ 8 * (i.val : Int) ∨
        8 * (i.val : Int) + 8 ≤ 8 * (j.val : Int) := by omega
    apply CC.Mem.load_store_other stored
    exact Or.inr separate
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound localVector.binding different))

theorem vector_input_returns_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 64) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ localVector : VectorLocal m, ∃ after,
      CC.Star (CC.Step2 world)
        (.State producer (vectorStage i.val) k (allocation m).1 le before)
        trace (.State producer (vectorStage (i.val + 1)) k (allocation m).1
          (le.set (vectorInputTemp i) (.Vlong value)) after) ∧
      CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) = some (.Vlong value) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 supplied localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  obtain ⟨localVector⟩ := vector_local m
  obtain ⟨shape⟩ := vector_layout_bound world layout
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  obtain ⟨after, run, reads, lanes, locals, frame, finalAccess, next⟩ :=
    vector_input_returns_body world producer (allocation m).1 (CC.Positive.ofNat 64) inputBinding unshadowed
      Arm64Entry.__2854 (vectorInputTemp i) i (vectorStage (i.val + 1)) m before supplied localVector shape
      localVector.binding le k value trace provider access
  refine ⟨localVector, after, ?_, reads, lanes, locals, frame, finalAccess, next⟩
  rw [vector_stage_next i]
  exact run

theorem vector_input_ready (i : Fin 64) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 3 (.State producer (vectorStage i.val) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (vectorContinuation i m le k) memory) :=
  vector_input_ready_bound ge producer_input_binding i m memory le k

theorem vector_input_returns (i : Fin 64) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ localVector : VectorLocal m, ∃ after,
      CC.Star (CC.Step2 ge)
        (.State producer (vectorStage i.val) k (allocation m).1 le before)
        trace (.State producer (vectorStage (i.val + 1)) k (allocation m).1
          (le.set (vectorInputTemp i) (.Vlong value)) after) ∧
      CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) = some (.Vlong value) ∧
      (∀ j : Fin 64, j ≠ i → CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 supplied localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock :=
  vector_input_returns_bound ge rfl producer_input_binding i m before supplied le k value trace provider access

/-- The actual LR declaration immediately before vector inputs writes zero,
framing all other declared local loads and old caller memory. -/
theorem lr_initialized_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (rest : CC.Stmt) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (actualBinding : ∀ block, (allocation m).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) →
      e.get Arm64Entry.___a64_lr = some (block, CC.tulong))
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) ∧
      InternalRun world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint)) rest) k e le before)
        (.State f rest k e le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_lr →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨block, binding, fresh, writable⟩ := scalar_local m Arm64Entry.___a64_lr CC.tulong .Mint64
    (by decide +kernel) rfl (by decide)
  obtain ⟨after, stored, afterAccess⟩ := create_store m before .Mint64 block (.Vlong (0#64)) access writable
  have exec : steps world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint)) rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
      InternalPath world 3 (.State f (.Ssequence (.Sassign (.Evar Arm64Entry.___a64_lr CC.tulong) (.Econst_int (0#32) CC.tint)) rest) k e le before) := by
    change CC.Mem.storev .Mint64 before (.Vptr block (0#64)) (.Vlong (0#64)) = some after at stored
    simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doEvalLvalue, CC.doEvalExpr,
      CC.lvalOfVar, CC.doAssignLoc, CC.accessMode, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntLong, CC.Integers.Int.signed, CC.Integers.MI.signed,
      CC.Integers.Int64.repr, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.tulong, CC.tint,
      CC.Archi.ptr64, CC.E0, CC.Eapp, actualBinding block binding, stored]
  refine ⟨block, after, binding, internalRun_of_steps exec.2 exec.1,
    CC.Mem.load_store_same stored, ?_, FrameBelow.store fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  intro id ty other bound different chunk ofs
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
  exact CC.Mem.load_store_other stored chunk other ofs
    (.inl (distinct _ _ _ _ bound binding different))

theorem lr_initialized_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) ∧
      InternalRun world 3 (.State producer (flagDeclaration 3).rest k (allocation m).1 le before)
        (.State producer vectorStart k (allocation m).1 le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_lr →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  rw [lr_zero_source]
  exact lr_initialized_body world producer (allocation m).1 vectorStart m before le k
    (fun _ bound => bound) access

theorem lr_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) ∧
      InternalRun ge 3 (.State producer (flagDeclaration 3).rest k (allocation m).1 le before)
        (.State producer vectorStart k (allocation m).1 le after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_lr →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  lr_initialized_bound ge m before le k access

/-- The real LR initializer reaches the first vector-input boundary in six
internal transitions, retaining its zero word and complete local framing. -/
theorem lr_and_first_vector (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ block ready, (allocation m).1.get Arm64Entry.___a64_lr = some (block, CC.tulong) ∧
      InternalRun ge 6 (.State producer (flagDeclaration 3).rest k (allocation m).1 le before)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
          (vectorContinuation 0 m le k) ready) ∧
      CC.Mem.loadv .Mint64 ready (.Vptr block 0) = some (.Vlong 0) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ Arm64Entry.___a64_lr →
        ∀ chunk ofs, CC.Mem.load chunk ready other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow m.nextblock before ready ∧ ready.access = before.access ∧
      ready.nextblock = before.nextblock := by
  obtain ⟨block, ready, binding, lrRun, read, others, frame, finalAccess, next⟩ :=
    lr_initialized m before le k access
  have call := vector_input_ready 0 m ready le k
  simp only [Fin.val_zero, first_vector_stage] at call
  exact ⟨block, ready, binding, lrRun.trans call, read, others, frame, finalAccess, next⟩

end KProgFormal.ClightRefinement.Arm64Producer
