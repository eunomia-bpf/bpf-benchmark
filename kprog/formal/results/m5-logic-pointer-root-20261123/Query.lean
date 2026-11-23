import KProgFormal


-- m5-x86-logic-alu

#check KProgFormal.ClightRefinement.X86LogicAlu.xor_internal
#print axioms KProgFormal.ClightRefinement.X86LogicAlu.xor_internal
#check KProgFormal.ClightRefinement.X86LogicAlu.or_internal
#print axioms KProgFormal.ClightRefinement.X86LogicAlu.or_internal
#check KProgFormal.ClightRefinement.X86LogicAlu.and_internal
#print axioms KProgFormal.ClightRefinement.X86LogicAlu.and_internal

-- m5-x86-reader-raw

#check KProgFormal.ClightRefinement.X86RegisterReadValue.read_raw
#print axioms KProgFormal.ClightRefinement.X86RegisterReadValue.read_raw
#check KProgFormal.ClightRefinement.X86RegisterReadValue.read_value
#print axioms KProgFormal.ClightRefinement.X86RegisterReadValue.read_value
#check KProgFormal.ClightRefinement.X86RegisterReadValue.from_call
#print axioms KProgFormal.ClightRefinement.X86RegisterReadValue.from_call
#check KProgFormal.ClightRefinement.X86RegisterReadScalar.call
#print axioms KProgFormal.ClightRefinement.X86RegisterReadScalar.call
#check KProgFormal.ClightRefinement.X86RegisterReadScalar.native_call
#print axioms KProgFormal.ClightRefinement.X86RegisterReadScalar.native_call
#check KProgFormal.ClightRefinement.X86AluXorOperandsEntry.from_call
#print axioms KProgFormal.ClightRefinement.X86AluXorOperandsEntry.from_call

-- m5-x86-pointer-call

#check KProgFormal.ClightRefinement.X86RegisterReadPointerCall.call
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerCall.call

-- m5-x86-logic-site

#check KProgFormal.ClightRefinement.X86ShiftLeftSite.call_and_resume
#print axioms KProgFormal.ClightRefinement.X86ShiftLeftSite.call_and_resume
#check KProgFormal.ClightRefinement.X86ShiftLeftRoute.select_arithmetic
#print axioms KProgFormal.ClightRefinement.X86ShiftLeftRoute.select_arithmetic
#check KProgFormal.ClightRefinement.X86ShiftLeftRoute.select
#print axioms KProgFormal.ClightRefinement.X86ShiftLeftRoute.select
#check KProgFormal.ClightRefinement.X86ShiftLeftRoute.to_flags
#print axioms KProgFormal.ClightRefinement.X86ShiftLeftRoute.to_flags
#check KProgFormal.ClightRefinement.X86LogicSite.internal
#print axioms KProgFormal.ClightRefinement.X86LogicSite.internal
#check KProgFormal.ClightRefinement.X86LogicSite.to_flags
#print axioms KProgFormal.ClightRefinement.X86LogicSite.to_flags
#check KProgFormal.ClightRefinement.X86LogicSite.xor_to_flags
#print axioms KProgFormal.ClightRefinement.X86LogicSite.xor_to_flags
#check KProgFormal.ClightRefinement.X86LogicSite.or_to_flags
#print axioms KProgFormal.ClightRefinement.X86LogicSite.or_to_flags
#check KProgFormal.ClightRefinement.X86LogicSite.and_to_flags
#print axioms KProgFormal.ClightRefinement.X86LogicSite.and_to_flags
