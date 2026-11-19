import KProgFormal.ClightRefinement.Arm64ProducerPrefix
import KProgFormal.ClightRefinement.Arm64OriginCache

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

/-- Actual producer-native input declaration in the linked program. -/
theorem producer_input_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input =
      some (CC.Positive.ofNat 64) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 64) =
      some Arm64OriginCache.inputFunction := Binding.linked_input

private structure InputParts where
  registerStage : CC.Stmt
  setValue : CC.Stmt
  storeValue : CC.Stmt
  tags : CC.Stmt
  tagStore : CC.Stmt
  nextRegister : CC.Stmt

private def unpackInput : Option InputParts :=
  match afterCacheStage with
  | .Ssequence _ (.Ssequence _ (.Ssequence _
      (stage@(.Ssequence (.Ssequence (.Sifthenelse _ _ (.Ssequence _ setValue)) storeValue)
        (tags@(.Ssequence tagStore nextRegister)))))) =>
    some ⟨stage, setValue, storeValue, tags, tagStore, nextRegister⟩
  | _ => none

private def inputParts : InputParts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(unpackInput.get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `first_register_parts value

/-- Actual producer stage after the x0 declaration initializer and tag write. -/
def nextRegisterStage : CC.Stmt := inputParts.nextRegister

def inputContinuation (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Entry._t'2) producer (allocation m).1 le
    (.Kseq inputParts.setValue (.Kseq inputParts.storeValue (.Kseq inputParts.tags k)))

def setupNames : List CC.Ident :=
  [Arm64Entry.___a64_sim_is_xdp, Arm64Entry.___a64_sim_helper_ctx,
   Arm64Entry.___a64_sim_helper_abi_base]

theorem scalar_local (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty) (chunk : CC.Chunk)
    (present : (id, ty) ∈ producer.fn_vars)
    (size : CC.sizeof ge.genv_cenv ty = CC.sizeChunk chunk)
    (align : (0 : Int) % CC.alignChunk chunk = 0) :
    ∃ block, (allocation m).1.get id = some (block, ty) ∧
      m.nextblock.toNat ≤ block.toNat ∧
      CC.Mem.validAccess (allocation m).2 chunk block 0 .Writable = true := by
  obtain ⟨block, bound, fresh, _, range⟩ := local_storage m id ty present
  have writable := CC.Mem.rangePerm_implies range (by decide : CC.permOrder .Freeable .Writable = true)
  refine ⟨block, bound, fresh, ?_⟩
  simpa only [CC.Mem.validAccess, size, Int.zero_add, align, beq_self_eq_true,
    Bool.and_true] using writable

theorem create_store (m memory : CC.Mem) (chunk : CC.Chunk) (block : CC.Block)
    (value : CC.Val) (access : memory.access = (allocation m).2.access)
    (writable : CC.Mem.validAccess (allocation m).2 chunk block 0 .Writable = true) :
    ∃ after, CC.Mem.store chunk memory block 0 value = some after ∧
      after.access = (allocation m).2.access := by
  have actual := (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation m).2)
    (chunk := chunk) (b := block) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm, access])).trans writable
  have stored : ∃ after, CC.Mem.store chunk memory block 0 value = some after := by
    unfold CC.Mem.store
    rw [actual]
    exact ⟨_, rfl⟩
  obtain ⟨after, store⟩ := stored
  exact ⟨after, store, (CC.Mem.store_access store).trans access⟩

/-- The three exported setup stores and their real source successor. -/
def setupAssignments : List CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterCacheStage)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:3] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer setup no longer has three assignments"
      rows := rows.push body.getAppArgs[0]!
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `setup_assignments
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList)

def registerStage : CC.Stmt := inputParts.registerStage

theorem setup_source : afterCacheStage =
    setupAssignments.foldr CC.Stmt.Ssequence registerStage := by rfl

private theorem setup_exec (world : CC.CGenv) (f : CC.Function) (rest : CC.Stmt) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (fb cb ab : CC.Block) (before m1 m2 after : CC.Mem)
    (flag : e.get Arm64Entry.___a64_sim_is_xdp = some (fb, CC.tuchar))
    (ctx : e.get Arm64Entry.___a64_sim_helper_ctx = some (cb, CC.tptr CC.tvoid))
    (abi : e.get Arm64Entry.___a64_sim_helper_abi_base = some (ab, CC.tptr CC.tvoid))
    (s0 : CC.Mem.store .Mint8unsigned before fb 0 (.Vint (0#32)) = some m1)
    (s1 : CC.Mem.store CC.Mptr m1 cb 0 (.Vlong (0#64)) = some m2)
    (s2 : CC.Mem.store CC.Mptr m2 ab 0 (.Vlong (0#64)) = some after) :
    steps world 9 (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
    InternalPath world 9 (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before) := by
  change CC.Mem.storev .Mint8unsigned before (.Vptr fb (0#64)) (.Vint (0#32)) = some m1 at s0
  change CC.Mem.storev CC.Mptr m1 (.Vptr cb (0#64)) (.Vlong (0#64)) = some m2 at s1
  change CC.Mem.storev CC.Mptr m2 (.Vptr ab (0#64)) (.Vlong (0#64)) = some after at s2
  simp +decide [steps, InternalPath, InternalState, setupAssignments, List.foldr,
    CC.doStep, CC.doEvalLvalue, CC.lvalOfVar, CC.doEvalExpr, CC.typeof,
    CC.doAssignLoc, CC.accessMode, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.castIntLong, CC.Integers.Int.signed, CC.Integers.MI.signed,
    CC.Integers.Int64.repr, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
    CC.Archi.ptr64, CC.tptr, CC.tvoid, CC.tint, CC.tuchar,
    CC.E0, CC.Eapp, flag, ctx, abi, s0, s1, s2]

/-- Actual post-cache setup; all other declared local loads are preserved. -/
theorem setup_register_input_body (world : CC.CGenv) (f : CC.Function)
    (e : CC.Env) (rest : CC.Stmt) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (bound : ∀ id ∈ setupNames, e.get id = (allocation m).1.get id)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 9
        (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before)
        (.State f rest k e le after) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ∉ setupNames →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨fb, flag, flagFresh, flagWritable⟩ := scalar_local m Arm64Entry.___a64_sim_is_xdp
    CC.tuchar .Mint8unsigned (by decide +kernel) rfl (by decide)
  obtain ⟨cb, ctx, ctxFresh, ctxWritable⟩ := scalar_local m Arm64Entry.___a64_sim_helper_ctx
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  obtain ⟨ab, abi, abiFresh, abiWritable⟩ := scalar_local m Arm64Entry.___a64_sim_helper_abi_base
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  obtain ⟨m1, s0, a1⟩ := create_store m before .Mint8unsigned fb (.Vint (0#32)) access flagWritable
  obtain ⟨m2, s1, a2⟩ := create_store m m1 CC.Mptr cb (.Vlong (0#64)) a1 ctxWritable
  obtain ⟨after, s2, a3⟩ := create_store m m2 CC.Mptr ab (.Vlong (0#64)) a2 abiWritable
  have exec := setup_exec world f rest e le k fb cb ab before m1 m2 after
    ((bound _ (by decide +kernel)).trans flag)
    ((bound _ (by decide +kernel)).trans ctx)
    ((bound _ (by decide +kernel)).trans abi) s0 s1 s2
  refine ⟨after, internalRun_of_steps exec.2 exec.1, ?_, ?_, a3.trans access.symm, ?_⟩
  · intro id ty block bound other chunk ofs
    have separate := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    have nf : id ≠ Arm64Entry.___a64_sim_is_xdp := by intro h; apply other; simp [setupNames, h]
    have nc : id ≠ Arm64Entry.___a64_sim_helper_ctx := by intro h; apply other; simp [setupNames, h]
    have na : id ≠ Arm64Entry.___a64_sim_helper_abi_base := by intro h; apply other; simp [setupNames, h]
    exact (CC.Mem.load_store_other s2 chunk block ofs (.inl (separate _ _ _ _ bound abi na))).trans
      ((CC.Mem.load_store_other s1 chunk block ofs (.inl (separate _ _ _ _ bound ctx nc))).trans
        (CC.Mem.load_store_other s0 chunk block ofs (.inl (separate _ _ _ _ bound flag nf))))
  · exact ((FrameBelow.store flagFresh s0).trans (FrameBelow.store ctxFresh s1)).trans
      (FrameBelow.store abiFresh s2)
  · exact (CC.Mem.store_nextblock s2).trans ((CC.Mem.store_nextblock s1).trans (CC.Mem.store_nextblock s0))

/-- Source specialization keeps the original setup interface. -/
theorem setup_register_input_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 9
        (.State producer afterCacheStage k (allocation m).1 le before)
        (.State producer inputParts.registerStage k (allocation m).1 le after) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ∉ setupNames →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  rw [setup_source]
  exact setup_register_input_body world producer (allocation m).1 registerStage m before le k
    (fun _ _ => rfl) access

theorem setup_register_input (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun ge 9
        (.State producer afterCacheStage k (allocation m).1 le before)
        (.State producer inputParts.registerStage k (allocation m).1 le after) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ∉ setupNames →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  setup_register_input_bound ge m before le k access

theorem first_call_exec_bound (world : CC.CGenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction)
    (m : CC.Mem) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    steps world 5 (.State producer inputParts.registerStage k (allocation m).1 le memory) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (inputContinuation m le k) memory) ∧
    InternalPath world 5 (.State producer inputParts.registerStage k (allocation m).1 le memory) := by
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  simp +decide [steps, InternalPath, InternalState, inputParts, inputContinuation,
    CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.typeof, unshadowed,
    CC.typeconv, CC.removeAttributes, CC.tattr,
    binding.1, binding.2, CC.Genv.findFunct,
    CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.eq, CC.typeOfFundef,
    Arm64OriginCache.inputFunction, Arm64OriginCache.inputEF, CC.Cop.classifyFun,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
    CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.tuint, CC.tint, CC.tulong, CC.E0, CC.Eapp]

/-- The actual producer reaches the first kind-6 input boundary, with both
caches still cold and caller memory framed. No provider outcome is invented. -/
theorem first_input_ready (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun ge 594 (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
          (inputContinuation m (initialTemps ctx continuation) k) before) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 before (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned before (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock m before ∧ before.access = (allocation m).2.access ∧
      before.nextblock = (allocation m).2.nextblock := by
  obtain ⟨initialized, prefixRun, caches, frame, access, next⟩ := entry_caches_initialized m ctx continuation k
  obtain ⟨before, setupRun, otherLocals, setupFrame, setupAccess, setupNext⟩ :=
    setup_register_input m initialized (initialTemps ctx continuation) k access
  have call := first_call_exec_bound ge producer_input_binding m before (initialTemps ctx continuation) k
  refine ⟨before, prefixRun.trans (setupRun.trans (internalRun_of_steps call.2 call.1)), ?_,
    frame.trans setupFrame, setupAccess.trans access, setupNext.trans next⟩
  intro returns
  obtain ⟨locals, base, valid⟩ := caches returns
  refine ⟨locals, ?_, ?_⟩
  · have preserved := otherLocals _ _ _ locals.baseBinding (by cases returns <;> decide +kernel) .Mint64 0
    exact preserved.trans base
  · have preserved := otherLocals _ _ _ locals.validBinding (by cases returns <;> decide +kernel) .Mint8unsigned 0
    exact preserved.trans valid

def firstInputTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Entry._t'2 (.Vlong value)).set Arm64Entry._t'1 (.Vlong value)

def gprComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry._arm64_sim_gpr).get (by decide +kernel)
theorem x0_layout :
    ge.genv_cenv.get Arm64Entry._arm64_sim_gpr = some gprComposite ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Entry._x gprComposite.co_members = .OK (0, .Full) := by
  decide +kernel

private theorem first_return_exec (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (xb tb : CC.Block) (supplied middle after : CC.Mem) (value : BitVec 64)
    (cell : (allocation m).1.get Arm64Entry.___a64_x0 =
      some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tag : (allocation m).1.get Arm64Entry.___a64_x0_tag = some (tb, CC.tuchar))
    (storeCell : CC.Mem.storev .Mint64 supplied (.Vptr xb (0#64)) (.Vlong value) = some middle)
    (storeTag : CC.Mem.storev .Mint8unsigned middle (.Vptr tb (0#64)) (.Vint (0#32)) = some after) :
    steps world 9 (.Returnstate (.Vlong value) (inputContinuation m le k) supplied) =
      some (CC.E0, .State producer nextRegisterStage k (allocation m).1
        (firstInputTemps le value) after) ∧
    InternalPath world 9 (.Returnstate (.Vlong value) (inputContinuation m le k) supplied) := by
  rcases world with ⟨functions, composites⟩
  change composites = ge.genv_cenv at layout
  subst composites
  simp +decide [steps, InternalPath, InternalState, inputContinuation, inputParts, nextRegisterStage, firstInputTemps,
    CC.doStep, CC.setOpttemp, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
    CC.doDerefLoc, CC.doAssignLoc, CC.lvalOfField, CC.typeof, CC.accessMode,
    x0_layout.1, x0_layout.2, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr,
    CC.Integers.MI.zero, CC.Integers.MI.add, CC.tuchar, CC.tuint, CC.tulong, CC.E0, CC.Eapp,
    cell, tag, storeCell, storeTag]

/-- Every stated scalar outcome of the actual first register-input call is
stored through the real x0 union field and scalar tag. The provider's trace
and complete post-memory are retained except for those two constructed stores.
Writable local permissions after the provider remain an explicit ABI premise. -/
theorem first_input_returns_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ xb tb after,
      (allocation m).1.get Arm64Entry.___a64_x0 =
        some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get Arm64Entry.___a64_x0_tag = some (tb, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (inputContinuation m le k) before)
        trace (.State producer nextRegisterStage k (allocation m).1 (firstInputTemps le value) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong value) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_x0 → id ≠ Arm64Entry.___a64_x0_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  obtain ⟨xb, cell, cellFresh, cellWritable⟩ := scalar_local m Arm64Entry.___a64_x0
    (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr) .Mint64 (by decide +kernel)
    (by decide +kernel) (by decide)
  obtain ⟨tb, tag, tagFresh, tagWritable⟩ := scalar_local m Arm64Entry.___a64_x0_tag
    CC.tuchar .Mint8unsigned (by decide +kernel) rfl (by decide)
  obtain ⟨middle, storeCell, middleAccess⟩ := create_store m supplied .Mint64 xb (.Vlong value) access cellWritable
  obtain ⟨after, storeTag, afterAccess⟩ := create_store m middle .Mint8unsigned tb (.Vint (0#32)) middleAccess tagWritable
  have locals := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
  have distinct : xb ≠ tb := locals _ _ _ _ cell tag (by decide +kernel)
  have suffix := first_return_exec world layout m le k xb tb supplied middle after value cell tag storeCell storeTag
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (inputContinuation m le k) before)
      trace (.Returnstate (.Vlong value) (inputContinuation m le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨xb, tb, after, cell, tag, ?_, ?_, ?_, ?_,
    (FrameBelow.store cellFresh storeCell).trans (FrameBelow.store tagFresh storeTag),
    afterAccess.trans access.symm, (CC.Mem.store_nextblock storeTag).trans (CC.Mem.store_nextblock storeCell)⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using
      star_trans call (internalRun_of_steps suffix.2 suffix.1).sound
  · exact (CC.Mem.load_store_other storeTag .Mint64 xb 0 (.inl distinct)).trans
      (CC.Mem.load_store_same storeCell)
  · simpa [CC.Mem.loadv, CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using CC.Mem.load_store_same storeTag
  · intro id ty block bound notCell notTag chunk ofs
    exact (CC.Mem.load_store_other storeTag chunk block ofs (.inl (locals _ _ _ _ bound tag notTag))).trans
      (CC.Mem.load_store_other storeCell chunk block ofs (.inl (locals _ _ _ _ bound cell notCell)))

/-- Preserve the standalone API as a projection of the actual-world law. -/
theorem first_input_returns (m before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ xb tb after,
      (allocation m).1.get Arm64Entry.___a64_x0 =
        some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get Arm64Entry.___a64_x0_tag = some (tb, CC.tuchar) ∧
      CC.Star (CC.Step2 ge)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (inputContinuation m le k) before)
        trace (.State producer nextRegisterStage k (allocation m).1 (firstInputTemps le value) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong value) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_x0 → id ≠ Arm64Entry.___a64_x0_tag →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock :=
  first_input_returns_bound ge rfl m before supplied le k value trace provider access

end KProgFormal.ClightRefinement.Arm64Producer
