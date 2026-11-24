import KProgFormal.ClightRefinement.X86AluXorResultEntry

namespace KProgFormal.ClightRefinement.X86AluXorInputs

def temps (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (left right : BitVec 64) : CC.TempEnv :=
  let initial := X86RegisterView.writerInitialTemps binding op
    (X86Width.argument (X86RegisterReadValue.registerByte dst))
    (X86Width.argument (X86RegisterReadValue.registerByte src)) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let ready := X86AluDecode.temps (X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
  let lhs := X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8)
  let rhs := X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)
  X86ShiftLeftSite.afterTemps (X86AluReadXorOperands.temps ready dst src lhs rhs) (.Vlong (lhs ^^^ rhs))

/-- All six incoming fields consumed by the real logical-byte tail. -/
structure Observed (le : CC.TempEnv) (binding : CC.Val) (dst : Fin 16) (size : X86.Size)
    (shift : BitVec 8) (value : BitVec 64) : Prop where
  binding : le.get X86_program_profile_bpf.___x86_bind = some binding
  destination : le.get X86_program_profile_bpf._dst =
    some (.Vint ((X86RegisterReadValue.registerByte dst).setWidth 32))
  operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32))
  width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size)
  result : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value)
  shift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (shift.setWidth 32))

/-- Every tail observation is derived from the exact reached temporary map,
including the distinct-register and same-register/different-lane routes. -/
theorem observations (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (left right : BitVec 64)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (effective : X86Width.result flags = X86ShiftLeft.argument size) :
    Observed (temps binding op imm dst src flags width aux size left right) binding dst size
      ((aux >>> 8).setWidth 8)
      (X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8) ^^^
        X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)) := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals by_cases same : dst = src
  all_goals
    simp +decide [temps, X86ShiftLeftSite.afterTemps, X86AluReadXorOperands.temps,
      X86AluReadXorOperands.selectedTemps, X86AluReadXorSelect.differentLaneTemps,
      X86AluReadSite.selectedTemps, X86AluReadTail.temps, X86AluReadRhs.temps,
      X86AluReadSite.lhsTemps, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      X86AluDecode.field_byte, BitVec.ushiftRight_zero, same, xorCode, effective]

/-- The real decode and source execution retain the original source-lane
field needed by qword pointer selection; no intermediate observation is assumed. -/
theorem source_shift (binding op imm : CC.Val) (dst src : Fin 16) (flags width : BitVec 8)
    (aux : BitVec 32) (size : X86.Size) (left right : BitVec 64) :
    (temps binding op imm dst src flags width aux size left right).get
      X86_program_profile_bpf.___x86_l_src_shift =
      some (.Vint (((aux >>> 16).setWidth 8).setWidth 32)) := by
  by_cases same : dst = src
  all_goals
    simp +decide [temps, X86ShiftLeftSite.afterTemps, X86AluReadXorOperands.temps,
      X86AluReadXorOperands.selectedTemps, X86AluReadXorSelect.differentLaneTemps,
      X86AluReadSite.selectedTemps, X86AluReadTail.temps, X86AluReadRhs.temps,
      X86AluReadSite.lhsTemps, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      X86AluDecode.field_byte, same]

/-- The genuine eight-argument call derives both source execution and all
six tail inputs from the original reader/helper bodies and actual caller heap. -/
theorem entry (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (caller : CC.Mem) (k : CC.Cont) (op imm : CC.Val) (dst src : Fin 16)
    (flags width tagDst tagSrc : BitVec 8) (aux : BitVec 32) (size : X86.Size)
    (left right : BitVec 64) (widthBlock readerBlock aluBlock bindingBlock cellsBlock : CC.Block)
    (bindingOffset cellsOffset : CC.Integers.Ptrofs)
    (oldBinding : bindingBlock.toNat < caller.nextblock.toNat)
    (oldCells : cellsBlock.toNat < caller.nextblock.toNat)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (different : dst ≠ src ∨ (aux >>> 8).setWidth 8 ≠ (aux >>> 16).setWidth 8)
    (ordinaryDst : dst ≠ 4) (ordinarySrc : src ≠ 4)
    (notStackDst : tagDst ≠ (4#8)) (notStackSrc : tagSrc ≠ (4#8))
    (boundDst : ((aux >>> 8).setWidth 8).toNat < 64)
    (boundSrc : ((aux >>> 16).setWidth 8).toNat < 64)
    (effective : X86Width.result flags = X86ShiftLeft.argument size)
    (widthHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some widthBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv widthBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (readerHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg =
        some readerBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv readerBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg))
    (aluHelper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result =
        some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (cells : CC.Mem.load CC.Mptr caller bindingBlock (CC.Integers.Ptrofs.unsigned bindingOffset) =
      some (.Vptr cellsBlock cellsOffset))
    (leftRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int)))) =
        some (.Vlong left))
    (rightRead : CC.Mem.load CC.Mptr caller cellsBlock
      (CC.Integers.Ptrofs.unsigned (cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int)))) =
        some (.Vlong right))
    (leftTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (dst.val : Int))) + 8)) =
        some (X86Width.argument tagDst))
    (rightTag : CC.Mem.load .Mint8unsigned caller cellsBlock
      (CC.Integers.Ptrofs.unsigned ((cellsOffset + CC.Integers.Ptrofs.repr (16 * (src.val : Int))) + 8)) =
        some (X86Width.argument tagSrc)) :
    InternalRun ge (37 + X86AluReadOperands.length size + 29)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [.Vptr bindingBlock bindingOffset, op,
          X86Width.argument (X86RegisterReadValue.registerByte dst),
          X86Width.argument (X86RegisterReadValue.registerByte src), X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.flags
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (temps (.Vptr bindingBlock bindingOffset) op imm dst src flags width aux size left right)
        (X86RegisterView.writerAllocation ge.genv_cenv caller).2) ∧
    Observed (temps (.Vptr bindingBlock bindingOffset) op imm dst src flags width aux size left right)
      (.Vptr bindingBlock bindingOffset) dst size ((aux >>> 8).setWidth 8)
      (X86RegisterReadLanes.result left size ((aux >>> 8).setWidth 8) ^^^
        X86RegisterReadLanes.result right size ((aux >>> 16).setWidth 8)) := by
  refine ⟨?_, observations _ _ _ dst src flags width aux size left right xorCode effective⟩
  exact X86AluXorResultEntry.from_call ge layout caller k op imm dst src flags width tagDst tagSrc
    aux size left right widthBlock readerBlock aluBlock bindingBlock cellsBlock bindingOffset cellsOffset
    oldBinding oldCells xorCode different ordinaryDst ordinarySrc notStackDst notStackSrc boundDst boundSrc
    effective widthHelper readerHelper aluHelper cells leftRead rightRead leftTag rightTag

end KProgFormal.ClightRefinement.X86AluXorInputs
