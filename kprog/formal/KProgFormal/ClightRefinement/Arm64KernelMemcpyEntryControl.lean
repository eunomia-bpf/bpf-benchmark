import KProgFormal.ClightRefinement.Arm64KernelMemcpyLanding
import KProgFormal.ClightRefinement.Arm64Registers

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryControl
abbrev Landing := Arm64KernelMemcpyLanding.after
abbrev Branch := Arm64KernelMemcpyEntryCode.after

def after (s : Reference.AArch64.State) : Reference.AArch64.State := Landing (Branch (Landing s))

theorem field (s : Reference.AArch64.State) (name : StateField) (different : name ≠ .PC) :
    r name (after s).machine = r name s.machine :=
  (Arm64KernelMemcpyLanding.field _ name different).trans
    ((Arm64KernelMemcpyEntryCode.field _ name different).trans (Arm64KernelMemcpyLanding.field s name different))

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧
    (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    (after s).extraFlags = s.extraFlags := by
  have first := Arm64KernelMemcpyLanding.resources s
  have middle := Arm64KernelMemcpyEntryCode.resources (Landing s)
  have last := Arm64KernelMemcpyLanding.resources (Branch (Landing s))
  exact ⟨last.1.trans (middle.1.trans first.1),
    last.2.1.trans (middle.2.1.trans first.2.1),
    last.2.2.1.trans (middle.2.2.1.trans first.2.2.1),
    last.2.2.2.1.trans (middle.2.2.2.1.trans first.2.2.2.1),
    last.2.2.2.2.1.trans (middle.2.2.2.2.1.trans first.2.2.2.2.1),
    last.2.2.2.2.2.1.trans (middle.2.2.2.2.2.1.trans first.2.2.2.2.2.1),
    last.2.2.2.2.2.2.1.trans (middle.2.2.2.2.2.2.1.trans first.2.2.2.2.2.2.1),
    last.2.2.2.2.2.2.2.trans (middle.2.2.2.2.2.2.2.trans first.2.2.2.2.2.2.2)⟩

/-- The exact original heap/register relation survives all three actual
control steps, including SP,all SIMD halves,NZCV and provenance. -/
theorem registers {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {cells : Reference.AArch64.Gpr → Nat} {frontier : CC.Block}
    (m : CC.Mem) (entry : CC.Val) (s : Reference.AArch64.State) :
    Arm64Registers.Represents addresses origins cells frontier m entry (after s) ↔
      Arm64Registers.Represents addresses origins cells frontier m entry s := by
  exact (Arm64Registers.cursor m entry (Branch (Landing s)) _).trans
    ((Arm64Registers.cursor m entry (Landing s) _).trans (Arm64Registers.cursor m entry s _))

structure Result (s : Reference.AArch64.State) (origin : BitVec 64) : Prop where
  aliasLanding : Reference.AArch64.step s = ⟨Landing s,[],none⟩
  branch : Reference.AArch64.step (Landing s) = ⟨Branch (Landing s),[],none⟩
  genericLanding : Reference.AArch64.step (Branch (Landing s)) = ⟨after s,[],none⟩
  pc : read_pc (after s).machine = origin+4#64
  noError : read_err (after s).machine = .None
  code : Arm64KernelMemcpyCode.Code origin (after s).machine
  firstAdd : fetch_inst (read_pc (after s).machine) (after s).machine =
    some (Arm64KernelMemcpyCode.instruction 1).encoding

/-- Actual exported alias BTI,B to a distinct symbol and generic BTI
execute once on the SAME physical program. All three reached fetches and
errors derive from the previous real step. The captured B contract binds
this path's actual selected code; the plain BTI feature projection is explicit. -/
theorem execute (s : Reference.AArch64.State) (origin : BitVec 64)
    (code : Arm64KernelMemcpyEntryCode.Code origin s.machine)
    (pc : read_pc s.machine = origin+0x230#64) (noError : read_err s.machine = .None) :
    Result s origin := by
  have fetched : fetch_inst (read_pc s.machine) s.machine = some Arm64KernelMemcpyLanding.instruction.encoding := by
    rw [pc]
    exact code.landing
  have first := Arm64KernelMemcpyLanding.reference_step s fetched noError
  have firstPC : read_pc (Landing s).machine = origin+0x230#64+4#64 :=
    (Arm64KernelMemcpyLanding.pc s).trans (congrArg (fun p => p+4#64) pc)
  have firstError : read_err (Landing s).machine = .None :=
    (Arm64KernelMemcpyLanding.field s .ERR (by decide)).trans noError
  have firstCode : Arm64KernelMemcpyEntryCode.Code origin (Landing s).machine := {
    generic := Arm64KernelMemcpyCode.transport code.generic (Arm64KernelMemcpyLanding.resources s).2.1
    landing := by simpa only [fetch_inst,(Arm64KernelMemcpyLanding.resources s).2.1] using code.landing
    branch := by simpa only [fetch_inst,(Arm64KernelMemcpyLanding.resources s).2.1] using code.branch }
  obtain ⟨branch,atGeneric,_lr,_fields,genericCode,_fetched⟩ :=
    Arm64KernelMemcpyEntryCode.complete (Landing s) origin firstCode firstPC firstError
  have middleError : read_err (Branch (Landing s)).machine = .None :=
    (Arm64KernelMemcpyEntryCode.field _ .ERR (by decide)).trans firstError
  obtain ⟨last,lastPC,lastError,lastCode⟩ :=
    Arm64KernelMemcpyLanding.generic (Branch (Landing s)) origin genericCode atGeneric middleError
  have finalPC : read_pc (after s).machine = origin+4#64 := lastPC
  have firstAdd : fetch_inst (read_pc (after s).machine) (after s).machine =
      some (Arm64KernelMemcpyCode.instruction 1).encoding := by
    rw [finalPC]
    exact lastCode 1
  exact ⟨first,branch,last,lastPC,lastError,lastCode,firstAdd⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryControl
