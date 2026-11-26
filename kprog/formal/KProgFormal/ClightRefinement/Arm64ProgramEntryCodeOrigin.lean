import KProgFormal.ClightRefinement.Arm64ProgramEntryOriginalCodeSites

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCodeOrigin
open Arm64ProgramEntryControlAdmission (afterFourteen)
open Arm64ProgramEntryPostMemoryBranchSites (Sites)
open Arm64ProgramEntryPostMemoryCodeAdmission (cursor_pc cursor_program)

/-- A code view of one actual target. Registers and other fields are those of
the target; only real program/PC equality transports the code certificates. -/
structure Origin (target : Reference.AArch64.State) where
  state : Reference.AArch64.State
  program : target.machine.program = state.machine.program
  pc : read_pc target.machine = read_pc state.machine

def current (target : Reference.AArch64.State) : Origin target := ⟨target,rfl,rfl⟩

/-- Original program at PC+56, justified by the actual fourteen-word admission. -/
def original (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32)
    (pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64)
    (program : (afterFourteen s origins fields).machine.program = s.machine.program) :
    Origin (afterFourteen s origins fields) :=
  ⟨Arm64ProgramEntryOriginalCodeSites.anchor s,
    program.trans (cursor_program s _).symm,pc.trans (cursor_pc s _).symm⟩

/-- The same real two-site certificate at the actual reached target. -/
def sites {target : Reference.AArch64.State} (code : Origin target)
    (offset : BitVec 19) (admitted : Sites code.state offset) : Sites target offset :=
  Arm64ProgramEntryOriginalCodeSites.transport code.state target offset admitted code.program code.pc

/-- The current-code interface retains its original certificate definitionally. -/
theorem current_sites (target : Reference.AArch64.State) (offset : BitVec 19)
    (admitted : Sites target offset) : sites (current target) offset admitted = admitted := by
  cases admitted
  rfl

/-- The original-code interface uses exactly the existing original anchor transport. -/
theorem original_sites (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32)
    (pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64)
    (program : (afterFourteen s origins fields).machine.program = s.machine.program)
    (offset : BitVec 19) (admitted : Sites (Arm64ProgramEntryOriginalCodeSites.anchor s) offset) :
    sites (original s origins fields pc program) offset admitted =
      Arm64ProgramEntryOriginalCodeSites.from_original s origins fields pc program offset admitted := rfl

end KProgFormal.ClightRefinement.Arm64ProgramEntryCodeOrigin
