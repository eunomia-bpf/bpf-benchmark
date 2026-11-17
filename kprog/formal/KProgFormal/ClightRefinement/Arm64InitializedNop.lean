import KProgFormal.ClightRefinement.Arm64ProducerGprInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64InitializedNop

open Arm64Producer
open Arm64GlobalMemory (initialMemory)

/-- Actual global initialization and producer execution construct a live entry
for the real generic NOP procedure contract. The producer pauses before its
continuation; the separate nine-argument handler call is not a fabricated
continuation edge. Handler returns retain the OLD producer frontier. -/
theorem initialized_nop_contract
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (continuation : CC.Val) (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (gprProvider : Arm64ProducerGprInputs.Provider initialMemory inputs)
    (flagInputs : Fin 4 → BitVec 64)
    (flagProvider : Arm64ProducerFlagInputs.Provider initialMemory flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider initialMemory (Arm64ProducerVectorInputs.nativeVectorWord s))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32)) :
    Binding.program.initMem = some initialMemory ∧
    ∃ entry : HeaderLocal initialMemory, ∃ ready finalLe, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer afterVectorLoop k (allocation initialMemory).1 finalLe ready) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        ready.nextblock ready (.Vptr entry.block 0) s ∧
      FrameBelow (CC.Positive.ofNat 189) initialMemory ready ∧
      ready.access = (allocation initialMemory).2.access ∧
      ready.nextblock = (allocation initialMemory).2.nextblock ∧
      Reference.AArch64.step s = ⟨Arm64Nop.atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      ∀ (ignored : Arm64Nop.IgnoredArguments) (flags : BitVec 8),
      let bound : Arm64Nop.IgnoredArguments := { ignored with entry := .Vptr entry.block 0 }
      ∃ after, InternalRun Binding.ge 19
          (.Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments bound flags) .Kstop ready)
          (.Returnstate .Vundef .Kstop after) ∧
        FrameBelow ready.nextblock ready after ∧
        FrameBelow (CC.Positive.ofNat 189) initialMemory after ∧
        Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after
          (.Vptr entry.block 0) (Arm64Nop.atCursor (read_pc s.machine + (4#64)) s) ∧
        (∀ t other, CC.Star (CC.Step2 Binding.ge)
          (.Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments bound flags) .Kstop ready) t other →
          t = CC.E0 ∧ ∃ remaining, InternalRun Binding.ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
        (∀ t value final, CC.Star (CC.Step2 Binding.ge)
          (.Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments bound flags) .Kstop ready) t
          (.Returnstate value .Kstop final) →
          t = CC.E0 ∧ value = .Vundef ∧ FrameBelow (CC.Positive.ofNat 189) initialMemory final ∧
          Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock final
            (.Vptr entry.block 0) (Arm64Nop.atCursor (read_pc s.machine + (4#64)) s)) ∧
        ¬ (∃ states : Nat → CC.State,
          states 0 = .Callstate (.Internal Arm64Nop.handler) (Arm64Nop.arguments bound flags) .Kstop ready ∧
          ∀ i, ∃ t, CC.Step2 Binding.ge (states i) t (states (i + 1))) := by
  obtain ⟨entry, ready, finalLe, traces, length, sourceRun, registers, sourceFrame, access, next⟩ :=
    Arm64ProducerGprInputs.producer_registers_initialized addresses origins ctx ctxWord represented
      initialMemory continuation k s inputs gprProvider flagInputs flagProvider flagMatches vectorProvider
      nativeContext nativeReturn nativeOther nativeSp
  have globalNat : (CC.Positive.ofNat 189).toNat = 189 := by decide +kernel
  have globals : FrameBelow (CC.Positive.ofNat 189) initialMemory ready := by
    intro block below
    apply sourceFrame block
    simpa only [globalNat, Arm64GlobalMemory.initial_next] using below
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initialMemory)).symm
  have frontier : 189 ≤ ready.nextblock.toNat := by
    rw [next]
    simpa only [Arm64GlobalMemory.initial_next] using
      (FrameBelow.allocVariables allocated initialMemory.nextblock (Nat.le_refl _)).1
  have globalsAfter : ∀ final, FrameBelow ready.nextblock ready final →
      FrameBelow (CC.Positive.ofNat 189) initialMemory final := by
    intro final framed
    apply globals.trans
    intro block below
    apply framed block
    rw [globalNat] at below
    exact Nat.lt_of_lt_of_le below frontier
  refine ⟨Arm64GlobalMemory.init_mem, entry, ready, finalLe, traces, length, sourceRun,
    registers, globals, access, next, Arm64Nop.reference_step s noError fetched, ?_⟩
  intro ignored flags
  dsimp only
  let bound : Arm64Nop.IgnoredArguments := { ignored with entry := .Vptr entry.block 0 }
  obtain ⟨after, run, framed, prefixes, _, noInfinite⟩ := Arm64LinkedNop.call_all_behaviors ready bound flags
  obtain ⟨_, _, _, _, postRegisters⟩ :=
    Arm64LinkedNop.return_registers_correspond addresses origins (fun r => r.val) ready bound flags s
      registers noError fetched CC.E0 .Vundef after run.sound
  refine ⟨after, run, framed, globalsAfter after framed, postRegisters, prefixes, ?_, noInfinite⟩
  intro t value final observed
  obtain ⟨silent, result, framed, _, finalRegisters⟩ :=
    Arm64LinkedNop.return_registers_correspond addresses origins (fun r => r.val) ready bound flags s
      registers noError fetched t value final observed
  exact ⟨silent, result, globalsAfter final framed, finalRegisters⟩

end KProgFormal.ClightRefinement.Arm64InitializedNop
