import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoads

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairRead
open Arm64KernelMemcpyPairLoads (baseRegister offset fields codeIndex)
abbrev Read := Arm64KernelMemcpyReadMemory.after

def middle (s : Reference.AArch64.State) (profile : MemoryProfile) (address : BitVec 64) := Read s.machine profile 8 address

def splitAfter (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) : Reference.AArch64.State :=
  Arm64KernelMemcpyPairLoads.after s i (read_mem_bytes 8 address s.machine)
    (read_mem_bytes 8 (address+8#64) (middle s profile address))
    (Read (middle s profile address) profile 8 (address+8#64))

def singleAfter (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) : Reference.AArch64.State :=
  let value := read_mem_bytes 16 address s.machine
  Arm64KernelMemcpyPairLoads.after s i (value.extractLsb' 0 64) (value.extractLsb' 64 64) (Read s.machine profile 16 address)

def after (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) : Reference.AArch64.State :=
  if profile.pairSingleAccess then singleAfter s i profile address else splitAfter s i profile address

/-- Actual physical read observations keep real underlying bytes and the
computed initialization Boolean at the native access width. -/
def observation (s : Reference.AArch64.State) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) : Reference.Event :=
  .memory .read address ((List.range bytes).map (fun i => read_mem (address+BitVec.ofNat 64 i) s.machine))
    (MemoryMode.permitted profile.initialized address bytes)

def events (s : Reference.AArch64.State) (profile : MemoryProfile) (address : BitVec 64) : List Reference.Event :=
  if profile.pairSingleAccess then [observation s profile 16 address]
  else [observation s profile 8 address,observation s profile 8 (address+8#64)]

/-- A permitted wrapping native range supplies each real subrange, using
modular64 address arithmetic with no extra nonwrapping premise. -/
theorem permitted_part (permission : BitVec 64 → Bool) (address : BitVec 64) (total start bytes : Nat)
    (permitted : MemoryMode.permitted permission address total = true) (bound : start+bytes ≤ total) :
    MemoryMode.permitted permission (address+BitVec.ofNat 64 start) bytes = true := by
  simp only [MemoryMode.permitted,List.all_eq_true] at permitted ⊢
  intro j member
  have small := List.mem_range.mp member
  have actual := permitted (start+j) (List.mem_range.mpr (by omega))
  simpa only [BitVec.ofNat_add,BitVec.add_assoc] using actual

/-- Original16byte read permission derives both actual LDP access modes,
all real primitive read states/error results and exact Reference events.
The API assumes no successful-read equation or invented initialized byte. -/
theorem execute (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (address : BitVec 64)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (readable : MemoryMode.permitted profile.readable address 16 = true)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (Arm64KernelMemcpyCode.instruction (codeIndex i)).encoding) :
    Reference.AArch64.step s = ⟨after s i profile address,events s profile address,none⟩ := by
  have ordinary : ∀ i : Fin 2, (fields i).Rt ≠ 31#5 ∧ (fields i).Rt2 ≠ 31#5 := by decide +kernel
  have lowNZ := (ordinary i).1
  have highNZ := (ordinary i).2
  cases mode : profile.pairSingleAccess with
  | false =>
    have lowPerm : MemoryMode.permitted profile.readable address 8 = true := by
      simpa using permitted_part profile.readable address 16 0 8 readable (by decide)
    have highPerm := permitted_part profile.readable address 16 8 8 readable (by decide)
    have low := Arm64KernelMemcpyReadMemory.execute s.machine profile 8 address profileRead lowPerm
    have middleProfile : read_memory_profile (middle s profile address) = some profile := by
      simpa only [middle,Read,Arm64KernelMemcpyReadMemory.after,record_memory_access,read_memory_profile] using profileRead
    have high := Arm64KernelMemcpyReadMemory.execute (middle s profile address) profile 8 (address+8#64) middleProfile highPerm
    have rawError : read_err (Read (middle s profile address) profile 8 (address+8#64)) = .None :=
      (high.fields .ERR).trans ((low.fields .ERR).trans noError)
    have native := Arm64KernelMemcpyPairLoads.native_split s i profile profileRead mode address
      (read_mem_bytes 8 address s.machine) (read_mem_bytes 8 (address+8#64) (middle s profile address))
      (middle s profile address) (Read (middle s profile address) profile 8 (address+8#64))
      base low.checked high.checked noError rawError fetched
    have error : read_err (splitAfter s i profile address).machine = .None := by
      simpa [splitAfter,Arm64KernelMemcpyPairLoads.after,read_err,write_pc,write_gpr_zr,
        write_gpr,lowNZ,highNZ,r_of_w_different] using rawError
    have history : read_memory_accesses (splitAfter s i profile address).machine = read_memory_accesses s.machine ++
        [Arm64KernelMemcpyReadMemory.event s.machine profile 8 address,
         Arm64KernelMemcpyReadMemory.event s.machine profile 8 (address+8#64)] := by
      simp [splitAfter,Arm64KernelMemcpyPairLoads.after,write_pc,write_gpr_zr,write_gpr,lowNZ,highNZ,
        read_memory_accesses,w,write_base_pc,write_base_gpr,Read,middle,Arm64KernelMemcpyReadMemory.after,
        Arm64KernelMemcpyReadMemory.event,record_memory_access,read_mem,List.append_assoc]
    change stepi_checked s.machine = (splitAfter s i profile address).machine at native
    simp only [after,events,mode,ite_false]
    simp only [Reference.AArch64.step,native,history,List.drop_left,noError,error]
    rfl
  | true =>
    have read := Arm64KernelMemcpyReadMemory.execute s.machine profile 16 address profileRead readable
    have rawError : read_err (Read s.machine profile 16 address) = .None := (read.fields .ERR).trans noError
    have native := Arm64KernelMemcpyPairLoads.native_single s i profile profileRead mode address
      (read_mem_bytes 16 address s.machine) (Read s.machine profile 16 address) base read.checked noError rawError fetched
    have error : read_err (singleAfter s i profile address).machine = .None := by
      simpa [singleAfter,Arm64KernelMemcpyPairLoads.after,read_err,write_pc,write_gpr_zr,
        write_gpr,lowNZ,highNZ,r_of_w_different] using rawError
    have history : read_memory_accesses (singleAfter s i profile address).machine = read_memory_accesses s.machine ++
        [Arm64KernelMemcpyReadMemory.event s.machine profile 16 address] := by
      simp [singleAfter,Arm64KernelMemcpyPairLoads.after,write_pc,write_gpr_zr,write_gpr,lowNZ,highNZ,
        read_memory_accesses,w,write_base_pc,write_base_gpr,Read,Arm64KernelMemcpyReadMemory.after,record_memory_access]
    change stepi_checked s.machine = (singleAfter s i profile address).machine at native
    simp only [after,events,mode,ite_true]
    simp only [Reference.AArch64.step,native,history,List.drop_left,noError,error]
    rfl

/-- The concrete actual read states preserve every architectural field. -/
private theorem read_fields (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) (field : StateField) :
    r field (Read s profile bytes address) = r field s := by
  cases field <;> simp [Read,Arm64KernelMemcpyReadMemory.after,record_memory_access,r,
    read_base_gpr,read_base_sfp,read_base_pc,read_base_flag,read_base_error]

/-- Both real platform access modes preserve the full physical frame;
only the two actual loaded GPRs and PC change. -/
theorem frame (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :
    read_pc (after s i profile address).machine = read_pc s.machine+4#64 ∧
    (after s i profile address).extraFlags = s.extraFlags ∧
    (∀ field : StateField, field ≠ .PC → field ≠ .GPR (fields i).Rt → field ≠ .GPR (fields i).Rt2 →
      r field (after s i profile address).machine = r field s.machine) ∧
    (after s i profile address).machine.mem = s.machine.mem ∧
    (after s i profile address).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s i profile address).machine.program = s.machine.program ∧
    (after s i profile address).machine.exclusive = s.machine.exclusive ∧
    (after s i profile address).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s i profile address).machine.threadPointerInputs = s.machine.threadPointerInputs := by
  have ordinary : ∀ i : Fin 2, (fields i).Rt ≠ 31#5 ∧ (fields i).Rt2 ≠ 31#5 := by decide +kernel
  have lowNZ := (ordinary i).1
  have highNZ := (ordinary i).2
  refine ⟨?_,?_,?_,?_,?_,?_,?_,?_,?_⟩
  · cases mode : profile.pairSingleAccess <;>
      simp [after,mode,singleAfter,splitAfter,Arm64KernelMemcpyPairLoads.after,
        read_pc,write_pc,write_gpr_zr,write_gpr,lowNZ,highNZ,r_of_w_same,r_of_w_different]
  · cases mode : profile.pairSingleAccess <;> simp [after,mode,singleAfter,splitAfter,Arm64KernelMemcpyPairLoads.after]
  · intro field notPC notLow notHigh
    cases mode : profile.pairSingleAccess <;>
      simp [after,mode,ite_false,ite_true,singleAfter,splitAfter,
        Arm64KernelMemcpyPairLoads.after,write_pc,write_gpr_zr,lowNZ,highNZ,write_gpr,
        r_of_w_different notPC,r_of_w_different notLow,r_of_w_different notHigh,read_fields,middle]
  all_goals
    cases mode : profile.pairSingleAccess <;>
      simp [after,mode,singleAfter,splitAfter,Arm64KernelMemcpyPairLoads.after,
        write_pc,write_gpr_zr,write_gpr,lowNZ,highNZ,w,write_base_pc,write_base_gpr,
        Read,middle,Arm64KernelMemcpyReadMemory.after,record_memory_access]

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairRead
