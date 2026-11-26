import KProgFormal.ClightRefinement.Arm64MemcpyByteWrite

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyByteLane

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  body : CC.Stmt
  choice : CC.Stmt
  labels : CC.LStmts
  selected : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memcpy byte-lane control changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyByteGates.byteLoop)) none) ``CC.Stmt.Sloop
    let lane ← peel loop[0]! ``CC.Stmt.Ssequence
    let value ← peel lane[1]! ``CC.Stmt.Ssequence
    let shift ← peel value[1]! ``CC.Stmt.Ssequence
    let tail ← peel shift[1]! ``CC.Stmt.Ssequence
    let choice ← peel tail[0]! ``CC.Stmt.Sswitch
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((0 : Int))) none),choice[1]!]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_byte_lane
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,tail[0]!,choice[1]!,
        (← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected))])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_lane_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def choice : CC.Stmt := by run_tac cachePart (← `(parts.choice))
private def labels : CC.LStmts := by run_tac cachePart (← `(parts.labels))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private theorem selected_source : CC.seqOfLabeledStatement (CC.selectSwitch 0 labels) = selected := rfl
private theorem loop_source : Arm64MemcpyByteGates.byteLoop = .Sloop body .Sbreak := rfl
private theorem choice_source : choice = .Sswitch (.Etempvar Arm64Program.___kprog_a64_bl_lane CC.tulong) labels := rfl
private def beforeTemps (le : CC.TempEnv) (value : BitVec 8) : CC.TempEnv :=
  ((le.set Arm64Program.___kprog_a64_bl_lane (.Vlong 0)).set
    Arm64Program.___kprog_a64_bl_value (.Vlong (value.setWidth 64))).set Arm64Program.___kprog_a64_bl_shift (.Vlong 0)
def temps (le : CC.TempEnv) (value : BitVec 8) : CC.TempEnv :=
  (beforeTemps le value).set Arm64Program.___kprog_a64_bl_shift (.Vlong 0)
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

private theorem setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 8)
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64))) :
    InternalRun world 11 (.State handler Arm64MemcpyByteGates.byteLoop k e le m)
      (.State handler choice (.Kseq Arm64MemcpyByteWrite.statement (continuation k)) e (beforeTemps le value) m) := by
  apply internalRun_of_steps
  all_goals simp +decide [loop_source,body,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,
    beforeTemps,continuation,CC.PTree.gss,CC.PTree.gso,hvalue,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntLong,CC.typeof,CC.tint,CC.tulong,CC.Integers.Int.signed,CC.Integers.MI.signed,
    CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.E0,CC.Eapp,List.nil_append]
  constructor <;> rfl

/-- Original lane0 initialization and real selectSwitch0 keep all labels,
both shift assignments and genuine switch/break continuations. -/
theorem to_store (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 8)
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64))) :
    InternalRun world 19 (.State handler Arm64MemcpyByteGates.byteLoop k e le m)
      (.State handler Arm64MemcpyByteWrite.statement (continuation k) e (temps le value) m) := by
  let cont := CC.Cont.Kseq Arm64MemcpyByteWrite.statement (continuation k)
  have lane : (beforeTemps le value).get Arm64Program.___kprog_a64_bl_lane = some (.Vlong 0) := by
    have shiftOther : Arm64Program.___kprog_a64_bl_shift ≠ Arm64Program.___kprog_a64_bl_lane := by decide +kernel
    have valueOther : Arm64Program.___kprog_a64_bl_value ≠ Arm64Program.___kprog_a64_bl_lane := by decide +kernel
    simp only [beforeTemps,CC.PTree.gso _ _ _ _ shiftOther,CC.PTree.gso _ _ _ _ valueOther,CC.PTree.gss]
  have select : InternalRun world 1 (.State handler choice cont e (beforeTemps le value) m)
      (.State handler selected (.Kswitch cont) e (beforeTemps le value) m) := by
    refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
    simp only [choice_source,CC.doStep,CC.doEvalExpr,lane,CC.Cop.semSwitchArg,CC.Cop.classifySwitch,
      CC.typeof,CC.tulong,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,selected_source]
    rfl
  have finish : InternalRun world 7 (.State handler selected (.Kswitch cont) e (beforeTemps le value) m)
      (.State handler Arm64MemcpyByteWrite.statement (continuation k) e (temps le value) m) := by
    apply internalRun_of_steps
    all_goals simp +decide [selected,steps,InternalPath,InternalState,CC.doStep,CC.doEvalExpr,
      temps,cont,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeof,CC.tint,CC.tulong,
      CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int.repr,CC.Integers.Int64.repr,
      CC.Integers.MI.repr,CC.E0,CC.Eapp,List.nil_append]
  exact ((setup e le m k value hvalue).trans select).trans finish

/-- Complete the actual first byte loop through its real volatile store
and two genuine exit transitions, retaining the exact memory effect. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64)))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (range : CC.Mem.rangePerm m stack 0 160 .Cur .Writable = true) :
    ∃ after, CC.Star (CC.Step2 world) (.State handler Arm64MemcpyByteGates.byteLoop k e le m) CC.E0
      (.State handler .Sskip k e (Arm64MemcpyByteWrite.temps (temps le value) stack) after) ∧
      CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint (value.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after stack (i.val : Int) = some (.Vint (value.setWidth 32)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have entered := to_store e le m k value hvalue
  have valueRead : (temps le value).get Arm64Program.___kprog_a64_bl_value = some (.Vlong (value.setWidth 64)) := by
    have other : Arm64Program.___kprog_a64_bl_shift ≠ Arm64Program.___kprog_a64_bl_value := by decide +kernel
    simp only [temps,beforeTemps,CC.PTree.gso _ _ _ _ other,CC.PTree.gss]
  obtain ⟨after,write,stored,read,access,next⟩ := Arm64MemcpyByteWrite.write e (temps le value) m
    (continuation k) entry stack i value
    (by simpa +decide only [temps,beforeTemps,CC.PTree.gso] using hentry)
    (by simpa +decide only [temps,beforeTemps,CC.PTree.gso] using hindex)
    valueRead (by simp only [temps,CC.PTree.gss]) pointer range
  have leave : InternalRun world 2
      (.State handler .Sskip (continuation k) e (Arm64MemcpyByteWrite.temps (temps le value) stack) after)
      (.State handler .Sskip k e (Arm64MemcpyByteWrite.temps (temps le value) stack) after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  refine ⟨after,?_,stored,read,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans entered.sound (star_trans write leave.sound)

end KProgFormal.ClightRefinement.Arm64MemcpyByteLane
