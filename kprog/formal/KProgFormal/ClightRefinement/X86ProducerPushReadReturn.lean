import KProgFormal.ClightRefinement.X86ProducerPushRead

namespace KProgFormal.ClightRefinement.X86ProducerPushReadReturn
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

def save : CC.Stmt := .Sset X86_program_profile_bpf.___x86_l_pp_value
  (.Etempvar X86_program_profile_bpf._t'10 CC.tulong)

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original reader return parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerPushOperand.certificate arguments
    let continuation ← Lean.Meta.mkAppM ``X86ProducerPushOperand.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original reader return assignment missing"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_reader_following node.getAppArgs[1]!

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    (X86ProducerPushOperand.certificate binding k memory).continuation = .Kseq save (following binding k memory) := rfl

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) : CC.TempEnv :=
  ((X86ProducerPushOperand.certificate binding k memory).output.set X86_program_profile_bpf._t'10 (.Vlong value)).set
    X86_program_profile_bpf.___x86_l_pp_value (.Vlong value)

/-- The original nested reader return really resumes its caller and saves
RBX into the actual PUSH operand temporary, preserving complete memory. -/
theorem resume (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    InternalRun ge 3
      (.Returnstate (.Vlong value) (CC.callCont (X86ProducerPushRead.continuation binding k memory)) (allocation memory).2)
      (.State handler .Sskip (following binding k memory) (allocation memory).1
        (temps binding k memory value) (allocation memory).2) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, X86ProducerPushRead.continuation,
      CC.callCont, source, save, temps, CC.setOpttemp, CC.doEvalExpr, CC.PTree.gss,
      CC.Eapp, CC.E0, List.nil_append, true_and]

theorem saved (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    (temps binding k memory value).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong value) := by
  exact CC.PTree.gss _ _ _

theorem from_body {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) :
    InternalRun ge ((X86ProducerPushOperand.certificate ready.entry.block k ready.after).count + 1 +
        X86RegisterReadScalar.length .q + 3)
      (X86ProducerPushOperand.start ready.entry.block k ready.after)
      (.State handler .Sskip (following ready.entry.block k ready.after) (allocation ready.after).1
        (temps ready.entry.block k ready.after (ready.values 3)) (allocation ready.after).2) :=
  (X86ProducerPushRead.from_body ready k).trans (resume ready.entry.block k ready.after (ready.values 3))

end KProgFormal.ClightRefinement.X86ProducerPushReadReturn
