import KProgFormal.ClightRefinement.X86AluReadNativeTail

namespace KProgFormal.ClightRefinement.X86AluReadNativeOperands

def length (dst src : Fin 16) (size : X86.Size) : Nat :=
  13 + X86AluReadNativeTail.length dst src size

def temps (le : CC.TempEnv) (left right : BitVec 64) : CC.TempEnv :=
  X86AluReadNativeTail.temps (X86AluReadSite.selectedTemps le) left right

/-- The original non-XOR operand selector executes both real reader calls,
their complete ordinary/RSP bodies and original assignments to reach the arithmetic
dispatcher. Both native values come from actual cell/base/width/shift semantics, and the
entire input heap is retained. -/
theorem read (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation width : BitVec 8) (highDst highSrc : Bool) (size : X86.Size)
    (dst src : Fin 16) (left right : BitVec 64)
    (widthBlock readerBlock bindingBlock cellsBlock baseBlock : CC.Block)
    (cellsOffset baseOffset : CC.Integers.Ptrofs)
    (different : operation.setWidth 32 ≠ (2#32))
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
    (opRead : le.get X86_program_profile_bpf.___x86_l_alu = some (X86Width.argument operation))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte dst)))
    (sourceReg : le.get X86_program_profile_bpf._src =
      some (X86Width.argument (X86RegisterReadValue.registerByte src)))
    (widthRead : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86Width.argument width))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (X86Width.argument (if highDst then 8 else 0)))
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
    InternalRun ge (length dst src size) (.State function X86AluDecode.operandReads k e le m)
      (.State function X86ShiftLeftRoute.dispatch k e
        (temps le (cpu.getReg size (X86.GPR.ofIndex dst) highDst)
          (cpu.getReg size (X86.GPR.ofIndex src) highSrc)) m) := by
  let selected := X86AluReadSite.selectedTemps le
  have bindingReady : selected.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock (0 : CC.Integers.Ptrofs)) := by
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
      some (X86Width.argument (if highSrc then 8 else 0)) := by
    simp +decide [selected, X86AluReadSite.selectedTemps,
      CC.PTree.gso, srcShift]
  have first := X86AluReadSite.to_first_read ge function e le k m operation
    (X86RegisterReadValue.registerByte dst) width (if highDst then 8 else 0) bindingBlock readerBlock (0 : CC.Integers.Ptrofs)
      different opRead binding destination widthRead dstShift readerHelper unshadowed
  have rest := X86AluReadNativeTail.read ge layout valueLayout addresses origins cpu function e selected k m
    width highDst highSrc size dst src left right
    widthBlock readerBlock bindingBlock cellsBlock baseBlock cellsOffset baseOffset
    represented legalDst legalSrc effective widthHelper readerHelper unshadowed
    bindingReady sourceReady widthReady shiftReady cells leftRead rightRead leftTag rightTag header native
  simpa only [length, X86AluReadNativeTail.length, temps, Nat.add_assoc] using first.trans rest

/-- Both dispatcher inputs are actual reader results. Decoded operation and
effective width remain available for the existing arithmetic/flag proofs. -/
theorem observations (le : CC.TempEnv) (left right : BitVec 64) :
    (temps le left right).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong left) ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong right) ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_alu =
      le.get X86_program_profile_bpf.___x86_l_alu ∧
    (temps le left right).get X86_program_profile_bpf.___x86_l_width__1 =
      le.get X86_program_profile_bpf.___x86_l_width__1 := by
  simp +decide [temps, X86AluReadNativeTail.temps, X86AluReadRhs.temps, X86AluReadSite.lhsTemps,
    X86AluReadSite.selectedTemps,
    CC.PTree.gss, CC.PTree.gso]

end KProgFormal.ClightRefinement.X86AluReadNativeOperands
