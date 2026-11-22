import KProgFormal.ClightRefinement.Arm64CompareStores

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Body
open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage (Storage)

/-- The actual modifier result is masked again by the original SUB macro. -/
def rhsValue (rhs : BitVec 64) (narrow : Bool) : BitVec 64 := Arm64Modified.Modifier.result rhs narrow

def branchTemps (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) (blocks : Fin 4 → CC.Block) : CC.TempEnv :=
  Stores.temps (Math.temps (Prefix.temps le lhs rhs narrow) lhs (rhsValue rhs narrow) narrow) blocks

def finalTemps (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) (blocks : Fin 4 → CC.Block) : CC.TempEnv :=
  branchTemps (Dispatch.temps le narrow) lhs rhs narrow blocks

/-- Both real scalar operand calls and the complete original flag loop. No
resulting helper word, flag, store success or native readback is assumed. -/
theorem branch_execute {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (writable : Stores.Writable storage)
    (i j : Fin 31) (lhs rhs : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (modifiedName : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (op : le.get Arm64Program._op = some (.Vint (23#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint 0)) :
    ∃ after, Stores.Effect storage (Math.left lhs narrow) (Math.right (rhsValue rhs narrow) narrow)
        (Math.result lhs (rhsValue rhs narrow) narrow) (Math.sign narrow) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 291
        (.State Arm64Nop.handler Dispatch.branch k e le memory)
        (.State Arm64Nop.handler .Sskip k e
          (branchTemps le lhs rhs narrow (fun n => (storage.flags (Stores.flagIndex n)).block)) after) := by
  have readRun := Prefix.execute storage i j lhs rhs e le k narrow readName modifiedName
    entryRead dst src aux effective op lhsWord lhsTag rhsWord rhsTag
  have carried :
      (Prefix.temps le lhs rhs narrow).get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      (Prefix.temps le lhs rhs narrow).get Arm64Program.___a64_l_width = some (RhsCall.width narrow) := by
    dsimp only [Prefix.temps,Rhs.temps,Operands.lhsTemps]
    refine ⟨?_,?_⟩
    all_goals
      repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    · exact entryRead
    · exact effective
  have values := Prefix.values le lhs rhs narrow
  obtain ⟨after,effect,flagRun⟩ := Stores.execute_loop_writable storage e (Prefix.temps le lhs rhs narrow)
    k lhs (rhsValue rhs narrow) narrow carried.1 carried.2 values.1 values.2 writable
  exact ⟨after,effect,readRun.trans flagRun⟩

private theorem ready (le : CC.TempEnv) (narrow : Bool) (entry : CC.Block) (i j : Fin 31)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry 0))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (op : le.get Arm64Program._op = some (.Vint (23#32))) :
    (Dispatch.temps le narrow).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (Dispatch.temps le narrow).get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
    (Dispatch.temps le narrow).get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)) ∧
    (Dispatch.temps le narrow).get Arm64Program._aux = some (.Vint (256#32)) ∧
    (Dispatch.temps le narrow).get Arm64Program.___a64_l_width = some (RhsCall.width narrow) ∧
    (Dispatch.temps le narrow).get Arm64Program._op = some (.Vint (23#32)) := by
  cases narrow <;> refine ⟨?_,?_,?_,?_,?_,?_⟩
  all_goals
    dsimp only [Dispatch.temps,Dispatch.flags,Arm64Nop.resultEnv,Arm64Width.result,
      Arm64Width.argument,RhsCall.width]
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  all_goals first | exact entryRead | exact dst | exact src | exact aux | exact op | rfl

set_option hygiene false in
private theorem leave_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  run_tac do
    for _ in [:2] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Complete original W/X scalar CMP body: actual linked width helper and every
dispatch gate118, operand reads218, original flag loop73 and enclosing exit2.
The generic function's own caller frame remains live. -/
theorem execute {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (writable : Stores.Writable storage)
    (i j : Fin 31) (lhs rhs : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (modifiedName : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 j.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (Dispatch.flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (23#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint 0)) :
    ∃ after, Stores.Effect storage (Math.left lhs narrow) (Math.right (rhsValue rhs narrow) narrow)
        (Math.result lhs (rhsValue rhs narrow) narrow) (Math.sign narrow) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 411
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le memory)
        (.State Arm64Nop.handler .Sskip k e
          (finalTemps le lhs rhs narrow (fun n => (storage.flags (Stores.flagIndex n)).block)) after) := by
  have dispatched := Dispatch.Linked.body_dispatch e le memory k narrow widthName flags op
  have inputs := ready le narrow entry.block i j entryRead dst src aux op
  obtain ⟨after,effect,branchRun⟩ := branch_execute storage writable i j lhs rhs e
    (Dispatch.temps le narrow) (Dispatch.continuation k) narrow readName modifiedName
    inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1 inputs.2.2.2.2.1 inputs.2.2.2.2.2
    lhsWord lhsTag rhsWord rhsTag
  exact ⟨after,effect,(dispatched.trans branchRun).trans (leave_loop e _ after k)⟩

end KProgFormal.ClightRefinement.Arm64Compare.Body
