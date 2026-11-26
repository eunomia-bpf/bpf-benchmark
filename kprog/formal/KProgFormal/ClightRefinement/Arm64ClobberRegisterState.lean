import KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberRegisterState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ClobberMemoryState (Packet Caller)
open Arm64MemsetClobberRegisters (declaration)

/-- The two real original GPR stores retain shared current memory with
the actual R0. Their selected register1..18 receives the real provider word
and tag0; its output belongs to the advancing register-value map. -/
def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} (prior : Packet base abi byte rawR0 n before)
    {i : Fin 18} {value : BitVec 64}
    (effect : Arm64MemsetClobberRegisterStores.Effect prior.storage i value after) :
    Packet base abi byte rawR0 n after := by
  have nonzero : (0 : Fin 31) ≠ (declaration i).reg := by
    intro same
    exact (Arm64MemsetClobberRegisters.register_nonzero i) (congrArg Fin.val same).symm
  refine {
    view := Arm64MemsetClobberRegisterState.view effect prior.view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetClobberRegisterState.resources effect prior.resources
    storage := Arm64MemsetClobberRegisterState.storage effect
    spAtBase := prior.spAtBase
    r0 := (Arm64MemsetClobberRegisterState.other effect 0 nonzero).trans prior.r0
    abiHeader := (Arm64MemsetClobberRegisterState.header effect CC.Mptr 704).trans prior.abiHeader
    abiKind := (Arm64MemsetClobberRegisterState.tail effect 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · intro j
    have kept := Arm64MemsetClobberRegisterState.tail effect 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩
      .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := Arm64MemsetClobberRegisterState.tail effect 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := Arm64MemsetClobberRegisterState.tail effect 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- The same actual two-store effect keeps all eight saved memcpy-local
Freeable ranges and transports its initialized flag by the original
header/tail frame, while the advancing helper records selected outputs. -/
def caller_written {initial seed calleeBefore before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Caller base abi byte calleeBefore rawR0 n cell flagValue before outerLe)
    {i : Fin 18} {value : BitVec 64}
    (effect : Arm64MemsetClobberRegisterStores.Effect prior.memory.storage i value after) :
    Caller base abi byte calleeBefore rawR0 n cell flagValue after outerLe where
  memory := written prior.memory effect
  callee := fun id result binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,effect.access])).trans (prior.callee id result binding)
  entryRead := prior.entryRead
  length := prior.length
  counter := prior.counter
  sourceTag := prior.sourceTag
  flag := prior.flag.tail_frame
    ⟨Arm64MemsetClobberRegisterState.header effect,Arm64MemsetClobberRegisterState.tail effect⟩

end KProgFormal.ClightRefinement.Arm64ClobberRegisterState
