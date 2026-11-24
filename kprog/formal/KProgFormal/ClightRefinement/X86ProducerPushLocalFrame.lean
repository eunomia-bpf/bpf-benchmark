import KProgFormal.ClightRefinement.X86ProducerPushComplete

namespace KProgFormal.ClightRefinement.X86ProducerPushLocalFrame
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (localName)
open X86ProducerHeaderLocals (Local)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Every other actual allocated producer object retains all its typed
observations through genuine PUSH stores, body allocation and local free. -/
theorem loads (complete : X86ProducerPushComplete.Result cache)
    {name : CC.Ident} {type : CC.Ty} (object : Local ge.genv_cenv before name type)
    (different : name ≠ localName 0 ∧ name ≠ localName 1 ∧ name ≠ localName 12 ∧ name ≠ localName 13)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk complete.after object.block offset = CC.Mem.load chunk ready.after object.block offset := by
  have old : object.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact object.owned
  have gprs := X86ProducerGprStage.local_separate before object ready.gprs different.1
  have stack := X86ProducerGprStage.local_separate before object (ready.sources 1) different.2.1
  have tag := X86ProducerGprStage.local_separate before object (ready.sources 12) different.2.2.1
  have pointer := X86ProducerGprStage.local_separate before object (ready.sources 13) different.2.2.2
  exact (complete.old_frame.load _ _ _ old).trans
    ((CC.Mem.load_store_other cache.stored chunk object.block offset (.inl stack)).trans
      ((CC.Mem.load_store_other metadata.pointer_stored chunk object.block offset (.inl pointer)).trans
        ((CC.Mem.load_store_other metadata.tag_stored chunk object.block offset (.inl tag)).trans
          ((CC.Mem.load_store_other rsp.stored chunk object.block offset (.inl gprs)).trans
            ((X86ProducerPushBody.entry_frame ready.after).2.load _ _ _ old)))))

private theorem scalar_names : ∀ i : Fin 8,
    localName (X86ProducerScalarSource.row i) ≠ localName 0 ∧
    localName (X86ProducerScalarSource.row i) ≠ localName 1 ∧
    localName (X86ProducerScalarSource.row i) ≠ localName 12 ∧
    localName (X86ProducerScalarSource.row i) ≠ localName 13 := by decide +kernel

/-- All six real flag bytes and both real XMM words retain their actual
initialized observations; no native input/oracle relation is inferred. -/
theorem scalars (complete : X86ProducerPushComplete.Result cache) (i : Fin 8) :
    CC.Mem.load (X86ProducerScalarSource.chunk i) complete.after (ready.scalars i).block 0 =
      some (X86ProducerScalarValue.value i (ready.scalarValues i)) :=
  (loads complete (ready.scalars i) (scalar_names i) _ _).trans (ready.scalar_reads i)

end KProgFormal.ClightRefinement.X86ProducerPushLocalFrame
