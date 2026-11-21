import KProgFormal.ClightRefinement.X86ShiftFlagZF

namespace KProgFormal.ClightRefinement.X86ShiftFlagSF

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_sf
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  store : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftFlagZF.rest with
  | .Ssequence store rest => ⟨store, rest⟩
  | _ => ⟨.Sskip, .Sskip⟩

def sf : CC.Stmt := by run_tac cachePart (← `(pieces.store))
def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- The SF store and following CF/OF code are the original source sequence. -/
theorem source : X86ShiftFlagZF.rest = .Ssequence sf rest := rfl

private def fieldMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The actual source member list places the SF pointer after CF and ZF. -/
theorem sf_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._sf X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (136, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._sf fieldMembers = .OK (136, .Full)
  have size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  simp +decide [fieldMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr,
    CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, size, align]

def bit (value signValue : BitVec 64) : CC.Val :=
  .Vint (if value &&& signValue = 0 then 0 else 1)

def afterTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'220 (.Vptr block offset)

private theorem mask_zero (value : BitVec 64) (i : Nat) (bound : i < 64) :
    value &&& ((1#64) <<< i) = 0 ↔ value.getLsbD i = false := by
  constructor
  · intro equal
    have atBit := congrArg (fun v : BitVec 64 => v.getLsbD i) equal
    simpa [BitVec.getLsbD_and, BitVec.getLsbD_shiftLeft, bound] using atBit
  · intro bitZero
    apply BitVec.eq_of_getLsbD_eq_iff.mpr
    intro j hj
    by_cases same : j = i
    · subst j
      simp [  bound]
      simpa only [← BitVec.getLsbD_eq_getElem] using bitZero
    · by_cases lower : j < i
      · simp [BitVec.getLsbD_and, BitVec.getLsbD_shiftLeft, lower]
      · have difference : j - i ≠ 0 := by omega
        simp [BitVec.getLsbD_and, BitVec.getLsbD_shiftLeft, lower, difference]

/-- The source sign-mask test equals the mature ISA SF for every undefined-flag oracle choice. -/
theorem native_value (size : X86.Size) (lhs value : BitVec 64) (n : Nat)
    (cfU ofU afU : Bool) (before : X86.Flags) :
    bit value ((1#64) <<< (size.bits - 1)) =
      .Vint (if (X86.Flags.shiftFlags .shl size lhs value n cfU ofU afU before).sf then 1 else 0) := by
  change bit value ((1#64) <<< (size.bits - 1)) =
    .Vint (if X86.Value.msb size value then 1 else 0)
  have bound : size.bits - 1 < 64 := by cases size <;> decide
  have index : size.bits - 1 = size.signBit := by cases size <;> rfl
  have zeroIff : value &&& ((1#64) <<< (size.bits - 1)) = 0 ↔
      X86.Value.msb size value = false := by
    simpa only [X86.Value.msb, index] using mask_zero value (size.bits - 1) bound
  cases observed : X86.Value.msb size value with
  | false =>
      have zero := zeroIff.mpr observed
      simp [bit, zero]
  | true =>
      have nonzero : value &&& ((1#64) <<< (size.bits - 1)) ≠ 0 := by
        intro zero
        have impossible := zeroIff.mp zero
        rw [observed] at impossible
        cases impossible
      simp [bit]
      exact nonzero

private def pointerExpr : CC.Expr := by
  run_tac cachePart (← `(match sf with
    | .Ssequence (.Sset _ rhs) _ => rhs
    | _ => .Econst_int (0#32) CC.tint))
private def targetExpr : CC.Expr := by
  run_tac cachePart (← `(match sf with
    | .Ssequence _ (.Sassign target _) => target
    | _ => .Econst_int (0#32) CC.tint))
private def valueExpr : CC.Expr := by
  run_tac cachePart (← `(match sf with
    | .Ssequence _ (.Sassign _ rhs) => rhs
    | _ => .Econst_int (0#32) CC.tint))

private theorem sf_source : sf =
    .Ssequence (.Sset X86_program_profile_bpf._t'220 pointerExpr)
      (.Sassign targetExpr valueExpr) := rfl

/-- The actual SF pointer read and byte store execute with the original current-heap operations. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock sfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value signValue : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (sign : le.get X86_program_profile_bpf.___x86_sh_sign = some (.Vlong signValue))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value signValue) = some after) :
    InternalRun ge 4 (.State function sf k e le m)
      (.State function .Sskip k e (afterTemps le sfBlock offset) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._sf (.Vptr bindingBlock 0) = some (bindingBlock, 136, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, sf_offset ge.genv_cenv valueLayout]
    rfl
  have unsigned136 : CC.Integers.Ptrofs.unsigned (136 : CC.Integers.Ptrofs) = 136 := rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerRead : CC.doEvalExpr ge e le m pointerExpr = some (.Vptr sfBlock offset) := by
    simp only [pointerExpr, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      structAccess, ptrAccess, CC.Mem.loadv, binding, address, unsigned136, pointer]
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have valueType : CC.typeof valueExpr = CC.tint := rfl
  have targetLoc : CC.doEvalLvalue ge e (afterTemps le sfBlock offset) m targetExpr =
      some (sfBlock, offset, .Full) := by
    simp only [targetExpr, CC.doEvalLvalue, CC.doEvalExpr, afterTemps, CC.PTree.gss]
  have keptResult : (afterTemps le sfBlock offset).get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong value) := by
    simp +decide [afterTemps, CC.PTree.gso, result]
  have keptSign : (afterTemps le sfBlock offset).get X86_program_profile_bpf.___x86_sh_sign =
      some (.Vlong signValue) := by
    simp +decide [afterTemps, CC.PTree.gso, sign]
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) =
      (0 : BitVec 64) := rfl
  have evaluated : CC.doEvalExpr ge e (afterTemps le sfBlock offset) m valueExpr =
      some (bit value signValue) := by
    by_cases zero : value &&& signValue = 0
    all_goals
      simp +decide [valueExpr, CC.doEvalExpr, CC.typeof, keptResult, keptSign,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Integers.Int64.and, CC.Integers.MI.and, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
         CC.Cop.castIntLong, CC.tulong, CC.tint, CC.typeconv,
        CC.removeAttributes, CC.tattr, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
         CC.Integers.MI.eq, CC.Integers.Int.repr,
        CC.Integers.Int64.repr, CC.Integers.MI.repr, CC.Integers.MI.zero,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.zero,
        CC.Integers.Int.one, CC.Integers.MI.one, signedZero64, bit, zero, apply_ite]
  have byteCast : CC.Cop.semCast (bit value signValue) CC.tint CC.tuchar m = some (bit value signValue) := by
    unfold bit
    split <;> rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tuchar m sfBlock offset .Full (bit value signValue) =
      some after := by
    simp only [CC.doAssignLoc, charAccess, CC.Mem.storev, stored]
  dsimp only [afterTemps] at targetLoc evaluated
  rw [sf_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, pointerRead, targetLoc,
      targetType, valueType, evaluated, byteCast, assignment, afterTemps,
      CC.Eapp, CC.E0, List.nil_append, true_and]




/-- The original SF source sequence executes its pointer/byte store and reaches
the original CF/OF remainder in the exact updated heap. -/
theorem to_remaining_flags (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock sfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value signValue : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (sign : le.get X86_program_profile_bpf.___x86_sh_sign = some (.Vlong signValue))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value signValue) = some after) :
    InternalRun ge 6 (.State function X86ShiftFlagZF.rest k e le m)
      (.State function rest k e (afterTemps le sfBlock offset) after) := by
  have first : InternalRun ge 1 (.State function X86ShiftFlagZF.rest k e le m)
      (.State function sf (.Kseq rest k) e le m) := by
    rw [source]
    exact .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have wrote := internal ge bindingsLayout valueLayout function e le (.Kseq rest k) m after
    bindingBlock sfBlock offset value signValue binding result sign pointer stored
  have finish : InternalRun ge 1
      (.State function .Sskip (.Kseq rest k) e (afterTemps le sfBlock offset) after)
      (.State function rest k e (afterTemps le sfBlock offset) after) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (first.trans wrote).trans finish

/-- The actual relational SF execution retains caller locals and its original continuation. -/
theorem returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock sfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value signValue : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (sign : le.get X86_program_profile_bpf.___x86_sh_sign = some (.Vlong signValue))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value signValue) = some after) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftFlagZF.rest k e le m) CC.E0
      (.State function rest k e (afterTemps le sfBlock offset) after) :=
  (to_remaining_flags ge bindingsLayout valueLayout function e le k m after bindingBlock sfBlock
    offset value signValue binding result sign pointer stored).sound

/-- The sole pointer temporary reads back exactly; all other temporaries retain their input values. -/
theorem temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    (afterTemps le block offset).get X86_program_profile_bpf._t'220 = some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'220 →
      (afterTemps le block offset).get id = le.get id := by
  refine ⟨by simp [afterTemps], ?_⟩
  intro id different
  simp [afterTemps, CC.PTree.gso, Ne.symm different]


/-- The universal original nonzero SHL route executes both genuine ZF and SF stores,
deriving every intermediate observation and retaining the second store's exact heap. -/
theorem route_to_remaining_flags (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8)
    (heapBinding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (byte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (old.setWidth 32)))
    (effectiveBlock bitsBlock maskBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (maskBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some maskBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv maskBlock = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (widthsUnshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none ∧
      e.get X86_program_profile_bpf._x86_width_mask = none)
    (countBlock : CC.Block)
    (countBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some countBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv countBlock =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (countUnshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (nonzero : X86.Flags.shiftCount size (rhs.setWidth 8) ≠ 0)
    (zfBlock : CC.Block) (zfOffset : CC.Integers.Ptrofs) (middle : CC.Mem)
    (zfPointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock zfOffset))
    (zfStored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned zfOffset)
      (X86ShiftFlagZF.bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8)))) = some middle)
    (sfBlock : CC.Block) (sfOffset : CC.Integers.Ptrofs) (after : CC.Mem)
    (sfPointer : CC.Mem.load CC.Mptr middle bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (sfStored : CC.Mem.store .Mint8unsigned middle sfBlock (CC.Integers.Ptrofs.unsigned sfOffset)
      (bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) ((1#64) <<< (size.bits - 1))) = some after) :
    InternalRun ge ((((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) +
      X86ShiftFlagWidths.length size) + 25) + 10) + 6)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function rest (X86ShiftFlagZF.continuation
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) e
        (afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset)
          sfBlock sfOffset) after) := by
  have routed := X86ShiftFlagZF.route_to_remaining_flags ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed nonzero zfBlock zfOffset middle zfPointer zfStored
  let prepared := X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size
  let reached := X86ShiftFlagZF.afterTemps prepared zfBlock zfOffset
  let resultBits := X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    dsimp only [reached]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    dsimp only [prepared]
    rw [X86ShiftFlagInputs.frame _ lhs rhs _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).2.2
      _ (by decide +kernel) (by decide +kernel)]
    exact heapBinding
  have values := X86ShiftFlagInputs.temps
    (X86ShiftFlagWidths.afterTemps
      (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) cfBlock offset old)) size)
      lhs rhs resultBits size
  have keptResult : reached.get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong resultBits) := by
    dsimp only [reached]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    simpa only [resultBits, X86.Value.trunc_trunc] using values.2.1
  have keptSign : reached.get X86_program_profile_bpf.___x86_sh_sign =
      some (.Vlong ((1#64) <<< (size.bits - 1))) := by
    dsimp only [reached]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    exact values.2.2.2.2.1
  have wrote := to_remaining_flags ge bindingsLayout valueLayout function e reached
    (X86ShiftFlagZF.continuation
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) middle after bindingBlock sfBlock sfOffset resultBits ((1#64) <<< (size.bits - 1))
      keptBinding keptResult keptSign sfPointer sfStored
  exact routed.trans wrote

end KProgFormal.ClightRefinement.X86ShiftFlagSF
