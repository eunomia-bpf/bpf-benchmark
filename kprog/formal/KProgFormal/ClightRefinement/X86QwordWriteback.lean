import KProgFormal.ClightRefinement.X86FullWidthWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs
import KProgFormal.ClightRefinement.X86QwordWriterSelectors

namespace KProgFormal.ClightRefinement.X86QwordWriteback
open X86RegisterView

/-- Complete original ordinary scalar-tag qword writer, including both real
destination-tag calls, all source selectors, old-SP and old-cell reads, width
helper, local copy/overwrite, table stores and loop exit. Every read, cast and
successful store derives from initial representation, observations and rights. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (index : Fin 16) (value : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (sourceShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (tagHelper : CC.Block)
    (tagBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some tagHelper ∧
      CC.Genv.findFunctPtr ge.genv_genv tagHelper =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (tagUnshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none)
    (ordinary : index ≠ 4)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (scalarTag : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument (0#8)))
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
    ∃ final finalTemps, InternalRun ge 252
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg .q (X86.GPR.ofIndex index) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  obtain ⟨stack, stackRead, stackCast⟩ :=
    X86RegisterWriterInputs.stack addresses origins memory cellsBlock base cpu represented
  obtain ⟨old, tag, oldRead, _, copyCast⟩ :=
    X86RegisterWriterInputs.cell addresses origins memory cellsBlock base cpu represented index
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 old = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  let selected := X86QwordWriterSelectors.temps le index
  let loaded := X86ShiftWriteback.loadTemps selected cellsBlock base stack
  let prepared := X86ShiftWriteback.writerWidthTemps loaded .q (0#8) value
  let initialized := X86ShiftWriteback.cellReadTemps prepared cellsBlock base old
  let tagged := X86ShiftWriteback.tagTemps initialized index cellsBlock base (0#8)
  let reached := X86ShiftWriteback.classTemps tagged .q
  have selectedBinding : selected.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) :=
    (X86QwordWriterSelectors.get le index _ (by decide +kernel)).trans binding
  have selectedDst : selected.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) :=
    (X86QwordWriterSelectors.get le index _ (by decide +kernel)).trans destination
  have selectedWidth : selected.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument .q) :=
    (X86QwordWriterSelectors.get le index _ (by decide +kernel)).trans width
  have selectedShift : selected.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)) :=
    (X86QwordWriterSelectors.get le index _ (by decide +kernel)).trans observedShift
  have selectedValue : selected.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value) :=
    (X86QwordWriterSelectors.get le index _ (by decide +kernel)).trans observedValue
  have selectorsRun := X86QwordWriterSelectors.execute ge layout function e le k memory index code ordinary
    bindingBlock cellsBlock tagHelper base destination width observedShift sourceShift alu scalarCode
    binding tagBinding tagUnshadowed cells scalarTag
  have loadedRun := X86ShiftWriteback.load_prefix ge layout.bindings layout.gpr layout.cell
    function e selected k memory bindingBlock cellsBlock base stack selectedBinding cells stackRead stackCast
  have widthRun := X86ShiftWriteback.width_internal ge widthBlock widthBinding function e loaded unshadowed
    .q (0#8) value (X86ShiftWriteback.loadCont k) memory
    (by simp +decide [loaded, X86ShiftWriteback.loadTemps, CC.PTree.gso, selectedWidth])
    (by simp +decide [loaded, X86ShiftWriteback.loadTemps, CC.PTree.gso, selectedShift])
    (by simp +decide [loaded, X86ShiftWriteback.loadTemps, CC.PTree.gso, selectedValue])
  have preparedBinding : prepared.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [prepared, loaded, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerRawTemps, X86ShiftWriteback.writerEffectiveTemps,
      X86ShiftWriteback.loadTemps, CC.PTree.gso, selectedBinding]
  have preparedDst : prepared.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    simp +decide [prepared, loaded, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerRawTemps, X86ShiftWriteback.writerEffectiveTemps,
      X86ShiftWriteback.loadTemps, CC.PTree.gso, selectedDst]
  have copiedFrame : ∀ chunk other offset, other ≠ localBlock →
      CC.Mem.load chunk copied other offset = CC.Mem.load chunk memory other offset := by
    intro chunk other offset different
    exact CC.Mem.load_store_other copiedStore chunk other offset (.inl different)
  have initializedRun := X86ShiftWriteback.cell_initialized ge layout.bindings layout.gpr layout.cell
    function e prepared (X86ShiftWriteback.loadCont k) memory bindingBlock cellsBlock base index old
    preparedBinding cells oldRead copyCast preparedDst localBlock copied declared copiedStore
  have initializedBinding : initialized.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [initialized, X86ShiftWriteback.cellReadTemps, CC.PTree.gso, preparedBinding]
  have initializedDst : initialized.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    simp +decide [initialized, X86ShiftWriteback.cellReadTemps, CC.PTree.gso, preparedDst]
  have tagRun := X86ShiftWriteback.tag_internal ge layout.bindings layout.gpr layout.cell function e
    initialized (X86ShiftWriteback.loadCont k) copied bindingBlock cellsBlock base index (0#8)
    initializedBinding ((copiedFrame _ bindingBlock _ localSeparate.1).trans cells)
    ((copiedFrame _ cellsBlock _ localSeparate.2).trans scalarTag) initializedDst
  have taggedWidth : tagged.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .q) := by
    simp +decide [tagged, initialized, prepared, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, CC.PTree.gso]
  have dispatchRun := X86ShiftWriteback.width_dispatch ge function e tagged
    (X86ShiftWriteback.loadCont k) copied .q taggedWidth
  have entryRun := ((((selectorsRun.trans loadedRun).trans widthRun).trans initializedRun).trans tagRun).trans dispatchRun
  have reachedWidth : reached.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .q) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, CC.PTree.gso, taggedWidth]
  have reachedValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value) := by
    simp +decide [reached, tagged, initialized, prepared, X86ShiftWriteback.classTemps,
      X86ShiftWriteback.tagTemps, X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso]
  have reachedDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte index).setWidth 32)) := by
    simp +decide [reached, tagged, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps, CC.PTree.gso, initializedDst]
  have reachedBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, tagged, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps, CC.PTree.gso, initializedBinding]
  have copiedRegisters : RegistersRepresent addresses origins copied cellsBlock base cpu := by
    intro row
    obtain ⟨v, raw, t, vr, tr, rep, native⟩ := represented row
    exact ⟨v, raw, t, (copiedFrame _ cellsBlock _ localSeparate.2).trans vr,
      (copiedFrame _ cellsBlock _ localSeparate.2).trans tr, rep, native⟩
  obtain ⟨final, tailRun, native, access, next, kept⟩ :=
    X86FullWidthWriteback.from_storage ge layout function e reached k copied localBlock bindingBlock
      cellsBlock base index value false declared reachedWidth reachedValue reachedDestination ordinary
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

end KProgFormal.ClightRefinement.X86QwordWriteback
