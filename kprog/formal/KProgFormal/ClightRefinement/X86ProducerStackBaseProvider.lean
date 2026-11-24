import KProgFormal.ClightRefinement.X86ProducerStackBaseReturn

namespace KProgFormal.ClightRefinement.X86ProducerStackBaseProvider
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

/-- The actual kind1 outcome has its own explicit ABI. The kind6 outcome
contract is not substituted, and determinacy/trace length do not imply it. -/
structure Outcome (cache : CC.Block) (memory : CC.Mem) where
  value : BitVec 64
  trace : CC.Trace
  supplied : CC.Mem
  call : CC.externalCall X86RegisterWriteRspReleaseWord.inputEF (CC.Genv.toSenv ge.genv_genv)
    [.Vint (1#32)] memory trace (.Vlong value) supplied
  access : supplied.access = memory.access
  frontier : supplied.nextblock = memory.nextblock
  frame : X86ReleaseProvider.Frame cache memory supplied

/-- Explicit initial kind1 platform availability at the actual producer's
permissions/frontier. It is an open ABI premise, not a new logical axiom. -/
def Inputs (before : CC.Mem) : Prop := ∀ memory,
  memory.access = (allocation ge.genv_cenv before).2.access →
  memory.nextblock = (allocation ge.genv_cenv before).2.nextblock →
  ∃ cache : SourceLocal ge.genv_cenv before 1, Nonempty (Outcome cache.block memory)

structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (base : SourceLocal ge.genv_cenv before 14) (cache : SourceLocal ge.genv_cenv before 1) where
  outcome : Outcome cache.block memory
  after : CC.Mem
  run : CC.Star (CC.Step2 ge)
    (.Callstate X86RegisterWriteRspReleaseWord.inputFunction [.Vint (1#32)]
      (X86ProducerStackBaseSource.continuation (allocation ge.genv_cenv before).1 le k) memory) outcome.trace
    (.State producer X86ProducerStackBaseSource.finalSetup k (allocation ge.genv_cenv before).1
      (X86ProducerStackBaseReturn.temps le outcome.value) after)
  stored : CC.Mem.store .Mint64 outcome.supplied base.block 0 (.Vlong outcome.value) = some after
  read : CC.Mem.load .Mint64 after base.block 0 = some (.Vlong outcome.value)
  outside : ∀ c b ofs, b ≠ base.block → b ≠ cache.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  post_frame : FrameBelow before.nextblock outcome.supplied after
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock

/-- Actual source binding identifies the same cache, and the real kind1
outcome/return/base store preserves protected typed observations. The raw
frame starts at the complete supplied heap, not before the provider. -/
theorem execute (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (base : SourceLocal ge.genv_cenv before 14) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k base cache) := by
  obtain ⟨actualCache, ⟨outcome⟩⟩ := inputs memory access frontier
  have same : actualCache.block = cache.block := by
    have binding := actualCache.binding.symm.trans cache.binding
    exact congrArg Prod.fst (Option.some.inj binding)
  let actual : Outcome cache.block memory :=
    { value := outcome.value, trace := outcome.trace, supplied := outcome.supplied,
      call := outcome.call, access := outcome.access, frontier := outcome.frontier,
      frame := by
        intro c b ofs different
        exact outcome.frame c b ofs (by simpa only [same] using different) }
  obtain ⟨after, run, stored, read, outside, postFrame, rights, next⟩ :=
    X86ProducerStackBaseReturn.execute before memory actual.supplied le k actual.value actual.trace base
      actual.call (actual.access.trans access)
  refine ⟨⟨actual, after, run, stored, read, ?_, postFrame, rights.trans actual.access, next.trans actual.frontier⟩⟩
  intro c b ofs notBase notCache
  exact (outside c b ofs notBase).trans (actual.frame c b ofs notCache)

end KProgFormal.ClightRefinement.X86ProducerStackBaseProvider
