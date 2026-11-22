import KProgFormal.ClightRefinement.Arm64SelectCondition
import KProgFormal.ClightRefinement.Arm64SelectPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.PathCall
open Arm64ProgramEntryLinked (ge)

private def callStmt : CC.Stmt :=
  .Scall (some Arm64Program._t'162)
    (.Evar Arm64Program._kprog_arm64_csel_path
      (.Tfunction [CC.tulong,CC.tulong] CC.tulong CC.cc_default))
    [.Etempvar Arm64Program._op CC.tuint,.Etempvar Arm64Program.___a64_l_width CC.tuchar]
private def choose : CC.Stmt :=
  .Sifthenelse (.Etempvar Arm64Program._t'162 CC.tulong)
    Arm64Program.s_kprog_arm64_program_execute_128 Arm64Program.s_kprog_arm64_program_execute_129

/-- The real successor of the condition site calls the linked path helper. -/
theorem source : Condition.after = .Ssequence callStmt choose := rfl

def selected (op : BitVec 32) (width : BitVec 8) : CC.Stmt :=
  if (op.setWidth 64 == 28#64) && (width.setWidth 64 == 8#64) then
    Arm64Program.s_kprog_arm64_program_execute_128 else Arm64Program.s_kprog_arm64_program_execute_129

def temps (le : CC.TempEnv) (op : BitVec 32) (width : BitVec 8) : CC.TempEnv :=
  le.set Arm64Program._t'162 (Path.result (op.setWidth 64) (width.setWidth 64))
private def callCont (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'162) Arm64Nop.handler e le (.Kseq choose k)

private theorem binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_csel_path = some (CC.Positive.ofNat 99) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 99) = some (.Internal Arm64Numeric.f_kprog_arm64_csel_path) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem cast_op (m : CC.Mem) (op : BitVec 32) :
    CC.Cop.semCast (.Vint op) CC.tuint CC.tulong m = some (.Vlong (op.setWidth 64)) := by
  simp [CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.tuint,CC.tulong,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int64.repr,CC.Integers.MI.repr]
private theorem cast_width (m : CC.Mem) (width : BitVec 8) :
    CC.Cop.semCast (.Vint (width.setWidth 32)) CC.tuchar CC.tulong m = some (.Vlong (width.setWidth 64)) := by
  have cast := cast_op m (width.setWidth 32)
  change CC.Cop.semCast (.Vint (width.setWidth 32)) CC.tuint CC.tulong m = _
  simpa using cast

private theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (op : BitVec 32) (width : BitVec 8)
    (unshadowed : e.get Arm64Program._kprog_arm64_csel_path = none)
    (opRead : le.get Arm64Program._op = some (.Vint op))
    (widthRead : le.get Arm64Program.___a64_l_width = some (.Vint (width.setWidth 32))) :
    InternalRun ge 2 (.State Arm64Nop.handler Condition.after k e le m)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
        [.Vlong (op.setWidth 64),.Vlong (width.setWidth 64)] (callCont e le k) m) := by
  have execution : steps ge 2 (.State Arm64Nop.handler Condition.after k e le m) =
      some (CC.E0,.Callstate (.Internal Arm64Numeric.f_kprog_arm64_csel_path)
        [.Vlong (op.setWidth 64),.Vlong (width.setWidth 64)] (callCont e le k) m) ∧
      InternalPath ge 2 (.State Arm64Nop.handler Condition.after k e le m) := by
    simp +decide [steps,InternalPath,InternalState,CC.doStep,source,callStmt,callCont,
      opRead,widthRead,unshadowed,binding.1,binding.2,cast_op,cast_width,
      CC.doEvalExpr,CC.doEvalExprlist,CC.doEvalLvalue,CC.doDerefLoc,CC.lvalOfVar,CC.typeof,
      CC.Cop.classifyFun,CC.typeconv,CC.accessMode,CC.tptr,CC.Archi.ptr64,
      CC.Genv.findFunct,CC.typeOfFundef,CC.typeOfFunction,CC.typeOfParams,
      Arm64Numeric.f_kprog_arm64_csel_path,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero,CC.E0,CC.Eapp]
  exact internalRun_of_steps execution.2 execution.1

private theorem resume (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (op : BitVec 32) (width : BitVec 8) :
    InternalRun ge 3 (.Returnstate (Path.result (op.setWidth 64) (width.setWidth 64)) (callCont e le k) m)
      (.State Arm64Nop.handler (selected op width) k e (temps le op width) m) := by
  cases h : (op.setWidth 64 == 28#64) && (width.setWidth 64 == 8#64)
  all_goals
    apply internalRun_of_steps
    · simp [InternalPath,InternalState,CC.doStep,callCont,choose,temps,Path.result,h,
        CC.setOpttemp,CC.doEvalExpr,CC.PTree.gss,CC.typeof,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tulong,CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.zero,CC.Integers.MI.zero]
    · simp [steps,CC.doStep,callCont,choose,temps,selected,Path.result,h,CC.setOpttemp,
        CC.doEvalExpr,CC.PTree.gss,CC.typeof,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
        CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.zero,CC.Integers.MI.zero,CC.E0,CC.Eapp]

/-- Genuine uint/byte argument conversions, linked helper26 and caller
return/branch selection3. The original pointer or numeric suffix is untouched. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (op : BitVec 32) (width : BitVec 8)
    (supported : op=28#32 ∨ op=29#32 ∨ op=30#32 ∨ op=52#32 ∨
      op=61#32 ∨ op=62#32 ∨ op=68#32 ∨ op=69#32)
    (unshadowed : e.get Arm64Program._kprog_arm64_csel_path = none)
    (opRead : le.get Arm64Program._op = some (.Vint op))
    (widthRead : le.get Arm64Program.___a64_l_width = some (.Vint (width.setWidth 32))) :
    InternalRun ge 31 (.State Arm64Nop.handler Condition.after k e le m)
      (.State Arm64Nop.handler (selected op width) k e (temps le op width) m) := by
  have codes : op.setWidth 64=28#64 ∨ op.setWidth 64=29#64 ∨ op.setWidth 64=30#64 ∨
      op.setWidth 64=52#64 ∨ op.setWidth 64=61#64 ∨ op.setWidth 64=62#64 ∨
      op.setWidth 64=68#64 ∨ op.setWidth 64=69#64 := by
    rcases supported with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl <;> decide +kernel
  have first := enter e le m k op width unshadowed opRead widthRead
  have called := Path.internal ge m (callCont e le k) (op.setWidth 64) (width.setWidth 64) codes
  have last := resume e le m k op width
  simpa only [CC.callCont,callCont] using (first.trans called).trans last

/-- The path call changes only its actual result temporary. -/
theorem temps_other (le : CC.TempEnv) (op : BitVec 32) (width : BitVec 8)
    (id : CC.Ident) (outside : id ≠ Arm64Program._t'162) :
    (temps le op width).get id = le.get id := by
  exact CC.PTree.gso _ _ _ _ (Ne.symm outside)

/-- Compose the earlier real NZCV loads/EQ call/normalization with the actual
path call. Opcode and width observations are preserved through that prefix. -/
theorem execute_condition {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block (0#64)) s)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (op : BitVec 32) (width : BitVec 8)
    (supported : op=28#32 ∨ op=29#32 ∨ op=30#32 ∨ op=52#32 ∨
      op=61#32 ∨ op=62#32 ∨ op=68#32 ∨ op=69#32)
    (conditionUnshadowed : e.get Arm64Program._kprog_arm64_program_condition = none)
    (pathUnshadowed : e.get Arm64Program._kprog_arm64_csel_path = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block (0#64)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (opRead : le.get Arm64Program._op = some (.Vint op))
    (widthRead : le.get Arm64Program.___a64_l_width = some (.Vint (width.setWidth 32))) :
    InternalRun ge 66 (.State Arm64Nop.handler Condition.branch k e le m)
      (.State Arm64Nop.handler (selected op width) k e
        (temps (Condition.temps le (fun i => (storage.flags i).block) (read_flag .Z s.machine)) op width) m) := by
  have opKept := Condition.temps_other le (fun i => (storage.flags i).block)
    (read_flag .Z s.machine) Arm64Program._op (by decide +kernel)
  have widthKept := Condition.temps_other le (fun i => (storage.flags i).block)
    (read_flag .Z s.machine) Arm64Program.___a64_l_width (by decide +kernel)
  have first := Condition.execute storage s represented e le k conditionUnshadowed entryRead aux
  have second := execute e (Condition.temps le (fun i => (storage.flags i).block)
    (read_flag .Z s.machine)) m k op width supported pathUnshadowed
    (by simpa only [opKept] using opRead) (by simpa only [widthKept] using widthRead)
  exact first.trans second

/-- The fixture's plain 64-bit CSEL reaches the original pointer/tag branch. -/
theorem csel64_source : selected (28#32) (8#8) = Arm64Program.s_kprog_arm64_program_execute_128 := rfl

end KProgFormal.ClightRefinement.Arm64Select.PathCall
