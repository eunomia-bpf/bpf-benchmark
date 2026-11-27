import KProgFormal.ClightRefinement.Arm64CiliumCallerGPRFrames

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSequence
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerGPRSource (declaration stage inputIndex)
open Arm64CiliumCallerGPRFrames (localRead LocalFrame value Initialized)

noncomputable def atSource (n : Nat) : CC.Stmt :=
  if h : n < 31 then stage ⟨n,h⟩ else Arm64CiliumCallerGPRSource.after

noncomputable def nextTemps (inputs : Fin 30 → BitVec 64) (n : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  if h : n < 30 then
    let i := inputIndex ⟨n,h⟩
    (declaration i).temps le (value inputs i)
  else le.set (declaration 30).resultTemp (.Vlong (0#64))

noncomputable def finalTemps (inputs : Fin 30 → BitVec 64) (n count : Nat) (le : CC.TempEnv) : CC.TempEnv :=
  match count with
  | 0 => le
  | count+1 => finalTemps inputs (n+1) count (nextTemps inputs n le)

def Outside (id : CC.Ident) : Prop :=
  ∀ i : Fin 31,id ≠ (declaration i).word ∧ id ≠ (declaration i).tag

/-- Availability/effect evidence at each reached initialized initializedPrefix.
No callback result,heap,trace or cache frame is supplied by an oracle. -/
structure Outcomes (m : CC.Mem) (inputs : Fin 30 → BitVec 64) : Prop where
  provide : ∀ (i : Fin 30) (before : CC.Mem),
    Initialized m before inputs i.val → before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF ge.genv_genv.toSenv [.Vint (6#32)]
        before trace (.Vlong (value inputs (inputIndex i))) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      LocalFrame m before supplied ∧ FrameBelow m.nextblock before supplied

theorem next_source (i : Fin 31) : (declaration i).rest = atSource (i.val+1) := by
  by_cases h : i.val < 30
  · have next := Arm64CiliumCallerGPRSource.chain ⟨i.val,h⟩
    have below : i.val+1 < 31 := by omega
    simpa only [atSource,dite_eq_left below] using next
  · have same : i = 30 := Fin.ext (by omega)
    subst i
    rfl

/-- One actual source visit,using the SAME existing execution/store witness.
It advances the source position,actual temporaries and initialized initializedPrefix. -/
theorem visit {m before : CC.Mem} (inputs : Fin 30 → BitVec 64)
    (outcomes : Outcomes m inputs) (i : Fin 31)
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
  by_cases h : i.val < 30
  · let j : Fin 30 := ⟨i.val,h⟩
    obtain ⟨trace,supplied,provider,providerAccess,providerNext,effects,callerEffects⟩ :=
      outcomes.provide j before old access
    obtain ⟨writes,run,initializedPrefix,frame,locals⟩ := Arm64CiliumCallerGPRFrames.input_returns
      j inputs trace provider (providerAccess.trans access) effects callerEffects old le k
    have start : atSource i.val = stage (inputIndex j) := by
      simp only [atSource,dite_eq_left i.isLt]
      rfl
    have finish : (declaration (inputIndex j)).rest = atSource (i.val+1) := next_source (inputIndex j)
    have temps : nextTemps inputs i.val le =
        (declaration (inputIndex j)).temps le (value inputs (inputIndex j)) := by
      simp only [nextTemps,dite_eq_left h]
      rfl
    refine ⟨trace,writes.after,?_,initializedPrefix,writes.access.trans providerAccess,
      writes.frontier.trans providerNext,frame,?_⟩
    · rw [start,← finish,temps]
      exact run
    · intro id outside chunk offset
      exact locals id (outside (inputIndex j)).1 (outside (inputIndex j)).2 chunk offset
  · have same : i = 30 := Fin.ext (by omega)
    subst i
    obtain ⟨writes,run,initializedPrefix⟩ := Arm64CiliumCallerGPRFrames.literal_zero inputs access old le k
    refine ⟨CC.E0,writes.after,?_,initializedPrefix,writes.access,writes.frontier,writes.frame,?_⟩
    · exact run.sound
    · intro id outside chunk offset
      exact Arm64CiliumCallerGPRFrames.stored_frame writes id (outside 30).1 (outside 30).2 chunk offset

/-- Compose actual consecutive visits while retaining their reached heap,
trace and TempEnv;the initializedPrefix invariant feeds each actual next callback. -/
theorem run_from {m before : CC.Mem} (inputs : Fin 30 → BitVec 64)
    (outcomes : Outcomes m inputs) (count n : Nat) (bound : n+count ≤ 31)
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
    have below : n < 31 := by omega
    let i : Fin 31 := ⟨n,below⟩
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

/-- All31 original initializers execute once,with30 explicit actual kind6
external outcomes and the original R30 literal-zero branch. -/
theorem execute {m before : CC.Mem} (inputs : Fin 30 → BitVec 64)
    (outcomes : Outcomes m inputs) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ trace after,
      CC.Star (CC.Step2 ge)
        (.State procedure Arm64CiliumCallerDefaults.after k (allocation m).1 le before)
        trace (.State procedure Arm64CiliumCallerInitializers.start k (allocation m).1
          (finalTemps inputs 0 31 le) after) ∧
      Initialized m after inputs 31 ∧
      after.access = before.access ∧ after.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before after ∧
      (∀ id,Outside id → ∀ chunk offset,
        localRead m after id chunk offset = localRead m before id chunk offset) := by
  have empty : Initialized m before inputs 0 := by
    constructor <;> intro i below <;> omega
  have first : atSource 0 = Arm64CiliumCallerDefaults.after := Arm64CiliumCallerGPRSource.first_source
  have last : atSource 31 = Arm64CiliumCallerInitializers.start := Arm64CiliumCallerGPRSource.last_source
  simpa only [Nat.zero_add,first,last] using
    run_from inputs outcomes 31 0 (by omega) access empty le k

end KProgFormal.ClightRefinement.Arm64CiliumCallerGPRSequence
