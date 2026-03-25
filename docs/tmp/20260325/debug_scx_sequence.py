#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import errno
import json
import os
import subprocess
import sys
import threading
from collections import deque
from pathlib import Path

ROOT = Path("/home/yunwei37/workspace/bpf-benchmark")
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from e2e.cases.scx.case import (
    ScxSchedulerSession,
    preferred_path,
    probe_bpftool_register,
    read_scx_state,
    run_phase,
    workload_specs,
)
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy
from runner.libs.rejit import apply_daemon_rejit, scan_programs

DEFAULT_SCX_BINARY = ROOT / "runner/repos/scx/target/release/scx_rusty"
DEFAULT_SCX_OBJECT = ROOT / "corpus/build/scx/scx_rusty_main.bpf.o"
DEFAULT_DAEMON = ROOT / "daemon/target/debug/bpfrejit-daemon"
DEFAULT_BPFTOOL = Path("/usr/local/sbin/bpftool")
SYS_BPF = 321
BPF_PROG_GET_NEXT_ID = 11
BPF_PROG_GET_FD_BY_ID = 13
BPF_OBJ_GET_INFO_BY_FD = 15
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16
LIBC = ctypes.CDLL(None, use_errno=True)
LIBC.syscall.restype = ctypes.c_long


class BpfAttrId(ctypes.Structure):
    _fields_ = [
        ("start_id", ctypes.c_uint32),
        ("next_id", ctypes.c_uint32),
        ("open_flags", ctypes.c_uint32),
        ("fd_by_id_token_fd", ctypes.c_int32),
    ]


class BpfAttrInfo(ctypes.Structure):
    _fields_ = [
        ("bpf_fd", ctypes.c_uint32),
        ("info_len", ctypes.c_uint32),
        ("info", ctypes.c_uint64),
    ]


class BpfProgInfoMinimal(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("tag", ctypes.c_ubyte * BPF_TAG_SIZE),
        ("jited_prog_len", ctypes.c_uint32),
        ("xlated_prog_len", ctypes.c_uint32),
        ("jited_prog_insns", ctypes.c_uint64),
        ("xlated_prog_insns", ctypes.c_uint64),
        ("load_time", ctypes.c_uint64),
        ("created_by_uid", ctypes.c_uint32),
        ("nr_map_ids", ctypes.c_uint32),
        ("map_ids", ctypes.c_uint64),
        ("name", ctypes.c_char * BPF_OBJ_NAME_LEN),
    ]


def marker(*parts: object) -> None:
    print("MARK", *parts, flush=True)


class Collector:
    def __init__(self) -> None:
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)

    def consume(self, pipe, bucket: deque[str]) -> None:
        for raw_line in iter(pipe.readline, ""):
            bucket.append(raw_line.rstrip())
        pipe.close()


def maybe_probe(enabled: bool) -> None:
    if not enabled:
        marker("skip_probe")
        return
    marker("before_probe")
    probe = probe_bpftool_register(DEFAULT_SCX_OBJECT, DEFAULT_BPFTOOL)
    marker("after_probe", probe.get("returncode"), probe.get("after_state"), probe.get("usable"))


def start_scx_agent():
    return start_agent(
        "bash",
        [
            "-lc",
            "ulimit -l unlimited >/dev/null 2>&1 || true; exec "
            + str(DEFAULT_SCX_BINARY)
            + " --stats 1",
        ],
        env={"PATH": preferred_path()},
    )


def collect_prog_ids_from_fdinfo(pid: int) -> list[int]:
    fdinfo_dir = Path(f"/proc/{pid}/fdinfo")
    if not fdinfo_dir.exists():
        return []
    prog_ids: list[int] = []
    entries = sorted(fdinfo_dir.iterdir(), key=lambda item: int(item.name))
    for entry in entries:
        text = entry.read_text()
        for line in text.splitlines():
            if line.startswith("prog_id:"):
                prog_ids.append(int(line.split(":", 1)[1].strip()))
    return sorted(prog_ids)


def run_bpftool_show(args: list[str] | None = None) -> tuple[int, int]:
    command = [str(DEFAULT_BPFTOOL), "-j", "-p", "prog", "show"]
    if args:
        command.extend(args)
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=30,
    )
    payload = json.loads(completed.stdout) if completed.stdout.strip() else []
    return completed.returncode, len(payload)


def run_bpftool_show_payload(args: list[str] | None = None):
    command = [str(DEFAULT_BPFTOOL), "-j", "-p", "prog", "show"]
    if args:
        command.extend(args)
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=30,
    )
    payload = json.loads(completed.stdout) if completed.stdout.strip() else []
    return completed.returncode, payload


def bpf_syscall(command: int, attr, size: int) -> int:
    result = int(LIBC.syscall(SYS_BPF, command, ctypes.byref(attr), size))
    if result < 0:
        err = ctypes.get_errno()
        raise OSError(err, os.strerror(err))
    return result


def raw_prog_get_next_id(start_id: int) -> int | None:
    attr = BpfAttrId()
    attr.start_id = start_id
    try:
        bpf_syscall(BPF_PROG_GET_NEXT_ID, attr, ctypes.sizeof(attr))
    except OSError as exc:
        if exc.errno == errno.ENOENT:
            return None
        raise
    return int(attr.next_id)


def raw_prog_get_fd_by_id(prog_id: int) -> int:
    attr = BpfAttrId()
    attr.start_id = prog_id
    return bpf_syscall(BPF_PROG_GET_FD_BY_ID, attr, ctypes.sizeof(attr))


def raw_prog_get_info(fd: int) -> BpfProgInfoMinimal:
    info = BpfProgInfoMinimal()
    attr = BpfAttrInfo()
    attr.bpf_fd = fd
    attr.info_len = ctypes.sizeof(info)
    attr.info = ctypes.addressof(info)
    bpf_syscall(BPF_OBJ_GET_INFO_BY_FD, attr, ctypes.sizeof(attr))
    return info


def raw_prog_get_map_ids(fd: int, count: int) -> list[int]:
    info = BpfProgInfoMinimal()
    map_ids = (ctypes.c_uint32 * count)()
    info.nr_map_ids = count
    info.map_ids = ctypes.addressof(map_ids)
    attr = BpfAttrInfo()
    attr.bpf_fd = fd
    attr.info_len = ctypes.sizeof(info)
    attr.info = ctypes.addressof(info)
    bpf_syscall(BPF_OBJ_GET_INFO_BY_FD, attr, ctypes.sizeof(attr))
    return [int(map_ids[index]) for index in range(min(count, int(info.nr_map_ids)))]


def raw_prog_snapshot() -> list[dict[str, object]]:
    records: list[dict[str, object]] = []
    current_id = 0
    while True:
        next_id = raw_prog_get_next_id(current_id)
        if next_id is None:
            break
        current_id = next_id
        try:
            fd = raw_prog_get_fd_by_id(current_id)
        except OSError as exc:
            if exc.errno == errno.ENOENT:
                continue
            raise
        try:
            info = raw_prog_get_info(fd)
        finally:
            os.close(fd)
        records.append(
            {
                "id": int(info.id),
                "type": int(info.type),
                "nr_map_ids": int(info.nr_map_ids),
                "name": bytes(info.name).split(b"\0", 1)[0].decode("utf-8", "ignore"),
            }
        )
    return records


def raw_prog_map_ids_snapshot() -> list[dict[str, object]]:
    records: list[dict[str, object]] = []
    current_id = 0
    while True:
        next_id = raw_prog_get_next_id(current_id)
        if next_id is None:
            break
        current_id = next_id
        try:
            fd = raw_prog_get_fd_by_id(current_id)
        except OSError as exc:
            if exc.errno == errno.ENOENT:
                continue
            raise
        try:
            info = raw_prog_get_info(fd)
            map_ids = raw_prog_get_map_ids(fd, int(info.nr_map_ids)) if int(info.nr_map_ids) else []
        finally:
            os.close(fd)
        records.append(
            {
                "id": int(info.id),
                "type": int(info.type),
                "name": bytes(info.name).split(b"\0", 1)[0].decode("utf-8", "ignore"),
                "map_ids": map_ids,
            }
        )
    return records


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--mode",
        choices=(
            "probe-only",
            "session",
            "sequence",
            "manual-exact-health",
            "manual-find-loop",
            "manual-state-then-find",
            "manual-fdinfo-only",
            "manual-fdinfo-loop",
            "manual-fdinfo-then-bpftool",
            "manual-bpftool-show-only",
            "manual-bpftool-loop",
            "manual-owner-id-loop",
            "manual-raw-prog-loop",
        ),
        default="session",
    )
    parser.add_argument("--duration", type=int, default=10)
    parser.add_argument("--find-iterations", type=int, default=20)
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--owner-start-id", type=int, default=0)
    parser.add_argument("--owner-only-id", type=int, default=0)
    parser.add_argument("--skip-probe", action="store_true")
    args = parser.parse_args()

    if args.mode == "probe-only":
        maybe_probe(True)
        return 0

    maybe_probe(not args.skip_probe)

    if args.mode == "manual-exact-health":
        marker("before_start_agent")
        proc = start_scx_agent()
        assert proc.stdout is not None
        assert proc.stderr is not None
        collector = Collector()
        stdout_thread = threading.Thread(target=collector.consume, args=(proc.stdout, collector.stdout_tail), daemon=True)
        stderr_thread = threading.Thread(target=collector.consume, args=(proc.stderr, collector.stderr_tail), daemon=True)
        stdout_thread.start()
        stderr_thread.start()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled" and bool(find_bpf_programs(proc.pid)),
        )
        marker("after_wait_healthy", healthy)
        if healthy:
            marker("after_find", [int(item.get("id", 0)) for item in find_bpf_programs(proc.pid)])
        rc = stop_agent(proc, timeout=8)
        stdout_thread.join(timeout=2.0)
        stderr_thread.join(timeout=2.0)
        marker("after_stop_agent", rc, len(collector.stdout_tail), len(collector.stderr_tail))
        return 0

    if args.mode == "manual-state-then-find":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            marker("after_find", [int(item.get("id", 0)) for item in find_bpf_programs(proc.pid)])
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-find-loop":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            for index in range(args.find_iterations):
                marker("before_find_iter", index)
                programs = find_bpf_programs(proc.pid)
                marker("after_find_iter", index, [int(item.get("id", 0)) for item in programs])
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-fdinfo-only":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            prog_ids = collect_prog_ids_from_fdinfo(proc.pid)
            marker("after_fdinfo_scan", prog_ids)
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-fdinfo-loop":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            for index in range(args.find_iterations):
                marker("before_fdinfo_iter", index)
                marker("after_fdinfo_iter", index, collect_prog_ids_from_fdinfo(proc.pid))
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-bpftool-show-only":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            marker("before_bpftool_show")
            rc, payload_len = run_bpftool_show()
            marker("after_bpftool_show", rc, payload_len)
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-bpftool-loop":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            for index in range(args.find_iterations):
                marker("before_bpftool_iter", index)
                rc, payload_len = run_bpftool_show()
                marker("after_bpftool_iter", index, rc, payload_len)
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-fdinfo-then-bpftool":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            marker("after_fdinfo_scan", collect_prog_ids_from_fdinfo(proc.pid))
            marker("before_bpftool_show")
            rc, payload_len = run_bpftool_show()
            marker("after_bpftool_show", rc, payload_len)
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-owner-id-loop":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            owner_ids = collect_prog_ids_from_fdinfo(proc.pid)
            if args.owner_only_id:
                owner_ids = [prog_id for prog_id in owner_ids if prog_id == args.owner_only_id]
            if args.owner_start_id:
                owner_ids = [prog_id for prog_id in owner_ids if prog_id >= args.owner_start_id]
            marker("owner_ids", owner_ids)
            for index in range(args.find_iterations):
                for prog_id in owner_ids:
                    marker("before_owner_prog", index, prog_id)
                    rc, payload = run_bpftool_show_payload(["id", str(prog_id)])
                    if isinstance(payload, dict):
                        marker(
                            "after_owner_prog",
                            index,
                            prog_id,
                            rc,
                            payload.get("name"),
                            payload.get("type"),
                        )
                    else:
                        marker("after_owner_prog", index, prog_id, rc, type(payload).__name__, len(payload))
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    if args.mode == "manual-raw-prog-loop":
        marker("before_start_agent")
        proc = start_scx_agent()
        marker("after_start_agent", proc.pid)
        healthy = wait_healthy(
            proc,
            args.load_timeout,
            lambda: read_scx_state() == "enabled",
        )
        marker("after_wait_state", healthy)
        if healthy:
            for index in range(args.find_iterations):
                marker("before_raw_prog_iter", index)
                records = raw_prog_snapshot()
                marker("after_raw_prog_iter", index, len(records), [int(item["id"]) for item in records])
        rc = stop_agent(proc, timeout=8)
        marker("after_stop_agent", rc)
        return 0

    marker("before_session")
    with ScxSchedulerSession(DEFAULT_SCX_BINARY, [], args.load_timeout) as session:
        prog_ids = [int(program["id"]) for program in session.programs]
        marker("session_pid", session.pid)
        marker("session_prog_ids", prog_ids)
        snapshot = session.collector_snapshot()
        marker("session_stdout_tail_len", len(snapshot.get("stdout_tail") or []))
        marker("session_stderr_tail_len", len(snapshot.get("stderr_tail") or []))
        if args.mode == "session":
            return 0

        marker("before_run_phase")
        baseline = run_phase(workload_specs(), args.duration, agent_pid=session.pid)
        marker("after_run_phase", [record.get("name") for record in baseline.get("workloads") or []])

        marker("before_scan")
        scan_results = scan_programs(prog_ids, DEFAULT_DAEMON)
        marker("after_scan", sorted(scan_results))

        marker("before_apply")
        apply_result = apply_daemon_rejit(DEFAULT_DAEMON, prog_ids)
        marker(
            "after_apply",
            apply_result.get("applied"),
            apply_result.get("exit_code"),
            len(str(apply_result.get("error") or "")),
        )

    marker("after_session")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
