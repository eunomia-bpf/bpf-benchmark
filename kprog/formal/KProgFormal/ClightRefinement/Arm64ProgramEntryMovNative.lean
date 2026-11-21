import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall
import KProgFormal.ClightRefinement.Arm64MovKeepNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.Native

/-- The fetched native fields consume the low halfword, while the Clight
argument and its compiler temporary retain the actual full word. -/
theorem reference_word_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 64) (column : Fin 4) (narrow : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i (imm.setWidth 16) column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (mergeWord (Reference.AArch64.gpr s i) imm column) narrow), [], none⟩ := by
  simpa only [mergeWord_low16] using
    reference_step s instruction i (imm.setWidth 16) column narrow valid decoded noError fetched

end KProgFormal.ClightRefinement.Arm64MovKeep.Native

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)

/-- The actual source MOVK call refines its fetched LNSym step, with no
restriction on priority. Actual scalar loads identify the native DST value;
source control, writable storage and real frame release are retained. -/
theorem keep_corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (bits : BitVec 64) (priority : BitVec 32)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont)
    (loaded : le.get Arm64ProgramFixture._t'167 = some (.Vint priority))
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord bits (priority.setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      InternalRun world 206
        (.State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 1 := by
  have observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) (1 : Fin 31).val =
      some (.Vlong bits, .Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage 1, word, tag]
    rfl
  have input := Arm64MovKeep.scalar_native_bits addresses origins s before.nextblock before (.Vptr entry.block 0)
    1 bits observed represented
  have native := Arm64MovKeep.Native.reference_word_step s instruction 1 (priority.setWidth 64) 1 false
    (by decide) decoded noError fetched
  obtain ⟨written, after, finalStorage, finalWord, finalTag, run, registers, frame, freed,
      freeFrame, contents, next, released, kept, _finalBound⟩ :=
    execute_keep storage bound addresses origins s bits priority word tag represented le k loaded
  refine ⟨written, after, finalStorage, finalWord, finalTag, run, ?_, ?_, ?_, frame, freed,
    freeFrame, contents, next, released, kept⟩
  · rw [native]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s 1
        (Arm64MovKeep.mergeWord (Reference.AArch64.gpr s 1) (priority.setWidth 64) 1) false)
      (read_pc s.machine + 4#64)).mpr (by simpa only [input] using registers)
  · rw [native]
  · rw [native]

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall
