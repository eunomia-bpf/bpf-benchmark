# bpfrejit-daemon

`bpfrejit-daemon` is the Rust userspace control plane for BpfReJIT v2.
It discovers live kernel BPF programs, runs the rewrite pipeline, and applies
rewritten bytecode via `BPF_PROG_REJIT`.

All active CLI usage goes through `serve`.

## Build

```bash
cargo build --release --manifest-path daemon/Cargo.toml
cargo test --manifest-path daemon/Cargo.toml
```

The binary is produced at `daemon/target/release/bpfrejit-daemon`.

## Serve Mode

Start the long-running Unix socket server inside the benchmark VM/session:

```bash
daemon/target/release/bpfrejit-daemon serve
daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit.sock
```

Flags:

- `--socket PATH`: override the Unix socket path. Default: `/var/run/bpfrejit.sock`

## JSON Protocol

`serve` speaks newline-delimited JSON over a Unix domain socket.

Health check:

```json
{"cmd":"status"}
```

Optimize one live program:

```json
{"cmd":"optimize","prog_id":42,"enabled_passes":["map_inline","const_prop","dce"]}
```

Dry-run optimize one live program:

```json
{"cmd":"optimize","prog_id":42,"dry_run":true,"enabled_passes":["map_inline","const_prop","dce"]}
```

Optimize all live programs:

```json
{"cmd":"optimize-all","enabled_passes":["map_inline","const_prop","dce"]}
```

Successful `optimize` responses embed the full structured result from
`commands::try_apply_one()`, including:

- `status`
- `prog_id`
- `changed`
- `program`
- `summary`
- `passes`
- `attempts`
- `timings_ns`
- `inlined_map_entries`

`optimize-all` returns a compact summary:

```json
{"status":"ok","total":100,"applied":5,"errors":0}
```

## Pass Selection

The daemon builds a pass pipeline in `daemon/src/passes/` and executes it
through `PassManager` in `daemon/src/pass.rs`.

Requests must provide a non-empty `enabled_passes` list. Repo runners send
explicit pass lists derived from benchmark configuration.

`branch_flip` stays out of the default benchmark profile. If a caller explicitly
enables it, the current implementation still requires PMU-friendly profiling
context and per-site branch profiles.

## Layout

```text
daemon/
  Cargo.toml
  src/
    main.rs            # CLI entry point; serve is the only active subcommand
    server.rs          # Unix socket server and request dispatch
    commands.rs        # optimize/apply helpers used by serve
    bpf.rs             # raw BPF syscall wrappers
    insn.rs            # BPF instruction encoding/decoding
    pass.rs            # pass framework and policy plumbing
    passes/            # rewrite pass implementations
    analysis/          # reusable analysis passes
    profiler.rs        # runtime profiling helpers for PGO
    kfunc_discovery.rs # module/BTF kfunc discovery
```
