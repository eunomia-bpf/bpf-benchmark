# Actual vector allocation permissions

The producer's actual typed512-byte VectorLocal allocation supplies its
writable-range certificate. Real stores and owned FrameBelow relations
carry this certificate to reached heaps. Imported range permissions and
alignment yield writable Mint64 access for every low/high half of all32
vectors, including the first and last allocation boundaries. The actual
vectorLoopSourceOffset pointers refer to these same64 aligned half ranges.
Successful later stores are derived from these permissions in the next
source-write component.

Focused build177 and five public type/axiom queries pass at original
200000/512 caps under shared timing,CPU17,one worker,32GiB. These memory
permission proofs use standard logic only. V owns whole confirmation.
Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
