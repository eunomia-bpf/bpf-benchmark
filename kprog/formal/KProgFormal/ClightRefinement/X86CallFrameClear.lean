import KProgFormal.ClightRefinement.X86CallFrameStages

namespace KProgFormal.ClightRefinement.X86CallFrameClear

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_frame_clear_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def names : List (CC.Ident × CC.Ident) := by
  run_tac do
    let norm (e : Lean.Expr) := Lean.Meta.withTransparency .all (Lean.Meta.whnf e)
    let mut rows : Array Lean.Expr := #[]
    for i in [0:6] do
      let expr ← Lean.Elab.Term.elabTerm (← `(X86CallFrameStages.clear $(Lean.quote i))) none
      let loop ← norm expr
      unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "expected original clearing loop"
      let body ← norm loop.getAppArgs[0]!
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "expected original clearing sequence"
      let mut ids : Array Lean.Expr := #[]
      for side in body.getAppArgs do
        let seq ← norm side
        unless seq.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "expected original metadata sequence"
        let set ← norm seq.getAppArgs[0]!
        unless set.isAppOfArity ``CC.Stmt.Sset 2 do throwError "expected original metadata pointer read"
        ids := ids.push set.getAppArgs[0]!
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[ids[0]!, ids[1]!])
    Lean.Elab.Tactic.closeMainGoal `original_frame_clear_names
      (← Lean.Meta.mkListLit (← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Ident, Lean.mkConst ``CC.Ident]) rows.toList)
private theorem six : names.length = 6 := rfl
private def ids (slot : Fin 6) : CC.Ident × CC.Ident := names[slot.val]'(by rw [six]; exact slot.isLt)
def tagIdent (slot : Fin 6) : CC.Ident := (ids slot).1
def pointerIdent (slot : Fin 6) : CC.Ident := (ids slot).2

private def bindingsTy : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr
private def valueTy : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr
private def field (slot : Fin 6) (name : CC.Ident) (ty : CC.Ty) : CC.Expr :=
  .Efield (.Ederef
    (.Ebinop .Oadd
      (.Efield (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr bindingsTy)) bindingsTy)
        X86_program_profile_bpf._values (CC.tarray valueTy 6))
      (.Econst_int (CC.Integers.Int.repr slot.val) CC.tint) (CC.tptr valueTy)) valueTy) name ty
private def clearBody (slot : Fin 6) : CC.Stmt :=
  .Ssequence
    (.Ssequence (.Sset (tagIdent slot) (field slot X86_program_profile_bpf._tag (CC.tptr CC.tuchar)))
      (.Sassign (.Ederef (.Etempvar (tagIdent slot) (CC.tptr CC.tuchar)) CC.tuchar)
        (.Econst_int 0 CC.tuint)))
    (.Ssequence (.Sset (pointerIdent slot) (field slot X86_program_profile_bpf._pointer (CC.tptr (CC.tptr CC.tvoid))))
      (.Sassign (.Ederef (.Etempvar (pointerIdent slot) (CC.tptr (CC.tptr CC.tvoid))) (CC.tptr CC.tvoid))
        (.Econst_int 0 CC.tint)))

private theorem cases6 : ∀ i : Fin 6, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 := by decide +kernel

/-- The generic pattern is definitionally the actual original body at every slot. -/
theorem source (slot : Fin 6) : X86CallFrameStages.clear slot = .Sloop (clearBody slot) .Sbreak := by
  rcases cases6 slot with rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

private theorem distinct_names : ∀ slot : Fin 6,
    X86_program_profile_bpf.___x86_bind ≠ tagIdent slot ∧
    X86_program_profile_bpf.___x86_bind ≠ pointerIdent slot ∧
    tagIdent slot ≠ pointerIdent slot := by decide +kernel

private def bindingMembers : List CC.Member := by run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))
private def valueMembers : List CC.Member := by run_tac cachePart (← `(X86ShiftLeftCarry.valueRecord.co_members))
private theorem values_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._values X86ShiftLeftCarry.bindingsRecord.co_members = .OK (16, .Full) := by
  have aligned : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  change CC.fieldOffset ce X86_program_profile_bpf._values bindingMembers = _
  simp +decide [bindingMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, aligned]
private theorem tag_offset (ce : CC.CompositeEnv) :
    CC.fieldOffset ce X86_program_profile_bpf._tag X86ShiftLeftCarry.valueRecord.co_members = .OK (0, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._tag valueMembers = _
  simp +decide [valueMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.bitalignof, CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
private theorem pointer_offset (ce : CC.CompositeEnv) :
    CC.fieldOffset ce X86_program_profile_bpf._pointer X86ShiftLeftCarry.valueRecord.co_members = .OK (8, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._pointer valueMembers = _
  simp +decide [valueMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]

def headerOffset (slot : Fin 6) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add (CC.Integers.Ptrofs.repr 16)
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 16)
      (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr slot.val)))

/-- The source pointer arithmetic addresses exactly the two metadata fields. -/
theorem header_offset : ∀ slot : Fin 6,
    headerOffset slot = CC.Integers.Ptrofs.repr (16 + 16 * (slot.val : Int)) := by decide +kernel

def temps (le : CC.TempEnv) (slot : Fin 6) (tagBlock pointerBlock : CC.Block)
    (tagOffset pointerOffset : CC.Integers.Ptrofs) : CC.TempEnv :=
  (le.set (tagIdent slot) (.Vptr tagBlock tagOffset)).set (pointerIdent slot) (.Vptr pointerBlock pointerOffset)

/-- Both original stores are constructed from initial writable rights.
Actual source reads, null/tag readbacks and the outside-target frame are retained. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (slot : Fin 6) (binding tagBlock pointerBlock : CC.Block) (tagOffset pointerOffset : CC.Integers.Ptrofs)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (tagRead : CC.Mem.load CC.Mptr memory binding (CC.Integers.Ptrofs.unsigned (headerOffset slot)) =
      some (.Vptr tagBlock tagOffset))
    (pointerRead : CC.Mem.load CC.Mptr memory binding
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add (headerOffset slot) (CC.Integers.Ptrofs.repr 8))) =
      some (.Vptr pointerBlock pointerOffset))
    (notHeader : tagBlock ≠ binding) (different : tagBlock ≠ pointerBlock)
    (tagWritable : CC.Mem.validAccess memory .Mint8unsigned tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) .Writable = true)
    (pointerWritable : CC.Mem.validAccess memory CC.Mptr pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) .Writable = true) :
    ∃ middle after,
    CC.Mem.store .Mint8unsigned memory tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) (.Vint (0#32)) = some middle ∧
    CC.Mem.store CC.Mptr middle pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) (.Vlong (0#64)) = some after ∧
    InternalRun ge 13 (.State function (X86CallFrameStages.clear slot) k e le memory)
      (.State function .Sskip k e (temps le slot tagBlock pointerBlock tagOffset pointerOffset) after) ∧
    CC.Mem.load .Mint8unsigned after tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) = some (.Vint (0#32)) ∧
    CC.Mem.load CC.Mptr after pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) = some (.Vlong (0#64)) ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    (∀ chunk other offset, other ≠ tagBlock → other ≠ pointerBlock →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  have firstExists : ∃ middle, CC.Mem.store .Mint8unsigned memory tagBlock
      (CC.Integers.Ptrofs.unsigned tagOffset) (.Vint (0#32)) = some middle := by
    simp only [CC.Mem.store, tagWritable, ite_true]; exact ⟨_, rfl⟩
  obtain ⟨middle, tagStored⟩ := firstExists
  have nextPermission := (CC.Mem.validAccess_store_eq tagStored CC.Mptr pointerBlock
    (CC.Integers.Ptrofs.unsigned pointerOffset) .Writable).trans pointerWritable
  have secondExists : ∃ after, CC.Mem.store CC.Mptr middle pointerBlock
      (CC.Integers.Ptrofs.unsigned pointerOffset) (.Vlong (0#64)) = some after := by
    simp only [CC.Mem.store, nextPermission, ite_true]; exact ⟨_, rfl⟩
  obtain ⟨after, pointerStored⟩ := secondExists
  have keptPointer := (CC.Mem.load_store_other tagStored CC.Mptr binding _ (.inl (Ne.symm notHeader))).trans pointerRead
  have valuesField : CC.lvalOfField ge bindingsTy X86_program_profile_bpf._values (.Vptr binding (0#64)) =
      some (binding, (16#64), .Full) := by
    simp only [bindingsTy, CC.lvalOfField, layout.bindings, values_offset _ valueLayout]; rfl
  have tagField : CC.lvalOfField ge valueTy X86_program_profile_bpf._tag (.Vptr binding (headerOffset slot)) =
      some (binding, headerOffset slot, .Full) := by
    simp only [valueTy, CC.lvalOfField, valueLayout, tag_offset]
    exact congrArg (fun n : CC.Integers.Ptrofs => some (binding, n, CC.Bitfield.Full)) (BitVec.add_zero (headerOffset slot))
  have pointerField : CC.lvalOfField ge valueTy X86_program_profile_bpf._pointer (.Vptr binding (headerOffset slot)) =
      some (binding, CC.Integers.Ptrofs.add (headerOffset slot) (CC.Integers.Ptrofs.repr 8), .Full) := by
    simp only [valueTy, CC.lvalOfField, valueLayout, pointer_offset]
  dsimp only [bindingsTy, valueTy] at valuesField tagField pointerField
  change CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr)
      X86_program_profile_bpf._tag (.Vptr binding (CC.Integers.Ptrofs.add (16#64)
        (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr X86ShiftLeftCarry.valueRecord.co_sizeof)
          (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr slot.val))))) =
      some (binding, headerOffset slot, .Full) at tagField
  change CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr)
      X86_program_profile_bpf._pointer (.Vptr binding (CC.Integers.Ptrofs.add (16#64)
        (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr X86ShiftLeftCarry.valueRecord.co_sizeof)
          (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr slot.val))))) =
      some (binding, CC.Integers.Ptrofs.add (headerOffset slot) (CC.Integers.Ptrofs.repr 8), .Full) at pointerField
  have byteZero : CC.Integers.Int.zero_ext 8 (0#32) = (0#32) := rfl
  have pointerZero : CC.Integers.Int64.repr (CC.Integers.Int.signed (0#32)) = (0#64) := rfl
  have namesDistinct := distinct_names slot
  refine ⟨middle, after, tagStored, pointerStored, ?_, ?_, CC.Mem.load_store_same pointerStored,
    (CC.Mem.store_access pointerStored).trans (CC.Mem.store_access tagStored),
    (CC.Mem.store_nextblock pointerStored).trans (CC.Mem.store_nextblock tagStored), ?_⟩
  · rw [source]
    apply internalRun_of_steps
    all_goals simp +decide [steps, InternalPath, InternalState, clearBody, field, bindingsTy, valueTy, temps,
      CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof,
      CC.PTree.gss, CC.PTree.gso, namesDistinct.1, namesDistinct.2.1, namesDistinct.2.2,
      Ne.symm namesDistinct.1, Ne.symm namesDistinct.2.1, Ne.symm namesDistinct.2.2,
      bindingRead, valuesField, tagField, pointerField, CC.accessMode, CC.Mem.loadv, CC.Mem.storev,
      tagRead, keptPointer, tagStored, pointerStored, byteZero, pointerZero,
      CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.sizeof, valueLayout,
      CC.tint, CC.tuint, CC.tuchar, CC.tptr, CC.tarray, CC.tvoid, CC.Archi.ptr64_eq, CC.E0, CC.Eapp]
  · exact (CC.Mem.load_store_other pointerStored .Mint8unsigned tagBlock _ (.inl different)).trans (CC.Mem.load_store_same tagStored)
  · intro chunk other offset notTag notPointer
    exact (CC.Mem.load_store_other pointerStored chunk other offset (.inl notPointer)).trans
      (CC.Mem.load_store_other tagStored chunk other offset (.inl notTag))

/-- Actual clearing temporaries never overwrite the binding or raw-SP inputs. -/
theorem stable_temps (le : CC.TempEnv) (slot : Fin 6) (tagBlock pointerBlock : CC.Block)
    (tagOffset pointerOffset : CC.Integers.Ptrofs) :
    (temps le slot tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_bind =
      le.get X86_program_profile_bpf.___x86_bind ∧
    (temps le slot tagBlock pointerBlock tagOffset pointerOffset).get X86_program_profile_bpf.___x86_sv_sp =
      le.get X86_program_profile_bpf.___x86_sv_sp := by
  have untouched : ∀ slot : Fin 6,
      X86_program_profile_bpf.___x86_bind ≠ tagIdent slot ∧
      X86_program_profile_bpf.___x86_bind ≠ pointerIdent slot ∧
      X86_program_profile_bpf.___x86_sv_sp ≠ tagIdent slot ∧
      X86_program_profile_bpf.___x86_sv_sp ≠ pointerIdent slot := by decide +kernel
  have safe := untouched slot
  simp only [temps, CC.PTree.gso _ _ _ _ (Ne.symm safe.1),
    CC.PTree.gso _ _ _ _ (Ne.symm safe.2.1), CC.PTree.gso _ _ _ _ (Ne.symm safe.2.2.1),
    CC.PTree.gso _ _ _ _ (Ne.symm safe.2.2.2), and_self]

/-- The actual true guard, both constructed clearing stores and original
loop breaks compose to a complete17-transition selected slot. -/
theorem selected (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (slot : Fin 6) (binding tagBlock pointerBlock : CC.Block) (tagOffset pointerOffset : CC.Integers.Ptrofs)
    (sp : BitVec 64)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (observedSp : le.get X86_program_profile_bpf.___x86_sv_sp = some (.Vlong sp))
    (decision : X86CallFrameStages.selected slot sp = true)
    (tagRead : CC.Mem.load CC.Mptr memory binding (CC.Integers.Ptrofs.unsigned (headerOffset slot)) =
      some (.Vptr tagBlock tagOffset))
    (pointerRead : CC.Mem.load CC.Mptr memory binding
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add (headerOffset slot) (CC.Integers.Ptrofs.repr 8))) =
      some (.Vptr pointerBlock pointerOffset))
    (notHeader : tagBlock ≠ binding) (different : tagBlock ≠ pointerBlock)
    (tagWritable : CC.Mem.validAccess memory .Mint8unsigned tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) .Writable = true)
    (pointerWritable : CC.Mem.validAccess memory CC.Mptr pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) .Writable = true) :
    ∃ middle after,
    CC.Mem.store .Mint8unsigned memory tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) (.Vint (0#32)) = some middle ∧
    CC.Mem.store CC.Mptr middle pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) (.Vlong (0#64)) = some after ∧
    InternalRun ge 17 (.State function (X86CallFrameStages.stage slot) k e le memory)
      (.State function .Sskip k e (temps le slot tagBlock pointerBlock tagOffset pointerOffset) after) ∧
    CC.Mem.load .Mint8unsigned after tagBlock (CC.Integers.Ptrofs.unsigned tagOffset) = some (.Vint (0#32)) ∧
    CC.Mem.load CC.Mptr after pointerBlock (CC.Integers.Ptrofs.unsigned pointerOffset) = some (.Vlong (0#64)) ∧
    after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    (∀ chunk other offset, other ≠ tagBlock → other ≠ pointerBlock →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  have chosen := X86CallFrameStages.choose ge function e le k memory slot sp observedSp
  simp only [X86CallFrameStages.arm, decision, ite_true] at chosen
  obtain ⟨middle, after, tagStored, pointerStored, cleared, tagBack, pointerBack, access, frontier, frame⟩ :=
    execute ge layout valueLayout function e le (X86CallFrameStages.continuation slot k) memory slot
      binding tagBlock pointerBlock tagOffset pointerOffset bindingRead tagRead pointerRead notHeader different
      tagWritable pointerWritable
  have completed := chosen.trans cleared
  have finished := completed.trans (X86CallFrameStages.finish ge function e
    (temps le slot tagBlock pointerBlock tagOffset pointerOffset) k after slot)
  exact ⟨middle, after, tagStored, pointerStored, finished, tagBack, pointerBack, access, frontier, frame⟩

end KProgFormal.ClightRefinement.X86CallFrameClear
