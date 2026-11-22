import KProgFormal.ClightRefinement.Arm64CompareRhs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Prefix

private theorem checked_load {frontier : CC.Block} {chunk : CC.Chunk} {m : CC.Mem}
    {address value : CC.Val} (read : Arm64EntryMemory.load frontier chunk m address = some value) :
    CC.Mem.loadv chunk m address = some value := by
  obtain ⟨_, _, rfl, _, actual⟩ := Arm64EntryMemory.load_pointer read
  exact actual

private theorem cells_address (b : CC.Block) (ofs : CC.Integers.Ptrofs) :
    Arm64EntryMemory.fieldAddress (.Vptr b ofs) Arm64Program._cells =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 0))) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem tags_address (b : CC.Block) (ofs : CC.Integers.Ptrofs) :
    Arm64EntryMemory.fieldAddress (.Vptr b ofs) Arm64Program._tag_cells =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 8))) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem field_load (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (name : CC.Ident) (delta : CC.Z) (value : CC.Val)
    (address : Arm64EntryMemory.fieldAddress (.Vptr b ofs) name =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr delta))))
    (read : Arm64EntryMemory.field frontier CC.Mptr m (.Vptr b ofs) name = some value) :
    CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr delta))) = some value := by
  exact checked_load (by simpa only [Arm64EntryMemory.field, address, bind, Option.bind_some] using read)

/-- Real source storage observations supply all helper loads, not an assumed
helper return or a second native/result relation. -/
theorem rhs_scalar {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (op : le.get Arm64Program._op = some (.Vint (23#32)))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 138 (.State Arm64Nop.handler Operands.rhs k e le memory)
      (.State Arm64Nop.handler RhsCall.flags k e
        (Rhs.temps le (Arm64Modified.Modifier.result value narrow)) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong value, .Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  obtain ⟨cb, co, vb, vo, tb, to, kb, ko, cells, slot, tags, tagSlot, cell, kind⟩ :=
    Arm64EntryMemory.gpr_loads observed
  have cellsLoad := field_load memory.nextblock entry.block 0 memory _ 0 _
    (cells_address entry.block 0) cells
  have tagsLoad := field_load memory.nextblock entry.block 0 memory _ 8 _
    (tags_address entry.block 0) tags
  exact Rhs.execute i entry.block cb vb tb kb 0 co vo to ko memory k e le narrow value
    unshadowed entryRead src aux effective op cellsLoad slot tagsLoad tagSlot cell kind

def temps (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) : CC.TempEnv :=
  Rhs.temps (Operands.lhsTemps le lhs) (Arm64Modified.Modifier.result rhs narrow)

theorem values (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) :
    (temps le lhs rhs narrow).get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs) ∧
    (temps le lhs rhs narrow).get Arm64Program.___a64_l_rhs__4 =
      some (.Vlong (Arm64Modified.Modifier.result rhs narrow)) := by
  simp +decide [temps, Rhs.temps, Operands.lhsTemps, CC.PTree.gso]

/-- Both original scalar operand reads and the actual modified-helper/selector
path reach the original NZCV loop with the same full heap and caller. -/
theorem execute {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i j : Fin 31) (lhs rhs : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (modifiedName : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (op : le.get Arm64Program._op = some (.Vint (23#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 218 (.State Arm64Nop.handler Dispatch.branch k e le memory)
      (.State Arm64Nop.handler RhsCall.flags k e (temps le lhs rhs narrow) memory) := by
  have left := Operands.lhs_scalar storage i lhs e le k readName entryRead dst lhsWord lhsTag
  have inputs :
      (Operands.lhsTemps le lhs).get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      (Operands.lhsTemps le lhs).get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)) ∧
      (Operands.lhsTemps le lhs).get Arm64Program._aux = some (.Vint (256#32)) ∧
      (Operands.lhsTemps le lhs).get Arm64Program.___a64_l_width = some (RhsCall.width narrow) ∧
      (Operands.lhsTemps le lhs).get Arm64Program._op = some (.Vint (23#32)) := by
    simp +decide only [Operands.lhsTemps, CC.PTree.gso, entryRead, src, aux, effective, op]
  have right := rhs_scalar storage j rhs e (Operands.lhsTemps le lhs) k narrow modifiedName
    inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1 inputs.2.2.2.2 rhsWord rhsTag
  exact left.trans right

end KProgFormal.ClightRefinement.Arm64Compare.Prefix
