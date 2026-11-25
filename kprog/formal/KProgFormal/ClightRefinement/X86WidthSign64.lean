import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Clight.X86ProgramProfile

namespace KProgFormal.ClightRefinement.X86WidthSign64

/-- All original source sign-mask helper comparisons and casts on actual
width8 return the qword sign bit. Arbitrary heap and continuation are
preserved; no numerical result or helper execution premise is supplied. -/
theorem internal (ge : CC.CGenv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 14
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_sign_mask) [.Vint (8#32)] k memory)
      (.Returnstate (.Vlong (0x8000000000000000#64)) (CC.callCont k) memory) := by
  apply internalRun_of_steps
  · repeat constructor
  · rfl

end KProgFormal.ClightRefinement.X86WidthSign64
