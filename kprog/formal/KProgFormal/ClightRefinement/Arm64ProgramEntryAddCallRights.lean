import KProgFormal.ClightRefinement.Arm64ProgramEntryAddCall
import KProgFormal.ClightRefinement.Arm64AddImmediateNativeCallRights

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddCallRights

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryAddCall

/-- The original ADD callsite and its complete handler and return retain
all actual producer permissions and the same fetched native-step result. -/
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
    (le : CC.TempEnv) (k : CC.Cont) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 2) 0 =
        some (.Vlong (storage.spValue + (16#64))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 2) 0 = some (.Vint (4#32)) ∧
      InternalRun world 337
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMovCall.afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterAdd k
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
      Arm64CacheLocalFrame.Kept initial before after 2 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  have entered := enter entry le k before
  obtain ⟨written, after, finalStorage, word, tag, run, registers, events, fault, frame, freed,
      freeFrame, contents, next, released, kept, finalPointers, finalWarm, finalBound,permissionFrame⟩ :=
    Arm64AddImmediate.CallRights.corresponds storage bound header pointers addresses origins s represented warm
      2 (16#12) false (.Vlong (255#64)) (.Vlong (255#64)) (callCont initial le k) rfl
      instruction decoded noError fetched
  have returned := leave initial le k after
  exact ⟨written, after, finalStorage, word, tag, (entered.trans run).trans returned,
    registers, events, fault, frame, freed, freeFrame, contents, next, released, kept, finalPointers, finalWarm, finalBound,permissionFrame⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddCallRights
