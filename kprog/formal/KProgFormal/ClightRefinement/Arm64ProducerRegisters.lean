import KProgFormal.ClightRefinement.Arm64ProducerRegisterSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def RegisterDeclaration.continuation (d : RegisterDeclaration) (m : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some d.inputTemp) producer (allocation m).1 le
    (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))

def RegisterDeclaration.temps (d : RegisterDeclaration) (le : CC.TempEnv)
    (value : BitVec 64) : CC.TempEnv :=
  (le.set d.inputTemp (.Vlong value)).set d.resultTemp (.Vlong value)

/-- The exported declaration schema reaches the real input callee in any
function/environment whose local and global bindings resolve that callee. -/
theorem declaration_call_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (inputBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction) (d : RegisterDeclaration) (memory : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Entry._native_lab_entry_input = none) (different : CC.Integers.Int.eq d.index (30#32) = false) :
    steps world 5 (.State f d.body k e le memory) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (.Kcall (some d.inputTemp) f e le
          (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) memory) ∧
    InternalPath world 5 (.State f d.body k e le memory) := by
  have indexDifferent : d.index ≠ (30#32) := by
    simpa only [CC.Integers.Int.eq, CC.Integers.MI.eq, beq_eq_false_iff_ne] using different
  simp +decide [steps, InternalPath, InternalState, RegisterDeclaration.body,
    CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.typeof,
    CC.typeconv, CC.removeAttributes, CC.tattr, unshadowed, binding.1,
    binding.2, CC.Genv.findFunct, CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.eq,
    CC.typeOfFundef, Arm64OriginCache.inputFunction, Arm64OriginCache.inputEF, CC.Cop.classifyFun,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue,
    CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, indexDifferent,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.tuint, CC.tint, CC.tulong, CC.E0, CC.Eapp]

private theorem declaration_call_exec (world : CC.CGenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (d : RegisterDeclaration) (m memory : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (different : CC.Integers.Int.eq d.index (30#32) = false) :
    steps world 5 (.State producer d.body k (allocation m).1 le memory) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (d.continuation m le k) memory) ∧
    InternalPath world 5 (.State producer d.body k (allocation m).1 le memory) := by
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  exact declaration_call_body world producer (allocation m).1 (CC.Positive.ofNat 64)
    binding d memory le k unshadowed different

/-- Every actual x0--x29 initializer reaches its real kind-6 call. -/
theorem register_input_ready_bound (world : CC.CGenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 30) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
    InternalRun world 5 (.State producer (registerDeclarationStage j) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        ((registerDeclaration j).continuation m le k) memory) := by
  dsimp only
  let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
  have source := register_declarations_source j
  have different : CC.Integers.Int.eq (registerDeclaration j).index (30#32) = false := by
    rw [source.2.2.2]
    change (i.val == 30) = false
    exact beq_eq_false_iff_ne.mpr (Nat.ne_of_lt i.isLt)
  rw [source.1]
  have run := declaration_call_exec world binding (registerDeclaration j) m memory le k different
  exact internalRun_of_steps run.2 run.1

structure DeclarationStores (d : RegisterDeclaration) (m supplied : CC.Mem) (value : BitVec 64) where
  wordBlock : CC.Block
  tagBlock : CC.Block
  middle : CC.Mem
  after : CC.Mem
  wordBinding : (allocation m).1.get d.word = some (wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr)
  tagBinding : (allocation m).1.get d.tag = some (tagBlock, CC.tuchar)
  storeWord : CC.Mem.storev .Mint64 supplied (.Vptr wordBlock (0#64)) (.Vlong value) = some middle
  storeTag : CC.Mem.storev .Mint8unsigned middle (.Vptr tagBlock (0#64)) (.Vint (0#32)) = some after
  wordRead : CC.Mem.loadv .Mint64 after (.Vptr wordBlock 0) = some (.Vlong value)
  tagRead : CC.Mem.loadv .Mint8unsigned after (.Vptr tagBlock 0) = some (.Vint 0)
  otherLocals : ∀ id ty block, (allocation m).1.get id = some (block, ty) →
    id ≠ d.word → id ≠ d.tag → ∀ chunk ofs,
      CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  next : after.nextblock = supplied.nextblock

/-- A single shared memory construction for any declared word/tag pair. -/
theorem declaration_stores_for (d : RegisterDeclaration) (m supplied : CC.Mem) (value : BitVec 64)
    (wordMember : (d.word, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∈ producer.fn_vars)
    (tagMember : (d.tag, CC.tuchar) ∈ producer.fn_vars) (distinctNames : d.word ≠ d.tag)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (DeclarationStores d m supplied value) := by
  obtain ⟨xb, cell, cellFresh, cellWritable⟩ := scalar_local m d.word
    (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr) .Mint64 wordMember (by decide +kernel) (by decide)
  obtain ⟨tb, tag, tagFresh, tagWritable⟩ := scalar_local m d.tag
    CC.tuchar .Mint8unsigned tagMember rfl (by decide)
  obtain ⟨middle, storeWord, middleAccess⟩ := create_store m supplied .Mint64 xb (.Vlong value) access cellWritable
  obtain ⟨after, storeTag, afterAccess⟩ := create_store m middle .Mint8unsigned tb (.Vint (0#32)) middleAccess tagWritable
  have locals := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
  have distinct : xb ≠ tb := locals _ _ _ _ cell tag distinctNames
  refine ⟨⟨xb, tb, middle, after, cell, tag, storeWord, storeTag, ?_, ?_, ?_,
    (FrameBelow.store cellFresh storeWord).trans (FrameBelow.store tagFresh storeTag),
    afterAccess.trans access.symm, (CC.Mem.store_nextblock storeTag).trans (CC.Mem.store_nextblock storeWord)⟩⟩
  · exact (CC.Mem.load_store_other storeTag .Mint64 xb 0 (.inl distinct)).trans
      (CC.Mem.load_store_same storeWord)
  · simpa [CC.Mem.loadv, CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using CC.Mem.load_store_same storeTag
  · intro id ty block bound notWord notTag chunk ofs
    exact (CC.Mem.load_store_other storeTag chunk block ofs (.inl (locals _ _ _ _ bound tag notTag))).trans
      (CC.Mem.load_store_other storeWord chunk block ofs (.inl (locals _ _ _ _ bound cell notWord)))

private theorem declaration_stores (i : Fin 31) (m supplied : CC.Mem) (value : BitVec 64)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (DeclarationStores (registerDeclaration i) m supplied value) := by
  exact declaration_stores_for (registerDeclaration i) m supplied value
    (register_declarations_source i).2.1 (register_declarations_source i).2.2.1
    (by have different : ∀ i : Fin 31, (registerDeclaration i).word ≠ (registerDeclaration i).tag := by decide +kernel
        exact different i) access

/-- The named GPR record and its x field are the only composite facts used
by declaration writeback and the x30 zero branch. -/
def GprLayout (world : CC.CGenv) : Prop :=
  world.genv_cenv.get Arm64Entry._arm64_sim_gpr = some gprComposite ∧
  CC.unionFieldOffset world.genv_cenv Arm64Entry._x gprComposite.co_members = .OK (0, .Full)

/-- Execute a returned input in the actual caller using the shared stores. -/
theorem declaration_return_body_stored (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (supplied middle after : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (wordBlock tagBlock : CC.Block)
    (storedWord : CC.Mem.storev .Mint64 supplied (.Vptr wordBlock (0#64)) (.Vlong value) = some middle)
    (storedTag : CC.Mem.storev .Mint8unsigned middle (.Vptr tagBlock (0#64)) (.Vint (0#32)) = some after)
    (wordBinding : e.get d.word = some (wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (tagBlock, CC.tuchar)) :
    steps world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) =
      some (CC.E0, .State f d.rest k e (d.temps le value) after) ∧
    InternalPath world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) := by
  simp [steps, InternalPath, InternalState, RegisterDeclaration.temps,
    RegisterDeclaration.setValue, RegisterDeclaration.storeValue, RegisterDeclaration.storeTag,
    CC.doStep, CC.setOpttemp, CC.PTree.gss, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
    CC.doDerefLoc, CC.doAssignLoc, CC.lvalOfField, CC.typeof, CC.accessMode,
    gpr.1, gpr.2, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr,
    CC.Integers.MI.zero, CC.Integers.MI.add, CC.tuchar, CC.tuint, CC.tulong, CC.E0, CC.Eapp,
    wordBinding, tagBinding, storedWord, storedTag]

/-- Preserve the mature full API by the same single execution proof. -/
theorem declaration_return_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (m supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (writes : DeclarationStores d m supplied value)
    (wordBinding : e.get d.word = some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (writes.tagBlock, CC.tuchar)) :
    steps world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) =
      some (CC.E0, .State f d.rest k e (d.temps le value) writes.after) ∧
    InternalPath world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) := by
  exact declaration_return_body_stored world f e gpr d supplied writes.middle writes.after le k value
    writes.wordBlock writes.tagBlock writes.storeWord writes.storeTag wordBinding tagBinding

private theorem declaration_return_exec (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (d : RegisterDeclaration) (m supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (writes : DeclarationStores d m supplied value) :
    steps world 9 (.Returnstate (.Vlong value) (d.continuation m le k) supplied) =
      some (CC.E0, .State producer d.rest k (allocation m).1 (d.temps le value) writes.after) ∧
    InternalPath world 9 (.Returnstate (.Vlong value) (d.continuation m le k) supplied) := by
  have gpr : GprLayout world := by
    unfold GprLayout
    rw [layout]
    exact x0_layout
  exact declaration_return_body world producer (allocation m).1 gpr d m supplied le k value writes
    writes.wordBinding writes.tagBinding

/-- An actual initializer follows each stated provider outcome through the
real writeback. Preservation is relative to provider post-memory. -/
theorem register_input_returns_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 30) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
    let d := registerDeclaration j
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      CC.Star (CC.Step2 world) (.State producer (registerDeclarationStage j) k (allocation m).1 le before)
        trace (.State producer d.rest k (allocation m).1 (d.temps le value) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong value) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ d.word → id ≠ d.tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  dsimp only
  let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
  let d := registerDeclaration j
  obtain ⟨writes⟩ := declaration_stores j m supplied value access
  have suffix := declaration_return_exec world layout d m supplied le k value writes
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (d.continuation m le k) before)
      trace (.Returnstate (.Vlong value) (d.continuation m le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨writes.wordBlock, writes.tagBlock, writes.after, writes.wordBinding, writes.tagBinding,
    ?_, writes.wordRead, writes.tagRead, writes.otherLocals, writes.frame, writes.access, writes.next⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (register_input_ready_bound world binding i m before le k).sound
      (star_trans call (internalRun_of_steps suffix.2 suffix.1).sound)

/-- The zero branch uses the same store witness and named GPR layout. -/
theorem declaration_zero_body_stored (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (before middle after : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (same : CC.Integers.Int.eq d.index (30#32) = true)
    (wordBlock tagBlock : CC.Block)
    (storedWord : CC.Mem.storev .Mint64 before (.Vptr wordBlock (0#64)) (.Vlong (0#64)) = some middle)
    (storedTag : CC.Mem.storev .Mint8unsigned middle (.Vptr tagBlock (0#64)) (.Vint (0#32)) = some after)
    (wordBinding : e.get d.word = some (wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (tagBlock, CC.tuchar)) :
    steps world 10 (.State f d.body k e le before) =
      some (CC.E0, .State f d.rest k e
        (le.set d.resultTemp (.Vlong (0#64))) after) ∧
    InternalPath world 10 (.State f d.body k e le before) := by
  have indexSame : d.index = (30#32) := by
    simpa only [CC.Integers.Int.eq, CC.Integers.MI.eq, beq_iff_eq] using same
  simp +decide [steps, InternalPath, InternalState, RegisterDeclaration.body,
    RegisterDeclaration.storeValue, RegisterDeclaration.storeTag,
    CC.doStep, CC.typeconv, CC.removeAttributes, CC.tattr, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.doAssignLoc,
    CC.lvalOfField, CC.typeof, CC.accessMode, CC.PTree.gss, gpr.1, gpr.2,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue,
    CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, indexSame,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add,
    CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.E0, CC.Eapp,
    wordBinding, tagBinding, storedWord, storedTag]

/-- Preserve the original literal-zero API by the same single execution proof. -/
theorem declaration_zero_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (m before : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (same : CC.Integers.Int.eq d.index (30#32) = true)
    (writes : DeclarationStores d m before (0#64))
    (wordBinding : e.get d.word = some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (writes.tagBlock, CC.tuchar)) :
    steps world 10 (.State f d.body k e le before) =
      some (CC.E0, .State f d.rest k e
        (le.set d.resultTemp (.Vlong (0#64))) writes.after) ∧
    InternalPath world 10 (.State f d.body k e le before) := by
  exact declaration_zero_body_stored world f e gpr d before writes.middle writes.after le k same
    writes.wordBlock writes.tagBlock writes.storeWord writes.storeTag wordBinding tagBinding

private theorem declaration_zero_exec (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (d : RegisterDeclaration) (m before : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (same : CC.Integers.Int.eq d.index (30#32) = true)
    (writes : DeclarationStores d m before (0#64)) :
    steps world 10 (.State producer d.body k (allocation m).1 le before) =
      some (CC.E0, .State producer d.rest k (allocation m).1
        (le.set d.resultTemp (.Vlong (0#64))) writes.after) ∧
    InternalPath world 10 (.State producer d.body k (allocation m).1 le before) := by
  have gpr : GprLayout world := by
    unfold GprLayout
    rw [layout]
    exact x0_layout
  exact declaration_zero_body world producer (allocation m).1 gpr d m before le k same writes
    writes.wordBinding writes.tagBinding

/-- x30's declaration uses no provider call and writes its actual zero word
and scalar tag. Its later return-tag binding is a separate producer stage. -/
theorem register30_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    let d := registerDeclaration 30
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      InternalRun world 10 (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        (.State producer d.rest k (allocation m).1 (le.set d.resultTemp (.Vlong (0#64))) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong 0) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ d.word → id ≠ d.tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  dsimp only
  obtain ⟨writes⟩ := declaration_stores 30 m before (0#64) access
  have exec := declaration_zero_exec world layout (registerDeclaration 30) m before le k
    (by decide +kernel) writes
  refine ⟨writes.wordBlock, writes.tagBlock, writes.after, writes.wordBinding, writes.tagBinding,
    ?_, writes.wordRead, writes.tagRead, writes.otherLocals, writes.frame, writes.access, writes.next⟩
  rw [(register_declarations_source 30).1]
  exact internalRun_of_steps exec.2 exec.1

theorem register_input_ready (i : Fin 30) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
    InternalRun ge 5 (.State producer (registerDeclarationStage j) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        ((registerDeclaration j).continuation m le k) memory) :=
  register_input_ready_bound ge producer_input_binding i m memory le k

theorem register_input_returns (i : Fin 30) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    let j : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩
    let d := registerDeclaration j
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      CC.Star (CC.Step2 ge) (.State producer (registerDeclarationStage j) k (allocation m).1 le before)
        trace (.State producer d.rest k (allocation m).1 (d.temps le value) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong value) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ d.word → id ≠ d.tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock :=
  register_input_returns_bound ge rfl producer_input_binding i m before supplied le k value trace provider access

theorem register30_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    let d := registerDeclaration 30
    ∃ xb tb after,
      (allocation m).1.get d.word = some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tb, CC.tuchar) ∧
      InternalRun ge 10 (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        (.State producer d.rest k (allocation m).1 (le.set d.resultTemp (.Vlong (0#64))) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong 0) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ d.word → id ≠ d.tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  register30_initialized_bound ge rfl m before le k access

/-- The shared declaration continuation is the one reached by the already
proved complete producer prefix. Both caches remain cold at that boundary. -/
theorem producer_register_input_ready (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun ge 594 (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
          ((registerDeclaration 0).continuation m (initialTemps ctx continuation) k) before) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 before (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned before (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock m before ∧ before.access = (allocation m).2.access ∧
      before.nextblock = (allocation m).2.nextblock := by
  exact first_input_ready m ctx continuation k

end KProgFormal.ClightRefinement.Arm64Producer
