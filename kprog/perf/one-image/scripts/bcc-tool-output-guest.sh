#!/bin/bash
# Guest side of the bcc/set tool-output comparison: bring up the guest's docker
# from the one image, then run the eight tools in the runtime container once per
# arm. Mirrors `make -f kprog/perf/one-image/Makefile guest` for the parts a
# comparison needs (kernel module, debugfs, image load) and nothing else.
#
# Usage: bcc-tool-output-guest.sh <out-dir> [seconds]
set -euo pipefail

OUT=${1:?output directory}
SECONDS_N=${2:-20}
ROOT=/workspaces/repository
HERE=$ROOT/kprog/perf/one-image/scripts
IMAGE=bpf-benchmark/kprog:current
IMAGE_TAR=/var/tmp/runtime.image.tar
install -d "$OUT"
# vng does not always reach a tty (its own warning: "stderr may be lost"), and
# this guest is one command with no fallback, so keep the whole trace on the
# mounted output directory.
exec > >(tee -a "$OUT/guest.log") 2>&1
# The runtime container carries the image's own copy of the repository, which
# predates this script; run the script itself from the mounted output directory.
install -m755 "$HERE/bcc-tool-output-inner.sh" "$OUT/bcc-tool-output-inner.sh"

mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
insmod /var/tmp/bpf_x86_native_lab.ko

# The guest's docker disk and daemon, exactly as __runtime-vm-docker builds them.
make -C "$ROOT" __runtime-vm-docker
"$ROOT/runner/scripts/bpfrejit-install" --image "$IMAGE" "$IMAGE_TAR"

for arm in baseline post; do
  # RUNTIME_DOCKER in the root Makefile:196-198, with the output directory
  # mounted so the container's own filesystem stays disposable.
  docker run --rm --privileged --pid=host --network=host --ipc=host --cgroupns=host \
    -e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 -e HOME=/root \
    -w "$ROOT" \
    -v /sys:/sys -v /sys/fs/bpf:/sys/fs/bpf -v /sys/kernel/debug:/sys/kernel/debug \
    -v /lib/modules:/lib/modules:ro -v /boot:/boot:ro \
    -v "$OUT:$OUT" \
    "$IMAGE" bash "$OUT/bcc-tool-output-inner.sh" "$arm" "$OUT" "$SECONDS_N"
done
echo "=== bcc tool output comparison written under $OUT"
for arm in baseline post; do
  echo "--- $arm"
  for tool in capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat; do
    printf '%-12s %7s out %7s err\n' "$tool" \
      "$(wc -l < "$OUT/$arm/$tool.out")" "$(wc -l < "$OUT/$arm/$tool.err")"
  done
done