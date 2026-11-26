import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryContinuationByte
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

private def cachePart (index : Nat) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryReturnTarget.continuationBody)) none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original continuation byte source changed"
  Lean.Elab.Tactic.closeMainGoal `actual_continuation_byte_part actual.getAppArgs[index]!
def read : CC.Stmt := by run_tac cachePart 0
def update : CC.Stmt := by run_tac cachePart 1
theorem source : Arm64ProgramEntryReturnTarget.continuationBody = .Ssequence read update := rfl
private def stackType : CC.Ty := CC.tvolatile (.Tunion Arm64ProgramFixture.__5185 CC.noattr)
theorem read_source : read = .Sset Arm64ProgramFixture._t'158
    (.Ederef (.Ebinop .Oadd
      (.Efield (.Evar Arm64ProgramFixture.___a64_stack stackType) Arm64ProgramFixture._b
        (CC.tvolatile (CC.tarray CC.tuchar 160)))
      (.Econst_int (80#32) CC.tint) (CC.tptr CC.tuchar)) CC.tuchar) := rfl
theorem update_source : update = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong)
      (.Etempvar Arm64ProgramFixture._t'158 CC.tuchar) CC.tulong) := rfl
private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture.__5185).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64ProgramFixture.__5185 = some composite ∧
    CC.unionFieldOffset world.genv_cenv Arm64ProgramFixture._b composite.co_members = .OK (0,.Full) := by
  constructor <;> decide +kernel

theorem read_step {initial : CC.Mem} (stack : TailLocal initial 0) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (byte : BitVec 8) (loaded : CC.Mem.load .Mint8unsigned m stack.block 80 = some (.Vint (byte.setWidth 32))) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile read k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._t'158 (.Vint (byte.setWidth 32))) m) := by
  have binding : (allocation initial).1.get Arm64ProgramFixture.___a64_stack = some (stack.block,stackType) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ stack.binding
  rw [read_source]
  apply CC.doStep_sound
  simp +decide only [CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,binding,stackType,
    CC.lvalOfField,CC.doDerefLoc,CC.accessMode,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,
    CC.tulong,CC.tuchar,CC.tptr,CC.tarray,CC.tvolatile,CC.Archi.ptr64,CC.Archi.ptrWordsize,
    layout.1,layout.2,CC.Val.offsetPtr,CC.Cop.ptrofsOfInt,CC.sizeof,
    CC.Integers.Ptrofs.of_intu,CC.Integers.Ptrofs.of_int,CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,
    CC.Integers.MI.add,CC.Integers.MI.mul,ite_true,ite_false] <;> try rfl
  change (match CC.Mem.load .Mint8unsigned m stack.block 80 with
    | some value => some (CC.E0,CC.State.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k
        (allocation initial).1 (le.set Arm64ProgramFixture._t'158 value) m)
    | none => none) = _
  rw [loaded]

private theorem cast_byte (byte : BitVec 8) : CC.Cop.castIntLong .Unsigned (byte.setWidth 32) = byte.setWidth 64 := by
  change BitVec.ofInt 64 ((byte.setWidth 32).toNat : Int) = _
  rw [BitVec.ofInt_natCast]
  apply BitVec.eq_of_toNat_eq
  rw [BitVec.toNat_ofNat,BitVec.toNat_setWidth_of_le (by decide : 8 ≤ 32),
    BitVec.toNat_setWidth_of_le (by decide : 8 ≤ 64)]
  exact Nat.mod_eq_of_lt (by have := byte.isLt; omega)

def value (saved : BitVec 64) (byte : BitVec 8) : BitVec 64 := saved ^^^ byte.setWidth 64
def temps (le : CC.TempEnv) (saved : BitVec 64) (byte : BitVec 8) : CC.TempEnv :=
  (le.set Arm64ProgramFixture._t'158 (.Vint (byte.setWidth 32))).set Arm64ProgramFixture._result (.Vlong (value saved byte))

set_option hygiene false in
/-- The SAME copied-byte witness supplies the genuine union/array byte80 load
and full64 result XOR before the original terminal stores. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte rawR0 16 gprs flags vectors cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (saved : BitVec 64)
    (priorResult : le.get Arm64ProgramFixture._result = some (.Vlong saved)) :
    InternalRun world 5
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
        (.Kseq Arm64ProgramEntryReturnTarget.afterContinuation k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.afterContinuation k
        (allocation initial).1 (temps le saved byte) m) := by
  have loaded : CC.Mem.load .Mint8unsigned m packet.memory.view.stack.block 80 = some (.Vint (byte.setWidth 32)) := by
    rw [packet.memory.stackSame]
    exact packet.memory.copied 0 (by decide)
  run_tac do
    for i in [:5] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 1 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact read_step packet.memory.view.stack le m _ byte loaded))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [source,update_source,CC.doStep,CC.doEvalExpr,CC.typeof,
          CC.Cop.semBinaryOperation,CC.Cop.semXor,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuchar,
          CC.Archi.ptr64,CC.PTree.gss,CC.PTree.gso,priorResult] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [temps,value,cast_byte,CC.Integers.Int64.xor,CC.Integers.MI.xor]; exact InternalRun.refl _))


theorem result_value (le : CC.TempEnv) (saved : BitVec 64) (byte : BitVec 8) :
    (temps le saved byte).get Arm64ProgramFixture._result = some (.Vlong (value saved byte)) := CC.PTree.gss _ _ _

theorem ctx_preserved (le : CC.TempEnv) (saved : BitVec 64) (byte : BitVec 8) :
    (temps le saved byte).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  simp only [temps]
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Same actual callee/raw/tag/LR-store witness reaches the terminal stores
through the genuine copied byte load and result update. -/
theorem from_callee {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 16 gprs flags vectors cell flagValue before)
    (lr : Arm64Producer.HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)))
    (saved : BitVec 64) (priorResult : le.get Arm64ProgramFixture._result = some (.Vlong saved)) :
    ∃ after, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr before after,
      InternalRun world 89
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.afterContinuation
          (CC.callCont k) (allocation initial).1 (temps (Arm64ProgramEntryReturnComplete.temps le) saved byte) after) ∧
      FrameBelow initial.nextblock before after := by
  obtain ⟨after,effect,returned,_,_⟩ := Arm64ProgramEntryReturnComplete.execute current lr le k observed
  let reached := Arm64ProgramEntryLinkFrame.packet effect current
  have bytes := execute reached (Arm64ProgramEntryReturnComplete.temps le) (CC.callCont k) saved
    ((Arm64ProgramEntryReturnComplete.result_readback le).trans priorResult)
  exact ⟨after,effect,returned.trans bytes,effect.caller⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryContinuationByte
