import KProgFormal.ClightRefinement.Arm64MemcpyPhysicalByteRead
import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyByteNativeRead

/-- Real LDRB W3,[X1], retaining X1 for the following memcpy byte. -/
def fields : Reg_unsigned_imm_cls :=
  { size := 0, V := 0, opc := 1, imm12 := 0, Rn := 1, Rt := 3 }

theorem decoded_word : decode_raw_inst (0x39400023#32) =
    some (.LDST (.Reg_unsigned_imm fields)) := by decide +kernel

def instruction : Reference.AArch64.Instruction :=
  ⟨0x39400023#32,.LDST (.Reg_unsigned_imm fields),decoded_word⟩

def after (s : Reference.AArch64.State) (value : BitVec 8) (readState : ArmState) : Reference.AArch64.State :=
  {s with machine := write_pc (read_pc s.machine + 4#64) (write_gpr_zr 32 (3#5) (value.setWidth 32) readState)}

/-- Execute the actual imported zero-extending byte load and actual checked
memory read, retaining the complete same read-state result. -/
theorem execute (s : Reference.AArch64.State) (address : BitVec 64) (value : BitVec 8)
    (readState : ArmState) (base : Reference.AArch64.gpr s 1 = address)
    (read : MemoryMode.read .checked 1 address s.machine = .ok (value,readState))
    (noError : read_err readState = .None) :
    LDST.exec_reg_imm_unsigned_offset fields s.machine .checked = (after s value readState).machine := by
  change r (.GPR (1#5)) s.machine = address at base
  change r .ERR readState = .None at noError
  simp +decide [LDST.exec_reg_imm_unsigned_offset,fields,LDST.exec_reg_imm_common,
    LDST.exec_reg_imm_common_offset,LDST.reg_imm_operation,read_gpr,base,read,
    MemoryMode.finish,Functor.map,Except.map,after,read_err,write_gpr_zr,write_gpr,r_of_w_different,noError]

theorem destination (s : Reference.AArch64.State) (value : BitVec 8) (readState : ArmState) :
    Reference.AArch64.gpr (after s value readState) 3 = value.setWidth 64 := by
  change r (.GPR (3#5)) (after s value readState).machine = value.setWidth 64
  simp [after,write_pc,write_gpr_zr,write_gpr,r_of_w_different,r_of_w_same]

theorem native_step (s : Reference.AArch64.State) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (readState : ArmState)
    (base : Reference.AArch64.gpr s 1 = address)
    (read : MemoryMode.read .checked 1 address s.machine = .ok (value,readState))
    (noError : read_err s.machine = .None) (afterError : read_err readState = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s value readState).machine := by
  simpa [stepi_checked,stepi,noError,fetched,instruction,decoded_word,exec_inst,profileRead]
    using execute s address value readState base read afterError

/-- Earlier history remains in the machine; the public native step exposes
exactly the new initialized read, its real zero-extended register and PC. -/
theorem reference_step (s : Reference.AArch64.State) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (readState : ArmState)
    (base : Reference.AArch64.gpr s 1 = address)
    (read : MemoryMode.read .checked 1 address s.machine = .ok (value,readState))
    (noError : read_err s.machine = .None) (afterError : read_err readState = .None)
    (history : read_memory_accesses readState = read_memory_accesses s.machine ++ [.memory .read address [value] true])
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s value readState,[.memory .read address [value] true],none⟩ := by
  have error : read_err (after s value readState).machine = .None := by
    simpa [after,read_err,write_pc,write_gpr_zr,write_gpr,r_of_w_different] using afterError
  have events : read_memory_accesses (after s value readState).machine =
      read_memory_accesses s.machine ++ [.memory .read address [value] true] := by
    simpa [after,read_memory_accesses,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using history
  simp only [Reference.AArch64.step,
    native_step s profile profileRead address value readState base read noError afterError fetched,
    events,List.drop_left,noError,error]
  rfl

end KProgFormal.ClightRefinement.Arm64MemcpyByteNativeRead
