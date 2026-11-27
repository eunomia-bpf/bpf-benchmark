import KProgFormal.Clight.Arm64Addressing
import KProgFormal.Clight.Arm64Address
import CCLib.Linking

set_option Elab.async false

/-- The two original source units resolve the actual ten-argument pointer
writer while retaining their private symbol namespaces. -/
example : (CC.Link.linkProgramRenaming Arm64Addressing.prog Arm64Address.prog).isSome = true := by
  decide +kernel
