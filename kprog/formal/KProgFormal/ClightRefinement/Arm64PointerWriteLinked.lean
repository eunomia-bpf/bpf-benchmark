import KProgFormal.ClightRefinement.Arm64PointerWriteFrame
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkedBindings

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64PointerWrite.Linked

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage Arm64ProgramEntryLinked

/-- Check the actual merged composites, including the union's pointer field. -/
theorem layout : GprLayout ge := by
  constructor <;> decide +kernel

/-- The pointer procedure occupies its real source-linked block, not the
block adjacent to the scalar writer. The original function body is retained. -/
theorem binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_write_pointer =
      some (CC.Positive.ofNat 67) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 67) =
      some (.Internal procedure) := by
  constructor <;> run_tac sourceEquality

/-- Derive stores and the complete register effect in the actual linked world,
with the caller's original continuation and all canonical cache locals kept. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ after, Result storage i value tag after ∧
      InternalRun ge 53
        (.Callstate (.Internal procedure) (arguments entry.block i value tag) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins native i value tag) ∧
      Arm64CacheLocalFrame.Kept initial before after i := by
  obtain ⟨after, result, registers⟩ := write_represents storage i value tag addresses origins native represented
  obtain ⟨middle, payload, provenance⟩ := result.stores
  exact ⟨after, result, execute_stores_layout ge layout k valid initial before middle after entry storage
    i value tag payload provenance, registers, result.kept⟩

/-- All finite executions are silent prefixes of this same register-refining
return. Every stuck endpoint is that return; an infinite execution is impossible.
Candidate relational traces are arbitrary, not assumed silent. -/
theorem all_behaviors {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage i value tag after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i value tag) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j + 1))) := by
  obtain ⟨after, result, run, registers, _kept⟩ := write storage i value tag addresses origins s represented .Kstop rfl
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, result, registers,
    fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64PointerWrite.Linked
