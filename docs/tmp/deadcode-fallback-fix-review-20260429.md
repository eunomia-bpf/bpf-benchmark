# Review: 79f8a135 dead-code/fallback/silence-error fix

Date: 2026-04-29

Reviewed commit: `79f8a135603257eb2460b2d628b61e840e62ae59`

Scope: `bpfopt/crates/` and non-daemon fail-fast grep coverage. `daemon/` was intentionally excluded because it is under separate bpqonyswp refactor.

## Summary

No CRITICAL fail-fast regressions found in the reviewed scope.

The commit removes the two requested fallback paths:

- `bpfget --target` no longer emits `target.json` with empty `kinsns`; locally it exits 1 with contextual stderr and empty stdout when BTF enumeration is denied.
- `bpfprof` no longer emits `pmu_available: false`; PMU collection is required and failures propagate as errors.

The dead-code and silence-error grep checks are clean for `bpfopt/crates/`. The only non-code grep hits outside `daemon/`, `vendor/`, `target/`, and `docs/tmp/` are policy text in `CLAUDE.md` and `docs/kernel-jit-optimization-plan.md`.

## Findings

### MEDIUM: bpfget target-failure tests do not recognize missing vmlinux BTF

Location: `bpfopt/crates/bpfget/tests/cli.rs:59`

`target_btf_probe_unavailable()` recognizes permission-denied probing, no BTF objects, and no kinsn functions. It does not recognize the new fail-fast error path from `bpfget --target` when `KernelBtf::load_vmlinux()` itself fails, for example a host with no readable vmlinux BTF:

- `bpfopt/crates/bpfget/src/main.rs:307`
- `bpfopt/crates/bpfget/src/main.rs:333`

On such a host, `target_stdout_contains_arch_and_features`, `test_target_btf_probe_failure_exits_nonzero`, and `target_output_writes_json_file` can fail the test suite instead of treating the environment as target-BTF unavailable.

Fix suggestion: extend `target_btf_probe_unavailable()` to include the `load vmlinux BTF for split BTF probing` / `btf__load_vmlinux_btf` capability-missing path, preferably with specific errno text such as `No such file or directory`, `Operation not permitted`, or `Permission denied`. Keep unexpected parser or JSON errors non-skipped.

Impact: this is a test portability gap, not a production fallback. It can matter for all-platform smoke if any target lacks vmlinux BTF.

## Verified Behavior

`bpfget --target` without usable BTF:

```text
exit 1
stderr: failed to probe target kinsn BTF; --target requires readable kernel BTF or explicit --kinsns: enumerate BTF objects after id 0: BPF_BTF_GET_NEXT_ID: Operation not permitted (os error 1)
stdout: empty
```

`bpfget --target --kinsns bpf_rotate64:77` exits 0 and emits target JSON with the explicit kinsn descriptor.

`bpfprof --all --duration 100ms` exits 1 in this local environment before PMU setup because BPF program enumeration is not permitted:

```text
enumerate BPF programs after id 0: BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)
```

The PMU fail-fast path is covered by the unit test `pmu_open_failure_returns_error_without_sampling_window`.

## Grep Checks

Commands run:

```bash
rg -n "#\[allow\(dead_code\)\]|#\[cfg_attr\(not\(test\), allow\(dead_code\)\)\]" bpfopt/crates
rg -n "kinsns:\s*HashMap::new\(\)|kinsns:\s*BTreeMap::new\(\)|pmu_available:\s*false|pmu_available" bpfopt/crates
rg -n "\.ok\(\)|let _ = |unwrap_or_default\(|unwrap_or_else\(\|_\|" bpfopt/crates
rg -n "prog_load_dryrun\b|map_get_next_id\b" bpfopt/crates
rg -n "\.ok\(\)|let _ = |unwrap_or_default\(|unwrap_or_else\(\|_\|" --glob '!daemon/**' --glob '!vendor/**' --glob '!docs/tmp/**' --glob '!target/**' --glob '!**/target/**'
```

Results:

- `bpfopt/crates`: zero hits for `#[allow(dead_code)]`, empty-kinsns/PMU fallback patterns, and banned silence-error text patterns.
- `prog_load_dryrun` and `map_get_next_id`: zero hits in `bpfopt/crates`; `prog_load_dryrun_with_fd_array` remains as a real caller-facing API.
- non-daemon/non-vendor/non-target code grep: only policy-document hits in `CLAUDE.md` and `docs/kernel-jit-optimization-plan.md`.

## Verification

Commands run from `bpfopt/`:

```bash
cargo build --workspace
cargo test --workspace
cargo clippy --workspace --all-targets -- -D warnings
```

Results:

- `cargo build --workspace`: passed
- `cargo test --workspace`: passed
- `cargo clippy --workspace --all-targets -- -D warnings`: passed

## Conclusion

Ready to enter #47 all-platform functional smoke, with one caveat: if the smoke matrix includes hosts without vmlinux BTF, fix the bpfget test predicate above first to avoid a false red test result.
