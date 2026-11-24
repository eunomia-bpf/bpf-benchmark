import KProgFormal.ClightRefinement.X86FullWidthRspWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs

namespace KProgFormal.ClightRefinement.X86DwordRspSetup
open X86RegisterView

/-- Actual source observations at the dword overwrite frontier. -/
structure Ready (le : CC.TempEnv) (binding : CC.Block) (value old : BitVec 64) : Prop where
  binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0)
  destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32))
  old : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old)
  width : le.get X86_program_profile_bpf.___x86_wr_width__2 = some (X86ShiftLeft.argument .d)
  value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value)

/-- Original dword selectors, saved-SP/cell reads, actual width helper,
local union copy, arbitrary initial tag read and width dispatch reach the
real overwrite frontier. No signed-SP comparison or release result is assumed. -/
theorem to_storage (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (base : CC.Integers.Ptrofs) (value old : BitVec 64) (shift : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)))
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
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (rspRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some (.Vlong old))
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true) :
    ∃ copied reached, InternalRun ge 129
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e reached copied) ∧
    CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong old) = some copied ∧
    RegistersRepresent addresses origins copied cellsBlock base cpu ∧ Ready reached bindingBlock value old := by
  obtain ⟨rawValue, tag, oldRead, tagRead, copyCast⟩ :=
    X86RegisterWriterInputs.cell addresses origins memory cellsBlock base cpu represented 4
  have rawEqual : rawValue = .Vlong old := Option.some.inj (oldRead.symm.trans rspRead)
  subst rawValue
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong old) = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  have entryRun := X86ShiftWriteback.narrow_storage ge layout.bindings layout.gpr layout.cell
    function e le k memory bindingBlock cellsBlock base (.Vlong old) binding cells rspRead (by rfl)
    (4 : Fin 16) .d (by decide) destination width alu widthBlock widthBinding unshadowed shift value
    observedShift observedValue (.Vlong old) oldRead copyCast localBlock copied declared copiedStore tag tagRead
    ⟨localSeparate.1, localSeparate.2⟩ scalarCode
  let reached := X86ShiftWriteback.classTemps
    (X86ShiftWriteback.tagTemps
      (X86ShiftWriteback.cellReadTemps
        (X86ShiftWriteback.writerWidthTemps
          (X86ShiftWriteback.loadTemps
            (X86ShiftWriteback.narrowSrcTemps (X86ShiftWriteback.narrowDstTemps
              (X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte 4) .d)))
            cellsBlock base (.Vlong old)) .d shift value) cellsBlock base (.Vlong old))
      (4 : Fin 16) cellsBlock base tag) .d
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
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)) := by
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
  have reachedOld : reached.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    simp +decide [reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, CC.PTree.gss, CC.PTree.gso]
  exact ⟨copied, reached, entryRun, copiedStore, copiedRegisters,
    reachedBinding, reachedDestination, reachedOld, reachedWidth, reachedValue⟩

end KProgFormal.ClightRefinement.X86DwordRspSetup
