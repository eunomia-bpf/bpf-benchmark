import KProgFormal.ClightRefinement.X86RegisterReadTag

namespace KProgFormal.ClightRefinement.X86RegisterTagCall

private theorem bound : ∀ index : Fin 16,
    ((X86RegisterReadValue.registerByte index).setWidth 64).ult (16#64) = true := by decide +kernel

/-- The actual two-argument tag helper reads every architectural table row,
returns the exact tag byte and leaves the complete caller memory unchanged.
This includes register4 and every possible tag, without a scalar restriction. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (memory : CC.Mem) (k : CC.Cont) (index : Fin 16) (tag : BitVec 8)
    (bindingBlock cellsBlock : CC.Block) (bindingOffset base : CC.Integers.Ptrofs)
    (cells : CC.Mem.load CC.Mptr memory bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock base))
    (current : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    InternalRun ge 21
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock bindingOffset,
          .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)] k memory)
      (.Returnstate (X86Width.argument tag) (CC.callCont k) memory) := by
  let code := X86RegisterReadValue.registerByte index
  have below : CC.Cop.semBinaryOperation ge.genv_cenv .Olt
      (.Vlong (code.setWidth 64)) CC.tulong (.Vint (16#32))
      (.Tint .I32 .Unsigned CC.noattr) memory = some (.Vint (1#32)) := by
    change some (CC.Val.ofBool ((code.setWidth 64).ult (16#64))) = _
    rw [bound index]
    rfl
  have narrow : CC.Cop.semCast (.Vlong (code.setWidth 64)) CC.tulong CC.tuchar memory =
      some (X86Width.argument code) := by
    change some (CC.Val.Vint (((code.setWidth 64).setWidth 32) &&& (BitVec.allOnes 8).setWidth 32)) = _
    have down : (code.setWidth 64).setWidth 32 = code.setWidth 32 := by simp
    rw [down, ← BitVec.setWidth_and, BitVec.and_allOnes]
    rfl
  have byteWord : CC.Cop.semCast (X86Width.argument tag) CC.tuchar CC.tuint memory =
      some (X86Width.argument tag) := rfl
  have wordByte : CC.Cop.semCast (X86Width.argument tag) CC.tuint CC.tuchar memory =
      some (X86Width.argument tag) := by
    change some (CC.Val.Vint ((tag.setWidth 32) &&& (BitVec.allOnes 8).setWidth 32)) = _
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]
    rfl
  have byteByte : CC.Cop.semCast (X86Width.argument tag) CC.tuchar CC.tuchar memory =
      some (X86Width.argument tag) := wordByte
  have indexAdd := X86RegisterReadValue.cell_add ge layout memory cellsBlock base index
  have structAccess (name : CC.Ident) : CC.accessMode (.Tstruct name CC.noattr) = .By_copy := rfl
  have ptrAccess (ty : CC.Ty) : CC.accessMode (.Tpointer ty CC.noattr) = .By_value CC.Mptr := rfl
  have byteAccess : CC.accessMode (.Tint .I8 .Unsigned CC.noattr) = .By_value .Mint8unsigned := rfl
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  dsimp only [code] at below narrow indexAdd
  simp only [CC.tptr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, X86Width.argument] at below narrow byteWord wordByte byteByte indexAdd
  apply internalRun_of_steps
  all_goals
    simp +decide only [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
      X86_program_profile_bpf.f_x86_sim_inline_reg_tag, CC.listNorepet, CC.varNames,
      CC.listDisjoint, CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
      CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      BitVec.ofInt_ofNat, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      X86RegisterReadValue.table_address ge layout, X86RegisterReadTag.tag_address ge layout,
      below, narrow, byteWord, wordByte, byteByte, indexAdd,
      structAccess, ptrAccess, byteAccess, CC.Mem.loadv, cells, current,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Eapp, CC.E0, CC.blocksOfEnv, CC.emptyEnv, CC.Mem.freeList, empty,
      List.map_nil, List.nil_append, true_and, ite_true, ite_false]

end KProgFormal.ClightRefinement.X86RegisterTagCall
