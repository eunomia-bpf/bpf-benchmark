import KProgFormal.ClightRefinement.Arm64FmovNumeric

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.StoreEntry

/-- The original scalar reader, mode0 numeric body and real destination
helper reach the two actual vector stores on the unchanged heap. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (i : Fin 31)
    (oldLow value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (reader : e.get Arm64Program._kprog_arm64_program_read = none)
    (destination : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (oldVector : CC.Mem.load .Mint64 m storage.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.branch k e le m)
      (.State Arm64Nop.handler DestinationSite.vectorStores k e le' m) ∧
      le'.get Arm64Program.___a64_fmov_result = some (.Vlong value) ∧
      le'.get Arm64Program.___a64_fmov_index = some (.Vint (3#32)) ∧
      ∀ id ∈ ReadOperands.inputs, le'.get id = le.get id := by
  obtain ⟨readCount,readRun⟩ := ReadOperands.from_storage storage i oldLow value e le k
    reader entryRead index source aux oldVector word tag
  let readTemps := ReadEntry.valueTemps le storage.vectors.block
    (Arm64Producer.vectorLoopSourceOffset false 3) oldLow value
  have ready := ReadOperands.ready le storage.vectors.block
    (Arm64Producer.vectorLoopSourceOffset false 3) oldLow value
  obtain ⟨numericCount,numericTemps,numericRun,result,numericKept⟩ :=
    Numeric.execute Arm64ProgramEntryLinked.ge e readTemps m k value ready.1.2.1 ready.1.1
  have auxRead : readTemps.get Arm64Program._aux = some (.Vint 0) :=
    (ready.2 _ (by decide +kernel)).trans aux
  have auxNumeric : numericTemps.get Arm64Program._aux = some (.Vint 0) :=
    (numericKept _ (by decide +kernel)).trans auxRead
  obtain ⟨destCount,destRun⟩ := DestinationSite.execute e numericTemps m k destination auxNumeric
  refine ⟨readCount + numericCount + destCount,DestinationSite.temps numericTemps,
    (readRun.trans numericRun).trans destRun,?_,?_,?_⟩
  · unfold DestinationSite.temps
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact result
  · unfold DestinationSite.temps
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact (numericKept _ (by decide +kernel)).trans ready.1.2.2.1
  · intro id inside
    have member : id ∈ Numeric.retained := by
      simp only [ReadOperands.inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
      rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
      all_goals decide +kernel
    have different : Arm64Program._t'2789 ≠ id := by
      intro same
      subst id
      exact (by decide +kernel : Arm64Program._t'2789 ∉ ReadOperands.inputs) inside
    unfold DestinationSite.temps
    rw [CC.PTree.gso _ _ _ _ different]
    exact (numericKept id member).trans (ready.2 id inside)

end KProgFormal.ClightRefinement.Arm64Fmov.StoreEntry
