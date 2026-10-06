import KProgFormal.GeneratedX86MemDispatch

namespace KProgFormal

open GeneratedX86MemDispatch (ValueSrc)

/-- Independent statement of the x86 memory read dispatch, written as a
*nesting of predicates* over the three facts the C predicate consults rather
than as an exhaustive table. It is the shape the C `if/else` chain has: the
stack-pointer test first (register identity), then the ABI tag gated on width
64, then the ordinary load. -/
def x86MemReadSrcSpec (isRsp isAbi w64 : Bool) : ValueSrc :=
  if isRsp then .stackRead
  else if isAbi && w64 then .abiPtrLoad
  else .normalLoad

/-- The generated value-source table equals the independent predicate nesting
for all eight combinations of the three selector facts. -/
theorem x86_mem_dispatch_src_refines (isRsp isAbi w64 : Bool) :
    GeneratedX86MemDispatch.valueSrc isRsp isAbi w64 =
      x86MemReadSrcSpec isRsp isAbi w64 := by
  cases isRsp <;> cases isAbi <;> cases w64 <;> rfl

/-- The stack-pointer test comes first and is a test of register identity, not
of tag: an ABI-tagged stack pointer still selects the stack read, at either
width. This is the x86-specific asymmetry against the AArch64 dispatch, whose
first test is the memory tag. -/
theorem x86_mem_dispatch_stack_overrides_tag (isAbi w64 : Bool) :
    x86MemReadSrcSpec true isAbi w64 = ValueSrc.stackRead := by
  cases isAbi <;> cases w64 <;> rfl

/-- The ABI arm applies only at width 64. Off width 64 an ABI-tagged base falls
through to the ordinary load — there is no narrower pointer load, so no arch
state can make an ABI base reach `.abiPtrLoad` at another width. -/
theorem x86_mem_dispatch_abi_requires_width64 (isRsp : Bool) :
    x86MemReadSrcSpec isRsp true false =
        (if isRsp then ValueSrc.stackRead else ValueSrc.normalLoad) ∧
      x86MemReadSrcSpec false true true = ValueSrc.abiPtrLoad := by
  cases isRsp <;> refine ⟨rfl, rfl⟩

/-- Off width 64 the tag is irrelevant: only the register-identity stack test
can move the selection away from the ordinary load. This is the property the C
chain relies on — the ABI branch must be width-64-gated. -/
theorem x86_mem_dispatch_no_tag_widening (isRsp isAbi : Bool) :
    x86MemReadSrcSpec isRsp isAbi false =
      (if isRsp then ValueSrc.stackRead else ValueSrc.normalLoad) := by
  cases isRsp <;> cases isAbi <;> rfl

/-- Every arm of the contract is reachable: the table has no dead entry. -/
theorem x86_mem_dispatch_all_arms_reachable :
    x86MemReadSrcSpec true false false = ValueSrc.stackRead ∧
      x86MemReadSrcSpec false true true = ValueSrc.abiPtrLoad ∧
      x86MemReadSrcSpec false false false = ValueSrc.normalLoad := by
  refine ⟨rfl, rfl, rfl⟩

end KProgFormal
