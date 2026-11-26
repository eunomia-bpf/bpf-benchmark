import KProgFormal.ClightRefinement.Arm64MemcpyReadCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStoreIndex

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  loop : CC.Stmt
  post : CC.Stmt
  body : CC.Stmt
  setup : CC.Stmt
  afterIndex : CC.Stmt
  bias : CC.Stmt
  index : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memcpy store-index route changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadCall.store)) none) ``CC.Stmt.Ssequence
    let loop ← peel root[0]! ``CC.Stmt.Sloop
    let body ← peel loop[0]! ``CC.Stmt.Ssequence
    let setup ← peel body[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_index
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,loop[0]!,body[0]!,body[1]!,setup[0]!,setup[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_store_index_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
def post : CC.Stmt := by run_tac cachePart (← `(parts.post))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
def afterIndex : CC.Stmt := by run_tac cachePart (← `(parts.afterIndex))
private def bias : CC.Stmt := by run_tac cachePart (← `(parts.bias))
private def index : CC.Stmt := by run_tac cachePart (← `(parts.index))

theorem source : Arm64MemcpyReadCall.store = .Ssequence loop post ∧
    loop = .Sloop body .Sbreak ∧ body = .Ssequence setup afterIndex ∧
    setup = .Ssequence bias index := ⟨rfl,rfl,rfl,rfl⟩

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq post k)

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel

private def biasTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'158 (.Vlong 96)
def temps (le : CC.TempEnv) (off : BitVec 64) : CC.TempEnv :=
  (biasTemps le).set Arm64Program.___a64_stw_index (.Vlong ((96#64)+off))

private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State handler bias k e le m) =
      some (CC.E0,.State handler .Sskip k e (biasTemps le) m) := by
  simp only [bias,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tlong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,
    CC.Integers.MI.unsigned,biasTemps,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,observed]

private theorem index_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (off : BitVec 64)
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong off)) :
    CC.doStep world (.State handler index k e (biasTemps le) m) =
      some (CC.E0,.State handler .Sskip k e (temps le off) m) := by
  have other : Arm64Program._t'158 ≠ Arm64Program.___a64_loss_off := by decide +kernel
  simp only [index,CC.doStep,CC.doEvalExpr,biasTemps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other,hoff,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tlong,CC.tulong,CC.Archi.ptr64,
    CC.Integers.Int64.add,CC.Integers.MI.add,temps,ite_true,ite_false]
  rfl

theorem physical_index : ∀ i : Fin 16,
    (96#64)+((-16#64)+BitVec.ofNat 64 i.val) = BitVec.ofNat 64 (80+i.val) := by decide +kernel

/-- Original loop/sequence entries and the actual bias load derive the
physical destination index without changing the current source heap. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry : CC.Block) (off : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong off)) :
    InternalRun world 8 (.State handler Arm64MemcpyReadCall.store k e le m)
      (.State handler afterIndex (continuation k) e (temps le off) m) := by
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step e le m _ entry hentry observed)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (index_step e le m _ off hoff)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

theorem kept (le : CC.TempEnv) (off : BitVec 64) (id : CC.Ident)
    (indexOther : Arm64Program.___a64_stw_index ≠ id) (biasOther : Arm64Program._t'158 ≠ id) :
    (temps le off).get id = le.get id := by
  simp only [temps,biasTemps,CC.PTree.gso _ _ _ _ indexOther,CC.PTree.gso _ _ _ _ biasOther]

end KProgFormal.ClightRefinement.Arm64MemcpyStoreIndex
