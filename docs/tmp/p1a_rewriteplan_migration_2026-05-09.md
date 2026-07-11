# P1-A RewritePlan Migration

Date: 2026-05-09

## Scope

Migrated these kop-class passes from pass-local transaction loops to
`RewritePlan`:

- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `ccmp`
- `bulk_memory`
- `prefetch`

No changes were made to `map_inline.rs`, `insn.rs`, daemon sources, runner,
corpus, e2e, micro, or vendor trees.

## RewritePlan API Changes

| API | Change | Reason |
| --- | --- | --- |
| `replace_range(...)` | now returns `anyhow::Result<()>` | duplicate replacement is now a propagated error instead of `assert!` panic |
| `delete_range(...)` | now returns `anyhow::Result<()>` | range overflow and duplicate deletion are now propagated errors instead of `expect`/`assert!` panic |
| `BtfRemapPolicy::RemapKOperation(&KopRegistry)` | added | kop passes need the same `remap_kop_btf_metadata()` behavior they previously called after manual rewrites |
| `insert_before(pc, insns)` | kept and now used by `prefetch` | `prefetch` inserts packed kop calls before existing instructions, rather than replacing old bytecode |
| `add_internal_branch(...)` | kept and now used by `ccmp` | `ccmp` creates a new branch inside the replacement stream; it must be patched to an old target PC after the global address map is known |

`insert_before` and `add_internal_branch` are no longer dead APIs.

## Pass Migration Summary

Line counts are from the working tree immediately before and after this task.
"Txn lines removed" counts the deleted pass-local addr_map/new_insns/fixup/BTF
transaction block, including directly related helper cleanup where applicable.

| Pass | Before | After | Delta | Txn lines removed | Insert? | Internal branch? |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| `rotate.rs` | 501 | 468 | -33 | 56 | no | no |
| `cond_select.rs` | 607 | 574 | -33 | 57 | no | no |
| `extract.rs` | 223 | 190 | -33 | 51 | no | no |
| `endian.rs` | 571 | 512 | -59 | 79 | no | no |
| `ccmp.rs` | 419 | 345 | -74 | 98 | no | yes |
| `bulk_memory.rs` | 837 | 800 | -37 | 50 | no | no |
| `prefetch.rs` | 838 | 797 | -41 | 53 | yes | no |

### Per-Pass Notes

- `rotate`: emits the same packed rotate call payload in ascending site order,
  then commits with `RemapKOperation`.
- `cond_select`: preserves `prefix` emission before the packed select call.
- `extract`: preserves packed extract payload construction and site ordering.
- `endian_fusion`: modeled as `replace_range(load_pc, 1, call)` plus
  `delete_range(endian_pc, 1)`. This preserves the old mapping where intervening
  instructions survive after the inserted call and the final endian instruction
  maps to the end of the replacement.
- `ccmp`: builds the same `packed-call + JEQ` replacement. The JEQ offset is now
  patched by `RewritePlan::add_internal_branch`, using the same old-target-PC
  input as the deleted `fixup_ccmp_branches()` helper.
- `bulk_memory`: emits identical memcpy/memset packed call chunks per site.
- `prefetch`: emits identical packed prefetch calls in deduplicated candidate
  order through `insert_before`. RewritePlan's insertion mapping matches the old
  loop: a branch to `insert_pc` lands before the inserted prefetch sequence.

## LOC Delta

| Area | Insertions | Deletions | Net |
| --- | ---: | ---: | ---: |
| `rewrite.rs` | 32 | 20 | +12 |
| 7 migrated passes | 147 | 467 | -320 |
| Result-propagation callers (`wide_mem`, `const_prop`, `skb_load_bytes`, `bounds_check_merge`) | 5 | 5 | 0 |
| `utils.rs` | 0 | 0 | 0 |
| P1-A touched files subtotal | 184 | 492 | -308 |

Current requested shortstat:

```text
git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src
34 files changed, 634 insertions(+), 949 deletions(-)
```

Net requested-scope delta: **-315 LOC**.

## Panic to Anyhow

`RewritePlan::replace_range` no longer panics on duplicate start PCs.
`RewritePlan::delete_range` no longer panics on range overflow or duplicate
deletions. Existing callers now use `?`, so planning defects surface as normal
pass errors.

## Bytecode Identity Argument

No bytecode-generating helper was changed. Each migrated pass still computes the
same safe site list and calls the same emit functions with the same inputs:

- Replacement-only passes use `RewritePlan::replace_range`, whose commit path
  uses the same `map_replacement_range()` and `fixup_all_branches()` helpers as
  the deleted loops.
- `endian_fusion` preserves the old `addr_map` behavior by replacing only the
  load instruction and deleting only the terminal endian instruction, leaving
  middle instructions to be copied by RewritePlan in their original order.
- `ccmp` preserves the old final-branch offset formula by patching the branch
  after the global `addr_map` exists.
- `prefetch` preserves insertion order by iterating the already sorted and
  deduplicated candidate list; repeated insertions at the same PC append in the
  same order as the deleted grouped BTreeMap loop.
- All kop passes commit with `RemapKOperation`, matching the previous
  `remap_kop_btf_metadata()` call after mutation.

Only `cargo build --workspace --locked` was run, per task instruction. No cargo
tests, benchmarks, or make targets were run.

## Verification

The bpfopt workspace was built after each pass migration in this order:

1. public `RewritePlan` API update
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`
6. `ccmp`
7. `bulk_memory`
8. `prefetch`

Final required builds:

```text
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
Finished `dev` profile [unoptimized + debuginfo]

cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
Finished `dev` profile [unoptimized + debuginfo]
```

## CLAUDE.md Compliance

- Did not run `cargo test`, `cargo bench`, `make corpus`, or `make test`.
- Did not touch `map_inline.rs`, `insn.rs`, daemon sources, runner, corpus, e2e,
  micro, or vendor paths.
- Did not add framework metrics, summaries, ratios, geomeans, or rollups.
- Did not add fallback behavior or `#[allow(dead_code)]`.
- Did not introduce hardcoded BTF IDs or helper numeric aliases.
- Did not revert #277 changes and did not commit.
- `insert_before` and `add_internal_branch` both have real callers after this
  migration.

## Suggested Next Steps

- Consider whether `map_inline` has a separable subset that can use
  `RewritePlan`, but do not attempt a single bulk migration of the 5500-line
  file.
- Consider moving more transaction-specific helpers from `utils.rs` behind
  `rewrite.rs` once remaining direct callers are reduced.
- Add focused bytecode identity tests only if they catch a real regression mode,
  for example endian middle-instruction mapping or ccmp internal branch offset.
