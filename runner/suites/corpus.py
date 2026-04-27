from __future__ import annotations

import argparse
import os
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
    csv_tokens,
    ensure_bpf_stats_enabled,
    ensure_katran_artifacts,
    ensure_scx_artifacts,
    env_with_suite_runtime_ld,
    nonnegative_int,
    resolve_daemon_binary,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    suite_main_setup,
)

_die = partial(fail, "corpus-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run the corpus benchmark suite as a standalone entrypoint.",
    )
    add_common_args(parser)
    parser.set_defaults(workspace=str(ROOT_DIR), target_name="local")
    parser.add_argument("--daemon-binary", default="", help="Override the bpfrejit-daemon binary path.")
    parser.add_argument("--suite", default="", help="Path to the corpus app suite YAML manifest.")
    parser.add_argument("--samples", type=nonnegative_int, required=True, help="Measured samples per corpus app; 0 uses suite defaults.")
    parser.add_argument("--output-json", default="", help="JSON output path.")
    parser.add_argument("--native-repos", default="", help="Comma-separated native repo artifacts to validate.")
    parser.add_argument("--scx-packages", default="", help="Comma-separated SCX package artifacts to validate.")
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        default=[],
        help="Substring filter on app name/runner/workload. Repeat for OR. Forwarded to corpus/driver.py.",
    )
    parser.add_argument(
        "--workload-seconds",
        type=float,
        default=None,
        help="Override per-app workload duration in seconds. Forwarded to corpus/driver.py.",
    )
    parser.add_argument(
        "--no-kinsn",
        action="store_true",
        help="Disable loading kinsn modules. Forwarded to corpus/driver.py.",
    )
    args = parser.parse_args(sys.argv[1:] if argv is None else argv)

    args.native_repos = csv_tokens(args.native_repos)
    args.scx_packages = csv_tokens(args.scx_packages)
    return args


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    return base_suite_runtime_env(workspace, args, "corpus", _die)


def _corpus_driver_argv(workspace: Path, args: argparse.Namespace, daemon_binary: Path) -> list[str]:
    output_json = resolve_workspace_path(
        workspace,
        args.output_json or str(workspace / "corpus" / "results" / f"{args.target_name}_corpus.json"),
    )
    argv = [
        "--daemon", str(daemon_binary),
        "--samples", str(args.samples),
        "--output-json", str(output_json),
    ]
    if args.suite:
        argv.extend(["--suite", str(resolve_workspace_path(workspace, args.suite))])
    for f in (args.filters or []):
        argv.extend(["--filter", str(f)])
    if args.workload_seconds is not None:
        argv.extend(["--workload-seconds", str(args.workload_seconds)])
    if args.no_kinsn:
        argv.append("--no-kinsn")
    return argv


def _run_corpus_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    python_bin = resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    os.chdir(workspace)
    if inside_runtime_image() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_die)
    ensure_bpf_stats_enabled(workspace, _die)
    ensure_scx_artifacts(workspace, args.target_arch, args.scx_packages, _die)
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    ensure_katran_artifacts(workspace, args.target_arch, args.native_repos, _die)
    daemon_binary = resolve_daemon_binary(workspace, args.target_arch, args.daemon_binary, _die)
    command = [python_bin, str(workspace / "corpus" / "driver.py"), *_corpus_driver_argv(workspace, args, daemon_binary)]
    run_checked(command, cwd=workspace, env=runtime_env, die=_die)


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    _run_corpus_suite(workspace, args)


if __name__ == "__main__":
    main()
