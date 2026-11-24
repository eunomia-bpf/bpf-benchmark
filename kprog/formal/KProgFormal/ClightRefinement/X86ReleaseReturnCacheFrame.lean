import KProgFormal.ClightRefinement.X86ReleaseReturn
import KProgFormal.ClightRefinement.X86ReleaseOuterCacheFrame

namespace KProgFormal.ClightRefinement.X86ReleaseReturnCacheFrame
open X86ReleaseOuterComplete (View)
open X86ReleaseReturn (ObserverOutside FlagsOutside registers preserve_flags)
open X86ReleaseByteCacheFrame (AboveFrame)
open X86ReleaseByteCompleteFrame (PreservingInputs)

/-- Both raw-SP branches complete through the original ALU handler loops,
actual declared-local free and void return. Architectural observations and
caller loads outside the real release footprint survive every source effect.
Initial cache lifetime, cache/ghost ownership and the stronger provider ABI remain explicit. Actual cache-byte reads at or above new SP survive release and local free. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (caller : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places)
    (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places next)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (flags : X86LogicFlagOrder.Locations)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory cells cellOffset cpu)
    (flagValues : X86LogicFlagMemory.FlagsRepresent memory flags cpu.flags)
    (cellsOutside : ObserverOutside stack places cells)
    (flagsOutside : FlagsOutside stack places flags)
    (cacheOld : stack.toNat < caller.nextblock.toNat)
    (cellsOld : cells.toNat < caller.nextblock.toNat)
    (flagsOld : flags.cf.1.toNat < caller.nextblock.toNat ∧ flags.zf.1.toNat < caller.nextblock.toNat ∧
      flags.sf.1.toNat < caller.nextblock.toNat ∧ flags.overflow.1.toNat < caller.nextblock.toNat ∧
      flags.pf.1.toNat < caller.nextblock.toNat)
    (access : memory.access = (X86RegisterView.writerAllocation ge.genv_cenv caller).2.access)
    (boundary : CC.isCallCont k = true) :
    ∃ trace final, CC.Star (CC.Step2 ge)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip
        (X86ShiftWriteback.tableCont (X86AluEntry.continuation k))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).1 le memory) trace
      (.Returnstate .Vundef k final) ∧
    X86RegisterView.RegistersRepresent addresses origins final cells cellOffset cpu ∧
    X86LogicFlagMemory.FlagsRepresent final flags cpu.flags ∧
    final.nextblock = memory.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (X86RegisterView.writerAllocation ge.genv_cenv caller).1,
      ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
      ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
    (∀ chunk block offset, block.toNat < caller.nextblock.toNat → ObserverOutside stack places block →
      CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) ∧
    AboveFrame stack base next memory final := by
  obtain ⟨trace, middle, finalTemps, run, finalView, sourceAccess, sourceNext, frame, aboveFrame⟩ :=
    X86ReleaseOuterCacheFrame.all_offsets ge layout stackLayout valueLayout
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (X86RegisterView.writerAllocation ge.genv_cenv caller).1 le (X86AluEntry.continuation k) memory
      binding stack cells input helper base cellOffset places old next symbol global notLocal helperSymbol helperGlobal
      helperNotLocal bindingSeparate cellsSeparate cacheOutside metadataSeparate available view bindingRead destination oldSp
  have middleRegisters := registers addresses origins memory middle cells cellOffset cpu stack places frame cellsOutside represented
  have middleFlags := preserve_flags memory middle stack places flags cpu.flags frame flagsOutside flagValues
  obtain ⟨final, returned, callerFrame, contents, nextblock, released⟩ :=
    X86AluReturn.finish ge caller middle finalTemps k boundary (sourceAccess.trans access)
  refine ⟨trace, final, ?_, X86AluReturn.registers callerFrame addresses origins cells cellOffset cpu cellsOld middleRegisters,
    X86AluReturn.flags callerFrame flags cpu.flags flagsOld middleFlags,
    nextblock.trans sourceNext, released, ?_, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run returned.sound
  · intro chunk block offset oldBlock outside
    exact (callerFrame.load chunk block offset oldBlock).trans (frame chunk block offset outside.1 outside.2)
  · intro readSlot readLane above
    exact (callerFrame.load .Mint8unsigned stack _ cacheOld).trans (aboveFrame readSlot readLane above)

/-- The actual writer also retains its load loop. Its two genuine exit
transitions precede the original handler loops, local free and void return. -/
theorem from_load (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (caller : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding stack cells input helper : CC.Block) (base cellOffset : CC.Integers.Ptrofs)
    (places : X86CallFrameComplete.Places) (old next : BitVec 64)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some X86RegisterWriteRspReleaseWord.inputFunction)
    (notLocal : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._native_lab_entry_input = none)
    (helperSymbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_call_frame_values = some helper)
    (helperGlobal : CC.Genv.findFunctPtr ge.genv_genv helper = some (.Internal X86CallFrameEntry.handler))
    (helperNotLocal : (X86RegisterView.writerAllocation ge.genv_cenv caller).1.get X86_program_profile_bpf._x86_sim_inline_call_frame_values = none)
    (bindingSeparate : binding ≠ stack) (cellsSeparate : cells ≠ stack)
    (cacheOutside : X86CallFrameComplete.Outside places stack)
    (metadataSeparate : X86CallFrameComplete.Separated binding places)
    (available : PreservingInputs ge binding stack base next)
    (view : View memory binding stack cells base cellOffset places next)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (destination : le.get X86_program_profile_bpf._dst = some (.Vint (4#32)))
    (oldSp : le.get X86_program_profile_bpf.___x86_write_old_sp__5 = some (.Vlong old))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (cpu : X86.Cpu) (flags : X86LogicFlagOrder.Locations)
    (represented : X86RegisterView.RegistersRepresent addresses origins memory cells cellOffset cpu)
    (flagValues : X86LogicFlagMemory.FlagsRepresent memory flags cpu.flags)
    (cellsOutside : ObserverOutside stack places cells)
    (flagsOutside : FlagsOutside stack places flags)
    (cacheOld : stack.toNat < caller.nextblock.toNat)
    (cellsOld : cells.toNat < caller.nextblock.toNat)
    (flagsOld : flags.cf.1.toNat < caller.nextblock.toNat ∧ flags.zf.1.toNat < caller.nextblock.toNat ∧
      flags.sf.1.toNat < caller.nextblock.toNat ∧ flags.overflow.1.toNat < caller.nextblock.toNat ∧
      flags.pf.1.toNat < caller.nextblock.toNat)
    (access : memory.access = (X86RegisterView.writerAllocation ge.genv_cenv caller).2.access)
    (boundary : CC.isCallCont k = true) :
    ∃ trace final, CC.Star (CC.Step2 ge)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG .Sskip
        (X86ShiftWriteback.tableCont (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)))
        (X86RegisterView.writerAllocation ge.genv_cenv caller).1 le memory) trace
      (.Returnstate .Vundef k final) ∧
    X86RegisterView.RegistersRepresent addresses origins final cells cellOffset cpu ∧
    X86LogicFlagMemory.FlagsRepresent final flags cpu.flags ∧
    final.nextblock = memory.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (X86RegisterView.writerAllocation ge.genv_cenv caller).1,
      ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
      ∀ kind permission, CC.Mem.perm final row.1 offset kind permission = false) ∧
    (∀ chunk block offset, block.toNat < caller.nextblock.toNat → ObserverOutside stack places block →
      CC.Mem.load chunk final block offset = CC.Mem.load chunk memory block offset) ∧
    AboveFrame stack base next memory final := by
  obtain ⟨trace, middle, finalTemps, run, finalView, sourceAccess, sourceNext, frame, aboveFrame⟩ :=
    X86ReleaseOuterCacheFrame.all_offsets ge layout stackLayout valueLayout
      X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
      (X86RegisterView.writerAllocation ge.genv_cenv caller).1 le (X86ShiftWriteback.loadCont (X86AluEntry.continuation k)) memory
      binding stack cells input helper base cellOffset places old next symbol global notLocal helperSymbol helperGlobal
      helperNotLocal bindingSeparate cellsSeparate cacheOutside metadataSeparate available view bindingRead destination oldSp
  have middleRegisters := registers addresses origins memory middle cells cellOffset cpu stack places frame cellsOutside represented
  have middleFlags := preserve_flags memory middle stack places flags cpu.flags frame flagsOutside flagValues
  obtain ⟨final, returned, callerFrame, contents, nextblock, released⟩ :=
    X86AluReturn.finish ge caller middle finalTemps k boundary (sourceAccess.trans access)
  refine ⟨trace, final, ?_, X86AluReturn.registers callerFrame addresses origins cells cellOffset cpu cellsOld middleRegisters,
    X86AluReturn.flags callerFrame flags cpu.flags flagsOld middleFlags,
    nextblock.trans sourceNext, released, ?_, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using
      star_trans (star_trans run (X86ShiftWriteback.load_exit ge
        X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG
        (X86RegisterView.writerAllocation ge.genv_cenv caller).1 finalTemps
        (X86AluEntry.continuation k) middle).sound) returned.sound
  · intro chunk block offset oldBlock outside
    exact (callerFrame.load chunk block offset oldBlock).trans (frame chunk block offset outside.1 outside.2)
  · intro readSlot readLane above
    exact (callerFrame.load .Mint8unsigned stack _ cacheOld).trans (aboveFrame readSlot readLane above)

end KProgFormal.ClightRefinement.X86ReleaseReturnCacheFrame
