import KProgFormal.ClightRefinement.Arm64ProducerAbiTables
import KProgFormal.ClightRefinement.Arm64ProgramEntryFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiFlags

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryFlags (declaration metadata vectorStart Readbacks)
open Arm64Producer (tableCellName tableCellType tableName tableType TableLocals TailLocal)

private def Protected (id : CC.Ident) : Prop :=
  (∀ i : Fin 4, id ≠ (declaration i).name) ∧ id ≠ Arm64Entry.___a64_lr

private theorem protection (id : CC.Ident)
    (flags : ∀ i : Fin 4, id ≠ (Arm64Producer.flagDeclaration i).name)
    (lr : id ≠ Arm64Entry.___a64_lr) : Protected id := by
  refine ⟨?_, lr⟩
  intro i
  rw [(metadata i).1]
  exact flags i

private theorem cells_protected : ∀ selected (i : Fin 31), Protected (tableCellName selected i) := by
  have different : ∀ selected (i : Fin 31),
      (∀ j : Fin 4, tableCellName selected i ≠ (Arm64Producer.flagDeclaration j).name) ∧
      tableCellName selected i ≠ Arm64Entry.___a64_lr := by decide +kernel
  exact fun selected i => protection _ (different selected i).1 (different selected i).2

private theorem tables_protected : ∀ selected, Protected (tableName selected) := by
  have different : ∀ selected,
      (∀ j : Fin 4, tableName selected ≠ (Arm64Producer.flagDeclaration j).name) ∧
      tableName selected ≠ Arm64Entry.___a64_lr := by decide +kernel
  exact fun selected => protection _ (different selected).1 (different selected).2

private theorem caches_protected : ∀ returns,
    Protected (Arm64Producer.baseName returns) ∧ Protected (Arm64Producer.validName returns) := by
  have different : ∀ returns,
      ((∀ j : Fin 4, Arm64Producer.baseName returns ≠ (Arm64Producer.flagDeclaration j).name) ∧
        Arm64Producer.baseName returns ≠ Arm64Entry.___a64_lr) ∧
      ((∀ j : Fin 4, Arm64Producer.validName returns ≠ (Arm64Producer.flagDeclaration j).name) ∧
        Arm64Producer.validName returns ≠ Arm64Entry.___a64_lr) := by decide +kernel
  exact fun returns => ⟨protection _ (different returns).1.1 (different returns).1.2,
    protection _ (different returns).2.1 (different returns).2.2⟩

/-- Actual entry through the four flag visits and LR zero. The 30 GPR
traces precede the four flag traces; all earlier storage observations survive. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 34 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile vectorStart
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (.Vlong (Arm64ProgramEntryGprInputs.wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock, tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i, tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Readbacks initial after flags ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) := by
  obtain ⟨blocks, before, le, registerTraces, registerLength, bindings, actualBindings,
      registerRun, registers, tables, caches, context, frame, access, next,abi⟩ :=
    Arm64ProducerAbiTables.entry_initialized initial ctx k kind values provider
  obtain ⟨flagBlocks, lrBlock, after, finalLe, flagTraces, flagLength, flagBindings,
      actualFlagBindings, lrBinding, actualLrBinding, flagRun, flagReads, lrRead,
      other, temps, flagFrame, flagAccess, flagNext⟩ :=
    Arm64ProgramEntryFlags.initialized initial before le k flags flagProvider access
  refine ⟨blocks, after, finalLe, registerTraces ++ flagTraces, ?_, bindings, actualBindings,
    ?_, ?_, ?_, ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, flagReads, lrRead⟩,
    ?_, ?_, frame.trans flagFrame, flagAccess.trans access, flagNext.trans next,?_⟩
  · simp only [List.length_append, registerLength, flagLength]
  · simpa only [List.flatten_append, CC.Eapp] using star_trans registerRun flagRun
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_protected false i).1 (cells_protected false i).2 .Mint64 0).trans
        (registers i).1,
      (other _ _ _ (bindings true i) (cells_protected true i).1 (cells_protected true i).2 .Mint8unsigned 0).trans
        (registers i).2⟩
  · intro selected
    obtain ⟨locals, bound, cells, reads⟩ := tables selected
    refine ⟨locals, bound, cells, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_protected selected).1 (tables_protected selected).2
      CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_protected returns).1.1
        (caches_protected returns).1.2 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_protected returns).2.1
        (caches_protected returns).2.2 .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => Ne.symm (metadata i).2.2.2.2)).trans context

  · have keptKind : Protected (Arm64Producer.tailLocalName 6) :=
      protection _ (by decide +kernel) (by decide +kernel)
    exact (other _ _ _ kind.binding keptKind.1 keptKind.2 .Mint8unsigned 0).trans abi

end KProgFormal.ClightRefinement.Arm64ProducerAbiFlags
