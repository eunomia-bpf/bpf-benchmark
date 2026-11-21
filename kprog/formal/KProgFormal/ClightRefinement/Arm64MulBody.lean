import KProgFormal.ClightRefinement.Arm64MulPrefix
import KProgFormal.ClightRefinement.Arm64MulProduct

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.Body

/-- The original scalar writer edge, without replacing the call by its result. -/
private theorem scalar_call (world : CC.CGenv) (block b : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (dst value : BitVec 64) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (result : le.get Arm64Program.___a64_l_result__1 = some (.Vlong value))
    (width : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    CC.Step2 world (.State Arm64Nop.handler Operands.writer k e le m) CC.E0
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr b 0, .Vlong dst, .Vlong value, Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e le k) m) := by
  have source : Operands.writer = .Scall none
      (.Evar Arm64Program._kprog_arm64_program_write
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
          CC.tulong, CC.tuchar] CC.tvoid CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._dst CC.tulong,
       .Etempvar Arm64Program.___a64_l_result__1 CC.tulong,
       .Etempvar Arm64Program.___a64_l_width CC.tuchar] := rfl
  rw [source]
  apply CC.Step.call
    (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong, CC.tulong, CC.tuchar])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    cases narrow <;> simp +decide [Arm64RegisterWrite.width, CC.doEvalExprlist, CC.doEvalExpr, entry, destination, result, width, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.tuchar, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · rfl

/-- Both actual stores and the real caller return, on this reached heap. -/
theorem scalar_write {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry) (i : Fin 31)
    (value : BitVec 64) (narrow : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (result : le.get Arm64Program.___a64_l_result__1 = some (.Vlong value))
    (width : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    ∃ after, Arm64RegisterWrite.Result storage i value narrow after ∧
      InternalRun Arm64ProgramEntryLinked.ge 69
        (.State Arm64Nop.handler Operands.writer k e le memory)
        (.State Arm64Nop.handler .Sskip k e le after) := by
  obtain ⟨after, written⟩ := Arm64RegisterWrite.write storage i value narrow
  obtain ⟨middle, word, tag⟩ := written.stores
  have call : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler Operands.writer k e le memory)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        (Arm64RegisterWrite.arguments entry.block i value narrow)
        (.Kcall none Arm64Nop.handler e le k) memory) :=
    .step trivial (scalar_call Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 107) entry.block
      Arm64MovKeep.Linked.writer_binding e le memory k (BitVec.ofNat 64 i.val) value narrow
      unshadowed entryRead destination result width) (.refl _)
  have write := Arm64RegisterWrite.execute_stores_layout Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.writer_layout (.Kcall none Arm64Nop.handler e le k) rfl
    initial memory middle after entry storage i value narrow word tag
  have finish : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e le k) after)
      (.State Arm64Nop.handler .Sskip k e le after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨after, written, (call.trans write).trans finish⟩

def finalTemps (le : CC.TempEnv) (narrow : Bool) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Product.temps (Prefix.finalTemps le narrow lhs rhs) lhs rhs

set_option hygiene false in
private theorem leave_loop (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  run_tac do
    for _ in [:2] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem operands_ready (le : CC.TempEnv) (narrow : Bool) (lhs rhs : BitVec 64)
    (entry destination : CC.Val)
    (he : le.get Arm64Program._entry = some entry)
    (hd : le.get Arm64Program._dst = some destination) :
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program.___kprog_a64_mul_op = some (.Vlong (12#64)) ∧
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program.___kprog_a64_mul_lhs = some (.Vlong lhs) ∧
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program.___kprog_a64_mul_rhs = some (.Vlong rhs) ∧
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program._entry = some entry ∧
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program._dst = some destination ∧
    (Prefix.finalTemps le narrow lhs rhs).get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow) := by
  cases narrow <;> refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals
    simp only [Prefix.finalTemps, Prefix.afterRhs, Prefix.afterLhs,
      Operands.addendTemps, Operands.rhsTemps, Operands.lhsTemps, Operands.opTemps,
      Dispatch.temps, Dispatch.flags, Arm64Nop.resultEnv, Arm64Width.result, Arm64Width.argument,
      Arm64RegisterWrite.width, Bool.false_eq_true, ite_true, ite_false]
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  all_goals first | exact he | exact hd | rfl


private theorem product_ready (le : CC.TempEnv) (lhs rhs : BitVec 64)
    (entry destination width : CC.Val)
    (he : le.get Arm64Program._entry = some entry)
    (hd : le.get Arm64Program._dst = some destination)
    (hw : le.get Arm64Program.___a64_l_width = some width) :
    (Product.temps le lhs rhs).get Arm64Program._entry = some entry ∧
    (Product.temps le lhs rhs).get Arm64Program._dst = some destination ∧
    (Product.temps le lhs rhs).get Arm64Program.___a64_l_result__1 = some (.Vlong (lhs * rhs)) ∧
    (Product.temps le lhs rhs).get Arm64Program.___a64_l_width = some width := by
  simp +decide only [Product.temps, CC.PTree.gss, CC.PTree.gso, he, hd, hw, and_self]

/-- The actual W/X generic MUL body, including all3reads, product, real two
scalar stores, writer return and loop exit. Its own caller frame remains live. -/
theorem execute {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i j dst : Fin 31) (lhs rhs : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (writerName : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)))
    (source3 : le.get Arm64Program._src3 = some (.Vlong (255#64)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (Dispatch.flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (12#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint 0)) :
    ∃ after, Arm64RegisterWrite.Result storage dst (lhs * rhs) narrow after ∧
      InternalRun Arm64ProgramEntryLinked.ge 435
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le memory)
        (.State Arm64Nop.handler .Sskip k e (finalTemps le narrow lhs rhs) after) := by
  have readRun := Prefix.body_operands storage i j lhs rhs e le k narrow widthName readName
    entryRead source source2 source3 flags op lhsWord lhsTag rhsWord rhsTag
  have ready := operands_ready le narrow lhs rhs (.Vptr entry.block 0)
    (.Vlong (BitVec.ofNat 64 dst.val)) entryRead destination
  have product := Product.evaluate Arm64ProgramEntryLinked.ge e (Prefix.finalTemps le narrow lhs rhs)
    memory (Dispatch.continuation k) lhs rhs ready.1 ready.2.1 ready.2.2.1
  have writerReady := product_ready (Prefix.finalTemps le narrow lhs rhs) lhs rhs (.Vptr entry.block 0)
    (.Vlong (BitVec.ofNat 64 dst.val)) (Arm64RegisterWrite.width narrow)
    ready.2.2.2.1 ready.2.2.2.2.1 ready.2.2.2.2.2
  obtain ⟨after, result, write⟩ := scalar_write storage dst (lhs * rhs) narrow e
    (finalTemps le narrow lhs rhs) (Dispatch.continuation k) writerName
    writerReady.1 writerReady.2.1 writerReady.2.2.1 writerReady.2.2.2
  have leave := leave_loop Arm64ProgramEntryLinked.ge e (finalTemps le narrow lhs rhs) after k
  exact ⟨after, result, ((readRun.trans product).trans write).trans leave⟩

end KProgFormal.ClightRefinement.Arm64Mul.Body
