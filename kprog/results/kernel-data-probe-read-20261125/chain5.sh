#!/bin/sh
# After the 14:26Z OOM restart: rebuild the verified loader from HEAD (2d308a86f's ksym binding), then the Cilium, Tetragon and Tracee checked corpus.
cd /workspaces/repository
cmake --build /workspaces/.agent-state/kprog-ck/verified-loader --target trusted-native-loader native_loader native_loader_shared -j 8 > /workspaces/kprog-raw/coordinator/ksym-loader.log 2>&1 || exit 1
O=/workspaces/kprog-raw/verified/checked-corpus-20261125-kdata4
make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='cilium/agent tetragon/observer tracee/monitor' CHECKED_OUTPUT=$O > $O.make.log 2>&1; echo $? > $O.done
