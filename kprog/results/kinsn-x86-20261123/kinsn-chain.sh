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
# kinsn/module/x86 also holds kprog's bpf_x86_native_lab.c, which reads the kprog kernel's bpf_prog_aux
# fields (native_trusted_*), absent from the kinsn kernel (2026-11-23T13:40Z build: rc=2 on that file
# alone). The kinsn kernel takes the fourteen kinsn modules of that directory: the recipe's own kbuild
# command (runner/mk/build.mk host-kinsn-x86) with obj-m naming them, and the image target treats
# host-kinsn-x86 as made (-o).
KINSN_MODS=$(grep 'obj-m' $R/kinsn/module/x86/Makefile | sed 's/.*+= //' | grep -v native_lab | tr '\n' ' ')
s=$(date -u +%FT%TZ)
nice -n 5 taskset -c 8-23 make -C $R host-kernel-x86 $V IMAGE_BUILD_JOBS=16 > $D/kernel.log 2>&1; rc=$?
echo "kernel start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
s=$(date -u +%FT%TZ)
install -d $K/kinsn-x86
nice -n 5 taskset -c 8-23 make -C $K/build-x86 ARCH=x86_64 M=$R/kinsn/module/x86 MO=$K/kinsn-x86 modules -j16 "obj-m=$KINSN_MODS" > $D/modules.log 2>&1; rc=$?
echo "kinsn modules start $s end $(date -u +%FT%TZ) rc=$rc modules=$(ls $K/kinsn-x86/*.ko 2>/dev/null | wc -l)" >> $O
[ $rc = 0 ] || exit 0
# The image's kernel-dependent parts (micro programs with kernel_offsets.h, stage2 programs, the sim
# proofs under stage2) are built against the kinsn kernel in kinsn's own directories; kprog's copies
# under micro/programs/build-x86 are frozen (immutable, 2026-11-23T13:56Z: "Operation not permitted").
# The kernel-independent parts are kprog's builds as they are (-o: daemon, shim, app sources, runner,
# bpfopt LLVM, native objects), so no shared build directory is written.
# `make corpus` takes the image's prerequisites again (2026-11-23T14:12Z check: rc=2 in host-kinsn-x86),
# so every kinsn make below carries the same -o list and directories.
KO="-o host-kinsn-x86 -o host-rust-x86 -o host-shim-x86 -o host-source-apps-x86 -o host-runner-x86 -o host-bpfopt-llvm-x86 -o host-native-bpf-x86"
KV="MICRO_PROGRAM_BUILD_X86=$K/micro-programs-x86 STAGE2_PROGRAM_BUILD_X86=$K/stage2-programs-x86"
s=$(date -u +%FT%TZ)
flock $L/image nice -n 5 taskset -c 8-23 make -C $R $KO x86-runner-runtime-image-tar $V $KV \
  IMAGE_BUILD_JOBS=16 JOBS=16 > $D/image.log 2>&1; rc=$?
echo "image start $s end $(date -u +%FT%TZ) rc=$rc" >> $O
[ $rc = 0 ] || exit 0
# The frozen framework (runner/ as of 2026-05-29, 24a2d15aa) has no `kinsn` umbrella pass
# (runner/config/passes/kinsn/default.yaml is absent: 2026-11-23T14:33Z runs ended in status error);
# its kinsn group without prefetch is `kinsn-5` (corpus/config/benchmark_config.yaml), the x86 default
# that kinsn/docs/evaluation.md describes ("on x86, prefetch is disabled in the default kinsn command").
run() { # app stats samples duration tag
  local log=$D/$(date -u +%Y%m%dT%H%M%SZ)-$(echo $1 | tr / _)-$5.log
  flock $L/timing taskset -c 0-7 make -C $R $KO corpus PLATFORM=kvm ARCH=x86 $V $KV BPFREJIT_BENCH_PASSES=kinsn-5 \
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
