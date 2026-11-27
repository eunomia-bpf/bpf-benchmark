import KProgFormal.ClightRefinement.Arm64CodeRegisters
import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedProgram
import KProgFormal.ClightRefinement.Arm64MemcpyLinkCode

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyCodeView
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64KernelMemcpyProviders (Gprs Flags Vectors)
open Arm64KernelMemcpyRetainedRegisters (Kept)

/-- Original actual prefix/two loads/two stores/RET preserve the SAME
physical instruction map used by all code-label observations. -/
theorem native_program (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin) :
    (Arm64KernelMemcpyReturn.Return stores.final).machine.program = native.machine.program :=
  (Arm64ProgramEntryReturnNative.resources stores.final).2.1.trans
    (stores.program.trans (loads.program.trans
      ((congrArg (fun state : Reference.AArch64.State => state.machine.program) arrived).trans leading.program)))

/-- The captured actual LINK/BL coordinate supplies a concrete partial
label map. Every matching label still needs its real fetched instruction. -/
def linkLabels (origin : BitVec 64) (i : Fin 8) : Arm64CodeRegisters.Labels :=
  fun token => if token = Arm64MemcpyLinkCode.sourceToken i
    then some (origin+token,Arm64MemcpyLinkCode.continuation i) else none

theorem link_coordinate {m header offset} {h : Arm64MemcpyLinkCall.Header m header offset}
    {i origin source current}
    (observed : Arm64MemcpyLinkCode.Observation h i origin source current)
    (origins : Reference.Provenance.AArch64.Origins) :
    Arm64CodeRegisters.Coordinate (linkLabels origin i) origins current
      (Arm64MemcpyLinkCode.sourceToken i) (9#8) (Reference.AArch64.gpr current 30) := by
  change Arm64CodeRegisters.CodeAt (linkLabels origin i) current
    (Arm64MemcpyLinkCode.sourceToken i) (Reference.AArch64.gpr current 30)
  refine ⟨Arm64MemcpyLinkCode.continuation i,?_,observed.returnCode⟩
  simp only [linkLabels,ite_true,observed.nativeLink]

/-- Same real post-free readers and original input relation derive all31
GPR/SP/vector/NZCV observations,including fetched CODE9 coordinates. -/
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
    (labels : Arm64CodeRegisters.Labels) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native) :
    Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
      (Arm64KernelMemcpyReturn.Return stores.final) := by
  have view := Arm64KernelMemcpyTargetView.observe packet
  have program := native_program native first profile origin leading arrived loads stores
  refine ⟨?_,?_,view.vectors,view.flags⟩
  · intro j
    by_cases zero : j.val = 0
    · have same : j = 0 := Fin.ext zero
      subst j
      obtain ⟨value,raw,tag,read,valueRep,coordinate⟩ := prior.gpr 0
      have unchanged := packet.memory.r0.trans inputMemory.r0.symm
      exact ⟨value,raw,tag,unchanged.trans read,valueRep,
        by
          rw [Arm64KernelMemcpyRetainedView.native_gpr native first profile origin leading arrived loads stores 0 (Or.inl rfl)]
          exact Arm64CodeRegisters.coordinate_transport program coordinate⟩
    · by_cases selected : j.val ≤ 18
      · let i : Fin 18 := ⟨j.val-1,by omega⟩
        have value : i.val+1 = j.val := by dsimp [i]; omega
        have index : (⟨i.val+1,by omega⟩ : Reference.AArch64.Gpr) = j := Fin.ext value
        have read := view.gprs i
        rw [index,value] at read
        refine ⟨.Vlong (Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) j),
          Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) j,0,read,rfl,?_⟩
        simp [Arm64CodeRegisters.Coordinate,Reference.Provenance.AArch64.materialize]
      · have retainedBound : 19 ≤ j.val := by omega
        obtain ⟨value,raw,tag,read,valueRep,coordinate⟩ := prior.gpr j
        exact ⟨value,raw,tag,(kept j retainedBound).trans read,valueRep,
          by
            rw [Arm64KernelMemcpyRetainedView.native_gpr native first profile origin leading arrived loads stores j (Or.inr retainedBound)]
            exact Arm64CodeRegisters.coordinate_transport program coordinate⟩
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

/-- Observe a copy that has ALREADY executed,using exactly its reached
heap/temp/trace witnesses. The source copy is not run again. -/
theorem finish_copied {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (packetBefore : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (le : CC.TempEnv) (k : CC.Cont)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (labels : Arm64CodeRegisters.Labels) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (copied : CC.Mem) (copyLe : CC.TempEnv)
    (copyCurrent : Arm64MemcpyLoopState.Invariant base abi byte (Arm64MemcpyLengthState.words gprs) flags values before 16 copied copyLe)
    (copyRun : CC.Star (CC.Step2 world)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
        (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
      (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
        (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
        (Arm64MemcpySource.allocation before).1 copyLe copied))
    (copyFlag : Arm64MemcpyReadCurrent.Flag entry cell flagValue copied)
    (copyFrame : FrameBelow initial.nextblock before copied)
    (pbound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ copied.nextblock.toNat)
    (cbound : (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ copied.nextblock.toNat)
    (copyGprs : ∀ q : Fin 31, Arm64EntryMemory.gpr copied.nextblock copied (.Vptr entry.block 0) q.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val)
    :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧ Kept entry.block before after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by

  obtain ⟨inputMemory,after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedProgram.finish_copied_factual (Arm64KernelMemcpyReturn.Return stores.final)
      packetBefore le k flag byteInputs registerInputs flagInputs vectorInputs addresses bound
      copied copyLe copyCurrent copyRun copyFlag copyFrame pbound cbound copyGprs
  have represented := observe native first profile origin leading arrived loads stores
    inputMemory packet kept labels addresses origins prior
  exact ⟨after,written,trace,packet,run,freed,frame,next,kept,view,represented⟩

/-- One original caller-to-caller source execution feeds this observer.
Actual trace,packet,free8,Kept and native witnesses are not replayed. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (packetBefore : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (le : CC.TempEnv) (k : CC.Cont)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before)
    (byteInputs : ∀ outerLe, Arm64ClobberReleaseComplete.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe)
    (registerInputs : ∀ outerLe, Arm64KernelMemcpyProviderRegisters.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Arm64KernelMemcpyReturn.Return stores.final))
    (flagInputs : ∀ outerLe, Arm64KernelMemcpyProviderFlags.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (vectorInputs : ∀ outerLe, Arm64KernelMemcpyProviderVectors.Inputs base abi byte before (-16#64) 16 cell flagValue outerLe
      (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Arm64KernelMemcpyReturn.Return stores.final))
    (labels : Arm64CodeRegisters.Labels) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (prior : Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) native)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    :
    ∃ after written trace,
    ∃ packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 (Gprs (Arm64KernelMemcpyReturn.Return stores.final)) (Flags (Arm64KernelMemcpyReturn.Return stores.final)) (Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemcpyReturn.FreeResult before written after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧ Kept entry.block before after ∧ Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
      Arm64CodeRegisters.Represents labels addresses origins (fun r => r.val) after.nextblock after (.Vptr entry.block 0)
        (Arm64KernelMemcpyReturn.Return stores.final) := by

  obtain ⟨inputMemory,after,written,trace,packet,run,freed,frame,next,kept,view⟩ :=
    Arm64KernelMemcpyRetainedProgram.complete_factual (Arm64KernelMemcpyReturn.Return stores.final)
      packetBefore le k flag byteInputs registerInputs flagInputs vectorInputs addresses bound
  have represented := observe native first profile origin leading arrived loads stores
    inputMemory packet kept labels addresses origins prior
  exact ⟨after,written,trace,packet,run,freed,frame,next,kept,view,represented⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyCodeView
