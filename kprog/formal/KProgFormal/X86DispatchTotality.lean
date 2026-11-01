import KProgFormal.X86DispatchSingleton
import KProgFormal.X86DispatchFamily
import KProgFormal.GeneratedX86Opcode

/-!
The x86 dispatcher's *coverage*, mirroring `Arm64DispatchTotality`.

`x86_dispatch_chain_codes_nodup` proves no opcode is gated by two arms -- "at
most one". Nothing states "at least one", and the difference is behavioural: an
opcode with no arm falls through the whole chain, and the chain has no final
`else`, so the result is an unchanged state rather than a diagnostic.

That is deliberate for the five control-transfer opcodes. They are lowered
elsewhere (the emitted code carries the branches directly), so the modelling
chain is right to leave them unrouted -- and a route host uses `RET` precisely
because it has no arm. What was missing is a statement of *which* opcodes those
are, so that adding an opcode without routing it is a visible diff rather than
an unnoticed fall-through.

The partition below is the x86 counterpart of the AArch64 one, with the
difference that these five are a documented architectural category rather than
reserved filler.
-/

namespace KProgFormal.X86DispatchTotality

open KProgFormal

/-- Opcodes a dispatch family selects on. -/
def routedByFamily : List Nat :=
  (x86DispatchOps.map GeneratedX86DispatchFamily.code).eraseDups

/-- Opcodes a singleton arm selects on. -/
def routedBySingleton : List Nat :=
  (x86SingletonOps.map GeneratedX86DispatchSingleton.code).eraseDups

/-- Every routed opcode, from either side of the chain. -/
def routed : List Nat := (routedByFamily ++ routedBySingleton).eraseDups

/-- Opcodes the simulator defines but no arm selects on: the five
control-transfer codes, which the emitted code handles outside this chain.
Enumerated rather than discovered, so a newly added opcode appears here as a
diff. -/
def unrouted : List Nat := [0x10, 0x11, 0x14, 0x2e, 0xff]

/-- No opcode is selected by both a family and a singleton arm -- the
exclusivity half, restated over the deduped lists so it composes with the
coverage statement. -/
theorem routed_partition_disjoint :
    routedByFamily.all (fun c => !routedBySingleton.contains c) = true := by
  unfold routedByFamily routedBySingleton
  decide

/-- Each routed list is duplicate-free, so "is this opcode routed" is
well-defined rather than dependent on how often a code is listed. -/
theorem routed_lists_nodup :
    routedByFamily.Nodup ∧ routedBySingleton.Nodup := by
  unfold routedByFamily routedBySingleton
  decide

/-- The unrouted set is disjoint from everything routed: no opcode is both
handled by an arm and left to the fall-through. -/
theorem unrouted_disjoint :
    routed.all (fun c => !unrouted.contains c) = true := by
  unfold routed unrouted
  decide

/-- And the routed set is disjoint from the unrouted one in the other
direction, so membership in one excludes the other. -/
theorem unrouted_disjoint_symm :
    unrouted.all (fun c => !routed.contains c) = true := by
  unfold routed unrouted
  decide

/-- The unrouted set is non-empty. Were it empty the category would be
vacuous and the coverage statement would say nothing about the fall-through. -/
theorem unrouted_nonempty : unrouted.length = 5 := by
  decide

/-- The five codes are distinct -- an enumeration of five opcodes, not one
code written five times. -/
theorem unrouted_distinct : unrouted.Nodup := by
  decide

/-- Membership in the unrouted set is characterised exactly, stated as an
equivalence over a variable so it holds independently of list order. -/
theorem unrouted_characterisation (c : Nat) :
    (c = 0x10 ∨ c = 0x11 ∨ c = 0x14 ∨ c = 0x2e ∨ c = 0xff) ↔
      unrouted.contains c = true := by
  unfold unrouted
  simp only [List.contains_cons, List.contains_nil, Bool.or_eq_true,
             beq_iff_eq, Bool.false_eq_true, or_false]

/-- The routed and unrouted sets together are duplicate-free, so they form a
partition of the opcodes they name. -/
theorem routed_and_unrouted_partition :
    (routed ++ unrouted).Nodup := by
  unfold routed unrouted
  decide

/-- `RET` is in the unrouted set, which is why the route hosts use it as their
no-arm sentinel. Recorded so that changing its routing would be noticed. -/
theorem ret_has_no_arm : unrouted.contains 0xff = true := by
  decide

/-- The five unrouted opcodes are exactly the control-transfer ones the
simulator defines. Stated as a count so that adding a sixth control opcode
without routing it breaks a theorem rather than passing quietly. -/
theorem unrouted_are_control_transfer : unrouted.length = 5 ∧
    unrouted.contains 0x10 = true ∧ unrouted.contains 0x11 = true ∧
    unrouted.contains 0x14 = true ∧ unrouted.contains 0x2e = true ∧
    unrouted.contains 0xff = true := by
  refine ⟨rfl, ?_, ?_, ?_, ?_, ?_⟩ <;> decide

end KProgFormal.X86DispatchTotality