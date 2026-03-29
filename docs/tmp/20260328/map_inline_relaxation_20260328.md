# map_inline relaxation validation (2026-03-28)

## Scope

Implemented the three requested relaxations in `daemon/src/passes/map_inline.rs`:

1. Wide-key split-store bookkeeping
2. Full-removal contiguous proxy relaxation
3. `r0` use-classifier helper/scalar relaxation

Constraints honored:

- No changes under `docs/paper/`
- No changes under `vendor/linux-framework`
- No commit / push

## Code changes

### 1. Wide key / split-store bookkeeping

- Extended constant key extraction to collect multi-store stack materialization across the full key width instead of only a single terminal store.
- Added `materialization_pcs` tracking on `ConstantKey` so all participating `STX_MEM` / `LD_IMM64` instructions can be removed when full lookup elimination is legal.
- `find_constant_stack_bytes_with_limit()` now merges bytes from split stack stores and records all contributing materialization PCs.
- This covers patterns such as:
  - 16B key via 2 x `STX_MEM_DW`
  - 16B key via 4 x word/halfword stores

### 2. Full-removal contiguous proxy relaxation

- Replaced the previous contiguous-block requirement in `lookup_pattern_removal_is_safe()`.
- Full removal now tolerates side-effect-free gap instructions between map FD load, key setup, and lookup helper, as long as those instructions:
  - do not branch
  - are not calls
  - are not stores
  - do not read/define `r1` or `r2`
- Added `site_can_attempt_lookup_pattern_removal()` so speculative hash-map sites can attempt full removal when the use pattern and null-check shape are safe.

### 3. `r0` use-classifier helper/CFG relaxation

- Refined `classify_r0_uses_with_options()` so helper calls only block full removal when the helper directly consumes a live lookup-result pointer alias.
- Patterns like:

  `r6 = *(u32 *)(r0 + 4); r1 = r6; call helper(r1)`

  are now treated as scalar-only uses and remain eligible for full removal.
- `null_check_removal_window_is_trivial()` now tracks safe scalar registers through the guarded window so scalar helper forwarding after an inlined load does not keep the null path alive unnecessarily.

## Added / updated tests

Added targeted coverage for the three relaxations:

- `classify_r0_uses_allows_helper_argument_loaded_from_lookup_value`
- `map_inline_pass_removes_interleaved_side_effect_free_setup_gap`
- `map_inline_pass_removes_hash_lookup_with_16_byte_split_dw_key`
- `map_inline_pass_removes_hash_lookup_before_helper_using_loaded_scalar`

Updated cascade expectation to reflect earlier full removal:

- `cascade_hash_map_removes_lookup_and_null_path_then_folds_non_null_path`

## Phase 1: daemon validation

Completed:

- `cargo test map_inline --manifest-path daemon/Cargo.toml`
  - Result: `83 passed; 0 failed`
- `make daemon-tests`
  - Result: `517 passed; 0 failed`
- `make daemon`
  - Result: success

## Phase 2: vm-e2e TARGET=x86

### Queue / retry note

- The first `make vm-e2e TARGET=x86` spent a long time queued behind another workspace-level `vm_global` holder.
- After the lock was released, I mistakenly killed the original wrapper while checking whether the queued job had actually started.
- That first partial run produced false host-side `vm-tmp/...` missing-directory errors for later cases and is not used for final judgement.
- I then reran `make vm-e2e TARGET=x86` cleanly and use only that second run below.

### Final second-run result

Command:

- `make vm-e2e TARGET=x86`

Result:

- Overall: failed
- Pass cases: `tracee`, `bpftrace`, `scx`, `katran`, `bcc`
- Fail cases: `tetragon`

Per-case status:

- `tracee`: `ok`
- `tetragon`: `error`
- `bpftrace`: `ok`
- `scx`: `ok`
- `katran`: `ok`
- `bcc`: `ok`

### Requested observations

Katran map-inline site count:

- Baseline (`20260328`): `6 / 6 / 6`
- New run (`20260329`): `6 / 6 / 6`
- Net change: no change

Tracee map-inline site count:

- Baseline (`20260328`): program `20` had `map_inline_sites = 1`
- New run (`20260329`): program `20` has `map_inline_sites = 0`
- Net change: `-1`

Additional tracee scan delta:

- `total_sites`: `131 -> 68`
- `dce_sites`: `98 -> 36`

Tetragon health:

- Not normal in the clean rerun.
- Error:
  - `Tetragon case could not run: Command '['/usr/local/bin/tetragon', '--cgroup-rate', '1000,1s', '--tracing-policy-dir', '/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/vm-tmp/tetragon-policy-m_myr_ai']' timed out after 3 seconds`

6-case pass/fail summary:

- `5 / 6` passed
- Failed case: `tetragon`

## Phase 3: vm-corpus REPEAT=50

Not run.

Reason:

- The Phase 2 gate did not pass because `tetragon` failed in the clean rerun.
- There is also an unexpected `tracee` regression in `map_inline_sites` (`1 -> 0`), so a corpus smoke run would not have been a sound final validation point.
