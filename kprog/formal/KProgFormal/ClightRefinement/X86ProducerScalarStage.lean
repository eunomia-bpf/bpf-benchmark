import KProgFormal.ClightRefinement.X86ProducerScalarExecute

namespace KProgFormal.ClightRefinement.X86ProducerScalarStage
open X86ProducerScalarSource
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

abbrev Locals (before : CC.Mem) := (i : Fin 8) → SourceLocal ge.genv_cenv before (row i)

structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 8) (object : SourceLocal ge.genv_cenv before (row i)) (cache : SourceLocal ge.genv_cenv before 1) where
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  value : BitVec 64
  run : CC.Star (CC.Step2 ge)
    (.State producer (site i).whole k (allocation ge.genv_cenv before).1 le memory) trace
    (.State producer (site i).following k (allocation ge.genv_cenv before).1 output after)
  read : CC.Mem.load (chunk i) after object.block 0 = some (X86ProducerScalarValue.value i value)
  outside : ∀ c b ofs, b ≠ object.block → b ≠ cache.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock
  temporary : ∀ name, (site i).resultName ≠ name → output.get name = le.get name

/-- Actual outcome availability is the same explicit initial platform ABI.
Only protected typed loads, not raw byte contents, are framed across it. -/
theorem execute (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 8)
    (object : SourceLocal ge.genv_cenv before (row i)) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k i object cache) := by
  obtain ⟨actualCache, ⟨outcome⟩⟩ := inputs memory access frontier
  have same : actualCache.block = cache.block := by
    have binding := actualCache.binding.symm.trans cache.binding
    exact congrArg Prod.fst (Option.some.inj binding)
  obtain ⟨after, run, read, outside, frame, rights, next⟩ :=
    X86ProducerScalarExecute.execute before memory outcome.supplied le k i outcome.value outcome.trace object
      outcome.call (outcome.access.trans access)
  refine ⟨⟨after, X86ProducerScalarExecute.temps i le outcome.value, outcome.trace, outcome.value,
    run, read, ?_, rights.trans outcome.access, next.trans outcome.frontier, ?_⟩⟩
  · intro c b ofs notObject notCache
    exact (outside c b ofs notObject).trans (outcome.frame c b ofs (by simpa only [same] using notCache))
  · intro name different
    exact CC.PTree.gso _ _ _ _ different

end KProgFormal.ClightRefinement.X86ProducerScalarStage
