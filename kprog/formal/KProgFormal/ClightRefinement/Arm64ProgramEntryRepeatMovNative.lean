import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoveNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovNative

open Arm64ProgramEntryAllocation (world allocation)
open Arm64MovImmediate

/-- Actual pointer setup between the twelfth and thirteenth instruction calls. -/
def beforeNative (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State) :
    Reference.AArch64.State :=
  Arm64PointerWrite.nativeUpdate origins s 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8)

/-- The existing imported GPR write preserves PC, error and original code. -/
theorem pointer_control (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State) :
    read_pc (beforeNative origins s).machine = read_pc s.machine ∧
    read_err (beforeNative origins s).machine = read_err s.machine ∧
    (beforeNative origins s).machine.program = s.machine.program := by
  constructor
  · simp [beforeNative,Arm64PointerWrite.nativeUpdate,Arm64RegisterWrite.nativeUpdate,read_pc,r_of_w_different]
  constructor
  · simp [beforeNative,Arm64PointerWrite.nativeUpdate,Arm64RegisterWrite.nativeUpdate,read_err,r_of_w_different]
  · simp [beforeNative,Arm64PointerWrite.nativeUpdate,Arm64RegisterWrite.nativeUpdate,w,write_base_gpr]

/-- The original input and caller frame derive the repeated mark field load.
The same pointer effect derives storage and native inputs for the entire call. -/
theorem execute {initial before pointerWritten : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial before entry)
    (effect : Arm64PointerWrite.Result storage 0 (Arm64ProgramEntryPointerWrites.raw 0) (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (frame : FrameBelow initial.nextblock initial pointerWritten)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (mark : BitVec 32)
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (read : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (instruction : Reference.AArch64.Instruction) (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Wide.literal imm column false negate)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Wide.fields 1 imm column false negate)))
    (noError : read_err (beforeNative origins s).machine = .None)
    (fetched : fetch_inst (read_pc (beforeNative origins s).machine) (beforeNative origins s).machine = some instruction.encoding) :
    ∃ written after, OrdinaryCall.Result effect.storage 1 (mark.setWidth 64) addresses origins (beforeNative origins s)
        (Arm64ProgramEntryOrdinaryMovePath.callCont initial le k mark) written after ∧
      InternalRun world 210
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
          (allocation initial).1 le pointerWritten)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
          (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) pointerWritten.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step (beforeNative origins s)).state ∧
      (Reference.AArch64.step (beforeNative origins s)).events = [] ∧
      (Reference.AArch64.step (beforeNative origins s)).fault = none := by
  have actualBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat := by
    simpa only [effect.nextblock] using bound
  have actualRegisters : Arm64Registers.Represents addresses origins (fun r => r.val)
      pointerWritten.nextblock pointerWritten (.Vptr entry.block 0) (beforeNative origins s) := by
    simpa only [effect.nextblock,beforeNative] using effect.represents addresses origins s represented
  have field := (Arm64ProgramEntryBody.context_read_frame frame ctxBlock old ctxOfs 0).trans read
  exact Arm64ProgramEntryOrdinaryMoveNative.first effect.storage actualBound addresses origins (beforeNative origins s)
    actualRegisters le k ctxBlock ctxOfs mark ctx field instruction imm column negate literal decoded noError fetched

end KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovNative
