import KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceSP

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyPrefix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The same actual body110 initializes its tag, calls the real R1 tag
reader, selects the source-SP arm, then calls the real R1 pointer reader
and reads SP. All current observations belong to this one execution. -/
theorem execute {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    ∃ nextLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m nextLe,
      InternalRun world 83
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler .Sskip (Arm64MemcpyTransferCopyTag.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 nextLe m) ∧
      nextLe.get Arm64Program._t'79 = some (.Vint 1) ∧
      nextLe.get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
      nextLe.get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
      nextLe.get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
      nextLe.get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  obtain ⟨tagCurrent,tagRun⟩ := Arm64MemcpyTransferCopyTag.current le k addresses prior
  rcases Arm64MemcpyTransferCopyTag.observations le with ⟨_zero,_tag,_test,tagCounter,tagDst,tagLen,tagAt⟩
  let tagLe := Arm64MemcpyTransferCopyTag.temps le
  obtain ⟨next,sourceRun⟩ := Arm64MemcpyTransferSourceSP.current tagLe
    (Arm64MemcpyTransferCopyTag.continuation k) i addresses tagCurrent (tagCounter.trans hi)
  have kept := Arm64MemcpyTransferSourceSP.observations tagLe tagCurrent.packet.storage.sp.block
  exact ⟨_,next,tagRun.trans sourceRun,kept.1,kept.2.1.trans tagCounter,
    kept.2.2.1.trans tagDst,kept.2.2.2.1.trans tagLen,kept.2.2.2.2.trans tagAt⟩

end KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyPrefix
