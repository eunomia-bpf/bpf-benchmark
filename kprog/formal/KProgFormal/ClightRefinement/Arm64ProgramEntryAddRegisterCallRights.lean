import KProgFormal.ClightRefinement.Arm64AddRegisterNativeCallRights

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterCallRights
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryAddRegisterCall (enter leave callCont afterRegister)

/-- The original fourth caller executes its real packed arguments and resumes
its untouched source successor, refining the fetched native ADD throughout. -/
theorem corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (lhs raw : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 2) 0 = some (.Vlong raw))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 2) 0 = some (.Vint (4#32)))
    (le : CC.TempEnv) (k : CC.Cont)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 3) 0 = some (.Vlong (lhs + (raw + origins.stack))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 3) 0 = some (.Vint 0) ∧
      InternalRun world 473
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAddCall.afterAdd k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterRegister k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step native).state ∧
      (Reference.AArch64.step native).events = [] ∧ (Reference.AArch64.step native).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 3 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  have entered := enter entry le k before
  obtain ⟨written, after, finalStorage, word, tag, run, registers, events, fault, frame, freed,
      freeFrame, contents, next, released, kept, finalPointers, finalWarm, finalBound,permissions⟩ :=
    Arm64AddRegisterNativeCallRights.corresponds storage bound header pointers addresses origins native represented warm
      lhs raw lhsWord lhsTag rhsWord rhsTag (callCont initial le k) rfl instruction decoded noError fetched
  have returned := leave initial le k after
  exact ⟨written, after, finalStorage, word, tag, (entered.trans run).trans returned,
    registers, events, fault, frame, freed, freeFrame, contents, next, released, kept, finalPointers, finalWarm, finalBound,permissions⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterCallRights
