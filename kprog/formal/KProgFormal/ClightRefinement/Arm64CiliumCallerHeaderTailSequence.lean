import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerHeaderTailSource (stage rest row offset chunk shape chain)
open Arm64CiliumCallerHeaderTailValues (Storage value)
open Arm64CiliumCallerGPRFrames (localRead)

def Initialized {m : CC.Mem} (header : Header m) (resource : Storage m)
    (heap : CC.Mem) (count : Nat) : Prop :=
  ∀ i : Fin 16,i.val < count →
    CC.Mem.load (chunk i) heap header.block (offset i) = some (value resource i)

theorem stored_prefix {m before : CC.Mem} {header : Header m} {resource : Storage m} {i : Fin 16}
    (writes : Arm64CiliumCallerHeaderTailMemory.Store header resource before i)
    (old : Initialized header resource before i.val) :
    Initialized header resource writes.after (i.val+1) := by
  intro j below
  by_cases same : j = i
  · subst j
    exact writes.read
  · have prior : j.val < i.val := by
      have ne : j.val ≠ i.val := fun h => same (Fin.ext h)
      omega
    exact (writes.otherFields j same).trans (old j prior)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 16 then stage ⟨n,h⟩ else Arm64CiliumCallerHeaderTailSource.after

theorem next_source (i : Fin 16) : rest i = atSource (i.val+1) := by
  by_cases h : i.val < 15
  · have next := chain ⟨i.val,h⟩
    have below : i.val+1 < 16 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 15 := Fin.ext (by omega)
    subst i
    rfl

theorem visit {m before : CC.Mem} (header : Header m) (resource : Storage m) (i : Fin 16)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header resource before i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 3 (.State procedure (atSource i.val) k (allocation m).1 le before)
        (.State procedure (atSource (i.val+1)) k (allocation m).1 le after) ∧
      Initialized header resource after (i.val+1) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 76,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  obtain ⟨writes,run⟩ := Arm64CiliumCallerHeaderTailMemory.visit header resource i access le k (rest i)
  have start : atSource i.val = stage i := by simp only [atSource,dite_eq_left i.isLt]
  refine ⟨writes.after,?_,stored_prefix writes old,writes.access,writes.frontier,writes.frame,writes.oldFields,writes.otherBlocks⟩
  rw [start,shape,← next_source i]
  exact run

/-- Compose consecutive original stores over the same reached heap and temps. -/
theorem run_from {m before : CC.Mem} (header : Header m) (resource : Storage m)
    (count n : Nat) (bound : n+count ≤ 16)
    (access : before.access = (allocation m).2.access)
    (old : Initialized header resource before n) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge (3*count) (.State procedure (atSource n) k (allocation m).1 le before)
        (.State procedure (atSource (n+count)) k (allocation m).1 le after) ∧
      Initialized header resource after (n+count) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 76,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  induction count generalizing n before with
  | zero =>
    exact ⟨before,.refl _,old,rfl,rfl,FrameBelow.refl _ _,fun _ => rfl,fun _ _ _ _ => rfl⟩
  | succ count ih =>
    have below : n < 16 := by omega
    let i : Fin 16 := ⟨n,below⟩
    obtain ⟨middle,firstRun,initializedPrefix,middleAccess,middleNext,firstFrame,firstFixed,firstOther⟩ :=
      visit header resource i access old le k
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

/-- All sixteen original mixed-width header assignments,48 internal steps. -/
theorem execute {m before : CC.Mem} (header : Header m) (resource : Storage m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after,
      InternalRun ge 48 (.State procedure Arm64CiliumCallerHeaderVectorNullSource.after k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerHeaderTailSource.after k (allocation m).1 le after) ∧
      Initialized header resource after 16 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ j : Fin 76,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) := by
  have empty : Initialized header resource before 0 := by intro i below;omega
  have first : atSource 0 = Arm64CiliumCallerHeaderVectorNullSource.after := rfl
  have last : atSource 16 = Arm64CiliumCallerHeaderTailSource.after := rfl
  simpa only [Nat.zero_add,first,last] using
    run_from header resource 16 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailSequence
