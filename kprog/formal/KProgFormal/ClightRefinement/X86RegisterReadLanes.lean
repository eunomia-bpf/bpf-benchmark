import KProgFormal.ClightRefinement.X86RegisterReadTag

namespace KProgFormal.ClightRefinement.X86RegisterReadLanes

def length : X86.Size → Nat
  | .b => 9
  | .w => 13
  | .d | .q => 17

def result (value : BitVec 64) (size : X86.Size) (shift : BitVec 8) : BitVec 64 :=
  X86.Value.trunc size (value >>> (if size = .b then shift.toNat else 0))

def temps (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) (shift : BitVec 8) : CC.TempEnv :=
  let shifted := le.set X86_program_profile_bpf._t'4 (.Vint (if size = .b then shift.setWidth 32 else 0))
  let masked := shifted.set X86_program_profile_bpf._t'5 (.Vlong size.mask)
  let selected := if size = .b then masked else
    if size = .w then masked.set X86_program_profile_bpf._t'5 (.Vlong size.mask) else
      (masked.set X86_program_profile_bpf._t'5 (.Vlong size.mask)).set
        X86_program_profile_bpf._t'5 (.Vlong size.mask)
  selected.set X86_program_profile_bpf._value (.Vlong (result value size shift))

/-- The actual width/shift selectors and mask expression produce the shared
x86lean width view, with the complete memory unchanged. -/
theorem scalar (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m : CC.Mem) (value : BitVec 64) (size : X86.Size) (shift : BitVec 8)
    (width : le.get X86_program_profile_bpf.___x86_rd_width = some (X86ShiftLeft.argument size))
    (shiftRead : le.get X86_program_profile_bpf.___x86_rd_shift = some (X86Width.argument shift))
    (word : le.get X86_program_profile_bpf.___x86_rd_value = some (.Vlong value))
    (bound : shift.toNat < 64) :
    InternalRun ge (length size)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadTag.lanes k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg .Sskip k e
        (temps le value size shift) m) := by
  have shiftBound : (shift.setWidth 32).ult (64#32) = true := by
    simp only [BitVec.ult_eq_decide, BitVec.toNat_setWidth_of_le (by decide : 8 ≤ 32),
      BitVec.toNat_ofNat, decide_eq_true_eq]
    exact bound
  have shiftLong : CC.Integers.Int64.repr (CC.Integers.Int.unsigned (shift.setWidth 32)) =
      shift.setWidth 64 := X86RegisterReadEntry.unsigned_byte shift
  have shiftNat : (CC.Integers.Int.unsigned (shift.setWidth 32) % 18446744073709551616).toNat =
      shift.toNat := by
    rw [CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      BitVec.toNat_setWidth_of_le (by decide : 8 ≤ 32)]
    rw [Int.emod_eq_of_lt (Int.ofNat_zero_le _) (by omega)]
    rfl
  have zeroNat : (CC.Integers.Int.unsigned (0#32) % 18446744073709551616).toNat = 0 := rfl
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, X86RegisterReadTag.lanes,
      X86_program_profile_bpf.s_x86_sim_inline_read_reg_4,
      X86_program_profile_bpf.s_x86_sim_inline_read_reg_5,
      length, temps, result, CC.doEvalExpr, CC.typeof, width, shiftRead, word,
      X86ShiftLeft.argument, X86.Size.bytes, X86Width.argument, X86.Value.trunc, X86.Size.mask,
      CC.PTree.gss, CC.PTree.gso, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
      CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.semShr,
      CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semAnd,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.ltu, CC.Integers.MI.ltu, shiftNat, zeroNat,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int64.shru, CC.Integers.MI.shru, CC.Integers.Int64.and, CC.Integers.MI.and,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, shiftBound, shiftLong,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]

end KProgFormal.ClightRefinement.X86RegisterReadLanes
