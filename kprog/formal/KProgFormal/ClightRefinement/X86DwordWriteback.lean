import KProgFormal.ClightRefinement.X86FullWidthWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs

namespace KProgFormal.ClightRefinement.X86DwordWriteback
open X86RegisterView

/-- The actual ordinary dword writer, including old-SP and old-cell reads,
width helper, local union copy, zero-extending overwrite and both table
stores. Initial representation and permissions construct every read/cast/store. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (value : BitVec 64) (shift : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .d))
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
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge 197
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .d (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨stack, stackRead, stackCast⟩ :=
    X86RegisterWriterInputs.stack addresses origins memory cellsBlock base cpu represented
  obtain ⟨old, tag, oldRead, tagRead, copyCast⟩ :=
    X86RegisterWriterInputs.cell addresses origins memory cellsBlock base cpu represented index
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 old = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  have entryRun := X86ShiftWriteback.narrow_storage ge layout.bindings layout.gpr layout.cell
    function e le k memory bindingBlock cellsBlock base stack binding cells stackRead stackCast
    index .d (by decide) destination width alu widthBlock widthBinding unshadowed shift value
    observedShift observedValue old oldRead copyCast localBlock copied declared copiedStore tag tagRead
    localSeparate scalarCode
  let reached := X86ShiftWriteback.classTemps
    (X86ShiftWriteback.tagTemps
      (X86ShiftWriteback.cellReadTemps
        (X86ShiftWriteback.writerWidthTemps
          (X86ShiftWriteback.loadTemps
            (X86ShiftWriteback.narrowSrcTemps (X86ShiftWriteback.narrowDstTemps
              (X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte index) .d)))
            cellsBlock base stack) .d shift value) cellsBlock base old)
      index cellsBlock base tag) .d
  have reachedWidth : reached.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .d) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, CC.PTree.gso]
  have reachedValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso]
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
    X86FullWidthWriteback.from_storage ge layout function e reached k copied localBlock bindingBlock
      cellsBlock base index value true declared reachedWidth reachedValue reachedDestination ordinary
      reachedBinding ((copiedFrame _ bindingBlock _ localSeparate.1).trans cells) bindingSeparate
      localSeparate addresses origins cpu copiedRegisters
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans localPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans tagPermission)
  refine ⟨final, _, entryRun.trans tailRun, native,
    access.trans (CC.Mem.store_access copiedStore),
    next.trans (CC.Mem.store_nextblock copiedStore), ?_⟩
  intro chunk other offset notLocal notCells
  exact (kept chunk other offset notLocal notCells).trans (copiedFrame chunk other offset notLocal)

end KProgFormal.ClightRefinement.X86DwordWriteback
