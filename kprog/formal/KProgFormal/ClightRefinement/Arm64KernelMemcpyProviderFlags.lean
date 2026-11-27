import KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderRegisters
import KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderFlags
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64ClobberFlagsComplete (Invariant updated)
open Arm64MemsetClobberFlags (stage)

def flag (i : Fin 4) : PFlag := [PFlag.N,PFlag.Z,PFlag.C,PFlag.V][i]
def target (returned : Reference.AArch64.State) (i : Fin 4) : BitVec 64 :=
  (read_flag (flag i) returned.machine).setWidth 64

/-- The genuine C mask/cast of the actual native flag bit retains that bit. -/
theorem flag_word (bit : BitVec 1) : flagWord (bit.setWidth 64) = bit.setWidth 32 := by
  have positions : ∀ bit : BitVec 1, bit = 0 ∨ bit = 1 := by decide +kernel
  rcases positions bit with rfl | rfl <;> decide +kernel

theorem observed (returned : Reference.AArch64.State) (i : Fin 4) :
    CC.Val.Vint (flagWord (target returned i)) = Arm64ProducerEntryView.flagValues returned i := by
  have positions : ∀ i : Fin 4, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 := by decide +kernel
  rcases positions i with rfl | rfl | rfl | rfl <;>
    simp [target,flag_word,flag,Arm64ProducerEntryView.flagValues] <;> rfl

def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv)
    (gprs : Fin 18 → BitVec 64) (returned : Reference.AArch64.State) : Prop :=
  ∀ (i : Fin 4) m le, Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val (target returned) m le →
    ∃ (trace : CC.Trace) (provided : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong (target returned i)) provided ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m provided

private theorem update_target (returned : Reference.AArch64.State) (i : Fin 4) :
    updated (target returned) i (target returned i) = target returned := by
  funext j
  by_cases same : j = i <;> simp only [updated,same,ite_true,ite_false] <;> subst j <;> rfl

/-- Four original provider pairs write the exact actual native NZCV bits,
with their real supplied heaps, source masks/stores and ordered traces. -/
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
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 4 := ⟨n,by omega⟩
    obtain ⟨trace,provided,provider,cache⟩ := inputs i middle middleLe prior
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ :=
      Arm64ClobberFlagsComplete.step_supplied k i prior (target returned i) trace provided provider cache
    have exactCurrent : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (n+1) (target returned) after nextLe := by
      simpa only [update_target] using current
    exact ⟨after,nextLe,CC.Eapp firstTrace trace,exactCurrent,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} (returned : Reference.AArch64.State)
    (current : Arm64ClobberRegisterComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 18 gprs m le)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs returned) (k : CC.Cont) :
    ∃ after nextLe trace, ∃ final : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 4 (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper (Arm64ClobberRegisterComplete.stage 18) k CC.emptyEnv le m) trace
        (.State helper (stage 4) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      Arm64EntryMemory.flags after.nextblock after (.Vptr entry.block 0) =
        some (Arm64ProducerEntryView.flagValues returned 0,Arm64ProducerEntryView.flagValues returned 1,
          Arm64ProducerEntryView.flagValues returned 2,Arm64ProducerEntryView.flagValues returned 3) := by
  let start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 0 (target returned) m le :=
    ⟨current,by intros j impossible; omega⟩
  obtain ⟨after,nextLe,trace,final,run,frame,access,next⟩ := iterations returned inputs k start 4 (by decide)
  refine ⟨after,nextLe,trace,final,?_,frame,access,next,?_⟩
  · exact run
  · simpa only [observed] using Arm64ClobberFlagsComplete.final_flags final

end KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderFlags
