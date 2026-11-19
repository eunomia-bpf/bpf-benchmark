import KProgFormal.ClightRefinement.Arm64NumericMemory
import KProgFormal.ClightRefinement.Arm64ProducerInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerPrefix

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)

/-- Actual initialized Numeric-world execution through the complete producer
prefix and four real cache initializers. No prefix outcome is supplied. -/
theorem initialized_prefix (ctx continuation : CC.Val) (k : CC.Cont) :
    program.initMem = some initialMemory ∧
    ∃ after, InternalRun ge 580
        (.Callstate (.Internal Arm64Producer.producer) [ctx, continuation] k initialMemory)
        (.State Arm64Producer.producer Arm64Producer.afterCacheStage k
          (Arm64Producer.allocation initialMemory).1 (Arm64Producer.initialTemps ctx continuation) after) ∧
      (∀ returns, ∃ locals : Arm64Producer.CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (Arm64Producer.allocation initialMemory).2.access ∧
      after.nextblock = (Arm64Producer.allocation initialMemory).2.nextblock := by
  obtain ⟨after, run, caches, frame, access, next⟩ :=
    Arm64Producer.entry_caches_initialized_bound ge composites_same initialMemory ctx continuation k
  refine ⟨Arm64NumericMemory.init_mem, after, run, caches, ?_, access, next⟩
  intro b below
  apply frame b
  rw [CC.Positive.toNat_ofNat _ (by decide)] at below
  simpa only [Arm64NumericMemory.initial_next] using below

/-- Resolve the real provider symbol and typed external declaration in this
world, independently of its shared composite layout. -/
theorem input_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Entry._native_lab_entry_input = some (CC.Positive.ofNat 64) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction := by
  constructor <;> run_tac Arm64NumericProgram.sourceEquality

/-- Reach the actual first kind-6 provider call after prefix580, RAW setup9
and call setup5. No external call outcome or final register state is supplied. -/
theorem initialized_first_input (ctx continuation : CC.Val) (k : CC.Cont) :
    program.initMem = some initialMemory ∧
    ∃ before, InternalRun ge 594
        (.Callstate (.Internal Arm64Producer.producer) [ctx, continuation] k initialMemory)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
          (Arm64Producer.inputContinuation initialMemory (Arm64Producer.initialTemps ctx continuation) k) before) ∧
      (∀ returns, ∃ locals : Arm64Producer.CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 before (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned before (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory before ∧
      before.access = (Arm64Producer.allocation initialMemory).2.access ∧
      before.nextblock = (Arm64Producer.allocation initialMemory).2.nextblock := by
  obtain ⟨init, cached, prefixRun, caches, frame, access, next⟩ := initialized_prefix ctx continuation k
  obtain ⟨before, setup, other, setupFrame, setupAccess, setupNext⟩ :=
    Arm64Producer.setup_register_input_bound ge initialMemory cached
      (Arm64Producer.initialTemps ctx continuation) k access
  have call := Arm64Producer.first_call_exec_bound ge input_binding initialMemory before
    (Arm64Producer.initialTemps ctx continuation) k
  refine ⟨init, before, prefixRun.trans (setup.trans (internalRun_of_steps call.2 call.1)), ?_,
    frame.trans (by
      intro b below
      apply setupFrame b
      rw [CC.Positive.toNat_ofNat _ (by decide)] at below
      simpa only [Arm64NumericMemory.initial_next] using below),
    setupAccess.trans access, setupNext.trans next⟩
  intro returns
  obtain ⟨locals, base, valid⟩ := caches returns
  refine ⟨locals, ?_, ?_⟩
  · exact (other _ _ _ locals.baseBinding (by cases returns <;> decide +kernel) .Mint64 0).trans base
  · exact (other _ _ _ locals.validBinding (by cases returns <;> decide +kernel) .Mint8unsigned 0).trans valid

end KProgFormal.ClightRefinement.Arm64NumericProducerPrefix
