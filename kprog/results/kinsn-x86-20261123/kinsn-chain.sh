#!/bin/bash
# kinsn on x86 (operator 2026-11-23: "kinsn 的也跑一下?", "唯一内核、唯一镜像 可以保留一个 kinsn 的也保留一个 kprog 的"):
# its one kernel (the kinsn line 24cd6e63ce91 from the submodule history, exported once), its kinsn modules and
# its one runtime image, all built by the frozen recipe targets at kinsn's own locations; then the frozen
# kinsn corpus command (kinsn/docs/evaluation.md): a six-app function check, then the full run, breadth first.
D=/workspaces/kprog-raw/coordinator/kinsn-20261123
K=/workspaces/.agent-state/kinsn-ck
R=/workspaces/repository
L=/workspaces/.agent-state/kprog-lanes/locks
O=$D/chain.done
APPS="otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran"
mkdir -p $D $K
cd $R
if [ ! -f $K/src/Makefile ]; then
  mkdir -p $K/src
  git -C vendor/linux-framework archive 24cd6e63ce91 | tar -x -C $K/src
fi
echo "src $(date -u +%FT%TZ) $(du -sh $K/src | cut -f1) from 24cd6e63ce91" > $O
V="KERNEL_DIR=$K/src HOST_KERNEL_BUILD_DIR_X86=$K/build-x86 X86_RUNTIME_KERNEL_IMAGE=$K/build-x86/arch/x86/boot/bzImage HOST_KINSN_DIR_X86=$K/kinsn-x86 X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/kinsn:current X86_RUNNER_RUNTIME_IMAGE_TAR=$R/.cache/container-images/x86_64-kinsn-runtime.image.tar"
s=$(date -u +%FT%TZ)
nice -n 5 taskset -c 8-23 make -C $R host-kinsn-x86 $V IMAGE_BUILD_JOBS=16 > $D/kernel.log 2>&1; rc=$?
echo "kernel+kinsn modules start $s end $(date -u +%FT%TZ) rc=$rc modules=$(ls $K/kinsn-x86/*.ko 2>/dev/null | wc -l)" >> $O
[ $rc = 0 ] || exit 0
s=$(date -u +%FT%TZ)
flock $L/image nice -n 5 taskset -c 8-23 make -C $R x86-runner-runtime-image-tar $V IMAGE_BUILD_JOBS=16 JOBS=16 > $D/image.log 2>&1; rc=$?
echo "image start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
run() { # app stats samples duration tag
  local log=$D/$(date -u +%Y%m%dT%H%M%SZ)-$(echo $1 | tr / _)-$5.log
  flock $L/timing taskset -c 0-7 make -C $R corpus PLATFORM=kvm ARCH=x86 $V BPFREJIT_BENCH_PASSES=kinsn \
    BPFREJIT_CORPUS_APPS=$1 BPFREJIT_CORPUS_BPF_STATS=$2 SAMPLES=$3 WORKLOAD_DURATION=$4 WARMUPS=1 \
    BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 > $log 2>&1
  local rc=$?
  echo "$(date -u +%FT%TZ) $5 $1 stats=$2 rc=$rc run=$(grep -o '"artifact_run_dir": "[^"]*"' $log | tail -1 | cut -d'"' -f4)" >> $D/progress.log
  return $rc
}
fail=0
for a in $APPS; do run $a 1 1 10 check || fail=1; done
echo "check end $(date -u +%FT%TZ) fail=$fail" >> $O
[ $fail = 0 ] || exit 0
for s in 0 1; do for a in $APPS; do run $a $s 3 180 timing; done; done
echo "end $(date -u +%FT%TZ)" >> $O
