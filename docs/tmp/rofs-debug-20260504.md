# Tetragon ROFS Debug Notes

Date: 2026-05-04

Scope: read-only investigation of the 3-app kop-only corpus run that produced
`corpus/results/x86_kvm_corpus_20260504_003830_701212/`. No source code or build
artifacts were changed.

## Executive Summary

The read-only filesystem was caused by Docker's loop-backed ext4 filesystem
receiving write I/O errors, then aborting its journal. The first hard evidence is
not the daemon socket unlink failure; it is the kernel console showing `loop0`
space allocation failures around 688s and an ext4 journal abort around 690s.

The dominant write source is the daemon per-program workdir under container
`/var/tmp`, especially per-pass verifier logs. Failure artifacts and daemon
stderr are small in this run. `WorkDir` already has RAII-style cleanup, but the
workdir lives until each program finishes; with 16 worker threads and tetragon's
287 programs, concurrent successful-pass verifier logs can consume tens of GiB
before cleanup has a chance to run. Once ext4 becomes read-only, the cleanup path
itself also fails.

Recommended fix: stop writing full successful per-pass verifier logs to disk
(or delete them immediately after parsing verifier states), and put daemon
scratch storage/Docker backing storage on disk-backed capacity instead of guest
tmpfs. Increasing only `BPFREJIT_VM_DOCKER_DISK_SIZE` is not sufficient because
the default disk image is created inside guest `/var/tmp` tmpfs.

## Evidence

### Host Disk and Docker Image

Host-side checks:

- `ls -la /var/tmp/bpf-benchmark-docker.img` returned `No such file or directory`.
- `df -h / /var/tmp /tmp` showed host `/dev/nvme0n1p2` at `915G`, `759G` used,
  `110G` available (`88%`). Host root was not full.
- `/run/bpf-benchmark-docker` did not exist after the VM exited.

This is consistent with the KVM executor creating the Docker disk from inside the
guest and removing it in the guest cleanup trap. The script default is:

- `docker_disk="${BPFREJIT_VM_DOCKER_DISK:-/var/tmp/bpf-benchmark-docker.img}"`
- `docker_disk_size="${BPFREJIT_VM_DOCKER_DISK_SIZE:-64G}"`
- `truncate -s "$docker_disk_size" "$docker_disk"`
- `mkfs.ext4 -F -q "$docker_disk"`
- `mount -o loop "$docker_disk" "$docker_root"`

Source: `runner/libs/kvm_executor.py:26-73`.

The console confirms the logical size: `/tmp/vng-pty-log.vcol9629:433-434`
shows `loop0: detected capacity change from 0 to 134217728` and ext4 mounted
read/write. `134217728 * 512` bytes is exactly 64 GiB.

### Guest and Container Mount Chain

The VM command used `--mem 64G` and `--overlay-rwdir /tmp`:

`/tmp/vng-pty-log.vcol9629:1`

`virtme-init` creates overlay upper/work dirs under `/run/tmp/...` and also
mounts `/var/tmp` as tmpfs without an explicit size:

- `/home/yunwei37/.local/lib/python3.12/site-packages/virtme/guest/virtme-init:29-35`
- `/home/yunwei37/.local/lib/python3.12/site-packages/virtme/guest/virtme-init:92`

Linux tmpfs defaults to a max size of about half system RAM, so with `--mem 64G`
guest `/var/tmp` has roughly a 32G ceiling unless overridden.

The runtime container does not bind-mount `/var/tmp`. It bind-mounts results,
`/sys`, `/sys/fs/bpf`, `/sys/kernel/debug`, `/lib/modules:ro`, and `/boot:ro`;
container `/var/tmp` therefore goes to Docker overlay2, backed by dockerd's
`--data-root /run/bpf-benchmark-docker/data`, which is the `loop0` ext4 image.

Source: `runner/libs/suite_commands.py:122-153`.

Net effect:

`daemon workdir -> container /var/tmp -> Docker overlay2 -> loop0 ext4 -> guest /var/tmp tmpfs backing file`.

### Failure Timeline

Kernel console:

- `687.941988`: `critical space allocation error, dev loop0 ... WRITE`
- `687.943147`: ext4 I/O error writing to `loop0`
- `687.945414`: failed to convert unwritten extents, potential data loss
- `690.325302`: `Aborting journal on device loop0-8`
- `690.335159+`: repeated `ext4_journal_check_start ... comm bpfrejit-worker: Detected aborted journal`

Source: `/tmp/vng-pty-log.vcol9629:484-534`.

Downstream symptoms after the journal abort:

- stress-ng cannot create a runtime tmpdir:
  `/var/tmp/bpfrejit-runtime/.../tmp-stress-ng-aio-...`, errno 30.
- tracee cannot create its app dir under `/var/tmp/bpfrejit-runtime/.../tracee`.
- Python cleanup cannot unlink `/var/tmp/bpfrejit-daemon.sock`.
- Docker cleanup cannot remove overlay2 files and reports read-only filesystem.

Sources:

- `/tmp/vm-corpus-3apps-jit-mutex-1777854230.log:3383-3406`
- `/tmp/vng-pty-log.vcol9629:544-567`

Daemon stderr also shows cleanup after the damage:

- `daemon: failed to remove work directory ... Read-only file system`
- `Error: remove stale socket file /var/tmp/bpfrejit-daemon.sock`

Source: `corpus/results/x86_kvm_corpus_20260504_003830_701212/details/daemon.stderr.log:2430-2455`.

### Disk Consumers

Current result artifacts are not the culprit:

- `details/`: `2.7M`
- `details/failures/`: `480K`
- `daemon.stderr.log`: `156K`, `2455` lines
- `/tmp/vng-pty-log.vcol9629`: `48K`, `571` lines

The bounded socket-based failure artifacts are working in this run: the largest
current failure files are about 4-5 KiB each.

Historical full artifacts are large:

- `corpus/results/failures`: `8.3G`
- old full verifier logs include examples near 256 MiB.

The still-large transient source is daemon workdir content. `WorkDir::new()` uses
`std::env::temp_dir()` and creates paths like
`bpfrejit-daemon-optimize-<pid>-<id>` under `TMPDIR`; the corpus runtime sets
`TMPDIR` to `/var/tmp/bpfrejit-runtime/<token>` if unset.

Sources:

- `daemon/src/commands.rs:64-78`
- `runner/suites/_common.py:181-221`

Each optimized program writes:

- base files: `prog.bin`, `info.json`, `target.json`, `verifier-states.json`,
  `map-values.json`, `opt.bin`, `bpfrejit_summary.json`
- per pass: `<stem>.in.bin`, `<stem>.out.bin`, `<stem>.report.json`,
  `<stem>.verifier.log`

Sources:

- `daemon/src/commands.rs:737-744`
- `daemon/src/commands.rs:843-846`

The bytecode and report files are usually KiB to MiB scale. The verifier log is
the high-risk file:

- daemon starts with `REJIT_LOG_BUF_SIZE = 16 * 1024 * 1024`
- `kernel_sys::prog_rejit_with_log_buf()` doubles on log `ENOSPC` up to 256 MiB
- `rejit_program()` writes the full verifier log to `<stem>.verifier.log` on
  both success and failure, then parses verifier states from it

Sources:

- `daemon/src/commands.rs:34`
- `daemon/src/commands.rs:294-313`
- `bpfopt/crates/kernel-sys/src/lib.rs:43`
- `bpfopt/crates/kernel-sys/src/lib.rs:1431-1480`

Rough peak estimate for tetragon:

- Ordinary case: `12 passes * 16 MiB ~= 192 MiB` of verifier logs per active
  program workdir.
- Worst observed class: `12 passes * 256 MiB ~= 3 GiB` per active program.
- With 16 daemon workers, live verifier-log scratch can range from a few GiB to
  well above the guest `/var/tmp` tmpfs ceiling before any per-program `Drop`
  cleanup runs.

This is enough to explain loop0 backing allocation failure even though the ext4
image advertises 64G logical capacity.

## Root Cause

The Docker ext4 image is 64G logically, but its sparse backing file is created in
guest `/var/tmp`, which is tmpfs-sized around 32G for this 64G VM. Tetragon's
large parallel ReJIT batch writes many full verifier logs through the Docker
overlay into that loop image. The backing tmpfs can no longer allocate pages,
the loop device returns write I/O errors, ext4 aborts its journal, and everything
above it observes `EROFS`.

The socket path turning read-only is a late symptom, not the trigger.

## Fix Options

### 1. Delete or Avoid Full Successful Verifier Logs

Best fix. Keep verifier log in memory long enough to parse verifier states, then
write only a bounded summary or only failure artifacts. Alternatively, delete
`<stem>.verifier.log`, stale `<stem>.in.bin`, and stale `<stem>.out.bin`
immediately after the next pass no longer needs them.

Expected code area:

- `daemon/src/commands.rs:285-327`
- `daemon/src/commands.rs:843-935`
- failure artifact helpers around the existing bounded summaries

Estimated size: 40-120 LOC plus focused tests.

Why: fixes the dominant disk consumer directly and keeps the existing bounded
socket artifact behavior.

### 2. Put Daemon Scratch on Disk-Backed Storage

Add a runtime-container mount for a host/guest disk-backed scratch directory and
set `TMPDIR` or a dedicated `BPFREJIT_DAEMON_TMPDIR` to that path. Do not rely on
container overlay2 for daemon scratch.

Expected code area:

- `runner/libs/suite_commands.py`
- `runner/libs/kvm_executor.py`
- env wiring in `runner/suites/_common.py` if a new variable is introduced

Estimated size: 15-50 LOC.

Why: reduces overlay pressure and makes scratch capacity explicit. This is a
good companion to option 1, not a substitute for unbounded logs.

### 3. Move Docker Disk Backing off Guest tmpfs

If keeping Docker loop storage, make `BPFREJIT_VM_DOCKER_DISK` point to a
disk-backed path visible in the guest, or avoid the loop image when dockerd can
use a sufficiently large disk-backed data-root.

Estimated size: 10-40 LOC/config change depending on how this is exposed.

Why: fixes the 64G logical image over 32G tmpfs mismatch. Still needs scratch/log
bounding because 287 programs can fill any fixed pool eventually.

### 4. Increase VM Memory

Raising `--mem` from 64G to 128G would raise the default `/var/tmp` tmpfs ceiling
from roughly 32G to roughly 64G.

Why not sufficient: it is a capacity workaround, not a bound. With 16 workers and
large verifier logs, the workload can still hit the new ceiling.

### 5. Increase Docker Loop Image Size

Only useful after moving the backing file to disk-backed storage or increasing
the tmpfs ceiling. Increasing `BPFREJIT_VM_DOCKER_DISK_SIZE` from 64G to 128G or
256G while the backing file remains in guest `/var/tmp` does not fix the actual
allocation failure.

### 6. Reduce Daemon Trace

Low impact for this failure. Current `daemon.stderr.log` is only 156K. It is
reasonable cleanup, but it will not prevent ROFS.

### 7. "Make WorkDir RAII"

Already true. `Drop` calls `fs::remove_dir_all()` on the workdir
(`daemon/src/commands.rs:85-93`). The issue is peak live data before drop, plus
cleanup being impossible after ext4 has already gone read-only.

## Recommendation

Implement option 1 first, then option 2 or 3 for explicit scratch capacity.
Do not treat a larger Docker image alone as the fix.
