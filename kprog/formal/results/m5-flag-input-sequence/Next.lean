import KProgFormal.ClightRefinement.Arm64ProducerFlagInputs
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerFlagInputs.Inspection
open Arm64Producer

-- Actual named C flag stores supply the four borrowed header fields. Returned
-- high bits survive the provider ABI but cannot change the masked byte.
example : (∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex i) = (flagDeclaration i).name ∧
    headerSourceType (Arm64ProducerEntryView.flagIndex i) = CC.tuchar) ∧
    flagWord (0x80000000000000ff#64) = (1#32) ∧
    flagWord (0x80000000000000fe#64) = (0#32) := by
  decide +kernel
end KProgFormal.ClightRefinement.Arm64ProducerFlagInputs.Inspection
