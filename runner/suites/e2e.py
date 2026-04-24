from __future__ import annotations

import argparse
import os
import shlex
import shutil
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.workspace_layout import inside_runtime_image
from runner.suites._common import (
    add_common_args,
    base_suite_runtime_env,
    ensure_bpf_stats_enabled,
    ensure_katran_artifacts,
    ensure_scx_artifacts,
    env_with_suite_runtime_ld,
    merge_csv_and_repeated,
    resolve_daemon_binary,
    resolve_executable,
    run_checked,
    suite_main_setup,
)

_die = partial(fail, "e2e-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run the e2e benchmark suite as a standalone entrypoint.",
    )
    add_common_args(parser)
    parser.set_defaults(workspace=str(ROOT_DIR), target_name="local")
    parser.add_argument("--daemon-binary", default="", help="Override the bpfrejit-daemon binary path.")
    parser.add_argument("--e2e-smoke", action="store_true", help="Run e2e cases in smoke mode.")
    parser.add_argument("--native-repo", action="append", dest="native_repo_values", default=None, help="Native repo artifact to validate; repeatable.")
    parser.add_argument("--native-repos", default="", help="Comma-separated native repo artifacts to validate.")
    parser.add_argument("--scx-package", action="append", dest="scx_package_values", default=None, help="SCX package artifact to validate; repeatable.")
    parser.add_argument("--scx-packages", default="", help="Comma-separated SCX package artifacts to validate.")
    parser.add_argument(
        "--e2e-argv",
        action="append",
        dest="e2e_argv_values",
        default=None,
        help="Extra argument token or shell-quoted argument string passed to e2e/driver.py; repeatable.",
    )
    parser.add_argument("e2e_argv_remainder", nargs=argparse.REMAINDER, help=argparse.SUPPRESS)
    args = parser.parse_args(sys.argv[1:] if argv is None else argv)

    args.native_repos = merge_csv_and_repeated(args.native_repos, args.native_repo_values)
    args.scx_packages = merge_csv_and_repeated(args.scx_packages, args.scx_package_values)
    e2e_argv: list[str] = []
    for value in args.e2e_argv_values or []:
        e2e_argv.extend(shlex.split(str(value)))
    remainder = list(args.e2e_argv_remainder or [])
    if remainder and remainder[0] == "--":
        remainder = remainder[1:]
    e2e_argv.extend(remainder)
    args.e2e_argv = e2e_argv
    return args


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    return base_suite_runtime_env(workspace, args, "e2e", _die)


def _e2e_driver_argv(args: argparse.Namespace, daemon_binary: Path) -> list[str]:
    argv = ["all", "--daemon", str(daemon_binary)]
    if args.e2e_smoke:
        argv.append("--smoke")
    argv.extend(args.e2e_argv)
    return argv


def _run_e2e_case(workspace: Path, args: argparse.Namespace, env: dict[str, str], daemon_binary: Path, python_bin: str) -> None:
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    command = [python_bin, str(workspace / "e2e" / "driver.py"), *_e2e_driver_argv(args, daemon_binary)]
    run_checked(command, cwd=workspace, env=runtime_env, die=_die)


def _run_e2e_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    python_bin = resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    os.chdir(workspace)
    if inside_runtime_image() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_die)
    ensure_bpf_stats_enabled(workspace, _die)
    ensure_scx_artifacts(workspace, args.target_arch, args.scx_packages, _die)
    daemon_binary = resolve_daemon_binary(workspace, args.target_arch, args.daemon_binary, _die)
    ensure_katran_artifacts(workspace, args.target_arch, args.native_repos, _die)
    _run_e2e_case(workspace, args, env, daemon_binary, python_bin)


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    _run_e2e_suite(workspace, args)


if __name__ == "__main__":
    main()
