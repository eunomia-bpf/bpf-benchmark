import KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyGates

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferGuardPrefix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- One actual body110 execution carries the same complete packet through
the R1 tag/source-SP readers, R0 destination-SP reader, alignment and length
setters, and original copy selector. Each stage consumes the preceding
stage's actual current witness, reached heap and returned temporaries. -/
theorem execute {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (chosen : Arm64MemcpyTransferLoop.active i = true)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (Arm64MemcpyTransferLoop.position i))) :
    ∃ nextLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m nextLe,
      InternalRun world 132
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler Arm64MemcpyTransferCopyGates.copyBody (Arm64MemcpyTransferCopyGates.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 nextLe m) ∧
      nextLe.get Arm64Program._t'84 = some (.Vint 1) ∧
      nextLe.get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
      nextLe.get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
      nextLe.get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
      nextLe.get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  obtain ⟨sourceLe,sourceCurrent,sourceRun,sourceOK,sourceCounter,sourceDst,sourceLen,sourceAt⟩ :=
    Arm64MemcpyTransferCopyPrefix.execute le k i addresses prior hi
  obtain ⟨destinationCurrent,destinationRun⟩ := Arm64MemcpyTransferDestinationSP.current sourceLe k i addresses
    sourceCurrent (sourceCounter.trans hi) sourceOK
  let destinationLe := Arm64MemcpyTransferDestinationSP.temps sourceLe sourceCurrent.packet.storage.sp.block
  rcases Arm64MemcpyTransferDestinationSP.observations sourceLe sourceCurrent.packet.storage.sp.block with
    ⟨destinationOK,destinationCounter,destinationDst,destinationLen,destinationAt⟩
  obtain ⟨next,gatesRun⟩ := Arm64MemcpyTransferCopyGates.current destinationLe k i destinationCurrent chosen
    destinationOK (destinationCounter.trans (sourceCounter.trans hi))
    (destinationLen.trans (sourceLen.trans hlen)) (destinationAt.trans (sourceAt.trans hat))
  rcases Arm64MemcpyTransferCopyGates.observations destinationLe with ⟨copyOK,counter,dst,len,atRead⟩
  exact ⟨_,next,(sourceRun.trans destinationRun).trans gatesRun,copyOK,
    counter.trans (destinationCounter.trans sourceCounter),dst.trans (destinationDst.trans sourceDst),
    len.trans (destinationLen.trans sourceLen),atRead.trans (destinationAt.trans sourceAt)⟩

end KProgFormal.ClightRefinement.Arm64MemcpyTransferGuardPrefix
