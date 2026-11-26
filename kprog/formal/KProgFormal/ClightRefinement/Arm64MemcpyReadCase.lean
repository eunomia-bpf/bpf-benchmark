import KProgFormal.ClightRefinement.Arm64MemcpyReadSwitchExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadCase

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private def selectedTemps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  Arm64MemcpyReadByteSetup.temps (Arm64MemcpyReadIndex.temps le (-32#64) (BitVec.ofNat 64 i.val))
private def loadedTemps (le : CC.TempEnv) (i : Fin 16) (stack : CC.Block) (byte : BitVec 8) : CC.TempEnv :=
  Arm64MemcpyReadByte.temps (selectedTemps le i) stack byte
private def observedTemps (le : CC.TempEnv) (i : Fin 16) (stack : CC.Block) (byte : BitVec 8) : CC.TempEnv :=
  Arm64MemcpyReadObserve.temps (loadedTemps le i stack byte) (byte.setWidth 64)

def temps (le : CC.TempEnv) (i : Fin 16) (stack sp : CC.Block) (byte : BitVec 8) : CC.TempEnv :=
  Arm64MemcpyReadSwitchExit.temps
    (Arm64MemcpyReadSpCheck.temps (observedTemps le i stack byte) sp (byte.setWidth 64)) (byte.setWidth 64)

private theorem read_kept (le : CC.TempEnv) (i : Fin 16) (stack : CC.Block) (byte : BitVec 8) (key : CC.Ident)
    (observedOther : Arm64Program.___a64_observed ≠ key)
    (valueOther : Arm64Program.___a64_str_value ≠ key)
    (byteOther : Arm64Program._t'47 ≠ key) (pointerOther : Arm64Program._t'91 ≠ key)
    (secondOther : Arm64Program._t'56 ≠ key) (firstOther : Arm64Program._t'55 ≠ key)
    (widthOther : Arm64Program.___a64_str_width ≠ key)
    (indexOther : Arm64Program.___a64_str_index ≠ key) (biasOther : Arm64Program._t'93 ≠ key) :
    (observedTemps le i stack byte).get key = le.get key :=
  (Arm64MemcpyReadObserve.kept _ _ key observedOther).trans
    ((Arm64MemcpyReadByte.kept _ stack byte key valueOther byteOther pointerOther).trans
      ((Arm64MemcpyReadByteSetup.kept _ key secondOther firstOther widthOther).trans
        (Arm64MemcpyReadIndex.kept le (-32#64) (BitVec.ofNat 64 i.val) key indexOther biasOther)))

/-- Execute the complete actual width1 stack-read case and original switch
exit on the same current packet. Its byte comes from the previous real
memset writes; both real header loads, all loops and guards remain. -/
theorem execute {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values m)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hbase : le.get Arm64Program.___a64_mrd_base = some (.Vlong (-32#64)))
    (hoff : le.get Arm64Program.___a64_memory_off = some (.Vlong (BitVec.ofNat 64 i.val)))
    (width : le.get Arm64Program._width = some (.Vint 1)) :
    CC.Star (CC.Step2 world)
      (.State reader Arm64MemcpyReadDispatch.read (Arm64MemcpyReadSwitchExit.continuation k) e le m) CC.E0
      (.State reader .Sskip k e (temps le i base.stack.block packet.storage.sp.block byte) m) := by
  let caseCont := Arm64MemcpyReadSwitchExit.continuation k
  let innerCont := Arm64MemcpyReadIndex.continuation caseCont
  have indexRun := Arm64MemcpyReadIndex.execute e le m caseCont entry.block (-32#64)
    (BitVec.ofNat 64 i.val) hentry packet.view.bias hbase hoff
  have currentWidth := (Arm64MemcpyReadIndex.kept le (-32#64) (BitVec.ofNat 64 i.val)
    Arm64Program._width (by decide +kernel) (by decide +kernel)).trans width
  have selectRun := Arm64MemcpyReadByteSetup.execute e _ m innerCont currentWidth
  have selectedEntry : (selectedTemps le i).get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (Arm64MemcpyReadByteSetup.kept _ _ (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans
      ((Arm64MemcpyReadIndex.kept le (-32#64) (BitVec.ofNat 64 i.val) _
        (by decide +kernel) (by decide +kernel)).trans hentry)
  have originalIndex : (Arm64MemcpyReadIndex.temps le (-32#64) (BitVec.ofNat 64 i.val)).get
      Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 (64+i.val))) := by
    rw [← Arm64MemcpyReadIndex.physical_index i]
    exact CC.PTree.gss _ _ _
  have selectedIndex := (Arm64MemcpyReadByteSetup.kept _ Arm64Program.___a64_str_index
    (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans originalIndex
  have byteRun := Arm64MemcpyReadByte.of_packet packet e (selectedTemps le i)
    (.Kseq Arm64MemcpyReadByteSetup.observed innerCont) i selectedEntry selectedIndex
  have loadedWidth : (loadedTemps le i base.stack.block byte).get Arm64Program.___a64_str_width = some (.Vint 1) :=
    (Arm64MemcpyReadByte.kept _ base.stack.block byte _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans (Arm64MemcpyReadByteSetup.width_one _)
  have loadedValue : (loadedTemps le i base.stack.block byte).get Arm64Program.___a64_str_value =
      some (.Vlong (byte.setWidth 64)) := CC.PTree.gss _ _ _
  have observedRun := Arm64MemcpyReadObserve.after_width e _ m caseCont (byte.setWidth 64) loadedWidth loadedValue
  have observedEntry := (read_kept le i base.stack.block byte Arm64Program._entry
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans hentry
  have observedBase := (read_kept le i base.stack.block byte Arm64Program.___a64_mrd_base
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans hbase
  have observedOff := (read_kept le i base.stack.block byte Arm64Program.___a64_memory_off
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans hoff
  have actualSp : CC.Mem.load .Mint64 m packet.storage.sp.block 0 = some (.Vlong (-32#64)) := by
    simpa only [packet.spAtBase] using packet.storage.spRead
  have spRun := Arm64MemcpyReadSpCheck.execute e _ m (Arm64MemcpyReadObserve.continuation caseCont)
    entry.block packet.storage.sp.block i (byte.setWidth 64) observedEntry packet.storage.spPointer
    actualSp observedBase observedOff (CC.PTree.gss _ _ _)
  have exitRun := Arm64MemcpyReadSwitchExit.execute e
    (Arm64MemcpyReadSpCheck.temps (observedTemps le i base.stack.block byte) packet.storage.sp.block (byte.setWidth 64))
    m k (byte.setWidth 64) (CC.PTree.gss _ _ _)
  simpa only [temps,caseCont,CC.E0,CC.Eapp,List.nil_append] using
    star_trans indexRun.sound (star_trans selectRun.sound
      (star_trans byteRun (star_trans observedRun.sound (star_trans spRun.sound exitRun.sound))))

theorem value_read (le : CC.TempEnv) (i : Fin 16) (stack sp : CC.Block) (byte : BitVec 8) :
    (temps le i stack sp byte).get Arm64Program.___a64_memory_value = some (.Vlong (byte.setWidth 64)) :=
  CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpyReadCase
