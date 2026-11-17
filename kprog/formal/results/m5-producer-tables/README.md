# Actual raw producer pointer tables

The actual 62 assignments immediately after register 30's declaration are
kernel-bound to 31 cell-address stores followed by 31 tag-address stores.
Both actual declared pointer arrays occupy 248 bytes; each exported address
expression is checked against its eight-byte slot offset and actual local type.

`table_locals` derives the allocated table and target bindings and writable
ranges from the real producer allocation, without a caller allocation or alias
premise. Each real three-transition assignment constructs its typed pointer
store, reads back the exact Clight block/offset value, and preserves all other
slots, other declared-local loads, caller blocks, permissions and frontier.
A finite composition over the actual statements gives 93 transitions per
complete table and 186 for the complete source-bound segment.

`register30_and_pointer_tables` composes the actual x30 zero branch with this
segment in 196 internal transitions; both the zero word and scalar tag remain
readable after the table writes. The actual saved environment, temporaries and
continuation are retained. Only the stage-start access map matching the actual
allocation is assumed; the earlier external-provider ABI obligations remain.
The pointers are Clight local-block addresses, not physical native addresses.

Focused build passes 150 jobs. Public queries and the batch's full confirmation
are recorded in `validation.json` and the subsequent batch receipt. The last
complete full build before this step passed 275 jobs at `6048b066f`; last full
`make check` passed at `5236c0e96`. No C, external semantics, frozen benchmark,
image or kernel changes. No proof limits were raised.

Reproduce from `kprog/formal` using the lane CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerTables
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-tables/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

All attempts remain in `/workspaces/kprog-raw/formal/m5-producer-tables`.
Flag/vector inputs, stack/header/cache-pointer/consumer stages and native
ABI/origin/memory/control correspondence remain M5. Complete ISA-handler
refinements remain zero; M6 closure follows M5.
