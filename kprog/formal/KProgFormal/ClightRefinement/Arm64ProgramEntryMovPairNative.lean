import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPair
import KProgFormal.ClightRefinement.Arm64MovPairNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovPairNative

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMovCall

/-- Both original source calls and their actual same-heap resources correspond
to the two admitted fetched LNSym steps. The source provider trace remains
explicit; this does not discharge physical ABI/provider validity. -/
theorem corresponds {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) = some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (Arm64Producer.allocation initial).2.access)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (mark priority : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (markRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (priorityRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 32))) = some (.Vint priority))
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] (Arm64Nop.allocation world before).2 trace (.Vlong origins.stack) supplied)
    (outcome : Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world before).2 supplied)
    (first keep : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding) :
    ∃ firstWritten middle secondWritten after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps le mark) priority) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (Reference.AArch64.step s).state).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      (Reference.AArch64.step (Reference.AArch64.step s).state).events = [] ∧
      (Reference.AArch64.step (Reference.AArch64.step s).state).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some middle ∧
      FrameBelow before.nextblock firstWritten middle ∧
      middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some after ∧
      FrameBelow middle.nextblock secondWritten after ∧
      after.contents = secondWritten.contents ∧ after.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨firstWritten, middle, secondWritten, after, finalStorage, word, tag, run, registers,
      frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
      secondFree, secondFreeFrame, secondContents, afterNext, secondReleased⟩ :=
    Arm64ProgramEntryMovPair.execute storage header pointers access bound cold addresses origins s represented
      le k ctxBlock ctxOfs mark priority ctx old markRead priorityRead trace provider outcome
  have native := Arm64MovPairNative.steps s first keep mark priority imm column negate literal
    firstDecoded keepDecoded noError firstFetched keepFetched
  refine ⟨firstWritten, middle, secondWritten, after, finalStorage, word, tag, run, ?_, ?_, ?_, ?_, ?_,
    frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
    secondFree, secondFreeFrame, secondContents, afterNext, secondReleased⟩
  · rw [native.2]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0) _ (read_pc s.machine + 8#64)).mpr registers
  · rw [native.1]
  · rw [native.1]
  · rw [native.2]
  · rw [native.2]

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovPairNative
