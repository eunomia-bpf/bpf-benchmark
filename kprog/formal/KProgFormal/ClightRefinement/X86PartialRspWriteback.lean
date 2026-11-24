import KProgFormal.ClightRefinement.X86RegisterWriteRspPartialWriteback
import KProgFormal.ClightRefinement.X86RegisterWriterInputs

namespace KProgFormal.ClightRefinement.X86PartialRspWriteback
open X86RegisterView

/-- The actual scalar/tag0 RSP byte/word writer, including its initial selectors,
old-SP/cell reads, width helper, copied local, partial stores, reverse/table
writes and non-increasing release. All intermediate observations follow
from the original inputs, source execution and register relation. -/
theorem execute (isWord : Bool) (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (localBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (base baseOffset : CC.Integers.Ptrofs) (value old : BitVec 64) (shift : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument (if isWord then .w else .b)))
    (code : BitVec 32)
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (low : isWord = false → shift = 0)
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (localSeparate : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock ∧ baseBlock ≠ localBlock)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (represented : RegistersRepresent addresses origins memory cellsBlock base cpu)
    (rspRead : CC.Mem.load CC.Mptr memory cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + 64)) = some (.Vlong old))
    (scalar : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + 64) + 8)) = some (.Vint (0#32)))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (nativeBase : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack))
    (nonIncreasing : CC.Integers.Int64.cmp .Cgt
      (X86.Value.writeView (if isWord then .w else .b) (old + origins.stack) value - origins.stack) old = false)
    (localPermission : CC.Mem.validAccess memory CC.Mptr localBlock 0 .Writable = true)
    (wordPermission : CC.Mem.validAccess memory CC.Mptr cellsBlock
      (CC.Integers.Ptrofs.unsigned (base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int)))) .Writable = true)
    (tagPermission : CC.Mem.validAccess memory .Mint8unsigned cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * ((4 : Fin 16).val : Int))) + 8))
      .Writable = true) :
    ∃ final finalTemps, InternalRun ge (if isWord then 216 else 204)
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) ∧
      RegistersRepresent addresses origins final cellsBlock base
        (cpu.setReg (if isWord then .w else .b) (X86.GPR.ofIndex 4) value) ∧
      final.access = memory.access ∧ final.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ localBlock → other ≠ cellsBlock →
        CC.Mem.load chunk final other offset = CC.Mem.load chunk memory other offset) := by
  have copyExists : ∃ copied, CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong old) = some copied := by
    simp only [CC.Mem.store, localPermission, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨copied, copiedStore⟩ := copyExists
  have entered := X86ShiftWriteback.narrow_storage ge layout.bindings layout.gpr layout.cell
    function e le k memory bindingBlock cellsBlock base (.Vlong old) binding cells rspRead (by rfl)
    (4 : Fin 16) (if isWord then .w else .b) (by cases isWord <;> decide) destination width alu widthBlock widthBinding unshadowed shift value
    observedShift observedValue (.Vlong old) rspRead (by rfl) localBlock copied declared copiedStore (0#8) scalar
    ⟨localSeparate.1, localSeparate.2.1⟩ scalarCode
  let reached := X86ShiftWriteback.classTemps
    (X86ShiftWriteback.tagTemps
      (X86ShiftWriteback.cellReadTemps
        (X86ShiftWriteback.writerWidthTemps
          (X86ShiftWriteback.loadTemps
            (X86ShiftWriteback.narrowSrcTemps (X86ShiftWriteback.narrowDstTemps
              (X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte 4) (if isWord then .w else .b))))
            cellsBlock base (.Vlong old)) (if isWord then .w else .b) shift value) cellsBlock base (.Vlong old))
      (4 : Fin 16) cellsBlock base (0#8)) (if isWord then .w else .b)
  let selected := if isWord then X86WordStorage.selectionTemps reached else reached
  have selectedRun : InternalRun ge (if isWord then 9 else 0)
      (.State function (X86ShiftWriteback.storageArm (if isWord then .w else .b))
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e reached copied)
      (.State function (X86RegisterWriteRspPartial.leaf isWord)
        (.Kseq X86ShiftWriteback.storageTail (X86ShiftWriteback.loadCont k)) e selected copied) := by
    cases isWord with
    | false => exact .refl _
    | true =>
      apply X86WordStorage.select
      simp +decide [selected, X86WordStorage.selectionTemps, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
        X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
        X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
        X86ShiftWriteback.writerEffectiveTemps, CC.PTree.gso]
  have entryRun := entered.trans selectedRun
  have reachedValue : selected.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong value) := by
    cases isWord <;> simp +decide [selected, X86WordStorage.selectionTemps, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso]
  have reachedDestination : selected.get X86_program_profile_bpf._dst =
      some (.Vint ((X86RegisterReadValue.registerByte 4).setWidth 32)) := by
    cases isWord <;> simp +decide [selected, X86WordStorage.selectionTemps, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, X86ShiftWriteback.narrowSrcTemps,
      X86ShiftWriteback.narrowDstTemps, X86ShiftWriteback.selectTemps, CC.PTree.gso, destination]
  have reachedBinding : selected.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    cases isWord <;> simp +decide [selected, X86WordStorage.selectionTemps, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
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
    exact ⟨v, raw, t, (copiedFrame _ cellsBlock _ localSeparate.2.1).trans vr,
      (copiedFrame _ cellsBlock _ localSeparate.2.1).trans tr, rep, native⟩
  have reachedOld : selected.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old) := by
    cases isWord <;> simp +decide [selected, X86WordStorage.selectionTemps, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps,
      X86ShiftWriteback.writerEffectiveTemps, X86ShiftWriteback.writerRawTemps,
      X86ShiftWriteback.loadTemps, CC.PTree.gss, CC.PTree.gso]
  have reachedTag : selected.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)) := by
    cases isWord <;> simp +decide [selected, X86WordStorage.selectionTemps, reached,
      X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps, X86ShiftWriteback.tagReadTemps,
      X86ShiftWriteback.tagRegTemps, CC.PTree.gso]
  have reachedShift : isWord = false → selected.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32)) := by
    intro byte
    have zero := low byte
    subst isWord
    simp +decide [selected, reached, X86ShiftWriteback.classTemps, X86ShiftWriteback.tagTemps,
      X86ShiftWriteback.tagReadTemps, X86ShiftWriteback.tagRegTemps,
      X86ShiftWriteback.cellReadTemps, X86ShiftWriteback.writerWidthTemps, CC.PTree.gso, zero]
  obtain ⟨final, finalTemps, tailRun, native, access, next, kept⟩ :=
    X86RegisterWriteRspPartialWriteback.from_leaf isWord ge layout valueLayout function e selected k copied
      localBlock bindingBlock cellsBlock baseBlock base baseOffset old value declared reachedBinding
      (by simpa only [show (X86RegisterReadValue.registerByte 4).setWidth 32 = (4#32) from rfl] using reachedDestination)
      (CC.Mem.load_store_same copiedStore) reachedTag reachedValue reachedShift reachedOld
      ((copiedFrame _ bindingBlock _ localSeparate.1).trans cells)
      ((copiedFrame _ cellsBlock _ localSeparate.2.1).trans rspRead)
      ((copiedFrame _ bindingBlock _ localSeparate.1).trans header) bindingSeparate localSeparate addresses origins
      ((copiedFrame _ baseBlock _ localSeparate.2.2).trans nativeBase) cpu copiedRegisters nonIncreasing
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans localPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans wordPermission)
      ((CC.Mem.validAccess_store_eq copiedStore _ _ _ .Writable).trans tagPermission)
  have run : InternalRun ge (if isWord then 216 else 204)
      (.State function X86ShiftWriteback.writer k e le memory)
      (.State function .Sskip k e finalTemps final) := by
    have composed := entryRun.trans tailRun
    cases isWord <;> simpa only [X86ShiftWriteback.classifyLength, Bool.false_eq_true,
      ite_false, ite_true, Nat.reduceAdd] using composed
  refine ⟨final, _, run, native,
    access.trans (CC.Mem.store_access copiedStore),
    next.trans (CC.Mem.store_nextblock copiedStore), ?_⟩
  intro chunk other offset notLocal notCells
  exact (kept chunk other offset notLocal notCells).trans (copiedFrame chunk other offset notLocal)


end KProgFormal.ClightRefinement.X86PartialRspWriteback
