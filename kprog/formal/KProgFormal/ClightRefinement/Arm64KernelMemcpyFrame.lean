import KProgFormal.ClightRefinement.Arm64KernelMemcpyEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyFrame

/-- The SAME thirteen actual native steps retain every architectural field
outside their genuine PC, pointer-end, loaded-word and NZCV destinations. -/
theorem field (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (name : StateField) (notPC : name ≠ .PC) (not4 : name ≠ .GPR (4#5)) (not5 : name ≠ .GPR (5#5))
    (not6 : name ≠ .GPR (6#5)) (not7 : name ≠ .GPR (7#5))
    (not12 : name ≠ .GPR (12#5)) (not13 : name ≠ .GPR (13#5)) (notFlag : ∀ flag, name ≠ .FLAG flag) :
    r name (Arm64KernelMemcpyReturn.Return stores.final).machine = r name native.machine :=
  (Arm64ProgramEntryReturnNative.field stores.final name notPC).trans
    ((stores.fields name notPC).trans ((loads.fields name notPC not6 not7 not12 not13).trans
      ((congrArg (fun state : Reference.AArch64.State => r name state.machine) arrived).trans
        (leading.fields name notPC not4 not5 notFlag))))

/-- Both real stores and RET retain the flags actually produced by the
original final CMP16, on the SAME reached prefix machine. -/
theorem flags (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin) :
    read_pstate (Arm64KernelMemcpyReturn.Return stores.final).machine = Arm64KernelMemcpySmallGates.flags 2 := by
  have kept (flag : PFlag) : r (.FLAG flag) (Arm64KernelMemcpyReturn.Return stores.final).machine = r (.FLAG flag) first.machine :=
    (Arm64ProgramEntryReturnNative.field stores.final (.FLAG flag) (by intro h; cases h)).trans
      ((stores.fields (.FLAG flag) (by intro h; cases h)).trans
        (loads.fields (.FLAG flag) (by intro h; cases h) (by intro h; cases h) (by intro h; cases h) (by intro h; cases h) (by intro h; cases h)))
  have n := kept .N
  have z := kept .Z
  have c := kept .C
  have v := kept .V
  simp only [r,read_base_flag] at n z c v
  have state : read_pstate (Arm64KernelMemcpyReturn.Return stores.final).machine = read_pstate first.machine := by
    change PState.mk _ _ _ _ = PState.mk _ _ _ _
    rw [n,z,c,v]
  exact state.trans ((congrArg (fun state : Reference.AArch64.State => read_pstate state.machine) arrived).trans leading.flags)

/-- The final real returned memory retains every byte outside the actual
destination relative to the original native input, across all thirteen steps. -/
theorem outside (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (other : BitVec 64) (notWritten : 16 ≤ (other-Reference.AArch64.gpr native 0).toNat) :
    read_mem other (Arm64KernelMemcpyReturn.Return stores.final).machine = read_mem other native.machine := by
  have first0 : Reference.AArch64.gpr first 0 = Reference.AArch64.gpr native 0 :=
    (congrArg (fun state => Reference.AArch64.gpr state 0) arrived).trans
      (leading.fields (.GPR (0#5)) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide))
  have destination : Reference.AArch64.gpr loads.final 0 = Reference.AArch64.gpr native 0 :=
    (loads.fields (.GPR (0#5)) (by decide) (by decide) (by decide) (by decide) (by decide)).trans first0
  have permission : 16 ≤ (other-Reference.AArch64.gpr loads.final 0).toNat := by simpa only [destination] using notWritten
  have unchanged : loads.final.machine.mem = native.machine.mem :=
    loads.memory.trans ((congrArg (fun state : Reference.AArch64.State => state.machine.mem) arrived).trans leading.memory)
  exact (congrArg (fun mem : Memory => mem other) (Arm64ProgramEntryReturnNative.resources stores.final).1).trans
    ((Arm64KernelMemcpyOutput.outside loads.final profile origin stores other permission).trans
      (congrArg (fun mem : Memory => mem other) unchanged))

/-- Actual final source R0/tag4 and returned physical X0 agree through the
existing provenance coordinate map on that SAME complete-call packet. -/
theorem r0 {initial seed after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flagWords : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flagWords values cell flagValue after)
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (origins : Reference.Provenance.AArch64.Origins)
    (destination : Reference.AArch64.gpr native 0 = origins.stack+(-16#64)) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 0 = some (.Vlong (-16#64),.Vint (4#32)) ∧
    Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) 0 =
      Reference.Provenance.AArch64.materialize origins (-16#64) (4#8) := by
  refine ⟨packet.memory.r0,?_⟩
  have retained := field native first profile origin leading arrived loads stores (.GPR (0#5))
    (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide)
  simpa +decide [Reference.AArch64.gpr,Reference.Provenance.AArch64.materialize,BitVec.add_comm] using retained.trans destination

end KProgFormal.ClightRefinement.Arm64KernelMemcpyFrame
