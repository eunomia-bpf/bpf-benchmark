import KProgFormal.ClightRefinement.X86ProducerSubResult

namespace KProgFormal.ClightRefinement.X86ProducerSubScalarResources
open X86ProducerLayout (ge)
open X86ProducerHeaderLocals (Local)
open X86ProducerSubBody (allocation)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The SAME real producer-owned object's two permission maps survive all
PUSH stores/freeing and actual SUB allocation. No whole-map equality after
new local allocation is assumed. -/
theorem access (complete : X86ProducerPushComplete.Result cache)
    {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) :
    CC.PMap.get object.block (allocation complete.after).2.access =
      CC.PMap.get object.block (X86ProducerCacheAllocation.allocation ge.genv_cenv before).2.access := by
  have old : object.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact object.owned
  have subFrame := ((X86ProducerSubBody.entry_frame complete.after).2 object.block
    (X86ProducerSubResources.old_local complete object)).2
  have freed := (complete.old_frame object.block old).2
  have pushFrame := ((X86ProducerPushBody.entry_frame ready.after).2 object.block old).2
  have stores : CC.PMap.get object.block cache.after.access = CC.PMap.get object.block ready.after.access := by
    rw [cache.access,metadata.access,rsp.access]
    exact pushFrame
  exact subFrame.trans (freed.trans (stores.trans (congrArg (CC.PMap.get object.block) ready.access)))

/-- All declared original scalar-object range rights are current on the
actual SUB heap, for any offset and permission kind. -/
theorem rights (complete : X86ProducerPushComplete.Result cache)
    {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) :
    CC.Mem.rangePerm (allocation complete.after).2 object.block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable = true := by
  have maps := access complete object
  have same : CC.Mem.rangePerm (allocation complete.after).2 object.block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable =
      CC.Mem.rangePerm (X86ProducerCacheAllocation.allocation ge.genv_cenv before).2 object.block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable := by
    apply CC.Mem.rangePerm_congr
    intro offset
    simp only [CC.Mem.perm,maps]
  exact same.trans object.range

/-- Six actual flag bytes and both XMM words retain the SAME initialized
provider values through complete PUSH and original SUB allocation/setup. -/
theorem scalars (complete : X86ProducerPushComplete.Result cache) (i : Fin 8) :
    CC.Mem.load (X86ProducerScalarSource.chunk i) (allocation complete.after).2 (ready.scalars i).block 0 =
      some (X86ProducerScalarValue.value i (ready.scalarValues i)) :=
  ((X86ProducerSubBody.entry_frame complete.after).2.load _ _ _
    (X86ProducerSubResources.old_local complete (ready.scalars i))).trans (X86ProducerPushLocalFrame.scalars complete i)

/-- All actual scalar header pointers are derived from original initialized
header reads and allocator identity, not a new post-store pointer premise. -/
theorem headers (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) (i : Fin 8) :
    CC.Mem.load CC.Mptr (allocation complete.after).2 ready.entry.block (8*((X86ProducerScalarSource.row i).val:Int)) =
      some (.Vptr (ready.scalars i).block 0) := by
  have current := X86ProducerSubResources.headers complete header (X86ProducerScalarSource.row i)
  rw [X86ProducerHeaderReady.source_block ready (X86ProducerScalarSource.row i) (ready.scalars i)] at current
  exact current

end KProgFormal.ClightRefinement.X86ProducerSubScalarResources
