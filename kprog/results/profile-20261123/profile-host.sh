#!/bin/bash
# profile.sh with perf on the host: the guest's cpu-clock samples miss programs that run with interrupts
# off (OTel's perf-event unwinders), so the host samples the guest with the PMU (cpu_core cycles, guest
# mode, CPUs 0-7 where the guest runs) while the frozen guest target runs as in profile.sh. perf itself
# runs on CPUs 8-23. The 32 GiB guest lists BPF and native-lab module text every 30 s, so each phase resolves to
# its own programs (host-phases.py, host-annotate.py). Holds the timing lock for the whole run.
# The loader keeps each linked native program (plan, blob, relocations) in the runtime container's
# /tmp/native_kernel_link_cache; the loop copies it out through the container's mount namespace, so the
# native code the samples land in can be disassembled. With a third argument (a program name as the
# kernel keeps it, 15 characters), the loop also writes every program of that name, eBPF and native:
# verifier-rewritten instructions, JITed code and function addresses (dump-prog.py; bpftool from the image
# wrote nothing for the eBPF ones, 2026-11-23T16:17Z). The guest command goes through a file on the
# shared /var/tmp (2026-11-23T15:58Z: a longer --exec string left the guest without a command).
# EVENT in the environment samples that guest-mode PMU event every PERIOD (default 2000) events instead
# of cycles at 1999 Hz.
# Usage: profile-host.sh APP OUTDIR [PROG_NAME]
set -u
APP=$1 OUT=$2 XLATED=${3:-}
R=/workspaces/repository
M=$R/kprog/perf/one-image/Makefile
PERF=/workspaces/.agent-state/kprog-ck/perf-tool/perf
V=/var/tmp/kprog-tmp/one-image/var-tmp
L=/workspaces/.agent-state/kprog-lanes/locks
D=${APP%%/*}
exec 9>$L/timing; flock 9
exec 8>$L/image; flock -s 8
install -d $V $OUT
ln -sfn $R/.cache/container-images/x86_64-runner-runtime.image.tar $V/runtime.image.tar
ln -sfn $R/kinsn/module/x86/build/bpf_x86_native_lab.ko $V/bpf_x86_native_lab.ko
install -d $OUT/prior-staging
for f in $V/kallsyms*.txt $V/clock.txt $V/modules.txt $V/linkcache $V/progdump $V/guest.sh; do
  if [ -e "$f" ]; then mv "$f" "$OUT/prior-staging/"; fi
done
python3 -c 'import time; print(time.time()-time.clock_gettime(time.CLOCK_MONOTONIC))' > $OUT/host-rt-minus-uptime.txt
cat > $V/guest.sh <<EOF
sysctl -w net.core.bpf_jit_kallsyms=1 >/dev/null
echo \$(date +%s.%N) \$(cut -d' ' -f1 /proc/uptime) > /var/tmp/clock.txt
cp /proc/kallsyms /var/tmp/kallsyms.txt
mkdir -p /var/tmp/linkcache
(while true; do
  u=\$(cut -d' ' -f1 /proc/uptime)
  awk '\$2 ~ /^[tTwW]$/ && (\$3 ~ /^bpf_prog_/ || \$NF == "[bpf_x86_native_lab]")' /proc/kallsyms > /var/tmp/kallsyms-bpf-\$u.txt
  cp /proc/modules /var/tmp/modules.txt
  for c in \$(docker ps -q 2>/dev/null); do
    p=\$(docker inspect -f '{{.State.Pid}}' \$c)
    nsenter -t \$p -m -- tar -C /tmp -cf - native_kernel_link_cache 2>/dev/null | tar -C /var/tmp/linkcache -xf - 2>/dev/null
  done
  if [ -n "$XLATED" ]; then python3 $R/kprog/results/profile-20261123/dump-prog.py $XLATED /var/tmp/progdump/\$u > /dev/null 2>&1; fi
  sleep 30
done) &
make -f $M guest APPS=$APP SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0 NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/$D/manifest.json BENCH_PASSES= SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE=post
EOF
make -C $R kvm-host-cpu
if [ -n "${EVENT:-}" ]; then SAMPLING="-e $EVENT -c ${PERIOD:-2000}"; else SAMPLING="-e cpu_core/cycles/ -F 1999"; fi
taskset -c 8-23 $PERF kvm --guest record -g -a -C 0-7 $SAMPLING \
   -o $OUT/host-perf.data -- sleep 600 > $OUT/perf.log 2>&1 &
P=$!
timeout 900 taskset -c 0-7 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage --cwd $R --rwdir $R \
  --rwdir /var/tmp=$V --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor \
  --cpus 8 --memory 32G --append 'loglevel=4 panic=30 oops=panic' --exec "bash /var/tmp/guest.sh" > $OUT/guest.log 2>&1
guest_rc=$?
echo "guest rc=$guest_rc end $(date +%s.%N)" >> $OUT/guest.log
stop_requested=0
if kill -0 $P 2>/dev/null; then
  stop_requested=1
  printf 'SIGINT after guest completion\n' > $OUT/perf-stop-requested.txt
  kill -INT $P
fi
wait $P; perf_rc=$?
printf '%s\n' "$guest_rc" > $OUT/guest-exit.txt
printf '%s\n' "$perf_rc" > $OUT/perf-exit.txt
for f in $V/kallsyms*.txt $V/clock.txt $V/modules.txt $V/linkcache $V/progdump $V/guest.sh; do
  if [ -e "$f" ]; then mv "$f" "$OUT/"; fi
done
rm -f $V/bpf-benchmark-docker.img
grep -o '"artifact_run_dir": "[^"]*"' $OUT/guest.log | tail -1 | cut -d'"' -f4 > $OUT/run_dir
if [ "$guest_rc" != 0 ]; then exit "$guest_rc"; fi
if [ "$perf_rc" = 0 ]; then exit 0; fi
# perf forwards the requested stop to its sleep workload; that child can return SIGTERM (143).
if [ "$stop_requested" = 1 ] && { [ "$perf_rc" = 130 ] || [ "$perf_rc" = 143 ]; }; then exit 0; fi
exit "$perf_rc"
