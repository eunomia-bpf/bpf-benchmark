import KProgFormal.ClightRefinement.X86ProducerHeaderLocals

namespace KProgFormal.ClightRefinement.X86ProducerHeaderRhs
open X86ProducerHeaderSource X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

/-- Every actual initializer RHS evaluates to the address of the corresponding
allocated source object. The first row uses the real GPR-union array field. -/
theorem rhs_pointer (ge : CC.CGenv) (before memory : CC.Mem) (le : CC.TempEnv)
    (i : Fin 24) (source : SourceLocal ge.genv_cenv before i)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members =
      .OK (0, .Full)) :
    CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory (rhs i) = some (.Vptr source.block 0) := by
  by_cases first : i = 0
  · subst i
    have bound := source.binding
    change (allocation ge.genv_cenv before).1.get X86_program_profile_bpf.___x86_local_gprs =
      some (source.block, CC.Ty.Tunion X86_program_profile_bpf._x86_sim_register_cells CC.noattr) at bound
    change CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory
      (.Efield (.Evar X86_program_profile_bpf.___x86_local_gprs
        (.Tunion X86_program_profile_bpf._x86_sim_register_cells CC.noattr))
        X86_program_profile_bpf._gpr_cells
        (CC.tarray (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) 16)) = _
    have localExpr : CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory
        (.Evar X86_program_profile_bpf.___x86_local_gprs
          (.Tunion X86_program_profile_bpf._x86_sim_register_cells CC.noattr)) = some (.Vptr source.block 0) := by
      simp only [CC.doEvalExpr, CC.lvalOfVar, bound, CC.doDerefLoc, CC.accessMode]
      rfl
    rw [CC.doEvalExpr, localExpr]
    simp only [CC.typeof, CC.lvalOfField, registersLayout, cellsOffset,
      CC.doDerefLoc, CC.accessMode, CC.tarray]
    rfl
  · have nonzero : i.val ≠ 0 := fun equal => first (Fin.ext equal)
    simp only [rhs, nonzero, ite_false, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, source.binding]
    rfl

private theorem target_type (i : Fin 24) : CC.typeof (target i) = pointerType i := by
  unfold target
  split <;> rfl

/-- The actual array decay/address-of sources and destination pointer types
select the imported pointer-cast case and preserve the exact source address. -/
theorem cast_pointer (before : CC.Mem) (i : Fin 24) (block : CC.Block) :
    CC.Cop.semCast (.Vptr block 0) (CC.typeof (rhs i)) (CC.typeof (target i)) before =
      some (.Vptr block 0) := by
  rw [target_type]
  by_cases first : i.val = 0
  · have index : i = 0 := Fin.ext first
    subst i
    rfl
  · simp only [rhs, first, ite_false, CC.typeof, pointerType, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.tptr]

end KProgFormal.ClightRefinement.X86ProducerHeaderRhs
