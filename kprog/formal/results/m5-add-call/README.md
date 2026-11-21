# Complete generic ADD-from-SP source call

The source implementation binds all nine actual parameters, allocates the
original generic handler locals, invokes the unchanged331-transition body,
and frees its complete local environment. The actual call count is333.
Final source proof checking and both public type/axiom queries pass; native1
checks this module as a dependency. No diagnostic stage logging remains.

Storage/header ownership supplies the original observer frontier. The existing
warm SP cache and complete register relation are transported through actual
allocation; no new provider is called. Writer rights derive stores and preserve
local Freeable permissions. Actual generic deallocation derives successful free,
old-frame readbacks, released permissions and a caller frame. Returned resources
include exact raw SP+rhs/tag4, writable Storage, all register observations,
canonical header pointers and the same warm cache at the original frontier.

The unused SRC2/SRC3 values and caller continuation remain arbitrary. Scope is
opcode3/width8/AUX0/SRC32 and any ordinary destination/immediate64. Native physical
ABI/provider validity and source producer/successor composition remain separate.
M5/O1/O2/O4/M6 remain open; completed ISA families0. Proof-only verification;
no benchmark/functional test/measurement or native tool build. Raw attempts:
/workspaces/kprog-raw/formal/m5-add-call.
