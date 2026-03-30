from __future__ import annotations

import os
import signal
import subprocess
import time
from pathlib import Path
from typing import Callable, Sequence

from . import ROOT_DIR, resolve_bpftool_binary, run_json_command


def start_agent(
    binary: str,
    args: Sequence[str] = (),
    env: dict[str, str] | None = None,
) -> subprocess.Popen[str]:
    merged_env = os.environ.copy()
    if env:
        merged_env.update(env)
    return subprocess.Popen(
        [binary, *args],
        cwd=ROOT_DIR,
        env=merged_env,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        bufsize=1,
    )


def wait_healthy(
    proc: subprocess.Popen[str],
    timeout: int | float,
    health_check_fn: Callable[[], bool],
) -> bool:
    deadline = time.monotonic() + float(timeout)
    while time.monotonic() < deadline:
        if proc.poll() is not None:
            return False
        if health_check_fn():
            return True
        time.sleep(0.5)
    return proc.poll() is None and health_check_fn()


def stop_agent(proc: subprocess.Popen[str], timeout: int | float = 10) -> int:
    if proc.poll() is None:
        proc.send_signal(signal.SIGINT)
        try:
            return proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            proc.terminate()
            try:
                return proc.wait(timeout=3)
            except subprocess.TimeoutExpired:
                proc.kill()
                return proc.wait(timeout=3)
    return int(proc.returncode or 0)


def _resolve_pids(agent_name_or_pid: str | int) -> list[int]:
    if isinstance(agent_name_or_pid, int):
        return [agent_name_or_pid]
    text = str(agent_name_or_pid).strip()
    if text.isdigit():
        return [int(text)]

    matches: list[int] = []
    for proc_dir in Path("/proc").iterdir():
        if not proc_dir.name.isdigit():
            continue
        pid = int(proc_dir.name)
        try:
            comm = (proc_dir / "comm").read_text().strip()
        except OSError:
            continue
        if comm == text or Path(comm).name == text:
            matches.append(pid)
            continue
        try:
            raw_cmdline = (proc_dir / "cmdline").read_bytes().replace(b"\0", b" ").decode("utf-8", "ignore")
        except OSError:
            continue
        if text in raw_cmdline:
            matches.append(pid)
    return sorted(set(matches))


def _program_refs_from_pid(pid: int) -> dict[int, list[dict[str, int]]]:
    refs: dict[int, list[dict[str, int]]] = {}
    fdinfo_dir = Path(f"/proc/{pid}/fdinfo")
    if not fdinfo_dir.exists():
        return refs
    for entry in fdinfo_dir.iterdir():
        try:
            text = entry.read_text()
        except OSError:
            continue
        for line in text.splitlines():
            if not line.startswith("prog_id:"):
                continue
            _, value = line.split(":", 1)
            value = value.strip()
            if value.isdigit():
                refs.setdefault(int(value), []).append({"pid": pid, "fd": int(entry.name)})
    return refs


def find_bpf_programs(agent_name_or_pid: str | int) -> list[dict]:
    pids = _resolve_pids(agent_name_or_pid)
    if not pids:
        return []

    owner_map: dict[int, list[int]] = {}
    owner_fd_map: dict[int, list[dict[str, int]]] = {}
    for pid in pids:
        for prog_id, refs in _program_refs_from_pid(pid).items():
            owner_map.setdefault(prog_id, []).append(pid)
            owner_fd_map.setdefault(prog_id, []).extend(refs)

    if not owner_map:
        return []

    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        return []

    matches: list[dict] = []
    for record in payload:
        if not isinstance(record, dict):
            continue
        prog_id = int(record.get("id", -1))
        if prog_id not in owner_map:
            continue
        enriched = dict(record)
        enriched["owner_pids"] = sorted(owner_map[prog_id])
        enriched["owner_fds"] = sorted(owner_fd_map.get(prog_id, []), key=lambda item: (item["pid"], item["fd"]))
        matches.append(enriched)
    matches.sort(key=lambda item: int(item.get("id", 0)))
    return matches


__all__ = [
    "find_bpf_programs",
    "start_agent",
    "stop_agent",
    "wait_healthy",
]
