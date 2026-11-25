#!/bin/sh
# Pack the stopped CL lane's raw scratch (lane stopped 2026-11-11) into one zstd archive; originals go only after a full listing matches.
set -e
cd /workspaces/kprog-raw/var-tmp
n=$(find CL -type f | wc -l)
tar -cf - CL | nice -n 15 zstd -T6 -6 -q -o CL.tar.zst
m=$(zstd -dc CL.tar.zst | tar -tf - | grep -vc '/$')
if [ "$m" -eq "$n" ]; then
  rm -rf CL
  printf '%s\n' "CL.tar.zst holds the CL lane's raw scratch (files $n), packed by the coordinator on 2026-11-25 with /workspaces at 97%. Restore: zstd -dc CL.tar.zst | tar -xf -" > CL.README.txt
  echo "ok $n" > /workspaces/kprog-raw/coordinator/pack-var-tmp-CL-20261125.done
else
  echo "mismatch $n $m" > /workspaces/kprog-raw/coordinator/pack-var-tmp-CL-20261125.done
fi
