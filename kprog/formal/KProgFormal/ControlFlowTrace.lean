import KProgFormal.GeneratedControlFlowTrace
import KProgFormal.X86BranchEmit
import KProgFormal.Arm64BranchEmit

namespace KProgFormal

open GeneratedControlFlowTrace
open GeneratedX86BranchEmit (Shape)

/-- Independent statement of the architectural next PC at one conditional edge:
the shared `branchPc` model, with the fall-through resume stated directly as
`pc + 1` rather than the generated constant. -/
def archEdge (taken : Bool) (pc target : Nat) : Nat :=
  branchPc taken (pc + 1) target

/-- Independent architectural walk of a whole trace: fold `archEdge` over the
path, threading the program counter. Stated without reference to any emitted
shape or direction policy. -/
def archWalk (pc : Nat) : List (Bool × Nat) -> Nat
  | [] => pc
  | (taken, target) :: rest => archWalk (archEdge taken pc target) rest

/-- The generated emitted step refines the architectural per-edge next PC: for
both direction shapes and both predicate values, the emitted code selects the
same program counter as `branchPc`. This is the whole-trace instance of the
per-edge `x86_branch_emit_refines` / `arm64_branch_emit_refines` facts, whose
generated `nextPc` the emitted step is built from. -/
theorem control_flow_trace_step_refines (s : Shape) (taken : Bool) (pc target : Nat) :
    emittedStep s taken pc target = archEdge taken pc target := by
  unfold emittedStep fallthroughStep GeneratedX86BranchEmit.nextPc archEdge branchPc
  cases s <;> cases taken <;> rfl

/-- **The whole-program trace refinement.** Walking a whole trace with the emitted
step under a fixed direction shape yields exactly the architectural walk, for
every shape and every trace. Composed with the per-edge condition refinements,
this chains the condition predicates through the emitted `goto`/label code to a
whole-program architectural path. -/
theorem control_flow_trace_walk_refines (s : Shape) (pc : Nat) (steps : List (Bool × Nat)) :
    walk s pc steps = archWalk pc steps := by
  induction steps generalizing pc with
  | nil => rfl
  | cons head rest ih =>
    obtain ⟨taken, target⟩ := head
    simp only [walk, archWalk]
    rw [control_flow_trace_step_refines]
    exact ih _

/-- **The whole-program direction-policy refinement.** Even when the emitted code
recomputes the direction shape at every edge from the running program counter and
the edge target -- as the simulator calls `KPROG_X86_BRANCH_BACKWARD` /
`KPROG_ARM64_BRANCH_BACKWARD` at each conditional transfer -- the walked program
counter still equals the architectural walk, for every policy. The per-edge
direction computation is thus a machine-checked whole-program no-op. -/
theorem control_flow_trace_walk_policy_refines (policy : Nat -> Nat -> Shape) (pc : Nat)
    (steps : List (Bool × Nat)) :
    walkPolicy policy pc steps = archWalk pc steps := by
  induction steps generalizing pc with
  | nil => rfl
  | cons head rest ih =>
    obtain ⟨taken, target⟩ := head
    simp only [walkPolicy, archWalk]
    rw [control_flow_trace_step_refines]
    exact ih _

/-- The direction shape is irrelevant to a whole trace: the forward and backward
walks agree everywhere, generalizing the per-edge `shape_irrelevant` facts. -/
theorem control_flow_trace_walk_shape_irrelevant (pc : Nat) (steps : List (Bool × Nat)) :
    walk .forward pc steps = walk .backward pc steps := by
  rw [control_flow_trace_walk_refines, control_flow_trace_walk_refines]

/-- A trace walk splits over path concatenation: walking a path and then its
continuation is walking the concatenation. The induction principle the trace
theorem rests on. -/
theorem control_flow_trace_walk_append (s : Shape) (pc : Nat)
    (a b : List (Bool × Nat)) :
    walk s pc (a ++ b) = walk s (walk s pc a) b := by
  induction a generalizing pc with
  | nil => rfl
  | cons head rest ih =>
    obtain ⟨taken, target⟩ := head
    simp only [List.cons_append, walk]
    rw [ih]

/-- A trace in which every conditional transfer falls through advances the
program counter by exactly the trace length, for either direction shape. -/
theorem control_flow_trace_walk_all_fallthrough (s : Shape) (pc : Nat)
    (steps : List (Bool × Nat)) (h : ∀ p ∈ steps, p.1 = false) :
    walk s pc steps = pc + steps.length := by
  induction steps generalizing pc with
  | nil => rfl
  | cons head rest ih =>
    obtain ⟨taken, target⟩ := head
    have ht : taken = false := by simpa using h (taken, target) (by simp)
    have hr : ∀ p ∈ rest, p.1 = false := by
      intro p hp
      exact h p (by simp [hp])
    simp only [walk, List.length_cons]
    rw [control_flow_trace_step_refines, ht]
    unfold archEdge branchPc
    simp only [Bool.false_eq_true, ↓reduceIte]
    rw [ih _ hr]
    omega

end KProgFormal
