# v3 Architecture Pivot: daemon-owned kernel CLIs

Date: 2026-05-01

## Motivation

The original v3 implementation made the daemon fork+exec `bpfget`, `bpfopt`, `bpfverify`, and `bpfrejit`, then stitched state back together with stdin/stdout plus JSON/files (`prog_info`, map fd bindings, fd_array, BTF side files, verifier-state output, replay reports).

The 7-round corpus repair history showed that this boundary was the dominant defect source:

- multi-map relocation needed to reconstruct resolved kernel map pointers from serialized map bindings;
- BTF func_info/line_info had to survive side-file handoff and reuse;
- verifier-state subprocess timeout/ramp logic amplified Tetragon into outer VM timeouts;
- failure artifacts depended on subprocess output files that could be truncated by timeout/SIGKILL;
- workload routing bugs were made harder to diagnose because daemon subprocess failures hid the real stage boundary.

The isolation benefit was lower than the protocol cost. `bpfget`, `bpfverify`, and `bpfrejit` all fundamentally call BPF syscalls and naturally need the same process fd table. Keeping them in the daemon removes fd reopening and JSON reconstruction without changing the kernel ABI.

## Decision

- Keep `bpfopt` as a standalone CLI. It remains the pure bytecode transformer and reads/writes raw `struct bpf_insn[]` on stdin/stdout.
- Keep `bpfprof` as a standalone CLI. PMU/per-site profiling remains an independent tool.
- Move `bpfget`, `bpfverify`, and `bpfrejit` into the daemon workspace as daemon-owned library crates.
- Preserve the runner socket + JSON boundary. `runner/libs/`, `corpus/`, `e2e/`, and `micro/` are not refactored for this pivot.
- Preserve the kernel syscall ABI. `BPF_PROG_REJIT` still uses the fd-array ABI; the fd array is now built from daemon-owned fds.

## New Architecture

```text
runner Python
  |
  | Unix socket JSON
  v
bpfrejit-daemon
  |
  | in-process: bpfget::snapshot_program()
  |   - original bytecode
  |   - prog info / map ids
  |   - daemon-owned map fds
  |   - BTF func_info / line_info
  |
  | fork+exec: bpfopt pass/optimize
  |   stdin:  raw struct bpf_insn[]
  |   stdout: raw struct bpf_insn[]
  |   files:  target/profile/verifier-states/map-values/report
  |
  | in-process: bpfverify::verify_pass()
  |   - dry-run load with in-memory metadata
  |   - verifier states captured without subprocess output protocol
  |
  | in-process: bpfrejit::rejit_program()
  |   - final BPF_PROG_REJIT
  |   - fd_array built from daemon-owned fds
  v
kernel
```

## Removed Protocols

- `bpfget` subprocess for live program discovery.
- `bpfverify` subprocess for dry-run verification and verifier-state capture.
- `bpfrejit` subprocess for final ReJIT.
- map fd binding JSON between kernel-facing tools.
- fd_array JSON between verification/ReJIT stages.
- program info JSON as the authoritative in-process contract.
- replay report file protocol for `bpfverify`.
- subprocess timeout/ramp logic for kernel-facing stages.

`bpfopt` side files remain by design because `bpfopt` is still a CLI with file side-inputs and side-outputs.

## Code Changes

- `bpfopt/crates/bpfget` moved to `daemon/crates/bpfget` and converted from CLI to `ProgramSnapshot` library.
- `bpfopt/crates/bpfverify` moved to `daemon/crates/bpfverify` and converted from CLI to `VerifyRequest` / `VerifyReport` library.
- `bpfopt/crates/bpfrejit` moved to `daemon/crates/bpfrejit` and converted from CLI to `rejit_program()` library.
- `daemon/src/commands.rs` now calls those libraries in-process and only spawns `bpfopt` / `bpfprof`.
- Docker/build rules now install only `bpfopt`, `bpfprof`, and `bpfrejit-daemon` as runtime binaries.
- `make daemon-tests` now tests the daemon workspace, including daemon-owned kernel libraries.

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

Codex must not run:

```text
make vm-corpus
make vm-e2e
make vm-micro
```

## Claude VM Handoff

Please run the VM matrix from a clean post-commit tree:

```bash
make vm-corpus
```

Focus checks:

- No `bpfget`, `bpfverify`, or `bpfrejit` binary should be required in the runtime image.
- Calico/Cilium should no longer fail due to the previously fixed namespaced `wrk` path.
- Tetragon should no longer spend `program_count * verifier-state timeout` in subprocess retry/ramp logic.
- ReJIT attempts must still cover every program; failures should surface as per-program errors, not filtering.
- If a verifier/ReJIT error occurs, inspect daemon failure artifacts and stderr; there should be no replay script requirement for a missing subprocess report.

After corpus, run `vm-e2e` and `vm-micro` only from Claude side if needed for the final matrix. Codex intentionally did not run those VM targets.
