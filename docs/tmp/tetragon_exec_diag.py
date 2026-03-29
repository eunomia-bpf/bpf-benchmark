#!/usr/bin/env python3
from __future__ import annotations

import json
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

sys.path.insert(0, '/home/yunwei37/workspace/bpf-benchmark')
from runner.libs.metrics import enable_bpf_stats, sample_bpf_stats  # noqa: E402

TARGETS = ("execve_rate", "execve_send", "event_execve")

TRACEPOINT_POLICY = """
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
metadata:
  name: bpf-benchmark-tetragon-e2e-tracepoint
spec:
  tracepoints:
    - subsystem: syscalls
      event: sys_enter_execve
""".strip() + "\n"

KPROBE_POLICY = """
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
metadata:
  name: bpf-benchmark-tetragon-e2e-kprobes
spec:
  kprobes:
    - call: security_bprm_check
      syscall: false
    - call: security_file_open
      syscall: false
    - call: tcp_connect
      syscall: false
""".strip() + "\n"


def run(command: list[str], *, check: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=check, text=True, capture_output=True)


def current_target_programs() -> dict[str, dict[str, object]]:
    payload = json.loads(run(["bpftool", "-j", "-p", "prog", "show"]).stdout)
    programs = [dict(item) for item in payload if isinstance(item, dict)]
    by_name = {
        str(item.get("name") or ""): item
        for item in programs
        if str(item.get("name") or "") in TARGETS
    }
    ids = [int(item.get("id", 0) or 0) for item in by_name.values()]
    stats = sample_bpf_stats(ids)
    merged: dict[str, dict[str, object]] = {}
    for name, item in by_name.items():
        merged[name] = dict(item)
        prog_id = int(item.get("id", 0) or 0)
        merged[name].update(stats.get(prog_id, {}))
    return merged


def wait_for_targets(timeout_s: float = 20.0) -> dict[str, dict[str, object]]:
    deadline = time.time() + timeout_s
    last = {}
    while time.time() < deadline:
        last = current_target_programs()
        if set(TARGETS).issubset(last):
            return last
        time.sleep(1.0)
    return last


def print_snapshot(label: str, before: dict[str, dict[str, object]], after: dict[str, dict[str, object]]) -> None:
    print(f"== {label} ==")
    for name in TARGETS:
        current = after.get(name)
        previous = before.get(name, {})
        if current is None:
            print(f"{name}: missing")
            continue
        run_cnt = int(current.get("run_cnt", 0) or 0)
        run_time_ns = int(current.get("run_time_ns", 0) or 0)
        delta_cnt = run_cnt - int(previous.get("run_cnt", 0) or 0)
        delta_time = run_time_ns - int(previous.get("run_time_ns", 0) or 0)
        print(
            f"{name}: id={current.get('id')} type={current.get('type')} "
            f"run_cnt={run_cnt} delta_run_cnt={delta_cnt} "
            f"run_time_ns={run_time_ns} delta_run_time_ns={delta_time}"
        )
    print()


def run_exec_storm(*, cgroup_path: Path | None = None) -> None:
    stress_ng = shutil.which("stress-ng") or "/bin/stress-ng"
    setpriv = shutil.which("setpriv")
    base = [
        stress_ng,
        "--exec",
        "2",
        "--exec-method",
        "execve",
        "--temp-path",
        "/tmp",
        "--timeout",
        "5s",
        "--metrics-brief",
    ]
    if setpriv:
        base = [setpriv, "--reuid", "65534", "--regid", "65534", "--clear-groups", *base]
    if cgroup_path is None:
        completed = run(base, check=False)
    else:
        script = (
            "set -euo pipefail\n"
            f"echo $$ > {cgroup_path}/cgroup.procs\n"
            "exec " + " ".join(subprocess.list2cmdline([arg]) for arg in base)
        )
        completed = subprocess.run(["bash", "-lc", script], check=False, text=True, capture_output=True)
    if completed.returncode != 0:
        raise SystemExit(f"workload failed with rc={completed.returncode}: {(completed.stderr or completed.stdout).strip()}")


def main() -> None:
    policy_dir = Path(tempfile.mkdtemp(prefix="tetragon-diag-"))
    child_cgroup = Path("/sys/fs/cgroup/tetragon-e2e-diag")
    tetragon = None
    try:
        (policy_dir / "tracepoint.yaml").write_text(TRACEPOINT_POLICY)
        (policy_dir / "kprobes.yaml").write_text(KPROBE_POLICY)
        with enable_bpf_stats():
            baseline = current_target_programs()
            print_snapshot("before_start", {}, baseline)
            tetragon = subprocess.Popen(
                [
                    "/usr/local/bin/tetragon",
                    "--cgroup-rate",
                    "1000,1s",
                    "--tracing-policy-dir",
                    str(policy_dir),
                ],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                text=True,
            )
            time.sleep(8.0)
            loaded = wait_for_targets()
            print_snapshot("after_load", baseline, loaded)

            run_exec_storm()
            after_root = current_target_programs()
            print_snapshot("after_root_exec_storm", loaded, after_root)

            child_cgroup.mkdir(exist_ok=True)
            run_exec_storm(cgroup_path=child_cgroup)
            after_child = current_target_programs()
            print_snapshot("after_child_cgroup_exec_storm", after_root, after_child)
    finally:
        if tetragon is not None:
            tetragon.terminate()
            try:
                tetragon.communicate(timeout=15)
            except subprocess.TimeoutExpired:
                tetragon.kill()
                tetragon.communicate(timeout=5)
        try:
            if child_cgroup.exists():
                child_cgroup.rmdir()
        except OSError:
            pass
        shutil.rmtree(policy_dir, ignore_errors=True)


if __name__ == "__main__":
    main()
