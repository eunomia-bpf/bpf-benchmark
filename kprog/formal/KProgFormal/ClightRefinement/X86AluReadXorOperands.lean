import KProgFormal.ClightRefinement.X86AluReadXorSelect

namespace KProgFormal.ClightRefinement.X86AluReadXorOperands

def selectedTemps (le : CC.TempEnv) (dst src : Fin 16) : CC.TempEnv :=
  if dst = src then X86AluReadXorSelect.differentLaneTemps le else X86AluReadSite.selectedTemps le

private theorem selected_get (le : CC.TempEnv) (dst src : Fin 16) (query : CC.Ident)
    (four : query ≠ X86_program_profile_bpf._t'4) (five : query ≠ X86_program_profile_bpf._t'5) :
    (selectedTemps le dst src).get query = le.get query := by
  unfold selectedTemps
  split <;> simp only [X86AluReadXorSelect.differentLaneTemps, X86AluReadSite.selectedTemps,
    CC.PTree.gso _ _ _ _ four.symm, CC.PTree.gso _ _ _ _ five.symm]

private theorem register_code_injective : ∀ dst src : Fin 16,
    X86RegisterReadValue.registerByte dst = X86RegisterReadValue.registerByte src → dst = src := by
  decide +kernel

def temps (le : CC.TempEnv) (dst src : Fin 16) (left right : BitVec 64) : CC.TempEnv :=
  X86AluReadTail.temps (selectedTemps le dst src) left right

/-- Both non-shortcut XOR cases execute the original gates, both complete
scalar reader bodies and caller assignments through arithmetic dispatch.
Equal-register/different-lane inputs retain their actual first-test value1. -/
theorem read (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (width shiftDst shiftSrc tagDst tagSrc : BitVec 8) (size : X86.Size)
    (dst src : Fin 16) (left right : BitVec 64)
    (widthBlock readerBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (different : dst ≠ src ∨ shiftDst ≠ shiftSrc)
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
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)))
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
    InternalRun ge (X86AluReadOperands.length size) (.State function X86AluDecode.operandReads k e le m)
      (.State function X86ShiftLeftRoute.dispatch k e
        (temps le dst src (X86RegisterReadLanes.result left size shiftDst)
          (X86RegisterReadLanes.result right size shiftSrc)) m) := by
  let selected := selectedTemps le dst src
  have chosen : InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
      (.State function X86AluReadSite.readStatements (.Kseq X86ShiftLeftRoute.dispatch k) e selected m) := by
    by_cases registers : dst = src
    · subst src
      have lanes : shiftDst ≠ shiftSrc := different.resolve_left (by simp)
      simpa only [selected, selectedTemps, if_pos rfl, ite_true] using
        X86AluReadXorSelect.different_lanes ge function e le k m
          (X86RegisterReadValue.registerByte dst) shiftDst shiftSrc lanes operation
            destination sourceReg dstShift srcShift
    · have codes : X86RegisterReadValue.registerByte dst ≠ X86RegisterReadValue.registerByte src :=
        fun eq => registers (register_code_injective dst src eq)
      simpa only [selected, selectedTemps, if_neg registers] using
        X86AluReadXorSelect.different_registers ge function e le k m
          (X86RegisterReadValue.registerByte dst) (X86RegisterReadValue.registerByte src)
            codes operation destination sourceReg
  have bindingReady := (selected_get le dst src X86_program_profile_bpf.___x86_bind
    (by decide +kernel) (by decide +kernel)).trans binding
  have dstReady := (selected_get le dst src X86_program_profile_bpf._dst
    (by decide +kernel) (by decide +kernel)).trans destination
  have srcReady := (selected_get le dst src X86_program_profile_bpf._src
    (by decide +kernel) (by decide +kernel)).trans sourceReg
  have widthReady := (selected_get le dst src X86_program_profile_bpf.___x86_l_width__1
    (by decide +kernel) (by decide +kernel)).trans widthRead
  have dstShiftReady := (selected_get le dst src X86_program_profile_bpf.___x86_l_dst_shift
    (by decide +kernel) (by decide +kernel)).trans dstShift
  have srcShiftReady := (selected_get le dst src X86_program_profile_bpf.___x86_l_src_shift
    (by decide +kernel) (by decide +kernel)).trans srcShift
  have first := X86AluReadSite.first_read ge function e selected (.Kseq X86ShiftLeftRoute.dispatch k) m
    bindingBlock readerBlock bindingOffset (X86RegisterReadValue.registerByte dst) width shiftDst
      bindingReady dstReady widthReady dstShiftReady readerHelper unshadowed
  have tail := X86AluReadTail.read ge layout function e selected k m
    width shiftDst shiftSrc tagDst tagSrc size dst src left right
    widthBlock readerBlock bindingBlock cellsBlock bindingOffset cellsOffset
    ordinaryDst ordinarySrc notStackDst notStackSrc boundDst boundSrc effective
    widthHelper readerHelper unshadowed bindingReady srcReady widthReady srcShiftReady
    cells leftRead rightRead leftTag rightTag
  simpa only [X86AluReadOperands.length, X86AluReadTail.length, temps, selected, ← Nat.add_assoc] using
    (chosen.trans first).trans tail

end KProgFormal.ClightRefinement.X86AluReadXorOperands
