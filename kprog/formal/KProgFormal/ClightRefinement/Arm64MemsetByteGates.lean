import KProgFormal.ClightRefinement.Arm64MemsetTagSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetByteGates

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  afterTag : CC.Stmt
  width : CC.Stmt
  last : CC.Stmt
  crossing : CC.Stmt
  afterByte : CC.Stmt
  crossingTest : CC.Expr
  crossingYes : CC.Stmt
  widthTest : CC.Expr
  widthYes : CC.Stmt
  widthNo : CC.Stmt
  lastValue : CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original memset width-one gates changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_77)) none)
    let rest ← peel root[1]!
    let width ← peel rest[0]!
    let cross ← peel rest[1]!
    let bytes ← peel cross[1]!
    let crossing ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cross[0]!)
    unless crossing.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
      throwError "original memset crossing condition changed"
    let guard := crossing.getAppArgs
    let select ← Lean.Meta.withTransparency .all (Lean.Meta.whnf width[0]!)
    let last ← Lean.Meta.withTransparency .all (Lean.Meta.whnf width[1]!)
    unless select.isAppOfArity ``CC.Stmt.Sifthenelse 3 && last.isAppOfArity ``CC.Stmt.Sset 2 do
      throwError "original width selection and last assignment changed"
    let selection := select.getAppArgs
    Lean.Elab.Tactic.closeMainGoal `actual_memset_byte_gates
      (← Lean.Meta.mkAppM ``Parts.mk #[root[1]!,width[0]!,width[1]!,cross[0]!,bytes[1]!,guard[0]!,guard[1]!,selection[0]!,selection[1]!,selection[2]!,last.getAppArgs[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_gate_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def afterTag : CC.Stmt := by run_tac cachePart (← `(parts.afterTag))
private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def last : CC.Stmt := by run_tac cachePart (← `(parts.last))
private def crossing : CC.Stmt := by run_tac cachePart (← `(parts.crossing))
def afterByte : CC.Stmt := by run_tac cachePart (← `(parts.afterByte))
private def crossingTest : CC.Expr := by run_tac cachePart (← `(parts.crossingTest))
private def crossingYes : CC.Stmt := by run_tac cachePart (← `(parts.crossingYes))
private def widthTest : CC.Expr := by run_tac cachePart (← `(parts.widthTest))
private def widthYes : CC.Stmt := by run_tac cachePart (← `(parts.widthYes))
private def widthNo : CC.Stmt := by run_tac cachePart (← `(parts.widthNo))
private def lastValue : CC.Expr := by run_tac cachePart (← `(parts.lastValue))
private theorem width_source : width = .Sifthenelse widthTest widthYes widthNo := rfl
private theorem last_source : last = .Sset Arm64Program.___a64_stw_last lastValue := rfl

private def afterMath : CC.Stmt := .Ssequence crossing (.Ssequence Arm64MemsetByteWrite.byteLoop afterByte)
private theorem crossing_source : crossing = .Sifthenelse crossingTest crossingYes .Sskip := rfl

theorem source : Arm64Program.s_kprog_arm64_program_memset_77 =
    .Ssequence Arm64MemsetTagWrite.loop afterTag := rfl
private theorem gates_source : afterTag =
    .Ssequence (.Ssequence width last) (.Ssequence crossing (.Ssequence Arm64MemsetByteWrite.byteLoop afterByte)) := rfl

def temps (le : CC.TempEnv) (index : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'36 (.Vint 1)).set Arm64Program.___a64_stw_last (.Vlong index)

private theorem width_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    CC.doEvalExpr world e le m widthTest = some (.Vint 1) := by
  simp only [widthTest,CC.doEvalExpr,hwidth,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tuchar,CC.tuint,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl

private theorem last_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (index : BitVec 64)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    CC.doEvalExpr world e (le.set Arm64Program._t'36 (.Vint 1)) m lastValue = some (.Vlong index) := by
  simp +decide [lastValue,CC.doEvalExpr,hindex,CC.PTree.gss,CC.PTree.gso,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semSub,CC.Cop.classifySub,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tulong,CC.tuint,CC.Archi.ptr64,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int64.add,CC.Integers.MI.add,CC.Integers.Int64.sub,CC.Integers.MI.sub,
    BitVec.ofInt_natCast,BitVec.add_sub_cancel]

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (index : BitVec 64)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    InternalRun world 7 (.State handler afterTag k e le m)
      (.State handler afterMath k e (temps le index) m) := by
  rw [gates_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [width_source]
  refine .step (mid := .State handler widthYes
    (.Kseq last (.Kseq afterMath k)) e le m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,width_eval e le m hwidth]
    rfl
  refine .step (mid := .State handler .Sskip
    (.Kseq last (.Kseq afterMath k)) e (le.set Arm64Program._t'36 (.Vint 1)) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [widthYes,CC.doStep,CC.doEvalExpr,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,
      CC.Integers.Int.repr,CC.Integers.MI.repr]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [last_source]
  refine .step (mid := .State handler .Sskip (.Kseq afterMath k) e (temps le index) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,last_eval e le m index hindex]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)


private theorem crossing_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (index : BitVec 64)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    CC.doEvalExpr world e (temps le index) m crossingTest = some (.Vint 0) := by
  simp +decide [crossingTest,temps,CC.doEvalExpr,hindex,CC.PTree.gss,CC.PTree.gso,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semShr,
      CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
      CC.tulong,CC.tuint,CC.tint,CC.Archi.ptr64,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.shru,CC.Integers.MI.shru,CC.Integers.Int.ltu,CC.Integers.MI.ltu,
      CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.eq,
      CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Val.ofBool]

/-- The original width1 selection and false crossing guard reach the genuine
byte loop in eleven transitions, retaining the complete source continuation. -/
theorem to_byte (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (index : BitVec 64)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    InternalRun world 11 (.State handler afterTag k e le m)
      (.State handler Arm64MemsetByteWrite.byteLoop (.Kseq afterByte k) e (temps le index) m) := by
  have finish : InternalRun world 4 (.State handler afterMath k e (temps le index) m)
      (.State handler Arm64MemsetByteWrite.byteLoop (.Kseq afterByte k) e (temps le index) m) := by
    unfold afterMath
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [crossing_source]
    refine .step (mid := .State handler .Sskip
      (.Kseq (.Ssequence Arm64MemsetByteWrite.byteLoop afterByte) k) e (temps le index) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [CC.doStep,crossing_eval e le m index hindex]
      rfl
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  exact (math_setup e le m k index hwidth hindex).trans finish

end KProgFormal.ClightRefinement.Arm64MemsetByteGates
