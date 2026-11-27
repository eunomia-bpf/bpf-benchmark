import KProgFormal.ClightRefinement.Arm64CiliumCallerWriterPrefix
namespace KProgFormal.ClightRefinement
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation token)
open Arm64CiliumCallerWriterPrefix
example {m after : CC.Mem} (lr : Arm64CiliumCallerLink.LRLocal m)
    (stored : CC.Mem.store .Mint64 (allocation m).2 lr.block 0 (.Vlong token) = some after)
    (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 12
      (.State procedure Arm64CiliumCallerWriter.rest k (allocation m).1 le after)
      (.State procedure guard k (allocation m).1 (temps le) after) := Arm64CiliumCallerWriterPrefix.execute lr stored le k
example (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : Arm64CiliumCallerLink.LRLocal m, ∃ after block value,
      InternalRun ge 20
        (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le (allocation m).2)
        (.State procedure guard
          (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
          (allocation m).1 (temps (le.set ___a64_write_old_sp value)) after) ∧
      CC.Mem.store .Mint64 (allocation m).2 lr.block 0 (.Vlong token) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint64 after block 0 = some value ∧
      FrameBelow m.nextblock (allocation m).2 after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := Arm64CiliumCallerWriterPrefix.begin_allocated m le k
end KProgFormal.ClightRefinement
