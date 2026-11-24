import KProgFormal.ClightRefinement.X86FullWidthTable

namespace KProgFormal.ClightRefinement.X86FullWidthWriteback
open X86RegisterView

private theorem ordinary_code : ∀ index : Fin 16, index ≠ 4 →
    (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32) := by decide +kernel

/-- The original table writer loads its real local word/tag, stores the
selected row and exits in26 Clight transitions. Initial table permissions
construct both actual stores and the final native GPR view; other block
loads, access map and allocation frontier are preserved. -/
theorem table (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (value : BitVec 64) (narrow : Bool)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 =
      some (.Vlong (X86FullWidthStorage.result narrow value)))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ middle final,
      InternalRun ge 26
        (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le memory)
        (.State function .Sskip k e
          (X86ShiftWriteback.tableTemps le (.Vlong (X86FullWidthStorage.result narrow value))
            (0#8) index cellsBlock base) final) ∧
      CC.Mem.store CC.Mptr memory cellsBlock
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
        (.Vlong (X86FullWidthStorage.result narrow value)) = some middle ∧
      CC.Mem.store .Mint8unsigned middle cellsBlock
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
        (.Vint (0#32)) = some final ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg (if narrow then .d else .q) (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨middle, final, wordStored, tagStored, registers, access, next, kept⟩ :=
    X86FullWidthTable.writable addresses origins memory cellsBlock base cpu index value narrow ordinary
      represented wordPermission tagPermission
  have run := X86ShiftWriteback.table_internal ge layout.bindings layout.gpr layout.cell function e le k
    memory middle final localBlock bindingBlock cellsBlock base index
    (.Vlong (X86FullWidthStorage.result narrow value)) (0#8) declared current tag destination
    (ordinary_code index ordinary) binding cells (by rfl) bindingSeparate wordStored tagStored
  exact ⟨middle, final, run, wordStored, tagStored, registers, access, next, kept⟩

end KProgFormal.ClightRefinement.X86FullWidthWriteback
