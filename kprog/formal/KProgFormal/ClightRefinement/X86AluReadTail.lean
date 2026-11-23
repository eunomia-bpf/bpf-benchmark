import KProgFormal.ClightRefinement.X86AluReadRhs

namespace KProgFormal.ClightRefinement.X86AluReadTail

def length (size : X86.Size) : Nat :=
  X86RegisterReadScalar.length size + 4 + 2 + X86RegisterReadScalar.length size + 4

def temps (le : CC.TempEnv) (left right : BitVec 64) : CC.TempEnv :=
  X86AluReadRhs.temps (X86AluReadSite.lhsTemps le (.Vlong left)) (.Vlong right)

/-- Starting at the actual LHS call state, both complete scalar reader
bodies and their original caller continuations reach the real dispatcher.
No read-result or callee-execution premise is assumed. -/
theorem read (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (width shiftDst shiftSrc tagDst tagSrc : BitVec 8) (size : X86.Size)
    (dst src : Fin 16) (left right : BitVec 64)
    (widthBlock readerBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
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
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock bindingOffset))
    (sourceReg : le.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86Width.argument width))
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
    InternalRun ge (length size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock bindingOffset)
          (X86RegisterReadValue.registerByte dst) width shiftDst)
        (X86AluReadSite.callContinuation function e le (.Kseq X86ShiftLeftRoute.dispatch k)) m)
      (.State function X86ShiftLeftRoute.dispatch k e
        (temps le (X86RegisterReadLanes.result left size shiftDst)
          (X86RegisterReadLanes.result right size shiftSrc)) m) := by
  let leftValue := X86RegisterReadLanes.result left size shiftDst
  let rightValue := X86RegisterReadLanes.result right size shiftSrc
  let ready := X86AluReadSite.lhsTemps le (.Vlong leftValue)
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock bindingOffset) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, binding]
  have sourceReady : ready.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, sourceReg]
  have widthReady : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86Width.argument width) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, widthRead]
  have shiftReady : ready.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument shiftSrc) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, srcShift]
  have readLeft := X86RegisterReadScalar.call ge layout m
    (X86AluReadSite.callContinuation function e le (.Kseq X86ShiftLeftRoute.dispatch k))
      dst width shiftDst tagDst size left widthBlock bindingBlock cellsBlock bindingOffset cellsOffset
        ordinaryDst notStackDst boundDst effective widthHelper cells leftRead leftTag
  have leftResume := X86AluReadSite.resume_lhs ge function e le
    (.Kseq X86ShiftLeftRoute.dispatch k) m (.Vlong leftValue)
  have second := X86AluReadRhs.enter ge function e ready (.Kseq X86ShiftLeftRoute.dispatch k)
    m bindingBlock readerBlock bindingOffset (X86RegisterReadValue.registerByte src) width shiftSrc
      bindingReady sourceReady widthReady shiftReady readerHelper unshadowed
  have readRight := X86RegisterReadScalar.call ge layout m
    (X86AluReadRhs.continuation function e ready (.Kseq X86ShiftLeftRoute.dispatch k))
      src width shiftSrc tagSrc size right widthBlock bindingBlock cellsBlock bindingOffset cellsOffset
        ordinarySrc notStackSrc boundSrc effective widthHelper cells rightRead rightTag
  have rightResume := X86AluReadRhs.resume ge function e ready k m (.Vlong rightValue)
  exact (((readLeft.trans leftResume).trans second).trans readRight).trans rightResume

end KProgFormal.ClightRefinement.X86AluReadTail
