import KProgFormal.GeneratedArm64MemDispatch
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64MemDispatch (Space ValueSrc ResultTag)

/-- Independent statement of the value source, stated as a *nesting of
predicates* over the (space, width64) pair rather than as an exhaustive table.
It is the shape the C `if/else` chain has: stack first, then each width-64-only
space, then the ordinary load. -/
def arm64MemSrcSpec (space : Space) (w64 : Bool) : ValueSrc :=
  if space = .stack then .stackRead
  else if w64 && space = .abi then .abiPtrLoad
  else if w64 && space = .reloc then .relocPtr
  else .normalLoad

/-- Independent statement of the result tag in the same predicate-nesting
shape. -/
def arm64MemTagSpec (space : Space) (w64 : Bool) : ResultTag :=
  if space = .stack then .stackTag
  else if w64 && space = .abi then .abiTag
  else if w64 && space = .reloc then .mapPtr
  else .scalar

/-- The generated value-source table equals the independent predicate nesting
for all four spaces and both width cases. -/
theorem arm64_mem_dispatch_src_refines (space : Space) (w64 : Bool) :
    GeneratedArm64MemDispatch.valueSrc space w64 =
      arm64MemSrcSpec space w64 := by
  cases space <;> cases w64 <;>
    rfl

/-- The generated result-tag table equals the independent predicate nesting for
all four spaces and both width cases. -/
theorem arm64_mem_dispatch_tag_refines (space : Space) (w64 : Bool) :
    GeneratedArm64MemDispatch.valueTag space w64 =
      arm64MemTagSpec space w64 := by
  cases space <;> cases w64 <;>
    rfl

/-- **The two classifications agree on their arity**: exactly the stack space and
the two width-64-only spaces (ABI, reloc) can change the selected source and tag
away from the ordinary-load / scalar defaults. This is the property the C chain
relies on — after the stack test, each later branch must be width-64-gated. -/
theorem arm64_mem_dispatch_no_widening (space : Space) :
    arm64MemSrcSpec space false =
        (if space = .stack then ValueSrc.stackRead
         else ValueSrc.normalLoad) ∧
    arm64MemTagSpec space false =
        (if space = .stack then ResultTag.stackTag
         else ResultTag.scalar) := by
  cases space <;> refine ⟨rfl, rfl⟩

/-- The stack space is width-independent: a stack base selects the stack source
and tag at both widths. -/
theorem arm64_mem_dispatch_stack_width_independent :
    arm64MemSrcSpec .stack true = ValueSrc.stackRead ∧
    arm64MemSrcSpec .stack false = ValueSrc.stackRead ∧
    arm64MemTagSpec .stack true = ResultTag.stackTag ∧
    arm64MemTagSpec .stack false = ResultTag.stackTag := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- A reloc base at width 64 selects the reloc pointer source and the map-pointer
tag; off width 64 it behaves like an ordinary load. -/
theorem arm64_mem_dispatch_reloc :
    arm64MemSrcSpec .reloc true = ValueSrc.relocPtr ∧
    arm64MemSrcSpec .reloc false = ValueSrc.normalLoad ∧
    arm64MemTagSpec .reloc true = ResultTag.mapPtr ∧
    arm64MemTagSpec .reloc false = ResultTag.scalar := by
  refine ⟨rfl, rfl, rfl, rfl⟩

end KProgFormal
