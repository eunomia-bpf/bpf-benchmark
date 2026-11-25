#!/bin/sh
# Rebuild the one image from the committed tree, check Katran on it, then rerun the Cilium, Tetragon and Tracee checked corpus.
set -u
B=/workspaces/kprog-raw/builds/one-image-$(date -u +%Y%m%dT%H%MZ)
cd /workspaces/repository
git rev-parse --short HEAD > $B.before
flock -x /workspaces/.agent-state/kprog-lanes/locks/image make -C kprog/perf/one-image image > $B.log 2>&1; echo $? > $B.done
test "$(cat $B.done)" = 0 || exit 1
make -C kprog/perf/one-image check APPS=katran > /workspaces/kprog-raw/coordinator/aom-katran-check.log 2>&1; echo $? > /workspaces/kprog-raw/coordinator/aom-katran-check.done
O=/workspaces/kprog-raw/verified/checked-corpus-20261125-kdata2
make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='cilium/agent tetragon/observer tracee/monitor' CHECKED_OUTPUT=$O > $O.make.log 2>&1; echo $? > $O.done
