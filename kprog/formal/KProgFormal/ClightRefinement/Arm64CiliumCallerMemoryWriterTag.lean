import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterPayload

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTag
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  pointer : CC.Stmt
  load : CC.Stmt
  copy : CC.Stmt
  store : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual caller tag read-modify-write source changed"
      pure node.getAppArgs
    let original ← peel (← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_80)) none)
    let rest ← peel original[1]!
    let loaded ← peel rest[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_tag_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[original[0]!,loaded[0]!,loaded[1]!,rest[1]!])

noncomputable def statement : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_80
noncomputable def pointer : CC.Stmt := parts.pointer
noncomputable def load : CC.Stmt := parts.load
noncomputable def copy : CC.Stmt := parts.copy
noncomputable def store : CC.Stmt := parts.store
private noncomputable def pointerTy : CC.Ty := CC.tptr (CC.tvolatile CC.tulong)
private noncomputable def pointerExpr : CC.Expr :=
  .Ecast (.Ecast (.Ebinop .Oadd (.Evar ___a64_stack_tag (CC.tarray CC.tuchar 8))
    (.Ebinop .Oand (.Ecast (.Etempvar ___ti CC.tulong) CC.tulong)
      (.Eunop .Onotint (.Econst_long (CC.Integers.Int64.repr 7) CC.tulong) CC.tulong) CC.tulong)
    (CC.tptr CC.tuchar)) (CC.tptr CC.tvoid)) pointerTy
private noncomputable def address : CC.Expr :=
  .Eaddrof (.Ederef (.Etempvar ___tp pointerTy) (CC.tvolatile CC.tulong)) pointerTy
private noncomputable def updateExpr : CC.Expr :=
  .Ebinop .Oor
    (.Ebinop .Oand (.Etempvar ___tv CC.tulong)
      (.Eunop .Onotint (.Ebinop .Oshl (.Econst_long (CC.Integers.Int64.repr 255) CC.tulong)
        (.Etempvar ___ts CC.tuint) CC.tulong) CC.tulong) CC.tulong)
    (.Ebinop .Oshl (.Ecast (.Ecast (.Etempvar ___a64_store_tag CC.tuchar) CC.tuchar) CC.tulong)
      (.Etempvar ___ts CC.tuint) CC.tulong) CC.tulong

theorem source : statement = .Ssequence pointer (.Ssequence (.Ssequence load copy) store) := rfl
theorem pointer_source : pointer = .Sset ___tp pointerExpr := rfl
theorem load_source : load = .Sbuiltin (some _t'176) (.EF_vload .Mint64) [pointerTy] [address] := rfl
theorem copy_source : copy = .Sset ___tv (.Etempvar _t'176 (CC.tvolatile CC.tulong)) := rfl
theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint64)
    [pointerTy,CC.tvolatile CC.tulong] [address,updateExpr] := rfl

def updated (original : BitVec 64) : BitVec 64 := (original &&& ~~~(255#64)) ||| (10#64)

noncomputable def pointerEnv {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) : CC.TempEnv :=
  le.set ___tp (.Vptr (header.block 2) 0)
noncomputable def loadEnv {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (original : BitVec 64) : CC.TempEnv :=
  (pointerEnv header le).set _t'176 (.Vlong original)
noncomputable def resultEnv {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (original : BitVec 64) : CC.TempEnv :=
  (loadEnv header le original).set ___tv (.Vlong original)

theorem pointer_step {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (index : le.get ___ti = some (.Vlong (0#64))) (k : CC.Cont) :
    CC.doStep ge (.State procedure pointer k (allocation m).1 le before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (pointerEnv header le) before) := by
  have binding : (allocation m).1.get ___a64_stack_tag =
      some (header.block 2,CC.tarray CC.tuchar 8) := header.binding 2
  simp only [pointer_source,pointerExpr,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,binding,index,ite_true]
  rfl

private theorem address_value {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (ptr : le.get ___tp = some (.Vptr (header.block 2) 0)) :
    CC.doEvalExpr ge (allocation m).1 le before address = some (.Vptr (header.block 2) 0) := by
  simp only [address,CC.doEvalExpr,CC.doEvalLvalue,ptr]

theorem load_builtin {m before : CC.Mem} (header : Storage m) (le : CC.TempEnv)
    (original : BitVec 64)
    (read : CC.Mem.load .Mint64 before (header.block 2) 0 = some (.Vlong original)) (k : CC.Cont) :
    CC.Step2 ge (.State procedure load k (allocation m).1 (pointerEnv header le) before) CC.E0
      (.State procedure .Sskip k (allocation m).1 (loadEnv header le original) before) := by
  rw [load_source]
  apply CC.Step.builtin (vargs := [.Vptr (header.block 2) 0]) (vres := .Vlong original)
  · apply CC.doEvalExprlist_sound
    have ptr : (pointerEnv header le).get ___tp = some (.Vptr (header.block 2) 0) :=
      CC.PTree.gss _ _ _
    have evaluated := address_value header (pointerEnv header le) before ptr
    simp only [CC.doEvalExprlist,evaluated]
    rfl
  · exact CC.VolatileLoadSem.intro _ _ _ _ _ _
      (.nonvol _ _ _ _ _ (Arm64CiliumCallerMemoryWriterPayload.nonvolatile (header.block 2)) read)

theorem store_arguments {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (original : BitVec 64) (shift : le.get ___ts = some (.Vint (0#32)))
    (tag : le.get ___a64_store_tag = some (.Vint (10#32))) :
    CC.doEvalExprlist ge (allocation m).1 (resultEnv header le original) before
      [address,updateExpr] [pointerTy,CC.tvolatile CC.tulong] =
      some [.Vptr (header.block 2) 0,.Vlong (updated original)] := by
  have ptr : (resultEnv header le original).get ___tp = some (.Vptr (header.block 2) 0) := by
    simp +decide only [resultEnv,loadEnv,pointerEnv,CC.PTree.gso,CC.PTree.gss]
  have sh : (resultEnv header le original).get ___ts = some (.Vint (0#32)) := by
    simpa +decide only [resultEnv,loadEnv,pointerEnv,CC.PTree.gso] using shift
  have tg : (resultEnv header le original).get ___a64_store_tag = some (.Vint (10#32)) := by
    simpa +decide only [resultEnv,loadEnv,pointerEnv,CC.PTree.gso] using tag
  have value : (resultEnv header le original).get ___tv = some (.Vlong original) := CC.PTree.gss _ _ _
  simp only [CC.doEvalExprlist,address_value header _ before ptr,updateExpr,CC.doEvalExpr,sh,tg,value]
  rfl

theorem writable {m before : CC.Mem} (header : Storage m)
    (access : before.access = (allocation m).2.access) :
    CC.Mem.validAccess before .Mint64 (header.block 2) 0 .Writable = true := by
  have range : CC.Mem.rangePerm (allocation m).2 (header.block 2) 0 8 .Cur .Freeable = true :=
    ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 2)).2.2
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  refine ⟨?_,?_⟩
  · apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ range o lower upper)
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  · rfl

structure Store {m before : CC.Mem} (header : Storage m) (original : BitVec 64) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 before (header.block 2) 0 (.Vlong (updated original)) = some after
  read : CC.Mem.load .Mint64 after (header.block 2) 0 = some (.Vlong (updated original))
  otherBlocks : ∀ b,b ≠ header.block 2 → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o
  caller : FrameBelow m.nextblock before after
  access : after.access = before.access
  frontier : after.nextblock = before.nextblock

theorem write {m before : CC.Mem} (header : Storage m) (original : BitVec 64)
    (access : before.access = (allocation m).2.access) :
    Nonempty (Store (before := before) header original) := by
  have valid := writable header access
  obtain ⟨after,stored⟩ : ∃ after,
      CC.Mem.store .Mint64 before (header.block 2) 0 (.Vlong (updated original)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have fresh := ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ (header.binding 2)).1
  exact ⟨⟨after,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩

theorem bound_frame {m before : CC.Mem} {header : Storage m} {original : BitVec 64}
    (result : Store (before := before) header original)
    {id : CC.Ident} {ty : CC.Ty} {block : CC.Block}
    (binding : (allocation m).1.get id = some (block,ty)) (different : id ≠ ___a64_stack_tag) :
    ∀ c o,CC.Mem.load c result.after block o = CC.Mem.load c before block o :=
  result.otherBlocks block ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding (header.binding 2) different)

theorem store_builtin {m before : CC.Mem} (header : Storage m) (le : CC.TempEnv)
    (original : BitVec 64) (result : Store (before := before) header original)
    (shift : le.get ___ts = some (.Vint (0#32)))
    (tag : le.get ___a64_store_tag = some (.Vint (10#32))) (k : CC.Cont) :
    CC.Step2 ge (.State procedure store k (allocation m).1 (resultEnv header le original) before) CC.E0
      (.State procedure .Sskip k (allocation m).1 (resultEnv header le original) result.after) := by
  rw [store_source]
  apply CC.Step.builtin (vargs := [.Vptr (header.block 2) 0,.Vlong (updated original)]) (vres := .Vundef)
  · apply CC.doEvalExprlist_sound
    exact store_arguments header le before original shift tag
  · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
      (.nonvol _ _ _ _ _ _ (Arm64CiliumCallerMemoryWriterPayload.nonvolatile (header.block 2)) result.stored)

theorem copy_step {m : CC.Mem} (header : Storage m) (le : CC.TempEnv) (before : CC.Mem)
    (original : BitVec 64) (k : CC.Cont) :
    CC.doStep ge (.State procedure copy k (allocation m).1 (loadEnv header le original) before) =
      some (CC.E0,.State procedure .Sskip k (allocation m).1 (resultEnv header le original) before) := by
  simp only [copy_source,CC.doStep,CC.doEvalExpr,loadEnv,CC.PTree.gss] <;> rfl

/-- Execute the exact original pointer, volatile read, copy and volatile write.
The input word is a current memory resource, not inferred provider purity. -/
theorem advance {m before : CC.Mem} (header : Storage m) (le : CC.TempEnv)
    (original : BitVec 64) (access : before.access = (allocation m).2.access)
    (index : le.get ___ti = some (.Vlong (0#64)))
    (shift : le.get ___ts = some (.Vint (0#32)))
    (tag : le.get ___a64_store_tag = some (.Vint (10#32)))
    (read : CC.Mem.load .Mint64 before (header.block 2) 0 = some (.Vlong original)) (k : CC.Cont) :
    ∃ result : Store (before := before) header original,
      CC.Star (CC.Step2 ge) (.State procedure statement k (allocation m).1 le before)
        CC.E0 (.State procedure .Sskip k (allocation m).1 (resultEnv header le original) result.after) := by
  obtain ⟨result⟩ := write header original access
  refine ⟨result,?_⟩
  rw [source]
  refine .step _ _ _ _ _ _ (CC.Step.seq _ _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.doStep_sound _ _ _ _ (pointer_step header le before index _)) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.skip_seq _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.seq _ _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.seq _ _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ (load_builtin header le original read _) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.skip_seq _ _ _ _ _ _) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.doStep_sound _ _ _ _ (copy_step header le before original _)) ?_ rfl
  refine .step _ _ _ _ _ _ (CC.Step.skip_seq _ _ _ _ _ _) ?_ rfl
  exact .step _ _ _ _ _ _ (store_builtin header le original result shift tag k) (.refl _) rfl

/-- Frame a supplied current tag-word through the SAME concrete cache, word
and payload stores. No assumption that the provider preserves old contents. -/
theorem current_read {m supplied : CC.Mem} {locals : Arm64CiliumCallerDefaults.Locals m}
    {base original : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m)
    (word : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base)
    (payload : Arm64CiliumCallerMemoryWriterPayload.Store (before := word.after) header)
    (read : CC.Mem.load .Mint64 supplied (header.block 2) 0 = some (.Vlong original)) :
    CC.Mem.load .Mint64 payload.after (header.block 2) 0 = some (.Vlong original) := by
  have cached := Arm64CiliumCallerReturnMemory.bound_frame cache (header.binding 2)
    (by decide +kernel) (by decide +kernel) .Mint64 0
  have wordFrame := Arm64CiliumCallerMemoryWriterWord.bound_frame word (header.binding 2)
    (by decide +kernel) .Mint64 0
  have payloadFrame := Arm64CiliumCallerMemoryWriterPayload.bound_frame payload (header.binding 2)
    (by decide +kernel) .Mint64 0
  exact payloadFrame.trans (wordFrame.trans (cached.trans read))

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterTag
