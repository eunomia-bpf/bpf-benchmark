import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailValues
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderTailSource (rhs site chunk)

noncomputable def localName (i : Fin 9) : CC.Ident :=
  match i.val with
  | 0 => ___a64_stack
  | 1 => ___a64_stack_payload
  | 2 => ___a64_stack_tag
  | 3 => ___a64_sim_helper_ctx
  | 4 => ___a64_sim_helper_abi_base
  | 5 => ___a64_sim_is_xdp
  | 6 => ___a64_sim_abi_kind
  | 7 => ___a64_sim_skb_ctx
  | _ => ___a64_sim_abi

noncomputable def localType (i : Fin 9) : CC.Ty :=
  match i.val with
  | 0 => CC.tvolatile (.Tunion __5191 CC.noattr)
  | 1 => CC.tarray (CC.tvolatile CC.tulong) 1
  | 2 => CC.tarray CC.tuchar 8
  | 3 => CC.tptr CC.tvoid
  | 4 => CC.tptr CC.tvoid
  | 5 => CC.tuchar
  | 6 => CC.tuchar
  | 7 => CC.tptr (.Tstruct ___sk_buff CC.noattr)
  | _ => .Tstruct _arm64_sim_xdp_abi CC.noattr

theorem declared : ∀ i : Fin 9,(localName i,localType i) ∈ procedure.fn_vars := by decide +kernel

structure Storage (m : CC.Mem) where
  block : Fin 9 → CC.Block
  binding : ∀ i,(allocation m).1.get (localName i) = some (block i,localType i)

theorem storage (m : CC.Mem) : Nonempty (Storage m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have witness : ∀ i,∃ b,(allocation m).1.get (localName i) = some (b,localType i) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) names (declared i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

noncomputable def globalName (i : Fin 2) : CC.Ident :=
  if i.val=0 then _kprog_arm64_payload_load else _kprog_arm64_payload_store
noncomputable def globalType (i : Fin 2) : CC.Ty :=
  CC.typeof (rhs ⟨i.val+3,by omega⟩)

private theorem global_found : ∀ i : Fin 2,
    (CC.Genv.findSymbol ge.genv_genv (globalName i)).isSome := by decide +kernel

noncomputable def globalBlock (i : Fin 2) : CC.Block :=
  (CC.Genv.findSymbol ge.genv_genv (globalName i)).get (global_found i)

theorem symbols : ∀ i : Fin 2,
    CC.Genv.findSymbol ge.genv_genv (globalName i) = some (globalBlock i) := by decide +kernel

theorem not_local : ∀ i : Fin 2,globalName i ∉ CC.varNames procedure.fn_vars := by decide +kernel

theorem global_bindings (m : CC.Mem) (i : Fin 2) :
    (allocation m).1.get (globalName i) = none := by
  have absent := CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) (not_local i)
  simpa only [CC.emptyEnv,CC.PTree.gempty] using absent

private noncomputable def unionComposite : CC.Composite :=
  (ge.genv_cenv.get __5191).get (by decide +kernel)

theorem union_layout :
    ge.genv_cenv.get __5191 = some unionComposite ∧
    CC.unionFieldOffset ge.genv_cenv _b unionComposite.co_members = .OK (0,.Full) ∧
    CC.unionFieldOffset ge.genv_cenv _q unionComposite.co_members = .OK (0,.Full) := by decide +kernel

theorem global_modes : ∀ i : Fin 2,CC.accessMode (globalType i) = .By_reference := by decide +kernel

noncomputable def expression (i : Fin 16) : CC.Expr :=
  match i.val with
  | 0 => .Efield (.Evar (localName 0) (localType 0)) _b (CC.tvolatile (CC.tarray CC.tuchar 32))
  | 1 => .Efield (.Evar (localName 0) (localType 0)) _q (CC.tvolatile (CC.tarray CC.tulong 4))
  | 2 => .Evar (localName 1) (localType 1)
  | 3 => .Evar (globalName 0) (globalType 0)
  | 4 => .Evar (globalName 1) (globalType 1)
  | 5 => .Evar (localName 2) (localType 2)
  | 6 => .Esizeof (CC.tarray (CC.tvolatile CC.tuchar) 32) CC.tulong
  | 7 => .Ebinop .Odiv (.Esizeof (localType 1) CC.tulong)
      (.Esizeof (CC.tvolatile CC.tulong) CC.tulong) CC.tulong
  | 8 => .Esizeof (localType 2) CC.tulong
  | 9 => .Econst_long (32#64) CC.tlong
  | _ =>
    let j : Fin 9 := ⟨i.val-7,by have bound := i.isLt;omega⟩
    .Eaddrof (.Evar (localName j) (localType j)) (CC.tptr (localType j))

theorem source_form : ∀ i : Fin 16,rhs i = expression i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

noncomputable def prevalue {m : CC.Mem} (resource : Storage m) (i : Fin 16) : CC.Val :=
  match i.val with
  | 0 => .Vptr (resource.block 0) 0
  | 1 => .Vptr (resource.block 0) 0
  | 2 => .Vptr (resource.block 1) 0
  | 3 => .Vptr (globalBlock 0) 0
  | 4 => .Vptr (globalBlock 1) 0
  | 5 => .Vptr (resource.block 2) 0
  | 6 => .Vlong (32#64)
  | 7 => .Vlong (1#64)
  | 8 => .Vlong (8#64)
  | 9 => .Vlong (32#64)
  | _ => .Vptr (resource.block ⟨i.val-7,by have bound := i.isLt;omega⟩) 0

noncomputable def value {m : CC.Mem} (resource : Storage m) (i : Fin 16) : CC.Val :=
  if 6 ≤ i.val ∧ i.val < 9 then
    .Vint (if i.val=6 then 32#32 else if i.val=7 then 1#32 else 8#32)
  else prevalue resource i

theorem casts {m : CC.Mem} (resource : Storage m) (before : CC.Mem) : ∀ i : Fin 16,
    CC.Cop.semCast (prevalue resource i) (CC.typeof (rhs i)) (site i).ty before =
      some (value resource i) ∧
    CC.Val.loadResult (chunk i) (value resource i) = value resource i := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

private theorem eval_environment {m : CC.Mem} (resource : Storage m) (env : CC.Env)
    (locals : ∀ i,env.get (localName i) = some (resource.block i,localType i))
    (globals : ∀ i,env.get (globalName i) = none) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 16,CC.doEvalExpr ge env le before (rhs i) = some (prevalue resource i) := by
  have b0 : env.get ___a64_stack =
      some (resource.block 0,CC.tvolatile (.Tunion __5191 CC.noattr)) := locals 0
  have b1 : env.get ___a64_stack_payload =
      some (resource.block 1,CC.tarray (CC.tvolatile CC.tulong) 1) := locals 1
  have b2 : env.get ___a64_stack_tag =
      some (resource.block 2,CC.tarray CC.tuchar 8) := locals 2
  have b3 : env.get ___a64_sim_helper_ctx =
      some (resource.block 3,CC.tptr CC.tvoid) := locals 3
  have b4 : env.get ___a64_sim_helper_abi_base =
      some (resource.block 4,CC.tptr CC.tvoid) := locals 4
  have b5 : env.get ___a64_sim_is_xdp = some (resource.block 5,CC.tuchar) := locals 5
  have b6 : env.get ___a64_sim_abi_kind = some (resource.block 6,CC.tuchar) := locals 6
  have b7 : env.get ___a64_sim_skb_ctx =
      some (resource.block 7,CC.tptr (.Tstruct ___sk_buff CC.noattr)) := locals 7
  have b8 : env.get ___a64_sim_abi =
      some (resource.block 8,.Tstruct _arm64_sim_xdp_abi CC.noattr) := locals 8
  have g0 : env.get _kprog_arm64_payload_load = none := globals 0
  have g1 : env.get _kprog_arm64_payload_store = none := globals 1
  have s0 : CC.Genv.findSymbol ge.genv_genv _kprog_arm64_payload_load = some (globalBlock 0) := symbols 0
  have s1 : CC.Genv.findSymbol ge.genv_genv _kprog_arm64_payload_store = some (globalBlock 1) := symbols 1
  have evaluated : ∀ i : Fin 16,CC.doEvalExpr ge env le before (expression i) =
      some (prevalue resource i) := by
    simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
    repeat' apply And.intro
    · change CC.doEvalExpr ge env le before (.Efield (.Evar ___a64_stack (CC.tvolatile (.Tunion __5191 CC.noattr))) _b (CC.tvolatile (CC.tarray CC.tuchar 32))) = some (.Vptr (resource.block 0) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,b0,CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField,union_layout.1,union_layout.2.1,CC.tvolatile,CC.tattr,CC.tarray]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Efield (.Evar ___a64_stack (CC.tvolatile (.Tunion __5191 CC.noattr))) _q (CC.tvolatile (CC.tarray CC.tulong 4))) = some (.Vptr (resource.block 0) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,b0,CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField,union_layout.1,union_layout.2.2,CC.tvolatile,CC.tattr,CC.tarray]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Evar ___a64_stack_payload (CC.tarray (CC.tvolatile CC.tulong) 1)) = some (.Vptr (resource.block 1) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,b1,CC.doDerefLoc,CC.accessMode,CC.tarray]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Evar _kprog_arm64_payload_load (globalType 0)) = some (.Vptr (globalBlock 0) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,g0,s0,CC.doDerefLoc,global_modes 0]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Evar _kprog_arm64_payload_store (globalType 1)) = some (.Vptr (globalBlock 1) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,g1,s1,CC.doDerefLoc,global_modes 1]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Evar ___a64_stack_tag (CC.tarray CC.tuchar 8)) = some (.Vptr (resource.block 2) 0)
      simp [CC.doEvalExpr,CC.lvalOfVar,b2,CC.doDerefLoc,CC.accessMode,CC.tarray]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Esizeof (CC.tarray (CC.tvolatile CC.tuchar) 32) CC.tulong) = some (.Vlong (32#64))
      rfl
    · change CC.doEvalExpr ge env le before (.Ebinop .Odiv (.Esizeof (CC.tarray (CC.tvolatile CC.tulong) 1) CC.tulong) (.Esizeof (CC.tvolatile CC.tulong) CC.tulong) CC.tulong) = some (.Vlong (1#64))
      rfl
    · change CC.doEvalExpr ge env le before (.Esizeof (CC.tarray CC.tuchar 8) CC.tulong) = some (.Vlong (8#64))
      rfl
    · change CC.doEvalExpr ge env le before (.Econst_long (32#64) CC.tlong) = some (.Vlong (32#64))
      rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_helper_ctx (CC.tptr CC.tvoid)) (CC.tptr (CC.tptr CC.tvoid))) = some (.Vptr (resource.block 3) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b3]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_helper_abi_base (CC.tptr CC.tvoid)) (CC.tptr (CC.tptr CC.tvoid))) = some (.Vptr (resource.block 4) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b4]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_is_xdp (CC.tuchar)) (CC.tptr (CC.tuchar))) = some (.Vptr (resource.block 5) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b5]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_abi_kind (CC.tuchar)) (CC.tptr (CC.tuchar))) = some (.Vptr (resource.block 6) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b6]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_skb_ctx (CC.tptr (.Tstruct ___sk_buff CC.noattr))) (CC.tptr (CC.tptr (.Tstruct ___sk_buff CC.noattr)))) = some (.Vptr (resource.block 7) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b7]
      all_goals rfl
    · change CC.doEvalExpr ge env le before (.Eaddrof (.Evar ___a64_sim_abi (.Tstruct _arm64_sim_xdp_abi CC.noattr)) (CC.tptr (.Tstruct _arm64_sim_xdp_abi CC.noattr))) = some (.Vptr (resource.block 8) 0)
      simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,b8]
      all_goals rfl
    · trivial
  intro i
  rw [source_form i]
  exact evaluated i

/-- Every original RHS derives its real local/global address or scalar value. -/
theorem source_values {m : CC.Mem} (resource : Storage m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 16,CC.doEvalExpr ge (allocation m).1 le before (rhs i) = some (prevalue resource i) :=
  eval_environment resource (allocation m).1 resource.binding (global_bindings m) le before

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailValues
