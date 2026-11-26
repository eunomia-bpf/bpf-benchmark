import KProgFormal.ClightRefinement.Arm64MemcpyTransferDestinationSP

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyGates

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)
open Arm64MemcpyTransferLoop (active position)

private structure Parts where
  alignmentSet : CC.Stmt
  alignmentValue : CC.Expr
  lengthSet : CC.Stmt
  lengthValue : CC.Expr
  copyBody : CC.Stmt
private def parts : Parts := by
  run_tac do
    let arm (term : Lean.Expr) : Lean.Elab.Tactic.TacticM Lean.Expr := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
        throwError "original memcpy copy selector changed"
      pure actual.getAppArgs[1]!
    let value (term : Lean.Expr) : Lean.Elab.Tactic.TacticM Lean.Expr := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Sset 2 do
        throwError "original memcpy copy guard setter changed"
      pure actual.getAppArgs[1]!
    let alignment ← arm (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyTag.alignmentGuard)) none)
    let length ← arm (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyTag.lengthGuard)) none)
    let copy ← arm (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferCopyTag.copyGuard)) none)
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_gates
      (← Lean.Meta.mkAppM ``Parts.mk #[alignment,← value alignment,length,← value length,copy])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_copy_gate_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def alignmentSet : CC.Stmt := by run_tac cachePart (← `(parts.alignmentSet))
private def alignmentValue : CC.Expr := by run_tac cachePart (← `(parts.alignmentValue))
private def lengthSet : CC.Stmt := by run_tac cachePart (← `(parts.lengthSet))
private def lengthValue : CC.Expr := by run_tac cachePart (← `(parts.lengthValue))
def copyBody : CC.Stmt := by run_tac cachePart (← `(parts.copyBody))
private theorem alignment_source : Arm64MemcpyTransferCopyTag.alignmentGuard =
    .Sifthenelse (.Etempvar Arm64Program._t'81 CC.tint) alignmentSet
      (.Sset Arm64Program._t'83 (.Econst_int (CC.Integers.Int.repr 0) CC.tint)) ∧
    alignmentSet = .Sset Arm64Program._t'83 alignmentValue := ⟨rfl,rfl⟩
private theorem length_source : Arm64MemcpyTransferCopyTag.lengthGuard =
    .Sifthenelse (.Etempvar Arm64Program._t'83 CC.tint) lengthSet
      (.Sset Arm64Program._t'84 (.Econst_int (CC.Integers.Int.repr 0) CC.tint)) ∧
    lengthSet = .Sset Arm64Program._t'84 lengthValue := ⟨rfl,rfl⟩
private theorem copy_source : Arm64MemcpyTransferCopyTag.copyGuard =
    .Sifthenelse (.Etempvar Arm64Program._t'84 CC.tint) copyBody .Sskip := rfl

private def alignedTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'83 (.Vint 1)
def temps (le : CC.TempEnv) : CC.TempEnv := (alignedTemps le).set Arm64Program._t'84 (.Vint 1)
def continuation (k : CC.Cont) : CC.Cont := .Kseq Arm64MemcpyTransferCopyTag.tagStore k

private theorem aligned_data : ∀ i : Fin 16, active i = true →
    (position i &&& (7#64) == (0#64)) = true := by decide +kernel
private theorem length_data : ∀ i : Fin 16, active i = true →
    CC.Integers.MI.ltu ((16#64)-BitVec.ofNat 64 i.val) (8#64) = false := by decide +kernel
private theorem alignment_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (chosen : active i = true)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    CC.doEvalExpr world e le m alignmentValue = some (.Vint 1) := by
  simp only [alignmentValue,CC.doEvalExpr,hat,CC.Cop.semUnaryOperation,CC.Cop.semNotbool,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tulong,CC.tuint,CC.tint,CC.tbool,ite_true,ite_false,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.eq,CC.Integers.MI.eq,
    CC.Integers.Int64.zero,CC.Integers.MI.zero,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
  simp +decide [CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,aligned_data i chosen,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero]
private theorem length_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (chosen : active i = true)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16)) :
    CC.doEvalExpr world e (alignedTemps le) m lengthValue = some (.Vint 1) := by
  have counter : (alignedTemps le).get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [alignedTemps,CC.PTree.gso] using hi
  have len : (alignedTemps le).get Arm64Program.___a64_mt_len = some (.Vlong 16) := by
    simpa +decide only [alignedTemps,CC.PTree.gso] using hlen
  have checked := length_data i chosen
  simp +decide [lengthValue,CC.doEvalExpr,counter,len,CC.Cop.semBinaryOperation,
    CC.Cop.semSub,CC.Cop.classifySub,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,CC.tint,CC.tbool,
    CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int64.sub,CC.Integers.MI.sub,
    CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,checked,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse]
  all_goals rfl
private theorem alignment_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (chosen : active i = true) (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    CC.doStep world (.State handler alignmentSet k e le m) =
      some (CC.E0,.State handler .Sskip k e (alignedTemps le) m) := by
  rw [alignment_source.2]
  simp only [CC.doStep,alignment_eval e le m i chosen hat,alignedTemps]
private theorem length_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (chosen : active i = true)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16)) :
    CC.doStep world (.State handler lengthSet k e (alignedTemps le) m) =
      some (CC.E0,.State handler .Sskip k e (temps le) m) := by
  rw [length_source.2]
  simp only [CC.doStep,length_eval e le m i chosen hi hlen,temps]

/-- The actual destination-SP successor executes both original guarded
setters and the real copy selector at the two active transfer indices. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (chosen : active i = true) (destinationOK : le.get Arm64Program._t'81 = some (.Vint 1))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    InternalRun world 8
      (.State handler .Sskip (Arm64MemcpyTransferDestinationSP.continuation k) e le m)
      (.State handler copyBody (continuation k) e (temps le) m) := by
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [alignment_source.1]
  refine .step (mid := .State handler alignmentSet
    (.Kseq Arm64MemcpyTransferCopyTag.lengthGuard
      (.Kseq Arm64MemcpyTransferCopyTag.copyGuard (continuation k))) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,destinationOK]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ (alignment_step e le m _ i chosen hat)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [length_source.1]
  refine .step (mid := .State handler lengthSet
    (.Kseq Arm64MemcpyTransferCopyTag.copyGuard (continuation k)) e (alignedTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr,alignedTemps,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ (length_step e le m _ i chosen hi hlen)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [copy_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
  rfl

private def changed : List CC.Ident := [Arm64Program._t'84,Arm64Program._t'83]
theorem kept (le : CC.TempEnv) (id : CC.Ident) (other : id ∉ changed) :
    (temps le).get id = le.get id := by
  have different (name : CC.Ident) (member : name ∈ changed) : name ≠ id := by
    intro same
    exact other (same ▸ member)
  simp only [temps,alignedTemps,
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'84 (by decide +kernel)),
    CC.PTree.gso _ _ _ _ (different Arm64Program._t'83 (by decide +kernel))]

theorem observations (le : CC.TempEnv) :
    (temps le).get Arm64Program._t'84 = some (.Vint 1) ∧
    (temps le).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le).get Arm64Program.___a64_mt_at = le.get Arm64Program.___a64_mt_at :=
  ⟨CC.PTree.gss _ _ _,kept le _ (by decide +kernel),kept le _ (by decide +kernel),
    kept le _ (by decide +kernel),kept le _ (by decide +kernel)⟩

/-- The same complete packet and caller locals reach the actual copy arm
with the actual destination-SP, alignment and length results. -/
theorem current {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le)
    (chosen : active i = true) (destinationOK : le.get Arm64Program._t'81 = some (.Vint 1))
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m (temps le),
      InternalRun world 8
        (.State handler .Sskip (Arm64MemcpyTransferDestinationSP.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le m)
        (.State handler copyBody (continuation k) (Arm64MemcpySource.allocation calleeBefore).1 (temps le) m) := by
  refine ⟨⟨prior.packet,prior.callee,?_,?_,?_,?_,prior.copied⟩,
    execute _ le m k i chosen destinationOK hi hlen hat⟩
  · exact (kept le Arm64Program._entry (by decide +kernel)).trans prior.entryRead
  · exact (kept le Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length
  · exact (kept le Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter
  · exact (kept le Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag

end KProgFormal.ClightRefinement.Arm64MemcpyTransferCopyGates
