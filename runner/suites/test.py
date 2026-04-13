from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path
from typing import Sequence

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.kinsn import load_kinsn_modules
from runner.libs.workspace_layout import (
    kinsn_module_dir,
    test_negative_build_dir,
    test_unittest_build_dir,
)
from runner.suites._common import (
    add_common_args,
    base_suite_runtime_env,
    ensure_bpf_stats_enabled,
    ensure_scx_artifacts,
    env_with_suite_runtime_ld,
    inside_runtime_container,
    merge_csv_and_repeated,
    positive_int,
    resolve_daemon_binary,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    run_in_runtime_container,
    suite_main_setup,
)

_die = partial(fail, "test-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run the test suite as a standalone entrypoint.",
    )
    add_common_args(parser)
    parser.set_defaults(workspace=str(ROOT_DIR), target_name="local")
    parser.add_argument("--daemon-binary", default="", help="Override the bpfrejit-daemon binary path.")
    parser.add_argument("--artifact-dir", default="", help="Override the test suite artifact directory.")
    parser.add_argument("--run-contract-json", default="", help="Run contract JSON to persist beside test logs.")
    parser.add_argument("--run-contract-path", default="", help="Run contract JSON path to copy beside test logs.")
    parser.add_argument(
        "--test-mode",
        choices=["selftest", "negative", "test", "full", "fuzz"],
        default="test",
        help="Test mode to run. 'full' is an alias for 'test'.",
    )
    parser.add_argument("--fuzz-rounds", type=positive_int, default=1000, help="Number of fuzz_rejit rounds.")
    parser.add_argument("--scx-prog-show-race-mode", default="bpftool-loop", help="scx_prog_show_race mode.")
    parser.add_argument("--scx-prog-show-race-iterations", type=positive_int, default=20, help="scx_prog_show_race iterations.")
    parser.add_argument("--scx-prog-show-race-load-timeout", type=positive_int, default=20, help="scx_prog_show_race load timeout.")
    parser.add_argument("--scx-prog-show-race-skip-probe", action="store_true", help="Skip the sched_ext probe for scx_prog_show_race.")
    parser.add_argument("--scx-package", action="append", dest="scx_package_values", default=None, help="SCX package artifact to validate; repeatable.")
    parser.add_argument("--scx-packages", default="", help="Comma-separated SCX package artifacts to validate.")
    args = parser.parse_args(sys.argv[1:] if argv is None else argv)

    args.test_mode = "test" if args.test_mode == "full" else args.test_mode
    args.scx_packages = merge_csv_and_repeated(args.scx_packages, args.scx_package_values)
    return args


def _module_argv(args: argparse.Namespace) -> list[str]:
    argv = [
        "--workspace", str(args.workspace),
        "--target-arch", str(args.target_arch),
        "--target-name", str(args.target_name),
        "--executor", str(args.executor),
        "--bpftool-bin", str(args.bpftool_bin),
        "--test-mode", str(args.test_mode),
        "--fuzz-rounds", str(args.fuzz_rounds),
        "--scx-prog-show-race-mode", str(args.scx_prog_show_race_mode),
        "--scx-prog-show-race-iterations", str(args.scx_prog_show_race_iterations),
        "--scx-prog-show-race-load-timeout", str(args.scx_prog_show_race_load_timeout),
        "--container-runtime", str(args.container_runtime),
        "--runtime-python-bin", str(args.runtime_python_bin),
    ]
    for option, value in (
        ("--run-token", args.run_token),
        ("--python-bin", args.python_bin),
        ("--daemon-binary", args.daemon_binary),
        ("--artifact-dir", args.artifact_dir),
        ("--run-contract-json", args.run_contract_json),
        ("--run-contract-path", args.run_contract_path),
        ("--runtime-container-image", args.runtime_container_image),
    ):
        if value:
            argv.extend([option, str(value)])
    for package_name in args.scx_packages or []:
        argv.extend(["--scx-package", str(package_name)])
    if args.scx_prog_show_race_skip_probe:
        argv.append("--scx-prog-show-race-skip-probe")
    return argv


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    return base_suite_runtime_env(workspace, args, "test", _die)


def _run_with_status(
    command: Sequence[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path | None = None,
) -> bool:
    process = subprocess.Popen(
        list(command),
        cwd=cwd,
        env=env,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    assert process.stdout is not None
    log_file = None
    if log_path is not None:
        log_path.parent.mkdir(parents=True, exist_ok=True)
        log_file = log_path.open("a", encoding="utf-8")
    try:
        for line in process.stdout:
            if log_file is not None:
                log_file.write(line)
            sys.stderr.write(line)
    finally:
        if log_file is not None:
            log_file.close()
    return process.wait() == 0


def _expected_kinsn_modules(workspace: Path, target_arch: str) -> list[str]:
    module_dir = kinsn_module_dir(workspace, target_arch)
    modules = sorted(
        path.stem
        for path in module_dir.glob("bpf_*.ko")
        if path.is_file() and path.stem != "bpf_barrier"
    )
    if not modules:
        _die(f"no kinsn modules found under {module_dir}")
    return modules


def _load_kinsn_modules(workspace: Path, target_arch: str) -> None:
    load_kinsn_modules(
        _expected_kinsn_modules(workspace, target_arch),
        module_dir=kinsn_module_dir(workspace, target_arch),
    )


def _discover_unittest_binaries(workspace: Path, target_arch: str) -> list[Path]:
    build_dir = test_unittest_build_dir(workspace, target_arch)
    return sorted(
        path
        for path in build_dir.glob("rejit_*")
        if path.is_file() and os.access(path, os.X_OK)
    )


def _log_test_section(title: str) -> None:
    print(f"\n========================================\n  {title}\n========================================", file=sys.stderr)


def _run_unittest_suite(workspace: Path, args: argparse.Namespace, env: dict[str, str], *, log_path: Path | None = None) -> tuple[int, int]:
    _log_test_section("Running tests/unittest/ suite (pre-built)")
    build_dir = test_unittest_build_dir(workspace, args.target_arch)
    tests = _discover_unittest_binaries(workspace, args.target_arch)
    if not tests:
        print(f"ERROR: no rejit_* test binaries found in {build_dir}", file=sys.stderr)
        return 0, 1
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    runtime_env["BPFREJIT_PROGS_DIR"] = str(build_dir / "progs")
    runtime_env["BPFREJIT_DAEMON_PATH"] = str(resolve_daemon_binary(workspace, args.target_arch, args.daemon_binary, _die))
    passed = failed = 0
    for test_binary in tests:
        print(f"--- {test_binary.name} ---", file=sys.stderr)
        if _run_with_status([str(test_binary), str(build_dir / "progs")], cwd=workspace, env=runtime_env, log_path=log_path):
            passed += 1
        else:
            failed += 1
            print(f"FAIL: {test_binary.name}", file=sys.stderr)
    return passed, failed


def _fuzz_rounds_text(args: argparse.Namespace) -> str:
    return str(args.fuzz_rounds)


def _run_negative_suite(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    *,
    include_scx_race: bool,
    include_adversarial: bool = True,
    include_fuzz: bool = True,
    log_path: Path | None = None,
) -> tuple[int, int]:
    _log_test_section("Running tests/negative/ adversarial suite")
    negative_build = test_negative_build_dir(workspace, args.target_arch)
    runtime_env, runtime_ld = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    passed = 0
    failed = 0
    tests: list[tuple[str, list[str], dict[str, str]]] = []
    if include_adversarial:
        tests.append(("adversarial_rejit", [str(negative_build / "adversarial_rejit")], runtime_env.copy()))
    if include_fuzz:
        tests.append(
            (
                f"fuzz_rejit ({_fuzz_rounds_text(args)} rounds)",
                [str(negative_build / "fuzz_rejit"), _fuzz_rounds_text(args)],
                runtime_env.copy(),
            )
        )
    if include_scx_race:
        scx_env = {**runtime_env, "SCX_RUNTIME_LD_LIBRARY_PATH": runtime_ld}
        scx_command = [
            str(negative_build / "scx_prog_show_race"),
            str(workspace),
            "--mode", str(args.scx_prog_show_race_mode),
            "--iterations", str(args.scx_prog_show_race_iterations),
            "--load-timeout", str(args.scx_prog_show_race_load_timeout),
        ]
        if args.scx_prog_show_race_skip_probe:
            scx_command.append("--skip-probe")
        tests.append((f"scx_prog_show_race ({args.scx_prog_show_race_mode})", scx_command, scx_env))
    for label, command, command_env in tests:
        print(f"--- {label} ---", file=sys.stderr)
        if _run_with_status(command, cwd=workspace, env=command_env, log_path=log_path):
            passed += 1
        else:
            failed += 1
            print(f"FAIL: {label.split(' (')[0]}", file=sys.stderr)
    return passed, failed


def _run_kernel_selftest(workspace: Path, env: dict[str, str]) -> tuple[int, int]:
    kernel_selftest = workspace / "tests" / "kernel" / "build" / "test_recompile"
    if not kernel_selftest.is_file():
        print(f"SKIP: test_recompile not found at {kernel_selftest}", file=sys.stderr)
        return 0, 0
    _log_test_section("Kernel selftest (test_recompile)")
    if _run_with_status([str(kernel_selftest)], cwd=workspace, env=env):
        return 1, 0
    print("FAIL: test_recompile", file=sys.stderr)
    return 0, 1


def _print_test_summary(passed: int, failed: int, *, prefix: str = "RESULTS") -> None:
    print(f"\n========================================\n  {prefix}: {passed} passed, {failed} failed\n========================================", file=sys.stderr)


def _artifact_dir(workspace: Path, args: argparse.Namespace) -> Path:
    if args.artifact_dir:
        return resolve_workspace_path(workspace, args.artifact_dir)
    token = args.run_token or f"{args.target_name}_test"
    return workspace / "tests" / "results" / token


def _prepare_test_artifacts(workspace: Path, args: argparse.Namespace) -> Path:
    artifact_dir = _artifact_dir(workspace, args)
    artifact_dir.mkdir(parents=True, exist_ok=True)
    contract_path = artifact_dir / "run-contract.json"
    if args.run_contract_path:
        shutil.copy2(resolve_workspace_path(workspace, args.run_contract_path), contract_path)
    elif args.run_contract_json:
        try:
            payload = json.loads(args.run_contract_json)
        except json.JSONDecodeError as exc:
            _die(f"invalid run contract JSON: {exc}")
            raise AssertionError("unreachable")
        contract_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return artifact_dir


def _run_selftest_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "selftest.log"
    _log_test_section("Loading kinsn modules")
    _load_kinsn_modules(workspace, args.target_arch)
    pa, fa = _run_unittest_suite(workspace, args, env, log_path=log_path)
    pb, fb = _run_negative_suite(workspace, args, env, include_scx_race=False, log_path=log_path)
    _print_test_summary(pa + pb, fa + fb, prefix="vm-selftest")
    if fa + fb:
        _die("vm-selftest failed")


def _run_negative_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "negative.log"
    passed, failed = _run_negative_suite(workspace, args, env, include_scx_race=True, log_path=log_path)
    _print_test_summary(passed, failed, prefix="vm-negative-test")
    if failed:
        _die("vm-negative-test failed")


def _run_fuzz_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "fuzz.log"
    passed, failed = _run_negative_suite(
        workspace, args, env,
        include_scx_race=False, include_adversarial=False, include_fuzz=True,
        log_path=log_path,
    )
    _print_test_summary(passed, failed, prefix="vm-fuzz-test")
    if failed:
        _die("vm-fuzz-test failed")


def _run_full_test_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str]) -> None:
    total_pass = total_fail = 0
    p, f = _run_kernel_selftest(workspace, env)
    total_pass += p
    total_fail += f
    _log_test_section("Loading kinsn modules")
    _load_kinsn_modules(workspace, args.target_arch)
    p, f = _run_unittest_suite(workspace, args, env)
    total_pass += p
    total_fail += f
    p, f = _run_negative_suite(workspace, args, env, include_scx_race=True)
    total_pass += p
    total_fail += f
    _print_test_summary(total_pass, total_fail)
    if total_fail:
        _die("vm-test failed")
    print("vm-test: ALL PASSED", file=sys.stderr)


def _mode_needs_bpf_stats(mode: str) -> bool:
    return mode in {"selftest", "test"}


def _run_test_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    artifact_dir = _prepare_test_artifacts(workspace, args)
    os.chdir(workspace)
    if inside_runtime_container() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_die)
    if _mode_needs_bpf_stats(args.test_mode):
        ensure_bpf_stats_enabled(workspace, _die)
    ensure_scx_artifacts(workspace, args.target_arch, args.scx_packages, _die)

    if args.test_mode == "selftest":
        _run_selftest_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "negative":
        _run_negative_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "fuzz":
        _run_fuzz_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "test":
        _run_full_test_mode(workspace, args, env)
    else:
        _die(f"unsupported test mode: {args.test_mode}")


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    if args.runtime_container_image and not inside_runtime_container():
        run_in_runtime_container(
            args.workspace,
            args_module="runner.suites.test",
            module_argv=_module_argv(args),
            container_runtime=args.container_runtime,
            image=args.runtime_container_image,
            runtime_python_bin=args.runtime_python_bin,
            target_arch=args.target_arch,
        )
        return
    _run_test_suite(workspace, args)


if __name__ == "__main__":
    main()
