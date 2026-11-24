import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseWord

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteLoop

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_release_byte_loop_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Parts where
  initial : CC.Stmt
  body : CC.Stmt
  increment : CC.Stmt
  guard : CC.Stmt
  decisions : CC.Stmt
  test : CC.Expr
  provider : CC.Stmt

private def parts : Parts :=
  match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111 with
  | .Ssequence initial (.Sloop body increment) =>
    match body with
    | .Ssequence guard (.Ssequence decisions (.Sifthenelse test provider .Sskip)) =>
      ⟨initial, body, increment, guard, decisions, test, provider⟩
    | _ => ⟨initial, body, increment, .Sskip, .Sskip, .Econst_int 0 CC.tint, .Sskip⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Econst_int 0 CC.tint, .Sskip⟩

private def initial : CC.Stmt := by run_tac cachePart (← `(parts.initial))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def decisions : CC.Stmt := by run_tac cachePart (← `(parts.decisions))
private def test : CC.Expr := by run_tac cachePart (← `(parts.test))
def providerArm : CC.Stmt := by run_tac cachePart (← `(parts.provider))

def loopContinuation (k : CC.Cont) : CC.Cont := .Kloop1 body increment k

def laneArg (lane : Fin 8) : BitVec 32 := BitVec.ofNat 32 lane.val

def position (slot : Fin 6) (lane : Fin 8) : BitVec 64 :=
  X86RegisterWriteRspReleaseSelect.offset slot + BitVec.ofNat 64 lane.val

def released (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64) : Bool :=
  CC.Integers.Int64.cmp .Cge (position slot lane) old &&
    CC.Integers.Int64.cmp .Clt (position slot lane) next

def arm (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64) : CC.Stmt :=
  if released slot lane old next then providerArm else .Sskip

def temps (le : CC.TempEnv) (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'115
    (CC.Val.ofBool (CC.Integers.Int64.cmp .Cge (position slot lane) old))).set
    X86_program_profile_bpf._t'116 (CC.Val.ofBool (released slot lane old next))

/-- The original byte loop retains both source guard paths and kind-6 arm. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111 =
    .Ssequence initial (.Sloop body increment) ∧
    body = .Ssequence guard (.Ssequence decisions (.Sifthenelse test providerArm .Sskip)) := ⟨rfl, rfl⟩

/-- The real byte fallback initializes lane0 and enters its original loop. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 4
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_111 k e le memory)
      (.State function body (loopContinuation k) e
        (le.set X86_program_profile_bpf.___x86_release_lane__5 (.Vint (0#32))) memory) := by
  rw [source.1]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, initial, loopContinuation,
    CC.doStep, CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.tint, CC.tuint, CC.E0, CC.Eapp]
  all_goals rfl

private theorem fits : ∀ (slot : Fin 6) (lane : Fin 8),
    CC.Integers.Int.cmpu .Clt (X86RegisterWriteRspReleaseSelect.index slot + laneArg lane)
      (CC.Integers.Int.repr 48) = true := by decide +kernel
private theorem lane_fits : ∀ lane : Fin 8,
    CC.Integers.Int.cmpu .Clt (laneArg lane) (CC.Integers.Int.repr 8) = true := by decide +kernel
private theorem lane_cast : ∀ lane : Fin 8,
    CC.Cop.castIntLong .Unsigned (laneArg lane) = BitVec.ofNat 64 lane.val := by decide +kernel

/-- Actual unsigned bounds and signed old/new tests select the untouched
provider or skip arm at every one of the48 byte positions. No heap changes. -/
theorem choose (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (lane : Fin 8) (old next : BitVec 64)
    (observedLane : le.get X86_program_profile_bpf.___x86_release_lane__5 = some (.Vint (laneArg lane)))
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (observedOffset : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (observedOld : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (observedNext : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next)) :
    InternalRun ge 12 (.State function body (loopContinuation k) e le memory)
      (.State function (arm slot lane old next) (loopContinuation k) e
        (temps le slot lane old next) memory) := by
  have fit := fits slot lane
  have laneFit := lane_fits lane
  dsimp only [CC.Integers.Int.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr] at fit laneFit
  have cast : CC.Integers.Int64.repr (CC.Integers.Int.unsigned (laneArg lane)) =
      BitVec.ofNat 64 lane.val := lane_cast lane
  cases first : CC.Integers.Int64.cmp .Cge (position slot lane) old <;>
    cases last : CC.Integers.Int64.cmp .Clt (position slot lane) next <;>
    apply internalRun_of_steps
  all_goals dsimp only [position] at first last
  all_goals simp +decide only [steps, InternalPath, InternalState, body, guard, decisions, test,
    arm, released, temps, position, CC.doStep, CC.doEvalExpr, CC.typeof,
    observedLane, observedIndex, observedOffset, observedOld, observedNext, CC.PTree.gss, CC.PTree.gso,
    fit, laneFit, cast, first, last,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.tint, CC.tuint, CC.tlong, CC.tbool,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.cmpu, CC.Integers.Int64.add, CC.Integers.Int.add, CC.Integers.MI.add,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
    CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.E0, CC.Eapp,
    Bool.and_false, Bool.and_true, Bool.false_and, Bool.true_and,
    List.nil_append, true_and, ite_true, ite_false, Bool.false_eq_true]
  all_goals rfl

private theorem increased : ∀ lane : Fin 8,
    CC.Integers.Int.add (laneArg lane) (CC.Integers.Int.repr 1) =
      BitVec.ofNat 32 (lane.val + 1) := by decide +kernel

/-- The genuine loop backedge increments every original lane, including7 to8. -/
theorem advance (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (lane : Fin 8)
    (observedLane : le.get X86_program_profile_bpf.___x86_release_lane__5 = some (.Vint (laneArg lane))) :
    InternalRun ge 4 (.State function .Sskip (loopContinuation k) e le memory)
      (.State function body (loopContinuation k) e
        (le.set X86_program_profile_bpf.___x86_release_lane__5 (.Vint (BitVec.ofNat 32 (lane.val + 1)))) memory) := by
  have add := increased lane
  dsimp only [CC.Integers.Int.add, CC.Integers.MI.add] at add
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, loopContinuation, increment,
    CC.doStep, CC.doEvalExpr, CC.typeof, observedLane, add,
    CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Integers.Int.add, CC.Integers.MI.add,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.E0, CC.Eapp]
  all_goals rfl

/-- At actual lane8, the original false guard and breaks leave the byte loop. -/
theorem exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem)
    (observedLane : le.get X86_program_profile_bpf.___x86_release_lane__5 = some (.Vint (8#32))) :
    InternalRun ge 4 (.State function body (loopContinuation k) e le memory)
      (.State function .Sskip k e le memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, body, guard, loopContinuation,
    CC.doStep, CC.doEvalExpr, CC.typeof, observedLane,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.tint, CC.tuint, CC.E0, CC.Eapp]

/-- The actual whole-word false branch enters this same original byte loop.
The selector observations and lane0 assignment come from those source runs. -/
theorem fallback (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (slot : Fin 6) (old next : BitVec 64)
    (observedIndex : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (observedOffset : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (observedOld : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (observedNext : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (whole : X86RegisterWriteRspReleaseSelect.whole slot old next = false) :
    InternalRun ge 13 (.State function X86RegisterWriteRspReleaseLoop.iteration k e le memory)
      (.State function body (loopContinuation k) e
        ((X86RegisterWriteRspReleaseSelect.temps le slot old next).set
          X86_program_profile_bpf.___x86_release_lane__5 (.Vint (0#32))) memory) := by
  have chosen := X86RegisterWriteRspReleaseSelect.choose ge function e le k memory slot old next
    observedIndex observedOffset observedOld observedNext
  simp only [X86RegisterWriteRspReleaseSelect.arm, whole, ite_false] at chosen
  exact chosen.trans (enter ge function e (X86RegisterWriteRspReleaseSelect.temps le slot old next) k memory)

end KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteLoop
