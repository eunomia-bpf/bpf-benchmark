from __future__ import annotations

import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.manifest_file import manifest_scalar, parse_manifest, required_manifest_scalar
from runner.libs.vm import run_in_vm, write_guest_script

_die = partial(fail, "kvm-executor")


def suite_command(workspace_root: Path, manifest_path: Path, contract: dict[str, str | list[str]]) -> str:
    remote_python = required_manifest_scalar(contract, "RUN_REMOTE_PYTHON_BIN", die=_die)
    return (
        f'cd "{workspace_root}" && '
        f'PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '
        f'"{remote_python}" -m runner.libs.execute_workspace '
        f'"{workspace_root}" "{manifest_path}"'
    )


def _optional_int(mapping: dict[str, str | list[str]], name: str) -> int | None:
    value = manifest_scalar(mapping, name, die=_die)
    if not value:
        return None
    return int(value)


def run_vm_suite(workspace_root: Path, manifest_path: Path, contract: dict[str, str | list[str]]) -> int:
    guest_script = write_guest_script(
        [suite_command(workspace_root, manifest_path, contract)],
        initial_cwd=ROOT_DIR,
    )
    completed = run_in_vm(
        required_manifest_scalar(contract, "RUN_VM_KERNEL_IMAGE", die=_die),
        guest_script,
        _optional_int(contract, "RUN_VM_CPUS"),
        manifest_scalar(contract, "RUN_VM_MEM", die=_die) or None,
        int(required_manifest_scalar(contract, "RUN_VM_TIMEOUT_SECONDS", die=_die)),
        cwd=ROOT_DIR,
        rwdirs=(ROOT_DIR,),
        vm_executable=required_manifest_scalar(contract, "RUN_VM_EXECUTABLE", die=_die),
        machine_backend=required_manifest_scalar(contract, "RUN_VM_BACKEND", die=_die),
    )
    if completed.stdout:
        sys.stdout.write(completed.stdout)
    if completed.stderr:
        sys.stderr.write(completed.stderr)
    return completed.returncode


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 1:
        _die("usage: kvm_executor.py <manifest_path>")
    manifest_path = Path(args[0]).resolve()
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    contract = parse_manifest(manifest_path)

    executor = required_manifest_scalar(contract, "RUN_EXECUTOR", die=_die)
    if executor != "kvm":
        _die(f"manifest executor is not kvm: {executor}")
    workspace_root = ROOT_DIR
    raise SystemExit(run_vm_suite(workspace_root, manifest_path, contract))


if __name__ == "__main__":
    main()
