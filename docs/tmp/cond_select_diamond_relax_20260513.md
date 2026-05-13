# cond_select diamond join predecessor relaxation

Date: 2026-05-13

## Diff stat

Code diff stat, excluding this note:

```text
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs | 10 ++++++----
1 file changed, 6 insertions(+), 4 deletions(-)
```

## Modification principle

`replace_diamond_with_insns()` still validates that a joined diamond has the
expected local shape:

- pattern A: the conditional predecessor branches to the true and false arms,
  and both arms reach the join
- pattern C: the predecessor is the true arm, the taken edge reaches the join,
  and the false arm reaches the join

The validation no longer rejects unrelated external predecessors of the join.
This is valid because the rewrite preserves the join block. The diamond arms
that are owned by the rewritten pattern are removed or bypassed, while the
rewritten predecessor emits the replacement sequence and jumps to the same join.
Any external predecessor that already targeted the join continues targeting the
same live block after CFG rebuild/remap.

For the failing `cond_select_rewrites_diamond_join_with_external_predecessor`
shape, the outer `JEQ` edge to the exit join remains intact. The inner diamond
arms are replaced by the select lowering, and the rewritten inner predecessor
falls through logically via a `JA` to the preserved join.

## Test output

Command:

```text
cargo test -p bpfopt --lib
```

Result:

```text
running 167 tests
test passes::cond_select_tests::cond_select_rewrites_diamond_join_with_external_predecessor ... ok
test result: ok. 167 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.15s
```
