from __future__ import annotations
import os
import subprocess
import shutil
import sys
from pathlib import Path

from runner.libs.prereq_contract import env_csv, python_import_name, required_commands, tool_packages
from runner.libs.run_contract import load_manifest_environment


def die(message: str) -> "NoReturn":
    print(f"[guest-prereqs][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def resolve_workspace_contract_path(workspace: Path, path: str) -> Path:
    candidate = Path(path)
    if candidate.is_absolute():
        return candidate
    return workspace / candidate


def workload_tool_is_bundled(tool: str) -> bool:
    return tool in env_csv("RUN_BUNDLED_WORKLOAD_TOOLS_CSV")


def resolve_remote_workload_tool_bin(workspace: Path) -> Path | None:
    if not env_csv("RUN_WORKLOAD_TOOLS_CSV"):
        return None
    remote_tool_bin = os.environ.get("RUN_REMOTE_WORKLOAD_TOOL_BIN", "").strip()
    if not remote_tool_bin:
        die("manifest remote workload-tool bin is missing while workload tools are requested")
    return resolve_workspace_contract_path(workspace, remote_tool_bin)


def runtime_path_value(workspace: Path) -> str:
    remote_tool_bin = resolve_remote_workload_tool_bin(workspace)
    path_value = os.environ.get("PATH", "")
    if remote_tool_bin and remote_tool_bin.is_dir():
        return f"{remote_tool_bin}:{path_value}" if path_value else str(remote_tool_bin)
    return path_value


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


def install_python_modules(workspace: Path, python_bin: str) -> None:
    package_csv = env_csv("RUN_REMOTE_PYTHON_MODULES_CSV")
    if not package_csv:
        return
    path_value = runtime_path_value(workspace)
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


def install_guest_prereqs(workspace: Path) -> None:
    path_value = runtime_path_value(workspace)
    missing_commands: list[str] = []
    python_bin = os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip()
    for command_name in required_commands(mode="runtime"):
        if have_cmd(command_name, path_value=path_value):
            continue
        if workload_tool_is_bundled(command_name):
            die(f"required bundled workload tool is missing from the guest tool bin: {command_name}")
        if command_name not in missing_commands:
            missing_commands.append(command_name)

    missing_python_packages: list[str] = []
    for package_name in env_csv("RUN_REMOTE_PYTHON_MODULES_CSV"):
        import_name = python_import_name(package_name)
        if not python_module_available(python_bin, import_name, path_value=path_value):
            if package_name not in missing_python_packages:
                missing_python_packages.append(package_name)

    if not missing_commands and not missing_python_packages:
        return

    manager = os.environ.get("RUN_GUEST_PACKAGE_MANAGER", "").strip()
    if not manager:
        die("RUN_GUEST_PACKAGE_MANAGER is required for guest provisioning")
    packages: list[str] = []
    for command_name in missing_commands:
        for package_name in tool_packages(manager, command_name):
            if package_name not in packages:
                packages.append(package_name)
    install_packages(manager, packages, path_value=path_value)
    if missing_python_packages:
        install_python_modules(workspace, python_bin)


def validate_guest_prereqs(workspace: Path) -> None:
    remote_tool_bin = resolve_remote_workload_tool_bin(workspace)
    path_value = runtime_path_value(workspace)

    for command_name in required_commands(mode="runtime"):
        if workload_tool_is_bundled(command_name):
            if remote_tool_bin is None:
                die("manifest remote workload-tool bin is missing while workload tools are requested")
            bundled_tool = remote_tool_bin / command_name
            if not bundled_tool.is_file() or not os.access(bundled_tool, os.X_OK):
                die(f"required bundled workload tool is missing from the guest tool bin: {command_name}")
        if shutil.which(command_name, path=path_value) is None:
            die(f"required guest command is missing: {command_name}")

    python_bin = os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip()
    if python_bin and shutil.which(python_bin, path=path_value) is None:
        die(f"required guest command is missing: {python_bin}")

    for package_name in env_csv("RUN_REMOTE_PYTHON_MODULES_CSV"):
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
    load_manifest_environment(manifest_path)
    if args[0] == "install":
        install_guest_prereqs(workspace)
        return
    validate_guest_prereqs(workspace)


if __name__ == "__main__":
    main()
