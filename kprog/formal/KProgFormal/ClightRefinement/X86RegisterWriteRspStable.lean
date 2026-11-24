import KProgFormal.ClightRefinement.X86RegisterWriteRspStorage
import KProgFormal.ClightRefinement.X86RegisterWriteRspRelease

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspStable
open X86RegisterView

/-- Genuine reverse materialization, both table stores and the actual
non-increasing raw-SP release branch compose into the original continuation.
The new-SP read and every release input derive from the same source run. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (bindingBlock localBlock baseBlock cellsBlock : CC.Block)
    (baseOffset cellsOffset : CC.Integers.Ptrofs) (value old : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong value))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (permission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (localSeparate : localBlock ≠ bindingBlock ∧ localBlock ≠ cellsBlock)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (represented : RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt (value - origins.stack) old = false)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + 64) + 8)) .Writable = true) :
    ∃ final, InternalRun ge 56
      (.State function .Sskip (.Kseq X86ShiftWriteback.storageTail k) e le memory)
      (.State function .Sskip k e
        (X86RegisterWriteRspRelease.temps
          (X86ShiftWriteback.tableTemps
            (X86RegisterWriteRsp.temps le baseBlock baseOffset value origins.stack)
            (.Vlong (value - origins.stack)) (0#8) 4 cellsBlock cellsOffset)
          cellsBlock cellsOffset old (value - origins.stack)) final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        (cpu.setReg .q (X86.GPR.ofIndex 4) value) ∧
      CC.Mem.load CC.Mptr final cellsBlock (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) =
        some (.Vlong (value - origins.stack)) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨final, written, registers, readback, access, next, frame⟩ :=
    X86RegisterWriteRspStorage.execute_readback ge layout valueLayout function e le k memory
      bindingBlock localBlock baseBlock cellsBlock baseOffset cellsOffset value addresses origins cpu
      declared binding destination current header native permission localSeparate bindingSeparate cells tag
      represented wordPermission tagPermission
  let reached := X86ShiftWriteback.tableTemps
    (X86RegisterWriteRsp.temps le baseBlock baseOffset value origins.stack)
    (.Vlong (value - origins.stack)) (0#8) 4 cellsBlock cellsOffset
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps,
      X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps,
      X86RegisterWriteRsp.temps, CC.PTree.gso, binding]
  have keptDestination : reached.get X86_program_profile_bpf._dst = some (.Vint (4#32)) := by
    simp +decide [reached, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps,
      X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps,
      X86RegisterWriteRsp.temps, CC.PTree.gso, destination]
  have keptOld : reached.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    simp +decide [reached, X86ShiftWriteback.tableTemps, X86ShiftWriteback.tableStoreTemps,
      X86ShiftWriteback.tableIndexTemps, X86ShiftWriteback.tableLoadTemps,
      X86RegisterWriteRsp.temps, CC.PTree.gso, oldSp]
  have keptCells := (frame CC.Mptr bindingBlock 0 (Ne.symm localSeparate.1) bindingSeparate).trans cells
  have released := X86RegisterWriteRspRelease.unchanged ge layout function e reached k final
    bindingBlock cellsBlock cellsOffset old (value - origins.stack)
    keptBinding keptDestination keptOld keptCells readback nonIncreasing
  exact ⟨final, written.trans released, registers, readback, access, next, frame⟩

end KProgFormal.ClightRefinement.X86RegisterWriteRspStable
