# Dynamic Map Invalidation Review Report (2026-03-26)

## Findings

### Fixed

1. `daemon/src/invalidation.rs:118`

   `check_for_invalidations()` required `&mut self` even though the implementation only reads tracker state and the reader via shared borrows. That unnecessarily forced exclusive access for polling and made the tracker harder to use behind shared synchronization. The method now takes `&self`.

## Review Notes

- `daemon/src/invalidation.rs:56-123`

  `record_inline_site()`, `check_all()`, and `remove_prog()` are correct for the current tracker-only scope. Duplicate `(prog_id, map_fd, key)` records update in place, keys are deduplicated per map before polling, invalidated program IDs are deduplicated deterministically, and missing map values are conservatively treated as invalidations.

- `daemon/src/invalidation.rs:80-115`

  Batch behavior is efficient at the tracker layer: one `lookup_values_batch()` call per `map_fd`, with per-map key dedup via `BTreeSet`. The current implementation still stores entries in a flat `Vec`, so `record_inline_site()` remains O(n) per insertion, but that is a scale concern rather than a correctness defect in this patch.

- `daemon/src/invalidation.rs:24-30`

  The `MapValueReader` seam is acceptable for unit testing and future production adapters. Allowing `check_all()` to accept `?Sized` readers keeps the abstraction usable with trait objects as well as concrete mocks.

- `daemon/src/invalidation.rs:134-180`

  `MockMapValueReader` is intentionally single-threaded (`Rc<RefCell<_>>`). That is fine for unit tests, but it should not be read as evidence that the production tracker is internally synchronized. If runtime polling and registration ever happen across threads, callers still need external synchronization around `record_inline_site()` / `remove_prog()`, and the real reader implementation should be `Send + Sync`.

- `daemon/src/main.rs:11`

  Registration is currently limited to `mod invalidation;`. There is no integration into `cmd_watch()` or `cmd_serve()` yet, so this patch provides the tracker primitive, not the full #474f runtime invalidation loop.

## Test Results

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml invalidation
```

Result:

- Passed: 12/12 filtered tests
- New invalidation tests: 9/9 passed
- Additional pre-existing `*invalidation*` substring matches: 3/3 passed

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Result:

- Failed outside the invalidation area
- Suite summary: 407 passed, 6 failed, 12 ignored
- All 6 failures are in `daemon/src/passes/dangerous_helper_firewall.rs`
