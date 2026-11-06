import KProgFormal.Refinement.Arm64Register
import KProgFormal.Generated.GeneratedArm64Fmov
import KProgFormal.Generated.GeneratedArm64FmovDest

namespace KProgFormal.Refinement.Arm64Fmov

open Reference
open Reference.AArch64 (Width FmovInstruction)

/-- Operand selection for the four real FMOV directions. Unused integer fields
are ZR, not SP. Generated value and destination selectors are both exercised. -/
def fields : FmovInstruction → GeneratedArm64Fmov.Fmov × Width × Reference.AArch64.Register × Reference.AArch64.Register
  | .toVector .w64 src => (.d_from_x, .w64, 31, src)
  | .toVector .w32 src => (.s_from_w, .w32, 31, src)
  | .fromVector .w64 dst => (.x_from_d, .w64, dst, 31)
  | .fromVector .w32 dst => (.w_from_s, .w32, dst, 31)

def handlerState (i : FmovInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  let (direction, width, dst, src) := fields i
  let value := GeneratedArm64Fmov.value direction (s.vector0.setWidth 64) (Arm64Register.readReg s src)
  if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then
    let low := if direction = .s_from_w then (value.setWidth 32).setWidth 64 else value
    { s with vector0 := low.setWidth 128 }
  else Arm64Register.writeReg s dst value width

def handlerStep (i : FmovInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : FmovInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.fmov i) s := by
  cases i with
  | toVector width src =>
    cases width <;>
      simp [handlerStep, handlerState, fields, Reference.AArch64.step, Reference.AArch64.fmovStep,
        GeneratedArm64Fmov.value, GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
        Arm64Register.read_refines, Reference.AArch64.narrow, Reference.AArch64.Width.bits]
  | fromVector width dst =>
    cases width <;>
      simp [handlerStep, handlerState, fields, Reference.AArch64.step, Reference.AArch64.fmovStep,
        GeneratedArm64Fmov.value, GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
        Arm64Register.write_refines]

theorem handler_refines (i : FmovInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.fmov i) s (handlerStep i s) := (step_refines i s).symm

end KProgFormal.Refinement.Arm64Fmov
