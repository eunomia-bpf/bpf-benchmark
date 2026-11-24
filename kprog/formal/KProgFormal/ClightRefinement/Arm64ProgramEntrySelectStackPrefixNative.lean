import KProgFormal.ClightRefinement.Arm64ProgramEntryCompareStackPrefixNative
import KProgFormal.ClightRefinement.Arm64MemsetHeaderView
import KProgFormal.ClightRefinement.Arm64ProgramEntryComparePrefixNativeTail
import KProgFormal.ClightRefinement.Arm64ProgramEntrySelectPrefixNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntrySelectStackPrefixNative
open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps)
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)
open Arm64ProgramEntryMulAdmission (afterFour)
open Arm64ProgramEntryCompareAdmission (afterFive)
open Arm64ProgramEntrySelectAdmission (afterSix)

/-- The original98 provider inputs and complete seven-call source prefix refine
seven fetched mature native words, retaining every preceding heap/free contract
and the actual original afterSelect continuation. -/
theorem entry_corresponds (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (abiLocal : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i)))
    (first keep third fourth fifth sixth seventh : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding) :
    ∃ entry : HeaderLocal initial, ∃ header : (j : Fin 12) → HeaderSourceLocal initial j,
    ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      ready.nextblock = (Arm64Producer.allocation initial).2.nextblock ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
      (setupTemps temps fields).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      Nonempty (Arm64MemsetHeaderView.Ready initial ready entry) ∧
      ∀ (supplied : CC.Mem) (trace : CC.Trace),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
          [.Vint 1] (Arm64Nop.allocation world ready).2 trace (.Vlong origins.stack) supplied →
        Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world ready).2 supplied →
    ∃ firstWritten middle secondWritten pairAfter, ∃ pairStorage : Storage initial pairAfter entry,
    ∃ thirdWritten thirdAfter, ∃ thirdStorage : Storage initial thirdAfter entry,
      (      CC.Mem.load .Mint64 pairAfter ((pairStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned pairAfter ((pairStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Mem.load .Mint64 thirdAfter ((thirdStorage.tables false).cellBlock 2) 0 = some (.Vlong (pairStorage.spValue + (16#64))) ∧
      CC.Mem.load .Mint8unsigned thirdAfter ((thirdStorage.tables true).cellBlock 2) 0 = some (.Vint (4#32)) ∧
      CC.Mem.load .Mint64 thirdAfter ((thirdStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned thirdAfter ((thirdStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddCall.afterAdd k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) thirdAfter) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock thirdAfter (.Vptr entry.block 0)
        (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (nativeSetup s origins fields)).events = [] ∧
      (Reference.AArch64.step (nativeSetup s origins fields)).fault = none ∧
      (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).events = [] ∧
      (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).fault = none ∧
      (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterPair (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial thirdAfter ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1) = some middle ∧
      FrameBelow ready.nextblock firstWritten middle ∧ middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world ready).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some pairAfter ∧
      FrameBelow middle.nextblock secondWritten pairAfter ∧ pairAfter.contents = secondWritten.contents ∧
      pairAfter.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm pairAfter row.1 ofs kind permission = false) ∧
      CC.Mem.freeList thirdWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world pairAfter).1) = some thirdAfter ∧
      FrameBelow pairAfter.nextblock thirdWritten thirdAfter ∧ thirdAfter.contents = thirdWritten.contents ∧
      thirdAfter.nextblock = thirdWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world pairAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm thirdAfter row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial pairAfter thirdAfter 2 ∧
      (∀ j, CC.Mem.load CC.Mptr thirdAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock thirdAfter (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ thirdAfter.nextblock.toNat) ∧
    ∃ fourthWritten fourthAfter, ∃ fourthStorage : Storage initial fourthAfter entry,
      (CC.Mem.load .Mint64 fourthAfter ((fourthStorage.tables false).cellBlock 3) 0 = some (.Vlong ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack))) ∧
      CC.Mem.load .Mint8unsigned fourthAfter ((fourthStorage.tables true).cellBlock 3) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddRegisterCall.afterRegister k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) fourthAfter) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock fourthAfter (.Vptr entry.block 0)
        (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial fourthAfter ∧
      CC.Mem.freeList fourthWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1) = some fourthAfter ∧
      FrameBelow thirdAfter.nextblock fourthWritten fourthAfter ∧
      fourthAfter.contents = fourthWritten.contents ∧ fourthAfter.nextblock = fourthWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm fourthAfter row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial thirdAfter fourthAfter 3 ∧
      (∀ j, CC.Mem.load CC.Mptr fourthAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock fourthAfter (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ fourthAfter.nextblock.toNat) ∧
    ∃ fifthWritten after, ∃ finalStorage : Storage initial after entry,
      (CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 4) 0 = some (.Vlong ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) * ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack)))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 4) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (afterFour (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial after ∧
      CC.Mem.freeList fifthWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world fourthAfter).1) = some after ∧
      FrameBelow fourthAfter.nextblock fifthWritten after ∧
      after.contents = fifthWritten.contents ∧ after.nextblock = fifthWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world fourthAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial fourthAfter after 4 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat) ∧
    ∃ sixthWritten final, ∃ compareStorage : Storage initial final entry,
      (Arm64Compare.Call.Result finalStorage ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) * ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack))) (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)
        (Arm64ProgramEntryCompareCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        sixthWritten final compareStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock final (.Vptr entry.block 0)
        (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterFive (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial final ∧
      (∀ j, CC.Mem.load CC.Mptr final entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock final (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ final.nextblock.toNat) ∧
    ∃ count value raw tag seventhWritten selected, ∃ selectedStorage : Storage initial selected entry,
      Arm64Select.Call.Result compareStorage addresses origins (afterSix (nativeSetup s origins fields))
        (Arm64ProgramEntrySelectCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count value raw tag seventhWritten selected selectedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySelectCall.afterSelect k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) selected) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock selected (.Vptr entry.block 0)
        (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial selected ∧
      (∀ j, CC.Mem.load CC.Mptr selected entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock selected (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ selected.nextblock.toNat ∧
      Arm64ProducerTailFrame.Frame initial entry ready selected ∧
      CC.Mem.load .Mint8unsigned selected abiLocal.block 0 = some (.Vint 2) ∧
      CC.Mem.load CC.Mptr selected entry.block 704 = some (.Vptr abiLocal.block 0) ∧
      ∀ (tags : StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned selected tags.block (i.val : Int) = some (.Vint 0) := by
  have admitted := Arm64ProgramEntrySelectAdmission.setup_next s origins fields first keep third fourth fifth sixth seventh
    imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
  obtain ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,continuation⟩ :=
    Arm64ProgramEntryCompareStackPrefixNative.entry_corresponds initial ctxBlock ctxOfs k abiLocal addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
      first keep third fourth fifth sixth imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded
      fifthDecoded sixthDecoded noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched
  have readyBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ ready.nextblock.toNat :=
    Nat.le_of_eq (congrArg (fun block : CC.Block => block.toNat) readyNext.symm)
  refine ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
      thirdWritten,thirdAfter,thirdStorage,facts3,
      fourthWritten,fourthAfter,fourthStorage,facts4,
      fifthWritten,after,finalStorage,facts5,
      sixthWritten,final,compareStorage,facts6⟩ := continuation supplied trace origin outcome
  obtain ⟨_sixthResult,run6,registers6,_events6,_fault6,frame6,pointers6,warm6,bound6,priorTail,abiReadback,abiPointer,tagReads⟩ := facts6
  refine ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
    thirdWritten,thirdAfter,thirdStorage,facts3,
    fourthWritten,fourthAfter,fourthStorage,facts4,
    fifthWritten,after,finalStorage,facts5,
    sixthWritten,final,compareStorage,⟨_sixthResult,run6,registers6,_events6,_fault6,frame6,pointers6,warm6,bound6⟩,?_⟩
  have currentRegisters := (Arm64RegisterStorageFrontier.represents_iff compareStorage ready.nextblock readyBound
    addresses origins (afterSix (nativeSetup s origins fields))).mp registers6
  obtain ⟨count,value,raw,tag,seventhWritten,selected,selectedStorage,result,run7⟩ := Arm64Select.Call.returned
    compareStorage bound6 addresses origins (afterSix (nativeSetup s origins fields)) seventh currentRegisters
    seventhDecoded admitted.2.1 admitted.2.2
    (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k
  have currentFinal := (Arm64RegisterStorageFrontier.represents_iff selectedStorage final.nextblock bound6
    addresses origins (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).state).mp result.registers
  have finalRegisters := (Arm64RegisterStorageFrontier.represents_iff selectedStorage ready.nextblock readyBound
    addresses origins (Reference.AArch64.step (afterSix (nativeSetup s origins fields))).state).mpr currentFinal
  have stepTail := Arm64ProducerTailFrame.of_kept entry 5 result.kept
  have tailFrame := priorTail.trans stepTail
  have abiObserved := stepTail.abi abiLocal abiPointer abiReadback
  have finalTags (tags : StackTagLocal initial) (i : Fin 24) :=
    (stepTail.tail 2 ⟨tags.block,tags.binding⟩ .Mint8unsigned (i.val : Int)).trans (tagReads tags i)
  refine ⟨count,value,raw,tag,seventhWritten,selected,selectedStorage,result,?_,finalRegisters,?_,?_,
    frame6.trans result.caller,result.kept.pointers header pointers6,
    result.kept.warm ready.nextblock header readyBound pointers6 false origins.stack warm6,result.bound,tailFrame,abiObserved.2,abiObserved.1,finalTags⟩
  · simpa only [CC.Eapp,CC.E0,List.append_nil] using star_trans run6 run7.sound
  · rw [result.nativeStep]
  · rw [result.nativeStep]

end KProgFormal.ClightRefinement.Arm64ProgramEntrySelectStackPrefixNative
