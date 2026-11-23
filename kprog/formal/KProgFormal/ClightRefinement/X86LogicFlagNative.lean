import KProgFormal.ClightRefinement.X86LogicFlagMemory

namespace KProgFormal.ClightRefinement.X86LogicFlagNative
open X86LogicFlagOrder X86LogicFlagStores X86LogicFlagMemory

/-- The actual31-step logical store sequence yields the five represented
external x86lean logical flag bytes and preserves its binding header. Every
later source load and final readback follows from the actual initial loads,
ordered stores, header separation and distinct byte addresses. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m cfHeap zfHeap sfHeap ofHeap after : CC.Mem) (bindingBlock : CC.Block) (places : Locations)
    (value : BitVec 64) (size : X86.Size) (af : Bool) (before : X86.Flags)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong (X86.Value.trunc size value)))
    (bitsRead : le.get X86_program_profile_bpf.___x86_fl_bits = some (.Vint (BitVec.ofNat 32 size.bits)))
    (headers : HeaderLoads m bindingBlock places)
    (different : X86LogicFlagMemory.Distinct places)
    (separate : places.cf.1 ≠ bindingBlock ∧ places.zf.1 ≠ bindingBlock ∧
      places.sf.1 ≠ bindingBlock ∧ places.overflow.1 ≠ bindingBlock ∧ places.pf.1 ≠ bindingBlock)
    (cfStored : CC.Mem.store .Mint8unsigned m places.cf.1 (CC.Integers.Ptrofs.unsigned places.cf.2)
      (.Vint (0#32)) = some cfHeap)
    (zfStored : CC.Mem.store .Mint8unsigned cfHeap places.zf.1 (CC.Integers.Ptrofs.unsigned places.zf.2)
      (X86ShiftFlagZF.bit (X86.Value.trunc size value)) = some zfHeap)
    (sfStored : CC.Mem.store .Mint8unsigned zfHeap places.sf.1 (CC.Integers.Ptrofs.unsigned places.sf.2)
      (signByte (X86.Value.trunc size value) size) = some sfHeap)
    (ofStored : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (.Vint (0#32)) = some ofHeap)
    (pfStored : CC.Mem.store .Mint8unsigned ofHeap places.pf.1 (CC.Integers.Ptrofs.unsigned places.pf.2)
      (X86ShiftFlagPF.bit (X86.Value.trunc size value)) = some after) :
    InternalRun ge 31 (.State function X86LogicFlagWidths.rest k e le m)
      (.State function .Sskip k e (X86LogicFlagOrder.temps le places) after) ∧
    HeaderLoads after bindingBlock places ∧
    FlagsRepresent after places (X86.Flags.logic size (X86.Value.trunc size value) af before) := by
  let target := X86.Flags.logic size (X86.Value.trunc size value) af before
  have execution := X86LogicFlagOrder.internal ge bindingsLayout valueLayout function e le k
    m cfHeap zfHeap sfHeap ofHeap after bindingBlock places (X86.Value.trunc size value) size
    binding word bitsRead headers separate cfStored zfStored sfStored ofStored pfStored
  have values := X86LogicFlagStores.native_values value size af before
  have cfValue : (.Vint (0#32) : CC.Val) = flag target.cf := by
    simpa only [flag, target] using congrArg
      (fun tuple : CC.Val × CC.Val × CC.Val × CC.Val × CC.Val => tuple.1) values
  have cfWrite : CC.Mem.store .Mint8unsigned m places.cf.1
      (CC.Integers.Ptrofs.unsigned places.cf.2) (flag target.cf) = some cfHeap := by
    rw [← cfValue]
    exact cfStored
  have zfValue : (X86ShiftFlagZF.bit (X86.Value.trunc size value) : CC.Val) = flag target.zf := by
    simpa only [flag, target] using congrArg
      (fun tuple : CC.Val × CC.Val × CC.Val × CC.Val × CC.Val => tuple.2.1) values
  have zfWrite : CC.Mem.store .Mint8unsigned cfHeap places.zf.1
      (CC.Integers.Ptrofs.unsigned places.zf.2) (flag target.zf) = some zfHeap := by
    rw [← zfValue]
    exact zfStored
  have sfValue : (signByte (X86.Value.trunc size value) size : CC.Val) = flag target.sf := by
    simpa only [flag, target] using congrArg
      (fun tuple : CC.Val × CC.Val × CC.Val × CC.Val × CC.Val => tuple.2.2.1) values
  have sfWrite : CC.Mem.store .Mint8unsigned zfHeap places.sf.1
      (CC.Integers.Ptrofs.unsigned places.sf.2) (flag target.sf) = some sfHeap := by
    rw [← sfValue]
    exact sfStored
  have overflowValue : (.Vint (0#32) : CC.Val) = flag target.of := by
    simpa only [flag, target] using congrArg
      (fun tuple : CC.Val × CC.Val × CC.Val × CC.Val × CC.Val => tuple.2.2.2.1) values
  have overflowWrite : CC.Mem.store .Mint8unsigned sfHeap places.overflow.1
      (CC.Integers.Ptrofs.unsigned places.overflow.2) (flag target.of) = some ofHeap := by
    rw [← overflowValue]
    exact ofStored
  have pfValue : (X86ShiftFlagPF.bit (X86.Value.trunc size value) : CC.Val) = flag target.pf := by
    simpa only [flag, target] using congrArg
      (fun tuple : CC.Val × CC.Val × CC.Val × CC.Val × CC.Val => tuple.2.2.2.2) values
  have pfWrite : CC.Mem.store .Mint8unsigned ofHeap places.pf.1
      (CC.Integers.Ptrofs.unsigned places.pf.2) (flag target.pf) = some after := by
    rw [← pfValue]
    exact pfStored
  have represented := X86LogicFlagMemory.stores m cfHeap zfHeap sfHeap ofHeap after places target different
    cfWrite zfWrite sfWrite overflowWrite pfWrite
  exact ⟨execution.1, execution.2, represented⟩

end KProgFormal.ClightRefinement.X86LogicFlagNative
