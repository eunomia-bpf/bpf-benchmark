import KProgFormal.ClightRefinement.X86ProducerAbiLayout

namespace KProgFormal.ClightRefinement.X86ProducerAbiAddress
open X86ProducerAbiSource X86ProducerAbiLayout
open X86ProducerLayout (ge)

private theorem field_address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (block : CC.Block) (g : Fin 6)
    (bound : e.get X86_program_profile_bpf.___x86_sim_abi = some (block, abiType)) :
    CC.doEvalLvalue ge e le memory (field g) = some (block, CC.Integers.Ptrofs.repr (base g), .Full) := by
  simp only [field, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, bound,
    abiType, CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof,
    source_layout.1, field_offset ge.genv_cenv g]
  change some (block, (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (base g), CC.Bitfield.Full) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (block, ofs, CC.Bitfield.Full))
    (BitVec.zero_add (CC.Integers.Ptrofs.repr (base g)))

private theorem array_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (block : CC.Block) (g : Fin 6) (array : ¬ (g.val = 3 ∨ g.val = 5))
    (bound : e.get X86_program_profile_bpf.___x86_sim_abi = some (block, abiType)) :
    CC.doEvalExpr ge e le memory (field g) = some (.Vptr block (CC.Integers.Ptrofs.repr (base g))) := by
  have localExpr : CC.doEvalExpr ge e le memory (.Evar X86_program_profile_bpf.___x86_sim_abi abiType) = some (.Vptr block 0) := by
    simp only [CC.doEvalExpr, CC.lvalOfVar, bound, abiType, CC.doDerefLoc, CC.accessMode]
    rfl
  rw [field, CC.doEvalExpr, localExpr]
  simp only [CC.typeof, CC.lvalOfField, abiType, source_layout.1,
    field_offset ge.genv_cenv g, fieldType, array, ite_false,
    CC.doDerefLoc, CC.accessMode, CC.tarray]
  change some (CC.Val.Vptr block ((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (base g))) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (CC.Val.Vptr block ofs))
    (BitVec.zero_add (CC.Integers.Ptrofs.repr (base g)))

private theorem normalized_offset : ∀ i : Fin 187,
    ¬ ((group i).val = 3 ∨ (group i).val = 5) →
    CC.Integers.Ptrofs.repr (base (group i)) +
      CC.Integers.Ptrofs.repr (if (group i).val = 1 then 4 else 1) *
        CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr (index i)) =
      CC.Integers.Ptrofs.repr (offset i) := by decide +kernel

/-- Actual typed array indexing or direct-field addressing constructs every
ABI initializer destination from its original source declaration. -/
theorem target_address (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (block : CC.Block) (i : Fin 187)
    (bound : e.get X86_program_profile_bpf.___x86_sim_abi = some (block, abiType)) :
    CC.doEvalLvalue ge e le memory (target i) = some (block, CC.Integers.Ptrofs.repr (offset i), .Full) := by
  by_cases pointer : (group i).val = 3 ∨ (group i).val = 5
  · simp only [target, pointer, ite_true]
    have address := field_address e le memory block (group i) bound
    simpa only [offset, pointer, ite_true, Int.add_zero] using address
  · have array := array_value e le memory block (group i) pointer bound
    rw [target, ite_eq_right pointer, CC.doEvalLvalue, CC.doEvalExpr, array]
    by_cases word : (group i).val = 1
    all_goals simp only [CC.doEvalExpr, CC.typeof, field, fieldType, pointer, ite_false,
      element, word, ite_true, CC.Cop.semBinaryOperation, CC.Cop.semAdd,
      CC.Cop.classifyAdd, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
      CC.sizeof, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tarray, CC.tptr, CC.tuchar, CC.tuint, CC.tint, CC.noattr]
    all_goals
      have calculation := normalized_offset i pointer
      simp only [word, ite_true, ite_false] at calculation
      exact congrArg (fun ofs : CC.Integers.Ptrofs => some (block, ofs, CC.Bitfield.Full)) calculation

end KProgFormal.ClightRefinement.X86ProducerAbiAddress
