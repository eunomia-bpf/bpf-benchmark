import KProgFormal.ClightRefinement.Arm64ProducerVectorInputs
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerVectorInputs.Inspection
open Arm64Producer

-- Actual parsed low/high target fields and byte offsets agree for every
-- native lane, including lane31 at offsets496/504 in the 512-byte array.
example : ∀ lane : Fin 32,
    vectorField ⟨2 * lane.val, by have := lane.isLt; omega⟩ = Arm64Entry._lo ∧
    vectorField ⟨2 * lane.val + 1, by have := lane.isLt; omega⟩ = Arm64Entry._hi ∧
    CC.Integers.Ptrofs.unsigned (vectorPointerOffset ⟨2 * lane.val, by have := lane.isLt; omega⟩) =
      16 * (lane.val : Int) ∧
    CC.Integers.Ptrofs.unsigned (vectorPointerOffset ⟨2 * lane.val + 1, by have := lane.isLt; omega⟩) =
      16 * (lane.val : Int) + 8 := by
  decide +kernel
end KProgFormal.ClightRefinement.Arm64ProducerVectorInputs.Inspection
