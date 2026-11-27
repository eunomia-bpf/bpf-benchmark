import KProgFormal.ClightRefinement.Arm64KernelMemcpyFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderRegisters
open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64ClobberRegisterComplete (Invariant stage updated)
open Arm64MemsetClobberRegisters (declaration)

/-- The real declaration selects the corresponding register of the SAME
returned physical machine. Tag0 retains this actual word's numeric bits. -/
def target (returned : Reference.AArch64.State) (i : Fin 18) : BitVec 64 :=
  Reference.AArch64.gpr returned (declaration i).reg

/-- Actual kind6 provider outcomes on each visited heap supply the exact
native word and the existing cache frame. This is the explicit environment
domain used by the source run, retaining its genuine trace and supplied heap. -/
def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv) (returned : Reference.AArch64.State) : Prop :=
  ∀ (i : Fin 18) m le, Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val (target returned) m le →
    ∃ (trace : CC.Trace) (provided : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong (target returned i)) provided ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m provided

private theorem update_target (returned : Reference.AArch64.State) (i : Fin 18) :
    updated (target returned) i (target returned i) = target returned := by
  funext j
  by_cases same : j = i <;> simp only [updated,same,ite_true,ite_false] <;> subst j <;> rfl

/-- Every actual source pair writes its selected native word through the
same advancing Invariant, retaining all36 real stores and exact traces. -/
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
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 18 := ⟨n,by omega⟩
    obtain ⟨trace,provided,provider,cache⟩ := inputs i middle middleLe prior
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ :=
      Arm64ClobberRegisterComplete.step_supplied k i prior (target returned i) trace provided provider cache
    have exactCurrent : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (n+1) (target returned) after nextLe := by
      simpa only [update_target] using current
    exact ⟨after,nextLe,CC.Eapp firstTrace trace,exactCurrent,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

/-- The same actual release-stage packet supplies all18 targeted provider
pairs, ending at the genuine original flag stage with exact native words. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (returned : Reference.AArch64.State)
    (current : Arm64ClobberReleaseTagComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 20 m le)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe returned) (k : CC.Cont) :
    ∃ after nextLe trace, ∃ final : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 18 (target returned) after nextLe,
      CC.Star (CC.Step2 world) (.State helper Arm64MemsetClobberEntry.rest k CC.emptyEnv le m) trace
        (.State helper (stage 18) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ j : Fin 18, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) (declaration j).reg.val =
        some (.Vlong (Reference.AArch64.gpr returned (declaration j).reg),.Vint 0)) := by
  let start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 (target returned) m le :=
    ⟨current.released.ready,current.released.parameter,by intros j impossible; omega⟩
  obtain ⟨after,nextLe,trace,final,run,frame,access,next⟩ := iterations returned inputs k start 18 (by decide)
  exact ⟨after,nextLe,trace,final,by simpa only [Arm64ClobberRegisterComplete.first_source] using run,
    frame,access,next,fun j => final.written j j.isLt⟩

/-- The SAME actual memcpy clobber entry and release trace feed all18
targeted register pairs once, reaching the real flag continuation. -/
theorem original {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (returned : Reference.AArch64.State)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe returned) (k : CC.Cont) :
    ∃ after nextLe trace,
    ∃ final : Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe 18 (target returned) after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.State helper (stage 18)
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k)) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨middle,middleLe,firstTrace,packet,release,frame,access,next⟩ :=
    Arm64MemcpyClobberRelease.execute current flag byteInputs k
  obtain ⟨after,nextLe,secondTrace,final,registers,registerFrame,registerAccess,registerNext,_⟩ :=
    execute returned packet registerInputs (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k))
  exact ⟨after,nextLe,CC.Eapp firstTrace secondTrace,final,star_trans release registers,
    frame.trans registerFrame,registerAccess.trans access,registerNext.trans next⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyProviderRegisters
