from __future__ import annotations

import os
import re
import secrets
import shlex
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import aws_common
from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
from runner.libs.run_contract import build_manifest, build_target_manifest, write_manifest_file
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


def _base_env_from_contract(contract: dict[str, str | list[str]]) -> dict[str, str]:
    env: dict[str, str] = {}
    for name in ("PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL"):
        value = os.environ.get(name, "").strip()
        if value:
            env[name] = value
    for name, value in contract.items():
        env[name] = shlex.join(value) if isinstance(value, list) else value
    return env


def _run_local_prep(manifest_path: Path) -> None:
    contract = parse_manifest(manifest_path)
    env = _local_prep_env(contract=contract, manifest_path=manifest_path)
    host_python_bin = env["HOST_PYTHON_BIN"]
    targets = _local_prep_target_paths(contract)
    if not targets:
        return
    _make_real_targets(targets=targets, host_python_bin=host_python_bin, env=env)


def _local_prep_env(*, contract: dict[str, str | list[str]], manifest_path: Path) -> dict[str, str]:
    env = _base_env_from_contract(contract)
    host_python_bin = str(contract.get("RUN_HOST_PYTHON_BIN", "")).strip()
    if not host_python_bin:
        _die("manifest host python is missing")
    env.update(
        {
            "ROOT_DIR": str(ROOT_DIR),
            "PYTHONPATH": f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}",
            "MANIFEST_PATH": str(manifest_path),
            "HOST_PYTHON_BIN": host_python_bin,
            "RUN_CONTRACT_PYTHON_BIN": host_python_bin,
        }
    )
    return env


def _local_prep_target_paths(contract: dict[str, str | list[str]]) -> list[str]:
    executor = str(contract.get("RUN_EXECUTOR", "")).strip()
    if executor not in {"aws-ssh", "kvm"}:
        _die(f"unsupported executor for local prep: {executor}")
    target_name = str(contract.get("RUN_TARGET_NAME", "")).strip()
    suite_name = str(contract.get("RUN_SUITE_NAME", "")).strip()
    target_arch = str(contract.get("RUN_TARGET_ARCH", "")).strip()
    if not target_name:
        _die("manifest RUN_TARGET_NAME is empty")
    if not suite_name:
        _die("manifest RUN_SUITE_NAME is empty")
    if not target_arch:
        _die("manifest RUN_TARGET_ARCH is empty")
    return [
        str(path)
        for path in local_prep_targets(
            workspace=ROOT_DIR,
            suite_name=suite_name,
            target_arch=target_arch,
            executor=executor,
            needs_runner_binary=str(contract.get("RUN_NEEDS_RUNNER_BINARY", "0")).strip() == "1",
            needs_daemon_binary=str(contract.get("RUN_NEEDS_DAEMON_BINARY", "0")).strip() == "1",
            needs_kinsn_modules=str(contract.get("RUN_NEEDS_KINSN_MODULES", "0")).strip() == "1",
            needs_workload_tools=str(contract.get("RUN_NEEDS_WORKLOAD_TOOLS", "0")).strip() == "1",
            native_repos=[
                entry.strip()
                for entry in str(contract.get("RUN_NATIVE_REPOS_CSV", "")).split(",")
                if entry.strip()
            ],
            scx_packages=[
                entry.strip()
                for entry in str(contract.get("RUN_SCX_PACKAGES_CSV", "")).split(",")
                if entry.strip()
            ],
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


def _benchmark_shared_targets(target_name: str) -> list[str]:
    if target_name == "aws-x86":
        return [
            str(ROOT_DIR / ".cache" / "aws-x86" / "setup-artifacts" / "x86" / "kernel-release.txt"),
            str(ROOT_DIR / ".cache" / "aws-x86" / "setup-artifacts" / "x86" / "boot" / "bzImage"),
            str(ROOT_DIR / ".cache" / "aws-x86" / "setup-artifacts" / "x86" / "modules.tar.gz"),
        ]
    if target_name == "aws-arm64":
        return [
            str(ROOT_DIR / ".cache" / "aws-arm64" / "setup-artifacts" / "arm64" / "kernel-release.txt"),
            str(ROOT_DIR / ".cache" / "aws-arm64" / "setup-artifacts" / "arm64" / "boot" / "vmlinuz.efi"),
            str(ROOT_DIR / ".cache" / "aws-arm64" / "setup-artifacts" / "arm64" / "modules.tar.gz"),
        ]
    return []

def _write_manifest(target_name: str, suite_name: str, run_token: str, manifest_path: Path) -> None:
    env = os.environ.copy()
    env["RUN_TOKEN"] = run_token
    write_manifest_file(manifest_path, build_manifest(target_name, suite_name, env=env))


def _write_target_manifest(target_name: str, manifest_path: Path) -> None:
    write_manifest_file(manifest_path, build_target_manifest(target_name, env=os.environ.copy()))


def _cleanup_failed_aws_prep(manifest_path: Path) -> None:
    if not manifest_path.is_file():
        return
    ctx = aws_common._build_context("run", manifest_path)
    state: dict[str, str] = {}
    if ctx.state_file.is_file():
        state = aws_common._load_instance_state(ctx)
    instance_id = state.get("STATE_INSTANCE_ID", "").strip()
    if instance_id:
        try:
            aws_common._terminate_instance(ctx, instance_id)
        except Exception:
            pass
    shutil.rmtree(ctx.run_state_dir, ignore_errors=True)


def _run_token(target_name: str, suite_name: str) -> str:
    token = f"run.{target_name}.{suite_name}.{secrets.token_hex(4)}"
    return re.sub(r"[^0-9A-Za-z._-]+", "_", token)


def _control_dir(run_token: str) -> Path:
    control_dir = CONTROL_ROOT / run_token
    control_dir.mkdir(parents=True, exist_ok=True)
    return control_dir


def _run_action(target_name: str, suite_name: str) -> None:
    run_token = _run_token(target_name, suite_name)
    control_dir = _control_dir(run_token)
    manifest_path = control_dir / "manifest.env"
    prep_cleanup_armed = False
    success = False
    try:
        _write_manifest(target_name, suite_name, run_token, manifest_path)
        contract = parse_manifest(manifest_path)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor == "aws-ssh":
            prep_cleanup_armed = True
            _run_checked(
                _python_module_command(
                    "runner.libs.aws_remote_prep",
                    str(manifest_path),
                ),
            )
            if os.environ.get("RUN_SKIP_LOCAL_PREP", "").strip() != "1":
                _run_local_prep(manifest_path)
            prep_cleanup_armed = False
            _run_checked(
                _python_module_command(
                    "runner.libs.aws_executor",
                    "run",
                    str(manifest_path),
                )
            )
            success = True
            return
        if executor == "kvm":
            if os.environ.get("RUN_SKIP_LOCAL_PREP", "").strip() != "1":
                _run_local_prep(manifest_path)
            _run_checked(
                _python_module_command(
                    "runner.libs.kvm_executor",
                    str(manifest_path),
                )
            )
            success = True
            return
        _die(f"unsupported executor: {executor}")
    finally:
        if prep_cleanup_armed:
            _cleanup_failed_aws_prep(manifest_path)
        if success:
            shutil.rmtree(control_dir, ignore_errors=True)
        else:
            if control_dir.exists():
                print(f"[run-target-suite][ERROR] preserved debug artifact: {control_dir}", file=sys.stderr)


def _benchmark_action(target_name: str, mode: str) -> None:
    suites = [entry.strip() for entry in str(mode).split(",") if entry.strip()]
    allowed_suites = {"micro", "corpus", "e2e"}
    if not suites:
        _die("benchmark mode is empty")
    if len(suites) == 1 and suites[0] in allowed_suites:
        _run_action(target_name, suites[0])
        return
    if len(suites) == 1 and suites[0] == "all":
        suites = ["micro", "corpus", "e2e"]
    elif any(suite not in allowed_suites for suite in suites):
        _die(f"unsupported benchmark mode: {mode}")
    CONTROL_ROOT.mkdir(parents=True, exist_ok=True)
    target_manifest = CONTROL_ROOT / f"benchmark-target.{target_name}.env"
    try:
        _write_target_manifest(target_name, target_manifest)
        contract = parse_manifest(target_manifest)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor != "aws-ssh":
            for suite_name in suites:
                _run_action(target_name, suite_name)
            return
        prep_manifests: list[Path] = []
        shared_targets = _benchmark_shared_targets(target_name)
        shared_env: dict[str, str] | None = None
        shared_host_python_bin = ""
        try:
            for suite_name in suites:
                prep_manifest = CONTROL_ROOT / f"benchmark-prep.{target_name}.{suite_name}.env"
                prep_manifests.append(prep_manifest)
                _write_manifest(target_name, suite_name, f"benchmark-prep.{target_name}.{suite_name}", prep_manifest)
                prep_contract = parse_manifest(prep_manifest)
                prep_env = _local_prep_env(contract=prep_contract, manifest_path=prep_manifest)
                _make_real_targets(
                    targets=_local_prep_target_paths(prep_contract),
                    host_python_bin=prep_env["HOST_PYTHON_BIN"],
                    env=prep_env,
                )
                if shared_env is None:
                    shared_env = prep_env
                    shared_host_python_bin = prep_env["HOST_PYTHON_BIN"]
            if shared_targets and shared_env is not None:
                _make_real_targets(
                    targets=shared_targets,
                    host_python_bin=shared_host_python_bin,
                    env=shared_env,
                )
        finally:
            for prep_manifest in prep_manifests:
                prep_manifest.unlink(missing_ok=True)
        child_env = os.environ.copy()
        child_env["RUN_SKIP_LOCAL_PREP"] = "1"
        child_env["RUN_SKIP_AWS_SHARED_ARTIFACT_MAKE"] = "1"
        processes = [
            subprocess.Popen(
                [sys.executable, "-m", "runner.libs.run_target_suite", "run", target_name, suite_name],
                cwd=ROOT_DIR,
                env=child_env,
            )
            for suite_name in suites
        ]
        status = 0
        for process in processes:
            process.wait()
            if process.returncode != 0 and status == 0:
                status = process.returncode
        if status != 0:
            raise SystemExit(status)
        return
    finally:
        target_manifest.unlink(missing_ok=True)


def _terminate_action(target_name: str) -> None:
    CONTROL_ROOT.mkdir(parents=True, exist_ok=True)
    manifest_path = CONTROL_ROOT / f"terminate.{target_name}.env"
    try:
        _write_target_manifest(target_name, manifest_path)
        contract = parse_manifest(manifest_path)
        executor = str(contract.get("RUN_EXECUTOR", ""))
        if executor != "aws-ssh":
            _die("terminate is only valid for AWS targets")
        _run_checked(
            _python_module_command(
                "runner.libs.aws_executor",
                "terminate",
                str(manifest_path),
            )
        )
    finally:
        manifest_path.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args:
        _die("usage: run_target_suite.py <run|benchmark|terminate> <target> [suite]")
    action = args[0]
    target_name = args[1] if len(args) > 1 else ""
    suite_name = args[2] if len(args) > 2 else ""
    if action == "run":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py run <target> <suite>")
        _run_action(target_name, suite_name)
        return
    if action == "benchmark":
        if not target_name or not suite_name:
            _die("usage: run_target_suite.py benchmark <target> <micro|corpus|e2e|all|suite1,suite2>")
        _benchmark_action(target_name, suite_name)
        return
    if action == "terminate":
        if not target_name:
            _die("usage: run_target_suite.py terminate <target>")
        _terminate_action(target_name)
        return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
