# bpfrejit-daemon

`bpfrejit-daemon` keeps the benchmark runner on the socket JSON boundary while
running live BPF discovery, automatic side-input preparation, fd-array
construction, and final ReJIT in-process. `bpfopt` remains an
external pure bytecode CLI, and `bpfprof` remains the external profiling CLI.

## Build

```bash
cargo build --release --manifest-path daemon/Cargo.toml
cargo test --workspace --manifest-path daemon/Cargo.toml
```

## Serve

```bash
daemon/target/release/bpfrejit-daemon serve
daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit.sock
```

`serve` speaks newline-delimited JSON over a Unix domain socket. Optimize
requests must provide a non-empty `enabled_passes` list.

```json
{"cmd":"status"}
{"cmd":"optimize","prog_id":42,"enabled_passes":["map_inline","dce"]}
```

The main optimize path snapshots the live program, runs `bpfopt`, and then calls
`BPF_PROG_REJIT` directly. It does not perform a final `BPF_PROG_LOAD` dry-run.
When requested passes need side-inputs, the daemon prepares them automatically:
`map_inline` gets live map values and verifier states, `const_prop` gets verifier
states, and kinsn passes get target metadata plus fd-array call offsets.

Main `BPF_PROG_REJIT` has no daemon-side timeout. If the kernel verifier hangs,
the daemon blocks in the syscall; this is documented behavior, not a fallback.

`branch_flip` is experimental Paper B scaffolding. It is opt-in and uses loaded
profile data when requested; benchmark defaults live in runner configuration.

## Layout

```text
daemon/
  Cargo.toml
  crates/bpfget/     # daemon-owned live program snapshot library
  src/main.rs        # CLI entry point
  src/server.rs      # socket server and request dispatch
  src/commands.rs    # in-process BPF orchestration + bpfopt/bpfprof CLI calls
  src/dry_run.rs     # thin verifier-state capture for side-input consumers
  src/bpf.rs         # libbpf-backed map/watch helpers used by the daemon
  src/invalidation.rs
```
