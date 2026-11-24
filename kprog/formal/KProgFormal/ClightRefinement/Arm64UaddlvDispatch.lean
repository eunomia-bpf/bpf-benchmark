import KProgFormal.ClightRefinement.Arm64CntDispatch
import KProgFormal.ClightRefinement.Arm64UaddlvPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.Dispatch

abbrev continuation := Arm64Cnt.Dispatch.continuation
abbrev body_source := Arm64Cnt.Dispatch.body_source

/-- The original shared source cache and linked width call reach the same
actual reduction branch with opcode37; all nine caller inputs are retained. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (op : le.get Arm64Program._op = some (.Vint (37#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler Path.statement (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (8#32)) ∧
      ∀ id ∈ Path.inputs, le'.get id = le.get id := by
  exact Arm64Cnt.Dispatch.body_dispatch_uaddlv e le m k unshadowed flags op

end KProgFormal.ClightRefinement.Arm64Uaddlv.Dispatch
