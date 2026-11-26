import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalComplete
import KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryCalls

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Bookkeeping for the original source branch/result operations. Instruction
conditions remain the existing imported-model correspondences. -/
def resultWord (saved : BitVec 64) (mark : BitVec 32) (s : Reference.AArch64.State)
    (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) (byte : BitVec 8) : BitVec 32 :=
  let flagsState := Arm64ClobberNativeFlags.native s flags
  let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
  let cbzResult := Arm64ProgramEntryCbzExit.result
    (Arm64ProgramEntryJccExit.result (saved ^^^ (vectors 63)) mark flagsState) compareState
  let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
  let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
  let scalar := Arm64ProgramEntryCmpExit.result tbnzResult tbnzState (gprs 2) (gprs 3)
  (Arm64ProgramEntryContinuationByte.value scalar byte).setWidth 32

/-- Join the SAME genuine prefix supplied by MemoryCalls.compose to complete
original source return/freeList. The source suffix has E0, so the entire
original provider trace is retained exactly. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (frame : FrameBelow initial.nextblock initial m) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (saved : BitVec 64) (read : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (s : Reference.AArch64.State) (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)) :
    ∃ stored after, Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
        (.Returnstate (.Vint (resultWord saved mark s gprs flags vectors byte)) k after) ∧
      FrameBelow initial.nextblock initial after := by
  obtain ⟨lr⟩ := Arm64Producer.header_source_local initial (4 : Fin 12)
  obtain ⟨cmpAfter,updated,cmpLe,linked,linkedResult,returned,lrEffect,stored,stores,after,freed,count,cmpEffect,suffix,ctxEq,caller⟩ :=
    Arm64ProgramEntryTerminalComplete.from_memcpy current lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark saved read s
  refine ⟨stored,after,freed,?_,caller⟩
  simpa only [CC.Eapp,CC.E0,List.append_nil,resultWord] using star_trans prefixRun suffix.sound

/-- Instantiate both original memory calls and the completed source suffix
with the SAME actual native/source prefix, Ready/is_xdp witness and supplied
provider inputs. Every original prefix/helper trace is retained. -/
theorem compose {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (abi : TailLocal initial 6)
    (resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
      (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2
      view.tags.block (j.val : Int) = some (.Vint 0))
    (cell : TailLocal initial 5) (ready : CC.Mem)
    (readyPacket : Arm64MemsetHeaderView.Ready initial ready entry)
    (retained : Arm64ProducerTailFrame.Frame initial entry ready constantAfter)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe)
    (registerInputs : ∀ outerLe, Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) constantAfter (-32#64) 0 cell (0#8) outerLe gprs flags)
    (copyByteInputs : ∀ copyBefore outerLe,
      Arm64ClobberReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe)
    (copyRegisterInputs : ∀ copyBefore outerLe,
      Arm64ClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe)
    (copyFlagInputs : ∀ copyBefore outerLe gprs,
      Arm64ClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe gprs)
    (copyVectorInputs : ∀ copyBefore outerLe gprs flags,
      Arm64ClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) copyBefore (-16#64) 16 cell (0#8) outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) (ctx : CC.Val) (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
        (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter))
    (prefixCaller : FrameBelow initial.nextblock initial constantAfter)
    (hk : CC.isCallCont k = true) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs)
    (context : ctx = .Vptr ctxBlock ctxOffset) (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctxRead : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (saved : BitVec 64) (savedRead : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (s : Reference.AArch64.State) :
    ∃ gprs flags vectors stored after trace,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial) trace
        (.Returnstate (.Vint (resultWord saved mark s gprs flags vectors (Arm64MemsetLossSetup.byte mark))) k after) ∧
      FrameBelow initial.nextblock initial after := by
  subst ctx
  obtain ⟨m,written,copyBefore,gprs,flags,vectors,trace,current,memoryRun,copyFree,memoryCaller,finalBound⟩ :=
    Arm64ProgramEntryMemoryCalls.compose mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      cell ready readyPacket retained byteInputs registerInputs flagInputs vectorInputs
      copyByteInputs copyRegisterInputs copyFlagInputs copyVectorInputs le k (.Vptr ctxBlock ctxOffset) prefixTrace prefixRun prefixCaller
  obtain ⟨stored,after,freed,fullRun,caller⟩ := execute current memoryCaller le k hk ctxBlock ctxOffset mark ctxBelow ctxRead
    originalMark saved savedRead s trace memoryRun
  exact ⟨gprs,flags,vectors,stored,after,trace,freed,fullRun,caller⟩

/-- The actual top-level Returnstate is terminal in the imported semantics. -/
theorem stopped (value : BitVec 32) (m : CC.Mem) : ∀ trace next,
    ¬ CC.Step2 world (.Returnstate (.Vint value) .Kstop m) trace next := by
  intro trace next step
  cases step

end KProgFormal.ClightRefinement.Arm64ProgramEntryMemoryReturn
