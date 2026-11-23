import KProgFormal.ClightRefinement.X86AluReadTail

namespace KProgFormal.ClightRefinement.X86AluReadOperands

def length (size : X86.Size) : Nat :=
  13 + X86RegisterReadScalar.length size + 4 + 2 + X86RegisterReadScalar.length size + 4

def temps (le : CC.TempEnv) (left right : BitVec 64) : CC.TempEnv :=
  X86AluReadTail.temps (X86AluReadSite.selectedTemps le) left right

/-- The original non-XOR operand selector executes both real reader calls,
their complete scalar bodies and original assignments to reach the arithmetic
dispatcher. Both values come from actual cell/width/shift semantics, and the
entire input heap is retained. -/
theorem read (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation width shiftDst shiftSrc tagDst tagSrc : BitVec 8) (size : X86.Size)
    (dst src : Fin 16) (left right : BitVec 64)
    (widthBlock readerBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (different : operation.setWidth 32 ≠ (2#32))
    (ordinaryDst : dst ≠ 4) (ordinarySrc : src ≠ 4)
    (notStackDst : tagDst ≠ (4#8)) (notStackSrc : tagSrc ≠ (4#8))
    (boundDst : shiftDst.toNat < 64) (boundSrc : shiftSrc.toNat < 64)
    (effective : X86Width.result width = X86ShiftLeft.argument size)
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (readerHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some readerBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv readerBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_read_reg = none)
    (opRead : le.get X86_program_profile_bpf.___x86_l_alu = some (X86Width.argument operation))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte dst)))
    (sourceReg : le.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86Width.argument width))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (X86Width.argument shiftDst))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (X86Width.argument shiftSrc))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int))) + 8)) =
        some (X86Width.argument tagDst))
    (rightTag : CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (X86Width.argument tagSrc)) :
    InternalRun ge (length size) (.State function X86AluDecode.operandReads k e le m)
      (.State function X86ShiftLeftRoute.dispatch k e
        (temps le (X86RegisterReadLanes.result left size shiftDst)
          (X86RegisterReadLanes.result right size shiftSrc)) m) := by
  let selected := X86AluReadSite.selectedTemps le
  have bindingReady : selected.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [selected, X86AluReadSite.selectedTemps,
      CC.PTree.gso, binding]
  have sourceReady : selected.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)) := by
    simp +decide [selected, X86AluReadSite.selectedTemps,
      CC.PTree.gso, sourceReg]
  have widthReady : selected.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86Width.argument width) := by
    simp +decide [selected, X86AluReadSite.selectedTemps,
      CC.PTree.gso, widthRead]
  have shiftReady : selected.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument shiftSrc) := by
    simp +decide [selected, X86AluReadSite.selectedTemps,
      CC.PTree.gso, srcShift]
  have first := X86AluReadSite.to_first_read ge function e le k m operation
    (X86RegisterReadValue.registerByte dst) width shiftDst bindingBlock readerBlock bindingOffset
      different opRead binding destination widthRead dstShift readerHelper unshadowed
  have rest := X86AluReadTail.read ge layout function e selected k m
    width shiftDst shiftSrc tagDst tagSrc size dst src left right
    widthBlock readerBlock bindingBlock cellsBlock bindingOffset cellsOffset
    ordinaryDst ordinarySrc notStackDst notStackSrc boundDst boundSrc effective
    widthHelper readerHelper unshadowed bindingReady sourceReady widthReady shiftReady
    cells leftRead rightRead leftTag rightTag
  simpa only [length, X86AluReadTail.length, temps, Nat.add_assoc] using first.trans rest

/-- Both dispatcher inputs are actual reader results. Decoded operation and
effective width remain available for the existing arithmetic/flag proofs. -/
theorem observations (le : CC.TempEnv) (left right : BitVec 64) :
    (temps le left right).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong left) ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong right) ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_alu =
      le.get X86_program_profile_bpf.___x86_l_alu ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_width__1 =
      le.get X86_program_profile_bpf.___x86_l_width__1 := by
  simp +decide [temps, X86AluReadTail.temps, X86AluReadRhs.temps, X86AluReadSite.lhsTemps,
    X86AluReadSite.selectedTemps,
    CC.PTree.gss, CC.PTree.gso]

end KProgFormal.ClightRefinement.X86AluReadOperands
