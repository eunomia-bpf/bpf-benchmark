import KProgFormal.ClightRefinement.Arm64ProducerLifetime
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64Producer.UnifiedInspection
-- These witnesses must typecheck in the actual linked environment.  A run in
-- the standalone Entry environment cannot inhabit these statements.
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ after finalLe, InternalRun Binding.ge 638
      (.State producer afterContext k (allocation m).1 le before)
      (.State producer afterVectorLoop k (allocation m).1 finalLe after) := by
  obtain ⟨_, _, _, _, after, finalLe, run, _⟩ := header_initialized_before_consumer m before le k access
  exact ⟨after, finalLe, run⟩
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (target : CC.Val) (callee : CC.FunDef)
    (access : before.access = (allocation m).2.access)
    (continuation : le.get Arm64Entry._continuation = some target)
    (binding : CC.Genv.findFunct Binding.ge.genv_genv target = some callee)
    (signature : CC.typeOfFundef callee = consumerType) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, InternalRun Binding.ge 640
      (.State producer afterContext k (allocation m).1 le before)
      (.Callstate callee [.Vptr entry.block 0] (consumerContinuation m finalLe k) after) := by
  obtain ⟨entry, after, finalLe, run, _⟩ :=
    header_caches_at_consumer_call m before le k target callee access continuation binding signature
  exact ⟨entry, after, finalLe, run⟩
example : CC.Genv.findSymbol Binding.ge.genv_genv Arm64Entry._native_lab_entry_input =
    some (CC.Positive.ofNat 64) := producer_input_binding.1
example : CC.Genv.findFunctPtr Binding.ge.genv_genv (payloadCallbackBlock false) =
    some (.Internal Arm64Entry.f_kprog_arm64_payload_load) := (payload_callback_binding false).2
example : CC.Genv.findFunctPtr Binding.ge.genv_genv (payloadCallbackBlock true) =
    some (.Internal Arm64Entry.f_kprog_arm64_payload_store) := (payload_callback_binding true).2
-- A genuine continuation body and native provider/memory/control correspondence
-- remain separate obligations; this query does not fabricate them.
end KProgFormal.ClightRefinement.Arm64Producer.UnifiedInspection
