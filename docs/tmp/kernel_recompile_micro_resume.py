#!/usr/bin/env python3
from __future__ import annotations

import argparse
import importlib.util
import json
import platform
import shlex
import shutil
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR, BenchmarkSpec, load_suite
from micro.orchestrator.benchmarks import resolve_memory_file, select_benchmarks
from micro.orchestrator.results import ns_summary


def load_collector_module():
    module_path = ROOT_DIR / "docs" / "tmp" / "kernel_recompile_micro_strict.py"
    spec = importlib.util.spec_from_file_location("kernel_recompile_micro_strict", module_path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load collector module: {module_path}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


COLLECTOR = load_collector_module()


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Resume strict kernel-recompile collection one benchmark per VM boot.")
    parser.add_argument("--suite", default=str(CONFIG_PATH))
    parser.add_argument("--bench", action="append", dest="benches")
    parser.add_argument("--iterations", type=int, default=10)
    parser.add_argument("--warmups", type=int, default=2)
    parser.add_argument("--repeat", type=int, default=500)
    parser.add_argument("--cpu", default="0")
    parser.add_argument("--memory", default="4G")
    parser.add_argument("--cpus", default="2")
    parser.add_argument("--timeout", type=int, default=300)
    parser.add_argument(
        "--kernel",
        default=str(ROOT_DIR / "vendor" / "linux-framework" / "arch" / "x86" / "boot" / "bzImage"),
    )
    parser.add_argument(
        "--output-json",
        default=str(ROOT_DIR / "micro" / "results" / "kernel_recompile_strict_20260312.json"),
    )
    parser.add_argument(
        "--output-md",
        default=str(ROOT_DIR / "docs" / "tmp" / "kernel-recompile-micro-strict.md"),
    )
    parser.add_argument(
        "--per-bench-dir",
        default=str(ROOT_DIR / "docs" / "tmp" / "kernel_recompile_per_bench"),
    )
    return parser.parse_args(argv)


def tail_text(text: str, *, lines: int = 30) -> str:
    stripped = text.strip()
    if not stripped:
        return ""
    return "\n".join(stripped.splitlines()[-lines:])


def empty_run_record(runtime: str, status: str, failure: dict[str, Any]) -> dict[str, Any]:
    return {
        "runtime": runtime,
        "label": runtime,
        "mode": runtime,
        "repeat": None,
        "command": [],
        "measurement_complete": False,
        "status": status,
        "failures": [failure],
        "samples": [],
        "artifacts": {
            "program_object": None,
            "policy_file": None,
        },
        "compile_ns": ns_summary([]),
        "exec_ns": ns_summary([]),
        "phases_ns": {},
        "perf_counters": {},
        "perf_counters_meta": {"requested": False, "collected": False},
        "derived_metrics": {},
        "wall_exec_ns": None,
        "timing_source": "unknown",
        "recompile_observation": {
            "requested": runtime == "kernel-recompile",
            "applied": False,
            "requested_families": [],
            "skipped_families": [],
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "bitfield_sites": 0,
            "zero_ext_sites": 0,
            "endian_sites": 0,
            "branch_flip_sites": 0,
            "total_sites": 0,
            "errors": [],
        },
    }


def normalize_stock_run_record(run_record: dict[str, Any]) -> dict[str, Any]:
    normalized = dict(run_record)
    normalized.setdefault("command", [])
    normalized["measurement_complete"] = True
    normalized["status"] = "ok"
    normalized.setdefault("failures", [])
    normalized.setdefault("samples", [])
    normalized.setdefault("artifacts", {"program_object": None, "policy_file": None})
    normalized.setdefault("compile_ns", ns_summary([]))
    normalized.setdefault("exec_ns", ns_summary([]))
    normalized.setdefault("phases_ns", {})
    normalized.setdefault("perf_counters", {})
    normalized.setdefault("perf_counters_meta", {"requested": False, "collected": False})
    normalized.setdefault("derived_metrics", {})
    normalized.setdefault("wall_exec_ns", None)
    normalized.setdefault("timing_source", "unknown")
    normalized["recompile_observation"] = COLLECTOR.extract_recompile_observation(normalized)
    return normalized


def synthetic_benchmark_record(benchmark: BenchmarkSpec, reason: str, detail: dict[str, Any]) -> dict[str, Any]:
    memory_file = resolve_memory_file(benchmark, False)
    failure = {
        "phase": "vm",
        "iteration_index": None,
        "reason": reason,
        **detail,
    }
    return {
        "name": benchmark.name,
        "description": benchmark.description,
        "category": benchmark.category,
        "family": benchmark.family,
        "level": benchmark.level,
        "io_mode": benchmark.io_mode,
        "tags": list(benchmark.tags),
        "expected_result": benchmark.expected_result,
        "input": str(memory_file) if memory_file is not None else None,
        "policy": dict(benchmark.policy) if benchmark.policy is not None else None,
        "policy_file": str(benchmark.policy_file) if benchmark.policy_file else None,
        "runs": [
            empty_run_record("kernel", reason, failure),
            empty_run_record("kernel-recompile", reason, failure),
        ],
    }


def replace_or_append(results: dict[str, Any], benchmark_record: dict[str, Any], ordered_names: list[str]) -> None:
    by_name = {record["name"]: record for record in results.get("benchmarks", [])}
    by_name[benchmark_record["name"]] = benchmark_record
    results["benchmarks"] = [by_name[name] for name in ordered_names if name in by_name]
    results["summary"] = COLLECTOR.build_summary(results)


def write_aggregate(results: dict[str, Any], output_json: Path, output_md: Path) -> None:
    output_json.parent.mkdir(parents=True, exist_ok=True)
    output_md.parent.mkdir(parents=True, exist_ok=True)
    output_json.write_text(json.dumps(results, indent=2) + "\n")
    output_md.write_text(COLLECTOR.render_markdown(results))


def guest_exec(bench_name: str, output_json: Path, output_md: Path, log_path: Path, args: argparse.Namespace) -> str:
    collector_cmd = (
        "set -euo pipefail; "
        "if [ -d /sys/devices/system/cpu ]; then "
        "for f in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do "
        "[ -f \"$f\" ] || continue; echo performance > \"$f\" || true; done; fi; "
        f"taskset -c 0 python3 -u docs/tmp/kernel_recompile_micro_strict.py "
        f"--bench {shlex.quote(bench_name)} "
        f"--iterations {args.iterations} --warmups {args.warmups} --repeat {args.repeat} "
        f"--cpu {shlex.quote(args.cpu)} "
        f"--output-json {shlex.quote(str(output_json))} "
        f"--output-md {shlex.quote(str(output_md))} "
        f"2>&1 | tee {shlex.quote(str(log_path))}"
    )
    return f"bash -lc {shlex.quote(collector_cmd)}"


def run_vm(exec_script: str, args: argparse.Namespace) -> subprocess.CompletedProcess[str]:
    vng = shutil.which("vng") or "/home/yunwei37/.local/bin/vng"
    command = [
        vng,
        "--run",
        str(Path(args.kernel).resolve()),
        "--cwd",
        str(ROOT_DIR),
        "--disable-monitor",
        "--memory",
        str(args.memory),
        "--cpus",
        str(args.cpus),
        "--rwdir",
        str(ROOT_DIR / "micro" / "results"),
        "--rwdir",
        str(ROOT_DIR / "docs" / "tmp"),
        "--exec",
        exec_script,
    ]
    return subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        timeout=args.timeout,
        check=False,
    )


def run_stock_only(bench_name: str, stock_json: Path, stock_log: Path, args: argparse.Namespace) -> subprocess.CompletedProcess[str]:
    guest_cmd = (
        "set -euo pipefail; "
        "if [ -d /sys/devices/system/cpu ]; then "
        "for f in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do "
        "[ -f \"$f\" ] || continue; echo performance > \"$f\" || true; done; fi; "
        f"taskset -c 0 python3 -u micro/run_micro.py --bench {shlex.quote(bench_name)} "
        "--runtime kernel "
        f"--iterations {args.iterations} --warmups {args.warmups} --repeat {args.repeat} "
        f"--cpu {shlex.quote(args.cpu)} "
        f"--output {shlex.quote(str(stock_json))} "
        f"2>&1 | tee {shlex.quote(str(stock_log))}"
    )
    return run_vm(f"bash -lc {shlex.quote(guest_cmd)}", args)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite))
    benchmarks = select_benchmarks(args.benches, suite)
    ordered_names = [benchmark.name for benchmark in benchmarks]
    per_bench_dir = Path(args.per_bench_dir).resolve()
    per_bench_dir.mkdir(parents=True, exist_ok=True)
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()

    if output_json.exists():
        results = json.loads(output_json.read_text())
    else:
        results = {
            "suite": suite.suite_name,
            "manifest": str(suite.manifest_path),
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "host": {
                "hostname": platform.node(),
                "platform": platform.platform(),
                "python": sys.version.split()[0],
                "cpu_affinity": args.cpu,
                "kernel_version": "unknown",
                "cpu_governor": "unknown",
                "turbo_state": "unknown",
            },
            "defaults": {
                "iterations": args.iterations,
                "warmups": args.warmups,
                "repeat": args.repeat,
                "cpu": args.cpu,
            },
            "benchmarks": [],
            "summary": {},
        }

    existing_names = {record["name"] for record in results.get("benchmarks", [])}
    remaining = [benchmark for benchmark in benchmarks if benchmark.name not in existing_names]
    print(f"[resume] existing={len(existing_names)} remaining={len(remaining)}", flush=True)

    for benchmark in remaining:
        bench_json = per_bench_dir / f"{benchmark.name}.json"
        bench_md = per_bench_dir / f"{benchmark.name}.md"
        bench_log = per_bench_dir / f"{benchmark.name}.log"
        stock_json = per_bench_dir / f"{benchmark.name}.stock.json"
        stock_log = per_bench_dir / f"{benchmark.name}.stock.log"
        for path in (bench_json, bench_md, bench_log, stock_json, stock_log):
            path.unlink(missing_ok=True)

        print(f"[resume] {benchmark.name}", flush=True)
        completed = run_vm(guest_exec(benchmark.name, bench_json, bench_md, bench_log, args), args)
        benchmark_record: dict[str, Any] | None = None
        if bench_json.exists():
            payload = json.loads(bench_json.read_text())
            payload_host = payload.get("host")
            if isinstance(payload_host, dict) and payload_host.get("kernel_version"):
                results["host"] = payload_host
            if payload.get("benchmarks"):
                benchmark_record = payload["benchmarks"][0]
                print(f"  [ok] collected {benchmark.name} (vm exit {completed.returncode})", flush=True)

        if benchmark_record is None:
            detail = {
                "returncode": completed.returncode,
                "stdout_tail": tail_text(completed.stdout),
                "stderr_tail": tail_text(completed.stderr),
                "guest_log_tail": tail_text(bench_log.read_text(errors="replace")) if bench_log.exists() else "",
            }
            print(f"  [warn] batch vm failed for {benchmark.name}; attempting stock-only salvage", flush=True)
            stock_completed = run_stock_only(benchmark.name, stock_json, stock_log, args)
            if stock_json.exists():
                stock_payload = json.loads(stock_json.read_text())
                payload_host = stock_payload.get("host")
                if isinstance(payload_host, dict) and payload_host.get("kernel_version"):
                    results["host"] = payload_host
                if stock_payload.get("benchmarks"):
                    stock_record = stock_payload["benchmarks"][0]
                    recompile_failure = empty_run_record("kernel-recompile", "vm-crash", detail)
                    benchmark_record = dict(stock_record)
                    benchmark_record["runs"] = [normalize_stock_run_record(stock_record["runs"][0]), recompile_failure]
                    print(
                        f"  [partial] salvaged stock-only for {benchmark.name} (stock vm exit {stock_completed.returncode})",
                        flush=True,
                    )

            if benchmark_record is None:
                benchmark_record = synthetic_benchmark_record(benchmark, "vm-crash", detail)
                print(f"  [crash] recorded synthetic failure for {benchmark.name}", flush=True)

        replace_or_append(results, benchmark_record, ordered_names)
        results["generated_at"] = datetime.now(timezone.utc).isoformat()
        write_aggregate(results, output_json, output_md)
        print(
            f"  [aggregate] benchmarks={len(results['benchmarks'])} valid={results['summary']['overall']['valid_pairs']}",
            flush=True,
        )

    print(f"[done] wrote {output_json}", flush=True)
    print(f"[done] wrote {output_md}", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
