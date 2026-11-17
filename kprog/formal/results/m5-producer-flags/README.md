# Actual raw producer flag inputs

The four actual declaration blocks after the pointer tables are bound to N,
Z, C and V, in that order, with their real input temporaries, byte stores and
successor stages. The existing kind-6 input symbol and full function type are
reused. No new input provider or outcome is introduced.

`flag_input_ready` proves three internal transitions from each real declaration
to its external input call. `flag_input_returns` follows any stated scalar
outcome of that relation, preserving its trace and supplied post-memory, then
performs four internal transitions through the actual continuation and byte
store. The stored value is the exact Clight unsigned-byte cast of input AND 1;
`flag_word_bit` proves it is zero or one, and that exact value reads back.
Every other declared-local load, old caller block, permission and allocation
frontier is preserved relative to the provider's supplied memory. Retaining
the actual local permissions after the call is an explicit ABI premise.
Provider existence/purity and final native-flag correspondence are not assumed.

`pointer_tables_first_flag` composes the actual 186-transition table segment
with its real successor's first input call. Both complete pointer tables stay
readable at that 189-transition boundary. No flag outcome is assumed there.

The focused build passes 151 jobs. The revised arithmetic proof and eight
source-based public queries pass without native reflection assumptions. All
23 Clight exports remain byte-identical to `9c617740f`. The first full batch
build passes 278 jobs; it preceded that arithmetic revision, whose final
confirmation is queued under timing SH. Status is in `validation.json`. The
proof keeps default heartbeats/depth and one worker. This step
changes no C, external semantics, frozen benchmark, image or kernel. Last full
`make check` passed at `5236c0e96`.

Reproduce from `kprog/formal` with the lane's CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerFlags
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-flags/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

All attempts remain in `/workspaces/kprog-raw/formal/m5-producer-flags`.
Vector inputs, stack and later context/header/cache-pointer/consumer stages,
native ABI/origin/memory/control correspondence and O1/O2/O4 recount remain
M5. Complete ISA-handler refinements remain zero; M6 closure follows M5.
