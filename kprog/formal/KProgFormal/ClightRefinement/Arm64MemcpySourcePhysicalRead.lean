import KProgFormal.ClightRefinement.Arm64MemcpyByteNativeRead

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpySourcePhysicalRead
open Arm64MemsetPhysicalByte (Represents address)
open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

/-- Actual byte-reader continuation, sharing the SAME heap and mapped profile.
Only real X3/PC and the newly appended read event change on the native side. -/
structure Result (m : CC.Mem) (stack : CC.Block) (origin : BitVec 64)
    (profile : MemoryProfile) (native : Reference.AArch64.State) (i : Fin 160) (value : BitVec 8) where
  final : Reference.AArch64.State
  step : Reference.AArch64.step native = ⟨final,[.memory .read (address origin i) [value] true],none⟩
  mapped : Represents m stack origin profile final.machine
  initialized : profile.initialized (address origin i) = true
  data : Reference.AArch64.gpr final 3 = value.setWidth 64
  pc : read_pc final.machine = read_pc native.machine + 4#64
  extra : final.extraFlags = native.extraFlags
  fields : ∀ field : StateField, field ≠ .PC → field ≠ .GPR (3#5) → r field final.machine = r field native.machine
  memory : final.machine.mem = native.machine.mem
  profile : final.machine.memoryProfile = native.machine.memoryProfile
  history : read_memory_accesses final.machine = read_memory_accesses native.machine ++ [.memory .read (address origin i) [value] true]
  program : final.machine.program = native.machine.program
  exclusive : final.machine.exclusive = native.machine.exclusive
  atomic : final.machine.atomicAccesses = native.machine.atomicAccesses
  thread : final.machine.threadPointerInputs = native.machine.threadPointerInputs

/-- The actual source volatile byte path and native fetched LDRB execute on
one concrete byte load. Output error/history and initialization are derived. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry stack : CC.Block) (i : Fin 160) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (loaded : CC.Mem.load .Mint8unsigned m stack (i.val : Int) = some (.Vint (value.setWidth 32)))
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m stack origin profile native.machine)
    (base : Reference.AArch64.gpr native 1 = address origin i)
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemcpyByteNativeRead.instruction.encoding) :
    ∃ result : Result m stack origin profile native i value,
      CC.Star (CC.Step2 world) (.State reader Arm64MemcpyReadByte.bytes k e le m) CC.E0
        (.State reader Arm64MemcpyReadByte.remaining k e (Arm64MemcpyReadByte.temps le stack value) m) ∧
      (Arm64MemcpyReadByte.temps le stack value).get Arm64Program.___a64_str_value =
        some (.Vlong (Reference.AArch64.gpr result.final 3)) := by
  have source := Arm64MemcpyReadByte.execute e le m k entry stack i value hentry hindex pointer loaded
  obtain ⟨readState,checked,mapped,initialized,memory,profileSame,history,program,exclusive,atomic,thread,fields⟩ :=
    Arm64MemcpyPhysicalByteRead.load represented i value loaded
  have afterError : read_err readState = .None := (fields .ERR).trans noError
  let final := Arm64MemcpyByteNativeRead.after native value readState
  have mappedAfter : Represents m stack origin profile final.machine := by
    refine ⟨?_,mapped.readable,mapped.writable,?_⟩
    · simpa [final,Arm64MemcpyByteNativeRead.after,read_memory_profile,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using mapped.profileRead
    · intro j readable
      simpa [final,Arm64MemcpyByteNativeRead.after,read_mem,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using mapped.bytes j readable
  let result : Result m stack origin profile native i value := {
    final := final
    step := Arm64MemcpyByteNativeRead.reference_step native profile represented.profileRead (address origin i) value readState base checked noError afterError history fetched
    mapped := mappedAfter
    initialized := initialized
    data := Arm64MemcpyByteNativeRead.destination native value readState
    pc := by simp [final,Arm64MemcpyByteNativeRead.after,read_pc,write_pc,r_of_w_same]
    extra := rfl
    fields := by
      intro field notPC notGpr
      simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,r_of_w_different notPC,r_of_w_different notGpr] using fields field
    memory := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using memory
    profile := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using profileSame
    history := by simpa [final,Arm64MemcpyByteNativeRead.after,read_memory_accesses,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using history
    program := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using program
    exclusive := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using exclusive
    atomic := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using atomic
    thread := by simpa [final,Arm64MemcpyByteNativeRead.after,write_pc,write_gpr_zr,write_gpr,w,write_base_pc,write_base_gpr] using thread }
  refine ⟨result,source,?_⟩
  rw [result.data]
  exact CC.PTree.gss _ _ _

/-- The SAME completed memset/memcpy-input packet supplies the actual source
byte and header pointer. Every other packet observation stays on that heap. -/
theorem of_packet {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {view : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    (packet : Arm64MemsetPointerState.Packet view abi byte gprs flags vectors m)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hindex : le.get Arm64Program.___a64_str_index = some (.Vlong (BitVec.ofNat 64 (64+i.val))))
    (origin : BitVec 64) (profile : MemoryProfile) (native : Reference.AArch64.State)
    (represented : Represents m view.stack.block origin profile native.machine)
    (base : Reference.AArch64.gpr native 1 = address origin (Arm64MemsetStoreExecution.index i))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some Arm64MemcpyByteNativeRead.instruction.encoding) :
    ∃ result : Result m view.stack.block origin profile native (Arm64MemsetStoreExecution.index i) byte,
      CC.Star (CC.Step2 world) (.State reader Arm64MemcpyReadByte.bytes k e le m) CC.E0
        (.State reader Arm64MemcpyReadByte.remaining k e (Arm64MemcpyReadByte.temps le view.stack.block byte) m) ∧
      (Arm64MemcpyReadByte.temps le view.stack.block byte).get Arm64Program.___a64_str_value =
        some (.Vlong (Reference.AArch64.gpr result.final 3)) := by
  have pointer : CC.Mem.load CC.Mptr m entry.block 608 = some (.Vptr view.stack.block 0) := by
    simpa only [packet.stackSame] using packet.view.stackPointer
  exact execute e le m k entry.block view.stack.block (Arm64MemsetStoreExecution.index i) byte
    hentry hindex pointer (packet.written i) origin profile native represented base noError fetched

end KProgFormal.ClightRefinement.Arm64MemcpySourcePhysicalRead
