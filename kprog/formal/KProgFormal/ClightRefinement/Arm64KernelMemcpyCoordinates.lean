import KProgFormal.ClightRefinement.Arm64KernelMemcpyTargetView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyCoordinates

/-- The actual native helper preserves its original architectural SP.
The invocation's established SP coordinate is retained as the ABI input. -/
theorem sp (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (origins : Reference.Provenance.AArch64.Origins)
    (initialSP : Reference.AArch64.sp native = (-32#64)+origins.stack) :
    Reference.AArch64.sp (Arm64KernelMemcpyReturn.Return stores.final) =
      Reference.Provenance.AArch64.materialize origins (-32#64) (4#8) := by
  have retained := Arm64KernelMemcpyFrame.field native first profile origin leading arrived loads stores (.GPR (31#5))
    (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide)
  simpa +decide [Reference.AArch64.sp,Reference.Provenance.AArch64.materialize] using retained.trans initialSP

/-- One original-entry witness supplies both physical R0/SP coordinates
and the actual post-free source observations, without executing it again. -/
theorem observe {initial seed after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {cell : Arm64Producer.TailLocal initial 5} {flagValue : BitVec 8}
    (native first : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (leading : Arm64KernelMemcpySmallPrefix.Result native origin)
    (arrived : first = Arm64KernelMemcpySmallPrefix.after native)
    (loads : Arm64KernelMemcpyTwoLoads.Result first profile origin)
    (stores : Arm64KernelMemcpyTwoStores.Result loads.final profile origin)
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16
      (Arm64KernelMemcpyProviders.Gprs (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Flags (Arm64KernelMemcpyReturn.Return stores.final))
      (Arm64KernelMemcpyProviders.Vectors (Arm64KernelMemcpyReturn.Return stores.final)) cell flagValue after)
    (origins : Reference.Provenance.AArch64.Origins)
    (destination : Reference.AArch64.gpr native 0 = origins.stack+(-16#64))
    (initialSP : Reference.AArch64.sp native = (-32#64)+origins.stack) :
    Arm64KernelMemcpyTargetView.View after entry.block (Arm64KernelMemcpyReturn.Return stores.final) ∧
    Reference.AArch64.gpr (Arm64KernelMemcpyReturn.Return stores.final) 0 =
      Reference.Provenance.AArch64.materialize origins (-16#64) (4#8) ∧
    Reference.AArch64.sp (Arm64KernelMemcpyReturn.Return stores.final) =
      Reference.Provenance.AArch64.materialize origins (-32#64) (4#8) :=
  ⟨Arm64KernelMemcpyTargetView.observe packet,
    (Arm64KernelMemcpyFrame.r0 packet native first profile origin leading arrived loads stores origins destination).2,
    sp native first profile origin leading arrived loads stores origins initialSP⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyCoordinates
