import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoadValues

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyWriteMemory

def updated (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) : MemoryProfile :=
  { profile with initialized := fun a => if (a-address).toNat < bytes then true else profile.initialized a }

def event (bytes : Nat) (address : BitVec 64) (value : BitVec (bytes*8)) : MemoryAccessEvent :=
  .memory .write address ((List.range bytes).map (fun i => value.extractLsb' (i*8) 8)) true

def after (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64)
    (value : BitVec (bytes*8)) : ArmState :=
  record_memory_access (event bytes address value)
    (write_memory_profile (some (updated profile bytes address)) (write_mem_bytes bytes address value s))

/-- Each actually written byte is initialized even when the range wraps. -/
theorem initialized_inside (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64)
    (bounded : bytes ≤ 2^64) (i : Fin bytes) :
    (updated profile bytes address).initialized (address+BitVec.ofNat 64 i.val) = true := by
  have small : i.val < 2^64 := Nat.lt_of_lt_of_le i.isLt bounded
  have distance : address+BitVec.ofNat 64 i.val-address = BitVec.ofNat 64 i.val := by bv_omega
  simp only [updated,distance,BitVec.toNat_ofNat,Nat.mod_eq_of_lt small,ite_eq_left i.isLt]

/-- Outside the actual wrapping store range, initialization is retained. -/
theorem initialized_outside (profile : MemoryProfile) (bytes : Nat) (address other : BitVec 64)
    (outside : bytes ≤ (other-address).toNat) :
    (updated profile bytes address).initialized other = profile.initialized other := by
  simp only [updated,ite_eq_right (show ¬ (other-address).toNat < bytes by omega)]

/-- The imported byte-store recursion changes memory alone. -/
theorem write_frame (s : ArmState) (bytes : Nat) (address : BitVec 64) (value : BitVec (bytes*8)) :
    (write_mem_bytes bytes address value s).memoryAccesses = s.memoryAccesses ∧
    (write_mem_bytes bytes address value s).program = s.program ∧
    (write_mem_bytes bytes address value s).exclusive = s.exclusive ∧
    (write_mem_bytes bytes address value s).atomicAccesses = s.atomicAccesses ∧
    (write_mem_bytes bytes address value s).threadPointerInputs = s.threadPointerInputs := by
  induction bytes generalizing address s with
  | zero => exact ⟨rfl,rfl,rfl,rfl,rfl⟩
  | succ bytes ih =>
    exact ih (write_mem address (value.extractLsb' 0 8) s) (address+1#64)
      (BitVec.setWidth (bytes*8) (value >>> 8))

structure Result (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64)
    (value : BitVec (bytes*8)) : Prop where
  checked : MemoryMode.write .checked bytes address value s = .ok (after s profile bytes address value)
  memory : (after s profile bytes address value).mem = (write_mem_bytes bytes address value s).mem
  profileAfter : read_memory_profile (after s profile bytes address value) = some (updated profile bytes address)
  history : read_memory_accesses (after s profile bytes address value) = read_memory_accesses s ++ [event bytes address value]
  fields : ∀ field : StateField, r field (after s profile bytes address value) = r field s
  program : (after s profile bytes address value).program = s.program
  exclusive : (after s profile bytes address value).exclusive = s.exclusive
  atomic : (after s profile bytes address value).atomicAccesses = s.atomicAccesses
  thread : (after s profile bytes address value).threadPointerInputs = s.threadPointerInputs

/-- Real wrapping write permission derives the checked store, its exact
bytes/event, initialized range and complete architectural/environment frame. -/
theorem execute (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64)
    (value : BitVec (bytes*8)) (profileRead : read_memory_profile s = some profile)
    (writable : MemoryMode.permitted profile.writable address bytes = true) :
    Result s profile bytes address value := by
  obtain ⟨history,program,exclusive,atomic,thread⟩ := write_frame s bytes address value
  refine ⟨?_,rfl,rfl,?_,?_,program,exclusive,atomic,thread⟩
  · simp only [MemoryMode.write,profileRead,writable,ite_true,after,event,updated]
  · change (write_mem_bytes bytes address value s).memoryAccesses ++ _ = _
    rw [history]
    rfl
  · intro field
    have records : r field (after s profile bytes address value) = r field (write_mem_bytes bytes address value s) := by
      cases field <;> simp [after,record_memory_access,write_memory_profile,r,read_base_gpr,read_base_sfp,read_base_pc,read_base_flag,read_base_error]
    exact records.trans r_of_write_mem_bytes

end KProgFormal.ClightRefinement.Arm64KernelMemcpyWriteMemory
