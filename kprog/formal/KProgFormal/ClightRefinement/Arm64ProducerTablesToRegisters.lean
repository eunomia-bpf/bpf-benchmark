import KProgFormal.ClightRefinement.Arm64ProducerFlagInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerTablesToRegisters

open Arm64Producer

/-- Actual x30-zero and table stores supply the data needed by the complete
flag/vector/RAW execution. Earlier x1..x29 words/tags remain source premises;
no initial table contents, x30 payload, or x0 data are assumed. -/
theorem tables_to_registers
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (access : before.access = (allocation m).2.access)
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 68 ∧
      CC.Star (CC.Step2 ge) (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨xb, _, middle, wordBinding, _, zeroRun, zeroWord, _, zeroLocals,
      zeroFrame, zeroAccess, zeroNext⟩ := register30_initialized m before le k access
  obtain ⟨ready, tableRun, tables, tableLocals, tableFrame, tableAccess, tableNext⟩ :=
    pointer_tables_initialized m middle (le.set (registerDeclaration 30).resultTemp (.Vlong 0)) k
      (zeroAccess.trans access)
  have cellNotTables : ∀ tags (i : Fin 31),
      tableCellName tags i ≠ tableName false ∧ tableCellName tags i ≠ tableName true := by decide +kernel
  have cellNotZero : ∀ tags (i : Fin 31), i ≠ 30 →
      tableCellName tags i ≠ (registerDeclaration 30).word ∧
      tableCellName tags i ≠ (registerDeclaration 30).tag := by decide +kernel
  have words : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 ready block 0 = some (.Vlong (if i = 30 then 0 else inputs i)) := by
    intro i nonzero block bound
    rw [tableLocals _ _ _ bound (cellNotTables false i).1 (cellNotTables false i).2 .Mint64 0]
    by_cases lr : i = 30
    · subst i
      have same : block = xb := congrArg Prod.fst (Option.some.inj (bound.symm.trans wordBinding))
      subst block
      exact zeroWord
    · rw [zeroLocals _ _ _ bound (cellNotZero false i lr).1 (cellNotZero false i lr).2 .Mint64 0]
      simpa [lr] using wordsBefore i nonzero lr block bound
  have tags : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned ready block 0 = some (.Vint 0) := by
    intro i nonzero nonlr block bound
    rw [tableLocals _ _ _ bound (cellNotTables true i).1 (cellNotTables true i).2 .Mint8unsigned 0]
    rw [zeroLocals _ _ _ bound (cellNotZero true i nonlr).1 (cellNotZero true i nonlr).2 .Mint8unsigned 0]
    exact tagsBefore i nonzero nonlr block bound
  have ctxSeparate : Arm64Entry._ctx ≠ (registerDeclaration 30).resultTemp := by decide +kernel
  have ctxInput : (le.set (registerDeclaration 30).resultTemp (.Vlong 0)).get Arm64Entry._ctx = some ctx :=
    (CC.PTree.gso _ _ _ _ (Ne.symm ctxSeparate)).trans input
  have prefixRun : InternalRun ge 196
      (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
      (.State producer afterPointerTables k (allocation m).1
        (le.set (registerDeclaration 30).resultTemp (.Vlong 0)) ready) := zeroRun.trans tableRun
  obtain ⟨entry, after, finalLe, traces, length, suffix, registers, suffixFrame, suffixAccess, suffixNext⟩ :=
    Arm64ProducerFlagInputs.flag_vector_inputs_and_raw_registers addresses origins ctx ctxWord represented
      m ready (le.set (registerDeclaration 30).resultTemp (.Vlong 0)) ctxInput k s inputs
      flagInputs flagProvider flagMatches vectorProvider (tableAccess.trans (zeroAccess.trans access))
      tables words tags nativeContext nativeReturn nativeOther nativeSp
  refine ⟨entry, after, finalLe, traces, length, ?_, registers,
    (zeroFrame.trans tableFrame).trans suffixFrame,
    suffixAccess.trans (tableAccess.trans zeroAccess), suffixNext.trans (tableNext.trans zeroNext)⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans prefixRun.sound suffix

end KProgFormal.ClightRefinement.Arm64ProducerTablesToRegisters
