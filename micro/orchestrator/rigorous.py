from __future__ import annotations

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
from pathlib import Path
from typing import Callable

try:
    from benchmark_catalog import BenchmarkSpec, ROOT_DIR, RuntimeSpec, SuiteSpec
except ImportError:
    from micro.benchmark_catalog import BenchmarkSpec, ROOT_DIR, RuntimeSpec, SuiteSpec

from .commands import build_runner_command, maybe_prepend_sudo
from .benchmarks import resolve_memory_file, select_benchmarks

try:
    import numpy as np
except ImportError:  # pragma: no cover
    np = None

try:
    from scipy.stats import wilcoxon as scipy_wilcoxon
except ImportError:  # pragma: no cover
    scipy_wilcoxon = None


DEFAULT_BOOTSTRAP_SAMPLES = 10_000
DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS = 0.5
DEFAULT_HEAVY_PROCESS_THRESHOLD = 25.0
DEFAULT_ITERATIONS = 30
DEFAULT_REPEAT = 1000
DEFAULT_RUNTIME_ORDER_SEED = 0
DEFAULT_WARMUPS = 5
QUICK_ITERATIONS = 5
QUICK_REPEAT = 100
QUICK_WARMUPS = 2


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


def read_optional_text(path: str | Path) -> str | None:
    try:
        return Path(path).read_text().strip()
    except OSError:
        return None


def run_subprocess(command: list[str], *, cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        command,
        cwd=str(cwd) if cwd is not None else None,
        capture_output=True,
        text=True,
    )


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
    return list(range(os.cpu_count() or 1))


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
        selected_cpu = cpu
        source = "user-specified"
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
    return {
        "per_cpu": {str(cpu): governor for cpu, governor in governors.items()},
        "unique": sorted(set(governors.values())),
        "all_performance": bool(governors) and all(governor == "performance" for governor in governors.values()),
    }


def turbo_snapshot() -> dict[str, object]:
    intel_path = Path("/sys/devices/system/cpu/intel_pstate/no_turbo")
    boost_path = Path("/sys/devices/system/cpu/cpufreq/boost")
    if intel_path.exists():
        raw = read_optional_text(intel_path) or "unknown"
        return {"interface": str(intel_path), "raw_value": raw, "disabled": raw == "1", "disable_value": "1"}
    if boost_path.exists():
        raw = read_optional_text(boost_path) or "unknown"
        return {"interface": str(boost_path), "raw_value": raw, "disabled": raw == "0", "disable_value": "0"}
    return {"interface": None, "raw_value": "unknown", "disabled": None, "disable_value": None}


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
    run_root_shell(
        r"""
set -euo pipefail
for f in /sys/devices/system/cpu/cpu[0-9]*/cpufreq/scaling_governor; do
  [ -f "$f" ] || continue
  echo performance > "$f"
done
"""
    )


def disable_turbo() -> None:
    turbo = turbo_snapshot()
    interface = turbo.get("interface")
    disable_value = turbo.get("disable_value")
    if not interface or disable_value is None:
        raise RuntimeError("turbo control interface not found")
    run_root_shell(f"set -euo pipefail\necho {disable_value} > {interface}\n")


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
            {"pid": pid, "comm": comm, "cmdline": cmdline, "jiffies": utime + stime}
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

    meta_by_pid = {int(entry["pid"]): entry for entry in proc_meta_end}
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
    heavy = [row for row in rows if row["pid"] not in allowed_pids and float(row["cpu_percent"]) >= threshold_percent]
    return {
        "sample_seconds": sample_seconds,
        "threshold_percent": threshold_percent,
        "heavy_processes": heavy,
        "top": rows[:10],
    }


def collect_system_info(pinning: PinningSpec, runtime: RuntimeSpec, kernel_image: Path | None) -> dict[str, object]:
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
        "governor": governor_snapshot(),
        "turbo": turbo_snapshot(),
        "frequency_mhz": {
            "min_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq"),
            "max_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"),
            "base_mhz": read_freq_khz("/sys/devices/system/cpu/cpu0/cpufreq/base_frequency"),
        },
        "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        "git_sha": run_checked(["git", "rev-parse", "HEAD"], cwd=ROOT_DIR).stdout.strip(),
        "kernel_image": str(kernel_image) if kernel_image is not None else None,
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
    return percentile_interval(estimates)


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
    return {
        "n": len(values),
        "mean": mean_value,
        "median": statistics.median(values),
        "stdev": stdev_value,
        "min": min(values),
        "max": max(values),
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
    w_plus = sum(rank_value for rank_value, diff in ranks if diff > 0)
    w_minus = sum(rank_value for rank_value, diff in ranks if diff < 0)
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
    names = [part.strip() for part in raw_modes.split(",") if part.strip()] if raw_modes else ["stock", "recompile-all"]
    modes: list[ModeSpec] = []
    for name in names:
        mode = catalog.get(name)
        if mode is None:
            raise SystemExit(f"unknown mode '{name}'. Valid modes: {', '.join(sorted(catalog))}")
        modes.append(mode)
    return modes


def planned_build_commands(suite: SuiteSpec) -> list[list[str]]:
    return [list(suite.build.commands["micro_exec"]), list(suite.build.commands["programs"])]


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
    if runtime.require_sudo:
        return maybe_prepend_sudo(pinned, enabled=(os.geteuid() != 0))
    return pinned


def parse_micro_exec_output(stdout: str) -> dict[str, object]:
    lines = stdout.strip().splitlines()
    if not lines:
        raise RuntimeError("micro_exec produced no output")
    payload = json.loads(lines[-1])
    if not isinstance(payload, dict):
        raise RuntimeError("micro_exec payload was not an object")
    return payload


def run_mode_iteration(command: list[str]) -> dict[str, object]:
    completed = run_checked(command)
    return parse_micro_exec_output(completed.stdout)


def pair_values_by_iteration(samples: list[dict[str, object]]) -> dict[int, float]:
    indexed: dict[int, float] = {}
    for sample in samples:
        indexed[int(sample["iteration_index"])] = float(sample["exec_ns"])
    return indexed


def format_float(value: float | None, precision: int = 2) -> str:
    if value is None or math.isnan(value):
        return "n/a"
    return f"{value:.{precision}f}"


def format_ci_range(low: float | None, high: float | None) -> str:
    if low is None or high is None:
        return "n/a"
    return f"[{low:.2f}, {high:.2f}]"


__all__ = [
    "DEFAULT_BOOTSTRAP_SAMPLES",
    "DEFAULT_HEAVY_PROCESS_SAMPLE_SECONDS",
    "DEFAULT_HEAVY_PROCESS_THRESHOLD",
    "DEFAULT_ITERATIONS",
    "DEFAULT_REPEAT",
    "DEFAULT_RUNTIME_ORDER_SEED",
    "DEFAULT_WARMUPS",
    "ModeSpec",
    "PinningSpec",
    "QUICK_ITERATIONS",
    "QUICK_REPEAT",
    "QUICK_WARMUPS",
    "apply_pinning",
    "benjamini_hochberg_adjust",
    "build_base_command",
    "choose_pinning_spec",
    "collect_system_info",
    "detect_heavy_processes",
    "disable_turbo",
    "execute_build_commands",
    "format_ci_range",
    "format_float",
    "governor_snapshot",
    "kernel_mode_catalog",
    "planned_build_commands",
    "resolve_memory_file",
    "resolve_modes",
    "resolve_runtime",
    "run_checked",
    "run_mode_iteration",
    "run_root_shell",
    "set_governor_performance",
    "summarize_exec",
    "turbo_snapshot",
    "wilcoxon_signed_rank",
    "wrap_command",
]
