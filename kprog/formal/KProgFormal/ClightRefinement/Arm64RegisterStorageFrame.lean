import KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

/-- Carry the SAME producer storage through a frame preserving every old
block. Successful imported loads/permissions prove their old-block bounds. -/
def Storage.frame {m before after : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Storage m before entry) (frame : FrameBelow before.nextblock before after) :
    Storage m after entry := by
  have keep {chunk : CC.Chunk} {block : CC.Block} {offset : Int} {value : CC.Val}
      (read : CC.Mem.load chunk before block offset = some value) :
      CC.Mem.load chunk after block offset = some value :=
    (frame.load chunk block offset (Arm64ProducerEntryView.load_live chunk before block offset value read)).trans read
  have keepWritable (chunk : CC.Chunk) (block : CC.Block) (positive : (0 : Int) < CC.sizeChunk chunk)
      (writable : CC.Mem.validAccess before chunk block 0 .Writable = true) :
      CC.Mem.validAccess after chunk block 0 .Writable = true := by
    have valid := writable
    simp only [CC.Mem.validAccess,Bool.and_eq_true] at valid
    have range : CC.Mem.rangePerm before block 0 (0 + CC.sizeChunk chunk) .Cur .Writable = true := valid.1
    have below := CC.Mem.perm_valid_block before block 0 .Cur .Writable
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ range 0 (Int.le_refl _) (by simpa only [Int.zero_add] using positive))
    exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := chunk) (b := block) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm,(frame _ below).2])).trans writable
  have vectorOwned := CC.Mem.perm_valid_block before storage.vectors.block 0 .Cur .Writable
    (CC.Mem.rangePerm_perm before storage.vectors.block 0 512 .Cur .Writable
      storage.vectorWritable 0 (by decide) (by decide))
  refine {storage with
    vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun offset => by simp only [CC.Mem.perm,(frame _ vectorOwned).2])).trans storage.vectorWritable
    roots := fun tags => keep (storage.roots tags)
    slots := fun tags i => keep (storage.slots tags i)
    writable := fun tags i => keepWritable (cellChunk tags) ((storage.tables tags).cellBlock i)
      (by cases tags <;> decide) (storage.writable tags i)
    spPointer := keep storage.spPointer
    spRead := keep storage.spRead
    flagPointers := fun i => keep (storage.flagPointers i)
    flagWritable := fun i => keepWritable .Mint8unsigned (storage.flags i).block (by decide) (storage.flagWritable i)
    vectorPointers := fun high i => keep (storage.vectorPointers high i)}

end KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage
