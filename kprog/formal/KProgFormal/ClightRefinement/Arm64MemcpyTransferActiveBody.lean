import KProgFormal.ClightRefinement.Arm64MemcpyTransferTagStore

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferActiveBody

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private def high (i : Fin 16) : Bool := i.val == 8
private theorem selected_position : ∀ i : Fin 16, Arm64MemcpyTransferLoop.active i = true →
    Arm64MemcpyTransferTagStore.position (high i) = Arm64MemcpyTransferLoop.position i := by decide +kernel

/-- One original active body110 uses its actual guard/reader prefix,
source-tag builtin and payload decisions, and genuine destination tag
load/store. Every stage consumes the preceding actual current witness. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (chosen : Arm64MemcpyTransferLoop.active i = true)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (Arm64MemcpyTransferLoop.position i)))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some after ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock ∧
      nextLe.get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
      nextLe.get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
      nextLe.get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
      nextLe.get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at := by
  obtain ⟨sourceLe,sourceCurrent,sourceRun,sourceOK,sourceCounter,sourceDst,sourceLen,sourceAt⟩ :=
    Arm64MemcpyTransferSourcePrefix.execute le k i addresses prior chosen hi hlen hat
  obtain ⟨tagCurrent,tagRun⟩ := Arm64MemcpyTransferSourceTag.current sourceLe k i sourceCurrent sourceOK
  let tagLe := Arm64MemcpyTransferSourceTag.temps sourceLe i base.tags.block
  rcases Arm64MemcpyTransferSourceTag.observations sourceLe i base.tags.block with
    ⟨tagZero,tagCounter,tagDst,tagLen,tagAt⟩
  have destination : tagLe.get Arm64Program.___a64_mt_at = some (.Vlong (Arm64MemcpyTransferTagStore.position (high i))) := by
    rw [selected_position i chosen]
    exact tagAt.trans (sourceAt.trans hat)
  obtain ⟨after,next,storeRun,stored,frame,flagAfter,frontier⟩ := Arm64MemcpyTransferTagStore.current tagLe k (high i)
    tagCurrent producerBound callerBound destination tagZero cell flagValue flag
  rcases Arm64MemcpyTransferTagStore.observations tagLe (high i) base.tags.block with
    ⟨_tagAfter,counter,dst,len,atRead⟩
  refine ⟨after,_,next,?_,stored,frame,flagAfter,frontier,
    counter.trans (tagCounter.trans sourceCounter),dst.trans (tagDst.trans sourceDst),
    len.trans (tagLen.trans sourceLen),atRead.trans (tagAt.trans sourceAt)⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans sourceRun.sound tagRun) storeRun

end KProgFormal.ClightRefinement.Arm64MemcpyTransferActiveBody
