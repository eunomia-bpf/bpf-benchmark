import KProgFormal.ClightRefinement.Arm64MemsetPointerContinuation

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetPointerState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPointerContinuation (Effect)

private theorem tail_name : ∀ tags (i : Fin 31) (j : Fin 9),
    tableCellName tags i ≠ tailLocalName j := by decide +kernel
private theorem vector_name : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem register_position : ∀ j : Fin 18, 0 < j.val →
    (Arm64MemsetClobberRegisters.declaration j).reg ≠ 0 ∧
    (Arm64MemsetClobberRegisters.declaration j).reg ≠ 1 := by decide +kernel

/-- The reached memcpy-input continuation carries its actual updated R0/R1,
while retaining every unmodified provider value and original memory result. -/
structure Packet {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (gprValues : Fin 18 → BitVec 64) (flagValues : Fin 4 → BitVec 64) (vectorValues : Fin 64 → BitVec 64)
    (m : CC.Mem) where
  view : Arm64MemsetHeaderView.View initial m entry
  stackSame : view.stack.block = base.stack.block
  tagsSame : view.tags.block = base.tags.block
  resources : Arm64ProgramEntryResources.Resources initial m entry
  storage : Storage initial m entry
  spAtBase : storage.spValue = (-32#64)
  r0 : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
    some (.Vlong (-16#64),.Vint ((4#8).setWidth 32))
  r1 : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 1 =
    some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))
  abiHeader : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi.block 0)
  abiKind : CC.Mem.load .Mint8unsigned m abi.block 0 = some (.Vint 2)
  tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m base.tags.block (j.val : Int) = some (.Vint 0)
  written : ∀ j : Fin 16, CC.Mem.load .Mint8unsigned m base.stack.block
    ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))
  registers : ∀ j : Fin 18, 0 < j.val →
    Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (Arm64MemsetClobberRegisters.declaration j).reg.val =
      some (.Vlong (gprValues j),.Vint 0)
  flags : ∀ j : Fin 4, Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
    (Arm64MemsetClobberFlags.field j) = some (.Vint (flagWord (flagValues j)))
  vectors : ∀ j : Fin 64, CC.Mem.load .Mint64 m storage.vectors.block
    (Arm64MemsetClobberVectors.offset j) = some (.Vlong (vectorValues j))

section Effects
variable {initial beforeMem middle finalMem : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial beforeMem entry} (effect : Effect old middle finalMem)
include effect

theorem header (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem entry.block ofs = CC.Mem.load chunk beforeMem entry.block ofs :=
  effect.local_load _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) chunk ofs

theorem tail (j : Fin 9) (cell : TailLocal initial j) (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem cell.block ofs = CC.Mem.load chunk beforeMem cell.block ofs :=
  effect.local_load _ _ _ cell.binding (tail_name false 0 j) (tail_name true 0 j)
    (tail_name false 1 j) (tail_name true 1 j) chunk ofs

theorem flag (j : Fin 4) :
    Arm64EntryMemory.borrowed finalMem.nextblock .Mint8unsigned finalMem (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) =
    Arm64EntryMemory.borrowed beforeMem.nextblock .Mint8unsigned beforeMem (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) := by
  unfold Arm64MemsetClobberFlags.field
  rw [effect.second.nextblock,effect.second.flag j,effect.first.nextblock,effect.first.flag j]

theorem vector_load (chunk : CC.Chunk) (ofs : Int) :
    CC.Mem.load chunk finalMem old.vectors.block ofs = CC.Mem.load chunk beforeMem old.vectors.block ofs :=
  effect.local_load _ _ _ old.vectors.binding (vector_name false 0) (vector_name true 0)
    (vector_name false 1) (vector_name true 1) chunk ofs

/-- Transport the actual completed memset result through both pointer calls;
its R0 observation is replaced by the real new value, and R1 by the next. -/
def transport {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {outerLe helperLe : CC.TempEnv}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetClobberVectorsComplete.Invariant base abi byte outerLe gprs flags 64 values beforeMem helperLe)
    (actual : old = prior.flagsPacket.registers.ready.storage) :
    Packet base abi byte gprs flags values finalMem := by
  subst old
  let ready := prior.flagsPacket.registers.ready
  have headerKept := header effect
  let currentView : Arm64MemsetHeaderView.View initial finalMem entry := {
    ready.view with
      stackPointer := (headerKept CC.Mptr 608).trans ready.view.stackPointer
      tagPointer := (headerKept CC.Mptr 648).trans ready.view.tagPointer
      capacity := (headerKept .Mint32 656).trans ready.view.capacity
      bias := (headerKept .Mint64 672).trans ready.view.bias }
  refine {
    view := currentView
    stackSame := ready.stackSame
    tagsSame := ready.tagsSame
    resources := Arm64MemsetIterationResources.resources ready.resources headerKept
      (fun block _ => congrArg (CC.PMap.get block) effect.access)
    storage := effect.storage
    spAtBase := ready.spAtBase
    r0 := ?_
    r1 := ?_
    abiHeader := (headerKept CC.Mptr 704).trans ready.abiHeader
    abiKind := (tail effect 6 abi .Mint8unsigned 0).trans ready.abiKind
    tagBytes := ?_
    written := ?_
    registers := ?_
    flags := fun j => (flag effect j).trans (prior.flagsPacket.written j j.isLt)
    vectors := ?_ }
  · simpa +decide using effect.gpr 0
  · simpa +decide using effect.gpr 1
  · intro j
    have kept := tail effect 2 ⟨ready.view.tags.block,ready.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned finalMem ready.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned beforeMem ready.view.tags.block (j.val : Int) at kept
    rw [ready.tagsSame] at kept
    exact kept.trans (ready.tagBytes j)
  · intro j
    have kept := tail effect 0 ready.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [ready.stackSame] at kept
    exact kept.trans (ready.written j j.isLt)
  · intro j positive
    have distinct := register_position j positive
    simpa only [distinct.1,distinct.2,ite_false] using
      (effect.gpr (Arm64MemsetClobberRegisters.declaration j).reg).trans
        (by simpa only [distinct.1,distinct.2,ite_false] using prior.flagsPacket.registers.written j j.isLt)
  · intro j
    change CC.Mem.load .Mint64 finalMem ready.storage.vectors.block (Arm64MemsetClobberVectors.offset j) = _
    exact (vector_load effect .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.written j j.isLt)

end Effects

/-- The complete same-source packet executes both genuine following sites
and reaches the fifteenth MOV with its current resources and all retained data. -/
theorem execute {initial seed beforeMem : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe helperLe : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetClobberVectorsComplete.Invariant base abi byte outerLe gprs flags 64 values beforeMem helperLe)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ middle finalMem, ∃ effect : Effect prior.flagsPacket.registers.ready.storage middle finalMem,
      ∃ _current : Packet base abi byte gprs flags values finalMem,
        InternalRun world 114
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemsetProgramCaller.next k
            (Arm64ProgramEntryAllocation.allocation initial).1 le beforeMem)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
            (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) := by
  obtain ⟨middle,finalMem,effect,run⟩ := Arm64MemsetPointerContinuation.execute prior.flagsPacket.registers.ready.storage le k
  exact ⟨middle,finalMem,effect,transport effect prior rfl,run⟩

end KProgFormal.ClightRefinement.Arm64MemsetPointerState
