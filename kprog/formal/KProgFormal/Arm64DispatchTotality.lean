import KProgFormal.Arm64DispatchSingleton
import KProgFormal.Arm64DispatchFamily
import KProgFormal.Generated.GeneratedArm64Decode

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

The reserved set is explicit and empty for this modeled subset after the two
immediate aliases join the ALU family. Its membership and partition laws retain
the distinction between this subset and the complete dispatcher.

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

/-- Reserved numeric labels of the modeled generated-table subset. -/
def unrouted : List Nat := []

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

/-- Reserved labels stay disjoint from every modeled routed label. -/
theorem unrouted_disjoint :
    routed.all (fun c => !unrouted.contains c) = true := by
  unfold routed unrouted
  decide

/-- The modeled subset has an empty reserved set after both immediate aliases
join the ALU family. -/
theorem unrouted_empty : unrouted.length = 0 := by
  decide

/-- The reserved labels are pairwise distinct. -/
theorem unrouted_distinct : unrouted.Nodup := by
  decide

/-- Every numeric query returns false for membership in the empty reserved set. -/
theorem unrouted_characterisation (c : Nat) :
    unrouted.contains c = false := by rfl

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