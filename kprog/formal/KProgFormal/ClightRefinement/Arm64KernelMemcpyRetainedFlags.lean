import KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRegisters
import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderFlags

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedFlags
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64ClobberFlagsComplete (Invariant updated)
open Arm64MemsetClobberFlags (stage)
open Arm64KernelMemcpyProviderFlags (Inputs target)
open Arm64KernelMemcpyRetainedRegisters (Kept)

private theorem update_target (returned : Reference.AArch64.State) (i : Fin 4) :
    updated (target returned) i (target returned i) = target returned := by
  funext j
  by_cases same : j = i <;> simp only [updated,same,ite_true,ite_false] <;> subst j <;> rfl

/-- Every actual supplied word and source store retains the same remaining
GPR values and tags, while writing the exact selected native target map. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} (returned : Reference.AArch64.State)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs returned) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 0 (target returned) before le)
    (n : Nat) (bound : n ≤ 4) :
    ∃ after nextLe trace, ∃ current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs n (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧ Kept entry.block before after := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl,Kept.refl _ _⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next,kept⟩ := ih (by omega)
    let i : Fin 4 := ⟨n,by omega⟩
    obtain ⟨trace,provided,provider,cache⟩ := inputs i middle middleLe prior
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext,iterationKept⟩ :=
      Arm64ClobberFlagsComplete.step_supplied_framed k i prior (target returned i) trace provided provider cache
    have exactCurrent : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (n+1) (target returned) after nextLe := by
      simpa only [update_target] using current
    exact ⟨after,nextLe,CC.Eapp firstTrace trace,exactCurrent,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next,kept.trans (fun j _ => iterationKept j)⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedFlags
