import KProgFormal.ClightRefinement.Arm64KernelMemcpySmallPrefix
import KProgFormal.ClightRefinement.Arm64KernelMemcpyReadMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoads
open Arm64KernelMemcpyCode (instruction)

def baseRegister (i : Fin 2) : Fin 31 := if i.val = 0 then 1 else 4
def lowRegister (i : Fin 2) : Fin 31 := if i.val = 0 then 6 else 12
def highRegister (i : Fin 2) : Fin 31 := if i.val = 0 then 7 else 13
def offset (i : Fin 2) : BitVec 64 := if i.val = 0 then 0 else -16#64
def fields (i : Fin 2) : Reg_pair_signed_offset_cls :=
  {opc := 2,V := 0,L := 1,imm7 := if i.val = 0 then 0 else 126,
   Rn := BitVec.ofNat 5 (baseRegister i).val,Rt := BitVec.ofNat 5 (lowRegister i).val,
   Rt2 := BitVec.ofNat 5 (highRegister i).val}
def codeIndex (i : Fin 2) : Fin 14 := ⟨9+i.val,by omega⟩

theorem decoded : ∀ i : Fin 2,
    (instruction (codeIndex i)).decoded = .LDST (.Reg_pair_signed_offset (fields i)) := by decide +kernel

def after (s : Reference.AArch64.State) (i : Fin 2) (low high : BitVec 64) (readState : ArmState) : Reference.AArch64.State :=
  {s with machine := write_pc (read_pc s.machine+4#64) (write_gpr_zr 64 (fields i).Rt2 high (write_gpr_zr 64 (fields i).Rt low readState))}

/-- Both actual LDP words execute two ordered real8byte reads when the
platform selects split access, with the genuine signed tail offset. -/
theorem execute_split (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = false)
    (address : BitVec 64) (low high : BitVec 64) (middle readState : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (readLow : MemoryMode.read .checked 8 address s.machine = .ok (low,middle))
    (readHigh : MemoryMode.read .checked 8 (address+8#64) middle = .ok (high,readState))
    (afterError : read_err readState = .None) :
    LDST.exec_reg_pair_signed_offset (fields i) s.machine .checked = (after s i low high readState).machine := by
  change r .ERR readState = .None at afterError
  have cases : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
  rcases cases i with rfl | rfl <;>
    simp +decide [LDST.exec_reg_pair_signed_offset,LDST.exec_reg_pair_common,LDST.reg_pair_operation,
      LDST.reg_pair_constrain_unpredictable,fields,baseRegister,lowRegister,highRegister,
      offset,Reference.AArch64.gpr] at base ⊢ <;>
    simp +decide [read_gpr,base,profileRead,mode,readLow,readHigh,MemoryMode.finish,ldst_write,
      Bind.bind,Pure.pure,Except.bind,Except.pure,Functor.map,Except.map,after,fields,
      lowRegister,highRegister,baseRegister,read_err,write_gpr_zr,write_gpr,r_of_w_different,afterError,BitVec.cast_eq] <;> rfl

/-- The SAME real LDP instructions use one actual16byte read when selected
by the native platform profile; low/high registers use imported extracts. -/
theorem execute_single (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = true)
    (address : BitVec 64) (value : BitVec 128) (readState : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (read : MemoryMode.read .checked 16 address s.machine = .ok (value,readState))
    (afterError : read_err readState = .None) :
    LDST.exec_reg_pair_signed_offset (fields i) s.machine .checked =
      (after s i (value.extractLsb' 0 64) (value.extractLsb' 64 64) readState).machine := by
  change r .ERR readState = .None at afterError
  have cases : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
  rcases cases i with rfl | rfl <;>
    simp +decide [LDST.exec_reg_pair_signed_offset,LDST.exec_reg_pair_common,LDST.reg_pair_operation,
      LDST.reg_pair_constrain_unpredictable,fields,baseRegister,lowRegister,highRegister,
      offset,Reference.AArch64.gpr] at base ⊢ <;>
    simp +decide [read_gpr,base,profileRead,mode,read,MemoryMode.finish,ldst_write,
      Bind.bind,Pure.pure,Except.bind,Except.pure,Functor.map,Except.map,after,fields,
      lowRegister,highRegister,baseRegister,read_err,write_gpr_zr,write_gpr,r_of_w_different,afterError,BitVec.cast_eq]

/-- Actual fetched checked steps, using the captured mature decoder, keep
both possible pair-access modes explicit. -/
theorem native_split (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = false)
    (address : BitVec 64) (low high : BitVec 64) (middle readState : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (readLow : MemoryMode.read .checked 8 address s.machine = .ok (low,middle))
    (readHigh : MemoryMode.read .checked 8 (address+8#64) middle = .ok (high,readState))
    (noError : read_err s.machine = .None) (afterError : read_err readState = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction (codeIndex i)).encoding) :
    stepi_checked s.machine = (after s i low high readState).machine := by
  have actual := (instruction (codeIndex i)).valid.trans (congrArg some (decoded i))
  simpa [stepi_checked,stepi,noError,fetched,actual,exec_inst,profileRead] using
    execute_split s i profile profileRead mode address low high middle readState base readLow readHigh afterError

theorem native_single (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (mode : profile.pairSingleAccess = true)
    (address : BitVec 64) (value : BitVec 128) (readState : ArmState)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (read : MemoryMode.read .checked 16 address s.machine = .ok (value,readState))
    (noError : read_err s.machine = .None) (afterError : read_err readState = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction (codeIndex i)).encoding) :
    stepi_checked s.machine = (after s i (value.extractLsb' 0 64) (value.extractLsb' 64 64) readState).machine := by
  have actual := (instruction (codeIndex i)).valid.trans (congrArg some (decoded i))
  simpa [stepi_checked,stepi,noError,fetched,actual,exec_inst,profileRead] using
    execute_single s i profile profileRead mode address value readState base read afterError

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoads
