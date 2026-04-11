from __future__ import annotations

import sys
import shlex
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.run_contract import RunConfig, read_run_config_file
from runner.libs.vm import run_in_vm, write_guest_script

_die = partial(fail, "kvm-executor")


def suite_command(workspace_root: Path, config: RunConfig) -> str:
    remote_python = config.remote.python_bin.strip()
    if not remote_python:
        _die("run config remote python is empty")
    return (
        f'cd "{workspace_root}" && '
        f'PYTHONPATH="{workspace_root}${{PYTHONPATH:+:${{PYTHONPATH}}}}" '
        f'"{remote_python}" -m runner.libs.suite_entrypoint '
        f'"{workspace_root}" --config-json {shlex.quote(config.to_json_text())}'
    )


def _optional_int(value: str) -> int | None:
    if not value.strip():
        return None
    return int(value)


def run_vm_suite(workspace_root: Path, config: RunConfig) -> int:
    guest_script = write_guest_script(
        [suite_command(workspace_root, config)],
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
    if len(args) != 1:
        _die("usage: kvm_executor.py <config_path>")
    config_path = Path(args[0]).resolve()
    if not config_path.is_file():
        _die(f"run config is missing: {config_path}")
    config = read_run_config_file(config_path)
    executor = config.identity.executor
    if executor != "kvm":
        _die(f"run config executor is not kvm: {executor}")
    workspace_root = ROOT_DIR
    raise SystemExit(run_vm_suite(workspace_root, config))


if __name__ == "__main__":
    main()
