#!/bin/bash
# arm64 timing on one DGX Spark under KVM (operator 2026-11-05: "arm 后面可用 spark, 你先把模拟的跑通"; todo item
# "AArch64 硬件性能（DGX Spark，单次测试后立刻恢复 deepseek41-flash 部署）"). The guest root, kernel and module are the
# arm64 entry's (kprog/perf/one-image-arm64) after its QEMU six-app check; the guest script is that entry's with the
# frozen x86 entry defaults: rotate 3 x 180 s per app, breadth first, stats off then on. 4 vCPUs and 8G as the arm64
# entry; the vCPUs run on the Cortex-X925 cluster (CPUs 15-19) so -cpu host sees one core type.
set -u
W=$HOME/kprog-arm64
R=$W/root
LOG=$W/progress.log
ORDER="otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran"
for s in 0 1; do for a in $ORDER; do
  [ -e "$W/STOP" ] && { echo "$(date -u +%FT%TZ) STOP" >> "$LOG"; exit 0; }
  d=${a%%/*}
  sed -e "s#SAMPLES=1 #SAMPLES=3 #; s#WORKLOAD_DURATION=10 #WORKLOAD_DURATION=180 #" \
      -e "s#BPFREJIT_CORPUS_APPS=[^ ]* #BPFREJIT_CORPUS_APPS=$a #; s#BPFREJIT_CORPUS_BPF_STATS=[01] #BPFREJIT_CORPUS_BPF_STATS=$s #" \
      -e "s#native-bpf/arm64/[^/]*/manifest.json#native-bpf/arm64/$d/manifest.json#" \
      -e "s#echo [01] > /proc/sys/kernel/bpf_stats_enabled#echo $s > /proc/sys/kernel/bpf_stats_enabled#" \
      "$W/qemu-run.template" > "$R/qemu-run.sh"
  chmod +x "$R/qemu-run.sh"; : > "$R/qemu-status"
  tag=$(date -u +%Y%m%dT%H%M%SZ)-$(echo "$a" | tr / _)-stats$s
  echo "$(date -u +%FT%TZ) start $a stats=$s" >> "$LOG"
  docker run --rm --name kprog-arm64-timing --cpuset-cpus 15-19 --device /dev/kvm -v "$W:$W" kprog-qemu-arm64:24.04 \
    qemu-system-aarch64 -M virt -accel kvm -cpu host -smp 4 -m 8G -nographic -no-reboot \
    -kernel "$W/Image" \
    -fsdev local,id=rootfs,path="$R",security_model=none,multidevs=remap \
    -device virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root \
    -append 'console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=4 panic=30 oops=panic raid=noautodetect' \
    < /dev/null > "$W/logs/$tag.log" 2>&1
  rc=$(cat "$R/qemu-status" 2>/dev/null)
  run=$(grep -o '"artifact_run_dir": "[^"]*"' "$W/logs/$tag.log" | tail -1 | cut -d'"' -f4)
  echo "$(date -u +%FT%TZ) end $a stats=$s rc=${rc:-none} run=$run" >> "$LOG"
done; done
echo "$(date -u +%FT%TZ) done" >> "$LOG"
