import KProgFormal.ClightRefinement.X86ProducerScalarChain

namespace KProgFormal.ClightRefinement.X86ProducerScalarInitialize
open X86ProducerScalarSource
open X86ProducerScalarStage (Locals)
open X86ProducerHeaderSource (producer localName)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def Outside {before : CC.Mem} (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1)
    (base : SourceLocal ge.genv_cenv before 14) (b : CC.Block) : Prop :=
  b ≠ base.block ∧ X86ProducerScalarChain.Outside objects cache b

structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1) (base : SourceLocal ge.genv_cenv before 14) where
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  values : Fin 8 → BitVec 64
  run : CC.Star (CC.Step2 ge)
    (.State producer X86ProducerGprChain.following k (allocation ge.genv_cenv before).1 le memory) trace
    (.State producer following k (allocation ge.genv_cenv before).1 output after)
  reads : ∀ i : Fin 8, CC.Mem.load (chunk i) after (objects i).block 0 = some (X86ProducerScalarValue.value i (values i))
  base_zero : CC.Mem.load .Mint64 after base.block 0 = some (.Vlong 0)
  outside : ∀ c b ofs, Outside objects cache base b → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock
  temporary : ∀ name, (∀ i : Fin 8, (site i).resultName ≠ name) → output.get name = le.get name

/-- The real base-zero assignment and all eight actual input/store sites
compose at the original post-GPR boundary. Existing provider ABI is explicit;
all external effects are represented by genuine source execution and traces. -/
theorem initialized (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1) (base : SourceLocal ge.genv_cenv before 14)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k objects cache base) := by
  obtain ⟨middle, firstRun, stored, baseRead, firstOutside, frame, firstAccess, firstNext⟩ :=
    X86ProducerScalarExecute.initial_zero before memory le k base access
  obtain ⟨second⟩ := X86ProducerScalarChain.complete before middle le k objects cache inputs
    (firstAccess.trans access) (firstNext.trans frontier)
  have secondRun : CC.Star (CC.Step2 ge)
      (.State producer start k (allocation ge.genv_cenv before).1 le middle) second.trace
      (.State producer following k (allocation ge.genv_cenv before).1 second.output second.after) := second.run
  have names : (localName (14 : Fin 24) ≠ localName (1 : Fin 24)) ∧
      (∀ i : Fin 8, localName (14 : Fin 24) ≠ localName (row i)) := by decide +kernel
  have baseOutside : X86ProducerScalarChain.Outside objects cache base.block :=
    ⟨X86ProducerGprStage.local_separate before base cache names.1,
      fun i => X86ProducerGprStage.local_separate before base (objects i) (names.2 i)⟩
  refine ⟨⟨second.after, second.output, second.trace, second.values, ?_,
    fun i => second.reads i i.isLt, (second.outside _ _ _ baseOutside).trans baseRead,
    ?_, second.access.trans firstAccess, second.frontier.trans firstNext, second.temporary⟩⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans firstRun.sound secondRun
  · intro c b ofs outside
    exact (second.outside c b ofs outside.2).trans (firstOutside c b ofs outside.1)

end KProgFormal.ClightRefinement.X86ProducerScalarInitialize
