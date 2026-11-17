import KProgFormal.ClightRefinement.Arm64ProducerVectorLoop
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64Producer.ConsumerInspection
-- Actual source binding and argument evaluation; no consumer execution.
example : afterVectorLoop = .Ssequence
    (.Scall (some Arm64Entry._t'131)
      (.Etempvar Arm64Entry._continuation
        (CC.tptr (.Tfunction [CC.tptr headerType] CC.tuint CC.cc_default)))
      [.Eaddrof (.Evar Arm64Entry._entry headerType) (CC.tptr headerType)])
    (.Sreturn (some (.Etempvar Arm64Entry._t'131 CC.tuint))) := vector_loop_consumer_source
example (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) :
    CC.doEvalExpr ge (allocation m).1 le before
      (.Eaddrof (.Evar Arm64Entry._entry headerType) (CC.tptr headerType)) =
      some (.Vptr entry.block 0) := by
  simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, entry.binding]
  rfl
-- Function lookup in a linked environment and lifetime/deallocation remain open.
end KProgFormal.ClightRefinement.Arm64Producer.ConsumerInspection
