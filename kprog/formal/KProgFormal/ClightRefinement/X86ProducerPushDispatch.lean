import KProgFormal.ClightRefinement.X86ProducerPushWidth

namespace KProgFormal.ClightRefinement.X86ProducerPushDispatch
open X86ProducerPushCall (handler initialTemps)
open X86ProducerPushWidth (decision loopCont)
open X86ProducerLayout (ge)

def targetCall : CC.Stmt := by
  run_tac do
    let mut todo := #[← Lean.Elab.Term.elabTerm (← `(decision)) none]
    while !todo.isEmpty do
      let item := todo.back!
      todo := todo.pop
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf item)
      if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
        let expression ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if expression.isAppOfArity ``CC.Expr.Evar 2 &&
            expression.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_inline_arm_DISP_PUSH then
          Lean.Elab.Tactic.closeMainGoal `original_x86_push_dispatch_call stmt
          return
      else if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 || stmt.isAppOfArity ``CC.Stmt.Sloop 2 then
        todo := todo.push stmt.getAppArgs[1]!
        todo := todo.push stmt.getAppArgs[0]!
      else if stmt.isAppOfArity ``CC.Stmt.Sifthenelse 3 then
        todo := todo.push stmt.getAppArgs[2]!
        todo := todo.push stmt.getAppArgs[1]!
    throwError "original PUSH dispatch call missing"

def argumentTypes : List CC.Ty :=
  [CC.tptr X86ProducerHeaderSource.headerType, CC.tuchar, CC.tuchar, CC.tuchar,
    CC.tuchar, CC.tuint, CC.tulong, CC.tuchar]
def expression : CC.Expr := .Evar X86_program_profile_bpf._x86_sim_inline_arm_DISP_PUSH
  (.Tfunction argumentTypes CC.tvoid CC.cc_default)
def argumentExpressions : List CC.Expr :=
  [.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType),
    .Econst_int (CC.Integers.Int.repr 18) CC.tuint,
    .Etempvar X86_program_profile_bpf._dst CC.tuchar, .Etempvar X86_program_profile_bpf._src CC.tuchar,
    .Etempvar X86_program_profile_bpf._flags CC.tuchar, .Etempvar X86_program_profile_bpf._aux CC.tuint,
    .Etempvar X86_program_profile_bpf._imm CC.tulong, .Etempvar X86_program_profile_bpf.___x86_dispatch_width CC.tuchar]
def values (binding : CC.Block) : List CC.Val :=
  [.Vptr binding 0, .Vint (18#32), .Vint (255#32), .Vint (3#32), .Vint (8#32), .Vint 0, .Vlong 0, .Vint (8#32)]

theorem target_source : targetCall = .Scall none expression argumentExpressions := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler decision (loopCont k) CC.emptyEnv (X86ProducerPushWidth.temps (initialTemps binding)) memory

/-- The certificate retains every real Step2 transition and exact endpoint.
Only the meta traversal constructs the ordinary kernel-checked proof term. -/
structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory)
    (.State handler targetCall continuation CC.emptyEnv output memory)

/-- Execute the original deterministic decision prefix until its real PUSH
Scall, preserving all false branches/temporary updates/continuations. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : Certificate binding k memory := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    unless goalType.isAppOfArity ``Certificate 3 do throwError "expected original PUSH certificate parameters"
    let parameters := goalType.getAppArgs
    let initial ← Lean.Meta.mkAppM ``start #[parameters[0]!,parameters[1]!,parameters[2]!]
    let originalMem := parameters[2]!
    let originalEnv ← Lean.Elab.Term.elabTerm (← `(CC.emptyEnv)) none
    let originalHandler ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(targetCall)) none
    let silent ← Lean.Elab.Term.elabTerm (← `(CC.E0)) none
    let mut current := initial
    let mut frames : Array Lean.Expr := #[]
    while true do
      let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless state.isAppOfArity ``CC.State.State 6 do throwError "PUSH dispatch left an internal statement state"
      let args := state.getAppArgs
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf args[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
        unless ← Lean.Meta.isDefEq stmt target do throwError "original dispatch selected a different callee"
        unless ← Lean.Meta.isDefEq args[0]! originalHandler do throwError "PUSH dispatch changed wrapper"
        unless ← Lean.Meta.isDefEq args[3]! originalEnv do throwError "PUSH dispatch changed local environment"
        unless ← Lean.Meta.isDefEq args[5]! originalMem do throwError "PUSH decision prefix changed memory"
        let mut proof ← Lean.Meta.mkAppOptM ``InternalRun.refl #[some world, some current]
        let zeroType ← Lean.Meta.mkAppM ``InternalRun #[world, Lean.mkNatLit 0, current, current]
        unless ← Lean.Meta.isDefEq (← Lean.Meta.inferType proof) zeroType do throwError "PUSH certificate endpoint mismatch"
        for transition in frames.toList.reverse do
          let transitionType ← Lean.Meta.inferType transition
          let restType ← Lean.Meta.inferType proof
          let stepArgs := transitionType.getAppArgs
          let restArgs := restType.getAppArgs
          proof ← Lean.Meta.mkAppOptM ``InternalRun.step
            #[some world, some restArgs[1]!, some stepArgs[2]!, some stepArgs[4]!, some restArgs[3]!,
              some (Lean.mkConst ``True.intro), some transition, some proof]
        let term ← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit frames.size, args[4]!, args[2]!, proof]
        Lean.Elab.Tactic.closeMainGoal `original_x86_push_dispatch_path term
        return
      let application ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf application)
      unless result.isAppOfArity ``Option.some 2 do throwError "original PUSH decision prefix has no executable successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      unless pair.isAppOfArity ``Prod.mk 4 do throwError "original PUSH successor changed shape"
      unless ← Lean.Meta.isDefEq pair.getAppArgs[2]! silent do throwError "PUSH decision prefix emitted an external trace"
      let successor := pair.getAppArgs[3]!
      let equation ← Lean.Meta.mkEqRefl result
      let transition ← Lean.Meta.mkAppM ``CC.doStep_sound #[world,current,silent,successor,equation]
      frames := frames.push transition
      current := successor

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge (certificate binding k memory).count (start binding k memory)
      (.State handler targetCall (certificate binding k memory).continuation CC.emptyEnv
        (certificate binding k memory).output memory) := (certificate binding k memory).run

/-- The actual selected PUSH call still receives every original source
argument and the effective width, not a rebuilt instruction record. -/
theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    CC.doEvalExprlist ge CC.emptyEnv (certificate binding k memory).output memory
      argumentExpressions argumentTypes = some (values binding) := by rfl

/-- The exact original outer loop continuation survives all dispatch guards. -/
theorem source_continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    (certificate binding k memory).continuation = loopCont k := by rfl

end KProgFormal.ClightRefinement.X86ProducerPushDispatch
