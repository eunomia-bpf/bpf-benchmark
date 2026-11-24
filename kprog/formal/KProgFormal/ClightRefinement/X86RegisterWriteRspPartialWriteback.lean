import KProgFormal.ClightRefinement.X86RegisterWriteRspPartialStore
import KProgFormal.ClightRefinement.X86RegisterWriteRspStable
import KProgFormal.ClightRefinement.X86RegisterReadRspNative

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspPartialWriteback
open X86RegisterView

/-- The actual byte/word RSP add-base, scalar partial store, reverse-base,
real table stores, non-increasing release and writer-loop exit compose.
The native old RSP comes from the SAME original cell load and register
relation; its upper56/48 bits are retained by the real partial store. -/
theorem from_leaf (isWord : Bool) (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs) (old next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong old))
    (scalarTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (low : isWord = false → le.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rspRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some (.Vlong old))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock ∧ baseBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock cellsOffset cpu)
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) next - origins.stack) old = false)
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + 64) + 8)) .Writable = true) :
    ∃ final finalTemps, InternalRun ge ((13 + (if isWord then 11 else 12)) + 56 + 2)
      (.State function (X86RegisterWriteRspPartial.leaf isWord)
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock cellsOffset
        (cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) next) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  let result := X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) next
  obtain ⟨middle, partialRun, currentWord, access, nextBlock, frame⟩ :=
    X86RegisterWriteRspPartialStore.execute isWord ge layout valueLayout function e le
      (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) memory bindingBlock localBlock
      baseBlock baseOffset old origins.stack next declared binding destination current header nativeBase
      localPermission scalarTag observed low
  let materialized := X86RegisterWriteRspPartial.temps isWord le baseBlock baseOffset old origins.stack
  let reached := X86RegisterWriteRspScalarSuffix.temps isWord materialized next
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    cases isWord <;> simp +decide [reached, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, binding]
  have keptDestination : reached.get X86_program_profile_bpf._dst = some (.Vint (4#32)) := by
    cases isWord <;> simp +decide [reached, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, destination]
  have keptOld : reached.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    cases isWord <;> simp +decide [reached, materialized, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86WordStorage.laneTemps, X86ShiftWriteback.byteTemps, X86ShiftWriteback.byteLaneTemps,
      X86RegisterWriteRspPartial.temps, X86RegisterWriteRspWord.temps, X86RegisterWriteRspByte.temps, CC.PTree.gso, oldSp]
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    cases isWord <;> simp only [reached, X86RegisterWriteRspScalarSuffix.temps,
      X86WordStorage.temps, X86ShiftWriteback.byteTemps, CC.PTree.gss,
      Bool.false_eq_true, ite_true, ite_false]
  have keptRegisters : RegistersRepresent addresses origins middle cellsBlock cellsOffset cpu := by
    intro index
    obtain ⟨rawValue, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
    exact ⟨rawValue, raw, tag, (frame CC.Mptr cellsBlock _ localSeparate.2.1).trans wordRead,
      (frame .Mint8unsigned cellsBlock _ localSeparate.2.1).trans tagRead, valueRep, native⟩
  have permissions (chunk : CC.Chunk) (block : CC.Block) (offset : Int) :
      CC.Mem.validAccess middle chunk block offset .Writable = CC.Mem.validAccess memory chunk block offset .Writable := by
    apply CC.Mem.validAccess_congr
    intro point
    simp only [CC.Mem.perm, access]
  obtain ⟨final, completed, registers, _, finalAccess, finalNext, finalFrame⟩ :=
    X86RegisterWriteRspStable.execute ge layout valueLayout function e reached (X86ShiftWriteback.loadCont k)
      middle bindingBlock localBlock baseBlock cellsBlock baseOffset cellsOffset result old addresses origins cpu
      declared keptBinding keptDestination currentWord
      ((frame CC.Mptr bindingBlock 112 localSeparate.1).trans header)
      ((frame .Mint64 baseBlock _ localSeparate.2.2).trans nativeBase)
      ((permissions CC.Mptr localBlock 0).trans localPermission)
      ⟨Ne.symm localSeparate.1, Ne.symm localSeparate.2.1⟩ bindingSeparate
      ((frame CC.Mptr bindingBlock 0 localSeparate.1).trans cells) keptTag keptRegisters keptOld nonIncreasing
      ((permissions CC.Mptr cellsBlock _).trans wordPermission)
      ((permissions .Mint8unsigned cellsBlock _).trans tagPermission)
  have nativeOld := X86RegisterReadRspNative.native_word addresses origins memory cellsBlock cellsOffset cpu old represented rspRead
  have writes : cpu.setReg .q (X86.GPR.ofIndex 4) result =
      cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) next := by
    cases isWord <;> simp [result, X86.Cpu.setReg, X86.Value.writeView, nativeOld]
  refine ⟨final, _, (partialRun.trans completed).trans
    (X86ShiftWriteback.load_exit ge function e _ k final), ?_, finalAccess.trans access, finalNext.trans nextBlock, ?_⟩
  · simpa only [writes] using registers
  · intro chunk other offset notLocal notCells
    exact (finalFrame chunk other offset notLocal notCells).trans (frame chunk other offset notLocal)

end KProgFormal.ClightRefinement.X86RegisterWriteRspPartialWriteback
