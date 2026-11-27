import KProgFormal

namespace KProgFormal.ClightRefinement.Arm64Producer

example : ∀ (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (tag temporary : CC.Ident) (i : Fin 64) (rest : CC.Stmt) (m supplied after : CC.Mem)
    (localVector : VectorLocal m) (shape : VectorLayout world tag)
    (actualBinding : e.get Arm64Entry.___a64_vectors = some (localVector.block, vectorArrayTypeFor tag))
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (stored : CC.Mem.storev .Mint64 supplied (.Vptr localVector.block (vectorPointerOffset i))
      (.Vlong value) = some after),
    InternalRun world 4
      (.Returnstate (.Vlong value) (vectorContinuationFor f e tag temporary i rest le k) supplied)
      (.State f rest k e (le.set temporary (.Vlong value)) after) := vector_return_body

end KProgFormal.ClightRefinement.Arm64Producer
