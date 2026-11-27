import KProgFormal.ClightRefinement.Arm64ProducerRegisters
open KProgFormal.ClightRefinement
open Arm64Producer

example (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (m supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (writes : DeclarationStores d m supplied value)
    (wordBinding : e.get d.word = some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (writes.tagBlock, CC.tuchar)) :
    steps world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) =
      some (CC.E0, .State f d.rest k e (d.temps le value) writes.after) ∧
    InternalPath world 9 (.Returnstate (.Vlong value) (.Kcall (some d.inputTemp) f e le
      (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))) supplied) := by
  exact declaration_return_body world f e gpr d m supplied le k value writes wordBinding tagBinding

example (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (gpr : GprLayout world) (d : RegisterDeclaration) (m before : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (same : CC.Integers.Int.eq d.index (30#32) = true)
    (writes : DeclarationStores d m before (0#64))
    (wordBinding : e.get d.word = some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    (tagBinding : e.get d.tag = some (writes.tagBlock, CC.tuchar)) :
    steps world 10 (.State f d.body k e le before) =
      some (CC.E0, .State f d.rest k e
        (le.set d.resultTemp (.Vlong (0#64))) writes.after) ∧
    InternalPath world 10 (.State f d.body k e le before) := by
  exact declaration_zero_body world f e gpr d m before le k same writes wordBinding tagBinding
