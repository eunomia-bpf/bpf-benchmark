#!/usr/bin/env bash
# Run only under the workspace's exclusive image lock, with guests checkpointed.
set -euo pipefail
refresh_output=$1
refresh_root=/workspaces/repository
refresh_kernel=/workspaces/.agent-state/kprog-ck/build-x86
refresh_loader=/workspaces/.agent-state/kprog-ck/verified-loader
refresh_direct=$refresh_root/kinsn/module/x86/build
refresh_image=bpf-benchmark/kprog:current
install -d "$refresh_output"
date -u +%FT%TZ > "$refresh_output/started"
refresh_old_image=$(docker image inspect --format '{{.Id}}' "$refresh_image")
printf '%s\n' "$refresh_old_image" > "$refresh_output/old-image"

make -C "$refresh_root/kprog/stock-path/module"
make -C "$refresh_kernel" M="$refresh_root/kprog/perf/direct-native" MO="$refresh_direct" ARCH=x86 modules -j1
make -C "$refresh_root/kprog/libnativeloader" trusted-service BUILD_DIR="$refresh_loader"

# Exercise both frontends of the shared query transport before image assembly.
for refresh_module in verified direct; do
    if [[ $refresh_module == verified ]]; then
        refresh_module_path=/workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
    else
        refresh_module_path=$refresh_direct/bpf_x86_native_lab.ko
    fi
    make -C "$refresh_root/kprog/libnativeloader" helper-context-kernel-kvm \
        HELPER_KERNEL_MODULE="$refresh_module_path" \
        HELPER_KERNEL_OUTPUT="$refresh_output/helper-$refresh_module"
done
make -C "$refresh_root/kprog/libnativeloader" native-image-handoff-kvm \
    BUILD_DIR="$refresh_loader" NATIVE_MODULE="$refresh_direct/bpf_x86_native_lab.ko" SERVICE_HOST_CPUS=13

# Use the frozen image recipe and existing stable kernel/application artifacts.
# Rebuild its loader/shim; avoid unrelated source exports and object rebuilds.
refresh_release=$(cat "$refresh_kernel/include/config/kernel.release")
refresh_overrides="HOST_KERNEL_BUILD_DIR_X86=$refresh_kernel X86_RUNTIME_KERNEL_IMAGE=$refresh_kernel/arch/x86/boot/bzImage X86_RUNNER_RUNTIME_IMAGE=$refresh_image JOBS=1 KERNEL_OFFSETS_INPUT=$refresh_root/micro/programs/build-x86/kernel_offsets.h VMLINUX_BTF=$refresh_kernel/vmlinux KERNEL_RELEASE=$refresh_release"
for refresh_stable in host-kernel-x86 host-kinsn-x86 host-micro-programs-x86 host-source-apps-x86 host-stage2-programs-x86 host-x86-sim-proofs host-native-bpf-x86 host-bpfopt-llvm-x86 host-rust-x86; do
    refresh_overrides+=" -o $refresh_stable"
done
refresh_overrides+=" -o $refresh_kernel/arch/x86/boot/bzImage -o $refresh_kernel/vmlinux -o $refresh_kernel/modules.order"
make -f "$refresh_root/kprog/perf/one-image/Makefile" image -o module -o negative -o tetragon-base \
    JOBS=1 OVERRIDES="$refresh_overrides"
refresh_new_image=$(docker image inspect --format '{{.Id}}' "$refresh_image")
printf '%s\n' "$refresh_new_image" > "$refresh_output/new-image"
if [[ $refresh_old_image != "$refresh_new_image" ]]; then
    docker image rm "$refresh_old_image"
    printf -- '- %s VERIFIED shared refresh: removed superseded runtime image %s; current %s; raw retained in %s.\n' \
        "$(date -u +%FT%TZ)" "$refresh_old_image" "$refresh_new_image" "$refresh_output" >> "$refresh_root/kprog/docs/cleanup-log.md"
fi
sha256sum "$refresh_loader/libnative_loader.so" "$refresh_loader/trusted-native-loader" \
    "$refresh_direct/bpf_x86_native_lab.ko" \
    /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko > "$refresh_output/base-sha256"
date -u +%FT%TZ > "$refresh_output/finished"
