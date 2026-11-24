import KProgFormal.ClightRefinement.X86RegisterWriteRsp
import KProgFormal.ClightRefinement.X86RegisterView

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspTable
open X86RegisterView

/-- The actual RSP table stores write the reverse-materialized raw word.
Materializing that cell with the SAME native stack origin recovers the full
native result. Every other register retains its actual raw/tag representation. -/
theorem native (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory middle final : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (value : BitVec 64)
    (represented : RegistersRepresent addresses origins memory block base cpu)
    (wordStored : CC.Mem.store CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))))
      (.Vlong (value - origins.stack)) = some middle)
    (tagStored : CC.Mem.store .Mint8unsigned middle block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      (.Vint (0#32)) = some final) :
    RegistersRepresent addresses origins final block base
      (cpu.setReg .q (X86.GPR.ofIndex 4) value) := by
  let index : Fin 16 := 4
  let word := value - origins.stack
  intro other
  by_cases same : other = index
  · subst other
    have reads := X86ShiftWriteback.cell_write_readback memory middle final block
      (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) (.Vlong word) (0#8)
      wordStored tagStored
    have normalized : CC.Val.loadResult CC.Mptr (.Vlong word) = .Vlong word := rfl
    refine ⟨.Vlong word, word, 0, reads.1.trans (congrArg some normalized), reads.2, rfl, ?_⟩
    simp [index, word, X86.Cpu.setReg, X86.Value.writeView,
      Reference.Provenance.X86.materialize, BitVec.sub_add_cancel]
  · obtain ⟨rawValue, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented other
    have reads := X86ShiftWriteback.cell_write_other memory middle final block base index other
      (.Vlong word) (0#8) (Ne.symm same) wordStored tagStored
    have different : X86.GPR.ofIndex index ≠ X86.GPR.ofIndex other := by
      intro equal
      have encoded := congrArg X86.GPR.index equal
      exact same (by simpa only [X86.GPR.index_ofIndex] using encoded.symm)
    refine ⟨rawValue, raw, tag, reads.1.trans wordRead, reads.2.trans tagRead, valueRep, ?_⟩
    change (cpu.regs.set (X86.GPR.ofIndex index)
      (X86.Value.writeView .q (cpu.regs.get (X86.GPR.ofIndex index)) value)).get
        (X86.GPR.ofIndex other) = _
    exact (X86.Regs.get_set_ne _ _ _ _ different).trans native

/-- Initial table permissions construct both real stores and their native
view. The second store's permission is carried through the first one. -/
theorem writable (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (value : BitVec 64)
    (represented : RegistersRepresent addresses origins memory block base cpu)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true) :
    ∃ middle final,
      CC.Mem.store CC.Mptr memory block
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))))
        (.Vlong (value - origins.stack)) = some middle ∧
      CC.Mem.store .Mint8unsigned middle block
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
        (.Vint (0#32)) = some final ∧
      RegistersRepresent addresses origins final block base
        (cpu.setReg .q (X86.GPR.ofIndex 4) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ block →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  have existsWord : ∃ middle, CC.Mem.store CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))))
      (.Vlong (value - origins.stack)) = some middle := by
    simp only [CC.Mem.store, wordPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨middle, wordStored⟩ := existsWord
  have tagWritable := (CC.Mem.validAccess_store_eq wordStored .Mint8unsigned block
    (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
    .Writable).trans tagPermission
  have existsTag : ∃ final, CC.Mem.store .Mint8unsigned middle block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      (.Vint (0#32)) = some final := by
    simp only [CC.Mem.store, tagWritable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨final, tagStored⟩ := existsTag
  refine ⟨middle, final, wordStored, tagStored,
    native addresses origins memory middle final block base cpu value represented
      wordStored tagStored,
    (CC.Mem.store_access tagStored).trans (CC.Mem.store_access wordStored),
    (CC.Mem.store_nextblock tagStored).trans (CC.Mem.store_nextblock wordStored), ?_⟩
  intro chunk other offset different
  exact (CC.Mem.load_store_other tagStored chunk other offset (.inl different)).trans
    (CC.Mem.load_store_other wordStored chunk other offset (.inl different))

end KProgFormal.ClightRefinement.X86RegisterWriteRspTable
