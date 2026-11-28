import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerHeaderVectorNullSource (stage rest row offset shape chain)
open Arm64CiliumCallerGPRFrames (localRead)

def Initialized {m : CC.Mem} (header : Header m)
    (heap : CC.Mem) (count : Nat) : Prop :=
  ∀ i : Fin 64,i.val < count →
    CC.Mem.load .Mint64 heap header.block (offset i) = some (.Vlong (0#64))

theorem stored_prefix {m before : CC.Mem} {header : Header m} {i : Fin 64}
    (writes : Arm64CiliumCallerHeaderVectorNullMemory.Store header before i)
    (old : Initialized header before i.val) :
    Initialized header writes.after (i.val+1) := by
  intro j below
  by_cases same : j = i
  · subst j
    exact writes.read
  · have prior : j.val < i.val := by
      have ne : j.val ≠ i.val := fun h => same (Fin.ext h)
      omega
    exact (writes.otherFields j same).trans (old j prior)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 64 then stage ⟨n,h⟩ else Arm64CiliumCallerHeaderVectorNullSource.after

theorem next_source (i : Fin 64) : rest i = atSource (i.val+1) := by
  by_cases h : i.val < 63
  · have next := chain ⟨i.val,h⟩
    have below : i.val+1 < 64 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 63 := Fin.ext (by omega)
    subst i
    rfl

theorem visit {m before : CC.Mem} (header : Header m) (i : Fin 64)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header before i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 3 (.State procedure (atSource i.val) k (allocation m).1 le before)
        (.State procedure (atSource (i.val+1)) k (allocation m).1 le after) ∧
      Initialized header after (i.val+1) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  obtain ⟨writes,run⟩ := Arm64CiliumCallerHeaderVectorNullMemory.visit header i access le k (rest i)
  have start : atSource i.val = stage i := by simp only [atSource,dite_eq_left i.isLt]
  refine ⟨writes.after,?_,stored_prefix writes old,writes.access,writes.frontier,writes.frame,writes.fixedFields,writes.otherBlocks⟩
  rw [start,shape,← next_source i]
  exact run

/-- Compose consecutive original stores over the same reached heap and temps. -/
theorem run_from {m before : CC.Mem} (header : Header m)
    (count n : Nat) (bound : n+count ≤ 64)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header before n) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge (3*count) (.State procedure (atSource n) k (allocation m).1 le before)
        (.State procedure (atSource (n+count)) k (allocation m).1 le after) ∧
      Initialized header after (n+count) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  induction count generalizing n before with
  | zero =>
    exact ⟨before,.refl _,old,rfl,rfl,FrameBelow.refl _ _,fun _ => rfl,fun _ _ _ _ => rfl⟩
  | succ count ih =>
    have below : n < 64 := by omega
    let i : Fin 64 := ⟨n,below⟩
    obtain ⟨middle,firstRun,initializedPrefix,middleAccess,middleNext,firstFrame,firstFixed,firstOther⟩ :=
      visit header i access old le k
    obtain ⟨after,secondRun,initialized,afterAccess,afterNext,secondFrame,secondFixed,secondOther⟩ :=
      ih (n := n+1) (before := middle) (bound := by omega)
        (access := middleAccess.trans access) (old := initializedPrefix)
    have total : (n+1)+count = n+(count+1) := by omega
    have steps : 3+3*count = 3*(count+1) := by omega
    refine ⟨after,?_,?_,afterAccess.trans middleAccess,
      afterNext.trans middleNext,firstFrame.trans secondFrame,?_,?_⟩
    · simpa only [total,steps] using firstRun.trans secondRun
    · simpa only [total] using initialized
    · intro j
      exact (secondFixed j).trans (firstFixed j)
    · intro b different c o
      exact (secondOther b different c o).trans (firstOther b different c o)

/-- All sixty-four original vector pointer NULL assignments, 192 internal steps. -/
theorem execute {m before : CC.Mem} (header : Header m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 192 (.State procedure Arm64CiliumCallerHeaderSource.after k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerHeaderVectorNullSource.after k (allocation m).1 le after) ∧
      Initialized header after 64 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  have empty : Initialized header before 0 := by intro i below;omega
  have first : atSource 0 = Arm64CiliumCallerHeaderSource.after := rfl
  have last : atSource 64 = Arm64CiliumCallerHeaderVectorNullSource.after := rfl
  simpa only [Nat.zero_add,first,last] using
    run_from header 64 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullSequence
