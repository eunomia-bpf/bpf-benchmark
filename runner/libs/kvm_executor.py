from __future__ import annotations

import shutil
import subprocess
import sys
import tarfile
import tempfile
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
from runner.libs.state_file import read_state

_die = partial(fail, "kvm-executor")


def _require_scalar(mapping: dict[str, str | list[str]], name: str) -> str:
    value = mapping.get(name, "")
    if isinstance(value, list):
        _die(f"manifest {name} must be scalar")
    value = value.strip()
    if not value:
        _die(f"manifest {name} is empty")
    return value


def bundle_stage_root(bundle_tar: Path) -> Path:
    stage_token = bundle_tar.parent.name or bundle_tar.name.removesuffix(".tar.gz")
    stage_bundle_root = Path(tempfile.gettempdir()) / "bpf-benchmark-kvm" / stage_token
    stage_root = stage_bundle_root / "workspace"
    shutil.rmtree(stage_bundle_root, ignore_errors=True)
    stage_root.mkdir(parents=True, exist_ok=True)
    with tarfile.open(bundle_tar, "r:gz") as archive:
        archive.extractall(stage_root, filter="data")
    manifest_path = stage_root / "run-contract.env"
    if not manifest_path.is_file():
        _die(f"staged KVM manifest is missing after untar: {manifest_path}")
    return stage_root


def suite_command(workspace_root: Path, contract: dict[str, str | list[str]]) -> str:
    workspace_manifest = workspace_root / "run-contract.env"
    remote_python = _require_scalar(contract, "RUN_REMOTE_PYTHON_BIN")
    return (
        f'cd "{workspace_root}" && '
        f'PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '
        f'"{remote_python}" -m runner.libs.execute_workspace '
        f'"{workspace_root}" "{workspace_manifest}"'
    )


def build_vm_command(workspace_root: Path, contract: dict[str, str | list[str]]) -> list[str]:
    runner_dir = ROOT_DIR / "runner"
    command = [
        _require_scalar(contract, "RUN_HOST_PYTHON_BIN"),
        str(runner_dir / "scripts" / "run_vm_shell.py"),
        "--vm-backend",
        _require_scalar(contract, "RUN_VM_BACKEND"),
        "--vm-executable",
        _require_scalar(contract, "RUN_VM_EXECUTABLE"),
        "--vm-lock-scope",
        _require_scalar(contract, "RUN_VM_LOCK_SCOPE"),
        "--vm-machine-name",
        _require_scalar(contract, "RUN_VM_MACHINE_NAME"),
        "--vm-machine-arch",
        _require_scalar(contract, "RUN_VM_MACHINE_ARCH"),
        "--action",
        f"vm-{_require_scalar(contract, 'RUN_SUITE_NAME')}",
        "--kernel-image",
        _require_scalar(contract, "RUN_VM_KERNEL_IMAGE"),
        "--timeout",
        _require_scalar(contract, "RUN_VM_TIMEOUT_SECONDS"),
        "--cwd",
        str(workspace_root),
        "--rwdir",
        str(workspace_root),
        "--command",
        suite_command(workspace_root, contract),
    ]
    if cpus := _require_optional_scalar(contract, "RUN_VM_CPUS"):
        command.extend(["--cpus", cpus])
    if mem := _require_optional_scalar(contract, "RUN_VM_MEM"):
        command.extend(["--mem", mem])
    return command


def _require_optional_scalar(mapping: dict[str, str | list[str]], name: str) -> str:
    value = mapping.get(name, "")
    if isinstance(value, list):
        _die(f"manifest {name} must be scalar")
    return value.strip()


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

    contract = parse_manifest(manifest_path)
    local_state = read_state(local_state_path)

    executor = _require_scalar(contract, "RUN_EXECUTOR")
    if executor != "kvm":
        _die(f"manifest executor is not kvm: {executor}")
    bundle_tar_value = local_state.get("RUN_BUNDLE_TAR", "").strip()
    if not bundle_tar_value:
        _die("staged KVM bundle tar is missing from local state")
    bundle_tar = Path(bundle_tar_value).resolve()
    if not bundle_tar.is_file():
        _die(f"staged KVM bundle tar does not exist: {bundle_tar}")

    workspace_root = bundle_stage_root(bundle_tar)
    completed = subprocess.run(
        build_vm_command(workspace_root, contract),
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
