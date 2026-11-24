import KProgFormal.ClightRefinement.X86ProducerPushComplete
import KProgFormal.ClightRefinement.X86RegisterReadRspNative

namespace KProgFormal.ClightRefinement.X86ProducerPushGprView

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Every actual GPR/tag row after the complete call, including genuine
allocation, stores and freeing. Only the RSP word changes. -/
theorem table (complete : X86ProducerPushComplete.Result cache) (row : Fin 32) :
    CC.Mem.load (X86ProducerGprStore.chunk row) complete.after ready.gprs.block (X86ProducerGprStore.offset row) =
      if row = 8 then some (.Vlong X86ProducerPushRspStore.nextRsp)
      else CC.Mem.load (X86ProducerGprStore.chunk row) ready.after ready.gprs.block (X86ProducerGprStore.offset row) := by
  by_cases selected : row = 8
  · subst row
    exact complete.rsp_read
  · rw [if_neg selected]
    have old : ready.gprs.block.toNat < ready.after.nextblock.toNat := by
      rw [ready.frontier]
      exact ready.gprs.owned
    exact (complete.old_frame.load _ _ _ old).trans
      ((cache.gprs _ _).trans ((metadata.gprs _ _).trans
        ((rsp.rows row selected).trans ((X86ProducerPushBody.entry_frame ready.after).2.load _ _ _ old))))

private theorem rows : ∀ i : Fin 16,
    X86ProducerGprStore.chunk (X86ProducerGprSites.valueRow i) = CC.Mptr ∧
    X86ProducerGprStore.offset (X86ProducerGprSites.valueRow i) = 16 * (i.val : Int) ∧
    X86ProducerGprStore.chunk (X86ProducerGprSites.tagRow i) = .Mint8unsigned ∧
    X86ProducerGprStore.offset (X86ProducerGprSites.tagRow i) = 16 * (i.val : Int) + 8 ∧
    (i ≠ 4 → X86ProducerGprSites.valueRow i ≠ 8) ∧
    X86ProducerGprSites.tagRow i ≠ 8 ∧
    CC.Integers.Ptrofs.unsigned (0 + CC.Integers.Ptrofs.repr (16 * (i.val : Int))) = 16 * (i.val : Int) ∧
    CC.Integers.Ptrofs.unsigned ((0 + CC.Integers.Ptrofs.repr (16 * (i.val : Int))) + 8) = 16 * (i.val : Int) + 8 := by
  decide +kernel

/-- Initial relative RSP zero represents the SAME native stack origin. -/
theorem initial_sp (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu) :
    cpu.regs.get (X86.GPR.ofIndex 4) = origins.stack := by
  have read := (ready.gpr_reads 4 (by decide)).1
  rw [ready.rsp_zero] at read
  have native := X86RegisterReadRspNative.native_word addresses origins ready.after ready.gprs.block 0 cpu 0 represented read
  simpa using native

/-- Projection of the completed actual source call into the existing native
register relation. This is a register projection, not a fetched-ISA step:
native memory, faults, PC and input-oracle correspondence remain separate. -/
theorem registers (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 cpu) :
    X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0
      (cpu.setReg .q (X86.GPR.ofIndex 4) (X86ProducerPushRspStore.nextRsp + origins.stack)) := by
  intro other
  by_cases same : other = 4
  · subst other
    refine ⟨.Vlong X86ProducerPushRspStore.nextRsp, X86ProducerPushRspStore.nextRsp, 0,
      complete.rsp_read, complete.rsp_tag, rfl, ?_⟩
    simp [X86.Cpu.setReg, X86.Value.writeView, Reference.Provenance.X86.materialize]
  · obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented other
    have facts := rows other
    have word := table complete (X86ProducerGprSites.valueRow other)
    have tags := table complete (X86ProducerGprSites.tagRow other)
    rw [facts.1, facts.2.1, if_neg (facts.2.2.2.2.1 same)] at word
    rw [facts.2.2.1, facts.2.2.2.1, if_neg facts.2.2.2.2.2.1] at tags
    rw [facts.2.2.2.2.2.2.1] at wordRead
    rw [facts.2.2.2.2.2.2.2] at tagRead
    refine ⟨value, raw, tag, ?_, ?_, valueRep, ?_⟩
    · rw [facts.2.2.2.2.2.2.1]
      exact word.trans wordRead
    · rw [facts.2.2.2.2.2.2.2]
      exact tags.trans tagRead
    · have different : X86.GPR.ofIndex (4 : Fin 16) ≠ X86.GPR.ofIndex other := by
        intro equal
        have encoded := congrArg X86.GPR.index equal
        exact same (by simpa only [X86.GPR.index_ofIndex] using encoded.symm)
      change (cpu.regs.set (X86.GPR.ofIndex 4)
        (X86.Value.writeView .q (cpu.regs.get (X86.GPR.ofIndex 4))
          (X86ProducerPushRspStore.nextRsp + origins.stack))).get (X86.GPR.ofIndex other) = _
      exact (X86.Regs.get_set_ne _ _ _ _ different).trans native

end KProgFormal.ClightRefinement.X86ProducerPushGprView
