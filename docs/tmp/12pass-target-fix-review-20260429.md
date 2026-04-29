# Review: 2f36c3b8 12-pass optimize + bpfget target BTF probe

Commit reviewed: `2f36c3b8cc381ac977e27b435f8413c8d2c7d2ec`

Scope:

- `git diff 2f36c3b8^..2f36c3b8`
- `bpfopt/crates/bpfopt/src/main.rs`
- `bpfopt/crates/bpfopt/src/passes/*`
- `bpfopt/crates/bpfget/src/main.rs`
- `bpfopt/crates/kernel-sys/src/lib.rs`

## Summary

No CRITICAL functional blocker found in the reviewed implementation. The default optimize order matches v3 section 5, `bpfopt optimize` now skips missing side-input passes with warnings, per-pass subcommands still fail fast for missing side-inputs, and `bpfget --target` uses `kernel-sys` BTF APIs while preserving the empty-`kinsns` fallback.

I do not consider this ready for #47 full-platform corpus/e2e yet. The main remaining blocker is test coverage for the new BTF probing path: current tests validate target JSON shape and manual `--kinsns`, but they do not deterministically cover either automatic empty-probe fallback warnings or a non-empty auto-probed kinsn set. There is also downstream pass-list alignment work to confirm with daemon #44/#45.

## CRITICAL

None found.

Checked items:

- `DEFAULT_OPTIMIZE_PASS_ORDER` is `ALL_PASS_ORDER`, whose order is `map_inline`, `const_prop`, `dce`, `skb_load_bytes_spec`, `bounds_check_merge`, `wide_mem`, `bulk_memory`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `branch_flip` at `bpfopt/crates/bpfopt/src/main.rs:26`. This matches v3 section 5's public order: map-inline -> const-prop -> dce -> skb-load-bytes -> bounds-check-merge -> wide-mem -> bulk-memory -> rotate -> cond-select -> extract -> endian -> branch-flip.
- `bpfopt optimize` builds an `OptimizePassPlan`, emits `warning: skipping ...`, and only runs passes without `skip_reason` at `bpfopt/crates/bpfopt/src/main.rs:478`.
- Per-pass subcommands still call `validate_required_side_inputs()` and `validate_required_kinsns()` before running at `bpfopt/crates/bpfopt/src/main.rs:441`.
- No files under `bpfopt/crates/bpfopt/src/passes/*` changed in this commit.
- `bpfget --target` probes via `kernel_sys::KernelBtf` and `kernel_sys::btf_get_next_id`, not direct `libbpf-sys`, at `bpfopt/crates/bpfget/src/main.rs:332` and `bpfopt/crates/bpfget/src/main.rs:343`.
- `bpfget --target` emits v3 JSON names `bpf_rotate64`, `bpf_select64`, `bpf_extract64`, `bpf_endian_load64`, `bpf_bulk_memcpy`, and `bpf_bulk_memset` at `bpfopt/crates/bpfget/src/main.rs:111`.
- No-permission fallback was verified locally: `bpfget --target` exited 0 with `"kinsns": {}` and warnings for `BPF_BTF_GET_NEXT_ID: Operation not permitted`.
- `KernelBtf` owns the raw `btf *` and frees it in `Drop` at `bpfopt/crates/kernel-sys/src/lib.rs:405`.

## HIGH

### bpfget --target auto-probe behavior is not deterministically tested

Location:

- `bpfopt/crates/bpfget/tests/cli.rs:128`
- `bpfopt/crates/bpfget/tests/cli.rs:187`

Current tests assert that `kinsns` is an object and that any entries have numeric `btf_func_id`; the manual `--kinsns bpf_rotate64:77` test covers override serialization. They do not prove the new automatic BTF probing path:

- empty probe fallback with warning and exit 0
- non-empty auto-probed output for the six v3 kinsn names
- split-module probe path through `KernelBtf::load_from_kernel_by_id_split`

Why it matters:

The commit's largest new behavior is runtime BTF discovery. On a developer host without BPF permissions the current tests pass even if `probe_target_kinsns()` never finds a real kinsn, regresses the name mapping, or stops warning on fallback.

Fix recommendation:

Add deterministic tests around the probe layer rather than relying on the host kernel state. A practical shape is to split the probing backend behind a small trait or function table and unit-test:

- `Err(EPERM)` from `btf_get_next_id` -> `{}` plus warning, exit 0
- synthetic BTF backend containing all six names -> exact v3 `kinsns` keys and numeric IDs
- synthetic BTF backend containing only fallback internal bulk names -> output still uses `bpf_bulk_memcpy` / `bpf_bulk_memset`

These would be bug-detection tests, not mocks-only tautologies, because they verify observable JSON schema and fallback behavior.

## MEDIUM

### Downstream corpus config is still on the old 11-pass order

Location:

- `corpus/config/benchmark_config.yaml:1`
- `corpus/config/benchmark_config.yaml:14`
- `scripts/per-pass-verify.sh:32`

`bpfopt optimize` now defaults to the v3 12-pass order, but `corpus/config/benchmark_config.yaml` still lists the older 11-pass order and omits `branch_flip`. `scripts/per-pass-verify.sh` intentionally defaults to the zero-side-input subset, which is still reasonable for that script, but corpus/e2e readiness depends on how daemon #44/#45 delegates to the CLI.

Why it matters:

If daemon #44/#45 continues to send the runner's explicit `enabled_passes`, #47 corpus/e2e will not exercise the new `bpfopt optimize` default order and will still omit `branch_flip`. That may be intentional during the v3 migration, but it needs an explicit decision before treating #47 as a full 12-pass validation.

Fix recommendation:

Before #47, decide one of:

- daemon ignores absent runner pass overrides and lets `bpfopt optimize` use its default 12-pass order, with branch profile side-input available or branch-flip skipped by design
- update benchmark config after daemon migration to the v3 12-pass order, if runner-driven pass selection remains the authority

Do not refactor runner Python for this; keep the v3 socket boundary intact.

### Skipped pass reports use final bytecode length, not pass-position length

Location:

- `bpfopt/crates/bpfopt/src/main.rs:500`
- `bpfopt/crates/bpfopt/src/main.rs:1234`

`optimize_reports()` receives the final `BpfProgram` and uses `program.insns.len()` for skipped reports. If an early pass is skipped and a later pass changes instruction count, the skipped pass's `insn_count_before` / `insn_count_after` will show the final length rather than the length at that pass position.

Why it matters:

The new `skipped` and `reason` fields are reasonable, but the surrounding count fields can be misleading in reports with mixed skipped and applied passes.

Fix recommendation:

Record skipped reports while executing the planned sequence, or track the current instruction count before each runnable pass and splice skipped reports with the count at that plan position.

## LOW

### Clippy fails; one new warning is in the BTF API addition

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:390`

`cargo clippy --all-targets -- -D warnings` fails. Most failures are pre-existing `kernel-sys` lints outside this commit, but this commit adds one new `clippy::unnecessary_cast` warning:

```text
btf__find_by_name_kind(self.ptr.as_ptr(), c_name.as_ptr(), BTF_KIND_FUNC as u32)
```

Fix recommendation:

Remove the unnecessary cast and, if clippy is expected in CI, clean the existing `kernel-sys` warnings in the same cleanup pass.

### Bulk-memory skip reason exposes internal names

Location:

- `bpfopt/crates/bpfopt/src/main.rs:555`

`bpfget --target` correctly emits v3 names `bpf_bulk_memcpy` / `bpf_bulk_memset`, and `bpfopt` correctly accepts those aliases. However, `optimize_skip_reason()` reports missing bulk-memory kinsns using internal registry names `bpf_memcpy_bulk` / `bpf_memset_bulk`.

Why it matters:

This is not a schema break, but it is a user-facing mismatch with v3 section 3.2.

Fix recommendation:

Keep internal registry names if needed, but format user-facing warnings and `pass-report.json` reasons with v3 target names.

## Verification

Commands run:

```bash
git diff --stat 2f36c3b8^..2f36c3b8
git diff --name-only 2f36c3b8^..2f36c3b8
git diff 2f36c3b8^..2f36c3b8 -- bpfopt/crates/bpfopt/src/passes
cargo build
cargo test
cargo clippy --all-targets -- -D warnings
cargo run -q -p bpfget -- --target
```

Results:

- `cargo build`: PASS
- `cargo test`: PASS
- `cargo clippy --all-targets -- -D warnings`: FAIL due `kernel-sys` clippy warnings; one new warning is the BTF `BTF_KIND_FUNC as u32` cast.
- `bpfget --target` local fallback: PASS, exited 0 with `"kinsns": {}` and warnings under an unprivileged environment.

## Conclusion

Not ready for #47 full-platform corpus/e2e yet, even assuming daemon #44+#45 are ready. The implementation has no CRITICAL conformance blocker, but the new `bpfget --target` BTF probe path needs deterministic empty and non-empty tests before relying on it in full-platform runs. Also confirm whether #47 should use the new `bpfopt optimize` 12-pass default or the existing runner config pass list.
