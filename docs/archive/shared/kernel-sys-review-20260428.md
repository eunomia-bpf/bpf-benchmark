# kernel-sys commit review: 9f59ee43

Date: 2026-04-28

Scope:

- `git diff 9f59ee43^..9f59ee43`
- `bpfopt/Cargo.toml`
- `bpfopt/crates/kernel-sys/Cargo.toml`
- `bpfopt/crates/kernel-sys/src/lib.rs`
- `bpfopt/crates/kernel-sys/tests/prog_ids.rs`

Reference material checked:

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `daemon/src/bpf.rs`
- `docs/tmp/bpfopt_design_v3.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/libbpf-rs-eval-20260428.md`

## Findings

### CRITICAL: `BPF_PROG_GET_ORIGINAL = 40` is not a real fork UAPI command

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:23-28`
- `bpfopt/crates/kernel-sys/src/lib.rs:48-55`
- `bpfopt/crates/kernel-sys/src/lib.rs:223-271`
- `bpfopt/crates/kernel-sys/src/lib.rs:310-317`

Description:

`kernel-sys` defines `BPF_PROG_GET_ORIGINAL` as `BPF_PROG_REJIT + 1` and implements `prog_get_original()` by issuing raw `bpf(cmd=40, ...)`. I could not find any `BPF_PROG_GET_ORIGINAL` enum entry in either fork UAPI header. The fork header has `BPF_PROG_REJIT` at enum value 39 and then immediately `__MAX_BPF_CMD`:

- `vendor/linux-framework/include/uapi/linux/bpf.h:955-998`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h:955-998`

The kernel syscall dispatcher also only has a `case BPF_PROG_REJIT`; there is no `case BPF_PROG_GET_ORIGINAL`:

- `vendor/linux-framework/kernel/bpf/syscall.c:7224-7236`

The current daemon likewise has only `const BPF_PROG_REJIT: u32 = 39`; it does not define or call a separate `BPF_PROG_GET_ORIGINAL` command:

- `daemon/src/bpf.rs:16-41`

The actual fork mechanism for original bytecode is through fork-added `struct bpf_prog_info` fields, returned by `BPF_OBJ_GET_INFO_BY_FD`:

- `vendor/linux-framework/include/uapi/linux/bpf.h:6721-6722`
- `vendor/linux-framework/kernel/bpf/syscall.c:5944-5955`
- `daemon/src/bpf.rs:565-617`

Impact:

`kernel_sys::prog_get_original()` will call an unrecognized command slot and should fail with `EINVAL` on the current fork kernel. This blocks `bpfget PROG_ID > prog.bin` and v3 section 2.4's bytecode retrieval path.

Fix recommendation:

Remove the fake command constant and `AttrGetOriginal`. Implement original-bytecode retrieval by calling `libbpf_sys::bpf_obj_get_info_by_fd` with a project-local fork-compatible `BpfProgInfo` layout that includes `orig_prog_len` and `orig_prog_insns`, following the daemon's two-pass pattern:

1. first `BPF_OBJ_GET_INFO_BY_FD` with zero `orig_prog_len` to read required byte length;
2. allocate `orig_prog_len` bytes;
3. second `BPF_OBJ_GET_INFO_BY_FD` with `orig_prog_len` and `orig_prog_insns` set;
4. parse bytes as `struct bpf_insn[]`, rejecting non-multiple-of-8 lengths.

Also change the test so it checks the vendor fork UAPI or kernel dispatcher, not only "daemon constant exists or else +1".

### CRITICAL: `obj_get_info_by_fd()` uses upstream `libbpf_sys::bpf_prog_info`, which lacks fork `orig_prog_*` fields

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:179-193`

Description:

`obj_get_info_by_fd()` returns `libbpf_sys::bpf_prog_info`. The `libbpf-sys 1.7.0` generated struct ends at `attach_btf_id` and does not contain the fork-only fields:

- no `orig_prog_len`
- no `orig_prog_insns`

Local source check:

- `~/.cargo/registry/src/.../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs:5499-5540`
- `rg "orig_prog_len|orig_prog_insns" .../libbpf-sys-1.7.0+v1.7.0/src/bindings.rs` returned no matches.

The fork UAPI and daemon both require those fields for `bpfget`:

- `vendor/linux-framework/include/uapi/linux/bpf.h:6721-6722`
- `daemon/src/bpf.rs:156-201`
- `daemon/src/bpf.rs:565-617`

Impact:

Even after removing the fake `BPF_PROG_GET_ORIGINAL` command, the current `obj_get_info_by_fd()` API cannot retrieve original bytecode because it passes the shorter upstream struct and has no way to set/read `orig_prog_len` or `orig_prog_insns`.

Fix recommendation:

Keep using `libbpf_sys::bpf_obj_get_info_by_fd` for the standard syscall wrapper, but define a local fork-extension info struct in `kernel-sys` for program info. Expose separate APIs such as:

- `prog_get_info(fd) -> ForkBpfProgInfo`
- `prog_get_original(fd) -> Vec<bpf_insn>`

Do not rely on upstream `libbpf_sys::bpf_prog_info` for fork-only fields.

### HIGH: `fork_attr_layouts_are_128_bytes` asserts a stale `union bpf_attr` size

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:33-55`
- `bpfopt/crates/kernel-sys/src/lib.rs:320-324`

Description:

The test asserts both fork attr structs are 128 bytes and names this as attr layout coverage. The current fork UAPI `union bpf_attr` is 168 bytes, not 128 bytes. I confirmed with a C compile check against `vendor/linux-framework/include/uapi/linux/bpf.h`:

```text
sizeof(union bpf_attr) = 168
offsetof(rejit.prog_fd) = 0
offsetof(rejit.insn_cnt) = 4
offsetof(rejit.insns) = 8
offsetof(rejit.log_level) = 16
offsetof(rejit.log_size) = 20
offsetof(rejit.log_buf) = 24
offsetof(rejit.fd_array) = 32
offsetof(rejit.fd_array_cnt) = 40
offsetof(rejit.flags) = 44
```

`AttrRejit` field order and offsets through `flags` match the UAPI:

- `vendor/linux-framework/include/uapi/linux/bpf.h:1935-1945`

Passing 128 bytes to `BPF_PROG_REJIT` should still work today because `__sys_bpf()` zero-initializes the full union before copying the user-provided prefix, and `CHECK_ATTR(BPF_PROG_REJIT)` requires only zero tail bytes after `rejit.flags`:

- `vendor/linux-framework/kernel/bpf/syscall.c:91-112`
- `vendor/linux-framework/kernel/bpf/syscall.c:1204-1210`
- `vendor/linux-framework/kernel/bpf/syscall.c:7089-7102`
- `vendor/linux-framework/kernel/bpf/syscall.c:3594-3612`

Impact:

The current test gives a false sense that the local structs equal the fork's full `bpf_attr` union. It will not catch future UAPI growth and it contradicts the current vendor header.

Fix recommendation:

Rename/rework the test to check the meaningful ABI contract:

- `AttrRejit` offsets through `flags` match `offsetof(union bpf_attr, rejit.*)`;
- bytes after `flags` are zero;
- the command passes either `offsetofend(union bpf_attr, rejit.flags)` or an explicitly documented zero-padded prefix.

Avoid asserting 128 as the full union size.

### HIGH: `prog_rejit()` cannot capture verifier logs

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:205-220`

Description:

v3 section 2.5 requires `bpfrejit` to surface verifier logs on kernel verify failure. The daemon currently retries `BPF_PROG_REJIT` with `log_level=2` and a log buffer:

- `daemon/src/bpf.rs:1608-1659`
- `daemon/src/bpf.rs:1662-1675`

The new `kernel_sys::prog_rejit()` always sends `log_level=0`, has no log buffer parameter, and returns only `BPF_PROG_REJIT: <os error>` on failure.

Impact:

The future `bpfrejit` CLI cannot implement the v3 behavior using this API. ReJIT verifier failures would lose the actionable verifier diagnostics needed for scripts and benchmark results.

Fix recommendation:

Add an API that accepts optional log buffer/log level, or provide a higher-level `prog_rejit_with_log()` that mirrors the daemon behavior: try without log first, retry with `log_level=2` on failure, and include the verifier log in the error or structured result.

### MEDIUM: `prog_load_dryrun()` verifier-log handling is incomplete for `bpfverify`

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:104-153`

Description:

The implementation correctly uses `libbpf_sys::bpf_prog_load`, sets `log_level=2` when a buffer is provided, and includes the log in errors. However, it does not expose `bpf_prog_load_opts.log_true_size`, does not identify truncated logs, and does not support a grow/retry loop. The daemon has explicit ENOSPC/log-size retry logic:

- `daemon/src/bpf.rs:1563-1591`

v3 section 2.2 also lists `--expected-attach-type`, `--map-fds`, and `--fd-array`; this API currently accepts only `prog_type`, instructions, and an optional log buffer.

Impact:

The initial `bpfverify` CLI can perform a minimal dry-run, but it cannot reliably produce complete verifier-state logs or verify programs requiring expected attach type / map fd / fd array context.

Fix recommendation:

Return a structured result containing at least `log`, `log_true_size`, and status. Add options for `expected_attach_type`, `fd_array`, and any map-fd bindings required by the v3 CLI. Either implement log-buffer resizing in `kernel-sys` or make `log_true_size` visible so the CLI can do it.

### MEDIUM: bpfget map APIs are missing

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:156-203`

Description:

The current API covers:

- `prog_get_next_id`
- `prog_get_fd_by_id`
- `obj_get_info_by_fd` for program info only
- `enable_stats`

v3 section 2.4 and map-inline side inputs require bpfget to retrieve map IDs from program info and then fetch map fds/info. `libbpf-sys` provides the standard wrappers:

- `bpf_map_get_fd_by_id`
- `bpf_obj_get_info_by_fd` / `bpf_map_get_info_by_fd`

The commit does not expose these.

Impact:

`bpfget --full` cannot prepare `map_fds.json`, map metadata, or map-value side inputs using only `kernel-sys`.

Fix recommendation:

Add `map_get_fd_by_id(id) -> OwnedFd` and `map_get_info_by_fd(fd) -> bpf_map_info` wrappers using `libbpf_sys`. Keep them in `kernel-sys` so the future CLI crates do not call BPF syscalls directly.

### MEDIUM: bpfprof PMU support is not represented

Location:

- `bpfopt/crates/kernel-sys/src/lib.rs:196-203`

Description:

`enable_stats()` covers per-program `run_cnt`/`run_time_ns`. v3 section 2.3 also requires `perf_event_open` for `branch_misses` and `branch_instructions`.

Impact:

This commit is sufficient for BPF runtime stats but not for the complete `bpfprof` profile schema.

Fix recommendation:

Decide the ownership boundary explicitly before Phase 1.3:

- either add a small `perf_event_open` wrapper to `kernel-sys`, because it is a kernel syscall boundary used by bpfopt-suite;
- or standardize on a dedicated crate such as `perf-event-open-sys` in `bpfprof` and document that `kernel-sys` is the BPF syscall boundary, not every Linux syscall boundary.

### LOW: Integration test does not exercise the important fork paths

Location:

- `bpfopt/crates/kernel-sys/tests/prog_ids.rs:1-29`

Description:

The test only calls `prog_get_next_id(0)` and accepts `Ok(_)`. It does not open the returned program, retrieve program info, retrieve original bytecode, or exercise `BPF_PROG_REJIT`.

Impact:

The test passed even though `BPF_PROG_GET_ORIGINAL` is not a valid command and `prog_get_original()` is unusable on the current fork kernel.

Fix recommendation:

Keep the current smoke test, but add fork-kernel gated tests for:

- `prog_get_original()` through `BPF_OBJ_GET_INFO_BY_FD`;
- `BPF_PROG_REJIT` command number and attr offsets against the vendor UAPI;
- verifier-log capture on a controlled rejected ReJIT if the environment has privileges.

## Positive checks

- `BPF_PROG_REJIT = 39` matches the fork UAPI and daemon:
  - `vendor/linux-framework/include/uapi/linux/bpf.h:996`
  - `vendor/linux-framework/tools/include/uapi/linux/bpf.h:996`
  - `daemon/src/bpf.rs:38-41`
- `AttrRejit` field order and offsets through `flags` match `union bpf_attr.rejit`.
- Standard BPF commands in this commit use `libbpf_sys` wrappers, not hand-written raw syscalls:
  - `prog_load_dryrun()` uses `bpf_prog_load`
  - `prog_get_next_id()` uses `bpf_prog_get_next_id`
  - `prog_get_fd_by_id()` uses `bpf_prog_get_fd_by_id`
  - `obj_get_info_by_fd()` uses `bpf_obj_get_info_by_fd`
  - `enable_stats()` uses `bpf_enable_stats`
- The only direct `libc::syscall(SYS_bpf, ...)` helper is used by the intended fork-only path. The problem is that `BPF_PROG_GET_ORIGINAL` is not actually such a path in the current fork.
- `bpfopt/crates/bpfopt/Cargo.toml` has no `kernel-sys`, `libbpf-rs`, `libbpf-sys`, or `libc` dependency. `bpfopt` remains free of direct kernel/syscall dependencies in this commit.
- `OwnedFd` is used correctly for fds returned by libbpf wrappers, avoiding leaks on success paths.

## Verification

Commands run:

```bash
cargo build -p kernel-sys
cargo test -p kernel-sys
cargo fmt --check
cargo build
cargo test
```

Results:

- `cargo build -p kernel-sys`: passed
- `cargo test -p kernel-sys`: passed, 4 unit tests + 1 integration test
- `cargo fmt --check`: passed
- `cargo build`: passed
- `cargo test`: passed, including 415 `bpfopt` tests and all `kernel-sys` tests

The passing tests do not cover the invalid `BPF_PROG_GET_ORIGINAL` syscall path.

## Phase readiness conclusion

Not ready for Phase 1.2.5 or Phase 1.3.

Reason:

- Phase 1.2.5 should not move `bpfopt` onto `kernel-sys` types while `kernel-sys` has an invented fork command and cannot retrieve fork `orig_prog_*` fields.
- Phase 1.3 `bpfget`/`bpfrejit` CLIs would be blocked by `prog_get_original()` failing with `EINVAL`, incomplete fork program-info support, and missing ReJIT verifier-log capture.

Minimum fixes before proceeding:

1. Replace fake `BPF_PROG_GET_ORIGINAL` syscall with `BPF_OBJ_GET_INFO_BY_FD` + fork `BpfProgInfo.orig_prog_*`.
2. Rework attr-layout tests to compare offsets against the vendor UAPI and stop asserting `sizeof(union bpf_attr) == 128`.
3. Add ReJIT verifier-log API support.
4. Add map fd/info wrappers needed by `bpfget --full`, or explicitly defer them with tracked follow-up before claiming Phase 1.3 readiness.
