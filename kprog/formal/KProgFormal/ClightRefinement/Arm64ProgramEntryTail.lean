import KProgFormal.ClightRefinement.Arm64ProgramEntryVectors

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTail

open Arm64ProgramEntryAllocation (world localName localType)
open Arm64ProgramEntrySource (sourceType expression statement)
open Arm64Producer

def callbackBlock (store : Bool) : CC.Block := CC.Positive.ofNat (if store then 61 else 60)
def callbackFunction (store : Bool) : CC.FunDef :=
  .Internal (if store then Arm64ProgramFixture.f_kprog_arm64_payload_store
    else Arm64ProgramFixture.f_kprog_arm64_payload_load)

/-- Both symbols and function bodies are those in the actual production world. -/
theorem callback_binding (store : Bool) :
    CC.Genv.findSymbol world.genv_genv (payloadCallbackName store) = some (callbackBlock store) ∧
    CC.Genv.findFunctPtr world.genv_genv (callbackBlock store) = some (callbackFunction store) := by
  cases store <;> constructor <;> rfl

/-- Callback pointers differ from those in the extracted producer world. -/
theorem callback_blocks_differ : ∀ store,
    callbackBlock store ≠ payloadCallbackBlock store := by decide +kernel

/-- Source locals retain their block under the actual declaration map. -/
theorem local_binding (initial : CC.Mem) (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 9) :
    (Arm64ProgramEntryAllocation.allocation initial).1.get (localName (tailLocalName i)) =
      some ((sources i).block, sourceType (tailLocalType i)) := by
  have present : ∀ i : Fin 9, (tailLocalName i, tailLocalType i) ∈ producer.fn_vars := by decide +kernel
  have typed := Arm64ProgramEntryExpressions.declaration_type
    (tailLocalName i, tailLocalType i) (present i)
  rw [typed]
  exact Arm64ProgramEntryAllocation.local_binding initial _ _ _ (sources i).binding

def actualValue {initial : CC.Mem} (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16) : CC.Val :=
  if i.val = 3 then .Vptr (callbackBlock false) 0
  else if i.val = 4 then .Vptr (callbackBlock true) 0
  else tailValue sources i

def actualInputValue {initial : CC.Mem} (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16) : CC.Val :=
  if i.val = 6 then .Vlong 160 else if i.val = 7 then .Vlong 20 else
  if i.val = 8 then .Vlong 24 else actualValue sources i

private theorem sixteen_cases : ∀ i : Fin 16, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 := by decide +kernel

private def stackComposite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture.__5185).get (by decide +kernel)

private theorem stack_layout :
    world.genv_cenv.get Arm64ProgramFixture.__5185 = some stackComposite ∧
    CC.unionFieldOffset world.genv_cenv Arm64Entry._b stackComposite.co_members = .OK (0, .Full) ∧
    CC.unionFieldOffset world.genv_cenv Arm64Entry._q stackComposite.co_members = .OK (0, .Full) := by
  decide +kernel

private theorem callback_name_fixed (store : Bool) :
    localName (payloadCallbackName store) = payloadCallbackName store := by
  cases store <;> decide +kernel

/-- No allocated production local shadows either payload callback. -/
theorem callback_unshadowed (initial : CC.Mem) (store : Bool) :
    (Arm64ProgramEntryAllocation.allocation initial).1.get (payloadCallbackName store) = none := by
  have absent : payloadCallbackName store ∉ CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by
    cases store <;> decide +kernel
  simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm) absent

/-- Expose only the actual expression constructors behind source metadata.
Identifier/type constants remain shared. The resulting change is checked by
the kernel; this does not evaluate Clight or create a substitute C body. -/
private def normalize_rhs_goal : Lean.Elab.Tactic.TacticM Unit := do
  Lean.Elab.Tactic.withMainContext do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    let lhs := target.getAppArgs[1]!.consumeMData
    let args := lhs.getAppArgs
    unless args.size == 5 do throwError "expected imported expression evaluator"
    let mut value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf args[4]!)
    let mut frames : Array (Lean.Expr × Array Lean.Expr) := #[]
    while value.isAppOfArity ``CC.Expr.Ecast 2 || value.isAppOfArity ``CC.Expr.Eaddrof 2 ||
        value.isAppOfArity ``CC.Expr.Efield 3 do
      let fields := value.getAppArgs
      frames := frames.push (value.getAppFn, fields)
      value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf fields[0]!)
    for (head, fields) in frames.toList.reverse do
      value := Lean.mkAppN head (fields.set! 0 value)
    let rhs := target.getAppArgs[2]!.consumeMData
    let rhsArgs := rhs.getAppArgs
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rhsArgs[1]!)
    let normalizedRhs := Lean.mkAppN rhs.getAppFn (rhsArgs.set! 1 result)
    let desired ← Lean.Meta.mkEq (Lean.mkAppN lhs.getAppFn (args.set! 4 value)) normalizedRhs
    Lean.Elab.Tactic.replaceMainGoal [← goal.change desired]

private theorem tail_rhs_0 (initial before : CC.Mem) (temps : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16)
    (which : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailDeclaration i).rhs) = some (actualInputValue sources i) := by
  have b0 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_stack) =
      some ((sources 0).block, sourceType (CC.tvolatile (.Tunion Arm64Entry.__2856 CC.noattr))) := local_binding initial sources 0
  have b1 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_stack_payload) =
      some ((sources 1).block, sourceType (CC.tarray (CC.tvolatile CC.tulong) 20)) := local_binding initial sources 1
  have uload := callback_unshadowed initial false
  have sload := (callback_binding false).1
  rcases which with rfl | rfl | rfl | rfl
  all_goals run_tac normalize_rhs_goal
  all_goals simp +decide [sourceType, actualValue, actualInputValue, tailValue, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.accessMode, b0, b1, uload, sload, callback_name_fixed false, stack_layout.1, stack_layout.2.1, stack_layout.2.2, CC.tvolatile, CC.tattr, CC.tarray, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add, CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem tail_rhs_1 (initial before : CC.Mem) (temps : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16)
    (which : i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailDeclaration i).rhs) = some (actualInputValue sources i) := by
  have b2 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_stack_tag) =
      some ((sources 2).block, sourceType (CC.tarray CC.tuchar 24)) := local_binding initial sources 2
  have ustore := callback_unshadowed initial true
  have sstore := (callback_binding true).1
  rcases which with rfl | rfl | rfl | rfl
  all_goals run_tac normalize_rhs_goal
  all_goals simp +decide [sourceType, actualValue, actualInputValue, tailValue, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.accessMode, b2, ustore, sstore, callback_name_fixed true, CC.tvolatile, CC.tattr, CC.tarray, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add, CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem tail_rhs_2 (initial before : CC.Mem) (temps : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16)
    (which : i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailDeclaration i).rhs) = some (actualInputValue sources i) := by
  have b3 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_helper_ctx) =
      some ((sources 3).block, sourceType (CC.tptr CC.tvoid)) := local_binding initial sources 3
  have b4 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_helper_abi_base) =
      some ((sources 4).block, sourceType (CC.tptr CC.tvoid)) := local_binding initial sources 4
  rcases which with rfl | rfl | rfl | rfl
  all_goals run_tac normalize_rhs_goal
  all_goals simp +decide [sourceType, actualValue, actualInputValue, tailValue, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.lvalOfField, CC.doDerefLoc, CC.typeof, CC.accessMode, b3, b4, CC.tvolatile, CC.tattr, CC.tarray, CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.repr, CC.Integers.MI.add, CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  all_goals rfl

private theorem tail_rhs_3 (initial before : CC.Mem) (temps : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16)
    (which : i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailDeclaration i).rhs) = some (actualInputValue sources i) := by
  have b5 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_is_xdp) =
      some ((sources 5).block, sourceType (CC.tuchar)) := local_binding initial sources 5
  have b6 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_abi_kind) =
      some ((sources 6).block, sourceType (CC.tuchar)) := local_binding initial sources 6
  have b7 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_skb_ctx) =
      some ((sources 7).block, sourceType (CC.tptr (.Tstruct Arm64Entry.___sk_buff CC.noattr))) := local_binding initial sources 7
  have b8 : (Arm64ProgramEntryAllocation.allocation initial).1.get (localName Arm64Entry.___a64_sim_abi) =
      some ((sources 8).block, sourceType (.Tstruct Arm64Entry._arm64_sim_skb_abi CC.noattr)) := local_binding initial sources 8
  rcases which with rfl | rfl | rfl | rfl
  all_goals run_tac normalize_rhs_goal
  all_goals simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
    b5, b6, b7, b8, ite_true]
  all_goals rfl

/-- The actual RHS values use derived actual locals and actual callback
blocks, preserving the distinct producer/production callback addresses. -/
theorem tail_rhs (initial before : CC.Mem) (temps : CC.TempEnv)
    (sources : (i : Fin 9) → TailLocal initial i) (i : Fin 16) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailDeclaration i).rhs) = some (actualInputValue sources i) := by
  rcases sixteen_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact tail_rhs_0 initial before temps sources 0 (by decide +kernel)
  · exact tail_rhs_0 initial before temps sources 1 (by decide +kernel)
  · exact tail_rhs_0 initial before temps sources 2 (by decide +kernel)
  · exact tail_rhs_0 initial before temps sources 3 (by decide +kernel)
  · exact tail_rhs_1 initial before temps sources 4 (by decide +kernel)
  · exact tail_rhs_1 initial before temps sources 5 (by decide +kernel)
  · exact tail_rhs_1 initial before temps sources 6 (by decide +kernel)
  · exact tail_rhs_1 initial before temps sources 7 (by decide +kernel)
  · exact tail_rhs_2 initial before temps sources 8 (by decide +kernel)
  · exact tail_rhs_2 initial before temps sources 9 (by decide +kernel)
  · exact tail_rhs_2 initial before temps sources 10 (by decide +kernel)
  · exact tail_rhs_2 initial before temps sources 11 (by decide +kernel)
  · exact tail_rhs_3 initial before temps sources 12 (by decide +kernel)
  · exact tail_rhs_3 initial before temps sources 13 (by decide +kernel)
  · exact tail_rhs_3 initial before temps sources 14 (by decide +kernel)
  · exact tail_rhs_3 initial before temps sources 15 (by decide +kernel)

/-- The casts and memory load results use the actual pointers and original
field chunks, including the three narrowing size fields. -/
theorem tail_cast (initial before : CC.Mem) (sources : (i : Fin 9) → TailLocal initial i)
    (i : Fin 16) :
    CC.Cop.semCast (actualInputValue sources i) (CC.typeof (expression (tailDeclaration i).rhs))
      (sourceType (tailDeclaration i).ty) before = some (actualValue sources i) ∧
    CC.Val.loadResult (tailChunk i) (actualValue sources i) = actualValue sources i := by
  rcases sixteen_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> constructor <;> rfl

private theorem source_tail_lvalue (world : CC.CGenv)
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

/-- All actual target fields obtain their addresses from the checked
allocated-header transport and source offsets, without whole-world equality. -/
theorem tail_lvalue (initial before : CC.Mem) (temps : CC.TempEnv)
    (entry : HeaderLocal initial) (i : Fin 16) :
    CC.doEvalLvalue world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
      (expression (tailTarget i)) = some (entry.block, CC.Integers.Ptrofs.repr (tailOffset i), .Full) := by
  unfold tailTarget
  rw [(Arm64ProgramEntryFields.allocated_header initial before temps temps
    (tailDeclaration i).name (tailDeclaration i).ty).1]
  exact source_tail_lvalue ge rfl initial before temps entry i

private theorem tail_mode : ∀ i : Fin 16,
    CC.accessMode (sourceType (tailDeclaration i).ty) = .By_value (tailChunk i) := by
  intro i
  rcases sixteen_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

/-- One real tail store, using actual callback values and retaining all
previous typed observations and allocation/caller resources. -/
theorem tail_write (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (entry : HeaderLocal m) (sources : (i : Fin 9) → TailLocal m i)
    (i : Fin 16) (rest : CC.Stmt) (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (.Ssequence (statement (tailStore i)) rest) k
          (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (actualValue sources i) ∧
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
      (actualValue sources i) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev (tailChunk i) before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (tailOffset i))) (actualValue sources i) = some after := by
    simpa only [CC.Mem.storev, tail_offsets] using stored
  have target := tail_lvalue m before le entry i
  have rhs := tail_rhs m before le sources i
  have cast := tail_cast m before sources i
  have assigned : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (statement (tailStore i)) (.Kseq rest k)
        (Arm64ProgramEntryAllocation.allocation m).1 le before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq rest k)
        (Arm64ProgramEntryAllocation.allocation m).1 le after) := by
    have targetType : CC.typeof (expression (tailTarget i)) = sourceType (tailDeclaration i).ty := rfl
    simp only [tailStore, statement, CC.doStep, target, rhs, targetType, cast.1,
      CC.doAssignLoc, tail_mode i]
    change (match CC.Mem.storev (tailChunk i) before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (tailOffset i))) (actualValue sources i) with
      | some memory => some (CC.E0, CC.State.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq rest k)
          (Arm64ProgramEntryAllocation.allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have run : InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (statement (tailStore i)) rest) k
        (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
        (Arm64ProgramEntryAllocation.allocation m).1 le after) :=
    .step trivial (.seq _ _ _ _ _ _ _)
      (.step trivial (Arm64ProgramEntryAssignments.assignment_sound world _ _ _ _ _ _ _ _ assigned)
        (.step trivial (.skip_seq _ _ _ _ _ _) (.refl _)))
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

private theorem run_tail (m : CC.Mem) (entry : HeaderLocal m)
    (sources : (i : Fin 9) → TailLocal m i) (rows : List (Fin 16)) (rest : CC.Stmt)
    (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (rows.foldr (fun i next => .Ssequence (statement (tailStore i)) next) rest)
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (actualValue sources i)) ∧
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
      tail_write m before le k entry sources head
        (tail.foldr (fun i next => .Ssequence (statement (tailStore i)) next) rest) access
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

/-- The sixteen statements and successor come from the actual export. -/
private def productionParts : { last : CC.Stmt // Arm64ProgramEntryVectors.afterNullVectors =
    (List.ofFn (fun i => statement (tailStore i))).foldr CC.Stmt.Ssequence last } := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryVectors.afterNullVectors)) none
    for _ in [:16] do
      let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual header tail has fewer than sixteen statements"
      current := body.getAppArgs[1]!
    let rows ← Lean.Elab.Term.elabTerm (← `(List.ofFn (fun i => statement (tailStore i)))) none
    let rhs ← Lean.Meta.mkAppM ``List.foldr #[Lean.mkConst ``CC.Stmt.Ssequence, current, rows]
    let target ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    Lean.Elab.Tactic.closeMainGoal `production_tail_parts
      (← Lean.Meta.mkAppOptM ``Subtype.mk #[some target.getAppArgs[0]!,
        some target.getAppArgs[1]!, some current, some (← Lean.Meta.mkEqRefl rhs)])

def beforeLoop : CC.Stmt := productionParts.val

theorem production_tail_source : Arm64ProgramEntryVectors.afterNullVectors =
    (List.ofFn (fun i => statement (tailStore i))).foldr CC.Stmt.Ssequence beforeLoop :=
  productionParts.property

/-- All sixteen production tail stores execute without caller-supplied
callback-symbol or composite-world-equality premises. -/
theorem tail_initialized (m before : CC.Mem) (entry : HeaderLocal m)
    (le : CC.TempEnv) (k : CC.Cont) (access : before.access = (allocation m).2.access) :
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun world 48 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryVectors.afterNullVectors
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile beforeLoop
          k (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (actualValue sources i)) ∧
      (∀ j : Fin 76, CC.Mem.load .Mint64 after entry.block (8 * (j.val : Int)) =
        CC.Mem.load .Mint64 before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  let sources : (i : Fin 9) → TailLocal m i := fun i => Classical.choice (tail_local m i)
  obtain ⟨after, run, read, _, prefixReads, other, frame, finalAccess, next⟩ :=
    run_tail m entry sources (List.finRange 16) beforeLoop le k before access
  refine ⟨sources, after, ?_, (fun i => read i (List.mem_finRange i)), prefixReads, other, frame, finalAccess, next⟩
  have mapped : List.ofFn (fun i => statement (tailStore i)) =
      (List.finRange 16).map (fun i => statement (tailStore i)) := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [production_tail_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

/-- All 92 actual header readbacks hold at one reached pre-loop memory. -/
theorem header_initialized_before_loop (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i,
    ∃ sources : (i : Fin 9) → TailLocal m i, ∃ after,
      InternalRun world 276 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAssignments.beforeHeader
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile beforeLoop
          k (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0)) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) = some (actualValue sources i)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, middle, headRun, scalarReads, nullReads, headLocals, headFrame, headAccess, headNext⟩ :=
    Arm64ProgramEntryVectors.header_and_vectors m before le k access
  obtain ⟨sources, after, tailRun, tailReads, prefixReads, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
    tail_initialized m middle entry le k (headAccess.trans access)
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

end KProgFormal.ClightRefinement.Arm64ProgramEntryTail
