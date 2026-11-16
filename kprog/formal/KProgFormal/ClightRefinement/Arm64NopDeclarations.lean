import KProgFormal.Clight.Arm64Program

-- Check declaration facts sequentially within the lane's memory bound.
set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NopDeclarations

/-- Name metadata from the actual export. Individual chunk facts keep the
kernel checks within default resource limits; no native evaluation is used. -/
private def params := Arm64Program.f_kprog_arm64_program_execute.fn_params

private theorem disjoint_append (a b c : List CC.Ident) :
    CC.listDisjoint a (b ++ c) ↔ CC.listDisjoint a b ∧ CC.listDisjoint a c := by
  simp only [CC.listDisjoint, List.mem_append, not_or]
  constructor
  · intro h
    exact ⟨fun id hi => (h id hi).1, fun id hi => (h id hi).2⟩
  · intro h id hi
    exact ⟨h.1 id hi, h.2 id hi⟩

/-- Finite Boolean computations are reflected through the standard list
library, retaining the original identifier equality in the conclusion. -/
private theorem disjoint_of_all (a b : List CC.Ident)
    (h : a.all (fun x => b.all (fun y => decide (x ≠ y))) = true) :
    CC.listDisjoint a b := by
  intro x hx hy
  have hxx : decide (x ≠ x) = true :=
    List.all_eq_true.mp (List.all_eq_true.mp h x hx) x hy
  exact (of_decide_eq_true hxx) rfl

private theorem distinct_of_all (a b : List CC.Ident)
    (h : a.all (fun x => b.all (fun y => decide (x ≠ y))) = true) :
    ∀ x ∈ a, ∀ y ∈ b, x ≠ y := by
  intro x hx y hy
  exact of_decide_eq_true (List.all_eq_true.mp (List.all_eq_true.mp h x hx) y hy)

private theorem nodup_of_numbers (a : List CC.Ident)
    (h : (a.map CC.Positive.toNat).Nodup) : a.Nodup :=
  List.Pairwise.of_map CC.Positive.toNat
    (fun _ _ hne heq => hne (congrArg CC.Positive.toNat heq)) h

private theorem vars_0_norepet : (CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0).Nodup := by
  apply nodup_of_numbers
  decide +kernel

private theorem vars_1_norepet : (CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_1).Nodup := by
  apply nodup_of_numbers
  decide +kernel

private theorem vars_2_norepet : (CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_2).Nodup := by
  apply nodup_of_numbers
  decide +kernel

private theorem vars_3_norepet : (CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_3).Nodup := by
  apply nodup_of_numbers
  decide +kernel

private theorem vars_0_1_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_1, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem vars_0_2_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_2, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem vars_0_3_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_3, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem vars_1_2_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_1, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_2, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem vars_1_3_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_1, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_3, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem vars_2_3_distinct :
    ∀ a ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_2, ∀ b ∈ CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_3, a ≠ b := by
  apply distinct_of_all
  decide +kernel

private theorem nodup_four (a b c d : List CC.Ident)
    (ha : a.Nodup) (hb : b.Nodup) (hc : c.Nodup) (hd : d.Nodup)
    (hab : ∀ x ∈ a, ∀ y ∈ b, x ≠ y)
    (hac : ∀ x ∈ a, ∀ y ∈ c, x ≠ y)
    (had : ∀ x ∈ a, ∀ y ∈ d, x ≠ y)
    (hbc : ∀ x ∈ b, ∀ y ∈ c, x ≠ y)
    (hbd : ∀ x ∈ b, ∀ y ∈ d, x ≠ y)
    (hcd : ∀ x ∈ c, ∀ y ∈ d, x ≠ y) :
    ((a ++ b) ++ (c ++ d)).Nodup := by
  apply List.nodup_append.mpr
  refine ⟨List.nodup_append.mpr ⟨ha, hb, hab⟩,
    List.nodup_append.mpr ⟨hc, hd, hcd⟩, ?_⟩
  intro x hx y hy
  rcases List.mem_append.mp hx with hx | hx
  · rcases List.mem_append.mp hy with hy | hy
    · exact hac x hx y hy
    · exact had x hx y hy
  · rcases List.mem_append.mp hy with hy | hy
    · exact hbc x hx y hy
    · exact hbd x hx y hy

theorem vars_norepet : CC.listNorepet
    (CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_vars) := by
  dsimp only [Arm64Program.f_kprog_arm64_program_execute]
  simp only [CC.listNorepet, CC.varNames, List.map_append]
  exact nodup_four _ _ _ _ vars_0_norepet vars_1_norepet vars_2_norepet vars_3_norepet
    vars_0_1_distinct vars_0_2_distinct vars_0_3_distinct
    vars_1_2_distinct vars_1_3_distinct vars_2_3_distinct

theorem params_norepet : CC.listNorepet
    (CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_params) := by
  dsimp only [Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_0_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_0) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_1_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_1) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_2_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_2) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_3_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_3) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_4_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_4) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_5_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_5) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_6_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_6) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_7_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_7) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_8_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_8) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_9_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_9) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_10_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_10) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_11_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_11) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_12_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_12) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_13_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_13) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_14_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_14) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_15_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_15) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_16_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_16) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_17_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_17) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_18_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_18) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_19_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_19) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_20_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_20) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_21_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_21) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_22_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_22) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_23_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_23) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_24_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_24) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_25_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_25) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_26_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_26) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_27_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_27) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_28_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_28) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_29_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_29) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_30_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_30) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_31_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_31) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_32_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_32) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_33_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_33) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_34_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_34) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_35_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_35) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_36_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_36) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_37_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_37) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_38_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_38) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_39_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_39) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_40_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_40) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_41_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_41) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_42_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_42) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_43_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_43) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_44_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_44) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_45_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_45) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_46_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_46) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_47_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_47) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_48_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_48) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_49_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_49) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_50_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_50) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_51_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_51) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_52_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_52) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_53_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_53) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_54_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_54) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_55_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_55) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_56_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_56) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_57_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_57) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_58_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_58) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_59_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_59) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_60_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_60) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_61_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_61) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_62_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_62) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_63_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_63) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_64_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_64) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_65_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_65) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_66_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_66) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_67_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_67) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_68_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_68) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_69_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_69) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_70_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_70) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_71_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_71) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_72_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_72) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_73_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_73) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_74_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_74) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_75_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_75) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_76_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_76) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_77_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_77) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_78_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_78) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_79_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_79) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_80_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_80) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_81_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_81) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_82_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_82) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_83_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_83) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_84_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_84) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_85_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_85) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_86_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_86) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_87_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_87) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_88_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_88) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_89_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_89) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_90_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_90) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_91_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_91) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_92_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_92) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_93_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_93) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_94_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_94) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_95_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_95) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_96_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_96) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_97_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_97) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_98_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_98) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_99_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_99) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_100_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_100) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_101_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_101) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_102_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_102) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_103_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_103) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_104_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_104) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_105_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_105) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_106_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_106) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_107_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_107) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_108_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_108) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_109_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_109) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_110_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_110) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_111_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_111) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_112_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_112) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_113_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_113) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_114_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_114) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_115_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_115) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_116_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_116) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_117_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_117) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_118_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_118) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_119_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_119) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_120_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_120) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_121_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_121) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_122_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_122) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_123_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_123) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_124_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_124) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_125_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_125) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_126_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_126) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

private theorem temps_127_disjoint : CC.listDisjoint (CC.varNames params)
    (CC.varNames Arm64Program.l_kprog_arm64_program_execute_temps_127) := by
  apply disjoint_of_all
  dsimp only [params, Arm64Program.f_kprog_arm64_program_execute]
  decide +kernel

theorem params_temps_disjoint :
    CC.listDisjoint (CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_params)
      (CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_temps) := by
  dsimp only [Arm64Program.f_kprog_arm64_program_execute]
  simp only [CC.varNames, List.map_append, disjoint_append]
  exact ⟨⟨⟨⟨⟨⟨⟨temps_0_disjoint, temps_1_disjoint⟩, ⟨temps_2_disjoint, temps_3_disjoint⟩⟩, ⟨⟨temps_4_disjoint, temps_5_disjoint⟩, ⟨temps_6_disjoint, temps_7_disjoint⟩⟩⟩, ⟨⟨⟨temps_8_disjoint, temps_9_disjoint⟩, ⟨temps_10_disjoint, temps_11_disjoint⟩⟩, ⟨⟨temps_12_disjoint, temps_13_disjoint⟩, ⟨temps_14_disjoint, temps_15_disjoint⟩⟩⟩⟩, ⟨⟨⟨⟨temps_16_disjoint, temps_17_disjoint⟩, ⟨temps_18_disjoint, temps_19_disjoint⟩⟩, ⟨⟨temps_20_disjoint, temps_21_disjoint⟩, ⟨temps_22_disjoint, temps_23_disjoint⟩⟩⟩, ⟨⟨⟨temps_24_disjoint, temps_25_disjoint⟩, ⟨temps_26_disjoint, temps_27_disjoint⟩⟩, ⟨⟨temps_28_disjoint, temps_29_disjoint⟩, ⟨temps_30_disjoint, temps_31_disjoint⟩⟩⟩⟩⟩, ⟨⟨⟨⟨⟨temps_32_disjoint, temps_33_disjoint⟩, ⟨temps_34_disjoint, temps_35_disjoint⟩⟩, ⟨⟨temps_36_disjoint, temps_37_disjoint⟩, ⟨temps_38_disjoint, temps_39_disjoint⟩⟩⟩, ⟨⟨⟨temps_40_disjoint, temps_41_disjoint⟩, ⟨temps_42_disjoint, temps_43_disjoint⟩⟩, ⟨⟨temps_44_disjoint, temps_45_disjoint⟩, ⟨temps_46_disjoint, temps_47_disjoint⟩⟩⟩⟩, ⟨⟨⟨⟨temps_48_disjoint, temps_49_disjoint⟩, ⟨temps_50_disjoint, temps_51_disjoint⟩⟩, ⟨⟨temps_52_disjoint, temps_53_disjoint⟩, ⟨temps_54_disjoint, temps_55_disjoint⟩⟩⟩, ⟨⟨⟨temps_56_disjoint, temps_57_disjoint⟩, ⟨temps_58_disjoint, temps_59_disjoint⟩⟩, ⟨⟨temps_60_disjoint, temps_61_disjoint⟩, ⟨temps_62_disjoint, temps_63_disjoint⟩⟩⟩⟩⟩⟩, ⟨⟨⟨⟨⟨⟨temps_64_disjoint, temps_65_disjoint⟩, ⟨temps_66_disjoint, temps_67_disjoint⟩⟩, ⟨⟨temps_68_disjoint, temps_69_disjoint⟩, ⟨temps_70_disjoint, temps_71_disjoint⟩⟩⟩, ⟨⟨⟨temps_72_disjoint, temps_73_disjoint⟩, ⟨temps_74_disjoint, temps_75_disjoint⟩⟩, ⟨⟨temps_76_disjoint, temps_77_disjoint⟩, ⟨temps_78_disjoint, temps_79_disjoint⟩⟩⟩⟩, ⟨⟨⟨⟨temps_80_disjoint, temps_81_disjoint⟩, ⟨temps_82_disjoint, temps_83_disjoint⟩⟩, ⟨⟨temps_84_disjoint, temps_85_disjoint⟩, ⟨temps_86_disjoint, temps_87_disjoint⟩⟩⟩, ⟨⟨⟨temps_88_disjoint, temps_89_disjoint⟩, ⟨temps_90_disjoint, temps_91_disjoint⟩⟩, ⟨⟨temps_92_disjoint, temps_93_disjoint⟩, ⟨temps_94_disjoint, temps_95_disjoint⟩⟩⟩⟩⟩, ⟨⟨⟨⟨⟨temps_96_disjoint, temps_97_disjoint⟩, ⟨temps_98_disjoint, temps_99_disjoint⟩⟩, ⟨⟨temps_100_disjoint, temps_101_disjoint⟩, ⟨temps_102_disjoint, temps_103_disjoint⟩⟩⟩, ⟨⟨⟨temps_104_disjoint, temps_105_disjoint⟩, ⟨temps_106_disjoint, temps_107_disjoint⟩⟩, ⟨⟨temps_108_disjoint, temps_109_disjoint⟩, ⟨temps_110_disjoint, temps_111_disjoint⟩⟩⟩⟩, ⟨⟨⟨⟨temps_112_disjoint, temps_113_disjoint⟩, ⟨temps_114_disjoint, temps_115_disjoint⟩⟩, ⟨⟨temps_116_disjoint, temps_117_disjoint⟩, ⟨temps_118_disjoint, temps_119_disjoint⟩⟩⟩, ⟨⟨⟨temps_120_disjoint, temps_121_disjoint⟩, ⟨temps_122_disjoint, temps_123_disjoint⟩⟩, ⟨⟨temps_124_disjoint, temps_125_disjoint⟩, ⟨temps_126_disjoint, temps_127_disjoint⟩⟩⟩⟩⟩⟩⟩

private theorem width_not_local_0 : Arm64Program._arm64_width_effective ∉
    CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_0 := by decide +kernel

private theorem width_not_local_1 : Arm64Program._arm64_width_effective ∉
    CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_1 := by decide +kernel

private theorem width_not_local_2 : Arm64Program._arm64_width_effective ∉
    CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_2 := by decide +kernel

private theorem width_not_local_3 : Arm64Program._arm64_width_effective ∉
    CC.varNames Arm64Program.l_kprog_arm64_program_execute_vars_3 := by decide +kernel

theorem width_not_local : Arm64Program._arm64_width_effective ∉
    CC.varNames Arm64Program.f_kprog_arm64_program_execute.fn_vars := by
  dsimp only [Arm64Program.f_kprog_arm64_program_execute]
  simp only [CC.varNames, List.map_append, List.mem_append, not_or]
  exact ⟨⟨width_not_local_0, width_not_local_1⟩, ⟨width_not_local_2, width_not_local_3⟩⟩

end KProgFormal.ClightRefinement.Arm64NopDeclarations
