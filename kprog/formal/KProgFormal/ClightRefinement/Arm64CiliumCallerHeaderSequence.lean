import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header Sources stage rest row)
open Arm64CiliumCallerGPRFrames (localRead)

def Initialized {m : CC.Mem} (header : Header m) (sources : Sources m)
    (heap : CC.Mem) (count : Nat) : Prop :=
  ∀ i : Fin 12,i.val < count →
    CC.Mem.load .Mint64 heap header.block (8*(i.val : Int)) = some (.Vptr (sources.block i) 0)

theorem shape : ∀ i : Fin 12,stage i = .Ssequence (row i) (rest i) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem chain : ∀ i : Fin 11,rest ⟨i.val,by omega⟩ = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem stored_prefix {m before : CC.Mem} {header : Header m} {sources : Sources m} {i : Fin 12}
    (writes : Arm64CiliumCallerHeaderMemory.Store header sources before i)
    (old : Initialized header sources before i.val) :
    Initialized header sources writes.after (i.val+1) := by
  intro j below
  by_cases same : j = i
  · subst j
    exact writes.read
  · have prior : j.val < i.val := by
      have ne : j.val ≠ i.val := fun h => same (Fin.ext h)
      omega
    exact (writes.otherFields j same).trans (old j prior)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 12 then stage ⟨n,h⟩ else Arm64CiliumCallerHeaderSource.after

theorem next_source (i : Fin 12) : rest i = atSource (i.val+1) := by
  by_cases h : i.val < 11
  · have next := chain ⟨i.val,h⟩
    have below : i.val+1 < 12 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 11 := Fin.ext (by omega)
    subst i
    rfl

theorem visit {m before : CC.Mem} (header : Header m) (sources : Sources m) (i : Fin 12)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header sources before i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 3 (.State procedure (atSource i.val) k (allocation m).1 le before)
        (.State procedure (atSource (i.val+1)) k (allocation m).1 le after) ∧
      Initialized header sources after (i.val+1) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  obtain ⟨writes,run⟩ := Arm64CiliumCallerHeaderMemory.visit header sources i access le k (rest i)
  have start : atSource i.val = stage i := by simp only [atSource,dite_eq_left i.isLt]
  refine ⟨writes.after,?_,stored_prefix writes old,writes.access,writes.frontier,writes.frame,writes.otherBlocks⟩
  rw [start,shape,← next_source i]
  exact run

/-- Compose consecutive original stores over the same reached heap and temps. -/
theorem run_from {m before : CC.Mem} (header : Header m) (sources : Sources m)
    (count n : Nat) (bound : n+count ≤ 12)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header sources before n) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge (3*count) (.State procedure (atSource n) k (allocation m).1 le before)
        (.State procedure (atSource (n+count)) k (allocation m).1 le after) ∧
      Initialized header sources after (n+count) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  induction count generalizing n before with
  | zero =>
    exact ⟨before,.refl _,old,rfl,rfl,FrameBelow.refl _ _,fun _ _ _ _ => rfl⟩
  | succ count ih =>
    have below : n < 12 := by omega
    let i : Fin 12 := ⟨n,below⟩
    obtain ⟨middle,firstRun,initializedPrefix,middleAccess,middleNext,firstFrame,firstOther⟩ :=
      visit header sources i access old le k
    obtain ⟨after,secondRun,initialized,afterAccess,afterNext,secondFrame,secondOther⟩ :=
      ih (n := n+1) (before := middle) (bound := by omega)
        (access := middleAccess.trans access) (old := initializedPrefix)
    have total : (n+1)+count = n+(count+1) := by omega
    have steps : 3+3*count = 3*(count+1) := by omega
    refine ⟨after,?_,?_,afterAccess.trans middleAccess,
      afterNext.trans middleNext,firstFrame.trans secondFrame,?_⟩
    · simpa only [total,steps] using firstRun.trans secondRun
    · simpa only [total] using initialized
    · intro b different c o
      exact (secondOther b different c o).trans (firstOther b different c o)

/-- All twelve original header pointer assignments, thirty-six internal steps. -/
theorem execute {m before : CC.Mem} (header : Header m) (sources : Sources m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 36 (.State procedure Arm64CiliumCallerContextGPR.after k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerHeaderSource.after k (allocation m).1 le after) ∧
      Initialized header sources after 12 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  have empty : Initialized header sources before 0 := by intro i below;omega
  have first : atSource 0 = Arm64CiliumCallerContextGPR.after := rfl
  have last : atSource 12 = Arm64CiliumCallerHeaderSource.after := rfl
  simpa only [Nat.zero_add,first,last] using
    run_from header sources 12 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderSequence
