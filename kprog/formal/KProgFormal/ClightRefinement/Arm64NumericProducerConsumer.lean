import KProgFormal.ClightRefinement.Arm64NumericMemory
import KProgFormal.ClightRefinement.Arm64ProducerLifetime

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerConsumer

open Arm64Producer
open Arm64NumericMemory (initialMemory)

/-- The exported instruction handler cannot fill the producer's body hole:
its actual void/nine-argument ABI differs from the borrowed continuation. -/
theorem instruction_handler_not_continuation :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_execute) ≠ consumerType := by
  decide +kernel

/-- The reached producer borrows its actual entry at the retained continuation.
This records no callee binding, body execution or native admission. -/
structure Boundary (target : CC.Val) (k : CC.Cont) (before : CC.Mem)
    (le : CC.TempEnv) (entry : HeaderLocal initialMemory) : Prop where
  continuation : le.get Arm64Entry._continuation = some target
  argument : CC.doEvalExpr Arm64NumericProgram.ge (allocation initialMemory).1 le before
    consumerArgument = some (.Vptr entry.block 0)
  ready : InternalRun Arm64NumericProgram.ge 1
    (.State producer afterVectorLoop k (allocation initialMemory).1 le before)
    (.State producer consumerCall (.Kseq consumerReturn k) (allocation initialMemory).1 le before)
  freeable : ∀ id localValue, (allocation initialMemory).1.get id = some localValue →
    CC.Mem.rangePerm before localValue.1 0
      (CC.sizeof Arm64NumericProgram.ge.genv_cenv localValue.2) .Cur .Freeable = true

theorem boundary (target : CC.Val) (k : CC.Cont) (before : CC.Mem)
    (le : CC.TempEnv) (entry : HeaderLocal initialMemory)
    (continuation : le.get Arm64Entry._continuation = some target)
    (access : before.access = (allocation initialMemory).2.access) :
    Boundary target k before le entry := by
  refine ⟨continuation,
    consumer_argument_bound Arm64NumericProgram.ge initialMemory before le entry,
    consumer_ready_bound Arm64NumericProgram.ge initialMemory before le k, ?_⟩
  simpa only [Arm64NumericProgram.composites_same] using
    producer_locals_live_of_access initialMemory before access

/-- Lookup and the one-pointer/uint32 signature remain genuine linking facts.
The void/nine-argument instruction handler is not such a continuation. -/
theorem Boundary.call {target : CC.Val} {k : CC.Cont} {before : CC.Mem}
    {le : CC.TempEnv} {entry : HeaderLocal initialMemory}
    (reached : Boundary target k before le entry) (callee : CC.FunDef)
    (binding : CC.Genv.findFunct Arm64NumericProgram.ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    InternalRun Arm64NumericProgram.ge 2
      (.State producer afterVectorLoop k (allocation initialMemory).1 le before)
      (.Callstate callee [.Vptr entry.block 0]
        (consumerContinuation initialMemory le k) before) :=
  consumer_call_with_binding_bound Arm64NumericProgram.ge initialMemory before entry le k
    target callee reached.continuation binding signature

/-- The original trace is retained while the two silent call-boundary steps
are appended. No provider visit or initialization is replayed. -/
theorem Boundary.call_after {target : CC.Val} {k : CC.Cont} {before : CC.Mem}
    {le : CC.TempEnv} {entry : HeaderLocal initialMemory}
    (reached : Boundary target k before le entry) (start : CC.State) (trace : CC.Trace)
    (priorRun : CC.Star (CC.Step2 Arm64NumericProgram.ge) start trace
      (.State producer afterVectorLoop k (allocation initialMemory).1 le before))
    (callee : CC.FunDef)
    (binding : CC.Genv.findFunct Arm64NumericProgram.ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    CC.Star (CC.Step2 Arm64NumericProgram.ge) start trace
      (.Callstate callee [.Vptr entry.block 0]
        (consumerContinuation initialMemory le k) before) := by
  simpa only [CC.E0, CC.Eapp, List.append_nil] using
    star_trans priorRun (reached.call callee binding signature).sound

/-- An actual uint32 return releases the producer locals in the Numeric world.
The callee must preserve their Freeable ranges; return alone does not imply it. -/
theorem return_releases_locals (before : CC.Mem) (le : CC.TempEnv)
    (k : CC.Cont) (value : BitVec 32)
    (owned : ∀ id localValue, (allocation initialMemory).1.get id = some localValue →
      CC.Mem.rangePerm before localValue.1 0
        (CC.sizeof Arm64NumericProgram.ge.genv_cenv localValue.2) .Cur .Freeable = true) :
    ∃ after, InternalRun Arm64NumericProgram.ge 3
        (.Returnstate (.Vint value) (consumerContinuation initialMemory le k) before)
        (.Returnstate (.Vint value) (CC.callCont k) after) ∧
      FrameBelow initialMemory.nextblock before after ∧ after.contents = before.contents ∧
      after.nextblock = before.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv Arm64NumericProgram.ge.genv_cenv (allocation initialMemory).1, ∀ ofs,
        row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) :=
  consumer_return_releases_locals_bound Arm64NumericProgram.ge
    Arm64NumericProgram.composites_same initialMemory before le k value owned

/-- Compose a genuinely bound body with the reached producer and its actual
return/free suffix. Body execution and post-body ownership remain obligations. -/
theorem Boundary.call_return {target : CC.Val} {k : CC.Cont} {before : CC.Mem}
    {le : CC.TempEnv} {entry : HeaderLocal initialMemory}
    (reached : Boundary target k before le entry) (start : CC.State) (trace : CC.Trace)
    (priorRun : CC.Star (CC.Step2 Arm64NumericProgram.ge) start trace
      (.State producer afterVectorLoop k (allocation initialMemory).1 le before))
    (callee : CC.FunDef)
    (binding : CC.Genv.findFunct Arm64NumericProgram.ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType)
    (bodyTrace : CC.Trace) (returned : CC.Mem) (value : BitVec 32)
    (body : CC.Star (CC.Step2 Arm64NumericProgram.ge)
      (.Callstate callee [.Vptr entry.block 0]
        (consumerContinuation initialMemory le k) before) bodyTrace
      (.Returnstate (.Vint value) (consumerContinuation initialMemory le k) returned))
    (owned : ∀ id localValue, (allocation initialMemory).1.get id = some localValue →
      CC.Mem.rangePerm returned localValue.1 0
        (CC.sizeof Arm64NumericProgram.ge.genv_cenv localValue.2) .Cur .Freeable = true) :
    ∃ after, CC.Star (CC.Step2 Arm64NumericProgram.ge) start (CC.Eapp trace bodyTrace)
        (.Returnstate (.Vint value) (CC.callCont k) after) ∧
      FrameBelow initialMemory.nextblock returned after ∧ after.contents = returned.contents ∧
      after.nextblock = returned.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv Arm64NumericProgram.ge.genv_cenv (allocation initialMemory).1, ∀ ofs,
        row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨after, released, frame, contents, next, inaccessible⟩ :=
    return_releases_locals returned le k value owned
  refine ⟨after, ?_, frame, contents, next, inaccessible⟩
  simpa only [CC.E0, CC.Eapp, List.append_nil] using
    star_trans (star_trans (reached.call_after start trace priorRun callee binding signature) body)
      released.sound

end KProgFormal.ClightRefinement.Arm64NumericProducerConsumer
