import KProgFormal.ClightRefinement.X86RegisterReadEntry

namespace KProgFormal.ClightRefinement.X86RegisterReadValue

private structure Pieces where
  shift : CC.Stmt
  pointer : CC.Stmt
  save : CC.Stmt
  value : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86RegisterReadEntry.afterWidth with
  | .Ssequence shift (.Ssequence (.Ssequence pointer save) (.Ssequence value rest)) =>
      ⟨shift, pointer, save, value, rest⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_register_read_value_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def shiftSet : CC.Stmt := by run_tac cachePart (← `(pieces.shift))
private def pointerRead : CC.Stmt := by run_tac cachePart (← `(pieces.pointer))
private def pointerSave : CC.Stmt := by run_tac cachePart (← `(pieces.save))
private def valueSet : CC.Stmt := by run_tac cachePart (← `(pieces.value))
def afterValue : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- Original shift narrowing, selected cell-pointer read and scalar casts. -/
theorem source : X86RegisterReadEntry.afterWidth =
    .Ssequence shiftSet (.Ssequence (.Ssequence pointerRead pointerSave)
      (.Ssequence valueSet afterValue)) := rfl

def registerByte (index : Fin 16) : BitVec 8 := BitVec.ofNat 8 index.val

/-- Only the three actual composite lookups used by these source loads. -/
structure Layout (ge : CC.CGenv) : Prop where
  bindings : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
    some X86ShiftLeftCarry.bindingsRecord
  gpr : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr =
    some X86RegisterLayout.gprRecord
  cell : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell =
    some X86RegisterLayout.cellRecord

private def gprMembers : List CC.Member := by
  run_tac cachePart (← `(X86RegisterLayout.gprRecord.co_members))

private theorem add_zero (offset : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 0) = offset :=
  BitVec.add_zero offset

theorem table_address (ge : CC.CGenv) (layout : Layout ge)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr block offset) = some (block, offset, .Full) := by
  simp only [CC.lvalOfField, layout.bindings, X86RegisterLayout.cells_offset, add_zero]

theorem value_address (ge : CC.CGenv) (layout : Layout ge)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr)
      X86_program_profile_bpf._value (.Vptr block offset) = some (block, offset, .Full) := by
  simp only [CC.lvalOfField, layout.cell, X86RegisterLayout.value_offset _ layout.gpr, add_zero]

theorem pointer_address (ge : CC.CGenv) (layout : Layout ge)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    CC.lvalOfField ge (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr block offset) = some (block, offset, .Full) := by
  have field : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr
      X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
    change CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr gprMembers = _
    simp +decide [gprMembers, CC.unionFieldOffset, CC.layoutField, CC.bitalignof,
      CC.alignof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]
  simp only [CC.lvalOfField, layout.gpr, field, add_zero]

theorem cell_add (ge : CC.CGenv) (layout : Layout ge) (m : CC.Mem)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) (index : Fin 16) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr block offset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (.Vint ((registerByte index).setWidth 32)) CC.tuchar m =
        some (.Vptr block (offset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) := by
  simp only [CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semAddPtrInt, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint,
    CC.sizeof, layout.cell, X86RegisterLayout.layout.2.2.2.1]
  change some (CC.Val.Vptr block
    (CC.Integers.Ptrofs.add offset (X86ShiftWriteback.cellDelta index))) = _
  rw [X86ShiftWriteback.cell_delta]
  rfl

private theorem below_sixteen (index : Fin 16) :
    (CC.Cop.castIntLong .Unsigned ((registerByte index).setWidth 32)).ult (16#64) = true := by
  rw [X86RegisterReadEntry.unsigned_byte]
  have bound := index.isLt
  simp only [registerByte, BitVec.ult_eq_decide, BitVec.toNat_setWidth, BitVec.toNat_ofNat,
    decide_eq_true_eq]
  omega

def rawTemps (le : CC.TempEnv) (shift : BitVec 8) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (value : CC.Val) : CC.TempEnv :=
  (((((le.set X86_program_profile_bpf.___x86_rd_shift (X86Width.argument shift)).set
    X86_program_profile_bpf._t'13 (.Vptr block offset)).set
    X86_program_profile_bpf._t'14 value).set
    X86_program_profile_bpf._t'2 value).set
    X86_program_profile_bpf.___x86_rd_ptr value).set
    X86_program_profile_bpf.___x86_rd_value value

def valueTemps (le : CC.TempEnv) (shift : BitVec 8) (block : CC.Block)
    (offset : CC.Integers.Ptrofs) (value : BitVec 64) : CC.TempEnv :=
  (((((le.set X86_program_profile_bpf.___x86_rd_shift (X86Width.argument shift)).set
    X86_program_profile_bpf._t'13 (.Vptr block offset)).set
    X86_program_profile_bpf._t'14 (.Vlong value)).set
    X86_program_profile_bpf._t'2 (.Vlong value)).set
    X86_program_profile_bpf.___x86_rd_ptr (.Vlong value)).set
    X86_program_profile_bpf.___x86_rd_value (.Vlong value)

/-- The actual nineteen source steps load any of the sixteen GPR cells and
retain its raw word and the entire memory, before SP/tag materialization. -/
theorem read_raw (ge : CC.CGenv) (layout : Layout ge) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (index : Fin 16) (shift : BitVec 8)
    (bindingBlock cellsBlock : CC.Block) (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (value : CC.Val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (reg : le.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (registerByte index)))
    (shiftRead : le.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some value)
    (longPointer : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr)
      (.Tpointer CC.tvoid CC.noattr) m = some value)
    (pointerLong : CC.Cop.semCast value (.Tpointer CC.tvoid CC.noattr)
      CC.tlong m = some value)
    (longLong : CC.Cop.semCast value CC.tlong CC.tulong m = some value) :
    InternalRun ge 19
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadEntry.afterWidth k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg afterValue k e
        (rawTemps le shift cellsBlock cellsOffset value) m) := by
  have sixteen : CC.Cop.castIntLong .Unsigned (16#32) = (16#64) := rfl
  have indexAdd : CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr cellsBlock cellsOffset)
      (.Tpointer (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr) CC.noattr)
      (X86Width.argument (registerByte index)) (.Tint .I8 .Unsigned CC.noattr) m =
      some (.Vptr cellsBlock (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) :=
    cell_add ge layout m cellsBlock cellsOffset index
  have widen : CC.Cop.semCast (X86Width.argument (registerByte index))
      (.Tint .I8 .Unsigned CC.noattr) CC.tulong m =
      some (.Vlong (CC.Cop.castIntLong .Unsigned ((registerByte index).setWidth 32))) := rfl
  have compared : CC.Cop.semBinaryOperation ge.genv_cenv .Olt
      (.Vlong (CC.Cop.castIntLong .Unsigned ((registerByte index).setWidth 32))) CC.tulong
      (.Vint (16#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (1#32)) := by
    change some (CC.Val.ofBool
      ((CC.Cop.castIntLong .Unsigned ((registerByte index).setWidth 32)).ult
        (CC.Cop.castIntLong .Unsigned (16#32)))) = _
    rw [sixteen, below_sixteen]
    rfl
  have structAccess (name : CC.Ident) : CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have unionAccess : CC.accessMode (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, shiftSet, pointerRead,
      pointerSave, valueSet, rawTemps, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      CC.PTree.gss, CC.PTree.gso, binding, reg, shiftRead,
      X86RegisterReadEntry.byte_long_cast, X86RegisterReadEntry.byte_cast,
      table_address ge layout, value_address ge layout, pointer_address ge layout,
      indexAdd, structAccess, unionAccess, ptrAccess, cells, current, CC.Mem.loadv,
      compared, widen, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      longPointer, pointerLong, longLong, CC.Eapp, CC.E0]

/-- The actual nineteen source steps load any of the sixteen GPR cells and
retain its scalar word and the entire memory, before SP/tag materialization. -/
theorem read_value (ge : CC.CGenv) (layout : Layout ge) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (index : Fin 16) (shift : BitVec 8)
    (bindingBlock cellsBlock : CC.Block) (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (reg : le.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (registerByte index)))
    (shiftRead : le.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value)) :
    InternalRun ge 19
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadEntry.afterWidth k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg afterValue k e
        (valueTemps le shift cellsBlock cellsOffset value) m) := by
  exact read_raw ge layout e le k m index shift bindingBlock cellsBlock
    bindingOffset cellsOffset (.Vlong value) binding reg shiftRead cells current rfl rfl rfl

/-- Actual caller entry, width helper and selected scalar-cell loads compose
without allocating or changing any caller memory. -/
theorem from_call (ge : CC.CGenv) (layout : Layout ge) (m : CC.Mem) (k : CC.Cont)
    (index : Fin 16) (width shift : BitVec 8) (helperBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs) (value : BitVec 64)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (current : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value)) :
    let initial := X86RegisterReadEntry.initialTemps (.Vptr bindingBlock bindingOffset)
      (.Vlong ((registerByte index).setWidth 64)) (.Vlong (width.setWidth 64))
      (.Vlong (shift.setWidth 64))
    let ready := X86RegisterReadEntry.widthTemps
      (X86RegisterReadEntry.prefixTemps initial (registerByte index) width) width
    InternalRun ge 41
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset) (registerByte index) width shift) k m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg afterValue
        (X86RegisterReadEntry.continuation k) CC.emptyEnv
        (valueTemps ready shift cellsBlock cellsOffset value) m) := by
  dsimp only
  let initial := X86RegisterReadEntry.initialTemps (.Vptr bindingBlock bindingOffset)
    (.Vlong ((registerByte index).setWidth 64)) (.Vlong (width.setWidth 64))
    (.Vlong (shift.setWidth 64))
  let ready := X86RegisterReadEntry.widthTemps
    (X86RegisterReadEntry.prefixTemps initial (registerByte index) width) width
  have binding : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  have reg : ready.get X86_program_profile_bpf.___x86_rd_reg =
      some (X86Width.argument (registerByte index)) := by
    simp +decide [ready, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, CC.PTree.gss, CC.PTree.gso]
  have shiftRead : ready.get X86_program_profile_bpf._shift = some (.Vlong (shift.setWidth 64)) := by
    simp +decide [ready, initial, X86RegisterReadEntry.widthTemps,
      X86RegisterReadEntry.prefixTemps, X86RegisterReadEntry.initialTemps, CC.PTree.gss, CC.PTree.gso]
  rw [X86RegisterReadEntry.arguments]
  exact (X86RegisterReadEntry.from_call ge m k (.Vptr bindingBlock bindingOffset)
    (registerByte index) width shift helperBlock helper).trans
      (read_value ge layout CC.emptyEnv ready (X86RegisterReadEntry.continuation k) m index shift
        bindingBlock cellsBlock bindingOffset cellsOffset value binding reg shiftRead cells current)

/-- For an ordinary scalar row, the shared whole-register relation supplies
the exact x86lean register word read by the original C cell loads. -/
theorem native_word (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.X86.Origins) (m : CC.Mem)
    (block : CC.Block) (offset : CC.Integers.Ptrofs) (cpu : X86.Cpu)
    (represented : X86RegisterView.RegistersRepresent addresses origins m block offset cpu)
    (index : Fin 16) (value : BitVec 64) (ordinary : index ≠ (4 : Fin 16))
    (current : CC.Mem.load CC.Mptr m block
      (CC.Integers.Ptrofs.unsigned (offset + CC.Integers.Ptrofs.repr (16 * (index.val : Int)))) =
        some (.Vlong value))
    (scalar : CC.Mem.load .Mint8unsigned m block
      (CC.Integers.Ptrofs.unsigned ((offset + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (.Vint (0#32))) :
    cpu.regs.get (X86.GPR.ofIndex index) = value := by
  obtain ⟨word, raw, tag, wordRead, tagRead, valueRep, native⟩ := represented index
  have wordEq : word = .Vlong value := Option.some.inj (wordRead.symm.trans current)
  have tagEq32 : tag.setWidth 32 = (0#32) := CC.Val.Vint.inj (Option.some.inj (tagRead.symm.trans scalar))
  have tagEq : tag = (0#8) := by
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) tagEq32
  have rawEq : raw = value := by simpa only [wordEq, Arm64Registers.ValueRep] using valueRep
  simpa [Reference.Provenance.X86.materialize, ordinary, rawEq, tagEq] using native

end KProgFormal.ClightRefinement.X86RegisterReadValue
