import KProgFormal.ClightRefinement.X86WordStorage
import KProgFormal.ClightRefinement.X86WordTable

namespace KProgFormal.ClightRefinement.X86WordWriteback
open X86RegisterView

private theorem ordinary_code : ∀ index : Fin 16, index ≠ 4 →
    (BitVec.ofNat 8 index.val).setWidth 32 ≠ (4#32) := by decide +kernel

/-- The actual table writer reads the merged local word, stores its real row
and scalar tag, then exits. Native low16 refinement uses the same old table word. -/
theorem table (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (old next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 =
      some (.Vlong (X86.Value.writeView .w old next)))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (selected : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
      some (.Vint (0#32)))
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ middle final,
      InternalRun ge 26
        (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le memory)
        (.State function .Sskip k e
          (X86ShiftWriteback.tableTemps le (.Vlong (X86.Value.writeView .w old next))
            (0#8) index cellsBlock base) final) ∧
      CC.Mem.store CC.Mptr memory cellsBlock
        (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
        (.Vlong (X86.Value.writeView .w old next)) = some middle ∧
      CC.Mem.store .Mint8unsigned middle cellsBlock
        (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
        (.Vint (0#32)) = some final ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .w (X86.GPR.ofIndex index) next) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨middle, final, wordStored, tagStored, registers, access, frontier, kept⟩ :=
    X86WordTable.writable addresses origins memory cellsBlock base cpu index old next ordinary
      represented selected scalar wordPermission tagPermission
  have executed := X86ShiftWriteback.table_internal ge layout.bindings layout.gpr layout.cell function e le k
    memory middle final localBlock bindingBlock cellsBlock base index
    (.Vlong (X86.Value.writeView .w old next)) (0#8) declared current tag destination
    (ordinary_code index ordinary) binding cells (by rfl) bindingSeparate wordStored tagStored
  exact ⟨middle, final, executed, wordStored, tagStored, registers, access, frontier, kept⟩

/-- Original low16 selection/store, destination route, actual table stores and
writer-loop exit compose in56 transitions. The local initialization supplies
partial-store rights; every intermediate observation follows from source inputs. -/
theorem from_storage (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (old next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (initialized : CC.Mem.store CC.Mptr before localBlock 0 (.Vlong old) = some memory)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 = some (X86ShiftLeft.argument .w))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (selected : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
      some (.Vint (0#32)))
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    let ready := X86WordStorage.temps (X86WordStorage.selectionTemps le) next
    ∃ final, InternalRun ge 56
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e le memory)
      (.State function .Sskip k e
        (X86ShiftWriteback.tableTemps ready (.Vlong (X86.Value.writeView .w old next))
          (0#8) index cellsBlock base) final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .w (X86.GPR.ofIndex index) next) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  dsimp only
  let ready := X86WordStorage.temps (X86WordStorage.selectionTemps le) next
  obtain ⟨localMem, localStored, storedRun, localRead, _, localAccess, localFrontier, localKept⟩ :=
    X86WordStorage.execute ge layout.gpr function e le
      (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) before memory localBlock
      (X86RegisterReadValue.registerByte index) old next declared initialized width destination
      (ordinary_code index ordinary) tag observed
  have destinationReady : ready.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    simp +decide [ready, X86WordStorage.temps, X86WordStorage.laneTemps,
      X86WordStorage.selectionTemps, CC.PTree.gso, destination]
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [ready, X86WordStorage.temps, X86WordStorage.laneTemps,
      X86WordStorage.selectionTemps, CC.PTree.gso, binding]
  have tagReady : ready.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    simp only [ready, X86WordStorage.temps, CC.PTree.gss]
  have afterRegisters : RegistersRepresent addresses origins localMem cellsBlock base cpu := by
    intro row
    obtain ⟨rawValue, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented row
    exact ⟨rawValue, raw, tag, (localKept _ cellsBlock _ localSeparate.2).trans wordRead,
      (localKept _ cellsBlock _ localSeparate.2).trans tagRead, valueRep, native⟩
  have entered := X86ShiftWriteback.storage_enter ge function e ready (X86ShiftWriteback.loadCont k)
    localMem (X86RegisterReadValue.registerByte index) destinationReady (ordinary_code index ordinary)
  obtain ⟨middle, final, tableRun, _, _, registers, access, frontier, kept⟩ :=
    table ge layout function e ready (X86ShiftWriteback.loadCont k) localMem localBlock bindingBlock
      cellsBlock base index old next declared localRead tagReady destinationReady ordinary bindingReady
      ((localKept _ bindingBlock _ localSeparate.1).trans cells) bindingSeparate addresses origins cpu
      afterRegisters ((localKept _ cellsBlock _ localSeparate.2).trans selected)
      ((localKept _ cellsBlock _ localSeparate.2).trans scalar)
      ((CC.Mem.validAccess_store_eq localStored _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq localStored _ _ _ .Writable).trans tagPermission)
  have exited := X86ShiftWriteback.load_exit ge function e
    (X86ShiftWriteback.tableTemps ready (.Vlong (X86.Value.writeView .w old next))
      (0#8) index cellsBlock base) k final
  refine ⟨final, ((storedRun.trans entered).trans tableRun).trans exited, registers,
    access.trans localAccess, frontier.trans localFrontier, ?_⟩
  intro chunk other offset notLocal notCells
  exact (kept chunk other offset notCells).trans (localKept chunk other offset notLocal)

end KProgFormal.ClightRefinement.X86WordWriteback
