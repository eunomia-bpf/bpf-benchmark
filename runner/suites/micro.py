from __future__ import annotations

import argparse
import os
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.workspace_layout import (
    kernel_modules_root,
    micro_program_root,
    repo_artifact_root,
    runner_binary_path,
    runtime_path_value,
)
from runner.suites._common import (
    add_common_args,
    base_runtime_env,
    cross_runtime_ld_library_path,
    inside_runtime_container,
    nonnegative_int,
    positive_int,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    run_in_runtime_container,
    setup_tmpdir,
    suite_main_setup,
)

_die = partial(fail, "micro-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run the micro benchmark suite as a standalone entrypoint.",
    )
    add_common_args(parser)
    parser.set_defaults(workspace=str(ROOT_DIR), target_name="local")
    parser.add_argument("--runner-binary", default="", help="Override the micro_exec runner binary path.")
    parser.add_argument("--program-dir", default="", help="Override the compiled micro BPF program directory.")
    parser.add_argument("--suite", default="", help="Path to the micro suite YAML manifest.")
    parser.add_argument("--bench", action="append", dest="benches", help="Benchmark name to run; repeatable.")
    parser.add_argument(
        "--runtime",
        action="append",
        dest="runtimes",
        default=None,
        help="Runtime name to run; repeatable. Defaults to llvmbpf and kernel.",
    )
    parser.add_argument("--samples", type=positive_int, required=True, help="Measured samples per runtime pair.")
    parser.add_argument("--warmups", type=nonnegative_int, required=True, help="Warmup runs per benchmark/runtime.")
    parser.add_argument("--inner-repeat", type=positive_int, required=True, help="Repeat count inside each helper sample.")
    parser.add_argument("--output", default="", help="JSON output path.")
    parser.add_argument("--cpu", default="", help="Pin child processes to a specific CPU via taskset.")
    parser.add_argument("--strict-env", action="store_true", help="Fail if environment is not publication-grade.")
    parser.add_argument("--shuffle-seed", type=int, help="Shuffle benchmark order with a reproducible seed.")
    parser.add_argument("--perf-counters", action="store_true", help="Collect perf_event counters when available.")
    parser.add_argument(
        "--perf-scope",
        default="full_repeat_raw",
        choices=["full_repeat_raw", "full_repeat_avg"],
        help="PMU scope passed through to micro/driver.py.",
    )
    parser.add_argument("--regenerate-inputs", action="store_true", help="Force regeneration of generated inputs.")
    parser.add_argument("--write-details", action="store_true", help="Write per-sample live_samples detail artifacts.")
    parser.add_argument("--list", action="store_true", help="List benchmarks and runtimes.")
    return parser.parse_args(sys.argv[1:] if argv is None else argv)


def _module_argv(args: argparse.Namespace) -> list[str]:
    argv = [
        "--workspace", str(args.workspace),
        "--target-arch", str(args.target_arch),
        "--target-name", str(args.target_name),
        "--executor", str(args.executor),
        "--samples", str(args.samples),
        "--warmups", str(args.warmups),
        "--inner-repeat", str(args.inner_repeat),
        "--bpftool-bin", str(args.bpftool_bin),
        "--container-runtime", str(args.container_runtime),
        "--runtime-python-bin", str(args.runtime_python_bin),
    ]
    for option, value in (
        ("--run-token", args.run_token),
        ("--python-bin", args.python_bin),
        ("--runner-binary", args.runner_binary),
        ("--program-dir", args.program_dir),
        ("--suite", args.suite),
        ("--output", args.output),
        ("--cpu", args.cpu),
        ("--runtime-container-image", args.runtime_container_image),
    ):
        if value:
            argv.extend([option, str(value)])
    for bench in args.benches or []:
        argv.extend(["--bench", str(bench)])
    for runtime in args.runtimes or []:
        argv.extend(["--runtime", str(runtime)])
    if args.strict_env:
        argv.append("--strict-env")
    if args.shuffle_seed is not None:
        argv.extend(["--shuffle-seed", str(args.shuffle_seed)])
    if args.perf_counters:
        argv.append("--perf-counters")
    if args.perf_scope:
        argv.extend(["--perf-scope", str(args.perf_scope)])
    if args.regenerate_inputs:
        argv.append("--regenerate-inputs")
    if args.write_details:
        argv.append("--write-details")
    if args.list:
        argv.append("--list")
    return argv


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    env = base_runtime_env()
    setup_tmpdir(env, args.run_token or f"{args.target_name}_micro")
    env["PATH"] = runtime_path_value(workspace, args.target_arch)
    if runtime_ld := cross_runtime_ld_library_path(workspace, args.target_arch):
        env["LD_LIBRARY_PATH"] = runtime_ld
    env["BPFREJIT_REPO_ARTIFACT_ROOT"] = str(repo_artifact_root(workspace, args.target_arch))
    env["BPFREJIT_REMOTE_PYTHON_BIN"] = args.python_bin or sys.executable
    kernel_modules_dir = kernel_modules_root(workspace, args.target_arch, args.executor)
    if not kernel_modules_dir.is_dir():
        _die(f"kernel module artifact root is missing: {kernel_modules_dir}")
    env["BPFREJIT_KERNEL_MODULES_ROOT"] = str(kernel_modules_dir)
    env["PYTHONPATH"] = str(workspace)
    env["BPFTOOL_BIN"] = args.bpftool_bin
    return env


def _micro_driver_argv(workspace: Path, args: argparse.Namespace) -> list[str]:
    output_path = resolve_workspace_path(
        workspace,
        args.output or str(workspace / "micro" / "results" / f"{args.target_name}_micro.json"),
    )
    runtimes = args.runtimes or ["llvmbpf", "kernel"]
    argv: list[str] = []
    for runtime in runtimes:
        argv.extend(["--runtime", str(runtime)])
    argv.extend([
        "--samples", str(args.samples),
        "--warmups", str(args.warmups),
        "--inner-repeat", str(args.inner_repeat),
        "--output", str(output_path),
    ])
    if args.suite:
        argv.extend(["--suite", str(resolve_workspace_path(workspace, args.suite))])
    for bench in args.benches or []:
        argv.extend(["--bench", str(bench)])
    if args.cpu:
        argv.extend(["--cpu", str(args.cpu)])
    if args.strict_env:
        argv.append("--strict-env")
    if args.shuffle_seed is not None:
        argv.extend(["--shuffle-seed", str(args.shuffle_seed)])
    if args.perf_counters:
        argv.append("--perf-counters")
    if args.perf_scope:
        argv.extend(["--perf-scope", str(args.perf_scope)])
    if args.regenerate_inputs:
        argv.append("--regenerate-inputs")
    if args.write_details:
        argv.append("--write-details")
    if args.list:
        argv.append("--list")
    return argv


def _run_micro_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    python_bin = resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    program_dir = resolve_workspace_path(workspace, args.program_dir) if args.program_dir else micro_program_root(workspace, args.target_arch)
    runner_binary = resolve_workspace_path(workspace, args.runner_binary) if args.runner_binary else runner_binary_path(workspace, args.target_arch)
    if not runner_binary.is_file() or not os.access(runner_binary, os.X_OK):
        _die(f"runner artifact is missing or not executable: {runner_binary}")
    if not program_dir.is_dir():
        _die(f"micro program artifact root is missing: {program_dir}")

    env["BPFREJIT_MICRO_PROGRAM_DIR"] = str(program_dir)
    env["BPFREJIT_MICRO_RUNNER_BINARY"] = str(runner_binary)
    command = [python_bin, str(workspace / "micro" / "driver.py"), *_micro_driver_argv(workspace, args)]
    run_checked(command, cwd=workspace, env=env, die=_die)


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    if args.runtime_container_image and not inside_runtime_container():
        run_in_runtime_container(
            args.workspace,
            args_module="runner.suites.micro",
            module_argv=_module_argv(args),
            container_runtime=args.container_runtime,
            image=args.runtime_container_image,
            runtime_python_bin=args.runtime_python_bin,
            target_arch=args.target_arch,
        )
        return
    _run_micro_suite(workspace, args)


if __name__ == "__main__":
    main()
