# bpfrejit-daemon

`bpfrejit-daemon` keeps the benchmark runner on the socket JSON boundary while
running live BPF discovery, fd-array construction, optional `const_prop`
verifier-state capture, and final ReJIT in-process. `bpfopt` remains an
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
`BPF_PROG_REJIT` directly. It does not perform a `BPF_PROG_LOAD` dry-run unless
the request explicitly includes `const_prop`; that pass needs verifier-state JSON
as a `bpfopt` side input.

`branch_flip` is experimental Paper B scaffolding. It is opt-in and uses loaded
profile data when requested; it is not part of the default optimizer pass list.

## Layout

```text
daemon/
  Cargo.toml
  crates/bpfget/     # daemon-owned live program snapshot library
  src/main.rs        # CLI entry point
  src/server.rs      # socket server and request dispatch
  src/commands.rs    # in-process BPF orchestration + bpfopt/bpfprof CLI calls
  src/dry_run.rs     # thin const_prop verifier-state capture only
  src/bpf.rs         # libbpf-backed map/watch helpers used by the daemon
  src/invalidation.rs
```
