sysctl -w net.core.bpf_jit_kallsyms=1 >/dev/null
dmesg > /var/tmp/dmesg-before.txt
echo $(date +%s.%N) $(cut -d' ' -f1 /proc/uptime) > /var/tmp/clock.txt
cp /proc/kallsyms /var/tmp/kallsyms.txt
mkdir -p /var/tmp/linkcache /var/tmp/map-observe
last_stress_pid=
(while true; do
  u=$(cut -d' ' -f1 /proc/uptime)
  stress_pid=$(pgrep -xo stress-ng)
  stress_rc=$?
  printf '%s poll_rc=%s pid=%s\n' "$u" "$stress_rc" "$stress_pid" >> /var/tmp/stack-requests.txt
  if [ "$stress_rc" = 0 ] && [ "$stress_pid" != "$last_stress_pid" ]; then
    sleep 1
    request_u=$(cut -d' ' -f1 /proc/uptime)
    printf '<6>profile CPU snapshot stress_pid=%s uptime=%s\n' "$stress_pid" "$u" > /dev/kmsg
    echo l > /proc/sysrq-trigger
    request_rc=$?
    end_u=$(cut -d' ' -f1 /proc/uptime)
    printf '%s end=%s request_rc=%s\n' "$request_u" "$end_u" "$request_rc" >> /var/tmp/stack-requests.txt
    last_stress_pid=$stress_pid
  fi
  sleep 1
done) &
(while true; do
  u=$(cut -d' ' -f1 /proc/uptime)
  awk '$2 ~ /^[tTwW]$/ && ($3 ~ /^bpf_prog_/ || $NF == "[bpf_x86_native_lab]")' /proc/kallsyms > /var/tmp/kallsyms-bpf-$u.txt
  cp /proc/modules /var/tmp/modules.txt
  for c in $(docker ps -q 2>/dev/null); do
    p=$(docker inspect -f '{{.State.Pid}}' $c)
    nsenter -t $p -m -- tar -C /tmp -cf - native_kernel_link_cache 2>/dev/null | tar -C /var/tmp/linkcache -xf - 2>/dev/null
  done
  if [ -n "perf_unwind_nat" ]; then python3 /workspaces/repository/kprog/results/profile-20261123/dump-prog.py perf_unwind_nat /var/tmp/progdump/$u > /dev/null 2>&1; fi
  python3 /workspaces/repository/kprog/results/x86-otel-perf-20261127/observe_otel_maps.py /var/tmp/map-observe/$u > /var/tmp/map-observe/$u.log 2>&1
  sleep 2
done) &
make -f /workspaces/repository/kprog/perf/one-image/Makefile guest APPS=otelcol-ebpf-profiler/profiling SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1 NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json BENCH_PASSES= SKIP_REJIT_MODE=norejit NATIVE_LOADER_MODE=post
guest_result=$?
dmesg > /var/tmp/dmesg-after.txt
exit $guest_result
