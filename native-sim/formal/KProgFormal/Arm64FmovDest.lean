import KProgFormal.GeneratedArm64FmovDest
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64FmovDest (vectorDestination code)

/-- Independent statement of the FMOV destination routing: a direction code routes
to the vector register exactly when it is one of the four in-range codes and its
parity is even. Phrased arithmetically on the code, deliberately not a restatement
of the generated match arms. -/
def arm64FmovDestSpec (dirCode : Nat) : Bool :=
  dirCode < 4 && dirCode % 2 == 0

/-- The generated FMOV destination routing agrees with the independent
parity-and-range statement at every code. -/
theorem arm64_fmov_dest_refines (dirCode : Nat) :
    vectorDestination dirCode = arm64FmovDestSpec dirCode := by
  unfold vectorDestination arm64FmovDestSpec
  split <;> simp_all <;> omega

/-- The two register-half directions route to the general-purpose destination and
the two vector-half directions route to the vector register: the routing is the
parity of the direction code. -/
theorem arm64_fmov_dest_parity :
    vectorDestination 0 = true ∧ vectorDestination 1 = false ∧
    vectorDestination 2 = true ∧ vectorDestination 3 = false := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- An out-of-range direction code never routes to the vector register. -/
theorem arm64_fmov_dest_out_of_range (dirCode : Nat) (h : 4 ≤ dirCode) :
    vectorDestination dirCode = false := by
  have : vectorDestination dirCode = arm64FmovDestSpec dirCode :=
    arm64_fmov_dest_refines dirCode
  rw [this, arm64FmovDestSpec]
  simp [Nat.not_lt.mpr h]

/-- Routing to the general-purpose destination is the complement of routing to the
vector register over the four in-range codes. -/
theorem arm64_fmov_dest_complement (dirCode : Nat) (h : dirCode < 4) :
    vectorDestination dirCode = true ↔ dirCode % 2 = 0 := by
  rw [arm64_fmov_dest_refines, arm64FmovDestSpec]
  simp [h]

/-- The FMOV opcode is pinned to its numeric case-label code. -/
theorem arm64_fmov_dest_code_dispatch : code = 35 := by
  decide

/-- The FMOV opcode lies inside the byte range the shared C macro's numeric case
label addresses. -/
theorem arm64_fmov_dest_code_in_range : 35 ≤ code ∧ code ≤ 35 := by
  decide

/-- Canonical example: a D_FROM_X direction routes to the vector register. -/
theorem arm64_fmov_dest_example_vector :
    arm64FmovDestSpec 0 = true := by
  decide

/-- Canonical example: a W_FROM_S direction routes to the general-purpose
destination. -/
theorem arm64_fmov_dest_example_register :
    arm64FmovDestSpec 3 = false := by
  decide

end KProgFormal
