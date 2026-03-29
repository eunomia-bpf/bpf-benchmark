# Tracee `map_inline` Regression And Tetragon Timeout Investigation

Date: 2026-03-28

## Executive Summary

- Tracee regression root cause is confirmed.
  - The lost site was program `20` / `sys_enter_submit` / `PC=133` (`bpf_map_lookup_elem`).
  - The regression was introduced by the speculative lookup-pattern removal relaxation in commit `0131d10` (`daemon: relax map inline specialization`).
  - The relaxed path started trying to remove the whole lookup/null-check pattern for a site that previously only needed a load-only rewrite.
  - Because the removable setup region contained a branch target (`PC=129`), the new branch-target veto skipped the site entirely.
- `total_sites 131 -> 68` and `dce_sites 98 -> 36` were downstream effects of the same single lost Tracee site.
  - Old run removed `62` unreachable instructions after inlining that site.
  - New run lost exactly those `62` DCE opportunities: `98 - 36 = 62`, `131 - 68 = 63` (the extra `1` is the lost map-inline site itself).
- Fix implemented in `daemon/src/passes/map_inline.rs`.
  - If speculative full-pattern removal would cross a branch target, the pass now falls back to the old load-only rewrite instead of skipping the site.
  - This preserves old hits while still allowing newly relaxed safe cases to inline.
- Tetragon `timed out after 3 seconds` was not the real startup timeout.
  - Real startup wait is still `20s` in `e2e/cases/tetragon/case.py`.
  - The `3s` came from `runner/libs/agent.py:50-61`, where `stop_agent()` escalates from `SIGINT` to `SIGTERM`/`SIGKILL`.
  - When Tetragon failed to become healthy, cleanup raised `TimeoutExpired(... after 3 seconds)` and overwrote the original startup failure.
- Fix implemented in `e2e/cases/tetragon/case.py`.
  - Startup failure paths now preserve the original `failed to become healthy within 20s` or `healthy but no new BPF programs` message.
  - Cleanup failure is appended as additional context instead of replacing the primary error.

## Task 1: Tracee `map_inline` Regression

### 1. Lost Site Identification

Compared:

- Old successful Tracee run:
  - `e2e/results/tracee_20260328_204309/metadata.json`
- New regressed Tracee run:
  - `e2e/results/tracee_20260329_011116/metadata.json`

Confirmed lost site:

- Program id: `20`
- Program name: `sys_enter_submit`
- Call site: `PC=133`
- Old diagnostic:
  - `site at PC=133: inlined successfully, value=0xdb`
- New diagnostic:
  - `site at PC=133` skipped with reason `lookup pattern contains a branch target`

Relevant bytecode around the site from `corpus/build/tracee/tracee.bpf.o`:

- `129: r2 = r10`
- `130: r2 += -0x10`
- `131/132: ldimm64 r1 = sys_32_to_64_map`
- `133: call bpf_map_lookup_elem`
- `136: if r0 == 0 goto +1`
- `137: r1 = *(u32 *)(r0 + 0x0)`
- `138: *(u32 *)(r7 + 0x74) = r1`

There is an earlier branch landing at `PC=129`, so the setup region for the lookup contains a branch target.

### 2. Why The Site Regressed

Before commit `0131d10`, `build_site_rewrite()` only removed the lookup pattern when `info.can_remove_lookup_pattern_v1()` allowed it.

After commit `0131d10`, that decision changed to:

- `site_can_attempt_lookup_pattern_removal(program, uses, info, null_check_pc)`

That new helper allows speculative pattern removal for more hash/LRU-hash cases when:

- the site is speculative,
- there are no `other_uses`,
- and there is a fallthrough null-check.

That is exactly what happened to Tracee `sys_enter_submit` `PC=133`:

1. The old code performed a load-only rewrite at `PC=137`, so the site counted as applied.
2. The relaxed code attempted to remove the whole lookup/null-check/setup region.
3. The existing branch-target safety check then saw that `PC=129` is a branch target.
4. Instead of falling back to the old load-only rewrite, the site was fully skipped.

So the regression was not caused by the widened key extraction itself. It was caused by the new speculative full-pattern-removal path changing a previous partial-success case into an all-or-nothing skip.

### 3. Why `total_sites` And `dce_sites` Also Dropped

Old Tracee result for program `20`:

- `map_inline_sites = 1`
- `dce` diagnostic included:
  - `removed 62 unreachable insns`
  - `removed 36 nop insns`

New Tracee result for program `20`:

- `map_inline_sites = 0`
- `dce` diagnostic only included:
  - `removed 36 nop insns`

This explains the counters directly:

- `dce_sites`: `98 -> 36`
  - lost `62` unreachable instructions
- `total_sites`: `131 -> 68`
  - lost `62` DCE opportunities plus the `1` lost map-inline site

So all three regressions came from the same missed Tracee inline site.

### 4. Code Fix

Implemented in `daemon/src/passes/map_inline.rs:942-956`.

New behavior:

- If the speculative rewrite wants to remove lookup setup instructions, but one of those instructions is a branch target, the pass no longer skips the whole site.
- Instead it:
  - emits a diagnostic:
    - `site at PC={}: keeping lookup pattern because removal would cross a branch target`
  - clears `rewrite.skipped_pcs`
  - keeps `rewrite.removed_null_check = false`

That means:

- safe speculative full-pattern removals still happen,
- old branch-target-sensitive sites fall back to load-only rewriting,
- the old Tracee site remains inlineable.

### 5. Regression Test

Added targeted unit test in `daemon/src/passes/map_inline_tests.rs:1595-1653`:

- `map_inline_pass_falls_back_to_load_only_when_speculative_lookup_setup_has_branch_target`

It reproduces the exact failure mode:

- speculative hash lookup,
- removable setup region contains a branch target,
- full removal would be rejected,
- load-only rewrite must still succeed.

## Task 1 Validation

Completed:

- `make daemon-tests`
  - Result: `517 passed; 0 failed`
- Targeted regression test:
  - included in the suite above
  - passed

Status:

- Host-side validation is complete.
- The fix is specifically designed to restore the lost Tracee `PC=133` site by preserving the pre-relaxation load-only behavior when full speculative removal is unsafe.

## Task 2: Tetragon `3s` Timeout

### 1. What The `3s` Really Was

Tetragon startup logic in `e2e/cases/tetragon/case.py`:

- `DEFAULT_LOAD_TIMEOUT_S = 20`
- `TetragonAgentSession.__enter__()` waits with:
  - `wait_healthy(self.process, self.load_timeout, ...)`

So the actual health wait is `20s`, not `3s`.

The `3s` comes from `runner/libs/agent.py:50-61`:

- `SIGINT` wait: `timeout=8` from `TetragonAgentSession.close()`
- then:
  - `proc.wait(timeout=3)` after `terminate()`
  - `proc.wait(timeout=3)` after `kill()`

Therefore the error

- `Command '['/usr/local/bin/tetragon', ...] timed out after 3 seconds`

was cleanup-time `TimeoutExpired`, not the primary startup-time failure.

### 2. Why This Was Misleading

Failure payload from:

- `e2e/results/tetragon_20260329_014323/metadata.json`

contains:

- `baseline = None`
- `preflight = None`
- `programs = []`

So the failure happened before the case ever reached workload execution. That points to `TetragonAgentSession.__enter__()` startup.

But the old code did:

1. Tetragon fails to become healthy.
2. `self.close()` runs.
3. `stop_agent()` raises a `TimeoutExpired(... after 3 seconds)`.
4. That cleanup exception overwrites the original startup reason.

### 3. What Changed Relative To The Previous OK Run

Previous successful result:

- `e2e/results/tetragon_authoritative_20260328.json`

shows the same major environment characteristics:

- kernel: `7.0.0-rc2+`
- binary: `/usr/local/bin/tetragon`
- command includes `--cgroup-rate 1000,1s`
- case completed successfully

So there is no evidence that the nominal `20s` load timeout became globally too short for this kernel/environment.

The real regression here is the harness error path:

- the latest failure surfaced as a fake `3s` startup timeout,
- even though `3s` was just cleanup,
- which made diagnosis materially harder.

### 4. Code Fix

Implemented in `e2e/cases/tetragon/case.py:174-231`.

Changes:

- On `not healthy`:
  - collect startup logs,
  - attempt cleanup,
  - keep the primary error:
    - `Tetragon failed to become healthy within {load_timeout}s: ...`
  - append cleanup failure if cleanup also fails.
- On `healthy but no new BPF programs were found`:
  - same pattern: preserve primary startup/selection failure,
  - append cleanup failure instead of replacing it.
- In `close()`:
  - cleanup failure is wrapped as:
    - `failed to stop Tetragon process cleanly: ...`

### 5. Unit Coverage

Added Python tests in `tests/python/test_tetragon_case.py:95-140`:

- `test_tetragon_session_preserves_startup_failure_when_cleanup_times_out`
- `test_tetragon_session_preserves_empty_program_failure_when_cleanup_times_out`

These lock in the behavior that:

- original startup failure text remains visible,
- cleanup timeout remains visible as secondary context,
- raw cleanup `3s` timeout no longer replaces the real reason.

## Task 2 Validation

Completed:

- `pytest -q tests/python/test_tetragon_case.py`
  - Result: `5 passed`
- `python3 -m py_compile tests/python/test_tetragon_case.py e2e/cases/tetragon/case.py`
  - Result: passed

Additional debugging performed:

- Direct `vng-wrapper --verbose` boot with a trivial guest command (`echo VM_OK`) fails before guest execution.
- Root cause of that direct debug failure is not Tetragon.
  - The guest kernel panics during hostfs setup because `9p`, `virtiofs`, and `overlay` modules disagree with the running `bzImage`.
  - This is a direct-boot environment issue that occurs when bypassing the standard `make` path.
  - It is why ad-hoc `vng` debugging was not a valid replacement for `make vm-e2e`.

Pending:

- `make vm-e2e TARGET=x86 E2E_CASE=tetragon`
  - At the time of this report update, final VM validation was still blocked by another active repository benchmark/build workflow (`runner/scripts/aws_x86.sh full`), and I did not run a concurrent performance benchmark against repository policy.

## Files Changed

- `daemon/src/passes/map_inline.rs`
- `daemon/src/passes/map_inline_tests.rs`
- `e2e/cases/tetragon/case.py`
- `tests/python/test_tetragon_case.py`

