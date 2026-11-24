import KProgFormal.ClightRefinement.X86RegisterReadValue

namespace KProgFormal.ClightRefinement.X86FullWidthStorage

private structure Pieces where
  first : CC.Stmt
  firstTest : CC.Expr
  word : CC.Stmt
  second : CC.Stmt
  secondTest : CC.Expr
  dword : CC.Stmt
  qword : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 with
  | .Ssequence first (.Sifthenelse firstTest word
      (.Ssequence second (.Sifthenelse secondTest dword qword))) =>
      ⟨first, firstTest, word, second, secondTest, dword, qword⟩
  | _ => ⟨.Sskip, .Econst_int 0 CC.tint, .Sskip, .Sskip,
      .Econst_int 0 CC.tint, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_full_width_storage_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def first : CC.Stmt := by run_tac cachePart (← `(pieces.first))
private def firstTest : CC.Expr := by run_tac cachePart (← `(pieces.firstTest))
private def word : CC.Stmt := by run_tac cachePart (← `(pieces.word))
private def second : CC.Stmt := by run_tac cachePart (← `(pieces.second))
private def secondTest : CC.Expr := by run_tac cachePart (← `(pieces.secondTest))
def dword : CC.Stmt := by run_tac cachePart (← `(pieces.dword))
def qword : CC.Stmt := by run_tac cachePart (← `(pieces.qword))

/-- The complete original branch identity binds both leaves to the exported
production handler; source shape changes invalidate this proof. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 =
    .Ssequence first (.Sifthenelse firstTest word
      (.Ssequence second (.Sifthenelse secondTest dword qword))) := rfl

private theorem set_twice (id : CC.Ident) (value : CC.Val) (le : CC.TempEnv) :
    (le.set id value).set id value = le.set id value := by
  induction id generalizing le with
  | xH => cases le <;> rfl
  | xO id ih => cases le <;> simp [CC.PTree.set, ih]
  | xI id ih => cases le <;> simp [CC.PTree.set, ih]

def selectionTemps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  let code := X86ShiftWriteback.widthClass (if narrow then .d else .q)
  (le.set X86_program_profile_bpf._t'111 (.Vint code)).set
    X86_program_profile_bpf._t'110 (.Vint code)

/-- Both original repeated width classifiers and their actual branches
select the32/64-bit storage leaf in26 transitions without changing memory. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (narrow : Bool)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument (if narrow then .d else .q))) :
    InternalRun ge 26
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 k e le memory)
      (.State function (if narrow then dword else qword) k e (selectionTemps le narrow) memory) := by
  rw [source]
  cases narrow <;> apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep,
    first, firstTest, second, secondTest, selectionTemps, X86ShiftWriteback.widthClass,
    CC.doEvalExpr, CC.typeof, width, X86ShiftLeft.argument, X86.Size.bytes,
    CC.PTree.gss, CC.PTree.gso, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
    CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
    CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Eapp, CC.E0, set_twice]

def result (narrow : Bool) (value : BitVec 64) : BitVec 64 :=
  if narrow then X86.Value.trunc .d value else value

def temps (le : CC.TempEnv) (narrow : Bool) (value : BitVec 64) : CC.TempEnv :=
  let ready := if narrow then le.set X86_program_profile_bpf.___x86_wr_next__2
    (.Vlong (result narrow value)) else le
  ready.set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))

private theorem unsigned_widen (bits : BitVec 32) :
    CC.Cop.castIntLong .Unsigned bits = bits.setWidth 64 := by
  change BitVec.ofInt 64 (bits.toNat : Int) = _
  rw [BitVec.ofInt_natCast]
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_ofNat, BitVec.toNat_setWidth]

private theorem truncate_widen (value : BitVec 64) :
    (value.setWidth 32).setWidth 64 = X86.Value.trunc .d value := by
  change (value.setWidth 32).setWidth 64 = value &&& (BitVec.allOnes 32).setWidth 64
  rw [BitVec.and_setWidth_allOnes 32 32 value]
  simpa using (BitVec.setWidth_eq_append (x := value.setWidth 32) (w := 64) (by decide))

/-- The real32/64-bit storage leaves write the canonical zero-extended/full
word to the original local union and clear its tag in10/7 transitions. -/
private theorem run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory after : CC.Mem) (block : CC.Block) (value : BitVec 64) (narrow : Bool)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value))
    (stored : CC.Mem.store CC.Mptr memory block 0 (.Vlong (result narrow value)) = some after) :
    InternalRun ge (if narrow then 10 else 7)
      (.State function (if narrow then dword else qword) k e le memory)
      (.State function .Sskip k e (temps le narrow value) after) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = some (block, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have fieldAddress (offset : CC.Integers.Ptrofs) :=
    X86RegisterReadValue.pointer_address ge layout block offset
  have unionAccess : CC.accessMode (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      .By_copy := rfl
  have ptrAccess : CC.accessMode (CC.tptr CC.tvoid) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have zeroInt : CC.Integers.Int.repr 0 = (0#32) := rfl
  have longLong (bits : BitVec 64) (m : CC.Mem) :
      CC.Cop.semCast (.Vlong bits) CC.tulong CC.tlong m = some (.Vlong bits) := rfl
  have unsignedLong (bits : BitVec 64) (m : CC.Mem) :
      CC.Cop.semCast (.Vlong bits) CC.tulong CC.tulong m = some (.Vlong bits) := rfl
  have pointerCast (bits : BitVec 64) (m : CC.Mem) :
      CC.Cop.semCast (.Vlong bits) CC.tlong (CC.tptr CC.tvoid) m = some (.Vlong bits) := rfl
  have pointerSame (bits : BitVec 64) (m : CC.Mem) :
      CC.Cop.semCast (.Vlong bits) (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some (.Vlong bits) := rfl
  have zeroCast (m : CC.Mem) :
      CC.Cop.semCast (.Vint (0#32)) CC.tuint CC.tuchar m = some (.Vint (0#32)) := rfl
  have narrowCast (bits : BitVec 64) (m : CC.Mem) :
      CC.Cop.semCast (.Vlong bits) CC.tulong CC.tuint m = some (.Vint (bits.setWidth 32)) := rfl
  have widenUnsigned (bits : BitVec 32) (m : CC.Mem) :
      CC.Cop.semCast (.Vint bits) CC.tuint CC.tulong m =
        some (.Vlong (CC.Cop.castIntLong .Unsigned bits)) := rfl
  have widenSigned (bits : BitVec 32) (m : CC.Mem) :
      CC.Cop.semCast (.Vint bits) CC.tuint CC.tlong m =
        some (.Vlong (CC.Cop.castIntLong .Unsigned bits)) := rfl
  cases narrow
  all_goals simp only [result, Bool.false_eq_true, ite_true, ite_false] at stored
  all_goals apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, dword, qword,
    Bool.false_eq_true, ite_true, ite_false, List.nil_append, true_and,
    temps, result, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof,
    CC.Mem.storev, localAddress, fieldAddress, unionAccess, ptrAccess, unsigned0, zeroInt, observed, stored,
    CC.PTree.gss, zeroCast, narrowCast, widenUnsigned, widenSigned,
    longLong, unsignedLong, pointerCast, pointerSame,
    unsigned_widen, truncate_widen, X86.Value.trunc_trunc,
    CC.Eapp, CC.E0]

/-- Initial local write permission constructs the actual source store. The
final readback, access map and allocation frontier follow from that store. -/
theorem writable (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (block : CC.Block) (value : BitVec 64) (narrow : Bool)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value))
    (permission : CC.Mem.validAccess memory CC.Mptr block 0 .Writable = true) :
    ∃ after, InternalRun ge (if narrow then 10 else 7)
      (.State function (if narrow then dword else qword) k e le memory)
      (.State function .Sskip k e (temps le narrow value) after) ∧
      CC.Mem.load CC.Mptr after block 0 = some (.Vlong (result narrow value)) ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have existsStore : ∃ after, CC.Mem.store CC.Mptr memory block 0
      (.Vlong (result narrow value)) = some after := by
    simp only [CC.Mem.store, permission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  refine ⟨after, run ge layout function e le k memory after block value narrow declared observed stored,
    ?_, ?_, ?_⟩
  · have normalized : CC.Val.loadResult CC.Mptr (.Vlong (result narrow value)) =
        .Vlong (result narrow value) := rfl
    exact (CC.Mem.load_store_same stored).trans (congrArg some normalized)
  · exact CC.Mem.store_access stored
  · exact CC.Mem.store_nextblock stored

/-- Actual width selection and permission-derived storage compose from the
original branch. The concrete store, readback, access map, allocation frontier
and every other block's loads are retained for the table-writer composition. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (block : CC.Block) (value : BitVec 64) (narrow : Bool)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument (if narrow then .d else .q)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value))
    (permission : CC.Mem.validAccess memory CC.Mptr block 0 .Writable = true) :
    ∃ after, CC.Mem.store CC.Mptr memory block 0 (.Vlong (result narrow value)) = some after ∧
      InternalRun ge (26 + (if narrow then 10 else 7))
        (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 k e le memory)
        (.State function .Sskip k e (temps (selectionTemps le narrow) narrow value) after) ∧
      CC.Mem.load CC.Mptr after block 0 = some (.Vlong (result narrow value)) ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ block →
        CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  have selected := select ge function e le k memory narrow width
  have kept : (selectionTemps le narrow).get X86_program_profile_bpf.___x86_wr_next__2 =
      some (.Vlong value) := by
    simp +decide [selectionTemps, CC.PTree.gso, observed]
  have existsStore : ∃ after, CC.Mem.store CC.Mptr memory block 0
      (.Vlong (result narrow value)) = some after := by
    simp only [CC.Mem.store, permission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have written := run ge layout function e (selectionTemps le narrow) k memory after block value
    narrow declared kept stored
  have normalized : CC.Val.loadResult CC.Mptr (.Vlong (result narrow value)) =
      .Vlong (result narrow value) := rfl
  refine ⟨after, stored, selected.trans written,
    (CC.Mem.load_store_same stored).trans (congrArg some normalized),
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored, ?_⟩
  intro chunk other offset different
  exact CC.Mem.load_store_other stored chunk other offset (.inl different)

end KProgFormal.ClightRefinement.X86FullWidthStorage
