import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkFrame
open Arm64Producer
open Arm64ProducerRegisterStorage

private theorem header_other : Arm64Entry._entry ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem table_other : ∀ tags, tableName tags ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem cell_other : ∀ tags (r : Fin 31), tableCellName tags r ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem sp_other : headerSourceName 5 ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem vector_other : Arm64Entry.___a64_vectors ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem tail_other : ∀ j : Fin 9, tailLocalName j ≠ Arm64Entry.___a64_lr := by decide +kernel
private theorem flags_other : ∀ j : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex j) ≠ Arm64Entry.___a64_lr := by decide +kernel

section Effect
variable {initial before after : CC.Mem} {lr : HeaderSourceLocal initial 4}
    (effect : Arm64ProgramEntryLinkCall.Effect lr before after)
include effect

/-- The original allocated LR cell is separate from header/table/SP/flag/vector
storage. Its actual write transports the SAME live storage and permissions. -/
def storage {entry : HeaderLocal initial} (prior : Storage initial before entry) : Storage initial after entry := by
  have keepHeader := effect.local_load _ _ _ entry.binding header_other
  refine {prior with
    roots := fun tags => (keepHeader CC.Mptr _).trans (prior.roots tags)
    slots := fun tags i => (effect.local_load _ _ _ (prior.tables tags).binding (table_other tags) CC.Mptr _).trans (prior.slots tags i)
    writable := ?_
    spPointer := (keepHeader CC.Mptr _).trans prior.spPointer
    spRead := (effect.local_load _ _ _ prior.sp.binding sp_other .Mint64 _).trans prior.spRead
    flagPointers := fun i => (keepHeader CC.Mptr _).trans (prior.flagPointers i)
    flagWritable := fun i => (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans (prior.flagWritable i)
    vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans prior.vectorWritable
    vectorPointers := fun high i => (keepHeader CC.Mptr _).trans (prior.vectorPointers high i)}
  intro tags i
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans (prior.writable tags i)

/-- Same original header/tail blocks and every actual source/copied byte. -/
theorem tailFrame (entry : HeaderLocal initial) : Arm64ProducerTailFrame.Frame initial entry before after :=
  ⟨fun chunk ofs => effect.local_load _ _ _ entry.binding header_other chunk ofs,
   fun i cell chunk ofs => effect.local_load _ _ _ cell.binding (tail_other i) chunk ofs⟩

theorem gpr {entry : HeaderLocal initial} (prior : Storage initial before entry) (r : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) r.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) r.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage effect prior) r,Arm64RegisterWrite.storage_gpr prior r]
  change (do
    let word ← CC.Mem.load .Mint64 after ((prior.tables false).cellBlock r) 0
    let tag ← CC.Mem.load .Mint8unsigned after ((prior.tables true).cellBlock r) 0
    pure (word,tag)) = _
  rw [effect.local_load _ _ _ ((prior.tables false).cellBinding r) (cell_other false r) .Mint64 0,
      effect.local_load _ _ _ ((prior.tables true).cellBinding r) (cell_other true r) .Mint8unsigned 0]

theorem flag {entry : HeaderLocal initial} (prior : Storage initial before entry) (i : Fin 4) :
    Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field i) =
      Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field i) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag (storage effect prior) i,Arm64RegisterWrite.storage_flag prior i]
  exact effect.local_load _ _ _ (prior.flags i).binding (flags_other i) .Mint8unsigned 0

/-- Keep the entire real memory packet through the LR write. This changes the
actual LR contents while retaining its other original scalar/byte resources. -/
def memory {seed : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} (prior : Arm64ClobberMemoryState.Packet base abi byte rawR0 n before) :
    Arm64ClobberMemoryState.Packet base abi byte rawR0 n after := by
  let tail := tailFrame effect entry
  refine {
    view := Arm64MemsetHeaderView.of_frame prior.view tail
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources tail.header
      (fun block _ => congrArg (CC.PMap.get block) effect.access)
    storage := storage effect prior.storage
    spAtBase := prior.spAtBase
    r0 := (gpr effect prior.storage (0 : Fin 31)).trans prior.r0
    abiHeader := (tail.header CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail.tail 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := tail.tail 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- The SAME reached packet preserves its updated CMP flag map, all actual
GPR/tag/vector observations and initialized source flag through the LR store. -/
def packet {seed : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before) :
    Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue after where
  memory := memory effect prior.memory
  registers := fun i => (gpr effect prior.memory.storage (Arm64MemsetClobberRegisters.declaration i).reg).trans (prior.registers i)
  flagWords := fun i => (flag effect prior.memory.storage i).trans (prior.flagWords i)
  vectors := fun i => (effect.local_load _ _ _ prior.memory.storage.vectors.binding vector_other .Mint64
    (Arm64MemsetClobberVectors.offset i)).trans (prior.vectors i)
  flag := prior.flag.tail_frame (tailFrame effect entry)

end Effect
end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkFrame
