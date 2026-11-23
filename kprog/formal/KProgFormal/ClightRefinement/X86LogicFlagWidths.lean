import KProgFormal.ClightRefinement.X86LogicFlagClassify
import KProgFormal.ClightRefinement.X86Width
import KProgFormal.ClightRefinement.X86ApplyWidth

namespace KProgFormal.ClightRefinement.X86LogicFlagWidths

private structure Pieces where
  effective : CC.Stmt
  applyWidth : CC.Stmt
  bits : CC.Stmt
  rest : CC.Stmt
  loopExit : CC.Stmt
  branchExit : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces :=
  match X86LogicFlagClassify.branch with
  | .Ssequence (.Ssequence (.Sloop
      (.Ssequence effective (.Ssequence applyWidth (.Ssequence bits rest))) loopExit) branchExit) tail =>
    ⟨effective, applyWidth, bits, rest, loopExit, branchExit, tail⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_width_source
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def effective : CC.Stmt := by run_tac cachePart (← `(pieces.effective))
def applyWidth : CC.Stmt := by run_tac cachePart (← `(pieces.applyWidth))
def bits : CC.Stmt := by run_tac cachePart (← `(pieces.bits))
def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

private def body : CC.Stmt := .Ssequence effective (.Ssequence applyWidth (.Ssequence bits rest))

theorem source : X86LogicFlagClassify.branch =
    .Ssequence (.Ssequence (.Sloop body pieces.loopExit) pieces.branchExit) pieces.tail := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 body pieces.loopExit (.Kseq pieces.branchExit (.Kseq pieces.tail k))

def effectiveTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'78 (X86ShiftLeft.argument size)).set
    X86_program_profile_bpf.___x86_fl_width (X86ShiftLeft.argument size)

/-- Four original sequence/loop steps enter the real logical width call. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 4 (.State function X86LogicFlagClassify.branch k e le m)
      (.State function effective (.Kseq (.Ssequence applyWidth (.Ssequence bits rest))
        (continuation k)) e le m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp [steps, InternalPath, InternalState, body, continuation, CC.doStep, CC.Eapp, CC.E0]

private def effectiveAssign : CC.Stmt := by
  run_tac cachePart (← `(match effective with | .Ssequence _ assignment => assignment | _ => .Sskip))

/-- The real width call and original cast/assign return the effective ISA size. -/
theorem effective_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 11 (.State function effective k e le m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  let callK := CC.Cont.Kcall (some X86_program_profile_bpf._t'78) function e le
    (.Kseq effectiveAssign k)
  have beforeCall : InternalRun ge 2 (.State function effective k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86ShiftLeft.argument size] callK m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effective, effectiveAssign, callK,
        CC.typeof, CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
        CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
        unshadowed, observed, symbol, callee, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have afterCall : InternalRun ge 3
      (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effectiveTemps, effectiveAssign, callK,
        CC.doStep, CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.typeof, CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.callCont, CC.setOpttemp, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have value : X86Width.result (BitVec.ofNat 8 size.bytes) = X86ShiftLeft.argument size := by
    cases size <;> rfl
  have argument : X86Width.argument (BitVec.ofNat 8 size.bytes) = X86ShiftLeft.argument size := by
    cases size <;> rfl
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective)
        [X86ShiftLeft.argument size] callK m)
      (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m) := by
    simpa only [argument, value] using
      X86Width.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans helper).trans afterCall

/-- The actual branch prefix reaches its real width-application statement. -/
theorem to_apply (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 17 (.State function X86LogicFlagClassify.branch k e le m)
      (.State function applyWidth (.Kseq (.Ssequence bits rest) (continuation k)) e
        (effectiveTemps le size) m) := by
  have numerical := effective_internal ge block binding function e le unshadowed size
    (.Kseq (.Ssequence applyWidth (.Ssequence bits rest)) (continuation k)) m observed
  have next : InternalRun ge 2
      (.State function .Sskip (.Kseq (.Ssequence applyWidth (.Ssequence bits rest)) (continuation k))
        e (effectiveTemps le size) m)
      (.State function applyWidth (.Kseq (.Ssequence bits rest) (continuation k)) e
        (effectiveTemps le size) m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  exact ((enter ge function e le k m).trans numerical).trans next

def appliedTemps (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'79 (.Vlong (X86.Value.trunc size value))).set
    X86_program_profile_bpf.___x86_fl_value (.Vlong (X86.Value.trunc size value))

def bitsTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'80 (.Vint (BitVec.ofNat 32 size.bits))).set
    X86_program_profile_bpf.___x86_fl_bits (.Vint (BitVec.ofNat 32 size.bits))

private def applyAssign : CC.Stmt := by
  run_tac cachePart (← `(match applyWidth with | .Ssequence _ assignment => assignment | _ => .Sskip))
private def bitsAssign : CC.Stmt := by
  run_tac cachePart (← `(match bits with | .Ssequence _ assignment => assignment | _ => .Sskip))

/-- The original two-argument width application executes its complete helper
and resumes through both original result assignments. -/
theorem apply_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_apply_width = none)
    (value : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (width : le.get X86_program_profile_bpf.___x86_fl_width = some (X86ShiftLeft.argument size)) :
    InternalRun ge (2 + X86ApplyWidth.length size + 3) (.State function applyWidth k e le m)
      (.State function .Sskip k e (appliedTemps le value size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  let callK := CC.Cont.Kcall (some X86_program_profile_bpf._t'79) function e le
    (.Kseq applyAssign k)
  have beforeCall : InternalRun ge 2 (.State function applyWidth k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_apply_width)
        [.Vlong value, X86ShiftLeft.argument size] callK m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, applyWidth, applyAssign, callK,
        CC.typeof, CC.tuchar, CC.tulong, CC.cc_default, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
        CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
        unshadowed, word, width, symbol, callee, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have afterCall : InternalRun ge 3
      (.Returnstate (.Vlong (X86.Value.trunc size value)) (CC.callCont callK) m)
      (.State function .Sskip k e (appliedTemps le value size) m) := by
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, appliedTemps, applyAssign, callK,
        CC.doStep, CC.doEvalExpr, CC.callCont, CC.setOpttemp, CC.Eapp, CC.E0]
  exact (beforeCall.trans (X86ApplyWidth.internal ge value size callK m)).trans afterCall

/-- Original bit-count call, complete helper and caller assignment produce
the precise native operand bit count. -/
theorem bits_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_bits = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_fl_width = some (X86ShiftLeft.argument size)) :
    InternalRun ge (2 + X86WidthShape.length (BitVec.ofNat 8 size.bytes) + 3)
      (.State function bits k e le m) (.State function .Sskip k e (bitsTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  let callK := CC.Cont.Kcall (some X86_program_profile_bpf._t'80) function e le
    (.Kseq bitsAssign k)
  have beforeCall : InternalRun ge 2 (.State function bits k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [X86ShiftLeft.argument size] callK m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, bits, bitsAssign, callK,
        CC.typeof, CC.tuchar, CC.tuint, CC.cc_default, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
        CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
        unshadowed, width, symbol, callee, X86ShiftLeft.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  have afterCall : InternalRun ge 3
      (.Returnstate (.Vint (BitVec.ofNat 32 size.bits)) (CC.callCont callK) m)
      (.State function .Sskip k e (bitsTemps le size) m) := by
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, bitsTemps, bitsAssign, callK,
        CC.doStep, CC.doEvalExpr, CC.callCont, CC.setOpttemp, CC.Eapp, CC.E0]
  have argument : X86WidthShape.argument (BitVec.ofNat 8 size.bytes) = X86ShiftLeft.argument size := by
    cases size <;> rfl
  have value : X86WidthShape.Bits.result (BitVec.ofNat 8 size.bytes) =
      .Vint (BitVec.ofNat 32 size.bits) := by cases size <;> rfl
  have helper : InternalRun ge (X86WidthShape.length (BitVec.ofNat 8 size.bytes))
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits)
        [X86ShiftLeft.argument size] callK m)
      (.Returnstate (.Vint (BitVec.ofNat 32 size.bits)) (CC.callCont callK) m) := by
    simpa only [argument, value] using
      X86WidthShape.Bits.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans helper).trans afterCall

def preparedTemps (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  bitsTemps (appliedTemps (effectiveTemps le size) value size) size

def length (size : X86.Size) : Nat :=
  30 + X86ApplyWidth.length size + X86WidthShape.length (BitVec.ofNat 8 size.bytes)

/-- All three actual helper calls compose from the original branch through
its complete width/value/bits preparation to the real flag storage sequence. -/
theorem prepare (ge : CC.CGenv) (effectiveBlock applyBlock bitsBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (applyBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_apply_width = some applyBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv applyBlock =
        some (.Internal X86_program_profile_bpf.f_x86_apply_width))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_apply_width = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none)
    (value : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (word : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge (length size) (.State function X86LogicFlagClassify.branch k e le m)
      (.State function rest (continuation k) e (preparedTemps le value size) m) := by
  let effectiveLe := effectiveTemps le size
  let appliedLe := appliedTemps effectiveLe value size
  have first := to_apply ge effectiveBlock effectiveBinding function e le unshadowed.1 size k m width
  have wordReady : effectiveLe.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value) := by
    simp +decide [effectiveLe, effectiveTemps, CC.PTree.gso, word]
  have widthReady : effectiveLe.get X86_program_profile_bpf.___x86_fl_width =
      some (X86ShiftLeft.argument size) := by simp [effectiveLe, effectiveTemps]
  have applyRun := apply_internal ge applyBlock applyBinding function e effectiveLe unshadowed.2.1
    value size (.Kseq (.Ssequence bits rest) (continuation k)) m wordReady widthReady
  have nextBits : InternalRun ge 2
      (.State function .Sskip (.Kseq (.Ssequence bits rest) (continuation k)) e appliedLe m)
      (.State function bits (.Kseq rest (continuation k)) e appliedLe m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  have bitsWidth : appliedLe.get X86_program_profile_bpf.___x86_fl_width =
      some (X86ShiftLeft.argument size) := by
    simp +decide [appliedLe, appliedTemps, CC.PTree.gso, widthReady]
  have bitsRun := bits_internal ge bitsBlock bitsBinding function e appliedLe unshadowed.2.2
    size (.Kseq rest (continuation k)) m bitsWidth
  have nextRest : InternalRun ge 1
      (.State function .Sskip (.Kseq rest (continuation k)) e (bitsTemps appliedLe size) m)
      (.State function rest (continuation k) e (bitsTemps appliedLe size) m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  have count : (((17 + (2 + X86ApplyWidth.length size + 3)) + 2) +
      (2 + X86WidthShape.length (BitVec.ofNat 8 size.bytes) + 3)) + 1 = length size := by
    dsimp only [length]
    omega
  have run := (((first.trans applyRun).trans nextBits).trans bitsRun).trans nextRest
  rw [count] at run
  exact run

/-- The real prepared temporaries carry the exact native width, truncated
word and bit count, while every other incoming temporary is retained. -/
theorem observations (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) :
    (preparedTemps le value size).get X86_program_profile_bpf.___x86_fl_width =
      some (X86ShiftLeft.argument size) ∧
    (preparedTemps le value size).get X86_program_profile_bpf.___x86_fl_value =
      some (.Vlong (X86.Value.trunc size value)) ∧
    (preparedTemps le value size).get X86_program_profile_bpf.___x86_fl_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'78 →
      id ≠ X86_program_profile_bpf.___x86_fl_width →
      id ≠ X86_program_profile_bpf._t'79 → id ≠ X86_program_profile_bpf.___x86_fl_value →
      id ≠ X86_program_profile_bpf._t'80 → id ≠ X86_program_profile_bpf.___x86_fl_bits →
      (preparedTemps le value size).get id = le.get id := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · simp +decide [preparedTemps, effectiveTemps, appliedTemps, bitsTemps, CC.PTree.gss, CC.PTree.gso]
  · simp +decide [preparedTemps, effectiveTemps, appliedTemps, bitsTemps, CC.PTree.gss, CC.PTree.gso]
  · simp +decide [preparedTemps, effectiveTemps, appliedTemps, bitsTemps, CC.PTree.gss, CC.PTree.gso]
  · intro id first width second word third bits
    simp [preparedTemps, effectiveTemps, appliedTemps, bitsTemps, CC.PTree.gso,
      Ne.symm first, Ne.symm width, Ne.symm second, Ne.symm word, Ne.symm third, Ne.symm bits]

end KProgFormal.ClightRefinement.X86LogicFlagWidths
