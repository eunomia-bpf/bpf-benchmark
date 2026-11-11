#!/bin/bash
# usage: build-runtime.sh <kernel build dir (make O=)> <out dir>
# Census re-check runtime on the kernel line: kprog_stock.ko, kernel_offsets.h,
# libnative_loader.so and trusted-native-loader, with census inputs laid out as
# rerun.py reads them (KPROG_CENSUS_INPUTS=<out>/census-inputs).
set -e
K=$1; O=$2; R=/workspaces/repository
mkdir -p $O/mod $O/offsets $O/census-inputs
make -C $R/kprog/stock-path/module KDIR=$K MO=$O/mod
make -C $R/micro/programs OUTPUT_DIR=$O/offsets KERNEL_BTF_INPUT=$K/vmlinux $O/offsets/kernel_offsets.h
# The loader also needs these two; the micro/programs rule leaves them out.
f=$(pahole -C bpf_prog $K/vmlinux | awk '/\(\*bpf_func\)/ { match($0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); print a[1] }')
grep -q '^CONFIG_X86_KERNEL_IBT=y' $K/.config && t=16 || t=12   # X86_TAIL_CALL_OFFSET = 12 + ENDBR_INSN_SIZE
printf '#define K_BPF_PROG_BPF_FUNC_OFFSET %su\n#define K_X86_BPF_TAIL_CALL_OFFSET %su\n' $f $t >> $O/offsets/kernel_offsets.h
sed "s#/var/tmp/kprog-tmp/C/stock-entry/loader-offsets#$O/offsets#" $R/corpus/results/kprog_app_coverage_20261110/census-followups/build-loader.sh > $O/build-loader.sh
bash $O/build-loader.sh $O/loader
tar xzf $R/corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped/run-raw.tar.gz -C $O/census-inputs
I=$O/census-inputs/inputs; mkdir -p $I/stock-runtime
cp $K/arch/x86/boot/bzImage $I/bzImage
cp $R/kprog/x86/native_lab/native_link/target/release/native-link $I/native-link
cp $O/mod/bpf_kprog_stock.ko $I/stock-runtime/kprog_stock.ko
cp $O/loader/libnative_loader.so $O/loader/trusted-native-loader $I/stock-runtime/
echo RUNTIME_DONE
