import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedClobber

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedView
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- The same actual native witnesses preserve each remaining register and
SP. Finite index separation uses their genuine architectural field numbers. -/
theorem native_gpr (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (j : Fin 31) (outside : j.val = 0 ∨ 19 ≤ j.val) :
    Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) j = Reference.AArch64.gpr native j := by
  have separated : ∀ j : Fin 31, j.val = 0 ∨ 19 ≤ j.val →
      BitVec.ofNat 5 j.val ≠ 4#5 ∧ BitVec.ofNat 5 j.val ≠ 5#5 ∧
      BitVec.ofNat 5 j.val ≠ 6#5 ∧ BitVec.ofNat 5 j.val ≠ 7#5 ∧
      BitVec.ofNat 5 j.val ≠ 12#5 ∧ BitVec.ofNat 5 j.val ≠ 13#5 := by decide +kernel
  have different := separated j outside
  exact Arm64KernelMemcpyFrame.field native first profile origin leading arrived loads stores (.GPR (BitVec.ofNat 5 j.val))
    (by intro h; cases h)
    (by intro h; exact different.1 (StateField.GPR.inj h))
    (by intro h; exact different.2.1 (StateField.GPR.inj h))
    (by intro h; exact different.2.2.1 (StateField.GPR.inj h))
    (by intro h; exact different.2.2.2.1 (StateField.GPR.inj h))
    (by intro h; exact different.2.2.2.2.1 (StateField.GPR.inj h))
    (by intro h; exact different.2.2.2.2.2 (StateField.GPR.inj h))
    (by intro flag h; cases h)

/-- Initial source/native binding, actual remaining-register frames and the
same post-free packet derive the complete existing31-GPR/SP/SIMD/NZCV relation. -/
theorem observe {initial seed before after : CC.Mem} {entry : HeaderLocal initial} {inputN : Nat}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (inputMemory : Arm64ClobberMemoryState.Packet base abi byte (-16#64) inputN before)
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final))
      (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after)
    (kept : Kept entry.block before after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native) :
    Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
      (Arm64KernelMemcpyReturn.Return stores.final) := by
  have view := Arm64KernelMemcpyTargetView.observe packet
  refine ⟨?_,?_,view.vectors,view.flags⟩
  · intro j
    by_cases zero : j.val = 0
    · have same : j = 0 := Fin.ext zero
      subst j
      obtain ⟨value,raw,tag,read,valueRep,coordinate⟩ := prior.gpr 0
      have unchanged := packet.memory.r0.trans inputMemory.r0.symm
      exact ⟨value,raw,tag,unchanged.trans read,valueRep,
        (native_gpr native first profile origin leading arrived loads stores 0 (Or.inl rfl)).trans coordinate⟩
    · by_cases selected : j.val ≤ 18
      · let i : Fin 18 := ⟨j.val-1,by omega⟩
        have value : i.val+1 = j.val := by dsimp [i]; omega
        have index : (⟨i.val+1,by omega⟩ : Reference.AArch64.Gpr) = j := Fin.ext value
        have read := view.gprs i
        rw [index,value] at read
        refine ⟨.Vlong (Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) j),
          Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) j,0,read,rfl,?_⟩
        simp [Reference.Provenance.AArch64.materialize]
      · have retainedBound : 19 ≤ j.val := by omega
        obtain ⟨value,raw,tag,read,valueRep,coordinate⟩ := prior.gpr j
        exact ⟨value,raw,tag,(kept j retainedBound).trans read,valueRep,
          (native_gpr native first profile origin leading arrived loads stores j (Or.inr retainedBound)).trans coordinate⟩
  · obtain ⟨offset,read,coordinate⟩ := prior.sp
    have sourceSP := Arm64ProducerEntryView.header_borrowed_readback before entry.block 5 .Mint64
      inputMemory.storage.sp.block 0 _ inputMemory.storage.spPointer inputMemory.storage.spRead
    change Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong inputMemory.storage.spValue) at sourceSP
    rw [inputMemory.spAtBase] at sourceSP
    have unchanged := view.sp.trans sourceSP.symm
    have nativeSP := Arm64KernelMemcpyFrame.field native first profile origin leading arrived loads stores (.GPR (31#5))
      (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide)
    exact ⟨offset,unchanged.trans read,nativeSP.trans coordinate⟩

/-- The same real provider/store/helper-return/free execution derives the complete
existing register relation from its actual initial source/native binding. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe le : CC.TempEnv}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe 20 m le)
    (registerInputs : Arm64KernelMemcpyProviderRegisters.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : Arm64KernelMemcpyProviderFlags.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : Arm64KernelMemcpyProviderVectors.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ calleeBefore.nextblock.toNat)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State helper Arm64MemsetClobberEntry.rest
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe (Arm64MemcpySource.continuation k)))
          CC.emptyEnv le m) trace (.Returnstate .Vundef k after) ∧
      Arm64MemcpyReturn.FreeResult calleeBefore written after ∧ FrameBelow initial.nextblock m after ∧
      after.nextblock = m.nextblock ∧ Kept entry.block m after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by
  obtain ⟨after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedClobber.complete (Arm64KernelMemcpyReturn.Return stores.final) current
      registerInputs flagInputs vectorInputs bound k hk
  have represented := observe native first profile origin leading arrived loads stores
    current.released.ready.memory packet kept addresses origins prior
  exact ⟨after,written,trace,packet,run,freed,frame,next,kept,view,represented⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedView
