import KProgFormal.ClightRefinement.X86FullWidthStorage
import KProgFormal.ClightRefinement.X86RegisterView

namespace KProgFormal.ClightRefinement.X86FullWidthTable
open X86RegisterView

/-- The two real32/64-bit table stores implement native whole-register
writeback. Every other row preserves its raw word, tag and pointer origin;
the destination is scalarized, independent of its previous representation. -/
theorem native (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory middle final : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (index : Fin 16) (value : BitVec 64) (narrow : Bool) (ordinary : index ≠ 4)
    (represented : RegistersRepresent addresses origins memory block base cpu)
    (wordStored : CC.Mem.store CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
      (.Vlong (X86FullWidthStorage.result narrow value)) = some middle)
    (tagStored : CC.Mem.store .Mint8unsigned middle block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      (.Vint (0#32)) = some final) :
    RegistersRepresent addresses origins final block base
      (cpu.setReg (if narrow then .d else .q) (X86.GPR.ofIndex index) value) := by
  let word := X86FullWidthStorage.result narrow value
  intro other
  by_cases same : other = index
  · subst other
    have reads := X86ShiftWriteback.cell_write_readback memory middle final block
      (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) (.Vlong word) (0#8)
      wordStored tagStored
    have normalized : CC.Val.loadResult CC.Mptr (.Vlong word) = .Vlong word := rfl
    refine ⟨.Vlong word, word, 0, reads.1.trans (congrArg some normalized), reads.2, rfl, ?_⟩
    cases narrow <;> simp [word, X86FullWidthStorage.result, X86.Cpu.setReg,
      X86.Value.writeView, Reference.Provenance.X86.materialize, ordinary]
  · obtain ⟨rawValue, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented other
    have reads := X86ShiftWriteback.cell_write_other memory middle final block base index other
      (.Vlong word) (0#8) (Ne.symm same) wordStored tagStored
    have different : X86.GPR.ofIndex index ≠ X86.GPR.ofIndex other := by
      intro equal
      have encoded := congrArg X86.GPR.index equal
      exact same (by simpa only [X86.GPR.index_ofIndex] using encoded.symm)
    refine ⟨rawValue, raw, tag, reads.1.trans wordRead, reads.2.trans tagRead, valueRep, ?_⟩
    simpa only [X86.Cpu.setReg, X86.Regs.get_set_ne _ _ _ _ different] using native

/-- Initial table permissions construct both real stores and their native
view. The second store's permission is carried through the first one. -/
theorem writable (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (index : Fin 16) (value : BitVec 64) (narrow : Bool) (ordinary : index ≠ 4)
    (represented : RegistersRepresent addresses origins memory block base cpu)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ middle final,
      CC.Mem.store CC.Mptr memory block
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
        (.Vlong (X86FullWidthStorage.result narrow value)) = some middle ∧
      CC.Mem.store .Mint8unsigned middle block
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
        (.Vint (0#32)) = some final ∧
      RegistersRepresent addresses origins final block base
        (cpu.setReg (if narrow then .d else .q) (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ block →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  have existsWord : ∃ middle, CC.Mem.store CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
      (.Vlong (X86FullWidthStorage.result narrow value)) = some middle := by
    simp only [CC.Mem.store, wordPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨middle, wordStored⟩ := existsWord
  have tagWritable := (CC.Mem.validAccess_store_eq wordStored .Mint8unsigned block
    (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
    .Writable).trans tagPermission
  have existsTag : ∃ final, CC.Mem.store .Mint8unsigned middle block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      (.Vint (0#32)) = some final := by
    simp only [CC.Mem.store, tagWritable, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨final, tagStored⟩ := existsTag
  refine ⟨middle, final, wordStored, tagStored,
    native addresses origins memory middle final block base cpu index value narrow ordinary represented
      wordStored tagStored,
    (CC.Mem.store_access tagStored).trans (CC.Mem.store_access wordStored),
    (CC.Mem.store_nextblock tagStored).trans (CC.Mem.store_nextblock wordStored), ?_⟩
  intro chunk other offset different
  exact (CC.Mem.load_store_other tagStored chunk other offset (.inl different)).trans
    (CC.Mem.load_store_other wordStored chunk other offset (.inl different))

end KProgFormal.ClightRefinement.X86FullWidthTable
