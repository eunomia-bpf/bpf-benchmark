import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterUnmaterialize

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPayload
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderTailValues (Storage)

private noncomputable def payloadTy : CC.Ty := CC.tarray (CC.tvolatile CC.tulong) 1
private noncomputable def pointerTy : CC.Ty := CC.tptr (CC.tvolatile CC.tulong)
noncomputable def address : CC.Expr := .Eaddrof
  (.Ederef (.Ebinop .Oadd (.Evar ___a64_stack_payload payloadTy)
    (.Ebinop .Ogt
      (.Ecast (.Ebinop .Oshr (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 3) CC.tint) CC.tulong) CC.tulong)
      (.Econst_long (CC.Integers.Int64.repr 0) CC.tulong) CC.tint) pointerTy) (CC.tvolatile CC.tulong))
  pointerTy
noncomputable def arguments : List CC.Expr := [address,.Etempvar ___a64_stw_payload CC.tulong]
noncomputable def types : List CC.Ty := [pointerTy,CC.tvolatile CC.tulong]
noncomputable def statement : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_77

theorem source : Arm64CiliumCallerMemoryWriterUnmaterialize.after =
    .Sloop statement s_trusted_arm64_arm64_sim_xdp_78 := rfl
theorem statement_source : statement = .Sbuiltin none (.EF_vstore .Mint64) types arguments := rfl
theorem break_source : s_trusted_arm64_arm64_sim_xdp_78 = .Sbreak := rfl

private def globalVolatile (definition : CC.GlobDef CC.FunDef CC.Ty) : Bool :=
  match definition with
  | .Gfun _ => false
  | .Gvar gv => gv.gvar_volatile

private theorem add_nonvolatile (world : CC.Genv CC.FunDef CC.Ty)
    (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty)
    (prior : ∀ b,CC.Genv.blockIsVolatile world b = false)
    (current : globalVolatile row.2 = false) :
    ∀ b,CC.Genv.blockIsVolatile (CC.Genv.addGlobal world row) b = false := by
  intro b
  by_cases same : world.genv_next = b
  · subst b
    simp only [CC.Genv.blockIsVolatile,CC.Genv.findVarInfo,CC.Genv.findDef,CC.Genv.addGlobal,CC.PTree.gss]
    cases h : row.2 <;> simpa only [globalVolatile,h] using current
  · simpa only [CC.Genv.blockIsVolatile,CC.Genv.findVarInfo,CC.Genv.findDef,CC.Genv.addGlobal,
      CC.PTree.gso _ _ _ _ same] using prior b

private theorem globals_nonvolatile (world : CC.Genv CC.FunDef CC.Ty)
    (rows : List (CC.Ident × CC.GlobDef CC.FunDef CC.Ty))
    (prior : ∀ b,CC.Genv.blockIsVolatile world b = false)
    (entries : ∀ row ∈ rows,globalVolatile row.2 = false) :
    ∀ b,CC.Genv.blockIsVolatile (CC.Genv.addGlobals world rows) b = false := by
  induction rows generalizing world with
  | nil => exact prior
  | cons row rows ih =>
    exact ih (CC.Genv.addGlobal world row) (add_nonvolatile world row prior (entries row (by simp)))
      (fun entry present => entries entry (by simp only [List.mem_cons];exact .inr present))

private noncomputable def symbols := CC.Genv.addGlobals
  (CC.Genv.emptyGenv Arm64CiliumCallerLinkedProgram.program.prog_public)
  Arm64CiliumCallerLinkedProgram.program.prog_defs

private theorem symbols_source : ge.genv_genv = symbols := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected actual linked symbol equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private theorem transfer_nonvolatile
    (world reference : CC.Genv CC.FunDef CC.Ty) (same : world = reference)
    (b : CC.Block) (checked : CC.Genv.blockIsVolatile reference b = false) :
    world.toSenv.block_is_volatile b = false := by
  cases same
  exact checked

private theorem qualifiers : Arm64CiliumCallerLinkedProgram.program.prog_defs.all
    (fun row => decide (globalVolatile row.2 = false)) = true := by decide +kernel

private theorem nonvolatile_symbols (b : CC.Block) : CC.Genv.blockIsVolatile symbols b = false :=
  globals_nonvolatile _ _ (fun _ => by
    simp only [CC.Genv.blockIsVolatile,CC.Genv.findVarInfo,CC.Genv.findDef,CC.Genv.emptyGenv,CC.PTree.gempty])
    (fun row present => of_decide_eq_true (List.all_eq_true.mp qualifiers row present)) b

/-- Check the ACTUAL complete linked program's global qualifiers. Local volatile
array syntax uses the imported nonvol rule, which changes memory with E0. -/
theorem nonvolatile (b : CC.Block) : ge.genv_genv.toSenv.block_is_volatile b = false := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    unless target.isAppOfArity ``Eq 3 do
      throwError "expected actual caller nonvolatile equality"
    let lhs := target.getAppArgs[1]!
    unless lhs.isAppOfArity ``CC.Senv.block_is_volatile 2 do
      throwError "expected actual symbol environment volatility projection"
    let block := lhs.getAppArgs[1]!
    let certificate := Lean.mkApp (Lean.mkConst ``nonvolatile_symbols) block
    let world := Lean.mkApp (Lean.mkConst ``CC.CGenv.genv_genv)
      (Lean.mkConst ``Arm64CiliumCallerLinkedProgram.ge)
    let proof := Lean.mkAppN (Lean.mkConst ``transfer_nonvolatile)
      #[world,Lean.mkConst ``symbols,Lean.mkConst ``symbols_source,block,certificate]
    goal.assign proof
    Lean.Elab.Tactic.replaceMainGoal []

theorem arguments_value {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (payload : le.get ___a64_stw_payload = some (.Vlong (0#64))) :
    CC.doEvalExprlist ge (allocation m).1 le before arguments types =
      some [.Vptr (header.block 1) 0,.Vlong (0#64)] := by
  have binding : (allocation m).1.get ___a64_stack_payload = some (header.block 1,payloadTy) := header.binding 1
  simp only [arguments,types,address,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,
    CC.lvalOfVar,binding,index,payload,ite_true]
  rfl

theorem writable {m before : CC.Mem} (header : Storage m)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before .Mint64 (header.block 1) 0 .Writable = true := by
  have range : CC.Mem.rangePerm (allocation m).2 (header.block 1) 0 8 .Cur .Freeable = true :=
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 1)).2.2
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ range o lower upper)
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · rfl

structure Store {m before : CC.Mem} (header : Storage m) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 before (header.block 1) 0 (.Vlong (0#64)) = some after
  read : CC.Mem.load .Mint64 after (header.block 1) 0 = some (.Vlong (0#64))
  otherBlocks : ∀ b,b ≠ header.block 1 → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o
  caller : FrameBelow m.nextblock before after
  access : after.access = before.access
  frontier : after.nextblock = before.nextblock

theorem write {m before : CC.Mem} (header : Storage m)
    (access : before.access = (allocation m).2.access) : Nonempty (Store (before := before) header) := by
  have valid := writable header access
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 before (header.block 1) 0 (.Vlong (0#64)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 1)).1
  exact ⟨⟨after,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩

theorem bound_frame {m before : CC.Mem} {header : Storage m} (result : Store (before := before) header)
    {id : CC.Ident} {ty : CC.Ty} {block : CC.Block}
    (binding : (allocation m).1.get id = some (block,ty)) (different : id ≠ ___a64_stack_payload) :
    ∀ c o,CC.Mem.load c result.after block o = CC.Mem.load c before block o :=
  result.otherBlocks block ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding (header.binding 1) different)

theorem word_value {m before : CC.Mem} {header : Storage m} {base : BitVec 64}
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := before) header base)
    (payload : Store (before := word.after) header) :
    CC.Mem.load .Mint64 payload.after (header.block 0) 0 = some (.Vlong base) :=
  (bound_frame payload (header.binding 0) (by decide +kernel) .Mint64 0).trans word.read

/-- This is the imported builtin transition and its actual externalCall
relation, rather than an InternalRun step or assumed provider outcome. -/
theorem builtin {m before : CC.Mem} (header : Storage m) (result : Store (before := before) header)
    (le : CC.TempEnv) (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (payload : le.get ___a64_stw_payload = some (.Vlong (0#64))) (k : CC.Cont) :
    CC.Step2 ge (.State procedure statement k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le result.after) := by
  rw [statement_source]
  apply CC.Step.builtin (vargs := [.Vptr (header.block 1) 0,.Vlong (0#64)]) (vres := .Vundef)
  · apply CC.doEvalExprlist_sound
    exact arguments_value header le before index payload
  · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
      (.nonvol _ _ _ _ _ _ (nonvolatile (header.block 1)) result.stored)

/-- Original payload loop entry, builtin write, loop exit and sequence
continuation. All trace composition is E0 and the TempEnv is unchanged. -/
theorem advance {m before : CC.Mem} (header : Storage m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv)
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (payload : le.get ___a64_stw_payload = some (.Vlong (0#64))) (k : CC.Cont) :
    ∃ result : Store (before := before) header,
      CC.Star (CC.Step2 ge)
        (.State procedure Arm64CiliumCallerMemoryWriterUnmaterialize.after
          (Arm64CiliumCallerMemoryWriterUnmaterialize.continuation k) (allocation m).1 le before)
        CC.E0 (.State procedure Arm64CiliumCallerMemoryWriterUnmaterialize.tags k
          (allocation m).1 le result.after) := by
  obtain ⟨result⟩ := write header access
  have stored := builtin header result le index payload
    (.Kloop1 statement .Sbreak (.Kseq Arm64CiliumCallerMemoryWriterUnmaterialize.tags k))
  refine ⟨result,?_⟩
  rw [source,break_source,Arm64CiliumCallerMemoryWriterUnmaterialize.continuation]
  refine .step _ _ _ _ _ _ (CC.Step.loop _ _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ stored ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.skip_or_continue_loop1 _ _ _ _ _ _ _ _ (Or.inl rfl)) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.break_loop2 _ _ _ _ _ _ _) ?_ rfl
  exact .step _ _ _ _ _ _ (CC.Step.skip_seq _ _ _ _ _ _) (.refl _) rfl


theorem incoming_index {m : CC.Mem} (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m) (le : CC.TempEnv) (base : BitVec 64) :
    (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
      (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base).get
      ___a64_stw_index = some (.Vlong (0#64)) := by
  rw [Arm64CiliumCallerMemoryWriterUnmaterialize.temp_frame _ base ___a64_stw_index
    (by decide +kernel) (by decide +kernel) (by decide +kernel)
    (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  unfold Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv
  rw [Arm64CiliumCallerMemoryWriterMask.temp_frame _ base ___a64_stw_index
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
  exact Arm64CiliumCallerMemoryWriterAddress.index_zero _ base

/-- Compose the actual164 internal steps with the real payload builtin and
its loop continuation using Star/E0, preserving both concrete store witnesses. -/
theorem from_word {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Arm64CiliumCallerTables.Table true m)
    (wordCells : Arm64CiliumCallerInitializers.Cells false m)
    (tagCells : Arm64CiliumCallerInitializers.Cells true m)
    (access : supplied.access = (allocation m).2.access)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 = some (.Vlong Arm64CiliumCallerSPPreindex.delta))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    ∃ word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base,
      ∃ payload : Store (before := word.after) header,
        CC.Star (CC.Step2 ge)
          (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
            (Arm64CiliumCallerReturnOutcomes.resultEnv
              (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) cache.after)
          CC.E0 (.State procedure Arm64CiliumCallerMemoryWriterUnmaterialize.tags
            (Arm64CiliumCallerMemoryWriterAddress.continuation
              (Arm64CiliumCallerMemoryWriterPrefix.continuation k)) (allocation m).1
            (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv
              (Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base) base)
            payload.after) := by
  obtain ⟨word,unmat⟩ := Arm64CiliumCallerMemoryWriterUnmaterialize.advance cache header scalars tags
    wordCells tagCells access spRead abi slot tag le width k
  let input := Arm64CiliumCallerMemoryWriterUnmaterialize.incomingEnv wordCells tagCells le base
  obtain ⟨payload,written⟩ := advance header (word.access.trans (cache.access.trans access))
    (Arm64CiliumCallerMemoryWriterUnmaterialize.resultEnv input base)
    (incoming_index wordCells tagCells le base)
    (Arm64CiliumCallerMemoryWriterUnmaterialize.values input base).1
    (Arm64CiliumCallerMemoryWriterAddress.continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k))
  refine ⟨word,payload,?_⟩
  simpa only [CC.Eapp,CC.E0,List.nil_append] using star_trans unmat.sound written

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPayload
