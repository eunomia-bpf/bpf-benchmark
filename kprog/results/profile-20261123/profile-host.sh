#!/bin/bash
# profile.sh with perf on the host: the guest's cpu-clock samples miss programs that run with interrupts
# off (OTel's perf-event unwinders), so the host samples the guest with the PMU (cpu_core cycles, guest
# mode, CPUs 0-7 where the guest runs) while the frozen guest target runs as in profile.sh. perf itself
# runs on CPUs 8-23. The guest lists the BPF programs in kallsyms every 30 s, so both phases resolve to
# their own programs; each phase's window is the time span of the samples in its own programs
# (host-phases.py). Holds the timing lock for the whole run.
# Usage: profile-host.sh APP OUTDIR
set -u
APP=$1 OUT=$2
R=/workspaces/repository
M=$R/kprog/perf/one-image/Makefile
PERF=/workspaces/.agent-state/kprog-ck/perf-tool/perf
V=/var/tmp/kprog-tmp/one-image/var-tmp
L=/workspaces/.agent-state/kprog-lanes/locks
D=${APP%%/*}
install -d $V $OUT
ln -sfn $R/.cache/container-images/x86_64-runner-runtime.image.tar $V/runtime.image.tar
ln -sfn $R/kinsn/module/x86/build/bpf_x86_native_lab.ko $V/bpf_x86_native_lab.ko
rm -f $V/kallsyms*.txt $V/clock.txt $V/modules.txt
G="sysctl -w net.core.bpf_jit_kallsyms=1 >/dev/null; echo \$(date +%s.%N) \$(cut -d' ' -f1 /proc/uptime) > /var/tmp/clock.txt; cp /proc/kallsyms /var/tmp/kallsyms.txt; (while true; do grep bpf_prog_ /proc/kallsyms > /var/tmp/kallsyms-bpf-\$(cut -d' ' -f1 /proc/uptime).txt; cp /proc/modules /var/tmp/modules.txt; sleep 30; done) & make -f $M guest APPS=$APP SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0 NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/$D/manifest.json BENCH_PASSES= SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE=post"
exec 9>$L/timing; flock 9
make -C $R kvm-host-cpu
(taskset -c 8-23 $PERF kvm --guest record -a -C 0-7 -e cpu_core/cycles/ -F 1999 \
   -o $OUT/host-perf.data -- sleep 600 > $OUT/perf.log 2>&1) &
P=$!
timeout 900 taskset -c 0-7 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage --cwd $R --rwdir $R \
  --rwdir /var/tmp=$V --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor \
  --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' --exec "$G" > $OUT/guest.log 2>&1
echo "guest rc=$? end $(date +%s.%N)" >> $OUT/guest.log
kill -INT $(pgrep -P $P) 2>/dev/null; wait $P
mv $V/kallsyms*.txt $V/clock.txt $V/modules.txt $OUT/ 2>/dev/null
rm -f $V/bpf-benchmark-docker.img
grep -o '"artifact_run_dir": "[^"]*"' $OUT/guest.log | tail -1 | cut -d'"' -f4 > $OUT/run_dir
