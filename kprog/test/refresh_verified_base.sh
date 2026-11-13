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

finalize_refresh() {
    refresh_ids=$(docker image ls --no-trunc --format '{{.ID}}')
    refresh_old_present=false
    while IFS= read -r refresh_id; do
        if [[ $refresh_id == "$refresh_old_image" ]]; then
            refresh_old_present=true
        fi
    done <<< "$refresh_ids"
    refresh_cleanup=unchanged
    if [[ $refresh_old_image != "$refresh_new_image" ]]; then
        if [[ $refresh_old_present == true ]]; then
            docker image rm "$refresh_old_image"
            refresh_cleanup=removed
        else
            refresh_cleanup=already-absent
        fi
    fi
    printf '%s\n' "$refresh_cleanup" > "$refresh_output/image-cleanup"
    printf -- '- %s VERIFIED shared refresh: superseded runtime image %s %s; current %s; raw retained in %s.\n' \
        "$(date -u +%FT%TZ)" "$refresh_old_image" "$refresh_cleanup" "$refresh_new_image" "$refresh_output" >> "$refresh_root/kprog/docs/cleanup-log.md"
    sha256sum "$refresh_loader/libnative_loader.so" "$refresh_loader/trusted-native-loader" \
        "$refresh_direct/bpf_x86_native_lab.ko" \
        /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko > "$refresh_output/base-sha256"
    date -u +%FT%TZ > "$refresh_output/finished"
}

refresh_operation=${2:-full}
if [[ $refresh_operation == --finalize ]]; then
    refresh_old_image=$(cat "$refresh_output/old-image")
    refresh_new_image=$(docker image inspect --format '{{.Id}}' "$refresh_image")
    finalize_refresh
    exit 0
elif [[ $refresh_operation != full && $refresh_operation != --modules-only ]]; then
    printf 'Unknown refresh operation: %s\n' "$2" >&2
    exit 1
fi

date -u +%FT%TZ > "$refresh_output/started"
refresh_old_image=$(docker image inspect --format '{{.Id}}' "$refresh_image")
printf '%s\n' "$refresh_old_image" > "$refresh_output/old-image"

if [[ $refresh_operation == full ]]; then
# Interrupted recursive preflight removed vmlinux. Recover the matching ELF/BTF
# directly from the sole unchanged boot image; do not build another kernel.
"$refresh_root/vendor/linux-framework/scripts/extract-vmlinux" \
    "$refresh_kernel/arch/x86/boot/bzImage" > "$refresh_kernel/vmlinux"
sha256sum "$refresh_kernel/arch/x86/boot/bzImage" "$refresh_kernel/vmlinux" > "$refresh_output/kernel-sha256"

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
fi

# Kbuild's modules_install parser removes the installed kernel directory even
# with make -n. Restore the sole installed set from the already built modules;
# no kernel compilation or source/version change is involved.
find "$refresh_kernel/modules-install" -type f -print > "$refresh_output/modules-before.txt"
refresh_release=$(cat "$refresh_kernel/include/config/kernel.release")
if [[ ! -e $refresh_kernel/modules.order ]]; then
    # Kbuild installs this exact list by replacing .o with kernel/*.ko.
    # Preserve that existing metadata before modules_install replaces it.
    cp "$refresh_kernel/modules-install/lib/modules/$refresh_release/modules.order" \
        "$refresh_output/installed-modules.order"
    sed -e 's:^kernel/::' -e 's:\.ko$:.o:' "$refresh_output/installed-modules.order" \
        > "$refresh_kernel/modules.order"
    cp "$refresh_kernel/modules.order" "$refresh_output/recovered-modules.order"
fi
make -C "$refresh_root/vendor/linux-framework" O="$refresh_kernel" ARCH=x86_64 \
    INSTALL_MOD_PATH="$refresh_kernel/modules-install" INSTALL_MOD_STRIP=1 \
    DEPMOD=true modules_install -j1
find "$refresh_kernel/modules-install" -type f -print > "$refresh_output/modules-after.txt"
sha256sum "$refresh_kernel/net/netfilter/nfnetlink.ko" \
    "$refresh_kernel/modules-install/lib/modules/$refresh_release/kernel/net/netfilter/nfnetlink.ko" \
    > "$refresh_output/nfnetlink-sha256"
printf -- '- %s VERIFIED module packaging repair: replaced incomplete modules-install in the sole build using its existing .ko files (INSTALL_MOD_STRIP=1); no kernel compilation; file inventories and raw logs retained in %s.\n' \
    "$(date -u +%FT%TZ)" "$refresh_output" >> "$refresh_root/kprog/docs/cleanup-log.md"

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
finalize_refresh
