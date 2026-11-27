import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderFlags
import KProgFormal.ClightRefinement.Arm64ClobberVectorsComplete

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderVectors
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64ClobberVectorsComplete (Invariant stage updated)
open Arm64MemsetClobberVectors (declaration)

/-- The actual source declaration chooses its real native vector and half. -/
def target (returned : Reference.AArch64.State) (i : Fin 64) : BitVec 64 :=
  (Reference.AArch64.readVector returned (declaration i).index).extractLsb' (if (declaration i).high then 64 else 0) 64

theorem halves (returned : Reference.AArch64.State) (j : Fin 32) :
    target returned ⟨2*j.val,by omega⟩ = (Reference.AArch64.readVector returned j).extractLsb' 0 64 ∧
    target returned ⟨2*j.val+1,by omega⟩ = (Reference.AArch64.readVector returned j).extractLsb' 64 64 := by
  have indices : ∀ j : Fin 32,
      (declaration ⟨2*j.val,by omega⟩).index = j ∧ (declaration ⟨2*j.val,by omega⟩).high = false ∧
      (declaration ⟨2*j.val+1,by omega⟩).index = j ∧ (declaration ⟨2*j.val+1,by omega⟩).high = true := by decide +kernel
  simp only [target,(indices j).1,(indices j).2.1,(indices j).2.2.1,(indices j).2.2.2,ite_true,Bool.false_eq_true,ite_false,and_self]

def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv)
    (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) (returned : Reference.AArch64.State) : Prop :=
  ∀ (i : Fin 64) m le, Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags i.val (target returned) m le →
    ∃ (trace : CC.Trace) (provided : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong (target returned i)) provided ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m provided

private theorem update_target (returned : Reference.AArch64.State) (i : Fin 64) :
    updated (target returned) i (target returned i) = target returned := by
  funext j
  by_cases same : j = i <;> simp only [updated,same,ite_true,ite_false] <;> subst j <;> rfl

/-- All64 actual provider/half-store pairs retain their exact native words,
including the final original V31.hi pair and its shorter continuation. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (returned : Reference.AArch64.State)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags returned) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags 0 (target returned) before le)
    (n : Nat) (bound : n ≤ 64) :
    ∃ after nextLe trace, ∃ current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags n (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 64 := ⟨n,by omega⟩
    obtain ⟨trace,provided,provider,cache⟩ := inputs i middle middleLe prior
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ :=
      Arm64ClobberVectorsComplete.step_supplied k i prior (target returned i) trace provided provider cache
    have exactCurrent : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags (n+1) (target returned) after nextLe := by
      simpa only [update_target] using current
    exact ⟨after,nextLe,CC.Eapp firstTrace trace,exactCurrent,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (returned : Reference.AArch64.State)
    (current : Arm64ClobberFlagsComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 4 flags m le)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags returned) (k : CC.Cont) :
    ∃ after nextLe trace, ∃ final : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags 64 (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper (Arm64MemsetClobberFlags.stage 4) k CC.emptyEnv le m) trace
        (.State helper .Sskip k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ j : Fin 32, Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) j =
        some (.Vlong ((Reference.AArch64.readVector returned j).extractLsb' 0 64),
          .Vlong ((Reference.AArch64.readVector returned j).extractLsb' 64 64))) := by
  let start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs flags 0 (target returned) m le :=
    ⟨current,by intros j impossible; omega⟩
  obtain ⟨after,nextLe,trace,final,run,frame,access,next⟩ := iterations returned inputs k start 64 (by decide)
  refine ⟨after,nextLe,trace,final,?_,frame,access,next,?_⟩
  · simpa only [Arm64ClobberVectorsComplete.first_source,show stage 64 = .Sskip from rfl] using run
  · intro j
    simpa only [(halves returned j).1,(halves returned j).2] using Arm64ClobberVectorsComplete.final_vectors final j

end KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderVectors
