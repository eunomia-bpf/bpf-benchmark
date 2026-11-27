import KProgFormal.Reference.AArch64

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyReadMemory

/-- The actual imported checked-read observation, with its real permission
and initialization computation, keeps arbitrary native byte contents. -/
def event (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) : MemoryAccessEvent :=
  .memory .read address ((List.range bytes).map (fun i => read_mem (address+BitVec.ofNat 64 i) s))
    (MemoryMode.permitted profile.initialized address bytes)

def after (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) : ArmState :=
  record_memory_access (event s profile bytes address) s

/-- Exact imported read result and complete physical frame for any access
width, including the real8/16byte LDP platform modes. -/
structure Result (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64) : Prop where
  checked : MemoryMode.read .checked bytes address s = .ok (read_mem_bytes bytes address s,after s profile bytes address)
  memory : (after s profile bytes address).mem = s.mem
  profileSame : (after s profile bytes address).memoryProfile = s.memoryProfile
  history : read_memory_accesses (after s profile bytes address) = read_memory_accesses s ++ [event s profile bytes address]
  program : (after s profile bytes address).program = s.program
  exclusive : (after s profile bytes address).exclusive = s.exclusive
  atomic : (after s profile bytes address).atomicAccesses = s.atomicAccesses
  thread : (after s profile bytes address).threadPointerInputs = s.threadPointerInputs
  fields : ∀ field : StateField, r field (after s profile bytes address) = r field s

/-- Actual native byte reads depend only on the SAME physical memory. -/
theorem bytes_same (before after : ArmState) (memory : after.mem = before.mem) (bytes : Nat) (address : BitVec 64) :
    read_mem_bytes bytes address after = read_mem_bytes bytes address before := by
  induction bytes generalizing address with
  | zero => rfl
  | succ bytes ih => simp only [read_mem_bytes,read_mem,memory,ih]

/-- The true readable-range premise yields the real checked result. Neither
initialization nor byte values are replaced by assumed initialized zeros. -/
theorem execute (s : ArmState) (profile : MemoryProfile) (bytes : Nat) (address : BitVec 64)
    (profileRead : read_memory_profile s = some profile)
    (permitted : MemoryMode.permitted profile.readable address bytes = true) : Result s profile bytes address := by
  refine ⟨?_,rfl,rfl,rfl,rfl,rfl,rfl,rfl,?_⟩
  · simp only [MemoryMode.read,profileRead,permitted,ite_true,after,event]
  · intro field
    cases field <;> simp [after,record_memory_access,r,read_base_gpr,read_base_sfp,read_base_pc,read_base_flag,read_base_error]

end KProgFormal.ClightRefinement.Arm64KernelMemcpyReadMemory
