from __future__ import annotations

import os
import shutil
import subprocess
import sys
import tarfile
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import load_manifest_environment
from runner.libs.state_file import read_state


def _die(message: str) -> "NoReturn":
    print(f"[kvm-executor][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _require_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        _die(f"manifest {name} is empty")
    return value


def bundle_stage_root(bundle_tar: Path) -> Path:
    stage_token = bundle_tar.name.removesuffix(".tar.gz")
    stage_root = bundle_tar.parent / stage_token / "workspace"
    shutil.rmtree(stage_root, ignore_errors=True)
    stage_root.mkdir(parents=True, exist_ok=True)
    with tarfile.open(bundle_tar, "r:gz") as archive:
        archive.extractall(stage_root, filter="data")
    manifest_path = stage_root / "run-contract.env"
    if not manifest_path.is_file():
        _die(f"staged KVM manifest is missing after untar: {manifest_path}")
    return stage_root


def suite_command(workspace_root: Path) -> str:
    workspace_manifest = workspace_root / "run-contract.env"
    remote_python = _require_env("RUN_REMOTE_PYTHON_BIN")
    return (
        f'cd "{workspace_root}" && '
        f'PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '
        f'"{remote_python}" -m runner.libs.execute_workspace '
        f'"{workspace_root}" "{workspace_manifest}"'
    )


def build_vm_command(workspace_root: Path) -> list[str]:
    runner_dir = ROOT_DIR / "runner"
    command = [
        _require_env("RUN_HOST_PYTHON_BIN"),
        str(runner_dir / "scripts" / "run_vm_shell.py"),
        "--vm-backend",
        _require_env("RUN_VM_BACKEND"),
        "--vm-executable",
        _require_env("RUN_VM_EXECUTABLE"),
        "--vm-lock-scope",
        _require_env("RUN_VM_LOCK_SCOPE"),
        "--vm-machine-name",
        _require_env("RUN_VM_MACHINE_NAME"),
        "--vm-machine-arch",
        _require_env("RUN_VM_MACHINE_ARCH"),
        "--action",
        f"vm-{_require_env('RUN_SUITE_NAME')}",
        "--kernel-image",
        _require_env("RUN_VM_KERNEL_IMAGE"),
        "--timeout",
        _require_env("RUN_VM_TIMEOUT_SECONDS"),
        "--cwd",
        str(workspace_root),
        "--rwdir",
        str(workspace_root),
        "--command",
        suite_command(workspace_root),
    ]
    if os.environ.get("RUN_VM_CPUS", "").strip():
        command.extend(["--cpus", os.environ["RUN_VM_CPUS"].strip()])
    if os.environ.get("RUN_VM_MEM", "").strip():
        command.extend(["--mem", os.environ["RUN_VM_MEM"].strip()])
    return command


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 2:
        _die("usage: kvm_executor.py <manifest_path> <local_state_path>")
    manifest_path = Path(args[0]).resolve()
    local_state_path = Path(args[1]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")
    if not local_state_path.is_file():
        _die(f"local state file is missing: {local_state_path}")

    load_manifest_environment(manifest_path)
    for name, value in read_state(local_state_path).items():
        os.environ[name] = value

    if os.environ.get("RUN_EXECUTOR", "").strip() != "kvm":
        _die(f"manifest executor is not kvm: {os.environ.get('RUN_EXECUTOR', '').strip()}")
    bundle_tar_value = os.environ.get("RUN_BUNDLE_TAR", "").strip()
    if not bundle_tar_value:
        _die("staged KVM bundle tar is missing from local state")
    bundle_tar = Path(bundle_tar_value).resolve()
    if not bundle_tar.is_file():
        _die(f"staged KVM bundle tar does not exist: {bundle_tar}")

    workspace_root = bundle_stage_root(bundle_tar)
    completed = subprocess.run(
        build_vm_command(workspace_root),
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
