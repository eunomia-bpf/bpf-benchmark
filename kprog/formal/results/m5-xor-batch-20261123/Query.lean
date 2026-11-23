import KProgFormal


-- m5-x86-xor-selection

#check KProgFormal.ClightRefinement.X86AluReadXorSelect.different_registers
#print axioms KProgFormal.ClightRefinement.X86AluReadXorSelect.different_registers
#check KProgFormal.ClightRefinement.X86AluReadXorSelect.different_lanes
#print axioms KProgFormal.ClightRefinement.X86AluReadXorSelect.different_lanes
#check KProgFormal.ClightRefinement.X86AluReadXorSelect.all_cases
#print axioms KProgFormal.ClightRefinement.X86AluReadXorSelect.all_cases

-- m5-x86-read-tail

#check KProgFormal.ClightRefinement.X86AluReadTail.read
#print axioms KProgFormal.ClightRefinement.X86AluReadTail.read
#check KProgFormal.ClightRefinement.X86AluReadOperands.read
#print axioms KProgFormal.ClightRefinement.X86AluReadOperands.read
#check KProgFormal.ClightRefinement.X86AluReadOperands.observations
#print axioms KProgFormal.ClightRefinement.X86AluReadOperands.observations
#check KProgFormal.ClightRefinement.X86AluOperandsEntry.from_call
#print axioms KProgFormal.ClightRefinement.X86AluOperandsEntry.from_call

-- m5-x86-xor-operands

#check KProgFormal.ClightRefinement.X86AluReadXorOperands.read
#print axioms KProgFormal.ClightRefinement.X86AluReadXorOperands.read

-- m5-x86-xor-entry

#check KProgFormal.ClightRefinement.X86AluXorOperandsEntry.from_call
#print axioms KProgFormal.ClightRefinement.X86AluXorOperandsEntry.from_call

-- m5-x86-pointer-boundary

#check KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.source
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.source
#check KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.qword_prefix
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.qword_prefix
#check KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_assignment
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_assignment
#check KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_no_step
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_no_step
#check KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_boundary
#print axioms KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary.pointer_boundary
