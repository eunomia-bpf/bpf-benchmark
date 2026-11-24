import KProgFormal.ClightRefinement.X86ProducerCacheAllocation

namespace KProgFormal.ClightRefinement.X86ProducerHeaderSource

def producer : CC.Function := X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp

def headerType : CC.Ty := .Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr

def localName (i : Fin 24) : CC.Ident :=
  [X86_program_profile_bpf.___x86_local_gprs, X86_program_profile_bpf.___x86_stack_mem,
   X86_program_profile_bpf.___x86_stack_value_tag_0, X86_program_profile_bpf.___x86_stack_value_ptr_0,
   X86_program_profile_bpf.___x86_stack_value_tag_1, X86_program_profile_bpf.___x86_stack_value_ptr_1,
   X86_program_profile_bpf.___x86_stack_value_tag_2, X86_program_profile_bpf.___x86_stack_value_ptr_2,
   X86_program_profile_bpf.___x86_stack_value_tag_3, X86_program_profile_bpf.___x86_stack_value_ptr_3,
   X86_program_profile_bpf.___x86_stack_value_tag_4, X86_program_profile_bpf.___x86_stack_value_ptr_4,
   X86_program_profile_bpf.___x86_stack_value_tag_5, X86_program_profile_bpf.___x86_stack_value_ptr_5,
   X86_program_profile_bpf.___x86_native_stack_base, X86_program_profile_bpf.___x86_cf,
   X86_program_profile_bpf.___x86_zf, X86_program_profile_bpf.___x86_sf, X86_program_profile_bpf.___x86_of,
   X86_program_profile_bpf.___x86_pf, X86_program_profile_bpf.___x86_af,
   X86_program_profile_bpf.___x86_xmm0_lo, X86_program_profile_bpf.___x86_xmm0_hi,
   X86_program_profile_bpf.___x86_sim_ret_addr][i]

def localType (i : Fin 24) : CC.Ty :=
  if i.val = 0 then .Tunion X86_program_profile_bpf._x86_sim_register_cells CC.noattr
  else if i.val = 1 then .Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr
  else if i.val < 14 then if i.val % 2 = 0 then CC.tuchar else CC.tptr CC.tvoid
  else if i.val = 14 ∨ 21 ≤ i.val then CC.tulong else CC.tuchar

def pointerType (i : Fin 24) : CC.Ty :=
  if i.val = 0 then CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
  else CC.tptr (localType i)

def fieldName (i : Fin 24) : CC.Ident :=
  [X86_program_profile_bpf._cells, X86_program_profile_bpf._stack,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._values, X86_program_profile_bpf._values,
   X86_program_profile_bpf._native_stack_base, X86_program_profile_bpf._cf,
   X86_program_profile_bpf._zf, X86_program_profile_bpf._sf, X86_program_profile_bpf._of,
   X86_program_profile_bpf._pf, X86_program_profile_bpf._af,
   X86_program_profile_bpf._xmm0_lo, X86_program_profile_bpf._xmm0_hi,
   X86_program_profile_bpf._sim_ret_addr][i]

def target (i : Fin 24) : CC.Expr :=
  if 2 ≤ i.val ∧ i.val < 14 then
    .Efield (.Ederef (.Ebinop .Oadd
      (.Efield (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType)
        X86_program_profile_bpf._values
        (CC.tarray (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr) 6))
      (.Econst_int (CC.Integers.Int.repr ((i.val - 2) / 2)) CC.tint)
      (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr)))
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr))
      (if i.val % 2 = 0 then X86_program_profile_bpf._tag else X86_program_profile_bpf._pointer) (pointerType i)
  else .Efield (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType) (fieldName i) (pointerType i)

def rhs (i : Fin 24) : CC.Expr :=
  if i.val = 0 then .Efield (.Evar (localName i) (localType i))
    X86_program_profile_bpf._gpr_cells
    (CC.tarray (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) 16)
  else .Eaddrof (.Evar (localName i) (localType i)) (pointerType i)

def assignment (i : Fin 24) : CC.Stmt := .Sassign (target i) (rhs i)

private def prefixParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.s_x86_program_profile_x86_sim_xdp_30)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:40] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original producer header start missing"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      if head.isAppOfArity ``CC.Stmt.Sassign 2 then
        let lhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head.getAppArgs[0]!)
        if lhs.isAppOfArity ``CC.Expr.Efield 3 && lhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._cells then
          let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
          Lean.Elab.Tactic.closeMainGoal `actual_x86_header_cut (← Lean.Meta.mkAppM ``Prod.mk #[front, body])
          return
      rows := rows.push head
      body := body.getAppArgs[1]!
    throwError "original producer header start missing"

def beforeHeader : List CC.Stmt := prefixParts.1
def headerStart : CC.Stmt := prefixParts.2

private def headerParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(headerStart)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:24] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original producer pointer stores changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      rows := rows.push head
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_x86_header_rows (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def afterHeader : CC.Stmt := headerParts.2

/-- The chosen header cut is the actual suffix after the original input/flag
setup statements. This identity does not assert that the prefix has run. -/
theorem source_prefix : X86_program_profile_bpf.s_x86_program_profile_x86_sim_xdp_30 =
    beforeHeader.foldr CC.Stmt.Ssequence headerStart := by rfl

/-- Every typed target/source row matches an original exported assignment. -/
theorem source_header : headerStart = (List.ofFn assignment).foldr CC.Stmt.Ssequence afterHeader := by
  have rows : headerParts.1 = List.ofFn assignment := by rfl
  have source : headerStart = headerParts.1.foldr CC.Stmt.Ssequence afterHeader := rfl
  rw [rows] at source
  exact source

end KProgFormal.ClightRefinement.X86ProducerHeaderSource
