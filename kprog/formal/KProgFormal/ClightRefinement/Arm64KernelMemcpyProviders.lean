import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyProviders
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
abbrev Gprs := Arm64KernelMemcpyProviderRegisters.target
abbrev Flags := Arm64KernelMemcpyProviderFlags.target
abbrev Vectors := Arm64KernelMemcpyProviderVectors.target

/-- The SAME actual clobber entry composes release,18 GPR pairs,4 flag
pairs and64 vector halves with the exact words of one native output state. -/
theorem execute {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (returned : Reference.AArch64.State)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe returned)
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs returned) returned)
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) returned) (k : CC.Cont) :
    ∃ after nextLe trace,
    ∃ final : Arm64ClobberVectorsComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) 64 (Vectors returned) after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.State helper .Sskip (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k))
          CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let helperK := Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k)
  obtain ⟨regAfter,regLe,regTrace,regCurrent,regRun,regFrame,regAccess,regNext⟩ :=
    Arm64KernelMemcpyProviderRegisters.original returned current flag byteInputs registerInputs k
  obtain ⟨flagAfter,flagLe,flagTrace,flagCurrent,flagRun,flagFrame,flagAccess,flagNext,_⟩ :=
    Arm64KernelMemcpyProviderFlags.execute returned regCurrent flagInputs helperK
  obtain ⟨after,nextLe,vectorTrace,final,vectorRun,vectorFrame,vectorAccess,vectorNext,_⟩ :=
    Arm64KernelMemcpyProviderVectors.execute returned flagCurrent vectorInputs helperK
  exact ⟨after,nextLe,CC.Eapp (CC.Eapp regTrace flagTrace) vectorTrace,final,star_trans (star_trans regRun flagRun) vectorRun,
    (regFrame.trans flagFrame).trans vectorFrame,vectorAccess.trans (flagAccess.trans regAccess),vectorNext.trans (flagNext.trans regNext)⟩

/-- Actual helper return and eight-local free retain the exact same native
provider maps, source copied bytes, flag and original caller frame. -/
theorem complete {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (returned : Reference.AArch64.State)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe returned)
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs returned) returned)
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs returned) (Flags returned) returned)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs returned) (Flags returned) (Vectors returned) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers (Arm64MemcpySource.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧
      FrameBelow initial.nextblock m after ∧ after.nextblock = m.nextblock ∧
      (∀ j : Fin 18, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) (Arm64MemsetClobberRegisters.declaration j).reg.val =
        some (.Vlong (Reference.AArch64.gpr returned (Arm64MemsetClobberRegisters.declaration j).reg),.Vint 0)) ∧
      (∀ j : Fin 4, Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0) (Arm64MemsetClobberFlags.field j) =
        some (Arm64ProducerEntryView.flagValues returned j)) ∧
      (∀ j : Fin 64, CC.Mem.load .Mint64 after packet.memory.storage.vectors.block (Arm64MemsetClobberVectors.offset j) =
        some (.Vlong (Arm64KernelMemcpyProviderVectors.target returned j))) := by
  obtain ⟨written,helperLe,trace,vectorCurrent,run,frame,_access,next⟩ :=
    execute returned current flag byteInputs registerInputs flagInputs vectorInputs (Arm64MemcpySource.continuation k)
  have restore := Arm64MemcpyClobberReturn.restore calleeBefore written outerLe helperLe (Arm64MemcpySource.continuation k)
  obtain ⟨after,freed,leave⟩ := Arm64MemcpyReturn.exit vectorCurrent.flagsPacket.registers.ready outerLe k hk
  let packet := Arm64ClobberResult.retained calleeBefore.nextblock bound freed.caller (Arm64ClobberResult.of_complete vectorCurrent)
  have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
  have initialBound : initial.nextblock.toNat ≤ calleeBefore.nextblock.toNat := Nat.le_trans allocated bound
  have older : FrameBelow initial.nextblock written after :=
    fun block below => freed.caller block (Nat.lt_of_lt_of_le below initialBound)
  refine ⟨after,written,trace,packet,?_,freed,frame.trans older,freed.nextblock.trans next,
    packet.registers,?_,packet.vectors⟩
  · simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans (star_trans run restore.sound) leave.sound
  · intro j
    simpa only [Flags,Arm64KernelMemcpyProviderFlags.observed] using packet.flagWords j

end KProgFormal.ClightRefinement.Arm64KernelMemcpyProviders
