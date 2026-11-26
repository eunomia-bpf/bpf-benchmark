#!/bin/sh
# arm64 run 8, step 1: rebuild the arm64 image from the committed tree (key-size C hash routines for every key size
# 1-512, 42cd0d591; x86 six-app check passed on 7a11cb60285a, 4ce03654f), then the QEMU six-app functional check.
# The Spark timing (kprog/perf/one-image-arm64/spark-rotate.sh) follows after this check passes.
cd /workspaces/repository
O=/workspaces/kprog-raw/coordinator/arm64-run8-20261126
mkdir -p $O
git rev-parse --short HEAD > $O/image.before
flock -x /workspaces/.agent-state/kprog-lanes/locks/image make -C kprog/perf/one-image-arm64 image > $O/image.log 2>&1; echo $? > $O/image.done
test "$(cat $O/image.done)" = 0 || exit 1
make -C kprog/perf/one-image-arm64 check > $O/check.log 2>&1; echo $? > $O/check.done
