from __future__ import annotations

import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest

_die = partial(fail, "kvm-executor")


def _require_scalar(mapping: dict[str, str | list[str]], name: str) -> str:
    value = mapping.get(name, "")
    if isinstance(value, list):
        _die(f"manifest {name} must be scalar")
    value = value.strip()
    if not value:
        _die(f"manifest {name} is empty")
    return value


def suite_command(workspace_root: Path, manifest_path: Path, contract: dict[str, str | list[str]]) -> str:
    remote_python = _require_scalar(contract, "RUN_REMOTE_PYTHON_BIN")
    return (
        f'cd "{workspace_root}" && '
        f'PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '
        f'"{remote_python}" -m runner.libs.execute_workspace '
        f'"{workspace_root}" "{manifest_path}"'
    )


def build_vm_command(workspace_root: Path, manifest_path: Path, contract: dict[str, str | list[str]]) -> list[str]:
    runner_dir = ROOT_DIR / "runner"
    command = [
        _require_scalar(contract, "RUN_HOST_PYTHON_BIN"),
        str(runner_dir / "scripts" / "run_vm_shell.py"),
        "--vm-backend",
        _require_scalar(contract, "RUN_VM_BACKEND"),
        "--vm-executable",
        _require_scalar(contract, "RUN_VM_EXECUTABLE"),
        "--kernel-image",
        _require_scalar(contract, "RUN_VM_KERNEL_IMAGE"),
        "--timeout",
        _require_scalar(contract, "RUN_VM_TIMEOUT_SECONDS"),
        "--cwd",
        str(ROOT_DIR),
        "--rwdir",
        str(ROOT_DIR),
        "--command",
        suite_command(workspace_root, manifest_path, contract),
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
    if len(args) != 1:
        _die("usage: kvm_executor.py <manifest_path>")
    manifest_path = Path(args[0]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    contract = parse_manifest(manifest_path)

    executor = _require_scalar(contract, "RUN_EXECUTOR")
    if executor != "kvm":
        _die(f"manifest executor is not kvm: {executor}")
    workspace_root = ROOT_DIR
    completed = subprocess.run(
        build_vm_command(workspace_root, manifest_path, contract),
        cwd=ROOT_DIR,
        text=True,
        capture_output=False,
        check=False,
    )
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
