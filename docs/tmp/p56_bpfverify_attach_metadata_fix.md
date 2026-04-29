# P56 bpfverify Attach Metadata Replay Fix

## Audit

- `bpfverify` already accepted replay fields on the CLI and passed them into
  `kernel_sys::ProgLoadDryRunOptions` for `BPF_PROG_LOAD`: `prog_type`,
  `expected_attach_type`, `prog_btf_fd`, `attach_btf_id`,
  `attach_btf_obj_fd`, `map_fds`, and `fd_array`.
- The daemon already called `bpfget --full`, read `prog_info.json`, and used
  `append_load_context_args()` for both original verifier-state replay and
  final verification. The daemon could pass `expected_attach_type`, but
  `bpfget` did not emit it because `struct bpf_prog_info` does not expose
  `prog->expected_attach_type`.
- `kernel-sys` remains the only BPF syscall boundary. Standard BPF object and
  link queries use libbpf/libbpf-sys; no CLI crate calls `SYS_bpf` directly.

## Root Cause

`BPF_PROG_LOAD` replay had incomplete load context for attached programs.
`bpfget --full` exported `btf_id`, `attach_btf_id`, and
`attach_btf_obj_id`, but not `expected_attach_type`. That made `bpfverify`
reload tracing/LSM/kprobe-style programs without the original attach metadata.

The observed verifier text, `kernel btf_id ... is not a function`, also
matched kinsn replay using the wrong call encoding. The daemon generated
`fd_array.json`, but the target metadata consumed by `bpfopt` did not carry the
corresponding per-kinsn `call_offset`, so optimized bytecode could still encode
the BTF function id as an immediate instead of the fd-array slot offset.

After attach metadata replay was fixed, tracee exposed a second verifier
rejection: later `const_prop` iterations reused verifier-state PCs captured from
the original program after earlier passes had changed instruction layout. That
stale oracle could fold live helper/map arguments into scalar immediates.

Tracee also exposed an unsafe verifier-state replay detail: verifier log lines
for conditional jumps, such as `if r0 != 0 goto ... ; R0=0`, describe one
control-flow edge only. Treating those as ordinary instruction delta states let
`const_prop` apply the fallthrough fact to the taken edge, including map-in-map
paths where the taken edge carries `R0=map_ptr`.

## Fix

- Added `kernel_sys::expected_attach_type_for_prog(prog_id, prog_type)`.
  It enumerates live BPF links through libbpf-sys, matches links by
  `prog_id`, and recovers link-backed attach types from `struct bpf_link_info`.
  Conflicting attach types for the same program fail fast.
- Extended `bpfget --info` and `bpfget --full` to emit
  `expected_attach_type` in `prog_info.json` when recoverable.
- Extended `bpfverify` attach-type parsing to cover the attach names emitted by
  `bpfget`, and added fail-fast validation for program types that require BTF
  replay metadata.
- Extended `bpfrejit --dry-run` to recover and replay `expected_attach_type`
  from the live program before calling `kernel-sys`.
- Updated daemon target handling so `write_fd_array_from_target()` also writes
  each required kinsn's `call_offset` into `target.json` while producing
  `fd_array.json`.
- Invalidated `BpfProgram::verifier_states` after any pass-manager transform.
  Verifier logs are tied to the current instruction layout, so downstream passes
  must not consume them after a bytecode-changing pass.
- Classified conditional-jump verifier log states as branch-edge deltas and
  excluded them from `verifier_states.json`. Only unconditional instruction
  delta states are serialized for optimizer replay.

## Verification

- `cargo build --manifest-path bpfopt/Cargo.toml`
- `cargo clippy --manifest-path bpfopt/Cargo.toml --all-targets -- -D warnings`
- `cargo build --manifest-path daemon/Cargo.toml`
- `cargo clippy --manifest-path daemon/Cargo.toml --all-targets -- -D warnings`
- `cargo test --manifest-path bpfopt/Cargo.toml --all-targets`
- `cargo test --manifest-path daemon/Cargo.toml --all-targets`

KVM e2e verification:

- Command: `make vm-e2e SAMPLES=1 VM_E2E_SUITE_ARGS=--case\ tracee`
- Result: pending
