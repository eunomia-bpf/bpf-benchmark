import KProgFormal.ClightRefinement.Arm64CntReadReduction

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cnt.High

private def condition : CC.Expr :=
  .Ebinop .Oeq (.Etempvar Arm64Program._aux CC.tuint) (.Econst_int (CC.Integers.Int.repr 16) CC.tint) CC.tint
private def copyResult : CC.Stmt :=
  .Sset Arm64Program._t'2790 (.Ecast (.Etempvar Arm64Program._t'2791 CC.tulong) CC.tulong)
private def saveResult : CC.Stmt :=
  .Sset Arm64Program.___a64_red_hi (.Etempvar Arm64Program._t'2790 CC.tulong)

/-- The high-half choice and both copies are extracted from the actual CNT branch. -/
theorem source : ReductionSite.highPath =
    .Ssequence (.Sifthenelse condition (.Ssequence (ReductionSite.readPrefix true) copyResult)
      (.Sset Arm64Program._t'2790 (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tint) CC.tulong))) saveResult := rfl

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (yes no : CC.Stmt) (aux : le.get Arm64Program._aux = some (.Vint (16#32))) :
    CC.Step2 world (.State Arm64Nop.handler (.Sifthenelse condition yes no) k e le m) CC.E0
      (.State Arm64Nop.handler yes k e le m) := by
  apply CC.doStep_sound
  simp +decide only [condition,CC.doStep,CC.doEvalExpr,aux,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
    CC.tattr,CC.tuint,CC.tint,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Archi.ptr64,ite_true,ite_false]
  rfl

private theorem copy_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) (input : le.get Arm64Program._t'2791 = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler copyResult k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program._t'2790 (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [copyResult,CC.doStep,CC.doEvalExpr,input,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.Archi.ptr64,ite_true]

private theorem save_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) (input : le.get Arm64Program._t'2790 = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler saveResult k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program.___a64_red_hi (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [saveResult,CC.doStep,CC.doEvalExpr,input,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong]

def temps (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) : CC.TempEnv :=
  ((ReadReduction.temps true le vb vo value).set Arm64Program._t'2790
    (.Vlong (DPSFP.simd_count_bytes value))).set Arm64Program.___a64_red_hi
      (.Vlong (DPSFP.simd_count_bytes value))

/-- The real AUX16 choice, original high read/call and both original copies
save the imported count for the later high store, retaining the complete heap. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr 352)) = some (.Vptr vb vo))
    (loaded : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (16#32))) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler ReductionSite.highPath k e le m)
      (.State Arm64Nop.handler .Sskip k e (temps le vb vo value) m) := by
  have start : InternalRun Arm64ProgramEntryLinked.ge 3
      (.State Arm64Nop.handler ReductionSite.highPath k e le m)
      (.State Arm64Nop.handler (ReductionSite.readPrefix true)
        (.Kseq copyResult (.Kseq saveResult k)) e le m) := by
    rw [source]
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    apply InternalRun.step
    · trivial
    · exact choose_step _ e le m _ _ _ aux
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    exact .refl _
  obtain ⟨count,run⟩ := ReadReduction.execute true e le m (.Kseq copyResult (.Kseq saveResult k))
    b vb vo value entry slot loaded global op
  have tail : InternalRun Arm64ProgramEntryLinked.ge 4
      (.State Arm64Nop.handler .Sskip (.Kseq copyResult (.Kseq saveResult k)) e
        (ReadReduction.temps true le vb vo value) m)
      (.State Arm64Nop.handler .Sskip k e (temps le vb vo value) m) := by
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    apply InternalRun.step
    · trivial
    · exact copy_step _ e _ m _ _ (ReadReduction.result true le vb vo value)
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    apply InternalRun.step
    · trivial
    · exact save_step _ e _ m _ _ (CC.PTree.gss _ _ _)
    exact .refl _
  exact ⟨_,(start.trans run).trans tail⟩

theorem result (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps le vb vo value).get Arm64Program.___a64_red_hi = some (.Vlong (DPSFP.simd_count_bytes value)) :=
  CC.PTree.gss _ _ _

theorem entry (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps le vb vo value).get Arm64Program._entry = le.get Arm64Program._entry := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gso _ _ _ _ (by decide +kernel)]
  exact ReadReduction.entry true le vb vo value

theorem opcode (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps le vb vo value).get Arm64Program._op = le.get Arm64Program._op := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gso _ _ _ _ (by decide +kernel)]
  exact ReadReduction.opcode true le vb vo value

end KProgFormal.ClightRefinement.Arm64Cnt.High
