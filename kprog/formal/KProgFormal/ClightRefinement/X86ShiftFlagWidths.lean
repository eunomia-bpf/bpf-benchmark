import KProgFormal.ClightRefinement.X86ShiftLeftClassify
import KProgFormal.ClightRefinement.X86Width
import KProgFormal.ClightRefinement.X86WidthShape

namespace KProgFormal.ClightRefinement.X86ShiftFlagWidths

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_flag_widths
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  raw : CC.Stmt
  effective : CC.Stmt
  bits : CC.Stmt
  mask : CC.Stmt
  rest : CC.Stmt
  loopExit : CC.Stmt
  branchExit : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftLeftClassify.shiftBranch with
  | .Ssequence (.Ssequence (.Sloop
      (.Ssequence raw (.Ssequence effective (.Ssequence bits (.Ssequence mask rest))))
      loopExit) branchExit) tail =>
    ⟨raw, effective, bits, mask, rest, loopExit, branchExit, tail⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def raw : CC.Stmt := by run_tac cachePart (← `(pieces.raw))
def effective : CC.Stmt := by run_tac cachePart (← `(pieces.effective))
def bits : CC.Stmt := by run_tac cachePart (← `(pieces.bits))
def mask : CC.Stmt := by run_tac cachePart (← `(pieces.mask))
def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- The prefix and its original loop, branch and case fallthrough are actual source. -/
theorem source : X86ShiftLeftClassify.shiftBranch =
    .Ssequence (.Ssequence (.Sloop
      (.Ssequence raw (.Ssequence effective (.Ssequence bits (.Ssequence mask rest))))
      pieces.loopExit) pieces.branchExit) pieces.tail := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 (.Ssequence raw (.Ssequence effective (.Ssequence bits (.Ssequence mask rest))))
    pieces.loopExit (.Kseq pieces.branchExit (.Kseq pieces.tail k))

def argument (size : X86.Size) : CC.Val :=
  X86WidthShape.argument (BitVec.ofNat 8 size.bytes)

def rawTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___x86_sh_raw_width (argument size)

def effectiveTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'63 (argument size)).set
    X86_program_profile_bpf.___x86_sh_width (argument size)

def bitsTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'64 (.Vint (BitVec.ofNat 32 size.bits))).set
    X86_program_profile_bpf.___x86_sh_bits (.Vint (BitVec.ofNat 32 size.bits))

def maskTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'65 (.Vlong size.mask)).set
    X86_program_profile_bpf.___x86_sh_mask (.Vlong size.mask)

def afterTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  maskTemps (bitsTemps (effectiveTemps (rawTemps le size) size) size) size

/-- The genuine branch enters its loop and records the raw architectural width. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (argument size)) :
    InternalRun ge 6 (.State function X86ShiftLeftClassify.shiftBranch k e le m)
      (.State function (.Ssequence effective (.Ssequence bits (.Ssequence mask rest)))
        (continuation k) e (rawTemps le size) m) := by
  rw [source]
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [InternalPath, InternalState, steps, raw, CC.doStep, CC.doEvalExpr,
      CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      argument, X86WidthShape.argument, X86.Size.bytes, width, rawTemps, continuation,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Eapp, CC.E0]


private def effectiveAssign : CC.Stmt := by
  run_tac cachePart (← `(match effective with | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem effective_plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_raw_width = some (argument size)) :
    ∃ callK, InternalRun ge 2 (.State function effective k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [argument size] callK m) ∧
    InternalRun ge 3 (.Returnstate (argument size) (CC.callCont callK) m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_width_effective) =
      .Tfunction [CC.tuchar] CC.tuchar CC.cc_default := rfl
  refine ⟨.Kcall (some X86_program_profile_bpf._t'63) function e le
    (.Kseq effectiveAssign k), ?beforeCall, ?afterCall⟩
  case beforeCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effective, effectiveAssign, CC.typeof,   CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
      CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      unshadowed, observed, symbol, callee,  argument, X86WidthShape.argument,
      X86.Size.bytes, CC.Eapp, CC.E0]
  case afterCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, effectiveTemps, effectiveAssign, CC.doStep, CC.doEvalExpr,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.typeof,
        CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.callCont, CC.setOpttemp, argument, X86WidthShape.argument,
        X86.Size.bytes,   CC.Eapp, CC.E0]

/-- The actual effective call and caller assignments return the mature ISA value. -/
theorem effective_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_raw_width = some (argument size)) :
    InternalRun ge (2 + (6) + 3) (.State function effective k e le m)
      (.State function .Sskip k e (effectiveTemps le size) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    effective_plumbing ge block binding function e le unshadowed size k m observed
  have value : X86Width.result (BitVec.ofNat 8 size.bytes) = (argument size) := by cases size <;> rfl
  have body : InternalRun ge (6)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [argument size] callK m)
      (.Returnstate (argument size) (CC.callCont callK) m) := by
    simpa only [argument, X86WidthShape.argument, X86Width.argument, value] using
      X86Width.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans body).trans afterCall

private def bitsAssign : CC.Stmt := by
  run_tac cachePart (← `(match bits with | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem bits_plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_bits = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_width = some (argument size)) :
    ∃ callK, InternalRun ge 2 (.State function bits k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits) [argument size] callK m) ∧
    InternalRun ge 3 (.Returnstate (.Vint (BitVec.ofNat 32 size.bits)) (CC.callCont callK) m)
      (.State function .Sskip k e (bitsTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_width_bits) =
      .Tfunction [CC.tuchar] CC.tuint CC.cc_default := rfl
  refine ⟨.Kcall (some X86_program_profile_bpf._t'64) function e le
    (.Kseq bitsAssign k), ?beforeCall, ?afterCall⟩
  case beforeCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, bits, bitsAssign, CC.typeof,  CC.tuint, CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
      CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      unshadowed, observed, symbol, callee,  argument, X86WidthShape.argument,
      X86.Size.bytes, CC.Eapp, CC.E0]
  case afterCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, bitsTemps, bitsAssign, CC.doStep, CC.doEvalExpr,
           
          
        CC.callCont, CC.setOpttemp,  
         X86.Size.bits,  CC.Eapp, CC.E0]

/-- The actual bits call and caller assignments return the mature ISA value. -/
theorem bits_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_bits = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_width = some (argument size)) :
    InternalRun ge (2 + (X86WidthShape.length (BitVec.ofNat 8 size.bytes)) + 3) (.State function bits k e le m)
      (.State function .Sskip k e (bitsTemps le size) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    bits_plumbing ge block binding function e le unshadowed size k m observed
  have value : X86WidthShape.Bits.result (BitVec.ofNat 8 size.bytes) = (.Vint (BitVec.ofNat 32 size.bits)) := by cases size <;> rfl
  have body : InternalRun ge (X86WidthShape.length (BitVec.ofNat 8 size.bytes))
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_bits) [argument size] callK m)
      (.Returnstate (.Vint (BitVec.ofNat 32 size.bits)) (CC.callCont callK) m) := by
    simpa only [argument, X86WidthShape.argument, X86Width.argument, value] using
      X86WidthShape.Bits.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans body).trans afterCall

private def maskAssign : CC.Stmt := by
  run_tac cachePart (← `(match mask with | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem mask_plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_mask = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_width = some (argument size)) :
    ∃ callK, InternalRun ge 2 (.State function mask k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask) [argument size] callK m) ∧
    InternalRun ge 3 (.Returnstate (.Vlong size.mask) (CC.callCont callK) m)
      (.State function .Sskip k e (maskTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_width_mask) =
      .Tfunction [CC.tuchar] CC.tulong CC.cc_default := rfl
  refine ⟨.Kcall (some X86_program_profile_bpf._t'65) function e le
    (.Kseq maskAssign k), ?beforeCall, ?afterCall⟩
  case beforeCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, mask, maskAssign, CC.typeof, CC.tulong,  CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
      CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      unshadowed, observed, symbol, callee,  argument, X86WidthShape.argument,
      X86.Size.bytes, CC.Eapp, CC.E0]
  case afterCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, maskTemps, maskAssign, CC.doStep, CC.doEvalExpr,
           
          
        CC.callCont, CC.setOpttemp,  
          X86.Size.mask, CC.Eapp, CC.E0]

/-- The actual mask call and caller assignments return the mature ISA value. -/
theorem mask_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_mask = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_sh_width = some (argument size)) :
    InternalRun ge (2 + (X86WidthShape.length (BitVec.ofNat 8 size.bytes)) + 3) (.State function mask k e le m)
      (.State function .Sskip k e (maskTemps le size) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    mask_plumbing ge block binding function e le unshadowed size k m observed
  have value : X86WidthShape.Mask.result (BitVec.ofNat 8 size.bytes) = (.Vlong size.mask) := by cases size <;> rfl
  have body : InternalRun ge (X86WidthShape.length (BitVec.ofNat 8 size.bytes))
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_mask) [argument size] callK m)
      (.Returnstate (.Vlong size.mask) (CC.callCont callK) m) := by
    simpa only [argument, X86WidthShape.argument, X86Width.argument, value] using
      X86WidthShape.Mask.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans body).trans afterCall


private theorem sequence {ge : CC.CGenv} {n : Nat} {function : CC.Function}
    {head tail : CC.Stmt} {k : CC.Cont} {e : CC.Env} {le next : CC.TempEnv} {m : CC.Mem}
    (run : InternalRun ge n (.State function head (.Kseq tail k) e le m)
      (.State function .Sskip (.Kseq tail k) e next m)) :
    InternalRun ge (1 + n + 1) (.State function (.Ssequence head tail) k e le m)
      (.State function tail k e next m) := by
  have first : InternalRun ge 1 (.State function (.Ssequence head tail) k e le m)
      (.State function head (.Kseq tail k) e le m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have last : InternalRun ge 1 (.State function .Sskip (.Kseq tail k) e next m)
      (.State function tail k e next m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (first.trans run).trans last

def length (size : X86.Size) : Nat :=
  33 + 2 * X86WidthShape.length (BitVec.ofNat 8 size.bytes)

/-- The original selected flag branch executes all three real calls, deriving
the exact width, bit count and mask in the same heap and caller. -/
theorem internal (ge : CC.CGenv) (effectiveBlock bitsBlock maskBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (maskBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some maskBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv maskBlock = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none ∧
      e.get X86_program_profile_bpf._x86_width_mask = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (argument size)) :
    InternalRun ge (length size) (.State function X86ShiftLeftClassify.shiftBranch k e le m)
      (.State function rest (continuation k) e (afterTemps le size) m) := by
  have start := enter ge function e le size k m width
  have effectiveArg : (rawTemps le size).get X86_program_profile_bpf.___x86_sh_raw_width =
      some (argument size) := by simp [rawTemps]
  have eff := sequence (effective_internal ge effectiveBlock effectiveBinding function e
    (rawTemps le size) unshadowed.1 size
    (.Kseq (.Ssequence bits (.Ssequence mask rest)) (continuation k)) m effectiveArg)
  have bitsArg : (effectiveTemps (rawTemps le size) size).get
      X86_program_profile_bpf.___x86_sh_width = some (argument size) := by simp [effectiveTemps]
  have bitRun := sequence (bits_internal ge bitsBlock bitsBinding function e
    (effectiveTemps (rawTemps le size) size) unshadowed.2.1 size
    (.Kseq (.Ssequence mask rest) (continuation k)) m bitsArg)
  have maskArg : (bitsTemps (effectiveTemps (rawTemps le size) size) size).get
      X86_program_profile_bpf.___x86_sh_width = some (argument size) := by
    simp +decide [bitsTemps, effectiveTemps, CC.PTree.gso]
  have maskRun := sequence (mask_internal ge maskBlock maskBinding function e
    (bitsTemps (effectiveTemps (rawTemps le size) size) size) unshadowed.2.2 size
    (.Kseq rest (continuation k)) m maskArg)
  have run := ((start.trans eff).trans bitRun).trans maskRun
  have count : 6 + (1 + (2 + 6 + 3) + 1) +
      (1 + (2 + X86WidthShape.length (BitVec.ofNat 8 size.bytes) + 3) + 1) +
      (1 + (2 + X86WidthShape.length (BitVec.ofNat 8 size.bytes) + 3) + 1) = length size := by
    unfold length
    omega
  rw [count] at run
  exact run

/-- The actual source prefix has a silent relational execution with the complete
original memory and the source loop and case fallthrough continuation. -/
theorem returns (ge : CC.CGenv) (effectiveBlock bitsBlock maskBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (maskBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some maskBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv maskBlock = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none ∧
      e.get X86_program_profile_bpf._x86_width_mask = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (argument size)) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftLeftClassify.shiftBranch k e le m) CC.E0
      (.State function rest (continuation k) e (afterTemps le size) m) :=
  (internal ge effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding
    function e le unshadowed size k m width).sound

/-- Every newly written source temporary reads back its derived ISA width value. -/
theorem temps (le : CC.TempEnv) (size : X86.Size) :
    (afterTemps le size).get X86_program_profile_bpf.___x86_sh_raw_width = some (argument size) ∧
    (afterTemps le size).get X86_program_profile_bpf._t'63 = some (argument size) ∧
    (afterTemps le size).get X86_program_profile_bpf.___x86_sh_width = some (argument size) ∧
    (afterTemps le size).get X86_program_profile_bpf._t'64 = some (.Vint (BitVec.ofNat 32 size.bits)) ∧
    (afterTemps le size).get X86_program_profile_bpf.___x86_sh_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)) ∧
    (afterTemps le size).get X86_program_profile_bpf._t'65 = some (.Vlong size.mask) ∧
    (afterTemps le size).get X86_program_profile_bpf.___x86_sh_mask = some (.Vlong size.mask) := by
  simp +decide [afterTemps, maskTemps, bitsTemps, effectiveTemps, rawTemps, CC.PTree.gso]

/-- All other temporaries retain their incoming values through the exact source writes. -/
theorem frame (le : CC.TempEnv) (size : X86.Size) (id : CC.Ident)
    (rawNe : id ≠ X86_program_profile_bpf.___x86_sh_raw_width)
    (effectiveCallNe : id ≠ X86_program_profile_bpf._t'63)
    (effectiveNe : id ≠ X86_program_profile_bpf.___x86_sh_width)
    (bitsCallNe : id ≠ X86_program_profile_bpf._t'64)
    (bitsNe : id ≠ X86_program_profile_bpf.___x86_sh_bits)
    (maskCallNe : id ≠ X86_program_profile_bpf._t'65)
    (maskNe : id ≠ X86_program_profile_bpf.___x86_sh_mask) :
    (afterTemps le size).get id = le.get id := by
  simp [afterTemps, maskTemps, bitsTemps, effectiveTemps, rawTemps, CC.PTree.gso,
    Ne.symm rawNe, Ne.symm effectiveCallNe, Ne.symm effectiveNe, Ne.symm bitsCallNe,
    Ne.symm bitsNe, Ne.symm maskCallNe, Ne.symm maskNe]

end KProgFormal.ClightRefinement.X86ShiftFlagWidths
