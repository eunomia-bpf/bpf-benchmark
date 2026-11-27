import KProgFormal.ClightRefinement.Arm64CiliumCallerFlags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerFlagSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerFlags (declaration stage Store)
open Arm64CiliumCallerGPRFrames (localRead LocalFrame)
open Arm64Producer (flagWord)

def Initialized (m heap : CC.Mem) (inputs : Fin 4 → BitVec 64) (count : Nat) : Prop :=
  ∀ i : Fin 4,i.val < count →
    localRead m heap (declaration i).name .Mint8unsigned 0 = some (.Vint (flagWord (inputs i)))

def Outside (id : CC.Ident) : Prop := ∀ i : Fin 4,id ≠ (declaration i).name

theorem stored_frame {m supplied : CC.Mem} {i : Fin 4} {v : BitVec 64}
    (writes : Store m supplied i v) (id : CC.Ident) (different : id ≠ (declaration i).name)
    (chunk : CC.Chunk) (offset : Int) :
    localRead m writes.after id chunk offset = localRead m supplied id chunk offset := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding writes.binding different
    simpa only [localRead,binding,Option.bind_some] using writes.otherBlocks cell.1 separate chunk offset

theorem stored_prefix {m supplied : CC.Mem} {i : Fin 4} {inputs : Fin 4 → BitVec 64}
    (writes : Store m supplied i (inputs i)) (old : Initialized m supplied inputs i.val) :
    Initialized m writes.after inputs (i.val+1) := by
  intro j below
  by_cases same : j = i
  · subst j
    simpa only [localRead,writes.binding,Option.bind_some] using writes.read
  · have prior : j.val < i.val := by
      have ne : j.val ≠ i.val := fun h => same (Fin.ext h)
      omega
    exact (stored_frame writes (declaration j).name (Arm64CiliumCallerFlags.distinct j i same)
      .Mint8unsigned 0).trans (old j prior)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 4 then stage ⟨n,h⟩ else Arm64CiliumCallerFlags.after

noncomputable def nextTemps (inputs : Fin 4 → BitVec 64) (n : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  if h : n < 4 then le.set (declaration ⟨n,h⟩).inputTemp (.Vlong (inputs ⟨n,h⟩)) else le

noncomputable def finalTemps (inputs : Fin 4 → BitVec 64) (n count : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  match count with
  | 0 => le
  | count+1 => finalTemps inputs (n+1) count (nextTemps inputs n le)

/-- Actual outcomes at reached initialized prefixes;effect frames stay explicit. -/
structure Outcomes (m : CC.Mem) (inputs : Fin 4 → BitVec 64) : Prop where
  provide : ∀ (i : Fin 4) (before : CC.Mem),
    Initialized m before inputs i.val → before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv [.Vint (6#32)]
        before trace (.Vlong (inputs i)) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      LocalFrame m before supplied ∧ FrameBelow m.nextblock before supplied

theorem next_source (i : Fin 4) : (declaration i).rest = atSource (i.val+1) := by
  by_cases h : i.val < 3
  · have next := Arm64CiliumCallerFlags.chain ⟨i.val,h⟩
    have below : i.val+1 < 4 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 3 := Fin.ext (by omega)
    subst i
    rfl

theorem visit {m before : CC.Mem} (inputs : Fin 4 → BitVec 64)
    (outcomes : Outcomes m inputs) (i : Fin 4)
    (access : before.access = (allocation m).2.access)
    (old : Initialized m before inputs i.val) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge) (.State procedure (atSource i.val) k (allocation m).1 le before)
        trace (.State procedure (atSource (i.val+1)) k (allocation m).1
          (nextTemps inputs i.val le) after) ∧
      Initialized m after inputs (i.val+1) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ chunk offset,
        localRead m after id chunk offset = localRead m before id chunk offset) := by
  obtain ⟨trace,supplied,provider,providerAccess,providerNext,effects,callerEffects⟩ :=
    outcomes.provide i before old access
  obtain ⟨writes,run⟩ := Arm64CiliumCallerFlags.input_returns i (inputs i) trace provider
    (providerAccess.trans access) le k
  have initialized : Initialized m supplied inputs i.val := fun j below =>
    (effects _ _ _).trans (old j below)
  have start : atSource i.val = stage i := by simp only [atSource,dite_eq_left i.isLt]
  have temps : nextTemps inputs i.val le = le.set (declaration i).inputTemp (.Vlong (inputs i)) := by
    simp only [nextTemps,dite_eq_left i.isLt]
  refine ⟨trace,writes.after,?_,stored_prefix writes initialized,writes.access.trans providerAccess,
    writes.frontier.trans providerNext,callerEffects.trans writes.frame,?_⟩
  · rw [start,← next_source i,temps]
    exact run
  · intro id outside chunk offset
    exact (stored_frame writes id (outside i) chunk offset).trans (effects id chunk offset)
/-- Compose actual consecutive visits while retaining their reached heap,
trace and TempEnv;the initializedPrefix invariant feeds each actual next callback. -/
theorem run_from {m before : CC.Mem} (inputs : Fin 4 → BitVec 64)
    (outcomes : Outcomes m inputs) (count n : Nat) (bound : n+count ≤ 4)
    (access : before.access = (allocation m).2.access)
    (old : Initialized m before inputs n) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge) (.State procedure (atSource n) k (allocation m).1 le before)
        trace (.State procedure (atSource (n+count)) k (allocation m).1
          (finalTemps inputs n count le) after) ∧
      Initialized m after inputs (n+count) ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ chunk offset,
        localRead m after id chunk offset = localRead m before id chunk offset) := by
  induction count generalizing n before le with
  | zero =>
    exact ⟨CC.E0,before,.refl _,old,rfl,rfl,FrameBelow.refl _ _,fun _ _ _ _ => rfl⟩
  | succ count ih =>
    have below : n < 4 := by omega
    let i : Fin 4 := ⟨n,below⟩
    obtain ⟨first,middle,firstRun,initializedPrefix,middleAccess,middleNext,firstFrame,firstLocals⟩ :=
      visit inputs outcomes i access old le k
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

/-- All four actual NZCV sites execute once,through their reached heaps,
exact external traces and TempEnv updates,to the real LR-zero statement. -/
theorem execute {m before : CC.Mem} (inputs : Fin 4 → BitVec 64)
    (outcomes : Outcomes m inputs) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge)
        (.State procedure Arm64CiliumCallerInitializers.afterTables k (allocation m).1 le before)
        trace (.State procedure Arm64CiliumCallerFlags.after k (allocation m).1
          (finalTemps inputs 0 4 le) after) ∧
      Initialized m after inputs 4 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ chunk offset,
        localRead m after id chunk offset = localRead m before id chunk offset) := by
  have empty : Initialized m before inputs 0 := by intro i below;omega
  have first : atSource 0 = Arm64CiliumCallerInitializers.afterTables := Arm64CiliumCallerFlags.first_source
  have last : atSource 4 = Arm64CiliumCallerFlags.after := rfl
  simpa only [Nat.zero_add,first,last] using run_from inputs outcomes 4 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerFlagSequence
