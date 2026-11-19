import KProgFormal.ClightRefinement.Arm64ProducerHeaderVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

structure TailDeclaration where
  name : CC.Ident
  ty : CC.Ty
  rhs : CC.Expr

private def tailParts : List TailDeclaration × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterNullVectorPointers)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:16] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "remaining header initializer sequence changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      unless head.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "remaining header initializer is not a store"
      let target ← Lean.Meta.withTransparency .all (Lean.Meta.whnf head.getAppArgs[0]!)
      unless target.isAppOfArity ``CC.Expr.Efield 3 do
        throwError "remaining header initializer is not a field"
      rows := rows.push (← Lean.Meta.mkAppM ``TailDeclaration.mk
        #[target.getAppArgs[1]!, target.getAppArgs[2]!, head.getAppArgs[1]!])
      body := body.getAppArgs[1]!
    let front ← Lean.Meta.mkListLit (Lean.mkConst ``TailDeclaration) rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_remaining_header (← Lean.Meta.mkAppM ``Prod.mk #[front, body])

def tailDeclaration (i : Fin 16) : TailDeclaration := tailParts.1[i.val]'(by change i.val < 16; exact i.isLt)
def tailTarget (i : Fin 16) : CC.Expr :=
  .Efield (.Evar Arm64Entry._entry headerType) (tailDeclaration i).name (tailDeclaration i).ty
def tailStore (i : Fin 16) : CC.Stmt := .Sassign (tailTarget i) (tailDeclaration i).rhs
def beforeVectorLoop : CC.Stmt := tailParts.2

theorem tail_source : afterNullVectorPointers =
    (List.ofFn tailStore).foldr CC.Stmt.Ssequence beforeVectorLoop := by rfl

def tailOffset (i : Fin 16) : Int :=
  [608,616,624,632,640,648,656,660,664,672,680,688,696,704,712,720][i]
def tailChunk (i : Fin 16) : CC.Chunk := if 6 ≤ i.val ∧ i.val < 9 then .Mint32 else .Mint64

private def tailComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry._kprog_arm64_entry).get (by decide +kernel)

private theorem tail_cases : ∀ i : Fin 16,
  i=⟨0, by decide⟩ ∨ i=⟨1, by decide⟩ ∨ i=⟨2, by decide⟩ ∨ i=⟨3, by decide⟩ ∨ i=⟨4, by decide⟩ ∨ i=⟨5, by decide⟩ ∨ i=⟨6, by decide⟩ ∨ i=⟨7, by decide⟩ ∨ i=⟨8, by decide⟩ ∨ i=⟨9, by decide⟩ ∨ i=⟨10, by decide⟩ ∨ i=⟨11, by decide⟩ ∨ i=⟨12, by decide⟩ ∨ i=⟨13, by decide⟩ ∨ i=⟨14, by decide⟩ ∨ i=⟨15, by decide⟩ := by decide +kernel

theorem tail_layout :
    ge.genv_cenv.get Arm64Entry._kprog_arm64_entry = some tailComposite ∧
    (∀ i, CC.fieldOffset ge.genv_cenv (tailDeclaration i).name tailComposite.co_members = .OK (tailOffset i, .Full)) ∧
    (∀ i, CC.accessMode (tailDeclaration i).ty = .By_value (tailChunk i)) ∧
    (∀ i, 608 ≤ tailOffset i ∧ tailOffset i + CC.sizeChunk (tailChunk i) ≤ 728 ∧
      tailOffset i % CC.alignChunk (tailChunk i) = 0) ∧
    (∀ i j, i ≠ j → tailOffset i + CC.sizeChunk (tailChunk i) ≤ tailOffset j ∨
      tailOffset j + CC.sizeChunk (tailChunk j) ≤ tailOffset i) := by
  refine ⟨by decide +kernel, by decide +kernel, ?_, by decide +kernel, by decide +kernel⟩
  intro i
  rcases tail_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

theorem tail_offsets : ∀ i, CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (tailOffset i)) = tailOffset i := by decide +kernel

def tailLocalName (i : Fin 9) : CC.Ident :=
  [Arm64Entry.___a64_stack, Arm64Entry.___a64_stack_payload, Arm64Entry.___a64_stack_tag,
   Arm64Entry.___a64_sim_helper_ctx, Arm64Entry.___a64_sim_helper_abi_base,
   Arm64Entry.___a64_sim_is_xdp, Arm64Entry.___a64_sim_abi_kind,
   Arm64Entry.___a64_sim_skb_ctx, Arm64Entry.___a64_sim_abi][i]

def tailLocalType (i : Fin 9) : CC.Ty :=
  [CC.tvolatile (.Tunion Arm64Entry.__2856 CC.noattr), CC.tarray (CC.tvolatile CC.tulong) 20,
   CC.tarray CC.tuchar 24, CC.tptr CC.tvoid, CC.tptr CC.tvoid, CC.tuchar, CC.tuchar,
   CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr),
   .Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr][i]

structure TailLocal (m : CC.Mem) (i : Fin 9) where
  block : CC.Block
  binding : (allocation m).1.get (tailLocalName i) = some (block, tailLocalType i)

theorem tail_local (m : CC.Mem) (i : Fin 9) : Nonempty (TailLocal m i) := by
  have present : ∀ i, (tailLocalName i, tailLocalType i) ∈ producer.fn_vars := by decide +kernel
  obtain ⟨block, binding, _, _, _⟩ := local_storage m _ _ (present i)
  exact ⟨⟨block, binding⟩⟩

def payloadCallbackName (store : Bool) : CC.Ident :=
  if store then Arm64Entry._kprog_arm64_payload_store else Arm64Entry._kprog_arm64_payload_load

def payloadCallbackFunction (store : Bool) : CC.FunDef :=
  .Internal (if store then Arm64Entry.f_kprog_arm64_payload_store else Arm64Entry.f_kprog_arm64_payload_load)

def payloadCallbackBlock (store : Bool) : CC.Block := CC.Positive.ofNat (if store then 185 else 184)

theorem payload_callback_binding (store : Bool) :
    CC.Genv.findSymbol ge.genv_genv (payloadCallbackName store) = some (payloadCallbackBlock store) ∧
    CC.Genv.findFunctPtr ge.genv_genv (payloadCallbackBlock store) = some (payloadCallbackFunction store) := by
  cases store
  · simpa [ge, payloadCallbackName, payloadCallbackBlock, payloadCallbackFunction,
      Binding.functionName, Binding.functionBody, Binding.functionBlock, Fin.getElem_fin,
      Bool.false_eq_true, ite_false, ite_true, List.get_eq_getElem, List.getElem_cons] using
        Binding.appended_functions ⟨0, by decide⟩
  · simpa [ge, payloadCallbackName, payloadCallbackBlock, payloadCallbackFunction,
      Binding.functionName, Binding.functionBody, Binding.functionBlock, Fin.getElem_fin,
      Bool.false_eq_true, ite_false, ite_true, List.get_eq_getElem, List.getElem_cons] using
        Binding.appended_functions ⟨1, by decide⟩

def tailValue {m : CC.Mem} (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) : CC.Val :=
  match i.val with
  | 0 | 1 => .Vptr (sources 0).block 0
  | 2 => .Vptr (sources 1).block 0
  | 3 => .Vptr (payloadCallbackBlock false) 0
  | 4 => .Vptr (payloadCallbackBlock true) 0
  | 5 => .Vptr (sources 2).block 0
  | 6 => .Vint 160
  | 7 => .Vint 20
  | 8 => .Vint 24
  | 9 => .Vlong 96
  | 10 => .Vptr (sources 3).block 0
  | 11 => .Vptr (sources 4).block 0
  | 12 => .Vptr (sources 5).block 0
  | 13 => .Vptr (sources 6).block 0
  | 14 => .Vptr (sources 7).block 0
  | _ => .Vptr (sources 8).block 0

def tailInputValue {m : CC.Mem} (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) : CC.Val :=
  if i.val = 6 then .Vlong 160 else if i.val = 7 then .Vlong 20 else
  if i.val = 8 then .Vlong 24 else tailValue sources i

private def stackComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Entry.__2856).get (by decide +kernel)
private theorem stack_layout :
    ge.genv_cenv.get Arm64Entry.__2856 = some stackComposite ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Entry._b stackComposite.co_members = .OK (0,.Full) ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Entry._q stackComposite.co_members = .OK (0,.Full) := by decide +kernel

private theorem tail_lvalue (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal m) (i : Fin 16) :
    CC.doEvalLvalue world (allocation m).1 le before (tailTarget i) =
      some (entry.block, CC.Integers.Ptrofs.repr (tailOffset i), .Full) := by
  simp [tailTarget, headerType, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar,
    CC.doDerefLoc, CC.lvalOfField, CC.typeof, CC.accessMode, entry.binding, layout,
    tail_layout.1, tail_layout.2.1, CC.Integers.Ptrofs.add,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.Integers.MI.add]
  all_goals
    apply congrArg (fun ofs => (ofs, CC.Bitfield.Full))
    exact BitVec.zero_add _

private theorem tail_rhs_eval_0 (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) (which : i = ⟨0, by decide⟩ ∨ i = ⟨1, by decide⟩ ∨ i = ⟨2, by decide⟩ ∨ i = ⟨3, by decide⟩) :
    CC.doEvalExpr world (allocation m).1 le before (tailDeclaration i).rhs = some (tailInputValue sources i) := by
  have unshadowed : ∀ store, (allocation m).1.get (payloadCallbackName store) = none := by
    intro store
    have absent : payloadCallbackName store ∉ CC.varNames producer.fn_vars := by cases store <;> decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) absent
  have uload : (allocation m).1.get Arm64Entry._kprog_arm64_payload_load = none := unshadowed false
  have ustore : (allocation m).1.get Arm64Entry._kprog_arm64_payload_store = none := unshadowed true
  have sload : CC.Genv.findSymbol world.genv_genv Arm64Entry._kprog_arm64_payload_load =
      some (payloadCallbackBlock false) := symbols false
  have sstore : CC.Genv.findSymbol world.genv_genv Arm64Entry._kprog_arm64_payload_store =
      some (payloadCallbackBlock true) := symbols true
  have b0 : (allocation m).1.get Arm64Entry.___a64_stack = some ((sources 0).block, CC.tvolatile (.Tunion Arm64Entry.__2856 CC.noattr)) := (sources 0).binding
  have b1 : (allocation m).1.get Arm64Entry.___a64_stack_payload = some ((sources 1).block, CC.tarray (CC.tvolatile CC.tulong) 20) := (sources 1).binding
  rcases which with rfl | rfl | rfl | rfl
  all_goals simp +decide [tailDeclaration, tailParts, tailValue, tailInputValue, CC.doEvalExpr,
    CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof,
    CC.accessMode, b0,b1, layout, stack_layout.1, stack_layout.2.1,
    stack_layout.2.2, uload, ustore, sload, sstore, CC.tvolatile, CC.tattr, CC.tarray,
    CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add,
    CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem tail_rhs_eval_1 (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) (which : i = ⟨4, by decide⟩ ∨ i = ⟨5, by decide⟩ ∨ i = ⟨6, by decide⟩ ∨ i = ⟨7, by decide⟩) :
    CC.doEvalExpr world (allocation m).1 le before (tailDeclaration i).rhs = some (tailInputValue sources i) := by
  have unshadowed : ∀ store, (allocation m).1.get (payloadCallbackName store) = none := by
    intro store
    have absent : payloadCallbackName store ∉ CC.varNames producer.fn_vars := by cases store <;> decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) absent
  have uload : (allocation m).1.get Arm64Entry._kprog_arm64_payload_load = none := unshadowed false
  have ustore : (allocation m).1.get Arm64Entry._kprog_arm64_payload_store = none := unshadowed true
  have sload : CC.Genv.findSymbol world.genv_genv Arm64Entry._kprog_arm64_payload_load =
      some (payloadCallbackBlock false) := symbols false
  have sstore : CC.Genv.findSymbol world.genv_genv Arm64Entry._kprog_arm64_payload_store =
      some (payloadCallbackBlock true) := symbols true
  have b2 : (allocation m).1.get Arm64Entry.___a64_stack_tag = some ((sources 2).block, CC.tarray CC.tuchar 24) := (sources 2).binding
  rcases which with rfl | rfl | rfl | rfl
  all_goals simp +decide [tailDeclaration, tailParts, tailValue, tailInputValue, CC.doEvalExpr,
    CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof,
    CC.accessMode, b2, layout, stack_layout.1, stack_layout.2.1,
    stack_layout.2.2, uload, ustore, sload, sstore, CC.tvolatile, CC.tarray,
    CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add,
    CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem tail_rhs_eval_2 (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) (which : i = ⟨8, by decide⟩ ∨ i = ⟨9, by decide⟩ ∨ i = ⟨10, by decide⟩ ∨ i = ⟨11, by decide⟩) :
    CC.doEvalExpr world (allocation m).1 le before (tailDeclaration i).rhs = some (tailInputValue sources i) := by
  have b3 : (allocation m).1.get Arm64Entry.___a64_sim_helper_ctx = some ((sources 3).block, CC.tptr CC.tvoid) := (sources 3).binding
  have b4 : (allocation m).1.get Arm64Entry.___a64_sim_helper_abi_base = some ((sources 4).block, CC.tptr CC.tvoid) := (sources 4).binding
  rcases which with rfl | rfl | rfl | rfl
  all_goals simp +decide [tailDeclaration, tailParts, tailValue, tailInputValue, CC.doEvalExpr,
    CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof,
    CC.accessMode, b3,b4, stack_layout.1, stack_layout.2.1,
    stack_layout.2.2, CC.tvolatile, CC.tarray,
    CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add,
    CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem bound_local_address (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv)
    (name : CC.Ident) (ty addressTy : CC.Ty) (block : CC.Block)
    (binding : (allocation m).1.get name = some (block,ty)) :
    CC.doEvalExpr world (allocation m).1 le before (.Eaddrof (.Evar name ty) addressTy) = some (.Vptr block 0) := by
  simp [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, binding,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]

private theorem tail_rhs_eval_3 (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16)
    (which : i=⟨12,by decide⟩ ∨ i=⟨13,by decide⟩ ∨ i=⟨14,by decide⟩ ∨ i=⟨15,by decide⟩) :
    CC.doEvalExpr world (allocation m).1 le before (tailDeclaration i).rhs = some (tailInputValue sources i) := by
  rcases which with rfl | rfl | rfl | rfl
  · change CC.doEvalExpr world (allocation m).1 le before
      (.Eaddrof (.Evar Arm64Entry.___a64_sim_is_xdp (CC.tuchar)) (CC.tptr (CC.tuchar))) = some (.Vptr (sources 5).block 0)
    exact bound_local_address world m before le _ _ _ _ (sources 5).binding
  · change CC.doEvalExpr world (allocation m).1 le before
      (.Eaddrof (.Evar Arm64Entry.___a64_sim_abi_kind (CC.tuchar)) (CC.tptr (CC.tuchar))) = some (.Vptr (sources 6).block 0)
    exact bound_local_address world m before le _ _ _ _ (sources 6).binding
  · change CC.doEvalExpr world (allocation m).1 le before
      (.Eaddrof (.Evar Arm64Entry.___a64_sim_skb_ctx (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr))) (CC.tptr (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr)))) = some (.Vptr (sources 7).block 0)
    exact bound_local_address world m before le _ _ _ _ (sources 7).binding
  · change CC.doEvalExpr world (allocation m).1 le before
      (.Eaddrof (.Evar Arm64Entry.___a64_sim_abi (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr)) (CC.tptr (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr))) = some (.Vptr (sources 8).block 0)
    exact bound_local_address world m before le _ _ _ _ (sources 8).binding

private theorem tail_rhs_eval (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) :
    CC.doEvalExpr world (allocation m).1 le before (tailDeclaration i).rhs = some (tailInputValue sources i) := by
  rcases tail_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact tail_rhs_eval_0 world layout symbols m before le sources 0 (by decide +kernel)
  · exact tail_rhs_eval_0 world layout symbols m before le sources 1 (by decide +kernel)
  · exact tail_rhs_eval_0 world layout symbols m before le sources 2 (by decide +kernel)
  · exact tail_rhs_eval_0 world layout symbols m before le sources 3 (by decide +kernel)
  · exact tail_rhs_eval_1 world layout symbols m before le sources 4 (by decide +kernel)
  · exact tail_rhs_eval_1 world layout symbols m before le sources 5 (by decide +kernel)
  · exact tail_rhs_eval_1 world layout symbols m before le sources 6 (by decide +kernel)
  · exact tail_rhs_eval_1 world layout symbols m before le sources 7 (by decide +kernel)
  · exact tail_rhs_eval_2 world m before le sources 8 (by decide +kernel)
  · exact tail_rhs_eval_2 world m before le sources 9 (by decide +kernel)
  · exact tail_rhs_eval_2 world m before le sources 10 (by decide +kernel)
  · exact tail_rhs_eval_2 world m before le sources 11 (by decide +kernel)
  · exact tail_rhs_eval_3 world m before le sources 12 (by decide +kernel)
  · exact tail_rhs_eval_3 world m before le sources 13 (by decide +kernel)
  · exact tail_rhs_eval_3 world m before le sources 14 (by decide +kernel)
  · exact tail_rhs_eval_3 world m before le sources 15 (by decide +kernel)

private theorem tail_rhs_cast (m before : CC.Mem)
    (sources : (i : Fin 9) → TailLocal m i) (i : Fin 16) :
    CC.Cop.semCast (tailInputValue sources i) (CC.typeof (tailDeclaration i).rhs)
      (tailDeclaration i).ty before = some (tailValue sources i) ∧
    CC.Val.loadResult (tailChunk i) (tailValue sources i) = tailValue sources i := by
  rcases tail_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> constructor <;> rfl

private theorem tail_write (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (sources : (i : Fin 9) → TailLocal m i)
    (i : Fin 16) (rest : CC.Stmt) (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State producer (.Ssequence (tailStore i) rest) k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i) ∧
      (∀ j : Fin 16, j ≠ i → CC.Mem.load (tailChunk j) after entry.block (tailOffset j) =
        CC.Mem.load (tailChunk j) before entry.block (tailOffset j)) ∧
      (∀ j : Fin 76, CC.Mem.load .Mint64 after entry.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have bounds := tail_layout.2.2.2.1 i
  have writable : CC.Mem.validAccess before (tailChunk i) entry.block (tailOffset i) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        rw [null_vector_layout.2.2.2]
        omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · simp only [bounds.2.2, beq_self_eq_true]
  have existsStore : ∃ after, CC.Mem.store (tailChunk i) before entry.block (tailOffset i)
      (tailValue sources i) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev (tailChunk i) before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (tailOffset i))) (tailValue sources i) = some after := by
    simpa only [CC.Mem.storev, tail_offsets] using stored
  have target := tail_lvalue world layout m before le entry i
  have rhs := tail_rhs_eval world layout symbols m before le sources i
  have cast := tail_rhs_cast m before sources i
  have assigned : CC.doStep world
      (.State producer (tailStore i) (.Kseq rest k) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    have targetType : CC.typeof (tailTarget i) = (tailDeclaration i).ty := rfl
    simp only [tailStore, CC.doStep, target, rhs, targetType, cast.1,
      CC.doAssignLoc, tail_layout.2.2.1 i]
    change (match CC.Mem.storev (tailChunk i) before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (tailOffset i))) (tailValue sources i) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have run : InternalRun world 3
      (.State producer (.Ssequence (tailStore i) rest) k (allocation m).1 le before)
      (.State producer rest k (allocation m).1 le after) :=
    .step trivial (CC.doStep_sound world _ _ _ rfl)
      (.step trivial (CC.doStep_sound world _ _ _ assigned)
        (.step trivial (CC.doStep_sound world _ _ _ rfl) (.refl _)))
  refine ⟨after, run, ?_, ?_, ?_, ?_, FrameBelow.store entry.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa only [cast.2] using CC.Mem.load_store_same stored
  · intro j different
    exact CC.Mem.load_store_other stored (tailChunk j) entry.block (tailOffset j)
      (.inr (tail_layout.2.2.2.2 j i different))
  · intro j
    apply CC.Mem.load_store_other stored
    right; left
    have bound := j.isLt
    change 8 * (j.val : Int) + 8 ≤ tailOffset i
    omega
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound entry.binding different))

private theorem run_tail (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m : CC.Mem) (entry : HeaderLocal m)
    (sources : (i : Fin 9) → TailLocal m i) (rows : List (Fin 16)) (rest : CC.Stmt)
    (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State producer (rows.foldr (fun i next => .Ssequence (tailStore i) next) rest)
          k (allocation m).1 le before)
        (.State producer rest k (allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ i ∉ rows, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        CC.Mem.load (tailChunk i) before entry.block (tailOffset i)) ∧
      (∀ j : Fin 76, CC.Mem.load .Mint64 after entry.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro j; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headPrefix, headLocals, headFrame, headAccess, headNext⟩ :=
      tail_write world layout symbols m before le k entry sources head
        (tail.foldr (fun i next => .Ssequence (tailStore i) next) rest) access
    obtain ⟨after, tailRun, tailRead, tailOther, tailPrefix, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one,
        Nat.add_comm] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have notHead : i ≠ head := by intro same; apply absent; simp [same]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i notHead)
    · intro j
      exact (tailPrefix j).trans (headPrefix j)
    · intro id ty block bound different chunk ofs
      exact (tailLocals id ty block bound different chunk ofs).trans
        (headLocals id ty block bound different chunk ofs)

/-- Actual remaining header stores, including volatile-storage addresses,
callback pointers and the exact profile scalar casts. -/
theorem tail_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun world 48 (.State producer afterNullVectorPointers k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ j : Fin 76, CC.Mem.load .Mint64 after entry.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  let sources : (i : Fin 9) → TailLocal m i := fun i => Classical.choice (tail_local m i)
  obtain ⟨after, run, read, _, prefixReads, other, frame, finalAccess, next⟩ :=
    run_tail world layout symbols m entry sources (List.finRange 16) beforeVectorLoop le k before access
  refine ⟨sources, after, ?_, (fun i => read i (List.mem_finRange i)), prefixReads, other, frame, finalAccess, next⟩
  have mapped : List.ofFn tailStore = (List.finRange 16).map tailStore := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [tail_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

theorem tail_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun ge 48 (.State producer afterNullVectorPointers k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ j : Fin 76, CC.Mem.load .Mint64 after entry.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  tail_initialized_bound ge rfl (fun store => (payload_callback_binding store).1) m before entry le k access

/-- Complete actual header construction up to the vector-pointer loop, with
all 92 typed readbacks, using the same allocated entry and source locals. -/
theorem header_initialized_before_loop_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun world 276 (.State producer afterContext k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, middle, headRun, scalarReads, nullReads, headLocals, headFrame, headAccess, headNext⟩ :=
    header_and_null_vector_pointers_bound world layout m before le k access
  obtain ⟨sources, after, tailRun, tailReads, prefixReads, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
    tail_initialized_bound world layout symbols m middle entry le k (headAccess.trans access)
  refine ⟨entry, cells, sources, after, headRun.trans tailRun, ?_, ?_, tailReads, ?_,
    headFrame.trans tailFrame, tailAccess.trans headAccess, tailNext.trans headNext⟩
  · intro i
    have keep := prefixReads ⟨i.val, by have := i.isLt; omega⟩
    exact keep.trans (scalarReads i)
  · intro i
    have keep := prefixReads ⟨12 + i.val, by have := i.isLt; omega⟩
    have offset : 8 * (((12 + i.val : Nat) : Int)) = 96 + 8 * (i.val : Int) := by omega
    change CC.Mem.load .Mint64 after entry.block (8 * (((12+i.val : Nat) : Int))) =
      CC.Mem.load .Mint64 middle entry.block (8 * (((12+i.val : Nat) : Int))) at keep
    rw [offset] at keep
    exact keep.trans (nullReads i)
  · intro id ty block bound different chunk ofs
    exact (tailLocals id ty block bound different chunk ofs).trans
      (headLocals id ty block bound different chunk ofs)

theorem header_initialized_before_loop (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun ge 276 (.State producer afterContext k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (tailValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_initialized_before_loop_bound ge rfl (fun store => (payload_callback_binding store).1) m before le k access

/-- Both borrowed caches are bound at the actual reached pre-loop state. -/
theorem header_caches_before_loop_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (symbols : ∀ store, CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store)) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun world 276 (.State producer afterContext k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, _, after, run, reads, _, _, _, frame, afterAccess, next⟩ :=
    header_initialized_before_loop_bound world layout symbols m before le k access
  obtain ⟨stack, stackStorage⟩ := header_cache_storage false m after entry cells (afterAccess.trans access) reads
  obtain ⟨returns, returnStorage⟩ := header_cache_storage true m after entry cells (afterAccess.trans access) reads
  exact ⟨stack, returns, after, run, stackStorage, returnStorage, frame, afterAccess, next⟩

theorem header_caches_before_loop (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ stack : CacheLocals false m, ∃ returns : CacheLocals true m, ∃ after,
      InternalRun ge 276 (.State producer afterContext k (allocation m).1 le before)
        (.State producer beforeVectorLoop k (allocation m).1 le after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage false (allocation m).2.nextblock stack.entryBlock 0 after) ∧
      Nonempty (Arm64RegisterReads.BorrowedCacheStorage true (allocation m).2.nextblock returns.entryBlock 0 after) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  header_caches_before_loop_bound ge rfl (fun store => (payload_callback_binding store).1) m before le k access

end KProgFormal.ClightRefinement.Arm64Producer
