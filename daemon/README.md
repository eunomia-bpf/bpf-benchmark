# bpfrejit-daemon

`bpfrejit-daemon` keeps the benchmark runner on the socket JSON boundary while
delegating bytecode work to the v3 CLI tools (`bpfget`, `bpfopt`, `bpfverify`,
`bpfrejit`, and `bpfprof`).

## Build

```bash
cargo build --release --manifest-path daemon/Cargo.toml
cargo test --manifest-path daemon/Cargo.toml
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

`branch_flip` is opt-in and requires a loaded profile with per-site branch data.

## Layout

```text
daemon/
  Cargo.toml
  src/main.rs      # CLI entry point
  src/server.rs    # socket server and request dispatch
  src/commands.rs  # CLI subprocess orchestration
  src/bpf.rs       # libbpf-backed BPF helpers used by the daemon
  src/invalidation.rs
```
