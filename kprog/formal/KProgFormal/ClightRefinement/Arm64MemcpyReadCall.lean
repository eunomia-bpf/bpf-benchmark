import KProgFormal.ClightRefinement.Arm64MemcpyPointerRoute

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadCall

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

abbrev reader := Arm64Program.f_kprog_arm64_program_memory_read

private structure Parts where
  body : CC.Stmt
  offset : CC.Stmt
  afterOffset : CC.Stmt
  width : CC.Stmt
  afterWidth : CC.Stmt
  value : CC.Stmt
  call : CC.Stmt
  copy : CC.Stmt
  store : CC.Stmt
  args : List CC.Expr
  fn : CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy memory-reader call changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyPointerRoute.loss)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let afterOffset ← peel body[1]! ``CC.Stmt.Ssequence 2
    let afterWidth ← peel afterOffset[1]! ``CC.Stmt.Ssequence 2
    let value ← peel afterWidth[0]! ``CC.Stmt.Ssequence 2
    let call ← peel value[0]! ``CC.Stmt.Scall 3
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_memory_reader_call
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,body[0]!,body[1]!,afterOffset[0]!,afterOffset[1]!,
        afterWidth[0]!,value[0]!,value[1]!,afterWidth[1]!,call[2]!,call[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_memory_reader_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def offset : CC.Stmt := by run_tac cachePart (← `(parts.offset))
private def afterOffset : CC.Stmt := by run_tac cachePart (← `(parts.afterOffset))
private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def afterWidth : CC.Stmt := by run_tac cachePart (← `(parts.afterWidth))
private def value : CC.Stmt := by run_tac cachePart (← `(parts.value))
def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
private def args : List CC.Expr := by run_tac cachePart (← `(parts.args))
private def fn : CC.Expr := by run_tac cachePart (← `(parts.fn))

private theorem loop_source : Arm64MemcpyPointerRoute.loss = .Sloop body .Sbreak := rfl
private theorem body_source : body = .Ssequence offset afterOffset := rfl
private theorem offset_source : afterOffset = .Ssequence width afterWidth := rfl
private theorem width_source : afterWidth = .Ssequence value store := rfl
private theorem value_source : value = .Ssequence call copy := rfl
theorem call_source : call = .Scall (some Arm64Program._t'29) fn args := rfl

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq copy (.Kseq store (.Kloop1 body .Sbreak k))

def temps (le : CC.TempEnv) (base extra : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program.___a64_loss_off (.Vlong (base + extra))).set
    Arm64Program.___a64_loss_width (.Vint 1)

/-- The real destination-offset and width assignments precede the nested
source-byte read, keeping its actual value/store continuation. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (base extra : BitVec 64)
    (hbase : le.get Arm64Program.___a64_mwr_base = some (.Vlong base))
    (hoff : le.get Arm64Program.___a64_mwr_off = some (.Vlong extra)) :
    InternalRun world 9 (.State handler Arm64MemcpyPointerRoute.loss k e le m)
      (.State handler call (continuation k) e (temps le base extra) m) := by
  apply internalRun_of_steps
  all_goals simp +decide [loop_source,body_source,offset_source,width_source,value_source,
    offset,width,temps,continuation,InternalPath,InternalState,steps,CC.doStep,CC.doEvalExpr,hbase,hoff,
    CC.typeof,CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tlong,CC.tuchar,CC.tuint,
    CC.Archi.ptr64,CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int.zero_ext,
    CC.Integers.MI.zero_ext,CC.Integers.Int.repr,CC.Integers.MI.repr,CC.E0,CC.Eapp,List.nil_append]

def arguments (entry : CC.Block) (extra : BitVec 64) : List CC.Val :=
  [.Vptr entry 0,.Vlong 1,.Vlong 255,.Vint 255,.Vlong 0,.Vlong extra,.Vint 1]

private def symbol : CC.Block := CC.Positive.ofNat 108
theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_memory_read = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal reader) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

/-- All seven actual C arguments are evaluated and cast by the original
Clight call rule; the memcpy environment and temps are saved in Kcall. -/
theorem call_step (before m : CC.Mem) (entry : CC.Block) (extra : BitVec 64) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong extra)) :
    CC.Step2 world (.State handler call k (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal reader) (arguments entry extra)
        (.Kcall (some Arm64Program._t'29) handler (Arm64MemcpySource.allocation before).1 le k) m) := by
  have unshadowed : (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_memory_read = none := by
    have outside : Arm64Program._kprog_arm64_program_memory_read ∉ CC.varNames handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),
      CC.tulong,CC.tulong,CC.tuint,CC.tulong,CC.tlong,CC.tuchar])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [fn,CC.doEvalExpr,CC.lvalOfVar,unshadowed,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [args,arguments,CC.doEvalExprlist,CC.doEvalExpr,hentry,hi]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Returning from that real nested call restores the saved memcpy frame,
copies the actual reader word and enters the original destination store. -/
theorem resume (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (word : BitVec 64) :
    InternalRun world 4
      (.Returnstate (.Vlong word) (.Kcall (some Arm64Program._t'29) handler e le (continuation k)) m)
      (.State handler store (.Kloop1 body .Sbreak k) e
        ((le.set Arm64Program._t'29 (.Vlong word)).set Arm64Program.___a64_loss_value (.Vlong word)) m) := by
  apply internalRun_of_steps
  all_goals simp [continuation,copy,InternalPath,InternalState,steps,CC.doStep,CC.doEvalExpr,
    CC.callCont,CC.setOpttemp,CC.PTree.gss,CC.E0,CC.Eapp]

end KProgFormal.ClightRefinement.Arm64MemcpyReadCall
