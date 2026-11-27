# Actual LR zero initialization from function entry

The real Flags.after statement is the LR zero assignment followed by the
actual vector input source. execute obtains current LR write permission
from the existing LRLocal resource for the SAME 795-local allocation,
derives the actual store and zero readback, and executes the original three
sequence/assignment/skip steps. The heap change is exactly that one store.

Kernel checks establish that the actual GPR word/tag, ABI, defaults, table
and flag identifiers differ from LR. Real allocated bindings instantiate
the store's non-LR-block frame. entry invokes the accepted FlagEntry.entry
once and execute once, preserving all 31 GPR pairs, four flags, 62 table
slots, two ABI pointers, five CB zero words and nine defaults, plus caller
memory, access, frontier and actual TempEnv. Both genuine table initialization
resources retain the same original before/run/store fields and extend only
their current-memory frames through this SAME suffix.

There is no initialized LR/read/store success premise, old producer allocator,
repeated entry, new external call or regenerated source. Existing context,
GPR and flag external availability/effects remain explicit. The final LR
value zero is this source declaration's result; later inline LINK writes
and native LR behavior remain their own proof obligations.

The endpoint is the actual vectorStart before all 64 vector provider sites,
the instruction prefix and first LINK. Native/loaded-text/global/universal
refinement and recount remain open. Actual Cilium LINKs are BPF helper calls,
separate from memcpy. Query.lean checks five public declarations and actual
axioms; validation.json records source hash, original caps, timing and checks.
The promoted module is byte-identical to the successful direct snapshot.
