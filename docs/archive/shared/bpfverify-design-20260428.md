# bpfverify CLI implementation design notes (2026-04-28)

This report investigates the current implementation surface for a future `bpfverify`
CLI. It is read-only research plus design notes; no implementation code is changed.

## Scope and source map

- Authoritative v3 behavior: `docs/tmp/bpfopt_design_v3.md:102-137` defines `bpfverify`, pipe-through behavior, `--report`, `--verifier-states-out`, and required/optional flags.
- Verifier states schema: `docs/tmp/bpfopt_design_v3.md:337-363`.
- Current parser: `bpfopt/crates/bpfopt/src/verifier_log.rs`.
- Current shared kernel wrapper: `bpfopt/crates/kernel-sys/src/lib.rs`.
- Current daemon verifier/fd-array implementation: `daemon/src/commands.rs`, `daemon/src/pipeline.rs`, `daemon/src/bpf.rs`.
- Current override for libbpf use and syscall boundary: `CLAUDE.md:49-62`.
- There is currently no tracked `bpfverify` crate. The workspace only lists `crates/bpfopt` and `crates/kernel-sys` in `bpfopt/Cargo.toml:1-5`.

## 1. Current `bpfopt::verifier_log` parsing logic

Answer:

- Function signature: `pub fn parse_verifier_log(log: &str) -> Vec<VerifierInsn>` in `bpfopt/crates/bpfopt/src/verifier_log.rs:112-114`.
- Input format: raw kernel verifier log text captured with `log_level=2`. The module comment says it parses state snapshot forms:
  - `from <prev> to <pc>: R0=... R1=...`
  - `<pc>: R0=... R1=...`
  - `<pc>: (..insn..) ... ; R0=... R1=...`
  Source: `bpfopt/crates/bpfopt/src/verifier_log.rs:2-10`.
- Output type: `Vec<VerifierInsn>`. `VerifierInsn` carries `pc`, `frame`, `from_pc`, `kind`, `speculative`, `regs`, and `stack` (`bpfopt/crates/bpfopt/src/verifier_log.rs:49-58`). Register state carries type, width, exact scalar value, tnum, signed/unsigned ranges, offset, and id (`bpfopt/crates/bpfopt/src/verifier_log.rs:60-70`).
- Parsing mechanics: `parse_verifier_log()` line-splits and `filter_map`s `parse_state_line`; `parse_state_line()` recognizes edge/full/delta state lines, strips `frameN:`, tokenizes top-level state text, then parses `R*=` and `fp-*=` tokens (`bpfopt/crates/bpfopt/src/verifier_log.rs:112-229`).
- The parser also has `extract_failure_pc(verifier_log: &str) -> Option<usize>` for REJIT failure attribution (`bpfopt/crates/bpfopt/src/verifier_log.rs:116-171`).
- Current consumers:
  - `BpfProgram` stores `verifier_states: Arc<[VerifierInsn]>` and test-only `set_verifier_log()` calls `parse_verifier_log()` (`bpfopt/crates/bpfopt/src/pass.rs:65-67`, `bpfopt/crates/bpfopt/src/pass.rs:335-343`).
  - `ConstPropPass` imports `VerifierInsn`/`VerifierInsnKind` and only uses `InsnDeltaState` observations (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:9`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:128-145`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:198-199`).
  - `MapInlinePass` also imports `VerifierInsn` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:11`).

Design conclusion:

- Raw verifier-log parsing belongs in `bpfverify` for task #48.
- `bpfopt` should stop accepting raw kernel verifier logs and should consume plain `verifier-states.json` side input matching v3 section 3.5.
- Moving the parser file verbatim is feasible, but its data types should either become private to `bpfverify` plus a converter into the v3 JSON schema, or be split so only JSON DTOs remain in `bpfopt`.

## 2. `bpfverify` pipe mode implementation

Answer:

Required behavior from v3:

- Pipe mode passes verified bytecode through unchanged and fails with verifier log on stderr (`docs/tmp/bpfopt_design_v3.md:106-121`).
- stdin/stdout are raw `struct bpf_insn[]`, 8 bytes per instruction, no header/framing (`docs/tmp/bpfopt_design_v3.md:88-93`).

Current implementation surface:

- `kernel_sys::prog_load_dryrun()` exists with signature:

```rust
pub fn prog_load_dryrun(
    prog_type: bpf_prog_type,
    insns: &[bpf_insn],
    mut log_buf: Option<&mut [u8]>,
) -> Result<()>
```

Source: `bpfopt/crates/kernel-sys/src/lib.rs:150-205`.

- It uses `libbpf_sys::bpf_prog_load`, sets `attempts = 1`, and closes the returned fd immediately on success (`bpfopt/crates/kernel-sys/src/lib.rs:164-185`, `bpfopt/crates/kernel-sys/src/lib.rs:203-204`).
- If `log_buf` is present, it sets `opts.log_level = 2`, `log_size`, and `log_buf` (`bpfopt/crates/kernel-sys/src/lib.rs:168-175`). It cannot currently request log level 1.
- If load fails and a log was captured, the error includes `BPF_PROG_LOAD dry-run: ... verifier log:\n...` (`bpfopt/crates/kernel-sys/src/lib.rs:188-200`).

Recommended pipe algorithm:

1. Read `--input FILE` or stdin into `Vec<u8>`.
2. Reject bytecode whose length is not a multiple of `size_of::<kernel_sys::bpf_insn>()`; for current BPF ABI this is 8 bytes, matching v3 (`docs/tmp/bpfopt_design_v3.md:88-90`).
3. Convert bytes to `Vec<kernel_sys::bpf_insn>` without changing the original byte vector.
4. Parse `--prog-type TYPE` into `kernel_sys::bpf_prog_type`.
5. Allocate verifier log buffer. Default recommendation: 64 KiB minimum, with `--log-buf-size` as an internal/advanced option if added later. 64 KiB is enough for basic error logs and avoids the daemon's 16 MiB default in normal pipe mode.
6. Call a future `kernel_sys::prog_load_dryrun_opts()` with:
   - `prog_type`
   - `expected_attach_type`
   - `insns`
   - optional map relocation / fd array context
   - `log_level = max(cli_log_level.unwrap_or(1), 2 if --verifier-states-out else 1)`
   - log buffer
7. On pass, write the original input bytes to `--output FILE` or stdout and exit 0.
8. On fail, write the complete verifier log to stderr, do not write stdout/output bytecode, and exit 1.

Important gap:

- Current `kernel_sys::prog_load_dryrun()` is enough for a minimal `prog_type + raw insns + log_level=2` prototype, but not enough for the requested production CLI because it lacks explicit log-level, expected attach type, map FD relocation, fd_array, and typed return/error metadata.

## 3. `--report FILE` mode

Answer:

Recommended JSON payload:

```json
{
  "status": "pass",
  "verifier_log": "...",
  "insn_count": 12,
  "jited_size": null
}
```

Fields:

- `status`: `"pass"` or `"fail"`.
- `verifier_log`: raw verifier log string. Empty is allowed on pass when the chosen log level emits no log.
- `insn_count`: decoded instruction count.
- `jited_size`: optional. Current `kernel_sys::prog_load_dryrun()` returns `()`, so it cannot report JIT size. To populate this, the wrapper would need to query `BPF_OBJ_GET_INFO_BY_FD` before closing the successful load fd.
- Optional useful fields that are still factual rather than informational-only: `errno`, `log_level`, `log_truncated` or `log_true_size`. Avoid `limitations`, `workload_miss`, or similar metadata-only fields per repository instructions.

Exit status recommendation:

- Pure pipe mode fail: exit 1, stderr contains verifier log.
- `--report FILE` analysis mode fail: exit 0 after writing the report. Rationale: report mode is for analyzing pass/fail and failure cause; a failed verifier result is successful report generation.
- If report file cannot be written or input/flags are malformed: exit 1.

Conformance note:

- v3 says `--report FILE` emits structured JSON but does not specify fail exit status (`docs/tmp/bpfopt_design_v3.md:117-121`). The exit-0-on-verifier-fail behavior is a recommended policy, not already specified by v3.

## 4. `--verifier-states-out FILE` mode

Answer:

- This mode must force verifier log level 2 because current parser expects the state snapshots produced by verbose verifier logs (`bpfopt/crates/bpfopt/src/verifier_log.rs:2-10`).
- The flow is:
  1. Run dry-run load with `log_level = 2`.
  2. Parse raw log with the moved `parse_verifier_log(log: &str) -> Vec<VerifierInsn>`.
  3. Convert parser output into v3 schema JSON:

```json
{
  "insns": [
    {
      "pc": 5,
      "regs": {
        "r1": { "type": "scalar", "const_val": 42 },
        "r2": { "type": "scalar", "min": 0, "max": 255, "tnum": "0x0/0xff" }
      }
    }
  ]
}
```

Source schema: `docs/tmp/bpfopt_design_v3.md:337-363`.

Conversion rules:

- Prefer `VerifierInsnKind::InsnDeltaState` entries for const-prop, matching current `ConstPropPass` behavior (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:132-145`).
- Include only registers with exact scalar values, ranges, or tnums, as v3 requires only PCs with exact constant or range data (`docs/tmp/bpfopt_design_v3.md:361-363`).
- Map register keys from numeric `u8` to `"r0"` ... `"r10"`.
- `const_val` comes from `RegState::exact_u64()` or `exact_u32()` (`bpfopt/crates/bpfopt/src/verifier_log.rs:86-103`).
- `min`/`max` should use signed or unsigned range fields consistently. For v3's compact schema, prefer unsigned `umin`/`umax` when present; otherwise use signed `smin`/`smax`.
- `tnum` should be serialized as `"0xVALUE/0xMASK"` from `Tnum { value, mask }` (`bpfopt/crates/bpfopt/src/verifier_log.rs:31-35`, `bpfopt/crates/bpfopt/src/verifier_log.rs:704-712`).

Migration conclusion:

- Move the raw-log parser module from `bpfopt/crates/bpfopt/src/verifier_log.rs` to `bpfverify/src/verifier_log.rs`.
- Keep the current parser tests with the moved module; they cover real branch/delta state forms, exact constants, speculative state, truncated logs, non-state lines, and failure PC extraction (`bpfopt/crates/bpfopt/src/verifier_log.rs:714-1007`).
- `bpfopt` should read the v3 JSON file directly through serde, not call `parse_verifier_log()`.

## 5. `--map-fds FILE` and `--fd-array FILE`

Answer:

`--map-fds FILE`:

- v3 says `bpfget --full --outdir` produces `prog.bin`, `prog_info.json`, and `map_fds.json` (`docs/tmp/bpfopt_design_v3.md:174-188`).
- For BPF program load, map references in bytecode are normally `BPF_LD_IMM64` pseudo-map instructions. The daemon's current helper scans for `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE`, resolves old FD values to map IDs, opens fresh map FDs, and patches instruction immediates (`daemon/src/bpf.rs:1300-1393`).
- Therefore, `--map-fds` should not be implemented as `attach_btf_obj_fd`. `attach_btf_obj_fd` is attach-target BTF context (`daemon/src/bpf.rs:363-368`, `daemon/src/bpf.rs:1548-1552`), not ordinary map binding.
- Recommended design: `map_fds.json` should carry stable map IDs and old-FD-to-map-ID bindings. `bpfverify` reopens map IDs in its own process through `kernel-sys::map_get_fd_by_id()` (`bpfopt/crates/kernel-sys/src/lib.rs:266-273`) and patches pseudo-map immediates before `BPF_PROG_LOAD`.

`--fd-array FILE`:

- UAPI has `fd_array` and `fd_array_cnt` in `BPF_PROG_LOAD` (`vendor/libbpf/include/uapi/linux/bpf.h:1617-1639`).
- libbpf exposes the same in `bpf_prog_load_opts`: `fd_array` and `fd_array_cnt` (`vendor/libbpf/src/bpf.h:90-115`), and copies them into `attr.fd_array` / `attr.fd_array_cnt` (`vendor/libbpf/src/bpf.c:315-316`).
- Current daemon supports fd_array for BPF_PROG_LOAD in its custom `AttrProgLoad` path (`daemon/src/bpf.rs:1513-1557`) and passes fd_array during per-pass verify (`daemon/src/commands.rs:621-634`).
- Current pipeline resolver stores required BTF FDs and encodes `CALL.off` as a 1-based fd_array slot (`daemon/src/pipeline.rs:16-18`, `daemon/src/pipeline.rs:63-74`, `daemon/src/pipeline.rs:77-87`).
- `commands.rs` reserves slot 0 with a duplicate valid BTF FD because kinsn `CALL.off` uses 0 for vmlinux and 1-based slots for descriptor BTFs (`daemon/src/commands.rs:386-398`).

Kernel-sys gap:

- `kernel_sys::prog_load_dryrun()` currently has no `fd_array` parameter and does not set `opts.fd_array` or `opts.fd_array_cnt` (`bpfopt/crates/kernel-sys/src/lib.rs:155-175`).
- Commit `588da3644c7eaf822ced83df78feab18a06e9cb7` added verify-log/map APIs and `prog_rejit(..., fd_array, log_buf)` support, but it did not add fd_array support to `prog_load_dryrun`. The changed files were `bpfopt/crates/kernel-sys/src/lib.rs` and `bpfopt/crates/kernel-sys/tests/prog_get_original.rs`; commit date was 2026-04-28 20:33:49 -0700.
- `prog_rejit()` does accept `fd_array: &[i32]` and optional log buffer (`bpfopt/crates/kernel-sys/src/lib.rs:295-336`).

## 6. Error handling

Answer:

Required CLI behavior:

- Unknown prog type:
  - exit 1
  - stderr: `unknown prog type 'foo'`
  - Do not call the kernel.
- Bytecode length not aligned:
  - exit 1
  - stderr: `bytecode size not aligned to 8`
  - This follows v3's raw `struct bpf_insn[]` convention (`docs/tmp/bpfopt_design_v3.md:88-90`).
- Kernel rejection:
  - pipe mode: exit 1
  - stderr: complete verifier log if available; otherwise kernel error headline.
  - stdout/output bytecode should not be written on failure.
- `--map-fds` / `--fd-array` JSON format error:
  - exit 1
  - stderr should include the path and serde error.
- `--report FILE` write failure:
  - exit 1
  - stderr should include the path and I/O error.
- `--verifier-states-out FILE` parse failure:
  - if verifier rejected the program, still write any `--report`; pipe mode exits 1.
  - if verifier passed but log level 2 returned a non-empty unparsable log, fail the states side-output with exit 1, because the requested artifact cannot be produced.

Current daemon precedent:

- `parse_verifier_states_from_log()` treats a non-empty verifier log with no parseable states as an error (`daemon/src/commands.rs:419-431`).
- Per-pass verify degrades verifier-state refresh to a warning only inside the daemon's optimization loop (`daemon/src/commands.rs:636-665`). For CLI `--verifier-states-out`, the artifact is explicit, so failing is better.

## 7. CLI argument list

Answer:

Required:

- `--prog-type TYPE`
  - Required unless a future input metadata wrapper exists. v3 has no such stdin metadata (`docs/tmp/bpfopt_design_v3.md:123-128`).
  - String parser should accept at least v3 examples: `xdp`, `socket_filter`, `kprobe`.
  - There is currently no CLI string parser. `bpfopt` only has an ELF section-name inference helper for tests/ELF parsing (`bpfopt/crates/bpfopt/src/elf_parser.rs:23-40`, `bpfopt/crates/bpfopt/src/elf_parser.rs:1052-1120`).

Optional:

- `--expected-attach-type TYPE`
  - Required for some program types; UAPI notes expected attach type can affect context access and allowed helpers (`vendor/libbpf/include/uapi/linux/bpf.h:1597-1603`).
- `--input FILE`
  - Default stdin.
- `--output FILE`
  - Default stdout in pipe mode.
- `--report FILE`
  - Writes pass/fail report JSON.
- `--verifier-states-out FILE`
  - Forces log level 2 and writes v3 schema.
- `--map-fds FILE`
  - Stable map binding side input from `bpfget --full`.
- `--fd-array FILE`
  - kinsn BTF fd_array side input.
- `--log-level N`
  - Recommended accepted values: 0, 1, 2.
  - This task requests default 1 for basic error logs and forced 2 when `--verifier-states-out` is present.
  - v3 currently says default 0 (`docs/tmp/bpfopt_design_v3.md:131-137`), so default 1 is a task-level override that should be called out in implementation notes without editing v3 in this task.

Optional implementation helper:

- `--log-buf-size BYTES`
  - Not required by v3, but useful for debugging. Default should be at least 64 KiB. The daemon uses much larger buffers for per-pass state capture: 16 MiB initial and 64 MiB max (`daemon/src/bpf.rs:1559-1593`).

## 8. `bpfverify` must not depend on `bpfopt`

Answer:

- The no-cross-dependencies rule forbids compile-time dependencies between the six CLI binary crates and says shared code belongs in library crates, not in another CLI crate's lib portion (`CLAUDE.md:42-47`).
- `bpfverify` should depend directly on `kernel-sys` for kernel calls and BPF UAPI types, not on `bpfopt`.
- Current `bpfopt` is both library and CLI crate, exports `pub mod verifier_log`, and is workspace-internal/pure bytecode (`bpfopt/crates/bpfopt/src/lib.rs:1-7`, `bpfopt/crates/bpfopt/src/lib.rs:22`). Letting `bpfverify` depend on it would violate the CLI-cross-dependency constraint.
- After moving the raw-log parser to `bpfverify`, `bpfopt` const-prop should consume v3 `verifier-states.json` through serde. It should not call `parse_verifier_log()` or parse raw kernel logs.
- Because current const-prop consumes `VerifierInsn` and filters `InsnDeltaState` (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:128-145`), implementation work must introduce a local JSON-side data model in `bpfopt` or convert the v3 JSON schema to the const-prop oracle without depending on `bpfverify`.

## 9. Dependency list

Answer:

Recommended `bpfverify/Cargo.toml` dependencies:

```toml
[dependencies]
anyhow.workspace = true
clap.workspace = true
serde.workspace = true
serde_json.workspace = true
kernel-sys = { path = "../kernel-sys" }
```

Do not add direct dependencies on:

- `bpfopt`
- `libbpf-rs`
- `libbpf-sys`
- `libc`

Rationale and references:

- `kernel-sys` already depends on `libbpf-rs`, `libbpf-sys`, and `libc` (`bpfopt/crates/kernel-sys/Cargo.toml:7-11`).
- The root workspace already has `anyhow`, `clap`, `serde`, and `serde_json` workspace dependencies (`bpfopt/Cargo.toml:8-16`).
- `kernel-sys` re-exports `libbpf_sys`, `ProgramType`, and all `libbpf_sys::*` symbols, including `bpf_insn` and program type constants (`bpfopt/crates/kernel-sys/src/lib.rs:12-15`).
- Repository rules say standard BPF commands should go through libbpf-rs/libbpf-sys inside `kernel-sys`, and all other CLI crates must call BPF syscalls only through `kernel-sys` (`CLAUDE.md:49-62`).

## 10. Test strategy

Answer:

Unit tests:

- Move current parser tests with `verifier_log.rs`. They detect real bugs:
  - branch/full/delta state parsing (`bpfopt/crates/bpfopt/src/verifier_log.rs:718-775`)
  - exact constants and bounds (`bpfopt/crates/bpfopt/src/verifier_log.rs:777-803`)
  - speculative frame/stack spill parsing (`bpfopt/crates/bpfopt/src/verifier_log.rs:805-837`)
  - 32-bit vs 64-bit exact scalar handling (`bpfopt/crates/bpfopt/src/verifier_log.rs:839-858`)
  - truncated logs preserving complete states (`bpfopt/crates/bpfopt/src/verifier_log.rs:860-875`)
  - ignoring non-state lines (`bpfopt/crates/bpfopt/src/verifier_log.rs:877-887`)
  - failure PC heuristics (`bpfopt/crates/bpfopt/src/verifier_log.rs:947-1006`)
- Add JSON conversion tests for v3 schema: exact value, range, tnum, and filtering out regs without const/range/tnum.
- Add CLI parser unit tests for prog type strings and attach type strings.

Integration tests:

- Passing program:
  - Simple XDP bytecode: `r0 = 0; exit`.
  - Run `bpfverify --prog-type xdp --input pass.bin --output out.bin`.
  - Assert exit 0 and `out.bin == pass.bin`.
- Failing program:
  - Example: jump out of range, then exit.
  - Run `bpfverify --prog-type xdp --input bad.bin`.
  - Assert exit 1 and stderr contains verifier rejection text.
- Report mode:
  - On bad program with `--report report.json`, assert exit 0, report status `"fail"`, non-empty `verifier_log`, and correct `insn_count`.
- States mode:
  - On pass program with `--verifier-states-out states.json`, assert schema has top-level `insns`.
  - Use a slightly richer program than `r0=0; exit` if the verifier log for the minimal program does not emit useful delta state.
- Environment skip:
  - These tests require a kernel that permits BPF_PROG_LOAD for the current user and has the project/fork features needed by optional fd_array cases.
  - Skip on `EPERM`, `EACCES`, missing BPF syscall, or missing fork kernel. Do not treat permission failure as a product failure in generic CI.

## `main.rs` rough structure

```rust
use anyhow::{Context, Result};
use clap::Parser;
use serde::Serialize;
use std::io::{Read, Write};

#[derive(Parser)]
struct Cli {
    #[arg(long)]
    prog_type: String,
    #[arg(long)]
    expected_attach_type: Option<String>,
    #[arg(long)]
    input: Option<std::path::PathBuf>,
    #[arg(long)]
    output: Option<std::path::PathBuf>,
    #[arg(long)]
    report: Option<std::path::PathBuf>,
    #[arg(long)]
    verifier_states_out: Option<std::path::PathBuf>,
    #[arg(long)]
    map_fds: Option<std::path::PathBuf>,
    #[arg(long)]
    fd_array: Option<std::path::PathBuf>,
    #[arg(long, default_value_t = 1)]
    log_level: u32,
}

#[derive(Serialize)]
struct VerifyReport {
    status: &'static str,
    verifier_log: String,
    insn_count: usize,
    #[serde(skip_serializing_if = "Option::is_none")]
    jited_size: Option<u32>,
}

fn main() {
    if let Err(err) = run() {
        eprintln!("{err:#}");
        std::process::exit(1);
    }
}

fn run() -> Result<()> {
    let cli = Cli::parse();
    let input_bytes = read_input(cli.input.as_ref())?;
    let mut insns = decode_insns(&input_bytes)?;
    let prog_type = parse_prog_type(&cli.prog_type)?;
    let log_level = if cli.verifier_states_out.is_some() { 2 } else { cli.log_level };

    let map_fd_guard = load_and_apply_map_fds(cli.map_fds.as_ref(), &mut insns)?;
    let fd_array_guard = load_fd_array(cli.fd_array.as_ref())?;

    let verify = run_kernel_verify(prog_type, &insns, log_level, &fd_array_guard)?;

    if let Some(path) = &cli.report {
        write_report(path, &verify)?;
    }
    if let Some(path) = &cli.verifier_states_out {
        let states = verifier_log::parse_verifier_log(&verify.verifier_log);
        write_states(path, states)?;
    }

    match verify.status {
        Status::Pass => write_output(cli.output.as_ref(), &input_bytes),
        Status::Fail if cli.report.is_some() => Ok(()),
        Status::Fail => {
            eprintln!("{}", verify.verifier_log);
            std::process::exit(1);
        }
    }
}
```

Implementation notes:

- The final code should avoid parsing logs out of anyhow strings. Prefer typed `kernel-sys` result/error structs containing `verifier_log`, errno, and optional `log_true_size`.
- The map FD guard must keep reopened map FDs alive until `BPF_PROG_LOAD` returns, matching daemon relocation behavior (`daemon/src/bpf.rs:1306-1316`, `daemon/src/bpf.rs:1359-1393`).
- The fd_array guard must keep BTF/map FDs alive until `BPF_PROG_LOAD` returns.

## Migration steps

1. Add `crates/bpfverify` to the `bpfopt` workspace members.
2. Add `bpfverify/Cargo.toml` with only `clap`, `serde`, `serde_json`, `anyhow`, and `kernel-sys`.
3. Move raw verifier-log parser logic from `bpfopt/crates/bpfopt/src/verifier_log.rs` to `bpfverify/src/verifier_log.rs`.
4. Add v3 schema DTOs and conversion code in `bpfverify` for `--verifier-states-out`.
5. Update `bpfopt` const-prop input path to read v3 `verifier-states.json`, not raw verifier logs. Remove raw-log parsing calls from non-test bpfopt code.
6. Add or extend a typed `kernel-sys::prog_load_dryrun_opts()` with explicit log level, expected attach type, attach target fields if needed, fd_array, and typed success/failure result.
7. Implement `bpfverify/src/main.rs` pipe/report/states behavior.
8. Add parser unit tests, JSON conversion tests, CLI parse tests, and permission-aware integration tests.
9. Keep daemon code unchanged until the CLI path is ready; after task #45, remove daemon's internal pass/verify loop in favor of external scripts.

## Dependency graph

Desired:

```text
bpfverify
  -> kernel-sys
      -> libbpf-rs
      -> libbpf-sys
      -> libc
  -> clap
  -> serde
  -> serde_json
  -> anyhow

bpfopt
  -> serde / serde_json for verifier-states.json
  -> no bpfverify dependency
  -> no raw verifier-log parser

runtime composition
  bpfget | bpfopt pass | bpfverify | bpfrejit
```

Forbidden:

```text
bpfverify -> bpfopt
bpfverify -> libbpf-rs
bpfverify -> libbpf-sys
bpfverify -> libc
```

## v3 conformance check

Conforms:

- Pipe mode binary stdin/stdout: design preserves raw `struct bpf_insn[]` pass-through (`docs/tmp/bpfopt_design_v3.md:88-93`, `docs/tmp/bpfopt_design_v3.md:117-121`).
- `--prog-type TYPE` required: design follows v3 (`docs/tmp/bpfopt_design_v3.md:123-128`).
- `--report FILE`: design writes structured pass/fail + verifier log (`docs/tmp/bpfopt_design_v3.md:117-121`).
- `--verifier-states-out FILE`: design parses log-level-2 verifier state and emits v3 JSON (`docs/tmp/bpfopt_design_v3.md:337-363`).
- `--map-fds` / `--fd-array`: design keeps these as side-input files (`docs/tmp/bpfopt_design_v3.md:129-137`).
- No custom pipe framing: design keeps bytecode on stdin/stdout and side outputs in files (`docs/tmp/bpfopt_design_v3.md:88-93`).

Intentional task-level updates:

- v3 says `--log-level` default is 0 (`docs/tmp/bpfopt_design_v3.md:131-137`), but this task asks for default 1 and forced 2 for `--verifier-states-out`. The report recommends default 1.
- v3 section 6 originally showed `bpfverify` depending on `bpfopt-core` for verifier-log parsing (`docs/tmp/bpfopt_design_v3.md:522-565`). Current no-CLI-cross-dependency rules and task #48 require moving parser ownership into `bpfverify` and making `bpfopt` consume plain JSON instead.
- v3 section 11 excludes direct libbpf linking (`docs/tmp/bpfopt_design_v3.md:764-773`), but repository instructions now supersede that: standard BPF commands should use libbpf-rs/libbpf-sys via `kernel-sys` (`CLAUDE.md:49-62`).

Current implementation gaps:

- No `bpfverify` crate exists in the current workspace (`bpfopt/Cargo.toml:1-5`).
- Current `kernel_sys::prog_load_dryrun()` lacks explicit log level, expected attach type, map relocation, fd_array, and typed verifier-log return (`bpfopt/crates/kernel-sys/src/lib.rs:155-205`).
- Current bpfopt const-prop uses in-memory `VerifierInsn` from raw-log parser (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:9`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:128-145`) instead of v3 JSON.
- Current daemon still owns a richer per-pass BPF_PROG_LOAD verify loop (`daemon/src/commands.rs:587-700`), which v3 wants to move into scripts/CLI composition (`docs/tmp/bpfopt_design_v3.md:438-449`).

## Bottom line

The shortest correct implementation path is:

1. Build `bpfverify` as a kernel-facing CLI using `kernel-sys`.
2. Move raw verifier-log parsing from `bpfopt` into `bpfverify`.
3. Add a typed `kernel-sys` dry-run options API because the current wrapper is too narrow for attach type, fd_array, and log-level semantics.
4. Make `bpfverify --verifier-states-out` the only producer of v3 verifier states JSON.
5. Make `bpfopt` consume that JSON and stop parsing raw verifier logs.
