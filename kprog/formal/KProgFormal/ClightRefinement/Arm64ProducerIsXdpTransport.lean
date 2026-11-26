import KProgFormal.ClightRefinement.Arm64ProducerIsXdpSetup
import KProgFormal.ClightRefinement.Arm64ProgramEntryInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerIsXdpTransport

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (TailLocal)

private theorem cancel_prefix {ge : CC.CGenv} {n m : Nat} {start middle last : CC.State}
    (headRun : InternalRun ge n start middle) (whole : InternalRun ge (n+m) start last) :
    InternalRun ge m middle last := by
  induction headRun with
  | refl _ => simpa using whole
  | @step n start next middle hs step tail ih =>
    have reordered : InternalRun ge ((n+m)+1) start last := by
      simpa only [Nat.add_assoc,Nat.add_comm,Nat.add_left_comm] using whole
    cases reordered with
    | step _ other remaining =>
      have same := (internal_step_unique hs step other).2
      cases same
      exact ih remaining

private theorem actual_binding {initial : CC.Mem} (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = some (block,ty) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty binding
  simpa only [name,type] using actual

private theorem unchanged_binding (initial : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars)
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = (Arm64Producer.allocation initial).1.get id := by
  obtain ⟨block, bound, _, _, _⟩ := Arm64Producer.local_storage initial id ty present
  exact (actual_binding id ty block bound name type).trans bound.symm

private theorem setup_bindings (initial : CC.Mem) : ∀ id ∈ Arm64Producer.setupNames,
    (allocation initial).1.get id = (Arm64Producer.allocation initial).1.get id := by
  intro id member
  simp only [Arm64Producer.setupNames, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl
  · exact unchanged_binding initial _ CC.tuchar (by decide +kernel) (by decide +kernel) rfl
  · exact unchanged_binding initial _ (CC.tptr CC.tvoid) (by decide +kernel) (by decide +kernel) rfl
  · exact unchanged_binding initial _ (CC.tptr CC.tvoid) (by decide +kernel) (by decide +kernel) rfl

/-- The same actual589-step original entry/cache/setup witness determines
the initialized is_xdp zero byte on its real declared local. -/
theorem setup_observed (initial after : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (cell : TailLocal initial 5)
    (whole : InternalRun world 589
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after)) :
    CC.Mem.load .Mint8unsigned after cell.block 0 = some (.Vint 0) := by
  obtain ⟨before,run,_caches,_frame,access,_next⟩ := Arm64ProgramEntryPrefix.entry_caches_initialized initial ctx k
  have tail : InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) after) :=
    cancel_prefix run (by simpa using whole)
  rw [Arm64ProgramEntryInputs.setup_source] at tail
  have sourceAccess := access.trans (congrArg CC.Mem.access
    (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  exact Arm64ProducerIsXdpSetup.observed world Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1
    Arm64ProgramEntryInputs.registerStage initial before after (Arm64ProgramEntryCall.initialTemps ctx) k cell
    (setup_bindings initial) sourceAccess tail

/-- The actual first kind6 boundary carries the same zero byte, cold caches,
frame and allocation frontier from that original entry execution. -/
theorem first_provider (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) (cell : TailLocal initial 5) :
    ∃ before, InternalRun world 594
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (Arm64ProgramEntryInputs.inputContinuation initial (Arm64ProgramEntryCall.initialTemps ctx) k) before) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial before ∧ FrameBelow initial.nextblock initial before ∧
      before.access = (allocation initial).2.access ∧ before.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned before cell.block 0 = some (.Vint 0) := by
  obtain ⟨before,run,caches,frame,access,next⟩ := Arm64ProgramEntryInputs.entry_setup initial ctx k
  exact ⟨before,run.trans (Arm64ProgramEntryInputs.first_call_ready initial before _ k),
    caches,frame,access,next,setup_observed initial before ctx k cell run⟩

end KProgFormal.ClightRefinement.Arm64ProducerIsXdpTransport
