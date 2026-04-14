from __future__ import annotations

import sys
import shlex
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.run_contract import RunConfig, read_run_config_file
from runner.libs.suite_args import read_suite_args_file, suite_args_from_env
from runner.libs.suite_commands import (
    build_runtime_container_command,
    build_suite_argv,
    runtime_container_result_dirs,
)
from runner.libs.workspace_layout import runtime_container_image_tar_path
from runner.libs.vm import run_in_vm, write_guest_script

_die = partial(fail, "kvm-executor")


def _shell_join(command: list[str]) -> str:
    return " ".join(shlex.quote(str(part)) for part in command)


def _workspace_python_prefix(workspace_root: Path) -> str:
    return f'cd {shlex.quote(str(workspace_root))} && PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '


def _ensure_docker_shell(runtime: str) -> str:
    if Path(runtime).name != "docker":
        return "true"
    log = '"${TMPDIR:-/tmp}/bpf-benchmark-dockerd.log"'
    data_root = '"${TMPDIR:-/tmp}/bpf-benchmark-docker"'
    exec_root = '"${TMPDIR:-/tmp}/bpf-benchmark-docker-exec"'
    pidfile = '"${TMPDIR:-/tmp}/bpf-benchmark-docker.pid"'
    return (
        "(docker info >/dev/null 2>&1 || "
        "systemctl start docker >/dev/null 2>&1 || "
        "service docker start >/dev/null 2>&1 || "
        f"(dockerd --host=unix:///var/run/docker.sock --data-root={data_root} "
        f"--exec-root={exec_root} --pidfile={pidfile} >{log} 2>&1 & sleep 5); "
        "docker info >/dev/null)"
    )


def suite_command(workspace_root: Path, config: RunConfig, suite_args: list[str]) -> str:
    if config.remote.runtime_container_image.strip():
        runtime = config.remote.container_runtime or "docker"
        image_tar = runtime_container_image_tar_path(workspace_root, config.identity.target_arch)
        load_cmd = shlex.join([runtime, "load", "-i", str(image_tar)])
        result_dirs = [str(path) for path in runtime_container_result_dirs(workspace_root)]
        mkdir_cmd = shlex.join(["mkdir", "-p", *result_dirs])
        container_cmd = _shell_join(build_runtime_container_command(workspace_root, config, suite_args, die=_die))
        return f"{mkdir_cmd} && {_ensure_docker_shell(runtime)} && {load_cmd} >/dev/null && {container_cmd}"
    command = build_suite_argv(workspace_root, config, suite_args, die=_die)
    return _workspace_python_prefix(workspace_root) + _shell_join(command)


def _optional_int(value: str) -> int | None:
    if not value.strip():
        return None
    return int(value)


def run_vm_suite(workspace_root: Path, config: RunConfig, suite_args: list[str] | None = None) -> int:
    effective_suite_args = list(suite_args) if suite_args is not None else suite_args_from_env(
        config.identity.target_name,
        config.identity.suite_name,
    )
    guest_script = write_guest_script(
        [suite_command(workspace_root, config, effective_suite_args)],
        initial_cwd=ROOT_DIR,
    )
    completed = run_in_vm(
        config.kvm.kernel_image,
        guest_script,
        _optional_int(config.kvm.cpus),
        config.kvm.mem or None,
        int(config.kvm.timeout_seconds),
        cwd=ROOT_DIR,
        rwdirs=(ROOT_DIR,),
        vm_executable=config.kvm.executable,
        machine_backend=config.kvm.backend,
    )
    if completed.stdout:
        sys.stdout.write(completed.stdout)
    if completed.stderr:
        sys.stderr.write(completed.stderr)
    return completed.returncode


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {1, 2}:
        _die("usage: kvm_executor.py <config_path> [suite_args_path]")
    config_path = Path(args[0]).resolve()
    if not config_path.is_file():
        _die(f"run config is missing: {config_path}")
    config = read_run_config_file(config_path)
    executor = config.identity.executor
    if executor != "kvm":
        _die(f"run config executor is not kvm: {executor}")
    workspace_root = ROOT_DIR
    suite_args = read_suite_args_file(Path(args[1]).resolve()) if len(args) == 2 else None
    raise SystemExit(run_vm_suite(workspace_root, config, suite_args))


if __name__ == "__main__":
    main()
