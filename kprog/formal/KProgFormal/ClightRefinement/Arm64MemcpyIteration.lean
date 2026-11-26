import KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix
import KProgFormal.ClightRefinement.Arm64MemcpyStorePrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyIteration

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The complete original body calls the real thirteen-local reader,
executes source81's actual stores, then returns to its saved loop backedge. -/
theorem body {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.write k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨readAfter,readLe,readCurrent,readRun,off,width,value,readFrame,readFlag,pbound,cbound⟩ :=
    Arm64MemcpyReadCaller.execute le k i prior producerBound callerBound cell flagValue flag
  have bias : CC.Mem.load .Mint64 readAfter entry.block 672 = some (.Vlong 96) := readCurrent.packet.view.bias
  have prefixRun := Arm64MemcpyStorePrefix.execute (Arm64MemcpySource.allocation calleeBefore).1
    readLe readAfter (Arm64MemcpyReadCaller.continuation k) entry.block byte i
    readCurrent.entryRead off width value bias
  let prefixLe := Arm64MemcpyStorePrefix.temps readLe byte i
  let prefixCurrent := Arm64MemcpyStorePrefix.current i readCurrent
  have outputs := Arm64MemcpyStorePrefix.outputs readLe byte i
  have prefixOff : prefixLe.get Arm64Program.___a64_loss_off =
      some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)) :=
    (Arm64MemcpyStorePrefix.kept readLe byte i _ (by decide +kernel)).trans off
  obtain ⟨_tagged,after,nextLe,next,suffixRun,_tagStore,_byteStore,read,flagAfter,writeFrame,nextblock⟩ :=
    Arm64MemcpyStoreSuffix.execute prefixLe k i prefixCurrent pbound cbound outputs.1
      outputs.2.1 outputs.2.2 prefixOff cell flagValue readFlag
  have oldBound : initial.nextblock.toNat ≤ before.nextblock.toNat := by
    have owned := ((allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64Producer.allocation initial)).symm)).1 _ _ entry.binding)
    omega
  have oldFrame : FrameBelow initial.nextblock before readAfter := fun block below =>
    readFrame block (by omega)
  refine ⟨after,nextLe,next,?_,read,flagAfter,oldFrame.trans writeFrame,?_,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using
      star_trans readRun (star_trans prefixRun.sound suffixRun)
  · simpa only [nextblock] using pbound
  · simpa only [nextblock] using cbound

/-- A genuine true guard, the complete reader/store body, and the original
unsigned counter increment execute one actual copy iteration. The new copied
prefix is derived from that iteration's real byte-store readback. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore (i.val+1) after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  let e := (Arm64MemcpySource.allocation calleeBefore).1
  have enter := Arm64MemcpyLoop.enter_current e le k i prior
  obtain ⟨after,bodyLe,bodyCurrent,bodyRun,copied,flagAfter,frame,pbound,cbound⟩ :=
    body le (Arm64MemcpyLoop.writeCont k) i prior producerBound callerBound cell flagValue flag
  obtain ⟨next,advance⟩ := Arm64MemcpyLoop.advance_current e bodyLe k i bodyCurrent copied
  refine ⟨after,_,next,?_,flagAfter,frame,pbound,cbound⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans enter.sound (star_trans bodyRun advance.sound)

end KProgFormal.ClightRefinement.Arm64MemcpyIteration
