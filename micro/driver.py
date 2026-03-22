#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import platform
import random
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

import yaml

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from benchmark_catalog import CONFIG_PATH, ROOT_DIR, RuntimeSpec, SuiteSpec, load_suite
except ImportError:
    from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR, RuntimeSpec, SuiteSpec, load_suite

try:
    from results_layout import maybe_refresh_latest_alias, refresh_latest_alias, smoke_output_path
except ImportError:
    from micro.results_layout import maybe_refresh_latest_alias, refresh_latest_alias, smoke_output_path

try:
    from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
    from runner.libs.commands import build_micro_benchmark_command
    from runner.libs.environment import (
        ensure_build_steps,
        read_optional_text,
        read_required_text,
        validate_publication_environment,
    )
    from runner.libs.results import (
        derive_perf_metrics,
        ns_summary,
        parse_runner_sample,
        summarize_named_counters,
        summarize_optional_ns,
        summarize_perf_counter_meta,
        summarize_phase_timings,
    )
except ImportError:
    from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
    from runner.libs.commands import build_micro_benchmark_command
    from runner.libs.environment import (
        ensure_build_steps,
        read_optional_text,
        read_required_text,
        validate_publication_environment,
    )
    from runner.libs.results import (
        derive_perf_metrics,
        ns_summary,
        parse_runner_sample,
        summarize_named_counters,
        summarize_optional_ns,
        summarize_perf_counter_meta,
        summarize_phase_timings,
    )


DEFAULT_RUNTIME_ORDER_SEED = 0


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run declarative micro benchmark suites.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name.")
    parser.add_argument("--iterations", type=int, help="Measured runs per pair.")
    parser.add_argument("--warmups", type=int, help="Warmup runs per pair.")
    parser.add_argument("--repeat", type=int, help="Repeat count inside each helper sample.")
    parser.add_argument(
        "--rejit",
        action="store_true",
        help="Enable REJIT same-bytecode mode for kernel-rejit runtimes.",
    )
    parser.add_argument(
        "--daemon-path",
        default=None,
        help=(
            "Path to bpfrejit-daemon binary. When set, passed to micro_exec for "
            "kernel-rejit runtimes so the daemon can apply in-place JIT optimizations."
        ),
    )
    parser.add_argument("--output", help="Override JSON output path.")
    parser.add_argument("--cpu", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument(
        "--strict-env",
        action="store_true",
        help="Fail if environment is not publication-grade",
    )
    parser.add_argument(
        "--shuffle-seed",
        type=int,
        help="Shuffle benchmark order with a reproducible seed.",
    )
    parser.add_argument(
        "--perf-counters",
        action="store_true",
        help="Collect perf_event counters across the full repeated run when available.",
    )
    parser.add_argument(
        "--perf-scope",
        default="full_repeat_raw",
        choices=["full_repeat_raw", "full_repeat_avg"],
        help="PMU scope: full_repeat_raw (default, raw totals) or full_repeat_avg (cumulative counters divided by repeat).",
    )
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated inputs.",
    )
    parser.add_argument(
        "--build-bpftool",
        action="store_true",
        help="Build vendored bpftool in addition to the runner and program artifacts.",
    )
    parser.add_argument("--list", action="store_true", help="List benchmarks and runtimes.")
    parser.add_argument(
        "--policy-dir",
        help="Override policy directory (for named policy sets under config/policies/).",
    )
    raw_args = list(sys.argv[1:] if argv is None else argv)
    # Strip legacy positional "suite" subcommand for backward-compat with Makefile callers
    if raw_args and raw_args[0] == "suite":
        raw_args = raw_args[1:]
    return parser.parse_args(raw_args)


def format_ns(value: float | int | None) -> str:
    if value is None:
        return "n/a"
    if abs(value - round(value)) < 1e-9:
        value = int(round(value))
    if value >= 1_000_000:
        return f"{value / 1_000_000:.3f} ms"
    if value >= 1_000:
        return f"{value / 1_000:.3f} us"
    return f"{value} ns"


def run_command(command: list[str], cpu: str | None) -> subprocess.CompletedProcess[str]:
    full_command = command
    if cpu is not None:
        full_command = ["taskset", "-c", cpu, *command]

    completed = subprocess.run(
        full_command,
        capture_output=True,
        text=True,
    )
    if completed.returncode != 0:
        details = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"command failed ({completed.returncode}): {' '.join(full_command)}\n{details}")
    return completed


def read_git_sha() -> str:
    try:
        return subprocess.check_output(
            ["git", "rev-parse", "HEAD"],
            cwd=ROOT_DIR,
            stderr=subprocess.DEVNULL,
        ).decode().strip()
    except (FileNotFoundError, subprocess.CalledProcessError):
        return "unknown"


def _git_rev_parse(repo_dir: Path, short: bool = False) -> str:
    args = ["git", "rev-parse", "--short", "HEAD"] if short else ["git", "rev-parse", "HEAD"]
    try:
        return subprocess.check_output(args, cwd=repo_dir, stderr=subprocess.DEVNULL).decode().strip()
    except (FileNotFoundError, subprocess.CalledProcessError):
        return "unknown"


def _git_is_dirty(repo_dir: Path) -> bool:
    try:
        completed = subprocess.run(
            ["git", "status", "--porcelain"],
            cwd=repo_dir,
            capture_output=True,
            text=True,
            check=False,
        )
    except OSError:
        return False
    if completed.returncode != 0:
        return False
    return bool(completed.stdout.strip())


def _read_cpu_model() -> str:
    try:
        for line in Path("/proc/cpuinfo").read_text().splitlines():
            if line.startswith("model name"):
                return line.split(":", 1)[1].strip()
    except OSError:
        pass
    return platform.processor() or "unknown"


def _detect_environment() -> str:
    indicators = [
        "/sys/class/dmi/id/sys_vendor",
        "/sys/class/dmi/id/product_name",
        "/sys/class/dmi/id/board_vendor",
    ]
    vm_keywords = {"kvm", "qemu", "vmware", "virtualbox", "xen", "vng", "virtio", "bochs", "hyper-v"}
    for path in indicators:
        try:
            value = Path(path).read_text().lower()
            if any(keyword in value for keyword in vm_keywords):
                return "vm"
        except OSError:
            pass
    try:
        for line in Path("/proc/cpuinfo").read_text().splitlines():
            if line.startswith("flags") and "hypervisor" in line:
                return "vm"
    except OSError:
        pass
    return "bare-metal"


def _hash_policy_files(policy_dir: Path) -> str:
    try:
        yaml_files = sorted(policy_dir.glob("**/*.yaml"))
        if not yaml_files:
            return "no-policies"
        digest = hashlib.sha256()
        for path in yaml_files:
            digest.update(path.read_bytes())
        return digest.hexdigest()[:16]
    except OSError:
        return "unknown"


def _read_policy_payload(policy_file: Path | None) -> tuple[object | None, str | None]:
    if policy_file is None:
        return None, None
    try:
        raw = policy_file.read_bytes()
    except OSError as exc:
        raise RuntimeError(f"failed to read policy file {policy_file}: {exc}") from exc
    try:
        payload = yaml.safe_load(raw.decode("utf-8"))
    except (UnicodeDecodeError, yaml.YAMLError) as exc:
        raise RuntimeError(f"failed to parse policy file {policy_file}: {exc}") from exc
    return payload, hashlib.sha256(raw).hexdigest()


def collect_provenance(
    args: argparse.Namespace,
    iterations: int,
    warmups: int,
    policy_dir: Path | None = None,
) -> dict[str, object]:
    linux_dir = ROOT_DIR / "vendor" / "linux-framework"
    kernel_commit = _git_rev_parse(linux_dir) if linux_dir.is_dir() else "unknown"

    daemon_dir = ROOT_DIR / "daemon"
    daemon_commit = _git_rev_parse(daemon_dir) if daemon_dir.is_dir() else "unknown"

    repo_git_sha = _git_rev_parse(ROOT_DIR)
    repo_dirty = _git_is_dirty(ROOT_DIR)

    default_policy_dir = ROOT_DIR / "micro" / "policies"
    effective_policy_dir = policy_dir if (policy_dir and policy_dir.is_dir()) else default_policy_dir
    policy_files_hash = _hash_policy_files(effective_policy_dir)

    return {
        "kernel_commit": kernel_commit,
        "daemon_commit": daemon_commit,
        "repo_git_sha": repo_git_sha,
        "repo_dirty": repo_dirty,
        "policy_files_hash": policy_files_hash,
        "policy_dir": str(effective_policy_dir),
        "params": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": args.repeat,
        },
        "cpu_model": _read_cpu_model(),
        "environment": _detect_environment(),
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }


def list_suite(suite: SuiteSpec) -> None:
    print("Benchmarks")
    print("----------")
    for benchmark in suite.benchmarks.values():
        tags = ",".join(benchmark.tags)
        family = benchmark.family or "-"
        level = benchmark.level or "-"
        print(f"{benchmark.name:20} {benchmark.category:18} {benchmark.io_mode:8} {family:16} {level:8} {tags}")

    print()
    print("Runtimes")
    print("--------")
    for runtime in suite.runtimes.values():
        aliases = f" (aliases: {', '.join(runtime.aliases)})" if runtime.aliases else ""
        print(f"{runtime.name:12} {runtime.label}{aliases}")


def select_runtimes(names: list[str] | None, suite: SuiteSpec) -> list[RuntimeSpec]:
    requested = names or list(suite.defaults.runtimes)
    selected: list[RuntimeSpec] = []
    for raw_name in requested:
        name = suite.runtime_aliases.get(raw_name, raw_name)
        if name not in suite.runtimes:
            raise SystemExit(f"unknown runtime: {raw_name}")
        selected.append(suite.runtimes[name])
    return selected


def ensure_artifacts_built(suite: SuiteSpec, build_bpftool: bool) -> None:
    build_order: list[str] = []
    if not suite.build.runner_binary.exists():
        build_order.append("micro_exec")

    missing_program_objects = any(not benchmark.program_object.exists() for benchmark in suite.benchmarks.values())
    if missing_program_objects:
        build_order.append("programs")

    if build_bpftool and not suite.build.bpftool_binary.exists():
        build_order.append("bpftool")

    if not build_order:
        print("[build] reusing existing artifacts")
        return

    ensure_build_steps(
        suite.build.commands,
        root_dir=ROOT_DIR,
        build_order=build_order,
    )


def attach_baseline_adjustments(results: dict[str, object], baseline_benchmark: str | None) -> None:
    if not baseline_benchmark:
        return

    benchmarks = results.get("benchmarks", [])
    baseline_record = next((record for record in benchmarks if record.get("name") == baseline_benchmark), None)
    if baseline_record is None:
        return

    baseline_io_mode = baseline_record.get("io_mode")
    runtime_baselines: dict[str, float] = {}
    for run in baseline_record.get("runs", []):
        median = run.get("exec_ns", {}).get("median")
        if median is not None:
            runtime_baselines[str(run["runtime"])] = float(median)

    for benchmark in benchmarks:
        benchmark_io_mode = benchmark.get("io_mode")
        baseline_applies = benchmark_io_mode == baseline_io_mode
        for run in benchmark.get("runs", []):
            baseline_exec = runtime_baselines.get(str(run["runtime"])) if baseline_applies else None
            median_exec = run.get("exec_ns", {}).get("median")
            adjusted = None
            ratio = None
            if baseline_exec is not None and median_exec is not None:
                adjusted = max(float(median_exec) - baseline_exec, 0.0)
                if baseline_exec != 0:
                    ratio = float(median_exec) / baseline_exec
            run["baseline_adjustment"] = {
                "baseline_benchmark": baseline_benchmark,
                "baseline_io_mode": baseline_io_mode,
                "applied": baseline_applies,
                "baseline_exec_ns": baseline_exec,
                "median_minus_baseline_ns": adjusted,
                "median_over_baseline_ratio": ratio,
            }
            if not baseline_applies:
                run["baseline_adjustment"]["reason"] = (
                    f"skipped: benchmark io_mode {benchmark_io_mode} does not match baseline io_mode {baseline_io_mode}"
                )

    for benchmark in benchmarks:
        runtime_runs = {str(run["runtime"]): run for run in benchmark.get("runs", [])}
        llvm = runtime_runs.get("llvmbpf")
        kernel = runtime_runs.get("kernel")
        if llvm is None or kernel is None:
            continue

        llvm_exec = llvm.get("exec_ns", {}).get("median")
        kernel_exec = kernel.get("exec_ns", {}).get("median")
        llvm_adjusted = llvm.get("baseline_adjustment", {}).get("median_minus_baseline_ns")
        kernel_adjusted = kernel.get("baseline_adjustment", {}).get("median_minus_baseline_ns")

        raw_ratio = None
        adjusted_ratio = None
        if llvm_exec not in (None, 0) and kernel_exec not in (None, 0):
            raw_ratio = float(llvm_exec) / float(kernel_exec)
        if llvm_adjusted not in (None, 0) and kernel_adjusted not in (None, 0):
            adjusted_ratio = float(llvm_adjusted) / float(kernel_adjusted)

        benchmark["runtime_comparison"] = {
            "llvmbpf_over_kernel_exec_ratio": raw_ratio,
            "llvmbpf_over_kernel_adjusted_exec_ratio": adjusted_ratio,
        }


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite_path = Path(args.suite)
    try:
        suite = load_suite(suite_path)
    except Exception as exc:
        raise SystemExit(f"failed to load micro suite manifest {suite_path}: {exc}") from exc

    if args.list:
        list_suite(suite)
        return 0

    benchmarks = select_benchmarks(args.benches, suite)
    runtimes = select_runtimes(args.runtimes, suite)
    if args.rejit and not any(runtime.mode in {"kernel-rejit", "kernel_rejit"} for runtime in runtimes):
        raise SystemExit("--rejit requires --runtime kernel-rejit")
    if args.shuffle_seed is not None:
        random.Random(args.shuffle_seed).shuffle(benchmarks)
    runtime_order_seed = args.shuffle_seed if args.shuffle_seed is not None else DEFAULT_RUNTIME_ORDER_SEED

    iterations = args.iterations if args.iterations is not None else suite.defaults.iterations
    warmups = args.warmups if args.warmups is not None else suite.defaults.warmups
    policy_dir = Path(args.policy_dir).resolve() if getattr(args, "policy_dir", None) else None
    if args.output:
        output_path = Path(args.output).resolve()
    else:
        output_path = suite.defaults.output
        default_runtime_names = set(suite.defaults.runtimes)
        selected_runtime_names = {runtime.name for runtime in runtimes}
        full_benchmark_selection = len(benchmarks) == len(suite.benchmarks)
        authoritative_run = full_benchmark_selection and default_runtime_names.issubset(selected_runtime_names)
        if not authoritative_run:
            output_path = smoke_output_path(output_path.parent, "pure_jit")

    ensure_artifacts_built(suite, args.build_bpftool)

    results = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "provenance": collect_provenance(args, iterations, warmups, policy_dir),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": read_git_sha(),
            "kernel_version": platform.release(),
            "kernel_cmdline": read_required_text("/proc/cmdline"),
            "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
            "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo"),
            "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        },
        "toolchains": {name: {"root": str(toolchain.root)} for name, toolchain in suite.toolchains.items()},
        "build": {
            "runner_binary": str(suite.build.runner_binary),
            "bpftool_binary": str(suite.build.bpftool_binary),
        },
        "defaults": {
            "iterations": iterations,
            "warmups": warmups,
            "repeat": args.repeat if args.repeat is not None else suite.defaults.repeat,
            "rejit": args.rejit,
            "perf_counters": args.perf_counters,
            "perf_scope": args.perf_scope,
            "shuffle_seed": args.shuffle_seed,
            "runtime_order_seed": runtime_order_seed,
        },
        "iteration_runtime_orders": {},
        "benchmarks": [],
    }

    validate_publication_environment(
        results["host"],
        cpu=args.cpu,
        strict=args.strict_env,
    )

    for bench_idx, benchmark in enumerate(benchmarks):
        memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
        policy_content, policy_sha256 = _read_policy_payload(benchmark.policy_file)
        benchmark_record = {
            "name": benchmark.name,
            "description": benchmark.description,
            "category": benchmark.category,
            "family": benchmark.family,
            "level": benchmark.level,
            "hypothesis": benchmark.hypothesis,
            "io_mode": benchmark.io_mode,
            "tags": list(benchmark.tags),
            "expected_result": benchmark.expected_result,
            "input": str(memory_file) if memory_file else None,
            "policy": dict(benchmark.policy) if benchmark.policy is not None else None,
            "policy_file": str(benchmark.policy_file) if benchmark.policy_file else None,
            "policy_content": policy_content,
            "policy_sha256": policy_sha256,
            "runs": [],
        }

        print(f"[bench] ({bench_idx+1}/{len(benchmarks)}) {benchmark.name}", flush=True)
        runtime_samples: dict[str, dict[str, object]] = {}
        iteration_runtime_orders: list[list[str]] = []
        for runtime in runtimes:
            repeat = args.repeat if args.repeat is not None else runtime.default_repeat
            is_rejit_runtime = runtime.mode in {"kernel-rejit", "kernel_rejit"}
            daemon_path = getattr(args, "daemon_path", None)
            command = build_micro_benchmark_command(
                suite.build.runner_binary,
                runtime_mode=runtime.mode,
                program=benchmark.program_object,
                io_mode=benchmark.io_mode,
                repeat=repeat,
                memory=memory_file,
                input_size=benchmark.kernel_input_size,
                perf_counters=args.perf_counters,
                perf_scope=args.perf_scope,
                require_sudo=runtime.require_sudo,
                rejit=is_rejit_runtime,
                daemon_path=daemon_path if is_rejit_runtime else None,
            )

            for _ in range(warmups):
                parse_runner_sample(run_command(command, args.cpu).stdout)

            runtime_samples[runtime.name] = {
                "repeat": repeat,
                "command": command,
                "samples": [],
            }

        for iteration_idx in range(iterations):
            if len(runtimes) == 2:
                ordered = list(runtimes) if iteration_idx % 2 == 0 else list(reversed(runtimes))
            else:
                rng = random.Random(runtime_order_seed + iteration_idx)
                ordered = list(runtimes)
                rng.shuffle(ordered)
            iteration_runtime_orders.append([runtime.name for runtime in ordered])
            for runtime in ordered:
                sample_entry = runtime_samples[runtime.name]
                sample = parse_runner_sample(run_command(sample_entry["command"], args.cpu).stdout)
                sample["iteration_index"] = iteration_idx
                if benchmark.expected_result is not None and sample["result"] != benchmark.expected_result:
                    raise RuntimeError(
                        f"{benchmark.name}/{runtime.name} result mismatch: "
                        f"{sample['result']} != {benchmark.expected_result}"
                    )
                sample_entry["samples"].append(sample)

        results["iteration_runtime_orders"][benchmark.name] = iteration_runtime_orders
        for runtime in runtimes:
            sample_entry = runtime_samples[runtime.name]
            samples = sample_entry["samples"]
            repeat = sample_entry["repeat"]
            compile_values = [sample["compile_ns"] for sample in samples]
            exec_values = [sample["exec_ns"] for sample in samples]
            result_values = [sample["result"] for sample in samples]
            perf_counter_summary = summarize_named_counters(samples, "perf_counters")
            wall_exec_summary = summarize_optional_ns(samples, "wall_exec_ns")
            timing_source = str(samples[0].get("timing_source", "unknown")) if samples else "unknown"

            run_record = {
                "runtime": runtime.name,
                "label": runtime.label,
                "mode": runtime.mode,
                "repeat": repeat,
                "artifacts": {
                    "program_object": str(benchmark.program_object),
                },
                "samples": samples,
                "compile_ns": ns_summary(compile_values),
                "exec_ns": ns_summary(exec_values),
                "timing_source": timing_source,
                "phases_ns": summarize_phase_timings(samples),
                "perf_counters": perf_counter_summary,
                "perf_counters_meta": summarize_perf_counter_meta(samples),
                "derived_metrics": derive_perf_metrics(perf_counter_summary),
                "result_distribution": dict(Counter(str(value) for value in result_values)),
            }
            if wall_exec_summary is not None:
                run_record["wall_exec_ns"] = wall_exec_summary
            benchmark_record["runs"].append(run_record)

            print(
                f"  {runtime.name:10} "
                f"compile median {format_ns(run_record['compile_ns']['median'])} | "
                f"exec median {format_ns(run_record['exec_ns']['median'])} | "
                f"result {result_values[-1]}"
            )

        # ── Cross-runtime correctness check ──────────────────────────
        # Compare result values across runtimes for the same benchmark.
        # If kernel-rejit produces a different result than kernel, flag it.
        runtime_results: dict[str, int | None] = {}
        for run in benchmark_record["runs"]:
            samples = run.get("samples", [])
            if samples:
                # Use the most common result value across all iterations
                result_counts = Counter(sample["result"] for sample in samples)
                modal_result = result_counts.most_common(1)[0][0]
                runtime_results[run["runtime"]] = modal_result
            else:
                runtime_results[run["runtime"]] = None

        kernel_result = runtime_results.get("kernel")
        rejit_result = runtime_results.get("kernel-rejit")
        if kernel_result is not None and rejit_result is not None and kernel_result != rejit_result:
            print(
                f"  WARNING: correctness mismatch for {benchmark.name}: "
                f"kernel={kernel_result}, kernel-rejit={rejit_result}"
            )
            benchmark_record["correctness_mismatch"] = True
        else:
            benchmark_record["correctness_mismatch"] = False

        results["benchmarks"].append(benchmark_record)

    attach_baseline_adjustments(results, suite.analysis.baseline_benchmark)

    write_path = output_path
    latest_alias_path: Path | None = None
    if output_path.name.endswith(".latest.json"):
        suite_name = output_path.name[: -len(".latest.json")]
        timestamp = results["generated_at"][:10].replace("-", "")
        write_path = output_path.parent / f"{suite_name}_authoritative_{timestamp}.json"
        latest_alias_path = output_path

    write_path.parent.mkdir(parents=True, exist_ok=True)
    write_path.write_text(json.dumps(results, indent=2) + "\n")
    if latest_alias_path is not None:
        refresh_latest_alias(latest_alias_path, write_path)
    else:
        maybe_refresh_latest_alias(write_path)
    print(f"[done] wrote {write_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
