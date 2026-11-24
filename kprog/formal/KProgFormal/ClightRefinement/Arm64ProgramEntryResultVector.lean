import KProgFormal.ClightRefinement.Arm64ProgramEntryResultRead
import KProgFormal.ClightRefinement.Arm64ProgramEntryVectorInputs
import KProgFormal.ClightRefinement.Arm64FmovInputs
import KProgFormal.ClightRefinement.Arm64CntInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResultVector

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal VectorLocal)
open Arm64ProgramEntryResultRead

private def vectorKey (zero : Bool) : CC.Ident := if zero then Arm64ProgramFixture._t'165 else Arm64ProgramFixture._t'166
private def vectorIndex (zero : Bool) : Nat := if zero then 0 else 3
private def vectorStmt (zero : Bool) : CC.Stmt := if zero then vector0 else vector3
private def vectorType : CC.Ty := .Tstruct Arm64ProgramFixture.__5183 CC.noattr

private theorem vector_source (zero : Bool) : vectorStmt zero = .Sset (vectorKey zero)
    (.Efield (.Ederef (.Ebinop .Oadd
      (.Evar Arm64ProgramFixture.___a64_vectors (CC.tarray vectorType 32))
      (.Econst_int (CC.Integers.Int.repr (vectorIndex zero)) CC.tint)
      (CC.tptr vectorType)) vectorType) Arm64ProgramFixture._lo CC.tulong) := by
  cases zero <;> rfl

private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture.__5183).get (by decide +kernel)
private theorem layouts : world.genv_cenv.get Arm64ProgramFixture.__5183 = some composite ∧
    CC.fieldOffset world.genv_cenv Arm64ProgramFixture._lo composite.co_members = .OK (0,.Full) ∧
    CC.sizeof world.genv_cenv vectorType = 16 := by
  constructor
  · decide +kernel
  constructor <;> decide +kernel

/-- Read the actual source vector3 or vector0 low member through its real
anonymous composite layout and original allocation lookup. -/
theorem vector_step {initial : CC.Mem} (vectors : VectorLocal initial) (zero : Bool)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (loaded : CC.Mem.load .Mint64 m vectors.block (if zero then 0 else 48) = some (.Vlong value)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (vectorStmt zero) k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set (vectorKey zero) (.Vlong value)) m) := by
  have binding : (allocation initial).1.get Arm64ProgramFixture.___a64_vectors =
      some (vectors.block,CC.tarray vectorType 32) := Arm64ProgramEntryVectorInputs.binding initial vectors
  have size : CC.sizeof world.genv_cenv (.Tstruct Arm64ProgramFixture.__5183 CC.noattr) = 16 := layouts.2.2
  rw [vector_source]
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
      BitVec.signExtend CC.Archi.ptrWordsize (CC.Integers.Int.repr (vectorIndex zero)) + CC.Integers.Ptrofs.repr 0).toNat : Int) =
      (if zero then 0 else 48) := by cases zero <;> decide +kernel
  change (match CC.Mem.load .Mint64 m vectors.block
      (CC.Integers.Ptrofs.repr 0 + CC.Integers.Ptrofs.repr 16 *
        BitVec.signExtend CC.Archi.ptrWordsize (CC.Integers.Int.repr (vectorIndex zero)) + CC.Integers.Ptrofs.repr 0).toNat with
    | some value => some (CC.E0,CC.State.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k
        (allocation initial).1 (le.set (vectorKey zero) value) m)
    | none => none) = _
  rw [offset,loaded]

private theorem first_source : firstXor = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._t'131 CC.tulong)
      (.Etempvar Arm64ProgramFixture._t'132 CC.tulong) CC.tulong)
      (.Etempvar Arm64ProgramFixture._t'166 CC.tulong) CC.tulong) := rfl
private theorem second_source : secondXor = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong)
      (.Etempvar Arm64ProgramFixture._t'165 CC.tulong) CC.tulong) := rfl

def temps (le : CC.TempEnv) (left right third zeroth : BitVec 64) : CC.TempEnv :=
  ((((readTemps le left right).set Arm64ProgramFixture._t'166 (.Vlong third)).set
    Arm64ProgramFixture._result (.Vlong (left ^^^ right ^^^ third))).set
    Arm64ProgramFixture._t'165 (.Vlong zeroth)).set
    Arm64ProgramFixture._result (.Vlong (left ^^^ right ^^^ third ^^^ zeroth))

set_option hygiene false in
/-- Both actual vector loads and original XOR assignments execute after the
two real GPR calls, with the complete heap and original continuation retained. -/
theorem finish {initial : CC.Mem} (vectors : VectorLocal initial) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (left right third zeroth : BitVec 64)
    (load3 : CC.Mem.load .Mint64 m vectors.block 48 = some (.Vlong third))
    (load0 : CC.Mem.load .Mint64 m vectors.block 0 = some (.Vlong zeroth)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip
        (.Kseq (.Ssequence vector3 firstXor) (.Kseq (.Ssequence (.Ssequence vector0 secondXor) afterReads) k))
        (allocation initial).1 (readTemps le left right) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterReads k
        (allocation initial).1 (temps le left right third zeroth) m) := by
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:30] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if stmt.isConstOf ``afterReads then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual result vector/XOR transitions: {i}"
          finished := true
          break
        if stmt.isConstOf ``vector3 || stmt.isConstOf ``vector0 then
          let zero := stmt.isConstOf ``vector0
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          if zero then
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply vector_step vectors true))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact load0))
          else
            Lean.Elab.Tactic.evalTactic (← `(tactic| apply vector_step vectors false))
            Lean.Elab.Tactic.evalTactic (← `(tactic| exact load3))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,first_source,second_source,
        CC.doEvalExpr,CC.typeof,CC.Cop.semBinaryOperation,CC.Cop.semXor,CC.Cop.semBinarith,
        CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.Archi.ptr64,CC.PTree.gss,
        CC.PTree.gso,vectorKey,Bool.false_eq_true,ite_true,ite_false,readTemps]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    unless finished do throwError "original result vector/XOR continuation did not finish"

/-- Complete the original two GPR calls, vector3/vector0 loads and both result
XOR assignments. Both vector observations and native words follow from actual
storage and representation, with no independent native operand premise. -/
theorem execute {initial m : CC.Mem} {entry : HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (left right : BitVec 64) (tag : BitVec 8)
    (tags : tag = 0 ∨ tag = 4)
    (lhs : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 5 =
      some (.Vlong left,.Vint (tag.setWidth 32)))
    (rhs : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 7 = some (.Vlong right,.Vint 0))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m (.Vptr entry.block 0) origins.stack) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterReads k (allocation initial).1
        (temps le (Reference.AArch64.gpr s 5) (Reference.AArch64.gpr s 7)
          ((Reference.AArch64.readVector s 3).setWidth 64) ((Reference.AArch64.readVector s 0).setWidth 64)) m) := by
  let cont := CC.Cont.Kseq (.Ssequence vector3 firstXor)
    (.Kseq (.Ssequence (.Ssequence vector0 secondXor) afterReads) k)
  have enter : InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryUaddlvCall.afterUaddlv k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence (call false) (call true)) cont
        (allocation initial).1 le m) := by
    rw [source]
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    exact .refl _
  obtain ⟨readCount,reads⟩ := both entry le m cont origins left right tag tags lhs rhs cache
  obtain ⟨tailCount,tail⟩ := finish storage.vectors le m k
    (Reference.Provenance.AArch64.materialize origins left tag) right
    ((Reference.AArch64.readVector s 3).setWidth 64) ((Reference.AArch64.readVector s 0).setWidth 64)
    (Arm64Fmov.Inputs.old_vector storage addresses origins s represented)
    (Arm64Cnt.Inputs.words storage addresses origins s represented).1
  have physical5 := native_word addresses origins s m entry.block 5 left tag represented lhs
  have physical7 := Arm64MovKeep.scalar_native_bits addresses origins s m.nextblock m (.Vptr entry.block 0)
    7 right rhs represented
  refine ⟨2+readCount+tailCount,?_⟩
  simpa only [physical5,physical7] using (enter.trans reads).trans tail

theorem result (le : CC.TempEnv) (left right third zeroth : BitVec 64) :
    (temps le left right third zeroth).get Arm64ProgramFixture._result =
      some (.Vlong (left ^^^ right ^^^ third ^^^ zeroth)) := CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64ProgramEntryResultVector
