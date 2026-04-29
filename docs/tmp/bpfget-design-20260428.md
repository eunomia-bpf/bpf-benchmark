# bpfget CLI implementation research

Date: 2026-04-28

Scope: read-only research plus this report. I did not modify code or `docs/tmp/bpfopt_design_v3.md`.

## Executive summary

v3 defines `bpfget` as a flag-style kernel-dependent CLI for dumping raw original BPF bytecode, program metadata, map bindings, live program lists, and target platform JSON. The current daemon already has most of the discovery and metadata pieces, but not as a standalone CLI.

The biggest implementation mismatch is original bytecode retrieval:

- v3 says `BPF_PROG_GET_ORIGINAL`.
- current daemon retrieves original bytecode through fork-extended `struct bpf_prog_info` fields `orig_prog_len` and `orig_prog_insns` using `BPF_OBJ_GET_INFO_BY_FD`.
- current `vendor/linux-framework/include/uapi/linux/bpf.h` has `BPF_PROG_REJIT` but no `BPF_PROG_GET_ORIGINAL` command.
- the local `kernel-sys` crate has a proposed `BPF_PROG_GET_ORIGINAL = 40` wrapper, but the current kernel fork in this repo does not yet implement that command.

Recommendation: implement `bpfget` against `kernel-sys`, use libbpf/libbpf-sys for standard commands, and either add kernel support for `BPF_PROG_GET_ORIGINAL` before enabling that wrapper or keep a temporary `bpf_prog_info.orig_*` fallback until the fork syscall lands.

## 1. Current daemon bytecode read logic

Answer:

There is no function literally named `prog_get_original_bytecode`. The relevant public APIs are:

- `bpf_prog_get_info(fd: RawFd, fetch_orig: bool) -> Result<(BpfProgInfo, Vec<BpfInsn>)>`: fetches `bpf_prog_info` and optionally original instructions.
- `get_orig_insns_by_id(prog_id: u32) -> Result<(BpfProgInfo, Vec<BpfInsn>)>`: opens a program by ID and calls `bpf_prog_get_info(..., true)`.
- private `bpf_prog_get_images(fd, request) -> Result<BpfProgImages>`: common two-pass image fetch helper for original, xlated, and jited images.

The current flow is `BPF_PROG_GET_FD_BY_ID` -> first `BPF_OBJ_GET_INFO_BY_FD` -> allocate `orig_prog_len` bytes -> second `BPF_OBJ_GET_INFO_BY_FD` with `orig_prog_insns` pointing at the buffer -> parse bytes into `BpfInsn`.

Important detail: `orig_prog_len` is byte length, not instruction count. The binary output length must still be a multiple of `sizeof(struct bpf_insn) == 8`.

Current daemon references:

- `daemon/src/bpf.rs:156` defines `BpfProgInfo`, including fork fields `orig_prog_len` and `orig_prog_insns` at `daemon/src/bpf.rs:199`.
- `daemon/src/bpf.rs:491` wraps `BPF_OBJ_GET_INFO_BY_FD` for `BpfProgInfo`.
- `daemon/src/bpf.rs:540` validates instruction bytes are a multiple of 8 and converts them to `BpfInsn`.
- `daemon/src/bpf.rs:565` starts the two-pass image fetch.
- `daemon/src/bpf.rs:579` allocates `orig_bytes` from `info.orig_prog_len`.
- `daemon/src/bpf.rs:595` sets `second_info.orig_prog_len` and `second_info.orig_prog_insns`.
- `daemon/src/bpf.rs:609` performs the second `BPF_OBJ_GET_INFO_BY_FD`.
- `daemon/src/bpf.rs:1202` exposes `bpf_prog_get_info`.
- `daemon/src/bpf.rs:1760` exposes `get_orig_insns_by_id`.
- `daemon/src/commands.rs:503` and `daemon/src/server.rs:122` treat empty original bytecode as an error.

Kernel fork references:

- `vendor/linux-framework/kernel/bpf/syscall.c:3032` stores original load-time instructions in `prog->aux->orig_insns`.
- `vendor/linux-framework/kernel/bpf/syscall.c:3038` stores `orig_prog_len`.
- `vendor/linux-framework/kernel/bpf/syscall.c:5911` zeros original/xlated/JIT lengths for callers without `bpf_capable()`.
- `vendor/linux-framework/kernel/bpf/syscall.c:5944` copies `orig_insns` to user memory through `bpf_prog_info.orig_prog_insns`.
- `vendor/linux-framework/include/uapi/linux/bpf.h:6681` defines fork-extended `struct bpf_prog_info`; `orig_prog_len/orig_prog_insns` are at `vendor/linux-framework/include/uapi/linux/bpf.h:6721`.

Error behavior:

- Program does not exist: `bpf_prog_get_fd_by_id` fails before info fetch; daemon adds context in `get_orig_insns_by_id`.
- Permission lacking: standard syscalls may fail with `EPERM`/`EACCES`; additionally, current kernel info path can succeed but return `orig_prog_len = 0` when `!bpf_capable()`.
- Not fork-supported / no saved original: current daemon sees empty `orig_insns` and reports "missing original bytecode from BPF_PROG_GET_ORIGINAL", even though the actual syscall path is `BPF_OBJ_GET_INFO_BY_FD`.

URLs:

- Kernel syscall docs for `BPF_PROG_GET_NEXT_ID`, `BPF_PROG_GET_FD_BY_ID`, and `BPF_OBJ_GET_INFO_BY_FD`: https://docs.kernel.org/6.8/userspace-api/ebpf/syscall.html
- Current repo permalink for daemon bpf wrapper: https://github.com/eunomia-bpf/bpf-benchmark/blob/9f59ee436fc49aa75ab85e3cf481bc69a2fd7ce4/daemon/src/bpf.rs

## 2. PROG_GET_NEXT_ID enumeration

Answer:

libbpf exposes C wrappers for program/map/BTF/link ID enumeration, and `libbpf-sys` exposes them as unsafe Rust FFI. `libbpf-rs` also has a high-level `query::ProgInfoIter`, but that iterator returns `ProgramInfo` and hides syscall errors by ending/skipping, so it is not ideal for a CLI that must surface permission and enumeration errors naturally.

Use `kernel-sys::prog_get_next_id(start_id) -> Result<Option<u32>>` for bpfget's own list implementation. That wrapper already exists in the local `kernel-sys` crate.

References:

- `vendor/libbpf/src/bpf.h:498` exposes `bpf_prog_get_next_id`.
- `vendor/libbpf/src/bpf.h:511` exposes `bpf_prog_get_fd_by_id`.
- `vendor/libbpf/src/bpf.h:523` exposes `bpf_obj_get_info_by_fd`.
- `vendor/libbpf/src/bpf.h:543` exposes `bpf_prog_get_info_by_fd`.
- `~/.cargo/registry/src/.../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs:7334` exposes `bpf_prog_get_next_id`.
- `~/.cargo/registry/src/.../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs:7389` exposes `bpf_obj_get_info_by_fd`.
- `~/.cargo/registry/src/.../libbpf-rs-0.26.2/src/query.rs:190` defines `ProgInfoIter`.
- `~/.cargo/registry/src/.../libbpf-rs-0.26.2/src/query.rs:435` implements `ProgInfoIter` with `bpf_prog_get_next_id`.
- `bpfopt/crates/kernel-sys/src/lib.rs:156` wraps `bpf_prog_get_next_id` as `prog_get_next_id`.

Enumeration template:

```rust
let mut id = 0u32;
let mut out = Vec::new();

loop {
    let Some(next_id) = kernel_sys::prog_get_next_id(id)? else {
        break;
    };
    id = next_id;

    let fd = kernel_sys::prog_get_fd_by_id(next_id)?;
    let info = kernel_sys::obj_get_info_by_fd(fd.as_fd())?;
    out.push((next_id, info));
}
```

If using raw `libbpf_sys` directly, handle `ENOENT` as end-of-iteration and every other errno as a hard CLI error.

URLs:

- libbpf API source: https://github.com/libbpf/libbpf/blob/v1.7.0/src/bpf.h
- libbpf-rs `ProgInfoIter`: https://docs.rs/libbpf-rs/0.26.2/libbpf_rs/query/struct.ProgInfoIter.html
- libbpf-sys crate docs: https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/

## 3. PROG_GET_INFO_BY_FD metadata

Answer:

For `info.json`, prefer raw `libbpf_sys::bpf_prog_info` plus a fork extension path for `orig_prog_len`. `libbpf-rs::query::ProgramInfo` is convenient for display/listing, but it omits fields that matter to bpfget decisions, notably `attach_btf_obj_id`, `attach_btf_id`, and all fork-only original-bytecode fields.

Current daemon's `BpfProgInfo` includes:

- identity: `prog_type`, `id`, `tag`, `name`
- code sizes/pointers: `jited_prog_len`, `xlated_prog_len`, `jited_prog_insns`, `xlated_prog_insns`
- load metadata: `load_time`, `created_by_uid`, `gpl_compatible`, `ifindex`, netns fields
- maps: `nr_map_ids`, `map_ids`
- BTF/debug: `btf_id`, `func_info*`, `line_info*`, `attach_btf_obj_id`, `attach_btf_id`
- runtime stats: `run_time_ns`, `run_cnt`, `recursion_misses`, `verified_insns`
- fork extension: `orig_prog_len`, `orig_prog_insns`

References:

- `daemon/src/bpf.rs:160` lists daemon `BpfProgInfo` fields.
- `daemon/src/bpf_tests.rs:410` asserts the fork-extended struct is 240 bytes.
- `daemon/src/bpf_tests.rs:423` documents field offsets, including `nr_map_ids` and `map_ids`.
- `vendor/linux-framework/include/uapi/linux/bpf.h:6681` is the fork UAPI `struct bpf_prog_info`.
- `vendor/libbpf/include/uapi/linux/bpf.h:6659` is upstream `struct bpf_prog_info` without `orig_prog_len/orig_prog_insns`.
- `~/.cargo/registry/src/.../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs:5499` shows `libbpf_sys::bpf_prog_info` lacks fork-only original fields.
- `~/.cargo/registry/src/.../libbpf-rs-0.26.2/src/query.rs:127` defines high-level `ProgramInfo`.
- docs.rs lists `ProgramInfo` fields, including `map_ids`, `run_time_ns`, `run_cnt`, and `verified_insns`, but not attach/original fields.

Recommended `info.json` fields:

- `prog_id`
- `name`
- `prog_type`
- `prog_type_name` when known
- `tag`
- `load_time_ns`
- `created_by_uid`
- `gpl_compatible`
- `ifindex`
- `btf_id`
- `attach_btf_obj_id`
- `attach_btf_id`
- `xlated_prog_len`
- `jited_prog_len`
- `orig_prog_len`
- `orig_insn_cnt`
- `verified_insns`
- `run_time_ns`
- `run_cnt`
- `recursion_misses`
- `map_ids`

Do not include xlated or JIT byte arrays in `info.json`; `prog.bin` is the raw bytecode artifact, and xlated/JIT dumps should be a separate debug mode if ever needed.

URLs:

- libbpf-rs `ProgramInfo`: https://docs.rs/libbpf-rs/0.26.2/libbpf_rs/query/struct.ProgramInfo.html
- libbpf-sys `bpf_prog_info`: https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/struct.bpf_prog_info.html
- Kernel syscall docs for `BPF_OBJ_GET_INFO_BY_FD`: https://docs.kernel.org/6.8/userspace-api/ebpf/syscall.html

## 4. map_fds.json

Answer:

`bpf_prog_info.map_ids` is a user-provided pointer to a buffer of `u32` map IDs. The kernel first reports `nr_map_ids`; on the second call, userspace provides a buffer and the kernel copies the program's `used_maps[i]->id` values into it.

From each map ID:

1. open the map with `BPF_MAP_GET_FD_BY_ID`;
2. call `BPF_OBJ_GET_INFO_BY_FD` / `bpf_map_get_info_by_fd`;
3. serialize stable map metadata.

Do not serialize process-local FD numbers as durable JSON. FDs are only meaningful inside the process that opened them. Keep the filename `map_fds.json` for v3 compatibility if desired, but make the content map IDs plus metadata; consumers such as `bpfverify` or `bpfrejit` should reopen IDs in their own process.

References:

- `daemon/src/bpf.rs:222` defines `BpfMapInfo`.
- `daemon/src/bpf.rs:749` opens a map by ID.
- `daemon/src/bpf.rs:766` gets map info by FD.
- `daemon/src/bpf.rs:1229` implements two-pass `bpf_prog_get_map_ids`.
- `daemon/src/bpf.rs:1291` explains map FD relocation: original bytecode contains stale loader-process FDs, and the daemon maps first-seen old FDs to `map_ids` order.
- `vendor/linux-framework/kernel/bpf/syscall.c:5881` copies `used_maps` IDs into `bpf_prog_info.map_ids`.
- `~/.cargo/registry/src/.../libbpf-rs-0.26.2/src/query.rs:465` defines high-level `MapInfo`.
- `~/.cargo/registry/src/.../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs:5587` defines raw `bpf_map_info`.

Is this enough for `bpfopt --map-values`?

No. `map_fds.json` with map IDs and metadata is enough for relocation and for consumers that can reopen maps by ID. It is not enough for `bpfopt --map-values`, because `map-values.json` requires actual key/value snapshots. v3 section 3.3 also says map-values contains only program-lookup keys, not a full dump. bpfget cannot infer those keys without bytecode analysis or a separate map-inline probing step.

Recommended schema:

```json
{
  "prog_id": 123,
  "maps": [
    {
      "map_id": 10,
      "name": "events",
      "map_type": 2,
      "map_type_name": "array",
      "key_size": 4,
      "value_size": 8,
      "max_entries": 1024,
      "map_flags": 0,
      "btf_id": 0,
      "btf_key_type_id": 0,
      "btf_value_type_id": 0,
      "ifindex": 0
    }
  ]
}
```

URLs:

- libbpf map info API source: https://github.com/libbpf/libbpf/blob/v1.7.0/src/bpf.h
- Kernel BTF doc notes that `bpf_map_info` and `bpf_prog_info` provide BTF IDs for introspection: https://docs.kernel.org/6.4/bpf/btf.html

## 5. target.json generation

Answer:

Implement `bpfget --target` as a flag-style mode that does not require `PROG_ID` and writes JSON to stdout. Do not make a separate CLI binary or subcommand mode. This matches v3 section 2.4 flag style and v3 section 10 "target.json automatic generation".

The current daemon already has the two required pieces:

- platform feature detection in `daemon/src/platform_detect.rs`;
- kinsn BTF discovery in `daemon/src/kfunc_discovery.rs`.

Migration recommendation:

- move or copy the discovery logic into `bpfget/src/target.rs`;
- keep daemon using its current copy temporarily until daemon slimming;
- later delete daemon-local discovery when `bpfrejit-daemon` becomes only a watcher/trigger.

References:

- `docs/tmp/bpfopt_design_v3.md:263` defines `target.json`.
- `docs/tmp/bpfopt_design_v3.md:582` says `daemon/src/kfunc_discovery.rs` moves into `bpfget/src/main.rs`.
- `docs/tmp/bpfopt_design_v3.md:759` lists `bpfget --target` as Phase 4 enhancement.
- `daemon/src/main.rs:40` currently performs kinsn discovery at daemon startup.
- `daemon/src/main.rs:46` currently performs platform detection.
- `daemon/src/platform_detect.rs:27` parses `/proc/cpuinfo` flags for x86_64.
- `daemon/src/platform_detect.rs:39` maps CPU flags into `has_bmi1`, `has_bmi2`, `has_cmov`, `has_movbe`, and `has_rorx`.
- `daemon/src/kfunc_discovery.rs:21` defines known kinsn function/module mappings.
- `daemon/src/kfunc_discovery.rs:164` reads vmlinux BTF layout to handle split module BTF.
- `daemon/src/kfunc_discovery.rs:192` finds a `BTF_KIND_FUNC` by name.
- `daemon/src/kfunc_discovery.rs:313` is the discovery entry point.
- `daemon/src/kfunc_discovery.rs:386` gets BPF BTF FDs for daemon REJIT fd-array transport; `target.json` only needs function BTF IDs.
- `bpfopt/crates/bpfopt/src/pass.rs:593` defines `KinsnRegistry`.
- `bpfopt/crates/bpfopt/src/pass.rs:710` defines `PlatformCapabilities`.

Recommended target detection flow:

1. Detect `arch`: compile-time `target_arch` or `std::env::consts::ARCH`, normalized to `x86_64` or `aarch64`.
2. Detect CPU `features`:
   - x86_64: parse first `flags` line in `/proc/cpuinfo`;
   - aarch64: use known architectural capability for conditional select and optionally parse `/proc/cpuinfo` `Features`.
3. Scan `/sys/kernel/btf/vmlinux` for split BTF base string length and type-count bias.
4. For each known kinsn module under `/sys/kernel/btf/<module>`, parse BTF and find the `BTF_KIND_FUNC` ID.
5. Emit only discovered kinsns. Missing kinsns are absent rather than encoded as `-1`.

Recommended `target.json`:

```json
{
  "arch": "x86_64",
  "features": ["bmi1", "bmi2", "cmov", "movbe", "rorx"],
  "kinsns": {
    "bpf_rotate64": { "btf_func_id": 12345, "supported_encodings": ["packed_call"] },
    "bpf_select64": { "btf_func_id": 12346, "supported_encodings": ["packed_call"] },
    "bpf_extract64": { "btf_func_id": 12347, "supported_encodings": ["packed_call"] },
    "bpf_endian_load64": { "btf_func_id": 12348, "supported_encodings": ["packed_call"] }
  }
}
```

URLs:

- Kernel BTF docs: https://docs.kernel.org/6.4/bpf/btf.html
- Current repo kfunc discovery source: https://github.com/eunomia-bpf/bpf-benchmark/blob/9f59ee436fc49aa75ab85e3cf481bc69a2fd7ce4/daemon/src/kfunc_discovery.rs

## 6. CLI argument parsing

Answer:

Use flag style, not subcommands. v3 examples are all flag style, and flag style keeps the default `bpfget 123` behavior unambiguous for binary stdout.

Recommended flags:

- positional `PROG_ID: Option<u32>`
- `--info`
- `--full`
- `--outdir DIR`
- `--list`
- `--json`
- `--target`

Validation rules:

- default mode: requires `PROG_ID`, no primary flag, writes binary to stdout.
- `--info`: requires `PROG_ID`, writes JSON to stdout.
- `--full`: requires `PROG_ID` and `--outdir`, writes files and no stdout payload.
- `--list`: forbids `PROG_ID`; `--json` is valid only here.
- `--target`: forbids `PROG_ID`; writes `target.json` to stdout and is already JSON, so `--json` should be rejected.
- `--outdir` is only valid with `--full`.
- reject multiple primary modes among `--info`, `--full`, `--list`, and `--target`.

Suggested `main.rs` shape:

```rust
#[derive(Parser)]
struct Cli {
    prog_id: Option<u32>,
    #[arg(long)] info: bool,
    #[arg(long)] full: bool,
    #[arg(long)] outdir: Option<PathBuf>,
    #[arg(long)] list: bool,
    #[arg(long)] json: bool,
    #[arg(long)] target: bool,
}

enum Mode {
    Binary { prog_id: u32 },
    Info { prog_id: u32 },
    Full { prog_id: u32, outdir: PathBuf },
    List { json: bool },
    Target,
}
```

References:

- `docs/tmp/bpfopt_design_v3.md:163` defines `bpfget`.
- `docs/tmp/bpfopt_design_v3.md:167` shows `bpfget 123`, `bpfget 123 --info`, `bpfget 123 --full --outdir`, and `bpfget --list --json`.
- `bpfopt/crates/bpfopt/src/main.rs:7` shows the current Clap style used by the existing `bpfopt` CLI.

URLs:

- Clap derive docs: https://docs.rs/clap/latest/clap/_derive/

## 7. stdout binary vs JSON

Answer:

Use strict stdout semantics:

- `bpfget 123`: raw `struct bpf_insn[]` bytes to stdout; no text, no JSON, no framing.
- `bpfget 123 --info`: pretty or compact JSON to stdout; no binary.
- `bpfget 123 --full --outdir DIR`: create `DIR/prog.bin`, `DIR/prog_info.json`, and `DIR/map_fds.json`; no stdout payload.
- `bpfget --list`: plain text, one program per line. Recommended format: `ID<TAB>TYPE<TAB>NAME`.
- `bpfget --list --json`: JSON array. Recommended elements include `id`, `name`, `prog_type`, `prog_type_name`, and `map_ids` if already cheap to fetch.
- `bpfget --target`: JSON to stdout.

Do not add `--output FILE` for the first implementation. v3 intentionally uses shell redirection for stdout binary and info JSON. Adding `--output` is not necessary for `--full`, which already has `--outdir`, and it increases mode validation complexity.

References:

- `docs/tmp/bpfopt_design_v3.md:88` defines raw binary stdin/stdout as `struct bpf_insn[]`.
- `docs/tmp/bpfopt_design_v3.md:167` defines bpfget stdout examples.
- `docs/tmp/bpfopt_design_v3.md:174` defines `--full` output files.
- `docs/tmp/bpfopt_design_v3.md:381` defines pipeline protocol: binary through stdin/stdout, side-input/output through files, stderr for logs/errors.

URLs:

- Kernel syscall docs for introspection commands: https://docs.kernel.org/6.8/userspace-api/ebpf/syscall.html

## 8. Error handling

Answer:

All failure modes should exit 1 and write a human-readable message to stderr. No JSON error payload is needed for v3.

Recommended mappings:

- program not found: `BPF_PROG_GET_FD_BY_ID` returns `ENOENT`; report `program id <id> not found`.
- permission denied: `EPERM`/`EACCES` from get-fd, info, map, or original-bytecode paths; report required privileges, usually `CAP_BPF` and maybe `CAP_SYS_ADMIN` for this fork.
- no fork support for original bytecode:
  - if using proposed `BPF_PROG_GET_ORIGINAL`, map `EINVAL`, `ENOSYS`, or `EOPNOTSUPP` to `kernel does not support BPF_PROG_GET_ORIGINAL`;
  - if using current `bpf_prog_info.orig_*` fallback, empty `orig_insns` should be a hard error with guidance to use the fork kernel and sufficient capabilities.
- malformed kernel response: original byte length not divisible by 8 -> hard error.
- map info unavailable in `--full`: hard error; do not silently omit maps.
- list enumeration failure after partial output: hard error. For JSON list, collect first, then print only after success to avoid truncated JSON.

References:

- `daemon/src/bpf.rs:637` treats `ENOENT` from `BPF_PROG_GET_NEXT_ID` as end-of-iteration.
- `daemon/src/bpf.rs:658` returns syscall errors from `BPF_PROG_GET_FD_BY_ID`.
- `daemon/src/bpf.rs:504` returns `BPF_OBJ_GET_INFO_BY_FD` errors.
- `daemon/src/bpf.rs:545` errors on invalid bytecode length.
- `daemon/src/commands.rs:507` hard-fails empty original bytecode.
- `vendor/linux-framework/kernel/bpf/syscall.c:3617` requires `CAP_BPF` and `CAP_SYS_ADMIN` for `BPF_PROG_REJIT`; original-bytecode dump uses `bpf_capable()` gating in info path at `vendor/linux-framework/kernel/bpf/syscall.c:5911`.

URLs:

- Kernel syscall docs state standard return convention and errno behavior: https://docs.kernel.org/6.8/userspace-api/ebpf/syscall.html

## Implementation plan

### `bpfget/src/main.rs` structure

Recommended modules:

- `cli`: Clap parser and `Mode` validation.
- `binary`: byte-slice conversion for `Vec<libbpf_sys::bpf_insn>` and stdout/file writing.
- `info`: `ProgInfoJson`, raw info collection, tag/name/type helpers.
- `maps`: map ID two-pass fetch and map metadata JSON.
- `target`: platform detection plus kinsn BTF discovery.
- `list`: live program enumeration and plain/JSON rendering.

Mode dispatch:

```rust
fn main() -> Result<()> {
    let cli = Cli::parse();
    match Mode::try_from(cli)? {
        Mode::Binary { prog_id } => write_prog_bin(prog_id, stdout())?,
        Mode::Info { prog_id } => write_prog_info_json(prog_id, stdout())?,
        Mode::Full { prog_id, outdir } => write_full(prog_id, &outdir)?,
        Mode::List { json } => write_program_list(json, stdout())?,
        Mode::Target => write_target_json(stdout())?,
    }
    Ok(())
}
```

`--full` steps:

1. create output dir if absent;
2. open program by ID;
3. fetch original bytecode;
4. fetch raw program info plus map IDs;
5. fetch map metadata;
6. write `prog.bin`, `prog_info.json`, and `map_fds.json`.

### `kernel-sys` API needs

Already present in local `kernel-sys`:

- `prog_get_next_id(start_id) -> Result<Option<u32>>`
- `prog_get_fd_by_id(id) -> Result<OwnedFd>`
- `obj_get_info_by_fd(fd) -> Result<libbpf_sys::bpf_prog_info>`
- `prog_get_original(fd) -> Result<Vec<libbpf_sys::bpf_insn>>`

Still needed or should be added/confirmed:

- `prog_get_info_with_map_ids(fd) -> Result<(bpf_prog_info, Vec<u32>)>` using two-pass `map_ids`.
- `map_get_fd_by_id(id) -> Result<OwnedFd>` using `libbpf_sys::bpf_map_get_fd_by_id`.
- `map_get_info_by_fd(fd) -> Result<libbpf_sys::bpf_map_info>` using `libbpf_sys::bpf_map_get_info_by_fd`.
- `prog_get_original_via_info(fd) -> Result<Vec<bpf_insn>>` as temporary fallback if the kernel has only `orig_prog_len/orig_prog_insns`.
- `btf_get_next_id`, `btf_get_fd_by_id`, and BTF info helpers if `target` wants BPF-subsystem BTF FDs; pure `/sys/kernel/btf` parsing can live entirely in bpfget.

Keep the syscall boundary rule: all direct `libc::syscall(SYS_bpf, ...)` usage stays inside `kernel-sys`. Standard commands should go through libbpf/libbpf-sys. Fork-only `BPF_PROG_REJIT` and future `BPF_PROG_GET_ORIGINAL` may use direct syscalls inside `kernel-sys`.

### Migration steps

1. Add `bpfopt/crates/bpfget` and workspace member, depending on `kernel-sys`, `clap`, `serde`, `serde_json`, and `anyhow`.
2. Implement mode validation and stdout/file behavior first, with unit tests that do not require BPF privileges.
3. Move standard wrappers from daemon `bpf.rs` into `kernel-sys` using libbpf-sys equivalents, not custom attr wrappers.
4. Implement `--list` and `bpfget PROG_ID > prog.bin`.
5. Implement `--info` and `--full`.
6. Move `platform_detect.rs` and `kfunc_discovery.rs` logic into `bpfget target` module.
7. Update daemon later to call `bpfget --target` or consume generated `target.json`, then delete daemon-local discovery during daemon slimming.
8. Add Linux integration tests gated on capabilities and kernel support. Tests should accept `EPERM`/unsupported as skip only in test harness, not in CLI behavior.

## Schema drafts

### `prog_info.json`

```json
{
  "prog_id": 123,
  "name": "xdp_pass",
  "prog_type": 6,
  "prog_type_name": "xdp",
  "tag": "0123456789abcdef",
  "load_time_ns": 1234567890,
  "created_by_uid": 0,
  "gpl_compatible": true,
  "ifindex": 0,
  "btf_id": 0,
  "attach_btf_obj_id": 0,
  "attach_btf_id": 0,
  "xlated_prog_len": 512,
  "jited_prog_len": 384,
  "orig_prog_len": 512,
  "orig_insn_cnt": 64,
  "verified_insns": 64,
  "run_time_ns": 1000,
  "run_cnt": 10,
  "recursion_misses": 0,
  "map_ids": [10, 11]
}
```

### `map_fds.json`

```json
{
  "prog_id": 123,
  "maps": [
    {
      "map_id": 10,
      "name": "config",
      "map_type": 2,
      "map_type_name": "array",
      "key_size": 4,
      "value_size": 8,
      "max_entries": 1,
      "map_flags": 0,
      "btf_id": 0,
      "btf_key_type_id": 0,
      "btf_value_type_id": 0,
      "ifindex": 0
    }
  ]
}
```

### `target.json`

```json
{
  "arch": "x86_64",
  "features": ["bmi1", "bmi2", "cmov", "movbe", "rorx"],
  "kinsns": {
    "bpf_rotate64": {
      "btf_func_id": 12345,
      "supported_encodings": ["packed_call"]
    },
    "bpf_select64": {
      "btf_func_id": 12346,
      "supported_encodings": ["packed_call"]
    },
    "bpf_extract64": {
      "btf_func_id": 12347,
      "supported_encodings": ["packed_call"]
    },
    "bpf_memcpy_bulk": {
      "btf_func_id": 12348,
      "supported_encodings": ["packed_call"]
    },
    "bpf_memset_bulk": {
      "btf_func_id": 12349,
      "supported_encodings": ["packed_call"]
    }
  }
}
```

## Open design decision

The v3 request says `BPF_PROG_GET_ORIGINAL`; the checked-in kernel fork currently implements original-bytecode export through `BPF_OBJ_GET_INFO_BY_FD` fork fields and has no `BPF_PROG_GET_ORIGINAL` enum value. Before implementing bpfget, choose one of:

1. add kernel support for `BPF_PROG_GET_ORIGINAL` and keep `kernel-sys::prog_get_original` as the only bpfget bytecode path;
2. implement bpfget with a temporary `orig_prog_info` fallback and remove it once the syscall exists.

Given v3 is the authority, option 1 is cleaner. Option 2 is lower risk for incremental migration because it reuses daemon-proven behavior.
