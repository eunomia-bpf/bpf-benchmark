import KProgFormal.ClightRefinement.Arm64GlobalMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64LinkedNop

open Arm64Producer
open Arm64Nop

/-- The top-level symbol resolves to the unchanged actual generic handler,
not a copied NOP-only body or an assumed continuation. -/
theorem handler_binding :
    CC.Genv.findSymbol Binding.ge.genv_genv Arm64Program._kprog_arm64_program_execute =
      some (CC.Positive.ofNat 85) ∧
    CC.Genv.findFunctPtr Binding.ge.genv_genv (CC.Positive.ofNat 85) = some (.Internal handler) := by
  constructor
  · apply Binding.existing_symbols
    decide +kernel
  · rw [Binding.existing_functions _ (by decide +kernel)]
    -- Ordinary declaration kernel checking verifies the closed source lookup;
    -- avoid meta-level unfolding of the entire large function body.
    run_tac do
      let goal ← Lean.Elab.Tactic.getMainGoal
      let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
      unless target.isAppOfArity ``Eq 3 do throwError "expected actual handler binding"
      goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
      Lean.Elab.Tactic.replaceMainGoal []

/-- The source width function still resolves at actual block66; its caller
locals cannot shadow it. This is a Clight block, not a native address. -/
def widthBinding (m : CC.Mem) : WidthBinding Binding.ge (Arm64Nop.allocation Binding.ge m).1 where
  block := CC.Positive.ofNat 66
  unshadowed := entry_unshadowed Binding.ge m
  symbol := Binding.existing_symbols _ _
    (programBinding _ (entry_unshadowed Binding.ge m)).symbol
  function := by
    rw [Binding.existing_functions _ (by decide +kernel)]
    exact (programBinding _ (entry_unshadowed Binding.ge m)).function

/-- The complete actual NOP procedure executes in the same linked environment
as the producer, for arbitrary caller memory, ignored values and flags. -/
theorem call_internal (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after, InternalRun Binding.ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) k m)
      (.Returnstate .Vundef k after) ∧ FrameBelow m.nextblock m after :=
  call_internal_bound Binding.ge m (widthBinding m) ignored flags k hk

private theorem return_stop_stuck (value : CC.Val) (m : CC.Mem) :
    ∀ t next, ¬ CC.Step2 Binding.ge (.Returnstate value .Kstop m) t next := by
  intro t next step
  cases step

/-- Every finite relational execution has the certified silent continuation;
stuck endpoints coincide and no infinite execution starts at this boundary. -/
theorem call_all_behaviors (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8) :
    ∃ after, InternalRun Binding.ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m)
      (.Returnstate .Vundef .Kstop after) ∧ FrameBelow m.nextblock m after ∧
      (∀ t other, CC.Star (CC.Step2 Binding.ge)
        (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun Binding.ge remaining other
          (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 Binding.ge)
        (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m) t other →
        (∀ u next, ¬ CC.Step2 Binding.ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal handler) (arguments ignored flags) .Kstop m ∧
        ∀ i, ∃ t, CC.Step2 Binding.ge (states i) t (states (i + 1))) := by
  obtain ⟨after, run, frame⟩ := call_internal m ignored flags .Kstop rfl
  have stuck := return_stop_stuck .Vundef after
  exact ⟨after, run, frame, fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed otherStuck => run.endpoint_unique stuck observed otherStuck,
    run.no_infinite stuck⟩

/-- Real initialized global storage survives the full nineteen transitions,
including the handler's actual local allocation and deallocation. -/
theorem initialized_call (ignored : IgnoredArguments) (flags : BitVec 8)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after, InternalRun Binding.ge 19
      (.Callstate (.Internal handler) (arguments ignored flags) k Arm64GlobalMemory.initialMemory)
      (.Returnstate .Vundef k after) ∧
      FrameBelow (CC.Positive.ofNat 189) Arm64GlobalMemory.initialMemory after := by
  obtain ⟨after, run, frame⟩ := call_internal Arm64GlobalMemory.initialMemory ignored flags k hk
  refine ⟨after, run, ?_⟩
  intro b below
  apply frame b
  rw [CC.Positive.toNat_ofNat _ (by decide)] at below
  simpa only [Arm64GlobalMemory.initial_next] using below

/-- Every observed top-level return preserves the concrete register relation
while LNSym performs the actual NOP step. Native origins/cell maps and source
admissibility remain explicit; memory/events/control refinement is separate. -/
theorem return_registers_correspond (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (cells : Reference.AArch64.Gpr → Nat)
    (m : CC.Mem) (ignored : IgnoredArguments) (flags : BitVec 8)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins cells m.nextblock m ignored.entry s)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (0xd503201f#32))
    (trace : CC.Trace) (value : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 Binding.ge)
      (.Callstate (.Internal handler) (arguments ignored flags) .Kstop m) trace
      (.Returnstate value .Kstop after)) :
    trace = CC.E0 ∧ value = .Vundef ∧ FrameBelow m.nextblock m after ∧
      Reference.AArch64.step s =
        ⟨atCursor (read_pc s.machine + (4#64)) s, [], none⟩ ∧
      Arm64Registers.Represents addresses origins cells m.nextblock after ignored.entry
        (atCursor (read_pc s.machine + (4#64)) s) := by
  obtain ⟨expected, _, framed, _, unique, _⟩ := call_all_behaviors m ignored flags
  obtain ⟨silent, same⟩ := unique _ _ observed (return_stop_stuck value after)
  cases same
  exact ⟨silent, rfl, framed, reference_step s noError fetched,
    (Arm64Registers.cursor _ _ _ _).mpr ((Arm64Registers.frame framed ignored.entry s).mpr represented)⟩

end KProgFormal.ClightRefinement.Arm64LinkedNop
