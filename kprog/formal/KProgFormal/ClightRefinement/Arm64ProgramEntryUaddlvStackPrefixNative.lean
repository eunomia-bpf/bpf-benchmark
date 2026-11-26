import KProgFormal.ClightRefinement.Arm64ProgramEntryCntStackPrefixNative
import KProgFormal.ClightRefinement.Arm64MemsetHeaderView
import KProgFormal.ClightRefinement.Arm64ProgramEntryCntPrefixNativeTail
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvPrefixNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvStackPrefixNative
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

open Arm64ProgramEntryCnegAdmission (afterSeven)
open Arm64ProgramEntryOrnAdmission (afterEight)
open Arm64ProgramEntryFmovAdmission (afterNine)
open Arm64ProgramEntryCntAdmission (afterTen)
open Arm64ProgramEntryUaddlvAdmission (afterEleven)

private theorem header_not_vector : Arm64Entry._entry ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem tail_not_vector : ∀ i : Fin 9, tailLocalName i ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- The original 98 provider inputs and complete twelve-call prefix refine
twelve fetched imported native words. Original storage derives the UADDLV
inputs and permissions; every previous source/heap/free contract is retained. -/
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
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
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
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding) :
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
      (Arm64Select.Call.Result compareStorage addresses origins (afterSix (nativeSetup s origins fields))
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
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ selected.nextblock.toNat ) ∧
    ∃ count8 eighthWritten negated, ∃ negatedStorage : Storage initial negated entry,
      (Arm64Cneg.Call.Result selectedStorage addresses origins (afterSeven (nativeSetup s origins fields))
        (Arm64ProgramEntryCnegCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count8 eighthWritten negated negatedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCnegCall.afterCneg k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) negated) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock negated (.Vptr entry.block 0)
        (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterSeven (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial negated ∧
      (∀ j, CC.Mem.load CC.Mptr negated entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock negated (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ negated.nextblock.toNat ) ∧
    ∃ count9 ninthWritten combined, ∃ combinedStorage : Storage initial combined entry,
      ( Arm64Orn.Call.Result negatedStorage addresses origins (afterEight (nativeSetup s origins fields))
        (Arm64ProgramEntryOrnCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count9 ninthWritten combined combinedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrnCall.afterOrn k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) combined) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock combined (.Vptr entry.block 0)
        (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterEight (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial combined ∧
      (∀ j, CC.Mem.load CC.Mptr combined entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock combined (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ combined.nextblock.toNat ) ∧
    ∃ count10 tenthWritten final, ∃ finalStorage : Storage initial final entry,
      (      Arm64Fmov.Call.Result combinedStorage
        (Arm64RegisterWrite.written true (Arm64Orn.Call.nativeResult (afterEight (nativeSetup s origins fields))))
        addresses origins (afterNine (nativeSetup s origins fields))
        (Arm64ProgramEntryFmovCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count10 tenthWritten final finalStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryFmovCall.afterFmov k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock final (.Vptr entry.block 0)
        (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterNine (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial final ∧
      (∀ j, CC.Mem.load CC.Mptr final entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock final (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ final.nextblock.toNat ) ∧
    ∃ count11 eleventhWritten completed, ∃ completedStorage : Storage initial completed entry,
      (Arm64Cnt.Call.Result finalStorage addresses origins (afterTen (nativeSetup s origins fields))
        (Arm64ProgramEntryCntCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count11 eleventhWritten completed completedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCntCall.afterCnt k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) completed) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock completed (.Vptr entry.block 0)
        (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterTen (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial completed ∧
      (∀ j, CC.Mem.load CC.Mptr completed entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock completed (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ completed.nextblock.toNat ) ∧
    ∃ count12 twelfthWritten summed, ∃ summedStorage : Storage initial summed entry,
      Arm64Uaddlv.Call.Result completedStorage addresses origins (afterEleven (nativeSetup s origins fields))
        (Arm64ProgramEntryUaddlvCall.callCont initial
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k)
        count12 twelfthWritten summed summedStorage ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock summed (.Vptr entry.block 0)
        (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state ∧
      (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).events = [] ∧
      (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).fault = none ∧
      FrameBelow initial.nextblock initial summed ∧
      (∀ j, CC.Mem.load CC.Mptr summed entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock summed (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ summed.nextblock.toNat ∧
      Arm64ProducerTailFrame.Frame initial entry ready summed ∧
      CC.Mem.load .Mint8unsigned summed abiLocal.block 0 = some (.Vint 2) ∧
      CC.Mem.load CC.Mptr summed entry.block 704 = some (.Vptr abiLocal.block 0) ∧
      ∀ (tags : StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned summed tags.block (i.val : Int) = some (.Vint 0) := by
  have admitted := Arm64ProgramEntryUaddlvAdmission.setup_next s origins fields first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth
    imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
  obtain ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,continuation⟩ :=
    Arm64ProgramEntryCntStackPrefixNative.entry_corresponds initial ctxBlock ctxOfs k abiLocal addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
      first keep third fourth fifth sixth seventh eighth ninth tenth eleventh imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded
      fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched
  have readyBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ ready.nextblock.toNat :=
    Nat.le_of_eq (congrArg (fun block : CC.Block => block.toNat) readyNext.symm)
  refine ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
      thirdWritten,thirdAfter,thirdStorage,facts3,
      fourthWritten,fourthAfter,fourthStorage,facts4,
      fifthWritten,after,finalStorage,facts5,
      sixthWritten,final,compareStorage,facts6,
      count,value,raw,tag,seventhWritten,selected,selectedStorage,facts7,
      count8,eighthWritten,negated,negatedStorage,facts8,
      count9,ninthWritten,combined,combinedStorage,facts9,
      count10,tenthWritten,completed,completedStorage,facts10,
      count11,eleventhWritten,counted,countedStorage,facts11⟩ := continuation supplied trace origin outcome
  obtain ⟨result11,run11,registers11,_events11,_fault11,frame11,pointers11,warm11,bound11,priorTail,abiReadback,abiPointer,tagReads⟩ := facts11
  refine ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
    thirdWritten,thirdAfter,thirdStorage,facts3,
    fourthWritten,fourthAfter,fourthStorage,facts4,
    fifthWritten,after,finalStorage,facts5,
    sixthWritten,final,compareStorage,facts6,
    count,value,raw,tag,seventhWritten,selected,selectedStorage,facts7,
    count8,eighthWritten,negated,negatedStorage,facts8,
    count9,ninthWritten,combined,combinedStorage,facts9,
    count10,tenthWritten,completed,completedStorage,facts10,
    count11,eleventhWritten,counted,countedStorage,⟨result11,run11,registers11,_events11,_fault11,frame11,pointers11,warm11,bound11⟩,?_⟩
  have currentRegisters := (Arm64RegisterStorageFrontier.represents_iff countedStorage ready.nextblock readyBound
    addresses origins (afterEleven (nativeSetup s origins fields))).mp registers11
  obtain ⟨count12,twelfthWritten,summed,summedStorage,result12,run12⟩ := Arm64Uaddlv.Call.returned countedStorage bound11
    addresses origins (afterEleven (nativeSetup s origins fields)) twelfth currentRegisters
    twelfthDecoded admitted.2.1 admitted.2.2
    (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k
  have currentFinal := (Arm64RegisterStorageFrontier.represents_iff summedStorage counted.nextblock bound11
    addresses origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).mp result12.registers
  have finalRegisters := (Arm64RegisterStorageFrontier.represents_iff summedStorage ready.nextblock readyBound
    addresses origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).mpr currentFinal
  have stepTail : Arm64ProducerTailFrame.Frame initial entry counted summed :=
    ⟨fun chunk ofs => result12.locals _ _ _ entry.binding header_not_vector chunk ofs,
      fun i cell chunk ofs => result12.locals _ _ _ cell.binding (tail_not_vector i) chunk ofs⟩
  have tailFrame := priorTail.trans stepTail
  have abiObserved := stepTail.abi abiLocal abiPointer abiReadback
  have finalTags (tags : StackTagLocal initial) (i : Fin 24) :=
    (stepTail.tail 2 ⟨tags.block,tags.binding⟩ .Mint8unsigned (i.val : Int)).trans (tagReads tags i)
  refine ⟨count12,twelfthWritten,summed,summedStorage,result12,?_,finalRegisters,?_,?_,
    frame11.trans result12.caller,result12.pointers header pointers11,
    result12.warm ready.nextblock header readyBound pointers11 false origins.stack warm11,result12.bound,tailFrame,abiObserved.2,abiObserved.1,finalTags⟩
  · simpa only [CC.Eapp,CC.E0,List.append_nil] using star_trans run11 run12.sound
  · rw [result12.nativeStep]
  · rw [result12.nativeStep]

end KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvStackPrefixNative
