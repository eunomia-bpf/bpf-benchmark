import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairStores

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairWrite
open Arm64KernelMemcpyPairStores (baseRegister lowRegister highRegister offset codeIndex)
abbrev Write := Arm64KernelMemcpyWriteMemory.after
abbrev Updated := Arm64KernelMemcpyWriteMemory.updated
abbrev WriteEvent := Arm64KernelMemcpyWriteMemory.event

def low (s : Reference.AArch64.State) (i : Fin 2) := Reference.AArch64.gpr s (lowRegister i)
def high (s : Reference.AArch64.State) (i : Fin 2) := Reference.AArch64.gpr s (highRegister i)
def middle (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  Write s.machine profile 8 address (low s i)
def splitWritten (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  Write (middle s i profile address) (Updated profile 8 address) 8 (address+8#64) (high s i)
def singleWritten (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  Write s.machine profile 16 address (high s i ++ low s i)
def written (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  if profile.pairSingleAccess then singleWritten s i profile address else splitWritten s i profile address
def after (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  Arm64KernelMemcpyPairStores.after s (written s i profile address)
def finalProfile (profile : MemoryProfile) (address : BitVec 64) :=
  if profile.pairSingleAccess then Updated profile 16 address else Updated (Updated profile 8 address) 8 (address+8#64)
def nativeEvents (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :=
  if profile.pairSingleAccess then [WriteEvent 16 address (high s i ++ low s i)]
  else [WriteEvent 8 address (low s i),WriteEvent 8 (address+8#64) (high s i)]
def observation (bytes : Nat) (address : BitVec 64) (value : BitVec (bytes*8)) : Reference.Event :=
  .memory .write address ((List.range bytes).map (fun j => value.extractLsb' (j*8) 8)) true
def events (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) : List Reference.Event :=
  if profile.pairSingleAccess then [observation 16 address (high s i ++ low s i)]
  else [observation 8 address (low s i),observation 8 (address+8#64) (high s i)]

structure Effects (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) : Prop where
  native : stepi_checked s.machine = (after s i profile address).machine
  fields : ∀ field : StateField, r field (written s i profile address) = r field s.machine
  profileAfter : read_memory_profile (written s i profile address) = some (finalProfile profile address)
  history : read_memory_accesses (written s i profile address) = read_memory_accesses s.machine ++ nativeEvents s i profile address
  program : (written s i profile address).program = s.machine.program
  exclusive : (written s i profile address).exclusive = s.machine.exclusive
  atomic : (written s i profile address).atomicAccesses = s.machine.atomicAccesses
  thread : (written s i profile address).threadPointerInputs = s.machine.threadPointerInputs

/-- One original16byte writable range supplies every actual STP primitive
write, intermediate initialized profile and error result in either mode. -/
theorem effects (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (address : BitVec 64)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (writable : MemoryMode.permitted profile.writable address 16 = true)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (Arm64KernelMemcpyCode.instruction (codeIndex i)).encoding) :
    Effects s i profile address := by
  cases mode : profile.pairSingleAccess with
  | false =>
    have lowPerm : MemoryMode.permitted profile.writable address 8 = true := by
      simpa using Arm64KernelMemcpyPairRead.permitted_part profile.writable address 16 0 8 writable (by decide)
    have highPerm := Arm64KernelMemcpyPairRead.permitted_part profile.writable address 16 8 8 writable (by decide)
    have first := Arm64KernelMemcpyWriteMemory.execute s.machine profile 8 address (low s i) profileRead lowPerm
    have second := Arm64KernelMemcpyWriteMemory.execute (middle s i profile address) (Updated profile 8 address)
      8 (address+8#64) (high s i) first.profileAfter highPerm
    have rawError : read_err (splitWritten s i profile address) = .None :=
      (second.fields .ERR).trans ((first.fields .ERR).trans noError)
    have native := Arm64KernelMemcpyPairStores.native_split s i profile profileRead mode address
      (middle s i profile address) (splitWritten s i profile address) base first.checked second.checked noError rawError fetched
    refine ⟨?_,?_,?_,?_,?_,?_,?_,?_⟩
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,after,written,mode,Bool.false_eq_true,ite_false] using native
    · intro field
      simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,Bool.false_eq_true,ite_false] using (second.fields field).trans (first.fields field)
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,finalProfile,mode,Bool.false_eq_true,ite_false] using second.profileAfter
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,nativeEvents,mode,Bool.false_eq_true,ite_false,List.append_assoc,List.cons_append,List.nil_append] using second.history.trans
        (congrArg (fun xs => xs ++ [WriteEvent 8 (address+8#64) (high s i)]) first.history)
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,Bool.false_eq_true,ite_false] using second.program.trans first.program
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,Bool.false_eq_true,ite_false] using second.exclusive.trans first.exclusive
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,Bool.false_eq_true,ite_false] using second.atomic.trans first.atomic
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,Bool.false_eq_true,ite_false] using second.thread.trans first.thread
  | true =>
    have store := Arm64KernelMemcpyWriteMemory.execute s.machine profile 16 address (high s i ++ low s i) profileRead writable
    have rawError : read_err (singleWritten s i profile address) = .None := (store.fields .ERR).trans noError
    have native := Arm64KernelMemcpyPairStores.native_single s i profile profileRead mode address
      (singleWritten s i profile address) base store.checked noError rawError fetched
    refine ⟨?_,?_,?_,?_,?_,?_,?_,?_⟩
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,after,written,mode,ite_true] using native
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,ite_true] using store.fields
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,finalProfile,mode,ite_true] using store.profileAfter
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,nativeEvents,mode,ite_true] using store.history
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,ite_true] using store.program
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,ite_true] using store.exclusive
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,ite_true] using store.atomic
    · simpa only [splitWritten,singleWritten,Write,Updated,WriteEvent,written,mode,ite_true] using store.thread

/-- The actual Reference transition exposes exactly the newly written
bytes, with true initialization and the platform's real pair granularity. -/
theorem reference_step (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (address : BitVec 64) (noError : read_err s.machine = .None) (actual : Effects s i profile address) :
    Reference.AArch64.step s = ⟨after s i profile address,events s i profile address,none⟩ := by
  have error : read_err (after s i profile address).machine = .None := by
    simpa [after,Arm64KernelMemcpyPairStores.after,read_err,write_pc,r_of_w_different] using (actual.fields .ERR).trans noError
  have history : read_memory_accesses (after s i profile address).machine = read_memory_accesses s.machine ++ nativeEvents s i profile address := by
    simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc,read_memory_accesses] using actual.history
  simp only [Reference.AArch64.step,actual.native,history,List.drop_left,noError,error]
  cases mode : profile.pairSingleAccess <;>
    simp only [nativeEvents,events,mode] <;> rfl

/-- Original physical permissions derive the same complete Reference step. -/
theorem execute (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile)
    (profileRead : read_memory_profile s.machine = some profile) (address : BitVec 64)
    (base : Reference.AArch64.gpr s (baseRegister i)+offset i = address)
    (writable : MemoryMode.permitted profile.writable address 16 = true)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (Arm64KernelMemcpyCode.instruction (codeIndex i)).encoding) :
    Reference.AArch64.step s = ⟨after s i profile address,events s i profile address,none⟩ := by
  exact reference_step s i profile address noError (effects s i profile profileRead address base writable noError fetched)

/-- The actual initialized output profile retains the same access rights
and pair-access mode for the following real STP. -/
theorem permissions (profile : MemoryProfile) (address : BitVec 64) :
    (finalProfile profile address).readable = profile.readable ∧
    (finalProfile profile address).writable = profile.writable ∧
    (finalProfile profile address).pairSingleAccess = profile.pairSingleAccess := by
  cases mode : profile.pairSingleAccess <;> simp [finalProfile,mode,Updated,Arm64KernelMemcpyWriteMemory.updated]

/-- The SAME permission-derived store effects retain every register and
environment field while advancing PC and updating the real memory profile. -/
theorem frame (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64)
    (actual : Effects s i profile address) :
    read_pc (after s i profile address).machine = read_pc s.machine+4#64 ∧
    (after s i profile address).extraFlags = s.extraFlags ∧
    (∀ field : StateField, field ≠ .PC → r field (after s i profile address).machine = r field s.machine) ∧
    read_memory_profile (after s i profile address).machine = some (finalProfile profile address) ∧
    (after s i profile address).machine.program = s.machine.program ∧
    (after s i profile address).machine.exclusive = s.machine.exclusive ∧
    (after s i profile address).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s i profile address).machine.threadPointerInputs = s.machine.threadPointerInputs := by
  refine ⟨?_,rfl,?_,?_,?_,?_,?_,?_⟩
  · simp [after,Arm64KernelMemcpyPairStores.after,read_pc,write_pc,r_of_w_same]
  · intro field notPC
    simpa only [after,Arm64KernelMemcpyPairStores.after,write_pc,r_of_w_different notPC] using actual.fields field
  · simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc,read_memory_profile] using actual.profileAfter
  · simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc] using actual.program
  · simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc] using actual.exclusive
  · simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc] using actual.atomic
  · simpa [after,Arm64KernelMemcpyPairStores.after,write_pc,w,write_base_pc] using actual.thread

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairWrite
