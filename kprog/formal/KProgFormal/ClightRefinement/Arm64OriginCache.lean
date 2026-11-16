import KProgFormal.Clight.Arm64Address
import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.ClightRefinement.Arm64Width
import KProgFormal.Reference.Provenance

namespace KProgFormal.ClightRefinement.Arm64OriginCache

def ge : CC.CGenv := Arm64Address.prog.globalenv

private def coordinates : CC.Composite :=
  (ge.genv_cenv.get Arm64Address._kprog_arm64_coordinates).get (by decide +kernel)

private theorem coordinates_binding :
    ge.genv_cenv.get Arm64Address._kprog_arm64_coordinates = some coordinates := by
  decide +kernel

private theorem offsets :
    CC.fieldOffset ge.genv_cenv Arm64Address._sp_base coordinates.co_members = .OK (0, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Address._return_base coordinates.co_members = .OK (8, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Address._sp_valid coordinates.co_members = .OK (24, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Address._return_valid coordinates.co_members = .OK (25, .Full) := by
  decide +kernel

def reader (returns : Bool) : CC.Function :=
  if returns then Arm64Address.f_kprog_arm64_return_base else Arm64Address.f_kprog_arm64_stack_base

def pointer (b : CC.Block) (ofs : CC.Integers.Ptrofs) (delta : CC.Z) : CC.Val :=
  .Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr delta))

/-- The production cache treats every nonzero validity byte as warm. -/
private theorem widened_nonzero (valid : BitVec 8) (h : valid ≠ 0) :
    valid.setWidth 32 ≠ (0#32) := by
  intro heq
  apply h
  simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) heq

/-- Execute each actual exported cache reader from Callstate to Returnstate.
The selected cache's two typed reads suffice; caller memory and offsets remain
arbitrary. The cold native-input branch is not assigned a fabricated result. -/
theorem reader_executes (returns : Bool) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (base : BitVec 64) (valid : BitVec 8)
    (nonzero : valid ≠ 0)
    (hvalid : CC.Mem.loadv .Mint8unsigned m (pointer b ofs (if returns then 25 else 24)) =
      some (.Vint (valid.setWidth 32)))
    (hbase : CC.Mem.loadv .Mint64 m (pointer b ofs (if returns then 8 else 0)) =
      some (.Vlong base)) :
    steps ge 14 (.Callstate (.Internal (reader returns)) [.Vptr b ofs] k m) =
      some (CC.E0, .Returnstate (.Vlong base) (CC.callCont k) m) ∧
    InternalPath ge 14 (.Callstate (.Internal (reader returns)) [.Vptr b ofs] k m) := by
  have hz := widened_nonzero valid nonzero
  have ids : Arm64Address._t'1 ≠ Arm64Address._t'2 := by decide
  have cr : Arm64Address._coordinates ≠ Arm64Address._result := by decide
  have ct1 : Arm64Address._coordinates ≠ Arm64Address._t'1 := by decide
  have ct2 : Arm64Address._coordinates ≠ Arm64Address._t'2 := by decide
  have rt2 : Arm64Address._result ≠ Arm64Address._t'2 := by decide
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp only [pointer] at hvalid hbase
  cases returns <;> simp only [Bool.false_eq_true, ite_false, ite_true] at hvalid hbase
  all_goals
    simp [reader, steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      Arm64Address.f_kprog_arm64_stack_base, Arm64Address.f_kprog_arm64_return_base,
      CC.listNorepet, CC.varNames, CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps,
      CC.createUndefTemps, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfField, CC.doDerefLoc,
      CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode, coordinates_binding, offsets.1, offsets.2.1,
      offsets.2.2.1, offsets.2.2.2, hvalid, hbase,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
      CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.tuchar, CC.tint, CC.tuint, CC.tulong, CC.blocksOfEnv, CC.Mem.freeList,
      CC.emptyEnv, CC.E0, CC.Eapp, CC.PTree.gso, ids, cr, ct1, ct2, rt2,
      ids.symm, cr.symm, ct1.symm, ct2.symm, rt2.symm, hz, empty]

/-- The two actual cache loads, with no stipulated byte contents elsewhere. -/
def WarmCache (returns : Bool) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (base : BitVec 64) : Prop :=
  ∃ valid : BitVec 8, valid ≠ 0 ∧
    CC.Mem.loadv .Mint8unsigned m (pointer b ofs (if returns then 25 else 24)) =
      some (.Vint (valid.setWidth 32)) ∧
    CC.Mem.loadv .Mint64 m (pointer b ofs (if returns then 8 else 0)) = some (.Vlong base)

def materializeSteps (tag : BitVec 8) : Nat :=
  if tag = 4 then 30 else if tag = 10 then 31 else 18

private theorem materialize_names :
    CC.listNorepet (CC.varNames Arm64Address.f_kprog_arm64_materialize.fn_vars) ∧
    CC.listNorepet (CC.varNames Arm64Address.f_kprog_arm64_materialize.fn_params) ∧
    CC.listDisjoint (CC.varNames Arm64Address.f_kprog_arm64_materialize.fn_params)
      (CC.varNames Arm64Address.f_kprog_arm64_materialize.fn_temps) := by
  decide +kernel

private def materializeTemps (ptr value tag : CC.Val) : CC.TempEnv :=
  (((CC.createUndefTemps Arm64Address.f_kprog_arm64_materialize.fn_temps).set
    Arm64Address._coordinates ptr).set Arm64Address._value value).set Arm64Address._tag tag

private theorem materialize_entry (m : CC.Mem) (ptr value tag : CC.Val) :
    CC.doFunctionEntry2 ge Arm64Address.f_kprog_arm64_materialize [ptr, value, tag] m =
      some (CC.emptyEnv, materializeTemps ptr value tag, m) := by
  unfold CC.doFunctionEntry2
  rw [ite_eq_left materialize_names]
  rfl

private structure BodyParts where
  loop : CC.Stmt
  ret : CC.Stmt

private def unpackBody : Option BodyParts :=
  match Arm64Address.f_kprog_arm64_materialize.fn_body with
  | .Ssequence loop ret => some ⟨loop, ret⟩
  | _ => none

private def bodyParts : BodyParts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(unpackBody.get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `origin_body value

private theorem body_eq : Arm64Address.f_kprog_arm64_materialize.fn_body =
    .Ssequence bodyParts.loop bodyParts.ret := rfl

private theorem return_type : Arm64Address.f_kprog_arm64_materialize.fn_return = CC.tulong := rfl

/-- Constructor-specific definitional equations keep an unknown intermediate
state opaque instead of expanding every interpreter branch. -/
private theorem step_materialize (m : CC.Mem) (ptr value tag : CC.Val) (k : CC.Cont) :
    CC.doStep ge (.Callstate (.Internal Arm64Address.f_kprog_arm64_materialize)
      [ptr, value, tag] k m) = some (CC.E0,
        .State Arm64Address.f_kprog_arm64_materialize (.Ssequence bodyParts.loop bodyParts.ret)
          k CC.emptyEnv (materializeTemps ptr value tag) m) := by
  simp only [CC.doStep, materialize_entry, body_eq]

private theorem step_seq (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Ssequence s1 s2) k e le m) =
      some (CC.E0, .State f s1 (.Kseq s2 k) e le m) := rfl

private theorem step_loop (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sloop s1 s2) k e le m) =
      some (CC.E0, .State f s1 (.Kloop1 s1 s2 k) e le m) := rfl

private theorem step_skip_seq (f : CC.Function) (s : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sskip (.Kseq s k) e le m) =
      some (CC.E0, .State f s k e le m) := rfl

private theorem step_skip_loop (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sskip (.Kloop1 s1 s2 k) e le m) =
      some (CC.E0, .State f s2 (.Kloop2 s1 s2 k) e le m) := rfl

private theorem step_break_loop (f : CC.Function) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f .Sbreak (.Kloop2 s1 s2 k) e le m) =
      some (CC.E0, .State f .Sskip k e le m) := rfl

private theorem step_set (f : CC.Function) (id : CC.Ident) (a : CC.Expr) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sset id a) k e le m) =
      (CC.doEvalExpr ge e le m a).map (fun v =>
        (CC.E0, .State f .Sskip k e (le.set id v) m)) := by
  cases he : CC.doEvalExpr ge e le m a <;> simp [CC.doStep, he]

private theorem step_if (f : CC.Function) (a : CC.Expr) (s1 s2 : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sifthenelse a s1 s2) k e le m) =
      (CC.doEvalExpr ge e le m a).bind (fun v =>
        (CC.Cop.boolVal v (CC.typeof a) m).map (fun cond =>
          (CC.E0, .State f (if cond then s1 else s2) k e le m))) := by
  cases he : CC.doEvalExpr ge e le m a with
  | none => simp [CC.doStep, he]
  | some v =>
    cases hb : CC.Cop.boolVal v (CC.typeof a) m <;> simp [CC.doStep, he, hb]

private theorem step_return (f : CC.Function) (a : CC.Expr) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doStep ge (.State f (.Sreturn (some a)) k e le m) =
      (CC.doEvalExpr ge e le m a).bind (fun v =>
        (CC.Cop.semCast v (CC.typeof a) f.fn_return m).bind (fun result =>
          (CC.Mem.freeList m (CC.blocksOfEnv ge.genv_cenv e)).map (fun after =>
            (CC.E0, .Returnstate result (CC.callCont k) after)))) := by
  cases he : CC.doEvalExpr ge e le m a with
  | none => simp [CC.doStep, he]
  | some v =>
    cases hc : CC.Cop.semCast v (CC.typeof a) f.fn_return m with
    | none => simp [CC.doStep, he, hc]
    | some value =>
      cases hf : CC.Mem.freeList m (CC.blocksOfEnv ge.genv_cenv e) <;>
        simp [CC.doStep, he, hc, hf]

private theorem narrow_mask (tag : BitVec 8) :
    tag.setWidth 32 &&& (255#32) = tag.setWidth 32 := by
  change tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = tag.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

private theorem tag_compare_false (m : CC.Mem) (tag : BitVec 8) (code : BitVec 32)
    (hne : tag.setWidth 32 ≠ code) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oeq (.Vint (tag.setWidth 32)) CC.tuchar
      (.Vint code) CC.tuint m = some (.Vint 0) := by
  simp [CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.zero,
    CC.Integers.MI.zero, hne]

private theorem tag_ne_value : Arm64Address._tag ≠ Arm64Address._value := by decide +kernel
private theorem mat_value_ne_tag : Arm64Address.___a64_mat_value ≠ Arm64Address._tag := by decide +kernel
private theorem mat_value_ne_coordinates : Arm64Address.___a64_mat_value ≠ Arm64Address._coordinates := by decide +kernel
private theorem mat_tag_ne_coordinates : Arm64Address.___a64_mat_tag ≠ Arm64Address._coordinates := by decide +kernel
private theorem tag_ne_coordinates : Arm64Address._tag ≠ Arm64Address._coordinates := by decide +kernel
private theorem value_ne_coordinates : Arm64Address._value ≠ Arm64Address._coordinates := by decide +kernel
private theorem stack_valid_ne_coordinates : Arm64Address._t'4 ≠ Arm64Address._coordinates := by decide +kernel
private theorem return_valid_ne_coordinates : Arm64Address._t'3 ≠ Arm64Address._coordinates := by decide +kernel
private theorem stack_valid_ne_mat_value : Arm64Address._t'4 ≠ Arm64Address.___a64_mat_value := by decide +kernel
private theorem return_valid_ne_mat_value : Arm64Address._t'3 ≠ Arm64Address.___a64_mat_value := by decide +kernel
private theorem stack_base_ne_mat_value : Arm64Address.___a64_mat_base ≠ Arm64Address.___a64_mat_value := by decide +kernel
private theorem return_base_ne_mat_value : Arm64Address.___a64_mat_base__1 ≠ Arm64Address.___a64_mat_value := by decide +kernel
private theorem mat_tag_ne_mat_value : Arm64Address.___a64_mat_tag ≠ Arm64Address.___a64_mat_value := by decide +kernel

/-- Actual exported materialization for every 64-bit scalar and byte tag.
Only the selected STACK/RETURN cache is required to be warm. Other tags need
no memory premise. No result is supplied for a cold native-input call. -/
theorem materialize_executes (b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (k : CC.Cont) (origins : Reference.Provenance.AArch64.Origins)
    (value : BitVec 64) (tag : BitVec 8)
    (stack : tag = 4 → WarmCache false b ofs m origins.stack)
    (ret : tag = 10 → WarmCache true b ofs m origins.returnAddress) :
    steps ge (materializeSteps tag)
      (.Callstate (.Internal Arm64Address.f_kprog_arm64_materialize)
        [.Vptr b ofs, .Vlong value, .Vint (tag.setWidth 32)] k m) =
      some (CC.E0, .Returnstate
        (.Vlong (Reference.Provenance.AArch64.materialize origins value tag)) (CC.callCont k) m) ∧
    InternalPath ge (materializeSteps tag)
      (.Callstate (.Internal Arm64Address.f_kprog_arm64_materialize)
        [.Vptr b ofs, .Vlong value, .Vint (tag.setWidth 32)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have tagCast := Arm64Width.cast_argument tag m
  simp only [Arm64Width.argument] at tagCast
  by_cases hs : tag = 4
  · obtain ⟨valid, nz, hv, hb⟩ := stack hs
    have nonzero := widened_nonzero valid nz
    simp only [pointer, Bool.false_eq_true, ite_false] at hv hb
    subst tag
    simp [↓reduceIte, ↓reduceDIte, materializeSteps, steps, InternalPath, InternalState,
      step_materialize, step_seq, step_loop, step_skip_seq, step_skip_loop,
      step_break_loop, step_set, step_if, step_return, materializeTemps, bodyParts, return_type,

      tag_ne_value, mat_value_ne_tag, mat_value_ne_coordinates, mat_tag_ne_coordinates, tag_ne_coordinates, value_ne_coordinates, stack_valid_ne_coordinates, return_valid_ne_coordinates, stack_valid_ne_mat_value, return_valid_ne_mat_value, stack_base_ne_mat_value, return_base_ne_mat_value, mat_tag_ne_mat_value, narrow_mask, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfField,
      CC.doDerefLoc, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
      coordinates_binding, offsets.1, offsets.2.2.1, hv, hb, tagCast,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semAdd,
      CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int64.add, CC.Integers.MI.add,
      CC.tuchar, CC.tint, CC.tuint, CC.tulong, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv,
      CC.E0, CC.Eapp, nonzero, empty, Reference.Provenance.AArch64.materialize]
  · by_cases hr : tag = 10
    · obtain ⟨valid, nz, hv, hb⟩ := ret hr
      have nonzero := widened_nonzero valid nz
      simp only [pointer, ite_true] at hv hb
      subst tag
      simp [↓reduceIte, ↓reduceDIte, materializeSteps, steps, InternalPath, InternalState,
        step_materialize, step_seq, step_loop, step_skip_seq, step_skip_loop,
      step_break_loop, step_set, step_if, step_return, materializeTemps, bodyParts, return_type,

        tag_ne_value, mat_value_ne_tag, mat_value_ne_coordinates, mat_tag_ne_coordinates, tag_ne_coordinates, value_ne_coordinates, stack_valid_ne_coordinates, return_valid_ne_coordinates, stack_valid_ne_mat_value, return_valid_ne_mat_value, stack_base_ne_mat_value, return_base_ne_mat_value, mat_tag_ne_mat_value, narrow_mask, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfField,
        CC.doDerefLoc, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
        coordinates_binding, offsets.2.1, offsets.2.2.2, hv, hb, tagCast,
        CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semAdd,
        CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int64.add, CC.Integers.MI.add,
        CC.tuchar, CC.tint, CC.tuint, CC.tulong, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv,
        CC.E0, CC.Eapp, nonzero, empty, Reference.Provenance.AArch64.materialize]
    · have notStack : tag.setWidth 32 ≠ (4#32) := by
        intro h; apply hs
        simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
      have notReturn : tag.setWidth 32 ≠ (10#32) := by
        intro h; apply hr
        simpa using congrArg (fun x : BitVec 32 => x.setWidth 8) h
      have cmpStack := tag_compare_false m tag (4#32) notStack
      have cmpReturn := tag_compare_false m tag (10#32) notReturn
      simp only [CC.tuchar, CC.tuint] at cmpStack cmpReturn
      have result : Reference.Provenance.AArch64.materialize origins value tag = value := by
        unfold Reference.Provenance.AArch64.materialize
        rw [ite_eq_right hs, ite_eq_right hr]
      have count : materializeSteps tag = 18 := by
        unfold materializeSteps
        rw [ite_eq_right hs, ite_eq_right hr]
      simp only [count]
      simp [↓reduceIte, ↓reduceDIte, materializeSteps, hs, hr, steps, InternalPath, InternalState,
        step_materialize, step_seq, step_loop, step_skip_seq, step_skip_loop,
      step_break_loop, step_set, step_if, step_return, materializeTemps, bodyParts, return_type,

        tag_ne_value, mat_value_ne_tag, mat_value_ne_coordinates, mat_tag_ne_coordinates, tag_ne_coordinates, value_ne_coordinates, stack_valid_ne_coordinates, return_valid_ne_coordinates, stack_valid_ne_mat_value, return_valid_ne_mat_value, stack_base_ne_mat_value, return_base_ne_mat_value, mat_tag_ne_mat_value, narrow_mask, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.PTree.gso, CC.doEvalExpr, tagCast,
        CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.Cop.boolVal, CC.Cop.classifyBool,
        cmpStack, cmpReturn,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.tuchar, CC.tint, CC.tuint, CC.tulong, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv,
        CC.E0, CC.Eapp, notStack, notReturn, empty, Reference.Provenance.AArch64.materialize]
      exact result.symm

/-- Both actual base readers finish in fourteen internal transitions and
retain the complete memory. -/
theorem reader_returns (returns : Bool) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) (base : BitVec 64)
    (warm : WarmCache returns b ofs m base) :
    InternalRun ge 14 (.Callstate (.Internal (reader returns)) [.Vptr b ofs] k m)
      (.Returnstate (.Vlong base) (CC.callCont k) m) := by
  obtain ⟨valid, nonzero, hv, hb⟩ := warm
  have exec := reader_executes returns b ofs m k base valid nonzero hv hb
  exact internalRun_of_steps exec.2 exec.1

/-- The shared C materializer agrees with the existing provenance coordinate
function for every scalar word/tag, including exact whole-memory preservation. -/
theorem materialize_returns (b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (k : CC.Cont) (origins : Reference.Provenance.AArch64.Origins)
    (value : BitVec 64) (tag : BitVec 8)
    (stack : tag = 4 → WarmCache false b ofs m origins.stack)
    (ret : tag = 10 → WarmCache true b ofs m origins.returnAddress) :
    InternalRun ge (materializeSteps tag)
      (.Callstate (.Internal Arm64Address.f_kprog_arm64_materialize)
        [.Vptr b ofs, .Vlong value, .Vint (tag.setWidth 32)] k m)
      (.Returnstate (.Vlong (Reference.Provenance.AArch64.materialize origins value tag))
        (CC.callCont k) m) := by
  have exec := materialize_executes b ofs m k origins value tag stack ret
  exact internalRun_of_steps exec.2 exec.1

/-- Every top-level relational return has the specified result, unchanged
complete memory and empty trace, irrespective of the proposed trace/result. -/
theorem materialize_return_unique (b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem)
    (origins : Reference.Provenance.AArch64.Origins) (value : BitVec 64) (tag : BitVec 8)
    (stack : tag = 4 → WarmCache false b ofs m origins.stack)
    (ret : tag = 10 → WarmCache true b ofs m origins.returnAddress)
    (t : CC.Trace) (result : CC.Val) (after : CC.Mem)
    (observed : CC.Star (CC.Step2 ge)
      (.Callstate (.Internal Arm64Address.f_kprog_arm64_materialize)
        [.Vptr b ofs, .Vlong value, .Vint (tag.setWidth 32)] .Kstop m) t
      (.Returnstate result .Kstop after)) :
    t = CC.E0 ∧ result = .Vlong (Reference.Provenance.AArch64.materialize origins value tag) ∧
      after = m := by
  have run := materialize_returns b ofs m .Kstop origins value tag stack ret
  have stop : ∀ (v : CC.Val) (memory : CC.Mem) u next,
      ¬ CC.Step2 ge (.Returnstate v .Kstop memory) u next := by
    intro v memory u next step
    cases step
  obtain ⟨silent, same⟩ := run.endpoint_unique (stop _ _) observed (stop _ _)
  cases same
  exact ⟨silent, rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64OriginCache
