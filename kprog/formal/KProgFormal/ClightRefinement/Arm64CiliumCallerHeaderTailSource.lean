import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header headerType)

structure Site where
  stmt : CC.Stmt
  field : CC.Ident
  ty : CC.Ty
  rhs : CC.Expr
  rest : CC.Stmt

private noncomputable def sites : Array Site := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "original sixteen remaining header assignments changed"
      pure node.getAppArgs
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerHeaderVectorNullSource.after)) none
    let mut sites : Array Lean.Expr := #[]
    for _ in [:16] do
      let outer ← peel current ``CC.Stmt.Ssequence 2
      let assign ← peel outer[0]! ``CC.Stmt.Sassign 2
      let field ← peel assign[0]! ``CC.Expr.Efield 3
      sites := sites.push (← Lean.Meta.mkAppM ``Site.mk
        #[current,field[1]!,field[2]!,assign[1]!,outer[1]!])
      current := outer[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_sixteen_header_tail_sites
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Site) sites.toList)

noncomputable def site (i : Fin 16) : Site := sites[i.val]'(by change i.val < 16;exact i.isLt)
noncomputable def stage (i : Fin 16) : CC.Stmt := (site i).stmt
noncomputable def rest (i : Fin 16) : CC.Stmt := (site i).rest
noncomputable def after : CC.Stmt := rest 15
noncomputable def lhs (i : Fin 16) : CC.Expr :=
  .Efield (.Evar ___a64_entry headerType) (site i).field (site i).ty
noncomputable def rhs (i : Fin 16) : CC.Expr := (site i).rhs
noncomputable def row (i : Fin 16) : CC.Stmt := .Sassign (lhs i) (rhs i)

def offset (i : Fin 16) : Int :=
  if i.val < 6 then 608+8*(i.val : Int)
  else if i.val < 9 then 656+4*((i.val-6 : Nat) : Int)
  else 672+8*((i.val-9 : Nat) : Int)
def chunk (i : Fin 16) : CC.Chunk :=
  if 6 ≤ i.val ∧ i.val < 9 then .Mint32 else .Mint64
def pointerOffset (i : Fin 16) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero (CC.Integers.Ptrofs.repr (offset i))

theorem source : Arm64CiliumCallerHeaderVectorNullSource.after =
    (List.ofFn row).foldr CC.Stmt.Ssequence after := rfl

theorem first_source : stage 0 = Arm64CiliumCallerHeaderVectorNullSource.after := rfl

theorem shape : ∀ i : Fin 16,stage i = .Ssequence (row i) (rest i) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem chain : ∀ i : Fin 15,rest ⟨i.val,by omega⟩ = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem loop_start :
    (match after with
    | .Ssequence (.Ssequence (.Sset id expression) (.Sloop _ _)) _ =>
        id = _i ∧ expression = .Econst_int (CC.Integers.Int.repr 0) CC.tint
    | _ => False) := by
  constructor <;> rfl

private noncomputable def composite : CC.Composite :=
  (ge.genv_cenv.get _kprog_arm64_entry).get (by decide +kernel)

theorem layout :
    ge.genv_cenv.get _kprog_arm64_entry = some composite ∧
    CC.sizeof ge.genv_cenv headerType = 728 ∧
    (∀ i : Fin 16,
      CC.fieldOffset ge.genv_cenv (site i).field composite.co_members = .OK (offset i,.Full) ∧
      CC.accessMode (site i).ty = .By_value (chunk i) ∧
      CC.sizeof ge.genv_cenv (site i).ty = CC.sizeChunk (chunk i)) := by decide +kernel

theorem offsets : ∀ i : Fin 16,CC.Integers.Ptrofs.unsigned (pointerOffset i) = offset i := by decide +kernel

/-- The SAME original header witness supplies the remaining actual allocation rights. -/
theorem storage {m : CC.Mem} (header : Header m) :
    CC.Mem.rangePerm (allocation m).2 header.block 608 728 .Cur .Writable = true := by
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ header.binding
  apply CC.Mem.rangePerm_intro
  intro o lower upper
  have lo : (0 : Int) ≤ o := by omega
  have hi : o < CC.sizeof ge.genv_cenv headerType := by
    rw [layout.2.1]
    exact upper
  exact CC.Mem.perm_implies
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned.2.2 o lo hi)
    (by decide : CC.permOrder .Freeable .Writable = true)

theorem target_locations {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 16,CC.doEvalLvalue ge (allocation m).1 le before (lhs i) =
      some (header.block,pointerOffset i,.Full) := by
  intro i
  have bound : (allocation m).1.get ___a64_entry =
      some (header.block,.Tstruct _kprog_arm64_entry CC.noattr) := header.binding
  simp [lhs,headerType,CC.doEvalLvalue,CC.doEvalExpr,CC.lvalOfVar,bound,
    CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField,layout.1,(layout.2.2 i).1,pointerOffset]

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailSource
