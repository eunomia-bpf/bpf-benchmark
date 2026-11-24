import KProgFormal.ClightRefinement.X86ProducerPushComplete

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheFrame

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Cache loads disjoint from the actual qword payload retain their original
initialized-source value through body allocation, RSP/metadata stores and
genuine local freeing. No content of untouched cache bytes is invented. -/
theorem outside (complete : X86ProducerPushComplete.Result cache)
    (chunk : CC.Chunk) (offset : Int) (disjoint : offset + CC.sizeChunk chunk ≤ 40 ∨ 48 ≤ offset) :
    CC.Mem.load chunk complete.after (ready.sources 1).block offset =
      CC.Mem.load chunk ready.after (ready.sources 1).block offset := by
  have old : (ready.sources 1).block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact (ready.sources 1).owned
  have separate : (ready.sources 1).block ≠ ready.gprs.block :=
    Ne.symm (X86ProducerGprStage.local_separate before ready.gprs (ready.sources 1) (by decide +kernel))
  exact (complete.old_frame.load _ _ _ old).trans
    ((cache.disjoint _ _ _ (.inr disjoint)).trans ((metadata.cache _ _).trans
      ((rsp.outside _ _ _ separate).trans ((X86ProducerPushBody.entry_frame ready.after).2.load _ _ _ old))))

/-- All forty cache bytes outside the actual selected qword retain their
original observations. This statement does not assume initialized zeros. -/
theorem lower_bytes (complete : X86ProducerPushComplete.Result cache) (byte : Fin 40) :
    CC.Mem.load .Mint8unsigned complete.after (ready.sources 1).block byte.val =
      CC.Mem.load .Mint8unsigned ready.after (ready.sources 1).block byte.val := by
  apply outside complete
  left
  change (byte.val : Int) + 1 ≤ 40
  omega

end KProgFormal.ClightRefinement.X86ProducerPushCacheFrame
