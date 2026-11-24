import KProgFormal.ClightRefinement.X86QwordDestinationScalar
import KProgFormal.ClightRefinement.X86QwordSource

namespace KProgFormal.ClightRefinement.X86QwordWriterSelectors

private theorem ordinary_code : ∀ index : Fin 16, index ≠ 4 →
    (X86RegisterReadValue.registerByte index).setWidth 32 ≠ (4#32) := by decide +kernel

def destinationTemps (le : CC.TempEnv) (index : Fin 16) : CC.TempEnv :=
  X86QwordDestinationScalar.temps
    ((X86QwordDestination.temps
      ((X86QwordSelection.temps (X86ShiftWriteback.selectTemps le
        (X86RegisterReadValue.registerByte index) .q)).set
          X86_program_profile_bpf._t'132 (X86Width.argument (0#8)))).set
        X86_program_profile_bpf._t'135 (X86Width.argument (0#8)))

def temps (le : CC.TempEnv) (index : Fin 16) : CC.TempEnv :=
  X86QwordSource.temps (destinationTemps le index)

def inputs : List CC.Ident := [X86_program_profile_bpf.___x86_bind, X86_program_profile_bpf._dst,
  X86_program_profile_bpf.___x86_l_alu, X86_program_profile_bpf.___x86_l_width__1,
  X86_program_profile_bpf.___x86_l_result, X86_program_profile_bpf.___x86_l_dst_shift,
  X86_program_profile_bpf.___x86_l_src_shift]

/-- Each actual input survives the complete destination selector, including
source shift, result, binding, destination, operation and effective width. -/
theorem destination_get (le : CC.TempEnv) (index : Fin 16) (id : CC.Ident)
    (input : id ∈ inputs) : (destinationTemps le index).get id = le.get id := by
  simp [inputs] at input
  rcases input with rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [destinationTemps, X86QwordDestinationScalar.temps,
    X86QwordDestination.temps, X86QwordSelection.temps, X86ShiftWriteback.selectTemps, CC.PTree.gso]

/-- The exact same input observations survive all three actual selectors. -/
theorem get (le : CC.TempEnv) (index : Fin 16) (id : CC.Ident)
    (input : id ∈ inputs) : (temps le index).get id = le.get id := by
  rw [← destination_get le index id input]
  simp [inputs] at input
  rcases input with rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals simp +decide [temps, X86QwordSource.temps, CC.PTree.gso]

/-- Original stack, destination-pointer and source-pointer selectors compose
in109 real Clight transitions for an ordinary scalar-tag qword destination.
Both actual destination tag calls occur; the non-ADD source arm short-circuits.
Every byte, binding and input field is retained for the default writer. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (index : Fin 16) (code : BitVec 32) (ordinary : index ≠ 4)
    (bindingBlock cellsBlock helperBlock : CC.Block) (base : CC.Integers.Ptrofs)
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (scalarCode : code ≠ (0#32) ∧ code ≠ (1#32))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none)
    (cells : CC.Mem.load CC.Mptr memory bindingBlock 0 = some (.Vptr cellsBlock base))
    (current : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument (0#8))) :
    InternalRun ge 109 (.State function X86ShiftWriteback.writer k e le memory)
      (.State function X86ShiftWriteback.defaultWriter k e (temps le index) memory) := by
  have selected := X86ShiftWriteback.select_scalar ge function e le k memory
    (X86RegisterReadValue.registerByte index) .q destination width operation scalarCode
  have length : X86ShiftWriteback.selectLength (X86RegisterReadValue.registerByte index) .q = 9 := by
    simp [X86ShiftWriteback.selectLength, X86ShiftWriteback.stackWidth, X86.Size.bytes,
      ordinary_code index ordinary]
  rw [length] at selected
  let ready := X86ShiftWriteback.selectTemps le (X86RegisterReadValue.registerByte index) .q
  have destinationRun := X86QwordDestinationScalar.execute ge layout function e ready k memory index
    bindingBlock cellsBlock helperBlock 0 base
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, width])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, dstShift])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, srcShift])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, destination])
    (by simp +decide [ready, X86ShiftWriteback.selectTemps, CC.PTree.gso, binding])
    helper unshadowed cells current
  have sourceRun := X86QwordSource.execute ge function e (destinationTemps le index) k memory code
    ((destination_get le index _ (by decide +kernel)).trans width)
    ((destination_get le index _ (by decide +kernel)).trans dstShift)
    ((destination_get le index _ (by decide +kernel)).trans srcShift)
    ((destination_get le index _ (by decide +kernel)).trans operation) scalarCode.1
  exact (selected.trans destinationRun).trans sourceRun

end KProgFormal.ClightRefinement.X86QwordWriterSelectors
