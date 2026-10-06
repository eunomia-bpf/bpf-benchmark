# bpfprof + kernel-sys Removal - 2026-05-08

## Deleted Files and Directories

- `bpfopt/crates/bpfprof/`
  - `Cargo.toml` (19 LOC)
  - `src/main.rs` (1293 LOC)
  - `tests/cli.rs` (122 LOC)
- `bpfopt/crates/kernel-sys/`
  - `Cargo.toml` (13 LOC)
  - `src/lib.rs` (1839 LOC)
  - `src/verifier_log.rs` (943 LOC)
  - `tests/prog_get_original.rs` (77 LOC)
  - `tests/prog_ids.rs` (25 LOC)
- `scripts/p88_branch_flip_dense_pgo.sh` (153 LOC), because it invoked removed local `bpfprof` / legacy bpfopt-suite binaries.

## Moved Code

| From | To | Notes |
| --- | --- | --- |
| `bpfopt/crates/kernel-sys/src/verifier_log.rs` (943 LOC) | `bpfopt/crates/bpfopt/src/verifier_log.rs` (1179 LOC) | Moved verifier log parser into the only remaining caller crate. The destination also carries the former public verifier-state JSON/API conversion structs from `kernel-sys/src/lib.rs`. |
| `bpfopt/crates/kernel-sys/src/lib.rs` syscall wrapper subset | `daemon/src/syscall.rs` (633 LOC) | Moved only daemon-used wrappers: map lookup/iteration/open/info, prog open/info/map ids/original/rejit, and BTF id/fd helpers. bpfprof-only perf/ring-buffer/profiling code was not moved. |
| `daemon/src/bpf.rs` map-reference bytecode canonicalization helpers | `bpfopt/crates/bpfopt/src/main.rs` | `bpfopt --canonicalize-map-refs --map-ids ...` is now the first init step. This includes LDIMM64 map pseudo handling and target kinsn call-offset shifting through `--target` / `--target-output`. |

## Workspace Structure

Before:

```text
bpfopt/
  Cargo.toml
  crates/
    kernel-sys/
    bpfopt/
    bpfprof/
daemon/
  Cargo.toml  # depended on ../bpfopt/crates/kernel-sys
```

After:

```text
bpfopt/
  Cargo.toml
  crates/
    bpfopt/
      src/verifier_log.rs
daemon/
  Cargo.toml  # depends directly on libbpf-sys = 1.5
  src/syscall.rs
```

Dependency changes:

- `bpfopt/Cargo.toml` workspace members are now only `crates/bpfopt`.
- `bpfopt/crates/bpfopt/Cargo.toml` uses `libbpf-sys.workspace = true` instead of `kernel-sys`.
- `daemon/Cargo.toml` uses `libbpf-sys = "1.5"` instead of the path dependency on `kernel-sys`.
- Runner image/build rules install and verify only `bpfopt`, not `bpfprof`.

## Validation

Source checks:

```text
rg "kernel_sys::|kernel-sys|bpfprof" over live Rust/TOML/build/script files: no matches
rg "canonicalize_map_refs_to_idx|is_ldimm64|collect_fd_form_map_refs|contains_idx_form_map_ref|map_idx_pseudo|insn_raw_bytes|shift_target_module_call_offsets_for_map_prefix" daemon/src: no matches
rg "kernel-sys|bpfprof" bpfopt/Cargo.lock daemon/Cargo.lock: no matches
rg --files bpfopt/crates | rg '(^|/)(bpfprof|kernel-sys)(/|$)': no matches
```

Build:

```text
cargo build --workspace --manifest-path bpfopt/Cargo.toml
Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.01s

cargo build --workspace --manifest-path daemon/Cargo.toml
Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.01s
```

Tests:

```text
cargo test --workspace --manifest-path bpfopt/Cargo.toml
running 332 tests
test result: ok. 332 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

running 12 tests
test result: ok. 12 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

running 12 tests
test result: ok. 12 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

Doc-tests bpfopt
running 0 tests
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

```text
cargo test --workspace --manifest-path daemon/Cargo.toml
running 25 tests
test result: ok. 25 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

## Known Leftovers

- Historical/reference docs still mention the old `bpfprof` / `kernel-sys` architecture. The live source/build manifests, `CLAUDE.md`, `daemon/README.md`, and authoritative `docs/tmp/bpfopt_design_v3.md` were updated.
- No corpus benchmark was run for this migration.
