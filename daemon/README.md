# bpfrejit-daemon

`bpfrejit-daemon` keeps the benchmark runner on the socket JSON boundary while
running live BPF discovery, dry-run verification, and final ReJIT in-process.
`bpfopt` remains an external pure bytecode CLI, and `bpfprof` remains the
external profiling CLI.

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
{"cmd":"optimize","prog_id":42,"enabled_passes":["map_inline","const_prop","dce"]}
{"cmd":"optimize","prog_id":42,"dry_run":true,"enabled_passes":["map_inline","const_prop","dce"]}
```

`branch_flip` is experimental Paper B scaffolding. It is opt-in and uses loaded
profile data when requested; it is not part of the default optimizer pass list.

## Layout

```text
daemon/
  Cargo.toml
  crates/bpfget/     # daemon-owned live program snapshot library
  crates/bpfverify/  # daemon-owned verifier dry-run library
  crates/bpfrejit/   # daemon-owned BPF_PROG_REJIT library
  src/main.rs        # CLI entry point
  src/server.rs      # socket server and request dispatch
  src/commands.rs    # in-process BPF orchestration + bpfopt/bpfprof CLI calls
  src/bpf.rs         # libbpf-backed map/watch helpers used by the daemon
  src/invalidation.rs
```
