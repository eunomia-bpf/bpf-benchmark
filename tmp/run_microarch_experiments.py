#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import shlex
import subprocess
import sys
import time
from pathlib import Path

import yaml


ROOT = Path(__file__).resolve().parents[1]
TMP = ROOT / "tmp"
CONFIG = ROOT / "config" / "micro_pure_jit.yaml"
REPORT_PATH = TMP / "microarch_experiments.md"
META_PATH = TMP / "microarch_meta.json"

BENCHMARKS = [
    "simple",
    "binary_search",
    "bitcount",
    "load_byte_recompose",
    "switch_dispatch",
    "mega_basic_block_2048",
]
BRANCH_BENCHMARKS = ["branch_layout", "branch_fanout_32"]
CPU = "0"
ITERATIONS = 5
WARMUPS = 2
REPEAT = 500

CPUFREQ_POLICY = Path("/sys/devices/system/cpu/cpufreq/policy0")
INTEL_PSTATE = Path("/sys/devices/system/cpu/intel_pstate")

FREQ_OUTPUTS = {
    "low": TMP / "freq_sweep_low.json",
    "mid": TMP / "freq_sweep_mid.json",
    "high": TMP / "freq_sweep_high.json",
}
BRANCH_OUTPUTS = {
    "predictable": TMP / "branch_distribution_predictable.json",
    "random": TMP / "branch_distribution_random.json",
}
PMU_OUTPUT = TMP / "pmu_microarch.json"


def run(cmd: list[str], env: dict[str, str] | None = None) -> None:
    print(f"[cmd] {' '.join(shlex.quote(part) for part in cmd)}", flush=True)
    subprocess.run(cmd, cwd=ROOT, check=True, env=env)


def capture(cmd: list[str]) -> str:
    return subprocess.check_output(cmd, cwd=ROOT, text=True).strip()


def read_text(path: Path) -> str:
    return path.read_text().strip()


def read_optional_text(path: Path) -> str | None:
    try:
        return path.read_text().strip()
    except OSError:
        return None


def read_int(path: Path) -> int:
    return int(read_text(path))


def maybe_int(value: str | None) -> int | None:
    if value is None:
        return None
    value = value.strip()
    if not value or not value.isdigit():
        return None
    return int(value)


def capture_policy_state() -> dict[str, object]:
    return {
        "driver": read_optional_text(CPUFREQ_POLICY / "scaling_driver"),
        "governor": read_optional_text(CPUFREQ_POLICY / "scaling_governor"),
        "min_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "scaling_min_freq")),
        "max_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "scaling_max_freq")),
        "cur_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "scaling_cur_freq")),
        "avg_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "cpuinfo_avg_freq")),
        "cpuinfo_min_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "cpuinfo_min_freq")),
        "cpuinfo_max_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "cpuinfo_max_freq")),
        "base_khz": maybe_int(read_optional_text(CPUFREQ_POLICY / "base_frequency")),
        "no_turbo": maybe_int(read_optional_text(INTEL_PSTATE / "no_turbo")),
        "intel_pstate_status": read_optional_text(INTEL_PSTATE / "status"),
    }


def apply_fixed_frequency(freq_khz: int) -> dict[str, object]:
    current = capture_policy_state()
    current_min = int(current["min_khz"] or freq_khz)
    current_max = int(current["max_khz"] or freq_khz)

    commands = [
        "echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo",
        "echo performance > /sys/devices/system/cpu/cpufreq/policy0/scaling_governor",
    ]
    if freq_khz < current_min:
        commands.extend(
            [
                f"echo {freq_khz} > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq",
                f"echo {freq_khz} > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",
            ]
        )
    else:
        commands.extend(
            [
                f"echo {freq_khz} > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",
                f"echo {freq_khz} > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq",
            ]
        )
    run(["sudo", "bash", "-lc", " && ".join(commands)])
    time.sleep(0.5)
    return capture_policy_state()


def restore_policy_state(state: dict[str, object]) -> None:
    commands = []
    governor = state.get("governor")
    min_khz = state.get("min_khz")
    max_khz = state.get("max_khz")
    no_turbo = state.get("no_turbo")

    current = capture_policy_state()
    current_min = int(current["min_khz"] or 0)
    target_min = int(min_khz or current_min)
    target_max = int(max_khz or target_min)
    if target_max < current_min:
        commands.extend(
            [
                f"echo {target_min} > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq",
                f"echo {target_max} > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",
            ]
        )
    else:
        commands.extend(
            [
                f"echo {target_max} > /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",
                f"echo {target_min} > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq",
            ]
        )
    if governor:
        commands.append(f"echo {governor} > /sys/devices/system/cpu/cpufreq/policy0/scaling_governor")
    if no_turbo is not None:
        commands.append(f"echo {int(no_turbo)} > /sys/devices/system/cpu/intel_pstate/no_turbo")
    run(["sudo", "bash", "-lc", " && ".join(commands)])


def run_micro(
    output: Path,
    benches: list[str],
    suite: Path | None = None,
    perf_counters: bool = False,
    regenerate_inputs: bool = False,
) -> None:
    cmd = ["python3", "micro/run_micro.py"]
    if suite is not None:
        cmd.extend(["--suite", str(suite)])
    for bench in benches:
        cmd.extend(["--bench", bench])
    cmd.extend(
        [
            "--runtime",
            "llvmbpf",
            "--runtime",
            "kernel",
            "--iterations",
            str(ITERATIONS),
            "--warmups",
            str(WARMUPS),
            "--repeat",
            str(REPEAT),
            "--strict-env",
            "--cpu",
            CPU,
            "--output",
            str(output),
        ]
    )
    if regenerate_inputs:
        cmd.append("--regenerate-inputs")
    if perf_counters:
        cmd.append("--perf-counters")
    run(cmd)


def write_branch_suite(label: str, overrides: dict[str, str]) -> Path:
    data = yaml.safe_load(CONFIG.read_text())
    selected = []
    for benchmark in data["benchmarks"]:
        name = benchmark["name"]
        if name not in overrides:
            continue
        updated = dict(benchmark)
        updated["input_generator"] = overrides[name]
        updated["expected_result"] = None
        selected.append(updated)
    data["suite_name"] = f"micro_branch_distribution_{label}"
    data["benchmarks"] = selected
    data["analysis"] = {"baseline_benchmark": None}
    data["defaults"]["output"] = str((TMP / f"branch_distribution_{label}.json").relative_to(ROOT))
    suite_path = TMP / f"branch_distribution_{label}.yaml"
    suite_path.write_text(yaml.safe_dump(data, sort_keys=False))
    return suite_path


def parse_lscpu() -> dict[str, str]:
    fields = {}
    for line in capture(["lscpu"]).splitlines():
        if ":" not in line:
            continue
        key, value = line.split(":", 1)
        fields[key.strip()] = value.strip()
    return fields


def load_json(path: Path) -> dict[str, object]:
    return json.loads(path.read_text())


def benchmark_runs(doc: dict[str, object], benchmark_name: str) -> dict[str, dict[str, object]]:
    for benchmark in doc["benchmarks"]:
        if benchmark["name"] == benchmark_name:
            return {run["runtime"]: run for run in benchmark["runs"]}
    raise KeyError(f"missing benchmark {benchmark_name} in {doc.get('suite')}")


def exec_ratio(doc: dict[str, object], benchmark_name: str) -> float | None:
    runs = benchmark_runs(doc, benchmark_name)
    llvm = runs["llvmbpf"]["exec_ns"]["median"]
    kernel = runs["kernel"]["exec_ns"]["median"]
    if llvm in (None, 0) or kernel in (None, 0):
        return None
    return float(llvm) / float(kernel)


def exec_median(doc: dict[str, object], benchmark_name: str, runtime: str) -> float | None:
    return benchmark_runs(doc, benchmark_name)[runtime]["exec_ns"]["median"]


def pmu_metrics(doc: dict[str, object], benchmark_name: str, runtime: str) -> dict[str, object]:
    return benchmark_runs(doc, benchmark_name)[runtime]


def fmt_ns(value: float | int | None) -> str:
    if value is None:
        return "n/a"
    value = float(value)
    if value >= 1000.0:
        return f"{value / 1000.0:.1f} us"
    return f"{value:.0f} ns"


def fmt_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def fmt_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value * 100.0:.2f}%"


def markdown_table(headers: list[str], rows: list[list[str]]) -> str:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join(["---"] * len(headers)) + " |",
    ]
    lines.extend("| " + " | ".join(row) + " |" for row in rows)
    return "\n".join(lines)


def ratio_spread(values: list[float | None]) -> float | None:
    observed = [value for value in values if value is not None]
    if len(observed) < 2 or min(observed) == 0:
        return None
    return max(observed) / min(observed) - 1.0


def classify_delta(delta: float | None) -> str:
    if delta is None:
        return "n/a"
    if delta >= 0.15:
        return "material"
    if delta >= 0.05:
        return "minor"
    return "flat"


def write_report(meta: dict[str, object]) -> None:
    freq_docs = {label: load_json(path) for label, path in FREQ_OUTPUTS.items()}
    branch_docs = {label: load_json(path) for label, path in BRANCH_OUTPUTS.items()}
    pmu_doc = load_json(PMU_OUTPUT)
    freq_timer_limited = {
        benchmark: any(
            max(
                exec_median(doc, benchmark, "llvmbpf") or 0,
                exec_median(doc, benchmark, "kernel") or 0,
            )
            < 100
            for doc in freq_docs.values()
        )
        for benchmark in BENCHMARKS
    }

    freq_rows = []
    for benchmark in BENCHMARKS:
        low = exec_ratio(freq_docs["low"], benchmark)
        mid = exec_ratio(freq_docs["mid"], benchmark)
        high = exec_ratio(freq_docs["high"], benchmark)
        spread = ratio_spread([low, mid, high])
        classification = "timer-limited" if freq_timer_limited[benchmark] else classify_delta(spread)
        freq_rows.append(
            [
                benchmark,
                fmt_ratio(low),
                fmt_ratio(mid),
                fmt_ratio(high),
                "n/a" if spread is None else f"{spread * 100.0:.1f}%",
                classification,
            ]
        )

    branch_rows = []
    for benchmark in BRANCH_BENCHMARKS:
        predictable = exec_ratio(branch_docs["predictable"], benchmark)
        random_ratio = exec_ratio(branch_docs["random"], benchmark)
        delta = None
        if predictable not in (None, 0) and random_ratio is not None:
            delta = abs(random_ratio / predictable - 1.0)
        branch_rows.append(
            [
                benchmark,
                fmt_ratio(predictable),
                fmt_ratio(random_ratio),
                "n/a" if delta is None else f"{delta * 100.0:.1f}%",
                classify_delta(delta),
            ]
        )

    pmu_rows = []
    for benchmark in BENCHMARKS:
        for runtime in ("llvmbpf", "kernel"):
            run_record = pmu_metrics(pmu_doc, benchmark, runtime)
            derived = run_record.get("derived_metrics", {})
            pmu_rows.append(
                [
                    benchmark,
                    runtime,
                    fmt_ns(run_record["exec_ns"]["median"]),
                    f"{derived.get('ipc_median', 0.0):.3f}" if derived.get("ipc_median") is not None else "n/a",
                    fmt_pct(derived.get("branch_miss_rate_median")),
                    fmt_pct(derived.get("cache_miss_rate_median")),
                ]
            )

    freq_findings = []
    for benchmark in BENCHMARKS:
        ratios = [exec_ratio(doc, benchmark) for doc in freq_docs.values()]
        delta = ratio_spread(ratios)
        low = exec_ratio(freq_docs["low"], benchmark)
        high = exec_ratio(freq_docs["high"], benchmark)
        if delta is None:
            continue
        if freq_timer_limited[benchmark]:
            freq_findings.append(
                f"`{benchmark}` is timer-limited here: at least one runtime stayed below ~100 ns, so the ratio swing is mostly quantization noise."
            )
            continue
        if delta >= 0.15 and low is not None and high is not None:
            direction = "llvmbpf gained relative to kernel" if high < low else "kernel gained relative to llvmbpf"
            freq_findings.append(
                f"`{benchmark}` moved materially across frequency points ({delta * 100.0:.1f}% ratio spread); {direction} as frequency increased."
            )
    if not freq_findings:
        freq_findings.append("No benchmark crossed a 15% L/K ratio spread across the fixed-frequency sweep.")

    branch_findings = []
    for benchmark in BRANCH_BENCHMARKS:
        predictable = exec_ratio(branch_docs["predictable"], benchmark)
        random_ratio = exec_ratio(branch_docs["random"], benchmark)
        if predictable in (None, 0) or random_ratio is None:
            continue
        delta = abs(random_ratio / predictable - 1.0)
        if delta >= 0.15:
            branch_findings.append(
                f"`{benchmark}` was distribution-sensitive: predictable {predictable:.3f}x vs random {random_ratio:.3f}x."
            )
        else:
            branch_findings.append(
                f"`{benchmark}` only moved modestly under the predictable/random switch ({delta * 100.0:.1f}% ratio delta)."
            )

    pmu_findings = []
    for benchmark in BENCHMARKS:
        llvm = pmu_metrics(pmu_doc, benchmark, "llvmbpf")
        kernel = pmu_metrics(pmu_doc, benchmark, "kernel")
        llvm_exec = llvm["exec_ns"]["median"]
        kernel_exec = kernel["exec_ns"]["median"]
        faster = "llvmbpf" if llvm_exec < kernel_exec else "kernel"
        llvm_ipc = llvm.get("derived_metrics", {}).get("ipc_median")
        kernel_ipc = kernel.get("derived_metrics", {}).get("ipc_median")
        if llvm_ipc is not None and kernel_ipc is not None:
            better_ipc = "llvmbpf" if llvm_ipc > kernel_ipc else "kernel"
            if benchmark == "simple":
                pmu_findings.append(
                    "`simple`: timer-limited benchmark, so treat PMU-vs-time comparisons as qualitative only."
                )
                continue
            pmu_findings.append(
                f"`{benchmark}`: faster runtime was `{faster}`; higher IPC belonged to `{better_ipc}`."
            )

    report_lines = [
        "# Microarchitectural Experiments",
        "",
        "## Setup",
        f"- Host CPU: {meta['lscpu'].get('Model name', 'unknown')}",
        f"- CPUs / SMT: {meta['lscpu'].get('CPU(s)', 'unknown')} CPUs, {meta['lscpu'].get('Thread(s) per core', 'unknown')} thread(s) per core, `/sys/devices/system/cpu/smt/active={meta['smt_active']}`",
        f"- cpufreq driver: {meta['original_policy'].get('driver', 'unknown')} (`intel_pstate` status: {meta['original_policy'].get('intel_pstate_status', 'unknown')})",
        "- `cpupower` was not usable on this kernel build, so frequency control used the cpufreq sysfs interface directly.",
        "- `--strict-env` requires `performance` governor and `no_turbo=1` in this harness, so the requested max/min/mid sweep was implemented as fixed `performance`-governor clamps rather than a literal `powersave` run.",
        f"- Fixed frequency points: low {meta['frequencies']['low']} kHz, mid {meta['frequencies']['mid']} kHz, high {meta['frequencies']['high']} kHz.",
        "",
        "## Experiment 1: CPU Frequency Sweep",
        markdown_table(
            ["benchmark", "low L/K", "mid L/K", "high L/K", "ratio spread", "classification"],
            freq_rows,
        ),
        "",
        "Frequency notes:",
        *[f"- {finding}" for finding in freq_findings],
        "",
        "## Experiment 2: Input Distribution Sweep",
        "- `branch_layout` predictable input keeps all values on the hot `< hot_threshold` path; random input uses a pseudorandom hot/cold split.",
        "- `branch_fanout_32` predictable input repeats a single tag; random input uses a pseudorandom 32-way tag mix.",
        markdown_table(
            ["benchmark", "predictable L/K", "random L/K", "ratio delta", "classification"],
            branch_rows,
        ),
        "",
        "Distribution notes:",
        *[f"- {finding}" for finding in branch_findings],
        "",
        "## Experiment 3: SMT Effects",
        "- Skipped. This host reports `Thread(s) per core: 1` and `/sys/devices/system/cpu/smt/active=0`, so there is no sibling logical CPU to stress.",
        "",
        "## Experiment 4: PMU Counter Collection",
        markdown_table(
            ["benchmark", "runtime", "exec median", "IPC", "branch miss rate", "cache miss rate"],
            pmu_rows,
        ),
        "",
        "PMU notes:",
        *[f"- {finding}" for finding in pmu_findings],
        "",
        "## Conclusions",
    ]

    material_freq = [row[0] for row in freq_rows if row[-1] == "material"]
    timer_limited_freq = [row[0] for row in freq_rows if row[-1] == "timer-limited"]
    material_branch = [row[0] for row in branch_rows if row[-1] == "material"]
    if material_freq:
        report_lines.append(
            f"- Frequency changed the L/K ratio materially for {', '.join(f'`{name}`' for name in material_freq)}."
        )
    else:
        report_lines.append("- Frequency mostly scaled both runtimes together; the L/K ratio stayed fairly stable across the sweep.")
    if material_branch:
        report_lines.append(
            f"- Branch predictability changed the L/K ratio materially for {', '.join(f'`{name}`' for name in material_branch)}."
        )
    else:
        report_lines.append("- The branch distribution sweep did not materially move the L/K ratio on this host.")
    if timer_limited_freq:
        report_lines.append(
            f"- `{timer_limited_freq[0]}` remained timer-limited across the sweep and should not be used to infer real frequency sensitivity."
        )
    report_lines.append("- SMT interference could not be evaluated because SMT is disabled or unavailable on this machine.")
    report_lines.append(
        "- PMU counters are most useful here for explaining why a ratio changed; they should not be over-interpreted when the benchmark itself is near timer resolution."
    )
    report_lines.append("")
    report_lines.append("## Artifacts")
    report_lines.append(f"- Frequency sweep JSONs: `{FREQ_OUTPUTS['low']}`, `{FREQ_OUTPUTS['mid']}`, `{FREQ_OUTPUTS['high']}`")
    report_lines.append(
        f"- Branch distribution JSONs: `{BRANCH_OUTPUTS['predictable']}`, `{BRANCH_OUTPUTS['random']}`"
    )
    report_lines.append(f"- PMU JSON: `{PMU_OUTPUT}`")
    report_lines.append(f"- Metadata: `{META_PATH}`")
    report_lines.append("")
    REPORT_PATH.write_text("\n".join(report_lines) + "\n")


def main() -> int:
    TMP.mkdir(parents=True, exist_ok=True)

    original_policy = capture_policy_state()
    lscpu = parse_lscpu()
    smt_active = read_optional_text(Path("/sys/devices/system/cpu/smt/active")) or "unknown"
    min_khz = int(original_policy["cpuinfo_min_khz"] or read_int(CPUFREQ_POLICY / "cpuinfo_min_freq"))
    base_khz = int(original_policy["base_khz"] or read_int(CPUFREQ_POLICY / "base_frequency"))
    mid_khz = (min_khz + base_khz) // 2
    frequencies = {"low": min_khz, "mid": mid_khz, "high": base_khz}

    predictable_suite = write_branch_suite(
        "predictable",
        {
            "branch_layout": "branch_layout_predictable",
            "branch_fanout_32": "branch_fanout_32_predictable",
        },
    )
    random_suite = write_branch_suite(
        "random",
        {
            "branch_layout": "branch_layout_random",
            "branch_fanout_32": "branch_fanout_32_random",
        },
    )

    meta: dict[str, object] = {
        "cpu": CPU,
        "benchmarks": BENCHMARKS,
        "branch_benchmarks": BRANCH_BENCHMARKS,
        "iterations": ITERATIONS,
        "warmups": WARMUPS,
        "repeat": REPEAT,
        "lscpu": lscpu,
        "smt_active": smt_active,
        "original_policy": original_policy,
        "frequencies": frequencies,
        "runs": {"frequency": {}, "branch": {}, "pmu": {}},
        "artifacts": {
            "branch_suite_predictable": str(predictable_suite),
            "branch_suite_random": str(random_suite),
        },
    }

    prior_error: Exception | None = None
    try:
        for label, freq_khz in frequencies.items():
            print(f"[freq] {label} => {freq_khz} kHz", flush=True)
            state = apply_fixed_frequency(freq_khz)
            meta["runs"]["frequency"][label] = {"policy": state, "output": str(FREQ_OUTPUTS[label])}
            run_micro(FREQ_OUTPUTS[label], BENCHMARKS)

        high_state = apply_fixed_frequency(frequencies["high"])
        meta["runs"]["branch"]["base_policy"] = high_state
        run_micro(
            BRANCH_OUTPUTS["predictable"],
            BRANCH_BENCHMARKS,
            suite=predictable_suite,
            regenerate_inputs=True,
        )
        meta["runs"]["branch"]["predictable"] = {
            "suite": str(predictable_suite),
            "output": str(BRANCH_OUTPUTS["predictable"]),
        }
        run_micro(
            BRANCH_OUTPUTS["random"],
            BRANCH_BENCHMARKS,
            suite=random_suite,
            regenerate_inputs=True,
        )
        meta["runs"]["branch"]["random"] = {
            "suite": str(random_suite),
            "output": str(BRANCH_OUTPUTS["random"]),
        }

        high_state = apply_fixed_frequency(frequencies["high"])
        meta["runs"]["pmu"]["policy"] = high_state
        meta["runs"]["pmu"]["output"] = str(PMU_OUTPUT)
        run_micro(PMU_OUTPUT, BENCHMARKS, perf_counters=True)

        META_PATH.write_text(json.dumps(meta, indent=2))
        write_report(meta)
        print(f"[done] wrote {REPORT_PATH}", flush=True)
        return 0
    except Exception as exc:  # noqa: BLE001
        prior_error = exc
        raise
    finally:
        try:
            restore_policy_state(original_policy)
        except Exception as restore_exc:  # noqa: BLE001
            print(f"[warn] failed to restore cpufreq state: {restore_exc}", file=sys.stderr)
            if prior_error is None:
                raise


if __name__ == "__main__":
    raise SystemExit(main())
