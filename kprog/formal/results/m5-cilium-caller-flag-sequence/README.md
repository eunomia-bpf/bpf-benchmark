# All four actual caller NZCV input visits

The module sequences the four original input calls and masked byte stores
from Initializers.afterTables to Flags.after, immediately before the real
LR zero assignment. Each visit invokes the accepted actual-site theorem
once, carries its reached memory and trace into the next visit, and folds
the real input temporary updates. The final SAME execution derives all
four low-bit flag reads and retains caller memory, access and frontier.

Actual allocated identifiers and block separation instantiate the real
store's non-target-block frame. This preserves every earlier initialized
flag and every named local outside the four flag identifiers. The
initialized prefix advances from zero to four and feeds the next actual
provider obligation; no synthetic heap or repeated prefix supplies it.

Outcomes.provide explicitly requires actual CompCert call availability at
each reached initialized prefix and current access, with its actual trace,
return value and supplied heap. Local/caller frames, access and frontier
effects are explicit. No purity, fairness, fixed trace, or oracle is inferred.

The endpoint still precedes LR zero, 64 vector inputs, the instruction
prefix and the first LINK. Whole function-entry composition, transport of
the existing table execution resources, native execution, loaded-text,
global/universal refinement and fixture/resource recount remain open.
Actual Cilium LINKs remain BPF-helper calls, separate from memcpy.
Query.lean checks six public declarations and their actual axioms; exact
source hash, original resource/timing policy and checks are in validation.json.
The promoted module is byte-identical to the successful direct snapshot.
