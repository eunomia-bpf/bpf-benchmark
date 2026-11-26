import KProgFormal.ClightRefinement.Arm64MemsetPhysicalByte
import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetByteNative

/-- Actual STRB W1,[X0], using the mature unsigned-immediate class. -/
def fields : Reg_unsigned_imm_cls :=
  { size := 0, V := 0, opc := 0, imm12 := 0, Rn := 0, Rt := 1 }

theorem decoded_word : decode_raw_inst (0x39000001#32) =
    some (.LDST (.Reg_unsigned_imm fields)) := by decide +kernel

def instruction : Reference.AArch64.Instruction :=
  ⟨0x39000001#32,.LDST (.Reg_unsigned_imm fields),decoded_word⟩

/-- Execute the actual imported STRB body against its real checked write. -/
theorem execute (s : Reference.AArch64.State)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s 1).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err written = .None) :
    LDST.exec_reg_imm_unsigned_offset fields s.machine .checked =
      write_pc (read_pc s.machine + 4#64) written := by
  change r (.GPR (0#5)) s.machine = address at base
  change (r (.GPR (1#5)) s.machine).setWidth 8 = value at byte
  simp +decide [LDST.exec_reg_imm_unsigned_offset,fields,LDST.exec_reg_imm_common,
    LDST.exec_reg_imm_common_offset,
    LDST.reg_imm_operation,ldst_read,read_gpr_zr,read_gpr,
    BitVec.cast,base,byte,store,MemoryMode.finish,noError]

/-- The same real fetched code executes checked native memory, with original
error gating and the actual decoder certificate. -/
theorem native_step (s : Reference.AArch64.State) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s 1).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = write_pc (read_pc s.machine + 4#64) written := by
  simpa [stepi_checked,stepi,noError,fetched,instruction,decoded_word,exec_inst,profileRead]
    using execute s address value written base byte store afterError

/-- Actual ordered write observation: earlier memory history remains in the
machine, while the public native step exposes precisely its newly appended event. -/
theorem reference_step (s : Reference.AArch64.State) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s 1).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (history : read_memory_accesses written = read_memory_accesses s.machine ++
      [.memory .write address [value] true])
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨{s with machine := write_pc (read_pc s.machine + 4#64) written},
        [.memory .write address [value] true],none⟩ := by
  have error : read_err (write_pc (read_pc s.machine + 4#64) written) = .None := by
    simpa [read_err,write_pc,r_of_w_different] using afterError
  have events : read_memory_accesses (write_pc (read_pc s.machine + 4#64) written) =
      read_memory_accesses s.machine ++ [.memory .write address [value] true] := by
    simpa [read_memory_accesses,write_pc,w,write_base_pc] using history
  simp only [Reference.AArch64.step,
    native_step s profile profileRead address value written base byte store noError afterError fetched,
    events,List.drop_left,noError,error]
  rfl

end KProgFormal.ClightRefinement.Arm64MemsetByteNative
