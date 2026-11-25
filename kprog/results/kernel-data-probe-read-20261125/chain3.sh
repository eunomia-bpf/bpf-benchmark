#!/bin/sh
# After the 12:31Z eviction: rebuild the image and the verified loader from the committed tree, then rerun the Cilium, Tetragon and Tracee checked corpus.
set -u
cd /workspaces/repository
B=/workspaces/kprog-raw/builds/one-image-$(date -u +%Y%m%dT%H%MZ)
git rev-parse --short HEAD > $B.before
flock -x /workspaces/.agent-state/kprog-lanes/locks/image make -C kprog/perf/one-image image > $B.log 2>&1; echo $? > $B.done
test "$(cat $B.done)" = 0 || exit 1
cmake --build /workspaces/.agent-state/kprog-ck/verified-loader --target trusted-native-loader native_loader native_loader_shared -j 8 > /workspaces/kprog-raw/coordinator/ksym-loader.log 2>&1 || exit 1
O=/workspaces/kprog-raw/verified/checked-corpus-20261125-kdata3
make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='cilium/agent tetragon/observer tracee/monitor' CHECKED_OUTPUT=$O > $O.make.log 2>&1; echo $? > $O.done
