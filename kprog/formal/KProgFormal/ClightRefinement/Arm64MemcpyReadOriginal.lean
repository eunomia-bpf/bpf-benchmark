import KProgFormal.ClightRefinement.Arm64MemcpyReadBody
import KProgFormal.ClightRefinement.Arm64MemcpyReadReturn

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadOriginal

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

/-- The complete original reader call returns the byte from the same
current packet through the genuine value cast, actual thirteen-local free
and imported callCont, retaining its full old-caller frame. -/
theorem execute {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values (Arm64MemcpyReadSource.allocation before).2)
    (k : CC.Cont) (i : Fin 16) (flag : CC.Block) (flagValue : BitVec 8)
    (flagHeader : CC.Mem.load CC.Mptr (Arm64MemcpyReadSource.allocation before).2 entry.block 696 = some (.Vptr flag 0))
    (flagByte : CC.Mem.load .Mint8unsigned (Arm64MemcpyReadSource.allocation before).2 flag 0 = some (.Vint (flagValue.setWidth 32))) :
    ∃ after, Arm64MemcpyReadReturn.FreeResult before (Arm64MemcpyReadSource.allocation before).2 after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal reader) (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val)) k before) CC.E0
        (.Returnstate (.Vlong (byte.setWidth 64)) (CC.callCont k) after) ∧
      FrameBelow before.nextblock before after := by
  let offsetLe := Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block (BitVec.ofNat 64 i.val))
    (BitVec.ofNat 64 i.val)
  let finalLe := Arm64MemcpyReadBody.temps offsetLe packet.storage flag flagValue abi.block base.stack.block byte i
  have bodyRun := Arm64MemcpyReadBody.execute packet k i flag flagValue flagHeader flagByte
  obtain ⟨after,freed,returnRun⟩ := Arm64MemcpyReadReturn.exit before (Arm64MemcpyReadSource.allocation before).2
    finalLe k (byte.setWidth 64) rfl
    (Arm64MemcpyReadBody.result_read offsetLe packet.storage flag flagValue abi.block base.stack.block byte i)
  refine ⟨after,freed,?_,Arm64MemcpyReadReturn.original_frame before after freed⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans bodyRun returnRun.sound

end KProgFormal.ClightRefinement.Arm64MemcpyReadOriginal
