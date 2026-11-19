import KProgFormal.ClightRefinement.Arm64NumericProducerPrefix
import KProgFormal.ClightRefinement.Arm64ProducerGprInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerGprInputs

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer
open Arm64ProducerGprInputs (inputRegister)

/-- All 30 actual GPR calls, including x0, follow the initialized prefix
exactly once. Provider outcomes use this world's real Senv and post-memory. -/
theorem initialized_gpr_inputs (ctx continuation : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64)
    (provider : Arm64ProducerGprInputs.ProviderAt Arm64NumericProgram.ge initialMemory values) :
    program.initMem = some initialMemory ∧
    ∃ blocks : Bool → Fin 30 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (allocation initialMemory).1.get (tableCellName selected (inputRegister i)) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer (registerDeclarationStage 30) k
          (allocation initialMemory).1 finalLe after) ∧
      (∀ i : Fin 30, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (values (inputRegister i))) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ returns, ∃ cache : CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._ctx = some ctx ∧
      finalLe.get Arm64Entry._continuation = some continuation := by
  obtain ⟨init, cached, prefixRun, caches, prefixFrame, cachedAccess, cachedNext⟩ :=
    Arm64NumericProducerPrefix.initialized_prefix ctx continuation k
  obtain ⟨ready, setup, setupOther, setupFrame, setupAccess, setupNext⟩ :=
    setup_register_input_bound Arm64NumericProgram.ge initialMemory cached
      (initialTemps ctx continuation) k cachedAccess
  change InternalRun Arm64NumericProgram.ge 9
    (.State producer afterCacheStage k (allocation initialMemory).1 (initialTemps ctx continuation) cached)
    (.State producer (registerDeclarationStage 0) k (allocation initialMemory).1
      (initialTemps ctx continuation) ready) at setup
  obtain ⟨blocks, after, finalLe, traces, length, bindings, run, words, other, temps, frame, access, next⟩ :=
    Arm64ProducerGprInputs.gpr_inputs_initialized_bound Arm64NumericProgram.ge composites_same
      Arm64NumericProducerPrefix.input_binding initialMemory ready (initialTemps ctx continuation) k
      values provider (setupAccess.trans cachedAccess)
  have localFrame : FrameBelow (CC.Positive.ofNat 204) cached after := by
    intro b below
    have old : b.toNat < initialMemory.nextblock.toNat := by
      rw [CC.Positive.toNat_ofNat _ (by decide)] at below
      simpa only [Arm64NumericMemory.initial_next] using below
    exact (setupFrame.trans frame) b old
  refine ⟨init, blocks, after, finalLe, traces, length, bindings, ?_, words, ?_,
    prefixFrame.trans localFrame, access.trans (setupAccess.trans cachedAccess),
    next.trans (setupNext.trans cachedNext), ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using
      star_trans (prefixRun.trans setup).sound run
  · intro returns
    obtain ⟨cache, base, valid⟩ := caches returns
    have baseSeparate : ∀ i : Fin 30,
        baseName returns ≠ (registerDeclaration (inputRegister i)).word ∧
        baseName returns ≠ (registerDeclaration (inputRegister i)).tag := by
      cases returns <;> decide +kernel
    have validSeparate : ∀ i : Fin 30,
        validName returns ≠ (registerDeclaration (inputRegister i)).word ∧
        validName returns ≠ (registerDeclaration (inputRegister i)).tag := by
      cases returns <;> decide +kernel
    refine ⟨cache, ?_, ?_⟩
    · exact ((other _ _ _ cache.baseBinding baseSeparate .Mint64 0).trans
        (setupOther _ _ _ cache.baseBinding (by cases returns <;> decide +kernel) .Mint64 0)).trans base
    · exact ((other _ _ _ cache.validBinding validSeparate .Mint8unsigned 0).trans
        (setupOther _ _ _ cache.validBinding (by cases returns <;> decide +kernel) .Mint8unsigned 0)).trans valid
  · constructor
    · have ctxSeparate : ∀ i : Fin 30,
          Arm64Entry._ctx ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
          Arm64Entry._ctx ≠ (registerDeclaration (inputRegister i)).resultTemp := by decide +kernel
      rw [temps Arm64Entry._ctx ctxSeparate]
      simp +decide [initialTemps, CC.PTree.gso]
    · have continuationSeparate : ∀ i : Fin 30,
          Arm64Entry._continuation ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
          Arm64Entry._continuation ≠ (registerDeclaration (inputRegister i)).resultTemp := by decide +kernel
      rw [temps Arm64Entry._continuation continuationSeparate]
      simp +decide [initialTemps, CC.PTree.gso]

end KProgFormal.ClightRefinement.Arm64NumericProducerGprInputs
