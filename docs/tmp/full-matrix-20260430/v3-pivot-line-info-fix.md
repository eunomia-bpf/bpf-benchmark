# v3 Pivot BTF line_info Fix

Date: 2026-05-01

## Failure

After commit `9bbd56f8` pivoted `bpfget`, `bpfverify`, and `bpfrejit` into daemon-owned in-process libraries, the x86 KVM corpus regressed in bcc:

- `bcc/execsnoop`
- `bcc/bindsnoop`

The verifier rejected ReJIT replay with:

```text
Invalid insn code at line_info[35].insn_off
```

The preserved `bcc/execsnoop` failure fixture shows the same signature:

- program: `syscall__execve`
- original bytecode: 516 instructions
- raw line_info records: 251
- invalid line_info targets against the replay bytecode: 22
- first invalid target: `line_info[35].insn_off = 95`

## UAPI Check

`vendor/linux-framework/include/uapi/linux/bpf.h` defines `struct bpf_line_info` with:

```c
__u32 insn_off;
```

The verifier treats `insn_off` as an instruction index, not a byte offset. `kernel/bpf/verifier.c` indexes `prog->insnsi[linfo[i].insn_off]` while validating line info. The byte-to-index conversion is used by relocation/core logic, not by `BPF_PROG_LOAD` line_info validation.

## Root Cause

The pivot removed the old `bpfget` subprocess boundary but also dropped the old BTF record normalization that had been added for corpus replay.

That normalization is still needed because the daemon snapshot combines two kernel views:

- bytecode comes from `BPF_PROG_GET_ORIGINAL`, which returns the original instruction stream captured before verifier rewrites;
- BTF records come from `BPF_OBJ_GET_INFO_BY_FD`, where line_info has already followed kernel verifier adjustments such as removed or rewritten instructions.

For programs like bcc `execsnoop`, some returned line_info entries point at the second slot of an `ldimm64` or another non-instruction slot when replayed against `BPF_PROG_GET_ORIGINAL` bytecode. Refeeding those records to dry-run `BPF_PROG_LOAD` makes the verifier reject before normal pass verification can happen.

This was not a stale-program bug and not a byte-vs-index conversion bug. It was a lost replay normalization step in the new in-process path.

## Fix

`daemon/crates/bpfget/src/lib.rs` now normalizes BTF metadata immediately after reading original bytecode and BTF records:

```text
prog_get_original -> prog_btf_info -> normalize map immediates -> normalize func_info/line_info
```

The normalization is deterministic and local to replay metadata:

- `func_info` is preserved only when its function offsets match the replay bytecode subprogram layout.
- `line_info` records are preserved when `insn_off` indexes a real instruction in the replay bytecode.
- line_info must still cover every function entry required by `func_info` or the bytecode's pseudo-call layout.
- malformed record sizes and impossible pseudo-call targets remain hard errors.

No ReJIT program is filtered or skipped. The fix changes only the BTF metadata passed to verifier dry-run and final ReJIT replay so that it is consistent with the replay bytecode.

## Regression Tests

Added focused unit coverage in `bpfget`:

- synthetic `ldimm64` second-slot line_info target is dropped;
- preserved bcc/bindsnoop prog 13 line_info replays unchanged against the fixture bytecode;
- preserved bcc/execsnoop failure fixture reproduces `line_info[35].insn_off = 95`, normalizes 251 records to 229 records, and verifies that every remaining record targets a real instruction.

The preserved fixtures are embedded as raw `prog.bin`, `line_info.bin`, and `func_info.bin` bytes in the test module. The tests intentionally validate the record layout against real bytecode without mocking kernel behavior.

## Host Verification

Allowed host verification run by Codex:

```text
cargo test --workspace --manifest-path daemon/Cargo.toml
cargo test --workspace --manifest-path bpfopt/Cargo.toml
make daemon-tests
make check
```

Results:

```text
daemon workspace: passed
bpfopt workspace: passed
make daemon-tests: passed
make check: passed; vm-test reported 27 passed, 0 failed, fuzz 1000 rounds passed
```

The repository root does not contain a `Cargo.toml`, so bare `cargo test --workspace` fails before test discovery. Both actual Rust workspaces were tested explicitly with their manifest paths.

Codex did not run:

```text
make vm-corpus
make vm-e2e
make vm-micro
```

Those VM targets remain Claude-side validation.
