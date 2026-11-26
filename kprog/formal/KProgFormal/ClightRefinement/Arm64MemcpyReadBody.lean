import KProgFormal.ClightRefinement.Arm64MemcpyReadPrefix
import KProgFormal.ClightRefinement.Arm64MemcpyReadCase
import KProgFormal.ClightRefinement.Arm64MemcpyReadReturnSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadBody

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

def temps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (flag : CC.Block) (flagValue : BitVec 8) (abi stack : CC.Block) (byte : BitVec 8) (i : Fin 16) : CC.TempEnv :=
  Arm64MemcpyReadReturnSource.temps (Arm64MemcpyReadCase.temps
    (Arm64MemcpyReadPrefix.temps le storage flag flagValue abi) i stack storage.sp.block byte) (byte.setWidth 64)

/-- Execute the original seven-argument reader through its actual13-local
entry, every reached control and load, and original result/loop exits to its
true Sreturn. The typed flag observation remains at its actual input heap. -/
theorem execute {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values (Arm64MemcpyReadSource.allocation before).2)
    (k : CC.Cont) (i : Fin 16) (flag : CC.Block) (flagValue : BitVec 8)
    (flagHeader : CC.Mem.load CC.Mptr (Arm64MemcpyReadSource.allocation before).2 entry.block 696 = some (.Vptr flag 0))
    (flagByte : CC.Mem.load .Mint8unsigned (Arm64MemcpyReadSource.allocation before).2 flag 0 = some (.Vint (flagValue.setWidth 32))) :
    CC.Star (CC.Step2 world)
      (.Callstate (.Internal reader) (Arm64MemcpyReadCall.arguments entry.block (BitVec.ofNat 64 i.val)) k before) CC.E0
      (.State reader Arm64MemcpyReadSource.result k (Arm64MemcpyReadSource.allocation before).1
        (temps (Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block (BitVec.ofNat 64 i.val))
          (BitVec.ofNat 64 i.val)) packet.storage flag flagValue abi.block base.stack.block byte i)
        (Arm64MemcpyReadSource.allocation before).2) := by
  let offsetLe := Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block (BitVec.ofNat 64 i.val))
    (BitVec.ofNat 64 i.val)
  let reached := Arm64MemcpyReadPrefix.temps offsetLe packet.storage flag flagValue abi.block
  let originalCont := CC.Cont.Kseq Arm64MemcpyReadContext.result (Arm64MemcpyReadSource.outerCont k)
  obtain ⟨prefixRun,inputs,raw⟩ := Arm64MemcpyReadPrefix.original packet k (BitVec.ofNat 64 i.val) flag flagValue flagHeader flagByte
  have caseRun := Arm64MemcpyReadCase.execute packet (Arm64MemcpyReadSource.allocation before).1 reached originalCont i
    inputs.entryRead raw inputs.offsetRead inputs.width
  have resultRun := Arm64MemcpyReadReturnSource.execute (Arm64MemcpyReadSource.allocation before).1
    (Arm64MemcpyReadCase.temps reached i base.stack.block packet.storage.sp.block byte)
    (Arm64MemcpyReadSource.allocation before).2 k (byte.setWidth 64)
    (Arm64MemcpyReadCase.value_read reached i base.stack.block packet.storage.sp.block byte)
  simpa only [temps,reached,offsetLe,CC.E0,CC.Eapp,List.nil_append] using
    star_trans prefixRun.sound (star_trans caseRun resultRun.sound)

theorem result_read {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (flag : CC.Block) (flagValue : BitVec 8) (abi stack : CC.Block) (byte : BitVec 8) (i : Fin 16) :
    (temps le storage flag flagValue abi stack byte i).get Arm64Program._result = some (.Vlong (byte.setWidth 64)) :=
  CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpyReadBody
