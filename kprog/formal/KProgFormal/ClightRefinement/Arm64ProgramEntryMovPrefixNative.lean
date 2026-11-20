import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefix
import KProgFormal.ClightRefinement.Arm64MovPairNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefixNative

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps afterKeep)

/-- The actual wrapper/input/setup/MOV source prefix returns the register view
of both admitted fetched native steps. Setup preserves program/PC/error, so
its architectural input-view update adds no native fetch/error premise. The
later origin outcome is admitted only at the actual reached source heap. -/
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
    (first keep : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding) :
    ∃ entry : HeaderLocal initial, ∃ header : (j : Fin 12) → HeaderSourceLocal initial j, ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
      ∀ (supplied : CC.Mem) (trace : CC.Trace),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
          [.Vint 1] (Arm64Nop.allocation world ready).2 trace (.Vlong origins.stack) supplied →
        Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world ready).2 supplied →
    ∃ firstWritten middle secondWritten after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace) (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).state ∧
      (Reference.AArch64.step (nativeSetup s origins fields)).events = [] ∧ (Reference.AArch64.step (nativeSetup s origins fields)).fault = none ∧
      (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).events = [] ∧ (Reference.AArch64.step (Reference.AArch64.step (nativeSetup s origins fields)).state).fault = none ∧
      FrameBelow initial.nextblock initial after ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1) = some middle ∧
      FrameBelow ready.nextblock firstWritten middle ∧
      middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world ready).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some after ∧
      FrameBelow middle.nextblock secondWritten after ∧
      after.contents = secondWritten.contents ∧ after.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock after (.Vptr entry.block 0) origins.stack := by
  have setupPc : read_pc (nativeSetup s origins fields).machine = read_pc s.machine :=
    Arm64ProgramEntryBodyView.native_other s origins fields .PC (by intro equal; cases equal)
      (by intro flag equal; cases equal)
  have setupError : read_err (nativeSetup s origins fields).machine = .None :=
    (Arm64ProgramEntryBodyView.native_other s origins fields .ERR (by intro equal; cases equal)
      (by intro flag equal; cases equal)).trans noError
  have program := (Arm64ProgramEntryBodyView.native_resources s origins fields).2.1
  have setupFirst : fetch_inst (read_pc (nativeSetup s origins fields).machine)
      (nativeSetup s origins fields).machine = some first.encoding := by
    rw [setupPc]
    simpa only [fetch_inst, program] using firstFetched
  have setupKeep : fetch_inst (read_pc (nativeSetup s origins fields).machine + 4#64)
      (nativeSetup s origins fields).machine = some keep.encoding := by
    rw [setupPc]
    simpa only [fetch_inst, program] using keepFetched
  have checked := Arm64MovPairNative.steps (nativeSetup s origins fields) first keep (fields 0) (fields 1)
    imm column negate literal firstDecoded keepDecoded setupError setupFirst setupKeep
  obtain ⟨entry, header, ready, temps, traces, length, entryRun, continuation⟩ :=
    Arm64ProgramEntryMovPrefix.entry_pair initial ctxBlock ctxOfs k addresses ctxWord context values provider
      flags flagProvider vectors vectorProvider origins s native fields old reads
  refine ⟨entry, header, ready, temps, traces, length, entryRun, ?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten, middle, secondWritten, after, finalStorage, word, tag, run, registers,
      frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
      secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, finalPointers, finalWarm⟩ :=
    continuation supplied trace origin outcome
  refine ⟨firstWritten, middle, secondWritten, after, finalStorage, word, tag, run, ?_, ?_, ?_, ?_, ?_,
    frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
    secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, finalPointers, finalWarm⟩
  · rw [checked.2]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0) _
      (read_pc (nativeSetup s origins fields).machine + 8#64)).mpr registers
  · rw [checked.1]
  · rw [checked.1]
  · rw [checked.2]
  · rw [checked.2]

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefixNative
