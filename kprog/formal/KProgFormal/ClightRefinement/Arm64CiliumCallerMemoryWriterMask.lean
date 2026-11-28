import KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterWord

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterMask
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerTables (Table)
open Arm64CiliumCallerInitializers (Cells)
open Arm64CiliumCallerHeaderTailValues (Storage)

private structure Parts where
  mask : CC.Stmt
  action : CC.Stmt
  choice : CC.Stmt
  one : CC.Stmt
  two : CC.Stmt
  four : CC.Stmt
  unaligned : CC.Stmt
  narrow : CC.Stmt
  otherAction : CC.Stmt
  other : CC.Stmt
private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual original aligned writer selection changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemoryWriterAddress.after)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let mask ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let one ← peel mask[0]! ``CC.Stmt.Sifthenelse 3
    let two ← peel one[2]! ``CC.Stmt.Sifthenelse 3
    let four ← peel two[2]! ``CC.Stmt.Sifthenelse 3
    let rest ← peel outer[1]! ``CC.Stmt.Ssequence 2
    let action ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let choices ← peel action[0]! ``CC.Stmt.Ssequence 2
    let wide ← peel choices[0]! ``CC.Stmt.Sifthenelse 3
    let align ← peel wide[1]! ``CC.Stmt.Sifthenelse 3
    let mode ← peel choices[1]! ``CC.Stmt.Sifthenelse 3
    let choice ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_aligned_writer_selection
      (← Lean.Meta.mkAppM ``Parts.mk
        #[outer[0]!,rest[0]!,rest[1]!,one[1]!,two[1]!,four[1]!,align[2]!,wide[2]!,mode[2]!,choice[2]!])

noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemoryWriterAddress.after
noncomputable def mask : CC.Stmt := parts.mask
noncomputable def action : CC.Stmt := parts.action
noncomputable def choice : CC.Stmt := parts.choice

theorem source : stage = .Ssequence mask (.Ssequence action choice) := rfl
theorem mask_source : mask = .Ssequence
    (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint) parts.one
      (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 2) CC.tuint) CC.tint) parts.two
        (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
          (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) parts.four
          (.Ssequence s_trusted_arm64_arm64_sim_xdp_71
            (.Sset _t'169 (.Ecast (.Etempvar _t'169 CC.tulong) CC.tulong))))))
    (.Sset ___a64_stw_value (.Ebinop .Oand (.Etempvar ___a64_loss_value CC.tulong)
      (.Etempvar _t'169 CC.tulong) CC.tulong)) := rfl
theorem ones_source : s_trusted_arm64_arm64_sim_xdp_71 = .Ssequence
    (.Sset _t'169 (.Ecast (.Econst_long (CC.Integers.Int64.repr (-1)) CC.tulong) CC.tulong))
    (.Sset _t'169 (.Ecast (.Etempvar _t'169 CC.tulong) CC.tulong)) := rfl
theorem action_source : action = .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
        (.Econst_int (CC.Integers.Int.repr 8) CC.tuint) CC.tint)
        (.Sifthenelse (.Ebinop .Oeq
          (.Ebinop .Oand (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tuint)
            (.Econst_int (CC.Integers.Int.repr 7) CC.tuint) CC.tuint)
          (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint)
          (.Ssequence s_trusted_arm64_arm64_sim_xdp_72
            (.Sset _t'170 (.Ecast (.Etempvar _t'170 CC.tint) CC.tbool))) parts.unaligned) parts.narrow)
      (.Sifthenelse (.Etempvar _t'170 CC.tint)
        (.Sset _t'171 (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint))
        parts.otherAction))
    (.Sset ___a64_stw_action (.Ecast (.Ecast (.Etempvar _t'171 CC.tuint) CC.tuchar) CC.tuchar)) := rfl
theorem one_source : s_trusted_arm64_arm64_sim_xdp_72 =
    .Sset _t'170 (.Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tint) := rfl
theorem choice_source : choice = .Sifthenelse
    (.Ebinop .Oeq (.Etempvar ___a64_stw_action CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint)
    Arm64CiliumCallerMemoryWriterWord.fast parts.other := rfl

private theorem width1 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_width = some (.Vint (8#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 1) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem width2 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_width = some (.Vint (8#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 2) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem width4 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_width = some (.Vint (8#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 4) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem width8 (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_width = some (.Vint (8#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_stw_width CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 8) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem ones_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ecast (.Econst_long (CC.Integers.Int64.repr (-1)) CC.tulong) CC.tulong) =
      some (.Vlong (BitVec.allOnes 64)) := rfl
private theorem copy_ones (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'169 = some (.Vlong (BitVec.allOnes 64))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar _t'169 CC.tulong) CC.tulong) =
      some (.Vlong (BitVec.allOnes 64)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem masked_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (value : BitVec 64)
    (stored : le.get ___a64_loss_value = some (.Vlong value))
    (mask : le.get _t'169 = some (.Vlong (BitVec.allOnes 64))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oand (.Etempvar ___a64_loss_value CC.tulong)
      (.Etempvar _t'169 CC.tulong) CC.tulong) = some (.Vlong value) := by
  simp only [CC.doEvalExpr,stored,mask]
  change some (CC.Val.Vlong (value &&& BitVec.allOnes 64)) = some (.Vlong value)
  rw [BitVec.and_allOnes]
private theorem aligned (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_index = some (.Vlong (0#64))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq
      (.Ebinop .Oand (.Ecast (.Etempvar ___a64_stw_index CC.tulong) CC.tuint)
        (.Econst_int (CC.Integers.Int.repr 7) CC.tuint) CC.tuint)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem int_one (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tint) =
      some (.Vint (1#32)) := rfl
private theorem bool_one (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'170 = some (.Vint (1#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Etempvar _t'170 CC.tint) CC.tbool) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem uint_zero (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tuint) =
      some (.Vint (0#32)) := rfl
private theorem action_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get _t'171 = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory (.Ecast (.Ecast (.Etempvar _t'171 CC.tuint) CC.tuchar) CC.tuchar) =
      some (.Vint (0#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem choice_true (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (read : le.get ___a64_stw_action = some (.Vint (0#32))) :
    CC.doEvalExpr ge e le memory (.Ebinop .Oeq (.Etempvar ___a64_stw_action CC.tuchar)
      (.Econst_int (CC.Integers.Int.repr 0) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
  simp only [CC.doEvalExpr,read]
  rfl
private theorem temp_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (id : CC.Ident) (ty : CC.Ty) :
    CC.doEvalExpr ge e le memory (.Etempvar id ty) = le.get id := rfl
private theorem binop_type (op : CC.Binop) (a b : CC.Expr) (ty : CC.Ty) :
    CC.typeof (.Ebinop op a b ty) = ty := rfl
private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl
private theorem true_value (memory : CC.Mem) : CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true := rfl
private theorem false_value (memory : CC.Mem) : CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false := rfl

private theorem w169 (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'169 value le).get ___a64_stw_width = le.get ___a64_stw_width :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem wvalue (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set ___a64_stw_value value le).get ___a64_stw_width = le.get ___a64_stw_width :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem i169 (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'169 value le).get ___a64_stw_index = le.get ___a64_stw_index :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem ivalue (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set ___a64_stw_value value le).get ___a64_stw_index = le.get ___a64_stw_index :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)
private theorem v169 (le : CC.TempEnv) (value : CC.Val) :
    (CC.PTree.set _t'169 value le).get ___a64_loss_value = le.get ___a64_loss_value :=
  CC.PTree.gso _ _ _ _ (by decide +kernel)

noncomputable def resultEnv (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_stw_action (CC.Val.Vint (0#32))
    (CC.PTree.set _t'171 (CC.Val.Vint (0#32))
      (CC.PTree.set _t'170 (CC.Val.Vint (1#32))
        (CC.PTree.set _t'170 (CC.Val.Vint (1#32))
          (CC.PTree.set ___a64_stw_value (CC.Val.Vlong value)
            (CC.PTree.set _t'169 (CC.Val.Vlong (BitVec.allOnes 64))
              (CC.PTree.set _t'169 (CC.Val.Vlong (BitVec.allOnes 64))
                (CC.PTree.set _t'169 (CC.Val.Vlong (BitVec.allOnes 64)) le)))))))

/-- Original width8/all-ones mask and aligned-index0 action selection, preserving
the entire heap and all unselected original branches, to the real fast entry. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (value : BitVec 64)
    (width : le.get ___a64_stw_width = some (.Vint (8#32)))
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (stored : le.get ___a64_loss_value = some (.Vlong value)) (k : CC.Cont) :
    InternalRun ge 31 (.State procedure stage k e le memory)
      (.State procedure Arm64CiliumCallerMemoryWriterWord.fast k e (resultEnv le value) memory) := by
  have masked (temps : CC.TempEnv)
      (a : temps.get ___a64_loss_value = some (.Vlong value))
      (b : temps.get _t'169 = some (.Vlong (BitVec.allOnes 64))) :=
    masked_value e temps memory value a b
  apply internalRun_of_steps
  all_goals
    simp only [source,mask_source,ones_source,action_source,one_source,choice_source,
      steps,InternalPath,InternalState,CC.doStep,width1,width2,width4,width8,ones_value,copy_ones,
      masked,aligned,int_one,bool_one,uint_zero,action_value,choice_true,temp_value,
      w169,wvalue,i169,ivalue,v169,width,index,stored,CC.PTree.gss,binop_type,temp_type,true_value,false_value,
      resultEnv,ite_true,ite_false,Bool.false_eq_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

theorem temp_frame (le : CC.TempEnv) (value : BitVec 64) (id : CC.Ident)
    (h0 : id ≠ _t'169) (h1 : id ≠ ___a64_stw_value) (h2 : id ≠ _t'170)
    (h3 : id ≠ _t'171) (h4 : id ≠ ___a64_stw_action) :
    (resultEnv le value).get id = le.get id := by
  unfold resultEnv
  rw [CC.PTree.gso ___a64_stw_action id _ _ (Ne.symm h4),
    CC.PTree.gso _t'171 id _ _ (Ne.symm h3),
    CC.PTree.gso _t'170 id _ _ (Ne.symm h2),CC.PTree.gso _t'170 id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_stw_value id _ _ (Ne.symm h1),
    CC.PTree.gso _t'169 id _ _ (Ne.symm h0),CC.PTree.gso _t'169 id _ _ (Ne.symm h0),
    CC.PTree.gso _t'169 id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) (value : BitVec 64) :
    (resultEnv le value).get ___a64_stw_value = some (.Vlong value) ∧
    (resultEnv le value).get ___a64_stw_action = some (.Vint (0#32)) := by
  constructor
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_stw_action ___a64_stw_value _ _ (by decide +kernel),
      CC.PTree.gso _t'171 ___a64_stw_value _ _ (by decide +kernel),
      CC.PTree.gso _t'170 ___a64_stw_value _ _ (by decide +kernel),
      CC.PTree.gso _t'170 ___a64_stw_value _ _ (by decide +kernel)]
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    exact CC.PTree.gss _ _ _

/-- The original mask/action31 reaches the actual fast entry; its original3
steps then consume a derived real store on the same current allocation rights. -/
theorem write_and_advance {m before : CC.Mem} (header : Storage m) (value : BitVec 64)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv)
    (width : le.get ___a64_stw_width = some (.Vint (8#32)))
    (index : le.get ___a64_stw_index = some (.Vlong (0#64)))
    (stored : le.get ___a64_loss_value = some (.Vlong value)) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerMemoryWriterWord.Store (before := before) header value,
      InternalRun ge 34 (.State procedure stage k (allocation m).1 le before)
        (.State procedure Arm64CiliumCallerMemoryWriterWord.after k (allocation m).1
          (resultEnv le value) result.after) := by
  have routed := execute (allocation m).1 le before value width index stored k
  have reachedIndex : (resultEnv le value).get ___a64_stw_index = some (.Vlong (0#64)) :=
    (temp_frame le value ___a64_stw_index (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans index
  obtain ⟨result,written⟩ := Arm64CiliumCallerMemoryWriterWord.advance header value access
    (resultEnv le value) reachedIndex (values le value).1 k
  exact ⟨result,routed.trans written⟩

/-- Actual address95 + original mask/action31 + real word store3 =129.
The supplied post-provider SP=-32 and incoming width8 remain explicit; no
provider purity, tag completion or native whole-state refinement is inferred. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (cache : Arm64CiliumCallerReturnMemory.Store (supplied := supplied) locals base)
    (header : Storage m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (tags : Table true m) (wordCells : Cells false m) (tagCells : Cells true m)
    (access : supplied.access = (allocation m).2.access)
    (spRead : CC.Mem.load .Mint64 supplied (scalars.block 0) 0 =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta))
    (abi : CC.Mem.load .Mint8unsigned supplied (header.block 6) 0 = some (.Vint (1#32)))
    (slot : CC.Mem.load .Mint64 supplied tags.block 240 = some (.Vptr (tagCells.block ⟨30,by decide⟩) 0))
    (tag : CC.Mem.load .Mint8unsigned supplied (tagCells.block ⟨30,by decide⟩) 0 = some (.Vint (10#32)))
    (le : CC.TempEnv) (width : le.get ___a64_l_width = some (.Vint (8#32))) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerMemoryWriterWord.Store (before := cache.after) header base,
      InternalRun ge 129
        (.State procedure .Sskip (Arm64CiliumCallerReturnOutcomes.groupCont k) (allocation m).1
          (Arm64CiliumCallerReturnOutcomes.resultEnv
            (Arm64CiliumCallerReturnOutcomes.reachedEnv wordCells tagCells le) base) cache.after)
        (.State procedure Arm64CiliumCallerMemoryWriterWord.after
          (Arm64CiliumCallerMemoryWriterAddress.continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k))
          (allocation m).1
          (resultEnv
            (Arm64CiliumCallerMemoryWriterAddress.resultEnv
              (Arm64CiliumCallerMemoryWriterAddress.incomingEnv wordCells tagCells le base
                Arm64CiliumCallerSPPreindex.delta) Arm64CiliumCallerSPPreindex.delta base) base)
          result.after) := by
  have addressRun := Arm64CiliumCallerMemoryWriterAddress.advance cache header scalars tags wordCells tagCells
    Arm64CiliumCallerSPPreindex.delta spRead abi slot tag le width k
  let incoming := Arm64CiliumCallerMemoryWriterAddress.incomingEnv wordCells tagCells le base
    Arm64CiliumCallerSPPreindex.delta
  have reached := Arm64CiliumCallerMemoryWriterAddress.values incoming Arm64CiliumCallerSPPreindex.delta base
  obtain ⟨result,written⟩ := write_and_advance header base (cache.access.trans access)
    (Arm64CiliumCallerMemoryWriterAddress.resultEnv incoming Arm64CiliumCallerSPPreindex.delta base)
    reached.2.2.1 (Arm64CiliumCallerMemoryWriterAddress.index_zero incoming base) reached.2.2.2
    (Arm64CiliumCallerMemoryWriterAddress.continuation (Arm64CiliumCallerMemoryWriterPrefix.continuation k))
  exact ⟨result,addressRun.trans written⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemoryWriterMask
