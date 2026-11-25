#!/bin/sh
# After the kdata3 checked corpus finishes, rebuild the verified loader and rerun Cilium.
until test -f /workspaces/kprog-raw/verified/checked-corpus-20261125-kdata3.done; do sleep 60; done
cd /workspaces/repository
cmake --build /workspaces/.agent-state/kprog-ck/verified-loader --target trusted-native-loader native_loader native_loader_shared -j 8 > /workspaces/kprog-raw/coordinator/ksym-loader.log 2>&1 || exit 1
O=/workspaces/kprog-raw/verified/checked-corpus-20261125-kdata4
make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='cilium/agent' CHECKED_OUTPUT=$O > $O.make.log 2>&1; echo $? > $O.done
