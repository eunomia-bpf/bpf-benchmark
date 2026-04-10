from __future__ import annotations
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
from runner.libs.prereq_contract import bundled_commands, env_csv, python_import_name, required_commands

die = partial(fail, "guest-prereqs")


def _scalar(contract: dict[str, str | list[str]], name: str) -> str:
    value = contract.get(name, "")
    if isinstance(value, list):
        die(f"manifest {name} must be scalar")
    return value.strip()


def runtime_path_value(workspace: Path, contract: dict[str, str | list[str]]) -> str:
    path_entries: list[str] = []
    target_arch = _scalar(contract, "RUN_TARGET_ARCH")
    if target_arch:
        bundled_tool_dir = workspace / ".cache" / "workload-tools" / target_arch / "bin"
        if bundled_tool_dir.is_dir():
            path_entries.append(str(bundled_tool_dir))
    for standard_dir in ("/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin", "/bin"):
        if standard_dir not in path_entries:
            path_entries.append(standard_dir)
    return ":".join(path_entries)


def bundled_tool_dir(workspace: Path, contract: dict[str, str | list[str]]) -> Path | None:
    target_arch = _scalar(contract, "RUN_TARGET_ARCH")
    if not target_arch:
        return None
    candidate = workspace / ".cache" / "workload-tools" / target_arch / "bin"
    if not candidate.is_dir():
        return None
    return candidate


def bundled_command_available(
    workspace: Path,
    contract: dict[str, str | list[str]],
    command_name: str,
) -> bool:
    tool_dir = bundled_tool_dir(workspace, contract)
    if tool_dir is None:
        return False
    candidate = tool_dir / command_name
    return candidate.is_file() and os.access(candidate, os.X_OK)


def have_cmd(command_name: str, *, path_value: str | None = None) -> bool:
    return shutil.which(command_name, path=path_value) is not None


def python_module_available(python_bin: str, import_name: str, *, path_value: str) -> bool:
    if not python_bin:
        return False
    if not have_cmd(python_bin, path_value=path_value):
        return False
    resolved_python = shutil.which(python_bin, path=path_value)
    assert resolved_python is not None
    result = subprocess.run(
        [resolved_python, "-c", f"import {import_name}"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=False,
    )
    return result.returncode == 0


def run_command(command: list[str], *, path_value: str, sudo: bool = False, quiet: bool = False) -> None:
    final_command = list(command)
    if sudo and os.geteuid() != 0:
        if shutil.which("sudo") is None:
            die("guest prerequisite command requires sudo or root")
        final_command = ["sudo", *final_command]
    stdout = subprocess.DEVNULL if quiet else None
    stderr = subprocess.DEVNULL if quiet else None
    env = dict(os.environ)
    env["PATH"] = path_value
    try:
        subprocess.run(final_command, check=True, stdout=stdout, stderr=stderr, env=env)
    except subprocess.CalledProcessError as exc:
        die(f"command failed ({exc.returncode}): {' '.join(final_command)}")


def ensure_loopback_up(*, path_value: str) -> None:
    if not have_cmd("ip", path_value=path_value):
        return
    run_command(["ip", "link", "set", "lo", "up"], path_value=path_value, sudo=os.geteuid() != 0, quiet=True)


def ensure_guest_prereqs(workspace: Path, contract: dict[str, str | list[str]]) -> None:
    path_value = runtime_path_value(workspace, contract)
    missing_commands: list[str] = []
    python_bin = _scalar(contract, "RUN_REMOTE_PYTHON_BIN")
    bundled = set(bundled_commands(contract=contract))
    for command_name in required_commands(contract=contract):
        if command_name in bundled:
            if bundled_command_available(workspace, contract, command_name):
                continue
            if command_name not in missing_commands:
                missing_commands.append(command_name)
            continue
        if have_cmd(command_name, path_value=path_value):
            continue
        if command_name not in missing_commands:
            missing_commands.append(command_name)

    missing_python_packages: list[str] = []
    for package_name in env_csv("RUN_REMOTE_PYTHON_MODULES_CSV", contract=contract):
        import_name = python_import_name(package_name)
        if not python_module_available(python_bin, import_name, path_value=path_value):
            if package_name not in missing_python_packages:
                missing_python_packages.append(package_name)

    missing_bundled_commands = [command_name for command_name in missing_commands if command_name in bundled]
    if missing_bundled_commands:
        die(
            "required bundled guest commands are missing from workspace/.cache/workload-tools/<arch>/bin: "
            + " ".join(missing_bundled_commands)
        )

    if not missing_commands and not missing_python_packages:
        ensure_loopback_up(path_value=path_value)
        return

    missing = [f"command:{name}" for name in missing_commands if name not in bundled]
    missing.extend(f"python:{name}" for name in missing_python_packages)
    die(
        "guest image is missing required prerequisites; bake them into the VM/AMI or transfer them as artifacts: "
        + " ".join(missing)
    )


def validate_guest_prereqs(workspace: Path, contract: dict[str, str | list[str]]) -> None:
    path_value = runtime_path_value(workspace, contract)
    bundled = set(bundled_commands(contract=contract))

    for command_name in required_commands(contract=contract):
        if command_name in bundled:
            if bundled_command_available(workspace, contract, command_name):
                continue
            die(
                "required bundled guest command is missing from workspace/.cache/workload-tools/<arch>/bin: "
                f"{command_name}"
            )
        if shutil.which(command_name, path=path_value) is None:
            die(f"required guest command is missing: {command_name}")

    python_bin = _scalar(contract, "RUN_REMOTE_PYTHON_BIN")
    if python_bin and shutil.which(python_bin, path=path_value) is None:
        die(f"required guest command is missing: {python_bin}")

    for package_name in env_csv("RUN_REMOTE_PYTHON_MODULES_CSV", contract=contract):
        import_name = python_import_name(package_name)
        if not python_bin:
            die("RUN_REMOTE_PYTHON_BIN is required when guest Python modules are requested")
        if not python_module_available(python_bin, import_name, path_value=path_value):
            die(f"required guest Python module is missing for {python_bin}: {package_name}")


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) != 3 or args[0] not in {"ensure", "validate"}:
        die("usage: guest_prereqs.py <ensure|validate> <workspace> <manifest_path>")
    workspace = Path(args[1]).resolve()
    manifest_path = Path(args[2]).resolve()
    if not workspace.is_dir():
        die(f"workspace is missing: {workspace}")
    if not manifest_path.is_file():
        die(f"manifest is missing: {manifest_path}")
    contract = parse_manifest(manifest_path)
    if args[0] == "ensure":
        ensure_guest_prereqs(workspace, contract)
        return
    validate_guest_prereqs(workspace, contract)


if __name__ == "__main__":
    main()
