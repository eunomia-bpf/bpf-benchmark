#!/bin/sh
# After the running BCC/Katran checked corpus exits, run Cilium, Tetragon and Tracee on the current tree.
O=/workspaces/kprog-raw/verified/checked-corpus-20261125-kdata
while pgrep -f 'CHECKED_OUTPUT=/workspaces/kprog-raw/verified/checked-corpus-20261125-ktime2' > /dev/null; do sleep 30; done
cd /workspaces/repository
make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='cilium/agent tetragon/observer tracee/monitor' CHECKED_OUTPUT=$O > $O.make.log 2>&1
echo $? > $O.done
