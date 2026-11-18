import KProgFormal.ClightRefinement.Arm64MovImmediateCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate

open Arm64NumericProgram

/-- Compare two actual stores of the same value. This uses the imported raw
memory representation, including undefined bytes and both permission maps. -/
theorem stores_frame {frontier : CC.Block} {left right leftAfter rightAfter : CC.Mem}
    {chunk : CC.Chunk} {block : CC.Block} {offset : Int} {value : CC.Val}
    (frame : FrameBelow frontier left right)
    (leftStore : CC.Mem.store chunk left block offset value = some leftAfter)
    (rightStore : CC.Mem.store chunk right block offset value = some rightAfter) :
    FrameBelow frontier leftAfter rightAfter := by
  intro old below
  constructor
  · rw [CC.Mem.store_contents rightStore, CC.Mem.store_contents leftStore]
    by_cases same : block = old
    · subst old
      simpa only [CC.PMap.gss] using
        congrArg (CC.Mem.setN (CC.encodeVal chunk value) offset) (frame block below).1
    · simpa only [CC.PMap.gso _ _ _ _ same] using (frame old below).1
  · simpa only [CC.Mem.store_access rightStore, CC.Mem.store_access leftStore] using
      (frame old below).2

/-- The actual 203-transition procedure refines the complete register write
at the ORIGINAL reader frontier, including after its fresh locals are freed.
The comparison result is used only for its store and register equations; the
execution certificate remains the genuine Numeric-linked caller execution. -/
theorem call_represents {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Arm64RegisterWrite.nativeUpdate s i value narrow) := by
  obtain ⟨comparison, comparisonResult⟩ := Arm64RegisterWrite.write storage i value narrow
  obtain ⟨written, after, actualResult, run, _, freedFrame, _, _, _⟩ :=
    call_returns storage unused i value narrow
  obtain ⟨comparisonMiddle, comparisonWord, comparisonTag⟩ := comparisonResult.stores
  obtain ⟨actualMiddle, actualWord, actualTag⟩ := actualResult.stores
  have wordFrame := stores_frame (Arm64Nop.entry_frame ge before) comparisonWord actualWord
  have tagFrame := stores_frame wordFrame comparisonTag actualTag
  have finalFrame := tagFrame.trans freedFrame
  exact ⟨after, run, (Arm64Registers.frame finalFrame (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i value narrow)).mpr
      (comparisonResult.represents addresses origins s represented)⟩

/-- XZR preserves the complete register relation at the original frontier,
even after the actual generic local frame has been allocated and freed. -/
theorem call_zr_represents {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (value : BitVec 64) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 174
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (zrOperands unused entry.block value) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) s := by
  obtain ⟨after, run, _, frame, _⟩ := call_zr_returns storage unused value narrow
  exact ⟨after, run, (Arm64Registers.frame frame (.Vptr entry.block 0) s).mpr represented⟩

private theorem return_stuck (value : CC.Val) (memory : CC.Mem) :
    ∀ t next, ¬ CC.Step2 ge (.Returnstate value .Kstop memory) t next := by
  intro t next step
  cases step

/-- Arbitrary-trace relational executions can only be silent prefixes of the
same register-refining return; every stuck endpoint is that return and no
infinite execution exists. No external-call determinism premise is needed. -/
theorem call_all_behaviors {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Arm64RegisterWrite.nativeUpdate s i value narrow) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before ∧
        ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  obtain ⟨after, run, rep⟩ := call_represents storage unused i value narrow addresses origins s represented
  have stuck := return_stuck .Vundef after
  exact ⟨after, run, rep, fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed otherStuck => run.endpoint_unique stuck observed otherStuck,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64MovImmediate
