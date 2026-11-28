import KProgFormal.ClightRefinement.Arm64CiliumCallerContextEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

noncomputable def headerType : CC.Ty := .Tstruct _kprog_arm64_entry CC.noattr

structure Declaration where
  field : CC.Ident
  ty : CC.Ty
  sourceName : CC.Ident
  sourceType : CC.Ty
  address : Bool

private noncomputable def rows : Array (CC.Stmt × Declaration × CC.Stmt) := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual caller fixed header source changed"
      pure node.getAppArgs
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerContextGPR.after)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:12] do
      let outer ← peel current ``CC.Stmt.Ssequence 2
      let assign ← peel outer[0]! ``CC.Stmt.Sassign 2
      let field ← peel assign[0]! ``CC.Expr.Efield 3
      let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf assign[1]!)
      let address := rhs.isAppOfArity ``CC.Expr.Eaddrof 2
      let source ← peel (if address then rhs.getAppArgs[0]! else rhs) ``CC.Expr.Evar 2
      let declaration ← Lean.Meta.mkAppM ``Declaration.mk
        #[field[1]!,field[2]!,source[0]!,source[1]!,Lean.mkConst (if address then ``Bool.true else ``Bool.false)]
      let tail ← Lean.Meta.mkAppM ``Prod.mk #[declaration,outer[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[current,tail])
      current := outer[1]!
    let tailType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``Declaration,Lean.mkConst ``CC.Stmt]
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt,tailType]
    Lean.Elab.Tactic.closeMainGoal `actual_twelve_header_sites (← Lean.Meta.mkArrayLit rowType rows.toList)

noncomputable def declaration (i : Fin 12) : Declaration :=
  (rows[i.val]'(by change i.val < 12;exact i.isLt)).2.1
noncomputable def stage (i : Fin 12) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 12;exact i.isLt)).1
noncomputable def rest (i : Fin 12) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 12;exact i.isLt)).2.2
noncomputable def after : CC.Stmt := rest 11
noncomputable def lhs (i : Fin 12) : CC.Expr :=
  .Efield (.Evar ___a64_entry headerType) (declaration i).field (declaration i).ty
noncomputable def rhs (i : Fin 12) : CC.Expr :=
  let d := declaration i
  if d.address then .Eaddrof (.Evar d.sourceName d.sourceType) (CC.tptr d.sourceType)
  else .Evar d.sourceName d.sourceType
noncomputable def row (i : Fin 12) : CC.Stmt := .Sassign (lhs i) (rhs i)

theorem source : Arm64CiliumCallerContextGPR.after =
    (List.ofFn row).foldr CC.Stmt.Ssequence after := rfl

theorem after_source : after =
    .Ssequence s_trusted_arm64_arm64_sim_xdp_26 s_trusted_arm64_arm64_sim_xdp_9286 := rfl

private noncomputable def composite : CC.Composite :=
  (ge.genv_cenv.get _kprog_arm64_entry).get (by decide +kernel)
theorem layout :
    ge.genv_cenv.get _kprog_arm64_entry = some composite ∧
    (∀ i : Fin 12,CC.fieldOffset ge.genv_cenv (declaration i).field composite.co_members =
      .OK (8*(i.val : Int),.Full)) ∧
    96 ≤ CC.sizeof ge.genv_cenv headerType := by decide +kernel

theorem declared :
    (___a64_entry,headerType) ∈ procedure.fn_vars ∧
    (∀ i : Fin 12,((declaration i).sourceName,(declaration i).sourceType) ∈ procedure.fn_vars) := by decide +kernel

theorem source_outside : ∀ i : Fin 12,(declaration i).sourceName ≠ ___a64_entry := by decide +kernel

structure Header (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get ___a64_entry = some (block,headerType)
  fresh : m.nextblock.toNat ≤ block.toNat
  writable : CC.Mem.rangePerm (allocation m).2 block 0 96 .Cur .Writable = true

structure Sources (m : CC.Mem) where
  block : Fin 12 → CC.Block
  binding : ∀ i,(allocation m).1.get (declaration i).sourceName =
    some (block i,(declaration i).sourceType)

private theorem allocated_names (m : CC.Mem) : CC.listNorepet (CC.varNames procedure.fn_vars) := by
  cases Arm64CiliumCallerLink.entry_valid m .Vundef with
  | intro hn _ _ _ _ => exact hn

theorem header_storage (m : CC.Mem) : Nonempty (Header m) := by
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) (allocated_names m) declared.1
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  refine ⟨⟨block,binding,owned.1,?_⟩⟩
  apply CC.Mem.rangePerm_intro
  intro o lower upper
  have hi : o < CC.sizeof ge.genv_cenv headerType := by
    have bound : (96 : Int) ≤ CC.sizeof ge.genv_cenv headerType := layout.2.2
    omega
  exact CC.Mem.perm_implies
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned.2.2 o lower hi)
    (by decide : CC.permOrder .Freeable .Writable = true)

theorem source_storage (m : CC.Mem) : Nonempty (Sources m) := by
  have witness : ∀ i,∃ block,(allocation m).1.get (declaration i).sourceName =
      some (block,(declaration i).sourceType) :=
    fun i => allocated_local_binding (Arm64CiliumCallerLink.allocated m) (allocated_names m) (declared.2 i)
  exact ⟨⟨fun i => Classical.choose (witness i),fun i => Classical.choose_spec (witness i)⟩⟩

theorem source_modes : ∀ i : Fin 12,(declaration i).address = false →
    CC.accessMode (declaration i).sourceType = .By_reference := by decide +kernel

/-- Original array decay/address-of expressions derive actual local addresses. -/
theorem source_values {m : CC.Mem} (sources : Sources m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 12,CC.doEvalExpr ge (allocation m).1 le before (rhs i) =
      some (.Vptr (sources.block i) 0) := by
  intro i
  unfold rhs
  cases address : (declaration i).address with
  | true =>
    simp only [address,ite_true,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,sources.binding i,ite_true]
    rfl
  | false =>
    have mode := source_modes i address
    simp only [address,Bool.false_eq_true,ite_false,CC.doEvalExpr,CC.lvalOfVar,sources.binding i,ite_true,CC.doDerefLoc,mode]
    rfl

def pointerOffset (i : Fin 12) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero (CC.Integers.Ptrofs.repr (8*(i.val : Int)))

theorem offsets : ∀ i : Fin 12,CC.Integers.Ptrofs.unsigned (pointerOffset i) = 8*(i.val : Int) := by decide +kernel

/-- Original struct-field lvalues resolve the actual header block and offset. -/
theorem target_locations {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 12,CC.doEvalLvalue ge (allocation m).1 le before (lhs i) =
      some (header.block,pointerOffset i,.Full) := by
  intro i
  have bound : (allocation m).1.get ___a64_entry =
      some (header.block,.Tstruct _kprog_arm64_entry CC.noattr) := header.binding
  simp [lhs,headerType,CC.doEvalLvalue,CC.doEvalExpr,CC.lvalOfVar,bound,
    CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField,layout.1,layout.2.1 i,pointerOffset]

theorem modes (block : CC.Block) (before : CC.Mem) : ∀ i : Fin 12,
    CC.accessMode (declaration i).ty = .By_value .Mint64 ∧
    CC.Cop.semCast (.Vptr block 0) (CC.typeof (rhs i)) (declaration i).ty before =
      some (.Vptr block 0) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderSource
