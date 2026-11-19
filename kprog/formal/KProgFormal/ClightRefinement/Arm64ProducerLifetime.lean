import KProgFormal.ClightRefinement.Arm64ProducerVectorLoop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def consumerType : CC.Ty := .Tfunction [CC.tptr headerType] CC.tuint CC.cc_default
def consumerAddress : CC.Expr := .Etempvar Arm64Entry._continuation (CC.tptr consumerType)
def consumerArgument : CC.Expr := .Eaddrof (.Evar Arm64Entry._entry headerType) (CC.tptr headerType)
def consumerCall : CC.Stmt := .Scall (some Arm64Entry._t'131) consumerAddress [consumerArgument]
def consumerReturn : CC.Stmt := .Sreturn (some (.Etempvar Arm64Entry._t'131 CC.tuint))
def consumerContinuation (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Entry._t'131) producer (allocation m).1 le (.Kseq consumerReturn k)

theorem consumer_source : afterVectorLoop = .Ssequence consumerCall consumerReturn := rfl

theorem consumer_argument_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) :
    CC.doEvalExpr world (allocation m).1 le before consumerArgument = some (.Vptr entry.block 0) := by
  simp only [consumerArgument, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, entry.binding]
  rfl

theorem consumer_argument (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) :
    CC.doEvalExpr ge (allocation m).1 le before consumerArgument = some (.Vptr entry.block 0) :=
  consumer_argument_bound ge m before le entry

theorem consumer_arguments_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) :
    CC.doEvalExprlist world (allocation m).1 le before [consumerArgument] [CC.tptr headerType] =
      some [.Vptr entry.block 0] := by
  simp only [CC.doEvalExprlist, consumer_argument_bound world m before le entry]
  rfl

theorem consumer_arguments (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) :
    CC.doEvalExprlist ge (allocation m).1 le before [consumerArgument] [CC.tptr headerType] =
      some [.Vptr entry.block 0] :=
  consumer_arguments_bound ge m before le entry

/-- The source sequence reaches its actual indirect call without touching memory. -/
theorem consumer_ready_bound (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 1 (.State producer afterVectorLoop k (allocation m).1 le before)
      (.State producer consumerCall (.Kseq consumerReturn k) (allocation m).1 le before) := by
  rw [consumer_source]
  exact .step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)

theorem consumer_ready (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 1 (.State producer afterVectorLoop k (allocation m).1 le before)
      (.State producer consumerCall (.Kseq consumerReturn k) (allocation m).1 le before) :=
  consumer_ready_bound ge m before le k

/-- Callee lookup and its exact C signature are explicit.  This is a call
boundary theorem, not a choice or execution proof of a linked native body. -/
theorem consumer_call_with_binding_bound (world : CC.CGenv) (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (target : CC.Val) (callee : CC.FunDef)
    (continuation : le.get Arm64Entry._continuation = some target)
    (binding : CC.Genv.findFunct world.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    InternalRun world 2 (.State producer afterVectorLoop k (allocation m).1 le before)
      (.Callstate callee [.Vptr entry.block 0] (consumerContinuation m le k) before) := by
  have callStep : CC.doStep world
      (.State producer consumerCall (.Kseq consumerReturn k) (allocation m).1 le before) =
      some (CC.E0, .Callstate callee [.Vptr entry.block 0] (consumerContinuation m le k) before) := by
    have classified : CC.Cop.classifyFun (CC.typeof consumerAddress) =
        .f [CC.tptr headerType] CC.tuint CC.cc_default := rfl
    have targetEval : CC.doEvalExpr world (allocation m).1 le before consumerAddress = some target := continuation
    have typeEq : CC.typeOfFundef callee =
        .Tfunction [CC.tptr headerType] CC.tuint CC.cc_default := signature
    simp only [consumerCall, CC.doStep, classified, targetEval,
      consumer_arguments_bound world m before le entry, binding, typeEq, ite_true]
    rfl
  exact (consumer_ready_bound world m before le k).trans
    (.step trivial (CC.doStep_sound world _ _ _ callStep) (.refl _))

theorem consumer_call_with_binding (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (target : CC.Val) (callee : CC.FunDef)
    (continuation : le.get Arm64Entry._continuation = some target)
    (binding : CC.Genv.findFunct ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    InternalRun ge 2 (.State producer afterVectorLoop k (allocation m).1 le before)
      (.Callstate callee [.Vptr entry.block 0] (consumerContinuation m le k) before) :=
  consumer_call_with_binding_bound ge m before entry le k target callee continuation binding signature

/-- Counter updates preserve the actual continuation temporary. -/
theorem consumer_temp_distinct : Arm64Entry._continuation ≠ Arm64Entry._i := by decide +kernel

/-- The actual allocated local ranges remain Freeable through the preceding
store-only initialization.  This derives resources, not a successful free. -/
theorem producer_locals_live_of_access (m before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∀ id value, (allocation m).1.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
  intro id value binding
  have allocated := ((allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).1 id value binding).2.2
  apply CC.Mem.rangePerm_intro
  intro ofs lower upper
  have perm := CC.Mem.rangePerm_perm (allocation m).2 value.1 0
    (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable allocated ofs lower upper
  simpa only [CC.Mem.perm, access] using perm

/-- Header construction reaches the real call boundary with both cache
contracts on the same &entry passed to the explicitly bound callee. -/
theorem header_caches_at_consumer_call (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (target : CC.Val) (callee : CC.FunDef)
    (access : before.access = (allocation m).2.access)
    (continuation : le.get Arm64Entry._continuation = some target)
    (binding : CC.Genv.findFunct ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, InternalRun ge 640
        (.State producer afterContext k (allocation m).1 le before)
        (.Callstate callee [.Vptr entry.block 0] (consumerContinuation m finalLe k) after) ∧
      finalLe.get Arm64Entry._continuation = some target ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false
        (allocation m).2.nextblock entry.block 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true
        (allocation m).2.nextblock entry.block 0 after) ∧
      (∀ id localValue, (allocation m).1.get id = some localValue →
        CC.Mem.rangePerm after localValue.1 0 (CC.sizeof ge.genv_cenv localValue.2) .Cur .Freeable = true) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, _, _, after, finalLe, run, _, temps, reads, _, _, _, frame, finalAccess, next⟩ :=
    header_initialized_before_consumer m before le k access
  have finalContinuation := (temps _ consumer_temp_distinct).trans continuation
  obtain ⟨stack, stackStorage⟩ :=
    header_cache_storage false m after entry cells (finalAccess.trans access) reads
  obtain ⟨returns, returnStorage⟩ :=
    header_cache_storage true m after entry cells (finalAccess.trans access) reads
  have stackSame : stack.entryBlock = entry.block :=
    congrArg Prod.fst (Option.some.inj (stack.entryBinding.symm.trans entry.binding))
  have returnSame : returns.entryBlock = entry.block :=
    congrArg Prod.fst (Option.some.inj (returns.entryBinding.symm.trans entry.binding))
  rw [stackSame] at stackStorage
  rw [returnSame] at returnStorage
  exact ⟨entry, after, finalLe,
    run.trans (consumer_call_with_binding m after entry finalLe k target callee
      finalContinuation binding signature), finalContinuation, stackStorage, returnStorage,
    producer_locals_live_of_access m after (finalAccess.trans access), frame, finalAccess, next⟩

/-- A returned uint32 resumes the producer, then its real return statement
frees every local range.  Contents remain as inaccessible bytes, not a live
borrowed entry.  The continuation's execution and access preservation are not
inferred from this return-boundary theorem. -/
theorem consumer_return_releases_locals_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (value : BitVec 32)
    (owned : ∀ id localValue, (allocation m).1.get id = some localValue →
      CC.Mem.rangePerm before localValue.1 0 (CC.sizeof world.genv_cenv localValue.2) .Cur .Freeable = true) :
    ∃ after, InternalRun world 3
        (.Returnstate (.Vint value) (consumerContinuation m le k) before)
        (.Returnstate (.Vint value) (CC.callCont k) after) ∧
      FrameBelow m.nextblock before after ∧ after.contents = before.contents ∧
      after.nextblock = before.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (allocation m).1, ∀ ofs,
        row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  have ownedOld : ∀ id localValue, (allocation m).1.get id = some localValue →
      CC.Mem.rangePerm before localValue.1 0 (CC.sizeof ge.genv_cenv localValue.2) .Cur .Freeable = true := by
    simpa only [layout] using owned
  obtain ⟨after, freed, frame, contents, next, released⟩ := deallocate_live_locals
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) ownedOld
  have freedWorld : CC.Mem.freeList before (CC.blocksOfEnv world.genv_cenv (allocation m).1) = some after := by
    simpa only [layout] using freed
  have returnStep : CC.doStep world
      (.State producer consumerReturn k (allocation m).1
        (le.set Arm64Entry._t'131 (.Vint value)) before) =
      some (CC.E0, .Returnstate (.Vint value) (CC.callCont k) after) := by
    have cast : CC.Cop.semCast (.Vint value) CC.tuint producer.fn_return before =
        some (.Vint value) := rfl
    simp only [consumerReturn, CC.doStep, CC.doEvalExpr, CC.PTree.gss, CC.typeof, cast, freedWorld]
  refine ⟨after, ?_, frame, contents, next, ?_⟩
  · exact .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ rfl)
        (.step trivial (CC.doStep_sound world _ _ _ returnStep) (.refl _)))
  · simpa only [layout] using released

theorem consumer_return_releases_locals (m before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (value : BitVec 32)
    (owned : ∀ id localValue, (allocation m).1.get id = some localValue →
      CC.Mem.rangePerm before localValue.1 0 (CC.sizeof ge.genv_cenv localValue.2) .Cur .Freeable = true) :
    ∃ after, InternalRun ge 3
        (.Returnstate (.Vint value) (consumerContinuation m le k) before)
        (.Returnstate (.Vint value) (CC.callCont k) after) ∧
      FrameBelow m.nextblock before after ∧ after.contents = before.contents ∧
      after.nextblock = before.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (allocation m).1, ∀ ofs,
        row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) :=
  consumer_return_releases_locals_bound ge rfl m before le k value owned

end KProgFormal.ClightRefinement.Arm64Producer
