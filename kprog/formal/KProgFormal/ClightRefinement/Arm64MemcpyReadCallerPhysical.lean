import KProgFormal.ClightRefinement.Arm64MemcpySourcePhysicalRead
import KProgFormal.ClightRefinement.Arm64MemcpyReadCaller

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadCallerPhysical
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- Exact source contents and Cur/Max access below the actual caller frontier
retain the SAME physical relation, including undefined/initialized bytes. -/
theorem source_frame {before after : CC.Mem} {stack frontier : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : ArmState}
    (prior : Represents before stack origin profile native) (frame : FrameBelow frontier before after)
    (below : stack.toNat < frontier.toNat) : Represents after stack origin profile native where
  profileRead := prior.profileRead
  readable := by
    intro i
    simpa only [CC.Mem.perm,(frame stack below).2] using prior.readable i
  writable := by
    intro i
    simpa only [CC.Mem.perm,(frame stack below).2] using prior.writable i
  bytes := fun i readable => (frame.load .Mint8unsigned stack (i.val : Int) below).trans (prior.bytes i readable)

private def reframe {before after : CC.Mem} {stack frontier : CC.Block} {origin : BitVec 64}
    {profile : MemoryProfile} {native : Reference.AArch64.State} {i : Fin 160} {byte : BitVec 8}
    (prior : Arm64MemcpySourcePhysicalRead.Result before stack origin profile native i byte)
    (frame : FrameBelow frontier before after) (below : stack.toNat < frontier.toNat) :
    Arm64MemcpySourcePhysicalRead.Result after stack origin profile native i byte :=
  ⟨prior.final,prior.step,source_frame prior.mapped frame below,prior.initialized,prior.data,
    prior.pc,prior.extra,prior.fields,prior.memory,prior.profile,prior.history,prior.program,
    prior.exclusive,prior.atomic,prior.thread⟩

/-- Execute the complete original reader/caller ONCE, including real
allocation/free and saved-caller resume. Its actual source byte supplies the
same native LDRB; the real old-block frame carries that physical result to
the actual reached source heap without a fresh native state or source run. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {view : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (current : Arm64MemcpyLoopState.Invariant view abi byte gprs flags vectors calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents before view.stack.block origin profile native.machine)
    (base : Reference.AArch64.gpr native 1 = address origin (Arm64MemsetStoreExecution.index i))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemcpyByteNativeRead.instruction.encoding) :
    ∃ after nextLe, ∃ next : Arm64MemcpyLoopState.Invariant view abi byte gprs flags vectors calleeBefore i.val after nextLe,
    ∃ result : Arm64MemcpySourcePhysicalRead.Result after view.stack.block origin profile native (Arm64MemsetStoreExecution.index i) byte,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyReadCall.store (Arm64MemcpyReadCaller.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      nextLe.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)) ∧
      nextLe.get Arm64Program.___a64_loss_width = some (.Vint 1) ∧
      nextLe.get Arm64Program.___a64_loss_value = some (.Vlong (Reference.AArch64.gpr result.final 3)) ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨nativeResult⟩ := Arm64MemcpySourcePhysicalRead.from_load native represented
    (Arm64MemsetStoreExecution.index i) byte (current.packet.written i) base noError fetched
  obtain ⟨after,nextLe,next,run,off,width,value,frame,flagAfter,pbound,cbound⟩ :=
    Arm64MemcpyReadCaller.execute le k i current producerBound callerBound cell flagValue flag
  have below : view.stack.block.toNat < before.nextblock.toNat := Nat.lt_of_lt_of_le
    (Arm64RegisterStorageFrontier.local_owned initial _ _ _ view.stack.binding) producerBound
  let result := reframe nativeResult frame below
  refine ⟨after,nextLe,next,result,run,off,width,?_,frame,flagAfter,pbound,cbound⟩
  rw [result.data]
  exact value

end KProgFormal.ClightRefinement.Arm64MemcpyReadCallerPhysical
