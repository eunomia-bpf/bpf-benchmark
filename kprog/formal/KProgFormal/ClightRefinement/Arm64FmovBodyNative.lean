import KProgFormal.ClightRefinement.Arm64FmovBody
import KProgFormal.ClightRefinement.Arm64FmovNativeView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Body

/-- The complete original FMOV64 handler refines its fetched imported LNSym
step. Actual scalar/tag0 memory determines X7, allocation permissions derive
both stores, and their exact effect preserves all other producer locals. -/
theorem corresponds {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (writable : Arm64VectorWritable.Writable old.vectors before)
    (oldLow value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (oldVector : CC.Mem.load .Mint64 before old.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock 7) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock 7) 0 = some (.Vint 0))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (reader : e.get Arm64Program._kprog_arm64_program_read = none)
    (destination : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (7#64)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (op : le.get Arm64Program._op = some (.Vint (35#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (decoded : instruction.decoded = .DPSFP (.Conversion_between_FP_and_Int Native.fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count after le', VectorMemory.Effect before after old.vectors.block value ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le before)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after
        (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (∀ id ∈ inputs, le'.get id = le.get id) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
        id ≠ Arm64Entry.___a64_vectors → ∀ chunk offset,
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) ∧
      Reference.AArch64.step s = ⟨Native.after s,[],none⟩ := by
  have native := Native.reference_step s instruction decoded noError fetched
  obtain ⟨count,after,le',effect,afterWritable,run,kept⟩ := execute old writable 7 oldLow value e le k
    widthFree reader destination entryRead index source aux op flags oldVector word tag
  have afterRep := NativeView.represents old value effect addresses origins s represented word tag
  refine ⟨count,after,le',effect,afterWritable,run,?_,kept,?_,native⟩
  · rw [native]
    exact afterRep
  · intro id ty block binding different chunk offset
    exact VectorStorage.local_load old.vectors value effect id ty block binding different chunk offset

end KProgFormal.ClightRefinement.Arm64Fmov.Body
