import KProgFormal.ClightRefinement.Arm64CnegNumeric
import KProgFormal.ClightRefinement.Arm64CnegWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Path

/-- Original generic-handler inputs retained across this CNEG branch. -/
def inputs : List CC.Ident :=
  [Arm64Program._entry, Arm64Program._dst, Arm64Program._src, Arm64Program._src2,
    Arm64Program._src3, Arm64Program._flags, Arm64Program._aux, Arm64Program._op,
    Arm64Program.___a64_l_width]

private theorem retained_input (id : CC.Ident) (inside : id ∈ inputs) :
    id ∈ Numeric.retained := by
  simp only [inputs, List.mem_cons, List.not_mem_nil, or_false] at inside
  rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals simp [Numeric.retained]

private theorem condition_kept (le : CC.TempEnv) (blocks : Fin 4 → CC.Block)
    (z : BitVec 1) (id : CC.Ident) (inside : id ∈ inputs) :
    (Condition.temps le blocks z).get id = le.get id := by
  apply Condition.temps_other
  simp only [inputs, List.mem_cons, List.not_mem_nil, or_false] at inside
  rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals decide +kernel

/-- Actual scalar or warm-stack read, GE evaluation, numeric suffix and scalar
writer compose on the same reached heap, with original caller inputs kept.
Premises are pre-memory observations and the true source-call ABI. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (flags : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (src dst : Fin 31) (raw : BitVec 64) (tag : BitVec 8)
    (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) src.val =
      some (.Vlong raw, .Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (readerFree : e.get Arm64Program._kprog_arm64_program_read = none)
    (conditionFree : e.get Arm64Program._kprog_arm64_program_condition = none)
    (writerFree : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 src.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (op : le.get Arm64Program._op = some (.Vint (65#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (10#32)))
    (width : le.get Arm64Program.___a64_l_width = some (.Vint (8#32))) :
    ∃ count after le',
      Arm64RegisterWrite.Result storage dst
        (let value := Reference.Provenance.AArch64.materialize origins raw tag
         if ConditionHolds (10#4) s.machine then -value else value) false after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler ReadEntry.branch k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  let value := Reference.Provenance.AArch64.materialize origins raw tag
  let readTemps := ReadEntry.valueTemps le value
  let blocks := fun i => (storage.flags i).block
  let truth := BitVec.ofBool (ConditionHolds (10#4) s.machine)
  let conditionTemps := Condition.temps readTemps blocks truth
  have readRun := ReadEntry.scalar origins m.nextblock entry.block 0 src e le m k raw tag
    tags observed cache readerFree entryRead source op
  have ready := ReadEntry.ready le value
  have readKept (id : CC.Ident) (inside : id ∈ inputs) : readTemps.get id = le.get id :=
    ready.2 id inside
  have conditionKept (id : CC.Ident) (inside : id ∈ inputs) :
      conditionTemps.get id = le.get id :=
    (condition_kept readTemps blocks truth id inside).trans (readKept id inside)
  have geRun := Condition.execute storage s flags e readTemps (ReadEntry.tailCont k)
    conditionFree ((readKept _ (by simp [inputs])).trans entryRead)
    ((readKept _ (by simp [inputs])).trans aux)
  have numericOp : conditionTemps.get Arm64Program.___kprog_a64_cneg_op = some (.Vlong (65#64)) := by
    rw [Condition.temps_other _ _ _ _ (by decide +kernel)]
    change (((le.set Arm64Program.___kprog_a64_cneg_op (.Vlong (65#64))).set
      Arm64Program._t'54 (.Vlong value)).set Arm64Program.___kprog_a64_cneg_value (.Vlong value)).get
      Arm64Program.___kprog_a64_cneg_op = _
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gso _ _ _ _ (by decide +kernel), CC.PTree.gss]
  have operand : conditionTemps.get Arm64Program.___kprog_a64_cneg_value = some (.Vlong value) := by
    rw [Condition.temps_other _ _ _ _ (by decide +kernel)]
    exact ready.1
  obtain ⟨count, numericTemps, numericRun, result, numericKept⟩ := Numeric.execute
    Arm64ProgramEntryLinked.ge e conditionTemps m k value numericOp operand
    ((conditionKept _ (by simp [inputs])).trans width) (ConditionHolds (10#4) s.machine)
    (Condition.taken_value readTemps blocks truth)
  have finalKept (id : CC.Ident) (inside : id ∈ inputs) : numericTemps.get id = le.get id :=
    (numericKept id (retained_input id inside)).trans (conditionKept id inside)
  obtain ⟨after, written, writeRun⟩ := Write.scalar_write storage dst
    (if ConditionHolds (10#4) s.machine then -value else value) false e numericTemps k writerFree
    ((finalKept _ (by simp [inputs])).trans entryRead)
    ((finalKept _ (by simp [inputs])).trans destination) result
    ((finalKept _ (by simp [inputs])).trans width)
  exact ⟨_, after, numericTemps, written, ((readRun.trans geRun).trans numericRun).trans writeRun, finalKept⟩

end KProgFormal.ClightRefinement.Arm64Cneg.Path
