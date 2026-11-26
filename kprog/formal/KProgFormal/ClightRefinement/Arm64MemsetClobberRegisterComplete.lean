import KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberRegisters (declaration)

def stage (n : Nat) : CC.Stmt :=
  if h : n < 18 then (declaration ⟨n,h⟩).stage else (declaration 17).next

theorem first_source : stage 0 = Arm64MemsetClobberEntry.rest := rfl
theorem final_source : stage 18 = (declaration 17).next := rfl

private theorem positions : ∀ i : Fin 18,
    i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨
    i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 ∨ i = 16 ∨ i = 17 := by decide +kernel

theorem next_source (i : Fin 18) : (declaration i).next = stage (i.val + 1) := by
  rcases positions i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

/-- A source packet and the exact provider words already written to earlier
original registers. The saved caller and advancing helper temps stay distinct. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) (n : Nat) (values : Fin 18 → BitVec 64)
    (m : CC.Mem) (le : CC.TempEnv) where
  ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 m outerLe
  parameter : le.get Arm64Program._entry = some (.Vptr entry.block 0)
  written : ∀ j : Fin 18, j.val < n →
    Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (declaration j).reg.val =
      some (.Vlong (values j),.Vint 0)

/-- Available actual kind6 outcomes on the visited original register pairs,
with the existing explicit cache ABI on each supplied heap. -/
def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) : Prop :=
  ∀ (i : Fin 18) values m le, Invariant base abi byte outerLe i.val values m le →
    ∃ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong value) supplied ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m supplied

private def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} {values : Fin 18 → BitVec 64}
    (prior : Invariant base abi byte outerLe n values before le)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Invariant base abi byte outerLe n values after le where
  ready := Arm64MemsetClobberRegisterState.supplied prior.ready frame
  parameter := prior.parameter
  written := by
    intro j bound
    rw [frame.nextblock]
    exact (frame.gpr prior.ready.storage (declaration j).reg).trans (prior.written j bound)

def updated (values : Fin 18 → BitVec 64) (i : Fin 18) (value : BitVec 64) : Fin 18 → BitVec 64 :=
  fun j => if j = i then value else values j

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64} (i : Fin 18)
    (prior : Invariant base abi byte outerLe i.val values before le) (value : BitVec 64)
    (effect : Arm64MemsetClobberRegisterStores.Effect prior.ready.storage i value after) :
    Invariant base abi byte outerLe (i.val + 1) (updated values i value) after
      (Arm64MemsetClobberRegisterStores.temps prior.ready.storage i le value) where
  ready := Arm64MemsetClobberRegisterState.ready effect prior.ready rfl
  parameter := (Arm64MemsetClobberRegisterStores.entry_retained prior.ready.storage i le value).trans prior.parameter
  written := by
    intro j bound
    by_cases same : j = i
    · subst j
      simpa only [updated,ite_true,eq_self] using Arm64MemsetClobberRegisterState.selected effect
    · have unequal : j.val ≠ i.val := by intro equal; exact same (Fin.ext equal)
      have priorBound : j.val < i.val := by omega
      have registers : (declaration j).reg ≠ (declaration i).reg := by
        intro equal
        have indices := congrArg Fin.val equal
        rw [Arm64MemsetClobberRegisters.register_indices j,Arm64MemsetClobberRegisters.register_indices i] at indices
        omega
      simpa only [updated,same,ite_false] using
        (Arm64MemsetClobberRegisterState.other effect (declaration j).reg registers).trans (prior.written j priorBound)

/-- One real original pair: provider entry, supplied external outcome,
actual return and both inline stores. Earlier provider words are retained. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte outerLe) (k : CC.Cont) (i : Fin 18)
    (prior : Invariant base abi byte outerLe i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte outerLe (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage i.val) k CC.emptyEnv le m) trace
        (.State helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨value,trace,provided,provider,cache⟩ := inputs i values m le prior
  let packet := supplied prior cache
  have enter := Arm64MemsetClobberRegisters.ready i le m k
  have external : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (Arm64MemsetClobberRegisters.callCont i le k) m)
      trace (.Returnstate (.Vlong value) (Arm64MemsetClobberRegisters.callCont i le k) provided) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp only [CC.E0,CC.Eapp,List.append_nil])
  obtain ⟨after,effect,stores⟩ := Arm64MemsetClobberRegisterStores.returned_write packet.ready.storage i le value packet.parameter k
  refine ⟨after,_,_,trace,written i packet value effect,?_,cache.caller.trans effect.caller,
    effect.access.trans cache.access,effect.nextblock.trans cache.nextblock⟩
  have actual := star_trans (star_trans enter.sound external) stores.sound
  rw [next_source i] at actual
  simpa only [stage,i.isLt,dite_eq_left,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using actual

/-- Compose the18 genuine source pairs in order, with their actual traces,
provider words and36 stores on the same packet and current heaps. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte outerLe) (k : CC.Cont)
    (start : Invariant base abi byte outerLe 0 values before le) (n : Nat) (bound : n ≤ 18) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte outerLe n nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,values,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,middleValues,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 18 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,nextValues,secondTrace,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ := step inputs k i prior
    exact ⟨after,nextLe,nextValues,CC.Eapp firstTrace secondTrace,current,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

/-- Continue the real release scans into all18 original GPR pairs. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv}
    (current : Arm64MemsetReleaseTagComplete.Invariant base abi byte outerLe 20 m le)
    (inputs : Inputs base abi byte outerLe) (k : CC.Cont) :
    ∃ after nextLe values trace, ∃ _current : Invariant base abi byte outerLe 18 values after nextLe,
      CC.Star (CC.Step2 world) (.State helper Arm64MemsetClobberEntry.rest k CC.emptyEnv le m) trace
        (.State helper (stage 18) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let start : Invariant base abi byte outerLe 0 (fun _ => 0) m le :=
    ⟨current.released.ready,current.released.parameter,by intros j impossible; omega⟩
  simpa only [first_source] using iterations inputs k start 18 (by decide)

/-- From the same original memset clobbers call, compose160 byte indices,
20 tag indices and18 actual GPR provider pairs to the genuine flag tail. -/
theorem original {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe)
    (byteInputs : Arm64MemsetReleaseComplete.Inputs base abi byte outerLe)
    (registerInputs : Inputs base abi byte outerLe) (before : CC.Mem) (k : CC.Cont) :
    ∃ after nextLe values trace, ∃ _current : Invariant base abi byte outerLe 18 values after nextLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation before).1 outerLe m) trace
        (.State helper (stage 18)
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k)) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨middle,middleLe,firstTrace,packet,release,_reads,frame,access,next⟩ :=
    Arm64MemsetReleaseTagComplete.original current byteInputs before k
  obtain ⟨after,nextLe,values,secondTrace,current,registers,registerFrame,registerAccess,registerNext⟩ :=
    execute packet registerInputs (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k))
  exact ⟨after,nextLe,values,CC.Eapp firstTrace secondTrace,current,star_trans release registers,
    frame.trans registerFrame,registerAccess.trans access,registerNext.trans next⟩

end KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterComplete
