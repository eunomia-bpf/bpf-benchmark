import KProgFormal.ClightRefinement.X86ProducerEntry
import KProgFormal.ClightRefinement.X86ProducerLayout

namespace KProgFormal.ClightRefinement.X86ProducerAbiSource
open X86ProducerHeaderSource (producer)

def abiType : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_skb_abi CC.noattr

def group (i : Fin 187) : Fin 6 :=
  if i.val < 48 then 0 else if i.val < 53 then 1 else if i.val < 65 then 2
  else if i.val = 65 then 3 else if i.val < 186 then 4 else 5

def fieldName (g : Fin 6) : CC.Ident :=
  [X86_program_profile_bpf._pad0, X86_program_profile_bpf._cb, X86_program_profile_bpf._pad1,
   X86_program_profile_bpf._data_end, X86_program_profile_bpf._pad2, X86_program_profile_bpf._data][g]
def element (g : Fin 6) : CC.Ty := if g.val = 1 then CC.tuint else CC.tuchar
def count (g : Fin 6) : Nat := [48, 5, 12, 0, 120, 0][g]
def fieldType (g : Fin 6) : CC.Ty :=
  if g.val = 3 ∨ g.val = 5 then CC.tptr CC.tvoid else CC.tarray (element g) (count g)
def base (g : Fin 6) : Int := [0, 48, 68, 80, 88, 208][g]
def index (i : Fin 187) : Nat :=
  if i.val < 48 then i.val else if i.val < 53 then i.val - 48
  else if i.val < 65 then i.val - 53 else if i.val < 186 then i.val - 66 else 0

def field (g : Fin 6) : CC.Expr :=
  .Efield (.Evar X86_program_profile_bpf.___x86_sim_abi abiType) (fieldName g) (fieldType g)
def target (i : Fin 187) : CC.Expr :=
  if (group i).val = 3 ∨ (group i).val = 5 then field (group i)
  else .Ederef (.Ebinop .Oadd (field (group i))
    (.Econst_int (CC.Integers.Int.repr (index i)) CC.tint) (CC.tptr (element (group i)))) (element (group i))
def rhs (i : Fin 187) : CC.Expr :=
  if (group i).val = 3 ∨ (group i).val = 5 then
    .Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tint) (CC.tptr CC.tvoid)
  else .Econst_int (CC.Integers.Int.repr 0) CC.tint

def assignment (i : Fin 187) : CC.Stmt := .Sassign (target i) (rhs i)
def chunk (i : Fin 187) : CC.Chunk :=
  if (group i).val = 3 ∨ (group i).val = 5 then CC.Mptr
  else if (group i).val = 1 then .Mint32 else .Mint8unsigned
def offset (i : Fin 187) : Int := base (group i) +
  (if (group i).val = 3 ∨ (group i).val = 5 then 0 else (if (group i).val = 1 then 4 else 1) * (index i : Int))
def value (i : Fin 187) : CC.Val :=
  if (group i).val = 3 ∨ (group i).val = 5 then .Vlong 0 else .Vint 0

private def suffix : CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    for _ in [:187] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original x86 ABI initializer changed"
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_abi_suffix body

def afterAbi : CC.Stmt := suffix

/-- These187 actual typed assignments initialize every declared ABI field and
padding array before the first simulator-context temporary assignment. -/
theorem source_abi : producer.fn_body = (List.ofFn assignment).foldr CC.Stmt.Ssequence afterAbi := by
  run_tac do
    let source ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    (← Lean.Elab.Tactic.getMainGoal).assign (← Lean.Meta.mkEqRefl source)
    Lean.Elab.Tactic.replaceMainGoal []

end KProgFormal.ClightRefinement.X86ProducerAbiSource
