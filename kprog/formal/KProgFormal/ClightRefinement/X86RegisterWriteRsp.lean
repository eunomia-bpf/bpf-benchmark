import KProgFormal.ClightRefinement.X86RegisterReadRsp
import KProgFormal.ClightRefinement.X86ShiftWriteback

namespace KProgFormal.ClightRefinement.X86RegisterWriteRsp

def temps (le : CC.TempEnv) (baseBlock : CC.Block) (baseOffset : CC.Integers.Ptrofs)
    (value nativeBase : BitVec 64) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'147 (.Vlong value)).set
    X86_program_profile_bpf._t'148 (.Vptr baseBlock baseOffset)).set
    X86_program_profile_bpf._t'149 (.Vlong nativeBase)

/-- The actual RSP reverse-materialization gate loads the local numerical
word, the real native-base pointer and its word, then stores their difference
in the local union. The following table writer is reached in14 transitions. -/
theorem run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (memory after : CC.Mem) (bindingBlock localBlock baseBlock : CC.Block)
    (baseOffset : CC.Integers.Ptrofs) (value nativeBase : BitVec 64)
    (declared : e.get X86_program_profile_bpf.___x86_wr_cell__2 =
      some (localBlock, .Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (current : CC.Mem.load CC.Mptr memory localBlock 0 = some (.Vlong value))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong nativeBase))
    (stored : CC.Mem.store CC.Mptr memory localBlock 0 (.Vlong (value - nativeBase)) = some after) :
    InternalRun ge 14
      (.State function .Sskip (.Kseq X86ShiftWriteback.storageTail k) e le memory)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_112 k e
        (temps le baseBlock baseOffset value nativeBase) after) := by
  have localAddress : CC.lvalOfVar ge e X86_program_profile_bpf.___x86_wr_cell__2
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) = some (localBlock, 0, .Full) := by
    simp only [CC.lvalOfVar, declared]
    rfl
  have pointerAddress (offset : CC.Integers.Ptrofs) :=
    X86RegisterReadValue.pointer_address ge layout localBlock offset
  have pointerZero := pointerAddress (0 : CC.Integers.Ptrofs)
  have pointerBits : CC.lvalOfField ge
      (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr)
      X86_program_profile_bpf._ptr (.Vptr localBlock (0#64)) =
      some (localBlock, (0#64), .Full) := pointerZero
  have field : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._native_stack_base (.Vptr bindingBlock (0#64)) =
      some (bindingBlock, 112, .Full) := by
    simp only [CC.lvalOfField, layout.bindings, X86RegisterReadRsp.base_offset ge valueLayout]
    rfl
  have unionAccess : CC.accessMode (.Tunion X86_program_profile_bpf._x86_sim_gpr CC.noattr) =
      .By_copy := rfl
  have structAccess : CC.accessMode (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) =
      .By_copy := rfl
  have ptrAccess : CC.accessMode (CC.tptr CC.tvoid) = .By_value CC.Mptr := rfl
  have ptrLongAccess : CC.accessMode (CC.tptr CC.tulong) = .By_value CC.Mptr := rfl
  have longAccess : CC.accessMode CC.tulong = .By_value .Mint64 := rfl
  have unsigned112 : CC.Integers.Ptrofs.unsigned (112#64) = 112 := rfl
  have unsigned0 : CC.Integers.Ptrofs.unsigned (0#64) = 0 := rfl
  rw [X86ShiftWriteback.storage_tail_source]
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep,
    X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_107, temps,
    CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof,
    localAddress, pointerBits, field, unionAccess, structAccess, ptrAccess, ptrLongAccess,
    longAccess, CC.Mem.loadv, CC.Mem.storev, current, header, native, stored, unsigned112, unsigned0,
    binding, destination, CC.PTree.gss, CC.PTree.gso, CC.tptr, CC.Archi.ptr64_eq,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semSub, CC.Cop.classifySub, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tlong,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue,
    CC.Integers.Int64.sub, CC.Integers.MI.sub, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Eapp, CC.E0, List.nil_append, true_and, ite_true, ite_false]
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doEvalExpr,
    CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.typeof, localAddress, pointerBits, field,
    binding, destination, current, header, native, CC.Mem.loadv, CC.Mem.storev, CC.PTree.gss, CC.PTree.gso,
    unsigned0, unsigned112, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.semSub, CC.Cop.classifySub, CC.Cop.semBinaryOperation, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tptr, CC.tvoid, CC.tint, CC.tlong, CC.tulong,
    CC.Archi.ptr64_eq, CC.accessMode, CC.Integers.Int64.sub, CC.Integers.MI.sub, stored]

end KProgFormal.ClightRefinement.X86RegisterWriteRsp
