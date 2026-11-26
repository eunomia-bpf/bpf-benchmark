import KProgFormal.ClightRefinement.Arm64MemcpyClobberComplete
import KProgFormal.ClightRefinement.Arm64MemcpyTransferProgram

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The original program Kcall none and following sequence restore the saved
program env/temps and reach its actual statement after memcpy. -/
theorem returned (initial : CC.Mem) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.Returnstate .Vundef (Arm64MemcpyProgramEntry.callCont initial le k) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

/-- One original program-call execution retains all16 real byte copies,
both active tag-transfer effects, the complete shared helper/provider trace,
eight actual local frees and the saved program continuation in one witness. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64ClobberRegisterComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (flagInputs : ∀ outerLe selectedGprs, Arm64ClobberFlagsComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe selectedGprs)
    (vectorInputs : ∀ outerLe selectedGprs selectedFlags, Arm64ClobberVectorsComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe selectedGprs selectedFlags) :
    ∃ after written selectedGprs selectedFlags selectedVectors trace,
      ∃ _current : Arm64ClobberResult.Packet base abi byte (-16#64) 16 selectedGprs selectedFlags selectedVectors cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨middle,copyLe,copyCurrent,copyRun,_copied,copyFlag,copyFrame,pbound,_cbound⟩ :=
    Arm64MemcpyTransferProgram.execute prior bound le k addresses cell flagValue flag
  obtain ⟨after,written,selectedGprs,selectedFlags,selectedVectors,trace,packet,procedure,freed,frame,next⟩ :=
    Arm64MemcpyClobberComplete.original copyCurrent copyFlag (byteInputs copyLe) (registerInputs copyLe)
      (flagInputs copyLe) (vectorInputs copyLe) bound (Arm64MemcpyProgramEntry.callCont initial le k) rfl
  refine ⟨after,written,selectedGprs,selectedFlags,selectedVectors,trace,packet,?_,freed,copyFrame.trans frame,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
      star_trans (star_trans copyRun procedure) (returned initial le after k).sound
  · rw [next]
    exact pbound

end KProgFormal.ClightRefinement.Arm64MemcpyCompleteProgram
