import KProgFormal.ClightRefinement.Arm64KernelMemcpyWriteMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairStores
open Arm64KernelMemcpyCode (instruction)

def baseRegister (i : Fin 2) : Fin 31 := if i.val = 0 then 0 else 5
abbrev lowRegister := Arm64KernelMemcpyPairLoads.lowRegister
abbrev highRegister := Arm64KernelMemcpyPairLoads.highRegister
abbrev offset := Arm64KernelMemcpyPairLoads.offset
def fields (i : Fin 2) : Reg_pair_signed_offset_cls :=
  {opc := 2,V := 0,L := 0,imm7 := if i.val = 0 then 0 else 126,
   Rn := BitVec.ofNat 5 (baseRegister i).val,Rt := BitVec.ofNat 5 (lowRegister i).val,
   Rt2 := BitVec.ofNat 5 (highRegister i).val}
def codeIndex (i : Fin 2) : Fin 14 := ⟨11+i.val,by omega⟩

theorem decoded : ∀ i : Fin 2,
    (instruction (codeIndex i)).decoded = .LDST (.Reg_pair_signed_offset (fields i)) := by decide +kernel

def after (s : Reference.AArch64.State) (written : ArmState) : Reference.AArch64.State :=
  {s with machine := write_pc (read_pc s.machine+4#64) written}

/-- The actual two captured STPs perform ordered64bit writes in split mode,
reading both true register operands from their original machine. -/
theorem execute_split (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = false)
    (address : BitVec 64) (middle written : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (writeLow : MemoryMode.write .checked 8 address (Reference.AArch64.gpr s (lowRegister i)) s.machine = .ok middle)
    (writeHigh : MemoryMode.write .checked 8 (address+8#64) (Reference.AArch64.gpr s (highRegister i)) middle = .ok written)
    (afterError : read_err written = .None) :
    LDST.exec_reg_pair_signed_offset (fields i) s.machine .checked = (after s written).machine := by
  change r .ERR written = .None at afterError
  have cases : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
  rcases cases i with rfl | rfl <;>
    simp +decide [LDST.exec_reg_pair_signed_offset,LDST.exec_reg_pair_common,LDST.reg_pair_operation,
      LDST.reg_pair_constrain_unpredictable,fields,baseRegister,lowRegister,highRegister,
      Arm64KernelMemcpyPairLoads.lowRegister,Arm64KernelMemcpyPairLoads.highRegister,
      offset,Arm64KernelMemcpyPairLoads.offset,Reference.AArch64.gpr] at base ⊢ <;>
    simp +decide [lowRegister,highRegister,Arm64KernelMemcpyPairLoads.lowRegister,Arm64KernelMemcpyPairLoads.highRegister,Reference.AArch64.gpr] at writeLow writeHigh <;>
    simp +decide [read_gpr,read_gpr_zr,base,profileRead,mode,writeLow,writeHigh,MemoryMode.finish,ldst_read,
      Bind.bind,Pure.pure,Except.bind,Except.pure,after,fields,lowRegister,highRegister,baseRegister,
      read_err,BitVec.cast,afterError,Reference.AArch64.gpr]

/-- Single-access mode writes the actual high++low128bit register pair. -/
theorem execute_single (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = true)
    (address : BitVec 64) (written : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (write : MemoryMode.write .checked 16 address
      (Reference.AArch64.gpr s (highRegister i) ++ Reference.AArch64.gpr s (lowRegister i)) s.machine = .ok written)
    (afterError : read_err written = .None) :
    LDST.exec_reg_pair_signed_offset (fields i) s.machine .checked = (after s written).machine := by
  change r .ERR written = .None at afterError
  have cases : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
  rcases cases i with rfl | rfl <;>
    simp +decide [LDST.exec_reg_pair_signed_offset,LDST.exec_reg_pair_common,LDST.reg_pair_operation,
      LDST.reg_pair_constrain_unpredictable,fields,baseRegister,lowRegister,highRegister,
      Arm64KernelMemcpyPairLoads.lowRegister,Arm64KernelMemcpyPairLoads.highRegister,
      offset,Arm64KernelMemcpyPairLoads.offset,Reference.AArch64.gpr] at base ⊢ <;>
    simp +decide [lowRegister,highRegister,Arm64KernelMemcpyPairLoads.lowRegister,Arm64KernelMemcpyPairLoads.highRegister,Reference.AArch64.gpr] at write <;>
    simp +decide [read_gpr,read_gpr_zr,base,profileRead,mode,write,MemoryMode.finish,ldst_read,
      Bind.bind,Pure.pure,Except.bind,Except.pure,after,fields,lowRegister,highRegister,baseRegister,
      read_err,BitVec.cast,afterError,Reference.AArch64.gpr] <;>
    erw [write]
  all_goals simp only [afterError,ite_true]

theorem native_split (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = false)
    (address : BitVec 64) (middle written : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (writeLow : MemoryMode.write .checked 8 address (Reference.AArch64.gpr s (lowRegister i)) s.machine = .ok middle)
    (writeHigh : MemoryMode.write .checked 8 (address+8#64) (Reference.AArch64.gpr s (highRegister i)) middle = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction (codeIndex i)).encoding) :
    stepi_checked s.machine = (after s written).machine := by
  have actual := (instruction (codeIndex i)).valid.trans (congrArg some (decoded i))
  simpa [stepi_checked,stepi,noError,fetched,actual,exec_inst,profileRead] using
    execute_split s i profile profileRead mode address middle written base writeLow writeHigh afterError

theorem native_single (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = true)
    (address : BitVec 64) (written : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (write : MemoryMode.write .checked 16 address
      (Reference.AArch64.gpr s (highRegister i) ++ Reference.AArch64.gpr s (lowRegister i)) s.machine = .ok written)
    (noError : read_err s.machine = .None) (afterError : read_err written = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction (codeIndex i)).encoding) :
    stepi_checked s.machine = (after s written).machine := by
  have actual := (instruction (codeIndex i)).valid.trans (congrArg some (decoded i))
  simpa [stepi_checked,stepi,noError,fetched,actual,exec_inst,profileRead] using
    execute_single s i profile profileRead mode address written base write afterError

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairStores
