# DangerousHelperFirewallPass TDD Report (2026-03-26)

## Scope

Added a phase-1 `DangerousHelperFirewallPass` stub and registered it in the daemon pass registry. The pass currently returns the input program unchanged on purpose so the new unit tests stay red until the rewrite logic is implemented.

## Files Changed

- `daemon/src/passes/dangerous_helper_firewall.rs`
- `daemon/src/passes/mod.rs`

## Tests Added

The new test module covers:

- empty program handling
- helper-free program unchanged
- safe helper unchanged
- `send_signal` deny rewrite to `mov64 r0, -1`
- `override_return` deny rewrite to `mov64 r0, -1`
- `ktime_get_ns` coarseify rewrite to helper `160`
- `probe_read_kernel` audit-only behavior without bytecode change
- multiple dangerous helper sites in one program
- branch offset fixup when `send_signal` cleanup removes argument setup instructions

## Command Run

```bash
cargo test --manifest-path daemon/Cargo.toml dangerous_helper
```

## Result

The suite compiled and failed as expected for TDD red:

- 9 tests run
- 3 passed
- 6 failed

Passing tests:

- `test_empty_program`
- `test_no_helpers_unchanged`
- `test_safe_helper_unchanged`

Failing tests:

- `test_send_signal_replaced`
- `test_override_return_replaced`
- `test_ktime_get_ns_coarseified`
- `test_probe_read_kernel_audit_only`
- `test_multiple_dangerous_calls`
- `test_branch_fixup_after_replacement`

The failures are expected because the pass is still a no-op stub:

- `result.program_changed` remains `false`
- `sites_applied` remains `0`
- audit-only dangerous helpers are not reported in `sites_skipped`
- bytecode and branch offsets are not rewritten

## Notes

- The filtered test run completed in the daemon crate only; no kernel or VM actions were performed.
- Existing compile warnings unrelated to this TDD work were left unchanged.
