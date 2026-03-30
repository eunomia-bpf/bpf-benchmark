#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import platform
import shutil
import statistics
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

import yaml

REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs.catalog import DEFAULT_MICRO_MANIFEST, load_manifest as load_micro_suite
from runner.libs.benchmarks import resolve_memory_file
from runner.libs.rejit import apply_daemon_rejit, scan_programs
from runner.libs.run_artifacts import load_latest_result_for_output


ETHERNET_HEADER_SIZE = 14
SUPPORTED_E2E_CASES = ("tracee", "tetragon", "scx", "katran")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the x86 AWS benchmark bundle on the remote host.")
    parser.add_argument("--output", required=True, help="Final JSON output path.")
    parser.add_argument("--mode", choices=("micro", "e2e"), default="micro")
    parser.add_argument("--iterations", type=int, default=10)
    parser.add_argument("--warmups", type=int, default=2)
    parser.add_argument("--repeat", type=int, default=200)
    parser.add_argument("--cpu", default="0")
    parser.add_argument("--instance-id", required=True)
    parser.add_argument("--instance-type", required=True)
    parser.add_argument("--aws-profile", default="codex-ec2")
    parser.add_argument("--aws-region", default="us-east-1")
    parser.add_argument("--e2e-cases", default="tracee,tetragon,scx,katran")
    parser.add_argument("--e2e-smoke", type=int, choices=(0, 1), default=1)
    return parser.parse_args()


def run_command(
    command: list[str],
    *,
    cwd: Path | None = None,
    check: bool = True,
    timeout: int = 300,
) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=cwd or REPO_ROOT,
        capture_output=True,
        text=True,
        check=False,
        timeout=timeout,
    )
    if check and completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(command)}\n{detail}")
    return completed


def run_json_command(
    command: list[str],
    *,
    cwd: Path | None = None,
    timeout: int = 300,
    allow_empty: bool = False,
) -> Any:
    completed = run_command(command, cwd=cwd, timeout=timeout)
    stdout = completed.stdout.strip()
    if not stdout:
        if allow_empty:
            return None
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command returned no JSON: {' '.join(command)}\n{detail}")
    try:
        return json.loads(stdout)
    except json.JSONDecodeError as exc:
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command returned non-JSON: {' '.join(command)}\n{detail}") from exc


def maybe_read_text(path: str | Path) -> str | None:
    try:
        return Path(path).read_text().strip()
    except OSError:
        return None


def tail_text(text: str, *, max_lines: int = 40, max_chars: int = 8000) -> str:
    lines = [line.rstrip() for line in text.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


def parse_e2e_cases(cases_csv: str) -> list[str]:
    requested = [token.strip().lower() for token in str(cases_csv).split(",") if token.strip()]
    if not requested:
        raise RuntimeError("no E2E cases were selected")
    resolved: list[str] = []
    for token in requested:
        if token == "all":
            for case_name in SUPPORTED_E2E_CASES:
                if case_name not in resolved:
                    resolved.append(case_name)
            continue
        if token not in SUPPORTED_E2E_CASES:
            supported = ", ".join(SUPPORTED_E2E_CASES)
            raise RuntimeError(f"unsupported E2E case {token!r}; supported cases: {supported}")
        if token not in resolved:
            resolved.append(token)
    return resolved


def sanitize_name(text: str) -> str:
    return "".join(ch if ch.isalnum() else "_" for ch in text)


def ns_summary(samples: list[int | float]) -> dict[str, float | int]:
    ordered = [float(sample) for sample in samples]
    if not ordered:
        return {"count": 0, "min": 0, "max": 0, "mean": 0.0, "median": 0.0}
    return {
        "count": len(ordered),
        "min": min(ordered),
        "max": max(ordered),
        "mean": statistics.fmean(ordered),
        "median": statistics.median(ordered),
    }


def build_packet_input(input_bytes: bytes, prog_type_name: str) -> bytes:
    prefix_offset = ETHERNET_HEADER_SIZE if prog_type_name == "cgroup_skb" else 0
    packet = bytearray(prefix_offset + 8 + len(input_bytes))
    if prefix_offset == ETHERNET_HEADER_SIZE:
        packet[12] = 0x08
        packet[13] = 0x00
    packet[prefix_offset + 8 : prefix_offset + 8 + len(input_bytes)] = input_bytes
    return bytes(packet)


def ensure_bpffs_mounted() -> None:
    if subprocess.run(["mountpoint", "-q", "/sys/fs/bpf"], check=False).returncode == 0:
        return
    run_command(["mount", "-t", "bpf", "bpf", "/sys/fs/bpf"])


def runner_programs(runner_binary: Path, object_path: Path) -> list[dict[str, Any]]:
    payload = run_json_command([str(runner_binary), "list-programs", "--program", str(object_path)])
    if not isinstance(payload, list):
        raise RuntimeError(f"list-programs returned non-list JSON for {object_path}")
    programs = [record for record in payload if isinstance(record, dict)]
    if not programs:
        raise RuntimeError(f"no programs found in object: {object_path}")
    return programs


def bpftool_prog_show_pinned(bpftool_binary: str, pin_path: Path) -> dict[str, Any]:
    payload = run_json_command([bpftool_binary, "-j", "-p", "prog", "show", "pinned", str(pin_path)])
    if isinstance(payload, list):
        if len(payload) != 1:
            raise RuntimeError(f"unexpected pinned prog payload for {pin_path}")
        payload = payload[0]
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected pinned prog payload type for {pin_path}: {type(payload)}")
    return payload


def bpftool_prog_show_id(bpftool_binary: str, prog_id: int) -> dict[str, Any]:
    payload = run_json_command([bpftool_binary, "-j", "-p", "prog", "show", "id", str(prog_id)])
    if isinstance(payload, list):
        if len(payload) != 1:
            raise RuntimeError(f"unexpected prog payload for id {prog_id}")
        payload = payload[0]
    if not isinstance(payload, dict):
        raise RuntimeError(f"unexpected prog payload type for id {prog_id}: {type(payload)}")
    return payload


def scan_program(daemon_binary: Path, prog_id: int) -> dict[str, Any]:
    results = scan_programs([prog_id], daemon_binary)
    record = results.get(int(prog_id))
    if not isinstance(record, dict):
        raise RuntimeError(f"daemon scan did not return a record for prog_id={prog_id}")
    error = str(record.get("error") or "").strip()
    if error:
        raise RuntimeError(f"daemon scan failed for prog_id={prog_id}: {error}")
    return record


def command_record(mode: str, completed: subprocess.CompletedProcess[str]) -> dict[str, Any]:
    return {
        "mode": mode,
        "returncode": int(completed.returncode),
        "stdout": completed.stdout,
        "stderr": completed.stderr,
    }


def run_bpftool_samples(
    bpftool_binary: str,
    pin_path: Path,
    packet_path: Path,
    *,
    repeat: int,
    warmups: int,
    iterations: int,
) -> dict[str, Any]:
    command = [
        bpftool_binary,
        "-j",
        "-p",
        "prog",
        "run",
        "pinned",
        str(pin_path),
        "data_in",
        str(packet_path),
        "repeat",
        str(max(1, repeat)),
    ]
    for _ in range(max(0, warmups)):
        run_json_command(command)

    samples: list[dict[str, Any]] = []
    for _ in range(max(1, iterations)):
        payload = run_json_command(command)
        if not isinstance(payload, dict):
            raise RuntimeError(f"bpftool prog run returned non-dict JSON for {pin_path}")
        duration = int(payload.get("duration", 0) or 0)
        retval = int(payload.get("retval", 0) or 0)
        samples.append({"duration": duration, "retval": retval, "raw": payload})

    durations = [sample["duration"] for sample in samples]
    retval_distribution = Counter(str(sample["retval"]) for sample in samples)
    return {
        "samples": samples,
        "exec_ns": ns_summary(durations),
        "retval_distribution": dict(retval_distribution),
    }


def run_llvmbpf_vs_kernel(
    *,
    iterations: int,
    warmups: int,
    repeat: int,
    cpu: str,
    results_dir: Path,
) -> dict[str, Any]:
    output_path = results_dir / "llvmbpf_vs_kernel.json"
    run_command(
        [
            sys.executable,
            str(REPO_ROOT / "micro" / "driver.py"),
            "--runtime",
            "llvmbpf",
            "--runtime",
            "kernel",
            "--iterations",
            str(iterations),
            "--warmups",
            str(warmups),
            "--repeat",
            str(repeat),
            "--cpu",
            str(cpu),
            "--regenerate-inputs",
            "--output",
            str(output_path),
        ],
        cwd=REPO_ROOT,
        timeout=7200,
    )
    return load_latest_result_for_output(output_path, default_run_type="pure_jit")


def run_daemon_stock_vs_rejit(
    *,
    runner_binary: Path,
    daemon_binary: Path,
    bpftool_binary: str,
    iterations: int,
    warmups: int,
    repeat: int,
    cpu: str,
    results_dir: Path,
) -> dict[str, Any]:
    suite = load_micro_suite(DEFAULT_MICRO_MANIFEST)
    packet_dir = results_dir / "packets"
    packet_dir.mkdir(parents=True, exist_ok=True)
    benchmarks: list[dict[str, Any]] = []
    ensure_bpffs_mounted()

    for benchmark in suite.benchmarks.values():
        object_path = benchmark.program_object.resolve()
        input_path = resolve_memory_file(benchmark, regenerate_inputs=True)
        if input_path is None:
            raise RuntimeError(f"{benchmark.name}: missing generated input")
        input_path = input_path.resolve()
        input_bytes = input_path.read_bytes()

        programs = runner_programs(runner_binary, object_path)
        if len(programs) != 1:
            raise RuntimeError(f"{benchmark.name}: expected exactly one program, found {len(programs)}")
        program = programs[0]
        program_name = str(program.get("name", "")).strip()
        if not program_name:
            raise RuntimeError(f"{benchmark.name}: empty program name from list-programs")

        packet_path = packet_dir / f"{benchmark.name}.packet"
        packet_path.write_bytes(build_packet_input(input_bytes, str(program.get("prog_type_name", ""))))

        pin_dir = Path("/sys/fs/bpf") / f"aws_x86_micro_{sanitize_name(benchmark.name)}_{os.getpid()}"
        try:
            run_command(["rm", "-rf", str(pin_dir)], check=False)
            run_command(["mkdir", "-p", str(pin_dir)])
            run_command([bpftool_binary, "prog", "loadall", str(object_path), str(pin_dir)], timeout=120)

            pin_path = pin_dir / program_name
            if not pin_path.exists():
                pinned_paths = sorted(pin_dir.iterdir())
                if len(pinned_paths) != 1:
                    raise RuntimeError(f"{benchmark.name}: expected one pinned path under {pin_dir}")
                pin_path = pinned_paths[0]

            load_info_before = bpftool_prog_show_pinned(bpftool_binary, pin_path)
            prog_id = int(load_info_before.get("id", 0) or 0)
            if prog_id <= 0:
                raise RuntimeError(f"{benchmark.name}: invalid prog id from pinned program")

            scan_before = scan_program(daemon_binary, prog_id)
            stock = run_bpftool_samples(
                bpftool_binary,
                pin_path,
                packet_path,
                repeat=repeat,
                warmups=warmups,
                iterations=iterations,
            )

            total_sites = int(((scan_before.get("counts") or {}).get("total_sites", 0)) or 0)
            if total_sites > 0:
                rejit_apply = apply_daemon_rejit(str(daemon_binary), [prog_id])
            else:
                raise RuntimeError(f"{benchmark.name}: daemon scan found zero optimization sites")

            load_info_after = None
            rejit = None
            if total_sites > 0:
                load_info_after = bpftool_prog_show_id(bpftool_binary, prog_id)
            if bool(rejit_apply.get("applied")):
                rejit = run_bpftool_samples(
                    bpftool_binary,
                    pin_path,
                    packet_path,
                    repeat=repeat,
                    warmups=warmups,
                    iterations=iterations,
                )

            benchmarks.append(
                {
                    "name": benchmark.name,
                    "description": benchmark.description,
                    "category": benchmark.category,
                    "family": benchmark.family,
                    "level": benchmark.level,
                    "io_mode": benchmark.io_mode,
                    "program_object": str(object_path),
                    "input": str(input_path),
                    "packet_input": str(packet_path),
                    "program": program,
                    "load_info_before": load_info_before,
                    "load_info_after": load_info_after,
                    "scan_before": scan_before,
                    "rejit_apply": rejit_apply,
                    "stock": stock,
                    "rejit": rejit,
                }
            )
        finally:
            run_command(["rm", "-rf", str(pin_dir)], check=False)

    return {
        "suite": suite.suite_name,
        "method": "bpftool prog loadall/run pinned + daemon serve optimize (live auto policy)",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": platform.python_version(),
            "cpu_affinity": str(cpu),
            "kernel_version": platform.release(),
            "kernel_cmdline": maybe_read_text("/proc/cmdline") or "",
        },
        "defaults": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": repeat,
            "cpu": str(cpu),
        },
        "benchmarks": benchmarks,
    }


def run_katran_smoke(
    *,
    daemon_binary: Path,
    bpftool_binary: str,
) -> dict[str, Any]:
    ensure_bpffs_mounted()
    object_path = (REPO_ROOT / "corpus" / "build" / "katran" / "balancer.bpf.o").resolve()
    pin_root = Path("/sys/fs/bpf") / f"katran_x86_{os.getpid()}"
    pin_dir = pin_root / "progs"
    map_dir = pin_root / "maps"
    run_command(["rm", "-rf", str(pin_root)], check=False)
    run_command(["mkdir", "-p", str(pin_dir), str(map_dir)])

    loadall_attempts: list[dict[str, Any]] = []

    try:
        kernel_btf_attempt = subprocess.run(
            [
                bpftool_binary,
                "prog",
                "loadall",
                str(object_path),
                str(pin_dir),
                "kernel_btf",
                "/sys/kernel/btf/vmlinux",
                "type",
                "xdp",
                "pinmaps",
                str(map_dir),
            ],
            cwd=REPO_ROOT,
            capture_output=True,
            text=True,
            check=False,
            timeout=180,
        )
        loadall_attempts.append(command_record("kernel_btf", kernel_btf_attempt))
        selected_load_mode = "kernel_btf"
        if kernel_btf_attempt.returncode != 0:
            plain_xdp_attempt = subprocess.run(
                [
                    bpftool_binary,
                    "prog",
                    "loadall",
                    str(object_path),
                    str(pin_dir),
                    "type",
                    "xdp",
                    "pinmaps",
                    str(map_dir),
                ],
                cwd=REPO_ROOT,
                capture_output=True,
                text=True,
                check=False,
                timeout=180,
            )
            loadall_attempts.append(command_record("plain_xdp", plain_xdp_attempt))
            selected_load_mode = "plain_xdp"
            if plain_xdp_attempt.returncode != 0:
                detail = plain_xdp_attempt.stderr.strip() or plain_xdp_attempt.stdout.strip()
                raise RuntimeError(f"katran loadall failed ({plain_xdp_attempt.returncode}): {detail}")

        pinned_program = bpftool_prog_show_pinned(bpftool_binary, pin_dir / "balancer_ingress")
        prog_id = int(pinned_program.get("id", 0) or 0)
        if prog_id <= 0:
            raise RuntimeError("katran smoke did not produce a live program id")
        scan_before = scan_program(daemon_binary, prog_id)
        if int(((scan_before.get("counts") or {}).get("total_sites", 0)) or 0) > 0:
            rejit_apply = apply_daemon_rejit(str(daemon_binary), [prog_id])
        else:
            raise RuntimeError("katran smoke found zero optimization sites")

        return {
            "object": str(object_path),
            "pin_dir": str(pin_dir),
            "loadall_attempts": loadall_attempts,
            "selected_load_mode": selected_load_mode,
            "pinned_program": pinned_program,
            "scan_before": scan_before,
            "rejit_apply": rejit_apply,
        }
    finally:
        run_command(["rm", "-rf", str(pin_root)], check=False)


def summarize_llvmbpf_vs_kernel(raw: dict[str, Any]) -> dict[str, Any]:
    ratios: list[tuple[str, float, float, float]] = []
    llvmbpf_faster = 0
    kernel_faster = 0
    for benchmark in raw.get("benchmarks", []):
        if not isinstance(benchmark, dict):
            continue
        runs = {run.get("runtime"): run for run in benchmark.get("runs", []) if isinstance(run, dict)}
        llvmbpf_run = runs.get("llvmbpf")
        kernel_run = runs.get("kernel")
        if not isinstance(llvmbpf_run, dict) or not isinstance(kernel_run, dict):
            continue
        llvmbpf_exec = float((llvmbpf_run.get("exec_ns") or {}).get("median") or 0.0)
        kernel_exec = float((kernel_run.get("exec_ns") or {}).get("median") or 0.0)
        if llvmbpf_exec <= 0 or kernel_exec <= 0:
            continue
        ratio = llvmbpf_exec / kernel_exec
        ratios.append((str(benchmark.get("name")), ratio, llvmbpf_exec, kernel_exec))
        if math.isclose(ratio, 1.0, rel_tol=0.0, abs_tol=1e-12):
            continue
        if ratio < 1.0:
            llvmbpf_faster += 1
        else:
            kernel_faster += 1

    def record(item: tuple[str, float, float, float]) -> dict[str, Any]:
        return {
            "name": item[0],
            "llvmbpf_over_kernel_ratio": item[1],
            "llvmbpf_exec_ns": item[2],
            "kernel_exec_ns": item[3],
        }

    sorted_by_ratio = sorted(ratios, key=lambda item: item[1])
    return {
        "benchmarks": len(ratios),
        "llvmbpf_faster": llvmbpf_faster,
        "kernel_faster": kernel_faster,
        "median_ratio": statistics.median(item[1] for item in ratios) if ratios else None,
        "geometric_mean_ratio": statistics.geometric_mean(item[1] for item in ratios) if ratios else None,
        "largest_kernel_wins": [record(item) for item in sorted_by_ratio[:5]],
        "largest_llvmbpf_wins": [record(item) for item in sorted_by_ratio[-5:][::-1]],
    }


def summarize_rejit(raw: dict[str, Any]) -> dict[str, Any]:
    total_sites = 0
    applied_sites = 0
    deltas: list[tuple[str, float, float, float]] = []
    benchmarks_with_sites = 0
    benchmarks_rejited = 0

    for benchmark in raw.get("benchmarks", []):
        if not isinstance(benchmark, dict):
            continue
        scan_before = benchmark.get("scan_before") or {}
        rejit_apply = benchmark.get("rejit_apply") or {}
        stock = benchmark.get("stock") or {}
        rejit = benchmark.get("rejit") or {}
        total = int((((scan_before.get("counts") or {}).get("total_sites", 0)) or 0))
        applied = int((((rejit_apply.get("counts") or {}).get("applied_sites", 0)) or 0))
        total_sites += total
        applied_sites += applied
        if total > 0:
            benchmarks_with_sites += 1
        if bool(rejit_apply.get("applied")):
            benchmarks_rejited += 1
        stock_exec = float((stock.get("exec_ns") or {}).get("median") or 0.0)
        rejit_exec = float((rejit.get("exec_ns") or {}).get("median") or 0.0)
        if stock_exec > 0 and rejit_exec > 0:
            deltas.append((str(benchmark.get("name")), rejit_exec - stock_exec, stock_exec, rejit_exec))

    sorted_deltas = sorted(deltas, key=lambda item: abs(item[1]), reverse=True)
    return {
        "benchmarks": len(raw.get("benchmarks", [])),
        "benchmarks_with_sites": benchmarks_with_sites,
        "benchmarks_rejited": benchmarks_rejited,
        "total_sites": total_sites,
        "applied_sites": applied_sites,
        "median_absolute_exec_delta_ns": statistics.median(abs(item[1]) for item in deltas) if deltas else None,
        "max_absolute_exec_delta_ns": max((abs(item[1]) for item in deltas), default=None),
        "largest_exec_deltas": [
            {
                "name": item[0],
                "rejit_minus_stock_ns": item[1],
                "stock_exec_ns": item[2],
                "rejit_exec_ns": item[3],
            }
            for item in sorted_deltas[:10]
        ],
    }


def summarize_katran(raw: dict[str, Any]) -> dict[str, Any]:
    attempts = raw.get("loadall_attempts") if isinstance(raw.get("loadall_attempts"), list) else []
    scan_before = raw.get("scan_before") if isinstance(raw.get("scan_before"), dict) else {}
    rejit_apply = raw.get("rejit_apply") if isinstance(raw.get("rejit_apply"), dict) else {}
    attempt_by_mode = {
        str(item.get("mode")): item
        for item in attempts
        if isinstance(item, dict) and item.get("mode")
    }
    return {
        "selected_load_mode": raw.get("selected_load_mode"),
        "loadall_attempts": len(attempts),
        "loadall_kernel_btf_rc": int((attempt_by_mode.get("kernel_btf") or {}).get("returncode", 0) or 0),
        "loadall_plain_xdp_rc": int((attempt_by_mode.get("plain_xdp") or {}).get("returncode", 0) or 0),
        "pinned_program": raw.get("pinned_program"),
        "total_sites": int((((scan_before.get("counts") or {}).get("total_sites", 0)) or 0)),
        "applied_sites": int((((rejit_apply.get("counts") or {}).get("applied_sites", 0)) or 0)),
        "rejit_applied": bool(rejit_apply.get("applied")),
        "error": str(rejit_apply.get("error", scan_before.get("error", "")) or ""),
    }


def read_json_if_exists(path: Path) -> dict[str, Any] | None:
    if not path.exists():
        return None
    try:
        payload = json.loads(path.read_text())
    except (OSError, json.JSONDecodeError):
        return None
    return payload if isinstance(payload, dict) else None


def summarize_e2e_payload(payload: dict[str, Any] | None) -> dict[str, Any] | None:
    if payload is None:
        return None
    limitations = payload.get("limitations")
    limitations_count = len(limitations) if isinstance(limitations, list) else 0
    return {
        "status": str(payload.get("status") or ""),
        "duration_s": payload.get("duration_s"),
        "sample_count": payload.get("sample_count"),
        "measurement_driver": payload.get("traffic_driver") or payload.get("mode"),
        "error_message": payload.get("error_message"),
        "limitations_count": limitations_count,
    }


def run_e2e_case(
    case_name: str,
    *,
    smoke: bool,
    bpftool_binary: str,
    results_dir: Path,
) -> dict[str, Any]:
    case_results_dir = results_dir / "e2e" / case_name
    case_results_dir.mkdir(parents=True, exist_ok=True)
    output_json = case_results_dir / f"{case_name}.json"
    output_md = case_results_dir / f"{case_name}.md"
    report_md = case_results_dir / f"{case_name}-report.md"

    command = [
        sys.executable,
        str(REPO_ROOT / "e2e" / "run.py"),
        case_name,
        "--output-json",
        str(output_json),
        "--output-md",
        str(output_md),
        "--report-md",
        str(report_md),
        "--bpftool",
        bpftool_binary,
    ]
    if case_name == "tetragon":
        tetragon_bpf_lib = (REPO_ROOT / "e2e" / "cases" / "tetragon" / "lib" / "bpf").resolve()
        if tetragon_bpf_lib.exists():
            config_path = case_results_dir / "tetragon-aws.yaml"
            config_payload = yaml.safe_load((REPO_ROOT / "e2e" / "cases" / "tetragon" / "config_execve_rate.yaml").read_text())
            if not isinstance(config_payload, dict):
                raise RuntimeError("tetragon config payload is not a mapping")
            tetragon_extra_args = [
                str(value).strip()
                for value in (config_payload.get("tetragon_extra_args") or [])
                if str(value).strip()
            ]
            if not any(arg == "--bpf-lib" or str(arg).startswith("--bpf-lib=") for arg in tetragon_extra_args):
                tetragon_extra_args.extend(["--bpf-lib", str(tetragon_bpf_lib)])
            config_payload["tetragon_extra_args"] = tetragon_extra_args
            config_path.write_text(yaml.safe_dump(config_payload, sort_keys=False))
            command.extend(["--config", str(config_path)])
    if smoke:
        command.append("--smoke")

    env = os.environ.copy()
    env["BPFTOOL_BIN"] = bpftool_binary
    env["PYTHONPATH"] = str(REPO_ROOT)
    current_path = env.get("PATH", "")
    path_entries = [entry for entry in current_path.split(os.pathsep) if entry]
    extra_path_entries = [
        str(Path(bpftool_binary).resolve().parent),
        str((REPO_ROOT / "e2e" / "cases" / case_name / "bin").resolve()),
        str((REPO_ROOT / "e2e" / "bin").resolve()),
    ]
    updated_path_entries = list(path_entries)
    for entry in reversed(extra_path_entries):
        if entry not in updated_path_entries:
            updated_path_entries.insert(0, entry)
    env["PATH"] = os.pathsep.join(updated_path_entries)

    timed_out = False
    try:
        completed = subprocess.run(
            command,
            cwd=REPO_ROOT,
            env=env,
            capture_output=True,
            text=True,
            check=False,
            timeout=7200,
        )
    except subprocess.TimeoutExpired as exc:
        timed_out = True
        completed = subprocess.CompletedProcess(
            command,
            124,
            exc.stdout or "",
            exc.stderr or "",
        )

    payload = read_json_if_exists(output_json)
    payload_status = str((payload or {}).get("status") or "").strip().lower()
    if timed_out:
        status = "error"
    elif payload_status in {"ok", "error"}:
        status = payload_status
    elif payload_status:
        status = "error"
    elif completed.returncode == 0:
        status = "ok"
    else:
        status = "error"

    error_message = ""
    if isinstance(payload, dict):
        error_message = str(payload.get("error_message") or "").strip()
    if not error_message and payload_status and payload_status not in {"ok", "error"}:
        error_message = f"remote e2e case returned an invalid status: {payload_status!r}"
    if not error_message and status == "error":
        error_message = tail_text(completed.stderr or completed.stdout or "remote e2e case failed")

    return {
        "case": case_name,
        "status": status,
        "smoke": smoke,
        "timed_out": timed_out,
        "returncode": int(completed.returncode),
        "command": command,
        "output_json": str(output_json),
        "output_md": str(output_md) if output_md.exists() else None,
        "report_md": str(report_md) if report_md.exists() else None,
        "stdout_tail": tail_text(completed.stdout or ""),
        "stderr_tail": tail_text(completed.stderr or ""),
        "error_message": error_message,
        "result": summarize_e2e_payload(payload),
    }


def run_e2e_suite(
    *,
    cases_csv: str,
    smoke: bool,
    bpftool_binary: str,
    results_dir: Path,
) -> dict[str, Any]:
    cases = parse_e2e_cases(cases_csv)
    ensure_bpffs_mounted()
    module_load = run_command(
        ["bash", str(REPO_ROOT / "module" / "load_all.sh")],
        timeout=120,
    )
    case_results = [
        run_e2e_case(
            case_name,
            smoke=smoke,
            bpftool_binary=bpftool_binary,
            results_dir=results_dir,
        )
        for case_name in cases
    ]
    return {
        "suite": "e2e",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "supported_cases": list(SUPPORTED_E2E_CASES),
        "selected_cases": cases,
        "smoke": smoke,
        "bpftool": bpftool_binary,
        "module_load": {
            "returncode": int(module_load.returncode),
            "stdout_tail": tail_text(module_load.stdout or ""),
            "stderr_tail": tail_text(module_load.stderr or ""),
        },
        "cases": case_results,
    }


def summarize_e2e(raw: dict[str, Any]) -> dict[str, Any]:
    cases = raw.get("cases") if isinstance(raw.get("cases"), list) else []
    ok_cases: list[str] = []
    failed_cases: list[dict[str, Any]] = []
    for record in cases:
        if not isinstance(record, dict):
            continue
        case_name = str(record.get("case") or "unknown")
        status = str(record.get("status") or "").lower()
        if status == "ok":
            ok_cases.append(case_name)
        else:
            failed_cases.append(
                {
                    "case": case_name,
                    "error_message": record.get("error_message"),
                    "returncode": record.get("returncode"),
                    "timed_out": bool(record.get("timed_out")),
                }
            )
    return {
        "selected_cases": raw.get("selected_cases"),
        "smoke": bool(raw.get("smoke")),
        "total_cases": len(cases),
        "ok_cases": ok_cases,
        "failed_cases": failed_cases,
        "module_load_returncode": int(((raw.get("module_load") or {}).get("returncode", 0)) or 0),
    }


def main() -> int:
    args = parse_args()
    output_path = Path(args.output).resolve()
    results_dir = output_path.parent / f"{output_path.stem}_artifacts"
    results_dir.mkdir(parents=True, exist_ok=True)

    runner_binary = (REPO_ROOT / "runner" / "build" / "micro_exec").resolve()
    daemon_binary = (REPO_ROOT / "daemon" / "target" / "release" / "bpfrejit-daemon").resolve()
    bpftool_binary = shutil.which("bpftool") or "bpftool"

    if not runner_binary.exists():
        raise SystemExit(f"missing runner binary: {runner_binary}")
    if not daemon_binary.exists():
        raise SystemExit(f"missing daemon binary: {daemon_binary}")

    payload = {
        "run_date": datetime.now(timezone.utc).isoformat(),
        "aws": {
            "profile": args.aws_profile,
            "region": args.aws_region,
            "instance_id": args.instance_id,
            "instance_type": args.instance_type,
        },
        "kernel": {
            "release": platform.release(),
            "cmdline": maybe_read_text("/proc/cmdline") or "",
            "cached_artifacts": ".cache/aws-x86/",
        },
        "parameters": {
            "mode": args.mode,
            "iterations": args.iterations,
            "warmups": args.warmups,
            "repeat": args.repeat,
            "cpu": str(args.cpu),
        },
        "notes": {
            "cpu_governor": maybe_read_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor") or "unknown",
            "turbo_state": maybe_read_text("/sys/devices/system/cpu/intel_pstate/no_turbo") or "unknown",
            "perf_event_paranoid": maybe_read_text("/proc/sys/kernel/perf_event_paranoid") or "unknown",
        },
    }

    if args.mode == "e2e":
        try:
            raw_e2e = run_e2e_suite(
                cases_csv=args.e2e_cases,
                smoke=bool(args.e2e_smoke),
                bpftool_binary=bpftool_binary,
                results_dir=results_dir,
            )
            payload["parameters"].update(
                {
                    "e2e_cases": raw_e2e.get("selected_cases"),
                    "e2e_smoke": bool(args.e2e_smoke),
                }
            )
            payload["summary"] = {"e2e": summarize_e2e(raw_e2e)}
            payload["raw"] = {"e2e": raw_e2e}
        except Exception as exc:
            try:
                selected_cases = parse_e2e_cases(args.e2e_cases) if args.e2e_cases else []
            except Exception:
                selected_cases = []
            payload["parameters"].update(
                {
                    "e2e_cases": selected_cases,
                    "e2e_smoke": bool(args.e2e_smoke),
                }
            )
            payload["summary"] = {
                "e2e": {
                    "selected_cases": payload["parameters"]["e2e_cases"],
                    "smoke": bool(args.e2e_smoke),
                    "total_cases": 0,
                    "ok_cases": [],
                    "failed_cases": [{"case": "suite", "error_message": str(exc), "returncode": None, "timed_out": False}],
                    "module_load_returncode": None,
                }
            }
            payload["raw"] = {"e2e_error": str(exc)}
    else:
        raw_llvmbpf_vs_kernel = run_llvmbpf_vs_kernel(
            iterations=args.iterations,
            warmups=args.warmups,
            repeat=args.repeat,
            cpu=args.cpu,
            results_dir=results_dir,
        )
        raw_rejit = run_daemon_stock_vs_rejit(
            runner_binary=runner_binary,
            daemon_binary=daemon_binary,
            bpftool_binary=bpftool_binary,
            iterations=args.iterations,
            warmups=args.warmups,
            repeat=args.repeat,
            cpu=args.cpu,
            results_dir=results_dir,
        )
        raw_katran = run_katran_smoke(
            daemon_binary=daemon_binary,
            bpftool_binary=bpftool_binary,
        )
        payload["summary"] = {
            "llvmbpf_vs_kernel": summarize_llvmbpf_vs_kernel(raw_llvmbpf_vs_kernel),
            "daemon_stock_vs_rejit": summarize_rejit(raw_rejit),
            "katran_smoke": summarize_katran(raw_katran),
        }
        payload["raw"] = {
            "llvmbpf_vs_kernel": raw_llvmbpf_vs_kernel,
            "daemon_stock_vs_rejit": raw_rejit,
            "katran_smoke": raw_katran,
        }

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
