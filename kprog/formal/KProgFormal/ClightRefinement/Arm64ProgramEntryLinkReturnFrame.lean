import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnNative
import KProgFormal.ClightRefinement.Arm64ClobberNativeFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnFrame
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The full two-step native state closes: only true PC and X30 are changed,
and both contain callerPC+4. The imported writers supply every other field. -/
theorem state (s : Reference.AArch64.State) (offset : BitVec 26) :
    Arm64ProgramEntryLinkReturnNative.after s offset =
      {s with machine := (write_pc (read_pc s.machine + 4#64)
        (write_gpr 64 (30#5) (read_pc s.machine + 4#64) s.machine))} := by
  unfold Arm64ProgramEntryLinkReturnNative.after Arm64ProgramEntryReturnNative.after Arm64Nop.atCursor
  rw [Arm64ProgramEntryLinkNative.link]
  simp only [Arm64ProgramEntryLinkNative.after,write_pc,w_of_w_shadow]

theorem field (s : Reference.AArch64.State) (offset : BitVec 26) (name : StateField)
    (otherPC : name ≠ .PC) (otherLR : name ≠ .GPR (30#5)) :
    r name (Arm64ProgramEntryLinkReturnNative.after s offset).machine = r name s.machine := by
  exact (Arm64ProgramEntryReturnNative.field _ name otherPC).trans
    (Arm64ProgramEntryLinkNative.field s offset name otherPC otherLR)

theorem resources (s : Reference.AArch64.State) (offset : BitVec 26) :
    let changed := Arm64ProgramEntryLinkReturnNative.after s offset
    changed.machine.mem = s.machine.mem ∧ changed.machine.program = s.machine.program ∧
    changed.machine.memoryProfile = s.machine.memoryProfile ∧ changed.machine.memoryAccesses = s.machine.memoryAccesses ∧
    changed.machine.atomicAccesses = s.machine.atomicAccesses ∧ changed.machine.exclusive = s.machine.exclusive ∧
    changed.machine.threadPointerInputs = s.machine.threadPointerInputs ∧ changed.extraFlags = s.extraFlags := by
  rw [state]
  simp [write_pc,write_gpr,w,write_base_pc,write_base_gpr]

theorem flag_values (s : Reference.AArch64.State) (offset : BitVec 26) (i : Fin 4) :
    Arm64ProducerEntryView.flagValues (Arm64ProgramEntryLinkReturnNative.after s offset) i =
      Arm64ProducerEntryView.flagValues s i := by
  have keep (flag : PFlag) : read_flag flag (Arm64ProgramEntryLinkReturnNative.after s offset).machine =
      read_flag flag s.machine := field s offset (.FLAG flag)
        (by intro impossible; cases impossible) (by intro impossible; cases impossible)
  simp only [Arm64ProducerEntryView.flagValues,keep]

/-- Actual current source bytes relate to any native state whose incoming
flag observations have already been established by its original caller. -/
theorem flags_represent {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue m)
    (s : Reference.AArch64.State)
    (values : ∀ i, Arm64ProducerEntryView.flagValues s i = .Vint (Arm64Producer.flagWord (flags i))) :
    Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s := by
  have nn := current.flagWords 0
  have zz := current.flagWords 1
  have cc := current.flagWords 2
  have vv := current.flagWords 3
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._n = _ at nn
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._z = _ at zz
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._c = _ at cc
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._v = _ at vv
  unfold Arm64Nop.FlagsRepresent Arm64EntryMemory.flags
  rw [nn,zz,cc,vv]
  have nvalue := values 0
  have zvalue := values 1
  have cvalue := values 2
  have vvalue := values 3
  change CC.Val.Vint ((read_flag .N s.machine).setWidth 32) = _ at nvalue
  change CC.Val.Vint ((read_flag .Z s.machine).setWidth 32) = _ at zvalue
  change CC.Val.Vint ((read_flag .C s.machine).setWidth 32) = _ at cvalue
  change CC.Val.Vint ((read_flag .V s.machine).setWidth 32) = _ at vvalue
  simp only [bind,pure,Option.bind_some,nvalue,zvalue,cvalue,vvalue]

section Packet
variable {initial seed before linked reached : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before}
    {lr : HeaderSourceLocal initial 4}

def packet (result : Arm64ProgramEntryLinkComplete.Result prior lr linked)
    (effect : Arm64ProgramEntryLinkCall.Effect lr linked reached) :
    Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue reached :=
  Arm64ProgramEntryLinkFrame.packet effect result.packet
end Packet

/-- One actual source execution derives its final current Packet/resources and
native flag relation. Original caller flag observations are transported through
the real stores and both native steps; no reached-heap witness is an input. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (s : Reference.AArch64.State) (offset : BitVec 26) (admitted : Arm64ProgramEntryLinkReturnNative.Admission s offset)
    (noError : read_err s.machine = .None)
    (values : ∀ i, Arm64ProducerEntryView.flagValues s i = .Vint (Arm64Producer.flagWord (flags i))) :
    ∃ linked, ∃ result : Arm64ProgramEntryLinkComplete.Result prior lr linked,
      ∃ reached, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked reached,
      ∃ current : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue reached,
        InternalRun world 152
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
            (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
            (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
            (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)) reached) ∧
        Reference.AArch64.step s = ⟨Arm64ProgramEntryLinkNative.after s offset,[],none⟩ ∧
        Reference.AArch64.step (Arm64ProgramEntryLinkNative.after s offset) =
          ⟨Arm64ProgramEntryLinkReturnNative.after s offset,[],none⟩ ∧
        Arm64ProgramEntryLinkReturnNative.Observation reached (.Vptr entry.block 0) lr.block s
          (Arm64ProgramEntryLinkReturnNative.after s offset) admitted.continuation ∧
        Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0)
          (Arm64ProgramEntryLinkReturnNative.after s offset) ∧
        FrameBelow initial.nextblock before reached ∧
        (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)).get Arm64ProgramFixture._result =
          le.get Arm64ProgramFixture._result ∧
        (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)).get Arm64ProgramFixture._ctx =
          le.get Arm64ProgramFixture._ctx := by
  obtain ⟨linked,result,reached,effect,run,callNative,returnNative,_,observation,caller,resultTemp,ctxTemp⟩ :=
    Arm64ProgramEntryLinkReturnNative.complete prior lr le k hk s offset admitted noError
  let current := packet result effect
  have currentValues : ∀ i, Arm64ProducerEntryView.flagValues (Arm64ProgramEntryLinkReturnNative.after s offset) i =
      .Vint (Arm64Producer.flagWord (flags i)) := fun i => (flag_values s offset i).trans (values i)
  exact ⟨linked,result,reached,effect,current,run,callNative,returnNative,observation,
    flags_represent current _ currentValues,caller,resultTemp,ctxTemp⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnFrame
