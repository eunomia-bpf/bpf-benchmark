import KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
import KProgFormal.ClightRefinement.Arm64MemsetClobberVectorState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberVectorState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ClobberMemoryState (Packet Caller)

/-- The real vector-half store preserves the shared actual-R0 memory packet.
The advancing vector map records its selected provider word. -/
def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} (prior : Packet base abi byte rawR0 n before)
    {i : Fin 64} {value : BitVec 64}
    (effect : Arm64MemsetClobberVectors.Effect prior.storage i value after) :
    Packet base abi byte rawR0 n after := by
  refine {
    view := Arm64MemsetClobberVectorState.view effect prior.view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetClobberVectorState.resources effect prior.resources
    storage := Arm64MemsetClobberVectorState.storage effect
    spAtBase := prior.spAtBase
    r0 := (Arm64MemsetClobberVectorState.gpr effect 0).trans prior.r0
    abiHeader := (Arm64MemsetClobberVectorState.header effect CC.Mptr 704).trans prior.abiHeader
    abiKind := (Arm64MemsetClobberVectorState.tail effect 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := Arm64MemsetClobberVectorState.tail effect 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩
      .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := Arm64MemsetClobberVectorState.tail effect 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := Arm64MemsetClobberVectorState.tail effect 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- The same real vector effect preserves all eight saved memcpy-local Freeable
ranges and the initialized flag through the actual header/tail frame. -/
def caller_written {initial seed calleeBefore before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Caller base abi byte calleeBefore rawR0 n cell flagValue before outerLe)
    {i : Fin 64} {value : BitVec 64}
    (effect : Arm64MemsetClobberVectors.Effect prior.memory.storage i value after) :
    Caller base abi byte calleeBefore rawR0 n cell flagValue after outerLe where
  memory := written prior.memory effect
  callee := fun id result binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans (prior.callee id result binding)
  entryRead := prior.entryRead
  length := prior.length
  counter := prior.counter
  sourceTag := prior.sourceTag
  flag := prior.flag.tail_frame
    ⟨Arm64MemsetClobberVectorState.header effect,Arm64MemsetClobberVectorState.tail effect⟩

end KProgFormal.ClightRefinement.Arm64ClobberVectorState
