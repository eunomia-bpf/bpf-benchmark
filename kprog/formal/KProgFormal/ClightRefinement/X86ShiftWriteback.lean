import KProgFormal.ClightRefinement.X86ShiftFlagPF

namespace KProgFormal.ClightRefinement.X86ShiftWriteback

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_writer_exit
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def widthBody : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftFlagWidths.continuation .Kstop with
    | .Kloop1 body _ _ => body | _ => .Sskip))
private def widthTail : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftFlagWidths.continuation .Kstop with
    | .Kloop1 _ _ (.Kseq _ (.Kseq tail _)) => tail | _ => .Sskip))
private def flagBody : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftLeftCarry.continuation .Kstop with
    | .Kloop1 body _ _ => body | _ => .Sskip))
def writer : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftLeftCarry.continuation .Kstop with
    | .Kloop1 _ _ (.Kseq writer _) => writer | _ => .Sskip))

/-- The width-loop exit, selected-case break and flag-loop exit are original source. -/
theorem continuation_source (k : CC.Cont) :
    X86ShiftFlagWidths.continuation k =
      .Kloop1 widthBody .Sbreak (.Kseq .Sbreak (.Kseq widthTail k)) ∧
    X86ShiftLeftCarry.continuation k =
      .Kloop1 flagBody .Sbreak (.Kseq writer k) := by
  constructor <;> rfl

/-- Eight genuine skip/break transitions leave the original nested loops and switch,
reaching the unchanged writer with the whole heap, locals and temporaries preserved. -/
theorem resume_writer (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 8
      (.State function .Sskip
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) e le m)
      (.State function writer k e le m) := by
  rw [(continuation_source (.Kswitch (X86ShiftLeftCarry.continuation k))).1,
    (continuation_source k).2]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0,
      List.nil_append, true_and]

private theorem count_bound (rhs : BitVec 64) (size : X86.Size) :
    X86.Flags.shiftCount size (rhs.setWidth 8) < 64 := by
  cases size <;> simp only [X86.Flags.shiftCount] <;> omega

/-- Every positive-count original SHL dispatch completes all five flag stages,
then reaches its actual writer through the genuine enclosing loop/switch exits. -/
theorem route_to_writer (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
    (sfBlock : CC.Block) (sfOffset : CC.Integers.Ptrofs) (sfHeap : CC.Mem)
    (sfPointer : CC.Mem.load CC.Mptr middle bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (sfStored : CC.Mem.store .Mint8unsigned middle sfBlock (CC.Integers.Ptrofs.unsigned sfOffset)
      (X86ShiftFlagSF.bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) ((1#64) <<< (size.bits - 1))) = some sfHeap)
    (writeBlock : CC.Block) (writeOffset : CC.Integers.Ptrofs) (cfHeap : CC.Mem)
    (cfPointer : CC.Mem.load CC.Mptr sfHeap bindingBlock 120 = some (.Vptr writeBlock writeOffset))
    (cfStored : CC.Mem.store .Mint8unsigned sfHeap writeBlock (CC.Integers.Ptrofs.unsigned writeOffset)
      (X86ShiftFlagCF.byte (X86ShiftFlagCF.payload (X86.Value.trunc size lhs) size.bits (X86.Flags.shiftCount size (rhs.setWidth 8)))) = some cfHeap)
    (ofBlock readSFBlock readCFBlock : CC.Block)
    (ofOffset readSFOffset readCFOffset : CC.Integers.Ptrofs) (sf cf : Bool) (after : CC.Mem)
    (ofPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 144 = some (.Vptr ofBlock ofOffset))
    (readSFPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 136 = some (.Vptr readSFBlock readSFOffset))
    (readCFPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 120 = some (.Vptr readCFBlock readCFOffset))
    (readSFByte : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load .Mint8unsigned cfHeap readSFBlock (CC.Integers.Ptrofs.unsigned readSFOffset) = some (X86ShiftFlagOF.flag sf))
    (readCFByte : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load .Mint8unsigned cfHeap readCFBlock (CC.Integers.Ptrofs.unsigned readCFOffset) = some (X86ShiftFlagOF.flag cf))
    (ofStored : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.store .Mint8unsigned cfHeap ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
        (X86ShiftFlagOF.xorValue sf cf) = some after)
    (pfBlock : CC.Block) (pfOffset : CC.Integers.Ptrofs) (pfHeap : CC.Mem)
    (pfPointer : CC.Mem.load CC.Mptr (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap) bindingBlock 152 = some (.Vptr pfBlock pfOffset))
    (pfStored : CC.Mem.store .Mint8unsigned (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap) pfBlock
      (CC.Integers.Ptrofs.unsigned pfOffset) (X86ShiftFlagPF.bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8)))) = some pfHeap) :
    InternalRun ge ((((((((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) + X86ShiftFlagWidths.length size) + 25) + 10) + 6) + 11) + (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then 17 else 1)) + 17) + 8)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function writer k e
        (X86ShiftFlagPF.afterTemps (X86ShiftFlagPF.selectedTemps (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then
          X86ShiftFlagOF.afterTemps (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset) (.Vptr ofBlock ofOffset)
            (.Vptr readSFBlock readSFOffset) (.Vptr readCFBlock readCFOffset) sf cf
        else (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset))) pfBlock pfOffset) pfHeap) := by
  have routed := X86ShiftFlagPF.route_through_parity ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed nonzero zfBlock zfOffset middle zfPointer zfStored
    sfBlock sfOffset sfHeap sfPointer sfStored writeBlock writeOffset cfHeap cfPointer cfStored
    ofBlock readSFBlock readCFBlock ofOffset readSFOffset readCFOffset sf cf after
    ofPointer readSFPointer readCFPointer readSFByte readCFByte ofStored
    pfBlock pfOffset pfHeap pfPointer pfStored
  have resumed := resume_writer ge function e
    (X86ShiftFlagPF.afterTemps (X86ShiftFlagPF.selectedTemps (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then
          X86ShiftFlagOF.afterTemps (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset) (.Vptr ofBlock ofOffset)
            (.Vptr readSFBlock readSFOffset) (.Vptr readCFBlock readCFOffset) sf cf
        else (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset))) pfBlock pfOffset) k pfHeap
  exact routed.trans resumed

/-- Every effective-count-zero original SHL route reaches the same actual writer,
retaining its complete heap and original flag bytes through the genuine exits. -/
theorem route_zero_to_writer (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
    (zero : X86.Flags.shiftCount size (rhs.setWidth 8) = 0) :
    InternalRun ge ((((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) +
      X86ShiftFlagWidths.length size) + 25) + 11) + 8)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function writer k e
        ((X86ShiftFlagInputs.afterTemps (X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size).set X86_program_profile_bpf._t'70 (.Vint (0#32))) m) := by
  have routed := X86ShiftFlagInputs.route_zero_flags ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed zero
  have resumed := resume_writer ge function e
    ((X86ShiftFlagInputs.afterTemps (X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size).set X86_program_profile_bpf._t'70 (.Vint (0#32))) k m
  exact routed.trans resumed

/-- The source scalar result at effective count zero is the original width view. -/
theorem zero_value (lhs rhs : BitVec 64) (size : X86.Size)
    (zero : X86.Flags.shiftCount size (rhs.setWidth 8) = 0) :
    X86ShiftLeft.result lhs rhs size = .Vlong (X86.Value.trunc size lhs) := by
  simp [X86ShiftLeft.result, zero, X86.Value.trunc_trunc]


private structure WriterPieces where
  probe : CC.Stmt
  gate : CC.Expr
  fast : CC.Stmt
  scalar : CC.Stmt

private def writerPieces : WriterPieces :=
  match writer with
  | .Ssequence probe (.Sifthenelse gate fast scalar) => ⟨probe, gate, fast, scalar⟩
  | _ => ⟨.Sskip, .Econst_int (0#32) CC.tint, .Sskip, .Sskip⟩

private def probe : CC.Stmt := by run_tac cachePart (← `(writerPieces.probe))
private def gate : CC.Expr := by run_tac cachePart (← `(writerPieces.gate))
private def fast : CC.Stmt := by run_tac cachePart (← `(writerPieces.fast))
def scalarWriter : CC.Stmt := by run_tac cachePart (← `(writerPieces.scalar))

/-- The original writer contains its actual stack-ADD/SUB selector and general arm. -/
theorem writer_source : writer = .Ssequence probe (.Sifthenelse gate fast scalarWriter) := rfl

def stackWidth (dst : BitVec 8) (size : X86.Size) : Bool :=
  (dst.setWidth 32 == (4#32)) && (size.bytes == 8)

def selectLength (dst : BitVec 8) (size : X86.Size) : Nat :=
  if stackWidth dst size then 13 else 9

def selectTemps (le : CC.TempEnv) (dst : BitVec 8) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'139
    (.Vint (if stackWidth dst size then 1 else 0))).set
    X86_program_profile_bpf._t'140 (.Vint (0#32))

private theorem set_twice (id : CC.Ident) (value : CC.Val) (le : CC.TempEnv) :
    (le.set id value).set id value = le.set id value := by
  induction id generalizing le with
  | xH => cases le <;> rfl
  | xO id ih => cases le <;> simp [CC.PTree.set, ih]
  | xI id ih => cases le <;> simp [CC.PTree.set, ih]

/-- Every SHL destination and width follows the actual general writer arm,
retaining the whole heap and deriving the exact two selector temporaries. -/
theorem select_scalar (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst : BitVec 8) (size : X86.Size)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge (selectLength dst size) (.State function writer k e le m)
      (.State function scalarWriter k e (selectTemps le dst size) m) := by
  rw [writer_source]
  cases size <;> by_cases stack : dst.setWidth 32 = (4#32)
  all_goals
    simp +decide only [selectLength, stackWidth, X86.Size.bytes, stack, beq_self_eq_true,
      ite_true, ite_false, Bool.true_and]
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, probe, gate, selectTemps,
      stackWidth, X86.Size.bytes, stack, CC.doStep, CC.doEvalExpr, CC.typeof,
      CC.PTree.gso, destination, width, alu, X86ShiftLeft.argument,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
      CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Eapp, CC.E0, set_twice]

/-- Each selector temporary reads back its source value and all other temporaries are framed. -/
theorem select_temps (le : CC.TempEnv) (dst : BitVec 8) (size : X86.Size) :
    (selectTemps le dst size).get X86_program_profile_bpf._t'139 =
      some (.Vint (if stackWidth dst size then 1 else 0)) ∧
    (selectTemps le dst size).get X86_program_profile_bpf._t'140 = some (.Vint (0#32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'139 → id ≠ X86_program_profile_bpf._t'140 →
      (selectTemps le dst size).get id = le.get id := by
  refine ⟨by simp +decide [selectTemps, CC.PTree.gso], by simp [selectTemps], ?_⟩
  intro id ne139 ne140
  simp [selectTemps, CC.PTree.gso, Ne.symm ne139, Ne.symm ne140]

end KProgFormal.ClightRefinement.X86ShiftWriteback
