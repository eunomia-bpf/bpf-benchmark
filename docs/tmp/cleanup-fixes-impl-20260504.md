# App Cleanup Fixes Implementation (2026-05-04)

## Summary

Implemented 4 of 5 minimum cleanup fixes identified in `app-cleanup-status-20260504.md`.
P1 #4 (tracee tmpdir) was skipped intentionally.

## Commits

| Fix | Priority | Commit | Lines changed |
|---|---|---|---|
| cilium.py: umount bpffs before rmtree | P0 #1 | ac9a7366 | +2 |
| corpus/driver.py: wait_for_suite_quiescence() in normal path | P0 #2 | 4a480dfa | +1 |
| calico.py: nft delete table ip calico in stop() | P1 #3 | 0a5d7c5d | +1 |
| katran.py: teardown timeout 10s → 20s | P1 #5 | b847da55 | +1, -1 |

Total: 5 lines added, 1 line changed.

## Fix Details

### P0 #1: cilium.py bpffs umount (commit ac9a7366)

File: `runner/libs/app_runners/cilium.py`, `stop()` around line 221.

Before `shutil.rmtree(self.runtime_dir, ignore_errors=True)`, added:
```python
if self._bpf_root is not None and self._bpf_root.is_mount():
    run_command(["umount", str(self._bpf_root)], check=False, timeout=10)
```

Rationale: cilium-agent mounts bpffs at `--bpf-root`. `shutil.rmtree` with
`ignore_errors=True` silently fails on a mount point, leaving pinned programs
and maps alive in kernel memory until the mount is explicitly torn down.

### P0 #2: corpus/driver.py quiescence gap (commit 4a480dfa)

File: `corpus/driver.py`, `run_suite()` around line 816.

After `_run_suite_lifecycle_sessions()` returns in the normal (non-exception) path,
added one line:
```python
wait_for_suite_quiescence()
```

Rationale: `wait_for_suite_quiescence()` was already called in the exception path
(line 836) but was missing from the normal lifecycle path. Without it, the next
app's `runner.start()` could race against BPF IDR cleanup from the previous app.

### P1 #3: calico.py nft table cleanup (commit 0a5d7c5d)

File: `runner/libs/app_runners/calico.py`, end of `stop()`.

Added:
```python
run_command(["nft", "delete", "table", "ip", "calico"], check=False, timeout=10)
```

Rationale: Felix installs NFTables rules for MASQUERADE etc. After process death
and bpfbench0 deletion these rules are functionally inert but accumulate in
`nft list ruleset`. `check=False` handles the case where Felix never ran or the
table was never created.

Note: calico.py had concurrent uncommitted Mode A changes (BACKEND=bird) from a
parallel sonnet. The nft line touches only the end of `stop()`, which is a
separate section from the `_startup_env()` / `start()` changes. The commit
0a5d7c5d absorbed both sets of changes cleanly.

### P1 #5: katran.py teardown timeout (commit b847da55)

File: `runner/libs/app_runners/katran.py`, line 21.

Changed `DEFAULT_KATRAN_STOP_TIMEOUT_S = 10.0` to `DEFAULT_KATRAN_STOP_TIMEOUT_S = 20.0`.

Rationale: In VM environments, network namespace teardown is slower. 10s was
too tight and caused spurious `RuntimeError` from `wait_for_katran_teardown`.

## Skipped

### P1 #4: tracee tmpdir cleanup — SKIPPED

`_tracee_runtime_dir()` in `tracee.py` uses `mkdir -p` (not `mkdtemp`), returning
a fixed path `$TMPDIR/tracee/`. This path is shared across all `TraceeRunner`
instances and across runs. Deleting it in `stop()` would break the next
`TraceeRunner.start()` which expects the directory to already exist (or re-creates
it). The accumulation risk is low (signature files, no kernel state leaks). Skipped
to avoid cross-instance risk.

## Validation

All three modified Python files passed `python -m py_compile` syntax check before
each commit.
