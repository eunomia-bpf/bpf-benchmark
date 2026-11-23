import KProgFormal.ClightRefinement.X86RegisterReadValue

namespace KProgFormal.ClightRefinement.X86RegisterReadTag

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_register_read_tag_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def materialize : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterReadValue.afterValue with
    | .Ssequence first _ => first | _ => .Sskip))
def lanes : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterReadValue.afterValue with
    | .Ssequence _ rest => rest | _ => .Sskip))

/-- The original materialization selector and width/lane suffix. -/
theorem source : X86RegisterReadValue.afterValue = .Ssequence materialize lanes := rfl

theorem tag_address (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._tag (.Vptr block offset) =
      some (block, offset + 8, .Full) := by
  simp only [CC.lvalOfField, layout.cell, X86RegisterLayout.tag_offset _ layout.gpr]
  rfl

private theorem ordinary_code : ∀ index : Fin 16, index ≠ 4 →
    (X86RegisterReadValue.registerByte index).setWidth 32 ≠ (4#32) := by
  decide +kernel

private theorem code_bound : ∀ index : Fin 16,
    ((X86RegisterReadValue.registerByte index).setWidth 64).ult (16#64) = true := by
  decide +kernel

def tagTemps (le : CC.TempEnv) (index : Fin 16) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (tag : BitVec 8) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf.___x86_tag_reg
    (.Vlong ((X86RegisterReadValue.registerByte index).setWidth 64))).set
      X86_program_profile_bpf._t'9 (.Vptr block offset)).set
      X86_program_profile_bpf._t'10 (X86Width.argument tag)).set
      X86_program_profile_bpf._t'3 (X86Width.argument tag)).set
      X86_program_profile_bpf.___x86_rd_tag (X86Width.argument tag)

/-- The actual tag loop and materialization gate execute for every non-RSP
register and every non-stack tag, retaining the raw word and full heap. -/
theorem ordinary (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (index : Fin 16)
    (bindingBlock cellsBlock : CC.Block) (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (tag : BitVec 8) (notSp : index ≠ 4) (notStack : tag ≠ (4#8))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (reg : le.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    InternalRun ge 23
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadValue.afterValue k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg lanes k e
        (tagTemps le index cellsBlock cellsOffset tag) m) := by
  let code := X86RegisterReadValue.registerByte index
  have comparedReg : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (4#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (0#32)) := by
    change some (CC.Val.ofBool (code.setWidth 32 == (4#32))) = _
    rw [beq_eq_false_iff_ne.mpr (ordinary_code index notSp)]
    rfl
  have notStack32 : tag.setWidth 32 ≠ (4#32) := by
    intro eq
    apply notStack
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) eq
  have comparedTag : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (X86Width.argument tag) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (4#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (0#32)) := by
    change some (CC.Val.ofBool (tag.setWidth 32 == (4#32))) = _
    rw [beq_eq_false_iff_ne.mpr notStack32]
    rfl
  have below : CC.Cop.semBinaryOperation ge.genv_cenv .Olt
      (.Vlong (code.setWidth 64)) CC.tulong
      (.Vint (16#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (1#32)) := by
    change some (CC.Val.ofBool ((code.setWidth 64).ult (16#64))) = _
    rw [code_bound index]
    rfl
  have widen : CC.Cop.semCast (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr)
      CC.tulong m = some (.Vlong (code.setWidth 64)) := by
    change some (CC.Val.Vlong (CC.Cop.castIntLong .Unsigned (code.setWidth 32))) = _
    rw [X86RegisterReadEntry.unsigned_byte]
  have indexAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr cellsBlock cellsOffset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr) m =
      some (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) :=
    X86RegisterReadValue.cell_add ge layout m cellsBlock cellsOffset index
  have byteWord : CC.Cop.semCast (X86Width.argument tag) (.Tint .I8 .Unsigned CC.noattr)
      (.Tint .I32 .Unsigned CC.noattr) m = some (X86Width.argument tag) := rfl
  have wordByte : CC.Cop.semCast (X86Width.argument tag) (.Tint .I32 .Unsigned CC.noattr)
      (.Tint .I8 .Unsigned CC.noattr) m = some (X86Width.argument tag) := by
    change some (CC.Val.Vint ((tag.setWidth 32) &&& (BitVec.allOnes 8).setWidth 32)) = _
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]
    rfl
  have structAccess (name : CC.Ident) : CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have byteAccess : CC.accessMode (.Tint .I8 .Unsigned CC.noattr) = .By_value .Mint8unsigned := rfl
  dsimp only [code] at comparedReg below widen indexAdd
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide only [steps, InternalPath, InternalState, CC.doStep, materialize, tagTemps,
      X86_program_profile_bpf.s_x86_sim_inline_read_reg_0,
      CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr, CC.tuchar, CC.tuint, CC.tint,
      CC.PTree.gss, CC.PTree.gso, binding, reg, widen, code,
      X86RegisterReadEntry.byte_long_cast, comparedReg, comparedTag, below,
      X86RegisterReadValue.table_address ge layout, tag_address ge layout,
      indexAdd, structAccess, ptrAccess, byteAccess, byteWord, wordByte,
      CC.Mem.loadv, cells, current, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, BitVec.ofInt_ofNat,
      CC.Eapp, CC.E0, List.nil_append, true_and, ite_true, ite_false]

/-- The actual tag loop leaves every value consumed by the lane suffix intact. -/
theorem observations (le : CC.TempEnv) (index : Fin 16) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (tag : BitVec 8) :
    (tagTemps le index block offset tag).get X86_program_profile_bpf.___x86_rd_value =
      le.get X86_program_profile_bpf.___x86_rd_value ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf.___x86_rd_width =
      le.get X86_program_profile_bpf.___x86_rd_width ∧
    (tagTemps le index block offset tag).get X86_program_profile_bpf.___x86_rd_shift =
      le.get X86_program_profile_bpf.___x86_rd_shift := by
  simp +decide [tagTemps, CC.PTree.gso]

/-- Actual scalar word and tag loads reach the original lane suffix in42
steps; the selected word is retained without a materialization assumption. -/
theorem from_value (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (index : Fin 16) (shift tag : BitVec 8) (value : BitVec 64)
    (bindingBlock cellsBlock : CC.Block) (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (notSp : index ≠ 4) (notStack : tag ≠ (4#8))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (reg : le.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (shiftRead : le.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value))
    (tagRead : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    InternalRun ge 42
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadEntry.afterWidth k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg lanes k e
        (tagTemps (X86RegisterReadValue.valueTemps le shift cellsBlock cellsOffset value)
          index cellsBlock cellsOffset tag) m) := by
  let ready := X86RegisterReadValue.valueTemps le shift cellsBlock cellsOffset value
  have keptBinding : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, X86RegisterReadValue.valueTemps, CC.PTree.gso, binding]
  have keptReg : ready.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [ready, X86RegisterReadValue.valueTemps, CC.PTree.gso, reg]
  exact (X86RegisterReadValue.read_value ge layout e le k m index shift bindingBlock cellsBlock
    bindingOffset cellsOffset value binding reg shiftRead cells current).trans
      (ordinary ge layout e ready k m index bindingBlock cellsBlock bindingOffset cellsOffset
        tag notSp notStack keptBinding keptReg cells tagRead)

end KProgFormal.ClightRefinement.X86RegisterReadTag
