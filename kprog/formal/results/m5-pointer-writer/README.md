# Tagged ordinary-register pointer writer

Arm64PointerWrite executes the actual exported
f_kprog_arm64_program_write_pointer, including its eager SP read, ordinary
register guards, pointer-field assignment, tag assignment and empty-local free.
Its 53 internal transitions preserve arbitrary raw 64-bit payloads and all
256 input tags. Both successful stores and their common post-memory follow
from the existing producer Storage rights. Old payloads and tags are unrestricted.
The checked union field is _ptr, at offset zero, and its store uses CompCert Mptr.

Arm64PointerWriteFrame retains the actual typed cells and writable permissions,
the caller frame, every unselected register observation, SP, all SIMD pairs,
and NZCV. The mature native register write receives M3 materialize(raw, tag)
exactly once. The original raw bits and tag remain in the source cells. Exact
local-load preservation supplies the existing Kept predicate, so canonical
header pointers and warm origin caches transport without another origin call.

Arm64PointerWriteLinked checks the actual merged layouts and the real symbol
and original function definition at block 67. It composes the same stores,
register relation and kept locals with any valid call continuation in that
world. At Kstop every relational execution is a silent prefix of that return,
every stuck endpoint is the same return, and an infinite execution is impossible.
No silent-trace or external-determinism premise is added.

Focused linked checking passes 184 Lake jobs and nine public type/axiom queries
at the original 200000-heartbeat and 512-depth caps, CPU 17, nice 0, one worker,
and 32 GiB address space. Only standard logical axioms and the existing imported
external/assembly relations appear. Whole proof-library confirmation is pending
until the batch ends. Raw checks and debugging logs remain at
/workspaces/kprog-raw/formal/m5-pointer-writer.

This covers ordinary destinations with raw Vlong payloads, including the STACK
relative value needed by ADD_IMM. Abstract Vptr payloads, SP/ZR destinations,
the ADD handler's eager reads/numeric calls/dispatch, source continuation,
actual fetched native ADD and the remaining M5 obligations remain separate.
M5 and M6 stay open; completed ISA-family count is zero.
