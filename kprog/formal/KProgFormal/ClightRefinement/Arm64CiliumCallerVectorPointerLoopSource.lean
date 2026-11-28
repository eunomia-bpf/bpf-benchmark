import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSource
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (headerType)
open Arm64CiliumCallerVectorSource (vectorType vectorArrayType)

noncomputable def index : CC.Expr := .Etempvar _i CC.tuint
def pointerType : CC.Ty := CC.tptr CC.tulong
noncomputable def setup : CC.Stmt := .Sset _i (.Econst_int (0#32) CC.tint)
noncomputable def condition : CC.Expr :=
  .Ebinop .Olt index (.Econst_int (32#32) CC.tint) CC.tint
noncomputable def guard : CC.Stmt := .Sifthenelse condition .Sskip .Sbreak
noncomputable def lhs (high : Bool) : CC.Expr :=
  .Ederef (.Ebinop .Oadd
    (.Efield (.Evar ___a64_entry headerType) (if high then _vector_hi else _vector_lo)
      (CC.tarray pointerType 32))
    index (CC.tptr pointerType)) pointerType
noncomputable def rhs (high : Bool) : CC.Expr :=
  .Eaddrof (.Efield
    (.Ederef (.Ebinop .Oadd (.Evar ___a64_vectors vectorArrayType) index
      (CC.tptr vectorType)) vectorType)
    (if high then _hi else _lo) CC.tulong) pointerType
noncomputable def assignment (high : Bool) : CC.Stmt := .Sassign (lhs high) (rhs high)
noncomputable def body : CC.Stmt :=
  .Ssequence guard (.Ssequence (assignment false) (assignment true))
noncomputable def increment : CC.Stmt :=
  .Sset _i (.Ebinop .Oadd index (.Econst_int (1#32) CC.tint) CC.tuint)
noncomputable def loop : CC.Stmt := .Sloop body increment

noncomputable def after : CC.Stmt := by
  run_tac do
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerHeaderTailSource.after)) none
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf original)
    unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "original vector pointer loop successor changed"
    let tail := node.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_after_vector_pointer_loop tail

theorem source : Arm64CiliumCallerHeaderTailSource.after =
    .Ssequence (.Ssequence setup loop) after := rfl

theorem index_declared : (_i,CC.tuint) ∈ procedure.fn_temps := by decide +kernel
theorem index_not_context : _i ≠ _ctx := by decide +kernel

theorem next_label :
    (match after with
    | .Ssequence (.Slabel label _) _ => label = _arm64_l_0
    | _ => False) := rfl

def slot (high : Bool) (i : Fin 32) : Fin 64 :=
  ⟨i.val+(if high then 32 else 0),by have bound := i.isLt;cases high <;> simp_all <;> omega⟩
def headerOffset (high : Bool) (i : Fin 32) : Int :=
  (if high then 352 else 96)+8*(i.val : Int)

theorem header_slots : ∀ (high : Bool) (i : Fin 32),
    Arm64CiliumCallerHeaderVectorNullSource.offset (slot high i) = headerOffset high i ∧
    Arm64CiliumCallerHeaderVectorNullSource.field (slot high i) =
      (if high then _vector_hi else _vector_lo) := by decide +kernel

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopSource
