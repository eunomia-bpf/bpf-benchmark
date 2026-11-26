import KProgFormal.ClightRefinement.Arm64MemcpyClobberReturn

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReturn

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The original local ranges are released by the actual return. Older blocks
retain their current bytes and permissions while callee permissions change. -/
structure FreeResult (before current after : CC.Mem) : Prop where
  freed : CC.Mem.freeList current (CC.blocksOfEnv world.genv_cenv (Arm64MemcpySource.allocation before).1) = some after
  caller : FrameBelow before.nextblock current after
  contents : after.contents = current.contents
  nextblock : after.nextblock = current.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64MemcpySource.allocation before).1, ∀ ofs,
    row.2.1 ≤ ofs → ofs < row.2.2 → ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false

/-- The reached shared caller supplies each actual live Freeable range,
including through providers whose cache cells changed on their supplied heap. -/
theorem free {initial seed before current : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberCoreState.Saved (Arm64MemcpySource.allocation before).1 base abi byte rawR0 n cell flagValue current) :
    ∃ after, FreeResult before current after := by
  obtain ⟨after,freed,frame,contents,next,released⟩ := deallocate_live_locals (Arm64MemcpySource.allocated before) prior.callee
  exact ⟨after,freed,frame,contents,next,released⟩

/-- Follow the actual memcpy loop break and skip_call, consuming the real
PTree-enumerated eight-local freeList to its original Returnstate. -/
theorem exit {initial seed before current : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberCoreState.Saved (Arm64MemcpySource.allocation before).1 base abi byte rawR0 n cell flagValue current)
    (outerLe : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after, FreeResult before current after ∧ InternalRun world 3
      (.State handler .Sskip (Arm64MemcpySource.continuation k) (Arm64MemcpySource.allocation before).1 outerLe current)
      (.Returnstate .Vundef k after) := by
  obtain ⟨after,result⟩ := free prior
  refine ⟨after,result,?_⟩
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (.skip_call _ _ _ _ _ _ hk result.freed) (.refl _)

end KProgFormal.ClightRefinement.Arm64MemcpyReturn
