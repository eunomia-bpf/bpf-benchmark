"""BpfReJIT v2 helpers for live enumeration and apply flows."""
from __future__ import annotations

import json
import os
import shutil
import socket
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Any, Mapping, Sequence

from . import tail_text


_PASS_TO_SITE_FIELD = {
    "map_inline": "map_inline_sites",
    "const_prop": "const_prop_sites",
    "dce": "dce_sites",
    "branch_flip": "branch_flip_sites",
    "cond_select": "cmov_sites",
    "endian_fusion": "endian_sites",
    "extract": "extract_sites",
    "rotate": "rotate_sites",
    "wide_mem": "wide_sites",
}
_DEFAULT_REJIT_ENABLED_PASSES = ("map_inline", "const_prop", "dce")
_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"
_DEFAULT_APPLY_TIMEOUT_SECONDS = 120.0


def _parse_enabled_passes(raw: str | None) -> list[str]:
    text = str(raw or "").strip()
    if not text:
        return []
    if text.lower() in {"default", "benchmark-default"}:
        return list(_DEFAULT_REJIT_ENABLED_PASSES)
    return [token.strip() for token in text.split(",") if token.strip()]

def _zero_site_counts() -> dict[str, int]:
    return {
        "total_sites": 0,
        "map_inline_sites": 0,
        "const_prop_sites": 0,
        "dce_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "extract_sites": 0,
        "bitfield_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
    }


def _parse_last_json_object(text: str) -> dict[str, Any] | None:
    for line in reversed(text.splitlines()):
        payload = line.strip()
        if not payload or not payload.startswith("{"):
            continue
        try:
            parsed = json.loads(payload)
        except json.JSONDecodeError:
            continue
        if isinstance(parsed, dict):
            return parsed
    return None


def _parse_site_summary(site_summary: str) -> dict[str, int]:
    counts = _zero_site_counts()
    text = site_summary.strip()
    if not text or text == "-":
        return counts

    for token in text.split():
        pass_name, separator, raw_value = token.partition("=")
        if separator != "=":
            continue
        field_name = _PASS_TO_SITE_FIELD.get(pass_name)
        if field_name is None:
            continue
        try:
            counts[field_name] += int(raw_value)
        except ValueError:
            continue

    counts["bitfield_sites"] = counts["extract_sites"]
    counts["total_sites"] = sum(
        counts[field_name]
        for field_name in (
            "map_inline_sites",
            "const_prop_sites",
            "dce_sites",
            "cmov_sites",
            "wide_sites",
            "rotate_sites",
            "lea_sites",
            "extract_sites",
            "endian_sites",
            "branch_flip_sites",
        )
    )
    return counts


def _daemon_command(
    daemon: Path | str,
    subcommand: str,
    *subcommand_args: object,
) -> list[str]:
    command = [str(daemon)]
    command.append(subcommand)
    command.extend(str(arg) for arg in subcommand_args)
    return command


def benchmark_rejit_enabled_passes() -> list[str]:
    if _BENCH_PASSES_ENV not in os.environ:
        return list(_DEFAULT_REJIT_ENABLED_PASSES)
    return _parse_enabled_passes(os.environ.get(_BENCH_PASSES_ENV))


def _parse_enumerate_table(stdout: str) -> dict[int, dict[str, Any]]:
    records: dict[int, dict[str, Any]] = {}
    for line in stdout.splitlines():
        text = line.rstrip()
        if not text or text.startswith("ID") or set(text) == {"-"}:
            continue

        fields = text.split(None, 4)
        if len(fields) < 4 or not fields[0].isdigit():
            continue

        prog_id = int(fields[0])
        prog_type = int(fields[1])
        insn_count = int(fields[2])
        prog_name = fields[3]
        site_summary = fields[4] if len(fields) >= 5 else "-"
        site_counts = _parse_site_summary(site_summary)

        records[prog_id] = {
            "prog_id": prog_id,
            "prog_type": prog_type,
            "type": prog_type,
            "name": prog_name,
            "insn_count": insn_count,
            "site_summary": site_summary,
            "sites": dict(site_counts),
            "counts": dict(site_counts),
            "total_sites": int(site_counts["total_sites"]),
        }
    return records


def _run_enumerate(
    daemon: Path | str,
    *,
    timeout_seconds: int,
) -> dict[int, dict[str, Any]]:
    command = _daemon_command(daemon, "enumerate")
    completed = subprocess.run(
        command,
        capture_output=True,
        text=True,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(f"enumerate failed (rc={completed.returncode}): {detail}")

    stdout = completed.stdout.strip()
    if not stdout:
        raise RuntimeError("enumerate produced no output")

    records = _parse_enumerate_table(stdout)
    if not records:
        raise RuntimeError(f"enumerate output did not contain any program records:\n{stdout[:2000]}")
    return records


def enumerate_program_record(
    daemon: Path | str,
    prog_id: int,
    *,
    timeout_seconds: int = 60,
) -> dict[str, Any]:
    """Return the parsed daemon enumerate record for a specific live prog_id."""
    records = _run_enumerate(daemon, timeout_seconds=timeout_seconds)
    try:
        return records[int(prog_id)]
    except KeyError as exc:
        raise RuntimeError(f"prog {prog_id} not found in daemon enumerate output") from exc


def scan_programs(
    prog_ids: list[int],
    daemon: Path | str,
    *,
    prog_fds: dict[int, int] | None = None,
    timeout_seconds: int = 60,
) -> dict[int, dict[str, Any]]:
    """Collect enumerate site summaries for the requested live prog_ids."""
    del prog_fds

    requested_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not requested_ids:
        return {}

    try:
        records = _run_enumerate(daemon, timeout_seconds=timeout_seconds)
    except Exception as exc:
        error = str(exc)
        return {
            prog_id: {
                "enumerate_record": None,
                "sites": _zero_site_counts(),
                "counts": _zero_site_counts(),
                "error": error,
            }
            for prog_id in requested_ids
        }

    results: dict[int, dict[str, Any]] = {}
    for prog_id in requested_ids:
        record = records.get(prog_id)
        if record is None:
            zero = _zero_site_counts()
            results[prog_id] = {
                "enumerate_record": None,
                "sites": dict(zero),
                "counts": dict(zero),
                "error": f"prog {prog_id} not found in daemon enumerate output",
            }
            continue

        site_counts = dict(record.get("sites") or _zero_site_counts())
        results[prog_id] = {
            "enumerate_record": dict(record),
            "sites": dict(site_counts),
            "counts": dict(site_counts),
            "error": "",
        }
    return results


def _apply_one(
    daemon_binary: Path | str,
    prog_id: int,
    *,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object]:
    try:
        result = subprocess.run(
            _daemon_command(daemon_binary, "apply", prog_id),
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        detail = f"apply timed out after {timeout_seconds:.0f}s for prog {prog_id}"
        return {
            "applied": False,
            "output": (exc.stdout or "") + (exc.stderr or ""),
            "exit_code": 124,
            "debug_result": {},
            "kernel_prog_name": "",
            "inlined_map_entries": [],
            "summary": {},
            "counts": {
                "total_sites": 0,
                "applied_sites": 0,
            },
            "error": detail,
        }
    combined_output = result.stdout + result.stderr
    debug_result = _parse_last_json_object(f"{result.stderr}\n{result.stdout}")
    summary = debug_result.get("summary") if isinstance(debug_result, Mapping) else {}
    program = debug_result.get("program") if isinstance(debug_result, Mapping) else {}
    raw_inlined_entries = (
        debug_result.get("inlined_map_entries") if isinstance(debug_result, Mapping) else []
    )
    if not isinstance(raw_inlined_entries, list):
        raw_inlined_entries = []
    inlined_map_entries = [
        dict(entry) for entry in raw_inlined_entries if isinstance(entry, Mapping)
    ]
    applied_sites = int((summary or {}).get("total_sites_applied", 0) or 0)
    error_message = ""
    if isinstance(debug_result, Mapping):
        error_message = str(debug_result.get("error_message") or "")
    if not error_message and result.returncode != 0:
        error_message = combined_output.strip()

    return {
        "applied": result.returncode == 0 and bool((summary or {}).get("applied", True)),
        "output": combined_output,
        "exit_code": result.returncode,
        "debug_result": debug_result,
        "kernel_prog_name": str((program or {}).get("prog_name") or ""),
        "inlined_map_entries": inlined_map_entries,
        "summary": dict(summary) if isinstance(summary, Mapping) else {},
        "counts": {
            "total_sites": applied_sites,
            "applied_sites": applied_sites,
        },
        "error": error_message,
    }


def _apply_result_from_response(
    response: Mapping[str, Any],
    *,
    output: str,
    exit_code: int,
) -> dict[str, object]:
    summary = response.get("summary") if isinstance(response, Mapping) else {}
    program = response.get("program") if isinstance(response, Mapping) else {}
    raw_inlined_entries = response.get("inlined_map_entries") if isinstance(response, Mapping) else []
    if not isinstance(raw_inlined_entries, list):
        raw_inlined_entries = []
    inlined_map_entries = [
        dict(entry) for entry in raw_inlined_entries if isinstance(entry, Mapping)
    ]
    applied_sites = int((summary or {}).get("total_sites_applied", 0) or 0)
    error_message = str(response.get("error_message") or response.get("message") or "").strip()
    return {
        "applied": exit_code == 0 and bool((summary or {}).get("applied", True)),
        "output": output,
        "exit_code": exit_code,
        "debug_result": dict(response),
        "kernel_prog_name": str((program or {}).get("prog_name") or ""),
        "inlined_map_entries": inlined_map_entries,
        "summary": dict(summary) if isinstance(summary, Mapping) else {},
        "counts": {
            "total_sites": applied_sites,
            "applied_sites": applied_sites,
        },
        "error": error_message,
    }


def _socket_error_result(
    prog_id: int,
    detail: str,
    *,
    exit_code: int = 1,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
) -> dict[str, object]:
    notes: list[str] = [detail]
    if daemon_proc is not None:
        returncode = daemon_proc.poll()
        notes.append(
            f"daemon serve rc={returncode}" if returncode is not None else "daemon serve still running"
        )

    log_tail = _daemon_log_tail(stdout_path, stderr_path)
    if log_tail:
        notes.append(f"daemon log tail:\n{log_tail}")

    message = "\n".join(notes)
    return {
        "applied": False,
        "output": log_tail,
        "exit_code": exit_code,
        "debug_result": {},
        "kernel_prog_name": "",
        "inlined_map_entries": [],
        "summary": {},
        "counts": {
            "total_sites": 0,
            "applied_sites": 0,
        },
        "error": message,
    }


def _daemon_log_tail(stdout_path: Path | None, stderr_path: Path | None) -> str:
    fragments: list[str] = []
    for path in (stderr_path, stdout_path):
        if path is None:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        if text.strip():
            fragments.append(text)
    return tail_text("\n".join(fragments), max_lines=80, max_chars=8000)


def _start_daemon_server(
    daemon_binary: Path | str,
) -> tuple[subprocess.Popen[str], Path, str, Path, Path]:
    socket_dir = tempfile.mkdtemp(prefix="bpfrejit-daemon-")
    socket_path = Path(socket_dir) / "daemon.sock"
    stdout_path = Path(socket_dir) / "daemon.stdout.log"
    stderr_path = Path(socket_dir) / "daemon.stderr.log"
    stdout_handle = stdout_path.open("w", encoding="utf-8")
    stderr_handle = stderr_path.open("w", encoding="utf-8")
    try:
        proc = subprocess.Popen(
            [str(daemon_binary), "serve", "--socket", str(socket_path)],
            stdout=stdout_handle,
            stderr=stderr_handle,
            text=True,
        )
    finally:
        stdout_handle.close()
        stderr_handle.close()

    deadline = time.monotonic() + 5.0
    while time.monotonic() < deadline:
        if socket_path.exists():
            return proc, socket_path, socket_dir, stdout_path, stderr_path
        if proc.poll() is not None:
            raise RuntimeError(
                f"daemon serve exited early (rc={proc.returncode}): "
                f"{_daemon_log_tail(stdout_path, stderr_path)}"
            )
        time.sleep(0.05)
    proc.terminate()
    try:
        proc.wait(timeout=1)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait(timeout=1)
    raise RuntimeError(
        f"timed out waiting for daemon socket: {_daemon_log_tail(stdout_path, stderr_path)}"
    )


def _stop_daemon_server(proc: subprocess.Popen[str], socket_path: Path, socket_dir: str) -> None:
    proc.terminate()
    try:
        proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait(timeout=5)
    socket_path.unlink(missing_ok=True)
    shutil.rmtree(socket_dir, ignore_errors=True)


def _apply_one_via_socket(
    socket_path: Path,
    prog_id: int,
    enabled_passes: Sequence[str],
    *,
    daemon_proc: subprocess.Popen[str] | None = None,
    stdout_path: Path | None = None,
    stderr_path: Path | None = None,
    timeout_seconds: float = _DEFAULT_APPLY_TIMEOUT_SECONDS,
) -> dict[str, object]:
    payload: dict[str, object] = {
        "cmd": "optimize",
        "prog_id": int(prog_id),
    }
    normalized_passes = [str(name).strip() for name in enabled_passes if str(name).strip()]
    payload["enabled_passes"] = normalized_passes
    request = json.dumps(payload) + "\n"
    with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
        client.settimeout(timeout_seconds)
        try:
            client.connect(str(socket_path))
            client.sendall(request.encode())
            chunks: list[bytes] = []
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    break
                chunks.append(chunk)
                if b"\n" in chunk:
                    break
        except socket.timeout:
            return _socket_error_result(
                prog_id,
                f"socket optimize timed out after {timeout_seconds:.0f}s for prog {prog_id}",
                exit_code=124,
                daemon_proc=daemon_proc,
                stdout_path=stdout_path,
                stderr_path=stderr_path,
            )
        except OSError as exc:
            return _socket_error_result(
                prog_id,
                f"socket optimize failed for prog {prog_id}: {exc}",
                daemon_proc=daemon_proc,
                stdout_path=stdout_path,
                stderr_path=stderr_path,
            )
    line = b"".join(chunks).decode(errors="replace").strip()
    if not line:
        return _socket_error_result(
            prog_id,
            f"daemon socket returned an empty response for prog {prog_id}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    try:
        response = json.loads(line)
    except json.JSONDecodeError as exc:
        return _socket_error_result(
            prog_id,
            f"daemon socket returned invalid JSON for prog {prog_id}: {exc}: {line[:400]}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    if not isinstance(response, Mapping):
        return _socket_error_result(
            prog_id,
            f"daemon socket returned non-object JSON for prog {prog_id}: {line[:400]}",
            daemon_proc=daemon_proc,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
        )
    if str(response.get("status") or "") != "ok":
        return _apply_result_from_response(response, output=line, exit_code=1)
    return _apply_result_from_response(response, output=line, exit_code=0)


def apply_daemon_rejit(
    daemon_binary: Path | str,
    prog_ids: list[int] | None = None,
    *,
    enabled_passes: Sequence[str] | None = None,
) -> dict[str, object]:
    """Call daemon apply or apply-all and return a canonical ReJIT summary."""
    if prog_ids:
        per_program: dict[int, dict[str, object]] = {}
        outputs: list[str] = []
        exit_code = 0
        all_applied = True
        total_sites = 0
        applied_sites = 0
        errors: list[str] = []
        daemon_proc = None
        daemon_socket_path = None
        daemon_socket_dir = None
        daemon_stdout_path = None
        daemon_stderr_path = None

        if enabled_passes is not None:
            (
                daemon_proc,
                daemon_socket_path,
                daemon_socket_dir,
                daemon_stdout_path,
                daemon_stderr_path,
            ) = _start_daemon_server(daemon_binary)

        try:
            for prog_id in [int(value) for value in prog_ids if int(value) > 0]:
                if enabled_passes is not None:
                    assert daemon_socket_path is not None
                    result = _apply_one_via_socket(
                        daemon_socket_path,
                        prog_id,
                        enabled_passes,
                        daemon_proc=daemon_proc,
                        stdout_path=daemon_stdout_path,
                        stderr_path=daemon_stderr_path,
                    )
                else:
                    result = _apply_one(daemon_binary, prog_id)
                per_program[prog_id] = result
                outputs.append(str(result.get("output") or ""))
                exit_code = max(exit_code, int(result.get("exit_code", 0) or 0))
                all_applied = all_applied and bool(result.get("applied", False))

                counts = result.get("counts") if isinstance(result.get("counts"), Mapping) else {}
                total_sites += int((counts or {}).get("total_sites", 0) or 0)
                applied_sites += int((counts or {}).get("applied_sites", 0) or 0)

                error = str(result.get("error") or "").strip()
                if error:
                    errors.append(f"prog {prog_id}: {error}")
        finally:
            if daemon_proc is not None and daemon_socket_path is not None and daemon_socket_dir is not None:
                _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)

        return {
            "applied": all_applied,
            "output": "\n".join(output for output in outputs if output),
            "exit_code": exit_code,
            "per_program": per_program,
            "counts": {
                "total_sites": total_sites,
                "applied_sites": applied_sites,
            },
            "error": "; ".join(errors),
        }

    result = subprocess.run(
        _daemon_command(daemon_binary, "apply-all"),
        capture_output=True,
        text=True,
    )
    combined_output = result.stdout + result.stderr
    return {
        "applied": result.returncode == 0,
        "output": combined_output,
        "exit_code": result.returncode,
        "error": combined_output.strip() if result.returncode != 0 else "",
    }


__all__ = [
    "apply_daemon_rejit",
    "benchmark_rejit_enabled_passes",
    "enumerate_program_record",
    "scan_programs",
]
