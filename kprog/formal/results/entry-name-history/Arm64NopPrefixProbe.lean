import KProgFormal.Clight.Arm64Program
set_option Elab.async false
private def lowBits : Nat → CC.Positive → Nat
  | 0, _ => 0
  | _ + 1, .xH => 1
  | n + 1, .xO p => 2 * lowBits n p
  | n + 1, .xI p => 2 * lowBits n p + 1
private theorem prefix_disjoint :
    CC.listDisjoint
      ((CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_params).map (lowBits 28))
      ((CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_0).map (lowBits 28)) := by
  dsimp only [Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel
#print axioms prefix_disjoint
