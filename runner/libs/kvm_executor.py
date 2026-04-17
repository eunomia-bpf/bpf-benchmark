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
    runtime_container_host_dirs,
)
from runner.libs.workspace_layout import runtime_container_image_tar_path
from runner.libs.vm import run_in_vm, write_guest_script

_die = partial(fail, "kvm-executor")


def _shell_join(command: list[str]) -> str:
    return " ".join(shlex.quote(str(part)) for part in command)


def _docker_prelude_shell() -> str:
    return """
docker_started=0
docker_root="${BPFREJIT_VM_DOCKER_ROOT:-/run/bpf-benchmark-docker}"
docker_disk="${BPFREJIT_VM_DOCKER_DISK:-${TMPDIR:-/tmp}/bpf-benchmark-docker.img}"
docker_disk_size="${BPFREJIT_VM_DOCKER_DISK_SIZE:-64G}"
if [ "$docker_disk" = "none" ]; then
    docker_disk=""
fi
cleanup_bpf_benchmark_docker() {
    if [ "$docker_started" = 1 ]; then
        if [ -f "$docker_root/docker.pid" ]; then
            kill "$(cat "$docker_root/docker.pid")" 2>/dev/null || true
        fi
        for _ in $(seq 1 20); do
            if ! docker info >/dev/null 2>&1; then
                break
            fi
            sleep 1
        done
        if [ -n "$docker_disk" ]; then
            umount "$docker_root" 2>/dev/null || umount -l "$docker_root" 2>/dev/null || true
            rm -f "$docker_disk"
        fi
    fi
}
trap cleanup_bpf_benchmark_docker EXIT
if ! docker info >/dev/null 2>&1; then
    rm -rf "$docker_root"
    mkdir -p "$docker_root"
    if [ -n "$docker_disk" ]; then
        mkdir -p "$(dirname "$docker_disk")"
        rm -f "$docker_disk"
        truncate -s "$docker_disk_size" "$docker_disk"
        mkfs.ext4 -F -q "$docker_disk"
        mount -o loop "$docker_disk" "$docker_root"
    fi
    mkdir -p "$docker_root/data" "$docker_root/exec"
    dockerd \\
        --data-root "$docker_root/data" \\
        --exec-root "$docker_root/exec" \\
        --pidfile "$docker_root/docker.pid" \\
        --host unix:///run/docker.sock \\
        --bridge=none \\
        --iptables=false \\
        --ip-masq=false \\
        --ip-forward=false \\
        >"$docker_root/dockerd.log" 2>&1 &
    docker_started=1
    for _ in $(seq 1 60); do
        if docker info >/dev/null 2>&1; then
            break
        fi
        sleep 1
    done
fi
if ! docker info >/dev/null; then
    tail -100 "$docker_root/dockerd.log" 2>/dev/null || true
    exit 1
fi
"""


def suite_command(workspace_root: Path, config: RunConfig, suite_args: list[str]) -> str:
    if not config.remote.runtime_container_image.strip():
        _die("run config RUN_RUNTIME_CONTAINER_IMAGE is empty")
    image_tar = runtime_container_image_tar_path(workspace_root, config.identity.target_arch)
    result_dirs = [str(path) for path in runtime_container_host_dirs(workspace_root)]
    mkdir_cmd = shlex.join(["mkdir", "-p", *result_dirs])
    container_cmd = _shell_join(build_runtime_container_command(workspace_root, config, suite_args, die=_die))
    install_cmd = _shell_join([
        workspace_root / "runner" / "scripts" / "bpfrejit-install",
        "--image", config.remote.runtime_container_image,
        str(image_tar),
    ])
    docker_prelude = _docker_prelude_shell()
    return f"{mkdir_cmd} && (\n{docker_prelude}\n{install_cmd} && {container_cmd}\n)"


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
