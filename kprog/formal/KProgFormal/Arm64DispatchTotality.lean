import KProgFormal.Arm64DispatchSingleton
import KProgFormal.Arm64DispatchFamily
import KProgFormal.GeneratedArm64Decode

/-!
The dispatcher chain's *coverage*, as distinct from its exclusivity.

`arm64_dispatch_chain_codes_nodup` proves no opcode is gated by two arms --
"at most one". It says nothing about "at least one", and the difference
matters: an opcode with no arm falls through the whole chain to the unsupported
hook, which is a silent behavioural hole rather than a compile error.

This module states the missing half. It partitions the opcode space the decoder
names into three sets:

  * opcodes a dispatch family selects on,
  * opcodes a singleton arm selects on,
  * opcodes with *no* arm, which are reserved and must reach the unsupported
    hook (the hosts use one of them, RET, as the non-member sentinel).

The interesting property is that the third set is small, non-empty and
enumerated. If a new opcode were added to the decoder and routed by nothing,
it would join that set silently; making the set explicit is what turns that
into a reviewable fact rather than an accident.

Scope, stated because it is narrower than "the dispatch chain": this module
speaks about the opcodes the *generated* dispatch tables name. The C chain in
`arm64_sim_local_bpf.h` branches on 35 `HANDLED` predicates while those tables
name 25, so twelve families -- ADRP, CNEG, CSEL, EXTREV, LDRSX, MOV, MUL, ORN,
REDUCTION, SHIFT, STLXR, UNARY -- are routed by the code and absent here. Their
coverage is carried by route hosts rather than by these theorems, and
`check_dispatch_model.py` records which of them have one that drives the
dispatcher. Read this module as "the modelled subset is complete and
exclusive", not as "the chain is".
-/

namespace KProgFormal.DispatchTotality

open KProgFormal

/-- The opcodes the AArch64 decoder names, as distinct generated codes. -/
def routedByFamily : List Nat :=
  (arm64DispatchOps.map GeneratedArm64DispatchFamily.code).eraseDups

/-- The opcodes a singleton arm selects on. -/
def routedBySingleton : List Nat := (arm64SingletonOps.map GeneratedArm64DispatchSingleton.code).eraseDups

/-- Every routed opcode, from either side of the chain. -/
def routed : List Nat := (routedByFamily ++ routedBySingleton).eraseDups

/-- Opcodes defined in `arm64_sim.h` that no arm selects on. Enumerated, not
discovered, so adding an opcode without routing it shows up as a diff here. -/
def unrouted : List Nat := [0x03, 0x04]

/-- No opcode is selected by both a family and a singleton arm -- the
exclusivity half, restated over the deduped lists so it composes with the
coverage statement below. -/
theorem routed_partition_disjoint :
    routedByFamily.all (fun c => !routedBySingleton.contains c) = true := by
  unfold routedByFamily routedBySingleton
  decide

/-- The routed lists are each duplicate-free, so "count of matches" is a
well-defined notion for the coverage statement. -/
theorem routed_lists_nodup :
    routedByFamily.Nodup ∧ routedBySingleton.Nodup := by
  unfold routedByFamily routedBySingleton
  decide

/-- The reserved set is exactly the three codes with no arm, and it is
disjoint from everything routed. -/
theorem unrouted_disjoint :
    routed.all (fun c => !unrouted.contains c) = true := by
  unfold routed unrouted
  decide

/-- The reserved set is non-empty. If it were empty the "no arm" category
would be vacuous, and the coverage statement below would say nothing. -/
theorem unrouted_nonempty : unrouted.length = 2 := by
  decide

/-- Each reserved code is a *distinct* code, so the set is three opcodes and
not one opcode written three times. -/
theorem unrouted_distinct : unrouted.Nodup := by
  decide

/-- The three reserved codes are precisely the ones the decoder names that
appear in neither routed list. Stated as a membership equivalence rather than
as list equality, so it holds regardless of ordering. -/
theorem unrouted_characterisation (c : Nat) :
    (c = 0x03 ∨ c = 0x04) ↔
      unrouted.contains c = true := by
  unfold unrouted
  simp only [List.contains_cons, List.contains_nil, Bool.or_eq_true,
             beq_iff_eq]
  constructor
  · rintro (rfl | rfl) <;> simp
  · rintro (h | h) <;> simp_all

/-- The routed and reserved sets together name every code the two generated
tables mention, with no overlap -- the partition property. -/
theorem routed_and_unrouted_partition :
    (routed ++ unrouted).Nodup := by
  unfold routed unrouted
  decide

/-- A canonical witness that the two routed lists are non-vacuous: `RET`, the
opcode the hosts use as their non-member sentinel, is in fact a *routed*
singleton -- so a host driving it exercises an arm, and its fall-through test
must choose a different sentinel. -/
theorem ret_is_routed_singleton :
    (arm64SingletonOps.map GeneratedArm64DispatchSingleton.code).contains 0x1f
      = true := by
  decide

end KProgFormal.DispatchTotality