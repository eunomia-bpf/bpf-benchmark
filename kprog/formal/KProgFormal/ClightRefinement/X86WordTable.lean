import KProgFormal.ClightRefinement.X86FullWidthTable
import KProgFormal.ClightRefinement.X86WordMemory

namespace KProgFormal.ClightRefinement.X86WordTable
open X86RegisterView

/-- The real whole-cell stores of the merged low16 result implement the same
native word update. The old scalar word comes from the represented table,
not an independent native/source correspondence assumption. -/
theorem writable (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (memory : CC.Mem)
    (block : CC.Block) (base : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (index : Fin 16) (old next : BitVec 64) (ordinary : index ≠ 4)
    (represented : RegistersRepresent addresses origins memory block base cpu)
    (selected : CC.Mem.load CC.Mptr memory block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned memory block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
      some (.Vint (0#32)))
    (wordPermission : CC.Mem.validAccess memory CC.Mptr block
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned block
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ middle final,
      CC.Mem.store CC.Mptr memory block
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
        (.Vlong (X86.Value.writeView .w old next)) = some middle ∧
      CC.Mem.store .Mint8unsigned middle block
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
        (.Vint (0#32)) = some final ∧
      RegistersRepresent addresses origins final block base (cpu.setReg .w (X86.GPR.ofIndex index) next) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ block →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  have selectedNative : cpu.regs.get (X86.GPR.ofIndex index) = old := by
    obtain ⟨value, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
    have valueEq : value = .Vlong old := Option.some.inj (wordRead.symm.trans selected)
    have tagEq32 : tag.setWidth 32 = (0#32) :=
      CC.Val.Vint.inj (Option.some.inj (tagRead.symm.trans scalar))
    have tagEq : tag = (0#8) := by
      simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) tagEq32
    have rawEq : raw = old := by simpa only [valueEq, Arm64Registers.ValueRep] using valueRep
    simpa [Reference.Provenance.X86.materialize, ordinary, rawEq, tagEq] using native
  have updated : cpu.setReg .q (X86.GPR.ofIndex index) (X86.Value.writeView .w old next) =
      cpu.setReg .w (X86.GPR.ofIndex index) next := by
    simp [X86.Cpu.setReg, X86.Value.writeView, selectedNative]
  simpa only [X86FullWidthStorage.result, Bool.false_eq_true, ite_false, updated] using
    X86FullWidthTable.writable addresses origins memory block base cpu index
      (X86.Value.writeView .w old next) false ordinary represented wordPermission tagPermission

end KProgFormal.ClightRefinement.X86WordTable
