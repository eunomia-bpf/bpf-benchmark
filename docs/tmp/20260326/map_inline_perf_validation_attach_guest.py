#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import shlex
import statistics
import subprocess
import sys
import time
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[3]
RUNNER = REPO_ROOT / "runner" / "build" / "micro_exec"
DAEMON = REPO_ROOT / "daemon" / "target" / "release" / "bpfrejit-daemon"
BTF = REPO_ROOT / "vendor" / "linux-framework" / "vmlinux"
OUT_JSON = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_attach_20260326.json"
DAEMON_STDERR = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_attach_20260326.daemon.stderr.log"
DAEMON_STDOUT = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_attach_20260326.daemon.stdout.log"
SOCKET = f"/tmp/bpfrejit-map-inline-attach-{os.getpid()}.sock"

PASSES = [
    "map_inline",
    "const_prop",
    "dce",
    "wide_mem",
    "rotate",
    "cond_select",
    "extract",
    "endian_fusion",
    "bulk_memory",
    "bounds_check_merge",
    "skb_load_bytes",
    "branch_flip",
]
PASS_CSV = ",".join(PASSES)
MEASURE_ITERATIONS = 5

TARGETS = [
    {
        "canonical_name": "tracee:tracee.bpf.o:tracepoint__raw_syscalls__sys_enter",
        "object_path": "corpus/build/tracee/tracee.bpf.o",
        "program_name": "tracepoint__raw_syscalls__sys_enter",
        "workload_type": "getpid",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "tracee:tracee.bpf.o:tracepoint__raw_syscalls__sys_exit",
        "object_path": "corpus/build/tracee/tracee.bpf.o",
        "program_name": "tracepoint__raw_syscalls__sys_exit",
        "workload_type": "getpid",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "tracee:tracee.bpf.o:tracepoint__sched__sched_switch",
        "object_path": "corpus/build/tracee/tracee.bpf.o",
        "program_name": "tracepoint__sched__sched_switch",
        "workload_type": "nanosleep",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "bcc:libbpf-tools/syscount.bpf.o:sys_enter",
        "object_path": "corpus/build/bcc/libbpf-tools/syscount.bpf.o",
        "program_name": "sys_enter",
        "workload_type": "getpid",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "bcc:libbpf-tools/syscount.bpf.o:sys_exit",
        "object_path": "corpus/build/bcc/libbpf-tools/syscount.bpf.o",
        "program_name": "sys_exit",
        "workload_type": "getpid",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "bcc:libbpf-tools/cpudist.bpf.o:sched_switch_tp",
        "object_path": "corpus/build/bcc/libbpf-tools/cpudist.bpf.o",
        "program_name": "sched_switch_tp",
        "workload_type": "nanosleep",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "bcc:libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve",
        "object_path": "corpus/build/bcc/libbpf-tools/execsnoop.bpf.o",
        "program_name": "tracepoint__syscalls__sys_enter_execve",
        "workload_type": "mixed",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "bcc:libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_openat",
        "object_path": "corpus/build/bcc/libbpf-tools/opensnoop.bpf.o",
        "program_name": "tracepoint__syscalls__sys_enter_openat",
        "workload_type": "mixed",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
    {
        "canonical_name": "tetragon:bpf_execve_event.bpf.o:event_execve",
        "object_path": "corpus/build/tetragon/bpf_execve_event.bpf.o",
        "program_name": "event_execve",
        "workload_type": "mixed",
        "workload_iterations": 1,
        "repeat": 100,
        "warmup": 1,
    },
]


def serialize_for_json(value):
    if isinstance(value, Path):
        return str(value)
    if isinstance(value, dict):
        return {key: serialize_for_json(item) for key, item in value.items()}
    if isinstance(value, list):
        return [serialize_for_json(item) for item in value]
    return value


def write_output(payload: dict) -> None:
    OUT_JSON.write_text(json.dumps(serialize_for_json(payload), indent=2) + "\n")


def run_command(command: list[str]) -> dict:
    started = time.time()
    completed = subprocess.run(
        command,
        cwd=REPO_ROOT,
        capture_output=True,
        text=True,
        check=False,
    )
    return {
        "command": command,
        "command_text": shlex.join(command),
        "returncode": completed.returncode,
        "stdout": completed.stdout,
        "stderr": completed.stderr,
        "elapsed_s": time.time() - started,
    }


def extract_json_payload(text: str):
    for line in reversed(text.splitlines()):
        stripped = line.strip()
        if not stripped:
            continue
        try:
            return json.loads(stripped)
        except json.JSONDecodeError:
            continue
    return None


def sample_from_stdout(text: str) -> dict | None:
    payload = extract_json_payload(text)
    if isinstance(payload, list) and payload:
        for item in reversed(payload):
            if isinstance(item, dict):
                return item
    if isinstance(payload, dict):
        return payload
    return None


def extract_map_inline_details(sample: dict | None) -> dict:
    if not sample:
        return {}
    rejit = sample.get("rejit") or {}
    raw_response = rejit.get("daemon_response")
    if not raw_response:
        return {
            "rejit_requested": bool(rejit.get("requested")),
            "rejit_applied": bool(rejit.get("applied")),
            "passes_applied": list(rejit.get("passes_applied") or []),
            "total_sites_applied": int(rejit.get("total_sites_applied") or 0),
        }
    if isinstance(raw_response, dict):
        daemon_response = raw_response
    else:
        try:
            daemon_response = json.loads(raw_response)
        except json.JSONDecodeError:
            return {
                "rejit_requested": bool(rejit.get("requested")),
                "rejit_applied": bool(rejit.get("applied")),
                "passes_applied": list(rejit.get("passes_applied") or []),
                "total_sites_applied": int(rejit.get("total_sites_applied") or 0),
                "daemon_response_parse_error": "invalid_json",
            }

    map_inline_pass = None
    for pass_detail in daemon_response.get("passes") or []:
        if pass_detail.get("pass_name") == "map_inline":
            map_inline_pass = pass_detail
            break

    return {
        "rejit_requested": bool(rejit.get("requested")),
        "rejit_applied": bool(rejit.get("applied")),
        "passes_applied": list(rejit.get("passes_applied") or []),
        "total_sites_applied": int(rejit.get("total_sites_applied") or 0),
        "insn_delta": int(rejit.get("insn_delta") or 0),
        "verifier_retries": int(rejit.get("verifier_retries") or 0),
        "final_disabled_passes": list(rejit.get("final_disabled_passes") or []),
        "map_inline_changed": bool((map_inline_pass or {}).get("changed")),
        "map_inline_sites_applied": int((map_inline_pass or {}).get("sites_applied") or 0),
        "map_inline_sites_skipped": int((map_inline_pass or {}).get("sites_skipped") or 0),
        "map_inline_skip_reasons": (map_inline_pass or {}).get("skip_reasons") or {},
        "map_inline_diagnostics": list((map_inline_pass or {}).get("diagnostics") or []),
    }


def build_screen_command(target: dict) -> list[str]:
    return [
        str(RUNNER),
        "run-kernel",
        "--program",
        str(REPO_ROOT / target["object_path"]),
        "--program-name",
        target["program_name"],
        "--btf-custom-path",
        str(BTF),
        "--compile-only",
        "--rejit",
        "--daemon-socket",
        SOCKET,
        "--passes",
        PASS_CSV,
    ]


def build_measure_command(target: dict, *, rejit: bool) -> list[str]:
    command = [
        str(RUNNER),
        "run-kernel-attach",
        "--program",
        str(REPO_ROOT / target["object_path"]),
        "--program-name",
        target["program_name"],
        "--btf-custom-path",
        str(BTF),
        "--workload-type",
        target["workload_type"],
        "--workload-iterations",
        str(target["workload_iterations"]),
        "--warmup",
        str(target["warmup"]),
        "--repeat",
        str(target["repeat"]),
    ]
    if rejit:
        command.extend(
            [
                "--rejit",
                "--daemon-socket",
                SOCKET,
                "--passes",
                PASS_CSV,
            ]
        )
    return command


def screen_target(target: dict) -> dict:
    invocation = run_command(build_screen_command(target))
    sample = sample_from_stdout(invocation["stdout"])
    return {
        "target": target,
        "compile_only_invocation": invocation,
        "compile_only_sample": sample,
        "compile_only_rejit": extract_map_inline_details(sample),
    }


def measure_target(target: dict) -> dict:
    stock_runs = []
    rejit_runs = []
    for _ in range(MEASURE_ITERATIONS):
        stock_invocation = run_command(build_measure_command(target, rejit=False))
        stock_sample = sample_from_stdout(stock_invocation["stdout"])
        stock_runs.append({"invocation": stock_invocation, "sample": stock_sample})

        rejit_invocation = run_command(build_measure_command(target, rejit=True))
        rejit_sample = sample_from_stdout(rejit_invocation["stdout"])
        rejit_runs.append(
            {
                "invocation": rejit_invocation,
                "sample": rejit_sample,
                "rejit": extract_map_inline_details(rejit_sample),
            }
        )

    stock_exec_values = [
        int(run["sample"]["exec_ns"])
        for run in stock_runs
        if run.get("sample") and run["sample"].get("exec_ns") is not None
    ]
    rejit_exec_values = [
        int(run["sample"]["exec_ns"])
        for run in rejit_runs
        if run.get("sample") and run["sample"].get("exec_ns") is not None
    ]
    stock_median = statistics.median(stock_exec_values) if stock_exec_values else None
    rejit_median = statistics.median(rejit_exec_values) if rejit_exec_values else None
    speedup_ratio = None
    if stock_median not in (None, 0) and rejit_median not in (None, 0):
        speedup_ratio = stock_median / rejit_median

    representative_rejit = next(
        (run["rejit"] for run in rejit_runs if (run.get("rejit") or {}).get("map_inline_sites_applied", 0) >= 0),
        {},
    )
    return {
        "target": target,
        "stock_runs": stock_runs,
        "rejit_runs": rejit_runs,
        "stock_exec_ns_values": stock_exec_values,
        "rejit_exec_ns_values": rejit_exec_values,
        "stock_exec_ns_median": stock_median,
        "rejit_exec_ns_median": rejit_median,
        "speedup_ratio": speedup_ratio,
        "representative_rejit": representative_rejit,
    }


def start_daemon() -> subprocess.Popen:
    Path(SOCKET).unlink(missing_ok=True)
    DAEMON_STDERR.parent.mkdir(parents=True, exist_ok=True)
    daemon_stdout = open(DAEMON_STDOUT, "w")
    daemon_stderr = open(DAEMON_STDERR, "w")
    process = subprocess.Popen(
        [str(DAEMON), "--pgo", "serve", "--socket", SOCKET],
        cwd=REPO_ROOT,
        stdout=daemon_stdout,
        stderr=daemon_stderr,
        text=True,
    )
    deadline = time.time() + 10.0
    while time.time() < deadline:
        if process.poll() is not None:
            raise RuntimeError(f"daemon exited early with code {process.returncode}")
        if Path(SOCKET).exists():
            return process
        time.sleep(0.1)
    raise RuntimeError("daemon socket did not appear")


def stop_daemon(process: subprocess.Popen | None) -> None:
    if process is None:
        return
    process.terminate()
    try:
        process.wait(timeout=5)
    except subprocess.TimeoutExpired:
        process.kill()
        process.wait(timeout=5)
    Path(SOCKET).unlink(missing_ok=True)


def main() -> int:
    payload = {
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "passes": PASSES,
        "measure_iterations": MEASURE_ITERATIONS,
        "targets": TARGETS,
        "screening": [],
        "measurements": [],
        "errors": [],
    }
    write_output(payload)

    daemon_proc = None
    try:
        daemon_proc = start_daemon()
        for target in TARGETS:
            record = screen_target(target)
            payload["screening"].append(record)
            write_output(payload)

        measured_targets = [
            record["target"]
            for record in payload["screening"]
            if (record.get("compile_only_rejit") or {}).get("map_inline_sites_applied", 0) > 0
        ]
        for target in measured_targets:
            measurement = measure_target(target)
            payload["measurements"].append(measurement)
            write_output(payload)
    except Exception as exc:  # pragma: no cover - temp guest script
        payload["errors"].append(str(exc))
        write_output(payload)
        raise
    finally:
        stop_daemon(daemon_proc)

    payload["summary"] = {
        "screened": len(payload["screening"]),
        "map_inline_hits": len(payload["measurements"]),
        "measured_names": [item["target"]["canonical_name"] for item in payload["measurements"]],
        "output_json": str(OUT_JSON),
    }
    write_output(payload)
    print(json.dumps(payload["summary"], indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
