#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import platform
import random
import re
import select
import signal
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from micro.catalog import (
    DEFAULT_MICRO_MANIFEST as CONFIG_PATH,
    REPO_ROOT as ROOT_DIR,
    CatalogManifest as SuiteSpec,
    CatalogRuntime as RuntimeSpec,
    CatalogTarget,
    load_manifest as load_suite,
)
from runner.libs import run_command, tail_text
from runner.libs.benchmarks import resolve_memory_file, select_benchmarks
from runner.libs.environment import (
    require_existing_paths,
    read_optional_text,
    read_required_text,
    validate_publication_environment,
)
from runner.libs.results import parse_last_json_line
from runner.libs.rejit import DaemonSession, benchmark_rejit_enabled_passes
from runner.libs.run_artifacts import (
    ArtifactSession,
    derive_run_type,
    sanitize_artifact_token,
)
from runner.libs.workspace_layout import daemon_binary_path


DEFAULT_RUNTIME_ORDER_SEED = 0
RUNNER_TIMEOUT_SECONDS = 180


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run declarative micro benchmark suites.")
    parser.add_argument("--suite", default=str(CONFIG_PATH), help="Path to suite YAML.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name.")
    parser.add_argument("--runtime", action="append", dest="runtimes", help="Runtime name.")
    parser.add_argument("--samples", type=int, help="Measured samples per runtime pair.")
    parser.add_argument("--warmups", type=int, help="Warmup runs per pair.")
    parser.add_argument("--inner-repeat", type=int, dest="inner_repeat", help="Repeat count inside each helper sample.")
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
        help="PMU scope: full_repeat_raw (default, raw totals) or full_repeat_avg (cumulative counters divided by inner repeat).",
    )
    parser.add_argument(
        "--regenerate-inputs",
        action="store_true",
        help="Force regeneration of generated inputs.",
    )
    parser.add_argument("--list", action="store_true", help="List benchmarks and runtimes.")
    return parser.parse_args(sys.argv[1:] if argv is None else argv)


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


def collect_provenance(
    args: argparse.Namespace,
    samples: int,
    warmups: int,
    inner_repeat: int | None,
) -> dict[str, object]:
    linux_dir = ROOT_DIR / "vendor" / "linux-framework"
    kernel_commit = _git_rev_parse(linux_dir) if linux_dir.is_dir() else "unknown"
    repo_git_sha = _git_rev_parse(ROOT_DIR)
    repo_dirty = _git_is_dirty(ROOT_DIR)

    return {
        "kernel_commit": kernel_commit,
        "repo_git_sha": repo_git_sha,
        "repo_dirty": repo_dirty,
        "params": {
            "samples": samples,
            "warmups": warmups,
            "inner_repeat": inner_repeat,
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
    for runtime in suite.runtimes:
        aliases = f" (aliases: {', '.join(runtime.aliases)})" if runtime.aliases else ""
        print(f"{runtime.name:12} {runtime.label}{aliases}")


def select_runtimes(names: list[str] | None, suite: SuiteSpec) -> list[RuntimeSpec]:
    requested = names or list(suite.defaults.runtimes)
    runtimes_by_name = {runtime.name: runtime for runtime in suite.runtimes}
    selected: list[RuntimeSpec] = []
    for raw_name in requested:
        name = suite.runtime_aliases.get(raw_name, raw_name)
        if name not in runtimes_by_name:
            raise SystemExit(f"unknown runtime: {raw_name}")
        runtime = runtimes_by_name[name]
        if runtime.policy_mode != "stock":
            raise SystemExit(
                f"micro benchmark only supports stock runtimes under §5.6; got {runtime.name} ({runtime.mode})"
            )
        selected.append(runtime)
    return selected


def require_suite_artifacts(suite: SuiteSpec) -> None:
    required_paths = [suite.build.runner_binary]
    required_paths.extend(benchmark.object_path for benchmark in suite.benchmarks.values())
    require_existing_paths(required_paths)


def runtimes_for_benchmark(benchmark: CatalogTarget, runtimes: list[RuntimeSpec]) -> list[RuntimeSpec]:
    allowed_runtime_names = set(benchmark.runtime_names)
    return [
        runtime for runtime in runtimes
        if not allowed_runtime_names or runtime.name in allowed_runtime_names
    ]


def runner_help_text(runner_binary: Path) -> str:
    completed = run_command(
        [str(runner_binary), "--help"],
        cwd=ROOT_DIR,
        check=False,
        timeout=30,
    )
    return "\n".join([completed.stdout, completed.stderr])


def build_run_metadata(
    results: dict[str, Any],
    *,
    run_type: str,
) -> dict[str, Any]:
    metadata = {key: value for key, value in results.items()}
    metadata["run_type"] = run_type
    return metadata


def build_runner_command(
    *,
    runner_binary: Path,
    benchmark: CatalogTarget,
    runtime: RuntimeSpec,
    inner_repeat: int,
    memory_file: Path | None,
    perf_counters: bool,
    perf_scope: str,
    cpu: str | None,
    dump_jit_path: Path | None = None,
    dump_xlated_path: Path | None = None,
) -> list[str]:
    if runtime.mode == "llvmbpf":
        command = [str(runner_binary), "run-llvmbpf"]
    elif runtime.mode == "native":
        command = [str(runner_binary), "run-native"]
    elif runtime.mode == "native_lab":
        command = [str(runner_binary), "run-native-lab"]
        # Pick the native_lab program type from benchmark tags so the
        # runner builds the right BPF stub (XDP vs sched_cls vs cgroup_skb).
        tags = set(benchmark.tags)
        if "tc" in tags:
            command.extend(["--native-lab-prog-type", "sched_cls"])
        elif "cgroup_skb" in tags or "cgroup-skb" in tags:
            command.extend(["--native-lab-prog-type", "cgroup_skb"])
        # else: default xdp
    elif runtime.mode in {"kernel", "kernel_rejit"}:
        command = [str(runner_binary), "test-run"]
    else:
        raise RuntimeError(f"unsupported micro runtime mode: {runtime.mode}")

    command.extend(["--program", str(benchmark.object_path)])
    if benchmark.program_names:
        command.extend(["--program-name", benchmark.program_names[0]])
    if memory_file is not None:
        command.extend(["--memory", str(memory_file)])
    if benchmark.io_mode:
        command.extend(["--io-mode", benchmark.io_mode])
    if benchmark.kernel_input_size > 0:
        command.extend(["--input-size", str(benchmark.kernel_input_size)])
    command.extend(["--inner-repeat", str(max(1, inner_repeat))])

    if perf_counters:
        command.append("--perf-counters")
        command.extend(["--perf-scope", perf_scope])
    if dump_jit_path is not None:
        command.extend(["--dump-jit-path", str(dump_jit_path)])
    if dump_xlated_path is not None:
        command.extend(["--dump-xlated", str(dump_xlated_path)])
    if runtime.mode == "kernel_rejit":
        command.append("--signal-control")

    if cpu:
        return ["taskset", "-c", str(cpu), *command]
    return command


def run_single_sample(
    command: list[str],
    *,
    cwd: Path,
    artifact_dir: Path,
) -> dict[str, Any]:
    if "--signal-control" in command:
        return run_rejit_sample(command, cwd=cwd, artifact_dir=artifact_dir)
    completed = run_command(
        command,
        cwd=cwd,
        timeout=RUNNER_TIMEOUT_SECONDS,
    )
    try:
        payload = parse_last_json_line(completed.stdout, label="micro_exec")
    except Exception as exc:
        detail = tail_text(completed.stderr or completed.stdout or "")
        raise RuntimeError(
            f"micro_exec returned invalid JSON for {' '.join(command)}\n{detail}"
        ) from exc
    if not isinstance(payload, dict):
        raise RuntimeError(f"micro_exec returned non-object JSON for {' '.join(command)}")
    return dict(payload)


def run_rejit_sample(command: list[str], *, cwd: Path, artifact_dir: Path) -> dict[str, Any]:
    arch = os.environ.get("RUN_TARGET_ARCH", "").strip() or platform.machine()
    proc: subprocess.Popen[str] | None = None
    daemon_dir = artifact_dir / "details"
    with DaemonSession.start(
        daemon_binary_path(ROOT_DIR, arch),
        stdout_path=daemon_dir / "daemon.stdout.log",
        stderr_path=daemon_dir / "daemon.stderr.log",
    ) as daemon:
        try:
            proc = subprocess.Popen(command, cwd=cwd, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            assert proc.stdout is not None
            ready = dict(parse_last_json_line(proc.stdout.readline(), label="kernel_rejit ready"))
            prog_id = int(ready["id"])
            passes = benchmark_rejit_enabled_passes()
            rejit_result = daemon.apply_rejit(
                [prog_id],
                app_pid=int(proc.pid),
                enabled_passes=passes,
                prog_names_by_id={prog_id: str(ready.get("name") or "micro")},
            )
            os.kill(proc.pid, signal.SIGUSR1)
            readable, _, _ = select.select([proc.stdout], [], [], RUNNER_TIMEOUT_SECONDS)
            if not readable:
                raise RuntimeError("kernel_rejit micro_exec timed out")
            sample = dict(parse_last_json_line(proc.stdout.readline(), label="kernel_rejit micro_exec"))
            sample["passes"] = passes
            sample["rejit_result"] = rejit_result
        finally:
            if proc is not None and proc.poll() is None:
                proc.terminate()
                try:
                    proc.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    proc.kill()
                    proc.wait(timeout=5)
    return sample


def _dump_stem(benchmark_name: str, runtime_name: str, sample_idx: int | None = None) -> str:
    stem = f"{sanitize_artifact_token(benchmark_name)}__{sanitize_artifact_token(runtime_name)}"
    if sample_idx is not None:
        stem += f"__sample{sample_idx:02d}"
    return stem


def _jit_dump_paths(artifact_dir: Path, stem: str, *, xlated: bool = True) -> tuple[Path, Path | None]:
    dump_dir = artifact_dir / "details" / "jit_dumps"
    dump_dir.mkdir(parents=True, exist_ok=True)
    return dump_dir / f"{stem}.jited.bin", dump_dir / f"{stem}.xlated.bin" if xlated else None


def _read_text_or_missing(path: Path) -> str:
    return path.read_text() if path.exists() else "not captured"


def _strip_objdump_banner(text: str) -> str:
    lines = []
    for line in text.splitlines():
        stripped = line.strip()
        if re.match(r".+:\s+file format\s+\S+", stripped):
            continue
        lines.append(line)
    return "\n".join(lines).strip()


def _disassembly(path: Path | None, *, binary: bool = False, symbol: str | None = None) -> str:
    if path is None or not path.exists():
        return "not captured"
    command = ["objdump", "-D" if binary else "-dr"]
    machine = platform.machine().lower()
    if symbol:
        command.append(f"--disassemble={symbol}")
    if not binary and machine in {"x86_64", "amd64"}:
        command.append("-Mintel")
    if binary:
        command.extend(["-b", "binary"])
    if machine in {"x86_64", "amd64"}:
        command.extend(["-m", "i386:x86-64", "-Mintel"])
    elif machine in {"aarch64", "arm64"}:
        command.extend(["-m", "aarch64"])
    elif binary:
        raise RuntimeError(f"unsupported objdump machine for JIT dump: {platform.machine()}")
    command.append(str(path))
    return _strip_objdump_banner(run_command(command, cwd=ROOT_DIR, timeout=RUNNER_TIMEOUT_SECONDS).stdout)


def write_code_compare_markdown(benchmark: CatalogTarget, artifact_dir: Path) -> None:
    base_name = str(benchmark.metadata.get("base_name") or benchmark.name)
    dump_dir = artifact_dir / "details" / "jit_dumps"
    sections = [
        ("Original C", "c", _read_text_or_missing(ROOT_DIR / "micro" / "programs" / f"{base_name}.bpf.c")),
        ("Native ASM", "asm", _disassembly(benchmark.object_path.parent / f"{base_name}.native.so")),
        ("Original Kernel JIT ASM", "asm", _disassembly(dump_dir / f"{_dump_stem(benchmark.name, 'kernel', 0)}.jited.bin", binary=True)),
        ("llvmbpf JIT ASM", "asm", _disassembly(dump_dir / f"{_dump_stem(benchmark.name, 'llvmbpf', 0)}.jited.bin", binary=True)),
    ]
    text = f"# {benchmark.name}\n\n" + "\n\n".join(
        f"## {title}\n```{lang}\n{text.rstrip()}\n```" for title, lang, text in sections
    ) + "\n"
    for out in (
        ROOT_DIR / "micro" / "programs" / f"{sanitize_artifact_token(benchmark.name)}.md",
        artifact_dir / "details" / "code_compare" / f"{sanitize_artifact_token(benchmark.name)}.md",
    ):
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text)


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
    if os.environ.get("BPFREJIT_BENCH_PASSES", "").strip():
        runtimes.append(RuntimeSpec("kernel_rejit", "kernel eBPF + ReJIT", "kernel_rejit", "kernel", "stock"))
    if args.shuffle_seed is not None:
        random.Random(args.shuffle_seed).shuffle(benchmarks)
    runtime_order_seed = args.shuffle_seed if args.shuffle_seed is not None else DEFAULT_RUNTIME_ORDER_SEED

    samples = args.samples if args.samples is not None else suite.defaults.samples
    warmups = args.warmups if args.warmups is not None else suite.defaults.warmups
    default_inner_repeat = args.inner_repeat if args.inner_repeat is not None else suite.defaults.inner_repeat
    if args.output:
        output_path = Path(args.output).resolve()
    else:
        output_path = suite.defaults.output

    require_suite_artifacts(suite)
    runner_binary = Path(suite.build.runner_binary).resolve()
    if any(runtime.mode == "llvmbpf" for runtime in runtimes):
        runner_help = runner_help_text(runner_binary)
        if "run-llvmbpf" not in runner_help:
            detail = tail_text(runner_help, max_lines=20, max_chars=4000)
            detail_suffix = f"\n{detail}" if detail else ""
            raise RuntimeError(
                f"selected llvmbpf runtime but runner build does not expose run-llvmbpf: {runner_binary}"
                f"{detail_suffix}"
            )

    results: dict[str, Any] = {
        "suite": suite.suite_name,
        "manifest": str(suite.manifest_path),
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "provenance": collect_provenance(args, samples, warmups, default_inner_repeat),
        "host": {
            "hostname": platform.node(),
            "platform": platform.platform(),
            "python": sys.version.split()[0],
            "cpu_affinity": args.cpu,
            "git_sha": _git_rev_parse(ROOT_DIR),
            "kernel_version": platform.release(),
            "kernel_cmdline": read_required_text("/proc/cmdline"),
            "cpu_governor": read_optional_text("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"),
            "turbo_state": read_optional_text("/sys/devices/system/cpu/intel_pstate/no_turbo"),
            "perf_event_paranoid": read_optional_text("/proc/sys/kernel/perf_event_paranoid"),
        },
        "toolchains": {
            name: {"root": str(spec.get("root"))}
            for name, spec in ((suite.metadata.get("toolchains") or {}).items())
            if isinstance(spec, dict)
        },
        "build": {
            "runner_binary": str(runner_binary),
        },
        "defaults": {
            "samples": samples,
            "warmups": warmups,
            "inner_repeat": default_inner_repeat,
            "perf_counters": args.perf_counters,
            "perf_scope": args.perf_scope,
            "shuffle_seed": args.shuffle_seed,
            "runtime_order_seed": runtime_order_seed,
        },
        "benchmarks": [],
    }

    run_type = derive_run_type(output_path, results["suite"])
    current_benchmark_name: str | None = None
    current_benchmark_index: int | None = None
    current_benchmark_record: dict[str, Any] | None = None
    benchmark_errors: list[str] = []

    def build_artifact_metadata(
        status: str,
        started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        artifact_metadata = build_run_metadata(
            results,
            run_type=run_type,
        )
        artifact_metadata["status"] = status
        artifact_metadata["started_at"] = started_at
        artifact_metadata["last_updated_at"] = updated_at
        artifact_metadata["progress"] = {
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
        }
        if error_message:
            artifact_metadata["error_message"] = error_message
        return artifact_metadata

    session = ArtifactSession(
        output_path=output_path,
        run_type=run_type,
        generated_at=str(results["generated_at"]),
        metadata_builder=build_artifact_metadata,
    )
    artifact_dir = session.run_dir

    def flush_artifact(status: str, *, error_message: str | None = None) -> None:
        progress_payload = {
            "status": status,
            "total_benchmarks": len(benchmarks),
            "completed_benchmarks": len(results["benchmarks"]),
            "current_benchmark_index": current_benchmark_index,
            "current_benchmark": current_benchmark_name,
            "current_benchmark_record": current_benchmark_record,
        }
        if error_message:
            progress_payload["error_message"] = error_message
        session.write(
            status=status,
            progress_payload=progress_payload,
            result_payload=results,
            error_message=error_message,
        )

    flush_artifact("running")

    try:
        validate_publication_environment(
            results["host"],
            cpu=args.cpu,
            strict=args.strict_env,
        )

        for bench_idx, benchmark in enumerate(benchmarks):
            memory_file = resolve_memory_file(benchmark, args.regenerate_inputs)
            benchmark_runtimes = runtimes_for_benchmark(benchmark, runtimes)
            if not benchmark_runtimes:
                raise RuntimeError(
                    f"{benchmark.name} cannot run with selected runtimes: "
                    f"{', '.join(runtime.name for runtime in runtimes)}"
                )
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
                "runs": [],
            }

            current_benchmark_name = benchmark.name
            current_benchmark_index = bench_idx + 1
            current_benchmark_record = benchmark_record
            flush_artifact("running")

            print(f"[bench] ({bench_idx+1}/{len(benchmarks)}) {benchmark.name}", flush=True)

            runtime_samples: dict[str, dict[str, object]] = {}

            def append_runtime_records() -> None:
                recorded = {run["runtime"] for run in benchmark_record["runs"]}
                for runtime in benchmark_runtimes:
                    if runtime.name in recorded:
                        continue
                    sample_entry = runtime_samples.get(runtime.name)
                    if not sample_entry:
                        continue
                    run_samples = list(sample_entry["samples"])
                    if not run_samples:
                        continue
                    inner_repeat = int(sample_entry["inner_repeat"])
                    result_values = [sample["result"] for sample in run_samples]
                    benchmark_record["runs"].append({
                        "runtime": runtime.name,
                        "mode": runtime.mode,
                        "inner_repeat": inner_repeat,
                        "samples": run_samples,
                    })
                    last_sample = run_samples[-1]
                    print(
                        f"  {runtime.name:10} "
                        f"compile last {int(last_sample.get('compile_ns') or 0)} ns | "
                        f"exec last {int(last_sample.get('exec_ns') or 0)} ns | "
                        f"result {result_values[-1] if result_values else '?'}"
                    )

            try:
                for runtime in benchmark_runtimes:
                    inner_repeat = args.inner_repeat if args.inner_repeat is not None else runtime.default_inner_repeat
                    runtime_samples[runtime.name] = {
                        "inner_repeat": inner_repeat,
                        "samples": [],
                    }
                    warmup_command = build_runner_command(
                        runner_binary=runner_binary,
                        benchmark=benchmark,
                        runtime=runtime,
                        inner_repeat=inner_repeat,
                        memory_file=memory_file,
                        perf_counters=args.perf_counters,
                        perf_scope=args.perf_scope,
                        cpu=args.cpu,
                    )
                    for _ in range(max(0, warmups)):
                        sample = run_single_sample(warmup_command, cwd=ROOT_DIR, artifact_dir=artifact_dir)
                        if benchmark.expected_result is not None and sample.get("result") != benchmark.expected_result:
                            raise RuntimeError(
                                f"{benchmark.name}/{runtime.name} warmup result mismatch: "
                                f"{sample.get('result')} != {benchmark.expected_result}"
                            )

                for sample_idx in range(samples):
                    if len(benchmark_runtimes) == 2:
                        ordered = list(benchmark_runtimes) if sample_idx % 2 == 0 else list(reversed(benchmark_runtimes))
                    else:
                        rng = random.Random(runtime_order_seed + sample_idx)
                        ordered = list(benchmark_runtimes)
                        rng.shuffle(ordered)

                    for runtime in ordered:
                        inner_repeat = int(runtime_samples[runtime.name]["inner_repeat"])
                        dump_jit_path = None
                        dump_xlated_path = None
                        if runtime.mode in {"kernel", "kernel_rejit", "llvmbpf"}:
                            dump_jit_path, dump_xlated_path = _jit_dump_paths(
                                artifact_dir,
                                _dump_stem(benchmark.name, runtime.name, sample_idx),
                                xlated=runtime.mode in {"kernel", "kernel_rejit"},
                            )
                        command = build_runner_command(
                            runner_binary=runner_binary,
                            benchmark=benchmark,
                            runtime=runtime,
                            inner_repeat=inner_repeat,
                            memory_file=memory_file,
                            perf_counters=args.perf_counters,
                            perf_scope=args.perf_scope,
                            cpu=args.cpu,
                            dump_jit_path=dump_jit_path,
                            dump_xlated_path=dump_xlated_path,
                        )
                        sample = run_single_sample(command, cwd=ROOT_DIR, artifact_dir=artifact_dir)
                        sample["sample_index"] = sample_idx

                        if benchmark.expected_result is not None and sample.get("result") != benchmark.expected_result:
                            raise RuntimeError(
                                f"{benchmark.name}/{runtime.name} result mismatch: "
                                f"{sample.get('result')} != {benchmark.expected_result}"
                            )

                        runtime_samples[runtime.name]["samples"].append(sample)

                append_runtime_records()
                flush_artifact("running")
            except Exception as exc:
                append_runtime_records()
                benchmark_record["error"] = str(exc)
                benchmark_errors.append(f"{benchmark.name}: {exc}")
                print(f"  error {exc}", flush=True)

            results["benchmarks"].append(benchmark_record)
            current_benchmark_record = None
            flush_artifact("running")

        for benchmark in benchmarks:
            write_code_compare_markdown(benchmark, artifact_dir)
        current_benchmark_name = None
        current_benchmark_index = None
        if benchmark_errors:
            flush_artifact("error", error_message="; ".join(benchmark_errors))
            return 1
        flush_artifact("completed")
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise

    print(f"[done] wrote {artifact_dir / 'metadata.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
