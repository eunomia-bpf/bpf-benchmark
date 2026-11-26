import KProgFormal.ClightRefinement.Arm64MemcpyTagSetup

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyByteGates

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  width : CC.Stmt
  last : CC.Stmt
  crossing : CC.Stmt
  byteLoop : CC.Stmt
  afterByte : CC.Stmt
  widthTest : CC.Expr
  widthYes : CC.Stmt
  widthNo : CC.Stmt
  lastValue : CC.Expr
  crossingTest : CC.Expr
  crossingYes : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy byte guards changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTagSetup.afterTag)) none)
    let math ← peel root[0]!
    let rest ← peel root[1]!
    let bytes ← peel rest[1]!
    let width ← Lean.Meta.withTransparency .all (Lean.Meta.whnf math[0]!)
    let last ← Lean.Meta.withTransparency .all (Lean.Meta.whnf math[1]!)
    let crossing ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest[0]!)
    unless width.isAppOfArity ``CC.Stmt.Sifthenelse 3 && last.isAppOfArity ``CC.Stmt.Sset 2 &&
        crossing.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original memcpy width/last/crossing changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_byte_guards
      (← Lean.Meta.mkAppM ``Parts.mk #[math[0]!,math[1]!,rest[0]!,bytes[0]!,bytes[1]!,
        width.getAppArgs[0]!,width.getAppArgs[1]!,width.getAppArgs[2]!,last.getAppArgs[1]!,
        crossing.getAppArgs[0]!,crossing.getAppArgs[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_byte_guard_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def width : CC.Stmt := by run_tac cachePart (← `(parts.width))
private def last : CC.Stmt := by run_tac cachePart (← `(parts.last))
private def crossing : CC.Stmt := by run_tac cachePart (← `(parts.crossing))
def byteLoop : CC.Stmt := by run_tac cachePart (← `(parts.byteLoop))
def afterByte : CC.Stmt := by run_tac cachePart (← `(parts.afterByte))
private def widthTest : CC.Expr := by run_tac cachePart (← `(parts.widthTest))
private def widthYes : CC.Stmt := by run_tac cachePart (← `(parts.widthYes))
private def widthNo : CC.Stmt := by run_tac cachePart (← `(parts.widthNo))
private def lastValue : CC.Expr := by run_tac cachePart (← `(parts.lastValue))
private def crossingTest : CC.Expr := by run_tac cachePart (← `(parts.crossingTest))
private def crossingYes : CC.Stmt := by run_tac cachePart (← `(parts.crossingYes))
private def afterMath : CC.Stmt := .Ssequence crossing (.Ssequence byteLoop afterByte)
theorem source : Arm64MemcpyTagSetup.afterTag = .Ssequence (.Ssequence width last) afterMath ∧
    width = .Sifthenelse widthTest widthYes widthNo ∧ last = .Sset Arm64Program.___a64_stw_last lastValue ∧
    crossing = .Sifthenelse crossingTest crossingYes .Sskip := ⟨rfl,rfl,rfl,rfl⟩

def temps (le : CC.TempEnv) (index : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'39 (.Vint 1)).set Arm64Program.___a64_stw_last (.Vlong index)

private theorem width_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1)) :
    CC.doEvalExpr world e le m widthTest = some (.Vint 1) := by
  simp only [widthTest,CC.doEvalExpr,hwidth,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tuchar,CC.tuint,CC.tint,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl
private theorem last_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (index : BitVec 64)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    CC.doEvalExpr world e (le.set Arm64Program._t'39 (.Vint 1)) m lastValue = some (.Vlong index) := by
  simp +decide [lastValue,CC.doEvalExpr,hindex,CC.PTree.gss,CC.PTree.gso,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semSub,CC.Cop.classifySub,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,
    CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int64.add,CC.Integers.MI.add,
    CC.Integers.Int64.sub,CC.Integers.MI.sub,BitVec.ofInt_natCast,BitVec.add_sub_cancel]

private theorem math_setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (index : BitVec 64)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    InternalRun world 7 (.State handler Arm64MemcpyTagSetup.afterTag k e le m)
      (.State handler afterMath k e (temps le index) m) := by
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step (mid := .State handler widthYes (.Kseq last (.Kseq afterMath k)) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,width_eval e le m hwidth]
    rfl
  refine .step (mid := .State handler .Sskip (.Kseq last (.Kseq afterMath k)) e
    (le.set Arm64Program._t'39 (.Vint 1)) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [widthYes,CC.doStep,CC.doEvalExpr,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.Integers.Int.repr,CC.Integers.MI.repr]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
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
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,CC.Archi.ptr64,CC.Integers.Int.repr,
    CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Integers.Int64.shru,CC.Integers.MI.shru,
    CC.Integers.Int.ltu,CC.Integers.MI.ltu,CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,
    CC.Integers.MI.eq,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Val.ofBool]

/-- Width1 gives actual last=index, so the genuine crossing test chooses
its original skip and enters the byte loop with the real saved continuation. -/
theorem to_byte (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (index : BitVec 64)
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong index)) :
    InternalRun world 11 (.State handler Arm64MemcpyTagSetup.afterTag k e le m)
      (.State handler byteLoop (.Kseq afterByte k) e (temps le index) m) := by
  have finish : InternalRun world 4 (.State handler afterMath k e (temps le index) m)
      (.State handler byteLoop (.Kseq afterByte k) e (temps le index) m) := by
    unfold afterMath
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    rw [source.2.2.2]
    refine .step (mid := .State handler .Sskip (.Kseq (.Ssequence byteLoop afterByte) k) e (temps le index) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [CC.doStep,crossing_eval e le m index hindex]
      rfl
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  exact (math_setup e le m k index hwidth hindex).trans finish

theorem kept (le : CC.TempEnv) (index : BitVec 64) (id : CC.Ident)
    (lastOther : Arm64Program.___a64_stw_last ≠ id) (widthOther : Arm64Program._t'39 ≠ id) :
    (temps le index).get id = le.get id := by
  simp only [temps,CC.PTree.gso _ _ _ _ lastOther,CC.PTree.gso _ _ _ _ widthOther]

end KProgFormal.ClightRefinement.Arm64MemcpyByteGates
