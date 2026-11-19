import KProgFormal.ClightRefinement.Arm64Producer

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

private def prefixParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    let target ← Lean.Elab.Term.elabTerm (← `(Arm64Entry.___a64_numeric_sp)) none
    let mut front : Array Lean.Expr := #[]
    for _ in [:256] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "raw producer no longer has the expected initializer prefix"
      let head := body.getAppArgs[0]!
      let normalized ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head)
      if normalized.isAppOfArity ``CC.Stmt.Sassign 2 then
        let lhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf normalized.getAppArgs[0]!)
        if lhs.isAppOfArity ``CC.Expr.Evar 2 then
          if ← Lean.Meta.isDefEq lhs.getAppArgs[0]! target then
            let stmts ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) front.toList
            let result ← Lean.Meta.mkAppM ``Prod.mk #[stmts, body]
            Lean.Elab.Tactic.closeMainGoal `raw_prefix_parts result
            return
      front := front.push head
      body := body.getAppArgs[1]!
    throwError "raw producer initializer prefix exceeds the extraction bound"

def cachePrefix : List CC.Stmt := prefixParts.1

theorem cache_prefix_source :
    producer.fn_body = cachePrefix.foldr CC.Stmt.Ssequence cacheStage := by rfl

private def abiComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry._arm64_sim_skb_abi).get (by decide +kernel)

/-- The only composite layout used by the initial ABI assignments. -/
def AbiLayout (world : CC.CGenv) : Prop :=
    world.genv_cenv.get Arm64Entry._arm64_sim_skb_abi = some abiComposite ∧
    CC.sizeof world.genv_cenv (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr) = 216 ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._pad0 abiComposite.co_members = .OK (0, .Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._cb abiComposite.co_members = .OK (48, .Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._pad1 abiComposite.co_members = .OK (68, .Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._data_end abiComposite.co_members = .OK (80, .Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._pad2 abiComposite.co_members = .OK (88, .Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Entry._data abiComposite.co_members = .OK (208, .Full)

theorem source_abi_layout : AbiLayout ge := by
  unfold AbiLayout
  decide +kernel

structure PrefixLocal (env : CC.Mem → CC.Env) (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty) where
  block : CC.Block
  binding : (env m).get id = some (block, ty)
  fresh : m.nextblock.toNat ≤ block.toNat
  range : CC.Mem.rangePerm (allocation m).2 block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable = true

private theorem prefix_local (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (member : (id, ty) ∈ producer.fn_vars) : Nonempty (PrefixLocal (fun m => (allocation m).1) m id ty) := by
  obtain ⟨b, binding, fresh, _, range⟩ := local_storage m id ty member
  exact ⟨⟨b, binding, fresh, range⟩⟩

def PrefixInvariant (m memory : CC.Mem) : Prop :=
  memory.access = (allocation m).2.access ∧
  memory.nextblock = (allocation m).2.nextblock ∧
  FrameBelow m.nextblock (allocation m).2 memory

section Generic
variable (ge : CC.CGenv) (f : CC.Function) (env : CC.Mem → CC.Env)
variable (abiLayout : AbiLayout ge)

private def ReadyAssignment (m : CC.Mem) (s : CC.Stmt) : Prop :=
  ∀ le memory, PrefixInvariant m memory → ∃ after,
    (∀ k, InternalRun ge 1 (.State f s k (env m) le memory)
      (.State f .Sskip k (env m) le after)) ∧ PrefixInvariant m after

private theorem local_assignment (m : CC.Mem) {id : CC.Ident} {ty : CC.Ty}
    (cell : PrefixLocal env m id ty) (lhs rhs : CC.Expr) (chunk : CC.Chunk)
    (offset : CC.Integers.Ptrofs) (input value : CC.Val)
    (mode : CC.accessMode (CC.typeof lhs) = .By_value chunk)
    (address : ∀ memory le, CC.doEvalLvalue ge (env m) le memory lhs =
      some (cell.block, offset, .Full))
    (evaluated : ∀ memory le, CC.doEvalExpr ge (env m) le memory rhs = some input)
    (cast : ∀ memory, CC.Cop.semCast input (CC.typeof rhs) (CC.typeof lhs) memory = some value)
    (lo : 0 ≤ CC.Integers.Ptrofs.unsigned offset)
    (hi : CC.Integers.Ptrofs.unsigned offset + CC.sizeChunk chunk ≤ CC.sizeof Arm64Producer.ge.genv_cenv ty)
    (align : CC.Integers.Ptrofs.unsigned offset % CC.alignChunk chunk = 0) :
    ReadyAssignment ge f env m (.Sassign lhs rhs) := by
  intro le memory invariant
  have range := CC.Mem.rangePerm_implies cell.range (by decide : CC.permOrder .Freeable .Writable = true)
  have writable : CC.Mem.validAccess memory chunk cell.block
      (CC.Integers.Ptrofs.unsigned offset) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, by simpa [align]⟩
    apply CC.Mem.rangePerm_intro
    intro o lower upper
    have lower' : (0 : Int) ≤ o := Int.le_trans lo lower
    have upper' : o < CC.sizeof Arm64Producer.ge.genv_cenv ty := Int.lt_of_lt_of_le upper hi
    have good := CC.Mem.rangePerm_perm (allocation m).2 cell.block 0
      (CC.sizeof Arm64Producer.ge.genv_cenv ty) .Cur .Writable range o lower' upper'
    simpa only [CC.Mem.perm, invariant.1] using good
  have storeExists : ∃ after, CC.Mem.storev chunk memory (.Vptr cell.block offset) value = some after := by
    change ∃ after, CC.Mem.store chunk memory cell.block
      (CC.Integers.Ptrofs.unsigned offset) value = some after
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := storeExists
  refine ⟨after, ?_, (CC.Mem.store_access stored).trans invariant.1,
    (CC.Mem.store_nextblock stored).trans invariant.2.1,
    invariant.2.2.trans (FrameBelow.store cell.fresh stored)⟩
  intro k
  have step : CC.doStep ge (.State f (.Sassign lhs rhs) k (env m) le memory) =
      some (CC.E0, .State f .Sskip k (env m) le after) := by
    simp only [CC.doStep, address, evaluated, cast, CC.doAssignLoc, mode, stored]
  exact .step trivial (CC.doStep_sound ge _ _ _ step) (.refl _)

elab "raw_prefix_chunk " n:num : term => do
  let amount := Lean.Syntax.mkNumLit (toString (n.getNat * 8))
  let term ← Lean.Elab.Term.elabTerm (← `((cachePrefix.drop $amount).take 8)) none
  let mut current := term
  let mut rows : Array Lean.Expr := #[]
  for _ in [:9] do
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
    if value.isAppOfArity ``List.nil 1 then
      return ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    unless value.isAppOfArity ``List.cons 3 do
      throwError "expected actual raw-prefix statement list"
    rows := rows.push value.getAppArgs[1]!
    current := value.getAppArgs[2]!
  throwError "raw-prefix chunk exceeds eight statements"

private theorem uint_size (ce : CC.CompositeEnv) : CC.sizeof ce CC.tuint = 4 := rfl

macro "prove_prefix_assignment " cell:ident " using " facts:ident : tactic =>
  `(tactic| (
    run_tac do
      let target ← Lean.Elab.Tactic.getMainTarget
      let args := target.getAppArgs
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf args[4]!)
      let result ← Lean.Meta.mkAppM ``ReadyAssignment #[args[0]!, args[1]!, args[2]!, args[3]!, stmt]
      let next ← (← Lean.Elab.Tactic.getMainGoal).change result
      Lean.Elab.Tactic.replaceMainGoal [next]
    apply local_assignment _ _ _ _ $cell
    case mode => rfl
    case address =>
      intro memory le
      simp only [CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, ($cell).binding, ite_true]
      simp +decide [CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar,
        CC.lvalOfField, CC.doDerefLoc, CC.accessMode, CC.typeof, CC.Cop.semBinaryOperation,
        CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr,
        ($cell).binding, ($facts).1, ($facts).2.2.1, ($facts).2.2.2.1,
        ($facts).2.2.2.2.1, ($facts).2.2.2.2.2.1, ($facts).2.2.2.2.2.2.1,
        ($facts).2.2.2.2.2.2.2,
        CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Ptrofs.zero,
        CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.mul, CC.Integers.Ptrofs.of_ints,
        CC.Integers.MI.zero, CC.Integers.MI.add, CC.Integers.MI.mul,
        CC.Integers.Int.signed, CC.Integers.MI.signed, CC.Integers.Ptrofs.repr,
        CC.sizeof, CC.tarray, CC.tptr, CC.tuchar, CC.tint, CC.Mptr, CC.Archi.ptr64]
      rfl
    case evaluated => intro memory le; rfl
    case cast => intro memory; rfl
    all_goals try simp only [uint_size]
    all_goals decide +kernel
  ))

private def chunk0 : List CC.Stmt := raw_prefix_chunk 0
private def chunk1 : List CC.Stmt := raw_prefix_chunk 1
private def chunk2 : List CC.Stmt := raw_prefix_chunk 2
private def chunk3 : List CC.Stmt := raw_prefix_chunk 3
private def chunk4 : List CC.Stmt := raw_prefix_chunk 4
private def chunk5 : List CC.Stmt := raw_prefix_chunk 5
private def chunk6 : List CC.Stmt := raw_prefix_chunk 6
private def chunk7 : List CC.Stmt := raw_prefix_chunk 7
private def chunk8 : List CC.Stmt := raw_prefix_chunk 8
private def chunk9 : List CC.Stmt := raw_prefix_chunk 9
private def chunk10 : List CC.Stmt := raw_prefix_chunk 10
private def chunk11 : List CC.Stmt := raw_prefix_chunk 11
private def chunk12 : List CC.Stmt := raw_prefix_chunk 12
private def chunk13 : List CC.Stmt := raw_prefix_chunk 13
private def chunk14 : List CC.Stmt := raw_prefix_chunk 14
private def chunk15 : List CC.Stmt := raw_prefix_chunk 15
private def chunk16 : List CC.Stmt := raw_prefix_chunk 16
private def chunk17 : List CC.Stmt := raw_prefix_chunk 17
private def chunk18 : List CC.Stmt := raw_prefix_chunk 18
private def chunk19 : List CC.Stmt := raw_prefix_chunk 19
private def chunk20 : List CC.Stmt := raw_prefix_chunk 20
private def chunk21 : List CC.Stmt := raw_prefix_chunk 21
private def chunk22 : List CC.Stmt := raw_prefix_chunk 22
private def chunk23 : List CC.Stmt := raw_prefix_chunk 23

include abiLayout

private theorem chunk0_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk0, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk0, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk1_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk1, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk1, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk2_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk2, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk2, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk3_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk3, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk3, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk4_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk4, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk4, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk5_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk5, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk5, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk6_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk6, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk6, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk7_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk7, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk7, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk8_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk8, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk8, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk9_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk9, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk9, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk10_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk10, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk10, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk11_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk11, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk11, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk12_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk12, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk12, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk13_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk13, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk13, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk14_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk14, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk14, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk15_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk15, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk15, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk16_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk16, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk16, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk17_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk17, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk17, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk18_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk18, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk18, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk19_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk19, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk19, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk20_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk20, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk20, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk21_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk21, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk21, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk22_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
 :
    ∀ stmt ∈ chunk22, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk22, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals prove_prefix_assignment abi using abiLayout

private theorem chunk23_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
    (ctx : PrefixLocal env m Arm64Entry.___a64_sim_skb_ctx
      (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr)))
    (kind : PrefixLocal env m Arm64Entry.___a64_sim_abi_kind CC.tuchar) :
    ∀ stmt ∈ chunk23, ReadyAssignment ge f env m stmt := by
  intro stmt member
  simp only [chunk23, List.mem_cons, List.not_mem_nil, or_false] at member
  rcases member with rfl | rfl | rfl | rfl | rfl
  all_goals first | prove_prefix_assignment abi using abiLayout | prove_prefix_assignment ctx using abiLayout | prove_prefix_assignment kind using abiLayout

omit abiLayout

theorem cache_prefix_length : cachePrefix.length = 189 := by decide +kernel

private theorem chunks_source : cachePrefix = chunk0 ++ (chunk1 ++ (chunk2 ++ (chunk3 ++ (chunk4 ++ (chunk5 ++ (chunk6 ++ (chunk7 ++ (chunk8 ++ (chunk9 ++ (chunk10 ++ (chunk11 ++ (chunk12 ++ (chunk13 ++ (chunk14 ++ (chunk15 ++ (chunk16 ++ (chunk17 ++ (chunk18 ++ (chunk19 ++ (chunk20 ++ (chunk21 ++ (chunk22 ++ (chunk23))))))))))))))))))))))) := by rfl

include abiLayout in
private theorem all_ready (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
    (ctx : PrefixLocal env m Arm64Entry.___a64_sim_skb_ctx
      (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr)))
    (kind : PrefixLocal env m Arm64Entry.___a64_sim_abi_kind CC.tuchar) : ∀ stmt ∈ cachePrefix, ReadyAssignment ge f env m stmt := by
  intro stmt member
  rw [chunks_source] at member
  rcases List.mem_append.mp member with hit | member
  · exact chunk0_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk1_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk2_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk3_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk4_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk5_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk6_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk7_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk8_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk9_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk10_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk11_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk12_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk13_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk14_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk15_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk16_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk17_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk18_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk19_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk20_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk21_ready ge f env abiLayout m abi stmt hit
  rcases List.mem_append.mp member with hit | member
  · exact chunk22_ready ge f env abiLayout m abi stmt hit
  exact chunk23_ready ge f env abiLayout m abi ctx kind stmt member

private theorem run_ready_list (m : CC.Mem) (front : List CC.Stmt) (rest : CC.Stmt)
    (ready : ∀ stmt ∈ front, ReadyAssignment ge f env m stmt) (le : CC.TempEnv) (k : CC.Cont)
    (memory : CC.Mem) (invariant : PrefixInvariant m memory) :
    ∃ after, InternalRun ge (3 * front.length)
      (.State f (front.foldr CC.Stmt.Ssequence rest) k (env m) le memory)
      (.State f rest k (env m) le after) ∧ PrefixInvariant m after := by
  induction front generalizing memory k with
  | nil => exact ⟨memory, .refl _, invariant⟩
  | cons head tail ih =>
    obtain ⟨middle, headRun, middleInvariant⟩ := ready head (by simp) le memory invariant
    have enter : InternalRun ge 1
        (.State f (.Ssequence head (tail.foldr CC.Stmt.Ssequence rest)) k
          (env m) le memory)
        (.State f head (.Kseq (tail.foldr CC.Stmt.Ssequence rest) k)
          (env m) le memory) :=
      .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
    have leave : InternalRun ge 1
        (.State f .Sskip (.Kseq (tail.foldr CC.Stmt.Ssequence rest) k)
          (env m) le middle)
        (.State f (tail.foldr CC.Stmt.Ssequence rest) k (env m) le middle) :=
      .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
    obtain ⟨after, restRun, finalInvariant⟩ := ih
      (fun stmt member => ready stmt (List.mem_cons.mpr (.inr member))) k middle middleInvariant
    have composed := (enter.trans (headRun _)).trans (leave.trans restRun)
    refine ⟨after, ?_, finalInvariant⟩
    have count : 3 * (head :: tail).length = (1 + 1) + (1 + 3 * tail.length) := by
      simp only [List.length_cons]
      omega
    rw [count]
    exact composed

include abiLayout in
/-- Execute the real initial assignments in an arbitrary function and local
binding, using only the ABI record and the three allocated local cells. -/
theorem prefix_body_bound (m : CC.Mem)
    (abi : PrefixLocal env m Arm64Entry.___a64_sim_abi
      (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))
    (ctx : PrefixLocal env m Arm64Entry.___a64_sim_skb_ctx
      (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr)))
    (kind : PrefixLocal env m Arm64Entry.___a64_sim_abi_kind CC.tuchar)
    (rest : CC.Stmt) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after, InternalRun ge 567
      (.State f (cachePrefix.foldr CC.Stmt.Ssequence rest) k (env m) le (allocation m).2)
      (.State f rest k (env m) le after) ∧ PrefixInvariant m after := by
  obtain ⟨after, run, invariant⟩ := run_ready_list ge f env m cachePrefix rest
    (all_ready ge f env abiLayout m abi ctx kind) le k (allocation m).2
    ⟨rfl, rfl, FrameBelow.refl _ _⟩
  exact ⟨after, by simpa only [cache_prefix_length] using run, invariant⟩

end Generic

section Bound
variable (ge : CC.CGenv) (layout : ge.genv_cenv = Arm64Producer.ge.genv_cenv)

include layout in
/-- The actual raw producer reaches its cache-initializer stage after entry
and all 189 preceding assignments, without caller permission or prefix-state
premises. All original caller blocks and allocation permissions are retained. -/
theorem prefix_internal_bound (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun ge 568
        (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.State producer cacheStage k (allocation m).1 (initialTemps ctx continuation) before) ∧
      before.access = (allocation m).2.access ∧ before.nextblock = (allocation m).2.nextblock ∧
      FrameBelow m.nextblock m before := by
  obtain ⟨abi⟩ := prefix_local m Arm64Entry.___a64_sim_abi
    (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr) (by decide +kernel)
  obtain ⟨ctxLocal⟩ := prefix_local m Arm64Entry.___a64_sim_skb_ctx
    (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr)) (by decide +kernel)
  obtain ⟨kind⟩ := prefix_local m Arm64Entry.___a64_sim_abi_kind CC.tuchar (by decide +kernel)
  have abiLayout : AbiLayout ge := by
    unfold AbiLayout
    rw [layout]
    exact source_abi_layout
  obtain ⟨before, run, access, next, frame⟩ := prefix_body_bound ge producer
    (fun m => (allocation m).1) abiLayout m abi ctxLocal kind cacheStage
    (initialTemps ctx continuation) k
  have prefixRun : InternalRun ge 567
      (.State producer producer.fn_body k (allocation m).1
        (initialTemps ctx continuation) (allocation m).2)
      (.State producer cacheStage k (allocation m).1 (initialTemps ctx continuation) before) := by
    rw [cache_prefix_source]
    exact run
  exact ⟨before, (entry_internal_bound ge layout m ctx continuation k).trans prefixRun, access, next,
    (entry_frame m).trans frame⟩

include layout in
/-- The complete actual prefix through the four cache initializers. Both
invalid cache words and validity bytes read zero after 580 internal steps;
caller memory, all permissions and allocation identity are framed exactly. -/
theorem entry_caches_initialized_bound (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ after, InternalRun ge 580
        (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.State producer afterCacheStage k (allocation m).1 (initialTemps ctx continuation) after) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨before, prefixRun, access, next, frame⟩ := prefix_internal_bound ge layout m ctx continuation k
  obtain ⟨after, initRun, initialized, initFrame, initAccess, initNext⟩ :=
    initialize_caches_bound ge m before k (initialTemps ctx continuation) access
  exact ⟨after, prefixRun.trans initRun, initialized, frame.trans initFrame,
    initAccess.trans access, initNext.trans next⟩

end Bound

theorem prefix_internal (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ before, InternalRun ge 568
        (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.State producer cacheStage k (allocation m).1 (initialTemps ctx continuation) before) ∧
      before.access = (allocation m).2.access ∧ before.nextblock = (allocation m).2.nextblock ∧
      FrameBelow m.nextblock m before :=
  prefix_internal_bound ge rfl m ctx continuation k

theorem entry_caches_initialized (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    ∃ after, InternalRun ge 580
        (.Callstate (.Internal producer) [ctx, continuation] k m)
        (.State producer afterCacheStage k (allocation m).1 (initialTemps ctx continuation) after) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock :=
  entry_caches_initialized_bound ge rfl m ctx continuation k

end KProgFormal.ClightRefinement.Arm64Producer
