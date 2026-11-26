import KProgFormal.ClightRefinement.Arm64ProgramEntryComplete
import KProgFormal.ClightRefinement.Arm64ProgramEntryPrefixSp
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvStackRightsPrefixNative
import KProgFormal.ClightRefinement.Arm64MemsetHeaderView
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvPrefixNativeTail
import KProgFormal.ClightRefinement.Arm64ProgramEntryResultVector
import KProgFormal.ClightRefinement.Arm64ProgramEntryResultCondition
import KProgFormal.ClightRefinement.Arm64ProgramEntryPointerWrites
import KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovAdmission
import KProgFormal.ClightRefinement.Arm64ProgramEntryConstantMovNative
import KProgFormal.ClightRefinement.Arm64UaddlvCacheFrame
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvAdmission
import KProgFormal.ClightRefinement.Arm64ProgramEntryOrnPrefixNative
import KProgFormal.ClightRefinement.Arm64FmovInputs
import KProgFormal.ClightRefinement.Arm64FmovCacheFrame
import KProgFormal.ClightRefinement.Arm64ProgramEntryFmovAdmission
import KProgFormal.ClightRefinement.Arm64OrnCaller
import KProgFormal.ClightRefinement.Arm64ProgramEntryOrnAdmission

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackRights
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

private theorem cells_other : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel

private theorem cell_from_locals {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (new : Storage initial after entry)
    (locals : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
      id ≠ Arm64Entry.___a64_vectors → ∀ chunk offset,
      CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset)
    (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((new.tables tags).cellBlock i) offset =
      CC.Mem.load chunk before ((old.tables tags).cellBlock i) offset := by
  have same : (new.tables tags).cellBlock i = (old.tables tags).cellBlock i :=
    congrArg Prod.fst (Option.some.inj
      (((new.tables tags).cellBinding i).symm.trans ((old.tables tags).cellBinding i)))
  rw [same]
  exact locals _ _ _ ((old.tables tags).cellBinding i) (cells_other tags i) chunk offset

private theorem gpr_from_cells {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (new : Storage initial after entry) (i : Fin 31)
    (cells : ∀ tags chunk offset, CC.Mem.load chunk after ((new.tables tags).cellBlock i) offset =
      CC.Mem.load chunk before ((old.tables tags).cellBlock i) offset) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [Arm64RegisterWrite.storage_gpr new i,Arm64RegisterWrite.storage_gpr old i,
    cells false .Mint64 0,cells true .Mint8unsigned 0]

private theorem caller_context (le : CC.TempEnv) (fields : Fin 3 → BitVec 32) :
    (priorityTemps (markTemps (setupTemps le fields) (fields 0)) (fields 1)).get Arm64ProgramFixture._ctx =
      (setupTemps le fields).get Arm64ProgramFixture._ctx := by
  unfold priorityTemps markTemps
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Reuse the exact original result temporary environment. -/
abbrev resultTemps := Arm64ProgramEntryResultStackPrefix.resultTemps

/-- Every actual pre-pointer observation is derived at the SAME reached heap. -/
structure Reached {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (abi : TailLocal initial 6) where
  view : Arm64MemsetHeaderView.View initial memory entry
  resources : Arm64ProgramEntryResources.Resources initial memory entry
  spAtBase : storage.spValue = (-32#64)
  abiHeader : CC.Mem.load CC.Mptr memory entry.block 704 = some (.Vptr abi.block 0)
  abiKind : CC.Mem.load .Mint8unsigned memory abi.block 0 = some (.Vint 2)
  tagBytes : ∀ i : Fin 24, CC.Mem.load .Mint8unsigned memory view.tags.block (i.val : Int) = some (.Vint 0)

/-- The original 98-provider and twelve-call result/condition/pointer prefix
executes the complete thirteenth and fourteenth MOV calls. Every earlier source/native, heap, free,
cache and provenance contract remains, including the full original call trace. -/
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
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
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
    (thirteenthDecoded : thirteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (fourteenthDecoded : fourteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 2 (16#16) 0 false false)))
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
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding)
    (fourteenthFetched : fetch_inst (read_pc s.machine + 52#64) s.machine = some fourteenth.encoding) :
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
      (Arm64Uaddlv.Call.Result completedStorage addresses origins (afterEleven (nativeSetup s origins fields))
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
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ summed.nextblock.toNat ) ∧
    ∃ readCount, InternalRun world readCount
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryResultRead.afterReads k
        (Arm64ProgramEntryAllocation.allocation initial).1
        (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64)) summed) ∧
      (Arm64ProgramEntryResultVector.temps
        (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
        (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
        (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
        ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
        ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64)).get
        Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      ∃ conditionCount, InternalRun world conditionCount
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryResultCondition.afterCondition k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) summed) ∧
      ∃ pointerWritten, ∃ pointerEffect : Arm64PointerWrite.Result summedStorage 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8) pointerWritten,
        InternalRun world (conditionCount + 57)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
            (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
            (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) pointerWritten) ∧
        Arm64Registers.Represents addresses origins (fun r => r.val) summed.nextblock pointerWritten (.Vptr entry.block 0)
          (Arm64PointerWrite.nativeUpdate origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8)) ∧
        FrameBelow initial.nextblock initial pointerWritten ∧
        Arm64RegisterReads.WarmEntryCache false summed.nextblock pointerWritten (.Vptr entry.block 0) origins.stack ∧
        (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
        ∃ repeatWritten repeatAfter, ∃ repeatResult : Arm64MovImmediate.OrdinaryCall.Result pointerEffect.storage
          1 ((fields 0).setWidth 64) addresses origins (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))
          (Arm64ProgramEntryOrdinaryMovePath.callCont initial (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) k (fields 0)) repeatWritten repeatAfter,
          InternalRun world (conditionCount + 57 + 210)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
              (Arm64ProgramEntryAllocation.allocation initial).1
              (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
              (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) repeatAfter) ∧
          Arm64Registers.Represents addresses origins (fun r => r.val) pointerWritten.nextblock repeatAfter (.Vptr entry.block 0)
            (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).state ∧
          (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).events = [] ∧ (Reference.AArch64.step (Arm64ProgramEntryRepeatMovNative.beforeNative origins (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))).fault = none ∧
          FrameBelow initial.nextblock initial repeatAfter ∧
          (∀ j, CC.Mem.load CC.Mptr repeatAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
          Arm64RegisterReads.WarmEntryCache false pointerWritten.nextblock repeatAfter (.Vptr entry.block 0) origins.stack ∧
          (Arm64Producer.allocation initial).2.nextblock.toNat ≤ repeatAfter.nextblock.toNat ∧
          (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
          CC.Star (CC.Step2 world)
            (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
            (CC.Eapp traces.flatten trace)
            (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
              (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) repeatAfter) ∧
          ∃ pointerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat,
          ∃ constantWritten constantAfter, ∃ constantResult : Arm64MovImmediate.OrdinaryCall.Result
            (repeatResult.storage pointerBound) 2 (16#64) addresses origins (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))
            (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1
              (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterSecond k)) constantWritten constantAfter,
            InternalRun world (conditionCount + 57 + 210 + 207)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
                (Arm64ProgramEntryAllocation.allocation initial).1
                (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) summed)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
                (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) constantAfter) ∧
            Arm64Registers.Represents addresses origins (fun r => r.val) constantAfter.nextblock constantAfter (.Vptr entry.block 0)
              (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state ∧
            (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).events = [] ∧ (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).fault = none ∧
            FrameBelow initial.nextblock initial constantAfter ∧
            (∀ j, CC.Mem.load CC.Mptr constantAfter entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
            Arm64RegisterReads.WarmEntryCache false constantAfter.nextblock constantAfter (.Vptr entry.block 0) origins.stack ∧
            (Arm64Producer.allocation initial).2.nextblock.toNat ≤ constantAfter.nextblock.toNat ∧
            CC.Star (CC.Step2 world)
              (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
              (CC.Eapp traces.flatten trace)
              (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
                (Arm64ProgramEntryAllocation.allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) constantAfter) ∧
            Arm64ProducerTailFrame.Frame initial entry ready constantAfter ∧
            CC.Mem.load .Mint8unsigned constantAfter abiLocal.block 0 = some (.Vint 2) ∧
            CC.Mem.load CC.Mptr constantAfter entry.block 704 = some (.Vptr abiLocal.block 0) ∧
            (∀ (tags : StackTagLocal initial) (i : Fin 24),
              CC.Mem.load .Mint8unsigned constantAfter tags.block (i.val : Int) = some (.Vint 0)) ∧
      Nonempty (Arm64MemsetHeaderView.View initial summed entry) ∧
      Nonempty (Arm64MemsetHeaderView.View initial constantAfter entry) ∧
      ∃ reached : Reached summedStorage abiLocal,
      ∀ (cell : TailLocal initial 5)
        (providers : Arm64ProgramEntryMemoryPacket.Providers
          (Arm64ProgramEntryMemoryPacket.prepare pointerEffect pointerBound repeatResult constantResult
            reached.view reached.resources reached.spAtBase abiLocal reached.abiHeader reached.abiKind reached.tagBytes).view
          abiLocal (fields 0) constantAfter cell),
      CC.isCallCont k = true →
      ∃ gprs helperFlags helperVectors stored returned trace,
        Arm64ProgramEntryTerminalFree.FreeResult initial stored returned ∧
        CC.Star (CC.Step2 world)
          (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial) trace
          (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord
            (Arm64ProgramEntryComplete.sourceResult fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)))
            (fields 0) (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state
            gprs helperFlags helperVectors (Arm64MemsetLossSetup.byte (fields 0)))) k returned) ∧
        FrameBelow initial.nextblock initial returned := by
  obtain ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,continuation⟩ :=
    Arm64ProgramEntryUaddlvStackRightsPrefixNative.entry_corresponds initial ctxBlock ctxOfs k abiLocal addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
      first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth imm column negate literal
      firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded
      ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded noError firstFetched keepFetched thirdFetched
      fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
  have readyBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ ready.nextblock.toNat :=
    Nat.le_of_eq (congrArg (fun block : CC.Block => block.toNat) readyNext.symm)
  refine ⟨entry,header,ready,temps,traces,length,readyNext,entryRun, ctxRead,readyPacket,?_⟩
  intro supplied trace origin outcome
  obtain ⟨stackPacket⟩ := readyPacket
  obtain ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
      thirdWritten,thirdAfter,thirdStorage,facts3,
      fourthWritten,fourthAfter,fourthStorage,facts4,
      fifthWritten,after,finalStorage,facts5,
      sixthWritten,final,compareStorage,facts6,
      count,value,raw,tag,seventhWritten,selected,selectedStorage,facts7,
      count8,eighthWritten,negated,negatedStorage,facts8,
      count9,ninthWritten,combined,combinedStorage,facts9,
      count10,tenthWritten,completed,completedStorage,facts10,
      count11,eleventhWritten,counted,countedStorage,facts11,
      count12,twelfthWritten,summed,summedStorage,facts12⟩ := continuation supplied trace origin outcome
  obtain ⟨result12,run12,registers12,events12,fault12,frame12,pointers12,warm12,bound12,priorTail,abiReadback,abiPointer,tagReads,⟨priorView⟩,priorResources,priorPermissions⟩ := facts12
  have original12 := And.intro result12 (And.intro run12 (And.intro registers12 (And.intro events12 (And.intro fault12 (And.intro frame12 (And.intro pointers12 (And.intro warm12 (bound12))))))))
  refine ⟨firstWritten,middle,secondWritten,pairAfter,pairStorage,
    thirdWritten,thirdAfter,thirdStorage,facts3,
    fourthWritten,fourthAfter,fourthStorage,facts4,
    fifthWritten,after,finalStorage,facts5,
    sixthWritten,final,compareStorage,facts6,
    count,value,raw,tag,seventhWritten,selected,selectedStorage,facts7,
    count8,eighthWritten,negated,negatedStorage,facts8,
    count9,ninthWritten,combined,combinedStorage,facts9,
    count10,tenthWritten,completed,completedStorage,facts10,
    count11,eleventhWritten,counted,countedStorage,facts11,
    count12,twelfthWritten,summed,summedStorage,original12,?_⟩
  obtain ⟨result7,run7,registers7,_events7,_fault7,frame7,pointers7,warm7,bound7⟩ := facts7
  obtain ⟨_,_,_,_,_,_,_,_,_,_,_,_,kept4,_,_,_⟩ := facts4
  obtain ⟨_,_,_,_,_,_,_,_,_,_,_,_,kept5,_,_,_⟩ := facts5
  have earlyCell (tags : Bool) (j : Fin 31) (not3 : (3 : Fin 31) ≠ j) (not4 : (4 : Fin 31) ≠ j)
      (chunk : CC.Chunk) :
      CC.Mem.load chunk final ((compareStorage.tables tags).cellBlock j) 0 =
        CC.Mem.load chunk thirdAfter ((thirdStorage.tables tags).cellBlock j) 0 :=
    (facts6.1.gpr_load tags j chunk 0).trans
      ((kept5.cell_load fourthStorage finalStorage tags j not4 chunk 0).trans
        (kept4.cell_load thirdStorage fourthStorage tags j not3 chunk 0))
  obtain ⟨bits,kind,kindCases,selectedRead⟩ := Arm64Cneg.selected_source result7
    (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) (pairStorage.spValue + (16#64))
    ((earlyCell false 1 (by decide) (by decide) .Mint64).trans facts3.2.2.2.2.1)
    ((earlyCell true 1 (by decide) (by decide) .Mint8unsigned).trans facts3.2.2.2.2.2.1)
    ((earlyCell false 2 (by decide) (by decide) .Mint64).trans facts3.2.2.1)
    ((earlyCell true 2 (by decide) (by decide) .Mint8unsigned).trans facts3.2.2.2.1)
  have tailCells (tags : Bool) (j : Fin 31) (chunk : CC.Chunk) (offset : Int) :
      CC.Mem.load chunk summed ((summedStorage.tables tags).cellBlock j) offset =
        CC.Mem.load chunk combined ((combinedStorage.tables tags).cellBlock j) offset :=
    (cell_from_locals countedStorage summedStorage original12.1.locals tags j chunk offset).trans
      ((cell_from_locals completedStorage countedStorage facts11.1.locals tags j chunk offset).trans
        (cell_from_locals combinedStorage completedStorage facts10.1.locals tags j chunk offset))
  have selectedKept := gpr_from_cells selectedStorage summedStorage 5 (fun tags chunk offset =>
    (tailCells tags 5 chunk offset).trans
      (((facts9.1.kept).cell_load negatedStorage combinedStorage tags 5 (by decide) chunk offset).trans
        (((facts8.1.kept).cell_load selectedStorage negatedStorage tags 5 (by decide) chunk offset))))
  have lhs := selectedKept.trans selectedRead
  have rhs : Arm64EntryMemory.gpr summed.nextblock summed (.Vptr entry.block 0) 7 =
      some (.Vlong (Arm64RegisterWrite.written true (Arm64Orn.Call.nativeResult (afterEight (nativeSetup s origins fields)))) , .Vint 0) := by
    change Arm64EntryMemory.gpr summed.nextblock summed (.Vptr entry.block 0) (7 : Fin 31).val = _
    rw [Arm64RegisterWrite.storage_gpr summedStorage 7,tailCells false 7 .Mint64 0,
      tailCells true 7 .Mint8unsigned 0,facts9.1.word,facts9.1.tag]
    rfl
  have currentRegisters := (Arm64RegisterStorageFrontier.represents_iff summedStorage ready.nextblock readyBound
    addresses origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).mp original12.2.2.1
  have currentWarm := (Arm64CacheLocalFrame.warm_iff ready.nextblock header readyBound original12.2.2.2.2.2.2.1
    false origins.stack).mp original12.2.2.2.2.2.2.2.1
  obtain ⟨readCount,readRun⟩ := Arm64ProgramEntryResultVector.execute summedStorage addresses origins (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state currentRegisters
    (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) k bits _ kind kindCases lhs rhs (fun _ => currentWarm)
  have finalCtx : (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
      (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
      (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
      ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
      ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64)).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) :=
    (Arm64ProgramEntryResultVector.context _ _ _ _ _).trans
    ((caller_context temps fields).trans ctxRead)
  have field := (Arm64ProgramEntryBody.context_read_frame original12.2.2.2.2.2.1 ctxBlock old ctxOfs 1).trans (reads 1)
  obtain ⟨conditionCount,conditionRun⟩ := Arm64ProgramEntryResultCondition.execute summedStorage
    (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state currentRegisters.flags _ k ctxBlock ctxOfs
    (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) finalCtx field
    (Arm64ProgramEntryResultVector.result _ _ _ _ _)
  obtain ⟨pointerWritten,pointerEffect,pointerRun,pointerRegisters,pointerKept⟩ :=
    Arm64ProgramEntryPointerWrites.execute summedStorage 0 addresses origins
      (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state currentRegisters _ k
  have headerFacts := original12.2.2.2.2.2.2
  have pointerWarm := pointerKept.warm summed.nextblock header headerFacts.2.2 headerFacts.1 false origins.stack currentWarm
  have retainedCtx : (Arm64ProgramEntryResultCondition.resultTemps (Arm64ProgramEntryResultVector.temps (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1))
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 5)
          (Reference.AArch64.gpr (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 7)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 3).setWidth 64)
          ((Reference.AArch64.readVector (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state 0).setWidth 64))
            (Arm64ProgramEntryResultCondition.nativeResult (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state) (fields 1) (Reference.AArch64.step (afterEleven (nativeSetup s origins fields))).state).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := by
    unfold Arm64ProgramEntryResultCondition.resultTemps Arm64ProgramEntryResultCondition.conditionTemps
      Arm64ProgramEntryResultCondition.priorityTemps
    repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact finalCtx
  have admitted := Arm64ProgramEntryRepeatMovAdmission.admission s origins fields first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched
  have pointerFrame := original12.2.2.2.2.2.1.trans pointerEffect.caller
  obtain ⟨repeatWritten,repeatAfter,repeatResult,repeatRun,repeatRegisters,repeatEvents,repeatFault⟩ :=
    Arm64ProgramEntryRepeatMovNative.execute summedStorage pointerEffect headerFacts.2.2 pointerFrame addresses origins
      (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)) currentRegisters (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) k ctxBlock ctxOfs (fields 0) old retainedCtx (reads 0)
      thirteenth imm column negate literal thirteenthDecoded admitted.2.1 admitted.2.2.1
  have pointerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat := by
    simpa only [pointerEffect.nextblock] using headerFacts.2.2
  have pointerPointers := pointerKept.pointers header headerFacts.1
  have actualWarm : Arm64RegisterReads.WarmEntryCache false pointerWritten.nextblock pointerWritten (.Vptr entry.block 0) origins.stack := by
    simpa only [pointerEffect.nextblock] using pointerWarm
  have repeatWarm := repeatResult.kept.warm pointerWritten.nextblock header pointerBound pointerPointers false origins.stack actualWarm
  have repeatPointers := repeatResult.kept.pointers header pointerPointers
  have repeatBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ repeatAfter.nextblock.toNat := by
    rw [repeatResult.nextblock,repeatResult.effect.nextblock]
    exact Nat.le_trans pointerBound (FrameBelow.allocVariables
      (Arm64MovImmediate.allocated_bound world pointerWritten) pointerWritten.nextblock (Nat.le_refl _)).1
  have repeatCtx : (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := by
    unfold Arm64ProgramEntryOrdinaryMoves.markTemps
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact retainedCtx
  have nextAdmitted := Arm64ProgramEntryRepeatMovAdmission.next_admission s origins fields first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched fourteenthFetched
  obtain ⟨constantWritten,constantAfter,constantResult,constantRun,constantRegisters,constantEvents,constantFault⟩ :=
    Arm64ProgramEntryConstantMovNative.execute addresses origins repeatResult pointerBound (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields)) repeatRegisters
      (Arm64ProgramEntryOrdinaryMoves.markTemps (resultTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) (fields 0)) k fourteenth fourteenthDecoded nextAdmitted.2.1 nextAdmitted.2.2.1
  have constantPointers := constantResult.kept.pointers header repeatPointers
  have actualRepeatWarm := (Arm64CacheLocalFrame.warm_iff pointerWritten.nextblock header pointerBound
    repeatPointers false origins.stack).mp repeatWarm
  have constantWarm := constantResult.kept.warm repeatAfter.nextblock header repeatBound repeatPointers false origins.stack actualRepeatWarm
  have actualConstantWarm := (Arm64CacheLocalFrame.warm_iff repeatAfter.nextblock header repeatBound
    constantPointers false origins.stack).mp constantWarm
  have actualConstantRegisters := (Arm64RegisterStorageFrontier.represents_iff (constantResult.storage repeatBound)
    repeatAfter.nextblock repeatBound addresses origins (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state).mp constantRegisters
  have constantBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ constantAfter.nextblock.toNat := by
    rw [constantResult.nextblock,constantResult.effect.nextblock]
    exact Nat.le_trans repeatBound (FrameBelow.allocVariables
      (Arm64MovImmediate.allocated_bound world repeatAfter) repeatAfter.nextblock (Nat.le_refl _)).1
  have complete := star_trans original12.2.1 (((readRun.trans conditionRun).trans pointerRun).trans repeatRun).sound
  have constantComplete := star_trans original12.2.1 ((((readRun.trans conditionRun).trans pointerRun).trans repeatRun).trans constantRun).sound
  have pointerTail := Arm64ProducerTailFrame.of_kept entry 0 pointerKept
  have repeatTail := Arm64ProducerTailFrame.of_kept entry 1 repeatResult.kept
  have constantTail := Arm64ProducerTailFrame.of_kept entry 2 constantResult.kept
  have sourceTail := (pointerTail.trans repeatTail).trans constantTail
  have tailFrame := priorTail.trans sourceTail
  have abiObserved := sourceTail.abi abiLocal abiPointer abiReadback
  have finalTags (tags : StackTagLocal initial) (i : Fin 24) :=
    (sourceTail.tail 2 ⟨tags.block,tags.binding⟩ .Mint8unsigned (i.val : Int)).trans (tagReads tags i)
  refine ⟨readCount,readRun,finalCtx,_,readRun.trans conditionRun,pointerWritten,pointerEffect,
    (readRun.trans conditionRun).trans pointerRun,pointerRegisters,pointerFrame,pointerWarm,retainedCtx,
    repeatWritten,repeatAfter,repeatResult,((readRun.trans conditionRun).trans pointerRun).trans repeatRun,
    repeatRegisters,repeatEvents,repeatFault,pointerFrame.trans repeatResult.caller,
    repeatPointers,repeatWarm,repeatBound,repeatCtx,?_,pointerBound,constantWritten,constantAfter,constantResult,
    (((readRun.trans conditionRun).trans pointerRun).trans repeatRun).trans constantRun,actualConstantRegisters,
    constantEvents,constantFault,(pointerFrame.trans repeatResult.caller).trans constantResult.caller,
    constantPointers,actualConstantWarm,constantBound,?_,tailFrame,abiObserved.2,abiObserved.1,finalTags,⟨Arm64MemsetHeaderView.of_frame stackPacket.view priorTail⟩,⟨Arm64MemsetHeaderView.of_frame stackPacket.view tailFrame⟩,?_⟩
  · simpa only [CC.Eapp,CC.E0,List.append_nil] using complete
  · simpa only [CC.Eapp,CC.E0,List.append_nil] using constantComplete

  · have nativeSP := Arm64ProgramEntryPrefixSp.setup s origins fields first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth
      imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded
      eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded noError
      firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
    have rawSP := Arm64ProgramEntryPrefixSp.storage summedStorage addresses origins
      (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields)) currentRegisters nativeSP
    let reached : Reached summedStorage abiLocal := {
      view := priorView, resources := priorResources, spAtBase := rawSP,
      abiHeader := abiPointer, abiKind := abiReadback,
      tagBytes := fun i => tagReads priorView.tags i }
    refine ⟨reached,?_⟩
    intro cell providers hk
    have sourceRun : CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond k
          (Arm64ProgramEntryAllocation.allocation initial).1
          (Arm64ProgramEntryComplete.sourceTemps temps fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))) constantAfter) := by
      simpa only [CC.Eapp,CC.E0,List.append_nil,Arm64ProgramEntryComplete.sourceTemps] using constantComplete
    exact Arm64ProgramEntryComplete.compose fields (Arm64ProgramEntryRepeatMovAdmission.afterTwelve (nativeSetup s origins fields))
      pointerEffect pointerBound repeatResult constantResult reached.view reached.resources reached.spAtBase
      abiLocal reached.abiHeader reached.abiKind reached.tagBytes cell ready stackPacket tailFrame providers temps k hk
      ctxBlock ctxOfs old ctxRead reads (CC.Eapp traces.flatten trace) sourceRun
      ((pointerFrame.trans repeatResult.caller).trans constantResult.caller)
      (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins (nativeSetup s origins fields))).state

end KProgFormal.ClightRefinement.Arm64ProgramEntryResultStackRights
