import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoStores
open Arm64KernelMemcpyCode (Code instruction)

structure Result (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64) where
  stored : Reference.AArch64.State
  final : Reference.AArch64.State
  storedView : stored = Arm64KernelMemcpyPairWrite.after s 0 profile (Reference.AArch64.gpr s 0)
  storedFields : ∀ field : StateField, field ≠ .PC → r field stored.machine = r field s.machine
  finalView : final = Arm64KernelMemcpyPairWrite.after stored 1
    (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr s 0)) (Reference.AArch64.gpr s 0)
  firstStore : Reference.AArch64.step s =
    ⟨stored,Arm64KernelMemcpyPairWrite.events s 0 profile (Reference.AArch64.gpr s 0),none⟩
  secondStore : Reference.AArch64.step stored =
    ⟨final,Arm64KernelMemcpyPairWrite.events stored 1
      (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr s 0)) (Reference.AArch64.gpr s 0),none⟩
  pc : read_pc final.machine = origin+52#64
  noError : read_err final.machine = .None
  fields : ∀ field : StateField, field ≠ .PC → r field final.machine = r field s.machine
  profileAfter : read_memory_profile final.machine = some
    (Arm64KernelMemcpyPairWrite.finalProfile (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr s 0)) (Reference.AArch64.gpr s 0))
  program : final.machine.program = s.machine.program
  exclusive : final.machine.exclusive = s.machine.exclusive
  atomic : final.machine.atomicAccesses = s.machine.atomicAccesses
  thread : final.machine.threadPointerInputs = s.machine.threadPointerInputs
  extra : final.extraFlags = s.extraFlags
  code : Code origin final.machine
  returnFetch : fetch_inst (read_pc final.machine) final.machine = some (instruction 13).encoding

/-- Both actual repeated STPs consume the SAME reached machine. The first
real write supplies the second profile/rights/code/error/address facts. -/
theorem execute (s : Reference.AArch64.State) (origin : BitVec 64) (profile : MemoryProfile)
    (code : Code origin s.machine) (pc : read_pc s.machine = origin+44#64)
    (noError : read_err s.machine = .None)
    (destinationEnd : Reference.AArch64.gpr s 5 = Reference.AArch64.gpr s 0+16#64)
    (profileRead : read_memory_profile s.machine = some profile)
    (writable : MemoryMode.permitted profile.writable (Reference.AArch64.gpr s 0) 16 = true) :
    Nonempty (Result s profile origin) := by
  let address := Reference.AArch64.gpr s 0
  let stored := Arm64KernelMemcpyPairWrite.after s 0 profile address
  let profile1 := Arm64KernelMemcpyPairWrite.finalProfile profile address
  let finished := Arm64KernelMemcpyPairWrite.after stored 1 profile1 address
  have base0 : Reference.AArch64.gpr s (Arm64KernelMemcpyPairStores.baseRegister 0)+
      Arm64KernelMemcpyPairStores.offset 0 = address := by
    simp [Arm64KernelMemcpyPairStores.baseRegister,Arm64KernelMemcpyPairStores.offset,Arm64KernelMemcpyPairLoads.offset,address]
  have fetch0 : fetch_inst (read_pc s.machine) s.machine = some (instruction 11).encoding := by
    rw [pc]
    exact code 11
  have effect0 := Arm64KernelMemcpyPairWrite.effects s 0 profile profileRead address base0 writable noError fetch0
  have store0 := Arm64KernelMemcpyPairWrite.reference_step s 0 profile address noError effect0
  obtain ⟨pc0,extra0,fields0,profile0,program0,exclusive0,atomic0,thread0⟩ :=
    Arm64KernelMemcpyPairWrite.frame s 0 profile address effect0
  change read_pc stored.machine = read_pc s.machine+4#64 at pc0
  have cursor0 : read_pc stored.machine = origin+48#64 := by
    simpa only [pc,BitVec.add_assoc,show (44#64)+(4#64) = 48#64 by decide] using pc0
  have error0 : read_err stored.machine = .None := (fields0 .ERR (by decide)).trans noError
  have end0 : Reference.AArch64.gpr stored 5 = address+16#64 :=
    (fields0 (.GPR (5#5)) (by decide)).trans destinationEnd
  have base1 : Reference.AArch64.gpr stored (Arm64KernelMemcpyPairStores.baseRegister 1)+
      Arm64KernelMemcpyPairStores.offset 1 = address := by
    change Reference.AArch64.gpr stored 5+(-16#64) = _
    rw [end0]
    simpa only [←BitVec.sub_eq_add_neg] using BitVec.add_sub_cancel address (16#64)
  have rights := Arm64KernelMemcpyPairWrite.permissions profile address
  have writable1 : MemoryMode.permitted profile1.writable address 16 = true := by
    simpa only [profile1,rights.2.1] using writable
  have code1 : Code origin stored.machine :=
    @Arm64KernelMemcpyCode.transport origin s.machine stored.machine code program0
  have fetch1 : fetch_inst (read_pc stored.machine) stored.machine = some (instruction 12).encoding := by
    rw [cursor0]
    exact code1 12
  have effect1 := Arm64KernelMemcpyPairWrite.effects stored 1 profile1 profile0 address base1 writable1 error0 fetch1
  have store1 := Arm64KernelMemcpyPairWrite.reference_step stored 1 profile1 address error0 effect1
  obtain ⟨pc1,extra1,fields1,profileFinal,program1,exclusive1,atomic1,thread1⟩ :=
    Arm64KernelMemcpyPairWrite.frame stored 1 profile1 address effect1
  change read_pc finished.machine = read_pc stored.machine+4#64 at pc1
  have cursor1 : read_pc finished.machine = origin+52#64 := by
    simpa only [cursor0,BitVec.add_assoc,show (48#64)+(4#64) = 52#64 by decide] using pc1
  have finalProgram : finished.machine.program = s.machine.program := program1.trans program0
  have finalCode : Code origin finished.machine :=
    @Arm64KernelMemcpyCode.transport origin s.machine finished.machine code finalProgram
  refine ⟨{
    stored := stored
    final := finished
    storedView := rfl
    storedFields := fields0
    finalView := rfl
    firstStore := store0
    secondStore := store1
    pc := cursor1
    noError := (fields1 .ERR (by decide)).trans error0
    fields := fun field notPC => (fields1 field notPC).trans (fields0 field notPC)
    profileAfter := profileFinal
    program := finalProgram
    exclusive := exclusive1.trans exclusive0
    atomic := atomic1.trans atomic0
    thread := thread1.trans thread0
    extra := extra1.trans extra0
    code := finalCode
    returnFetch := ?_ }⟩
  rw [cursor1]
  exact finalCode 13

/-- Equal loaded register pairs produce the true repeated write event list.
The first actual store preserves the second pair and the platform mode. -/
theorem repeated (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (result : Result s profile origin)
    (lowEqual : Reference.AArch64.gpr s 12 = Reference.AArch64.gpr s 6)
    (highEqual : Reference.AArch64.gpr s 13 = Reference.AArch64.gpr s 7) :
    Arm64KernelMemcpyPairWrite.events result.stored 1
      (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr s 0)) (Reference.AArch64.gpr s 0) =
    Arm64KernelMemcpyPairWrite.events s 0 profile (Reference.AArch64.gpr s 0) := by
  have low : Arm64KernelMemcpyPairWrite.low result.stored 1 = Arm64KernelMemcpyPairWrite.low s 0 :=
    (result.storedFields (.GPR (12#5)) (by decide)).trans lowEqual
  have high : Arm64KernelMemcpyPairWrite.high result.stored 1 = Arm64KernelMemcpyPairWrite.high s 0 :=
    (result.storedFields (.GPR (13#5)) (by decide)).trans highEqual
  have mode := (Arm64KernelMemcpyPairWrite.permissions profile (Reference.AArch64.gpr s 0)).2.2
  simp only [Arm64KernelMemcpyPairWrite.events,mode,low,high]

/-- Original load witnesses feed both genuine stores once, including all
four true operand words from the SAME original physical source memory. -/
theorem continue_from_loads (s current : Reference.AArch64.State) (origin : BitVec 64) (profile : MemoryProfile)
    (loads : Arm64KernelMemcpyTwoLoads.Result s profile origin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr s 5 = Reference.AArch64.gpr s 0+16#64)
    (profileRead : read_memory_profile s.machine = some profile)
    (writable : MemoryMode.permitted profile.writable (Reference.AArch64.gpr s 0) 16 = true) :
    Nonempty (Result current profile origin) ∧
    Reference.AArch64.gpr current 6 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
    Reference.AArch64.gpr current 7 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine ∧
    Reference.AArch64.gpr current 12 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
    Reference.AArch64.gpr current 13 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine := by
  have originalDestination : Reference.AArch64.gpr loads.final 0 = Reference.AArch64.gpr s 0 :=
    loads.fields (.GPR (0#5)) (by decide) (by decide) (by decide) (by decide) (by decide)
  have destination : Reference.AArch64.gpr current 0 = Reference.AArch64.gpr s 0 :=
    (congrArg (fun state => Reference.AArch64.gpr state 0) reached).trans originalDestination
  have actualEnd : Reference.AArch64.gpr current 5 = Reference.AArch64.gpr current 0+16#64 :=
    (((congrArg (fun state => Reference.AArch64.gpr state 5) reached).trans loads.destinationEnd).trans destinationEnd).trans
      (congrArg (fun address => address+16#64) destination.symm)
  have actualProfile : read_memory_profile current.machine = some profile :=
    ((congrArg (fun state : Reference.AArch64.State => state.machine.memoryProfile) reached).trans loads.profileSame).trans profileRead
  have actualProgram : current.machine.program = loads.final.machine.program :=
    congrArg (fun state : Reference.AArch64.State => state.machine.program) reached
  have actualCode : Code origin current.machine :=
    @Arm64KernelMemcpyCode.transport origin loads.final.machine current.machine loads.code actualProgram
  have actualPC : read_pc current.machine = origin+44#64 :=
    (congrArg (fun state : Reference.AArch64.State => read_pc state.machine) reached).trans loads.pc
  have actualError : read_err current.machine = .None :=
    (congrArg (fun state : Reference.AArch64.State => read_err state.machine) reached).trans loads.noError
  have actualWritable : MemoryMode.permitted profile.writable (Reference.AArch64.gpr current 0) 16 = true :=
    (congrArg (fun address => MemoryMode.permitted profile.writable address 16) destination).trans writable
  obtain ⟨low6,high7,low12,high13⟩ := Arm64KernelMemcpyPairLoadValues.two_values s profile origin loads
  exact ⟨execute current origin profile actualCode actualPC actualError actualEnd actualProfile actualWritable,
    (congrArg (fun state => Reference.AArch64.gpr state 6) reached).trans low6,
    (congrArg (fun state => Reference.AArch64.gpr state 7) reached).trans high7,
    (congrArg (fun state => Reference.AArch64.gpr state 12) reached).trans low12,
    (congrArg (fun state => Reference.AArch64.gpr state 13) reached).trans high13⟩

/-- One actual store execution carries the original loaded bytes and its
two identical ordered write-event lists into the final RET fetch. -/
theorem complete_from_loads (s current : Reference.AArch64.State) (origin : BitVec 64) (profile : MemoryProfile)
    (loads : Arm64KernelMemcpyTwoLoads.Result s profile origin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr s 5 = Reference.AArch64.gpr s 0+16#64)
    (profileRead : read_memory_profile s.machine = some profile)
    (writable : MemoryMode.permitted profile.writable (Reference.AArch64.gpr s 0) 16 = true) :
    ∃ stores : Result current profile origin,
      Arm64KernelMemcpyPairWrite.events stores.stored 1
        (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr current 0)) (Reference.AArch64.gpr current 0) =
        Arm64KernelMemcpyPairWrite.events current 0 profile (Reference.AArch64.gpr current 0) ∧
      Reference.AArch64.gpr current 6 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
      Reference.AArch64.gpr current 7 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine ∧
      Reference.AArch64.gpr current 12 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
      Reference.AArch64.gpr current 13 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine := by
  obtain ⟨⟨stores⟩,low6,high7,low12,high13⟩ :=
    continue_from_loads s current origin profile loads reached destinationEnd profileRead writable
  exact ⟨stores,repeated current profile origin stores (low12.trans low6.symm) (high13.trans high7.symm),
    low6,high7,low12,high13⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoStores
