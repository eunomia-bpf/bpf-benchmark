import KProgFormal.ClightRefinement.X86ProducerPushReadReturn

namespace KProgFormal.ClightRefinement.X86ProducerPushRspSource
open X86ProducerPushBody (handler allocation)
open X86ProducerLayout (ge)

def update : CC.Stmt := X86_program_profile_bpf.s_x86_sim_inline_arm_DISP_PUSH_3
def stackLoop : CC.Stmt := .Sloop X86_program_profile_bpf.s_x86_sim_inline_arm_DISP_PUSH_27
  X86_program_profile_bpf.s_x86_sim_inline_arm_DISP_PUSH_28

private structure Parts where
  first : CC.Stmt
  second : CC.Stmt
  third : CC.Stmt
  store : CC.Stmt
  headerRead : CC.Expr
  currentRead : CC.Expr
  target : CC.Expr
  rhs : CC.Expr
private def parts : Parts := by
  run_tac do
    let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(update)) none))
    unless first.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH RSP first sequence changed"
    let second ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first.getAppArgs[1]!)
    unless second.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH RSP second sequence changed"
    let third ← Lean.Meta.withTransparency .all (Lean.Meta.whnf second.getAppArgs[1]!)
    unless third.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original PUSH RSP third sequence changed"
    let load ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first.getAppArgs[0]!)
    let raw ← Lean.Meta.withTransparency .all (Lean.Meta.whnf third.getAppArgs[0]!)
    let store ← Lean.Meta.withTransparency .all (Lean.Meta.whnf third.getAppArgs[1]!)
    unless load.isAppOfArity ``CC.Stmt.Sset 2 && raw.isAppOfArity ``CC.Stmt.Sset 2 &&
        store.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "original PUSH RSP reads/store changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_rsp_source
      (← Lean.Meta.mkAppM ``Parts.mk #[first.getAppArgs[0]!, second.getAppArgs[0]!, third.getAppArgs[0]!,
        third.getAppArgs[1]!,load.getAppArgs[1]!,raw.getAppArgs[1]!,store.getAppArgs[0]!,store.getAppArgs[1]!])

def first : CC.Stmt := parts.first
def second : CC.Stmt := parts.second
def third : CC.Stmt := parts.third
def store : CC.Stmt := parts.store
def headerRead : CC.Expr := parts.headerRead
def currentRead : CC.Expr := parts.currentRead
def target : CC.Expr := parts.target
def rhs : CC.Expr := parts.rhs

theorem source : update = .Ssequence first (.Ssequence second (.Ssequence third store)) := rfl
theorem reads : first = .Sset X86_program_profile_bpf._t'228 headerRead ∧
    second = .Sset X86_program_profile_bpf._t'229 headerRead ∧
    third = .Sset X86_program_profile_bpf._t'230 currentRead ∧ store = .Sassign target rhs := by
  exact ⟨rfl,rfl,rfl,rfl⟩

def control (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual PUSH continuation argument"
      pure (Lean.mkFVar argument.fvarId)
    let following ← Lean.Meta.mkAppM ``X86ProducerPushReadReturn.following arguments
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf following)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original PUSH update continuation changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_rsp_control node.getAppArgs[1]!

theorem following_source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    X86ProducerPushReadReturn.following binding k memory =
      .Kseq (.Ssequence update stackLoop) (control binding k memory) := rfl

/-- Execute the original sequence pops to the genuine RSP update. -/
theorem enter (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    InternalRun ge 2
      (.State handler .Sskip (X86ProducerPushReadReturn.following binding k memory) (allocation memory).1
        (X86ProducerPushReadReturn.temps binding k memory value) (allocation memory).2)
      (.State handler update (.Kseq stackLoop (control binding k memory)) (allocation memory).1
        (X86ProducerPushReadReturn.temps binding k memory value) (allocation memory).2) := by
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, following_source,
    CC.E0, CC.Eapp, List.nil_append, true_and]

/-- All three inputs are actual temporaries of the accepted source path. -/
theorem inputs (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    (X86ProducerPushReadReturn.temps binding k memory value).get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) ∧
    (X86ProducerPushReadReturn.temps binding k memory value).get X86_program_profile_bpf.___x86_l_pp_step = some (.Vlong (8#64)) ∧
    (X86ProducerPushReadReturn.temps binding k memory value).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong value) := by
  exact ⟨rfl,rfl,X86ProducerPushReadReturn.saved binding k memory value⟩

end KProgFormal.ClightRefinement.X86ProducerPushRspSource
