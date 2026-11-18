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
  refine { storage with
    roots := fun tags => keep (storage.roots tags)
    slots := fun tags i => keep (storage.slots tags i)
    writable := ?_
    spPointer := keep storage.spPointer
    spRead := keep storage.spRead
    flagPointers := fun i => keep (storage.flagPointers i)
    vectorPointers := fun high i => keep (storage.vectorPointers high i) }
  intro tags i
  have valid := storage.writable tags i
  simp only [CC.Mem.validAccess, Bool.and_eq_true] at valid
  have range : CC.Mem.rangePerm before ((storage.tables tags).cellBlock i) 0
      (0 + CC.sizeChunk (cellChunk tags)) .Cur .Writable = true :=
    valid.1
  have positive : (0 : Int) < CC.sizeChunk (cellChunk tags) := by cases tags <;> decide
  have below := CC.Mem.perm_valid_block before ((storage.tables tags).cellBlock i) 0 .Cur .Writable
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ range 0 (Int.le_refl _) (by simpa only [Int.zero_add] using positive))
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock i) (ofs := 0) (p := .Writable)
    (fun offset => by simp only [CC.Mem.perm, (frame _ below).2])).trans (storage.writable tags i)

end KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage
