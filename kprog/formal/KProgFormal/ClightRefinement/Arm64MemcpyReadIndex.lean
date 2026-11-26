import KProgFormal.ClightRefinement.Arm64MemcpyReadDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadIndex

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  outer : CC.Stmt
  caseBreak : CC.Stmt
  outerBody : CC.Stmt
  inner : CC.Stmt
  postRead : CC.Stmt
  innerBody : CC.Stmt
  setup : CC.Stmt
  afterIndex : CC.Stmt
  bias : CC.Stmt
  index : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original reader stack-index source changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadDispatch.read)) none) ``CC.Stmt.Ssequence
    let outer ← peel root[0]! ``CC.Stmt.Sloop
    let outerBody ← peel outer[0]! ``CC.Stmt.Ssequence
    let inner ← peel outerBody[0]! ``CC.Stmt.Sloop
    let body ← peel inner[0]! ``CC.Stmt.Ssequence
    let setup ← peel body[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_reader_stack_index
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,outer[0]!,outerBody[0]!,outerBody[1]!,inner[0]!,body[0]!,body[1]!,setup[0]!,setup[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_index_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def outer : CC.Stmt := by run_tac cachePart (← `(parts.outer))
def caseBreak : CC.Stmt := by run_tac cachePart (← `(parts.caseBreak))
private def outerBody : CC.Stmt := by run_tac cachePart (← `(parts.outerBody))
private def inner : CC.Stmt := by run_tac cachePart (← `(parts.inner))
def postRead : CC.Stmt := by run_tac cachePart (← `(parts.postRead))
private def innerBody : CC.Stmt := by run_tac cachePart (← `(parts.innerBody))
private def setup : CC.Stmt := by run_tac cachePart (← `(parts.setup))
def afterIndex : CC.Stmt := by run_tac cachePart (← `(parts.afterIndex))
private def bias : CC.Stmt := by run_tac cachePart (← `(parts.bias))
private def index : CC.Stmt := by run_tac cachePart (← `(parts.index))

theorem source : Arm64MemcpyReadDispatch.read = .Ssequence outer caseBreak ∧
    outer = .Sloop outerBody .Sbreak ∧ outerBody = .Ssequence inner postRead ∧
    inner = .Sloop innerBody .Sbreak ∧ innerBody = .Ssequence setup afterIndex ∧
    setup = .Ssequence bias index := ⟨rfl,rfl,rfl,rfl,rfl,rfl⟩

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 innerBody .Sbreak (.Kseq postRead (.Kloop1 outerBody .Sbreak (.Kseq caseBreak k)))

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor <;> decide +kernel

private def biasTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'93 (.Vlong 96)

def temps (le : CC.TempEnv) (raw off : BitVec 64) : CC.TempEnv :=
  (biasTemps le).set Arm64Program.___a64_str_index (.Vlong ((96#64)+(raw+off)))

private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State reader bias k e le m) =
      some (CC.E0,.State reader .Sskip k e (biasTemps le) m) := by
  simp only [bias,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tlong,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,biasTemps,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [offset,observed]

private theorem index_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (raw off : BitVec 64)
    (hbase : le.get Arm64Program.___a64_mrd_base = some (.Vlong raw))
    (hoff : le.get Arm64Program.___a64_memory_off = some (.Vlong off)) :
    CC.doStep world (.State reader index k e (biasTemps le) m) =
      some (CC.E0,.State reader .Sskip k e (temps le raw off) m) := by
  have baseOther : Arm64Program._t'93 ≠ Arm64Program.___a64_mrd_base := by decide +kernel
  have offOther : Arm64Program._t'93 ≠ Arm64Program.___a64_memory_off := by decide +kernel
  simp only [index,CC.doStep,CC.doEvalExpr,biasTemps,CC.PTree.gss,
    CC.PTree.gso _ _ _ _ baseOther,CC.PTree.gso _ _ _ _ offOther,hbase,hoff,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tlong,CC.tulong,CC.Archi.ptr64,
    CC.Integers.Int64.add,CC.Integers.MI.add,temps,ite_true,ite_false]
  rfl

/-- The physical source index derives from the actual bias and current R1,
with the current iteration as its original extra argument. -/
theorem physical_index : ∀ i : Fin 16,
    (96#64)+((-32#64)+BitVec.ofNat 64 i.val) = BitVec.ofNat 64 (64+i.val) := by decide +kernel

/-- Execute the original nested-loop entries, genuine bias load and original
signed/unsigned casts and additions. The saved case and both loops remain. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry : CC.Block) (raw off : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96))
    (hbase : le.get Arm64Program.___a64_mrd_base = some (.Vlong raw))
    (hoff : le.get Arm64Program.___a64_memory_off = some (.Vlong off)) :
    InternalRun world 10 (.State reader Arm64MemcpyReadDispatch.read k e le m)
      (.State reader afterIndex (continuation k) e (temps le raw off) m) := by
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step e le m _ entry hentry observed)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (index_step e le m _ raw off hbase hoff)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

theorem kept (le : CC.TempEnv) (raw off : BitVec 64) (key : CC.Ident)
    (indexOther : Arm64Program.___a64_str_index ≠ key) (biasOther : Arm64Program._t'93 ≠ key) :
    (temps le raw off).get key = le.get key := by
  simp only [temps,biasTemps,CC.PTree.gso _ _ _ _ indexOther,CC.PTree.gso _ _ _ _ biasOther]

end KProgFormal.ClightRefinement.Arm64MemcpyReadIndex
