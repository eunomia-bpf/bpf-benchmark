# P61 Cross-Program Daemon Parallelism

## Summary

P61 moves the daemon's cross-program work from serial loops to rayon-backed parallel execution:

- `optimize-all` now processes independent BPF program IDs with `par_iter`.
- map-invalidation reapply now reoptimizes invalidated program IDs in parallel.
- each program still calls the existing `try_apply_one` or `try_reapply_one` path, so the socket protocol and CLI subprocess boundary stay unchanged.
- shared daemon state remains protected by mutexes: `reoptimization_state`, invalidation tracking, and failure aggregation.
- `program_order` is built before parallel execution and returned in that same order; error reporting sorts collected failures by `prog_id`.

The KVM benchmark defaults now request 12 vCPUs and 64G memory through `runner/targets/x86-kvm.env`. Test VM sizing is unchanged.

## Why Rayon

The daemon work units are independent and dominated by fork+exec pipelines:

1. `bpfverify` for verifier states.
2. `bpfopt`.
3. final `bpfverify`.
4. `bpfrejit`.

Rayon gives bounded cross-program concurrency with fail-fast `try_for_each`, avoids bespoke worker lifecycle code, and keeps the hot path close to the existing iterator structure. The subprocesses remain the isolation boundary required by the v3 daemon design.

## Jobs Default

`bpfrejit-daemon serve` accepts `--jobs N`, and the same value can be supplied through `BPFREJIT_DAEMON_JOBS`.

When neither is set, the daemon uses `std::thread::available_parallelism()` and initializes rayon's global thread pool with that count. In KVM runs this means the default tracks the guest CPU count rather than the host CPU count.
