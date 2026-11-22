import KProgFormal.Clight.Arm64Program
set_option Elab.async false
private theorem local_numbers :
    ((CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0).map CC.Positive.toNat).Nodup := by
  decide +kernel
#print axioms local_numbers
