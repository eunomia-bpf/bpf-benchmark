import KProgFormal.ClightRefinement.Arm64MemcpyTransferSourceAddress

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSourcePrefix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- One original body110 reaches its genuine source-tag loop through all
actual pointer/tag readers and the actual source and destination
guards. The source address and every retained observation belong to this
same reached packet, heap and caller frame. -/
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
      InternalRun world 172
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler Arm64MemcpyTransferSourceAddress.tagLoop (Arm64MemcpyTransferSourceAddress.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 nextLe m) ∧
      nextLe.get Arm64Program.___a64_mt_src = some (.Vlong (Arm64MemcpyTransferSourceAddress.position i)) ∧
      nextLe.get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
      nextLe.get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
      nextLe.get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
      nextLe.get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  obtain ⟨guardLe,guardCurrent,guardRun,_copyOK,guardCounter,guardDst,guardLen,guardAt⟩ :=
    Arm64MemcpyTransferGuardPrefix.execute le k i addresses prior chosen hi hlen hat
  obtain ⟨next,addressRun⟩ := Arm64MemcpyTransferSourceAddress.current guardLe k i addresses guardCurrent
    chosen (guardCounter.trans hi)
  rcases Arm64MemcpyTransferSourceAddress.observations guardLe i with ⟨sourceOK,counter,dst,len,atRead⟩
  exact ⟨_,next,guardRun.trans addressRun,sourceOK,counter.trans guardCounter,
    dst.trans guardDst,len.trans guardLen,atRead.trans guardAt⟩

end KProgFormal.ClightRefinement.Arm64MemcpyTransferSourcePrefix
