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
from runner.suites._common import (
    add_common_args,
    argv_option_value,
    base_suite_runtime_env,
    ensure_bpf_stats_enabled,
    ensure_katran_artifacts,
    ensure_scx_artifacts,
    env_with_suite_runtime_ld,
    inside_runtime_image,
    merge_csv_and_repeated,
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
    parser.add_argument("--warmups", type=nonnegative_int, default=0, help="Accepted for run-contract parity; corpus ignores warmups.")
    parser.add_argument("--output-json", default="", help="JSON output path.")
    parser.add_argument("--output-md", default="", help="Markdown output path.")
    parser.add_argument(
        "--corpus-filter",
        "--filter",
        action="append",
        dest="corpus_filter_values",
        default=None,
        help="Corpus app filter to run; repeatable.",
    )
    parser.add_argument("--corpus-filters", default="", help="Comma-separated corpus app filters.")
    parser.add_argument("--corpus-workload-seconds", "--workload-seconds", default="", help="Override corpus workload duration.")
    parser.add_argument("--native-repo", action="append", dest="native_repo_values", default=None, help="Native repo artifact to validate; repeatable.")
    parser.add_argument("--native-repos", default="", help="Comma-separated native repo artifacts to validate.")
    parser.add_argument("--scx-package", action="append", dest="scx_package_values", default=None, help="SCX package artifact to validate; repeatable.")
    parser.add_argument("--scx-packages", default="", help="Comma-separated SCX package artifacts to validate.")
    parser.add_argument(
        "--corpus-argv",
        action="append",
        dest="corpus_argv_values",
        default=None,
        help="Extra argument token or shell-quoted argument string passed to corpus/driver.py; repeatable.",
    )
    parser.add_argument("corpus_argv_remainder", nargs=argparse.REMAINDER, help=argparse.SUPPRESS)
    args = parser.parse_args(sys.argv[1:] if argv is None else argv)

    args.corpus_filters = merge_csv_and_repeated(args.corpus_filters, args.corpus_filter_values)
    args.native_repos = merge_csv_and_repeated(args.native_repos, args.native_repo_values)
    args.scx_packages = merge_csv_and_repeated(args.scx_packages, args.scx_package_values)
    corpus_argv: list[str] = []
    for value in args.corpus_argv_values or []:
        corpus_argv.extend(shlex.split(str(value)))
    remainder = list(args.corpus_argv_remainder or [])
    if remainder and remainder[0] == "--":
        remainder = remainder[1:]
    corpus_argv.extend(remainder)
    args.corpus_argv = corpus_argv
    return args


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    env = base_suite_runtime_env(workspace, args, "corpus", _die)
    if rejit_passes := argv_option_value(args.corpus_argv, "--rejit-passes", _die):
        env["BPFREJIT_BENCH_PASSES"] = rejit_passes
    return env


def _corpus_driver_argv(workspace: Path, args: argparse.Namespace, daemon_binary: Path) -> list[str]:
    output_json = resolve_workspace_path(
        workspace,
        args.output_json or str(workspace / "corpus" / "results" / f"{args.target_name}_corpus.json"),
    )
    output_md = resolve_workspace_path(
        workspace,
        args.output_md or str(workspace / "corpus" / "results" / f"{args.target_name}_corpus.md"),
    )
    argv = [
        "--daemon", str(daemon_binary),
        "--samples", str(args.samples),
        "--output-json", str(output_json),
        "--output-md", str(output_md),
    ]
    if args.suite:
        argv.extend(["--suite", str(resolve_workspace_path(workspace, args.suite))])
    if args.corpus_workload_seconds:
        argv.extend(["--workload-seconds", str(args.corpus_workload_seconds)])
    for filter_name in args.corpus_filters or []:
        argv.extend(["--filter", str(filter_name)])
    argv.extend(args.corpus_argv)
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
