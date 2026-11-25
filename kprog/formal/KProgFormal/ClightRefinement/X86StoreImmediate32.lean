import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile

namespace KProgFormal.ClightRefinement.X86StoreImmediate32

/-- Complete original C immediate helper on the actual SUB imm32/width8
arguments. It includes the real sign-bit guard and low32 cast; no result or
source-run premise is added, and the whole arbitrary heap is unchanged. -/
theorem internal (ge : CC.CGenv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 10
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_store_imm_value)
        [.Vlong (32#64),.Vint (8#32)] k memory)
      (.Returnstate (.Vlong (32#64)) (CC.callCont k) memory) := by
  apply internalRun_of_steps
  · repeat constructor
  · rfl

end KProgFormal.ClightRefinement.X86StoreImmediate32
