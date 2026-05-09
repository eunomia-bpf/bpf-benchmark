# RewriteBuilder / RewritePlan P0

Date: 2026-05-09

Scope:
- Added `bpfopt/crates/bpfopt/src/passes/rewrite.rs`.
- Migrated first-batch passes only: `skb_load_bytes_spec`, `bounds_check_merge`, `const_prop`, `wide_mem`.
- Did not migrate kinsn-class passes or `map_inline`.
- Did not run corpus benchmarks.

## LOC Delta

Measured from task-start line counts in this working tree.

| File | Before | After | Delta |
|---|---:|---:|---:|
| `passes/rewrite.rs` | 0 | 263 | +263 |
| `passes/skb_load_bytes.rs` | 389 | 346 | -43 |
| `passes/bounds_check_merge.rs` | 589 | 550 | -39 |
| `passes/const_prop.rs` | 863 | 833 | -30 |
| `passes/wide_mem.rs` | 719 | 673 | -46 |
| `passes/utils.rs` | 1532 | 1532 | 0 |
| `passes/mod.rs` | 237 | 238 | +1 |
| `pass.rs` | 1012 | 1012 | 0 |
| **Total** | **5341** | **5447** | **+106** |

Migrated pass files only: `2560 -> 2402`, delta `-158`.

Tracked worktree shortstat at this point, including pre-existing dirty files outside this task:

```text
31 files changed, 766 insertions(+), 970 deletions(-)
```

## RewritePlan API

Actual signature returns `anyhow::Result<PassResult>` so BTF remap and validation errors propagate instead of being hidden.

```rust
pub struct RewritePlan { /* replacements, deletions, insertions, internal branch patches */ }

pub enum BtfRemapPolicy {
    Remap,
    NoRemap,
}

impl RewritePlan {
    pub fn new() -> Self;
    pub fn replace_range(&mut self, start_pc: usize, old_len: usize, new_insns: Vec<BpfInsn>);
    pub fn insert_before(&mut self, pc: usize, new_insns: Vec<BpfInsn>);
    pub fn delete_range(&mut self, start_pc: usize, len: usize);
    pub fn add_internal_branch(
        &mut self,
        replacement_old_pc: usize,
        replacement_idx: usize,
        target_old_pc: usize,
    );
    pub fn commit(
        self,
        program: &mut BpfProgram,
        btf_policy: BtfRemapPolicy,
    ) -> anyhow::Result<PassResult>;
}
```

`commit` owns:
- conflict and instruction-boundary validation
- `addr_map` construction
- replacement / insertion / deletion application
- LD_IMM64 two-slot copying
- surviving branch fixup via `fixup_all_branches`
- internal branch patching
- optional BTF metadata remap
- annotation remap

## Diff Samples

`skb_load_bytes_spec`: deleted local `rewrite_sites()` and now only records call-site replacements.

```diff
- let old_insns = program.insns.clone();
- let (mut new_insns, addr_map) = rewrite_sites(&old_insns, &scan.sites, layout);
- fixup_all_branches(&mut new_insns, &old_insns, &addr_map);
- program.insns = new_insns;
- program.remap_annotations(&addr_map);
+ let mut plan = RewritePlan::new();
+ for site in &scan.sites {
+     plan.replace_range(site.call_pc, 1, emit_replacement(*site, layout));
+ }
+ let mut result = plan.commit(program, BtfRemapPolicy::NoRemap)?;
```

`bounds_check_merge`: rewrite/delete plan replaces manual `replacements + skip_pcs + addr_map` loop; post-cleanup remains local.

```diff
- let mut replacements = BTreeMap::new();
+ let mut plan = RewritePlan::new();
  let mut skip_pcs = HashSet::new();
  for rewrite in &rewrites {
      let mut widened = program.insns[rewrite.dominant_add_pc];
      widened.imm = rewrite.merged_end;
-     replacements.insert(rewrite.dominant_add_pc, vec![widened]);
+     plan.replace_range(rewrite.dominant_add_pc, insn_width(&program.insns[rewrite.dominant_add_pc]), vec![widened]);
      skip_pcs.extend(rewrite.skip_pcs.iter().copied());
  }
+ for pc in skip_pcs {
+     plan.delete_range(pc, insn_width(&program.insns[pc]));
+ }
+ let mut result = plan.commit(program, BtfRemapPolicy::NoRemap)?;
```

`const_prop`: analysis stays unchanged; materialization candidates now become replacements.

```diff
- let orig_len = program.insns.len();
- let mut new_insns = Vec::with_capacity(orig_len + sites_applied);
- let mut addr_map = vec![0usize; orig_len + 1];
- while pc < orig_len { ... }
- fixup_all_branches(&mut new_insns, &program.insns, &addr_map);
- super::utils::remap_btf_metadata(program, &addr_map)?;
+ let mut plan = RewritePlan::new();
+ for (&pc, replacement) in &rewrite_plan.replacements {
+     plan.replace_range(pc, insn_width(&program.insns[pc]), replacement.clone());
+ }
+ let mut result = plan.commit(program, BtfRemapPolicy::Remap)?;
```

`wide_mem`: byte-ladder range replacement now delegates LD_IMM64 copying, branch fixup, BTF remap, and annotations.

```diff
- let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(orig_len);
- let mut addr_map: Vec<usize> = vec![0; orig_len + 1];
- while old_pc < orig_len { ... }
- fixup_all_branches(&mut new_insns, orig_insns, &addr_map);
- super::utils::remap_btf_metadata(program, &addr_map)?;
+ let mut plan = RewritePlan::new();
+ for site in &safe_sites {
+     plan.replace_range(site.start_pc, site.old_len, emit_wide_mem(site)?);
+ }
+ let mut result = plan.commit(program, BtfRemapPolicy::Remap)?;
```

## Verification

`bpfopt/` workspace:

```text
$ cargo build --workspace --locked
Finished `dev` profile [unoptimized + debuginfo] target(s)

$ cargo test --workspace --locked
lib tests: 332 passed
main tests: 12 passed
cli_pipeline: 12 passed
doc tests: 0 passed
```

`daemon/` workspace:

```text
$ cargo build --workspace --locked
Finished `dev` profile [unoptimized + debuginfo] target(s)

$ cargo test --workspace --locked
25 passed
```

Total executed tests: `332 + 12 + 12 + 25 = 381`, all passing.

`cli_pipeline` remained passing, covering fixture bytecode comparisons used by the CLI tests. No corpus benchmark was run.

## Known Remainder

P1 migration candidates:
- `rotate`
- `cond_select`
- `extract`
- `bulk_memory`
- `ccmp`
- `endian`
- `prefetch`
- `map_inline`

`branch_flip` still has custom block reordering and was not part of this P0 batch.
