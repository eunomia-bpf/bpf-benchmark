# Plain HASH native C lookup

The C body follows the sole kernel's plain HASH helper: Jenkins hash with the
actual map seed, the selected bucket's RCU nulls chain, stored-hash and full-key
comparison, retry on a different bucket's nulls marker, and an eight-byte-rounded
key offset to the value. B retains helper 1. LRU, per-CPU and map-of-maps behavior
is outside this body and keeps its existing calls.

The installed compiler's existing lookup hook imports this C body for exact map
identities and immutable key sizes; no compiler source change or tool build is
needed. The fixture checks distinct 8/16-byte maps and a retained generic call.
The driver compares hashing with the actual kernel `jhash.h`, exercises guarded
keys, collisions, seeds, bucket counts and value padding, and supplies a changed
nulls marker through shared memory. Application selection follows host validation.
