import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteLoop

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteCall
open X86RegisterWriteRspReleaseWord (inputEF inputFunction stackRecord)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_byte_call_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def afterProvider : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterWriteRspReleaseByteLoop.providerArm with
    | .Ssequence _ rest => rest | _ => .Sskip))

private def bindingMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))
private def stackMembers : List CC.Member := by
  run_tac cachePart (← `(stackRecord.co_members))

private theorem stack_offset (ce : CC.CompositeEnv) :
    CC.fieldOffset ce X86_program_profile_bpf._stack X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (8, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._stack bindingMembers = _
  simp +decide [bindingMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]

private theorem byte_offset (ce : CC.CompositeEnv) :
    CC.unionFieldOffset ce X86_program_profile_bpf._b stackRecord.co_members = .OK (0, .Full) := by
  change CC.unionFieldOffset ce X86_program_profile_bpf._b stackMembers = _
  simp +decide [stackMembers, CC.unionFieldOffset, CC.layoutField,
    CC.bitalignof, CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tarray, CC.tuchar, CC.noattr]

private theorem separated (left right : _root_.Int) (different : left ≠ right) :
    left + 1 ≤ right ∨ right + 1 ≤ left := by omega

/-- The original unsigned-char cast keeps exactly the low8 bits. -/
theorem byte_cast (value : BitVec 64) :
    CC.Cop.castIntInt .I8 .Unsigned (CC.Integers.Int.repr (CC.Integers.Int64.unsigned value)) =
      (value.setWidth 8).setWidth 32 := by
  change value.setWidth 32 &&& (255#32) = (value.setWidth 8).setWidth 32
  have mask : (255#32) = (BitVec.allOnes 8).setWidth 32 := rfl
  rw [mask]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_setWidth, BitVec.getLsbD_allOnes, hi,
    decide_true, Bool.true_and, Bool.and_comm]

private theorem byte_again (value : BitVec 8) :
    CC.Cop.castIntInt .I8 .Unsigned (value.setWidth 32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (255#32) = value.setWidth 32
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

def continuation (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'114) function e le (.Kseq afterProvider k)

def temps (le : CC.TempEnv) (value : BitVec 64) (stack : CC.Block) (base : CC.Integers.Ptrofs) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'114 (.Vlong value)).set X86_program_profile_bpf._t'141 (.Vptr stack base)

def address (base : CC.Integers.Ptrofs) (slot : Fin 6) (lane : Fin 8) : CC.Integers.Ptrofs :=
  base + CC.Integers.Ptrofs.repr (8 * (slot.val : Int) + lane.val)

private theorem displacement : ∀ (slot : Fin 6) (lane : Fin 8),
    CC.Integers.Ptrofs.mul (1#64) (CC.Cop.ptrofsOfInt .Unsigned
      (X86RegisterWriteRspReleaseSelect.index slot + X86RegisterWriteRspReleaseByteLoop.laneArg lane)) =
      CC.Integers.Ptrofs.repr (8 * (slot.val : Int) + lane.val) := by decide +kernel

/-- The actual selected byte arm calls the same real kind-6 external function. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (input : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none) :
    InternalRun ge 2 (.State function X86RegisterWriteRspReleaseByteLoop.providerArm k e le memory)
      (.Callstate inputFunction [.Vint (6#32)] (continuation function e le k) memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, X86RegisterWriteRspReleaseByteLoop.providerArm,
    afterProvider, continuation, inputFunction, inputEF, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
    CC.lvalOfVar, CC.typeof, CC.doDerefLoc, CC.accessMode, CC.Genv.findFunct, symbol, global, notLocal,
    CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tuint, CC.tint, CC.tulong, CC.E0, CC.Eapp]

/-- The real return/header/cast/store path constructs one byte write from
post-provider writable rights and preserves every other block. -/
theorem returned (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (supplied : CC.Mem)
    (binding stack : CC.Block) (base : CC.Integers.Ptrofs) (slot : Fin 6) (lane : Fin 8) (value : BitVec 64)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)))
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint8unsigned stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) .Writable = true) :
    ∃ after, CC.Mem.store .Mint8unsigned supplied stack (CC.Integers.Ptrofs.unsigned (address base slot lane))
      (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
    InternalRun ge 6 (.Returnstate (.Vlong value) (continuation function e le k) supplied)
      (.State function .Sskip k e (temps le value stack base) after) ∧
    CC.Mem.load .Mint8unsigned after stack (CC.Integers.Ptrofs.unsigned (address base slot lane)) =
      some (.Vint ((value.setWidth 8).setWidth 32)) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) ∧
    (∀ offset, offset ≠ CC.Integers.Ptrofs.unsigned (address base slot lane) →
      CC.Mem.load .Mint8unsigned after stack offset = CC.Mem.load .Mint8unsigned supplied stack offset) := by
  have existsStore : ∃ after, CC.Mem.store .Mint8unsigned supplied stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) (.Vint ((value.setWidth 8).setWidth 32)) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have field : CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._stack (.Vptr binding (0#64)) = some (binding, (8#64), .Full) := by
    simp only [CC.lvalOfField, layout.bindings, stack_offset]
    rfl
  have bfield : CC.lvalOfField ge (.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr)
      X86_program_profile_bpf._b (.Vptr stack base) = some (stack, base, .Full) := by
    simp only [CC.lvalOfField, stackLayout, byte_offset]
    exact congrArg (fun n : CC.Integers.Ptrofs => some (stack, n, CC.Bitfield.Full)) (BitVec.add_zero base)
  have delta := displacement slot lane
  have readback : CC.Mem.load .Mint8unsigned after stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) = some (.Vint ((value.setWidth 8).setWidth 32)) := by
    rw [CC.Mem.load_store_same stored]
    change some (CC.Val.Vint (CC.Cop.castIntInt .I8 .Unsigned ((value.setWidth 8).setWidth 32))) = _
    rw [byte_again]
  refine ⟨after, stored, ?_, readback, CC.Mem.store_access stored, CC.Mem.store_nextblock stored, ?_, ?_⟩
  · change CC.Mem.store .Mint8unsigned supplied stack
      (Int.ofNat ((@BitVec.add 64 base (BitVec.ofInt 64 (8 * (slot.val : Int) + lane.val))).toNat))
      (.Vint ((value.setWidth 8).setWidth 32)) = some after at stored
    apply internalRun_of_steps
    all_goals simp +decide [steps, InternalPath, InternalState, continuation, afterProvider, temps,
      CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof,
      CC.setOpttemp, CC.PTree.gss, CC.PTree.gso, bindingRead, indexRead, laneRead, field, bfield,
      CC.accessMode, CC.Mem.loadv, CC.Mem.storev, header, byte_cast, byte_again,
      CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.semBinaryOperation, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof, delta,
      CC.tint, CC.tuint, CC.tuchar, CC.tulong, CC.tptr, CC.tarray, CC.Archi.ptr64_eq,
      CC.Integers.Int.add, CC.Integers.MI.add, CC.Integers.Ptrofs.add,
      CC.Integers.Ptrofs.repr, CC.Integers.MI.repr, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned,
      CC.Archi.ptrWordsize, CC.E0, CC.Eapp]
    all_goals rw (transparency := .all) [stored]
    all_goals trivial
  · intro chunk other offset different
    exact CC.Mem.load_store_other stored chunk other offset (.inl different)

  · intro offset different
    have disjoint : offset + CC.sizeChunk .Mint8unsigned ≤ CC.Integers.Ptrofs.unsigned (address base slot lane) ∨
        CC.Integers.Ptrofs.unsigned (address base slot lane) + CC.sizeChunk .Mint8unsigned ≤ offset :=
      separated offset _ different
    exact CC.Mem.load_store_other stored .Mint8unsigned stack offset (.inr disjoint)

/-- The genuine byte call retains the exact external trace and full supplied
heap, then constructs the source byte store and both outside-cache and other-byte frames. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (lane : Fin 8) (value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)))
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint8unsigned stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) .Writable = true) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseByteLoop.providerArm k e le before)
      trace (.State function .Sskip k e (temps le value stack base) after) ∧
    CC.Mem.store .Mint8unsigned supplied stack (CC.Integers.Ptrofs.unsigned (address base slot lane))
      (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
    CC.Mem.load .Mint8unsigned after stack (CC.Integers.Ptrofs.unsigned (address base slot lane)) =
      some (.Vint ((value.setWidth 8).setWidth 32)) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) ∧
    (∀ offset, offset ≠ CC.Integers.Ptrofs.unsigned (address base slot lane) →
      CC.Mem.load .Mint8unsigned after stack offset = CC.Mem.load .Mint8unsigned supplied stack offset) := by
  have entered := enter ge function e le k before input symbol global notLocal
  obtain ⟨after, stored, suffix, readback, access, frontier, frame, bytes⟩ :=
    returned ge layout stackLayout function e le k supplied binding stack base slot lane value
      bindingRead indexRead laneRead header writable
  have call : CC.Star (CC.Step2 ge)
      (.Callstate inputFunction [.Vint (6#32)] (continuation function e le k) before)
      trace (.Returnstate (.Vlong value) (continuation function e le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨after, ?_, stored, readback, access, frontier, frame, bytes⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) suffix.sound

/-- All original range decisions compose with the actual byte provider/store.
No initial byte value, after-run store or deterministic provider is assumed. -/
theorem selected (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (lane : Fin 8) (old next value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)))
    (offsetRead : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (released : X86RegisterWriteRspReleaseByteLoop.released slot lane old next = true)
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint8unsigned stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) .Writable = true) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e le before)
      trace (.State function .Sskip (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e
        (temps (X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next) value stack base) after) ∧
    CC.Mem.store .Mint8unsigned supplied stack (CC.Integers.Ptrofs.unsigned (address base slot lane))
      (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
    CC.Mem.load .Mint8unsigned after stack (CC.Integers.Ptrofs.unsigned (address base slot lane)) =
      some (.Vint ((value.setWidth 8).setWidth 32)) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) ∧
    (∀ offset, offset ≠ CC.Integers.Ptrofs.unsigned (address base slot lane) →
      CC.Mem.load .Mint8unsigned after stack offset = CC.Mem.load .Mint8unsigned supplied stack offset) := by
  let ready := X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next
  have chosen := X86RegisterWriteRspReleaseByteLoop.choose ge function e le k before slot lane old next
    laneRead indexRead offsetRead oldRead nextRead
  simp only [X86RegisterWriteRspReleaseByteLoop.arm, released, ite_true] at chosen
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) := by
    simp +decide [ready, X86RegisterWriteRspReleaseByteLoop.temps, CC.PTree.gso, bindingRead]
  have indexReady : ready.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)) := by
    simp +decide [ready, X86RegisterWriteRspReleaseByteLoop.temps, CC.PTree.gso, indexRead]
  have laneReady : ready.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)) := by
    simp +decide [ready, X86RegisterWriteRspReleaseByteLoop.temps, CC.PTree.gso, laneRead]
  obtain ⟨after, suffix, stored, readback, access, frontier, frame, bytes⟩ :=
    execute ge layout stackLayout function e ready (X86RegisterWriteRspReleaseByteLoop.loopContinuation k)
      before supplied binding stack input base slot lane value trace symbol global notLocal
      bindingReady indexReady laneReady provider header writable
  refine ⟨after, ?_, stored, readback, access, frontier, frame, bytes⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans chosen.sound suffix

/-- An excluded byte takes the actual skip arm and next-lane backedge in16
internal transitions, without an external call or any heap change. -/
theorem skipped (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64)
    (laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (offsetRead : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (released : X86RegisterWriteRspReleaseByteLoop.released slot lane old next = false) :
    InternalRun ge 16
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e le memory)
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e
        ((X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next).set
          X86_program_profile_bpf.___x86_release_lane__5 (.Vint (BitVec.ofNat 32 (lane.val + 1)))) memory) := by
  let ready := X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next
  have chosen := X86RegisterWriteRspReleaseByteLoop.choose ge function e le k memory slot lane old next
    laneRead indexRead offsetRead oldRead nextRead
  simp only [X86RegisterWriteRspReleaseByteLoop.arm, released, ite_false] at chosen
  have laneReady : ready.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)) := by
    simp +decide [ready, X86RegisterWriteRspReleaseByteLoop.temps, CC.PTree.gso, laneRead]
  exact chosen.trans (X86RegisterWriteRspReleaseByteLoop.advance ge function e ready k memory lane laneReady)

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteCall
