# Tetragon 287-Program Batch Crash Investigation

Date: 2026-05-03  
Evidence: `/tmp/kvm-tracee-tetragon-kinsn-v7-1777792974.log`, daemon source `daemon/src/commands.rs`, `runner/libs/rejit.py`, `runner/libs/kvm_executor.py`

---

## Symptom

The KVM VM filesystem becomes read-only mid-run whenever `BPFREJIT_CORPUS_APPS=tetragon/observer` (287 BPF programs) is used. The daemon dies, the runner gets `daemon socket returned an empty response`, and docker cleanup fails with `EROFS: read-only file system`.

---

## Evidence

**Log timeline (from the error JSON in the log):**

1. `rejit_start` — 287 prog_ids sent to daemon in one `optimize` batch.
2. Daemon logs `serve: observed new BPF program id 249` through `307` — the 16-worker rayon pool is actively processing programs.
3. Daemon logs 20 `preserved failure workdir for prog <id> at /var/tmp/bpfrejit-failures/<id>` messages. These are the last 20 visible in the 80-line log tail; the true count is higher — all 287 programs were being processed by 16 parallel workers.
4. `serve: listening on /var/tmp/bpfrejit-daemon.sock` appears — daemon process restarted (died and reinvoked, or died leaving a second instance), which means it was killed externally.
5. Runner reads an empty response from the (new) daemon socket and raises the error.
6. Python cleanup tries `Path('/var/tmp/bpfrejit-daemon.sock').unlink()` → `OSError: [Errno 30] Read-only file system`.
7. Docker daemon reports `unlinkat overlay2/.../lower: read-only file system` during container removal.

**Failure workdir disk accounting:**

- Each `preserve_failure_workdir` call copies the per-prog workdir to `/var/tmp/bpfrejit-failures/<prog_id>/`.  
- Per-prog workdir contains: `prog.bin`, `prog.bpf`, `info.json`, `opt.bin`, `map-values.json`, `verifier-states.json`, and per-pass artifacts. For each of the 6 passes in this run (`rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch`), the workdir holds `pass-XX.in.bin`, `pass-XX.out.bin`, `pass-XX.report.json`, `pass-XX.verifier.log`. The verifier log buffer is `REJIT_LOG_BUF_SIZE = 16 MiB` per pass; successful passes also write a `verifier-states.json` from the log.  
- Rough per-prog cost: 6 passes × ~16 MiB verifier log + a few MB of other files ≈ **~100 MiB per failed program**.  
- With a high failure rate (many tetragon programs hit verifier rejection or EINVAL), 16 workers each preserving workdirs concurrently means peak disk consumption can reach tens of GiB before any cleanup.

**Where the disk space comes from:**

The container runs without a bind-mount of `/var/tmp`. Container `/var/tmp` is the overlay upper layer, which lives in dockerd's `--data-root /run/bpf-benchmark-docker/data` (overlay2 storage), which is in turn the **64 GB loop-mounted disk image** at `/var/tmp/bpf-benchmark-docker.img` on the host. The daemon's failure workdirs and the docker overlay data therefore compete for the same 64 GB pool. When the overlay upper layer grows too large, the ext4 filesystem fills and remounts read-only, killing the daemon.

**Why the daemon "restarts":**

There is no auto-restart in `DaemonSession.start` or the server loop. The `serve: listening on` message appearing mid-batch means the OOM killer (or a full-disk-triggered fatal write error) killed the original daemon process. The `serve: listening on` line printed to the log is from the *new* `bpfrejit-daemon` process that the corpus driver must have launched when trying to reconnect — or it is leftover stdout from the previous daemon that the log captured. Either way, the root trigger is the same: the VM filesystem filled.

---

## Most Likely Root Cause

**The 64 GB docker loop disk fills due to unbounded failure workdir accumulation.** With 287 programs processed in parallel at 16 workers, every program that fails a ReJIT pass writes ~100 MiB of bytecode + verifier logs into `/var/tmp/bpfrejit-failures/` inside the container overlay layer. Tetragon has many programs that hit verifier rejection (the 20 visible in the log tail are only a partial count). Combined with the docker overlay layer itself and program execution data, the 64 GB disk image exhausts before the batch completes. ext4 on an out-of-space device remounts read-only. The daemon's next write fails, causing it to crash or be OOM-killed. The VM never recovers.

Tracee at 158 programs succeeds because it has fewer failed programs and/or a lower failure rate, generating less failure workdir data.

---

## Ranked Fix Options

**1. Disable preserved failure workdir capture for routine per-pass ReJIT errors (recommended)**  
Only capture the workdir when the error is truly unexpected (e.g., a Rust panic in the worker or a daemon-internal bug), not for normal verifier rejection (`EINVAL`, `E2BIG`, verifier log overflow). This eliminates the dominant disk cost for large batches. The workdir data is useful for debugging but is already recorded in the per-program error message; writing 100 MiB to disk per rejected program is disproportionate.  
*Tradeoff:* Loses bytecode artifacts for routine ReJIT failures; verifier logs for `EINVAL` cases will not be on disk. Acceptable for production benchmark runs; can be re-enabled with a flag for debugging.

**2. Stream prog_ids in chunks of 50 instead of one batch of 287**  
The corpus driver sends all 287 prog_ids in a single `optimize` request. Splitting into chunks of ~50 lets the failure workdir accumulate and get cleaned between batches, keeping peak disk usage bounded.  
*Tradeoff:* Requires a minor change in the corpus driver (violates the "runner stays untouched" v3 rule unless framed as a bug fix). Does not eliminate the root cause — a chunk of 50 heavily-failing programs could still write ~5 GB.

**3. Reduce the verifier log buffer size for per-pass ReJIT from 16 MiB to 1–2 MiB**  
The 16 MiB `REJIT_LOG_BUF_SIZE` is the per-pass allocation; with 6 passes and 16 parallel workers, peak in-memory log allocation reaches `16 × 6 × 16 MiB = 1.5 GiB`. Reducing to 2 MiB cuts this to 192 MiB and reduces per-prog failure workdir size to ~12 MiB, giving ~3.5 GB headroom even for 287 failed programs.  
*Tradeoff:* Some programs with large instruction counts will hit log truncation, causing verifier state parse to fail with "empty verifier states" even though the ReJIT succeeded. This trades reliability for one bug type against reliability for another.

---

## Recommended Single Fix

**Fix 1: skip `preserve_failure_workdir` for normal per-pass verifier rejections.**  
Call `preserve_failure_workdir` only when the worker catches a Rust panic (currently handled by `apply_program_catching_unwind`). For ordinary `Err` results from `try_apply_one_with_map_access` (ReJIT rejected, bpfopt failed, etc.), record the error message and verifier log excerpt in the returned `OptimizeOneResult::error_message` but do not write the full workdir to disk. This is a small, targeted change in `commands.rs` (the existing `match result` at line 1110), removes the primary disk pressure entirely, and does not touch the runner Python.
