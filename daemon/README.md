# bpfrejit-daemon

`bpfrejit-daemon` is the userspace front end for BpfReJIT v2, written in Rust.
It scans live kernel BPF programs for optimization sites and can apply
bytecode rewrites via `BPF_PROG_REJIT`.

**Zero libbpf dependency** -- all kernel interaction is via raw BPF syscalls.

## Build

```bash
cd daemon
cargo build --release
# run unit tests
cargo test
```

The binary is produced at `daemon/target/release/bpfrejit-daemon`.

## Subcommands

### `enumerate` -- list all live BPF programs with optimization sites

```bash
sudo bpfrejit-daemon enumerate
```

### `rewrite <prog_id>` -- dry-run rewrite (print result, do not apply)

```bash
sudo bpfrejit-daemon rewrite 42
```

### `apply <prog_id>` -- rewrite and apply via BPF_PROG_REJIT

```bash
sudo bpfrejit-daemon apply 42
```

### `apply-all` -- rewrite and apply all live programs

```bash
sudo bpfrejit-daemon apply-all
```

## Supported Transforms (POC)

| Family | Description |
|--------|-------------|
| **WIDE_MEM** | Replaces byte-ladder loads (2/4/8 byte LE recompose) with a single wide `LDX_MEM` |

Additional transforms (ROTATE, COND_SELECT, BITFIELD_EXTRACT, etc.) are planned
for post-POC implementation.

## Layout

```
daemon/
  Cargo.toml
  src/
    main.rs       # CLI entry point (clap)
    bpf.rs        # BPF syscall wrappers (zero libbpf)
    insn.rs       # BPF instruction encoding/decoding
    matcher.rs    # Pattern matching (WIDE_MEM)
    rewriter.rs   # Bytecode rewrite + branch fixup
    emit.rs       # Per-transform emit logic
```

## Dependencies

- `clap` -- CLI argument parsing
- `libc` -- raw syscall interface
- `anyhow` / `thiserror` -- error handling

No libbpf, no yaml-cpp, no C++ dependencies.
