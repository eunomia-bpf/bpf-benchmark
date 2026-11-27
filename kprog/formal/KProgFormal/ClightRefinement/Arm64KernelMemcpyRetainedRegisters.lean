import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRegisters
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64ClobberRegisterComplete (Invariant stage updated)
open Arm64KernelMemcpyProviderRegisters (Inputs target)

/-- The real remaining source register reads retain their complete values
and tags, through each actual supplied heap and source store. -/
def Kept (entry : CC.Block) (before after : CC.Mem) : Prop :=
  ∀ j : Fin 31, 19 ≤ j.val → Arm64EntryMemory.gpr after.nextblock after (.Vptr entry 0) j.val =
    Arm64EntryMemory.gpr before.nextblock before (.Vptr entry 0) j.val

theorem Kept.refl (entry : CC.Block) (m : CC.Mem) : Kept entry m m := fun _ _ => rfl
theorem Kept.trans {entry : CC.Block} {a b c : CC.Mem} (first : Kept entry a b) (second : Kept entry b c) :
    Kept entry a c := fun j bound => (second j bound).trans (first j bound)

private theorem update_target (returned : Reference.AArch64.State) (i : Fin 18) :
    updated (target returned) i (target returned i) = target returned := by
  funext j
  by_cases same : j = i <;> simp only [updated,same,ite_true,ite_false] <;> subst j <;> rfl

/-- The same18 real provider pairs retain R19 through R30 alongside exact
selected native words, all36 actual stores, traces and advancing invariants. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (returned : Reference.AArch64.State)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe returned) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 (target returned) before le)
    (n : Nat) (bound : n ≤ 18) :
    ∃ after nextLe trace, ∃ current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧ Kept entry.block before after := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl,Kept.refl _ _⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next,kept⟩ := ih (by omega)
    let i : Fin 18 := ⟨n,by omega⟩
    obtain ⟨trace,provided,provider,cache⟩ := inputs i middle middleLe prior
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext,iterationKept⟩ :=
      Arm64ClobberRegisterComplete.step_supplied_framed k i prior (target returned i) trace provided provider cache
    have exactCurrent : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (n+1) (target returned) after nextLe := by
      simpa only [update_target] using current
    have retained : Kept entry.block middle after := by
      intro j bound
      have declared : ∀ i : Fin 18, (Arm64MemsetClobberRegisters.declaration i).reg.val = i.val+1 := by decide +kernel
      have different : j ≠ (Arm64MemsetClobberRegisters.declaration i).reg := by
        intro equal
        have equalValues := congrArg Fin.val equal
        rw [declared] at equalValues
        have := i.isLt
        omega
      exact iterationKept j different
    exact ⟨after,nextLe,CC.Eapp firstTrace trace,exactCurrent,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next,kept.trans retained⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyRetainedRegisters
