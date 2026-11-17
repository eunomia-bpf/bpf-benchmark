import KProgFormal.ClightRefinement.Arm64ProducerBinding
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64Producer.BindingInspection
private theorem count : Binding.program.prog_defs.length = 188 := by
  rw [Binding.linked_definitions]
  rfl
example : Binding.ge.genv_genv.genv_next = CC.Positive.ofNat 189 := by decide +kernel
-- A decision procedure for this finite signature proposition needs only the
-- imported type equality, never equality or execution of function bodies.
private def noConsumer : CC.GlobDef CC.FunDef CC.Ty → Prop
  | .Gfun fd => CC.typeOfFundef fd ≠ consumerType
  | .Gvar _ => True
private instance (definition : CC.GlobDef CC.FunDef CC.Ty) : Decidable (noConsumer definition) := by
  cases definition with
  | Gfun fd => exact inferInstanceAs (Decidable (CC.typeOfFundef fd ≠ consumerType))
  | Gvar _ => exact isTrue trivial
-- Both complete exports contain handlers and entry templates, but no body
-- supplies the borrowed continuation ABI.  The body obligation stays open.
example : ∀ row ∈ Binding.program.prog_defs, noConsumer row.2 := by
  rw [Binding.linked_definitions]
  decide +kernel
end KProgFormal.ClightRefinement.Arm64Producer.BindingInspection
