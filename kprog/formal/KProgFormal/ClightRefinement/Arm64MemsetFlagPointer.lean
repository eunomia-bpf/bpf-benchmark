import KProgFormal.ClightRefinement.Arm64MemsetFlagComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetFlagPointer

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetPointerContinuation (Effect)
open Arm64MemsetPointerState (header tail flag vector_load)

private theorem register_position : ∀ j : Fin 18, 0 < j.val →
    (Arm64MemsetClobberRegisters.declaration j).reg ≠ 0 ∧
    (Arm64MemsetClobberRegisters.declaration j).reg ≠ 1 := by decide +kernel

section Effect
variable {initial beforeMem middle finalMem : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial beforeMem entry} (effect : Effect old middle finalMem)
include effect

/-- The original two pointer calls update R0/R1 with their actual stores.
All same current source bytes and earlier real provider values remain. -/
def transport {seed : CC.Mem} {base : Arm64MemsetHeaderView.View initial seed entry}
    {abi : TailLocal initial 6} {byte : BitVec 8} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64ClobberResult.Packet base abi byte (-32#64) 0 gprs flags values cell flagValue beforeMem)
    (actual : old = prior.memory.storage) :
    Arm64MemsetPointerState.Packet base abi byte gprs flags values finalMem := by
  subst old
  let ready := prior.memory
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
    flags := fun j => (flag effect j).trans (prior.flagWords j)
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
    have offset : ((Arm64MemsetStoreExecution.index j).val : Int) = 64+(j.val : Int) := by
      change ((64+j.val : Nat) : Int) = _
      omega
    exact kept.trans (by simpa only [offset] using ready.source j)
  · intro j positive
    have distinct := register_position j positive
    simpa only [distinct.1,distinct.2,ite_false] using
      (effect.gpr (Arm64MemsetClobberRegisters.declaration j).reg).trans
        (by simpa only [distinct.1,distinct.2,ite_false] using prior.registers j)
  · intro j
    change CC.Mem.load .Mint64 finalMem ready.storage.vectors.block (Arm64MemsetClobberVectors.offset j) = _
    exact (vector_load effect .Mint64 (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)


end Effect

/-- The same real memset output runs both original pointer calls and retains
its initialized flag alongside the actual new input packet for the next MOV. -/
theorem execute {initial seed beforeMem : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64ClobberResult.Packet base abi byte (-32#64) 0 gprs flags values cell flagValue beforeMem)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ middle finalMem, ∃ effect : Effect prior.memory.storage middle finalMem,
      ∃ _current : Arm64MemsetPointerState.Packet base abi byte gprs flags values finalMem,
        InternalRun world 114
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemsetProgramCaller.next k
            (Arm64ProgramEntryAllocation.allocation initial).1 le beforeMem)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
            (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) ∧
        Arm64MemcpyReadCurrent.Flag entry cell flagValue finalMem := by
  obtain ⟨middle,finalMem,effect,run⟩ := Arm64MemsetPointerContinuation.execute prior.memory.storage le k
  exact ⟨middle,finalMem,effect,transport effect prior rfl,run,
    prior.flag.tail_frame ⟨header effect,tail effect⟩⟩

end KProgFormal.ClightRefinement.Arm64MemsetFlagPointer
