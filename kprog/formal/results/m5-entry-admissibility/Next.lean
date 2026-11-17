import KProgFormal.ClightRefinement.Arm64EntryAdmissibility
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64EntryAdmissibility.Inspection
open Arm64Producer

-- Every exported declaration uses its architectural register number, and the
-- actual context stores target the same x0/x30 cells consumed by the table.
example : (∀ i : Fin 31, (registerDeclaration i).index = CC.Integers.Int.repr i.val) ∧
    contextName 2 = tableCellName false 0 ∧
    contextName 3 = tableCellName true 30 ∧
    contextName 4 = tableCellName true 0 ∧
    contextRhs 3 = .Econst_int (10#32) CC.tuint ∧
    contextRhs 4 = .Econst_int (1#32) CC.tuint := by
  exact ⟨by decide +kernel, rfl, rfl, rfl, rfl, rfl⟩

-- Actual input ABI is one integer kind, not an extra context parameter; the
-- linked function lookup retains that external rather than a fixture body.
example : Arm64OriginCache.inputFunction = .External
      (.EF_external "native_lab_entry_input" (CC.mksignature [.Xint] .Xlong CC.cc_default))
      [CC.tuint] CC.tulong CC.cc_default ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction := by
  exact ⟨rfl, producer_input_binding.2⟩
end KProgFormal.ClightRefinement.Arm64EntryAdmissibility.Inspection
