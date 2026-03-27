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
OUT_JSON = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_20260326.json"
DAEMON_STDERR = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_20260326.daemon.stderr.log"
DAEMON_STDOUT = REPO_ROOT / "docs" / "tmp" / "20260326" / "map_inline_perf_validation_20260326.daemon.stdout.log"
SOCKET = f"/tmp/bpfrejit-map-inline-{os.getpid()}.sock"

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
SCREEN_REPEAT = 100
MEASURE_REPEAT = 100
MEASURE_ITERATIONS = 5
WARMUP_REPEAT = 1

TARGETS = [
    {
        "canonical_name": "katran:xdp_pktcntr.bpf.o:pktcntr",
        "object_path": "corpus/build/katran/xdp_pktcntr.bpf.o",
        "program_name": "pktcntr",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "katran:balancer.bpf.o:balancer_ingress",
        "object_path": "corpus/build/katran/balancer.bpf.o",
        "program_name": "balancer_ingress",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": "corpus/inputs/katran_vip_packet_64.bin",
    },
    {
        "canonical_name": "katran:healthchecking.bpf.o:healthcheck_encap",
        "object_path": "corpus/build/katran/healthchecking.bpf.o",
        "program_name": "healthcheck_encap",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "katran:healthchecking_ipip.bpf.o:healthcheck_encap",
        "object_path": "corpus/build/katran/healthchecking_ipip.bpf.o",
        "program_name": "healthcheck_encap",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "tracee:tracee.bpf.o:cgroup_skb_ingress",
        "object_path": "corpus/build/tracee/tracee.bpf.o",
        "program_name": "cgroup_skb_ingress",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "tracee:tracee.bpf.o:cgroup_skb_egress",
        "object_path": "corpus/build/tracee/tracee.bpf.o",
        "program_name": "cgroup_skb_egress",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "calico:xdp_no_log.bpf.o:calico_xdp_main",
        "object_path": "corpus/build/calico/xdp_no_log.bpf.o",
        "program_name": "calico_xdp_main",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": "corpus/inputs/macro_dummy_packet_64.bin",
    },
    {
        "canonical_name": "calico:from_hep_debug.bpf.o:calico_tc_maglev",
        "object_path": "corpus/build/calico/from_hep_debug.bpf.o",
        "program_name": "calico_tc_maglev",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": "corpus/inputs/macro_dummy_packet_64.bin",
    },
    {
        "canonical_name": "calico:from_hep_debug.bpf.o:calico_tc_main",
        "object_path": "corpus/build/calico/from_hep_debug.bpf.o",
        "program_name": "calico_tc_main",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "calico:to_hep_debug.bpf.o:calico_tc_main",
        "object_path": "corpus/build/calico/to_hep_debug.bpf.o",
        "program_name": "calico_tc_main",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": None,
    },
    {
        "canonical_name": "suricata:xdp_filter.bpf.o:xdp_hashfilter",
        "object_path": "corpus/build/suricata/xdp_filter.bpf.o",
        "program_name": "xdp_hashfilter",
        "io_mode": "packet",
        "input_size": 64,
        "memory_path": "corpus/inputs/macro_dummy_packet_64.bin",
    },
]


def repo_path(path: str | None) -> Path | None:
    if path is None:
        return None
    return REPO_ROOT / path


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

    result = {
        "rejit_requested": bool(rejit.get("requested")),
        "rejit_applied": bool(rejit.get("applied")),
        "passes_applied": list(rejit.get("passes_applied") or []),
        "total_sites_applied": int(rejit.get("total_sites_applied") or 0),
        "insn_delta": int(rejit.get("insn_delta") or 0),
        "verifier_retries": int(rejit.get("verifier_retries") or 0),
        "final_disabled_passes": list(rejit.get("final_disabled_passes") or []),
        "daemon_status": daemon_response.get("status"),
        "daemon_changed": daemon_response.get("changed"),
        "daemon_program": daemon_response.get("program") or {},
        "daemon_summary": daemon_response.get("summary") or {},
    }
    if map_inline_pass is not None:
        result.update(
            {
                "map_inline_changed": bool(map_inline_pass.get("changed")),
                "map_inline_sites_applied": int(map_inline_pass.get("sites_applied") or 0),
                "map_inline_sites_skipped": int(map_inline_pass.get("sites_skipped") or 0),
                "map_inline_skip_reasons": map_inline_pass.get("skip_reasons") or {},
                "map_inline_diagnostics": list(map_inline_pass.get("diagnostics") or []),
            }
        )
    else:
        result.update(
            {
                "map_inline_changed": False,
                "map_inline_sites_applied": 0,
                "map_inline_sites_skipped": 0,
                "map_inline_skip_reasons": {},
                "map_inline_diagnostics": [],
            }
        )
    return result


def build_test_run_command(
    target: dict,
    *,
    rejit: bool,
    compile_only: bool,
) -> list[str]:
    command = [
        str(RUNNER),
        "run-kernel",
        "--program",
        str(repo_path(target["object_path"])),
        "--program-name",
        target["program_name"],
        "--btf-custom-path",
        str(BTF),
        "--io-mode",
        target["io_mode"],
        "--input-size",
        str(target["input_size"]),
        "--warmup",
        str(WARMUP_REPEAT),
        "--repeat",
        str(MEASURE_REPEAT if not compile_only else SCREEN_REPEAT),
    ]
    memory_path = repo_path(target.get("memory_path"))
    if memory_path is not None:
        command.extend(["--memory", str(memory_path)])
    if compile_only:
        command.append("--compile-only")
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
    invocation = run_command(build_test_run_command(target, rejit=True, compile_only=True))
    sample = sample_from_stdout(invocation["stdout"])
    details = extract_map_inline_details(sample)
    return {
        "target": target,
        "compile_only_invocation": invocation,
        "compile_only_sample": sample,
        "compile_only_rejit": details,
    }


def measure_target(target: dict) -> dict:
    stock_runs = []
    rejit_runs = []
    for _ in range(MEASURE_ITERATIONS):
        stock_invocation = run_command(build_test_run_command(target, rejit=False, compile_only=False))
        stock_sample = sample_from_stdout(stock_invocation["stdout"])
        stock_runs.append(
            {
                "invocation": stock_invocation,
                "sample": stock_sample,
            }
        )

        rejit_invocation = run_command(build_test_run_command(target, rejit=True, compile_only=False))
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

    first_successful_rejit = next(
        (run for run in rejit_runs if run.get("sample") and run["sample"].get("rejit")),
        None,
    )
    representative_rejit = (
        first_successful_rejit.get("rejit") if first_successful_rejit is not None else {}
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
    payload: dict = {
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "passes": PASSES,
        "screen_repeat": SCREEN_REPEAT,
        "measure_repeat": MEASURE_REPEAT,
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

    measured_names = [
        measurement["target"]["canonical_name"] for measurement in payload["measurements"]
    ]
    summary = {
        "screened": len(payload["screening"]),
        "map_inline_hits": len(measured_names),
        "measured_names": measured_names,
        "output_json": str(OUT_JSON),
        "daemon_stderr_log": str(DAEMON_STDERR),
    }
    payload["summary"] = summary
    write_output(payload)
    print(json.dumps(summary, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
