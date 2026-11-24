import KProgFormal.ClightRefinement.X86ProducerScalarStage

namespace KProgFormal.ClightRefinement.X86ProducerScalarChain
open X86ProducerScalarSource
open X86ProducerScalarStage (Locals)
open X86ProducerHeaderSource (producer localName)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def Outside {before : CC.Mem} (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1) (b : CC.Block) : Prop :=
  b ≠ cache.block ∧ ∀ i, b ≠ (objects i).block

private theorem names : (∀ i j : Fin 8, i ≠ j → localName (row i) ≠ localName (row j)) ∧
    (∀ i : Fin 8, localName (row i) ≠ localName (1 : Fin 24)) := by decide +kernel

structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1) (count : Nat) where
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  values : Fin 8 → BitVec 64
  run : CC.Star (CC.Step2 ge)
    (.State producer (cursor 0) k (allocation ge.genv_cenv before).1 le memory) trace
    (.State producer (cursor count) k (allocation ge.genv_cenv before).1 output after)
  reads : ∀ i : Fin 8, i.val < count →
    CC.Mem.load (chunk i) after (objects i).block 0 = some (X86ProducerScalarValue.value i (values i))
  outside : ∀ c b ofs, Outside objects cache b → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock
  temporary : ∀ name, (∀ i : Fin 8, (site i).resultName ≠ name) → output.get name = le.get name

/-- Every genuine scalar provider/store site executes in original source order.
All previously constructed flag/XMM readbacks survive actual subsequent
provider frames and stores, with actual concatenated traces and values. -/
theorem initialized_prefix (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock)
    (count : Nat) (bound : count ≤ 8) : Nonempty (Result before memory le k objects cache count) := by
  induction count with
  | zero =>
    refine ⟨⟨memory, le, CC.E0, fun _ => 0, .refl _, ?_, ?_, rfl, rfl, ?_⟩⟩
    · intro i impossible; omega
    · intro c b ofs _; rfl
    · intro name _; rfl
  | succ count ih =>
    obtain ⟨prior⟩ := ih (by omega)
    let i : Fin 8 := ⟨count, by omega⟩
    obtain ⟨step⟩ := X86ProducerScalarStage.execute before prior.after prior.output k i (objects i) cache inputs
      (prior.access.trans access) (prior.frontier.trans frontier)
    have run : CC.Star (CC.Step2 ge)
        (.State producer (cursor count) k (allocation ge.genv_cenv before).1 prior.output prior.after) step.trace
        (.State producer (cursor (count + 1)) k (allocation ge.genv_cenv before).1 step.output step.after) := by
      simpa only [show count = i.val from rfl, cursor_at, cursor_next] using step.run
    refine ⟨⟨step.after, step.output, CC.Eapp prior.trace step.trace,
      fun j => if j = i then step.value else prior.values j, star_trans prior.run run,
      ?_, ?_, step.access.trans prior.access, step.frontier.trans prior.frontier, ?_⟩⟩
    · intro j previous
      by_cases equal : j = i
      · subst j
        simpa only [ite_true] using step.read
      · have earlier : j.val < count := by
          have different : j.val ≠ i.val := fun eq => equal (Fin.ext eq)
          change j.val ≠ count at different
          omega
        have notCurrent := X86ProducerGprStage.local_separate before (objects j) (objects i) (names.1 j i equal)
        have notCache := X86ProducerGprStage.local_separate before (objects j) cache (names.2 j)
        have preserved := (step.outside (chunk j) (objects j).block 0 notCurrent notCache).trans (prior.reads j earlier)
        simpa only [equal, ite_false] using preserved
    · intro c b ofs outside
      exact (step.outside c b ofs (outside.2 i) outside.1).trans (prior.outside c b ofs outside)
    · intro name untouched
      exact (step.temporary name (untouched i)).trans (prior.temporary name untouched)

/-- All six flags and both XMM halves are initialized by actual source calls. -/
theorem complete (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (objects : Locals before) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k objects cache 8) :=
  initialized_prefix before memory le k objects cache inputs access frontier 8 (by omega)

end KProgFormal.ClightRefinement.X86ProducerScalarChain
