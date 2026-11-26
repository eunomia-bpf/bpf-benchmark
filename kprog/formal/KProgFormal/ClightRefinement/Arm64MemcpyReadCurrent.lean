import KProgFormal.ClightRefinement.Arm64MemcpyReadFrame
import KProgFormal.ClightRefinement.Arm64MemcpyReadOriginal

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The real source flag, using its original declared cell and header field. -/
structure Flag {initial : CC.Mem} (entry : HeaderLocal initial) (cell : TailLocal initial 5)
    (value : BitVec 8) (m : CC.Mem) : Prop where
  header : CC.Mem.load CC.Mptr m entry.block 696 = some (.Vptr cell.block 0)
  byte : CC.Mem.load .Mint8unsigned m cell.block 0 = some (.Vint (value.setWidth 32))

/-- Actual older-block frames retain both the header pointer and its own
unsigned-byte cell, including the genuine reader allocation and free. -/
theorem Flag.frame {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {cell : TailLocal initial 5} {value : BitVec 8}
    (prior : Flag entry cell value before) (frontier : CC.Block)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (kept : FrameBelow frontier before after) : Flag entry cell value after :=
  ⟨(Arm64MemsetFreeState.header frontier bound kept CC.Mptr 696).trans prior.header,
   (Arm64MemsetFreeState.tail frontier bound kept 5 cell .Mint8unsigned 0).trans prior.byte⟩

/-- An existing real header/tail frame transports the initialized flag
through the original provider, setup, pointer and cache effects. -/
theorem Flag.tail_frame {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {cell : TailLocal initial 5} {value : BitVec 8}
    (prior : Flag entry cell value before)
    (kept : Arm64ProducerTailFrame.Frame initial entry before after) : Flag entry cell value after :=
  ⟨(kept.header CC.Mptr 696).trans prior.header,
   (kept.tail 5 cell .Mint8unsigned 0).trans prior.byte⟩

section Current
variable {initial seed calleeBefore before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv} {cell : TailLocal initial 5} {flagValue : BitVec 8}

/-- The actual current memcpy packet supplies the reader's allocated input.
Its complete original call returns the real source byte and preserves the
same eight caller-local rights and every copied destination observation. -/
theorem execute (i : Fin 16) (k : CC.Cont)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (flag : Flag entry cell flagValue before) :
    ∃ after, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after le,
      Arm64MemcpyReadReturn.FreeResult before (Arm64MemcpyReadSource.allocation before).2 after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64MemcpyReadCall.reader)
          (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val)) k before) CC.E0
        (.Returnstate (.Vlong (byte.setWidth 64)) (CC.callCont k) after) ∧
      FrameBelow before.nextblock before after ∧ Flag entry cell flagValue after ∧
      before.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  let allocated := Arm64MemcpyReadFrame.at_entry producerBound callerBound current
  have flagAtEntry := flag.frame before.nextblock producerBound (Arm64MemcpyReadSource.entry_frame before)
  obtain ⟨after,freed,run,frame⟩ := Arm64MemcpyReadOriginal.execute allocated.packet k i cell.block flagValue
    flagAtEntry.header flagAtEntry.byte
  let next := Arm64MemcpyReadFrame.after_return producerBound callerBound freed current
  have advanced : before.nextblock.toNat ≤ after.nextblock.toNat := by
    rw [freed.nextblock]
    exact (FrameBelow.allocVariables (Arm64MemcpyReadSource.allocated before)
      before.nextblock (Nat.le_refl _)).1
  exact ⟨after,next,freed,run,frame,flag.frame before.nextblock producerBound frame,
    advanced,Nat.le_trans producerBound advanced,Nat.le_trans callerBound advanced⟩

end Current
end KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent
