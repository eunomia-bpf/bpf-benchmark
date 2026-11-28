import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerVectorSource (Storage stage rest temporary)
open Arm64CiliumCallerGPRFrames (localRead LocalFrame)

def Initialized {m : CC.Mem} (storage : Storage m) (heap : CC.Mem)
    (inputs : Fin 64 → BitVec 64) (count : Nat) : Prop :=
  ∀ i : Fin 64,i.val < count →
    CC.Mem.load .Mint64 heap storage.block (8*(i.val : Int)) = some (.Vlong (inputs i))

def Outside (id : CC.Ident) : Prop := id ≠ Arm64Entry.___a64_vectors

/-- SAME actual store preserves every prior lane and initializes this lane. -/
theorem stored_prefix {m supplied : CC.Mem} {storage : Storage m}
    {i : Fin 64} {inputs : Fin 64 → BitVec 64}
    (writes : Arm64CiliumCallerVectorMemory.Store storage supplied i (inputs i))
    (old : Initialized storage supplied inputs i.val) :
    Initialized storage writes.after inputs (i.val+1) := by
  intro j below
  by_cases same : j = i
  · subst j
    exact writes.read
  · have prior : j.val < i.val := by
      have ne : j.val ≠ i.val := fun h => same (Fin.ext h)
      omega
    exact (writes.otherFields j same).trans (old j prior)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 64 then stage ⟨n,h⟩ else Arm64CiliumCallerVectorSource.after

noncomputable def nextTemps (inputs : Fin 64 → BitVec 64) (n : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  if h : n < 64 then le.set (temporary ⟨n,h⟩) (.Vlong (inputs ⟨n,h⟩)) else le

noncomputable def finalTemps (inputs : Fin 64 → BitVec 64) (n count : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  match count with
  | 0 => le
  | count+1 => finalTemps inputs (n+1) count (nextTemps inputs n le)

/-- Actual availability/effects at the SAME reached initialized vector prefix.
No purity,successful reader,oracle or fixed trace is silently assumed. -/
structure Outcomes {m : CC.Mem} (storage : Storage m) (inputs : Fin 64 → BitVec 64) : Prop where
  provide : ∀ (i : Fin 64) (before : CC.Mem),
    Initialized storage before inputs i.val → before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv [.Vint (6#32)]
        before trace (.Vlong (inputs i)) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      LocalFrame m before supplied ∧ FrameBelow m.nextblock before supplied

theorem next_source (i : Fin 64) : rest i = atSource (i.val+1) := by
  by_cases h : i.val < 63
  · have next := Arm64CiliumCallerVectorSource.chain ⟨i.val,h⟩
    have below : i.val+1 < 64 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 63 := Fin.ext (by omega)
    subst i
    rfl

/-- Each real provider outcome feeds the SAME genuine store witness. -/
theorem visit {m before : CC.Mem} (storage : Storage m) (inputs : Fin 64 → BitVec 64)
    (outcomes : Outcomes storage inputs) (i : Fin 64)
    (access : before.access = (allocation m).2.access)
    (old : Initialized storage before inputs i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge) (.State procedure (atSource i.val) k (allocation m).1 le before)
        trace (.State procedure (atSource (i.val+1)) k (allocation m).1
          (nextTemps inputs i.val le) after) ∧
      Initialized storage after inputs (i.val+1) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ c o,localRead m after id c o = localRead m before id c o) := by
  obtain ⟨trace,supplied,provider,providerAccess,providerNext,effects,callerEffects⟩ :=
    outcomes.provide i before old access
  have arrayFrame (j : Fin 64) :
      CC.Mem.load .Mint64 supplied storage.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before storage.block (8*(j.val : Int)) := by
    simpa only [localRead,storage.binding,Option.bind_some] using
      effects Arm64Entry.___a64_vectors .Mint64 (8*(j.val : Int))
  have initialized : Initialized storage supplied inputs i.val :=
    fun j below => (arrayFrame j).trans (old j below)
  obtain ⟨writes,run⟩ := Arm64CiliumCallerVectorMemory.input_returns storage i (inputs i) trace provider
    (providerAccess.trans access) le k
  have start : atSource i.val = stage i := by simp only [atSource,dite_eq_left i.isLt]
  have temps : nextTemps inputs i.val le = le.set (temporary i) (.Vlong (inputs i)) := by
    simp only [nextTemps,dite_eq_left i.isLt]
  refine ⟨trace,writes.after,?_,stored_prefix writes initialized,writes.access.trans providerAccess,
    writes.frontier.trans providerNext,callerEffects.trans writes.frame,?_⟩
  · rw [start,← next_source i,temps]
    exact run
  · intro id outside c o
    exact (Arm64CiliumCallerVectorMemory.named_frame writes id outside c o).trans (effects id c o)
/-- Compose actual consecutive visits while retaining their reached heap,
trace and TempEnv;the initializedPrefix invariant feeds each actual next callback. -/
theorem run_from {m before : CC.Mem} (storage : Storage m) (inputs : Fin 64 → BitVec 64)
    (outcomes : Outcomes storage inputs) (count n : Nat) (bound : n+count ≤ 64)
    (access : before.access = (allocation m).2.access)
    (old : Initialized storage before inputs n) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge) (.State procedure (atSource n) k (allocation m).1 le before)
        trace (.State procedure (atSource (n+count)) k (allocation m).1
          (finalTemps inputs n count le) after) ∧
      Initialized storage after inputs (n+count) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ chunk offset,
        localRead m after id chunk offset = localRead m before id chunk offset) := by
  induction count generalizing n before le with
  | zero =>
    exact ⟨CC.E0,before,.refl _,old,rfl,rfl,FrameBelow.refl _ _,fun _ _ _ _ => rfl⟩
  | succ count ih =>
    have below : n < 64 := by omega
    let i : Fin 64 := ⟨n,below⟩
    obtain ⟨first,middle,firstRun,initializedPrefix,middleAccess,middleNext,firstFrame,firstLocals⟩ :=
      visit storage inputs outcomes i access old le k
    obtain ⟨second,after,secondRun,initialized,afterAccess,afterNext,secondFrame,secondLocals⟩ :=
      ih (n := n+1) (before := middle) (le := nextTemps inputs n le)
        (bound := by omega) (access := middleAccess.trans access) (old := initializedPrefix)
    have total : (n+1)+count = n+(count+1) := by omega
    refine ⟨CC.Eapp first second,after,?_,?_,afterAccess.trans middleAccess,
      afterNext.trans middleNext,firstFrame.trans secondFrame,?_⟩
    · simpa only [finalTemps,total] using star_trans firstRun secondRun
    · simpa only [total] using initialized
    · intro id outside chunk offset
      exact (secondLocals id outside chunk offset).trans (firstLocals id outside chunk offset)

/-- All64 original vector input/store visits execute ONCE over this SAME
actual storage,with64 explicit actual outcomes,to the untouched successor. -/
theorem execute {m before : CC.Mem} (storage : Storage m) (inputs : Fin 64 → BitVec 64)
    (outcomes : Outcomes storage inputs) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge)
        (.State procedure Arm64CiliumCallerFlags.vectorStart k (allocation m).1 le before)
        trace (.State procedure Arm64CiliumCallerVectorSource.after k (allocation m).1
          (finalTemps inputs 0 64 le) after) ∧
      Initialized storage after inputs 64 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ c o,localRead m after id c o = localRead m before id c o) := by
  have empty : Initialized storage before inputs 0 := by intro i below;omega
  have first : atSource 0 = Arm64CiliumCallerFlags.vectorStart := Arm64CiliumCallerVectorSource.first_source
  have last : atSource 64 = Arm64CiliumCallerVectorSource.after := rfl
  simpa only [Nat.zero_add,first,last] using
    run_from storage inputs outcomes 64 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorSequence
