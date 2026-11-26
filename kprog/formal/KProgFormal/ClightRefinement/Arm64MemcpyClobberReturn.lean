import KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete
import KProgFormal.ClightRefinement.Arm64MemsetClobberReturn

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyClobberReturn

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

/-- The real helper break and empty-local return restore this memcpy caller's
own eight-local environment and saved temps on the same reached heap. -/
theorem restore (before m : CC.Mem) (outerLe helperLe : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 4
      (.State helper .Sskip
        (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont before outerLe k)) CC.emptyEnv helperLe m)
      (.State Arm64MemcpySource.handler .Sskip k (Arm64MemcpySource.allocation before).1 outerLe m) := by
  have leave := Arm64MemsetClobberReturn.exit helperLe m (Arm64MemcpyClobberEntry.callCont before outerLe k) rfl
  have returned : InternalRun world 1 (.Returnstate .Vundef (Arm64MemcpyClobberEntry.callCont before outerLe k) m)
      (.State Arm64MemcpySource.handler .Sskip k (Arm64MemcpySource.allocation before).1 outerLe m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact leave.trans returned

/-- All150 actual provider outcomes and176 original stores, followed by the
real helper exit, empty-local free and return to the same memcpy caller. -/
theorem original {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64ClobberRegisterComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (flagInputs : ∀ selectedGprs, Arm64ClobberFlagsComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs)
    (vectorInputs : ∀ selectedGprs selectedFlags, Arm64ClobberVectorsComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs selectedFlags)
    (k : CC.Cont) :
    ∃ after nextLe selectedGprs selectedFlags values trace,
      ∃ _current : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs selectedFlags 64 values after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.State Arm64MemcpySource.handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 outerLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨after,helperLe,selectedGprs,selectedFlags,values,trace,packet,run,frame,access,next⟩ :=
    Arm64ClobberVectorsComplete.original current flag byteInputs registerInputs flagInputs vectorInputs k
  have returned := restore calleeBefore after outerLe helperLe k
  refine ⟨after,helperLe,selectedGprs,selectedFlags,values,trace,packet,?_,frame,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans run returned.sound

end KProgFormal.ClightRefinement.Arm64MemcpyClobberReturn
