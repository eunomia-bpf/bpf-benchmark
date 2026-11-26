import KProgFormal.ClightRefinement.X86ProducerSubFlagStorage

namespace KProgFormal.ClightRefinement.X86ProducerScalarSeparation
open X86ProducerLayout (ge)

private theorem names : ∀ i j : Fin 8, i ≠ j →
    X86ProducerHeaderSource.localName (X86ProducerScalarSource.row i) ≠
      X86ProducerHeaderSource.localName (X86ProducerScalarSource.row j) := by decide +kernel

/-- Distinct original scalar objects occupy distinct blocks in the actual
producer allocation. Later stores use this derived fact to protect all
previous flag writes; no new non-aliasing premise is introduced. -/
theorem separate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer)
    (i j : Fin 8) (different : i ≠ j) : (ready.scalars i).block ≠ (ready.scalars j).block := by
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before X86ProducerHeaderSource.producer.fn_vars
      (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1
      (X86ProducerCacheAllocation.allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (X86ProducerCacheAllocation.allocation ge.genv_cenv before)).symm
  exact (allocated_local_storage allocated).2 _ _ _ _ (ready.scalars i).binding (ready.scalars j).binding (names i j different)

end KProgFormal.ClightRefinement.X86ProducerScalarSeparation
