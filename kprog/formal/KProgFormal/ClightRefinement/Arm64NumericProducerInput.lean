import KProgFormal.ClightRefinement.Arm64NumericProducerPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerInput

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)

/-- Derive the actual reached call memory, then resume every admitted scalar
provider outcome there. Keep its real world, trace, post-memory and Kcall. -/
theorem initialized_first_outcomes (ctx continuation : CC.Val) (k : CC.Cont) :
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
      before.nextblock = (Arm64Producer.allocation initialMemory).2.nextblock ∧
      ∀ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
          [.Vint (6#32)] before trace (.Vlong value) supplied →
        supplied.access = (Arm64Producer.allocation initialMemory).2.access →
        ∃ xb tb after,
          (Arm64Producer.allocation initialMemory).1.get Arm64Entry.___a64_x0 =
            some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
          (Arm64Producer.allocation initialMemory).1.get Arm64Entry.___a64_x0_tag = some (tb, CC.tuchar) ∧
          CC.Star (CC.Step2 ge)
            (.Callstate (.Internal Arm64Producer.producer) [ctx, continuation] k initialMemory)
            trace (.State Arm64Producer.producer Arm64Producer.nextRegisterStage k
              (Arm64Producer.allocation initialMemory).1
              (Arm64Producer.firstInputTemps (Arm64Producer.initialTemps ctx continuation) value) after) ∧
          CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong value) ∧
          CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
          (∀ id ty block, (Arm64Producer.allocation initialMemory).1.get id = some (block, ty) →
            id ≠ Arm64Entry.___a64_x0 → id ≠ Arm64Entry.___a64_x0_tag →
            ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
          FrameBelow (CC.Positive.ofNat 204) supplied after ∧
          after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
          (Arm64Producer.firstInputTemps (Arm64Producer.initialTemps ctx continuation) value).get
            Arm64Entry._ctx = some ctx ∧
          (FrameBelow (CC.Positive.ofNat 204) before supplied →
            FrameBelow (CC.Positive.ofNat 204) initialMemory after) := by
  obtain ⟨init, before, prefixRun, caches, frame, beforeAccess, beforeNext⟩ :=
    Arm64NumericProducerPrefix.initialized_first_input ctx continuation k
  refine ⟨init, before, prefixRun, caches, frame, beforeAccess, beforeNext, ?_⟩
  intro value trace supplied provider access
  obtain ⟨xb, tb, after, cell, tagCell, resumed, word, tag, other, storedFrame, afterAccess, afterNext⟩ :=
    Arm64Producer.first_input_returns_bound ge composites_same initialMemory before supplied
      (Arm64Producer.initialTemps ctx continuation) k value trace provider access
  have storedFrame204 : FrameBelow (CC.Positive.ofNat 204) supplied after := by
    intro b below
    apply storedFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨xb, tb, after, cell, tagCell, ?_, word, tag, other, storedFrame204,
    afterAccess, afterNext, ?_, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans prefixRun.sound resumed
  · simp +decide [Arm64Producer.firstInputTemps, Arm64Producer.initialTemps, CC.PTree.gso]
  · intro providerFrame
    exact frame.trans (providerFrame.trans storedFrame204)

end KProgFormal.ClightRefinement.Arm64NumericProducerInput
