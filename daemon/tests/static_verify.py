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
    run_command,
    tail_text,
    write_json,
)
from runner.libs.batch_runner import run_batch_runner  # noqa: E402
from runner.libs.catalog import (  # noqa: E402
    DEFAULT_MACRO_MANIFEST,
    DEFAULT_MICRO_MANIFEST,
    CatalogTarget,
    load_catalog,
)


DEFAULT_RESULTS_DIR = ROOT_DIR / "daemon" / "tests" / "results"
DEFAULT_OUTPUT = DEFAULT_RESULTS_DIR / "static_verify.json"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_PIN_ROOT = Path("/sys/fs/bpf/static_verify")
DEFAULT_SOCKET_PATH = Path("/tmp/bpfrejit-static-verify.sock")
DEFAULT_DAEMON_TIMEOUT = 60

INT_WITH_SUFFIX_RE = re.compile(r"^\s*(\d+)(?:B)?\s*$")


def repo_relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT_DIR))
    except ValueError:
        return str(path.resolve())


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
    extra_args: list[str] = field(default_factory=list)
    process: subprocess.Popen[str] | None = None
    log_file: Any | None = None

    def start(self) -> None:
        self.log_path.parent.mkdir(parents=True, exist_ok=True)
        if path_exists(self.socket_path):
            self.socket_path.unlink()
        self.log_file = self.log_path.open("w", encoding="utf-8")
        self.process = subprocess.Popen(
            [str(self.binary), *self.extra_args, "serve", "--socket", str(self.socket_path)],
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


def static_verify_parallel_jobs() -> int:
    cpu_count = os.cpu_count() or 1
    return max(1, min(8, int(cpu_count * 0.8) or 1))


def build_static_batch_job(
    *,
    entry: ObjectEntry,
    object_index: int,
    daemon_socket: Path,
) -> dict[str, object]:
    return {
        "id": f"object-{object_index:04d}",
        "type": "static_verify_object",
        "execution": "parallel",
        "object": str(entry.object_path),
        "object_index": object_index,
        "daemon_socket": str(daemon_socket),
        "manifest_kinds": list(entry.manifest_kinds),
        "target_names": list(entry.target_names),
        "program_names_from_manifest": list(entry.program_names),
        "sections_from_manifest": list(entry.sections),
        "prog_types": list(entry.prog_types),
    }


def batch_result_map(batch_payload: Mapping[str, object] | None) -> dict[str, dict[str, object]]:
    if not isinstance(batch_payload, Mapping):
        return {}
    jobs = batch_payload.get("jobs")
    if not isinstance(jobs, list):
        return {}
    mapped: dict[str, dict[str, object]] = {}
    for item in jobs:
        if not isinstance(item, Mapping):
            continue
        job_id = item.get("id")
        if isinstance(job_id, str) and job_id:
            mapped[job_id] = dict(item)
    return mapped


def merge_batch_record(
    *,
    entry: ObjectEntry,
    object_index: int,
    record: Mapping[str, object],
) -> dict[str, object]:
    prog_id = parse_int_like(record.get("prog_id"))
    prefix = build_record_prefix(entry, object_index, None, prog_id)
    merged = dict(prefix)
    merged.update(dict(record))
    return merged


def synthesize_failed_job_record(
    *,
    entry: ObjectEntry,
    object_index: int,
    job_result: Mapping[str, object],
) -> dict[str, object]:
    record = build_record_prefix(entry, object_index, None, None)
    record.update(
        {
            "status": "error",
            "prog_name": None,
            "verifier_accepted": None,
            "applied": False,
            "program_changed": False,
            "passes_applied": [],
            "daemon_status": "error",
            "daemon_message": None,
            "daemon_error_message": None,
            "daemon_verifier_retries": None,
            "daemon_final_disabled_passes": [],
            "insn_count_before": None,
            "insn_count_after": None,
            "code_size_before": None,
            "code_size_after": None,
            "before_jited_size": None,
            "after_jited_size": None,
            "insn_delta": None,
            "daemon_submitted_insn_delta": None,
            "code_delta_bytes": None,
            "before_xlated": None,
            "after_xlated": None,
            "before_jited": None,
            "after_jited": None,
            "daemon_submitted_xlated_insn_count": None,
            "daemon_runtime_final_xlated_insn_count": None,
            "daemon_runtime_final_jited_size": None,
            "after_xlated_count_mismatch": False,
            "after_xlated_count_mismatch_note": None,
            "load_command": None,
            "loadall_attempts": [],
            "load_error": None,
            "error": str(job_result.get("error") or "batch job failed without a payload"),
        }
    )
    return record


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
        "--daemon-args",
        default="",
        help="Extra arguments passed to the daemon before `serve`.",
    )
    parser.add_argument(
        "--runner-binary",
        default=str(DEFAULT_RUNNER),
        help="Path to the runner batch binary.",
    )
    parser.add_argument(
        "--bpftool",
        default="",
        help="Deprecated. Kept for compatibility; no longer used by the batch path.",
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
    runner_binary = Path(args.runner_binary).resolve()
    if not runner_binary.exists():
        raise SystemExit(f"runner binary not found: {runner_binary}")

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

    daemon = DaemonServer(
        binary=daemon_binary,
        socket_path=socket_path,
        log_path=daemon_log,
        timeout_seconds=15,
        extra_args=shlex.split(args.daemon_args),
    )

    records: list[dict[str, object]] = []
    object_statuses: dict[str, str] = {}
    micro_objects = {str(entry.object_path) for entry in objects if "micro" in entry.manifest_kinds}

    try:
        daemon.start()
        print(
            f"static_verify: dispatching {len(objects)} objects via C++ batch runner "
            f"(parallel_jobs={static_verify_parallel_jobs()})",
            flush=True,
        )
        batch_spec = {
            "schema_version": 1,
            "scheduler": {"max_parallel_jobs": static_verify_parallel_jobs()},
            "jobs": [
                build_static_batch_job(
                    entry=entry,
                    object_index=index,
                    daemon_socket=socket_path,
                )
                for index, entry in enumerate(objects, start=1)
            ],
        }
        batch_result = run_batch_runner(
            runner_binary,
            spec_payload=batch_spec,
            cwd=ROOT_DIR,
            capture_logs=True,
            write_progress=True,
        )
        if not batch_result["ok"]:
            raise RuntimeError(
                (batch_result["error"] or "static verify batch runner failed")
                + "\n"
                + "batch runner stdout tail:\n"
                + (str(batch_result.get("stdout") or "").strip() or "<empty>")
                + "\n"
                + "batch runner stderr tail:\n"
                + (str(batch_result.get("stderr") or "").strip() or "<empty>")
            )
        batch_jobs = batch_result_map(batch_result.get("result"))
        for index, entry in enumerate(objects, start=1):
            job_id = f"object-{index:04d}"
            job_result = batch_jobs.get(job_id)
            if not job_result:
                raise RuntimeError(f"missing batch result for {job_id}")
            payload = job_result.get("payload")
            if not isinstance(payload, Mapping):
                object_statuses[str(entry.object_path)] = "partial"
                records.append(
                    synthesize_failed_job_record(
                        entry=entry,
                        object_index=index,
                        job_result=job_result,
                    )
                )
                continue
            object_status = str(payload.get("object_status") or "error")
            object_statuses[str(entry.object_path)] = object_status
            payload_records = payload.get("records")
            if not isinstance(payload_records, list):
                raise RuntimeError(f"batch payload records for {job_id} were not a list")
            for record in payload_records:
                if not isinstance(record, Mapping):
                    continue
                records.append(
                    merge_batch_record(
                        entry=entry,
                        object_index=index,
                        record=record,
                    )
                )
    finally:
        daemon.stop()

    summary = summarize(records, object_statuses)

    payload = {
        "generated_at_utc": datetime.now(timezone.utc).isoformat(),
        "kernel_release": run_command(["uname", "-r"], timeout=10).stdout.strip(),
        "mode": mode,
        "runner_binary": str(runner_binary),
        "bpftool_binary": None,
        "daemon_binary": str(daemon_binary),
        "daemon_log": str(daemon_log),
        "socket_path": str(socket_path),
        "pin_root": str(pin_root),
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
