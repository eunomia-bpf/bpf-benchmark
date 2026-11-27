import KProgFormal.ClightRefinement.Arm64CiliumCallerInitializers
namespace KProgFormal.ClightRefinement
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerTables
open Arm64CiliumCallerInitializers
example {m before : CC.Mem} (words : Table false m) (tags : Table true m)
    (wordCells : Cells false m) (tagCells : Cells true m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 186
        (.State procedure start k (allocation m).1 le before)
        (.State procedure afterTables k (allocation m).1 le after) ∧
      (∀ i,CC.Mem.load .Mint64 after words.block (8*(i.val : Int)) =
        some (.Vptr (wordCells.block i) 0)) ∧
      (∀ i,CC.Mem.load .Mint64 after tags.block (8*(i.val : Int)) =
        some (.Vptr (tagCells.block i) 0)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized false m after words (lastCell false wordCells)) ∧
      Nonempty (Arm64CiliumCallerTableWrites.Initialized true m after tags (lastCell true tagCells)) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  exact Arm64CiliumCallerInitializers.execute words tags wordCells tagCells access le k
end KProgFormal.ClightRefinement
