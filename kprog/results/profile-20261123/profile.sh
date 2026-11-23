#!/bin/bash
# Profile one application's eBPF and native phases with perf, system-wide, in the frozen entry's guest
# (operator 2026-11-22: "可以 profile 但是不允许做任何设计之外的事情或者细节调优"). The guest command is
# the one `make -n -f kprog/perf/one-image/Makefile corpus APPS=<app> SAMPLES=1 WORKLOAD_DURATION=60
# BPFREJIT_CORPUS_BPF_STATS=0` prints, with the frozen guest target run under `perf record`; the
# entry, the runner and their settings are used as they are. Usage: profile.sh APP OUTDIR
set -u
APP=$1 OUT=$2
R=/workspaces/repository
M=$R/kprog/perf/one-image/Makefile
PERF=/workspaces/.agent-state/kprog-ck/perf-tool/perf
V=/var/tmp/kprog-tmp/one-image/var-tmp
D=${APP%%/*}
install -d $V $OUT
ln -sfn $R/.cache/container-images/x86_64-runner-runtime.image.tar $V/runtime.image.tar
ln -sfn $R/kinsn/module/x86/build/bpf_x86_native_lab.ko $V/bpf_x86_native_lab.ko
make -C $R kvm-host-cpu
G="sysctl -w net.core.bpf_jit_kallsyms=1 >/dev/null; $PERF record -a -F 999 --no-buildid --no-buildid-cache -o /var/tmp/perf.data -- make -f $M guest APPS=$APP SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0 NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/$D/manifest.json BENCH_PASSES= SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE=post; cp /proc/kallsyms /var/tmp/kallsyms.txt"
taskset -c 0-7 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage --cwd $R --rwdir $R \
  --rwdir /var/tmp=$V --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor \
  --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' --exec "$G" > $OUT/guest.log 2>&1
echo "guest rc=$?" >> $OUT/guest.log
mv $V/perf.data $V/kallsyms.txt $OUT/ 2>/dev/null
rm -f $V/bpf-benchmark-docker.img
grep -o '"artifact_run_dir": "[^"]*"' $OUT/guest.log | tail -1 | cut -d'"' -f4 > $OUT/run_dir
