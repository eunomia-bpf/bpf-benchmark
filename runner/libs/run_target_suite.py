from __future__ import annotations

import os
import re
import secrets
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_executor
from runner.libs.cli_support import fail
from runner.libs.file_lock import runner_lock
from runner.libs.run_contract import (
    RunConfig,
    build_run_config,
    build_target_config,
    write_run_config_file,
)
from runner.libs.suite_args import suite_args_from_env, write_suite_args_file
from runner.libs.workspace_layout import local_prep_targets


CONTROL_ROOT = ROOT_DIR / ".state" / "runner-contracts"


_die = partial(fail, "run-target-suite")


def _run_checked(command: list[str]) -> None:
    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _python_module_command(module: str, *args: str) -> list[str]:
    return [sys.executable, "-m", module, *args]


def _run_local_prep(config: RunConfig) -> None:
    env = _local_prep_env(config=config)
    host_python_bin = env["HOST_PYTHON_BIN"]
    targets = _local_prep_target_paths(config)
    if not targets:
        return
    target_arch = config.identity.target_arch.strip() or config.identity.target_name.strip()
    with runner_lock(f"artifact-build.{target_arch}"):
        _make_real_targets(targets=targets, host_python_bin=host_python_bin, env=env)


def _local_prep_env(*, config: RunConfig) -> dict[str, str]:
    env = config.env()
    host_python_bin = config.kvm.host_python_bin.strip()
    if not host_python_bin:
        _die("run config host python is missing")
    env.update(
        {
            "ROOT_DIR": str(ROOT_DIR),
            "PYTHONPATH": f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}",
            "HOST_PYTHON_BIN": host_python_bin,
            "RUN_CONTRACT_PYTHON_BIN": host_python_bin,
        }
    )
    return env


def _local_prep_target_paths(config: RunConfig) -> list[str]:
    executor = config.identity.executor.strip()
    if executor not in {"aws-ssh", "kvm"}:
        _die(f"unsupported executor for local prep: {executor}")
    target_name = config.identity.target_name.strip()
    suite_name = config.identity.suite_name.strip()
    target_arch = config.identity.target_arch.strip()
    if not target_name:
        _die("run config target name is empty")
    if not suite_name:
        _die("run config suite name is empty")
    if not target_arch:
        _die("run config target arch is empty")
    return [
        str(path)
        for path in local_prep_targets(
            workspace=ROOT_DIR,
            suite_name=suite_name,
            target_arch=target_arch,
            executor=executor,
        )
    ]


def _make_real_targets(*, targets: list[str], host_python_bin: str, env: dict[str, str]) -> None:
    completed = subprocess.run(
        [
            "make",
            "-C",
            str(ROOT_DIR),
            *targets,
            f"PYTHON={host_python_bin}",
        ],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _build_config(target_name: str, suite_name: str, run_token: str, suite_args: list[str]) -> RunConfig:
    env = os.environ.copy()
    env["RUN_TOKEN"] = run_token
    return build_run_config(target_name, suite_name, env=env, suite_args=suite_args)


def _cleanup_failed_aws_prep(config_path: Path) -> None:
    try:
        aws_executor.cleanup_failed_run_for_config(config_path)
    except Exception as exc:
        print(f"[run-target-suite][WARN] failed to cleanup AWS prep state: {exc}", file=sys.stderr)


def _run_token(target_name: str, suite_name: str) -> str:
    token = f"run.{target_name}.{suite_name}.{secrets.token_hex(4)}"
    return re.sub(r"[^0-9A-Za-z._-]+", "_", token)


def _control_dir(run_token: str) -> Path:
    control_dir = CONTROL_ROOT / run_token
    control_dir.mkdir(parents=True, exist_ok=True)
    return control_dir


def _effective_suite_args(target_name: str, suite_name: str, suite_args: list[str] | None) -> list[str]:
    if suite_args is not None:
        return list(suite_args)
    return suite_args_from_env(target_name, suite_name, env=os.environ.copy())


def _run_action(target_name: str, suite_name: str, suite_args: list[str] | None = None) -> None:
    effective_suite_args = _effective_suite_args(target_name, suite_name, suite_args)
    run_token = _run_token(target_name, suite_name)
    control_dir = _control_dir(run_token)
    config_path = control_dir / "run-config.json"
    suite_args_path = control_dir / "suite-args.json"
    prep_cleanup_armed = False
    success = False
    try:
        config = _build_config(target_name, suite_name, run_token, effective_suite_args)
        executor = config.identity.executor
        if executor == "aws-ssh":
            write_run_config_file(config_path, config)
            write_suite_args_file(suite_args_path, effective_suite_args)
            _run_local_prep(config)
            prep_cleanup_armed = True
            _run_checked(
                _python_module_command(
                    "runner.libs.aws_executor",
                    "run",
                    str(config_path),
                    str(suite_args_path),
                )
            )
            success = True
            return
        if executor == "kvm":
            _run_local_prep(config)
            from runner.libs.kvm_executor import run_vm_suite

            return_code = run_vm_suite(ROOT_DIR, config, effective_suite_args)
            success = return_code == 0
            if return_code != 0:
                raise SystemExit(return_code)
            return
        _die(f"unsupported executor: {executor}")
    finally:
        if prep_cleanup_armed and not success:
            _cleanup_failed_aws_prep(config_path)
        if success:
            shutil.rmtree(control_dir, ignore_errors=True)
        else:
            if control_dir.exists():
                print(f"[run-target-suite][ERROR] preserved debug artifact: {control_dir}", file=sys.stderr)


def _parse_benchmark_suites(mode: str) -> list[str]:
    suites = [entry.strip() for entry in str(mode).split(",") if entry.strip()]
    allowed_suites = {"micro", "corpus", "e2e"}
    if not suites:
        _die("benchmark mode is empty")
    if len(suites) == 1 and suites[0] in allowed_suites:
        return suites
    if len(suites) == 1 and suites[0] == "all":
        return ["micro", "corpus", "e2e"]
    if any(suite not in allowed_suites for suite in suites):
        _die(f"unsupported benchmark mode: {mode}")
    return suites


def _benchmark_action(target_name: str, mode: str, suite_args: list[str] | None = None) -> None:
    suites = _parse_benchmark_suites(mode)
    if suite_args is not None and len(suites) != 1:
        _die("explicit suite arguments are only supported for a single benchmark suite")
    for suite_name in suites:
        _run_action(target_name, suite_name, suite_args)


def _suite_args_from_cli(args: list[str], start_index: int) -> list[str] | None:
    if len(args) <= start_index:
        return None
    if args[start_index] != "--":
        _die("suite arguments must follow --")
    return args[start_index + 1:]


def _terminate_action(target_name: str) -> None:
    CONTROL_ROOT.mkdir(parents=True, exist_ok=True)
    config_path = CONTROL_ROOT / f"terminate.{target_name}.json"
    try:
        config = build_target_config(target_name, env=os.environ.copy())
        write_run_config_file(config_path, config)
        executor = config.identity.executor
        if executor != "aws-ssh":
            _die("terminate is only valid for AWS targets")
        _run_checked(
            _python_module_command(
                "runner.libs.aws_executor",
                "terminate",
                str(config_path),
            )
        )
    finally:
        config_path.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: run_target_suite.py <run|benchmark|terminate> <target> [suite]")
    action = args[0]
    target_name = args[1] if len(args) > 1 else ""
    suite_name = args[2] if len(args) > 2 else ""
    if action == "run":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py run <target> <suite> [-- suite-args...]")
        _run_action(target_name, suite_name, _suite_args_from_cli(args, 3))
        return
    if action == "benchmark":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py benchmark <target> <micro|corpus|e2e|all|suite1,suite2> [-- suite-args...]")
        _benchmark_action(target_name, suite_name, _suite_args_from_cli(args, 3))
        return
    if action == "terminate":
        if not target_name or len(args) != 2:
            _die("usage: run_target_suite.py terminate <target>")
        _terminate_action(target_name)
        return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
