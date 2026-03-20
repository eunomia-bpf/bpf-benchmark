#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import platform
import random
import shutil
import statistics
import subprocess
import sys
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from itertools import combinations
from pathlib import Path
from typing import Callable

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from benchmark_catalog import CONFIG_PATH, ROOT_DIR, BenchmarkSpec, RuntimeSpec, SuiteSpec, load_suite
try:
    from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
    from runner.libs.commands import build_runner_command
    from runner.libs.environment import validate_publication_environment
except ImportError:
    from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
    from runner.libs.commands import build_runner_command
    from runner.libs.environment import validate_publication_environment

try:
    import numpy as np
except ImportError:  # pragma: no cover - fallback exercised when numpy is absent
    np = None

try:
    from scipy.stats import wilcoxon as scipy_wilcoxon
except ImportError:  # pragma: no cover - fallback exercised when scipy is absent
    scipy_wilcoxon = None


MICRO_ROOT = Path(__file__).resolve().parent
DEFAULT_OUTPUT_DIR = MICRO_ROOT / "results" / "rigorous"
DEFAULT_ITERATIONS = 30
DEFAULT_WARMUPS = 5
DEFAULT_REPEAT = 1000
DEFAULT_BOOTSTRAP_SAMPLES = 10_000
DEFAULT_RUNTIME_ORDER_SEED = 0
DEFAULT_HEAVY_PROCESS_THRESHOLD = 25.0
DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS = 0.5
QUICK_ITERATIONS = 5
QUICK_WARMUPS = 2
QUICK_REPEAT = 100


@dataclass(frozen=True)
class ModeSpec:
    name: str
    label: str
    extra_args: tuple[str, ...]


@dataclass(frozen=True)
class PinningSpec:
    cpu: int
    tool: str
    source: str
    is_isolated: bool
    isolated_cpus: tuple[int, ...]
    online_cpus: tuple[int, ...]


def kernel_mode_catalog() -> dict[str, ModeSpec]:
    return {
        "stock": ModeSpec("stock", "stock kernel JIT", ()),
        "recompile-cmov": ModeSpec("recompile-cmov", "v4 auto-scan CMOV", ("--recompile-cmov",)),
        "recompile-wide": ModeSpec("recompile-wide", "v4 auto-scan WIDE_MEM", ("--recompile-wide",)),
        "recompile-rotate": ModeSpec("recompile-rotate", "v4 auto-scan ROTATE", ("--recompile-rotate",)),
        "recompile-rotate-rorx": ModeSpec(
            "recompile-rotate-rorx",
            "v4 auto-scan ROTATE (RORX)",
            ("--recompile-rotate-rorx",),
        ),
        "recompile-lea": ModeSpec("recompile-lea", "v4 auto-scan LEA", ("--recompile-lea",)),
        "recompile-all": ModeSpec("recompile-all", "v4 auto-scan all", ("--recompile-all",)),
        "recompile-v5": ModeSpec(
            "recompile-v5",
            "v5 auto-scan rotate+wide+lea",
            ("--recompile-v5", "--recompile-rotate", "--recompile-wide", "--recompile-lea"),
        ),
        "recompile-v5-cmov": ModeSpec(
            "recompile-v5-cmov",
            "v5 auto-scan cmov",
            ("--recompile-v5", "--recompile-cmov"),
        ),
        "recompile-v5-rotate": ModeSpec(
            "recompile-v5-rotate",
            "v5 auto-scan rotate",
            ("--recompile-v5", "--recompile-rotate"),
        ),
        "recompile-v5-rotate-rorx": ModeSpec(
            "recompile-v5-rotate-rorx",
            "v5 auto-scan rotate (RORX)",
            ("--recompile-v5", "--recompile-rotate-rorx"),
        ),
        "recompile-v5-wide": ModeSpec(
            "recompile-v5-wide",
            "v5 auto-scan wide",
            ("--recompile-v5", "--recompile-wide"),
        ),
        "recompile-v5-lea": ModeSpec(
            "recompile-v5-lea",
            "v5 auto-scan lea",
            ("--recompile-v5", "--recompile-lea"),
        ),
        "recompile-v5-all": ModeSpec(
            "recompile-v5-all",
            "v5 auto-scan all",
            ("--recompile-v5", "--recompile-all"),
        ),
    }


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run publication-grade microbenchmark experiments.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name. May be passed multiple times.")
    parser.add_argument(
        "--runtime",
        default="kernel",
        help="Runtime to execute (default: kernel). Supports suite runtime names and aliases.",
    )
    parser.add_argument(
        "--modes",
        help="Comma-separated execution modes. Kernel defaults to stock,recompile-all. llvmbpf only supports stock.",
    )
    parser.add_argument("--iterations", type=int, help=f"Measured iterations per mode (default: {DEFAULT_ITERATIONS}).")
    parser.add_argument("--warmups", type=int, help=f"Warmup iterations per mode (default: {DEFAULT_WARMUPS}).")
    parser.add_argument("--repeat", type=int, help=f"Repeats inside each micro_exec run (default: {DEFAULT_REPEAT}).")
    parser.add_argument("--cpu", type=int, help="Pin runs to this CPU core. Defaults to highest isolated CPU if available.")
    parser.add_argument(
        "--pin-tool",
        choices=["auto", "taskset", "numactl"],
        default="auto",
        help="CPU pinning tool to use.",
    )
    parser.add_argument(
        "--bootstrap-samples",
        type=int,
        default=DEFAULT_BOOTSTRAP_SAMPLES,
        help=f"Bootstrap resamples for confidence intervals (default: {DEFAULT_BOOTSTRAP_SAMPLES}).",
    )
    parser.add_argument("--seed", type=int, default=0, help="Random seed for bootstrap and mode-order shuffling.")
    parser.add_argument(
        "--heavy-process-threshold",
        type=float,
        default=DEFAULT_HEAVY_PROCESS_THRESHOLD,
        help="Flag other processes above this CPU percent of one core.",
    )
    parser.add_argument(
        "--heavy-process-sample-seconds",
        type=float,
        default=DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS,
        help="Sampling window for heavy-process detection.",
    )
    parser.add_argument("--kernel", help="Optional bzImage path to record for VM runs.")
    parser.add_argument("--output-dir", default=str(DEFAULT_OUTPUT_DIR), help="Directory for JSON/Markdown outputs.")
    parser.add_argument("--regenerate-inputs", action="store_true", help="Force regeneration of generated inputs.")
    parser.add_argument("--skip-build", action="store_true", help="Skip building micro_exec and programs.")
    parser.add_argument(
        "--no-system-fixes",
        action="store_true",
        help="Do not try to set governor/turbo even when sudo is available.",
    )
    parser.add_argument("--dry-run", action="store_true", help="Print build/run plan without executing benchmarks.")
    parser.add_argument("--quick", action="store_true", help="Use a short smoke-test configuration.")
    return parser.parse_args(argv)


def read_optional_text(path: str | Path) -> str | None:
    try:
        return Path(path).read_text().strip()
    except OSError:
        return None


def run_subprocess(command: list[str], *, cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    completed = subprocess.run(
        command,
        cwd=str(cwd) if cwd is not None else None,
        capture_output=True,
        text=True,
    )
    return completed


def run_checked(command: list[str], *, cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    completed = run_subprocess(command, cwd=cwd)
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(command)}\n{details}")
    return completed


def parse_cpu_set(raw: str | None) -> list[int]:
    if raw is None:
        return []
    text = raw.strip()
    if not text:
        return []
    cpus: list[int] = []
    for part in text.split(","):
        part = part.strip()
        if not part:
            continue
        if "-" in part:
            start_text, end_text = part.split("-", 1)
            start = int(start_text)
            end = int(end_text)
            cpus.extend(range(start, end + 1))
        else:
            cpus.append(int(part))
    return sorted(set(cpus))


def online_cpus() -> list[int]:
    online = parse_cpu_set(read_optional_text("/sys/devices/system/cpu/online"))
    if online:
        return online
    count = os.cpu_count() or 1
    return list(range(count))


def isolated_cpus() -> list[int]:
    isolated = parse_cpu_set(read_optional_text("/sys/devices/system/cpu/isolated"))
    if isolated:
        return isolated

    cmdline = read_optional_text("/proc/cmdline") or ""
    for token in cmdline.split():
        if token.startswith("isolcpus="):
            value = token.split("=", 1)[1]
            if ":" in value:
                value = value.split(":", 1)[1]
            return parse_cpu_set(value)
    return []


def choose_pinning_spec(cpu: int | None, pin_tool: str) -> PinningSpec:
    online = online_cpus()
    isolated = isolated_cpus()

    if pin_tool == "auto":
        if shutil.which("taskset") is not None:
            tool = "taskset"
        elif shutil.which("numactl") is not None:
            tool = "numactl"
        else:
            raise RuntimeError("neither taskset nor numactl is available")
    else:
        if shutil.which(pin_tool) is None:
            raise RuntimeError(f"{pin_tool} is not available")
        tool = pin_tool

    if cpu is not None:
        if cpu not in online:
            raise RuntimeError(f"requested CPU {cpu} is not online")
        source = "user-specified"
        selected_cpu = cpu
    elif isolated:
        selected_cpu = max(isolated)
        source = "highest-isolated"
    else:
        selected_cpu = max(online)
        source = "highest-online-fallback"

    return PinningSpec(
        cpu=selected_cpu,
        tool=tool,
        source=source,
        is_isolated=selected_cpu in set(isolated),
        isolated_cpus=tuple(isolated),
        online_cpus=tuple(online),
    )


def cpu_model_name() -> str:
    cpuinfo = Path("/proc/cpuinfo")
    if cpuinfo.exists():
        for line in cpuinfo.read_text().splitlines():
            if line.lower().startswith("model name"):
                return line.split(":", 1)[1].strip()
    return platform.processor() or "unknown"


def read_freq_khz(path: str) -> float | None:
    raw = read_optional_text(path)
    if raw is None:
        return None
    try:
        return float(raw) / 1000.0
    except ValueError:
        return None


def governor_snapshot() -> dict[str, object]:
    governors: dict[int, str] = {}
    for cpu in online_cpus():
        path = Path(f"/sys/devices/system/cpu/cpu{cpu}/cpufreq/scaling_governor")
        if not path.exists():
            continue
        value = read_optional_text(path)
        if value is not None:
            governors[cpu] = value
    values = sorted(set(governors.values()))
    return {
        "per_cpu": {str(cpu): governor for cpu, governor in governors.items()},
        "unique": values,
        "all_performance": bool(governors) and all(governor == "performance" for governor in governors.values()),
    }


def turbo_snapshot() -> dict[str, object]:
    intel_path = Path("/sys/devices/system/cpu/intel_pstate/no_turbo")
    boost_path = Path("/sys/devices/system/cpu/cpufreq/boost")
    if intel_path.exists():
        raw = read_optional_text(intel_path) or "unknown"
        return {
            "interface": str(intel_path),
            "raw_value": raw,
            "disabled": raw == "1",
            "disable_value": "1",
        }
    if boost_path.exists():
        raw = read_optional_text(boost_path) or "unknown"
        return {
            "interface": str(boost_path),
            "raw_value": raw,
            "disabled": raw == "0",
            "disable_value": "0",
        }
    return {
        "interface": None,
        "raw_value": "unknown",
        "disabled": None,
        "disable_value": None,
    }


def sudo_available() -> bool:
    if os.geteuid() == 0:
        return True
    if shutil.which("sudo") is None:
        return False
    return run_subprocess(["sudo", "-n", "true"]).returncode == 0


def run_root_shell(script: str) -> None:
    if os.geteuid() == 0:
        command = ["bash", "-lc", script]
    else:
        command = ["sudo", "-n", "bash", "-lc", script]
    run_checked(command)


def set_governor_performance() -> None:
    script = r"""
set -euo pipefail
for f in /sys/devices/system/cpu/cpu[0-9]*/cpufreq/scaling_governor; do
  [ -f "$f" ] || continue
  echo performance > "$f"
done
"""
    run_root_shell(script)


def disable_turbo() -> None:
    turbo = turbo_snapshot()
    interface = turbo.get("interface")
    disable_value = turbo.get("disable_value")
    if not interface or disable_value is None:
        raise RuntimeError("turbo control interface not found")
    script = f"set -euo pipefail\necho {disable_value} > {interface}\n"
    run_root_shell(script)


def parent_pid(pid: int) -> int | None:
    status = read_optional_text(f"/proc/{pid}/status")
    if status is None:
        return None
    for line in status.splitlines():
        if line.startswith("PPid:"):
            try:
                return int(line.split()[1])
            except (IndexError, ValueError):
                return None
    return None


def sample_process_cpu() -> tuple[dict[int, float], list[dict[str, object]]]:
    per_process: dict[int, tuple[int, int, str, str]] = {}

    for proc_dir in Path("/proc").iterdir():
        if not proc_dir.name.isdigit():
            continue
        pid = int(proc_dir.name)
        stat_path = proc_dir / "stat"
        cmdline_path = proc_dir / "cmdline"
        try:
            raw_stat = stat_path.read_text()
        except OSError:
            continue
        close_index = raw_stat.rfind(")")
        if close_index == -1:
            continue
        comm = raw_stat[raw_stat.find("(") + 1 : close_index]
        fields = raw_stat[close_index + 2 :].split()
        if len(fields) < 15:
            continue
        try:
            utime = int(fields[11])
            stime = int(fields[12])
        except ValueError:
            continue
        try:
            cmdline = cmdline_path.read_bytes().replace(b"\x00", b" ").decode().strip()
        except OSError:
            cmdline = ""
        per_process[pid] = (utime, stime, comm, cmdline)

    return (
        {pid: float(utime + stime) for pid, (utime, stime, _, _) in per_process.items()},
        [
            {
                "pid": pid,
                "comm": comm,
                "cmdline": cmdline,
                "jiffies": utime + stime,
            }
            for pid, (utime, stime, comm, cmdline) in per_process.items()
        ],
    )


def detect_heavy_processes(threshold_percent: float, sample_seconds: float) -> dict[str, object]:
    total_start_raw = read_optional_text("/proc/stat")
    if total_start_raw is None:
        return {"sample_seconds": sample_seconds, "threshold_percent": threshold_percent, "heavy_processes": [], "top": []}
    total_start = sum(int(value) for value in total_start_raw.splitlines()[0].split()[1:])
    proc_start, _ = sample_process_cpu()
    time.sleep(sample_seconds)
    total_end_raw = read_optional_text("/proc/stat")
    if total_end_raw is None:
        return {"sample_seconds": sample_seconds, "threshold_percent": threshold_percent, "heavy_processes": [], "top": []}
    total_end = sum(int(value) for value in total_end_raw.splitlines()[0].split()[1:])
    proc_end, proc_meta_end = sample_process_cpu()

    total_delta = max(total_end - total_start, 1)
    cpu_count = len(online_cpus())
    allowed_pids = set()
    current = os.getpid()
    while current > 1:
        allowed_pids.add(current)
        parent = os.getppid() if current == os.getpid() else parent_pid(current)
        if parent is None or parent in allowed_pids:
            break
        current = parent

    meta_by_pid: dict[int, dict[str, object]] = {int(entry["pid"]): entry for entry in proc_meta_end}
    rows: list[dict[str, object]] = []
    for pid, end_jiffies in proc_end.items():
        start_jiffies = proc_start.get(pid)
        if start_jiffies is None:
            continue
        delta = end_jiffies - start_jiffies
        cpu_percent = (delta / total_delta) * cpu_count * 100.0
        if cpu_percent <= 0:
            continue
        meta = meta_by_pid.get(pid, {"pid": pid, "comm": "unknown", "cmdline": ""})
        rows.append(
            {
                "pid": pid,
                "comm": meta.get("comm", "unknown"),
                "cmdline": meta.get("cmdline", ""),
                "cpu_percent": cpu_percent,
            }
        )

    rows.sort(key=lambda row: float(row["cpu_percent"]), reverse=True)
    heavy = [
        row
        for row in rows
        if row["pid"] not in allowed_pids and float(row["cpu_percent"]) >= threshold_percent
    ]
    return {
        "sample_seconds": sample_seconds,
        "threshold_percent": threshold_percent,
        "heavy_processes": heavy,
        "top": rows[:10],
    }


def collect_system_info(pinning: PinningSpec, runtime: RuntimeSpec, kernel_image: Path | None) -> dict[str, object]:
    governor = governor_snapshot()
    turbo = turbo_snapshot()
    freq_info = {
        "min_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"),
        "max_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"),
        "base_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/base_frequency"),
    }
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "python": sys.version.split()[0],
        "kernel_version": platform.release(),
        "kernel_cmdline": read_optional_text("/proc/cmdline"),
        "cpu_model": cpu_model_name(),
        "cpu_count": len(pinning.online_cpus),
        "selected_cpu": pinning.cpu,
        "selected_cpu_source": pinning.source,
        "selected_cpu_isolated": pinning.is_isolated,
        "isolated_cpus": list(pinning.isolated_cpus),
        "online_cpus": list(pinning.online_cpus),
        "pinning_tool": pinning.tool,
        "runtime": runtime.name,
        "runtime_label": runtime.label,
        "governor": governor,
        "turbo": turbo,
        "frequency_mhz": freq_info,
        "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        "git_sha": run_checked(["git", "rev-parse", "HEAD"], cwd=ROOT_DIR).stdout.strip(),
        "kernel_image": str(kernel_image) if kernel_image is not None else None,
    }


def perform_preflight(
    *,
    pinning: PinningSpec,
    runtime: RuntimeSpec,
    allow_system_fixes: bool,
    dry_run: bool,
    heavy_process_threshold: float,
    heavy_process_sample_seconds: float,
    kernel_image: Path | None,
) -> dict[str, object]:
    checks: list[dict[str, object]] = []
    can_sudo = sudo_available()
    mutation_allowed = allow_system_fixes and not dry_run and can_sudo

    governor = governor_snapshot()
    governor_status = "pass" if governor["all_performance"] else "fail"
    governor_action = None
    if governor_status == "fail" and mutation_allowed:
        set_governor_performance()
        governor = governor_snapshot()
        governor_status = "pass" if governor["all_performance"] else "fail"
        governor_action = "set-to-performance"
    checks.append(
        {
            "name": "cpu_governor",
            "status": governor_status,
            "action": governor_action,
            "detail": governor,
        }
    )

    turbo = turbo_snapshot()
    turbo_ok = turbo["disabled"] is True or turbo["disabled"] is None
    turbo_status = "pass" if turbo_ok else "fail"
    turbo_action = None
    if turbo_status == "fail" and mutation_allowed:
        disable_turbo()
        turbo = turbo_snapshot()
        turbo_ok = turbo["disabled"] is True or turbo["disabled"] is None
        turbo_status = "pass" if turbo_ok else "fail"
        turbo_action = "disable-turbo"
    checks.append(
        {
            "name": "turbo_boost",
            "status": turbo_status,
            "action": turbo_action,
            "detail": turbo,
        }
    )

    checks.append(
        {
            "name": "cpu_pinning",
            "status": "pass",
            "detail": {
                "tool": pinning.tool,
                "cpu": pinning.cpu,
                "source": pinning.source,
                "is_isolated": pinning.is_isolated,
                "isolated_cpus": list(pinning.isolated_cpus),
            },
        }
    )

    heavy_processes = detect_heavy_processes(heavy_process_threshold, heavy_process_sample_seconds)
    heavy_status = "pass" if not heavy_processes["heavy_processes"] else "fail"
    checks.append(
        {
            "name": "heavy_processes",
            "status": heavy_status,
            "detail": heavy_processes,
        }
    )

    if runtime.require_sudo:
        checks.append(
            {
                "name": "sudo",
                "status": "pass" if can_sudo else "fail",
                "detail": {"available": can_sudo},
            }
        )

    if kernel_image is not None:
        checks.append(
            {
                "name": "kernel_image",
                "status": "pass",
                "detail": {"path": str(kernel_image)},
            }
        )

    failures = [check for check in checks if check["status"] == "fail"]
    system = collect_system_info(pinning, runtime, kernel_image)
    validate_publication_environment(
        {
            "cpu_governor": "performance" if governor_snapshot()["all_performance"] else "unknown",
            "turbo_state": "1" if turbo_snapshot()["disabled"] is True else "0",
            "perf_event_paranoid": system.get("perf_event_paranoid", "unknown"),
        },
        cpu=pinning.cpu,
        strict=False,
    )
    return {
        "ok": not failures,
        "checks": checks,
        "system": system,
        "publication_ready": (
            governor_snapshot()["all_performance"]
            and (turbo_snapshot()["disabled"] is not False)
            and not heavy_processes["heavy_processes"]
            and pinning.is_isolated
        ),
    }


def quantile(values: list[float], q: float) -> float:
    if not values:
        return math.nan
    sorted_values = sorted(values)
    if len(sorted_values) == 1:
        return float(sorted_values[0])
    position = (len(sorted_values) - 1) * q
    lower = int(math.floor(position))
    upper = int(math.ceil(position))
    if lower == upper:
        return float(sorted_values[lower])
    lower_value = float(sorted_values[lower])
    upper_value = float(sorted_values[upper])
    fraction = position - lower
    return lower_value + (upper_value - lower_value) * fraction


def percentile_interval(values: list[float]) -> tuple[float, float]:
    return quantile(values, 0.025), quantile(values, 0.975)


def bootstrap_ci(
    values: list[float],
    statistic: Callable[[list[float]], float],
    bootstrap_samples: int,
    seed: int,
) -> tuple[float | None, float | None]:
    if not values:
        return None, None
    if len(values) == 1:
        value = statistic(values)
        return value, value

    if np is not None:
        arr = np.asarray(values, dtype=np.float64)
        rng = np.random.default_rng(seed)
        indices = rng.integers(0, len(arr), size=(bootstrap_samples, len(arr)))
        resampled = arr[indices]
        if statistic is mean_statistic:
            estimates = resampled.mean(axis=1)
        elif statistic is median_statistic:
            estimates = np.median(resampled, axis=1)
        else:
            estimates = np.asarray([statistic(sample.tolist()) for sample in resampled], dtype=np.float64)
        low, high = np.percentile(estimates, [2.5, 97.5])
        return float(low), float(high)

    rng = random.Random(seed)
    estimates = [
        statistic([values[rng.randrange(len(values))] for _ in range(len(values))])
        for _ in range(bootstrap_samples)
    ]
    low, high = percentile_interval(estimates)
    return low, high


def mean_statistic(values: list[float]) -> float:
    return float(statistics.fmean(values))


def median_statistic(values: list[float]) -> float:
    return float(statistics.median(values))


def summarize_exec(values: list[float], bootstrap_samples: int, seed: int) -> dict[str, object]:
    if not values:
        raise RuntimeError("cannot summarize empty sample list")

    q1 = quantile(values, 0.25)
    q3 = quantile(values, 0.75)
    iqr = q3 - q1
    lower_fence = q1 - (3.0 * iqr)
    upper_fence = q3 + (3.0 * iqr)
    outliers = [
        {"iteration_index": index, "exec_ns": value}
        for index, value in enumerate(values)
        if value < lower_fence or value > upper_fence
    ]

    mean_value = statistics.fmean(values)
    stdev_value = statistics.stdev(values) if len(values) > 1 else 0.0
    mean_ci_low, mean_ci_high = bootstrap_ci(values, mean_statistic, bootstrap_samples, seed)
    median_ci_low, median_ci_high = bootstrap_ci(values, median_statistic, bootstrap_samples, seed + 1)
    minimum = min(values)
    maximum = max(values)

    return {
        "n": len(values),
        "mean": mean_value,
        "median": statistics.median(values),
        "stdev": stdev_value,
        "min": minimum,
        "max": maximum,
        "q1": q1,
        "q3": q3,
        "iqr": iqr,
        "ci95_mean": {"low": mean_ci_low, "high": mean_ci_high, "method": "bootstrap"},
        "ci95_median": {"low": median_ci_low, "high": median_ci_high, "method": "bootstrap"},
        "cv": (stdev_value / mean_value) if mean_value != 0 else math.nan,
        "noisy": bool(mean_value != 0 and (stdev_value / mean_value) > 0.05),
        "outlier_rule": "flag values outside [Q1 - 3*IQR, Q3 + 3*IQR]",
        "outliers": outliers,
        "outlier_count": len(outliers),
        "fence": {"low": lower_fence, "high": upper_fence},
    }


def normal_cdf(x: float) -> float:
    return 0.5 * (1.0 + math.erf(x / math.sqrt(2.0)))


def wilcoxon_signed_rank(lhs: list[float], rhs: list[float]) -> dict[str, object]:
    paired = [(left, right) for left, right in zip(lhs, rhs) if not math.isnan(left) and not math.isnan(right)]
    diffs = [left - right for left, right in paired if left != right]
    if not diffs:
        return {"n": len(paired), "statistic": 0.0, "pvalue": 1.0, "method": "degenerate"}

    if scipy_wilcoxon is not None:
        result = scipy_wilcoxon(lhs, rhs, zero_method="wilcox", alternative="two-sided", method="auto")
        return {"n": len(diffs), "statistic": float(result.statistic), "pvalue": float(result.pvalue), "method": "scipy"}

    ranked = sorted((abs(diff), diff) for diff in diffs)
    ranks: list[tuple[float, float]] = []
    index = 0
    rank = 1.0
    while index < len(ranked):
        end = index
        while end < len(ranked) and ranked[end][0] == ranked[index][0]:
            end += 1
        average_rank = (rank + (rank + (end - index) - 1)) / 2.0
        for tied_index in range(index, end):
            ranks.append((average_rank, ranked[tied_index][1]))
        rank += end - index
        index = end

    w_plus = sum(rank for rank, diff in ranks if diff > 0)
    w_minus = sum(rank for rank, diff in ranks if diff < 0)
    statistic = min(w_plus, w_minus)
    n = len(diffs)
    mean_rank = n * (n + 1) / 4.0
    variance = n * (n + 1) * (2 * n + 1) / 24.0
    if variance <= 0:
        pvalue = 1.0
    else:
        z = (abs(w_plus - mean_rank) - 0.5) / math.sqrt(variance)
        pvalue = 2.0 * (1.0 - normal_cdf(z))
    return {"n": n, "statistic": statistic, "pvalue": pvalue, "method": "normal-approx"}


def benjamini_hochberg_adjust(pvalues: list[float | None]) -> list[float | None]:
    finite = [(index, value) for index, value in enumerate(pvalues) if value is not None and math.isfinite(value)]
    adjusted: list[float | None] = [None] * len(pvalues)
    if not finite:
        return adjusted

    finite.sort(key=lambda item: item[1])
    total = len(finite)
    previous = 1.0
    for rank, (index, pvalue) in reversed(list(enumerate(finite, start=1))):
        current = min(previous, (float(pvalue) * total) / rank, 1.0)
        adjusted[index] = current
        previous = current
    return adjusted


def resolve_runtime(name: str, suite: SuiteSpec) -> RuntimeSpec:
    resolved = suite.runtime_aliases.get(name, name)
    runtime = suite.runtimes.get(resolved)
    if runtime is None:
        raise SystemExit(f"unknown runtime: {name}")
    return runtime


def resolve_modes(runtime: RuntimeSpec, raw_modes: str | None) -> list[ModeSpec]:
    if runtime.mode == "llvmbpf":
        names = ["stock"] if not raw_modes else [part.strip() for part in raw_modes.split(",") if part.strip()]
        if names != ["stock"]:
            raise SystemExit("llvmbpf only supports the stock mode in this driver")
        return [ModeSpec("stock", "stock llvmbpf", ())]

    catalog = kernel_mode_catalog()
    names = (
        [part.strip() for part in raw_modes.split(",") if part.strip()]
        if raw_modes
        else ["stock", "recompile-all"]
    )
    modes: list[ModeSpec] = []
    for name in names:
        mode = catalog.get(name)
        if mode is None:
            valid = ", ".join(sorted(catalog))
            raise SystemExit(f"unknown mode '{name}'. Valid modes: {valid}")
        modes.append(mode)
    return modes


def planned_build_commands(suite: SuiteSpec) -> list[list[str]]:
    return [
        list(suite.build.commands["micro_exec"]),
        list(suite.build.commands["programs"]),
    ]


def execute_build_commands(commands: list[list[str]], skip_build: bool) -> None:
    if skip_build:
        return
    for command in commands:
        run_checked(command, cwd=ROOT_DIR)


def build_base_command(
    suite: SuiteSpec,
    runtime: RuntimeSpec,
    benchmark: BenchmarkSpec,
    repeat: int,
    memory_file: Path | None,
    mode: ModeSpec,
) -> list[str]:
    if runtime.mode == "llvmbpf":
        return build_runner_command(
            suite.build.runner_binary,
            "run-llvmbpf",
            program=benchmark.program_object,
            io_mode=benchmark.io_mode,
            repeat=repeat,
            memory=memory_file,
        )

    return build_runner_command(
        suite.build.runner_binary,
        "run-kernel",
        program=benchmark.program_object,
        io_mode=benchmark.io_mode,
        repeat=repeat,
        memory=memory_file,
        input_size=benchmark.kernel_input_size,
        raw_packet=(benchmark.io_mode == "packet"),
        recompile_v5="--recompile-v5" in mode.extra_args,
        recompile_cmov="--recompile-cmov" in mode.extra_args,
        recompile_wide="--recompile-wide" in mode.extra_args,
        recompile_rotate="--recompile-rotate" in mode.extra_args,
        recompile_rotate_rorx="--recompile-rotate-rorx" in mode.extra_args,
        recompile_lea="--recompile-lea" in mode.extra_args,
        recompile_all="--recompile-all" in mode.extra_args,
    )


def apply_pinning(command: list[str], pinning: PinningSpec) -> list[str]:
    if pinning.tool == "taskset":
        return ["taskset", "-c", str(pinning.cpu), *command]
    return ["numactl", "--physcpubind", str(pinning.cpu), "--localalloc", *command]


def wrap_command(command: list[str], runtime: RuntimeSpec, pinning: PinningSpec) -> list[str]:
    pinned = apply_pinning(command, pinning)
    if runtime.require_sudo and os.geteuid() != 0:
        return ["sudo", "-n", *pinned]
    return pinned


def parse_micro_exec_output(stdout: str) -> dict[str, object]:
    lines = stdout.strip().splitlines()
    if not lines:
        raise RuntimeError("micro_exec produced no output")
    return json.loads(lines[-1])


def run_mode_iteration(command: list[str]) -> dict[str, object]:
    completed = run_checked(command)
    return parse_micro_exec_output(completed.stdout)


def pair_values_by_iteration(samples: list[dict[str, object]]) -> dict[int, float]:
    indexed: dict[int, float] = {}
    for sample in samples:
        indexed[int(sample["iteration_index"])] = float(sample["exec_ns"])
    return indexed


def summarize_mode_record(mode_record: dict[str, object], bootstrap_samples: int, seed: int) -> None:
    values = [float(sample["exec_ns"]) for sample in mode_record["samples"]]
    mode_record["stats"] = summarize_exec(values, bootstrap_samples, seed)
    compile_values = [float(sample["compile_ns"]) for sample in mode_record["samples"] if sample.get("compile_ns") is not None]
    if compile_values:
        mode_record["compile_stats"] = summarize_exec(compile_values, bootstrap_samples, seed + 101)


def build_pairwise_comparisons(benchmark_record: dict[str, object]) -> list[dict[str, object]]:
    mode_records = {str(record["mode"]): record for record in benchmark_record["modes"]}
    comparisons: list[dict[str, object]] = []
    for left_name, right_name in combinations(mode_records.keys(), 2):
        left_samples = pair_values_by_iteration(mode_records[left_name]["samples"])
        right_samples = pair_values_by_iteration(mode_records[right_name]["samples"])
        common_iterations = sorted(set(left_samples) & set(right_samples))
        left_values = [left_samples[index] for index in common_iterations]
        right_values = [right_samples[index] for index in common_iterations]
        if not common_iterations:
            continue
        deltas = [left - right for left, right in zip(left_values, right_values)]
        ratios = [left / right for left, right in zip(left_values, right_values) if right != 0]
        wilcoxon = wilcoxon_signed_rank(left_values, right_values)
        comparisons.append(
            {
                "benchmark": benchmark_record["name"],
                "mode_a": left_name,
                "mode_b": right_name,
                "paired_iterations": common_iterations,
                "n": len(common_iterations),
                "mean_delta_ns": statistics.fmean(deltas),
                "median_delta_ns": statistics.median(deltas),
                "mean_ratio_a_over_b": (statistics.fmean(left_values) / statistics.fmean(right_values))
                if statistics.fmean(right_values) != 0
                else math.nan,
                "median_ratio_a_over_b": statistics.median(ratios) if ratios else math.nan,
                "wins_a": sum(1 for left, right in zip(left_values, right_values) if left < right),
                "wins_b": sum(1 for left, right in zip(left_values, right_values) if right < left),
                "ties": sum(1 for left, right in zip(left_values, right_values) if left == right),
                "wilcoxon": wilcoxon,
                "pvalue": wilcoxon["pvalue"],
                "pvalue_adjusted_bh": None,
                "significant_bh_0_05": None,
            }
        )
    return comparisons


def format_float(value: float | None, precision: int = 2) -> str:
    if value is None or not math.isfinite(value):
        return "n/a"
    return f"{value:,.{precision}f}"


def format_ci_range(low: float | None, high: float | None) -> str:
    return f"[{format_float(low)}, {format_float(high)}]"


def write_summary_markdown(
    path: Path,
    raw_results: dict[str, object],
    summary_rows: dict[str, object],
) -> None:
    lines: list[str] = []
    lines.append("# Rigorous Benchmark Summary")
    lines.append("")
    lines.append(f"- Generated at: `{raw_results['generated_at']}`")
    lines.append(f"- Suite: `{raw_results['suite']}`")
    lines.append(f"- Runtime: `{raw_results['runtime']['name']}`")
    lines.append(f"- Modes: `{', '.join(raw_results['mode_names'])}`")
    lines.append(
        f"- Methodology: `{raw_results['methodology']['warmups']}` warmups discarded, "
        f"`{raw_results['methodology']['iterations']}` measured iterations, "
        f"`{raw_results['methodology']['repeat']}` repeats per `micro_exec` invocation"
    )
    lines.append(
        f"- Statistics: bootstrap 95% CI (`{raw_results['methodology']['bootstrap_samples']}` resamples), "
        "`CV > 5%` flagged as noisy, outliers flagged outside `Q1 +/- 3*IQR`, "
        "Wilcoxon signed-rank with BH correction across all benchmark/mode pairs"
    )
    lines.append("")
    lines.append("## System")
    lines.append("")
    system = raw_results["system"]
    lines.append(f"- CPU: `{system['cpu_model']}`")
    freq = system["frequency_mhz"]
    lines.append(
        f"- Frequency MHz: min `{format_float(freq.get('min_mhz'))}`, "
        f"base `{format_float(freq.get('base_mhz'))}`, max `{format_float(freq.get('max_mhz'))}`"
    )
    lines.append(f"- Kernel: `{system['kernel_version']}`")
    lines.append(f"- Governor: `{', '.join(system['governor']['unique']) or 'unknown'}`")
    lines.append(
        f"- Turbo disabled: `{system['turbo']['disabled']}` via `{system['turbo']['interface'] or 'unavailable'}`"
    )
    lines.append(
        f"- Pinning: CPU `{system['selected_cpu']}` via `{system['pinning_tool']}` "
        f"(source `{system['selected_cpu_source']}`, isolated `{system['selected_cpu_isolated']}`)"
    )
    if system["kernel_image"]:
        lines.append(f"- Kernel image metadata: `{system['kernel_image']}`")
    lines.append("")
    lines.append("## Preflight")
    lines.append("")
    for check in raw_results["preflight"]["checks"]:
        action = f", action `{check['action']}`" if check.get("action") else ""
        lines.append(f"- `{check['name']}`: `{check['status']}`{action}")
    lines.append("")

    for benchmark in raw_results["benchmarks"]:
        lines.append(f"## {benchmark['name']}")
        lines.append("")
        lines.append("| Mode | N | Median exec_ns | Mean exec_ns | 95% CI (mean) | Stdev | IQR | CV | Noisy | Outliers |")
        lines.append("| --- | ---: | ---: | ---: | --- | ---: | ---: | ---: | --- | ---: |")
        for mode in benchmark["modes"]:
            stats = mode["stats"]
            lines.append(
                f"| {mode['mode']} | {stats['n']} | {format_float(stats['median'])} | {format_float(stats['mean'])} | "
                f"{format_ci_range(stats['ci95_mean']['low'], stats['ci95_mean']['high'])} | "
                f"{format_float(stats['stdev'])} | {format_float(stats['iqr'])} | {format_float(stats['cv'], 3)} | "
                f"{'Yes' if stats['noisy'] else 'No'} | {stats['outlier_count']} |"
            )
        lines.append("")
        if benchmark["comparisons"]:
            lines.append("| Mode A | Mode B | N | Mean delta ns (A-B) | Median ratio A/B | Wilcoxon p | BH-adjusted p | Significant |")
            lines.append("| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |")
            for comparison in benchmark["comparisons"]:
                lines.append(
                    f"| {comparison['mode_a']} | {comparison['mode_b']} | {comparison['n']} | "
                    f"{format_float(comparison['mean_delta_ns'])} | {format_float(comparison['median_ratio_a_over_b'], 3)} | "
                    f"{format_float(comparison['pvalue'], 4)} | {format_float(comparison['pvalue_adjusted_bh'], 4)} | "
                    f"{'Yes' if comparison['significant_bh_0_05'] else 'No'} |"
                )
            lines.append("")

    lines.append("## Aggregate")
    lines.append("")
    lines.append(f"- Benchmarks: `{summary_rows['suite_summary']['benchmarks']}`")
    lines.append(f"- Mode rows: `{summary_rows['suite_summary']['mode_rows']}`")
    lines.append(f"- Pairwise comparisons: `{summary_rows['suite_summary']['comparisons']}`")
    lines.append(f"- Noisy mode rows: `{summary_rows['suite_summary']['noisy_mode_rows']}`")
    lines.append(
        f"- Publication-ready environment: `{raw_results['preflight']['publication_ready']}` "
        "(requires performance governor, turbo disabled, no heavy processes, isolated CPU)"
    )
    path.write_text("\n".join(lines) + "\n")


def build_machine_summary(raw_results: dict[str, object]) -> dict[str, object]:
    mode_rows: list[dict[str, object]] = []
    comparison_rows: list[dict[str, object]] = []
    for benchmark in raw_results["benchmarks"]:
        for mode in benchmark["modes"]:
            stats = mode["stats"]
            mode_rows.append(
                {
                    "benchmark": benchmark["name"],
                    "mode": mode["mode"],
                    "n": stats["n"],
                    "median_exec_ns": stats["median"],
                    "mean_exec_ns": stats["mean"],
                    "stdev_exec_ns": stats["stdev"],
                    "iqr_exec_ns": stats["iqr"],
                    "ci95_mean_low": stats["ci95_mean"]["low"],
                    "ci95_mean_high": stats["ci95_mean"]["high"],
                    "cv": stats["cv"],
                    "noisy": stats["noisy"],
                    "outlier_count": stats["outlier_count"],
                }
            )
        comparison_rows.extend(benchmark["comparisons"])

    suite_summary = {
        "benchmarks": len(raw_results["benchmarks"]),
        "mode_rows": len(mode_rows),
        "comparisons": len(comparison_rows),
        "noisy_mode_rows": sum(1 for row in mode_rows if row["noisy"]),
    }
    return {
        "run_id": raw_results["run_id"],
        "generated_at": raw_results["generated_at"],
        "suite": raw_results["suite"],
        "runtime": raw_results["runtime"],
        "mode_rows": mode_rows,
        "comparison_rows": comparison_rows,
        "suite_summary": suite_summary,
        "system": raw_results["system"],
        "preflight": {
            "publication_ready": raw_results["preflight"]["publication_ready"],
            "checks": raw_results["preflight"]["checks"],
        },
        "methodology": raw_results["methodology"],
    }


def benchmark_slug(benchmarks: list[BenchmarkSpec], suite: SuiteSpec) -> str:
    if len(benchmarks) == 1:
        return benchmarks[0].name
    if benchmarks and len(benchmarks) <= 4:
        return "-".join(benchmark.name for benchmark in benchmarks)
    return suite.suite_name


def print_dry_run(
    *,
    build_commands: list[list[str]],
    suite: SuiteSpec,
    runtime: RuntimeSpec,
    modes: list[ModeSpec],
    benchmarks: list[BenchmarkSpec],
    methodology: dict[str, object],
    pinning: PinningSpec,
    preflight: dict[str, object],
    kernel_image: Path | None,
) -> None:
    print("[dry-run] configuration")
    print(json.dumps(
        {
            "suite": suite.suite_name,
            "runtime": runtime.name,
            "modes": [mode.name for mode in modes],
            "kernel_image": str(kernel_image) if kernel_image is not None else None,
            "methodology": methodology,
            "pinning": {
                "cpu": pinning.cpu,
                "tool": pinning.tool,
                "source": pinning.source,
                "is_isolated": pinning.is_isolated,
            },
            "publication_ready": preflight["publication_ready"],
        },
        indent=2,
    ))
    print("[dry-run] build commands")
    for command in build_commands:
        print("  " + " ".join(command))
    print("[dry-run] benchmark commands")
    for benchmark in benchmarks:
        memory_file = resolve_memory_file(benchmark, regenerate_inputs=False)
        for mode in modes:
            command = build_base_command(
                suite=suite,
                runtime=runtime,
                benchmark=benchmark,
                repeat=int(methodology["repeat"]),
                memory_file=memory_file,
                mode=mode,
            )
            wrapped = wrap_command(command, runtime, pinning)
            print(f"  [{benchmark.name}/{mode.name}] {' '.join(wrapped)}")


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite))
    runtime = resolve_runtime(args.runtime, suite)
    modes = resolve_modes(runtime, args.modes)
    benchmarks = select_benchmarks(args.benches, suite)

    iterations = QUICK_ITERATIONS if args.quick else (args.iterations or DEFAULT_ITERATIONS)
    warmups = QUICK_WARMUPS if args.quick else (args.warmups or DEFAULT_WARMUPS)
    repeat = QUICK_REPEAT if args.quick else (args.repeat or DEFAULT_REPEAT)

    if iterations <= 0 or warmups < 0 or repeat <= 0:
        raise SystemExit("iterations/repeat must be positive and warmups must be non-negative")

    kernel_image = Path(args.kernel).resolve() if args.kernel else None
    if kernel_image is not None and not kernel_image.exists():
        raise SystemExit(f"kernel image not found: {kernel_image}")

    pinning = choose_pinning_spec(args.cpu, args.pin_tool)
    methodology = {
        "iterations": iterations,
        "warmups": warmups,
        "repeat": repeat,
        "bootstrap_samples": args.bootstrap_samples,
        "shuffle_seed": args.seed,
        "runtime_order_seed": DEFAULT_RUNTIME_ORDER_SEED if args.seed == 0 else args.seed,
        "outlier_rule": "flag values outside [Q1 - 3*IQR, Q3 + 3*IQR]",
        "noise_rule": "CV > 0.05",
        "paired_test": "Wilcoxon signed-rank",
        "multiple_comparison_correction": "Benjamini-Hochberg across all benchmark/mode comparisons in this run",
    }

    build_commands = planned_build_commands(suite)
    preflight = perform_preflight(
        pinning=pinning,
        runtime=runtime,
        allow_system_fixes=not args.no_system_fixes,
        dry_run=args.dry_run,
        heavy_process_threshold=args.heavy_process_threshold,
        heavy_process_sample_seconds=args.heavy_process_sample_seconds,
        kernel_image=kernel_image,
    )
    if not preflight["ok"]:
        print(json.dumps(preflight, indent=2), file=sys.stderr)
        raise SystemExit("preflight failed")

    if args.dry_run:
        print_dry_run(
            build_commands=build_commands,
            suite=suite,
            runtime=runtime,
            modes=modes,
            benchmarks=benchmarks,
            methodology=methodology,
            pinning=pinning,
            preflight=preflight,
            kernel_image=kernel_image,
        )
        return 0

    execute_build_commands(build_commands, args.skip_build)

    run_id = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    results: dict[str, object] = {
        "run_id": run_id,
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "runtime": {
            "name": runtime.name,
            "label": runtime.label,
            "mode": runtime.mode,
        },
        "mode_names": [mode.name for mode in modes],
        "methodology": methodology,
        "system": preflight["system"],
        "preflight": {
            "publication_ready": preflight["publication_ready"],
            "checks": preflight["checks"],
        },
        "benchmarks": [],
    }

    for benchmark in benchmarks:
        memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
        benchmark_record: dict[str, object] = {
            "name": benchmark.name,
            "description": benchmark.description,
            "category": benchmark.category,
            "family": benchmark.family,
            "level": benchmark.level,
            "io_mode": benchmark.io_mode,
            "expected_result": benchmark.expected_result,
            "program_object": str(benchmark.program_object),
            "input": str(memory_file) if memory_file is not None else None,
            "iteration_mode_orders": [],
            "modes": [],
            "comparisons": [],
        }
        print(f"[bench] {benchmark.name}")

        per_mode: dict[str, dict[str, object]] = {}
        for mode in modes:
            base_command = build_base_command(suite, runtime, benchmark, repeat, memory_file, mode)
            wrapped_command = wrap_command(base_command, runtime, pinning)
            warmup_samples: list[dict[str, object]] = []
            for _ in range(warmups):
                warmup_samples.append(run_mode_iteration(wrapped_command))
            per_mode[mode.name] = {
                "mode": mode.name,
                "label": mode.label,
                "command": wrapped_command,
                "base_command": base_command,
                "warmup_samples": warmup_samples,
                "samples": [],
            }

        for iteration_index in range(iterations):
            if len(modes) == 2:
                ordered_modes = list(modes) if iteration_index % 2 == 0 else list(reversed(modes))
            else:
                ordered_modes = list(modes)
                random.Random(args.seed + iteration_index).shuffle(ordered_modes)
            benchmark_record["iteration_mode_orders"].append([mode.name for mode in ordered_modes])
            for mode in ordered_modes:
                record = per_mode[mode.name]
                sample = run_mode_iteration(list(record["command"]))
                sample["iteration_index"] = iteration_index
                if benchmark.expected_result is not None and sample.get("result") != benchmark.expected_result:
                    raise RuntimeError(
                        f"{benchmark.name}/{mode.name} result mismatch: "
                        f"{sample.get('result')} != {benchmark.expected_result}"
                    )
                record["samples"].append(sample)

        for mode in modes:
            record = per_mode[mode.name]
            summarize_mode_record(record, args.bootstrap_samples, args.seed + len(benchmark_record["modes"]) + 17)
            benchmark_record["modes"].append(record)
            stats = record["stats"]
            print(
                f"  {mode.name:18} median {format_float(stats['median'])} ns | "
                f"mean {format_float(stats['mean'])} ns | cv {format_float(stats['cv'], 3)}"
            )

        benchmark_record["comparisons"] = build_pairwise_comparisons(benchmark_record)
        results["benchmarks"].append(benchmark_record)

    all_comparisons = [
        comparison
        for benchmark in results["benchmarks"]
        for comparison in benchmark["comparisons"]
    ]
    adjusted = benjamini_hochberg_adjust([comparison["pvalue"] for comparison in all_comparisons])
    for comparison, adjusted_p in zip(all_comparisons, adjusted):
        comparison["pvalue_adjusted_bh"] = adjusted_p
        comparison["significant_bh_0_05"] = bool(adjusted_p is not None and adjusted_p < 0.05)

    summary = build_machine_summary(results)
    output_dir = Path(args.output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    slug = benchmark_slug(benchmarks, suite)
    raw_path = output_dir / f"{run_id}_{slug}.json"
    summary_json_path = output_dir / f"{run_id}_summary.json"
    summary_md_path = output_dir / f"{run_id}_summary.md"
    raw_path.write_text(json.dumps(results, indent=2))
    summary_json_path.write_text(json.dumps(summary, indent=2))
    write_summary_markdown(summary_md_path, results, summary)
    print(f"[done] raw results: {raw_path}")
    print(f"[done] summary json: {summary_json_path}")
    print(f"[done] summary md: {summary_md_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
