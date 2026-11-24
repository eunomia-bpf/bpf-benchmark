import KProgFormal.ClightRefinement.X86FullWidthStorage
import KProgFormal.ClightRefinement.X86RegisterWriteRspStable

namespace KProgFormal.ClightRefinement.X86FullWidthRspWriteback
open X86RegisterView

/-- The actual32/64-bit local overwrite, reverse materialization, table
stores and non-increasing raw-SP release compose through the writer-loop exit.
All intermediate reads, stores, permissions and the native RSP view derive
from initial state and the original source observations. -/
theorem from_storage (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs) (value old : BitVec 64) (narrow : Bool)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument (if narrow then .d else .q)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock ∧ baseBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86FullWidthStorage.result narrow value - origins.stack) old = false)
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + 64) + 8)) .Writable = true) :
    ∃ final finalTemps, InternalRun ge (26 + (if narrow then 10 else 7) + 56 + 2)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        (cpu.setReg (if narrow then .d else .q) (X86.GPR.ofIndex 4) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨middle, stored, overwritten, current, access, next, frame⟩ :=
    X86FullWidthStorage.execute ge layout function e le
      (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) memory localBlock value narrow
      declared width observed localPermission
  let reached := X86FullWidthStorage.temps (X86FullWidthStorage.selectionTemps le narrow) narrow value
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    cases narrow <;> simp +decide [reached, X86FullWidthStorage.temps, X86FullWidthStorage.selectionTemps,
      CC.PTree.gso, binding]
  have keptDestination : reached.get X86_program_profile_bpf._dst = some (.Vint (4#32)) := by
    cases narrow <;> simp +decide [reached, X86FullWidthStorage.temps, X86FullWidthStorage.selectionTemps,
      CC.PTree.gso, destination]
  have keptOld : reached.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    cases narrow <;> simp +decide [reached, X86FullWidthStorage.temps, X86FullWidthStorage.selectionTemps,
      CC.PTree.gso, oldSp]
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    simp only [reached, X86FullWidthStorage.temps, CC.PTree.gss]
  have keptRegisters : RegistersRepresent addresses origins middle cellsBlock cellsOffset cpu := by
    intro index
    obtain ⟨rawValue, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
    exact ⟨rawValue, raw, tag, (frame CC.Mptr cellsBlock _ localSeparate.2.1).trans wordRead,
      (frame .Mint8unsigned cellsBlock _ localSeparate.2.1).trans tagRead, valueRep, native⟩
  obtain ⟨final, completed, registers, readback, finalAccess, finalNext, finalFrame⟩ :=
    X86RegisterWriteRspStable.execute ge layout valueLayout function e reached
      (X86ShiftWriteback.loadCont k) middle bindingBlock localBlock baseBlock cellsBlock baseOffset cellsOffset
      (X86FullWidthStorage.result narrow value) old addresses origins cpu declared keptBinding keptDestination
      current ((frame CC.Mptr bindingBlock 112 localSeparate.1).trans header)
      ((frame .Mint64 baseBlock _ localSeparate.2.2).trans nativeBase)
      ((CC.Mem.validAccess_store_eq stored _ _ _ .Writable).trans localPermission)
      ⟨Ne.symm localSeparate.1, Ne.symm localSeparate.2.1⟩ bindingSeparate
      ((frame CC.Mptr bindingBlock 0 localSeparate.1).trans cells) keptTag keptRegisters keptOld nonIncreasing
      ((CC.Mem.validAccess_store_eq stored _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq stored _ _ _ .Writable).trans tagPermission)
  have writes : cpu.setReg .q (X86.GPR.ofIndex 4) (X86FullWidthStorage.result narrow value) =
      cpu.setReg (if narrow then .d else .q) (X86.GPR.ofIndex 4) value := by
    cases narrow <;> simp [X86FullWidthStorage.result, X86.Cpu.setReg, X86.Value.writeView, X86.Value.trunc_trunc]
  refine ⟨final, _, (overwritten.trans completed).trans
    (X86ShiftWriteback.load_exit ge function e _ k final), ?_, finalAccess.trans access, finalNext.trans next, ?_⟩
  · simpa only [writes] using registers
  · intro chunk other offset notLocal notCells
    exact (finalFrame chunk other offset notLocal notCells).trans (frame chunk other offset notLocal)

end KProgFormal.ClightRefinement.X86FullWidthRspWriteback
