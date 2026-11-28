import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopIteration

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSequence
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerVectorPointerLoopSource (loop after headerOffset)
open Arm64CiliumCallerVectorPointerLoopValues (vectorPointerOffset)

def Initialized {m : CC.Mem} (header : Header m) (vectors : Storage m)
    (memory : CC.Mem) (count : Nat) : Prop :=
  ∀ (high : Bool) (i : Fin 32),i.val < count →
    CC.Mem.load .Mint64 memory header.block (headerOffset high i) =
      some (.Vptr vectors.block (vectorPointerOffset high i))

/-- Actual reached heaps and temporary environments feed every iteration. -/
theorem run_from {m : CC.Mem} (header : Header m) (vectors : Storage m)
    (count n : Nat) (bound : n+count ≤ 32) (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr n)))
    (access : before.access = (allocation m).2.access)
    (initialized : Initialized header vectors before n) :
    ∃ finalMem finalLe,InternalRun ge (11*count)
        (.State procedure loop k (allocation m).1 le before)
        (.State procedure loop k (allocation m).1 finalLe finalMem) ∧
      finalLe.get _i = some (.Vint (CC.Integers.Int.repr (n+count))) ∧
      (∀ id,id ≠ _i → finalLe.get id = le.get id) ∧
      Initialized header vectors finalMem (n+count) ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 finalMem header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ j : Fin 16,CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          finalMem header.block (Arm64CiliumCallerHeaderTailSource.offset j) =
        CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          before header.block (Arm64CiliumCallerHeaderTailSource.offset j)) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  induction count generalizing n before le with
  | zero =>
    refine ⟨before,le,.refl _,indexFound,?_,initialized,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro id different;rfl
    · intro j;rfl
    · intro j;rfl
    · intro b different c o;rfl
  | succ count ih =>
    have nBound : n < 32 := by omega
    let i : Fin 32 := ⟨n,nBound⟩
    obtain ⟨middle,headRun,headRead,headOther,headFixed,headTail,headBlocks,
        headFrame,headAccess,headNext⟩ :=
      Arm64CiliumCallerVectorPointerLoopIteration.iteration
        header vectors i access le k indexFound
    have initializedNext : Initialized header vectors middle (n+1) := by
      intro high j below
      by_cases same : j = i
      · subst j;exact headRead high
      · have ne : j.val ≠ n := fun h => same (Fin.ext h)
        exact (headOther high j same).trans (initialized high j (by omega))
    obtain ⟨finalMem,finalLe,tailRun,tailIndex,tailTemps,tailRead,tailFixed,tailTail,tailBlocks,
        tailFrame,tailAccess,tailNext⟩ :=
      ih (n+1) (by omega) middle
        (le.set _i (.Vint (CC.Integers.Int.repr (n+1))))
        (CC.PTree.gss _ _ _) (headAccess.trans access) initializedNext
    have total : n+1+count = n+Nat.succ count := by omega
    have totalIndex : ((n+1 : Nat) : Int)+(count : Int) =
        (n : Int)+((Nat.succ count : Nat) : Int) := by omega
    rw [totalIndex] at tailIndex
    rw [total] at tailRead
    refine ⟨finalMem,finalLe,?_,tailIndex,?_,tailRead,
      (fun j => (tailFixed j).trans (headFixed j)),
      (fun j => (tailTail j).trans (headTail j)),
      (fun b different c o => (tailBlocks b different c o).trans (headBlocks b different c o)),
      headFrame.trans tailFrame,tailAccess.trans headAccess,tailNext.trans headNext⟩
    · simpa only [Nat.mul_succ,Nat.add_comm] using headRun.trans tailRun
    · intro id different
      exact (tailTemps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm different))


/-- Four setup steps,32 genuine11-step iterations and six exit steps. -/
theorem execute {m before : CC.Mem} (header : Header m) (vectors : Storage m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ finalMem finalLe,InternalRun ge 362
        (.State procedure Arm64CiliumCallerHeaderTailSource.after k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 finalLe finalMem) ∧
      finalLe.get _i = some (.Vint (32#32)) ∧
      (∀ id,id ≠ _i → finalLe.get id = le.get id) ∧
      Initialized header vectors finalMem 32 ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 finalMem header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ j : Fin 16,CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          finalMem header.block (Arm64CiliumCallerHeaderTailSource.offset j) =
        CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          before header.block (Arm64CiliumCallerHeaderTailSource.offset j)) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c finalMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before finalMem ∧ finalMem.access = before.access ∧
      finalMem.nextblock = before.nextblock := by
  have empty : Initialized header vectors before 0 := by
    intro high i impossible;omega
  obtain ⟨finalMem,finalLe,loopRun,finalIndex,temps,reads,fixedFields,tailFields,blocks,frame,
      finalAccess,finalNext⟩ :=
    run_from header vectors 32 0 (by decide) before (le.set _i (.Vint (0#32)))
      (.Kseq after k) (CC.PTree.gss _ _ _) access empty
  have index32 : finalLe.get _i = some (.Vint (32#32)) := finalIndex
  refine ⟨finalMem,finalLe,
    ((Arm64CiliumCallerVectorPointerLoopIteration.initialized (m := m) (before := before) le k).trans loopRun).trans
      (Arm64CiliumCallerVectorPointerLoopIteration.exited (m := m) (before := finalMem) finalLe k index32),
    index32,?_,reads,fixedFields,tailFields,blocks,frame,finalAccess,finalNext⟩
  intro id different
  exact (temps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm different))

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSequence
