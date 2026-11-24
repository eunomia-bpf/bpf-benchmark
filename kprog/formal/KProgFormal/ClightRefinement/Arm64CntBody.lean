import KProgFormal.ClightRefinement.Arm64CntDispatch

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Body

abbrev inputs := Path.inputs

private theorem leave_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  exact .refl _

/-- The complete original CNT handler body uses the real width call,
all 38 dispatch gates, both reductions and stores, and the outer-loop exit. -/
theorem execute {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (reductionFree : e.get Arm64Program._kprog_arm64_reduction = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (16#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8))) :
    ∃ count after le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le before)
      (.State Arm64Nop.handler .Sskip k e le' after) ∧
      VectorMemory.Effect before after old.vectors.block
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0).setWidth 64))
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0 >>> 64).setWidth 64)) ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  obtain ⟨dispatchCount,dispatchTemps,dispatchRun,width,dispatchKept⟩ :=
    Dispatch.body_dispatch e le before k widthFree flags op
  have entryAt : dispatchTemps.get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (dispatchKept _ (by decide +kernel)).trans entryRead
  have opAt : dispatchTemps.get Arm64Program._op = some (.Vint (36#32)) :=
    (dispatchKept _ (by decide +kernel)).trans op
  have auxAt : dispatchTemps.get Arm64Program._aux = some (.Vint (16#32)) :=
    (dispatchKept _ (by decide +kernel)).trans aux
  obtain ⟨after,le',pathCount,pathRun,effect,writable,pathKept⟩ :=
    Path.execute old addresses origins s represented e dispatchTemps (Dispatch.continuation k)
      reductionFree entryAt opAt auxAt
  refine ⟨_,after,le',(dispatchRun.trans pathRun).trans (leave_loop e le' after k),effect,writable,?_⟩
  intro id inside
  exact (pathKept id inside).trans (dispatchKept id inside)

/-- The actual complete Clight handler refines the fetched LNSym CNT step.
Original storage supplies both inputs and allocation supplies both writes. -/
theorem corresponds {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (reductionFree : e.get Arm64Program._kprog_arm64_reduction = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (16#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (decoded : instruction.decoded = .DPSFP (.Advanced_simd_two_reg_misc Native.fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count after le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le before)
      (.State Arm64Nop.handler .Sskip k e le' after) ∧
      VectorMemory.Effect before after old.vectors.block
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0).setWidth 64))
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0 >>> 64).setWidth 64)) ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after
        (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (∀ id ∈ inputs, le'.get id = le.get id) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
        id ≠ Arm64Entry.___a64_vectors → ∀ chunk offset,
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) ∧
      Reference.AArch64.step s = ⟨Native.after s,[],none⟩ := by
  have native := Native.reference_step s instruction decoded noError fetched
  obtain ⟨count,after,le',run,effect,writable,kept⟩ :=
    execute old addresses origins s represented e le k widthFree reductionFree entryRead op aux flags
  obtain ⟨lowRead,highRead⟩ := Inputs.words old addresses origins s represented
  have afterRep := NativeView.represents old _ _ effect addresses origins s represented lowRead highRead
  refine ⟨count,after,le',run,effect,writable,?_,kept,?_,native⟩
  · rw [native]
    exact afterRep
  · intro id ty block binding different chunk offset
    exact effect.other chunk block offset
      (Arm64Fmov.VectorStorage.separate old.vectors id ty block binding different)

end KProgFormal.ClightRefinement.Arm64Cnt.Body
