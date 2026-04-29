# bpfget + bpfrejit CLI review for dc3abe33

Date: 2026-04-28

Scope:

- Reviewed `git diff dc3abe33^..dc3abe33`.
- Reviewed `bpfopt/crates/bpfget/{Cargo.toml,src/main.rs,tests/}`.
- Reviewed `bpfopt/crates/bpfrejit/{Cargo.toml,src/main.rs,tests/}`.
- Reviewed `bpfopt/Cargo.toml` workspace member changes.
- Did not modify implementation code or `docs/tmp/bpfopt_design_v3.md`.

## Verdict

Not ready to enter #41 as a v3-conformant Phase 1 pipeline yet.

The commit builds and the workspace tests pass, and the two new CLIs do not add compile-time dependencies on `bpfopt`, the daemon, or other CLI crates. However, there are two blocking issues before this should be treated as ready: `bpfget` bypasses the `kernel-sys` syscall boundary for map-id info reads, and `bpfrejit --dry-run --fd-array` is explicitly unsupported even though kinsn-bearing bytecode needs fd-array support to be dry-run verified.

## Findings

### HIGH: `bpfget` bypasses the `kernel-sys` syscall boundary

Location: `bpfopt/crates/bpfget/src/main.rs:392-413`

`read_prog_map_ids()` constructs a fork `BpfProgInfoFork` and calls `kernel_sys::libbpf_sys::bpf_obj_get_info_by_fd(...)` directly from the `bpfget` crate. The narrow grep requested by the review, `rg -n "libc::syscall|SYS_bpf" bpfget/src bpfrejit/src`, is clean, but this direct libbpf-sys BPF syscall helper call still violates the project rule that `kernel-sys` is the only syscall boundary and CLI crates call BPF syscalls only through `kernel-sys` APIs.

Impact: this moves ABI/error handling back into a CLI crate, duplicates the errno conversion already present in `kernel-sys`, and weakens the boundary that v3 relies on for all six CLI binaries.

Fix: move the second-pass map-id read into `kernel-sys`, for example `kernel_sys::prog_map_ids(fd)` or `kernel_sys::obj_get_info_with_map_ids(fd)`, and have `bpfget` call that wrapper. Keep the raw `bpf_obj_get_info_by_fd` usage and errno conversion private to `kernel-sys`.

### HIGH: `bpfrejit --dry-run --fd-array` rejects the required kinsn verification path

Location: `bpfopt/crates/bpfrejit/src/main.rs:69-72`

`bpfrejit` parses `--fd-array`, but then bails out in dry-run mode when the fd array is non-empty:

```text
--dry-run with --fd-array is not supported by current kernel-sys prog_load_dryrun
```

v3 §2.5 defines `--dry-run` as verifier-only validation and also defines `--fd-array FILE` for kinsn BTF fd_array input. Those flags need to compose because optimized bytecode containing kinsn calls cannot be verifier-checked without the same fd_array that would be used for `BPF_PROG_REJIT`.

Impact: a pipeline can submit kinsn bytecode through normal ReJIT but cannot run the v3 dry-run validation for the same payload. That blocks reliable Phase 1 validation for transformations that emit kinsn calls.

Fix: extend `kernel_sys::prog_load_dryrun()` to accept fd_array data and set `bpf_prog_load_opts.fd_array` / `fd_array_cnt`. Keep the backing fds alive through the load attempt, then remove this CLI-side rejection.

### HIGH: `bpfget --full --outdir` creates missing output directories instead of failing

Location: `bpfopt/crates/bpfget/src/main.rs:208-210`

`write_full()` calls `fs::create_dir_all(outdir)` before opening the target program or reading bytecode. The requested error behavior says nonexistent `--outdir` should exit 1. The current code instead creates the directory and can leave that directory behind even when the later program open or bytecode read fails.

Impact: this gives `--full` surprising filesystem side effects on failure and does not satisfy the requested error-path contract.

Fix: require `--outdir` to already exist and be a directory. Validate it with `fs::metadata()` / `is_dir()` before doing any kernel operation or file write, and fail with a clear stderr message if it is missing.

### MEDIUM: `bpfget --full` writes multi-file output non-atomically

Location: `bpfopt/crates/bpfget/src/main.rs:217-225` and `bpfopt/crates/bpfget/src/main.rs:472-477`

`--full` writes `prog.bin`, then `prog_info.json`, then `map_fds.json` via direct `File::create`. If JSON serialization, map info lookup, permission checks, or disk writes fail midway, the output directory can contain a partial or stale mix of files. Existing files are also truncated immediately.

Impact: downstream pipeline steps can accidentally consume half-produced side inputs if a failure is not handled carefully by the caller.

Fix: stage all outputs in a temporary directory or same-directory temporary files, flush them, then atomically rename into final names after every payload has been successfully produced. At minimum, write `map_fds.json.tmp`, `prog_info.json.tmp`, and `prog.bin.tmp` and rename only after all three writes succeed.

### MEDIUM: `bpfget --target` is schema-shaped but not v3-complete

Location: `bpfopt/crates/bpfget/src/main.rs:267-302`

`--target` emits `arch`, `features`, and `kinsns`, and it provides a manual `--kinsns name:btf_func_id` override. By default, though, `kinsns` is `{}` and the CLI prints a warning that kinsn BTF probing is not implemented.

Impact: the JSON shape matches v3 §3.2, but it does not yet perform the automatic kinsn discovery required for a useful `target.json`. Any pass requiring kinsn IDs will fail or skip unless the user supplies manual `--kinsns` values.

Fix: move the kinsn discovery logic into `bpfget` or into a shared non-CLI library callable by `bpfget`, and emit discovered kinsns by default. Keep `--kinsns` as an override/debug escape hatch.

### MEDIUM: integration tests miss several committed CLI modes

Locations:

- `bpfopt/crates/bpfget/tests/cli.rs:21-73`
- `bpfopt/crates/bpfrejit/tests/cli.rs:44-70`

The four integration tests cover:

- `bpfget --list`
- `bpfget --list --json`
- `bpfrejit` input length validation
- `bpfrejit --dry-run` argument/input ordering up to the target-program open failure

They do not cover:

- `bpfget PROG_ID` binary stdout
- `bpfget PROG_ID --info`
- `bpfget PROG_ID --full --outdir`
- `bpfget --target`
- `bpfrejit --fd-array` JSON parsing through the CLI
- a real dry-run verifier path, when the environment supports it

The unit tests are mostly useful serialization/parser checks and do not contain `size_of`-only or pure self-equality tautology coverage. The `bpfget` JSON round-trip test is weaker than the others, but it does at least assert the externally visible serde field names.

Fix: add focused integration coverage for the mode-validation and filesystem behavior that does not require a fork kernel, especially `--target`, `--info`/missing program errors, `--full` missing/outdir errors, and CLI-level `--fd-array` parse errors. Add fork-kernel gated tests for successful default/`--info`/`--full` behavior if a live program exposing original bytecode is available.

## Non-Issues Checked

- `bpfget PROG_ID` writes raw `struct bpf_insn[]` bytes to stdout and emits no JSON in the default path.
- `bpfget PROG_ID --info` writes JSON to stdout.
- `bpfget --full --outdir DIR` writes the required filenames: `prog.bin`, `prog_info.json`, and `map_fds.json`.
- `bpfget --list` uses one line per program with `id name type_name`; `--list --json` emits an array of objects.
- `bpfget` reports empty original bytecode as `program has no original bytecode (not loaded by fork kernel?)`.
- `bpfrejit PROG_ID FILE` and `bpfrejit PROG_ID < stdin` are both implemented.
- `bpfrejit` rejects byte streams whose length is not a multiple of 8 with a friendly `multiple of 8` error.
- `bpfrejit` prints success summaries to stderr and keeps stdout empty.
- `bpfrejit --fd-array` uses a JSON array of objects with optional `name`, optional `slot`, and required `btf_fd`; malformed JSON and missing/invalid fields produce contextual errors.
- `bpfget/Cargo.toml` and `bpfrejit/Cargo.toml` directly depend only on `kernel-sys`, `clap`, `serde`, `serde_json`, and `anyhow`.
- `cargo tree -p bpfget` and `cargo tree -p bpfrejit` show no dependency on `bpfopt`, `bpfverify`, `bpfprof`, `bpfrejit-daemon`, or daemon crates.
- `bpfopt/Cargo.toml` includes `crates/bpfopt`, `crates/bpfget`, `crates/bpfrejit`, and `crates/kernel-sys` as workspace members. The ordering is not a functional issue, though keeping `kernel-sys` before CLI crates would make the dependency direction visually clearer.

## Validation Run

Commands run from `bpfopt/` unless noted:

- `cargo build --workspace` passed.
- `cargo test --workspace` passed: 423 tests passed.
- `cargo tree -p bpfget` passed and confirmed no CLI cross-dependency.
- `cargo tree -p bpfrejit` passed and confirmed no CLI cross-dependency.
- From repo root, `rg -n "libc::syscall|SYS_bpf" bpfopt/crates/bpfget/src bpfopt/crates/bpfrejit/src` produced no matches.
- Additional boundary check found the direct libbpf-sys helper call at `bpfopt/crates/bpfget/src/main.rs:405`.

## #41 Readiness

Not ready for #41 as-is. I would fix the `kernel-sys` boundary violation and fd-array dry-run support first, then re-run the same build/test/tree checks plus at least one fork-kernel smoke path for:

```bash
bpfget PROG_ID --full --outdir DIR
bpfopt optimize --target target.json < DIR/prog.bin > DIR/opt.bin
bpfrejit PROG_ID DIR/opt.bin --dry-run --fd-array fd_array.json
bpfrejit PROG_ID DIR/opt.bin --fd-array fd_array.json
```
