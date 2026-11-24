import KProgFormal.ClightRefinement.X86ProducerPushRspSource
import KProgFormal.ClightRefinement.X86ProducerPushRspStore

namespace KProgFormal.ClightRefinement.X86ProducerPushRspValue
open X86ProducerLayout (ge)

def raw : CC.Expr := .Etempvar X86_program_profile_bpf._t'230 (CC.tptr CC.tvoid)
def step : CC.Expr := .Etempvar X86_program_profile_bpf.___x86_l_pp_step CC.tulong
def expression : CC.Expr := .Ecast (.Ecast (.Ebinop .Oadd
  (.Ecast (.Ecast raw CC.tulong) CC.tulong)
  (.Ecast (.Eunop .Oneg step CC.tulong) CC.tulong) CC.tulong) CC.tulong) (CC.tptr CC.tuchar)

theorem source : X86ProducerPushRspSource.rhs = expression := rfl

/-- The real pointer-typed union word goes through its genuine integer and
pointer casts. The unsigned subtraction wraps at64 bits, exactly as C. -/
theorem evaluate (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (current : le.get X86_program_profile_bpf._t'230 = some (.Vlong 0))
    (eight : le.get X86_program_profile_bpf.___x86_l_pp_step = some (.Vlong (8#64))) :
    CC.doEvalExpr ge e le memory X86ProducerPushRspSource.rhs = some (.Vlong X86ProducerPushRspStore.nextRsp) ∧
    CC.Cop.semCast (.Vlong X86ProducerPushRspStore.nextRsp) (CC.typeof X86ProducerPushRspSource.rhs)
      (CC.typeof X86ProducerPushRspSource.target) memory = some (.Vlong X86ProducerPushRspStore.nextRsp) := by
  constructor
  · rw [source]
    simp only [expression, raw, step, CC.doEvalExpr, current, eight]
    rfl
  · rfl

end KProgFormal.ClightRefinement.X86ProducerPushRspValue
