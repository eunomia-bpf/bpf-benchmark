import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryBranchSites
import KProgFormal.ClightRefinement.Arm64ProgramEntryControlAdmission

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryOriginalCodeSites
open Arm64ProgramEntryPostMemoryBranchSites (Sites atSite cursor)
open Arm64ProgramEntryPostMemoryCodeAdmission (cursor_pc cursor_program)
open Arm64ProgramEntryControlAdmission (afterFourteen)

/-- Both actual imported branch successors retain their physical cursor when
current PC agrees; data, flags and all other native fields remain arbitrary. -/
private theorem site_pc (source target : Reference.AArch64.State) (offset : BitVec 19)
    (taken : Bool) (pc : read_pc target.machine = read_pc source.machine) :
    read_pc (atSite target offset taken).machine = read_pc (atSite source offset taken).machine := by
  simp only [atSite,cursor_pc,cursor,pc]

/-- Reuse both original real BL/RET/continuation certificates, independently
of the actual register/provider values that will select one of the sites. -/
def transport (source target : Reference.AArch64.State) (offset : BitVec 19)
    (sites : Sites source offset)
    (program : target.machine.program = source.machine.program)
    (pc : read_pc target.machine = read_pc source.machine) : Sites target offset where
  fallOffset := sites.fallOffset
  takenOffset := sites.takenOffset
  fallCode := Arm64ProgramEntryPostMemoryCodeAdmission.transport
    (atSite source offset false) (atSite target offset false) sites.fallOffset sites.fallCode
    (by simpa only [atSite,cursor_program] using program) (site_pc source target offset false pc)
  takenCode := Arm64ProgramEntryPostMemoryCodeAdmission.transport
    (atSite source offset true) (atSite target offset true) sites.takenOffset sites.takenCode
    (by simpa only [atSite,cursor_program] using program) (site_pc source target offset true pc)

/-- Original code anchor for the first control word after fourteen real words.
This cursor view is used only to bind code, not to assert native execution. -/
def anchor (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (read_pc s.machine + 56#64) s

/-- The actual fourteen-step successor consumes the SAME original-program
sites and real Instructions. Physical PC/program facts come from admission. -/
def from_original (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32)
    (pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64)
    (program : (afterFourteen s origins fields).machine.program = s.machine.program)
    (offset : BitVec 19) (sites : Sites (anchor s) offset) : Sites (afterFourteen s origins fields) offset :=
  transport (anchor s) (afterFourteen s origins fields) offset sites
    (program.trans (cursor_program s _).symm) (pc.trans (cursor_pc s _).symm)

end KProgFormal.ClightRefinement.Arm64ProgramEntryOriginalCodeSites
