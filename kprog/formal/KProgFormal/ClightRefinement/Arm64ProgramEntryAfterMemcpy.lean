import KProgFormal.ClightRefinement.Arm64ClobberResult

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAfterMemcpy

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal VectorLocal)

private structure Parts where
  read : CC.Stmt
  update : CC.Stmt
  branches : CC.Stmt
private def parts : Parts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyProgramEntry.next)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original post-memcpy sequence changed"
    let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual.getAppArgs[0]!)
    unless pair.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original post-memcpy read/XOR changed"
    Lean.Elab.Tactic.closeMainGoal `original_post_memcpy_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[pair.getAppArgs[0]!,pair.getAppArgs[1]!,actual.getAppArgs[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `original_post_memcpy_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def read : CC.Stmt := by run_tac cachePart (← `(parts.read))
def update : CC.Stmt := by run_tac cachePart (← `(parts.update))
def branches : CC.Stmt := by run_tac cachePart (← `(parts.branches))
theorem source : Arm64MemcpyProgramEntry.next = .Ssequence (.Ssequence read update) branches := rfl
private def vectorType : CC.Ty := .Tstruct Arm64ProgramFixture.__5183 CC.noattr
private theorem read_source : read = .Sset Arm64ProgramFixture._t'162
    (.Efield (.Ederef (.Ebinop .Oadd
      (.Evar Arm64ProgramFixture.___a64_vectors (CC.tarray vectorType 32))
      (.Econst_int (CC.Integers.Int.repr 31) CC.tint) (CC.tptr vectorType)) vectorType)
      Arm64ProgramFixture._hi CC.tulong) := rfl
private theorem update_source : update = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong)
      (.Etempvar Arm64ProgramFixture._t'162 CC.tulong) CC.tulong) := rfl
private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture.__5183).get (by decide +kernel)
private theorem layouts : world.genv_cenv.get Arm64ProgramFixture.__5183 = some composite ∧
    CC.fieldOffset world.genv_cenv Arm64ProgramFixture._hi composite.co_members = .OK (8,.Full) ∧
    CC.sizeof world.genv_cenv vectorType = 16 := by
  constructor
  · decide +kernel
  constructor <;> decide +kernel

theorem read_step {initial : CC.Mem} (vectors : VectorLocal initial)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (loaded : CC.Mem.load .Mint64 m vectors.block 504 = some (.Vlong value)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile read k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'162 (.Vlong value)) m) := by
  have binding : (allocation initial).1.get Arm64ProgramFixture.___a64_vectors =
      some (vectors.block,CC.tarray vectorType 32) := Arm64ProgramEntryVectorInputs.binding initial vectors
  have size : CC.sizeof world.genv_cenv (.Tstruct Arm64ProgramFixture.__5183 CC.noattr) = 16 := layouts.2.2
  rw [read_source]
  apply CC.doStep_sound
  simp +decide only [CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,binding,
    Arm64ProgramEntryVectorInputs.arrayType,Arm64ProgramEntryVectorInputs.tag,Arm64Producer.vectorArrayTypeFor,
    vectorType,CC.lvalOfField,CC.doDerefLoc,CC.accessMode,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,
    CC.tulong,CC.tptr,CC.tarray,CC.Archi.ptr64,CC.Archi.ptrWordsize,
    layouts.1,layouts.2.1,layouts.2.2,CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,
    CC.Integers.Ptrofs.of_intu,CC.Integers.Ptrofs.of_int,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.MI.add,CC.Integers.MI.mul,size,ite_true,ite_false] <;> try rfl
  have offset : ((CC.Integers.Ptrofs.repr 0 + CC.Integers.Ptrofs.repr 16 *
      BitVec.signExtend CC.Archi.ptrWordsize (CC.Integers.Int.repr 31) + CC.Integers.Ptrofs.repr 8).toNat : Int) =
      504 := by decide +kernel
  change (match CC.Mem.load .Mint64 m vectors.block
      (CC.Integers.Ptrofs.repr 0 + CC.Integers.Ptrofs.repr 16 *
        BitVec.signExtend CC.Archi.ptrWordsize (CC.Integers.Int.repr 31) + CC.Integers.Ptrofs.repr 8).toNat with
    | some value => some (CC.E0,CC.State.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k
        (allocation initial).1 (le.set Arm64ProgramFixture._t'162 value) m)
    | none => none) = _
  rw [offset,loaded]

def temps (le : CC.TempEnv) (value selected : BitVec 64) : CC.TempEnv :=
  (le.set Arm64ProgramFixture._t'162 (.Vlong selected)).set Arm64ProgramFixture._result (.Vlong (value ^^^ selected))

set_option hygiene false in
/-- The same complete memcpy output supplies its actual last provider word
at V31.hi. The real source load and XOR reach the original branch suffix on
that heap, retaining the saved program temp map and current memory packet. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (priorResult : le.get Arm64ProgramFixture._result = some (.Vlong value)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile branches k (allocation initial).1 (temps le value (values 63)) m) := by
  have loaded : CC.Mem.load .Mint64 m packet.memory.storage.vectors.block 504 = some (.Vlong (values 63)) := by
    exact packet.vectors 63
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:16] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if stmt.isConstOf ``branches then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual post-memcpy V31.hi/XOR transitions: {i}"
          finished := true
          break
        if stmt.isConstOf ``read then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply read_step packet.memory.storage.vectors))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact loaded))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [source,update_source,CC.doStep,CC.doEvalExpr,CC.typeof,
        CC.Cop.semBinaryOperation,CC.Cop.semXor,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.Archi.ptr64,
        CC.PTree.gss,CC.PTree.gso,priorResult]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    unless finished do throwError "original post-memcpy continuation did not finish"

end KProgFormal.ClightRefinement.Arm64ProgramEntryAfterMemcpy
