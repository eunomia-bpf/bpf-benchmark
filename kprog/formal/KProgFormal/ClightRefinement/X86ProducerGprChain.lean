import KProgFormal.ClightRefinement.X86ProducerGprStage

namespace KProgFormal.ClightRefinement.X86ProducerGprChain
open X86ProducerGprSites
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def following : CC.Stmt := (site 15).following
def cursor (count : Nat) : CC.Stmt := if h : count < 16 then (site ⟨count, h⟩).whole else following

theorem cursor_at (i : Fin 16) : cursor i.val = (site i).whole := by simp only [cursor, dite_eq_left i.isLt]

/-- Definitional identities in the original exported AST connect each value/tag
pair to the next original pair, and the last pair to its real successor. -/
theorem cursor_next (i : Fin 16) : cursor (i.val + 1) = (site i).following := by
  have cases : ∀ i : Fin 16, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 := by decide +kernel
  rcases cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

private theorem rows : ∀ i : Fin 16,
    X86ProducerGprStore.chunk (valueRow i) = CC.Mptr ∧
    X86ProducerGprStore.offset (valueRow i) = 16 * (i.val : Int) ∧
    X86ProducerGprStore.chunk (tagRow i) = .Mint8unsigned ∧
    X86ProducerGprStore.offset (tagRow i) = 16 * (i.val : Int) + 8 := by decide +kernel

private theorem separate : ∀ i j : Fin 16, i ≠ j →
    valueRow i ≠ valueRow j ∧ valueRow i ≠ tagRow j ∧
    tagRow i ≠ valueRow j ∧ tagRow i ≠ tagRow j := by decide +kernel

/-- A prefix of the SAME sixteen original sites. Values record actual external
outcomes, with the actual RSP zero. Protected observations are typed loads,
not arbitrary raw-byte equalities across the provider. -/
structure Result (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (cache : SourceLocal ge.genv_cenv before 1) (count : Nat) where
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  values : Fin 16 → BitVec 64
  run : CC.Star (CC.Step2 ge)
    (.State producer (cursor 0) k (allocation ge.genv_cenv before).1 le memory) trace
    (.State producer (cursor count) k (allocation ge.genv_cenv before).1 output after)
  reads : ∀ i : Fin 16, i.val < count →
    CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong (values i)) ∧
    CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)
  rsp : 4 < count → values 4 = 0
  outside : ∀ c b ofs, b ≠ gprs.block → b ≠ cache.block →
    CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs
  access : after.access = memory.access
  frontier : after.nextblock = memory.nextblock
  temporary : ∀ name, (∀ i : Fin 16, (site i).savedName ≠ name ∧ (site i).resultName ≠ name) →
    output.get name = le.get name

/-- Execute the original sites in order, keeping each accepted source step.
The provider availability/permission ABI is explicit; all prior initialized
rows survive each actual provider frame and subsequent real stores. -/
theorem initialized_prefix (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock)
    (count : Nat) (bound : count ≤ 16) : Nonempty (Result before memory le k gprs cache count) := by
  induction count with
  | zero =>
    refine ⟨⟨memory, le, CC.E0, fun _ => 0, .refl _, ?_, ?_, ?_, rfl, rfl, ?_⟩⟩
    · intro i impossible; omega
    · intro impossible; omega
    · intro c b ofs _ _; rfl
    · intro name _; rfl
  | succ count ih =>
    obtain ⟨prior⟩ := ih (by omega)
    let i : Fin 16 := ⟨count, by omega⟩
    obtain ⟨step⟩ := X86ProducerGprStage.execute before prior.after prior.output k gprs cache i inputs
      (prior.access.trans access) (prior.frontier.trans frontier)
    have run : CC.Star (CC.Step2 ge)
        (.State producer (cursor count) k (allocation ge.genv_cenv before).1 prior.output prior.after) step.trace
        (.State producer (cursor (count + 1)) k (allocation ge.genv_cenv before).1 step.output step.after) := by
      simpa only [show count = i.val from rfl, cursor_at, cursor_next] using step.run
    refine ⟨⟨step.after, step.output, CC.Eapp prior.trace step.trace,
      fun j => if j = i then step.value else prior.values j,
      star_trans prior.run run, ?_, ?_, ?_, step.access.trans prior.access,
      step.frontier.trans prior.frontier, ?_⟩⟩
    · intro j previous
      by_cases equal : j = i
      · subst j
        simpa only [ite_true] using And.intro step.pointer step.tag
      · have earlier : j.val < count := by
          have different : j.val ≠ i.val := fun eq => equal (Fin.ext eq)
          change j.val ≠ count at different
          omega
        have old := prior.reads j earlier
        have distinct := separate j i equal
        have pointer := step.others (valueRow j) distinct.1 distinct.2.1
        have tag := step.others (tagRow j) distinct.2.2.1 distinct.2.2.2
        simp only [(rows j).1, (rows j).2.1] at pointer
        simp only [(rows j).2.2.1, (rows j).2.2.2] at tag
        exact ⟨by simpa only [equal, ite_false] using pointer.trans old.1, tag.trans old.2⟩
    · intro previous
      by_cases equal : (4 : Fin 16) = i
      · simpa only [equal, ite_true] using step.rsp equal.symm
      · have earlier : 4 < count := by
          have different : (4 : Nat) ≠ count := fun eq => equal (Fin.ext eq)
          omega
        simpa only [equal, ite_false] using prior.rsp earlier
    · intro c b ofs notGpr notCache
      exact (step.outside c b ofs notGpr notCache).trans (prior.outside c b ofs notGpr notCache)
    · intro name untouched
      exact (step.temporary name (untouched i).1 (untouched i).2).trans (prior.temporary name untouched)

/-- All sixteen actual sites execute in their original order. -/
theorem complete (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (gprs : SourceLocal ge.genv_cenv before 0) (cache : SourceLocal ge.genv_cenv before 1)
    (inputs : X86ProducerRaxPrefix.Inputs before)
    (access : memory.access = (allocation ge.genv_cenv before).2.access)
    (frontier : memory.nextblock = (allocation ge.genv_cenv before).2.nextblock) :
    Nonempty (Result before memory le k gprs cache 16) :=
  initialized_prefix before memory le k gprs cache inputs access frontier 16 (by omega)

end KProgFormal.ClightRefinement.X86ProducerGprChain
