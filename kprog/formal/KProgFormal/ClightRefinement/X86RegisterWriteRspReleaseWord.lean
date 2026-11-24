import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseSelect

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseWord

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_word_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def stackDefinition : CC.CompositeDef := by
  run_tac do
    let mut rest ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.composites)) none
    repeat
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless node.isAppOfArity ``List.cons 3 do throwError "expected original stack composite"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``CC.CompositeDef.Composite 4 do throwError "expected composite constructor"
      if row.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_stack_mem then
        Lean.Elab.Tactic.closeMainGoal `original_x86_release_stack row
        break
      rest := node.getAppArgs[2]!

private def members : List CC.Member := by
  run_tac cachePart (← `(match stackDefinition with | .Composite _ _ rows _ => rows))

def stackRecord : CC.Composite :=
  {co_su := .Union, co_members := members, co_attr := CC.noattr,
   co_sizeof := 48, co_alignof := 8, co_rank := 1}

/-- The actual exported stack union is built by the imported C layout function. -/
theorem layout_source :
    (match stackDefinition with
      | .Composite name kind rows attr => CC.compositeOfDef CC.PTree.empty name kind rows attr) =
      .OK stackRecord := by rfl

private def bindingMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

private theorem stack_offset (ce : CC.CompositeEnv) :
    CC.fieldOffset ce X86_program_profile_bpf._stack X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (8, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._stack bindingMembers = _
  simp +decide [bindingMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]

private theorem word_offset (ce : CC.CompositeEnv) :
    CC.unionFieldOffset ce X86_program_profile_bpf._q stackRecord.co_members = .OK (0, .Full) := by
  simp +decide [stackRecord, members, CC.unionFieldOffset, CC.layoutField,
    CC.bitalignof, CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tarray, CC.tulong, CC.noattr]

def inputEF : CC.ExtFun := .EF_external "native_lab_entry_input"
  (CC.mksignature [.Xint] .Xlong CC.cc_default)
def inputFunction : CC.FunDef := .External inputEF [CC.tuint] CC.tulong CC.cc_default

private def afterProvider : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110 with
    | .Ssequence _ rest => rest | _ => .Sskip))

def continuation (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'113) function e le (.Kseq afterProvider k)

def temps (le : CC.TempEnv) (value : BitVec 64) (stack : CC.Block) (base : CC.Integers.Ptrofs) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'113 (.Vlong value)).set X86_program_profile_bpf._t'142 (.Vptr stack base)

def address (base : CC.Integers.Ptrofs) (slot : Fin 6) : CC.Integers.Ptrofs :=
  base + CC.Integers.Ptrofs.repr (8 * (slot.val : Int))

/-- The original selected word arm reaches the real kind-6 external call. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (input : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none) :
    InternalRun ge 2 (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110 k e le memory)
      (.Callstate inputFunction [.Vint (6#32)] (continuation function e le k) memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110,
    afterProvider, continuation, inputFunction, inputEF, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
    CC.doEvalLvalue, CC.lvalOfVar, CC.typeof, CC.doDerefLoc, CC.accessMode,
    CC.Genv.findFunct, symbol, global, notLocal, CC.Cop.classifyFun,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.tuint, CC.tint, CC.tulong, CC.E0, CC.Eapp]

private theorem displacement : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.mul (8#64) (CC.Cop.ptrofsOfInt .Unsigned
      (X86RegisterWriteRspReleaseSelect.index slot / CC.Integers.Int.repr 8)) =
      CC.Integers.Ptrofs.repr (8 * (slot.val : Int)) := by decide +kernel

/-- The real return continuation stores the supplied word through the actual
stack union and source index. Store existence is constructed from permissions. -/
theorem returned (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (supplied : CC.Mem)
    (binding stack : CC.Block) (base : CC.Integers.Ptrofs) (slot : Fin 6) (value : BitVec 64)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint64 stack
      (CC.Integers.Ptrofs.unsigned (address base slot)) .Writable = true) :
    ∃ after, CC.Mem.store .Mint64 supplied stack (CC.Integers.Ptrofs.unsigned (address base slot))
      (.Vlong value) = some after ∧
    InternalRun ge 6 (.Returnstate (.Vlong value) (continuation function e le k) supplied)
      (.State function .Sskip k e (temps le value stack base) after) ∧
    CC.Mem.load .Mint64 after stack (CC.Integers.Ptrofs.unsigned (address base slot)) = some (.Vlong value) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) := by
  have existsStore : ∃ after, CC.Mem.store .Mint64 supplied stack
      (CC.Integers.Ptrofs.unsigned (address base slot)) (.Vlong value) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have field : CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._stack (.Vptr binding (0#64)) = some (binding, (8#64), .Full) := by
    simp only [CC.lvalOfField, layout.bindings, stack_offset]
    rfl
  have qfield : CC.lvalOfField ge (.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr)
      X86_program_profile_bpf._q (.Vptr stack base) = some (stack, base, .Full) := by
    simp only [CC.lvalOfField, stackLayout, word_offset]
    change some (stack, base + (0 : CC.Integers.Ptrofs), CC.Bitfield.Full) = _
    exact congrArg (fun n : CC.Integers.Ptrofs => some (stack, n, CC.Bitfield.Full)) (BitVec.add_zero base)
  have unsigned8 : CC.Integers.Ptrofs.unsigned (8#64) = 8 := rfl
  have delta := displacement slot
  change CC.Mem.store .Mint64 supplied stack
    (Int.ofNat ((@BitVec.add 64 base (BitVec.ofInt 64 (8 * (slot.val : Int)))).toNat))
    (.Vlong value) = some after at stored
  refine ⟨after, stored, ?_, (CC.Mem.load_store_same stored),
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored, ?_⟩
  · apply internalRun_of_steps
    all_goals simp +decide [steps, InternalPath, InternalState, continuation, afterProvider, temps,
      CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof,
      CC.setOpttemp, CC.PTree.gss, CC.PTree.gso, bindingRead, indexRead, field, qfield,
      CC.accessMode, CC.Mem.loadv, CC.Mem.storev, header, stored, unsigned8,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.semBinaryOperation, CC.Cop.semDiv, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof,
      delta, address, CC.tuint, CC.tint, CC.tulong, CC.tptr, CC.tarray, CC.Archi.ptr64_eq,
      CC.Integers.Int.divu, CC.Integers.MI.divu, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr,
      CC.Integers.MI.zero, CC.Integers.MI.add, CC.Integers.MI.repr,
      CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned, CC.Archi.ptrWordsize, CC.E0, CC.Eapp]
    all_goals rw (transparency := .all) [stored]
    all_goals trivial
  · intro chunk other offset different
    exact CC.Mem.load_store_other stored chunk other offset (.inl different)

/-- The genuine word arm, actual provider outcome and constructed source store
compose without replacing the provider by a deterministic or memory-free model.
Every external trace and supplied memory are retained. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint64 stack
      (CC.Integers.Ptrofs.unsigned (address base slot)) .Writable = true) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_110 k e le before)
      trace (.State function .Sskip k e (temps le value stack base) after) ∧
    CC.Mem.store .Mint64 supplied stack (CC.Integers.Ptrofs.unsigned (address base slot))
      (.Vlong value) = some after ∧
    CC.Mem.load .Mint64 after stack (CC.Integers.Ptrofs.unsigned (address base slot)) = some (.Vlong value) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) := by
  have entered := enter ge function e le k before input symbol global notLocal
  obtain ⟨after, stored, suffix, readback, access, next, frame⟩ :=
    returned ge layout stackLayout function e le k supplied binding stack base slot value
      bindingRead indexRead header writable
  have call : CC.Star (CC.Step2 ge)
      (.Callstate inputFunction [.Vint (6#32)] (continuation function e le k) before)
      trace (.Returnstate (.Vlong value) (continuation function e le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨after, ?_, stored, readback, access, next, frame⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) suffix.sound

/-- Original comparisons select the actual word arm, then the same real
provider/store execution runs. All six slots retain their source guards;
no after-run read or store is assumed. -/
theorem selected (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (old next value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (offsetRead : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (whole : X86RegisterWriteRspReleaseSelect.whole slot old next = true)
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint64 stack
      (CC.Integers.Ptrofs.unsigned (address base slot)) .Writable = true) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseLoop.iteration k e le before)
      trace (.State function .Sskip k e
        (temps (X86RegisterWriteRspReleaseSelect.temps le slot old next) value stack base) after) ∧
    CC.Mem.store .Mint64 supplied stack (CC.Integers.Ptrofs.unsigned (address base slot))
      (.Vlong value) = some after ∧
    CC.Mem.load .Mint64 after stack (CC.Integers.Ptrofs.unsigned (address base slot)) = some (.Vlong value) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) := by
  let ready := X86RegisterWriteRspReleaseSelect.temps le slot old next
  have entered := X86RegisterWriteRspReleaseSelect.choose ge function e le k before slot old next
    indexRead offsetRead oldRead nextRead
  simp only [X86RegisterWriteRspReleaseSelect.arm, whole, ite_true] at entered
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simp +decide [ready, X86RegisterWriteRspReleaseSelect.temps, CC.PTree.gso, bindingRead]
  have indexReady : ready.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)) := by
    simp +decide [ready, X86RegisterWriteRspReleaseSelect.temps, CC.PTree.gso, indexRead]
  obtain ⟨after, suffix, stored, readback, access, frontier, frame⟩ :=
    execute ge layout stackLayout function e ready k before supplied binding stack input base slot value trace
      symbol global notLocal bindingReady indexReady provider header writable
  refine ⟨after, ?_, stored, readback, access, frontier, frame⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans entered.sound suffix

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseWord
