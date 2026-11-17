import KProgFormal.ClightRefinement.Arm64ProducerGprView
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerGprView.Inspection
open Arm64Producer

-- The header and producer table declarations share the actual ABI.
example : headerSourceName 0 = tableName false ∧ headerSourceName 1 = tableName true ∧
    headerSourceType 0 = tableType false ∧ headerSourceType 1 = tableType true ∧
    CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) = 8 ∧
    CC.sizeof ge.genv_cenv (tableType false) = 248 ∧ CC.sizeof ge.genv_cenv (tableType true) = 248 := by
  decide +kernel

-- Consumer slot arithmetic matches every real producer index, including30.
example : ∀ i : Fin 31, tableOffset i = CC.Integers.Ptrofs.repr (8 * (i.val : Int)) ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = 8 * (i.val : Int) := by
  decide +kernel

-- The last source cell is actually zero-initialized. This is a C source fact,
-- not an assumption that it represents an architectural LR value.
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    let d := registerDeclaration 30
    ∃ word tag after,
      (allocation m).1.get d.word = some (word, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation m).1.get d.tag = some (tag, CC.tuchar) ∧
      InternalRun Binding.ge 196 (.State producer (registerDeclarationStage 30) k (allocation m).1 le before)
        (.State producer afterPointerTables k (allocation m).1 (le.set d.resultTemp (.Vlong 0)) after) ∧
      CC.Mem.loadv .Mint64 after (.Vptr word 0) = some (.Vlong 0) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr tag 0) = some (.Vint 0) := by
  obtain ⟨word, tag, after, wordBinding, tagBinding, run, wordRead, tagRead, _⟩ :=
    register30_and_pointer_tables m before le k access
  exact ⟨word, tag, after, wordBinding, tagBinding, run, wordRead, tagRead⟩

-- All 31 readbacks inhabit the actual linked execution world and reached
-- memory frontier; source tables/data remain explicit premises.
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 31 → CC.Val) (kinds : Fin 31 → BitVec 8)
    (access : before.access = (allocation m).2.access)
    (tables : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (words : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (values i))
    (tags : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint ((kinds i).setWidth 32))) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun Binding.ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
        some (values i, .Vint ((kinds i).setWidth 32))) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock :=
  producer_gprs_initialized m before le k values kinds access tables words tags
end KProgFormal.ClightRefinement.Arm64ProducerGprView.Inspection
