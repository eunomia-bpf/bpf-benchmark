# kill_kernel_sys Review - 2026-05-08

## Verdict

The bpfprof/kernel-sys removal is structurally complete in live source: Rust/TOML manifests no longer reference `kernel_sys` / `kernel-sys`, daemon-owned syscalls moved to `daemon/src/syscall.rs`, and map-reference canonicalization moved behind the `bpfopt --canonicalize-map-refs` CLI boundary. I did not find a fatal migration bug; the remaining issues are low-risk documentation/stale-artifact cleanup items.

## 完整性 Audit

| Item | Status | Evidence |
| --- | --- | --- |
| `kernel_sys::` Rust/TOML references removed | ✅ | `rg -n "kernel_sys::" -g '*.rs' -g 'Cargo.toml' -g '!target/**' -g '!**/target/**' .` returned no matches. |
| `kernel-sys` path dependencies removed | ✅ | `rg -n "kernel-sys\|kernel_sys\|bpfprof" -g 'Cargo.toml' -g 'Cargo.lock' -g '!target/**' -g '!**/target/**' .` returned no matches. `rg -n 'path\\s*=\\s*\"' -g Cargo.toml .` only found bin path entries: `bpfopt/crates/bpfopt/Cargo.toml:9` and `daemon/Cargo.toml:22`. |
| `bpfopt` depends directly on `libbpf-sys` | ✅ | `bpfopt/Cargo.toml:12` has `libbpf-sys = "1.7.0"`; `bpfopt/crates/bpfopt/Cargo.toml:16` has `libbpf-sys.workspace = true`. |
| daemon depends directly on `libbpf-sys` | ✅ | `daemon/Cargo.toml:14` has `libbpf-sys = "1.5"`; `daemon/Cargo.toml:27` has `libbpf-sys.workspace = true`. |
| workspace members only `crates/bpfopt` | ✅ | `bpfopt/Cargo.toml:1-5` lists only `crates/bpfopt`; `find bpfopt/crates -maxdepth 2 -type f -name Cargo.toml` returns only `bpfopt/crates/bpfopt/Cargo.toml`. |
| removed crate paths absent from live tree | ✅ | `rg --files -g '!target/**' -g '!**/target/**' bpfopt/crates daemon \| rg '(^|/)(bpfprof|kernel-sys|bpfget|bpfverify|bpfrejit)(/|$)'` returned no matches. |

Note: plain grep without excluding `target/` finds stale build artifacts mentioning old crates. Those are not live source or manifests.

## 正确性 Audit

| Item | Status | Evidence |
| --- | --- | --- |
| daemon no longer carries map-ref bytecode parser/canonicalizer | ✅ | `rg -n "is_ldimm64\|is_call\|is_exit\|is_map_pseudo\|map_fd_pseudo" daemon/src/*.rs` returned no matches. |
| `canonicalize_map_refs_to_idx` moved to bpfopt only | ✅ | `rg -n "canonicalize_map_refs_to_idx" bpfopt/crates/bpfopt/src daemon/src` shows only `bpfopt/crates/bpfopt/src/main.rs:286,529,...`; no daemon definition/caller remains. |
| canonicalize entry is CLI flag, not a normal pass | ✅ | `bpfopt/crates/bpfopt/src/main.rs:243-250` rejects combining `--canonicalize-map-refs` with `--pass` or subcommands and dispatches to `run_canonicalize_map_refs()`. |
| daemon invokes bpfopt CLI for init canonicalization | ✅ | `daemon/src/commands.rs:448-503` builds `Command::new("bpfopt")` with `--canonicalize-map-refs`, `--input`, `--output`, optional `--map-ids`, and optional `--target/--target-output`. `run_program_steps()` calls it at `daemon/src/commands.rs:534-542`. |
| daemon still only decodes raw bytecode for ReJIT | ✅ | `daemon/src/commands.rs:1374-1391` decodes 8-byte records into `libbpf_sys::bpf_insn`; this is wire-format decoding before `BPF_PROG_REJIT`, not map-reference semantic parsing. |
| standard BPF calls isolated to daemon syscall layer | ✅ | `rg -n "bpf_obj_get_info_by_fd\|bpf_prog_get_fd_by_id\|bpf_map_get_fd_by_id\|bpf_map_lookup_elem\|bpf_map_get_next_key\|bpf_btf_get" bpfopt/crates/bpfopt/src daemon/src` shows real calls only in `daemon/src/syscall.rs`; bpfopt hits are comments about helper calls. |
| direct `SYS_bpf` isolated to daemon syscall layer | ✅ | `rg -n "libc::syscall\|SYS_bpf\|__NR_bpf" bpfopt/crates/bpfopt/src daemon/src` shows only `daemon/src/syscall.rs:202-203`. |
| syscall wrapper subset covers daemon callers | ✅ | Active callers use `prog_get_fd_by_id`, `prog_get_original`, `obj_get_info_by_fd`, `prog_map_ids`, `map_get_fd_by_id`, `map_obj_get_info_by_fd`, `btf_get_next_id`, `btf_get_fd_by_id`, `map_get_next_key`, `map_lookup_elem`, and `prog_rejit`; all are present in `daemon/src/syscall.rs:211-481`. |

Omitted old `kernel-sys` APIs such as `prog_get_next_id`, `enable_stats`, perf/ringbuf helpers, dry-run/load helpers, and jited/xlated readers have no active caller after bpfprof removal. That matches the fail-fast/no-dead-code rule.

## 命名 Audit

| API group | Status | Evidence |
| --- | --- | --- |
| `crate::verifier_log` | ✅ | `bpfopt/crates/bpfopt/src/verifier_log.rs` preserves `VerifierStatesJson`, `VerifierInsnJson`, `VerifierRegJson`, `VerifierStackJson`, `RegState`, `ScalarRange`, `Tnum`, `VerifierInsn`, `VerifierInsnKind`, `VerifierValueWidth`, `parse_verifier_log()`, and `verifier_states_from_log()`. `bpfopt/crates/bpfopt/src/pass.rs:19-21` re-exports the pass-facing types. |
| verifier log callers updated | ✅ | `bpfopt/crates/bpfopt/src/main.rs:23-25` imports from `bpfopt::verifier_log`; no `kernel_sys` import remains. |
| `crate::syscall` daemon API names | ✅ | The daemon-used old names are retained as `syscall::{prog_get_fd_by_id, prog_get_original, obj_get_info_by_fd, prog_map_ids, map_get_fd_by_id, map_obj_get_info_by_fd, btf_get_next_id, btf_get_fd_by_id, map_get_next_key, map_lookup_elem, prog_rejit}`. |
| caller sync | ✅ | `rg -n "syscall::(...)" daemon/src` shows all active daemon callers updated to `crate::syscall`; build/test confirms no stale names. |

Minor note: `daemon/src/bpf.rs:283` exposes a local facade named `bpf_map_get_fd_by_id()` over `syscall::map_get_fd_by_id()`. It is internally consistent and used for opener injection, but the name differs from the syscall wrapper.

## CLAUDE.md 同步 Audit

| Item | Status | Evidence |
| --- | --- | --- |
| old "kernel-sys is the Only Syscall Boundary" section removed | ✅ | `CLAUDE.md:117-120` now has "Daemon Syscall Boundary" and states `kernel-sys` has been removed. |
| daemon direct `libbpf-sys` + local `syscall.rs` documented | ✅ | `CLAUDE.md:97` and `CLAUDE.md:120` describe `bpfopt --canonicalize-map-refs`, live discovery/BTF/map helpers through `daemon/src/syscall.rs`, and daemon importing `libbpf_sys::bpf_insn` directly. |
| No CLI cross-dependency rule updated | ✅ | `CLAUDE.md:102-107` lists only `bpfopt` and `bpfrejit-daemon` as remaining standalone CLI crates and says removed crates include `bpfget`, `bpfverify`, `bpfrejit`, `bpfprof`, and `kernel-sys`. |
| stale kernel-sys references in CLAUDE | ✅ | `rg -n "kernel-sys.*only\|Only Syscall Boundary\|kernel_sys" CLAUDE.md` has no stale old-boundary hit. Current mentions say the crate was removed. |
| related authoritative design doc updated | ✅ | `docs/tmp/bpfopt_design_v3.md:12`, `:82-87`, `:131-152`, and `:191-206` match the new two-component layout. |

Low-risk wording issue: `CLAUDE.md:114` still calls `BPF_PROG_GET_ORIGINAL` a "custom wrapper" beside `BPF_PROG_REJIT`, while `CLAUDE.md:120` correctly clarifies that original bytecode is read through fork-extended `bpf_prog_info`. This is not a code bug, but the line could be tightened to avoid implying a distinct syscall command.

## 潜在 Bug 清单

- No HIGH/CRITICAL functional bug found.
- Low: `bpfopt` uses `libbpf-sys 1.7.0`, while daemon uses `libbpf-sys 1.5`. There is no Rust type mismatch today because `bpfopt` and daemon are separate workspaces and communicate through raw byte streams, not shared Rust values. Both sides encode/decode ABI-compatible `struct bpf_insn`, and ABI offset tests pass. Still, this is worth keeping in mind if anyone later tries to reintroduce compile-time sharing.
- Low: historical/reference docs still contain old `kernel-sys`/`bpfprof` architecture text. The migration report already records this as a known leftover; live source, manifests, CLAUDE.md, daemon README, and `docs/tmp/bpfopt_design_v3.md` are aligned.
- Low: stale `target/` artifacts contain old crate names. They are build cache only, not source; exclude `target/` in future audits.

## 改进建议

1. P2: adjust `CLAUDE.md:114` wording from "custom wrappers ... `BPF_PROG_GET_ORIGINAL`" to "fork-only original-bytecode helper via fork-extended `bpf_prog_info`" so it matches the actual implementation.
2. P3: when doing broad repository grep for removed crates, standardize on `-g '!target/**' -g '!**/target/**'` or clean target dirs before publishing audit output.
3. P3: optionally align daemon `libbpf-sys` to the same version as bpfopt during a later dependency hygiene pass, if the daemon build environment supports it.

## 测试 Sanity

Commands run with `--locked` to prevent the review from changing lockfiles.

| Command | Result | Warning status |
| --- | --- | --- |
| `cargo build --workspace --locked` in `bpfopt/` | ✅ pass, `Finished dev profile ... in 17.73s` | no warnings printed |
| `cargo test --workspace --locked` in `bpfopt/` | ✅ pass | no warnings printed |
| `cargo build --workspace --locked` in `daemon/` | ✅ pass, `Finished dev profile ... in 8.10s` | no warnings printed |
| `cargo test --workspace --locked` in `daemon/` | ✅ pass | no warnings printed |

Fresh test counts:

```text
bpfopt lib tests:        332 passed
bpfopt bin tests:         12 passed
bpfopt cli_pipeline:      12 passed
bpfopt doc tests:          0 passed
daemon unit tests:        25 passed
total non-doc tests:     381 passed
```

This does not align with the "341 passed" reference in the review prompt. The current tree and the migration report both show bpfopt at `332 + 12 + 12 = 356`, and daemon adds `25`, for `381` non-doc tests. No corpus benchmark was run.
