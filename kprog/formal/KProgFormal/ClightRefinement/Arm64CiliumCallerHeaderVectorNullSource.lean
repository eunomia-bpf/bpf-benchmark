import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header headerType)

def pointerType : CC.Ty := CC.tptr CC.tulong
def arrayType : CC.Ty := CC.tarray pointerType 32
noncomputable def field (i : Fin 64) : CC.Ident := if i.val < 32 then _vector_lo else _vector_hi
def baseOffset (i : Fin 64) : Int := if i.val < 32 then 96 else 352
def lane (i : Fin 64) : Int := (i.val % 32 : Nat)
def offset (i : Fin 64) : Int := 96+8*(i.val : Int)
noncomputable def arrayExpr (i : Fin 64) : CC.Expr :=
  .Efield (.Evar ___a64_entry headerType) (field i) arrayType
noncomputable def lhs (i : Fin 64) : CC.Expr :=
  .Ederef (.Ebinop .Oadd (arrayExpr i) (.Econst_int (CC.Integers.Int.repr (lane i)) CC.tint)
    (CC.tptr pointerType)) pointerType
def rhs : CC.Expr := .Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tint) (CC.tptr CC.tvoid)
noncomputable def row (i : Fin 64) : CC.Stmt := .Sassign (lhs i) rhs

private noncomputable def rows : Array (CC.Stmt × CC.Stmt) := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerHeaderSource.after)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:64] do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original 64 vector pointer NULL initializer source changed"
      let next := node.getAppArgs[1]!
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[current,next])
      current := next
    let ty ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt,Lean.mkConst ``CC.Stmt]
    Lean.Elab.Tactic.closeMainGoal `original_vector_null_sites (← Lean.Meta.mkArrayLit ty rows.toList)

noncomputable def stage (i : Fin 64) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 64;exact i.isLt)).1
noncomputable def rest (i : Fin 64) : CC.Stmt :=
  (rows[i.val]'(by change i.val < 64;exact i.isLt)).2
noncomputable def after : CC.Stmt := rest 63

theorem source : Arm64CiliumCallerHeaderSource.after =
    (List.ofFn row).foldr CC.Stmt.Ssequence after := rfl

theorem shape : ∀ i : Fin 64,stage i = .Ssequence (row i) (rest i) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem chain : ∀ i : Fin 63,rest ⟨i.val,by omega⟩ = stage ⟨i.val+1,by omega⟩ := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

private noncomputable def composite : CC.Composite :=
  (ge.genv_cenv.get _kprog_arm64_entry).get (by decide +kernel)

theorem layout :
    ge.genv_cenv.get _kprog_arm64_entry = some composite ∧
    (∀ i : Fin 64,CC.fieldOffset ge.genv_cenv (field i) composite.co_members =
      .OK (baseOffset i,.Full)) ∧
    608 ≤ CC.sizeof ge.genv_cenv headerType := by decide +kernel

def pointerOffset (i : Fin 64) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add
    (CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero (CC.Integers.Ptrofs.repr (baseOffset i)))
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr (lane i))))

theorem offsets : ∀ i : Fin 64,CC.Integers.Ptrofs.unsigned (pointerOffset i) = offset i := by decide +kernel

/-- Extend the SAME header witness's allocation rights to its two vector arrays. -/
theorem storage {m : CC.Mem} (header : Header m) :
    CC.Mem.rangePerm (allocation m).2 header.block 96 608 .Cur .Writable = true := by
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ header.binding
  apply CC.Mem.rangePerm_intro
  intro o lower upper
  have lo : (0 : Int) ≤ o := by omega
  have hi : o < CC.sizeof ge.genv_cenv headerType := by
    have bound : (608 : Int) ≤ CC.sizeof ge.genv_cenv headerType := layout.2.2
    omega
  exact CC.Mem.perm_implies
    (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned.2.2 o lo hi)
    (by decide : CC.permOrder .Freeable .Writable = true)

theorem first_source : stage 0 = Arm64CiliumCallerHeaderSource.after := rfl

/-- The original array field decays to its real header address without loading memory. -/
theorem array_values {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 64,CC.doEvalExpr ge (allocation m).1 le before (arrayExpr i) =
      some (.Vptr header.block
        (CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero (CC.Integers.Ptrofs.repr (baseOffset i)))) := by
  intro i
  have bound : (allocation m).1.get ___a64_entry =
      some (header.block,.Tstruct _kprog_arm64_entry CC.noattr) := header.binding
  simp [arrayExpr,headerType,arrayType,pointerType,CC.tarray,CC.doEvalExpr,CC.lvalOfVar,bound,
    CC.doDerefLoc,CC.accessMode,CC.typeof,CC.lvalOfField,layout.1,layout.2.1 i]

private theorem add_array_address (g : CC.CGenv) (env : CC.Env) (le : CC.TempEnv) (before : CC.Mem)
    (a : CC.Expr) (n : BitVec 32) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (found : CC.doEvalExpr g env le before a = some (.Vptr b ofs))
    (typed : CC.typeof a = arrayType) :
    CC.doEvalExpr g env le before
      (.Ebinop .Oadd a (.Econst_int n CC.tint) (CC.tptr pointerType)) =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs
        (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8) (CC.Cop.ptrofsOfInt .Signed n)))) := by
  simp only [CC.doEvalExpr,found]
  rw [typed]
  rfl

theorem target_locations {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (before : CC.Mem) :
    ∀ i : Fin 64,CC.doEvalLvalue ge (allocation m).1 le before (lhs i) =
      some (header.block,pointerOffset i,.Full) := by
  intro i
  have binary : CC.doEvalExpr ge (allocation m).1 le before
      (.Ebinop .Oadd (arrayExpr i) (.Econst_int (CC.Integers.Int.repr (lane i)) CC.tint)
        (CC.tptr pointerType)) = some (.Vptr header.block (pointerOffset i)) :=
    add_array_address ge (allocation m).1 le before (arrayExpr i)
      (CC.Integers.Int.repr (lane i)) header.block _
      (array_values header le before i) rfl
  simp only [lhs,CC.doEvalLvalue,binary]

theorem rhs_value (before : CC.Mem) (env : CC.Env) (le : CC.TempEnv) :
    CC.doEvalExpr ge env le before rhs = some (.Vlong (0#64)) := rfl

theorem assignment (before : CC.Mem) :
    CC.accessMode pointerType = .By_value .Mint64 ∧
    CC.Cop.semCast (.Vlong (0#64)) (CC.typeof rhs) pointerType before =
      some (.Vlong (0#64)) := by
  constructor <;> rfl

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullSource
