import KProgFormal.ClightRefinement.Arm64ClobberReleaseTagComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

/-- The actual memcpy caller opens the shared helper and executes the
original byte and tag release scans. Each real provider and store consumes
the same current caller/flag packet and the actual reached memory. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {outerLe : CC.TempEnv} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 before outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (inputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (k : CC.Cont) :
    ∃ after nextLe trace,
      ∃ _current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore (-16#64) 16
        cell flagValue outerLe 20 after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe before) trace
        (.State helper Arm64MemsetClobberEntry.rest
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k))
          CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  let packet := Arm64ClobberCoreState.of_memcpy (Arm64ClobberMemoryState.of_memcpy current flag)
  have opened := Arm64MemcpyClobberEntry.execute current k
  obtain ⟨after,nextLe,trace,next,scans,frame,access,frontier⟩ :=
    Arm64ClobberReleaseTagComplete.original packet inputs (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k)
  refine ⟨after,nextLe,trace,next,?_,frame,access,frontier⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans opened.sound scans

end KProgFormal.ClightRefinement.Arm64MemcpyClobberRelease
