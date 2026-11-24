import KProgFormal.ClightRefinement.X86ProducerAbiSource

namespace KProgFormal.ClightRefinement.X86ProducerAbiLayout
open X86ProducerAbiSource
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private def close_source_equality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected original ABI layout equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

def abiRecord : CC.Composite := by
  run_tac do
    let lookup ← Lean.Elab.Term.elabTerm (← `(ge.genv_cenv.get X86_program_profile_bpf._x86_sim_skb_abi)) none
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf lookup)
    unless result.isAppOfArity ``Option.some 2 do throwError "original ABI struct missing"
    Lean.Elab.Tactic.closeMainGoal `original_x86_abi_record result.getAppArgs[1]!

private def members : List CC.Member := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(abiRecord.co_members)) (some (← Lean.Elab.Tactic.getMainTarget))
    Lean.Elab.Tactic.closeMainGoal `original_x86_abi_members
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

theorem source_layout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_skb_abi = some abiRecord ∧
    CC.sizeof ge.genv_cenv abiType = 216 := by
  refine ⟨?_, ?_⟩ <;> run_tac close_source_equality

/-- All six field offsets are computed from the actual ABI member declaration. -/
theorem field_offset (ce : CC.CompositeEnv) (g : Fin 6) :
    CC.fieldOffset ce (fieldName g) abiRecord.co_members = .OK (base g, .Full) := by
  have cases : ∀ g : Fin 6, g = 0 ∨ g = 1 ∨ g = 2 ∨ g = 3 ∨ g = 4 ∨ g = 5 := by decide +kernel
  change CC.fieldOffset ce (fieldName g) members = _
  rcases cases g with rfl | rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [fieldName, base, members, CC.fieldOffset, CC.fieldOffsetRec,
    CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
    CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
    CC.tptr, CC.tarray, CC.tuchar, CC.tuint, CC.noattr]

/-- The original ABI object has a distinct fresh block and complete Freeable
rights from the same actual producer allocation. -/
theorem abi_local (before : CC.Mem) : Nonempty (Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi abiType) := by
  have names : CC.listNorepet (CC.varNames producer.fn_vars) := by decide +kernel
  have present : (X86_program_profile_bpf.___x86_sim_abi, abiType) ∈ producer.fn_vars := by decide +kernel
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  obtain ⟨block, binding⟩ := allocated_local_binding allocated names present
  obtain ⟨fresh, owned, range⟩ := (allocated_local_storage allocated).1 _ _ binding
  exact ⟨⟨block, binding, fresh, owned, range⟩⟩

end KProgFormal.ClightRefinement.X86ProducerAbiLayout
