import CCLib.MemoryLemmas
import KProgFormal.ClightRefinement.X86ShiftFlagPF
import KProgFormal.ClightRefinement.X86RegisterLayout

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


private def dstPieces : WriterPieces :=
  match scalarWriter with
  | .Ssequence probe (.Sifthenelse gate fast scalar) => ⟨probe, gate, fast, scalar⟩
  | _ => ⟨.Sskip, .Econst_int (0#32) CC.tint, .Sskip, .Sskip⟩

private def dstProbe : CC.Stmt := by run_tac cachePart (← `(dstPieces.probe))
private def dstGate : CC.Expr := by run_tac cachePart (← `(dstPieces.gate))
private def dstFast : CC.Stmt := by run_tac cachePart (← `(dstPieces.fast))
def sourceWriter : CC.Stmt := by run_tac cachePart (← `(dstPieces.scalar))

private def srcPieces : WriterPieces :=
  match sourceWriter with
  | .Ssequence probe (.Sifthenelse gate fast scalar) => ⟨probe, gate, fast, scalar⟩
  | _ => ⟨.Sskip, .Econst_int (0#32) CC.tint, .Sskip, .Sskip⟩

private def srcProbe : CC.Stmt := by run_tac cachePart (← `(srcPieces.probe))
private def srcGate : CC.Expr := by run_tac cachePart (← `(srcPieces.gate))
private def srcFast : CC.Stmt := by run_tac cachePart (← `(srcPieces.fast))
def defaultWriter : CC.Stmt := by run_tac cachePart (← `(srcPieces.scalar))

/-- Both pointer selectors and the default register writer are exact original source arms. -/
theorem pointer_source :
    scalarWriter = .Ssequence dstProbe (.Sifthenelse dstGate dstFast sourceWriter) ∧
    sourceWriter = .Ssequence srcProbe (.Sifthenelse srcGate srcFast defaultWriter) := by
  constructor <;> rfl

def narrowDstTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf._t'129 (.Vint (0#32))).set
    X86_program_profile_bpf._t'130 (.Vint (0#32))).set
    X86_program_profile_bpf._t'131 (.Vint (0#32))).set
    X86_program_profile_bpf._t'136 (.Vint (0#32))).set
    X86_program_profile_bpf._t'138 (.Vint (0#32))

def narrowSrcTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf._t'119 (.Vint (0#32))).set
    X86_program_profile_bpf._t'120 (.Vint (0#32))).set
    X86_program_profile_bpf._t'121 (.Vint (0#32))).set
    X86_program_profile_bpf._t'122 (.Vint (0#32))).set
    X86_program_profile_bpf._t'124 (.Vint (0#32))

/-- Every narrow width takes the genuine short-circuit path with exact
selector zeroes and the complete incoming memory preserved. -/
theorem narrow_destination (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (narrow : size ≠ .q)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 21 (.State function scalarWriter k e le m)
      (.State function sourceWriter k e (narrowDstTemps le) m) := by
  rw [pointer_source.1]
  cases size <;> try exact (narrow rfl).elim
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, dstProbe, dstGate, narrowDstTemps,
      CC.doStep, CC.doEvalExpr, CC.typeof, width, X86ShiftLeft.argument, X86.Size.bytes,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vfalse,
      CC.Eapp, CC.E0]

/-- Every narrow width takes the genuine short-circuit path with exact
selector zeroes and the complete incoming memory preserved. -/
theorem narrow_source (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (narrow : size ≠ .q)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 21 (.State function sourceWriter k e le m)
      (.State function defaultWriter k e (narrowSrcTemps le) m) := by
  rw [pointer_source.2]
  cases size <;> try exact (narrow rfl).elim
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, srcProbe, srcGate, narrowSrcTemps,
      CC.doStep, CC.doEvalExpr, CC.typeof, width, X86ShiftLeft.argument, X86.Size.bytes,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vfalse,
      CC.Eapp, CC.E0]

/-- The actual narrow-width pointer selectors compose to the default writer
in forty-two transitions, retaining every incoming byte and local binding. -/
theorem narrow_default (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (narrow : size ≠ .q)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)) :
    InternalRun ge 42 (.State function scalarWriter k e le m)
      (.State function defaultWriter k e (narrowSrcTemps (narrowDstTemps le)) m) := by
  have destination := narrow_destination ge function e le k m size narrow width
  have kept : (narrowDstTemps le).get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    simp +decide [narrowDstTemps, CC.PTree.gso, width]
  have source := narrow_source ge function e (narrowDstTemps le) k m size narrow kept
  exact destination.trans source


/-- Every narrow SHL destination reaches the actual default register writer
through all three original pointer-selection stages in fifty-one silent steps. -/
theorem narrow_writer (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst : BitVec 8) (size : X86.Size)
    (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 51 (.State function writer k e le m)
      (.State function defaultWriter k e
        (narrowSrcTemps (narrowDstTemps (selectTemps le dst size))) m) := by
  have selected := select_scalar ge function e le k m dst size destination width alu
  have length : selectLength dst size = 9 := by
    cases size <;> simp_all [selectLength, stackWidth, X86.Size.bytes]
  rw [length] at selected
  have kept : (selectTemps le dst size).get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    rw [(select_temps le dst size).2.2 _ (by decide +kernel) (by decide +kernel)]
    exact width
  have rest := narrow_default ge function e (selectTemps le dst size) k m size narrow kept
  exact selected.trans rest


private structure LoadPieces where
  body : CC.Stmt
  exit : CC.Stmt
  cells : CC.Stmt
  rsp : CC.Stmt
  save : CC.Stmt
  rest : CC.Stmt

private def loadPieces : LoadPieces :=
  match defaultWriter with
  | .Sloop (.Ssequence (.Ssequence cells (.Ssequence rsp save)) rest) exit =>
      ⟨.Ssequence (.Ssequence cells (.Ssequence rsp save)) rest, exit, cells, rsp, save, rest⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def loadBody : CC.Stmt := by run_tac cachePart (← `(loadPieces.body))
private def loadExit : CC.Stmt := by run_tac cachePart (← `(loadPieces.exit))
private def loadCells : CC.Stmt := by run_tac cachePart (← `(loadPieces.cells))
private def loadRsp : CC.Stmt := by run_tac cachePart (← `(loadPieces.rsp))
private def saveRsp : CC.Stmt := by run_tac cachePart (← `(loadPieces.save))
def widthWriter : CC.Stmt := by run_tac cachePart (← `(loadPieces.rest))

/-- The real default writer enters its original loop, cell-table/RSP reads,
old-SP conversion and following width/value preparation. -/
theorem loads_source : defaultWriter =
    .Sloop (.Ssequence (.Ssequence loadCells (.Ssequence loadRsp saveRsp)) widthWriter) loadExit ∧
    loadBody = .Ssequence (.Ssequence loadCells (.Ssequence loadRsp saveRsp)) widthWriter := by
  constructor <;> rfl

def loadCont (k : CC.Cont) : CC.Cont := .Kloop1 loadBody loadExit k

def loadTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : CC.Val) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'170 (.Vptr block offset)).set
    X86_program_profile_bpf._t'171 value).set
    X86_program_profile_bpf.___x86_write_old_sp__5 value

/-- The original casts retain every actual pointer-valued old SP. -/
theorem old_pointer_cast (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.Cop.semCast (.Vptr block offset) (CC.tptr CC.tvoid) CC.tlong m =
      some (.Vptr block offset) := rfl

/-- The original casts retain every actual 64-bit numeric old SP. -/
theorem old_long_cast (m : CC.Mem) (value : BitVec 64) :
    CC.Cop.semCast (.Vlong value) (CC.tptr CC.tvoid) CC.tlong m =
      some (.Vlong value) := rfl

private def gprMembers : List CC.Member := by
  run_tac cachePart (← `(X86RegisterLayout.gprRecord.co_members))


/-- Ten genuine source transitions read the current cell table and RSP cell,
save the admitted pointer/numeric word and reach the original width preparation. -/
theorem load_prefix (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value) :
    InternalRun ge 10 (.State function defaultWriter k e le m)
      (.State function widthWriter (loadCont k) e (loadTemps le cellsBlock cellsOffset value) m) := by
  have addZero (offset : CC.Integers.Ptrofs) :
      CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset := by
    change offset + 0 = offset
    exact BitVec.add_zero offset
  have tableAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr bindingBlock 0) =
      some (bindingBlock, 0, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86RegisterLayout.cells_offset ge.genv_cenv, addZero]
  have valueAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._value (.Vptr cellsBlock (cellsOffset + 64)) =
      some (cellsBlock, cellsOffset + 64, .Full) := by
    simp only [CC.lvalOfField, cellLayout, X86RegisterLayout.value_offset ge.genv_cenv gprLayout, addZero]
  have ptrOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  have pointerAddress : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr cellsBlock (cellsOffset + 64)) =
      some (cellsBlock, cellsOffset + 64, .Full) := by
    simp only [CC.lvalOfField, gprLayout, ptrOffset, addZero]
  have cellAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr cellsBlock cellsOffset) (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint (CC.Integers.Int.repr 4)) CC.tint m = some (.Vptr cellsBlock (cellsOffset + 64)) := by
    simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint,
      CC.sizeof, cellLayout, X86RegisterLayout.layout.2.2.2.1]
    rfl
  have structAccess (name : CC.Ident) :
      CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have wordCast : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr) CC.tlong m =
      some value := word
  have recast : CC.Cop.semCast value CC.tlong CC.tlong m = some value := word
  rw [loads_source.1]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, loads_source.2, loadCells, loadRsp, saveRsp,
      loadCont, loadTemps, CC.doStep, CC.doEvalExpr, CC.doDerefLoc,
      CC.typeof, CC.tptr, CC.PTree.gss, structAccess, unionAccess, ptrAccess,
      tableAddress, valueAddress, pointerAddress, cellAdd, binding,
      CC.Mem.loadv, unsigned0, cells, rsp, wordCast, recast, CC.Eapp, CC.E0,
      List.nil_append, true_and]

/-- The actual table pointer, loaded RSP word and saved old-SP temporary read back exactly;
every other temporary keeps its incoming value. -/
theorem load_temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : CC.Val) :
    (loadTemps le block offset value).get X86_program_profile_bpf._t'170 =
      some (.Vptr block offset) ∧
    (loadTemps le block offset value).get X86_program_profile_bpf._t'171 = some value ∧
    (loadTemps le block offset value).get X86_program_profile_bpf.___x86_write_old_sp__5 = some value ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'170 → id ≠ X86_program_profile_bpf._t'171 →
      id ≠ X86_program_profile_bpf.___x86_write_old_sp__5 →
      (loadTemps le block offset value).get id = le.get id := by
  refine ⟨by simp +decide [loadTemps, CC.PTree.gso], by simp +decide [loadTemps, CC.PTree.gso],
    by simp [loadTemps], ?_⟩
  intro id ne170 ne171 neOld
  simp [loadTemps, CC.PTree.gso, Ne.symm ne170, Ne.symm ne171, Ne.symm neOld]

/-- The original narrow SHL writer executes all selectors and real pointer reads,
reaching width preparation in sixty-one silent transitions on the same heap. -/
theorem narrow_loaded (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (dst : BitVec 8) (size : X86.Size) (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 61 (.State function writer k e le m)
      (.State function widthWriter (loadCont k) e
        (loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le dst size)))
          cellsBlock cellsOffset value) m) := by
  have selected := narrow_writer ge function e le k m dst size narrow destination width alu
  have keptBinding :
      (narrowSrcTemps (narrowDstTemps (selectTemps le dst size))).get
        X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, binding]
  have loaded := load_prefix ge bindingsLayout gprLayout cellLayout function e
    (narrowSrcTemps (narrowDstTemps (selectTemps le dst size))) k m
    bindingBlock cellsBlock cellsOffset value keptBinding cells rsp word
  exact selected.trans loaded


private structure WidthPieces where
  raw : CC.Stmt
  effective : CC.Stmt
  shift : CC.Stmt
  next : CC.Stmt
  rest : CC.Stmt

private def widthPieces : WidthPieces :=
  match widthWriter with
  | .Ssequence raw (.Ssequence effective (.Ssequence shift (.Ssequence next rest))) =>
      ⟨raw, effective, shift, next, rest⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def writerRaw : CC.Stmt := by run_tac cachePart (← `(widthPieces.raw))
private def writerEffective : CC.Stmt := by run_tac cachePart (← `(widthPieces.effective))
private def writerShift : CC.Stmt := by run_tac cachePart (← `(widthPieces.shift))
private def writerNext : CC.Stmt := by run_tac cachePart (← `(widthPieces.next))
def cellWriter : CC.Stmt := by run_tac cachePart (← `(widthPieces.rest))

/-- The original width/helper/shift/result preparation retains the exact destination-cell suffix. -/
theorem width_source : widthWriter =
    .Ssequence writerRaw (.Ssequence writerEffective
      (.Ssequence writerShift (.Ssequence writerNext cellWriter))) := rfl

def writerRawTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___x86_wr_raw_width__2 (X86ShiftLeft.argument size)

def writerEffectiveTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'105 (X86ShiftLeft.argument size)).set
    X86_program_profile_bpf.___x86_wr_width__2 (X86ShiftLeft.argument size)

def writerWidthTemps (le : CC.TempEnv) (size : X86.Size) (shift : BitVec 8)
    (value : BitVec 64) : CC.TempEnv :=
  ((writerEffectiveTemps (writerRawTemps le size) size).set
    X86_program_profile_bpf.___x86_wr_shift__2 (.Vint (shift.setWidth 32))).set
    X86_program_profile_bpf.___x86_wr_next__2 (.Vlong value)

/-- Four real source transitions record the input width and reach its actual helper call. -/
theorem width_enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size)) :
    InternalRun ge 4 (.State function widthWriter k e le m)
      (.State function writerEffective
        (.Kseq (.Ssequence writerShift (.Ssequence writerNext cellWriter)) k) e
        (writerRawTemps le size) m) := by
  rw [width_source]
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, writerRaw, writerRawTemps,
      CC.doStep, CC.doEvalExpr, CC.typeof, width, X86ShiftLeft.argument, X86.Size.bytes,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Eapp, CC.E0]

private def writerEffectiveAssign : CC.Stmt := by
  run_tac cachePart (← `(match writerEffective with | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem writer_effective_plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_wr_raw_width__2 = some (X86ShiftLeft.argument size)) :
    ∃ callK, InternalRun ge 2 (.State function writerEffective k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [X86ShiftLeft.argument size] callK m) ∧
    InternalRun ge 3 (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m)
      (.State function .Sskip k e (writerEffectiveTemps le size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_width_effective) =
      .Tfunction [CC.tuchar] CC.tuchar CC.cc_default := rfl
  refine ⟨.Kcall (some X86_program_profile_bpf._t'105) function e le
    (.Kseq writerEffectiveAssign k), ?beforeCall, ?afterCall⟩
  case beforeCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, writerEffective, writerEffectiveAssign, CC.typeof,   CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
      CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
      unshadowed, observed, symbol, callee,  X86ShiftLeft.argument,
      X86.Size.bytes, CC.Eapp, CC.E0]
  case afterCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, writerEffectiveTemps, writerEffectiveAssign, CC.doStep, CC.doEvalExpr,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.typeof,
        CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.callCont, CC.setOpttemp, X86ShiftLeft.argument,
        X86.Size.bytes,   CC.Eapp, CC.E0]

/-- The actual effective-width call and caller assignments return the mature ISA value. -/
theorem width_effective (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block = some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (observed : le.get X86_program_profile_bpf.___x86_wr_raw_width__2 = some (X86ShiftLeft.argument size)) :
    InternalRun ge (2 + (6) + 3) (.State function writerEffective k e le m)
      (.State function .Sskip k e (writerEffectiveTemps le size) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    writer_effective_plumbing ge block binding function e le unshadowed size k m observed
  have value : X86Width.result (BitVec.ofNat 8 size.bytes) = (X86ShiftLeft.argument size) := by cases size <;> rfl
  have argument : X86Width.argument (BitVec.ofNat 8 size.bytes) =
      X86ShiftLeft.argument size := by cases size <;> rfl
  have body : InternalRun ge (6)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [X86ShiftLeft.argument size] callK m)
      (.Returnstate (X86ShiftLeft.argument size) (CC.callCont callK) m) := by
    simpa only [argument, value] using
      X86Width.internal ge (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans body).trans afterCall


private theorem writer_byte_cast (value : BitVec 8) :
    value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- Seven actual caller transitions resume the width call and copy the byte shift
and complete result word into the original writer temporaries. -/
theorem width_tail (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (shift : BitVec 8) (value : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value)) :
    InternalRun ge 7
      (.State function .Sskip
        (.Kseq (.Ssequence writerShift (.Ssequence writerNext cellWriter)) k) e le m)
      (.State function cellWriter k e
        ((le.set X86_program_profile_bpf.___x86_wr_shift__2 (.Vint (shift.setWidth 32))).set
          X86_program_profile_bpf.___x86_wr_next__2 (.Vlong value)) m) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, writerShift, writerNext,
      CC.doStep, CC.doEvalExpr, CC.typeof, observedShift, observedValue, CC.PTree.gso,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, writer_byte_cast, CC.Eapp, CC.E0]

/-- Twenty-two genuine writer transitions call the actual width helper, retain
the whole heap and prepare the original destination-cell read and initializer. -/
theorem width_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (size : X86.Size) (shift : BitVec 8) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value)) :
    InternalRun ge 22 (.State function widthWriter k e le m)
      (.State function cellWriter k e (writerWidthTemps le size shift value) m) := by
  have entered := width_enter ge function e le k m size width
  have raw : (writerRawTemps le size).get X86_program_profile_bpf.___x86_wr_raw_width__2 =
      some (X86ShiftLeft.argument size) := by simp [writerRawTemps]
  have called := width_effective ge block binding function e (writerRawTemps le size) unshadowed
    size (.Kseq (.Ssequence writerShift (.Ssequence writerNext cellWriter)) k) m raw
  have keptShift :
      (writerEffectiveTemps (writerRawTemps le size) size).get X86_program_profile_bpf.___x86_l_dst_shift =
        some (.Vint (shift.setWidth 32)) := by
    simp +decide [writerEffectiveTemps, writerRawTemps, CC.PTree.gso, observedShift]
  have keptValue :
      (writerEffectiveTemps (writerRawTemps le size) size).get X86_program_profile_bpf.___x86_l_result =
        some (.Vlong value) := by
    simp +decide [writerEffectiveTemps, writerRawTemps, CC.PTree.gso, observedValue]
  have copied := width_tail ge function e (writerEffectiveTemps (writerRawTemps le size) size)
    k m shift value keptShift keptValue
  exact (entered.trans called).trans copied


/-- The actual raw width, call temporary, effective width, shift and result all
read back their exact source values; every other temporary keeps its input. -/
theorem width_temps (le : CC.TempEnv) (size : X86.Size) (shift : BitVec 8) (value : BitVec 64) :
    (writerWidthTemps le size shift value).get X86_program_profile_bpf.___x86_wr_raw_width__2 =
      some (X86ShiftLeft.argument size) ∧
    (writerWidthTemps le size shift value).get X86_program_profile_bpf._t'105 =
      some (X86ShiftLeft.argument size) ∧
    (writerWidthTemps le size shift value).get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument size) ∧
    (writerWidthTemps le size shift value).get X86_program_profile_bpf.___x86_wr_shift__2 =
      some (.Vint (shift.setWidth 32)) ∧
    (writerWidthTemps le size shift value).get X86_program_profile_bpf.___x86_wr_next__2 =
      some (.Vlong value) ∧
    ∀ id, id ≠ X86_program_profile_bpf.___x86_wr_raw_width__2 →
      id ≠ X86_program_profile_bpf._t'105 → id ≠ X86_program_profile_bpf.___x86_wr_width__2 →
      id ≠ X86_program_profile_bpf.___x86_wr_shift__2 → id ≠ X86_program_profile_bpf.___x86_wr_next__2 →
      (writerWidthTemps le size shift value).get id = le.get id := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  · simp +decide [writerWidthTemps, writerRawTemps, writerEffectiveTemps, CC.PTree.gso]
  · simp +decide [writerWidthTemps, writerRawTemps, writerEffectiveTemps, CC.PTree.gso]
  · simp +decide [writerWidthTemps, writerRawTemps, writerEffectiveTemps, CC.PTree.gso]
  · simp +decide [writerWidthTemps, writerRawTemps, writerEffectiveTemps, CC.PTree.gso]
  · simp [writerWidthTemps]
  · intro id neRaw neCall neWidth neShift neValue
    simp [writerWidthTemps, writerRawTemps, writerEffectiveTemps, CC.PTree.gso,
      Ne.symm neRaw, Ne.symm neCall, Ne.symm neWidth, Ne.symm neShift, Ne.symm neValue]

/-- The original narrow SHL writer reaches actual destination-cell preparation
through its selectors, real RSP read and actual width helper in eighty-three silent steps. -/
theorem narrow_prepared (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (dst : BitVec 8) (size : X86.Size) (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next)) :
    InternalRun ge 83 (.State function writer k e le m)
      (.State function cellWriter (loadCont k) e
        (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le dst size)))
          cellsBlock cellsOffset value) size shift next) m) := by
  have loaded := narrow_loaded ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word dst size narrow destination width alu
  let reached := loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le dst size)))
    cellsBlock cellsOffset value
  have keptWidth : reached.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86ShiftLeft.argument size) := by
    simp +decide [reached, loadTemps, narrowSrcTemps, narrowDstTemps, selectTemps,
      CC.PTree.gso, width]
  have keptShift : reached.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (.Vint (shift.setWidth 32)) := by
    simp +decide [reached, loadTemps, narrowSrcTemps, narrowDstTemps, selectTemps,
      CC.PTree.gso, observedShift]
  have keptValue : reached.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next) := by
    simp +decide [reached, loadTemps, narrowSrcTemps, narrowDstTemps, selectTemps,
      CC.PTree.gso, observedValue]
  have prepared := width_internal ge widthBlock widthBinding function e reached unshadowed
    size shift next (loadCont k) m keptWidth keptShift keptValue
  exact loaded.trans prepared


private def registerByte (index : Fin 16) : BitVec 8 := BitVec.ofNat 8 index.val

def cellDelta (index : Fin 16) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 16)
    (CC.Cop.ptrofsOfInt .Signed ((registerByte index).setWidth 32))

/-- The imported pointer arithmetic gives the actual sixteen-byte stride for every GPR slot. -/
theorem cell_delta : ∀ index : Fin 16,
    cellDelta index = CC.Integers.Ptrofs.repr (16 * (index.val : Int)) := by
  decide +kernel

private structure CellPieces where
  choice : CC.Stmt
  assignment : CC.Stmt
  rest : CC.Stmt

private def cellPieces : CellPieces :=
  match cellWriter with
  | .Ssequence (.Ssequence choice assignment) rest => ⟨choice, assignment, rest⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip⟩

private def cellChoice : CC.Stmt := by run_tac cachePart (← `(cellPieces.choice))
private def cellInitialize : CC.Stmt := by run_tac cachePart (← `(cellPieces.assignment))
def tagWriter : CC.Stmt := by run_tac cachePart (← `(cellPieces.rest))

/-- The actual destination-cell read, local union initialization and tag suffix retain source identity. -/
theorem cell_source : cellWriter =
    .Ssequence (.Ssequence cellChoice cellInitialize) tagWriter := rfl

def cellReadTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : CC.Val) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'168 (.Vptr block offset)).set
    X86_program_profile_bpf._t'169 value).set X86_program_profile_bpf._t'106 value

/-- Seven actual source transitions read every architectural destination slot
and preserve the entire heap and caller continuation. -/
theorem cell_read (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32))) :
    InternalRun ge 7
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_100 k e le m)
      (.State function .Sskip k e (cellReadTemps le cellsBlock cellsOffset value) m) := by
  have addZero (offset : CC.Integers.Ptrofs) :
      CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset := by
    change offset + 0 = offset
    exact BitVec.add_zero offset
  have tableAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr bindingBlock 0) =
      some (bindingBlock, 0, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86RegisterLayout.cells_offset ge.genv_cenv, addZero]
  have valueAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._value (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)), .Full) := by
    simp only [CC.lvalOfField, cellLayout, X86RegisterLayout.value_offset ge.genv_cenv gprLayout, addZero]
  have ptrOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  have pointerAddress : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)), .Full) := by
    simp only [CC.lvalOfField, gprLayout, ptrOffset, addZero]

  have cellAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr cellsBlock cellsOffset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint ((registerByte index).setWidth 32)) CC.tuchar m =
        some (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) := by
    simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint,
      CC.sizeof, cellLayout, X86RegisterLayout.layout.2.2.2.1]
    change some (CC.Val.Vptr cellsBlock (CC.Integers.Ptrofs.add cellsOffset (cellDelta index))) =
      some (CC.Val.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
    rw [cell_delta index]
    rfl
  have indexCast : CC.Cop.semCast (.Vint ((registerByte index).setWidth 32))
      CC.tuchar CC.tuchar m = some (.Vint ((registerByte index).setWidth 32)) := by
    simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, writer_byte_cast]
  have structAccess (name : CC.Ident) :
      CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have wordCast : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr)
      (.Tpointer CC.tvoid CC.noattr) m = some value := word
  have keptDestination : (le.set X86_program_profile_bpf._t'168 (.Vptr cellsBlock cellsOffset)).get
      X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [CC.PTree.gso, destination]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_100, cellReadTemps,
      CC.doStep, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      CC.PTree.gss, structAccess, unionAccess, ptrAccess, tableAddress, valueAddress,
      pointerAddress, cellAdd, binding, keptDestination, indexCast, wordCast,
      CC.Mem.loadv, unsigned0, cells, current, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Both real pointer reads and the admitted source word read back exactly;
every other temporary retains its incoming value. -/
theorem cell_read_temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : CC.Val) :
    (cellReadTemps le block offset value).get X86_program_profile_bpf._t'168 =
      some (.Vptr block offset) ∧
    (cellReadTemps le block offset value).get X86_program_profile_bpf._t'169 = some value ∧
    (cellReadTemps le block offset value).get X86_program_profile_bpf._t'106 = some value ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'168 → id ≠ X86_program_profile_bpf._t'169 →
      id ≠ X86_program_profile_bpf._t'106 →
      (cellReadTemps le block offset value).get id = le.get id := by
  refine ⟨by simp +decide [cellReadTemps, CC.PTree.gso],
    by simp +decide [cellReadTemps, CC.PTree.gso], by simp [cellReadTemps], ?_⟩
  intro id ne168 ne169 ne106
  simp [cellReadTemps, CC.PTree.gso, Ne.symm ne168, Ne.symm ne169, Ne.symm ne106]


private def cellTest : CC.Expr := by
  run_tac cachePart (← `(match cellChoice with
    | .Sifthenelse test _ _ => test | _ => .Econst_int (0#32) CC.tint))

private theorem cell_choice_source : cellChoice =
    .Sifthenelse cellTest X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_100
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_101 := rfl

private theorem register_long : ∀ index : Fin 16,
    CC.Cop.castIntLong .Unsigned ((registerByte index).setWidth 32) =
      BitVec.ofNat 64 index.val := by
  decide +kernel

/-- Three original sequence/range-test transitions select the real valid-cell body. -/
theorem cell_select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32))) :
    InternalRun ge 3 (.State function cellWriter k e le m)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_100
        (.Kseq cellInitialize (.Kseq tagWriter k)) e le m) := by
  have bound64 : index.val < 2 ^ 64 := by have bound := index.isLt; omega
  have indexNat : (BitVec.ofNat 64 index.val).toNat = index.val := Nat.mod_eq_of_lt bound64
  have sixteen : CC.Cop.castIntLong .Unsigned (CC.Integers.Int.repr 16) = (16#64) := rfl
  have evaluated : CC.doEvalExpr ge e le m cellTest = some (.Vint (1#32)) := by
    simp +decide [cellTest, CC.doEvalExpr, CC.typeof, destination,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tulong, CC.tuint, register_long, sixteen,
      CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.MI.ltu, BitVec.ult, indexNat, index.isLt,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Integers.Int.one, CC.Integers.MI.one]
  have testType : CC.typeof cellTest = CC.tint := rfl
  have truth : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  rw [cell_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, cell_choice_source, CC.doStep,
      evaluated, testType, truth, ite_true, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- The original local union initializer performs its genuine pointer-word store,
retaining the entire environment and temporary map. -/
theorem initialize_cell (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (localBlock : CC.Block) (value : CC.Val)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observed : le.get X86_program_profile_bpf._t'106 = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value)
    (stored : CC.Mem.store CC.Mptr m localBlock 0 value = some after) :
    InternalRun ge 1 (.State function cellInitialize k e le m)
      (.State function .Sskip k e le after) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      some (localBlock, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have ptrOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  have pointerAddress : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr localBlock 0) = some (localBlock, 0, .Full) := by
    simp only [CC.lvalOfField, gprLayout, ptrOffset]
    rfl
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tvoid CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have wordCast : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr)
      (.Tpointer CC.tvoid CC.noattr) m = some value := word
  have assignment : CC.doAssignLoc ge.genv_cenv (.Tpointer CC.tvoid CC.noattr)
      m localBlock 0 .Full value = some after := by
    simp only [CC.doAssignLoc, ptrAccess, CC.Mem.storev, unsigned0, stored]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, cellInitialize, CC.doStep,
      CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof, CC.tptr,
      localAddress, pointerAddress, unionAccess, observed, wordCast, assignment,
      CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Every real destination slot follows the source range test, pointer reads and
local union store to the original tag stage in thirteen silent transitions. -/
theorem cell_initialized (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)))
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 value = some after) :
    InternalRun ge 13 (.State function cellWriter k e le m)
      (.State function tagWriter k e (cellReadTemps le cellsBlock cellsOffset value) after) := by
  have selected := cell_select ge function e le k m index destination
  have read := cell_read ge bindingsLayout gprLayout cellLayout function e le
    (.Kseq cellInitialize (.Kseq tagWriter k)) m
    bindingBlock cellsBlock cellsOffset index value binding cells current word destination
  have resume : InternalRun ge 1
      (.State function .Sskip (.Kseq cellInitialize (.Kseq tagWriter k)) e
        (cellReadTemps le cellsBlock cellsOffset value) m)
      (.State function cellInitialize (.Kseq tagWriter k) e
        (cellReadTemps le cellsBlock cellsOffset value) m) := by
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0,
      List.nil_append, true_and]
  have observed := (cell_read_temps le cellsBlock cellsOffset value).2.2.1
  have initialized := initialize_cell ge gprLayout function e
    (cellReadTemps le cellsBlock cellsOffset value) (.Kseq tagWriter k) m after
    localBlock value declared observed word stored
  have resumeTag : InternalRun ge 1
      (.State function .Sskip (.Kseq tagWriter k) e
        (cellReadTemps le cellsBlock cellsOffset value) after)
      (.State function tagWriter k e (cellReadTemps le cellsBlock cellsOffset value) after) := by
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0,
      List.nil_append, true_and]
  exact (((selected.trans read).trans resume).trans initialized).trans resumeTag

/-- Every narrow architectural SHL destination follows the original writer
through its actual local union store, reaching the tag stage in ninety-six silent transitions. -/
theorem narrow_initialized (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16) (size : X86.Size) (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (cellValue : CC.Val)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some cellValue)
    (cellWord : CC.Cop.semCast cellValue (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some cellValue)
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 cellValue = some after) :
    InternalRun ge 96 (.State function writer k e le m)
      (.State function tagWriter (loadCont k) e
        (cellReadTemps
          (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le (registerByte index) size)))
            cellsBlock cellsOffset value) size shift next)
          cellsBlock cellsOffset cellValue) after) := by
  have prepared := narrow_prepared ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word
    (registerByte index) size narrow destination width alu widthBlock widthBinding unshadowed
    shift next observedShift observedValue
  let reached := writerWidthTemps
    (loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le (registerByte index) size)))
      cellsBlock cellsOffset value) size shift next
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    simp +decide [reached, writerWidthTemps, writerRawTemps, writerEffectiveTemps, loadTemps,
      narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, binding]
  have keptDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [reached, writerWidthTemps, writerRawTemps, writerEffectiveTemps, loadTemps,
      narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, destination]
  have initialized := cell_initialized ge bindingsLayout gprLayout cellLayout function e reached
    (loadCont k) m bindingBlock cellsBlock cellsOffset index cellValue keptBinding cells
    cellCurrent cellWord keptDestination localBlock after declared stored
  exact prepared.trans initialized


private def tagLoop : CC.Stmt :=
  .Ssequence X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_102
    X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103

def widthDispatch : CC.Stmt := by
  run_tac cachePart (← `(match tagWriter with
    | .Ssequence _ rest => rest | _ => .Sskip))

/-- The original tag loop and its exact width-dispatch continuation retain source identity. -/
theorem tag_source : tagWriter = .Ssequence (.Sloop tagLoop .Sbreak) widthDispatch := rfl

def tagCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 tagLoop .Sbreak (.Kseq widthDispatch k)

def tagRegTemps (le : CC.TempEnv) (index : Fin 16) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___x86_tag_reg__2 (.Vlong (BitVec.ofNat 64 index.val))

def tagReadTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (tag : BitVec 8) : CC.TempEnv :=
  (((le.set X86_program_profile_bpf._t'166 (.Vptr block offset)).set
    X86_program_profile_bpf._t'167 (.Vint (tag.setWidth 32))).set
    X86_program_profile_bpf._t'107 (.Vint (tag.setWidth 32))).set
    X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (tag.setWidth 32))

def tagTemps (le : CC.TempEnv) (index : Fin 16) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (tag : BitVec 8) : CC.TempEnv :=
  tagReadTemps (tagRegTemps le index) block offset tag

private def tagTest : CC.Expr := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 with
    | .Ssequence (.Sifthenelse test _ _) _ => test | _ => .Econst_int (0#32) CC.tint))

private def tagValid : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 with
    | .Ssequence (.Sifthenelse _ active _) _ => active | _ => .Sskip))
private def tagInvalid : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 with
    | .Ssequence (.Sifthenelse _ _ inactive) _ => inactive | _ => .Sskip))
private def tagAssignment : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 with
    | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem tag_body_source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 =
    .Ssequence (.Sifthenelse tagTest tagValid tagInvalid) tagAssignment := rfl

private theorem register_back : ∀ index : Fin 16,
    CC.Cop.castIntInt .I8 .Unsigned
      (CC.Integers.Int.repr (CC.Integers.Int64.unsigned (BitVec.ofNat 64 index.val))) =
        (registerByte index).setWidth 32 := by
  decide +kernel

/-- Five actual source transitions enter the tag loop and copy the true register index. -/
theorem tag_enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32))) :
    InternalRun ge 5 (.State function tagWriter k e le m)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103
        (tagCont k) e (tagRegTemps le index) m) := by
  rw [tag_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, tagLoop, tagCont, tagRegTemps,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_102, CC.doStep,
      CC.doEvalExpr, CC.typeof, destination, CC.Cop.semCast, CC.Cop.classifyCast, CC.tuchar, CC.tulong,
      register_long, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Three actual skip/break transitions resume the original width dispatch unchanged. -/
theorem tag_exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 3 (.State function .Sskip (tagCont k) e le m)
      (.State function widthDispatch k e le m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, tagCont, CC.doStep, CC.Eapp,
      CC.E0, List.nil_append, true_and]

/-- Eleven actual source transitions test the real tag index, read the current
tag byte and retain its exact source casts and four writes on the same heap. -/
theorem tag_body (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (tag : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))

    (current : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (.Vint (tag.setWidth 32)))
    (indexValue : le.get X86_program_profile_bpf.___x86_tag_reg__2 =
      some (.Vlong (BitVec.ofNat 64 index.val))) :
    InternalRun ge 11
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_103 k e le m)
      (.State function .Sskip k e (tagReadTemps le cellsBlock cellsOffset tag) m) := by
  have addZero (offset : CC.Integers.Ptrofs) :
      CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset := by
    change offset + 0 = offset
    exact BitVec.add_zero offset
  have tableAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr bindingBlock 0) =
      some (bindingBlock, 0, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86RegisterLayout.cells_offset ge.genv_cenv, addZero]

  have tagAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._tag (.Vptr cellsBlock
        (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8, .Full) := by
    simp only [CC.lvalOfField, cellLayout, X86RegisterLayout.tag_offset ge.genv_cenv gprLayout]
    rfl
  have cellAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr cellsBlock cellsOffset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint ((registerByte index).setWidth 32)) CC.tuchar m =
        some (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) := by
    simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint,
      CC.sizeof, cellLayout, X86RegisterLayout.layout.2.2.2.1]
    change some (CC.Val.Vptr cellsBlock (CC.Integers.Ptrofs.add cellsOffset (cellDelta index))) =
      some (CC.Val.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
    rw [cell_delta index]
    rfl
  have bound64 : index.val < 2 ^ 64 := by have bound := index.isLt; omega
  have indexNat : (BitVec.ofNat 64 index.val).toNat = index.val := Nat.mod_eq_of_lt bound64
  have sixteen : CC.Cop.castIntLong .Unsigned (CC.Integers.Int.repr 16) = (16#64) := rfl
  have evaluated : CC.doEvalExpr ge e le m tagTest = some (.Vint (1#32)) := by
    simp +decide [tagTest, CC.doEvalExpr, CC.typeof, indexValue,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tulong, CC.tuint, sixteen,
      CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.MI.ltu, BitVec.ult, indexNat, index.isLt,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Integers.Int.one, CC.Integers.MI.one]

  have testType : CC.typeof tagTest = CC.tint := rfl
  dsimp only [CC.typeof] at testType
  have truth : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  have indexCast : CC.Cop.semCast (.Vlong (BitVec.ofNat 64 index.val)) CC.tulong CC.tuchar m =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.tuchar, register_back]
  have uintCast : CC.Cop.semCast (.Vint (tag.setWidth 32)) CC.tuchar CC.tuint m =
      some (.Vint (tag.setWidth 32)) := rfl
  have byteCast : CC.Cop.semCast (.Vint (tag.setWidth 32)) CC.tuint CC.tuchar m =
      some (.Vint (tag.setWidth 32)) := by
    simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar, CC.tuint,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, writer_byte_cast]
  have structAccess (name : CC.Ident) :
      CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have keptIndex : (le.set X86_program_profile_bpf._t'166 (.Vptr cellsBlock cellsOffset)).get
      X86_program_profile_bpf.___x86_tag_reg__2 = some (.Vlong (BitVec.ofNat 64 index.val)) := by
    simp +decide [CC.PTree.gso, indexValue]
  rw [tag_body_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState,
      tagValid, tagAssignment, tagReadTemps,
      CC.doStep, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr, CC.PTree.gss,
      evaluated, testType, truth, ite_true, structAccess, ptrAccess, charAccess,
      tableAddress, tagAddress, cellAdd, binding, keptIndex, indexCast, uintCast, byteCast,
      CC.Mem.loadv, unsigned0, cells, current, CC.Eapp, CC.E0, List.nil_append, true_and]

theorem tag_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (tag : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))

    (current : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (.Vint (tag.setWidth 32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32))) :
    InternalRun ge 19 (.State function tagWriter k e le m)
      (.State function widthDispatch k e (tagTemps le index cellsBlock cellsOffset tag) m) := by
  have entered := tag_enter ge function e le k m index destination
  have keptBinding : (tagRegTemps le index).get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    simp +decide [tagRegTemps, CC.PTree.gso, binding]
  have observedIndex : (tagRegTemps le index).get X86_program_profile_bpf.___x86_tag_reg__2 =
      some (.Vlong (BitVec.ofNat 64 index.val)) := by simp [tagRegTemps]
  have body := tag_body ge bindingsLayout gprLayout cellLayout function e (tagRegTemps le index)
    (tagCont k) m bindingBlock cellsBlock cellsOffset index tag keptBinding cells current observedIndex
  have exited := tag_exit ge function e
    (tagReadTemps (tagRegTemps le index) cellsBlock cellsOffset tag) k m
  exact (entered.trans body).trans exited

theorem tag_temps (le : CC.TempEnv) (index : Fin 16) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (tag : BitVec 8) :
    (tagTemps le index block offset tag).get X86_program_profile_bpf.___x86_tag_reg__2 =
      some (.Vlong (BitVec.ofNat 64 index.val)) ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf._t'166 =
      some (.Vptr block offset) ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf._t'167 =
      some (.Vint (tag.setWidth 32)) ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf._t'107 =
      some (.Vint (tag.setWidth 32)) ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (tag.setWidth 32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf.___x86_tag_reg__2 →
      id ≠ X86_program_profile_bpf._t'166 → id ≠ X86_program_profile_bpf._t'167 →
      id ≠ X86_program_profile_bpf._t'107 → id ≠ X86_program_profile_bpf.___x86_wr_cell_tag__2 →
      (tagTemps le index block offset tag).get id = le.get id := by
  refine ⟨by simp +decide [tagTemps, tagReadTemps, tagRegTemps, CC.PTree.gso],
    by simp +decide [tagTemps, tagReadTemps, CC.PTree.gso],
    by simp +decide [tagTemps, tagReadTemps, CC.PTree.gso],
    by simp +decide [tagTemps, tagReadTemps, CC.PTree.gso],
    by simp [tagTemps, tagReadTemps], ?_⟩
  intro id neReg ne166 ne167 ne107 neTag
  simp [tagTemps, tagReadTemps, tagRegTemps, CC.PTree.gso,
    Ne.symm neReg, Ne.symm ne166, Ne.symm ne167, Ne.symm ne107, Ne.symm neTag]

theorem narrow_tagged (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16) (size : X86.Size) (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (cellValue : CC.Val)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some cellValue)
    (cellWord : CC.Cop.semCast cellValue (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some cellValue)
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 cellValue = some after)
    (tag : BitVec 8)
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (tag.setWidth 32)))
    (callerBlocks : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock) :
    InternalRun ge 115 (.State function writer k e le m)
      (.State function widthDispatch (loadCont k) e
        (tagTemps
          (cellReadTemps
            (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
              (selectTemps le (registerByte index) size))) cellsBlock cellsOffset value)
              size shift next) cellsBlock cellsOffset cellValue)
          index cellsBlock cellsOffset tag) after) := by
  have initialized := narrow_initialized ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word index size narrow destination
    width alu widthBlock widthBinding unshadowed shift next observedShift observedValue
    cellValue cellCurrent cellWord localBlock after declared stored
  let reached := cellReadTemps
    (writerWidthTemps
      (loadTemps (narrowSrcTemps (narrowDstTemps (selectTemps le (registerByte index) size)))
        cellsBlock cellsOffset value) size shift next) cellsBlock cellsOffset cellValue
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    simp +decide [reached, cellReadTemps, writerWidthTemps, writerRawTemps, writerEffectiveTemps,
      loadTemps, narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, binding]
  have keptDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [reached, cellReadTemps, writerWidthTemps, writerRawTemps, writerEffectiveTemps,
      loadTemps, narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, destination]
  have postCells : CC.Mem.load CC.Mptr after bindingBlock 0 =
      some (.Vptr cellsBlock cellsOffset) :=
    (CC.Mem.load_store_other stored CC.Mptr bindingBlock 0 (.inl callerBlocks.1)).trans cells
  have postTag : CC.Mem.load .Mint8unsigned after cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (tag.setWidth 32)) :=
    (CC.Mem.load_store_other stored .Mint8unsigned cellsBlock _ (.inl callerBlocks.2)).trans currentTag
  have tagged := tag_internal ge bindingsLayout gprLayout cellLayout function e reached
    (loadCont k) after bindingBlock cellsBlock cellsOffset index tag keptBinding postCells
    postTag keptDestination
  exact initialized.trans tagged


private def widthBranch : CC.Stmt := by
  run_tac cachePart (← `(match widthDispatch with
    | .Ssequence (.Ssequence _ branch) _ => branch | _ => .Sskip))

def storageTail : CC.Stmt := by
  run_tac cachePart (← `(match widthDispatch with
    | .Ssequence _ rest => rest | _ => .Sskip))

theorem width_dispatch_source : widthDispatch =
    .Ssequence (.Ssequence X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_104
      widthBranch) storageTail := rfl

def widthClass (size : X86.Size) : BitVec 32 :=
  match size with | .b => 0 | .w => 1 | .d => 2 | .q => 3

def classTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'112 (.Vint (widthClass size))

def classifyLength (size : X86.Size) : Nat :=
  match size with | .b => 2 | .w => 6 | .d => 10 | .q => 10

theorem width_classify (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument size)) :
    InternalRun ge (classifyLength size)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_104 k e le m)
      (.State function .Sskip k e (classTemps le size) m) := by
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, classifyLength,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_104,
      classTemps, widthClass, CC.doStep, CC.doEvalExpr, CC.typeof,
      width, X86ShiftLeft.argument, X86.Size.bytes,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuchar, CC.tuint, CC.tint,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
      CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext,
      CC.Integers.MI.zero_ext, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Eapp, CC.E0, set_twice]

theorem class_temps (le : CC.TempEnv) (size : X86.Size) :
    (classTemps le size).get X86_program_profile_bpf._t'112 =
      some (.Vint (widthClass size)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'112 →
      (classTemps le size).get id = le.get id := by
  refine ⟨by simp [classTemps], ?_⟩
  intro id other
  simp [classTemps, CC.PTree.gso, Ne.symm other]

def storageArm (size : X86.Size) : CC.Stmt :=
  match size with
  | .b => X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105
  | _ => X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_106

theorem width_dispatch (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (size : X86.Size)
    (width : le.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument size)) :
    InternalRun ge (classifyLength size + 4)
      (.State function widthDispatch k e le m)
      (.State function (storageArm size) (.Kseq storageTail k) e (classTemps le size) m) := by
  rw [width_dispatch_source]
  have entered : InternalRun ge 2
      (.State function
        (.Ssequence (.Ssequence X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_104
          widthBranch) storageTail) k e le m)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_104
        (.Kseq widthBranch (.Kseq storageTail k)) e le m) := by
    apply internalRun_of_steps <;>
      simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  have classified := width_classify ge function e le
    (.Kseq widthBranch (.Kseq storageTail k)) m size width
  have selected : InternalRun ge 2
      (.State function .Sskip (.Kseq widthBranch (.Kseq storageTail k)) e (classTemps le size) m)
      (.State function (storageArm size) (.Kseq storageTail k) e (classTemps le size) m) := by
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, widthBranch, storageArm,
        classTemps, widthClass, CC.doStep, CC.doEvalExpr, CC.typeof,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuint, CC.tint,
        CC.Integers.Int.eq, CC.Integers.MI.eq,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
  have counts : 2 + classifyLength size + 2 = classifyLength size + 4 := by omega
  rw [← counts]
  exact (entered.trans classified).trans selected

theorem narrow_storage (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16) (size : X86.Size) (narrow : size ≠ .q)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (cellValue : CC.Val)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some cellValue)
    (cellWord : CC.Cop.semCast cellValue (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some cellValue)
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 cellValue = some after)
    (tag : BitVec 8)
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (tag.setWidth 32)))
    (callerBlocks : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock) :
    InternalRun ge (115 + (classifyLength size + 4)) (.State function writer k e le m)
      (.State function (storageArm size) (.Kseq storageTail (loadCont k)) e
        (classTemps
          (tagTemps
            (cellReadTemps
              (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
                (selectTemps le (registerByte index) size))) cellsBlock cellsOffset value)
                size shift next) cellsBlock cellsOffset cellValue)
            index cellsBlock cellsOffset tag) size) after) := by
  have tagged := narrow_tagged ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word index size narrow destination
    width alu widthBlock widthBinding unshadowed shift next observedShift observedValue
    cellValue cellCurrent cellWord localBlock after declared stored tag currentTag callerBlocks
  let reached := tagTemps
    (cellReadTemps
      (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
        (selectTemps le (registerByte index) size))) cellsBlock cellsOffset value)
        size shift next) cellsBlock cellsOffset cellValue)
    index cellsBlock cellsOffset tag
  have reachedWidth : reached.get X86_program_profile_bpf.___x86_wr_width__2 =
      some (X86ShiftLeft.argument size) := by
    simp +decide [reached, tagTemps, tagReadTemps, tagRegTemps, cellReadTemps,
      writerWidthTemps, writerEffectiveTemps, CC.PTree.gso]
  have dispatched := width_dispatch ge function e reached (loadCont k) after size reachedWidth
  exact tagged.trans dispatched


private def bytePrelude : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105 with
    | .Ssequence prelude _ => prelude | _ => .Sskip))

private def byteBody : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105 with
    | .Ssequence _ (.Sloop body _) => body | _ => .Sskip))

private def byteLane : CC.Stmt := by
  run_tac cachePart (← `(match byteBody with | .Ssequence lane _ => lane | _ => .Sskip))

private def byteChoice : CC.Stmt := by
  run_tac cachePart (← `(match byteBody with
    | .Ssequence _ (.Ssequence choice _) => choice | _ => .Sskip))

private def byteTag : CC.Stmt := by
  run_tac cachePart (← `(match byteBody with
    | .Ssequence _ (.Ssequence _ tag) => tag | _ => .Sskip))

private def byteScalar : CC.Stmt := by
  run_tac cachePart (← `(match byteChoice with | .Sifthenelse _ scalar _ => scalar | _ => .Sskip))

theorem byte_source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105 =
    .Ssequence bytePrelude (.Sloop (.Ssequence byteLane (.Ssequence byteChoice byteTag)) .Sbreak) := rfl

def byteCont (k : CC.Cont) : CC.Cont := .Kloop1 byteBody .Sbreak k

def byteValue (next : BitVec 64) : BitVec 32 := next.setWidth 32 &&& (255#32)

def byteLaneTemps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___kprog_x86_lane__4 (.Vint (byteValue next))

def byteTemps (le : CC.TempEnv) (next : BitVec 64) : CC.TempEnv :=
  (byteLaneTemps le next).set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))

theorem byte_enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst : BitVec 8) (next : BitVec 64)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next)) :
    InternalRun ge 10
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105 k e le m)
      (.State function byteScalar (.Kseq byteTag (byteCont k)) e (byteLaneTemps le next) m) := by
  rw [byte_source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, bytePrelude, byteLane, byteChoice,
      byteCont, byteBody, byteScalar, byteTag, byteLaneTemps, byteValue,
      CC.doStep, CC.doEvalExpr, CC.typeof, destination, ordinary, tag, value, CC.PTree.gso,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero,
      CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]

theorem byte_exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 4
      (.State function .Sskip (.Kseq byteTag (byteCont k)) e le m)
      (.State function .Sskip k e
        (le.set X86_program_profile_bpf.___x86_wr_cell_tag__2 (.Vint (0#32))) m) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, byteTag, byteCont, CC.doStep,
      CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.tuchar, CC.tuint, CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Eapp, CC.E0]



private def byteTest : CC.Expr := by
  run_tac cachePart (← `(match byteScalar with
    | .Sifthenelse test _ _ => test
    | _ => .Econst_int (0#32) CC.tint))
private def byteHigh : CC.Stmt := by
  run_tac cachePart (← `(match byteScalar with | .Sifthenelse _ high _ => high | _ => .Sskip))
private def byteLow : CC.Stmt := by
  run_tac cachePart (← `(match byteScalar with | .Sifthenelse _ _ low => low | _ => .Sskip))
private theorem byte_scalar_source : byteScalar = .Sifthenelse byteTest byteHigh byteLow := rfl

def byteOffset (shift : BitVec 8) : CC.Integers.Ptrofs :=
  if shift.setWidth 32 = (8#32) then 1 else 0

theorem byte_store (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (localBlock : CC.Block) (shift : BitVec 8) (next : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observedShift : le.get X86_program_profile_bpf.___x86_wr_shift__2 =
      some (.Vint (shift.setWidth 32)))
    (observedLane : le.get X86_program_profile_bpf.___kprog_x86_lane__4 =
      some (.Vint (byteValue next)))
    (stored : CC.Mem.store .Mint8unsigned m localBlock
      (CC.Integers.Ptrofs.unsigned (byteOffset shift)) (.Vint (byteValue next)) = some after) :
    InternalRun ge 2 (.State function byteScalar k e le m)
      (.State function .Sskip k e le after) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      some (localBlock, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have arrayOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._b
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._b gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.tuchar, CC.noattr]
  have arrayAddress (offset : CC.Integers.Ptrofs) : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._b (.Vptr localBlock offset) =
      some (localBlock, offset, .Full) := by
    simp only [CC.lvalOfField, gprLayout, arrayOffset]
    change some (localBlock, offset + 0, CC.Bitfield.Full) = some (localBlock, offset, .Full)
    exact congrArg (fun n => some (localBlock, n, CC.Bitfield.Full)) (BitVec.add_zero offset)
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have arrayAccess : CC.accessMode (.Tarray CC.tuchar 8 CC.noattr) = .By_reference := rfl
  have byteAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerAdd (high : Bool) (offset : CC.Integers.Ptrofs) :
      CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
        (.Vptr localBlock offset) (.Tarray CC.tuchar 8 CC.noattr)
        (.Vint (if high then (1#32) else (0#32))) CC.tint m =
      some (.Vptr localBlock (offset + (if high then 1 else 0))) := by
    cases high <;> rfl
  have arrayZero := arrayAddress (0#64)
  have highAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr localBlock (0#64)) (.Tarray CC.tuchar 8 CC.noattr) (.Vint (1#32)) CC.tint m =
      some (.Vptr localBlock (1#64)) := pointerAdd true (0#64)
  have lowAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr localBlock (0#64)) (.Tarray CC.tuchar 8 CC.noattr) (.Vint (0#32)) CC.tint m =
      some (.Vptr localBlock (0#64)) := pointerAdd false (0#64)
  have offsetUnsigned : CC.Integers.Ptrofs.unsigned (byteOffset shift) =
      (if shift.setWidth 32 = (8#32) then (1 : Int) else 0) := by
    by_cases high : shift.setWidth 32 = (8#32)
    all_goals simp only [byteOffset, high, ite_true, ite_false]
    all_goals rfl
  rw [offsetUnsigned] at stored
  have laneCast : CC.Cop.semCast (.Vint (byteValue next)) CC.tuchar CC.tuchar m =
      some (.Vint (byteValue next)) := by
    simp +decide [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      byteValue, BitVec.and_assoc]
  have testType : CC.typeof byteTest = CC.tint := rfl
  dsimp only [CC.typeof] at testType
  have trueValue : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  have falseValue : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  rw [byte_scalar_source]
  by_cases high : shift.setWidth 32 = (8#32)
  all_goals
    simp only [high, ite_true, ite_false] at stored
  all_goals
    have evaluated : CC.doEvalExpr ge e le m byteTest =
        some (.Vint (if shift.setWidth 32 = (8#32) then (1#32) else (0#32))) := by
      simp +decide [byteTest, CC.doEvalExpr, CC.typeof, observedShift,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes,
        CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.Integers.Int.cmpu,
        CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, high,
        CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.one, CC.Integers.MI.one,
        CC.Integers.Int.zero, CC.Integers.MI.zero]
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, byteHigh, byteLow,
        CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof, CC.tarray,
        evaluated, testType, high, localAddress, arrayZero, unionAccess, arrayAccess,
        highAdd, lowAdd, observedLane, laneCast,
        CC.doAssignLoc, byteAccess, CC.Mem.storev, stored, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned, trueValue, falseValue, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Eapp, CC.E0]


theorem byte_internal (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (localBlock : CC.Block) (dst shift : BitVec 8) (next : BitVec 64)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32))
    (tag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (0#32)))
    (value : le.get X86_program_profile_bpf.___x86_wr_next__2 = some (.Vlong next))
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (observedShift : le.get X86_program_profile_bpf.___x86_wr_shift__2 =
      some (.Vint (shift.setWidth 32)))
    (stored : CC.Mem.store .Mint8unsigned m localBlock
      (CC.Integers.Ptrofs.unsigned (byteOffset shift)) (.Vint (byteValue next)) = some after) :
    InternalRun ge 16
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_105 k e le m)
      (.State function .Sskip k e (byteTemps le next) after) := by
  have entered := byte_enter ge function e le k m dst next destination ordinary tag value
  have keptShift : (byteLaneTemps le next).get X86_program_profile_bpf.___x86_wr_shift__2 =
      some (.Vint (shift.setWidth 32)) := by
    simp +decide [byteLaneTemps, CC.PTree.gso, observedShift]
  have lane : (byteLaneTemps le next).get X86_program_profile_bpf.___kprog_x86_lane__4 =
      some (.Vint (byteValue next)) := by simp [byteLaneTemps]
  have written := byte_store ge gprLayout function e (byteLaneTemps le next)
    (.Kseq byteTag (byteCont k)) m after localBlock shift next declared keptShift lane stored
  have exited := byte_exit ge function e (byteLaneTemps le next) k after
  exact (entered.trans written).trans exited

theorem byte_temps (le : CC.TempEnv) (next : BitVec 64) :
    (byteTemps le next).get X86_program_profile_bpf.___kprog_x86_lane__4 =
      some (.Vint (byteValue next)) ∧
    (byteTemps le next).get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (0#32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf.___kprog_x86_lane__4 →
      id ≠ X86_program_profile_bpf.___x86_wr_cell_tag__2 →
      (byteTemps le next).get id = le.get id := by
  refine ⟨by simp +decide [byteTemps, byteLaneTemps, CC.PTree.gso],
    by simp [byteTemps], ?_⟩
  intro id neLane neTag
  simp [byteTemps, byteLaneTemps, CC.PTree.gso, Ne.symm neLane, Ne.symm neTag]

theorem byte_value (next : BitVec 64) :
    byteValue next = (next.setWidth 8).setWidth 32 := by
  change next.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 =
    (next.setWidth 8).setWidth 32
  rw [BitVec.and_setWidth_allOnes 24 8]
  rw [BitVec.setWidth_setWidth_of_le next (by decide : 8 ≤ 32)]
  exact (BitVec.setWidth_eq_append (x := next.setWidth 8) (by decide : 8 ≤ 32)).symm

theorem byte_writer (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cellsBlock : CC.Block) (cellsOffset : CC.Integers.Ptrofs) (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (rsp : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + 64)) = some value)
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) CC.tlong m = some value)
    (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .b))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (unshadowed : e.get X86_program_profile_bpf._x86_width_effective = none)
    (shift : BitVec 8) (next : BitVec 64)
    (observedShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32)))
    (observedValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong next))
    (cellValue : CC.Val)
    (cellCurrent : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some cellValue)
    (cellWord : CC.Cop.semCast cellValue (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some cellValue)
    (localBlock : CC.Block) (after : CC.Mem)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (stored : CC.Mem.store CC.Mptr m localBlock 0 cellValue = some after)
    (currentTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
          some (.Vint (0#32)))
    (callerBlocks : bindingBlock ≠ localBlock ∧ cellsBlock ≠ localBlock)
    (ordinary : (registerByte index).setWidth 32 ≠ (4#32))
    (final : CC.Mem)
    (byteStored : CC.Mem.store .Mint8unsigned after localBlock
      (CC.Integers.Ptrofs.unsigned (byteOffset shift)) (.Vint (byteValue next)) = some final) :
    InternalRun ge 137 (.State function writer k e le m)
      (.State function .Sskip (.Kseq storageTail (loadCont k)) e
        (byteTemps
          (classTemps
            (tagTemps
              (cellReadTemps
                (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
                  (selectTemps le (registerByte index) .b))) cellsBlock cellsOffset value)
                  .b shift next) cellsBlock cellsOffset cellValue)
              index cellsBlock cellsOffset (0#8)) .b) next) final) := by
  have routed := narrow_storage ge bindingsLayout gprLayout cellLayout function e le k m
    bindingBlock cellsBlock cellsOffset value binding cells rsp word index .b (by decide)
    destination width alu widthBlock widthBinding unshadowed shift next observedShift observedValue
    cellValue cellCurrent cellWord localBlock after declared stored (0#8) currentTag callerBlocks
  let reached := classTemps
    (tagTemps
      (cellReadTemps
        (writerWidthTemps (loadTemps (narrowSrcTemps (narrowDstTemps
          (selectTemps le (registerByte index) .b))) cellsBlock cellsOffset value)
          .b shift next) cellsBlock cellsOffset cellValue)
      index cellsBlock cellsOffset (0#8)) .b
  have keptDestination : reached.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [reached, classTemps, tagTemps, tagReadTemps, tagRegTemps, cellReadTemps,
      writerWidthTemps, writerEffectiveTemps, writerRawTemps, loadTemps,
      narrowSrcTemps, narrowDstTemps, selectTemps, CC.PTree.gso, destination]
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (0#32)) := by
    simp +decide [reached, classTemps, tagTemps, tagReadTemps, CC.PTree.gso]
  have keptValue : reached.get X86_program_profile_bpf.___x86_wr_next__2 =
      some (.Vlong next) := by
    simp +decide [reached, classTemps, tagTemps, tagReadTemps, tagRegTemps, cellReadTemps,
      writerWidthTemps, CC.PTree.gso]
  have keptShift : reached.get X86_program_profile_bpf.___x86_wr_shift__2 =
      some (.Vint (shift.setWidth 32)) := by
    simp +decide [reached, classTemps, tagTemps, tagReadTemps, tagRegTemps, cellReadTemps,
      writerWidthTemps, CC.PTree.gso]
  have written := byte_internal ge gprLayout function e reached (.Kseq storageTail (loadCont k))
    after final localBlock (registerByte index) shift next keptDestination ordinary keptTag keptValue
    declared keptShift byteStored
  exact routed.trans written


theorem storage_tail_source : storageTail =
    .Ssequence X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_107
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 := rfl

theorem storage_enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst : BitVec 8)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32)) :
    InternalRun ge 4 (.State function .Sskip (.Kseq storageTail k) e le m)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le m) := by
  rw [storage_tail_source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_107,
      CC.doStep, CC.doEvalExpr, CC.typeof, destination, ordinary,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vfalse,
      CC.Eapp, CC.E0]

private def tableParts : CC.Stmt × CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 with
    | .Ssequence ptr (.Ssequence tag (.Ssequence (.Sloop body _) release)) =>
      (ptr, tag, body, release)
    | _ => (.Sskip, .Sskip, .Sskip, .Sskip)))
private def tablePtr : CC.Stmt := by
  run_tac cachePart (← `(tableParts.1))
private def tableTag : CC.Stmt := by
  run_tac cachePart (← `(tableParts.2.1))
private def tableBody : CC.Stmt := by
  run_tac cachePart (← `(tableParts.2.2.1))
private def tableRelease : CC.Stmt := by
  run_tac cachePart (← `(tableParts.2.2.2))
private def tableIndex : CC.Stmt := by
  run_tac cachePart (← `(match tableBody with | .Ssequence index _ => index | _ => .Sskip))
private def tableChoice : CC.Stmt := by
  run_tac cachePart (← `(match tableBody with | .Ssequence _ choice => choice | _ => .Sskip))
def tableStores : CC.Stmt := by
  run_tac cachePart (← `(match tableChoice with | .Sifthenelse _ stores _ => stores | _ => .Sskip))

theorem table_source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 =
    .Ssequence tablePtr (.Ssequence tableTag
      (.Ssequence (.Sloop (.Ssequence tableIndex tableChoice) .Sbreak) tableRelease)) := rfl

def tableCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 tableBody .Sbreak (.Kseq tableRelease k)
def tableIndexTemps (le : CC.TempEnv) (index : Fin 16) : CC.TempEnv :=
  le.set X86_program_profile_bpf.___x86_store_reg__5 (.Vlong (BitVec.ofNat 64 index.val))
def tableLoadTemps (le : CC.TempEnv) (value : CC.Val) (tag : BitVec 8) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_wr_next_ptr__5 value).set
    X86_program_profile_bpf.___x86_wr_next_tag__5 (.Vint (tag.setWidth 32))

theorem table_select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (index : Fin 16)
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32))) :
    InternalRun ge 5 (.State function (.Sloop tableBody .Sbreak) (.Kseq tableRelease k) e le m)
      (.State function tableStores (tableCont k) e (tableIndexTemps le index) m) := by
  have bound64 : index.val < 2 ^ 64 := by have small := index.isLt; omega
  have indexNat : (BitVec.ofNat 64 index.val).toNat = index.val :=
    Nat.mod_eq_of_lt bound64
  have sixteen : CC.Cop.castIntLong .Unsigned (CC.Integers.Int.repr 16) = (16#64) := rfl
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, tableBody,
      tableStores, tableCont, tableIndexTemps, CC.doStep, CC.doEvalExpr, CC.typeof, destination,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tulong, CC.tuint, CC.tint,
      register_long, sixteen, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.MI.ltu, BitVec.ult, indexNat, index.isLt, CC.Val.ofBool, CC.Val.Vtrue,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Eapp, CC.E0]

theorem table_exit (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (dst : BitVec 8)
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (dst.setWidth 32)))
    (ordinary : dst.setWidth 32 ≠ (4#32)) :
    InternalRun ge 4 (.State function .Sskip (tableCont k) e le m)
      (.State function .Sskip k e le m) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, tableCont, tableRelease,
      CC.doStep, CC.doEvalExpr, CC.typeof, destination, ordinary,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vfalse,
      CC.Eapp, CC.E0]


theorem table_prepare (ge : CC.CGenv)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m : CC.Mem) (localBlock : CC.Block) (value : CC.Val) (tag : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (current : CC.Mem.load CC.Mptr m localBlock 0 = some value)
    (observedTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (tag.setWidth 32))) :
    InternalRun ge 7
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le m)
      (.State function (.Sloop tableBody .Sbreak) (.Kseq tableRelease k) e
        (tableLoadTemps le value tag) m) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      some (localBlock, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have ptrOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  have pointerAddress (offset : CC.Integers.Ptrofs) : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr localBlock offset) =
      some (localBlock, offset, .Full) := by
    simp only [CC.lvalOfField, gprLayout, ptrOffset]
    change some (localBlock, offset + 0, CC.Bitfield.Full) = some (localBlock, offset, .Full)
    exact congrArg (fun n => some (localBlock, n, CC.Bitfield.Full)) (BitVec.add_zero offset)
  have pointerZero := pointerAddress (0 : CC.Integers.Ptrofs)
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tvoid CC.noattr) = .By_value CC.Mptr := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  have tagCast : CC.Cop.semCast (.Vint (tag.setWidth 32)) CC.tuchar CC.tuchar m =
      some (.Vint (tag.setWidth 32)) := by
    simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, writer_byte_cast]
  have keptTag : (le.set X86_program_profile_bpf.___x86_wr_next_ptr__5 value).get
      X86_program_profile_bpf.___x86_wr_cell_tag__2 = some (.Vint (tag.setWidth 32)) := by
    simp +decide [CC.PTree.gso, observedTag]
  rw [table_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, tablePtr, tableTag, tableBody,
      tableIndex, tableChoice, tableLoadTemps, CC.doStep, CC.doEvalExpr, CC.doDerefLoc,
      CC.typeof, CC.tptr, localAddress, pointerZero, unionAccess, ptrAccess, unsigned0,
      CC.Mem.loadv, current, keptTag, tagCast, CC.Eapp, CC.E0, List.nil_append, true_and]


def tableStoreTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'146 (.Vptr block offset)).set
    X86_program_profile_bpf._t'145 (.Vptr block offset)

theorem table_body (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m middle final : CC.Mem) (bindingBlock cellsBlock : CC.Block)
    (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (value : CC.Val) (tag : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (observedIndex : le.get X86_program_profile_bpf.___x86_store_reg__5 =
      some (.Vlong (BitVec.ofNat 64 index.val)))
    (observedValue : le.get X86_program_profile_bpf.___x86_wr_next_ptr__5 = some value)
    (observedTag : le.get X86_program_profile_bpf.___x86_wr_next_tag__5 =
      some (.Vint (tag.setWidth 32)))
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (wordStored : CC.Mem.store CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) value = some middle)
    (tagStored : CC.Mem.store .Mint8unsigned middle cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      (.Vint (tag.setWidth 32)) = some final) :
    InternalRun ge 10 (.State function tableStores k e le m)
      (.State function .Sskip k e (tableStoreTemps le cellsBlock cellsOffset) final) := by
  have addZero (offset : CC.Integers.Ptrofs) :
      CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset := by
    change offset + 0 = offset
    exact BitVec.add_zero offset
  have tableAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr bindingBlock 0) =
      some (bindingBlock, 0, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86RegisterLayout.cells_offset ge.genv_cenv, addZero]
  have tableZero : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr bindingBlock (0#64)) =
      some (bindingBlock, (0#64), .Full) := tableAddress
  have valueAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._value (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)), .Full) := by
    simp only [CC.lvalOfField, cellLayout, X86RegisterLayout.value_offset ge.genv_cenv gprLayout, addZero]
  have ptrOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = .OK (0, .Full)
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  have pointerAddress : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)), .Full) := by
    simp only [CC.lvalOfField, gprLayout, ptrOffset, addZero]

  have cellAdd (heap : CC.Mem) : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd
      (.Vptr cellsBlock cellsOffset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint ((registerByte index).setWidth 32)) CC.tuchar heap =
        some (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) := by
    simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint,
      CC.sizeof, cellLayout, X86RegisterLayout.layout.2.2.2.1]
    change some (CC.Val.Vptr cellsBlock (CC.Integers.Ptrofs.add cellsOffset (cellDelta index))) =
      some (CC.Val.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))))
    rw [cell_delta index]
    rfl

  have tagAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._tag (.Vptr cellsBlock
        (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
      some (cellsBlock, (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8, .Full) := by
    simp only [CC.lvalOfField, cellLayout, X86RegisterLayout.tag_offset ge.genv_cenv gprLayout]
    rfl
  have indexCast (heap : CC.Mem) : CC.Cop.semCast
      (.Vlong (BitVec.ofNat 64 index.val)) CC.tulong CC.tuchar heap =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.tuchar, register_back]
  have tagCast (heap : CC.Mem) : CC.Cop.semCast (.Vint (tag.setWidth 32))
      CC.tuchar CC.tuchar heap = some (.Vint (tag.setWidth 32)) := by
    simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuchar,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, writer_byte_cast]
  have structAccess (name : CC.Ident) : CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have unionAccess : CC.accessMode
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0#64) = 0 := rfl
  have wordCast : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr)
      (.Tpointer CC.tvoid CC.noattr) m = some value := word
  have postCells : CC.Mem.load CC.Mptr middle bindingBlock 0 =
      some (.Vptr cellsBlock cellsOffset) :=
    (CC.Mem.load_store_other wordStored CC.Mptr bindingBlock 0 (.inl bindingSeparate)).trans cells
  simp +decide at tagStored
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, tableStores, tableStoreTemps,
      CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof, CC.tptr,
      CC.PTree.gso, structAccess, unionAccess, ptrAccess, charAccess, tableZero,
      valueAddress, pointerAddress, tagAddress, cellAdd, binding, observedIndex, observedValue,
      observedTag, indexCast, tagCast, wordCast, CC.doAssignLoc, CC.Mem.loadv, CC.Mem.storev,
      unsigned0, cells, postCells, wordStored, tagStored, CC.Eapp, CC.E0]


def tableTemps (le : CC.TempEnv) (value : CC.Val) (tag : BitVec 8) (index : Fin 16)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  tableStoreTemps (tableIndexTemps (tableLoadTemps le value tag) index) block offset

theorem table_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (gprLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
      some X86RegisterLayout.gprRecord)
    (cellLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
      some X86RegisterLayout.cellRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m middle final : CC.Mem) (localBlock bindingBlock cellsBlock : CC.Block)
    (cellsOffset : CC.Integers.Ptrofs) (index : Fin 16) (value : CC.Val) (tag : BitVec 8)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (current : CC.Mem.load CC.Mptr m localBlock 0 = some value)
    (observedTag : le.get X86_program_profile_bpf.___x86_wr_cell_tag__2 =
      some (.Vint (tag.setWidth 32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)))
    (ordinary : (registerByte index).setWidth 32 ≠ (4#32))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (cells : CC.Mem.load CC.Mptr m bindingBlock 0 = some (.Vptr cellsBlock cellsOffset))
    (word : CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) m = some value)
    (bindingSeparate : bindingBlock ≠ cellsBlock)
    (wordStored : CC.Mem.store CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) value = some middle)
    (tagStored : CC.Mem.store .Mint8unsigned middle cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset +
        CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8))
      (.Vint (tag.setWidth 32)) = some final) :
    InternalRun ge 26
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e le m)
      (.State function .Sskip k e (tableTemps le value tag index cellsBlock cellsOffset) final) := by
  have prepared := table_prepare ge gprLayout function e le k m localBlock value tag
    declared current observedTag
  have loadedDestination : (tableLoadTemps le value tag).get X86_program_profile_bpf._dst =
      some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [tableLoadTemps, CC.PTree.gso, destination]
  have selected := table_select ge function e (tableLoadTemps le value tag) k m index loadedDestination
  let reached := tableIndexTemps (tableLoadTemps le value tag) index
  have keptBinding : reached.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    simp +decide [reached, tableIndexTemps, tableLoadTemps, CC.PTree.gso, binding]
  have keptIndex : reached.get X86_program_profile_bpf.___x86_store_reg__5 =
      some (.Vlong (BitVec.ofNat 64 index.val)) := by simp [reached, tableIndexTemps]
  have keptValue : reached.get X86_program_profile_bpf.___x86_wr_next_ptr__5 = some value := by
    simp +decide [reached, tableIndexTemps, tableLoadTemps, CC.PTree.gso]
  have keptTag : reached.get X86_program_profile_bpf.___x86_wr_next_tag__5 =
      some (.Vint (tag.setWidth 32)) := by
    simp +decide [reached, tableIndexTemps, tableLoadTemps, CC.PTree.gso]
  have written := table_body ge bindingsLayout gprLayout cellLayout function e reached (tableCont k)
    m middle final bindingBlock cellsBlock cellsOffset index value tag keptBinding cells
    keptIndex keptValue keptTag word bindingSeparate wordStored tagStored
  have exitDestination : (tableStoreTemps reached cellsBlock cellsOffset).get
      X86_program_profile_bpf._dst = some (.Vint ((registerByte index).setWidth 32)) := by
    simp +decide [tableStoreTemps, reached, tableIndexTemps, tableLoadTemps, CC.PTree.gso, destination]
  have exited := table_exit ge function e (tableStoreTemps reached cellsBlock cellsOffset) k final
    (registerByte index) exitDestination ordinary
  exact ((prepared.trans selected).trans written).trans exited

theorem table_temps (le : CC.TempEnv) (value : CC.Val) (tag : BitVec 8) (index : Fin 16)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    (tableTemps le value tag index block offset).get X86_program_profile_bpf.___x86_wr_next_ptr__5 =
      some value ∧
    (tableTemps le value tag index block offset).get X86_program_profile_bpf.___x86_wr_next_tag__5 =
      some (.Vint (tag.setWidth 32)) ∧
    (tableTemps le value tag index block offset).get X86_program_profile_bpf.___x86_store_reg__5 =
      some (.Vlong (BitVec.ofNat 64 index.val)) ∧
    (tableTemps le value tag index block offset).get X86_program_profile_bpf._t'146 =
      some (.Vptr block offset) ∧
    (tableTemps le value tag index block offset).get X86_program_profile_bpf._t'145 =
      some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf.___x86_wr_next_ptr__5 →
      id ≠ X86_program_profile_bpf.___x86_wr_next_tag__5 →
      id ≠ X86_program_profile_bpf.___x86_store_reg__5 →
      id ≠ X86_program_profile_bpf._t'146 → id ≠ X86_program_profile_bpf._t'145 →
      (tableTemps le value tag index block offset).get id = le.get id := by
  refine ⟨by simp +decide [tableTemps, tableStoreTemps, tableIndexTemps, tableLoadTemps, CC.PTree.gso],
    by simp +decide [tableTemps, tableStoreTemps, tableIndexTemps, tableLoadTemps, CC.PTree.gso],
    by simp +decide [tableTemps, tableStoreTemps, tableIndexTemps, CC.PTree.gso],
    by simp +decide [tableTemps, tableStoreTemps, CC.PTree.gso],
    by simp [tableTemps, tableStoreTemps], ?_⟩
  intro id nePtr neTag neIndex ne146 ne145
  simp [tableTemps, tableStoreTemps, tableIndexTemps, tableLoadTemps, CC.PTree.gso,
    Ne.symm nePtr, Ne.symm neTag, Ne.symm neIndex, Ne.symm ne146, Ne.symm ne145]

end KProgFormal.ClightRefinement.X86ShiftWriteback
