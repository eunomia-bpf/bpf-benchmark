import KProgFormal.ClightRefinement.X86ProducerPushStackSource

namespace KProgFormal.ClightRefinement.X86ProducerPushStorageSource

private structure Parts where
  body : CC.Stmt
  first : CC.Stmt
  second : CC.Stmt
  lossSet : CC.Stmt
  widthCall : CC.Stmt
  widthSave : CC.Stmt
  valueSet : CC.Stmt
  fastLoop : CC.Stmt
  lossCheck : CC.Stmt
  fastBody : CC.Stmt
  indexSet : CC.Stmt
  guardCall : CC.Stmt
  alignTest : CC.Stmt
  flagSet : CC.Stmt
  branch : CC.Stmt
  cacheRead : CC.Stmt
  cacheStore : CC.Stmt
private def shape (expression : Lean.Expr) (constructor : Lean.Name) (arity : Nat) : Lean.Meta.MetaM Lean.Expr := do
  let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf expression)
  unless result.isAppOfArity constructor arity do throwError "original PUSH storage source changed"
  return result
private def parts : Parts := by
  run_tac do
    let loop ← shape (← Lean.Elab.Term.elabTerm (← `(X86ProducerPushStackSource.storage)) none) ``CC.Stmt.Sloop 2
    let body ← shape loop.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let setup ← shape body.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let raw ← shape setup.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let following ← shape body.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let width ← shape following.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let value ← shape following.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let loops ← shape value.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let fast ← shape loops.getAppArgs[0]! ``CC.Stmt.Sloop 2
    let fastBody ← shape fast.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let guarded ← shape fastBody.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    let guards ← shape guarded.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let helper ← shape guards.getAppArgs[0]! ``CC.Stmt.Ssequence 2
    let branch ← shape guarded.getAppArgs[1]! ``CC.Stmt.Sifthenelse 3
    let cached ← shape branch.getAppArgs[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_storage_source
      (← Lean.Meta.mkAppM ``Parts.mk #[loop.getAppArgs[0]!, setup.getAppArgs[0]!, raw.getAppArgs[0]!, raw.getAppArgs[1]!,
        width.getAppArgs[0]!,width.getAppArgs[1]!,value.getAppArgs[0]!,loops.getAppArgs[0]!,loops.getAppArgs[1]!,
        fast.getAppArgs[0]!,fastBody.getAppArgs[0]!,helper.getAppArgs[0]!,helper.getAppArgs[1]!,guards.getAppArgs[1]!,
        guarded.getAppArgs[1]!,cached.getAppArgs[0]!,cached.getAppArgs[1]!])

def body : CC.Stmt := parts.body
def first : CC.Stmt := parts.first
def second : CC.Stmt := parts.second
def lossSet : CC.Stmt := parts.lossSet
def widthCall : CC.Stmt := parts.widthCall
def widthSave : CC.Stmt := parts.widthSave
def valueSet : CC.Stmt := parts.valueSet
def fastLoop : CC.Stmt := parts.fastLoop
def lossCheck : CC.Stmt := parts.lossCheck
def fastBody : CC.Stmt := parts.fastBody
def indexSet : CC.Stmt := parts.indexSet
def guardCall : CC.Stmt := parts.guardCall
def alignTest : CC.Stmt := parts.alignTest
def flagSet : CC.Stmt := parts.flagSet
def branch : CC.Stmt := parts.branch
def cacheRead : CC.Stmt := parts.cacheRead
def cacheStore : CC.Stmt := parts.cacheStore

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSave (.Kseq (.Ssequence valueSet (.Ssequence fastLoop lossCheck)) (loopCont k))

theorem source : X86ProducerPushStackSource.storage = .Sloop body .Sbreak ∧
    body = .Ssequence (.Ssequence first (.Ssequence second lossSet))
      (.Ssequence (.Ssequence widthCall widthSave) (.Ssequence valueSet (.Ssequence fastLoop lossCheck))) ∧
    fastLoop = .Sloop fastBody .Sbreak ∧
    fastBody = .Ssequence indexSet (.Ssequence (.Ssequence (.Ssequence guardCall alignTest) flagSet) branch) := ⟨rfl,rfl,rfl,rfl⟩

theorem inputs_source : first = .Sset X86_program_profile_bpf._t'212 X86ProducerPushRspSource.headerRead ∧
    second = .Sset X86_program_profile_bpf._t'213 (X86ProducerPushRspAddress.pointer X86_program_profile_bpf._t'212) ∧
    lossSet = .Sset X86_program_profile_bpf.___x86_loss_off
      (.Ecast (.Ecast (.Etempvar X86_program_profile_bpf._t'213 (CC.tptr CC.tvoid)) CC.tlong) CC.tlong) := ⟨rfl,rfl,rfl⟩

theorem width_source : widthCall = .Scall (some X86_program_profile_bpf._t'18)
    (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
    [.Etempvar X86_program_profile_bpf.___x86_l_pp_width CC.tuchar] ∧
    widthSave = .Sset X86_program_profile_bpf.___x86_loss_width (.Ecast (.Etempvar X86_program_profile_bpf._t'18 CC.tuchar) CC.tuchar) ∧
    guardCall = .Scall (some X86_program_profile_bpf._t'32)
      (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
      [.Etempvar X86_program_profile_bpf.___x86_loss_width CC.tuchar] := ⟨rfl,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushStorageSource
