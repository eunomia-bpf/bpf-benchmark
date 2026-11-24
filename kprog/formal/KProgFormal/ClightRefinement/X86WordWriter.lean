import KProgFormal.ClightRefinement.X86WordWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs

namespace KProgFormal.ClightRefinement.X86WordWriter
open X86RegisterView

/-- The actual ordinary scalar/tag0 word16 writer, including old-SP and old-cell reads,
width helper, local union copy, partial low16 overwrite and both table
stores. Initial representation and permissions construct every read/cast/store. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (old value : BitVec 64) (shift : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .w))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (oldRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (.Vlong old))
    (tagRead : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
      some (.Vint (0#32)))
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge 181
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .w (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨stack, stackRead, stackCast⟩ :=
    X86RegisterWriterInputs.stack addresses origins memory cellsBlock base cpu represented
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong old) = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  have entryRun := X86ShiftWriteback.narrow_storage ge layout.bindings layout.gpr layout.cell
    function e le k memory bindingBlock cellsBlock base stack binding cells stackRead stackCast
    index .w (by decide) destination width alu widthBlock widthBinding unshadowed shift value
    observedShift observedValue (.Vlong old) oldRead (by rfl) localBlock copied declared copiedStore (0#8) tagRead
    localSeparate scalarCode
  let reached := X86ShiftWriteback.classTemps
    (X86ShiftWriteback.tagTemps
      (X86ShiftWriteback.cellReadTemps
        (X86ShiftWriteback.writerWidthTemps
          (X86ShiftWriteback.loadTemps
            (X86ShiftWriteback.narrowSrcTemps (X86ShiftWriteback.narrowDstTemps
              (X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte index) .w)))
            cellsBlock base stack) .w shift value) cellsBlock base (.Vlong old))
      index cellsBlock base (0#8)) .w
  have reachedWidth : reached.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .w) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, CC.PTree.gso]
  have reachedValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso]
  have reachedTag : reached.get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (0#32)) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps, CC.PTree.gso]
  have reachedDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, X86ShiftWriteback.narrowSrcTemps,
      X86ShiftWriteback.narrowDstTemps, X86ShiftWriteback.selectTemps, CC.PTree.gso, destination]
  have reachedBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, X86ShiftWriteback.narrowSrcTemps,
      X86ShiftWriteback.narrowDstTemps, X86ShiftWriteback.selectTemps, CC.PTree.gso, binding]
  have copiedFrame : ∀ chunk other offset, other ≠ localBlock →
      CC.Mem.load chunk copied other offset = CC.Mem.load chunk memory other offset := by
    intro chunk other offset different
    exact CC.Mem.load_store_other copiedStore chunk other offset (.inl different)
  have copiedRegisters : RegistersRepresent addresses origins copied cellsBlock base cpu := by
    intro row
    obtain ⟨v, raw, t, vr, tr, rep, native⟩ := represented row
    exact ⟨v, raw, t, (copiedFrame _ cellsBlock _ localSeparate.2).trans vr,
      (copiedFrame _ cellsBlock _ localSeparate.2).trans tr, rep, native⟩
  obtain ⟨final, tailRun, native, access, next, kept⟩ :=
    X86WordWriteback.from_storage ge layout function e reached k memory copied localBlock bindingBlock
      cellsBlock base index old value declared copiedStore reachedWidth reachedValue reachedTag
      reachedDestination ordinary reachedBinding
      ((copiedFrame _ bindingBlock _ localSeparate.1).trans cells) bindingSeparate localSeparate
      addresses origins cpu copiedRegisters
      ((copiedFrame _ cellsBlock _ localSeparate.2).trans oldRead)
      ((copiedFrame _ cellsBlock _ localSeparate.2).trans tagRead)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans tagPermission)
  refine ⟨final, _, entryRun.trans tailRun, native,
    access.trans (CC.Mem.store_access copiedStore),
    next.trans (CC.Mem.store_nextblock copiedStore), ?_⟩
  intro chunk other offset notLocal notCells
  exact (kept chunk other offset notLocal notCells).trans (copiedFrame chunk other offset notLocal)

end KProgFormal.ClightRefinement.X86WordWriter
