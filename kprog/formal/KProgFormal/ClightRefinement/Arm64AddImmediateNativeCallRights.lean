import KProgFormal.ClightRefinement.Arm64AddImmediateCallRights
import KProgFormal.ClightRefinement.Arm64AddImmediateNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.CallRights

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryLinked (ge)

/-- The complete actual generic call refines the fetched mature ADD-from-SP
step. Source raw/tag storage, real release, cache and caller facts survive. -/
theorem corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (i : Fin 31) (imm : BitVec 12) (shifted : Bool) (src2 src3 : CC.Val)
    (k : CC.Cont) (valid : CC.isCallCont k = true)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (Native.fields i imm shifted)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
        some (.Vlong (storage.spValue + Native.operand imm shifted)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint (4#32)) ∧
      InternalRun ge 333
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i (Native.operand imm shifted) src2 src3) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after i ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  have sourceSP := Arm64AddOperandReads.Linked.sp_native storage addresses origins s represented
  have native := Native.reference_step s instruction i imm shifted decoded noError fetched
  have update := Native.pointer_update s i imm shifted origins storage.spValue sourceSP
  obtain ⟨written, after, finalStorage, word, tag, run, registers, frame, freed, freeFrame,
      contents, next, released, kept, finalPointers, finalWarm, finalBound,permissionFrame⟩ :=
    execute storage bound header pointers addresses origins s represented warm i (Native.operand imm shifted) src2 src3 k valid
  refine ⟨written, after, finalStorage, word, tag, run, ?_, ?_, ?_, frame, freed, freeFrame,
    contents, next, released, kept, finalPointers, finalWarm, finalBound,permissionFrame⟩
  · rw [native]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + Native.operand imm shifted) false)
      (read_pc s.machine + 4#64)).mpr (by simpa only [update] using registers)
  · rw [native]
  · rw [native]

end KProgFormal.ClightRefinement.Arm64AddImmediate.CallRights
