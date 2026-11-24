import KProgFormal.ClightRefinement.X86RegisterWriteRspPartial
import KProgFormal.ClightRefinement.X86WordStorage

namespace KProgFormal.ClightRefinement.X86RegisterWriteRspScalarSuffix

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_rsp_partial_suffix
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Parts where
  body : CC.Stmt
  lane : CC.Stmt
  choice : CC.Stmt
  tag : CC.Stmt
  scalar : CC.Stmt

private def extract (source : CC.Stmt) : Parts :=
  match source with
  | .Sloop (.Ssequence lane (.Ssequence choice tag)) .Sbreak =>
      match choice with
      | .Sifthenelse _ scalar _ => ⟨.Ssequence lane (.Ssequence choice tag), lane, choice, tag, scalar⟩
      | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def wordParts : Parts := by
  run_tac cachePart (← `(extract X86RegisterWriteRspWord.afterMaterialize))
private def byteParts : Parts := by
  run_tac cachePart (← `(extract X86RegisterWriteRspByte.afterMaterialize))
private def parts (isWord : Bool) : Parts := if isWord then wordParts else byteParts
private def body (isWord : Bool) : CC.Stmt := (parts isWord).body
private def lane (isWord : Bool) : CC.Stmt := (parts isWord).lane
private def choice (isWord : Bool) : CC.Stmt := (parts isWord).choice
private def tag (isWord : Bool) : CC.Stmt := (parts isWord).tag

def scalar (isWord : Bool) : CC.Stmt := (parts isWord).scalar

def continuation (isWord : Bool) (k : CC.Cont) : CC.Cont :=
  .Kseq (tag isWord) (.Kloop1 (body isWord) .Sbreak k)

def laneTemps (isWord : Bool) (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  if isWord then X86WordStorage.laneTemps le value else X86ShiftWriteback.byteLaneTemps le value

def temps (isWord : Bool) (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  if isWord then X86WordStorage.temps le value else X86ShiftWriteback.byteTemps le value

def chunk (isWord : Bool) : CC.Chunk := if isWord then .Mint16unsigned else .Mint8unsigned

def value (isWord : Bool) (next : BitVec 64) : BitVec 32 :=
  if isWord then X86WordMemory.lane next else X86ShiftWriteback.byteValue next

/-- Both suffixes are the original loops following the real RSP add-base
store; the scalar alternatives come from those SAME source branches. -/
theorem source (isWord : Bool) : X86RegisterWriteRspPartial.suffix isWord =
    .Sloop (.Ssequence (lane isWord) (.Ssequence (choice isWord) (tag isWord))) .Sbreak := by
  cases isWord <;> rfl

private theorem word_lane (next : BitVec 64) :
    next.setWidth 32 &&& (65535#32) = (next.setWidth 16).setWidth 32 := by
  have mask : (65535#32) = (BitVec.allOnes 16).setWidth 32 := by decide
  rw [mask, BitVec.and_setWidth_allOnes 16 16 (next.setWidth 32)]
  simpa using (BitVec.setWidth_eq_append (x := next.setWidth 16) (w := 32) (by decide)).symm

/-- The actual post-materialization loop computes its byte/word lane and
selects the scalar branch in six transitions, retaining the whole heap. -/
theorem enter (isWord : Bool) (ge : CC.CGenv) (function : CC.Function)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (next : BitVec 64)
    (scalarTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next)) :
    InternalRun ge 6 (.State function (X86RegisterWriteRspPartial.suffix isWord) k e le memory)
      (.State function (scalar isWord) (continuation isWord k) e (laneTemps isWord le next) memory) := by
  rw [source]
  cases isWord <;> apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, body, lane, choice, tag,
    parts, wordParts, byteParts, scalar, continuation, laneTemps,
    X86WordStorage.laneTemps, X86ShiftWriteback.byteLaneTemps,
    X86WordMemory.lane, X86ShiftWriteback.byteValue,
    CC.doEvalExpr, CC.typeof, scalarTag, observed, CC.PTree.gss, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tushort, CC.tuint, CC.tint, CC.tulong,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
    CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, word_lane, CC.Eapp, CC.E0]

/-- Actual scalar byte/word stores, tag reset and both loop exits compose
from the true suffix. The RSP byte lane is low0; no alternate writer is used. -/
theorem run (isWord : Bool) (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory after : CC.Mem) (block : CC.Block) (next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (scalarTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (observed : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (low : isWord = false → le.get X86_program_profile_bpf.___x86_wr_shift__2 = some (.Vint (0#32)))
    (stored : CC.Mem.store (chunk isWord) memory block 0 (.Vint (value isWord next)) = some after) :
    InternalRun ge (if isWord then 11 else 12)
      (.State function (X86RegisterWriteRspPartial.suffix isWord) k e le memory)
      (.State function .Sskip k e (temps isWord le next) after) := by
  have entered := enter isWord ge function e le k memory next scalarTag observed
  cases isWord with
  | false =>
    have keptShift : (X86ShiftWriteback.byteLaneTemps le next).get X86_program_profile_bpf.___x86_wr_shift__2 =
        some (.Vint ((0#8).setWidth 32)) := by
      simp +decide [X86ShiftWriteback.byteLaneTemps, CC.PTree.gso, low rfl]
    have laneValue : (X86ShiftWriteback.byteLaneTemps le next).get X86_program_profile_bpf.___kprog_x86_lane__4 =
        some (.Vint (X86ShiftWriteback.byteValue next)) := by simp [X86ShiftWriteback.byteLaneTemps]
    have written := X86ShiftWriteback.byte_store ge gprLayout function e
      (X86ShiftWriteback.byteLaneTemps le next) (continuation false k) memory after block (0#8) next
      declared keptShift laneValue stored
    exact (entered.trans written).trans
      (X86ShiftWriteback.byte_exit ge function e (X86ShiftWriteback.byteLaneTemps le next) k after)
  | true =>
    have laneValue : (X86WordStorage.laneTemps le next).get X86_program_profile_bpf.___kprog_x86_lane__5 =
        some (.Vint (X86WordMemory.lane next)) := by simp [X86WordStorage.laneTemps]
    have written := X86WordStorage.store ge gprLayout function e
      (X86WordStorage.laneTemps le next) (continuation true k) memory after block next declared laneValue stored
    exact (entered.trans written).trans
      (X86WordStorage.exit ge function e (X86WordStorage.laneTemps le next) k after)

end KProgFormal.ClightRefinement.X86RegisterWriteRspScalarSuffix
