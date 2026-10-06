# Tetragon Upstream Policies Round 9 Report

## 1. Inputs

- Required local context read first:
  - `docs/kernel-jit-optimization-plan.md`
  - `docs/tmp/tetragon-revert-20260423/summary.md`
  - `docs/tmp/app-attach-undercount-20260423/summary.md`
  - `runner/containers/runner-runtime.Dockerfile`
  - `runner/libs/app_runners/tetragon.py`
- `docs/tmp/round8-vm-smoke-20260423/summary.md` does not exist in this checkout. I used `docs/tmp/commit-round8-20260423/summary.md` as the closest available Round 8 status summary instead.

## 2. Download Method

- No full `git clone`.
- Helper added: `e2e/cases/tetragon/sync_upstream_policies.sh`
- Transport: `curl` against pinned raw GitHub URLs under:
  - `https://raw.githubusercontent.com/cilium/tetragon/38a65437a875246d31e13347ebf6a3c0184d4b6b/examples/tracingpolicy/...`
- Pinned upstream ref:
  - SHA: `38a65437a875246d31e13347ebf6a3c0184d4b6b`
  - Commit date: `2026-04-23T11:46:56Z`
  - Subject: `Fix null spec.{pod, container, host}Selectors`

## 3. Retained Policies

- Retained set: `18` real upstream policies under `e2e/cases/tetragon/policies/`
- Exact retained files:
  - `bpf.yaml`
  - `datagram-with-sock-tracking.yaml`
  - `datagram_518.yaml`
  - `fd_install_cap_changes.yaml`
  - `filename_monitoring.yaml`
  - `host-changes/monitor-kernel-modules.yaml`
  - `list-syscalls-tracepoint.yaml`
  - `process-credentials/process-creds-changed.yaml`
  - `process-exec/process-exec-elf-begin.yaml`
  - `raw_syscalls.yaml`
  - `rawtp.yaml`
  - `security-socket-connect.yaml`
  - `security_inode_follow_link.yaml`
  - `stack_traces.yaml`
  - `sys_mount.yaml`
  - `tcp-accept.yaml`
  - `tcp-connect-with-selectors.yaml`
  - `tty.yaml`
- Static pack census:
  - YAML files: `18`
  - kprobes: `38`
  - tracepoints: `3`
  - duplicate `metadata.name`: `0`

## 4. Filtering Rules

- Skipped because they change system behavior instead of pure observe:
  - `cves/cve-2023-2640-overlayfs-ubuntu.yaml`
  - `dns-only-specified-servers.yaml`
  - `hardlink-override.yaml`
  - `modules-nohost.yaml`
  - `override-security.yaml`
  - `security-socket-connect-block-others.yaml`
  - `symlink-override.yaml`
  - `tcp-connect-only-local-addrs.yaml`
  - `tcp-connect-only-private-addrs.yaml`
- Skipped because they depend on LSM, uprobes, or other user-space hook families that are more fragile for this VM-host runner path:
  - `lsm_bprm_check.yaml`
  - `lsm_file_open.yaml`
  - `lsm_track_grandparent.yml`
  - `uprobe-binaries.yaml`
  - `uprobe-host.yaml`
  - `uprobe-pid.yaml`
  - `uprobe.yaml`
- Skipped because they depend on specific binaries or ambiguous helper behavior:
  - `cves/cve-2024-3094-xz-ssh.yaml`
  - `killer.yaml`
  - `list-generated-ftrace.yaml`
  - `list-syscalls-generated.yaml`
  - `open_dnsrequest.yaml`
  - `open_geturl.yaml`
  - `security_bprm_check.yaml`
- Skipped because they are not useful to bulk-load as startup policies here:
  - `loader.yaml`
  - `usdt.yaml`
  - `usdt-set.yaml`
- Skipped even though technically observable because they collide on duplicate `metadata.name` with a higher-value retained policy:
  - `datagram-with-selectors.yaml`
  - `datagram.yaml`
  - `fd_install_caps.yaml`
  - `filename_monitoring_filtered.yaml`
  - `kprobe_commit_creds.yaml`
  - `list-syscalls.yaml`
  - `process-credentials/creds-capability-usage.yaml`
  - `process-credentials/process-creds-installed.yaml`
  - `sys_clock_settime.yaml`
  - `sys_ptrace.yaml`
  - `sys_setuid.yaml`
  - `symlink-observe.yaml`
  - `tcp-connect.yaml`
  - `tty_54.yaml`
  - `write.yaml`
- Skipped for kernel-version fragility:
  - `host-changes/monitor-signed-kernel-modules.yaml`
  - Reason: the upstream file comments that `find_module_sections` may be inlined on some kernels.

## 5. Expected Program Count

- Reference model came from `docs/tmp/app-attach-undercount-20260423/summary.md` on `2026-04-23`.
- That note modeled Tetragon as:
  - base built-ins: about `8`
  - generic kprobe expansion: about `7` programs per kprobe hook
  - generic tracepoint expansion: about `6` programs per tracepoint hook
- With the retained pack:
  - `8 + 38*7 + 3*6 = 292`
- This clears the `200+` target with margin while avoiding the much larger `500+` hook pack that would result from bulk-loading every host-compatible upstream example.

## 6. Integration

- Runner change:
  - `runner/libs/app_runners/tetragon.py` now resolves `ROOT_DIR/e2e/cases/tetragon/policies` and injects `--tracing-policy-dir`.
  - Missing policy directory or empty policy directory is now a hard failure.
- Runtime image change:
  - `runner/containers/runner-runtime.Dockerfile` now explicitly copies `e2e/cases/tetragon/policies` into the image workspace before the full `e2e/cases` sync.
  - The Docker build now also asserts that at least one YAML exists under `./e2e/cases/tetragon/policies`.
- No `build.mk` change was needed because the existing runtime image dependency tracking already covers `e2e/**`.

## 7. Verification

- `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
  - `exit 0`
- `source /home/yunwei37/workspace/.venv/bin/activate && make check`
  - `exit 0`
- `source /home/yunwei37/workspace/.venv/bin/activate && make -n vm-e2e`
  - output: `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`
- `source /home/yunwei37/workspace/.venv/bin/activate && make -n aws-e2e RUN_TARGET_ARCH=x86_64`
  - output: `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run aws-x86 e2e`
- Not run on a real VM in this turn:
  - user explicitly prohibited `make vm-*`
  - a separate codex session was already iterating VM verification

## 8. AWS Path

- The retained policies are part of the built runtime image, not a host bind mount.
- Runtime resolution path inside the image remains repo-relative:
  - `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/policies`
- `make -n aws-e2e RUN_TARGET_ARCH=x86_64` stayed valid after the image change, so the AWS path will carry the same static policy pack.

## 9. Diff Stat

- Entity changes before this docs commit (`git diff --shortstat HEAD~2..HEAD`):
  - `21 files changed, 782 insertions(+), 1 deletion(-)`
