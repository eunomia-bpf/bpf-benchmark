import KProgFormal.ClightRefinement.X86StackCacheView

namespace KProgFormal.ClightRefinement.X86ProducerPushNativeCache
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The SAME final cache represents the shared native byte-memory update.
Initial cache/native correspondence remains explicit; no successful source
store or post-store representation is assumed. -/
theorem memory (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (native : Reference.Memory) (cpu : X86.Cpu)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu)
    (represented : X86StackCacheView.Represents ready.after (ready.sources 1).block native origins.stack) :
    X86StackCacheView.Represents complete.after (ready.sources 1).block
      (Reference.storeMemory native (cpu.regs.get (X86.GPR.ofIndex 4) - 8)
        (cpu.regs.get (X86.GPR.ofIndex 3)) 8) origins.stack := by
  have payload := X86ProducerPushNativeRegisters.payload complete addresses origins cpu registers
  have same : ready.values 3 = cpu.regs.get (X86.GPR.ofIndex 3) :=
    CC.Val.Vlong.inj (Option.some.inj (complete.word_read.symm.trans payload))
  rw [X86ProducerPushGprView.initial_sp addresses origins cpu registers]
  apply X86StackCacheView.store ready.after complete.after (ready.sources 1).block native origins.stack _ represented
  intro byte
  simpa only [same] using X86ProducerPushCacheBytes.table complete byte

/-- Actual source execution, native GPR update and native cache-memory view
share one accepted final heap. This is the success-side representation
bridge; checked permission/canonicality/fault, PC, oracle and guest-event
correspondence remain separate obligations. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (native : Reference.Memory) (cpu : X86.Cpu)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu)
    (represented : X86StackCacheView.Represents ready.after (ready.sources 1).block native origins.stack) :
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
    X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0
      (cpu.setReg .q (X86.GPR.ofIndex 4) (cpu.regs.get (X86.GPR.ofIndex 4) - 8)) ∧
    X86StackCacheView.Represents complete.after (ready.sources 1).block
      (Reference.storeMemory native (cpu.regs.get (X86.GPR.ofIndex 4) - 8)
        (cpu.regs.get (X86.GPR.ofIndex 3)) 8) origins.stack := by
  have source := X86ProducerPushNativeRegisters.execute complete addresses origins cpu registers
  exact ⟨source.1,source.2.1,memory complete addresses origins native cpu registers represented⟩

end KProgFormal.ClightRefinement.X86ProducerPushNativeCache
