import KProgFormal.ClightRefinement.Arm64MemcpyReadInputs
import KProgFormal.ClightRefinement.Arm64MemcpyReadSwitchExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadPrefix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private def tagTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry) : CC.TempEnv :=
  Arm64MemcpyReadTag.finalTemps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) (4#8)
private def selectedTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry) : CC.TempEnv :=
  Arm64MemcpyReadSelect.temps (tagTemps le storage)
private def contextTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block) : CC.TempEnv :=
  Arm64MemcpyReadContextFlow.temps (selectedTemps le storage) flag flagValue abi

def temps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (le : CC.TempEnv) (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (flag : CC.Block) (flagValue : BitVec 8) (abi : CC.Block) : CC.TempEnv :=
  Arm64MemcpyReadPointer.temps (Arm64MemcpyReadPointer.readTemps
    (Arm64MemcpyReadPointer.regTemps (contextTemps le storage flag flagValue abi))
      (storage.tables false).tableBlock ((storage.tables false).cellBlock 1) (-32#64)) (-32#64)

def continuation (k : CC.Cont) : CC.Cont :=
  Arm64MemcpyReadSwitchExit.continuation (.Kseq Arm64MemcpyReadContext.result k)

/-- Execute the real tag, source, two context gates, switch and R1 pointer
paths into source37. Actual current Storage and typed flag/ABI reads supply
each load; every current input reaches the genuine byte-read continuation. -/
theorem route {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values m)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (off : BitVec 64)
    (actual : Arm64MemcpyReadInputs.Inputs entry.block off le)
    (flag : CC.Block) (flagValue : BitVec 8)
    (flagHeader : CC.Mem.load CC.Mptr m entry.block 696 = some (.Vptr flag 0))
    (flagByte : CC.Mem.load .Mint8unsigned m flag 0 = some (.Vint (flagValue.setWidth 32))) :
    InternalRun world 101 (.State reader Arm64MemcpyReadOffset.tagRest k e le m)
      (.State reader Arm64MemcpyReadDispatch.read (continuation k) e
        (temps le packet.storage flag flagValue abi.block) m) ∧
    Arm64MemcpyReadInputs.Inputs entry.block off (temps le packet.storage flag flagValue abi.block) ∧
    (temps le packet.storage flag flagValue abi.block).get Arm64Program.___a64_mrd_base = some (.Vlong (-32#64)) := by
  let storage := packet.storage
  have tagRun := Arm64MemcpyReadTag.complete storage e le k (.Vlong (-32#64)) (4#8)
    actual.entryRead actual.base packet.r1
  have tagInputs := Arm64MemcpyReadInputs.tagged le (storage.tables true).tableBlock
    ((storage.tables true).cellBlock 1) actual
  have tagValue : (tagTemps le storage).get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)) :=
    CC.PTree.gss _ _ _
  have selectRun := Arm64MemcpyReadSelect.execute e (tagTemps le storage) m k tagInputs.base tagValue
  have selected := Arm64MemcpyReadInputs.selected (tagTemps le storage) tagInputs tagValue
  have contextRun := Arm64MemcpyReadContextFlow.execute e (selectedTemps le storage) m k
    entry.block flag abi.block flagValue selected.entryRead selected.tag flagHeader flagByte packet.abiHeader packet.abiKind
  have context := Arm64MemcpyReadInputs.contexts (selectedTemps le storage) flag flagValue abi.block selected
  let finalCont := CC.Cont.Kseq Arm64MemcpyReadContext.result k
  have dispatchRun := Arm64MemcpyReadDispatch.execute e (contextTemps le storage flag flagValue abi.block) m finalCont context.source0
  have pointerRun := Arm64MemcpyReadPointer.execute storage (-32#64) (4#8) e
    (contextTemps le storage flag flagValue abi.block) (Arm64MemcpyReadDispatch.continuation finalCont)
    context.entryRead context.base packet.r1
  have entered := Arm64MemcpyReadSwitchExit.enter_read e (temps le storage flag flagValue abi.block) m finalCont
  have finalInputs := Arm64MemcpyReadInputs.pointer (contextTemps le storage flag flagValue abi.block)
    (storage.tables false).tableBlock ((storage.tables false).cellBlock 1) (-32#64) context.toInputs
  exact ⟨(((((tagRun.trans selectRun).trans contextRun).trans dispatchRun).trans pointerRun).trans entered),
    finalInputs.1,finalInputs.2⟩

/-- The real seven-argument Callstate includes actual13-local allocation,
original no-index offset arithmetic and all reached source-control routes.
The current post-allocation packet is supplied by the actual caller frame. -/
theorem original {initial seed before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet base abi byte gprs flags values (Arm64MemcpyReadSource.allocation before).2)
    (k : CC.Cont) (off : BitVec 64) (flag : CC.Block) (flagValue : BitVec 8)
    (flagHeader : CC.Mem.load CC.Mptr (Arm64MemcpyReadSource.allocation before).2 entry.block 696 = some (.Vptr flag 0))
    (flagByte : CC.Mem.load .Mint8unsigned (Arm64MemcpyReadSource.allocation before).2 flag 0 = some (.Vint (flagValue.setWidth 32))) :
    InternalRun world 179
      (.Callstate (.Internal reader) (Arm64MemcpyReadCall.arguments entry.block off) k before)
      (.State reader Arm64MemcpyReadDispatch.read (continuation (Arm64MemcpyReadSource.outerCont k))
        (Arm64MemcpyReadSource.allocation before).1
        (temps (Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block off) off)
          packet.storage flag flagValue abi.block) (Arm64MemcpyReadSource.allocation before).2) ∧
    Arm64MemcpyReadInputs.Inputs entry.block off
      (temps (Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block off) off)
        packet.storage flag flagValue abi.block) ∧
    (temps (Arm64MemcpyReadOffset.temps (Arm64MemcpyReadSource.initialTemps entry.block off) off)
      packet.storage flag flagValue abi.block).get Arm64Program.___a64_mrd_base = some (.Vlong (-32#64)) := by
  have offsetRun := Arm64MemcpyReadOffset.original before entry.block off k
  have actual := Arm64MemcpyReadInputs.offset (Arm64MemcpyReadSource.initialTemps entry.block off) off
    (Arm64MemcpyReadInputs.initial entry.block off)
  obtain ⟨path,inputs,raw⟩ := route packet (Arm64MemcpyReadSource.allocation before).1 _
    (Arm64MemcpyReadSource.outerCont k) off actual flag flagValue flagHeader flagByte
  exact ⟨offsetRun.trans path,inputs,raw⟩

end KProgFormal.ClightRefinement.Arm64MemcpyReadPrefix
