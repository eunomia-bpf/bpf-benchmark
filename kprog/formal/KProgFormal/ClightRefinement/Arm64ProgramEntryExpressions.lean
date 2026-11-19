import KProgFormal.ClightRefinement.Arm64ProgramEntrySource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryExpressions

open Arm64ProgramEntryAllocation (localName localType EnvsCorrespond world)
open Arm64ProgramEntrySource (sourceType expression)

private theorem source_types : ∀ i : Fin Arm64Producer.producer.fn_vars.length,
    sourceType Arm64Producer.producer.fn_vars[i].2 =
      localType Arm64Producer.producer.fn_vars[i].2 := by decide +kernel

/-- The recursive source annotation map agrees with the checked allocator map
on every actual declaration. This is not a claim about arbitrary C types. -/
theorem declaration_type (row : CC.Ident × CC.Ty)
    (present : row ∈ Arm64Producer.producer.fn_vars) : sourceType row.2 = localType row.2 := by
  obtain ⟨i, rfl⟩ := List.mem_iff_get.mp present
  exact source_types i

private theorem access_mode (ty : CC.Ty) : CC.accessMode (sourceType ty) = CC.accessMode ty := by
  cases ty <;> rfl

private theorem dereference_full (ty : CC.Ty) (m : CC.Mem) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) :
    CC.doDerefLoc (sourceType ty) m block offset .Full =
      CC.doDerefLoc ty m block offset .Full := by
  simp only [CC.doDerefLoc, access_mode]

/-- Local bindings, not a global-symbol equivalence, justify the same address.
The source declaration annotation is checked at both lookup sites. -/
theorem bound_lvalue (source actual : CC.Env) (related : EnvsCorrespond source actual)
    (id : CC.Ident) (block : CC.Block) (ty : CC.Ty)
    (bound : source.get id = some (block, ty)) (typed : sourceType ty = localType ty)
    (m : CC.Mem) (le : CC.TempEnv) :
    CC.doEvalLvalue world actual le m (expression (.Evar id ty)) =
      CC.doEvalLvalue Arm64Producer.ge source le m (.Evar id ty) := by
  simp only [expression, CC.doEvalLvalue, CC.lvalOfVar, related id, bound,
    Option.map_some, typed, ite_true]

/-- The same actual memory is read with the same access mode and chunk. A
failed read is retained as none; readable or initialized contents are not assumed. -/
theorem bound_read (source actual : CC.Env) (related : EnvsCorrespond source actual)
    (id : CC.Ident) (block : CC.Block) (ty : CC.Ty)
    (bound : source.get id = some (block, ty)) (typed : sourceType ty = localType ty)
    (m : CC.Mem) (le : CC.TempEnv) :
    CC.doEvalExpr world actual le m (expression (.Evar id ty)) =
      CC.doEvalExpr Arm64Producer.ge source le m (.Evar id ty) := by
  simp only [expression, CC.doEvalExpr, CC.lvalOfVar, related id, bound,
    Option.map_some, ← typed, ite_true, dereference_full]

theorem bound_address (source actual : CC.Env) (related : EnvsCorrespond source actual)
    (id : CC.Ident) (block : CC.Block) (ty : CC.Ty)
    (bound : source.get id = some (block, ty)) (typed : sourceType ty = localType ty)
    (m : CC.Mem) (le : CC.TempEnv) :
    CC.doEvalExpr world actual le m (expression (.Eaddrof (.Evar id ty) (CC.tptr ty))) =
      CC.doEvalExpr Arm64Producer.ge source le m (.Eaddrof (.Evar id ty) (CC.tptr ty)) := by
  simp only [expression, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
    related id, bound, Option.map_some, typed, ite_true]

/-- Every real local obtains its address, read and address-of correspondence
from actual allocation, for arbitrary subsequent memory and temporaries. -/
theorem allocated_local (initial m : CC.Mem) (le : CC.TempEnv) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars) :
    CC.doEvalLvalue world (Arm64ProgramEntryAllocation.allocation initial).1 le m
        (expression (.Evar id ty)) =
      CC.doEvalLvalue Arm64Producer.ge (Arm64Producer.allocation initial).1 le m (.Evar id ty) ∧
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 le m
        (expression (.Evar id ty)) =
      CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1 le m (.Evar id ty) ∧
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 le m
        (expression (.Eaddrof (.Evar id ty) (CC.tptr ty))) =
      CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1 le m
        (.Eaddrof (.Evar id ty) (CC.tptr ty)) := by
  obtain ⟨block, bound, _, _, _⟩ := Arm64Producer.local_storage initial id ty present
  have related := (Arm64ProgramEntryAllocation.allocation_corresponds initial).2
  have typed := declaration_type (id, ty) present
  exact ⟨bound_lvalue _ _ related id block ty bound typed m le,
    bound_read _ _ related id block ty bound typed m le,
    bound_address _ _ related id block ty bound typed m le⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryExpressions
