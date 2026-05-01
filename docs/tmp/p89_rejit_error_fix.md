# P89 ReJIT Error Fix

Date: 2026-05-01

## Root Cause

`bpfget --full` paired fork-recovered original bytecode with live BTF func/line metadata that can refer to offsets in a different instruction layout. `bpfverify --verifier-states-out` then replayed those records during original verifier-state capture, and the kernel rejected malformed `line_info` before verifier execution.

This is not a PrefetchV2 pass bug and not a PostAudit retry regression. The failing path runs before `bpfopt optimize`; the malformed metadata already exists in saved pre-PrefetchV2 workdirs.

## Fix

- `bpfget --full` now normalizes BTF metadata against the exact `prog.bin` it writes.
- `line_info` keeps only records whose `insn_off` targets an in-range real instruction (`code != 0`), dropping `ldimm64` second slots and end/out-of-range records.
- `func_info` is kept only when the subprogram layout is complete, strictly increasing, starts at 0, and targets real instructions; otherwise it is cleared because partial func_info can violate the kernel's subprogram metadata contract.
- `prog_info.json` now reports the post-normalization `nr_func_info` and `nr_line_info` counts.
- Daemon original verifier-state capture now uses the structured `bpfverify` report path and writes `verifier.log`, so future verifier-state failures preserve a useful workdir instead of failing preservation due to a missing log alias.

## Validation

Rust:

- `cd bpfopt && cargo check --workspace`
- `cd bpfopt && cargo test --workspace --release`
- `cd bpfopt && cargo build --release --workspace`
- `cd daemon && cargo build --release`
- `cd daemon && cargo test --release`

Host-side saved-workdir checks:

- `bcc/execsnoop` prog 9 line_info: `251 -> 229`, remaining invalid targets `0`.
- Saved debug corpus scan: 314 workdirs had bad line_info before normalization, 0 after; 82 had invalid func_info layouts before normalization, 0 after clearing inconsistent layouts.
- `sudo -n bpfverify` accepted the saved execsnoop bytecode with dummy maps and host BTF id 1: status `pass`, 516 instructions, 295 verifier states.

I did not run `make vm-corpus` or `make vm-e2e`.
