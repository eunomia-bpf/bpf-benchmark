import KProgFormal.ClightRefinement.Arm64MemcpyReadReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadFrame

open Arm64ProgramEntryAllocation (world)

/-- The exact older-block frame preserves the actual complete iteration
packet, the memcpy caller's eight live local ranges and already copied bytes.
The reader's own thirteen fresh scratch ranges may be allocated or freed. -/
def transport {initial seed calleeBefore before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {n : Nat} {le : CC.TempEnv} (frontier : CC.Block)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n before le) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after le := by
  refine {
    packet := Arm64MemcpyLoopState.packet_frame frontier producerBound frame prior.packet
    callee := ?_
    entryRead := prior.entryRead
    length := prior.length
    counter := prior.counter
    sourceTag := prior.sourceTag
    copied := ?_ }
  · intro id value binding
    have allocated := (allocated_local_storage (Arm64MemcpySource.allocated calleeBefore)).1 id value binding
    have below : value.1.toNat < frontier.toNat := Nat.lt_of_lt_of_le allocated.2.1 callerBound
    have access := (frame value.1 below).2
    exact (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,access])).trans (prior.callee id value binding)
  · intro j limit
    have kept := Arm64MemsetFreeState.tail frontier producerBound frame 0 prior.packet.view.stack
      .Mint8unsigned (80+(j.val : Int))
    rw [prior.packet.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- The actual reader allocation retains the original current memcpy
packet and its eight local ranges below the caller's real frontier. -/
def at_entry {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {n : Nat} {le : CC.TempEnv}
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n before le) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n
      (Arm64MemcpyReadSource.allocation before).2 le :=
  transport before.nextblock producerBound callerBound (Arm64MemcpyReadSource.entry_frame before) prior

/-- On the actual selected same-heap read path, original allocation and all
thirteen local frees retain the complete current memcpy iteration state. -/
def after_return {initial seed calleeBefore before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {n : Nat} {le : CC.TempEnv}
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (freed : Arm64MemcpyReadReturn.FreeResult before (Arm64MemcpyReadSource.allocation before).2 after)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n before le) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after le :=
  transport before.nextblock producerBound callerBound (Arm64MemcpyReadReturn.original_frame before after freed) prior

end KProgFormal.ClightRefinement.Arm64MemcpyReadFrame
