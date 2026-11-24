import KProgFormal.ClightRefinement.X86WordMemory
import KProgFormal.ClightRefinement.X86FullWidthStorage

namespace KProgFormal.ClightRefinement.X86WordStorage

private structure Pieces where
  first : CC.Stmt
  test : CC.Expr
  word : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 with
  | .Ssequence first (.Sifthenelse test word rest) => ⟨first, test, word, rest⟩
  | _ => ⟨.Sskip, .Econst_int 0 CC.tint, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_word_storage_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def first : CC.Stmt := by run_tac cachePart (← `(pieces.first))
private def test : CC.Expr := by run_tac cachePart (← `(pieces.test))
def word : CC.Stmt := by run_tac cachePart (← `(pieces.word))
private def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- The word leaf is selected from the original handler's complete branch. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 =
    .Ssequence first (.Sifthenelse test word rest) := rfl

private theorem set_twice (id : CC.Ident) (value : CC.Val) (le : CC.TempEnv) :
    (le.set id value).set id value = le.set id value := by
  induction id generalizing le with
  | xH => cases le <;> rfl
  | xO id ih => cases le <;> simp [CC.PTree.set, ih]
  | xI id ih => cases le <;> simp [CC.PTree.set, ih]

def selectionTemps (le : CC.TempEnv) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'111 (.Vint (1#32))

/-- The actual first width classifier selects low16 storage in nine steps. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument .w)) :
    InternalRun ge 9
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 k e le memory)
      (.State function word k e (selectionTemps le) memory) := by
  rw [source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep,
    first, test, selectionTemps, CC.doEvalExpr, CC.typeof, width,
    X86ShiftLeft.argument, X86.Size.bytes, CC.PTree.gss, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.Integers.Int.eq, CC.Integers.MI.eq,
    CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Eapp, CC.E0, set_twice]

private def prelude : CC.Stmt := by
  run_tac cachePart (← `(match word with | .Ssequence prelude _ => prelude | _ => .Sskip))
private def body : CC.Stmt := by
  run_tac cachePart (← `(match word with | .Ssequence _ (.Sloop body _) => body | _ => .Sskip))
private def laneSet : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence lane _ => lane | _ => .Sskip))
private def choice : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence choice _) => choice | _ => .Sskip))
private def tagSet : CC.Stmt := by
  run_tac cachePart (← `(match body with | .Ssequence _ (.Ssequence _ tag) => tag | _ => .Sskip))
private def scalar : CC.Stmt := by
  run_tac cachePart (← `(match choice with | .Sifthenelse _ scalar _ => scalar | _ => .Sskip))

theorem word_source : word =
    .Ssequence prelude (.Sloop (.Ssequence laneSet (.Ssequence choice tagSet)) .Sbreak) := rfl

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

def laneTemps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___kprog_x86_lane__5 (.Vint (X86WordMemory.lane next))

def temps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  (laneTemps le next).set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))

private theorem cast_lane (next : BitVec 64) :
    next.setWidth 32 &&& (65535#32) = (next.setWidth 16).setWidth 32 := by
  have mask : (65535#32) = (BitVec.allOnes 16).setWidth 32 := by decide
  rw [mask]
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_setWidth, BitVec.getLsbD_allOnes]
  simp [hi, Bool.and_comm]

/-- Execute the real ordinary/scalar prelude, lane cast and tag branch. -/
theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (dst : BitVec 8) (next : BitVec 64)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next)) :
    InternalRun ge 10
      (.State function word k e le memory)
      (.State function scalar (.Kseq tagSet (loopCont k)) e (laneTemps le next) memory) := by
  rw [word_source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, prelude, laneSet, choice,
    loopCont, body, scalar, tagSet, laneTemps, X86WordMemory.lane,
    CC.doStep, CC.doEvalExpr, CC.typeof, destination, ordinary, tag, value, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
    CC.tattr, CC.tuchar, CC.tushort, CC.tuint, CC.tint, CC.tulong,
    CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
    CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0, cast_lane]

private def gprMembers : List CC.Member := by
  run_tac cachePart (← `(X86RegisterLayout.gprRecord.co_members))

/-- The scalar source arm performs exactly its real unsigned16 union-field store. -/
theorem store (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory after : CC.Mem) (block : CC.Block) (next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observed : le.get X86_program_profile_bpf.___kprog_x86_lane__5 =
      some (.Vint (X86WordMemory.lane next)))
    (stored : CC.Mem.store .Mint16unsigned memory block 0
      (.Vint (X86WordMemory.lane next)) = some after) :
    InternalRun ge 1 (.State function scalar k e le memory)
      (.State function .Sskip k e le after) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      some (block, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have fieldOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._w
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._w gprMembers = _
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.tarray,
      CC.tuchar, CC.tushort, CC.noattr]
  have fieldAddress (offset : CC.Integers.Ptrofs) : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._w (.Vptr block offset) = some (block, offset, .Full) := by
    simp only [CC.lvalOfField, gprLayout, fieldOffset]
    change some (block, offset + 0, CC.Bitfield.Full) = some (block, offset, .Full)
    exact congrArg (fun n => some (block, n, CC.Bitfield.Full)) (BitVec.add_zero offset)
  have unionAccess : CC.accessMode (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      .By_copy := rfl
  have wordAccess : CC.accessMode CC.tushort = .By_value .Mint16unsigned := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have laneCast : CC.Cop.semCast (.Vint (X86WordMemory.lane next)) CC.tushort CC.tushort memory =
      some (.Vint (X86WordMemory.lane next)) := by
    simp +decide [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.tushort, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      X86WordMemory.lane, ← cast_lane, BitVec.and_assoc]
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, scalar, CC.doStep, CC.doEvalExpr,
    CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof, localAddress, fieldAddress,
    unionAccess, wordAccess, CC.Mem.storev, observed, stored, laneCast,
    unsigned0, CC.Eapp, CC.E0, true_and, List.nil_append]

/-- The actual tag assignment, break and loop exit preserve the stored memory. -/
theorem exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 4
      (.State function .Sskip (.Kseq tagSet (loopCont k)) e le memory)
      (.State function .Sskip k e
        (le.set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))) memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, tagSet, loopCont, CC.doStep,
    CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tuchar, CC.tuint, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Eapp, CC.E0]

/-- Complete original low16 leaf execution, including its real local store. -/
theorem run (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory after : CC.Mem) (block : CC.Block) (dst : BitVec 8) (next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (stored : CC.Mem.store .Mint16unsigned memory block 0
      (.Vint (X86WordMemory.lane next)) = some after) :
    InternalRun ge 15 (.State function word k e le memory)
      (.State function .Sskip k e (temps le next) after) := by
  have entered := enter ge function e le k memory dst next destination ordinary tag value
  have lane : (laneTemps le next).get X86_program_profile_bpf.___kprog_x86_lane__5 =
      some (.Vint (X86WordMemory.lane next)) := by simp only [laneTemps, CC.PTree.gss]
  exact (entered.trans (store ge gprLayout function e (laneTemps le next)
    (.Kseq tagSet (loopCont k)) memory after block next declared lane stored)).trans
    (exit ge function e (laneTemps le next) k after)

/-- The real initialized local64 cell supplies low16 write permission.
All intermediate stores and observations are constructed from the source
inputs. Readback equals the same ISA writeView and keeps every other block. -/
theorem execute (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before memory : CC.Mem) (block : CC.Block) (dst : BitVec 8) (old next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (block, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (initialized : CC.Mem.store CC.Mptr before block 0 (.Vlong old) = some memory)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 = some (X86ShiftLeft.argument .w))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next)) :
    ∃ after, CC.Mem.store .Mint16unsigned memory block 0
        (.Vint (X86WordMemory.lane next)) = some after ∧
      InternalRun ge 24
        (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106 k e le memory)
        (.State function .Sskip k e (temps (selectionTemps le) next) after) ∧
      CC.Mem.load CC.Mptr after block 0 = some (.Vlong (X86.Value.writeView .w old next)) ∧
      CC.Cop.semCast (.Vlong (X86.Value.writeView .w old next)) (CC.tptr CC.tvoid)
        (CC.tptr CC.tvoid) after = some (.Vlong (X86.Value.writeView .w old next)) ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
      (∀ chunk other offset, other ≠ block →
        CC.Mem.load chunk after other offset = CC.Mem.load chunk memory other offset) := by
  have full : CC.Mem.validAccess memory CC.Mptr block 0 .Writable = true := by
    rw [CC.Mem.validAccess_store_eq initialized]
    exact CC.Mem.store_valid_access initialized
  have parts := full
  simp only [CC.Mem.validAccess, Bool.and_eq_true] at parts
  have range : CC.Mem.rangePerm memory block 0 8 .Cur .Writable = true := parts.1
  have half : CC.Mem.validAccess memory .Mint16unsigned block 0 .Writable = true := by
    change CC.Mem.rangePerm memory block 0 2 .Cur .Writable && (0 % 2 == 0) = true
    rw [Bool.and_eq_true]
    refine ⟨CC.Mem.rangePerm_intro memory block 0 2 .Cur .Writable
      (fun point lo hi => CC.Mem.rangePerm_perm memory block 0 8 .Cur .Writable range point
        lo (by omega)), by decide⟩
  have existsStore : ∃ after, CC.Mem.store .Mint16unsigned memory block 0
      (.Vint (X86WordMemory.lane next)) = some after := by
    simp only [CC.Mem.store, half, ite_true]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have selected := select ge function e le k memory width
  have destinationReady : (selectionTemps le).get X86_program_profile_bpf._dst =
      some (.Vint (dst.setWidth 32)) := by
    simp +decide [selectionTemps, CC.PTree.gso, destination]
  have tagReady : (selectionTemps le).get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (0#32)) := by
    simp +decide [selectionTemps, CC.PTree.gso, tag]
  have valueReady : (selectionTemps le).get X86_program_profile_bpf.___x86_wr_next__2 =
      some (.Vlong next) := by
    simp +decide [selectionTemps, CC.PTree.gso, value]
  have written := run ge gprLayout function e (selectionTemps le) k memory after block dst next
    declared destinationReady ordinary tagReady valueReady stored
  have readback := X86WordMemory.load before memory after block old next initialized stored
  refine ⟨after, stored, selected.trans written, ?_, ?_, CC.Mem.store_access stored,
    CC.Mem.store_nextblock stored, ?_⟩
  · simpa only [X86WordMemory.native] using readback.1
  · simpa only [X86WordMemory.native] using readback.2
  · intro chunk other offset different
    exact CC.Mem.load_store_other stored chunk other offset (.inl different)

end KProgFormal.ClightRefinement.X86WordStorage
