import KProgFormal.ClightRefinement.X86ProducerPushGprView
import KProgFormal.ClightRefinement.X86ProducerPushLocal

namespace KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The actual scalar RBX reader and payload store use the native RBX value
already represented by the initialized table. -/
theorem payload (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu) :
    CC.Mem.load .Mint64 complete.after (ready.sources 1).block 40 =
      some (.Vlong (cpu.regs.get (X86.GPR.ofIndex 3))) := by
  obtain ⟨value,raw,tag,wordRead,tagRead,valueRep,native⟩ := represented (3 : Fin 16)
  have reads := ready.gpr_reads 3 (by decide)
  have wordEq : value = .Vlong (ready.values 3) := Option.some.inj (wordRead.symm.trans reads.1)
  have rawEq : raw = ready.values 3 := by simpa only [wordEq,Arm64Registers.ValueRep] using valueRep
  have tagEq : tag = 0 := by
    have encoded := congrArg (fun v => match v with | CC.Val.Vint v => v.setWidth 8 | _ => 0)
      (Option.some.inj (tagRead.symm.trans reads.2))
    simpa using encoded
  have same : cpu.regs.get (X86.GPR.ofIndex 3) = ready.values 3 := by
    simpa [Reference.Provenance.X86.materialize,rawEq,tagEq] using native
  simpa only [same] using complete.word_read

/-- The represented native RSP changes by eight bytes; native stack origin
is preserved and is not identified with relative zero. -/
theorem delta (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu) :
    X86ProducerPushRspStore.nextRsp + origins.stack = cpu.regs.get (X86.GPR.ofIndex 4) - (8#64) := by
  rw [X86ProducerPushGprView.initial_sp addresses origins cpu represented]
  simp only [X86ProducerPushRspStore.nextRsp,BitVec.sub_eq_add_neg]
  ac_rfl

/-- Same actual silent source execution, native register projection and
native RBX payload, all sharing the accepted final memory. This leaves native
memory mapping, faults, fetch/PC and oracle correspondence explicitly open. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu) :
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
    X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0
      (cpu.setReg .q (X86.GPR.ofIndex 4) (cpu.regs.get (X86.GPR.ofIndex 4) - (8#64))) ∧
    CC.Mem.load .Mint64 complete.after (ready.sources 1).block 40 =
      some (.Vlong (cpu.regs.get (X86.GPR.ofIndex 3))) := by
  refine ⟨X86ProducerPushLocal.silent complete,?_,payload complete addresses origins cpu represented⟩
  simpa only [delta addresses origins cpu represented] using
    X86ProducerPushGprView.registers complete addresses origins cpu represented

end KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters
