# ARM trusted generation worker preparation

The architecture worker accepts native ELF bytes, an entry symbol and the
common service's normalized typed metadata. It creates its own native-link
proof representation and simulator object. Producer proof, C source, paths and
compiler flags are absent from that input schema. The common daemon still owns
kernel/source-map identity validation, activation, loading and completion.

The actual Katran balancer native ELF generated and compiled afresh. libbpf
opens the result and matches all 17 declared maps, including lru_mapping's inner
map template. Seven malformed/extra metadata cases reject. Its 82 indirect
sites have finite target sets. The final import isolation/refactoring produces
byte-identical C to the compiled candidate and passes a foreign-generator-name
collision check. Exact hashes and logs remain in validation.json and the gzip
logs. Built raw outputs are deleted after this checkpoint per the cleanup order.

This establishes generation, compilation and ELF/map parsing. Kernel service
admission, the new request-binding path and the application workload are pending.
The ARM adapter now uses the committed common declaration/ELF validator: it is
76 lines, with the same 17 map declarations as the compiled candidate and both
actual native entries accepted by preflight. ARM/x86 module imports coexist.
The committed helper and the workspace helper were checked separately; their
hashes are recorded in shared-helper-check.json. This worker creates no broker.
