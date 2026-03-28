# bpfrejit-daemon

`bpfrejit-daemon` is the Rust userspace control plane for BpfReJIT v2.
It discovers live kernel BPF programs, runs the rewrite pipeline, and applies
rewritten bytecode via `BPF_PROG_REJIT`.

All active CLI usage goes through `serve`.

## Build

```bash
cd daemon
cargo build --release
cargo test
```

The binary is produced at `daemon/target/release/bpfrejit-daemon`.

## Serve Mode

Start the long-running Unix socket server:

```bash
sudo daemon/target/release/bpfrejit-daemon serve
sudo daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit.sock
sudo daemon/target/release/bpfrejit-daemon --pgo serve --socket /tmp/bpfrejit.sock
```

Flags:

- `--socket PATH`: override the Unix socket path. Default: `/var/run/bpfrejit.sock`
- `--pgo`: collect runtime profiling before each optimize request
- `--pgo-interval-ms N`: PGO observation interval, default `500`
- `--no-rollback`: disable verifier-guided pass rollback

When `--pgo` is enabled, the kernel must have `kernel.bpf_stats_enabled=1`.

## JSON Protocol

`serve` speaks newline-delimited JSON over a Unix domain socket.

Health check:

```json
{"cmd":"status"}
```

Optimize one live program:

```json
{"cmd":"optimize","prog_id":42}
```

Dry-run optimize one live program:

```json
{"cmd":"optimize","prog_id":42,"dry_run":true}
```

Optimize all live programs:

```json
{"cmd":"optimize-all"}
```

Override pass selection for a request:

```json
{"cmd":"optimize","prog_id":42,"enabled_passes":["map_inline","const_prop","dce"]}
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

## Pipeline

The daemon builds a pass pipeline in `daemon/src/passes/` and executes it
through `PassManager` in `daemon/src/pass.rs`.

The active benchmarked default pipeline is:

- `map_inline`
- `const_prop`
- `dce`
- `wide_mem`
- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `branch_flip`

Security-oriented passes are not part of the default benchmark pipeline.

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
