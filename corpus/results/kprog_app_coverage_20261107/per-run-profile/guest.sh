#!/bin/bash
set -euo pipefail
cd /workspaces/repository
export BPFREJIT_VM_DOCKER_DISK_SIZE=12G
make __runtime-vm-docker
image=${2:-bpf-benchmark/kprog-map-capture:c-20261107}
image_tar=${3:-/workspaces/.agent-state/kprog-lanes/C/map-capture-runtime.image.tar}
runner/scripts/bpfrejit-install --image "$image" "$image_tar"
docker run --rm --privileged --pid=host --network=host --ipc=host --cgroupns=host -e HOME=/root -e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 -e RUN_TARGET_ARCH=x86_64 -e BPFREJIT_KERNEL_MODULES_ROOT=/artifacts -e BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/x86_64 -v /sys:/sys -v /sys/fs/bpf:/sys/fs/bpf -v /sys/kernel/debug:/sys/kernel/debug -v /lib/modules:/lib/modules:ro -v /boot:/boot:ro -v /workspaces/repository:/workspaces/repository -w /workspaces/repository "$image" python3 corpus/results/kprog_app_coverage_20261107/per-run-profile/guest.py "$1"
