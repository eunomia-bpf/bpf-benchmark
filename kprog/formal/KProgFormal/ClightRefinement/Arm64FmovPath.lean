import KProgFormal.ClightRefinement.Arm64FmovVectorWrite
import KProgFormal.ClightRefinement.Arm64FmovVectorStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Path

private theorem pointer_offsets : ∀ high, Arm64Producer.vectorLoopSourceOffset high 3 =
    CC.Integers.Ptrofs.repr (if high then 56 else 48) := by decide +kernel

/-- Compose the original reads, numeric body, destination helper and both
actual vector assignments. Allocation-derived permissions provide every
successful store, preserving genuine producer storage and all other locals. -/
theorem execute {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (writable : Arm64VectorWritable.Writable old.vectors before) (i : Fin 31)
    (oldLow value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (reader : e.get Arm64Program._kprog_arm64_program_read = none)
    (destination : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (oldVector : CC.Mem.load .Mint64 before old.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ after le' count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.branch k e le before)
      (.State Arm64Nop.handler .Sskip k e le' after) ∧
      VectorMemory.Effect before after old.vectors.block value ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      ∀ id ∈ ReadOperands.inputs, le'.get id = le.get id := by
  obtain ⟨prefixCount,prefixTemps,prefixRun,result,indexValue,prefixKept⟩ :=
    StoreEntry.execute old i oldLow value e le k reader destination entryRead index source aux oldVector word tag
  have prefixEntry := (prefixKept _ (by decide +kernel)).trans entryRead
  have prefixAux := (prefixKept _ (by decide +kernel)).trans aux
  obtain ⟨after,effect,afterWritable⟩ := VectorMemory.write old.vectors writable value
  have separate := VectorStorage.separate old.vectors _ _ _ entry.binding (by decide +kernel)
  have low : CC.Mem.loadv CC.Mptr before (.Vptr entry.block (CC.Integers.Ptrofs.repr 120)) =
      some (.Vptr old.vectors.block (CC.Integers.Ptrofs.repr 48)) := by
    have slot := old.vectorPointers false 3
    rw [pointer_offsets] at slot
    exact slot
  have high : CC.Mem.loadv CC.Mptr before (.Vptr entry.block (CC.Integers.Ptrofs.repr 376)) =
      some (.Vptr old.vectors.block (CC.Integers.Ptrofs.repr 56)) := by
    have slot := old.vectorPointers true 3
    rw [pointer_offsets] at slot
    exact slot
  obtain ⟨storeCount,storeRun⟩ := VectorWrite.execute e prefixTemps before after k
    entry.block old.vectors.block value prefixEntry indexValue prefixAux result low high separate effect
  refine ⟨after,VectorWrite.temps prefixTemps old.vectors.block value,prefixCount+storeCount,
    prefixRun.trans storeRun,effect,afterWritable,?_⟩
  intro id inside
  have included : id ∈ Numeric.retained ++ [Arm64Program.___a64_fmov_result] := by
    simp only [ReadOperands.inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
    rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals decide +kernel
  exact (VectorWrite.retained _ _ _ id included).trans (prefixKept id inside)

end KProgFormal.ClightRefinement.Arm64Fmov.Path
