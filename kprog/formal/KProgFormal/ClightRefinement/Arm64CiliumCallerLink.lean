import KProgFormal.Clight.Arm64CiliumCaller
import KProgFormal.ClightRefinement.Arm64Producer

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLink
open Arm64CiliumCallerUnit


noncomputable def procedure : CC.Function := f_trusted_arm64_arm64_sim_xdp
noncomputable def ge : CC.CGenv := prog.globalenv
noncomputable def label : CC.Ident := _arm64_l_54
noncomputable def token : BitVec 64 := 88#64

theorem label_present :
    (CC.findLabel label procedure.fn_body .Kstop).isSome = true := by decide +kernel

noncomputable def site : CC.Stmt := ((CC.findLabel label procedure.fn_body .Kstop).get label_present).1


private noncomputable def writer : CC.Stmt := by
  run_tac do
    let info ← Lean.getConstInfo
      ``Arm64CiliumCallerUnit.s_trusted_arm64_arm64_sim_xdp_9280
    let mut pending := #[info.value!]
    let mut found : Option Lean.Expr := none
    while !pending.isEmpty do
      let value := pending.back!
      pending := pending.pop
      if value.isAppOfArity ``CC.Stmt.Slabel 2 &&
          value.getAppArgs[0]!.isConstOf ``Arm64CiliumCallerUnit._arm64_l_54 then
        if found.isSome then throwError "duplicate actual LINK label"
        found := some value.getAppArgs[1]!
      else
        pending := pending ++ value.getAppArgs
    let some outer := found | throwError "actual LINK label absent from source part"
    unless outer.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "actual LINK loop changed"
    let body := outer.getAppArgs[0]!
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual LR sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_inline_writer body.getAppArgs[1]!

noncomputable def lrStatement : CC.Stmt :=
  .Sassign (.Evar ___a64_lr CC.tulong) (.Econst_long token CC.tulong)

theorem site_source : site = .Sloop (.Ssequence lrStatement writer) .Sbreak := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []


noncomputable def allocation (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ge.genv_cenv CC.emptyEnv m procedure.fn_vars

private theorem nodup_of_numbers (xs : List CC.Ident)
    (h : (xs.map CC.Positive.toNat).Nodup) : xs.Nodup :=
  List.Pairwise.of_map CC.Positive.toNat
    (fun _ _ different same => different (congrArg CC.Positive.toNat same)) h

private theorem disjoint_of_numbers (xs ys : List CC.Ident)
    (h : (xs.map CC.Positive.toNat).all
      (fun x => (ys.map CC.Positive.toNat).all (fun y => decide (x ≠ y))) = true) :
    CC.listDisjoint xs ys := by
  intro x hx hy
  have a := List.mem_map_of_mem (f := CC.Positive.toNat) hx
  have b := List.mem_map_of_mem (f := CC.Positive.toNat) hy
  have impossible := List.all_eq_true.mp (List.all_eq_true.mp h _ a) _ b
  exact (of_decide_eq_true impossible) rfl

private theorem vars_norepet : CC.listNorepet (CC.varNames procedure.fn_vars) := by
  apply nodup_of_numbers
  decide +kernel


private theorem params_norepet : CC.listNorepet (CC.varNames procedure.fn_params) := by
  decide +kernel

private theorem disjoint_append (a b c : List CC.Ident) :
    CC.listDisjoint a (b ++ c) ↔ CC.listDisjoint a b ∧ CC.listDisjoint a c := by
  simp only [CC.listDisjoint,List.mem_append,not_or]
  constructor
  · intro h
    exact ⟨fun id hi => (h id hi).1,fun id hi => (h id hi).2⟩
  · intro h id hi
    exact ⟨h.1 id hi,h.2 id hi⟩


private theorem temps_0_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_0) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_1_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_1) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_2_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_2) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_3_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_3) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_4_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_4) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_5_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_5) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_6_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_6) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_7_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_7) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_8_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_8) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_9_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_9) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_10_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_10) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_11_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_11) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_12_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_12) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_13_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_13) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_14_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_14) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_15_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_15) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_16_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_16) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_17_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_17) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_18_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_18) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_19_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_19) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_20_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_20) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_21_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_21) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_22_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_22) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_23_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_23) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_24_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_24) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_25_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_25) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_26_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_26) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_27_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_27) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_28_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_28) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_29_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_29) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_30_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_30) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_31_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_31) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_32_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_32) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_33_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_33) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_34_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_34) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_35_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_35) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_36_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_36) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_37_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_37) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_38_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_38) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_39_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_39) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_40_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_40) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_41_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_41) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_42_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_42) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_43_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_43) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_44_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_44) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_45_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_45) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_46_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_46) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_47_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_47) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_48_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_48) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_49_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_49) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_50_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_50) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_51_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_51) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_52_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_52) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_53_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_53) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_54_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_54) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_55_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_55) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_56_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_56) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_57_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_57) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_58_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_58) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_59_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_59) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_60_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_60) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_61_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_61) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_62_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_62) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_63_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_63) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_64_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_64) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_65_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_65) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_66_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_66) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_67_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_67) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_68_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_68) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_69_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_69) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_70_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_70) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_71_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_71) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_72_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_72) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_73_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_73) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_74_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_74) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_75_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_75) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_76_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_76) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_77_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_77) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_78_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_78) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_79_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_79) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_80_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_80) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_81_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_81) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_82_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_82) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_83_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_83) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_84_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_84) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_85_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_85) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_86_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_86) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_87_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_87) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_88_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_88) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_89_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_89) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_90_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_90) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_91_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_91) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_92_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_92) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_93_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_93) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_94_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_94) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_95_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_95) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_96_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_96) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_97_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_97) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_98_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_98) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_99_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_99) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_100_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_100) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_101_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_101) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_102_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_102) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_103_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_103) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_104_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_104) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_105_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_105) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_106_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_106) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_107_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_107) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_108_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_108) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_109_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_109) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_110_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_110) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_111_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_111) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_112_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_112) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_113_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_113) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_114_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_114) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_115_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_115) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_116_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_116) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_117_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_117) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_118_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_118) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_119_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_119) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_120_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_120) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_121_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_121) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_122_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_122) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_123_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_123) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_124_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_124) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_125_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_125) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_126_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_126) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_127_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_127) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_128_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_128) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_129_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_129) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_130_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_130) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_131_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_131) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_132_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_132) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_133_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_133) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_134_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_134) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_135_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_135) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_136_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_136) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_137_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_137) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_138_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_138) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_139_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_139) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_140_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_140) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_141_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_141) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_142_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_142) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_143_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_143) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_144_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_144) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_145_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_145) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_146_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_146) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_147_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_147) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_148_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_148) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_149_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_149) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_150_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_150) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_151_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_151) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_152_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_152) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_153_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_153) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_154_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_154) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_155_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_155) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_156_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_156) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_157_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_157) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_158_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_158) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_159_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_159) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_160_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_160) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_161_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_161) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_162_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_162) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_163_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_163) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_164_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_164) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_165_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_165) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_166_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_166) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_167_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_167) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_168_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_168) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_169_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_169) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_170_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_170) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_171_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_171) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_172_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_172) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_173_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_173) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_174_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_174) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_175_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_175) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_176_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_176) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_177_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_177) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_178_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_178) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_179_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_179) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_180_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_180) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_181_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_181) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_182_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_182) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_183_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_183) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_184_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_184) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_185_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_185) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_186_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_186) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_187_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_187) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_188_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_188) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_189_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_189) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_190_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_190) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_191_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_191) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_192_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_192) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_193_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_193) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_194_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_194) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_195_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_195) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_196_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_196) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_197_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_197) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_198_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_198) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_199_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_199) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_200_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_200) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_201_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_201) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_202_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_202) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_203_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_203) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_204_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_204) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_205_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_205) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_206_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_206) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_207_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_207) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_208_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_208) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_209_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_209) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_210_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_210) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_211_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_211) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_212_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_212) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_213_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_213) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_214_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_214) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_215_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_215) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_216_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_216) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_217_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_217) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_218_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_218) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_219_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_219) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_220_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_220) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_221_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_221) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_222_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_222) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_223_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_223) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_224_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_224) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_225_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_225) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_226_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_226) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_227_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_227) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_228_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_228) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_229_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_229) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_230_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_230) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_231_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_231) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_232_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_232) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_233_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_233) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_234_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_234) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_235_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_235) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_236_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_236) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_237_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_237) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_238_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_238) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_239_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_239) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_240_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_240) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_241_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_241) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_242_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_242) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_243_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_243) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_244_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_244) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_245_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_245) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_246_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_246) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_247_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_247) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_248_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_248) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_249_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_249) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_250_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_250) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_251_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_251) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_252_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_252) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_253_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_253) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_254_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_254) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem temps_255_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params)
      (CC.varNames l_trusted_arm64_arm64_sim_xdp_temps_255) := by
  apply disjoint_of_numbers
  decide +kernel

private theorem params_temps_disjoint :
    CC.listDisjoint (CC.varNames procedure.fn_params) (CC.varNames procedure.fn_temps) := by
  dsimp only [procedure,f_trusted_arm64_arm64_sim_xdp]
  simp only [CC.varNames,List.map_append,disjoint_append]
  exact ⟨⟨⟨⟨⟨⟨⟨⟨temps_0_disjoint , temps_1_disjoint⟩ , ⟨temps_2_disjoint , temps_3_disjoint⟩⟩ , ⟨⟨temps_4_disjoint , temps_5_disjoint⟩ , ⟨temps_6_disjoint , temps_7_disjoint⟩⟩⟩ , ⟨⟨⟨temps_8_disjoint , temps_9_disjoint⟩ , ⟨temps_10_disjoint , temps_11_disjoint⟩⟩ , ⟨⟨temps_12_disjoint , temps_13_disjoint⟩ , ⟨temps_14_disjoint , temps_15_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_16_disjoint , temps_17_disjoint⟩ , ⟨temps_18_disjoint , temps_19_disjoint⟩⟩ , ⟨⟨temps_20_disjoint , temps_21_disjoint⟩ , ⟨temps_22_disjoint , temps_23_disjoint⟩⟩⟩ , ⟨⟨⟨temps_24_disjoint , temps_25_disjoint⟩ , ⟨temps_26_disjoint , temps_27_disjoint⟩⟩ , ⟨⟨temps_28_disjoint , temps_29_disjoint⟩ , ⟨temps_30_disjoint , temps_31_disjoint⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨temps_32_disjoint , temps_33_disjoint⟩ , ⟨temps_34_disjoint , temps_35_disjoint⟩⟩ , ⟨⟨temps_36_disjoint , temps_37_disjoint⟩ , ⟨temps_38_disjoint , temps_39_disjoint⟩⟩⟩ , ⟨⟨⟨temps_40_disjoint , temps_41_disjoint⟩ , ⟨temps_42_disjoint , temps_43_disjoint⟩⟩ , ⟨⟨temps_44_disjoint , temps_45_disjoint⟩ , ⟨temps_46_disjoint , temps_47_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_48_disjoint , temps_49_disjoint⟩ , ⟨temps_50_disjoint , temps_51_disjoint⟩⟩ , ⟨⟨temps_52_disjoint , temps_53_disjoint⟩ , ⟨temps_54_disjoint , temps_55_disjoint⟩⟩⟩ , ⟨⟨⟨temps_56_disjoint , temps_57_disjoint⟩ , ⟨temps_58_disjoint , temps_59_disjoint⟩⟩ , ⟨⟨temps_60_disjoint , temps_61_disjoint⟩ , ⟨temps_62_disjoint , temps_63_disjoint⟩⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨⟨temps_64_disjoint , temps_65_disjoint⟩ , ⟨temps_66_disjoint , temps_67_disjoint⟩⟩ , ⟨⟨temps_68_disjoint , temps_69_disjoint⟩ , ⟨temps_70_disjoint , temps_71_disjoint⟩⟩⟩ , ⟨⟨⟨temps_72_disjoint , temps_73_disjoint⟩ , ⟨temps_74_disjoint , temps_75_disjoint⟩⟩ , ⟨⟨temps_76_disjoint , temps_77_disjoint⟩ , ⟨temps_78_disjoint , temps_79_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_80_disjoint , temps_81_disjoint⟩ , ⟨temps_82_disjoint , temps_83_disjoint⟩⟩ , ⟨⟨temps_84_disjoint , temps_85_disjoint⟩ , ⟨temps_86_disjoint , temps_87_disjoint⟩⟩⟩ , ⟨⟨⟨temps_88_disjoint , temps_89_disjoint⟩ , ⟨temps_90_disjoint , temps_91_disjoint⟩⟩ , ⟨⟨temps_92_disjoint , temps_93_disjoint⟩ , ⟨temps_94_disjoint , temps_95_disjoint⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨temps_96_disjoint , temps_97_disjoint⟩ , ⟨temps_98_disjoint , temps_99_disjoint⟩⟩ , ⟨⟨temps_100_disjoint , temps_101_disjoint⟩ , ⟨temps_102_disjoint , temps_103_disjoint⟩⟩⟩ , ⟨⟨⟨temps_104_disjoint , temps_105_disjoint⟩ , ⟨temps_106_disjoint , temps_107_disjoint⟩⟩ , ⟨⟨temps_108_disjoint , temps_109_disjoint⟩ , ⟨temps_110_disjoint , temps_111_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_112_disjoint , temps_113_disjoint⟩ , ⟨temps_114_disjoint , temps_115_disjoint⟩⟩ , ⟨⟨temps_116_disjoint , temps_117_disjoint⟩ , ⟨temps_118_disjoint , temps_119_disjoint⟩⟩⟩ , ⟨⟨⟨temps_120_disjoint , temps_121_disjoint⟩ , ⟨temps_122_disjoint , temps_123_disjoint⟩⟩ , ⟨⟨temps_124_disjoint , temps_125_disjoint⟩ , ⟨temps_126_disjoint , temps_127_disjoint⟩⟩⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨⟨⟨temps_128_disjoint , temps_129_disjoint⟩ , ⟨temps_130_disjoint , temps_131_disjoint⟩⟩ , ⟨⟨temps_132_disjoint , temps_133_disjoint⟩ , ⟨temps_134_disjoint , temps_135_disjoint⟩⟩⟩ , ⟨⟨⟨temps_136_disjoint , temps_137_disjoint⟩ , ⟨temps_138_disjoint , temps_139_disjoint⟩⟩ , ⟨⟨temps_140_disjoint , temps_141_disjoint⟩ , ⟨temps_142_disjoint , temps_143_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_144_disjoint , temps_145_disjoint⟩ , ⟨temps_146_disjoint , temps_147_disjoint⟩⟩ , ⟨⟨temps_148_disjoint , temps_149_disjoint⟩ , ⟨temps_150_disjoint , temps_151_disjoint⟩⟩⟩ , ⟨⟨⟨temps_152_disjoint , temps_153_disjoint⟩ , ⟨temps_154_disjoint , temps_155_disjoint⟩⟩ , ⟨⟨temps_156_disjoint , temps_157_disjoint⟩ , ⟨temps_158_disjoint , temps_159_disjoint⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨temps_160_disjoint , temps_161_disjoint⟩ , ⟨temps_162_disjoint , temps_163_disjoint⟩⟩ , ⟨⟨temps_164_disjoint , temps_165_disjoint⟩ , ⟨temps_166_disjoint , temps_167_disjoint⟩⟩⟩ , ⟨⟨⟨temps_168_disjoint , temps_169_disjoint⟩ , ⟨temps_170_disjoint , temps_171_disjoint⟩⟩ , ⟨⟨temps_172_disjoint , temps_173_disjoint⟩ , ⟨temps_174_disjoint , temps_175_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_176_disjoint , temps_177_disjoint⟩ , ⟨temps_178_disjoint , temps_179_disjoint⟩⟩ , ⟨⟨temps_180_disjoint , temps_181_disjoint⟩ , ⟨temps_182_disjoint , temps_183_disjoint⟩⟩⟩ , ⟨⟨⟨temps_184_disjoint , temps_185_disjoint⟩ , ⟨temps_186_disjoint , temps_187_disjoint⟩⟩ , ⟨⟨temps_188_disjoint , temps_189_disjoint⟩ , ⟨temps_190_disjoint , temps_191_disjoint⟩⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨⟨temps_192_disjoint , temps_193_disjoint⟩ , ⟨temps_194_disjoint , temps_195_disjoint⟩⟩ , ⟨⟨temps_196_disjoint , temps_197_disjoint⟩ , ⟨temps_198_disjoint , temps_199_disjoint⟩⟩⟩ , ⟨⟨⟨temps_200_disjoint , temps_201_disjoint⟩ , ⟨temps_202_disjoint , temps_203_disjoint⟩⟩ , ⟨⟨temps_204_disjoint , temps_205_disjoint⟩ , ⟨temps_206_disjoint , temps_207_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_208_disjoint , temps_209_disjoint⟩ , ⟨temps_210_disjoint , temps_211_disjoint⟩⟩ , ⟨⟨temps_212_disjoint , temps_213_disjoint⟩ , ⟨temps_214_disjoint , temps_215_disjoint⟩⟩⟩ , ⟨⟨⟨temps_216_disjoint , temps_217_disjoint⟩ , ⟨temps_218_disjoint , temps_219_disjoint⟩⟩ , ⟨⟨temps_220_disjoint , temps_221_disjoint⟩ , ⟨temps_222_disjoint , temps_223_disjoint⟩⟩⟩⟩⟩ , ⟨⟨⟨⟨⟨temps_224_disjoint , temps_225_disjoint⟩ , ⟨temps_226_disjoint , temps_227_disjoint⟩⟩ , ⟨⟨temps_228_disjoint , temps_229_disjoint⟩ , ⟨temps_230_disjoint , temps_231_disjoint⟩⟩⟩ , ⟨⟨⟨temps_232_disjoint , temps_233_disjoint⟩ , ⟨temps_234_disjoint , temps_235_disjoint⟩⟩ , ⟨⟨temps_236_disjoint , temps_237_disjoint⟩ , ⟨temps_238_disjoint , temps_239_disjoint⟩⟩⟩⟩ , ⟨⟨⟨⟨temps_240_disjoint , temps_241_disjoint⟩ , ⟨temps_242_disjoint , temps_243_disjoint⟩⟩ , ⟨⟨temps_244_disjoint , temps_245_disjoint⟩ , ⟨temps_246_disjoint , temps_247_disjoint⟩⟩⟩ , ⟨⟨⟨temps_248_disjoint , temps_249_disjoint⟩ , ⟨temps_250_disjoint , temps_251_disjoint⟩⟩ , ⟨⟨temps_252_disjoint , temps_253_disjoint⟩ , ⟨temps_254_disjoint , temps_255_disjoint⟩⟩⟩⟩⟩⟩⟩⟩

private theorem names :
    CC.listNorepet (CC.varNames procedure.fn_vars) ∧
    CC.listNorepet (CC.varNames procedure.fn_params) ∧
    CC.listDisjoint (CC.varNames procedure.fn_params) (CC.varNames procedure.fn_temps) :=
  ⟨vars_norepet,params_norepet,params_temps_disjoint⟩


theorem allocated (m : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv m procedure.fn_vars
      (allocation m).1 (allocation m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm

noncomputable def initialTemps (context : CC.Val) : CC.TempEnv :=
  (CC.createUndefTemps procedure.fn_temps).set _ctx context


theorem entry_valid (m : CC.Mem) (context : CC.Val) :
    CC.FunctionEntry2 ge procedure [context] m
      (allocation m).1 (initialTemps context) (allocation m).2 :=
  .intro names.1 names.2.1 names.2.2 (allocated m) rfl


structure LRLocal (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get ___a64_lr = some (block,CC.tulong)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : block.toNat < (allocation m).2.nextblock.toNat
  live : CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Freeable = true

theorem lr_local (m : CC.Mem) : Nonempty (LRLocal m) := by
  have member : (___a64_lr,CC.tulong) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (allocated m) names.1 member
  have live := (allocated_local_storage (allocated m)).1 _ _ binding
  exact ⟨⟨block,binding,live.1,live.2.1,live.2.2⟩⟩

/-- Four actual source steps from one real LINK site. The current permission
is an original lr resource;successful store,final LR and caller frame
are derived. Reaching this site from entry remains a separate obligation. -/

theorem begin_link {m before : CC.Mem} (lr : LRLocal m)
    (le : CC.TempEnv) (k : CC.Cont)
    (live : CC.Mem.rangePerm before lr.block 0 8 .Cur .Freeable = true) :
    ∃ after,
      InternalRun ge 4
        (.State procedure site k (allocation m).1 le before)
        (.State procedure writer
          (.Kloop1 (.Ssequence lrStatement writer) .Sbreak k)
          (allocation m).1 le after) ∧
      CC.Mem.store .Mint64 before lr.block 0 (.Vlong token) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  have range := CC.Mem.rangePerm_implies live (by decide : CC.permOrder .Freeable .Writable = true)
  have writable : CC.Mem.validAccess before .Mint64 lr.block 0 .Writable = true := by
    change (CC.Mem.rangePerm before lr.block 0 8 .Cur .Writable && true) = true
    rw [range]
    rfl
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store .Mint64 before lr.block 0 (.Vlong token) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  have target : CC.doEvalLvalue ge (allocation m).1 le before
      (.Evar ___a64_lr CC.tulong) = some (lr.block,0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,lr.binding]
    rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tulong before lr.block 0 .Full
      (.Vlong token) = some after := stored
  have step : CC.Step2 ge
      (.State procedure lrStatement
        (.Kseq writer (.Kloop1 (.Ssequence lrStatement writer) .Sbreak k))
        (allocation m).1 le before) CC.E0
      (.State procedure .Sskip
        (.Kseq writer (.Kloop1 (.Ssequence lrStatement writer) .Sbreak k))
        (allocation m).1 le after) := by
    apply CC.doStep_sound
    have cast : CC.Cop.semCast (.Vlong token) CC.tulong CC.tulong before =
        some (.Vlong token) := rfl
    simp only [lrStatement,CC.doStep,target,CC.doEvalExpr,CC.typeof,cast,assignment]
  refine ⟨after,?_,stored,CC.Mem.load_store_same stored,
    FrameBelow.store lr.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  rw [site_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))

/-- The same LR write leaves every differently named real caller local
unchanged,including the original register and tag pointer tables. -/
theorem preserves_other_locals {m before after : CC.Mem} (lr : LRLocal m)
    (stored : CC.Mem.store .Mint64 before lr.block 0 (.Vlong token) = some after)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation m).1.get id = some (block,ty))
    (different : id ≠ ___a64_lr) (chunk : CC.Chunk) (offset : CC.Z) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (allocated m)).2
    id ___a64_lr (block,ty) (lr.block,CC.tulong) binding lr.binding different
  exact CC.Mem.load_store_other stored chunk block offset (.inl separate)

/-- At the original allocated memory the genuine allocator supplies the
current permission automatically,without a live-resource hypothesis. -/

theorem begin_allocated (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : LRLocal m, ∃ after,
      InternalRun ge 4
        (.State procedure site k (allocation m).1 le (allocation m).2)
        (.State procedure writer
          (.Kloop1 (.Ssequence lrStatement writer) .Sbreak k)
          (allocation m).1 le after) ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      FrameBelow m.nextblock (allocation m).2 after := by
  obtain ⟨lr⟩ := lr_local m
  obtain ⟨after,run,stored,read,frame,access,next⟩ := begin_link lr le k lr.live
  exact ⟨lr,after,run,read,frame⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerLink
