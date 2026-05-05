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
from runner.libs.run_contract import (
    RunConfig,
    build_run_config,
    build_target_config,
    write_run_config_file,
)
from runner.libs.suite_args import suite_args_from_env, write_suite_args_file


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
    mode_text = str(mode).strip()
    allowed_suites = {"micro", "corpus"}
    ordered_suites = ["micro", "corpus"]
    if not mode_text:
        _die("benchmark mode is empty")
    if mode_text == "all":
        return ordered_suites
    suites = [suite.strip() for suite in mode_text.split(",")]
    if any(not suite for suite in suites):
        _die(f"unsupported benchmark mode: {mode}; use one of micro, corpus, all")
    invalid = [suite for suite in suites if suite not in allowed_suites]
    if invalid:
        _die(f"unsupported benchmark mode: {mode}; use one of micro, corpus, all")
    return suites


def _benchmark_action(target_name: str, mode: str, suite_args: list[str] | None = None) -> None:
    for suite in _parse_benchmark_suites(mode):
        _run_action(target_name, suite, suite_args)


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
            _die("usage: run_target_suite.py benchmark <target> <micro|corpus> [-- suite-args...]")
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
