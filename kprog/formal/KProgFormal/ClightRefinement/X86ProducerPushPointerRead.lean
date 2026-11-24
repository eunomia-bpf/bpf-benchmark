import KProgFormal.ClightRefinement.X86ProducerPushRspAddress

namespace KProgFormal.ClightRefinement.X86ProducerPushPointerRead
open X86ProducerLayout (ge)
open X86ProducerPushRspAddress (pointer unionValue)

/-- A real pointer-typed union read may carry any scalar64-bit word. The
address is the accepted original GPR4 address; no raw-zero substitution is used. -/
theorem scalar (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (cells : CC.Block)
    (temporary : CC.Ident) (word : BitVec 64)
    (read : le.get temporary = some (.Vptr cells 0))
    (current : CC.Mem.load CC.Mptr memory cells 64 = some (.Vlong word)) :
    CC.doEvalExpr ge e le memory (pointer temporary) = some (.Vlong word) := by
  have address := X86ProducerPushRspAddress.pointer_address e le memory cells temporary read
  rw [pointer, CC.doEvalLvalue] at address
  rw [pointer, CC.doEvalExpr]
  cases lookup : CC.doEvalExpr ge e le memory (unionValue temporary) with
  | none => simp [lookup] at address
  | some value =>
    simp only [lookup] at address ⊢
    rw [address]
    exact current

end KProgFormal.ClightRefinement.X86ProducerPushPointerRead
