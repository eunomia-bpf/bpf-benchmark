# Impl Product Config Summary (2026-04-23)

## Scope

- Implemented APP config fixes for Tracee and Katran.
- Kept Tetragon policy pack unchanged; only added workload dispatch for the new mixed workload.
- Added six Y workload variants through the shared `run_named_workload()` path.
- Did not run `vm-e2e` or `vm-corpus`.

## Tracee Command Change

- Before:
  - `tracee --events execve,sched_process_exec,security_file_open,security_socket_connect ...`
  - Source of the old 4-event pin: `docs/tmp/app-attach-undercount-20260423/summary.md` and previous `e2e/cases/tracee/config.yaml`.
- After:
  - `tracee --events all ...`
  - Command assembly still lives in `runner/libs/app_runners/tracee.py:440-445`.
  - Default event source is now `e2e/cases/tracee/config.yaml:1-2`.
  - Tracee runner/e2e load timeout was raised from `20` to `60` seconds in `runner/libs/app_runners/tracee.py:494-496` and `e2e/cases/tracee/case.py:63-67`.
- Expected attach count:
  - `baseline.programs` should move from `37` toward the APP-summary estimate `120-154`.
- Fallback:
  - Not needed. `all` was used directly, with the timeout increase from the summary's safety suggestion.

## Katran Change

- Before:
  - Runner launched `katran_server_grpc ... -balancer_prog=... -intf=... -hc_forwarding=false ...`
  - Observed attach count from APP summary: `1`.
- After:
  - Removed the forced `-hc_forwarding=false`.
  - Added healthchecking program and shared-root wiring in `runner/libs/app_runners/katran.py:477-507`.
  - Host healthcheck tunnel interfaces are created and cleaned up in `runner/libs/app_runners/katran.py:271-358`.
  - Shared `xdp_root` install / pin / detach flow lives in `runner/libs/app_runners/katran.py:819-883`.
  - Runner now resolves all three Katran BPF artifacts and starts the server with healthcheck + root-map arguments in `runner/libs/app_runners/katran.py:886-969`.
  - Teardown now waits for all discovered program ids instead of only one id in `runner/libs/app_runners/katran.py:130-160` and `runner/libs/app_runners/katran.py:1009-1017`.
- Effective command shape now:
  - `katran_server_grpc -balancer_prog=... -healthchecker_prog=... -default_mac=... -intf=... -ipip_intf=ipip0 -ipip6_intf=ipip60 -map_path=<bpffs>/root_array -prog_pos=2 -logtostderr -alsologtostderr`
  - Plus a pre-launch `bpftool prog load/attach` for `xdp_root`.
- Expected attach count:
  - `1 -> 3` (`xdp_root` + `balancer_ingress` + `healthchecking_ipip`), matching the APP summary.
- Note:
  - This source path does not expose a separate extra "stats BPF program"; the practical unlock here is healthcheck plus shared root mode.

## New Workload Variants

- Shared low-level syscall/module helpers were added in `runner/libs/workload.py:25-284`.
- `tetragon_exec_connect_mix`
  - Impl: `runner/libs/workload.py:722-736`
  - Dispatch: `runner/libs/workload.py:1117-1118`
  - Tetragon runner branch: `runner/libs/app_runners/tetragon.py:214-226`
- `tracee_system_edge_mix`
  - Impl: `runner/libs/workload.py:739-760`
  - Dispatch: `runner/libs/workload.py:1135-1136`
  - Tracee runner branch: `runner/libs/app_runners/tracee.py:464-473`
- `tracee_module_load_loop`
  - Impl: `runner/libs/workload.py:763-775`
  - Dispatch: `runner/libs/workload.py:1137-1138`
  - Helper path for candidate selection/load/unload: `runner/libs/workload.py:230-284`
  - Fallback used:
    - Instead of introducing a new test module artifact, this variant cycles existing non-builtin candidate modules from `repo_kernel_modules_root()` via `modprobe`.
- `tracee_io_vector_mix`
  - Impl: `runner/libs/workload.py:778-799`
  - Dispatch: `runner/libs/workload.py:1139-1140`
  - Fallback used:
    - Used direct `read/write/readv/writev/preadv/pwritev` from Python's low-level OS API rather than adding a separate raw `preadv2/pwritev2` syscall shim.
- `open_family_storm`
  - Impl: `runner/libs/workload.py:967-997`
  - Dispatch: `runner/libs/workload.py:1127-1128`
  - Safety behavior:
    - Explicit `open/openat/openat2`; if `openat2` is unavailable, the workload records a note instead of failing immediately.
- `vfs_create_fsync_exact`
  - Impl: `runner/libs/workload.py:1013-1033`
  - Dispatch: `runner/libs/workload.py:1153-1154`

## Macro App Workload Switches

- `bcc/vfsstat`
  - `vfs_create_write_fsync -> vfs_create_fsync_exact`
  - Location: `corpus/config/macro_apps.yaml:37-42`
- `bcc/opensnoop`
  - `file_open_storm -> open_family_storm`
  - Location: `corpus/config/macro_apps.yaml:44-49`
- `tetragon/default`
  - `exec_storm -> tetragon_exec_connect_mix`
  - Location: `corpus/config/macro_apps.yaml:86-90`
- `tracee/default`
  - `tracee_default -> tracee_system_edge_mix`
  - Location: `corpus/config/macro_apps.yaml:98-103`
- No `bpftrace` workload switch was made.
  - The Y summary did not identify a direct `macro_apps.yaml` variant swap for the current bpftrace suite.

## Tetragon Non-Change

- No new `TracingPolicy` objects were added.
- The existing synthetic policy pack remains unchanged.
- Only workload dispatch/import plumbing was extended so `tetragon/default` can use the new mixed workload:
  - `runner/libs/app_runners/tetragon.py:13-20`
  - `runner/libs/app_runners/tetragon.py:214-226`

## Validation

- Passed:
  - `python3 -m py_compile runner/libs/workload.py runner/libs/app_runners/tracee.py runner/libs/app_runners/katran.py runner/libs/app_runners/tetragon.py`
  - `make check`
- Not run:
  - `vm-e2e`
  - `vm-corpus`

## Diff Stat

- Path-filtered to this implementation's touched files:
  - `git diff --shortstat -- runner/libs/workload.py runner/libs/app_runners/tracee.py runner/libs/app_runners/katran.py runner/libs/app_runners/tetragon.py corpus/config/macro_apps.yaml e2e/cases/tracee/config.yaml e2e/cases/tracee/case.py`
  - Result: `7 files changed, 746 insertions(+), 57 deletions(-)`
- Full worktree status is larger because unrelated pre-existing edits were present in forbidden/out-of-scope files (`corpus/driver.py`, `runner/libs/rejit.py`, `daemon/*`, and other docs paths), and those were left untouched.
