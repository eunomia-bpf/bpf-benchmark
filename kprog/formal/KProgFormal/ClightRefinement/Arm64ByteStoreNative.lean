import KProgFormal.ClightRefinement.Arm64MemsetPhysicalByte
import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ByteStoreNative

/-- Real scalar byte stores at X0, including actual source/data aliasing. -/
def fields (data : Fin 31) : Reg_unsigned_imm_cls :=
  { size := 0, V := 0, opc := 0, imm12 := 0, Rn := 0, Rt := BitVec.ofNat 5 data.val }

def word (data : Fin 31) : BitVec 32 := (0x39000000#32) + BitVec.ofNat 32 data.val

theorem decoded_word : ∀ data : Fin 31, decode_raw_inst (word data) =
    some (.LDST (.Reg_unsigned_imm (fields data))) := by decide +kernel

def instruction (data : Fin 31) : Reference.AArch64.Instruction :=
  ⟨word data,.LDST (.Reg_unsigned_imm (fields data)),decoded_word data⟩

private theorem data_not_zr : ∀ data : Fin 31, BitVec.ofNat 5 data.val ≠ (31#5) := by decide +kernel

/-- Execute the actual imported STRB body against its real checked write. -/
theorem execute (s : Reference.AArch64.State) (data : Fin 31)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s data).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err written = .None) :
    LDST.exec_reg_imm_unsigned_offset (fields data) s.machine .checked =
      write_pc (read_pc s.machine + 4#64) written := by
  change r (.GPR (0#5)) s.machine = address at base
  change (r (.GPR (BitVec.ofNat 5 data.val)) s.machine).setWidth 8 = value at byte
  simp +decide [LDST.exec_reg_imm_unsigned_offset,fields,LDST.exec_reg_imm_common,
    LDST.exec_reg_imm_common_offset,LDST.reg_imm_constrain_unpredictable,
    LDST.reg_imm_operation,ldst_read,read_gpr_zr,read_gpr,
    BitVec.cast,data_not_zr data,base,byte,store,MemoryMode.finish,noError]

/-- The same real fetched code executes checked native memory, with original
error gating and the actual decoder certificate. -/
theorem native_step (s : Reference.AArch64.State) (data : Fin 31) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s data).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction data).encoding) :
    stepi_checked s.machine = write_pc (read_pc s.machine + 4#64) written := by
  simpa [stepi_checked,stepi,noError,fetched,instruction,decoded_word,exec_inst,profileRead]
    using execute s data address value written base byte store afterError

/-- Actual ordered write observation: earlier memory history remains in the
machine, while the public native step exposes precisely its newly appended event. -/
theorem reference_step (s : Reference.AArch64.State) (data : Fin 31) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile)
    (address : BitVec 64) (value : BitVec 8) (written : ArmState)
    (base : Reference.AArch64.gpr s 0 = address)
    (byte : (Reference.AArch64.gpr s data).setWidth 8 = value)
    (store : MemoryMode.write .checked 1 address value s.machine = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (history : read_memory_accesses written = read_memory_accesses s.machine ++
      [.memory .write address [value] true])
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction data).encoding) :
    Reference.AArch64.step s =
      ⟨{s with machine := write_pc (read_pc s.machine + 4#64) written},
        [.memory .write address [value] true],none⟩ := by
  have error : read_err (write_pc (read_pc s.machine + 4#64) written) = .None := by
    simpa [read_err,write_pc,r_of_w_different] using afterError
  have events : read_memory_accesses (write_pc (read_pc s.machine + 4#64) written) =
      read_memory_accesses s.machine ++ [.memory .write address [value] true] := by
    simpa [read_memory_accesses,write_pc,w,write_base_pc] using history
  simp only [Reference.AArch64.step,
    native_step s data profile profileRead address value written base byte store noError afterError fetched,
    events,List.drop_left,noError,error]
  rfl

end KProgFormal.ClightRefinement.Arm64ByteStoreNative
