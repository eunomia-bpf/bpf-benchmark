import KProgFormal.ClightRefinement.Arm64ProducerLifetime
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64Producer.ConsumerInspection
-- The real exported borrowed handler is not the producer's continuation ABI.
example : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_raw) =
    .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong]
      CC.tulong CC.cc_default := rfl
example : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_raw) ≠ consumerType := by
  decide +kernel
example : producer.fn_params = [(Arm64Entry._ctx, CC.tptr CC.tvoid),
    (Arm64Entry._continuation, CC.tptr consumerType)] := rfl
example : producer.fn_return = CC.tuint := rfl
-- Callee lookup/type still require a genuine compilation-unit binding theorem.
-- This query neither invents a callback nor executes the continuation.
end KProgFormal.ClightRefinement.Arm64Producer.ConsumerInspection
