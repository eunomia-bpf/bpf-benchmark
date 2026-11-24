import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMovePath
import KProgFormal.ClightRefinement.Arm64MovImmediateWide

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoveNative

open Arm64ProgramEntryAllocation (world allocation)
open Arm64MovImmediate

/-- The real context-derived MOV call refines the same decoded and fetched
LNSym instruction. Every actual C store and frame release remains in Result. -/
theorem first {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (block : CC.Block) (ofs : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr block ofs))
    (read : CC.Mem.loadv .Mint32 m
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (instruction : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Wide.literal imm column false negate)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Wide.fields 1 imm column false negate)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, OrdinaryCall.Result storage 1 (mark.setWidth 64) addresses origins s
        (Arm64ProgramEntryOrdinaryMovePath.callCont initial le k mark) written after ∧
      InternalRun world 210
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
          (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
          (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨written,after,result,run⟩ := Arm64ProgramEntryOrdinaryMovePath.first storage bound addresses origins s represented
    le k block ofs mark ctx read
  have native := Wide.reference_step s instruction 1 imm column false negate (by intro impossible; cases impossible)
    decoded noError fetched
  have actual := result.registers
  rw [literal] at actual
  rw [native]
  exact ⟨written,after,result,run,
    (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s 1 (Wide.literal imm column false negate) false)
      (read_pc s.machine + 4#64)).mpr actual,rfl,rfl⟩

/-- The two original constant16 calls refine the same imported MOVZ X2,#16
step at their own reached positions and preserve their real continuations. -/
theorem constant {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (third : Bool) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Wide.fields 2 (16#16) 0 false false)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, OrdinaryCall.Result storage 2 (16#64) addresses origins s
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le
          (.Kseq (Arm64ProgramEntryOrdinaryMovePath.afterConstant third) k)) written after ∧
      InternalRun world 207
        (.State Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryOrdinaryMovePath.beforeConstant third) k
          (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryOrdinaryMovePath.afterConstant third) k
          (allocation initial).1 le after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨written,after,result,run⟩ := Arm64ProgramEntryOrdinaryMovePath.constant storage bound third addresses origins s represented le k
  have native := Wide.reference_step s instruction 2 (16#16) 0 false false (by intro impossible; cases impossible)
    decoded noError fetched
  rw [native]
  exact ⟨written,after,result,run,
    (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s 2 (16#64) false) (read_pc s.machine + 4#64)).mpr result.registers,rfl,rfl⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoveNative
