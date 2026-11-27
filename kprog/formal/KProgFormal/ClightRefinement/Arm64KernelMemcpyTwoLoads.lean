import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairRead

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoLoads
open Arm64KernelMemcpyCode (Code instruction)

/-- Both real LDPs execute on one actual reached machine and code,
including the repeated first/tail16byte source interval. -/
structure Result (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64) where
  loaded : Reference.AArch64.State
  final : Reference.AArch64.State
  loadedView : loaded = Arm64KernelMemcpyPairRead.after s 0 profile (Reference.AArch64.gpr s 1)
  finalView : final = Arm64KernelMemcpyPairRead.after loaded 1 profile (Reference.AArch64.gpr s 1)
  firstLoad : Reference.AArch64.step s =
    ⟨loaded,Arm64KernelMemcpyPairRead.events s profile (Reference.AArch64.gpr s 1),none⟩
  secondLoad : Reference.AArch64.step (loaded) =
    ⟨final,Arm64KernelMemcpyPairRead.events (loaded) profile (Reference.AArch64.gpr s 1),none⟩
  repeated : Arm64KernelMemcpyPairRead.events (loaded) profile (Reference.AArch64.gpr s 1) =
    Arm64KernelMemcpyPairRead.events s profile (Reference.AArch64.gpr s 1)
  pc : read_pc (final).machine = origin+44#64
  noError : read_err (final).machine = .None
  sourceEnd : Reference.AArch64.gpr (final) 4 = Reference.AArch64.gpr s 1+16#64
  destinationEnd : Reference.AArch64.gpr (final) 5 = Reference.AArch64.gpr s 5
  fields : ∀ field : StateField, field ≠ .PC → field ≠ .GPR (6#5) → field ≠ .GPR (7#5) →
    field ≠ .GPR (12#5) → field ≠ .GPR (13#5) → r field (final).machine = r field s.machine
  memory : (final).machine.mem = s.machine.mem
  profileSame : (final).machine.memoryProfile = s.machine.memoryProfile
  program : (final).machine.program = s.machine.program
  exclusive : (final).machine.exclusive = s.machine.exclusive
  atomic : (final).machine.atomicAccesses = s.machine.atomicAccesses
  thread : (final).machine.threadPointerInputs = s.machine.threadPointerInputs
  extra : (final).extraFlags = s.extraFlags
  code : Code origin (final).machine
  firstStore : fetch_inst (read_pc (final).machine) (final).machine = some (instruction 11).encoding

/-- All later fetch/profile/error/base facts derive from the SAME original
code, count and physical read permission. Both actual platform modes retain
their real repeated access events, with no fresh read-state assumptions. -/
theorem execute (s : Reference.AArch64.State) (origin : BitVec 64) (profile : MemoryProfile)
    (code : Code origin s.machine) (pc : read_pc s.machine = origin+36#64)
    (noError : read_err s.machine = .None)
    (sourceEnd : Reference.AArch64.gpr s 4 = Reference.AArch64.gpr s 1+16#64)
    (profileRead : read_memory_profile s.machine = some profile)
    (readable : MemoryMode.permitted profile.readable (Reference.AArch64.gpr s 1) 16 = true) : Nonempty (Result s profile origin) := by
  let loaded := Arm64KernelMemcpyPairRead.after s 0 profile (Reference.AArch64.gpr s 1)
  let finished := Arm64KernelMemcpyPairRead.after loaded 1 profile (Reference.AArch64.gpr s 1)
  have base0 : Reference.AArch64.gpr s (Arm64KernelMemcpyPairLoads.baseRegister 0)+
      Arm64KernelMemcpyPairLoads.offset 0 = Reference.AArch64.gpr s 1 := by
    simp [Arm64KernelMemcpyPairLoads.baseRegister,Arm64KernelMemcpyPairLoads.offset]
  have fetch0 : fetch_inst (read_pc s.machine) s.machine = some (instruction 9).encoding := by
    rw [pc]
    exact code 9
  have load0 := Arm64KernelMemcpyPairRead.execute s 0 profile profileRead (Reference.AArch64.gpr s 1)
    base0 readable noError fetch0
  obtain ⟨pc0,extra0,fields0,mem0,profile0,program0,exclusive0,atomic0,thread0⟩ :=
    Arm64KernelMemcpyPairRead.frame s 0 profile (Reference.AArch64.gpr s 1)
  change (loaded).machine.mem = s.machine.mem at mem0
  change (loaded).machine.memoryProfile = s.machine.memoryProfile at profile0
  change read_pc (loaded).machine = read_pc s.machine+4#64 at pc0
  have cursor0 : read_pc (loaded).machine = origin+40#64 := by
    simpa only [pc,BitVec.add_assoc,show (36#64)+(4#64) = 40#64 by decide] using pc0
  have error0 : read_err (loaded).machine = .None :=
    (fields0 .ERR (by decide) (by decide) (by decide)).trans noError
  have profileFirst : read_memory_profile (loaded).machine = some profile := by
    simpa only [read_memory_profile,profile0] using profileRead
  have codeFirst : Code origin (loaded).machine := Arm64KernelMemcpyCode.transport (before := s.machine) (after := (loaded).machine) code program0
  have fetch1 : fetch_inst (read_pc (loaded).machine) (loaded).machine = some (instruction 10).encoding := by
    rw [cursor0]
    exact codeFirst 10
  have end0 : Reference.AArch64.gpr (loaded) 4 = Reference.AArch64.gpr s 1+16#64 :=
    (fields0 (.GPR (4#5)) (by decide) (by decide) (by decide)).trans sourceEnd
  have base1 : Reference.AArch64.gpr (loaded) (Arm64KernelMemcpyPairLoads.baseRegister 1)+
      Arm64KernelMemcpyPairLoads.offset 1 = Reference.AArch64.gpr s 1 := by
    change Reference.AArch64.gpr (loaded) 4+(-16#64) = _
    rw [end0]
    simpa only [←BitVec.sub_eq_add_neg] using BitVec.add_sub_cancel (Reference.AArch64.gpr s 1) (16#64)
  have load1 := Arm64KernelMemcpyPairRead.execute (loaded) 1 profile profileFirst (Reference.AArch64.gpr s 1)
    base1 readable error0 fetch1
  obtain ⟨pc1,extra1,fields1,mem1,profile1,program1,exclusive1,atomic1,thread1⟩ :=
    Arm64KernelMemcpyPairRead.frame (loaded) 1 profile (Reference.AArch64.gpr s 1)
  change read_pc (finished).machine = read_pc (loaded).machine+4#64 at pc1
  have cursor1 : read_pc (finished).machine = origin+44#64 := by
    simpa only [cursor0,BitVec.add_assoc,show (40#64)+(4#64) = 44#64 by decide] using pc1
  have fullFields (field : StateField) (notPC : field ≠ .PC) (not6 : field ≠ .GPR (6#5))
      (not7 : field ≠ .GPR (7#5)) (not12 : field ≠ .GPR (12#5)) (not13 : field ≠ .GPR (13#5)) :
      r field (finished).machine = r field s.machine :=
    (fields1 field notPC not12 not13).trans (fields0 field notPC not6 not7)
  have finalProgram : (finished).machine.program = s.machine.program := program1.trans program0
  have finalCode : Code origin (finished).machine :=
    @Arm64KernelMemcpyCode.transport origin s.machine (finished).machine code finalProgram
  refine ⟨{
    loaded := loaded
    final := finished
    loadedView := rfl
    finalView := rfl
    firstLoad := by
      exact load0
    secondLoad := by
      exact load1
    repeated := ?_
    pc := by
      exact cursor1
    noError := by
      exact (fields1 .ERR (by decide) (by decide) (by decide)).trans error0
    sourceEnd := ?_
    destinationEnd := ?_
    fields := by
      exact fullFields
    memory := by
      exact mem1.trans mem0
    profileSame := by
      exact profile1.trans profile0
    program := by
      exact finalProgram
    exclusive := by
      exact exclusive1.trans exclusive0
    atomic := by
      exact atomic1.trans atomic0
    thread := by
      exact thread1.trans thread0
    extra := by
      exact extra1.trans extra0
    code := by
      exact finalCode
    firstStore := ?_ }⟩
  · simp only [Arm64KernelMemcpyPairRead.events,Arm64KernelMemcpyPairRead.observation,read_mem,mem0]
  · change r (.GPR (4#5)) (finished).machine = _
    exact (fullFields (.GPR (4#5)) (by decide) (by decide) (by decide) (by decide) (by decide)).trans sourceEnd
  · change r (.GPR (5#5)) (finished).machine = _
    exact fullFields (.GPR (5#5)) (by decide) (by decide) (by decide) (by decide) (by decide)
  · rw [cursor1]
    exact finalCode 11

/-- The SAME actual eight-step prefix reaches the two-load theorem once.
All input code/count/permission facts belong to the original machine. -/
theorem continue_from_prefix (s current : Reference.AArch64.State) (origin : BitVec 64) (profile : MemoryProfile)
    (leading : Arm64KernelMemcpySmallPrefix.Result s origin)
    (reached : current = Arm64KernelMemcpySmallPrefix.after s)
    (profileRead : read_memory_profile s.machine = some profile)
    (readable : MemoryMode.permitted profile.readable (Reference.AArch64.gpr s 1) 16 = true) :
    Nonempty (Result current profile origin) := by
  have originalSource : Reference.AArch64.gpr (Arm64KernelMemcpySmallPrefix.after s) 1 = Reference.AArch64.gpr s 1 :=
    leading.fields (.GPR (1#5)) (by decide) (by decide) (by decide) (by intro f; cases f <;> decide)
  have source : Reference.AArch64.gpr current 1 = Reference.AArch64.gpr s 1 :=
    (congrArg (fun state => Reference.AArch64.gpr state 1) reached).trans originalSource
  have sourceEnd : Reference.AArch64.gpr current 4 = Reference.AArch64.gpr current 1+16#64 :=
    ((congrArg (fun state => Reference.AArch64.gpr state 4) reached).trans leading.sourceEnd).trans
      (congrArg (fun address => address+16#64) source.symm)
  have actualProfile : read_memory_profile current.machine = some profile :=
    ((congrArg (fun state : Reference.AArch64.State => state.machine.memoryProfile) reached).trans leading.profile).trans profileRead
  have actualProgram : current.machine.program = (Arm64KernelMemcpySmallPrefix.after s).machine.program :=
    congrArg (fun state : Reference.AArch64.State => state.machine.program) reached
  have actualCode : Code origin current.machine :=
    @Arm64KernelMemcpyCode.transport origin (Arm64KernelMemcpySmallPrefix.after s).machine current.machine leading.code actualProgram
  have actualPC : read_pc current.machine = origin+36#64 :=
    (congrArg (fun state : Reference.AArch64.State => read_pc state.machine) reached).trans leading.pc
  have actualError : read_err current.machine = .None :=
    (congrArg (fun state : Reference.AArch64.State => read_err state.machine) reached).trans leading.noError
  have actualPermission : MemoryMode.permitted profile.readable (Reference.AArch64.gpr current 1) 16 = true :=
    (congrArg (fun address => MemoryMode.permitted profile.readable address 16) source).trans readable
  exact execute current origin profile actualCode actualPC actualError sourceEnd actualProfile actualPermission

end KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoLoads
