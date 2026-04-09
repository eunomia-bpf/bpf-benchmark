from __future__ import annotations
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path

from runner.libs.cli_support import fail
from runner.libs.manifest_file import parse_manifest
from runner.libs.prereq_contract import env_csv, python_import_name, required_commands, tool_packages

die = partial(fail, "guest-prereqs")


def resolve_workspace_contract_path(workspace: Path, path: str) -> Path:
    candidate = Path(path)
    if candidate.is_absolute():
        return candidate
    return workspace / candidate


def _scalar(contract: dict[str, str | list[str]], name: str) -> str:
    value = contract.get(name, "")
    if isinstance(value, list):
        die(f"manifest {name} must be scalar")
    return value.strip()


def runtime_path_value(workspace: Path, contract: dict[str, str | list[str]]) -> str:
    path_entries: list[str] = []
    bundled_tool_bin = workspace / ".cache" / "workload-tools" / "bin"
    if bundled_tool_bin.is_dir():
        path_entries.append(str(bundled_tool_bin))
    existing = os.environ.get("PATH", "")
    if existing:
        path_entries.extend(token for token in existing.split(":") if token)
    for standard_dir in ("/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin", "/bin"):
        if standard_dir not in path_entries:
            path_entries.append(standard_dir)
    return ":".join(path_entries)


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
            die("guest package installation requires sudo or root")
        final_command = ["sudo", *final_command]
    stdout = subprocess.DEVNULL if quiet else None
    stderr = subprocess.DEVNULL if quiet else None
    env = dict(os.environ)
    env["PATH"] = path_value
    try:
        subprocess.run(final_command, check=True, stdout=stdout, stderr=stderr, env=env)
    except subprocess.CalledProcessError as exc:
        die(f"command failed ({exc.returncode}): {' '.join(final_command)}")


def install_packages(manager: str, packages: list[str], *, path_value: str) -> None:
    if not packages:
        return
    if manager == "apt":
        run_command(["apt-get", "update"], path_value=path_value, sudo=True)
        env_command = ["env", "DEBIAN_FRONTEND=noninteractive", "apt-get", "install", "-y", *packages]
        run_command(env_command, path_value=path_value, sudo=True)
        return
    if manager == "dnf":
        run_command(["dnf", "-y", "install", *packages], path_value=path_value, sudo=True)
        return
    die(f"unsupported guest package manager contract: {manager}")


def ensure_python_pip(python_bin: str, *, path_value: str) -> None:
    resolved_python = shutil.which(python_bin, path=path_value)
    if resolved_python is None:
        die(f"required guest command is missing: {python_bin}")
    result = subprocess.run(
        [resolved_python, "-m", "pip", "--version"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=False,
    )
    if result.returncode == 0:
        return
    run_command([resolved_python, "-m", "ensurepip", "--upgrade"], path_value=path_value, sudo=os.geteuid() != 0, quiet=True)
    result = subprocess.run(
        [resolved_python, "-m", "pip", "--version"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=False,
    )
    if result.returncode != 0:
        die(f"python pip is unavailable for {resolved_python}")


def install_python_modules(workspace: Path, contract: dict[str, str | list[str]], python_bin: str) -> None:
    package_csv = env_csv("RUN_REMOTE_PYTHON_MODULES_CSV", contract=contract)
    if not package_csv:
        return
    path_value = runtime_path_value(workspace, contract)
    resolved_python = shutil.which(python_bin, path=path_value)
    if resolved_python is None:
        die(f"required guest command is missing: {python_bin}")
    ensure_python_pip(python_bin, path_value=path_value)
    run_command(
        [resolved_python, "-m", "pip", "install", "--quiet", *package_csv],
        path_value=path_value,
        sudo=os.geteuid() != 0,
        quiet=True,
    )


def ensure_loopback_up(*, path_value: str) -> None:
    if not have_cmd("ip", path_value=path_value):
        return
    run_command(["ip", "link", "set", "lo", "up"], path_value=path_value, sudo=os.geteuid() != 0, quiet=True)


def install_guest_prereqs(workspace: Path, contract: dict[str, str | list[str]]) -> None:
    path_value = runtime_path_value(workspace, contract)
    missing_commands: list[str] = []
    python_bin = _scalar(contract, "RUN_REMOTE_PYTHON_BIN")
    for command_name in required_commands(mode="runtime", contract=contract):
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

    if not missing_commands and not missing_python_packages:
        ensure_loopback_up(path_value=path_value)
        return

    manager = _scalar(contract, "RUN_GUEST_PACKAGE_MANAGER")
    if not manager:
        die("RUN_GUEST_PACKAGE_MANAGER is required for guest provisioning")
    packages: list[str] = []
    for command_name in missing_commands:
        for package_name in tool_packages(manager, command_name):
            if package_name not in packages:
                packages.append(package_name)
    install_packages(manager, packages, path_value=path_value)
    if missing_python_packages:
        install_python_modules(workspace, contract, python_bin)
    ensure_loopback_up(path_value=path_value)


def validate_guest_prereqs(workspace: Path, contract: dict[str, str | list[str]]) -> None:
    path_value = runtime_path_value(workspace, contract)

    for command_name in required_commands(mode="runtime", contract=contract):
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
    if len(args) != 3 or args[0] not in {"install", "validate"}:
        die("usage: guest_prereqs.py <install|validate> <workspace> <manifest_path>")
    workspace = Path(args[1]).resolve()
    manifest_path = Path(args[2]).resolve()
    if not workspace.is_dir():
        die(f"workspace is missing: {workspace}")
    if not manifest_path.is_file():
        die(f"manifest is missing: {manifest_path}")
    contract = parse_manifest(manifest_path)
    if args[0] == "install":
        install_guest_prereqs(workspace, contract)
        return
    validate_guest_prereqs(workspace, contract)


if __name__ == "__main__":
    main()
