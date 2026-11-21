import KProgFormal.ClightRefinement.Arm64ProgramEntryAddPrefixNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterAdmission

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterPrefixNative
open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps)
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)

/-- The original98 inputs and real four-call prefix refine four fetched native
words, retaining provider traces, predecessor releases and the reached heaps. -/
theorem entry_corresponds (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
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
    (first keep third fourth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding) :
    ∃ entry : HeaderLocal initial, ∃ header : (j : Fin 12) → HeaderSourceLocal initial j,
    ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      ready.nextblock = (Arm64Producer.allocation initial).2.nextblock ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
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
    ∃ fourthWritten after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 3) 0 = some (.Vlong ((Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) + ((pairStorage.spValue + (16#64)) + origins.stack))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 3) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddRegisterCall.afterRegister k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (afterThree (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial after ∧
      CC.Mem.freeList fourthWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1) = some after ∧
      FrameBelow thirdAfter.nextblock fourthWritten after ∧
      after.contents = fourthWritten.contents ∧ after.nextblock = fourthWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world thirdAfter).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial thirdAfter after 3 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  have admitted := Arm64ProgramEntryAddRegisterAdmission.setup_next s origins fields first keep third fourth
    imm column negate literal firstDecoded keepDecoded thirdDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched
  obtain ⟨entry, header, ready, temps, traces, length, readyNext, entryRun, continuation⟩ :=
    Arm64ProgramEntryAddPrefixNative.entry_corresponds initial ctxBlock ctxOfs k addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
      first keep third imm column negate literal firstDecoded keepDecoded thirdDecoded noError
      firstFetched keepFetched thirdFetched
  have readyBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ ready.nextblock.toNat :=
    Nat.le_of_eq (congrArg (fun block : CC.Block => block.toNat) readyNext.symm)
  refine ⟨entry, header, ready, temps, traces, length, readyNext, entryRun, ?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten, middle, secondWritten, pairAfter, pairStorage,
      thirdWritten, thirdAfter, thirdStorage, facts⟩ := continuation supplied trace origin outcome
  refine ⟨firstWritten, middle, secondWritten, pairAfter, pairStorage,
    thirdWritten, thirdAfter, thirdStorage, facts, ?_⟩
  obtain ⟨pairWord, pairTag, thirdWord, thirdTag, lhsWord, lhsTag, run3, registers3,
      events1, fault1, events2, fault2, events3, fault3, frame,
      firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
      secondFree, secondFreeFrame, secondContents, pairNext, secondReleased,
      thirdFree, thirdFreeFrame, thirdContents, thirdNext, thirdReleased,
      thirdKept, thirdPointers, thirdWarm, thirdBound⟩ := facts
  have liveRegisters := (Arm64RegisterStorageFrontier.represents_iff thirdStorage ready.nextblock readyBound
    addresses origins (afterThree (nativeSetup s origins fields))).mp registers3
  have liveWarm := (Arm64CacheLocalFrame.warm_iff ready.nextblock header readyBound thirdPointers false origins.stack).mp thirdWarm
  obtain ⟨fourthWritten, after, finalStorage, word, tag, run4, registers4, events4, fault4, frame4,
      fourthFree, fourthFreeFrame, fourthContents, fourthNext, fourthReleased,
      fourthKept, finalPointers, _finalWarm, finalBound⟩ :=
    Arm64ProgramEntryAddRegisterNative.corresponds thirdStorage thirdBound header thirdPointers addresses origins
      (afterThree (nativeSetup s origins fields)) liveRegisters liveWarm
      (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)
      (pairStorage.spValue + (16#64)) lhsWord lhsTag thirdWord thirdTag
      (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k
      fourth fourthDecoded admitted.2.1 admitted.2.2
  have finalRegisters := (Arm64RegisterStorageFrontier.represents_iff finalStorage ready.nextblock readyBound
    addresses origins _).mpr ((Arm64RegisterStorageFrontier.represents_iff finalStorage thirdAfter.nextblock thirdBound
      addresses origins _).mp registers4)
  have finalWarm := fourthKept.warm ready.nextblock header readyBound thirdPointers false origins.stack thirdWarm
  refine ⟨fourthWritten, after, finalStorage, word, tag, ?_, finalRegisters, events4, fault4,
    frame.trans frame4, fourthFree, fourthFreeFrame, fourthContents, fourthNext, fourthReleased,
    fourthKept, finalPointers, finalWarm, finalBound⟩
  simpa only [CC.Eapp, CC.E0, List.append_nil] using star_trans run3 run4.sound

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterPrefixNative
