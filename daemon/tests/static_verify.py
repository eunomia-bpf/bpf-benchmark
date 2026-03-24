#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import socket
import subprocess
import sys
import time
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import (  # noqa: E402
    ROOT_DIR,
    prepare_bpftool_environment,
    run_command,
    run_json_command,
    tail_text,
    write_json,
)
from runner.libs.catalog import (  # noqa: E402
    DEFAULT_MACRO_MANIFEST,
    DEFAULT_MICRO_MANIFEST,
    CatalogTarget,
    load_catalog,
)


DEFAULT_RESULTS_DIR = ROOT_DIR / "daemon" / "tests" / "results"
DEFAULT_OUTPUT = DEFAULT_RESULTS_DIR / "static_verify.json"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_PIN_ROOT = Path("/sys/fs/bpf/static_verify")
DEFAULT_SOCKET_PATH = Path("/tmp/bpfrejit-static-verify.sock")
DEFAULT_LOAD_TIMEOUT = 90
DEFAULT_DUMP_TIMEOUT = 60
DEFAULT_DAEMON_TIMEOUT = 60

INSN_LINE_RE = re.compile(r"^\s*\d+:")
HEX_BYTE_LINE_RE = re.compile(r"^\s*(?:[0-9a-fA-F]{2})(?:\s+[0-9a-fA-F]{2})*\s*$")
INT_WITH_SUFFIX_RE = re.compile(r"^\s*(\d+)(?:B)?\s*$")
PIN_COMPONENT_RE = re.compile(r"[^A-Za-z0-9_-]+")


def repo_relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT_DIR))
    except ValueError:
        return str(path.resolve())


def command_text(command: Sequence[str]) -> str:
    return " ".join(shlex.quote(part) for part in command)


def path_exists(path: Path) -> bool:
    try:
        path.lstat()
        return True
    except FileNotFoundError:
        return False
    except PermissionError:
        return False


def parse_int_like(value: object) -> int | None:
    if isinstance(value, bool):
        return int(value)
    if isinstance(value, int):
        return value
    if isinstance(value, float) and value.is_integer():
        return int(value)
    if isinstance(value, str):
        text = value.strip()
        if text.isdigit():
            return int(text)
        match = INT_WITH_SUFFIX_RE.fullmatch(text)
        if match:
            return int(match.group(1))
    return None


def first_int(payload: Mapping[str, object], *keys: str) -> int | None:
    for key in keys:
        value = parse_int_like(payload.get(key))
        if value is not None:
            return value
    return None


def normalize_single_json_payload(payload: object) -> dict[str, object]:
    if isinstance(payload, Mapping):
        return dict(payload)
    if isinstance(payload, list) and len(payload) == 1 and isinstance(payload[0], Mapping):
        return dict(payload[0])
    raise RuntimeError(f"unexpected bpftool JSON payload type: {type(payload).__name__}")


def mount_is_bpffs(path: Path) -> bool:
    if not Path("/proc/mounts").exists():
        return False
    for line in Path("/proc/mounts").read_text().splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[1] == str(path) and parts[2] == "bpf":
            return True
    return False


def ensure_bpffs() -> None:
    bpffs_root = Path("/sys/fs/bpf")
    bpffs_root.mkdir(parents=True, exist_ok=True)
    if mount_is_bpffs(bpffs_root):
        return
    run_command(["mount", "-t", "bpf", "bpf", str(bpffs_root)], timeout=30)


def remove_tree(path: Path) -> None:
    if not path_exists(path):
        return
    if path.is_symlink() or path.is_file():
        path.unlink()
        return
    for child in sorted(path.iterdir(), key=lambda item: item.name, reverse=True):
        remove_tree(child)
    path.rmdir()


def sanitize_pin_component(text: str) -> str:
    sanitized = PIN_COMPONENT_RE.sub("-", text.strip())
    sanitized = sanitized.strip(".-")
    return sanitized or "object"


def count_xlated_instructions(text: str) -> int:
    return sum(1 for line in text.splitlines() if INSN_LINE_RE.match(line))


def count_jited_bytes(text: str) -> int:
    total = 0
    for line in text.splitlines():
        if not HEX_BYTE_LINE_RE.match(line):
            continue
        total += len(line.split())
    return total


def format_hex_blob(blob: str | None) -> str | None:
    if not blob:
        return None
    cleaned = blob.strip()
    if not cleaned:
        return None
    if len(cleaned) % 16 != 0:
        return cleaned
    lines: list[str] = []
    for pc, start in enumerate(range(0, len(cleaned), 16)):
        insn_hex = cleaned[start : start + 16]
        byte_pairs = " ".join(insn_hex[index : index + 2] for index in range(0, len(insn_hex), 2))
        lines.append(f"{pc:4d}: {byte_pairs}")
    return "\n".join(lines)


def average(values: Sequence[float]) -> float | None:
    if not values:
        return None
    return sum(values) / len(values)


def format_average(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.2f}"


@dataclass
class ObjectEntry:
    object_path: Path
    manifest_kinds: list[str] = field(default_factory=list)
    target_names: list[str] = field(default_factory=list)
    prog_types: list[str] = field(default_factory=list)
    program_names: list[str] = field(default_factory=list)
    sections: list[str] = field(default_factory=list)

    def add_target(self, target: CatalogTarget, manifest_kind: str) -> None:
        self._append_unique(self.manifest_kinds, manifest_kind)
        self._append_unique(self.target_names, target.name)
        if target.prog_type:
            self._append_unique(self.prog_types, target.prog_type)
        for program_name in target.program_names:
            self._append_unique(self.program_names, program_name)
        for section in target.sections:
            self._append_unique(self.sections, section)

    @staticmethod
    def _append_unique(values: list[str], value: str) -> None:
        if value and value not in values:
            values.append(value)


@dataclass
class DaemonServer:
    binary: Path
    socket_path: Path
    log_path: Path
    timeout_seconds: int
    process: subprocess.Popen[str] | None = None
    log_file: Any | None = None

    def start(self) -> None:
        self.log_path.parent.mkdir(parents=True, exist_ok=True)
        if path_exists(self.socket_path):
            self.socket_path.unlink()
        self.log_file = self.log_path.open("w", encoding="utf-8")
        self.process = subprocess.Popen(
            [str(self.binary), "serve", "--socket", str(self.socket_path)],
            cwd=ROOT_DIR,
            stdout=self.log_file,
            stderr=subprocess.STDOUT,
            text=True,
        )
        deadline = time.monotonic() + self.timeout_seconds
        last_error = "daemon did not become ready"
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                break
            if self.socket_path.exists():
                try:
                    status = self.request({"cmd": "status"}, timeout=5)
                    if status.get("status") == "ok":
                        return
                    last_error = f"unexpected daemon status: {status}"
                except Exception as exc:  # noqa: BLE001
                    last_error = str(exc)
            time.sleep(0.1)
        log_tail = ""
        if self.log_path.exists():
            log_tail = tail_text(self.log_path.read_text(encoding="utf-8", errors="replace"))
        raise RuntimeError(
            f"failed to start daemon server: {last_error}\n"
            f"daemon log tail:\n{log_tail}"
        )

    def request(self, payload: Mapping[str, object], timeout: int) -> dict[str, object]:
        raw_request = (json.dumps(payload, sort_keys=True) + "\n").encode("utf-8")
        with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
            client.settimeout(timeout)
            client.connect(str(self.socket_path))
            client.sendall(raw_request)
            client.shutdown(socket.SHUT_WR)
            response_chunks: list[bytes] = []
            while True:
                chunk = client.recv(65536)
                if not chunk:
                    break
                response_chunks.append(chunk)
                if b"\n" in chunk:
                    break
        if not response_chunks:
            raise RuntimeError("daemon returned an empty response")
        response_line = b"".join(response_chunks).splitlines()[0].decode("utf-8")
        payload_obj = json.loads(response_line)
        if not isinstance(payload_obj, Mapping):
            raise RuntimeError(f"daemon returned non-object response: {type(payload_obj).__name__}")
        return dict(payload_obj)

    def stop(self) -> None:
        if self.process is not None and self.process.poll() is None:
            self.process.terminate()
            try:
                self.process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.process.kill()
                self.process.wait(timeout=5)
        if self.log_file is not None:
            self.log_file.close()
            self.log_file = None
        if path_exists(self.socket_path):
            self.socket_path.unlink()


def collect_objects(mode: str, filter_text: str | None) -> tuple[list[ObjectEntry], dict[str, int]]:
    manifests: list[tuple[str, Path]] = [("micro", Path(DEFAULT_MICRO_MANIFEST))]
    if mode == "all":
        manifests.append(("macro", Path(DEFAULT_MACRO_MANIFEST)))

    object_map: dict[Path, ObjectEntry] = {}
    counts: dict[str, int] = {}
    for manifest_kind, manifest_path in manifests:
        manifest = load_catalog(manifest_path)
        counts[f"{manifest_kind}_targets"] = len(manifest.targets)
        counts[f"{manifest_kind}_objects"] = len({target.object_path.resolve() for target in manifest.targets})
        for target in manifest.targets:
            object_path = target.object_path.resolve()
            entry = object_map.setdefault(object_path, ObjectEntry(object_path=object_path))
            entry.add_target(target, manifest_kind)

    objects = list(object_map.values())
    if filter_text:
        needle = filter_text.lower()
        objects = [
            entry
            for entry in objects
            if needle in str(entry.object_path).lower()
            or any(needle in value.lower() for value in entry.target_names)
            or any(needle in value.lower() for value in entry.program_names)
        ]
    return objects, counts


def bpftool_prog_show_pinned(bpftool: str, pinned_path: Path) -> dict[str, object]:
    payload = run_json_command(
        [bpftool, "-j", "prog", "show", "pinned", str(pinned_path)],
        timeout=30,
    )
    return normalize_single_json_payload(payload)


def bpftool_prog_show_id(bpftool: str, prog_id: int) -> dict[str, object]:
    payload = run_json_command(
        [bpftool, "-j", "prog", "show", "id", str(prog_id)],
        timeout=30,
    )
    return normalize_single_json_payload(payload)


def bpftool_dump(bpftool: str, dump_kind: str, prog_id: int, timeout: int) -> str:
    completed = run_command(
        [bpftool, "prog", "dump", dump_kind, "id", str(prog_id), "opcodes"],
        timeout=timeout,
    )
    return completed.stdout


def loadall_commands(bpftool: str, entry: ObjectEntry, pin_dir: Path) -> list[list[str]]:
    commands = [[bpftool, "prog", "loadall", str(entry.object_path), str(pin_dir)]]
    unique_prog_types = [prog_type for prog_type in entry.prog_types if prog_type]
    if len(unique_prog_types) == 1:
        commands.append(
            [bpftool, "prog", "loadall", str(entry.object_path), str(pin_dir), "type", unique_prog_types[0]]
        )
    return commands


def try_loadall(bpftool: str, entry: ObjectEntry, pin_dir: Path) -> tuple[list[str] | None, list[dict[str, object]]]:
    attempts: list[dict[str, object]] = []
    for command in loadall_commands(bpftool, entry, pin_dir):
        if path_exists(pin_dir):
            remove_tree(pin_dir)
        pin_dir.mkdir(parents=True, exist_ok=True)
        completed = run_command(command, check=False, timeout=DEFAULT_LOAD_TIMEOUT)
        attempt = {
            "command": command_text(command),
            "returncode": completed.returncode,
            "stdout_tail": tail_text(completed.stdout or ""),
            "stderr_tail": tail_text(completed.stderr or ""),
        }
        attempts.append(attempt)
        if completed.returncode == 0:
            return command, attempts
    return None, attempts


def enumerate_pinned_programs(bpftool: str, pin_dir: Path) -> list[dict[str, object]]:
    programs: list[dict[str, object]] = []
    for pinned_path in sorted(path for path in pin_dir.rglob("*") if not path.is_dir()):
        info = bpftool_prog_show_pinned(bpftool, pinned_path)
        prog_id = first_int(info, "id")
        if prog_id is None:
            raise RuntimeError(f"missing prog id for pinned path {pinned_path}")
        programs.append(
            {
                "pinned_path": pinned_path,
                "prog_id": prog_id,
                "info": info,
            }
        )
    return programs


def extract_prog_name(info: Mapping[str, object], pinned_path: Path) -> str:
    name = info.get("name")
    if isinstance(name, str) and name.strip():
        return name
    return pinned_path.name


def extract_prog_size(payload: Mapping[str, object], *keys: str) -> int | None:
    value = first_int(payload, *keys)
    if value is not None:
        return value
    for key, raw_value in payload.items():
        if key in keys:
            continue
        if any(needle in key for needle in keys):
            parsed = parse_int_like(raw_value)
            if parsed is not None:
                return parsed
    return None


def daemon_passes_applied(response: Mapping[str, object]) -> list[str]:
    passes = response.get("passes")
    if not isinstance(passes, list):
        return []
    applied: list[str] = []
    for item in passes:
        if not isinstance(item, Mapping):
            continue
        sites_applied = parse_int_like(item.get("sites_applied")) or 0
        changed = bool(item.get("changed"))
        pass_name = item.get("pass_name")
        if (changed or sites_applied > 0) and isinstance(pass_name, str) and pass_name:
            applied.append(pass_name)
    return applied


def daemon_last_debug(response: Mapping[str, object]) -> Mapping[str, object] | None:
    attempts = response.get("attempts")
    if not isinstance(attempts, list) or not attempts:
        return None
    last_attempt = attempts[-1]
    if not isinstance(last_attempt, Mapping):
        return None
    debug = last_attempt.get("debug")
    if not isinstance(debug, Mapping):
        return None
    return debug


def build_record_prefix(entry: ObjectEntry, object_index: int, pinned_path: Path | None, prog_id: int | None) -> dict[str, object]:
    return {
        "object_index": object_index,
        "obj_path": repo_relative(entry.object_path),
        "obj_abs_path": str(entry.object_path),
        "manifest_kinds": list(entry.manifest_kinds),
        "target_names": list(entry.target_names),
        "program_names_from_manifest": list(entry.program_names),
        "sections_from_manifest": list(entry.sections),
        "prog_id": prog_id,
        "pinned_path": str(pinned_path) if pinned_path is not None else None,
    }


def process_program(
    *,
    entry: ObjectEntry,
    object_index: int,
    bpftool: str,
    daemon: DaemonServer,
    pinned_program: Mapping[str, object],
) -> dict[str, object]:
    pinned_path = Path(str(pinned_program["pinned_path"]))
    prog_id = int(pinned_program["prog_id"])
    initial_info = pinned_program["info"]
    if not isinstance(initial_info, Mapping):
        raise RuntimeError(f"unexpected initial pinned info type: {type(initial_info).__name__}")
    prog_name = extract_prog_name(initial_info, pinned_path)

    before_xlated = bpftool_dump(bpftool, "xlated", prog_id, DEFAULT_DUMP_TIMEOUT)
    before_jited = bpftool_dump(bpftool, "jited", prog_id, DEFAULT_DUMP_TIMEOUT)
    before_info = bpftool_prog_show_id(bpftool, prog_id)

    before_insn_count = count_xlated_instructions(before_xlated)
    before_code_size = count_jited_bytes(before_jited) or extract_prog_size(
        before_info,
        "jited_prog_len",
        "jited_len",
        "jited",
    )

    daemon_response = daemon.request({"cmd": "optimize", "prog_id": prog_id}, timeout=DEFAULT_DAEMON_TIMEOUT)

    after_xlated = bpftool_dump(bpftool, "xlated", prog_id, DEFAULT_DUMP_TIMEOUT)
    after_jited = bpftool_dump(bpftool, "jited", prog_id, DEFAULT_DUMP_TIMEOUT)
    after_info = bpftool_prog_show_id(bpftool, prog_id)

    bpftool_after_insn_count = count_xlated_instructions(after_xlated)
    after_code_size = count_jited_bytes(after_jited) or extract_prog_size(
        after_info,
        "jited_prog_len",
        "jited_len",
        "jited",
    )

    summary = daemon_response.get("summary")
    daemon_summary = dict(summary) if isinstance(summary, Mapping) else {}
    daemon_program = daemon_response.get("program")
    daemon_program_info = dict(daemon_program) if isinstance(daemon_program, Mapping) else {}
    daemon_debug = daemon_last_debug(daemon_response)
    daemon_pre_rejit = (
        dict(daemon_debug.get("pre_rejit_bytecode"))
        if isinstance(daemon_debug, Mapping) and isinstance(daemon_debug.get("pre_rejit_bytecode"), Mapping)
        else {}
    )
    daemon_final_xlated = (
        dict(daemon_debug.get("final_xlated_bytecode"))
        if isinstance(daemon_debug, Mapping) and isinstance(daemon_debug.get("final_xlated_bytecode"), Mapping)
        else {}
    )
    daemon_final_jited = (
        dict(daemon_debug.get("final_jited_machine_code"))
        if isinstance(daemon_debug, Mapping) and isinstance(daemon_debug.get("final_jited_machine_code"), Mapping)
        else {}
    )

    daemon_after_insn_count = parse_int_like(daemon_program_info.get("final_insn_count"))
    after_xlated_count_mismatch = bool(
        daemon_response.get("status") == "ok"
        and daemon_summary.get("program_changed")
        and daemon_after_insn_count is not None
        and bpftool_after_insn_count != daemon_after_insn_count
    )

    record = build_record_prefix(entry, object_index, pinned_path, prog_id)
    record.update(
        {
            "status": "ok" if daemon_response.get("status") == "ok" else "error",
            "prog_name": prog_name,
            "verifier_accepted": daemon_response.get("status") == "ok",
            "applied": bool(daemon_summary.get("applied")) if daemon_summary else False,
            "program_changed": bool(daemon_summary.get("program_changed")) if daemon_summary else False,
            "passes_applied": daemon_passes_applied(daemon_response),
            "daemon_status": daemon_response.get("status"),
            "daemon_message": daemon_response.get("message"),
            "daemon_error_message": daemon_response.get("error_message"),
            "daemon_verifier_retries": parse_int_like(daemon_summary.get("verifier_retries")) if daemon_summary else None,
            "daemon_final_disabled_passes": daemon_summary.get("final_disabled_passes") if daemon_summary else [],
            "insn_count_before": before_insn_count,
            "insn_count_after": bpftool_after_insn_count,
            "bpftool_insn_count_after": bpftool_after_insn_count,
            "daemon_insn_count_after": daemon_after_insn_count,
            "code_size_before": before_code_size,
            "code_size_after": after_code_size,
            "before_jited_size": before_code_size,
            "after_jited_size": after_code_size,
            "insn_delta": bpftool_after_insn_count - before_insn_count,
            "daemon_submitted_insn_delta": None if daemon_after_insn_count is None else daemon_after_insn_count - before_insn_count,
            "code_delta_bytes": None if before_code_size is None or after_code_size is None else after_code_size - before_code_size,
            "before_xlated": before_xlated,
            "after_xlated": after_xlated,
            "before_jited": before_jited,
            "after_jited": after_jited,
            "after_xlated_count_mismatch": after_xlated_count_mismatch,
            "after_xlated_count_mismatch_note": (
                "bpftool xlated dump count differs from the daemon-submitted REJIT bytecode length; this can be caused by verifier canonicalization or stale xlated info"
                if after_xlated_count_mismatch
                else None
            ),
            "bpftool_after_xlated_matches_before": after_xlated == before_xlated,
            "before_xlated_info": {
                "show_xlated_size_bytes": extract_prog_size(before_info, "xlated_prog_len", "xlated_len", "xlated"),
                "show_jited_size_bytes": extract_prog_size(before_info, "jited_prog_len", "jited_len", "jited"),
            },
            "after_xlated_info": {
                "show_xlated_size_bytes": extract_prog_size(after_info, "xlated_prog_len", "xlated_len", "xlated"),
                "show_jited_size_bytes": extract_prog_size(after_info, "jited_prog_len", "jited_len", "jited"),
            },
            "daemon_submitted_xlated_insn_count": parse_int_like(daemon_pre_rejit.get("insn_count")),
            "daemon_submitted_xlated_raw_hex": daemon_pre_rejit.get("raw_hex_blob"),
            "daemon_submitted_xlated_hex_dump": format_hex_blob(
                daemon_pre_rejit.get("raw_hex_blob") if isinstance(daemon_pre_rejit.get("raw_hex_blob"), str) else None
            ),
            "daemon_runtime_final_xlated_insn_count": parse_int_like(daemon_final_xlated.get("insn_count")),
            "daemon_runtime_final_jited_size": parse_int_like(daemon_final_jited.get("byte_len")),
        }
    )
    return record


def process_object(
    *,
    entry: ObjectEntry,
    object_index: int,
    object_count: int,
    bpftool: str,
    daemon: DaemonServer,
    pin_root: Path,
) -> tuple[list[dict[str, object]], str]:
    rel_object = repo_relative(entry.object_path)
    print(f"[{object_index}/{object_count}] {rel_object}", flush=True)

    pin_dir = pin_root / f"{object_index:03d}-{sanitize_pin_component(entry.object_path.stem)}"
    records: list[dict[str, object]] = []

    try:
        load_command, load_attempts = try_loadall(bpftool, entry, pin_dir)
        if load_command is None:
            error_record = build_record_prefix(entry, object_index, None, None)
            error_record.update(
                {
                    "status": "skip_load",
                    "prog_name": None,
                    "verifier_accepted": None,
                    "applied": False,
                    "passes_applied": [],
                    "insn_count_before": None,
                    "insn_count_after": None,
                    "code_size_before": None,
                    "code_size_after": None,
                    "insn_delta": None,
                    "code_delta_bytes": None,
                    "before_xlated": None,
                    "after_xlated": None,
                    "before_jited": None,
                    "after_jited": None,
                    "loadall_attempts": load_attempts,
                }
            )
            print("  loadall: skipped", flush=True)
            return [error_record], "skip_load"

        pinned_programs = enumerate_pinned_programs(bpftool, pin_dir)
        if not pinned_programs:
            empty_record = build_record_prefix(entry, object_index, None, None)
            empty_record.update(
                {
                    "status": "skip_load",
                    "prog_name": None,
                    "verifier_accepted": None,
                    "applied": False,
                    "passes_applied": [],
                    "insn_count_before": None,
                    "insn_count_after": None,
                    "code_size_before": None,
                    "code_size_after": None,
                    "insn_delta": None,
                    "code_delta_bytes": None,
                    "before_xlated": None,
                    "after_xlated": None,
                    "before_jited": None,
                    "after_jited": None,
                    "loadall_attempts": load_attempts,
                    "load_command": command_text(load_command),
                    "load_error": "bpftool loadall succeeded but produced no pinned programs",
                }
            )
            print("  loadall: no pinned programs", flush=True)
            return [empty_record], "skip_load"

        print(f"  loadall: ok ({len(pinned_programs)} programs)", flush=True)
        for pinned_program in pinned_programs:
            prog_id = int(pinned_program["prog_id"])
            pinned_path = Path(str(pinned_program["pinned_path"]))
            try:
                record = process_program(
                    entry=entry,
                    object_index=object_index,
                    bpftool=bpftool,
                    daemon=daemon,
                    pinned_program=pinned_program,
                )
                record["load_command"] = command_text(load_command)
                record["loadall_attempts"] = load_attempts
                records.append(record)
                print(
                    "  "
                    f"{record['prog_name']} id={prog_id} "
                    f"applied={int(bool(record['applied']))} "
                    f"verifier={record['verifier_accepted']} "
                    f"insns={record['insn_count_before']}->{record['insn_count_after']} "
                    f"code={record['code_size_before']}->{record['code_size_after']}",
                    flush=True,
                )
            except Exception as exc:  # noqa: BLE001
                error_record = build_record_prefix(entry, object_index, pinned_path, prog_id)
                error_record.update(
                    {
                        "status": "error",
                        "prog_name": extract_prog_name(pinned_program["info"], pinned_path),
                        "verifier_accepted": None,
                        "applied": False,
                        "passes_applied": [],
                        "insn_count_before": None,
                        "insn_count_after": None,
                        "code_size_before": None,
                        "code_size_after": None,
                        "insn_delta": None,
                        "code_delta_bytes": None,
                        "before_xlated": None,
                        "after_xlated": None,
                        "before_jited": None,
                        "after_jited": None,
                        "load_command": command_text(load_command),
                        "loadall_attempts": load_attempts,
                        "error": str(exc),
                    }
                )
                records.append(error_record)
                print(f"  {pinned_path.name} id={prog_id} error: {exc}", flush=True)

        object_status = "ok" if all(record["status"] == "ok" for record in records) else "partial"
        return records, object_status
    finally:
        if path_exists(pin_dir):
            remove_tree(pin_dir)


def summarize(records: Sequence[Mapping[str, object]], object_statuses: Mapping[str, str]) -> dict[str, object]:
    program_records = [record for record in records if record.get("prog_name")]
    ok_programs = [record for record in program_records if record.get("status") == "ok"]
    applied_programs = [record for record in ok_programs if record.get("applied")]
    verifier_accepted_programs = [record for record in program_records if record.get("verifier_accepted") is True]
    applied_insn_deltas = [
        float(record["insn_delta"])
        for record in applied_programs
        if isinstance(record.get("insn_delta"), int)
    ]
    applied_code_deltas = [
        float(record["code_delta_bytes"])
        for record in applied_programs
        if isinstance(record.get("code_delta_bytes"), int)
    ]
    insn_deltas = [
        float(record["insn_delta"])
        for record in ok_programs
        if isinstance(record.get("insn_delta"), int)
    ]
    code_deltas = [
        float(record["code_delta_bytes"])
        for record in ok_programs
        if isinstance(record.get("code_delta_bytes"), int)
    ]
    summary = {
        "objects_total": len(object_statuses),
        "objects_ok": sum(1 for status in object_statuses.values() if status == "ok"),
        "objects_partial": sum(1 for status in object_statuses.values() if status == "partial"),
        "objects_skipped": sum(1 for status in object_statuses.values() if status == "skip_load"),
        "programs_total": len(program_records),
        "programs_ok": len(ok_programs),
        "programs_applied": len(applied_programs),
        "verifier_accepted_programs": len(verifier_accepted_programs),
        "avg_insn_delta": average(insn_deltas),
        "avg_code_delta_bytes": average(code_deltas),
        "avg_insn_delta_applied_only": average(applied_insn_deltas),
        "avg_code_delta_bytes_applied_only": average(applied_code_deltas),
    }
    return summary


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Load live .bpf.o programs in the VM, run daemon REJIT, and capture before/after dumps."
    )
    parser.add_argument(
        "--mode",
        choices=("all", "micro", "macro"),
        default="all",
        help="Which manifest set to scan. 'all' means micro + macro.",
    )
    parser.add_argument(
        "--output",
        default=str(DEFAULT_OUTPUT),
        help="Path to the output JSON file.",
    )
    parser.add_argument(
        "--daemon-binary",
        default=str(DEFAULT_DAEMON),
        help="Path to the daemon binary.",
    )
    parser.add_argument(
        "--bpftool",
        default="",
        help="Optional explicit bpftool binary. Defaults to the repo resolver/PATH.",
    )
    parser.add_argument(
        "--pin-root",
        default=str(DEFAULT_PIN_ROOT),
        help="bpffs directory used for temporary pinning during verification.",
    )
    parser.add_argument(
        "--socket-path",
        default=str(DEFAULT_SOCKET_PATH),
        help="Unix socket path for the long-running daemon serve mode.",
    )
    parser.add_argument(
        "--daemon-log",
        default="",
        help="Optional daemon log path. Defaults next to the output JSON.",
    )
    parser.add_argument(
        "--filter",
        default="",
        help="Only process objects whose path/target/program names contain this substring.",
    )
    parser.add_argument(
        "--max-objects",
        type=int,
        default=0,
        help="Optional limit for debugging.",
    )
    parser.add_argument(
        "--allow-micro-failures",
        action="store_true",
        help="Do not fail the run when any micro object is skipped or errors.",
    )
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    if os.geteuid() != 0:
        raise SystemExit("static_verify.py must run as root")

    output_path = Path(args.output).resolve()
    output_path.parent.mkdir(parents=True, exist_ok=True)
    daemon_binary = Path(args.daemon_binary).resolve()
    if not daemon_binary.exists():
        raise SystemExit(f"daemon binary not found: {daemon_binary}")

    bpftool = args.bpftool.strip() or prepare_bpftool_environment()
    pin_root = Path(args.pin_root)
    socket_path = Path(args.socket_path)
    daemon_log = Path(args.daemon_log).resolve() if args.daemon_log else output_path.with_suffix(".daemon.log")

    mode = args.mode
    if mode == "macro":
        manifest_mode = "all"
        filter_text = args.filter or ""
    else:
        manifest_mode = "all" if mode == "all" else "micro"
        filter_text = args.filter or ""

    objects, manifest_counts = collect_objects(manifest_mode, filter_text or None)
    if mode == "macro":
        objects = [entry for entry in objects if "macro" in entry.manifest_kinds]
    if args.max_objects > 0:
        objects = objects[: args.max_objects]

    ensure_bpffs()
    if path_exists(pin_root):
        remove_tree(pin_root)
    pin_root.mkdir(parents=True, exist_ok=True)

    daemon = DaemonServer(
        binary=daemon_binary,
        socket_path=socket_path,
        log_path=daemon_log,
        timeout_seconds=15,
    )

    records: list[dict[str, object]] = []
    object_statuses: dict[str, str] = {}
    micro_objects = {str(entry.object_path) for entry in objects if "micro" in entry.manifest_kinds}

    try:
        daemon.start()
        total_objects = len(objects)
        for index, entry in enumerate(objects, start=1):
            object_records, object_status = process_object(
                entry=entry,
                object_index=index,
                object_count=total_objects,
                bpftool=bpftool,
                daemon=daemon,
                pin_root=pin_root,
            )
            records.extend(object_records)
            object_statuses[str(entry.object_path)] = object_status
    finally:
        daemon.stop()
        if path_exists(pin_root):
            remove_tree(pin_root)

    summary = summarize(records, object_statuses)

    payload = {
        "generated_at_utc": datetime.now(timezone.utc).isoformat(),
        "kernel_release": run_command(["uname", "-r"], timeout=10).stdout.strip(),
        "mode": mode,
        "bpftool_binary": bpftool,
        "daemon_binary": str(daemon_binary),
        "daemon_log": str(daemon_log),
        "socket_path": str(socket_path),
        "manifest_counts": manifest_counts,
        "summary": summary,
        "records": records,
    }
    write_json(output_path, payload)

    micro_failures = sorted(
        repo_relative(Path(path))
        for path, status in object_statuses.items()
        if path in micro_objects and status != "ok"
    )

    print(
        "summary: "
        f"objects={summary['objects_total']} "
        f"programs={summary['programs_total']} "
        f"applied={summary['programs_applied']} "
        f"verifier_accepted={summary['verifier_accepted_programs']} "
        f"avg_insn_delta={format_average(summary['avg_insn_delta'])} "
        f"avg_code_delta={format_average(summary['avg_code_delta_bytes'])}",
        flush=True,
    )
    print(f"results: {output_path}", flush=True)

    if micro_failures and not args.allow_micro_failures:
        print(
            "micro gate failed: "
            f"{len(micro_failures)} micro objects did not complete successfully",
            file=sys.stderr,
            flush=True,
        )
        for path in micro_failures[:10]:
            print(f"  {path}", file=sys.stderr, flush=True)
        if len(micro_failures) > 10:
            print(f"  ... {len(micro_failures) - 10} more", file=sys.stderr, flush=True)
        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
