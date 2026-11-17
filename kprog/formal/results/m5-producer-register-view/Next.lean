import KProgFormal.ClightRefinement.Arm64ProducerRegisterView
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerRegisterView.Inspection
open Arm64Producer

-- Actual source/consumer SP is the signed-long pointer at offset40. Its
-- allocation binding and type differ from the unsigned numeric cache at16.
example : headerField 5 = Arm64Program._sp ∧
    headerSourceName 5 = Arm64Entry.___a64_sp ∧ headerSourceType 5 = CC.tlong ∧
    headerField 2 = Arm64Program._sp_base ∧
    headerSourceName 2 = Arm64Entry.___a64_numeric_sp ∧ headerSourceType 2 = CC.tulong ∧
    headerSourceName 2 ≠ headerSourceName 5 ∧
    ((Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).map (fun co =>
      (CC.fieldOffset Arm64EntryMemory.composites Arm64Program._sp co.co_members,
       CC.fieldType Arm64Program._sp co.co_members,
       CC.fieldOffset Arm64EntryMemory.composites Arm64Program._sp_base co.co_members,
       CC.fieldType Arm64Program._sp_base co.co_members))) =
      some (.OK (40, .Full), .OK (CC.tptr CC.tlong), .OK (16, .Full), .OK (CC.tptr CC.tulong)) := by
  decide +kernel
end KProgFormal.ClightRefinement.Arm64ProducerRegisterView.Inspection
