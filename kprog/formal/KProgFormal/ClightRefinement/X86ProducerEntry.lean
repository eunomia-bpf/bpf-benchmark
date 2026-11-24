import KProgFormal.ClightRefinement.X86ProducerHeaderProgramSource

namespace KProgFormal.ClightRefinement.X86ProducerEntry
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)

def initialTemps (ctx : CC.Val) : CC.TempEnv :=
  (CC.createUndefTemps producer.fn_temps).set X86_program_profile_bpf._ctx ctx

private theorem names :
    CC.listNorepet (CC.varNames producer.fn_vars) ∧
    CC.listNorepet (CC.varNames producer.fn_params) ∧
    CC.listDisjoint (CC.varNames producer.fn_params) (CC.varNames producer.fn_temps) := by decide +kernel

/-- The real exported producer enters with its actual single context argument,
full original local allocation and original temporary declarations. -/
theorem entry_valid (ge : CC.CGenv) (before : CC.Mem) (ctx : CC.Val) :
    CC.FunctionEntry2 ge producer [ctx] before
      (allocation ge.genv_cenv before).1 (initialTemps ctx) (allocation ge.genv_cenv before).2 := by
  apply CC.FunctionEntry2.intro names.1 names.2.1 names.2.2
  · exact CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  · rfl

/-- The genuine function-entry transition reaches the complete original body,
retaining its entire input/setup prefix rather than starting at the header cut. -/
theorem entry_internal (ge : CC.CGenv) (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    InternalRun ge 1 (.Callstate (.Internal producer) [ctx] k before)
      (.State producer producer.fn_body k (allocation ge.genv_cenv before).1
        (initialTemps ctx) (allocation ge.genv_cenv before).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid ge before ctx)) (.refl _)

theorem entry_frame (ge : CC.CGenv) (before : CC.Mem) :
    FrameBelow before.nextblock before (allocation ge.genv_cenv before).2 := by
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  exact (FrameBelow.allocVariables allocated before.nextblock (Nat.le_refl _)).2

end KProgFormal.ClightRefinement.X86ProducerEntry
