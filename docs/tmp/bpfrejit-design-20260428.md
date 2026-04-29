# bpfrejit CLI design note - 2026-04-28

## Scope

本报告只调研 `bpfrejit` CLI 的实现细节，不修改代码，也不修改
`docs/tmp/bpfopt_design_v3.md`。结论以 v3 §2.5 的字面要求为准：

- `bpfrejit PROG_ID FILE`
- `bpfrejit PROG_ID < stdin`
- `--dry-run`
- `--fd-array FILE`

当前 `bpfopt` workspace 只有 `crates/bpfopt` 和 `crates/kernel-sys`，还没有
`bpfrejit` crate（`bpfopt/Cargo.toml:1-5`）。v3 计划新增
`crates/bpfrejit`，且依赖方向是 `kernel-sys -> bpfrejit`，不是依赖
`bpfopt` 或 `bpfverify`（`docs/tmp/bpfopt_design_v3.md:534-564`）。

## Existing API references

- `kernel-sys` re-export 了 `libbpf-rs` / `libbpf-sys` 的 UAPI 类型和 helper；
  fork-only syscall 包在 `kernel-sys` 内（`bpfopt/crates/kernel-sys/src/lib.rs:1-15`）。
- `BPF_PROG_REJIT` 的 fork command number 现在定义为 `39`，`AttrRejit`
  包含 `prog_fd`, `insn_cnt`, `insns`, `log_*`, `fd_array`,
  `fd_array_cnt`, `flags`（`bpfopt/crates/kernel-sys/src/lib.rs:17-38`）。
- `kernel_sys::prog_get_fd_by_id(id)` 已用 libbpf helper 打开 live program
  FD（`bpfopt/crates/kernel-sys/src/lib.rs:221-228`）。
- `kernel_sys::obj_get_info_by_fd(fd)` 能取 fork-extended
  `BpfProgInfoFork`（`bpfopt/crates/kernel-sys/src/lib.rs:245-249`）。
- `kernel_sys::prog_load_dryrun(prog_type, insns, log_buf)` 已提供简单
  `BPF_PROG_LOAD` dry-run（`bpfopt/crates/kernel-sys/src/lib.rs:150-205`）。
- `kernel_sys::prog_rejit(prog_fd, new_insns, fd_array, log_buf)` 已把
  `fd_array` 和可选 verifier log buffer 传给 `BPF_PROG_REJIT`
  （`bpfopt/crates/kernel-sys/src/lib.rs:295-320`）。

## Answers to investigation questions

### 1. `prog_id -> prog_fd`

Use `kernel_sys::prog_get_fd_by_id(prog_id)`.

Failure handling:

- nonexistent program: libbpf returns a negative fd; surface as
  `BPF_PROG_GET_FD_BY_ID: ...` on stderr, exit 1.
- permission/capability error: same path, no special handling. The CLI should
  add context like `open BPF program id 123` but preserve the kernel/libbpf
  error.
- keep the returned `OwnedFd` alive for the full dry-run or REJIT call.

The daemon uses the same shape today: `try_apply_one()` opens the program with
`bpf::bpf_prog_get_fd_by_id(prog_id)` before reading info and applying ReJIT
(`daemon/src/commands.rs:501-504`).

### 2. stdin/file bytecode reading

v3 defines the pipeline bytecode as a headerless raw `struct bpf_insn[]`, each
instruction exactly 8 bytes, little-endian fields, and file size must be an
8-byte multiple (`docs/tmp/bpfopt_design_v3.md:247-261`).

CLI mode selection:

- positional `FILE` present: read all bytes from that file.
- positional `FILE` absent: read all bytes from stdin.
- stdout is never used by `bpfrejit`.

Validation:

- reject empty input as a CLI input error: no zero-instruction BPF program is a
  meaningful ReJIT payload.
- reject `bytes.len() % 8 != 0` before any syscall.
- parse each 8-byte chunk into `kernel_sys::bpf_insn` using
  `code = chunk[0]`, `dst_reg = chunk[1] & 0x0f`, `src_reg = chunk[1] >> 4`,
  `off = i16::from_le_bytes(chunk[2..4])`, `imm =
  i32::from_le_bytes(chunk[4..8])`.

Do not depend on `bpfopt::insn::BpfInsn` for this parser: `bpfrejit` should only
use `kernel-sys` UAPI types to keep the no-cross-dependency rule. The daemon
has an equivalent raw parser for its internal `BpfInsn` that checks the
8-byte multiple and decodes little-endian fields
(`daemon/src/bpf.rs:541-564`).

### 3. `--fd-array FILE`

Current daemon behavior:

- `CALL.off` is the 1-based slot in the REJIT/load `fd_array`; `0` means
  vmlinux BTF (`daemon/src/pipeline.rs:16-17`,
  `bpfopt/crates/bpfopt/src/insn.rs:247-255`).
- The daemon resolver maps kinsn target name to a live BTF raw fd and records
  the required fds in dense slot order (`daemon/src/pipeline.rs:19-84`).
- Before verifier dry-run and final ReJIT, the daemon calls
  `build_rejit_fd_array(required_btf_fds)` (`daemon/src/commands.rs:621-633`,
  `daemon/src/commands.rs:823-827`).
- `build_rejit_fd_array()` duplicates the first valid BTF fd into slot 0, then
  appends the real 1-based slots. This is needed because the kernel pre-scan
  wants every populated slot to be a valid map or BTF fd
  (`daemon/src/commands.rs:386-397`).
- The daemon opens proper BPF subsystem BTF FDs, not plain
  `/sys/kernel/btf/<module>` file descriptors
  (`daemon/src/kfunc_discovery.rs:386-399`). It keeps `OwnedFd`s alive for the
  daemon lifetime because closing them invalidates the raw fd numbers
  (`daemon/src/kfunc_discovery.rs:299-307`).

Implication for CLI JSON:

Raw `{"btf_fd": 3}` entries are not a good durable file format. FD numbers are
process-local. They only work if the caller intentionally execs `bpfrejit` with
those fds inherited and the JSON refers to inherited raw fd numbers. That is a
special mode, not the default pipeline contract.

Recommended default JSON contract:

```json
[
  { "slot": 1, "name": "bpf_rotate64", "btf_module": "bpf_rotate" },
  { "slot": 2, "name": "bpf_select64", "btf_module": "bpf_select" }
]
```

Rules:

- `slot` is the exact `CALL.off` value already encoded in the input bytecode.
- slots must be dense starting at 1; reject holes because the kernel expects
  valid populated slots.
- `name` is diagnostic only.
- `btf_module` lets `bpfrejit` open a fresh BPF BTF fd in its own process.
- Hold all opened `OwnedFd`s until after dry-run/ReJIT.
- Construct the syscall slice as `[fd_for_slot_1, fd_for_slot_1, fd_for_slot_2,
  ...]`, matching daemon slot-0 reservation.

Alternative if a future `bpfget --target` records BTF object IDs:

```json
[
  { "slot": 1, "name": "bpf_rotate64", "btf_obj_id": 42 }
]
```

Then `bpfrejit` can call `kernel_sys::libbpf_sys::bpf_btf_get_fd_by_id()` and
wrap the returned fd in `OwnedFd`. `kernel-sys` currently does not expose a
safe helper for opening BTF by module name; the migration should move the
daemon helper equivalent into `kernel-sys` rather than putting raw BPF syscalls
in `bpfrejit`.

If no `--fd-array` is provided and the bytecode contains kinsn calls with
nonzero `CALL.off`, the kernel verifier should reject naturally and its log
should be printed. The CLI should not scan bytecode to skip such programs.

### 4. `--dry-run`

v3 §2.5 explicitly lists `bpfrejit 123 opt.bin --dry-run`
(`docs/tmp/bpfopt_design_v3.md:190-210`), so the CLI should implement it.

Recommended implementation:

1. Open `prog_fd` with `kernel_sys::prog_get_fd_by_id`.
2. Read current metadata with `kernel_sys::obj_get_info_by_fd`.
3. Read and parse input bytecode.
4. Build `fd_array` if requested.
5. Call a `kernel-sys` dry-run helper with live program metadata and the
   optional `fd_array`.
6. Do not call `kernel_sys::prog_rejit`.
7. On success, exit 0 and print a dry-run summary to stderr.

This keeps `bpfrejit` independent of `bpfverify` while preserving v3 behavior.
It is a simple wrapper, not a full verifier pipeline. The current
`kernel_sys::prog_load_dryrun` takes only `prog_type`, instructions and
log buffer; it does not yet accept `expected_attach_type`, attach metadata,
map fd bindings, BTF func/line info, or `fd_array`
(`bpfopt/crates/kernel-sys/src/lib.rs:155-159`). Therefore a v3-complete
`--dry-run` needs a small `kernel-sys` extension for `BPF_PROG_LOAD` options.
Until that exists, the existing helper is only an MVP for programs that do not
need those side inputs. Do not hide this by ignoring `--fd-array` in dry-run
mode.

The fork `BPF_PROG_REJIT` wrapper has a `flags` field in its attr in daemon code
(`daemon/src/bpf.rs:1610-1632`), but current user-space wrappers pass `flags = 0`
and there is no known "verify but do not commit" flag exposed in `kernel-sys`.
Do not fake dry-run by calling `prog_rejit`.

### 5. Error handling

All errors go to stderr and exit 1.

- Program open failure: `open BPF program id 123: BPF_PROG_GET_FD_BY_ID: ...`
- Bytecode length error: `input bytecode length 17 is not a multiple of 8`
- Empty bytecode: `input bytecode is empty`
- fd_array JSON parse/open failure: include file path and slot/name context.
- `BPF_PROG_LOAD` dry-run verifier rejection: print the `prog_load_dryrun`
  error, including `verifier log:` when present.
- `BPF_PROG_REJIT` verifier rejection or kernel race: print the
  `prog_rejit` error. `kernel_sys::prog_rejit` already includes verifier log
  summary when a log buffer is provided and the kernel fills it
  (`bpfopt/crates/kernel-sys/src/lib.rs:306-320`).

For normal ReJIT, call `prog_rejit(..., Some(&mut log_buf))` directly. This is
slower than daemon's fast-path-then-log retry, but it guarantees verifier log
visibility in the CLI path. If performance becomes important, move daemon's
retry policy into `kernel-sys` as a reusable helper.

### 6. Summary output

On success, do not write stdout. Print summary to stderr.

Recommended stderr line:

```json
{"status":"ok","prog_id":123,"insn_count_before":96,"insn_count_after":88,"dry_run":false}
```

For `--dry-run`, use `status: "dry_run_ok"` and `dry_run: true`.

`insn_count_after` is the parsed input instruction count. `insn_count_before`
should come from `obj_get_info_by_fd` before the syscall: prefer
`orig_prog_len / size_of::<bpf_insn>()` when nonzero, otherwise fall back to
`xlated_prog_len / size_of::<bpf_insn>()`. This mirrors daemon reporting, where
the result carries original and final instruction counts
(`daemon/src/commands.rs:535-541`).

`--output FILE` is optional. If implemented, write the same JSON summary to the
file and still keep stdout empty. Stderr may either print the same JSON or a
single human-readable success line; JSON on stderr is simpler for benchmark
logs.

### 7. CLI arguments

Recommended clap shape:

```text
bpfrejit [OPTIONS] <PROG_ID> [FILE]

Arguments:
  <PROG_ID>    live BPF program ID
  [FILE]       raw struct bpf_insn[] input; stdin when omitted

Options:
  --fd-array <FILE>   kinsn fd_array manifest
  --dry-run           verify only; do not call BPF_PROG_REJIT
  --output <FILE>     optional summary JSON output
```

`PROG_ID` is required. `FILE` is optional positional. More than one positional
file should be rejected by clap.

### 8. Cargo dependencies

`crates/bpfrejit/Cargo.toml` should use only:

- `kernel-sys`
- `clap`
- `serde`
- `serde_json`
- `anyhow`

No dependency on `bpfopt`, `bpfverify`, or `bpfrejit-daemon`. Runtime
composition remains shell/stdin/stdout/stderr, matching v3's no CLI
cross-dependency rule (`docs/tmp/bpfopt_design_v3.md:550-567`).

### 9. Tests

Unit tests with clear bug-detection purpose:

- clap parsing: `PROG_ID` required, optional `FILE`, `--fd-array`, `--dry-run`,
  `--output`.
- bytecode parser rejects empty input.
- bytecode parser rejects non-8-byte length.
- bytecode parser decodes dst/src nibble and little-endian `off`/`imm`
  correctly. This catches ABI/serialization mistakes.
- fd_array manifest rejects slot 0, holes, duplicate slots, and missing
  openable descriptor fields.
- fd_array builder duplicates slot 1 into syscall index 0, matching daemon
  behavior. Existing daemon test already guards this pattern
  (`daemon/src/commands_tests.rs:42-47`).

Integration tests:

- require fork kernel with `BPF_PROG_REJIT` and a real live BPF program.
- skip on hosts where `kernel_sys::prog_get_fd_by_id`, `prog_load_dryrun`, or
  `prog_rejit` return unsupported/permission errors.
- cover `bpfrejit PROG_ID FILE`, stdin mode, verifier rejection, and dry-run not
  mutating the program.

## Proposed `main.rs` structure

```rust
#[derive(Parser)]
struct Cli {
    prog_id: u32,
    file: Option<PathBuf>,
    #[arg(long)]
    fd_array: Option<PathBuf>,
    #[arg(long)]
    dry_run: bool,
    #[arg(long)]
    output: Option<PathBuf>,
}

fn main() -> anyhow::Result<()> {
    let cli = Cli::parse();
    let prog_fd = kernel_sys::prog_get_fd_by_id(cli.prog_id)
        .with_context(|| format!("open BPF program id {}", cli.prog_id))?;
    let before = kernel_sys::obj_get_info_by_fd(prog_fd.as_fd())?;
    let insns = read_insns(cli.file.as_deref())?;
    let fd_array = load_fd_array(cli.fd_array.as_deref())?;

    if cli.dry_run {
        let mut log = vec![0u8; 16 * 1024 * 1024];
        // Final v3 implementation should pass fd_array and live-program load
        // metadata through a richer kernel-sys dry-run API.
        kernel_sys::prog_load_dryrun(before.prog_type as _, &insns, Some(&mut log))?;
        emit_summary("dry_run_ok", cli.prog_id, &before, insns.len(), true, cli.output)?;
        return Ok(());
    }

    let mut log = vec![0u8; 16 * 1024 * 1024];
    kernel_sys::prog_rejit(prog_fd.as_fd(), &insns, &fd_array.raw_fds, Some(&mut log))?;
    emit_summary("ok", cli.prog_id, &before, insns.len(), false, cli.output)?;
    Ok(())
}
```

Keep `load_fd_array()` returning both `Vec<OwnedFd>` guards and `Vec<i32>`
raw fds so the actual descriptors remain open while the syscall runs.

Do not put pass execution, profiling, verifier-state parsing, daemon socket
client logic, or pipeline orchestration in this CLI.

## Migration steps

1. Add `crates/bpfrejit` to `bpfopt/Cargo.toml` workspace members.
2. Add `crates/bpfrejit/Cargo.toml` with the dependencies listed above.
3. Implement local raw-bytecode parser using `kernel_sys::bpf_insn`, not
   `bpfopt::insn::BpfInsn`.
4. Implement `prog_id -> prog_fd`, metadata read, summary generation, and
   normal `prog_rejit` path.
5. Implement `--dry-run` through `kernel_sys::prog_load_dryrun`.
6. Move or recreate BTF object open helpers in `kernel-sys` if the chosen
   `--fd-array` manifest uses `btf_module` or `btf_obj_id`.
7. Implement `--fd-array` manifest parsing and dense-slot fd array construction.
8. Add focused unit tests; add integration tests that skip without fork kernel
   support.
9. Update runner scripts to call `bpfrejit` directly only after `bpfget` /
   `bpfopt` produce compatible side inputs.

## Comparison with current daemon

The daemon currently does more than `bpfrejit` should:

- opens program by ID, reads metadata and original bytecode
  (`daemon/src/commands.rs:501-504`);
- runs pass pipeline and per-pass verifier dry-runs
  (`daemon/src/commands.rs:586-634`);
- tracks kinsn BTF fds and builds the REJIT `fd_array`
  (`daemon/src/pipeline.rs:16-84`, `daemon/src/commands.rs:386-397`);
- relocates map FDs before final ReJIT (`daemon/src/commands.rs:811-817`);
- calls `bpf_prog_rejit` and records structured daemon result JSON
  (`daemon/src/commands.rs:823-827`).

The CLI should only keep the pieces necessary for v3 §2.5: open prog, read raw
bytecode, optionally open BTF descriptors for `fd_array`, dry-run or ReJIT, and
print a summary. Pipeline execution, pass rollback, profiling, map invalidation,
and daemon watch behavior belong outside `bpfrejit`.

One migration gap is map FD relocation. The daemon patches map FDs before final
ReJIT. The v3 CLI contract for `bpfrejit` does not currently define a
`--map-fds` input. Either `bpfget` must emit bytecode already suitable for the
current CLI process, or a future side-input contract must handle map fd
relocation without making `bpfrejit` depend on `bpfopt` or the daemon.
