import KProgFormal.ClightRefinement.X86RegisterWriteRspTable

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspPrefix
open X86RegisterView

/-- The original table writer executes its real local reads, index selection
and both RSP cell stores. The native GPR view is established at the exact
stack-release frontier; that remaining source branch is deliberately retained. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (cellsOffset : CC.Integers.Ptrofs) (value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong (value - origins.stack)))
    (observedTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (represented : RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + 64) + 8)) .Writable = true) :
    ∃ final, InternalRun ge 22
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le memory)
      (.State function .Sskip (X86ShiftWriteback.tableCont k) e
        (X86ShiftWriteback.tableTemps le (.Vlong (value - origins.stack)) (0#8) 4
          cellsBlock cellsOffset) final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        (cpu.setReg .q (X86.GPR.ofIndex 4) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  let raw : CC.Val := .Vlong (value - origins.stack)
  let tag : BitVec 8 := 0
  let index : Fin 16 := 4
  obtain ⟨middle, final, wordStored, tagStored, registers, access, next, frame⟩ :=
    X86RegisterWriteRspTable.writable addresses origins memory cellsBlock cellsOffset cpu value
      represented wordPermission tagPermission
  have prepared := X86ShiftWriteback.table_prepare ge layout.gpr function e le k memory localBlock raw tag
    declared current observedTag
  have indexCode : (X86RegisterReadValue.registerByte index).setWidth 32 = (4#32) := rfl
  have loadedDestination : (X86ShiftWriteback.tableLoadTemps le raw tag).get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    rw [indexCode]
    simp +decide [X86ShiftWriteback.tableLoadTemps, CC.PTree.gso, destination]
  have selected := X86ShiftWriteback.table_select ge function e
    (X86ShiftWriteback.tableLoadTemps le raw tag) k memory index loadedDestination
  let reached := X86ShiftWriteback.tableIndexTemps (X86ShiftWriteback.tableLoadTemps le raw tag) index
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps, CC.PTree.gso, binding]
  have keptIndex : reached.get X86_program_profile_bpf.___x86_store_reg__5 =
      some (.Vlong (BitVec.ofNat 64 index.val)) := by simp [reached, X86ShiftWriteback.tableIndexTemps]
  have keptValue : reached.get X86_program_profile_bpf.___x86_wr_next_ptr__5 = some raw := by
    simp +decide [reached, X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps, CC.PTree.gso]
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_next_tag__5 = some (.Vint (tag.setWidth 32)) := by
    simp +decide [reached, X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps, CC.PTree.gso]
  have written := X86ShiftWriteback.table_body ge layout.bindings layout.gpr layout.cell function e reached
    (X86ShiftWriteback.tableCont k) memory middle final bindingBlock cellsBlock cellsOffset index raw tag
    keptBinding cells keptIndex keptValue keptTag (by rfl) bindingSeparate wordStored tagStored
  exact ⟨final, (prepared.trans selected).trans written, registers, access, next, frame⟩

end KProgFormal.ClightRefinement.X86RegisterWriteRspPrefix
