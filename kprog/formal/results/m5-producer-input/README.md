# Actual raw producer first register-input boundary

`producer_input_binding` binds the native/host input symbol and full signature
in the actual raw producer environment at Clight block 58. This is distinct
from the address and Program exports' global bindings. It reuses the existing
input function declaration; the stock BPF mutable-map provider remains a
different ABI.

`setup_register_input` constructs the real three post-cache setup stores from
allocated writable local ranges. It completes nine internal transitions and
preserves all other declared-local loads, caller blocks, access and allocation
identity. `first_input_ready` composes the previous checked prefix and the
actual branch/call evaluation: arbitrary producer calls reach the first kind-6
input boundary in 594 internal transitions, with both caches still zero and
invalid and complete caller memory framed. No provider outcome is assumed.

`first_input_returns` follows any stated scalar outcome admitted by the
imported external relation. Nine internal transitions resume the real saved
continuation, store the returned word through x0's actual union field and
write its scalar tag zero. Both values read back exactly. All other declared
local loads remain as in the provider's supplied memory; its trace and memory
are retained except for those two constructed stores. The provider retaining
the allocated local permissions is an explicit ABI condition. Its allocation
frontier is retained by the stores; it need not equal the pre-call frontier.
Provider purity and physical native-origin correctness are not assumed.

This is x0's declaration initializer. The raw producer later binds its actual
context and other state. No final architectural x0 or whole-producer/consumer
refinement is claimed here. Remaining register/flag/vector inputs, header
construction and continuation, native ABI memory/origin, compact/PC/native
memory/control and the O1/O2/O4 recount remain M5 before remaining M6 closure.
Complete ISA-handler refinements remain zero.

Reproduce from `kprog/formal` with the lane's CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerInputs
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-input/Query.lean
lake build
```

Raw attempts stay in `/workspaces/kprog-raw/formal/m5-producer-input`.
This step changes no C, external semantics, generated export or frozen
benchmark path. Last complete `make check` passed at `5236c0e96`.
