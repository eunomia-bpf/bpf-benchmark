from __future__ import annotations

import argparse
import os
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.kinsn import load_kinsn_modules
from runner.libs.workspace_layout import (
    kernel_modules_root,
    kinsn_module_dir,
    micro_program_root,
    runner_binary_path,
    runtime_path_value,
    runtime_repo_artifact_root,
    sim_proof_root,
    stage2_program_root,
)
from runner.suites._common import (
    base_runtime_env,
    common_env_args,
    cross_runtime_ld_library_path,
    env_bool,
    env_int,
    env_str,
    env_tokens,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    setup_tmpdir,
    suite_main_setup,
)

_die = partial(fail, "micro-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    if argv or (argv is None and sys.argv[1:]):
        _die("micro suite takes env only; run through Make")
    args = common_env_args(str(ROOT_DIR), _die)
    args.runner_binary = env_str("MICRO_RUNNER_BINARY")
    args.program_dir = env_str("MICRO_PROGRAM_DIR")
    args.suite = env_str("SUITE")
    args.benches = env_tokens("BENCH")
    args.runtimes = env_tokens("RUNTIMES") or None
    args.samples = env_int("SAMPLES", 3, _die, positive=True)
    args.warmups = env_int("WARMUPS", 0, _die)
    args.inner_repeat = env_int("INNER_REPEAT", 100000, _die, positive=True)
    args.output = env_str("MICRO_OUTPUT")
    args.cpu = env_str("CPU")
    args.strict_env = env_bool("STRICT_ENV")
    args.shuffle_seed = int(env_str("SHUFFLE_SEED")) if env_str("SHUFFLE_SEED") else None
    args.regenerate_inputs = env_bool("REGENERATE_INPUTS")
    args.list = env_bool("LIST")
    return args


def _selected_runtimes(args: argparse.Namespace) -> list[str]:
    return args.runtimes or ["native", "llvmbpf", "kernel"]


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    env = base_runtime_env()
    setup_tmpdir(env, args.run_token or f"{args.target_name}_micro")
    env["PATH"] = runtime_path_value(workspace, args.target_arch)
    if runtime_ld := cross_runtime_ld_library_path(workspace, args.target_arch):
        env["LD_LIBRARY_PATH"] = runtime_ld
    env["BPFREJIT_REPO_ARTIFACT_ROOT"] = str(runtime_repo_artifact_root(workspace, args.target_arch))
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
    argv: list[str] = []
    for runtime in _selected_runtimes(args):
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
    if args.regenerate_inputs:
        argv.append("--regenerate-inputs")
    if args.list:
        argv.append("--list")
    return argv


def _run_micro_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    python_bin = resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    if args.program_dir:
        program_dir = resolve_workspace_path(workspace, args.program_dir)
    elif args.suite and "stage2" in Path(args.suite).name:
        # The Stage 2 maps/helpers suite (micro/config/micro_stage2.yaml)
        # consumes programs built from native-sim/test/ that live under a
        # parallel artifact tree. Detected here by the suite filename so
        # users don't have to pass --program-dir explicitly.
        program_dir = stage2_program_root(workspace, args.target_arch)
    else:
        program_dir = micro_program_root(workspace, args.target_arch)
    if args.runner_binary:
        runner_binary = resolve_workspace_path(workspace, args.runner_binary)
    else:
        runner_binary = runner_binary_path(workspace, args.target_arch)
    if not runner_binary.is_file() or not os.access(runner_binary, os.X_OK):
        _die(f"runner artifact is missing or not executable: {runner_binary}")
    if not program_dir.is_dir():
        _die(f"micro program artifact root is missing: {program_dir}")

    env["BPFREJIT_MICRO_PROGRAM_DIR"] = str(program_dir)
    env["BPFREJIT_MICRO_RUNNER_BINARY"] = str(runner_binary)
    env["BPFREJIT_MICRO_PROOF_DIR"] = str(sim_proof_root(workspace, args.target_arch))

    if "native_kernel" in _selected_runtimes(args):
        module_dir = kinsn_module_dir(workspace, args.target_arch)
        if not module_dir.is_dir():
            _die(f"kinsn module artifact root is missing: {module_dir}")
        expected = sorted(path.stem for path in module_dir.glob("bpf_*.ko") if path.is_file())
        if not expected:
            _die(f"no kinsn modules found under {module_dir}")
        load_kinsn_modules(expected, module_dir=module_dir)

    if "native_proof" in _selected_runtimes(args):
        proof_dir = sim_proof_root(workspace, args.target_arch)
        if not proof_dir.is_dir():
            _die(f"native proof artifact root is missing: {proof_dir}")

    command = [python_bin, str(workspace / "micro" / "driver.py"), *_micro_driver_argv(workspace, args)]
    run_checked(command, cwd=workspace, env=env, die=_die)


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    _run_micro_suite(workspace, args)


if __name__ == "__main__":
    main()
