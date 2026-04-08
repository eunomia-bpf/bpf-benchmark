# bpfrejit-daemon

`bpfrejit-daemon` is the Rust userspace control plane for BpfReJIT v2.
It discovers live kernel BPF programs, runs the rewrite pipeline, and applies
rewritten bytecode via `BPF_PROG_REJIT`.

All active CLI usage goes through `serve`.

## Build

```bash
make -C runner DAEMON_TARGET_DIR="$PWD/daemon/target" daemon-binary
make -C runner daemon-tests
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

## Pass Selection

The daemon builds a pass pipeline in `daemon/src/passes/` and executes it
through `PassManager` in `daemon/src/pass.rs`.

Two defaults matter here:

- Daemon request default: if a client omits `enabled_passes`, the daemon falls back to its internal registry order.
- Benchmark/e2e default: repo runners send explicit pass lists derived from [corpus/config/benchmark_config.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/benchmark_config.yaml). The current default benchmark profile is `map_inline`, `const_prop`, `dce`.

`branch_flip` stays out of the default benchmark profile. If a caller explicitly
enables it, the current implementation still requires PMU-friendly profiling
context and may use a conservative size-asymmetry fallback when per-site branch
profiles are unavailable.

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
