# daemon / bpfopt unification correction (2026-04-28)

## Corrected decision

`bpfopt-core` is the single source of truth for pass, IR, and analysis code.
The daemon depends on `bpfopt-core`; it does not keep a duplicate
`daemon/src/passes/` tree.

`08f8a7cf` took the opposite direction by deleting `bpfopt/` and keeping
daemon passes. That direction is superseded by the later refactor:

- restored `bpfopt/`
- migrated daemon's newer pass implementations into `bpfopt-core`
- deleted daemon's duplicate `analysis/`, `passes/`, `insn.rs`, `pass.rs`,
  `verifier_log.rs`, and test-only ELF/parser helpers
- kept daemon runtime logic in daemon

## Runtime boundary

daemon remains the only live REJIT runtime entry. It owns:

- `serve` socket API
- raw BPF syscalls
- live program and map discovery
- per-pass `BPF_PROG_LOAD` verifier callback
- final `BPF_PROG_REJIT`
- profiler and invalidation tracker
- final result/error reporting

`bpfopt-core` owns shared code:

- `BpfInsn` and bytecode helpers
- `BpfProgram`, `PassContext`, `PassManager`
- CFG/liveness/branch-target/map-info analyses
- all optimization passes
- verifier log parser consumed by const-prop/map-inline

## Adapter split

The unified pass code uses adapters rather than daemon-only imports:

- `MapInfoProvider` / `MapValueProvider`
  - daemon: live raw BPF syscall provider
  - bpfopt CLI/tests: snapshot metadata/value provider
- `KinsnCallResolver`
  - daemon: descriptor BTF FD array slots encoded in `CALL.off`
  - bpfopt CLI: static target call offsets

This keeps the pass pipeline behavior unchanged while avoiding a second pass
implementation.

## Validation

The corrected refactor was validated with:

- `cargo test --manifest-path bpfopt/Cargo.toml`
- `cargo test --manifest-path daemon/Cargo.toml`
- `make -C daemon release`
