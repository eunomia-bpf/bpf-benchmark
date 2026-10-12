#!/bin/bash
# Host launcher for one measurement arm.  It boots the current guest kernel with
# exactly the vng flags of `make micro` (Makefile VNG: --cpus 8 --pin 0-7 --mem 64G,
# same --rwdir/--overlay-rwdir/--append) and runs guest-run.sh, which runs the
# repository's in-guest step `make __runtime-vm-micro` with the RUN_MAKE_VARS
# that `make micro` would pass.  The host-side `make micro` itself is not used
# because its prerequisite runtime-kernel-image -> x86-runner-runtime-image-tar
# is phony and would rebuild and re-save the runtime image.
#
# The whole guest life is held under the shared host lock.
#
# usage: host-run.sh <arm> <premodule_dir|-> <suite yaml basename> [extra suite env assignments, e.g. SAMPLES=4]
set -euo pipefail
ROOT=/home/yunwei37/workspace/bpf-benchmark-rerun-20261009
HERE=$ROOT/micro/results/kinsn_load_time_current_20261011
LOCK=/home/yunwei37/workspace/codex-runs/followup-20261011/host.lock
VNG=/home/yunwei37/.local/bin/vng
export PATH=/home/yunwei37/.local/bin:$PATH
arm=$1; premods=$2; suite=$3; shift 3
out=$HERE/runs/$arm
mkdir -p "$out"
token=$(od -An -N4 -tx4 /dev/urandom | tr -d ' \n')

make_vars=(
    "TARGET=x86-kvm" "RUN_TARGET_NAME=x86-kvm" "RUN_TARGET_ARCH=x86_64" "RUN_EXECUTOR=kvm"
    "RUNTIME_CONTAINER_IMAGE=bpf-benchmark/runner-runtime:x86_64"
    "RUNTIME_IMAGE_TAR=$ROOT/.cache/container-images/x86_64-runner-runtime.image.tar"
    "RUN_REMOTE_PYTHON_BIN=python3" "RUN_RUNTIME_PYTHON_BIN=python3" "RUN_BPFTOOL_BIN=bpftool"
    "RUN_NATIVE_REPOS_CSV=bcc,katran,tracee,tetragon" "RUN_TOKEN=$token"
    "SUITE=micro/results/kinsn_load_time_current_20261011/$suite"
    # The suite always sets BPFREJIT_MICRO_PROGRAM_DIR from MICRO_PROGRAM_DIR (or the image's
    # micro/programs), which overrides the manifest's paths.program_dir; MICRO_PROGRAM_DIR is not
    # in SUITE_ENV_NAMES, so forward it into the runtime container via RUNTIME_ENV_BASE_NAMES.
    "RUNTIME_ENV_BASE_NAMES=TARGET RUN_TARGET_NAME RUN_TOKEN RUN_TARGET_ARCH RUN_EXECUTOR RUN_REMOTE_PYTHON_BIN RUN_RUNTIME_PYTHON_BIN RUN_BPFTOOL_BIN RUN_NATIVE_REPOS_CSV MICRO_PROGRAM_DIR"
    "MICRO_PROGRAM_DIR=$HERE/programs"
    "$@"
)

{
    echo "arm=$arm premods=$premods token=$token start=$(date -u +%FT%TZ)"
    echo "kernel=$(sha256sum "$ROOT/vendor/build/x86/linux/arch/x86/boot/bzImage")"
    echo "image_tar=$(stat -c '%s %y' "$ROOT/.cache/container-images/x86_64-runner-runtime.image.tar")"
    echo "clone_head=$(git -C "$ROOT" rev-parse HEAD)"
    printf 'make_var %s\n' "${make_vars[@]}"
} > "$out/host-run.txt"

echo "$premods" > "$out/premods"
printf '%s\n' "${make_vars[@]}" > "$out/make-vars"
guest_cmd="bash $HERE/guest-run.sh $out"
echo "guest_cmd=$guest_cmd" >> "$out/host-run.txt"

set +e
# Inside the lock: refuse to start if any other guest is running (e.g. one started outside the lock).
flock "$LOCK" bash -c 'if pgrep -f "[q]emu-system" >/dev/null; then pgrep -af "[q]emu-system"; echo "foreign guest running; not starting"; exit 75; fi; exec "$@"' guard \
    "$VNG" --run "$ROOT/vendor/build/x86/linux/arch/x86/boot/bzImage" --cwd "$ROOT" \
    --disable-monitor --verbose --cpus 8 --pin 0-7 --mem 64G \
    --rwdir "$ROOT" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" \
    --exec "$guest_cmd" > "$out/vng.log" 2>&1
rc=$?
set -e
echo "vng_rc=$rc end=$(date -u +%FT%TZ)" >> "$out/host-run.txt"
echo "rc=$rc" > "$out/host-rc.txt"
