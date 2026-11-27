import KProgFormal.ClightRefinement.Arm64CiliumCallerTables

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerTableWrites
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation token)
open Arm64CiliumCallerTables

noncomputable def pair (tags : Bool) : CC.Stmt := by
  cases tags with
  | false => run_tac do
      let source ← Lean.getConstInfo ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_1701
      Lean.Elab.Tactic.closeMainGoal `original_word_pair source.value!.getAppArgs[0]!
  | true => run_tac do
      let source ← Lean.getConstInfo ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_1701
      Lean.Elab.Tactic.closeMainGoal `original_tag_pair source.value!.getAppArgs[1]!

noncomputable def tempName (tags : Bool) : CC.Ident := if tags then _t'12899 else _t'12900
noncomputable def valueType (tags : Bool) : CC.Ty := if tags then CC.tuchar else CC.tptr CC.tvoid
noncomputable def valueName (tags : Bool) : CC.Ident :=
  if tags then ___a64_l_next_tag else ___a64_l_next_ptr
noncomputable def chunk (tags : Bool) : CC.Chunk := if tags then .Mint8unsigned else .Mint64
noncomputable def value (tags : Bool) : CC.Val := if tags then .Vint (9#32) else .Vlong token
noncomputable def readExpr (tags : Bool) : CC.Expr :=
  .Ederef (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
    (.Ecast (.Etempvar ___a64_l_reg__234 CC.tulong) CC.tuchar)
    (CC.tptr (CC.tptr (cellType tags)))) (CC.tptr (cellType tags))
noncomputable def destination (tags : Bool) : CC.Expr :=
  if tags then .Ederef (.Etempvar (tempName tags) (CC.tptr (cellType tags))) CC.tuchar
  else .Efield (.Ederef (.Etempvar (tempName tags) (CC.tptr (cellType tags)))
    (cellType tags)) _ptr (CC.tptr CC.tvoid)
noncomputable def assignment (tags : Bool) : CC.Stmt :=
  .Sassign (destination tags) (.Etempvar (valueName tags) (valueType tags))

theorem pair_source (tags : Bool) : pair tags =
    .Ssequence (.Sset (tempName tags) (readExpr tags)) (assignment tags) := by
  cases tags <;> rfl
theorem tableWrites_source : Arm64CiliumCallerWriterGuard.tableWrites =
    .Ssequence (pair false) (pair true) := rfl

/-- A reached table entry retains the SAME original initializer execution.
Only its table-block frame is needed when later source stores intervene. -/
structure Initialized (tags : Bool) (m current : CC.Mem)
    (table : Table tags m) (cell : Cell tags m) where
  before : CC.Mem
  initialized : CC.Mem
  le : CC.TempEnv
  k : CC.Cont
  run : InternalRun ge 1
    (.State procedure (initializer tags) k (allocation m).1 le before)
    (.State procedure .Sskip k (allocation m).1 le initialized)
  stored : CC.Mem.store .Mint64 before table.block 240 (.Vptr cell.block 0) = some initialized
  frame : ∀ c o, CC.Mem.load c current table.block o = CC.Mem.load c initialized table.block o

theorem initialize_entry {m before : CC.Mem} (tags : Bool) (table : Table tags m)
    (cell : Cell tags m) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after, Nonempty (Initialized tags m after table cell) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨after,run,stored,_,_,frame,access,next⟩ := initializer_store tags table cell access le k
  exact ⟨after,⟨⟨before,after,le,k,run,stored,fun _ _ => rfl⟩⟩,frame,access,next⟩

def Initialized.after_store {m current after : CC.Mem} {tags : Bool}
    {table : Table tags m} {cell : Cell tags m}
    (entry : Initialized tags m current table cell) {c b o v}
    (stored : CC.Mem.store c current b o v = some after) (different : table.block ≠ b) :
    Initialized tags m after table cell :=
  {entry with frame := fun c o =>
    (CC.Mem.load_store_other stored c table.block o (.inl different)).trans (entry.frame c o)}

theorem cell_writable {m before : CC.Mem} (tags : Bool) (cell : Cell tags m)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before (chunk tags) cell.block 0 .Writable = true := by
  have owned := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ cell.binding).2.2
  have size : CC.sizeof ge.genv_cenv (cellType tags) = CC.sizeChunk (chunk tags) := by
    cases tags <;> rfl
  rw [size] at owned
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro offset lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned offset lower (by simpa using upper))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · cases tags <;> decide

/-- Each ORIGINAL read/assignment pair executes from a genuine initializer
resource;the successful table read and cell store are derived,not assumed. -/
theorem execute_pair {m before : CC.Mem} (tags : Bool) (table : Table tags m)
    (cell : Cell tags m) (entry : Initialized tags m before table cell)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont)
    (reg : le.get ___a64_l_reg__234 = some (.Vlong (30#64)))
    (outgoing : le.get (valueName tags) = some (value tags)) :
    ∃ after,
      InternalRun ge 4
        (.State procedure (pair tags) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1
          (le.set (tempName tags) (.Vptr cell.block 0)) after) ∧
      CC.Mem.store (chunk tags) before cell.block 0 (value tags) = some after ∧
      CC.Mem.load (chunk tags) after cell.block 0 = some (value tags) ∧
      (∀ block,block ≠ cell.block → ∀ c o,
        CC.Mem.load c after block o = CC.Mem.load c before block o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable := cell_writable tags cell access
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store (chunk tags) before cell.block 0 (value tags) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  have readback : CC.Mem.load .Mint64 before table.block 240 = some (.Vptr cell.block 0) := by
    rw [entry.frame]
    exact CC.Mem.load_store_same entry.stored
  have arrayValue : CC.doEvalExpr ge (allocation m).1 le before
      (.Evar (tableName tags) (tableType tags)) = some (.Vptr table.block 0) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,table.binding]
    cases tags <;> rfl
  have index : CC.doEvalExpr ge (allocation m).1 le before
      (.Ecast (.Etempvar ___a64_l_reg__234 CC.tulong) CC.tuchar) =
      some (.Vint (30#32)) := by
    simp only [CC.doEvalExpr,reg]
    rfl
  have add : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr table.block 0)
      (tableType tags) (.Vint (30#32)) CC.tuchar before =
      some (.Vptr table.block (240#64)) := by cases tags <;> rfl
  have address : CC.EvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
        (.Ecast (.Etempvar ___a64_l_reg__234 CC.tulong) CC.tuchar)
        (CC.tptr (CC.tptr (cellType tags)))) (.Vptr table.block (240#64)) :=
    .Ebinop .Oadd _ _ _ _ _ _
      (CC.doEvalExpr_sound _ _ _ _ _ _ arrayValue)
      (CC.doEvalExpr_sound _ _ _ _ _ _ index) add
  have read : CC.EvalExpr ge (allocation m).1 le before (readExpr tags) (.Vptr cell.block 0) := by
    apply CC.EvalExpr.Elvalue _ table.block (240#64) .Full _ (.Ederef _ _ _ _ address)
    apply CC.DerefLoc.value .Mint64 _ (by cases tags <;> rfl)
    exact readback
  let updated := le.set (tempName tags) (.Vptr cell.block 0)
  have target : CC.doEvalLvalue ge (allocation m).1 updated before (destination tags) =
      some (cell.block,0,.Full) := by
    cases tags <;> simp [destination,tempName,cellType,updated,CC.doEvalLvalue,
      CC.doEvalExpr,CC.PTree.gss,CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField]
    rfl
  have retained : updated.get (valueName tags) = some (value tags) := by
    rw [CC.PTree.gso _ _ _ _ (by cases tags <;> decide +kernel)]
    exact outgoing
  have cast : CC.Cop.semCast (value tags) (valueType tags) (valueType tags) before =
      some (value tags) := by cases tags <;> rfl
  have assigned : CC.doAssignLoc ge.genv_cenv (valueType tags) before cell.block 0
      .Full (value tags) = some after := by cases tags <;> exact stored
  have setStep : CC.Step2 ge
      (.State procedure (.Sset (tempName tags) (readExpr tags))
        (.Kseq (assignment tags) k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq (assignment tags) k) (allocation m).1 updated before) := by
    exact CC.Step.set _ _ _ _ _ _ _ _ read
  have assignStep : CC.Step2 ge
      (.State procedure (assignment tags) k (allocation m).1 updated before) CC.E0
      (.State procedure .Sskip k (allocation m).1 updated after) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _ target
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ retained
    · have ty : CC.typeof (destination tags) = valueType tags := by cases tags <;> rfl
      change CC.Cop.semCast (value tags) (valueType tags) (CC.typeof (destination tags)) before = _
      rw [ty]
      exact cast
    · have ty : CC.typeof (destination tags) = valueType tags := by cases tags <;> rfl
      rw [ty]
      exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have run : InternalRun ge 4
      (.State procedure (pair tags) k (allocation m).1 le before)
      (.State procedure .Sskip k (allocation m).1 updated after) := by
    rw [pair_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial setStep (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial assignStep (.refl _))))
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ cell.binding).1
  have same : CC.Mem.load (chunk tags) after cell.block 0 = some (value tags) := by
    have h := CC.Mem.load_store_same stored
    cases tags <;> exact h
  exact ⟨after,run,stored,same,
    (fun block different c o => CC.Mem.load_store_other stored c block o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

theorem cells_separate (m : CC.Mem) (word : Cell false m) (tag : Cell true m) :
    word.block ≠ tag.block :=
  (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ word.binding tag.binding (by decide +kernel)

private theorem guard_values (le : CC.TempEnv) :
    (Arm64CiliumCallerWriterGuard.temps le).get ___a64_l_reg__234 = some (.Vlong (30#64)) ∧
    (Arm64CiliumCallerWriterGuard.temps le).get ___a64_l_next_ptr = some (.Vlong token) ∧
    (Arm64CiliumCallerWriterGuard.temps le).get ___a64_l_next_tag = some (.Vint (9#32)) := by
  unfold Arm64CiliumCallerWriterGuard.temps Arm64CiliumCallerWriterPrefix.temps
  refine ⟨?_,?_,?_⟩
  · rw [CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1593 ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1595 ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1594 ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : ___a64_l_next_tag ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : ___a64_l_next_ptr ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'12904 ≠ ___a64_l_reg__234),
      CC.PTree.gss]
  · rw [CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1593 ≠ ___a64_l_next_ptr),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1595 ≠ ___a64_l_next_ptr),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1594 ≠ ___a64_l_next_ptr),
      CC.PTree.gso _ _ _ _ (by decide +kernel : ___a64_l_next_tag ≠ ___a64_l_next_ptr),
      CC.PTree.gss]
  · rw [CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1593 ≠ ___a64_l_next_tag),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1595 ≠ ___a64_l_next_tag),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'1594 ≠ ___a64_l_next_tag),
      CC.PTree.gss]

/-- The two real pairs are consecutive in1701. Each input table resource
retains its OWN genuine earlier initializer trace;no adjacency of those
initializers or entry-to-site reachability is asserted. -/
theorem execute {m before : CC.Mem} (words : Table false m) (tags : Table true m)
    (word : Cell false m) (tag : Cell true m)
    (wordEntry : Initialized false m before words word)
    (tagEntry : Initialized true m before tags tag)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ afterWord after,
      InternalRun ge 10
        (.State procedure Arm64CiliumCallerWriterGuard.tableWrites k (allocation m).1
          (Arm64CiliumCallerWriterGuard.temps le) before)
        (.State procedure .Sskip k (allocation m).1
          (((Arm64CiliumCallerWriterGuard.temps le).set _t'12900 (.Vptr word.block 0)).set
            _t'12899 (.Vptr tag.block 0)) after) ∧
      CC.Mem.store .Mint64 before word.block 0 (.Vlong token) = some afterWord ∧
      CC.Mem.store .Mint8unsigned afterWord tag.block 0 (.Vint (9#32)) = some after ∧
      CC.Mem.load .Mint64 after word.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint8unsigned after tag.block 0 = some (.Vint (9#32)) ∧
      Nonempty (Initialized false m after words word) ∧
      Nonempty (Initialized true m after tags tag) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨reg,ptr,tagValue⟩ := guard_values le
  obtain ⟨afterWord,wordRun,wordStore,wordRead,_,wordFrame,wordAccess,wordNext⟩ :=
    execute_pair false words word wordEntry access
      (Arm64CiliumCallerWriterGuard.temps le) (.Kseq (pair true) k) reg ptr
  let middle := (Arm64CiliumCallerWriterGuard.temps le).set _t'12900 (.Vptr word.block 0)
  have middleReg : middle.get ___a64_l_reg__234 = some (.Vlong (30#64)) := by
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact reg
  have middleTag : middle.get ___a64_l_next_tag = some (.Vint (9#32)) := by
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact tagValue
  have tagEntry' := tagEntry.after_store wordStore (table_cell_separate m true false tags word)
  obtain ⟨after,tagRun,tagStore,tagRead,tagOther,tagFrame,tagAccess,tagNext⟩ :=
    execute_pair true tags tag tagEntry' (wordAccess.trans access) middle k middleReg middleTag
  have separate := cells_separate m word tag
  have wordFinal := (tagOther word.block separate .Mint64 0).trans wordRead
  have wordEntry' := (wordEntry.after_store wordStore
    (table_cell_separate m false false words word)).after_store tagStore
      (table_cell_separate m false true words tag)
  have tagEntry'' := tagEntry'.after_store tagStore (table_cell_separate m true true tags tag)
  have run : InternalRun ge 10
      (.State procedure Arm64CiliumCallerWriterGuard.tableWrites k (allocation m).1
        (Arm64CiliumCallerWriterGuard.temps le) before)
      (.State procedure .Sskip k (allocation m).1
        (middle.set _t'12899 (.Vptr tag.block 0)) after) := by
    rw [tableWrites_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (wordRun.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) tagRun))
  exact ⟨afterWord,after,run,wordStore,tagStore,wordFinal,tagRead,⟨wordEntry'⟩,⟨tagEntry''⟩,
    wordFrame.trans tagFrame,tagAccess.trans wordAccess,tagNext.trans wordNext⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerTableWrites
