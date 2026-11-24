import KProgFormal.ClightRefinement.X86AluReadRhs
import KProgFormal.ClightRefinement.X86RegisterReadNumeric

namespace KProgFormal.ClightRefinement.X86AluReadNativeTail

def length (dst src : Fin 16) (size : X86.Size) : Nat :=
  X86RegisterReadNumeric.length dst size + 4 + 2 + X86RegisterReadNumeric.length src size + 4

def temps (le : CC.TempEnv) (left right : BitVec 64) : CC.TempEnv :=
  X86AluReadRhs.temps (X86AluReadSite.lhsTemps le (.Vlong left)) (.Vlong right)

/-- Starting at the actual LHS call state, both complete native-view reader
bodies and their original caller continuations reach the real dispatcher.
RSP uses its original base loads; both native results follow from initial
representation and source memory, without a callee-run premise. -/
theorem read (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (width : BitVec 8) (highDst highSrc : Bool) (size : X86.Size)
    (dst src : Fin 16) (left right : BitVec 64)
    (widthBlock readerBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (represented : X86RegisterView.RegistersRepresent addresses origins m cellsBlock cellsOffset cpu)
    (legalDst : highDst = true → size = .b ∧ dst.val < 4)
    (legalSrc : highSrc = true → size = .b ∧ src.val < 4)
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
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)))
    (sourceReg : le.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86Width.argument width))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (X86Width.argument (if highSrc then 8 else 0)))
    (cells : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs)) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr m cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : dst ≠ 4 → CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (rightTag : src ≠ 4 → CC.Mem.load .Mint8unsigned m cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (.Vint (0#32)))
    (header : CC.Mem.load CC.Mptr m bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 m baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong origins.stack)) :
    InternalRun ge (length dst src size)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86AluReadSite.arguments (.Vptr bindingBlock (0 : CC.Integers.Ptrofs))
          (X86RegisterReadValue.registerByte dst) width (if highDst then 8 else 0))
        (X86AluReadSite.callContinuation function e le (.Kseq X86ShiftLeftRoute.dispatch k)) m)
      (.State function X86ShiftLeftRoute.dispatch k e
        (temps le (cpu.getReg size (X86.GPR.ofIndex dst) highDst)
          (cpu.getReg size (X86.GPR.ofIndex src) highSrc)) m) := by
  let leftValue := cpu.getReg size (X86.GPR.ofIndex dst) highDst
  let rightValue := cpu.getReg size (X86.GPR.ofIndex src) highSrc
  let ready := X86AluReadSite.lhsTemps le (.Vlong leftValue)
  have bindingReady : ready.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, binding]
  have sourceReady : ready.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, sourceReg]
  have widthReady : ready.get X86_program_profile_bpf.___x86_l_width__1 =
      some (X86Width.argument width) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, widthRead]
  have shiftReady : ready.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument (if highSrc then 8 else 0)) := by
    simp +decide [ready, X86AluReadSite.lhsTemps, CC.PTree.gso, srcShift]
  have readLeft := X86RegisterReadNumeric.call ge layout valueLayout addresses origins m
    (X86AluReadSite.callContinuation function e le (.Kseq X86ShiftLeftRoute.dispatch k))
    cpu dst size width highDst left widthBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
    represented legalDst effective widthHelper cells leftRead leftTag header native
  have leftResume := X86AluReadSite.resume_lhs ge function e le
    (.Kseq X86ShiftLeftRoute.dispatch k) m (.Vlong leftValue)
  have second := X86AluReadRhs.enter ge function e ready (.Kseq X86ShiftLeftRoute.dispatch k)
    m bindingBlock readerBlock (0 : CC.Integers.Ptrofs) (X86RegisterReadValue.registerByte src) width (if highSrc then 8 else 0)
      bindingReady sourceReady widthReady shiftReady readerHelper unshadowed
  have readRight := X86RegisterReadNumeric.call ge layout valueLayout addresses origins m
    (X86AluReadRhs.continuation function e ready (.Kseq X86ShiftLeftRoute.dispatch k))
    cpu src size width highSrc right widthBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
    represented legalSrc effective widthHelper cells rightRead rightTag header native
  have rightResume := X86AluReadRhs.resume ge function e ready k m (.Vlong rightValue)
  exact (((readLeft.trans leftResume).trans second).trans readRight).trans rightResume

end KProgFormal.ClightRefinement.X86AluReadNativeTail
