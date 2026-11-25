#!/bin/sh
# After the OTel cache-miss profile: rebuild the arm64 image from the committed tree and run the arm64 functional check.
until test -f /workspaces/kprog-raw/coordinator/profile-20261123/otel-host-cachemiss-20261125.done; do sleep 60; done
cd /workspaces/repository
B=/workspaces/kprog-raw/builds/one-image-arm64-$(date -u +%Y%m%dT%H%MZ)
git rev-parse --short HEAD > $B.before
flock -x /workspaces/.agent-state/kprog-lanes/locks/image make -C kprog/perf/one-image-arm64 image > $B.log 2>&1; echo $? > $B.done
test "$(cat $B.done)" = 0 || exit 1
make -C kprog/perf/one-image-arm64 check > /workspaces/kprog-raw/coordinator/arm64-check-20261125.log 2>&1; echo $? > /workspaces/kprog-raw/coordinator/arm64-check-20261125.done
