from __future__ import annotations

import sys
import shlex
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.run_contract import RunConfig, build_run_config
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
docker_disk="${BPFREJIT_VM_DOCKER_DISK:-/var/tmp/bpf-benchmark-docker.img}"
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
        mount -o loop,discard "$docker_disk" "$docker_root"
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
    result_dirs = [
        str(path)
        for path in runtime_container_host_dirs(
            workspace_root,
            config.identity.suite_name,
            die=_die,
        )
    ]
    mkdir_cmd = shlex.join(["mkdir", "-p", *result_dirs])
    container_cmd = _shell_join(
        build_runtime_container_command(
            workspace_root,
            config,
            suite_args,
            die=_die,
        )
    )
    install_cmd = _shell_join([
        workspace_root / "runner" / "scripts" / "bpfrejit-install",
        "--image", config.remote.runtime_container_image,
        str(image_tar),
    ])
    post_container_cmd = ""
    if config.identity.suite_name == "micro":
        post_container_cmd = """ && bash -lc '
latest_compare_dir="$(find micro/results -path "*/details/code_compare" -type d -printf "%T@ %p\\n" | sort -nr | awk "NR == 1 { print \\$2; exit }")"
if [ -n "$latest_compare_dir" ]; then
    mkdir -p micro/programs
    cp "$latest_compare_dir"/*.md micro/programs/
    rm -rf "$latest_compare_dir"
fi
'"""
    docker_prelude = _docker_prelude_shell()
    return f"{mkdir_cmd} && (\n{docker_prelude}\n{install_cmd} && {container_cmd}{post_container_cmd}\n)"


def _optional_int(value: str) -> int | None:
    if not value.strip():
        return None
    return int(value)


def run_vm_suite(workspace_root: Path, config: RunConfig, suite_args: list[str] | None = None) -> int:
    effective_suite_args = list(suite_args) if suite_args is not None else []
    guest_script = write_guest_script(
        [suite_command(workspace_root, config, effective_suite_args)],
        initial_cwd=ROOT_DIR,
    )
    completed = run_in_vm(
        config.kvm.kernel_image,
        guest_script,
        _optional_int(config.kvm.cpus),
        config.kvm.mem or None,
        _optional_int(config.kvm.timeout_seconds),
        cwd=ROOT_DIR,
        rwdirs=(ROOT_DIR,),
        vm_executable=config.kvm.executable,
        machine_backend=config.kvm.backend,
        stream_output=True,
    )
    if completed.stdout:
        sys.stdout.write(completed.stdout)
    if completed.stderr:
        sys.stderr.write(completed.stderr)
    return completed.returncode


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) < 2:
        _die("usage: kvm_executor.py <target> <suite> [suite_args...]")
    target_name, suite_name = args[0], args[1]
    config = build_run_config(target_name, suite_name)
    if config.identity.executor != "kvm":
        _die(f"target {target_name} executor is not kvm: {config.identity.executor}")
    raise SystemExit(run_vm_suite(ROOT_DIR, config, args[2:]))


if __name__ == "__main__":
    main()
