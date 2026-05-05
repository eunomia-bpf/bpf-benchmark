# Daemon Failure Tar, 2026-05-05

Used a hand-written table base64 encoder in `daemon/src/commands.rs` so no Rust crate dependency was added; Python uses stdlib `base64` to decode. The daemon now serializes `OptimizeOneResult.workdir_tar_b64` at `daemon/src/commands.rs:128`, builds `tar -czf - -C <workdir> .` at `daemon/src/commands.rs:308`, and attaches the tar before `WorkDir::drop` at `daemon/src/commands.rs:619`; `daemon/src/server.rs:293` only needed the existing test fixture field.

Runner persistence is in `runner/libs/rejit.py:234`, the `failure_artifacts_dir` parameter is accepted at `runner/libs/rejit.py:348`, per-program payloads are popped and written/extracted at `runner/libs/rejit.py:401`, and `DaemonSession.apply_rejit` forwards the destination at `runner/libs/rejit.py:468`. Code LoC delta before this note: `+92/-4`; verification: daemon release build passed, daemon release tests passed `23/23`, and bpfopt release build passed.
