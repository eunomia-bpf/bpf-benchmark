import KProgFormal.ClightRefinement.Arm64ProducerIsXdpGprInputs
import KProgFormal.ClightRefinement.Arm64ProgramEntryTables

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerIsXdpTables

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryTables (afterPointerTables)
open Arm64Producer (tableCellName tableCellType tableName tableType TableLocals TailLocal)

private theorem cells_separate : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ tableName false ∧ tableCellName tags i ≠ tableName true := by decide +kernel
private theorem caches_separate : ∀ returns,
    Arm64Producer.baseName returns ≠ tableName false ∧ Arm64Producer.baseName returns ≠ tableName true ∧
    Arm64Producer.validName returns ≠ tableName false ∧ Arm64Producer.validName returns ≠ tableName true := by decide +kernel
private theorem abi_separate :
    Arm64Producer.tailLocalName 6 ≠ tableName false ∧ Arm64Producer.tailLocalName 6 ≠ tableName true := by decide +kernel

/-- Execute both original31-cell pointer tables after the same30 provider
outcomes, retaining every actual register/cache read and the ABI initializer. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6) (cell : TailLocal initial 5) (values : Fin 31 → BitVec 64)
    (provider : Arm64ProducerGprInputs.ProviderAt world initial values) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterPointerTables
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (.Vlong (Arm64ProgramEntryGprInputs.wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock,tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i,tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
      CC.Mem.load .Mint8unsigned after cell.block 0 = some (.Vint 0) := by
  obtain ⟨blocks,middle,le,traces,length,bindings,actualBindings,registerRun,
      registers,caches,context,frame,access,next,abi,isXdp⟩ :=
    Arm64ProducerIsXdpGprInputs.entry_initialized initial ctx k kind cell values provider
  obtain ⟨after,tableRun,tables,other,tableFrame,tableAccess,tableNext⟩ :=
    Arm64ProgramEntryTables.initialized initial middle le k access
  refine ⟨blocks,after,le,traces,length,bindings,actualBindings,?_,?_,?_,?_,context,
    frame.trans tableFrame,tableAccess.trans access,tableNext.trans next,?_,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans registerRun tableRun.sound
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_separate false i).1 (cells_separate false i).2 .Mint64 0).trans
        (registers i).1,
      (other _ _ _ (bindings true i) (cells_separate true i).1 (cells_separate true i).2 .Mint8unsigned 0).trans
        (registers i).2⟩
  · intro selected
    obtain ⟨locals,bound,cells,reads⟩ := tables selected
    refine ⟨locals,bound,cells,?_⟩
    intro i
    have same : locals.cellBlock i = blocks selected i :=
      congrArg Prod.fst (Option.some.inj ((locals.cellBinding i).symm.trans (bindings selected i)))
    simpa only [same] using reads i
  · intro returns
    obtain ⟨locals,baseBound,validBound,base,valid⟩ := caches returns
    refine ⟨locals,baseBound,validBound,?_,?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_separate returns).1
        (caches_separate returns).2.1 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_separate returns).2.2.1
        (caches_separate returns).2.2.2 .Mint8unsigned 0).trans valid
  · exact (other _ _ _ kind.binding abi_separate.1 abi_separate.2 .Mint8unsigned 0).trans abi

  · have separate : Arm64Producer.tailLocalName 5 ≠ tableName false ∧
        Arm64Producer.tailLocalName 5 ≠ tableName true := by decide +kernel
    exact (other _ _ _ cell.binding separate.1 separate.2 .Mint8unsigned 0).trans isXdp

end KProgFormal.ClightRefinement.Arm64ProducerIsXdpTables
